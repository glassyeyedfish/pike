use std::env;
use std::fs::File;
use std::io::{prelude::*, BufReader};

fn encode(src_path: &str, dst_path: &str) -> std::io::Result<()> {
    let src_file: File = File::open(src_path)?;
    let mut buf_reader: BufReader<File> = BufReader::new(src_file);
    let mut contents: String = String::new();

    buf_reader.read_to_string(&mut contents)?;

    let mut dst_file: File = File::create(dst_path)?;
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

    dst_file.write_all(dst_bytes.as_slice())?;

    Ok(())
}

fn main() {
    // First, grab the CLI arguments to decide what action to take.
    let args: Vec<String> = env::args().collect();

    // The must be at least one argument for the command being used.
    if args.len() <= 1 {
        println!("Usage: pike [command] [args...]");
        return;
    }

    // Check if the command passed enough arguments the call that function.
    match args[1].as_str() {
        "e" => {
            if args.len() != 4 {
                println!("Usage: pike e [src] [dst]");
                return;
            }
            if let Err(e) = encode(&args[2], &args[3]) {
                panic!("[ERROR]: {:?}", e)
            }
        }
        _ => {
            println!("That's not a valid command!");
        }
    }
}
