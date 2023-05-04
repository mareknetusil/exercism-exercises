use std::cmp;

#[derive(Debug)]
pub struct HighScores<'a> {
    _scores: &'a [u32]
}

impl<'a> HighScores<'a> {
    pub fn new(scores: &'a [u32]) -> Self {
        HighScores { _scores: scores }
    }

    pub fn scores(&self) -> &[u32] {
        self._scores
    }

    pub fn latest(&self) -> Option<u32> {
        self._scores.last().copied()
    }

    pub fn personal_best(&self) -> Option<u32> {
        match self._scores {
            [] => None,
            _ => Some(self._scores.iter().fold(0, |x, y| cmp::max(x, *y)))
        }
    }

    pub fn personal_top_three(&self) -> Vec<u32> {
        let mut results = self._scores.iter().fold(vec![], top_three);
        results.reverse();
        results
    }
}

fn top_three(mut top: Vec<u32>, val: &u32) -> Vec<u32> {
    let idx = top.binary_search(val).unwrap_or_else(|x| x);
    top.insert(idx, *val);
    if top.len() > 3 {
        top.remove(0);
    }
    top
}
