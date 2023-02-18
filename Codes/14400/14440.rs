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

    let x = reader.read::<i32>();
    let y = reader.read::<i32>();
    let (a0, a1) = (reader.read::<i32>(), reader.read::<i32>());
    let n = reader.read::<i32>();

    if n == 0 {
        println!("{a0:02}");
        return;
    } else if n == 1 {
        println!("{a1:02}");
        return;
    }

    let power = matrix_power([[x, y], [1, 0]], n - 1);
    let result = (power[0][0] * a1 + power[0][1] * a0) % 100;
    println!("{result:02}");
}

fn matrix_power(mut matrix: [[i32; 2]; 2], mut exp: i32) -> [[i32; 2]; 2] {
    let mut result = [[1, 0], [0, 1]];
    while exp > 0 {
        if exp % 2 == 1 {
            result = matmul(&result, &matrix);
        }
        matrix = matmul(&matrix, &matrix);
        exp /= 2;
    }
    result
}

fn matmul(a: &[[i32; 2]; 2], b: &[[i32; 2]; 2]) -> [[i32; 2]; 2] {
    let mut result = [[0; 2]; 2];
    for i in 0..2 {
        for j in 0..2 {
            let mut dot = 0;
            for (k, column) in b.iter().enumerate().take(2) {
                dot += a[i][k] * column[j];
            }
            result[i][j] = dot % 100;
        }
    }
    result
}
