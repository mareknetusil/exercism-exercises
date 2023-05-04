// The code below is a stub. Just enough to satisfy the compiler.
// In order to pass the tests you can add-to or change any of this code.

#[derive(Debug)]
pub struct Duration {
    secs: u64,
}

impl From<u64> for Duration {
    fn from(s: u64) -> Self {
        Duration { secs: s }
    }
}

pub trait Planet {
    const EARTH_YEAR: f64 = 31_557_600.;
    const EARTH_YEARS: f64;
    const SECS_IN_YEAR: f64 = Self::EARTH_YEAR * Self::EARTH_YEARS;

    fn years_during(d: &Duration) -> f64 {
        d.secs as f64 / Self::SECS_IN_YEAR
    }
}

pub struct Mercury;
pub struct Venus;
pub struct Earth;
pub struct Mars;
pub struct Jupiter;
pub struct Saturn;
pub struct Uranus;
pub struct Neptune;

impl Planet for Mercury {
    const EARTH_YEARS: f64 = 0.240_846_7;
}
impl Planet for Venus {
    const EARTH_YEARS: f64 = 0.615_197_26;
}
impl Planet for Earth {
    const EARTH_YEARS: f64 = 1.;
}
impl Planet for Mars {
    const EARTH_YEARS: f64 = 1.880_815_8;
}
impl Planet for Jupiter {
    const EARTH_YEARS: f64 = 11.862_615;
}
impl Planet for Saturn {
    const EARTH_YEARS: f64 = 29.447_498;
}
impl Planet for Uranus {
    const EARTH_YEARS: f64 = 84.016_846;
}
impl Planet for Neptune {
    const EARTH_YEARS: f64 = 164.791_32;
}
