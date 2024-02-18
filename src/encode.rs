use std::fs::File;
use std::io::{prelude::*, BufReader};

pub fn encode(src_path: &str, dst_path: &str) -> Result<(), String> {
    let src_file: File;

    match File::open(src_path) {
        Ok(f) => src_file = f,
        Err(e) => match e.kind() {
            std::io::ErrorKind::NotFound => {
                return Result::Err(
                    format!("The file at '{}' was not found!", src_path).to_string(),
                )
            }
            std::io::ErrorKind::PermissionDenied => {
                return Result::Err(
                    format!(
                        "You don't have permission to access the file at '{}'!",
                        src_path
                    )
                    .to_string(),
                )
            }
            _ => {
                return Result::Err(
                    format!("An error occured while trying to open '{}'!", src_path).to_string(),
                )
            }
        },
    }

    let mut reader: BufReader<File> = BufReader::new(src_file);
    let mut contents: String = String::new();

    if reader.read_to_string(&mut contents).is_err() {
        return Result::Err(
            format!(
                "The program was interupted while trying to read from '{}'!",
                src_path
            )
            .to_string(),
        );
    }

    let mut dst_file: File;

    match File::create(dst_path) {
        Ok(f) => dst_file = f,
        Err(e) => match e.kind() {
            std::io::ErrorKind::PermissionDenied => {
                return Result::Err(
                    format!(
                        "You don't have permission to access the file at '{}'!",
                        dst_path
                    )
                    .to_string(),
                )
            }
            _ => {
                return Result::Err(
                    format!("An error occured while trying to create '{}'!", dst_path).to_string(),
                )
            }
        },
    }

    let mut dst_bytes: Vec<u8> = Vec::new();
    let mut dst_buf: String = String::new();
    let mut reading_first: bool = true;

    for s in contents.chars() {
        if !s.is_ascii_hexdigit() {
            continue;
        }

        if reading_first {
            dst_buf.push(s);
            reading_first = false;
            continue;
        }

        dst_buf.push(s);
        reading_first = true;

        let next_byte: u8 = u8::from_str_radix(dst_buf.as_str(), 16).unwrap();
        dst_bytes.push(next_byte);
        dst_buf.clear();
    }

    if dst_file.write_all(dst_bytes.as_slice()).is_err() {
        return Result::Err(
            format!(
                "The program was interupted while trying to write to '{}'!",
                src_path
            )
            .to_string(),
        );
    }

    Ok(())
}
