pub fn square_of_sum(n: u32) -> u32 {
    let sum = sum_till_n(n);
    sum * sum
}

pub fn sum_of_squares(n: u32) -> u32 {
    n * (n + 1) * (2 * n + 1) / 6
}

pub fn difference(n: u32) -> u32 {
    square_of_sum(n) - sum_of_squares(n)
}

fn sum_till_n(n: u32) -> u32 {
    n * (n + 1) / 2
}