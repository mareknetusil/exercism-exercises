mod hidden {
    use std::fmt;

    #[derive(Debug, PartialEq)]
    pub struct Clock {
        _mins: u32,
    }
    
    impl Clock {
        pub fn new(hours: i32, minutes: i32) -> Self {
            let mins_in_day = 24 * 60;
            let total = hours * 60 + minutes;
            Clock { _mins: total.rem_euclid(mins_in_day) as u32 }
        }
    
        pub fn add_minutes(&self, minutes: i32) -> Self {
            Clock::new(0, self._mins as i32 + minutes)
        }
    }
    
    impl fmt::Display for Clock {
        fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
            write!(f, "{:02}:{:02}", self._mins.div_euclid(60), self._mins.rem_euclid(60))
        }
    }
}

pub use hidden::Clock;

