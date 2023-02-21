use std::io::{self, BufWriter, Write};

fn main() {
    let mut writer = BufWriter::new(io::stdout().lock());

    for numerator in 100..1000 {
        for denominator in 100..1000 {
            if !check_removable(denominator, numerator) {
                continue;
            }

            let x = numerator / 10;
            let y = denominator % 100;

            if x * denominator == y * numerator {
                _ = writeln!(writer, "{numerator} / {denominator} = {x} / {y}");
            }
        }
    }
}

fn check_removable(denominator: i32, numerator: i32) -> bool {
    (denominator / 100 == numerator % 10) && (denominator != numerator)
}
