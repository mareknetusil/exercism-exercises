namespace hellmath {

	enum class AccountStatus
	{
		troll,
		guest,
		user,
		mod
	};

	enum class Action
	{
		read,
		write,
		remove
	};

	bool display_post(AccountStatus poster, AccountStatus viewer)
	{
		if (poster == AccountStatus::troll)
			return viewer == AccountStatus::troll;

		return true;
	}

	bool permission_check(Action action, AccountStatus user)
	{
		if (user == AccountStatus::guest)
			return action == Action::read;

		if (user == AccountStatus::user || user == AccountStatus::troll)
			return action == Action::write || action == Action::read;

		return true;
	}

	bool valid_player_combination(AccountStatus first, AccountStatus second)
	{
		if (first == AccountStatus::guest || second == AccountStatus::guest)
			return false;

		if (first == AccountStatus::troll || second == AccountStatus::troll)
			return first == second;

		return true;
	}

	bool has_priority(AccountStatus first, AccountStatus second)
	{
		return first > second;
	}

}  // namespace hellmath