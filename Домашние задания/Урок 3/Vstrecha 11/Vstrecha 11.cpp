#include <iostream>
#include <algorithm>

template<typename T>
void ShowArr(T* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

template<typename T>
T FindMax(T* arr, size_t size)
{
	T max = arr[0];

	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

template<typename T>
T FindMin(T* arr, size_t size)
{
	T min = arr[0];

	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

template<typename T>
void SortArr(T* arr, size_t size)
{
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				T b = arr[j]; 
				arr[j] = arr[j + 1]; 
				arr[j + 1] = b;
			}
		}
	}
}

template<typename T>
T BinarySearch(T* arr, size_t size, T key)
{
	bool flag = false;
	int left = 0, right = size - 1, mid;

	while ((left <= right) && !flag)
	{
		mid = (left + right) / 2;

		if (arr[mid] == key)
		{
			flag = true;
		}
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	if (flag)
	{
		return mid;
	}
	else
	{
		return -1;
	}
}

template<typename T>
void ChangeElement(T* arr, size_t size, int index, T value)
{
	if (index < 0 || index >= size)
	{
		std::cout << "Такого индекса не существует." << std::endl;
	}
	else
	{
		arr[index] = value;
		std::cout << "Элемент успешно изменен.";
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	const int size = 10;

	int arr[size] = {3, 2, 1, -100, 4214, 333, 89, 4, 33, -10};

	int max = FindMax(arr, size);
	std::cout << "Максимальный элемент: " << max << std::endl;

	int min = FindMin(arr, size);
	std::cout << "Минимальный элемент: " << min << std::endl;

	SortArr(arr, size);
	std::cout << "Отсортированный массив: ";
	ShowArr(arr, size);

	int key;
	std::cout << "\nВведите значение элемента, который нужно найти: ";
	std::cin >> key;
	int index = BinarySearch(arr, size, key);
	if (index != -1)
	{
		std::cout << key << " находится в массиве под индексом " << index << std::endl;
	}
	else
	{
		std::cout << "Элемент не найден." << std::endl;
	}

	int value_index, value;
	std::cout << "Введите индекс элемента, который хотите изменить: ";
	std::cin >> value_index;
	std::cout << "Введите значение нового элемента: ";
	std::cin >> value;
	ChangeElement(arr, size, value_index, value);
	ShowArr(arr, size);

	return 0;
}