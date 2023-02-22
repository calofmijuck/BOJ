use std::{
    cmp,
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
        handle_case(&mut reader);
    }
}

fn handle_case(reader: &mut Reader) {
    let lines = reader.read::<i32>();

    let mut people = 0;
    let mut min_people = 0;
    for _ in 0..lines {
        let enter = reader.read::<i32>();
        let leave = reader.read::<i32>();

        people = people + enter - leave;
        min_people = cmp::min(min_people, people);
    }

    println!("{}", min_people.abs());
}
