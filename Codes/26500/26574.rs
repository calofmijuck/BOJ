use std::io;

fn read_i32() -> i32 {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim().parse::<i32>().unwrap()
}

fn main() {
    let n = read_i32();
    for _ in 0..n {
        let x = read_i32();
        println!("{x} {x}");
    }
}
