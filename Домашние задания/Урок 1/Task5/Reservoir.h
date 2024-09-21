#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <conio.h>

class Reservoir
{
public:

	explicit Reservoir(const std::string& name, const std::string& type,
		const int& length, const int& width, const int& depth) :
		m_name{ name }, m_type{type}, m_length{length}, m_width{width}, m_depth{depth} {}

	Reservoir() : Reservoir{ "","",0,0,0 } {}
	
	void CompareArea(const Reservoir& res_to_compare) const;

	void CopyReservoirs(Reservoir& res_to_copy_into) const;

	int FindArea() const;

	int FindVolume() const;

	int GetResDepth() const;

	int GetResLength() const;

	std::string GetResName() const;

	std::string GetResType() const;

	int GetResWidth() const;

	bool IsOneType(const Reservoir& res_to_check) const;

	void PrintReservoirInfo() const;

	void SetReservoirData();

private:
	std::string m_name;
	std::string m_type;

	int m_length;
	int m_width;
	int m_depth;
};

