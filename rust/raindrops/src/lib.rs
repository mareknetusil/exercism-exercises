pub fn raindrops(n: u32) -> String {
    let sounds = rainsounds(n);
    if sounds.is_empty() {n.to_string()} else {sounds}
}

fn rainsounds(n: u32) -> String {
    (if n % 3 == 0 {"Pling"} else {""}).to_owned() +
    (if n % 5 == 0 {"Plang"} else {""}) +
    (if n % 7 == 0 {"Plong"} else {""})
}