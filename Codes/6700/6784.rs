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

    let problems = reader.read::<i32>();

    let mut responses: Vec<char> = Vec::new();
    for _ in 0..problems {
        responses.push(reader.read::<char>());
    }

    let mut answers: Vec<char> = Vec::new();
    for _ in 0..problems {
        answers.push(reader.read::<char>());
    }

    let mut correct = 0;
    for i in 0..problems {
        correct += (responses[i as usize] == answers[i as usize]) as i32;
    }

    println!("{correct}");
}
