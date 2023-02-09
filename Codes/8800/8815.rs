use std::io;

const PATTERN: [char; 12] = ['A', 'B', 'C', 'B', 'C', 'D', 'C', 'D', 'A', 'D', 'A', 'B'];

fn read_i32() -> i32 {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim().parse::<i32>().unwrap()
}

fn main() {
    let cases = read_i32();
    for _ in 0..cases {
        let n = read_i32();
        println!("{}", answer(n));
    }
}

fn answer(n: i32) -> char {
    let remainder = (n - 1) % 12;
    PATTERN[remainder as usize]
}
