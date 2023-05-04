pub fn nth(n: u32) -> u32 {
    let mut divisors = vec![2];
    for _ in 0..n {
        let next = next_prime(&divisors);
        divisors.push(next);
    }
    divisors.last().copied().unwrap()
}

fn next_prime(divisors: &Vec<u32>) -> u32 {
    let mut next = divisors.last().unwrap() + 1;
    loop {
        if prime_adept(next, divisors) {
            break;
        } else {
            next += 1;
        }
    }
    next
}

fn prime_adept(n: u32, divisors: &Vec<u32>) -> bool {
    divisors.iter().find(|&&x| n % x == 0) == None
}