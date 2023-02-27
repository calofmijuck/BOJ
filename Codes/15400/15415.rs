use std::io;

fn read_input() -> Vec<i32> {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim()
        .split(' ')
        .map(|e| e.parse::<i32>().unwrap())
        .collect()
}

fn read_i32() -> i32 {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim().parse::<i32>().unwrap()
}

fn main() {
    let width = read_i32();

    let mut area = 0;
    let pieces = read_i32();
    for _ in 0..pieces {
        let input = read_input();
        let (piece_width, piece_height) = (input[0], input[1]);

        area += piece_width * piece_height;
    }

    println!("{}", area / width);
}
