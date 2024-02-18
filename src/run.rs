use std::fs::File;
use std::io::{prelude::*, BufReader};

#[derive(Debug, Clone, Copy)]
enum PikeVal {
    Int(i32),
}

impl PikeVal {
    fn get_int(self) -> i32 {
        match self {
            PikeVal::Int(i) => i,
        }
    }
}

pub fn run(bin_path: &str) -> Result<(), String> {
    // Open the file where the binary is stored.
    let bin_file: File;

    match File::open(bin_path) {
        Ok(f) => bin_file = f,
        Err(e) => match e.kind() {
            std::io::ErrorKind::NotFound => {
                return Result::Err(
                    format!("The file at '{}' was not found!", bin_path).to_string(),
                )
            }
            std::io::ErrorKind::PermissionDenied => {
                return Result::Err(
                    format!(
                        "You don't have permission to access the file at '{}'!",
                        bin_path
                    )
                    .to_string(),
                )
            }
            _ => {
                return Result::Err(
                    format!("An error occured while trying to open '{}'!", bin_path).to_string(),
                )
            }
        },
    }

    // Read all the bytes into a Vec.
    let mut buf_reader: BufReader<File> = BufReader::new(bin_file);
    let mut buf: Vec<u8> = Vec::new();

    if buf_reader.read_to_end(&mut buf).is_err() {
        return Result::Err(
            format!(
                "The program was interupted while trying to read from '{}'!",
                bin_path
            )
            .to_string(),
        );
    }

    let mut pc: usize = 0;
    let mut working_stack: Vec<PikeVal> = Vec::new();

    while pc < buf.len() {
        match buf[pc] {
            // NOP
            0x00 => (),
            // PUSHI
            0x01 => {
                let new_int: [u8; 4] = buf.get(pc + 1..pc + 5).unwrap().try_into().unwrap();
                working_stack.push(PikeVal::Int(i32::from_be_bytes(new_int)));
                pc += 4;
            }
            // POPI
            0x02 => {
                let _poped = working_stack.pop();
            },
            // PUTI
            0x03 => {
                println!("{}", working_stack.last().unwrap().get_int())
            },
            // ADDI
            0x04 => {
                let lhs = working_stack.pop().unwrap().get_int();
                let rhs = working_stack.pop().unwrap().get_int();
                working_stack.push(PikeVal::Int(lhs + rhs));
            }
            // SUBI
            0x05 => {
                let lhs = working_stack.pop().unwrap().get_int();
                let rhs = working_stack.pop().unwrap().get_int();
                working_stack.push(PikeVal::Int(lhs - rhs));
            }
            // MULI
            0x06 => {
                let lhs = working_stack.pop().unwrap().get_int();
                let rhs = working_stack.pop().unwrap().get_int();
                working_stack.push(PikeVal::Int(lhs * rhs));
            }
            // END
            0xFF => break,
            _ => panic!("Illegal operator!"),
        }

        pc += 1;
    }

    Ok(())
}
