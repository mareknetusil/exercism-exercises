#include <cmath>

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(const double hourly_rate) {
    return 8 * hourly_rate;
}

// apply_discount calculates the price after a discount
double apply_discount(const double before_discount, const double discount) {
    return before_discount * (1 - discount / 100.0);
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(const double hourly_rate, const double discount) {
    const auto rate = 22 * daily_rate(hourly_rate);
    const auto monthly_rate_ = apply_discount(rate, discount);
    return std::ceil(monthly_rate_);
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(const int budget, const double hourly_rate, const double discount) {
    const auto day_rate = daily_rate(hourly_rate);
    const auto discounted_rate = apply_discount(day_rate, discount);
    return std::floor(budget / discounted_rate);
}