use std::io;

fn read_i32() -> i32 {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim().parse::<i32>().unwrap()
}

const HEART: &str = " @@@   @@@ \n@   @ @   @\n@    @    @\n@         @\n @       @ \n  @     @  \n   @   @   \n    @ @    \n     @     \n";

fn main() {
    let n = read_i32();

    let mut result = String::new();
    for _ in 0..n {
        result.push_str(HEART);
    }
    print!("{result}");
}
