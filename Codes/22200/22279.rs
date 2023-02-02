use std::io;

fn read_i32() -> i32 {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    return line.trim().parse().unwrap();
}

fn main() {
    let period = read_i32();
    let mut life_year = 0.0;

    let mut line;

    for _ in 0..period {
        line = String::new();
        io::stdin().read_line(&mut line).unwrap();

        let values: Vec<f64> = line
            .as_mut_str()
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();

        life_year += values[0] * values[1];
    }

    print!("{:.5}", life_year);
}
