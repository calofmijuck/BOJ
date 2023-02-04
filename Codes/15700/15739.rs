use std::{io, vec};

fn read_u32() -> u32 {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    return line.trim().parse().unwrap();
}

fn main() {
    let n = read_u32();
    let square = read_square(n);

    let magic = check_uniqueness(&square)
        & check_row_sum(&square)
        & check_column_sum(&square)
        & check_diagonal_sum(&square);

    println!("{}", magic.to_string().to_uppercase());
}

fn read_square(n: u32) -> Vec<Vec<u32>> {
    let mut square: Vec<Vec<u32>> = Vec::new();
    for _ in 0..n {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let row = line
            .trim()
            .split(' ')
            .map(|e| e.parse().unwrap())
            .collect::<Vec<u32>>();

        square.push(row);
    }
    square
}

fn check_uniqueness(square: &Vec<Vec<u32>>) -> bool {
    let n = square.len();

    let mut used = vec![false; n * n];
    for row in square {
        for item in row {
            used[(item - 1) as usize] = true;
        }
    }

    used.iter().fold(true, |res, e| res & e)
}

fn check_row_sum(square: &Vec<Vec<u32>>) -> bool {
    let n = square.len();

    let target_sum = n * (n * n + 1) / 2;
    for row in square {
        let sum: u32 = row.iter().sum();
        if sum != target_sum as u32 {
            return false;
        }
    }
    true
}

fn check_column_sum(square: &Vec<Vec<u32>>) -> bool {
    let n = square.len();

    let target_sum = n * (n * n + 1) / 2;
    for column in 0..n {
        let mut sum = 0;
        for row in square {
            sum += row[column];
        }

        if sum != target_sum as u32 {
            return false;
        }
    }
    true
}

fn check_diagonal_sum(square: &Vec<Vec<u32>>) -> bool {
    let n = square.len();
    let target_sum = n * (n * n + 1) / 2;

    let mut sum = 0;
    for (i, row) in square.iter().enumerate() {
        sum += row[i];
    }

    if sum != target_sum as u32 {
        return false;
    }

    sum = 0;
    for (i, row) in square.iter().enumerate() {
        sum += row[n - 1 - i];
    }

    if sum != target_sum as u32 {
        return false;
    }

    true
}
