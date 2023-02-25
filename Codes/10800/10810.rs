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

    let buckets = reader.read::<i32>();
    let operations = reader.read::<i32>();

    let mut bucket = Vec::new();
    bucket.resize(buckets as usize + 1, 0);

    for _ in 0..operations {
        let start = reader.read::<i32>();
        let end = reader.read::<i32>();
        let number = reader.read::<i32>();

        fill(&mut bucket, start, end, number);
    }

    for i in 1..=buckets {
        print!("{} ", bucket[i as usize]);
    }
}

fn fill(bucket: &mut [i32], start: i32, end: i32, number: i32) {
    for i in start..=end {
        bucket[i as usize] = number;
    }
}
