pub fn factors(n: u64) -> Vec<u64> {
    let mut factors = Vec::new();
    let mut x = n;
    let mut factor = Factor::new();
    while x > 1 {
        if x % factor.val == 0 {
            factors.push(factor.val);
            x = x / factor.val;
        } else {
            factor.next();
        }
    }

    factors
}

struct Factor {
    pub val: u64,
}

impl Factor {
    fn new() -> Factor {
        Factor { val: 2 }
    }

    fn next(&mut self) {
        let n = &self.val;
        assert!(*n == 2 || *n % 2 == 1);
        if *n == 2 {
            self.val = 3;
        } else {
            self.val = n + 2;
        }
    }
}
