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
    let (hour, minute) = (input[0], input[1]);

    println!("{}", 60 * (hour - 9) + minute);
}
