mod encode;
mod run;

use std::env;

use crate::encode::*;
use crate::run::*;

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
                print!("[ERROR]: {}", e);
            }
        }
        "r" => {
            if args.len() != 3 {
                println!("Usage: pike r [bin]");
                return;
            }
            if let Err(e) = run(&args[2]) {
                panic!("[ERROR]: {:?}", e)
            }
        }
        _ => {
            println!("That's not a valid command!");
        }
    }
}
