use std::io;

fn read_u64() -> u64 {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim().parse::<u64>().unwrap()
}

fn main() {
    let n = read_u64();

    let mut prod = 1;
    for i in 1..=n {
        prod *= i;
    }

    println!("{prod}");
}
