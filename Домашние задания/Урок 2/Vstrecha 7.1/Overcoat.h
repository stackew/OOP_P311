#pragma once

#include <string>

class Overcoat
{

public:
	Overcoat() = default;

	friend bool operator==(const Overcoat& overcoat1, const Overcoat& overcoat2);
	Overcoat& operator= (Overcoat&& overcoat);
	friend bool operator>(const Overcoat& overcoat1, const Overcoat& overcoat2);

private:
	std::string type;
	float cost;

	friend std::ostream& operator<<(std::ostream& output, const Overcoat& overcoat);
	friend std::istream& operator>>(std::istream& input, Overcoat& overcoat);
};

