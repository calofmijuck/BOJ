use std::io;

fn read_i32() -> i32 {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    return line.trim().parse().unwrap();
}

fn main() {
    let n = read_i32();

    let mut closest = 99;
    let mut diff = (n - closest).abs();
    loop {
        let next = closest + 100;
        let next_diff = (n - next).abs();

        if next_diff <= diff {
            closest = next;
            diff = next_diff;
        } else {
            break;
        }
    }
    print!("{:.5}", closest);
}
