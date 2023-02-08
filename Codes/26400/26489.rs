use std::io::{self, Read};

fn main() {
    let mut line = String::new();
    io::stdin().read_to_string(&mut line).unwrap();
    let lines = line
        .trim()
        .split('\n')
        .map(|e| e.to_string())
        .collect::<Vec<String>>();

    println!("{}", lines.len());
}
