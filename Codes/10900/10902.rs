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

    let submissions = reader.read::<i32>();
    let (mut max_score, mut max_idx, mut max_time) = (0, 0, 0);
    for i in 0..submissions {
        let time = reader.read::<i32>();
        let score = reader.read::<i32>();

        if score > max_score {
            max_score = score;
            max_idx = i;
            max_time = time;
        }
    }

    let penalty = match max_score {
        0 => 0,
        1 | 4 => max_time + max_idx * 20,
        _ => panic!(),
    };

    println!("{penalty}");
}
