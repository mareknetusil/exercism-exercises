use std::iter::Iterator;

pub fn is_armstrong_number(num: u32) -> bool {
    let digits: Vec<u32> = Digits::new(num).collect();
    let len = digits.len() as u32;
    let result = digits.iter().map(|d| d.pow(len)).sum();
    num == result
}

struct Digits {
    _val: u32
}

impl Digits {
    pub fn new(x: u32) -> Digits {
        Digits { _val: x }
    }
}

impl Iterator for Digits {
    type Item = u32;

    fn next(&mut self) -> Option<Self::Item> {
        match self._val {
            0 => None,
            _ => {
                let rm = self._val % 10;
                self._val /= 10;
                Some(rm)
            }
        }
    }
}
