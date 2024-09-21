#include "Reservoir.h"
#include "FuncsLibrary.h"


void AddReservoir(std::vector<Reservoir>& reservoirs)
{
	Reservoir res;

	int int_add_method;
	AddMethods add_method;

	std::cout << "---Методы добавления водоема---" << std::endl;
	std::cout << "1)Вручную" << std::endl;
	std::cout << "2)Скопировать информацию о водоеме с другого водоема" << std::endl;
	std::cout << "Как вы хотите добавить водоем: ";
	std::cin >> int_add_method;
	add_method = static_cast<AddMethods>(int_add_method);

	switch (add_method)
	{
	case BY_HAND:
		res.SetReservoirData();
		reservoirs.push_back(res);
		std::cout << "Водоем успешно добавлен!" << std::endl;
		break;
	case COPY:
		CopyMethod(reservoirs);
		break;
	default:
		std::cout << "Вы ввели что-то не так." << std::endl;
		break;
	}
}

void CompareReservoirs(const std::vector<Reservoir>& reservoirs)
{
	std::string res_name1, res_name2;

	std::cout << "\nВведите название 1 водоема для сравнения: ";
	std::cin >> res_name1;
	std::cout << "\nВведите название 2 водоема для сравнения: ";
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
		std::cout << "При поиске водоемов произошла ошибка." << std::endl;
	}
}

void CopyMethod(std::vector<Reservoir>& reservoirs)
{
	std::string res_to_copy_from_name;

	std::cout << "Введите название водоема, с которого хотите скопировать информацию: ";
	std::cin >> res_to_copy_from_name;

	auto it = std::find_if(reservoirs.begin(), reservoirs.end(),
		[&res_to_copy_from_name](const Reservoir& reservoir) { return reservoir.GetResName() == res_to_copy_from_name; });

	if (it != reservoirs.end())
	{
		Reservoir res_to_copy_into;
		Reservoir res_to_copy_from = *it;

		res_to_copy_from.CopyReservoirs(res_to_copy_into);
		reservoirs.push_back(res_to_copy_into);
		std::cout << "Водоем успешно скопирован и добавлен!" << std::endl;
	}
	else
	{
		std::cout << "Не удалось скопировать объект." << std::endl;
	}

}

void DeleteReservoir(std::vector<Reservoir>& reservoirs)
{
	std::string res_name;

	std::cout << "\nВведите название водоема, которого хотите удалить: ";
	std::cin >> res_name;

	auto it = std::find_if(reservoirs.begin(), reservoirs.end(),
		[&res_name](const Reservoir& reservoir) { return reservoir.GetResName() == res_name; });

	if (it != reservoirs.end())
	{
		reservoirs.erase(it);
		std::cout << "Водоем успешно удален." << std::endl;
	}
	else
	{
		std::cout << "Такой водоем не найден." << std::endl;
	}
}

void PrintReservoirsInfo(const std::vector<Reservoir>& reservoirs)
{
	std::cout << "Список водоемов: " << std::endl;

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
		std::cout << "\nФайл не удалось открыть." << std::endl;
	}
	else
	{
		for (const Reservoir& res : reservoirs)
		{
			file.write((char*)&res, sizeof(Reservoir));
		}

		std::cout << "\nСписок бинарно сохранен в файл!" << std::endl;
	}

	file.close();
}

void SaveInfoToFile(const std::vector<Reservoir>& reservoirs)
{
	std::ofstream file;

	file.open("Reservoirs.txt");

	if (!file.is_open())
	{
		std::cout << "\nФайл не удалось открыть." << std::endl;
	}
	else
	{
		file << "Список водоемов: ";
		for (const Reservoir& res : reservoirs)
		{
			file << "\n\nНазвание: " << res.GetResName();
			file << "\nТип: " << res.GetResType();
			file << "\nДлина: " << res.GetResLength();
			file << "\nШирина: " << res.GetResWidth();
			file << "\n\nГлубина: " << res.GetResDepth();
			file << "\nПлощадь: " << res.FindArea();
			file << "\nОбъем: " << res.FindVolume();
		}

		std::cout << "\nСписок успешно сохранен в файл!" << std::endl;
	}

	file.close();
}

void ShowMenu()
{
	std::cout << "----Меню----" << std::endl;
	std::cout << "1)Добавить водоем" << std::endl;
	std::cout << "2)Удалить водоем" << std::endl;
	std::cout << "3)Вывести информацию о водоемах на экран" << std::endl;
	std::cout << "4)Сравнить площадь водоемов одного типа" << std::endl;
	std::cout << "5)Сохранить информацию о водоемах в файл" << std::endl;
	std::cout << "6)Сохранить информацию о водоемах в бинарный файл" << std::endl;
	std::cout << "7)Выйти" << std::endl;
	std::cout << "Что вы хотите сделать: ";
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
		std::cout << "Программма успешно завершена." << std::endl;
		break;
	default:
		std::cout << "Вы ввели что-то не так." << std::endl;
		break;
	}
}