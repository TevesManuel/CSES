/* AUTHOR: Manuel Tomas Teves */

use std::io::{self, Read, Write, BufWriter};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut tokens = input.split_whitespace();

    let stdout = io::stdout();
    let mut out = BufWriter::new(stdout.lock());

    if let Some(k_str) = tokens.next() {
        let k: i64 = k_str.parse().unwrap();

        for i in 1..=k {
            let i2 = i * i;
            let ways = ((i2 - 1) * i2) / 2 - 4 * (i - 1) * (i - 2);
            
            writeln!(out, "{}", ways).unwrap();
        }
    }
}