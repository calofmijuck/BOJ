use std::{
    io::{self, BufReader, Read},
    str::FromStr,
};

struct Reader {
    vec: Vec<String>,
    idx: usize,
}

impl Reader {
    fn read_input() -> Reader {
        let mut stdin = String::new();
        BufReader::new(io::stdin().lock())
            .read_to_string(&mut stdin)
            .unwrap();
        let vec = stdin
            .split_ascii_whitespace()
            .map(|e| e.to_string())
            .collect::<Vec<String>>();
        Reader { vec, idx: 0 }
    }

    fn read<T: FromStr>(&mut self) -> T {
        let token = &self.vec[self.idx];
        let parsed = token.parse::<T>();
        self.idx += 1;
        match parsed {
            Ok(val) => val,
            Err(_) => panic!(),
        }
    }
}

fn main() {
    let mut reader = Reader::read_input();

    let cases = reader.read::<i32>();
    for _ in 0..cases {
        add_backward(&mut reader);
    }
}

fn add_backward(reader: &mut Reader) {
    let a = reader.read::<i32>();
    let b = reader.read::<i32>();
    println!("{}", reverse(reverse(a) + reverse(b)));
}

fn reverse(mut x: i32) -> i32 {
    let mut result = 0;
    while x > 0 {
        result *= 10;
        result += x % 10;
        x /= 10;
    }
    result
}
