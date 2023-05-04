pub fn build_proverb(list: &[&str]) -> String {
    if list.is_empty() {
        String::new()
    } else {
        list.iter().zip(&list[1..])
            .map(proverb)
            .chain(std::iter::once(format!("And all for the want of a {}.", list.first().unwrap())))
            .collect::<Vec<String>>()
            .join("")
    }
}

fn proverb(pair: (&&str, &&str)) -> String {
    format!("For want of a {} the {} was lost.\n", pair.0, pair.1)
}