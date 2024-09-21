#include "Reservoir.h"

void Reservoir::CompareArea(const Reservoir& res_to_compare) const
{
	if (this->IsOneType(res_to_compare))
	{
		if (this->FindArea() > res_to_compare.FindArea())
		{
			std::cout << "������� " << this->m_name << " ������ ������� " << res_to_compare.m_name << std::endl;
		}
		else if (this->FindArea() < res_to_compare.FindArea())
		{
			std::cout << "������� " << this->m_name << " ������ ������� " << res_to_compare.m_name << std::endl;
		}
		else
		{
			std::cout << "������� " << this->m_name << " ����� ������� " << res_to_compare.m_name << std::endl;
		}
	}
	else
	{
		std::cout << "������� ����� ������ ����" << std::endl;
	}
}

void Reservoir::CopyReservoirs(Reservoir& res_to_copy_into) const
{
	res_to_copy_into = *this;
}

int Reservoir::FindArea() const
{
	return m_length * m_width;
}

int Reservoir::FindVolume() const
{
	return m_length * m_width * m_depth;
}

int Reservoir::GetResDepth() const
{
	return m_depth;
}

int Reservoir::GetResLength() const
{
	return m_length;
}

std::string Reservoir::GetResName() const
{
	return m_name;
}

std::string Reservoir::GetResType() const
{
	return m_name;
}

int Reservoir::GetResWidth() const
{
	return m_width;
}

bool Reservoir::IsOneType(const Reservoir& res_to_check) const
{
	return this->m_type == res_to_check.m_type;
}

void Reservoir::PrintReservoirInfo() const
{
	std::cout << "��������: " << m_name << std::endl;
	std::cout << "���: " << m_type << std::endl;
	std::cout << "�����: " << m_length << std::endl;
	std::cout << "������: " << m_width << std::endl;
	std::cout << "�������: " << m_depth << std::endl;
	std::cout << "�����: " << this->FindVolume() << std::endl;
	std::cout << "�������: " << this->FindArea() << std::endl;
}

void Reservoir::SetReservoirData()
{
	std::cout << "������� �������� �������: ";
	std::cin >> m_name;
	std::cout << "������� ��� �������: ";
	std::cin >> m_type;
	std::cout << "������� ����� �������: ";
	std::cin >> m_length;
	std::cout << "������� ������ �������: ";
	std::cin >> m_width;
	std::cout << "������� ������� �������: ";
	std::cin >> m_depth;
}