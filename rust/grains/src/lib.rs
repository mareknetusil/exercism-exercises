use std::collections::HashMap;

pub fn square(s: u32) -> u64 {
    if 0 < s && s < 65 {
        power(2, s - 1)
    } else {
        panic!("Square must be between 1 and 64")
    }
}

pub fn total() -> u64 {
    let mut cacher = Cacher::new(square);
    (1..65).map(|x| cacher.value(x)).sum()
}

fn power(base: u32, exp: u32) -> u64 {
    match exp {
        0 => 1,
        _ => {
            if exp % 2 == 0 {
                let half = power(base, exp / 2);
                half * half
            } else {
                (base as u64) * power(base, exp - 1)
            }
        }
    }
}

struct Cacher<T> where T: Fn(u32) -> u64 {
    function: T,
    values: HashMap<u32, u64>,
}

impl<T> Cacher<T> where T: Fn(u32) -> u64 {
    fn new(f: T) -> Cacher<T> {
        Cacher {
            function: f,
            values: HashMap::new(),
        }
    }

    fn value(&mut self, val: u32) -> u64 {
        match self.values.get(&val) {
            Some(&arg) => arg,
            None => {
                let result = (self.function)(val);
                self.values.insert(val, result);
                result
            }
        }
    }
}