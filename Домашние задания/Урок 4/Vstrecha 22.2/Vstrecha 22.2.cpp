#include <iostream>
#include <fstream>
#include <string>


class Exception : public std::exception 
{
public:
    explicit Exception(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override 
    {
        return message.c_str();
    }
private:
    std::string message;
};


class MathException : public Exception 
{
public:
    explicit MathException(const std::string& msg) : Exception("Математическая ошибка: " + msg) {}
};

class DivisionByZeroException : public MathException 
{
public:
    DivisionByZeroException() : MathException("деление на ноль невозможно.") {}
};



class MemoryException : public Exception 
{
public:
    explicit MemoryException(const std::string& msg) : Exception("Ошибка памяти: " + msg) {}
};

class AllocationException : public MemoryException 
{
public:
    AllocationException() : MemoryException("не удалось выделить память.") {}
};



class FileException : public Exception 
{
public:
    explicit FileException(const std::string& msg) : Exception("ошибка с файлом: " + msg) {}
};

class FileNotFoundException : public FileException 
{
public:
    explicit FileNotFoundException(const std::string& filename)
        : FileException("файл не найден: " + filename) {}
};


void DivisionEx(int a, int b)
{
    if (b == 0) 
    {
        throw DivisionByZeroException();
    }
    int result = a / b;
    std::cout << "Результат: " << result << std::endl;
}

void AllocateMemoryEx(int size)
{
    if (size > 6) 
    { 
        throw AllocationException();
    }
    int* arr = new int[size];

    delete[] arr;
}

void OpenFileEx(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw FileNotFoundException(filename);
    }
    std::cout << "Файл успешно открыт: " << filename << std::endl;
    file.close();
}

int main()
{
    setlocale(LC_ALL, "rus");

    try 
    {
        
        DivisionEx(10, 0);
    }
    catch (const Exception& ex) 
    {
        std::cerr << ex.what() << std::endl;
    }

    try
    {
        AllocateMemoryEx(7);
    }
    catch (const Exception& ex) 
    {
        std::cerr << ex.what() << std::endl;
    }

    try 
    {
        OpenFileEx("test_file.txt");
    }
    catch (const Exception& ex) 
    {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}