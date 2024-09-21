#include "Reservoir.h"
#include "FuncsLibrary.h"


void AddReservoir(std::vector<Reservoir>& reservoirs)
{
	Reservoir res;

	int int_add_method;
	AddMethods add_method;

	std::cout << "---������ ���������� �������---" << std::endl;
	std::cout << "1)�������" << std::endl;
	std::cout << "2)����������� ���������� � ������� � ������� �������" << std::endl;
	std::cout << "��� �� ������ �������� ������: ";
	std::cin >> int_add_method;
	add_method = static_cast<AddMethods>(int_add_method);

	switch (add_method)
	{
	case BY_HAND:
		res.SetReservoirData();
		reservoirs.push_back(res);
		std::cout << "������ ������� ��������!" << std::endl;
		break;
	case COPY:
		CopyMethod(reservoirs);
		break;
	default:
		std::cout << "�� ����� ���-�� �� ���." << std::endl;
		break;
	}
}

void CompareReservoirs(const std::vector<Reservoir>& reservoirs)
{
	std::string res_name1, res_name2;

	std::cout << "\n������� �������� 1 ������� ��� ���������: ";
	std::cin >> res_name1;
	std::cout << "\n������� �������� 2 ������� ��� ���������: ";
	std::cin >> res_name2;

	auto it1 = std::find_if(reservoirs.begin(), reservoirs.end(),
		[&res_name1](const Reservoir& reservoir) { return reservoir.GetResName() == res_name1; });
	auto it2 = std::find_if(reservoirs.begin(), reservoirs.end(),
		[&res_name2](const Reservoir& reservoir) { return reservoir.GetResName() == res_name2; });

	if (it1 != reservoirs.end() && it2 != reservoirs.end())
	{
		Reservoir res1 = *it1;
		Reservoir res2 = *it2;

		res1.CompareArea(res2);
	}
	else
	{
		std::cout << "��� ������ �������� ��������� ������." << std::endl;
	}
}

void CopyMethod(std::vector<Reservoir>& reservoirs)
{
	std::string res_to_copy_from_name;

	std::cout << "������� �������� �������, � �������� ������ ����������� ����������: ";
	std::cin >> res_to_copy_from_name;

	auto it = std::find_if(reservoirs.begin(), reservoirs.end(),
		[&res_to_copy_from_name](const Reservoir& reservoir) { return reservoir.GetResName() == res_to_copy_from_name; });

	if (it != reservoirs.end())
	{
		Reservoir res_to_copy_into;
		Reservoir res_to_copy_from = *it;

		res_to_copy_from.CopyReservoirs(res_to_copy_into);
		reservoirs.push_back(res_to_copy_into);
		std::cout << "������ ������� ���������� � ��������!" << std::endl;
	}
	else
	{
		std::cout << "�� ������� ����������� ������." << std::endl;
	}

}

void DeleteReservoir(std::vector<Reservoir>& reservoirs)
{
	std::string res_name;

	std::cout << "\n������� �������� �������, �������� ������ �������: ";
	std::cin >> res_name;

	auto it = std::find_if(reservoirs.begin(), reservoirs.end(),
		[&res_name](const Reservoir& reservoir) { return reservoir.GetResName() == res_name; });

	if (it != reservoirs.end())
	{
		reservoirs.erase(it);
		std::cout << "������ ������� ������." << std::endl;
	}
	else
	{
		std::cout << "����� ������ �� ������." << std::endl;
	}
}

void PrintReservoirsInfo(const std::vector<Reservoir>& reservoirs)
{
	std::cout << "������ ��������: " << std::endl;

	for (const Reservoir& res : reservoirs)
	{
		res.PrintReservoirInfo();
		std::cout << std::endl;
	}
}

void Program()
{
	std::vector<Reservoir> reservoirs;

	int int_action;
	Actions action;

	do
	{
		ShowMenu();
		std::cin >> int_action;
		action = static_cast<Actions>(int_action);

		SwitchCase(reservoirs, action);

		_getch();
		system("cls");
	} while (action != EXIT);
}

void SaveInfoToBinFile(const std::vector<Reservoir>& reservoirs)
{
	std::ofstream file;

	file.open("Reservoirs.bin", std::ios_base::binary);

	if (!file.is_open())
	{
		std::cout << "\n���� �� ������� �������." << std::endl;
	}
	else
	{
		for (const Reservoir& res : reservoirs)
		{
			file.write((char*)&res, sizeof(Reservoir));
		}

		std::cout << "\n������ ������� �������� � ����!" << std::endl;
	}

	file.close();
}

void SaveInfoToFile(const std::vector<Reservoir>& reservoirs)
{
	std::ofstream file;

	file.open("Reservoirs.txt");

	if (!file.is_open())
	{
		std::cout << "\n���� �� ������� �������." << std::endl;
	}
	else
	{
		file << "������ ��������: ";
		for (const Reservoir& res : reservoirs)
		{
			file << "\n\n��������: " << res.GetResName();
			file << "\n���: " << res.GetResType();
			file << "\n�����: " << res.GetResLength();
			file << "\n������: " << res.GetResWidth();
			file << "\n\n�������: " << res.GetResDepth();
			file << "\n�������: " << res.FindArea();
			file << "\n�����: " << res.FindVolume();
		}

		std::cout << "\n������ ������� �������� � ����!" << std::endl;
	}

	file.close();
}

void ShowMenu()
{
	std::cout << "----����----" << std::endl;
	std::cout << "1)�������� ������" << std::endl;
	std::cout << "2)������� ������" << std::endl;
	std::cout << "3)������� ���������� � �������� �� �����" << std::endl;
	std::cout << "4)�������� ������� �������� ������ ����" << std::endl;
	std::cout << "5)��������� ���������� � �������� � ����" << std::endl;
	std::cout << "6)��������� ���������� � �������� � �������� ����" << std::endl;
	std::cout << "7)�����" << std::endl;
	std::cout << "��� �� ������ �������: ";
}

void SwitchCase(std::vector<Reservoir>& reservoirs, Actions& action)
{
	switch (action)
	{
	case ADD_RESERVOIR:
		AddReservoir(reservoirs);
		break;
	case DELETE_RESERVOIR:
		DeleteReservoir(reservoirs);
		break;
	case PRINT_RESERVOIRS_INFO:
		PrintReservoirsInfo(reservoirs);
		break;
	case COMPARE_RESERVOIRS:
		CompareReservoirs(reservoirs);
		break;
	case SAVE_INFO_TO_FILE:
		SaveInfoToFile(reservoirs);
		break;
	case SAVE_INFO_TO_BIN_FILE:
		SaveInfoToBinFile(reservoirs);
		break;
	case EXIT:
		std::cout << "���������� ������� ���������." << std::endl;
		break;
	default:
		std::cout << "�� ����� ���-�� �� ���." << std::endl;
		break;
	}
}