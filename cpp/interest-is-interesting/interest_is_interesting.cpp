#include <vector>
#include <utility>
#include <algorithm>

// interest_rate returns the interest rate for the provided balance.
double interest_rate(const double balance) {
    const std::vector<std::pair<int, double>> rates = {
        {0    , 3.213},
        {1'000, 0.5},
        {5'000, 1.621},
    };
    const auto highest_rate = 2.475;
    const auto it = std::find_if(
        std::begin(rates), std::end(rates),
        [&balance](const auto threshold) { return balance < threshold.first ; }
        );
    return it == std::end(rates) ? highest_rate : it->second;
}

// yearly_interest calculates the yearly interest for the provided balance.
double yearly_interest(const double balance) {
    return balance * interest_rate(balance) / 100.0;
}

// annual_balance_update calculates the annual balance update, taking into
// account the interest rate.
double annual_balance_update(const double balance) {
    return balance * (1 + interest_rate(balance) / 100.);
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