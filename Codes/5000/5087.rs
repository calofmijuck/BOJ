use std::cmp::Ordering;
use std::io;

fn main() {
    loop {
        let case = read_case();
        if case[0] == "#" {
            break;
        }

        let winner = find_winner(case);
        println!("{winner}");
    }
}

fn read_case() -> Vec<String> {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    return line
        .trim()
        .split(' ')
        .map(|e| e.to_string())
        .collect::<Vec<String>>();
}

fn find_winner(case: Vec<String>) -> String {
    let mut score = vec![0, 0];
    for card in case {
        if card == "*" {
            continue;
        } else if card == "A" {
            score[0] += 1;
        } else {
            let i = 1 - (card.parse::<u32>().unwrap() % 2) as usize;
            score[i] += 1;
        }
    }

    match score[0].cmp(&score[1]) {
        Ordering::Greater => "Cheryl".to_string(),
        Ordering::Less => "Tania".to_string(),
        Ordering::Equal => "Draw".to_string(),
    }
}
