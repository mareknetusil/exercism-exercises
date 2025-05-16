#include <vector>
#include <utility>
#include <algorithm>
#include <limits>

// interest_rate returns the interest rate for the provided balance.
double interest_rate(const double balance) {
    const std::vector<std::pair<double, double>> rates = {
        {0    , 3.213},
        {1'000, 0.5},
        {5'000, 1.621},
        {std::numeric_limits<double>::max(), 2.475}
    };
    const auto it = std::find_if(
        std::begin(rates), std::end(rates),
        [&balance](const auto threshold) { return balance < threshold.first ; }
        );
    return it->second;
}

constexpr auto PERCENT_DIVISOR = 100.;

// yearly_interest calculates the yearly interest for the provided balance.
double yearly_interest(const double balance) {
    return balance * interest_rate(balance) / PERCENT_DIVISOR;
}

// annual_balance_update calculates the annual balance update, taking into
// account the interest rate.
double annual_balance_update(const double balance) {
    return balance * (1 + interest_rate(balance) / PERCENT_DIVISOR);
}

// years_until_desired_balance calculates the minimum number of years required
// to reach the desired balance.
int years_until_desired_balance(double balance, double target_balance) {
    // Can't reach positive target with a negative balance and vice versa.
    const auto reachable = (target_balance > 0) == (balance > 0);
    if (!reachable)
        return -1;

    auto current_balance = balance;
    auto years = 0;
    while ((target_balance - current_balance > 0) == (target_balance > 0)) {
        current_balance = annual_balance_update(current_balance);
        ++years;
    }
    return years;
}