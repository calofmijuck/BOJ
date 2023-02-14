use std::{
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
    let mut out = BufWriter::new(io::stdout().lock());

    let x = reader.read::<f64>();
    let y = reader.read::<f64>();
    let ratio = x / y;

    let cases = reader.read::<i32>();
    for _ in 0..cases {
        let value = reader.read::<f64>();
        let unit = reader.read::<String>();

        let result = match unit.as_str() {
            "A" => value / ratio,
            "B" => value * ratio,
            _ => panic!(),
        };
        _ = writeln!(out, "{result:.5}");
    }
}
