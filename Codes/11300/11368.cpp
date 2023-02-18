use std::{
    io::{self, BufReader, Read},
        str::FromStr,
};

struct Reader {
vec: Vec<String>,
idx : usize,
}

impl Reader {
    fn read_input() -> Reader {
        let mut stdin = String::new();
        BufReader::new(io::stdin().lock())
            .read_to_string(&mut stdin)
            .unwrap();
        let vec = stdin
            .split_ascii_whitespace()
            .map(| e | e.to_string())
            .collect::<Vec<String>>();
        Reader{ vec, idx: 0 }
    }

    fn read<T: FromStr>(&mut self) -> T {
        let token = &self.vec[self.idx];
        let parsed = token.parse::<T>();
        self.idx += 1;
        match parsed{
            Ok(val) = > val,
            Err(_) = > panic!(),
        }
    }
}

fn main() {
    let mut reader = Reader::read_input();

    loop{
        let chars = reader.read::<u128>();
        let chars_per_line = reader.read::<u32>();
        let line_per_page = reader.read::<u32>();
        let page_per_book = reader.read::<u32>();

        if chars == 0 && chars_per_line == 0 && line_per_page == 0 && page_per_book == 0 {
            break;
        }

        let combinations = chars.pow(chars_per_line * line_per_page * page_per_book);
        println!("{combinations}");
    }
}
