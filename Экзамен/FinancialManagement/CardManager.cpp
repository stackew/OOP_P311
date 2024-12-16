#include "CardManager.h"

void Card::SetType()
{
    int enum_card_type;
    do
    {
        std::cout << "Выберите тип карты: ";
        std::cin >> enum_card_type;
        if (enum_card_type > 2 || enum_card_type < 1) {
            std::cout << "Ошибка: неправильно указан тип карты (введите цифру 1 или 2).\n";
        }
    } while (enum_card_type > 2 || enum_card_type < 1);
    m_type = static_cast<CardType>(enum_card_type);
}

void Card::SetNumber()
{
    int card_digits = 0;
    for (size_t i = 0; i < 7; ++i)
    {
        card_digits = card_digits * 10 + (std::rand() % 10);
    }
    m_number = 4 * 10000000 + card_digits;
}

int Card::GetNumber() const { return m_number; }

void Card::OutputInfo() const
{
    std::cout << "Тип карты: ";
    if (m_type == DEBUT)
        std::cout << "Дебютовая" << std::endl;
    else if (m_type == CREDIT)
        std::cout << "Кредитная" << std::endl;
    else
        std::cout << "None" << std::endl;

    std::cout << "Номер карты: " << m_number << std::endl;
    std::cout << "Баланс карты: " << m_balance << std::endl;
    std::cout << "---------------------" << std::endl;
}

void Card::DepositMoney()
{
    std::cout << "------- Пополнение карты ----------" << std::endl;
    int sum;
    std::cout << "Введите сумму для пополнения: ";
    std::cin >> sum;
    m_balance += sum;
    std::cout << "Карта " << m_number << " успешно пополнена." << std::endl;
}

void Card::WithdrawMoney()
{
    int sum;
    std::cout << "Введите сумму покупки:";
    std::cin >> sum;
    if (m_balance - sum < 0)
    {
        std::cout << "Недостаточно денег на балансе." << std::endl;;
        return;
    }
    m_balance -= sum;
    std::string category;
    std::cout << "Введите категорию товара: ";
    std::cin.ignore();
    std::getline(std::cin, category);
    std::time_t current_time = std::time(nullptr);
    Expenses purchase(sum, current_time, category);
    m_expenses.push_back(purchase);

    std::cout << "Сумма покупки: " << sum << std::endl;
    std::cout << "Категория: " << category << std::endl;
    std::cout << "Дата покупки: " << FormatTime(purchase.date) << std::endl;
}


void Card::GenerateReportForPeriod(int days_back) const
{
    std::time_t now = std::time(nullptr);
    for (const auto& expense : m_expenses)
    {
        if (difftime(now, expense.date) <= (days_back * 86400))
        {
            std::cout << "Категория: " << expense.category
                << ", Сумма: " << expense.amount
                << ", Дата: " << FormatTime(expense.date) << std::endl;
        }
    }
}

void Card::GenerateTopExpenses(int days_back) const
{
    std::vector<Expenses> filtered_expenses;
    std::time_t now = std::time(nullptr);

    for (const auto& expense : m_expenses)
    {
        if (difftime(now, expense.date) <= (days_back * 86400))
        {
            filtered_expenses.push_back(expense);
        }
    }

    std::sort(filtered_expenses.begin(), filtered_expenses.end(), [](const Expenses& a, const Expenses& b) {
        return a.amount > b.amount;
        });

    for (size_t i = 0; i < 3 && i < filtered_expenses.size(); ++i)
    {
        std::cout << "Категория: " << filtered_expenses[i].category
            << ", Сумма: " << filtered_expenses[i].amount
            << ", Дата: " << FormatTime(filtered_expenses[i].date) << std::endl;
    }
}

void Card::GenerateTopCategories(int days_back) const
{
    std::map<std::string, int> category_totals;
    std::time_t now = std::time(nullptr);

    for (const auto& expense : m_expenses)
    {
        if (difftime(now, expense.date) <= (days_back * 86400))
        {
            category_totals[expense.category] += expense.amount;
        }
    }

    std::vector<std::pair<std::string, int>> sorted_categories(category_totals.begin(), category_totals.end());
    std::sort(sorted_categories.begin(), sorted_categories.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    for (size_t i = 0; i < 3 && i < sorted_categories.size(); ++i)
    {
        std::cout << "Категория: " << sorted_categories[i].first
            << ", Сумма: " << sorted_categories[i].second << std::endl;
    }
}

void Card::SetCustomDateForExpense(int amount, const std::string& category, const std::string& custom_date)
{
    std::time_t custom_time = ParseDate(custom_date);
    Expenses purchase(amount, custom_time, category);
    m_expenses.push_back(purchase);

    std::cout << "Сумма покупки: " << amount << std::endl;
    std::cout << "Категория: " << category << std::endl;
    std::cout << "Дата покупки: " << FormatTime(purchase.date) << std::endl;
}

std::string Card::FormatTime(std::time_t timestamp) const
{
    std::tm tm = {};
    if (localtime_s(&tm, &timestamp) != 0)
    {
        std::cout << "Ошибка при преобразовании времени." << std::endl;
        return "";
    }

    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%d.%m.%Y", &tm);
    return std::string(buffer);
}


std::time_t Card::ParseDate(const std::string& date) const
{
    if (date.length() != 10)
    {
        std::cout << "Ошибка: неверный формат даты. Используйте ДД.ММ.ГГГГ." << std::endl;
        return std::time_t(0);
    }

    int day, month, year;
    if (sscanf_s(date.c_str(), "%d.%d.%d", &day, &month, &year) != 3) {
        std::cout << "Ошибка: неверный формат даты. Используйте ДД.ММ.ГГГГ." << std::endl;
        return std::time_t(0);
    }

    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900)
    {
        std::cout << "Ошибка: некорректные значения даты." << std::endl;
        return std::time_t(0);
    }

    std::tm tm = {};
    tm.tm_mday = day;
    tm.tm_mon = month - 1;
    tm.tm_year = year - 1900;
    return std::mktime(&tm);
}




void Manager::Start()
{
    bool is_running = true;
    while (is_running)
    {
        PrintMenu();
        std::cout << "Что вы хотите сделать: ";

        int user_input;
        std::cin >> user_input;

        Options option = static_cast<Options>(user_input);

        switch (option)
        {
        case Options::ADD_CARD:
            CreateCard();
            break;
        case Options::DELETE_CARD:
            DeleteCard();
            break;
        case Options::VIEW_WALLET:
            OutputWalletInfo();
            break;
        case Options::DEPOSIT:
            Deposit();
            break;
        case Options::MAKE_PURCHASE:
            Withdraw();
            break;
        case Options::PRINT_REPORT:
            PrintReport();
            break;
        case Options::EXPENSES_TOP:
            PrintTopExpenses();
            break;
        case Options::CATEGORY_TOP:
            PrintTopCategories();
            break;
        case Options::SAVE_TO_FILE:
            SaveToFile("reports.txt");
            break;
        case Options::EXIT:
            std::cout << "Завершение программы" << std::endl;
            is_running = false;
            break;
        default:
            std::cout << "Неверная опция. Пожалуйста, выберите правильный номер.\n";
            break;
        }
    }
}

void Manager::CreateCard()
{
    Card new_card;

    std::cout << "---Оформление карты---" << std::endl;
    std::cout << "Типы карт:" << "\n1) Дебютовая" << "\n2) Кредитная" << std::endl;
    new_card.SetType();
    new_card.SetNumber();
    m_wallet.push_back(new_card);
    std::cout << "Карта успешно создана, ей присвоен номер: " << new_card.GetNumber() << std::endl;
}

void Manager::DeleteCard()
{
    int number_to_delete;
    std::cout << "Введите номер карты, которую хотите удалить: ";
    std::cin >> number_to_delete;

    size_t erased_elements = std::erase_if(m_wallet,
        [number_to_delete](const Card& card) { return card.GetNumber() == number_to_delete; });
    if (erased_elements > 0)
        std::cout << "\nКарта успешно удалена.\n" << std::endl;
    else
        std::cout << "\nКарта с указанным номером не найдена.\n" << std::endl;
}

void Manager::OutputWalletInfo() const
{
    std::cout << "--------Ваш кошелек-----------" << std::endl;
    for (const Card& card : m_wallet)
    {
        card.OutputInfo();
    }
}

void Manager::Deposit() 
{
    if (m_wallet.empty())
    {
        std::cout << "Ваш кошелёк пуст. Сначала добавьте карту." << std::endl;
        return;
    }

    int card_number;
    std::cout << "Введите номер карты, которую хотите пополнить: ";
    std::cin >> card_number;

    auto it = std::find_if(m_wallet.begin(), m_wallet.end(),
        [card_number](const Card& card) { return card.GetNumber() == card_number; });

    if (it != m_wallet.end())
    {
        it->DepositMoney();
    }
    else
    {
        std::cout << "Карта с номером " << card_number << " не найдена.\n";
    }
}

void Manager::Withdraw() 
{
    if (m_wallet.empty()) 
    {
        std::cout << "Ваш кошелёк пуст. Сначала добавьте карту." << std::endl;;
        return;
    }

    int card_number;
    std::cout << "Введите номер карты, с которой хотите списать деньги: ";
    std::cin >> card_number;

    auto it = std::find_if(m_wallet.begin(), m_wallet.end(),
        [card_number](const Card& card) { return card.GetNumber() == card_number; });

    if (it != m_wallet.end())
    {
        it->WithdrawMoney();
    }
    else {
        std::cout << "Карта с номером " << card_number << " не найдена.\n";
    }
}

void Manager::PrintReport() const
{
    std::cout << "\n----- Отчет за день -----\n";
    for (const auto& card : m_wallet) {
        card.GenerateReportForPeriod(1);
    }

    std::cout << "\n----- Отчет за неделю -----\n";
    for (const auto& card : m_wallet) {
        card.GenerateReportForPeriod(7);
    }

    std::cout << "\n----- Отчет за месяц -----\n";
    for (const auto& card : m_wallet) {
        card.GenerateReportForPeriod(30);
    }
}

void Manager::PrintTopExpenses() const 
{
    for (const auto& card : m_wallet) 
    {
        std::cout << "\n--- Карта: " << card.GetNumber() << " ---" << std::endl;
        std::cout << "Топ-3 расходов за день:" << std::endl;
        card.GenerateTopExpenses(1);

        std::cout << "Топ-3 расходов за неделю:" << std::endl;
        card.GenerateTopExpenses(7);

        std::cout << "Топ-3 расходов за месяц:" << std::endl;
        card.GenerateTopExpenses(30);
    }
}

void Manager::PrintTopCategories() const 
{
    for (const auto& card : m_wallet) 
    {
        std::cout << "\n--- Карта:" << card.GetNumber() << " ---" << std::endl;
        std::cout << "Топ-3 категорий за день:" << std::endl;
        card.GenerateTopCategories(1);

        std::cout << "Топ-3 категорий за неделю:" << std::endl;
        card.GenerateTopCategories(7);

        std::cout << "Топ-3 категорий за месяц:" << std::endl;
        card.GenerateTopCategories(30);
    }
}

void Manager::SaveToFile(const std::string& filename) const
{
    std::ofstream file(filename);

    if (!file)
    {
        std::cout << "Ошибка: не удалось открыть файл для записи.\n";
        return;
    }

    std::streambuf* original_cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(file.rdbuf());

    PrintReport();
    PrintTopExpenses();
    PrintTopCategories();

    std::cout.rdbuf(original_cout_buffer);
    std::cout << "Информация успешно сохранена в файл: " << filename << std::endl;
}

void Manager::PrintMenu() const
{
    std::cout << "\n------- Менеджер карт -------" << std::endl;
    std::cout << "1)Добавить карту в кошелек" << std::endl;
    std::cout << "2)Удалить карту из кошелька" << std::endl;
    std::cout << "3)Вывести кошелек" << std::endl;
    std::cout << "4)Пополнить баланс" << std::endl;
    std::cout << "5)Совершить покупку" << std::endl;
    std::cout << "6)Сформировать отчет покупок" << std::endl;
    std::cout << "7)Сформировать рейтинг по затратам" << std::endl;
    std::cout << "8)Сформировать рейтинг по категориям" << std::endl;
    std::cout << "9)Сохранить отчеты и рейтинг в файл" << std::endl;
    std::cout << "10)Выйти" << std::endl;
}