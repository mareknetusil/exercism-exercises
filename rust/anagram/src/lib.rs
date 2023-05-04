use std::collections::HashSet;
use itertools::Itertools;
use unicode_segmentation::UnicodeSegmentation;

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &'a [&str]) -> HashSet<&'a str> {
    let anagram = Anagram::new(word);
    possible_anagrams.iter().cloned()
                     .filter(|s| anagram.cmp(s))
                     .collect()
}

struct Anagram {
    lower: String,
    sorted: String,
}

impl Anagram {
    fn new(word: &str) -> Anagram {
        let lower = word.to_lowercase();
        let sorted = lower.graphemes(true).sorted().collect::<String>();
        Anagram { lower: lower, sorted: sorted }
    }

    fn cmp(&self, candidate: &str) -> bool {
        if self.lower.len() == candidate.len() {
            let candidate = candidate.to_lowercase();

            if self.lower != candidate {
                let candidate = candidate.graphemes(true).sorted().collect::<String>();
                return self.sorted == candidate;
            }
        }

        false
    }
}
