pub fn verse(n: u32) -> String {
    macro_rules! form_1  { () => ("{} of beer on the wall, {} of beer.\n") };
    macro_rules! form_2  { () => ("Take {} down and pass it around, {} of beer on the wall.\n") };
    let printed_bottles = print_bottles(n);
    let first_half: String = format!(form_1!(), &printed_bottles, &printed_bottles.to_lowercase());
    let second_half: String = match n {
        0 => "Go to the store and buy some more, 99 bottles of beer on the wall.\n".to_string(),
        1 => format!(form_2!(), "it", print_bottles(n-1).to_lowercase()),
        _ => format!(form_2!(), "one", print_bottles(n-1)),
    };
    first_half + &second_half
}

pub fn sing(start: u32, end: u32) -> String {
    let range = (end..(start+1)).rev();
    range.map(verse).collect::<Vec<String>>().join("\n")
}

fn print_bottles(n: u32) -> String {
    match n {
        0 => "No more bottles".to_string(),
        1 => "1 bottle".to_string(),
        _ => format!("{} bottles", n),
    }
}