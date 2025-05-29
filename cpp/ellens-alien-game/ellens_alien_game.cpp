namespace targets {
	class Alien
	{
	public:
		int x_coordinate;
		int y_coordinate;

		Alien(int x, int y)
			: x_coordinate{x}, y_coordinate{y}, m_health{3} {}

		[[nodiscard]] auto get_health() const { return m_health; }
		[[nodiscard]] bool is_alive() const { return m_health > 0; }

		bool hit()
		{
			if (m_health > 0)
				m_health -= 1;
			return true;
		}

		bool teleport(int x_new, int y_new)
		{
			x_coordinate = x_new;
			y_coordinate = y_new;
			return true;
		}

		[[nodiscard]] bool collision_detection(const Alien &other) const
		{
			return x_coordinate == other.x_coordinate &&
				y_coordinate == other.y_coordinate;
		}
	private:
		int m_health;
	};

}  // namespace targets