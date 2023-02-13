use std::io;

const MAX_N: i32 = 1000000000;

fn read_i32() -> i32 {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim().parse::<i32>().unwrap()
}

fn main() {
    let n = read_i32();

    for i in n..=MAX_N {
        if is_composite(i) {
            println!("{i}");
            break;
        }
    }
}

fn is_composite(n: i32) -> bool {
    let lim = (n as f64).sqrt().floor() as i32;
    for i in 2..=lim {
        if n % i == 0 {
            return true;
        }
    }
    false
}
