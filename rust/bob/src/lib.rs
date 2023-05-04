pub fn reply(message: &str) -> &str {
    let trimmed = message.trim();
    match trimmed {
        "" => "Fine. Be that way!",
        _ => {
            let mut letters = trimmed.chars().filter(|a| a.is_alphabetic()).peekable();
            let yelling = letters.peek().is_some() && letters.all(|a| a.is_uppercase());
            let question = trimmed.ends_with("?");
            match (yelling, question) {
                (false, true) => "Sure.",
                (true, false) => "Whoa, chill out!",
                (true, true) => "Calm down, I know what I'm doing!",
                _ => "Whatever."
            }
        }
    }

}
