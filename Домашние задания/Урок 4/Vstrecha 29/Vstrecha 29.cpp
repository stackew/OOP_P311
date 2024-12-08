#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Car
{
    std::string model;
    int production_year;
    int engine_capacity;
    int price;

    Car(const std::string& m, int y, int e, int p)
        : model(m), production_year(y), engine_capacity(e), price(p) {}
};

class Cars
{
public:
    void AddCar(const Car& car)
    {
        cars.push_back(car);
    }

    void DeleteCar(const std::string& model)
    {
        cars.erase(std::remove_if(cars.begin(), cars.end(),
            [&model](const Car& car) { return car.model == model; }),
            cars.end());
    }

    void ShowCars() const
    {
        for (const Car& car : cars)
        {
            Cars::PrintCar(car);
        }
    }

    void SortByModel()
    {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.model < b.model;
            });
    }

    void SortByPrice()
    {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.price < b.price;
            });
    }

    void SortByYear()
    {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.production_year < b.production_year;
            });
    }

    void FindByModel(const std::string& model) const
    {
        auto it = std::find_if(cars.begin(), cars.end(),
            [&model](const Car& car) { return car.model == model; });

        if (it != cars.end())
        {
            PrintCar(*it);
        }
        else
        {
            std::cout << "Автомобиль с моделью " << model << " не найден." << std::endl;
        }
    }

    void FindByPrice(int price) const
    {
        auto it = std::find_if(cars.begin(), cars.end(),
            [price](const Car& car) { return car.price == price; });

        if (it != cars.end())
        {
            PrintCar(*it);
        }
        else
        {
            std::cout << "Автомобиль с ценой " << price << " не найден." << std::endl;
        }
    }

private:
    std::vector<Car> cars;

    void PrintCar(const Car& car) const
    {
        std::cout << "Модель машины: " << car.model << std::endl;
        std::cout << "Год выпуска: " << car.production_year << std::endl;
        std::cout << "Объем двигателя: " << car.engine_capacity << " куб.см" << std::endl;
        std::cout << "Цена: " << car.price << " рублей" << std::endl;
        std::cout << "---------------------" << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    Cars showroom;

    showroom.AddCar({ "Toyota", 2018, 1600, 1200000 });
    showroom.AddCar({ "BMW", 2020, 3000, 4500000 });
    showroom.AddCar({ "Audi", 2019, 2000, 2500000 });

    std::cout << "Список автомобилей:" << std::endl;
    showroom.ShowCars();

    std::cout << "Сортировка по модели:" << std::endl;
    showroom.SortByModel();
    showroom.ShowCars();

    std::cout << "Сортировка по цене:" << std::endl;
    showroom.SortByPrice();
    showroom.ShowCars();

    std::cout << "Сортировка по году выпуска:" << std::endl;
    showroom.SortByYear();
    showroom.ShowCars();

    std::cout << "Поиск по модели (BMW X5):" << std::endl;
    showroom.FindByModel("BMW X5");

    std::cout << "Поиск по цене (2500000):" << std::endl;
    showroom.FindByPrice(2500000);

    showroom.DeleteCar("Toyota Corolla");
    showroom.ShowCars();

    return 0;
}