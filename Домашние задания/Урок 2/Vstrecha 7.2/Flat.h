#pragma once
class Flat
{
public:
	Flat() = default;

	friend bool operator==(const Flat& flat1, const Flat& flat2);
	Flat& operator= (Flat&& flat);
	friend bool operator>(const Flat& flat1, const Flat& flat2);

private:
	double area;
	double cost;

	friend std::ostream& operator<<(std::ostream& output, const Flat& flat);
	friend std::istream& operator>>(std::istream& input, Flat& flat);
};

