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

    let mut values: [i32; 10] = [0; 10];
    for value in &mut values {
        *value = reader.read::<i32>();
    }

    let mut result = 0;
    for i in 0..10 {
        for j in (i + 1)..10 {
            result ^= values[i] | values[j];
        }
    }

    for i in 0..10 {
        for j in (i + 1)..10 {
            for k in (j + 1)..10 {
                result ^= values[i] | values[j] | values[k];
            }
        }
    }

    println!("{result}");
}
