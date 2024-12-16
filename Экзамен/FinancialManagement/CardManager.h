#pragma once

#include "Libraries.h"

class Card 
{
public:
    Card() : m_type(NONE), m_number(0), m_balance(0) {}

    void SetType();
    void SetNumber();
    int GetNumber() const;
    void OutputInfo() const;
    void DepositMoney();
    void WithdrawMoney();
    void GenerateReportForPeriod(int days_back) const;
    void GenerateTopExpenses(int days_back) const;
    void GenerateTopCategories(int days_back) const;

protected:
    void SetCustomDateForExpense(int amount, const std::string& category, const std::string& custom_date);

private:
    CardType m_type;
    int m_number;
    int m_balance;
    std::vector<Expenses> m_expenses;

    std::string FormatTime(std::time_t timestamp) const;
    std::time_t ParseDate(const std::string& date) const;

};


class Manager
{
public:
    void Start();

private:
    std::vector<Card> m_wallet;

    void CreateCard();
    void DeleteCard();
    void OutputWalletInfo() const;
    void Deposit();
    void Withdraw();
    void PrintReport() const;
    void PrintTopExpenses() const;
    void PrintTopCategories() const;
    void SaveToFile(const std::string& filename) const;
    void PrintMenu() const;

};
