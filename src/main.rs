use std::env;

fn encode(src: &String, dst: &String) {
    println!("Time to encode!")
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
            encode(&args[2], &args[3]);
        }
        _ => {
            println!("That's not a valid command!");
        }
    }
}
