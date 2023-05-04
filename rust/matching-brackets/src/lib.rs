use std::collections::HashMap;

pub fn brackets_are_balanced(string: &str) -> bool {
    let opening = ['(', '[', '{'];
    let closing = [')', ']', '}'];
    let brackets_map: HashMap<&char, &char> = closing.iter().zip(opening.iter()).collect();
    let mut stack = vec![];
    for c in string.chars() {
        if let Some(ob) = opening.iter().find(|a| **a == c) {
            stack.push(ob);
        } else if let Some(cb) = closing.iter().find(|a| **a == c) {
            if brackets_map.get(cb) == stack.last() {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    stack.is_empty()
}
