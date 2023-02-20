use std::{
    cmp,
    io::{self, BufReader, BufWriter, Read, Write},
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
    let mut writer = BufWriter::new(io::stdout().lock());

    let cases = reader.read::<i32>();
    for _ in 0..cases {
        let init = reader.read::<i32>();
        let height = reader.read::<i32>();
        _ = writeln!(writer, "{}", find_bounces(init, height));
    }
}

fn find_bounces(init: i32, height: i32) -> i32 {
    if init >= height {
        return 0;
    }

    let ratio = height as f64 / init as f64;
    ratio.log2().ceil() as i32
}
