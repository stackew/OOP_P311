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

	return 0;
}