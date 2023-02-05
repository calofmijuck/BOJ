use std::io;

fn read_input() -> Vec<i32> {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim()
        .split(' ')
        .map(|e| e.parse::<i32>().unwrap())
        .collect()
}

fn main() {
    let input = read_input();
    let (time, drink) = (input[0], input[1]);

    println!("{}", solve(time, drink));
}

fn solve(time: i32, drink: i32) -> i32 {
    match time {
        12..=16 => {
            if drink == 0 {
                320
            } else {
                280
            }
        }
        _ => 280,
    }
}
