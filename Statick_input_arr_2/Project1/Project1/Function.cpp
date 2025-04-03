#include<iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

template <class T>
void InputArray(T* arr, int32_t size) {
	std::cout << "¬ведите " << size << " элементов массива:" << std::endl;
	for (int32_t i = 0; i < size; ++i) {
		std::cout << "Ёлемент " << i + 1 << ": ";
		std::cin >> arr[i];
	}
}


int32_t InputSize(int32_t& size) {

	std::cout << "¬ведите размер массива: ";
	std::cin >> size;


	return size;

}

template <class T>
void InputRandomArray(T* arr, int32_t size) {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	for (int32_t i = 0; i < size; ++i) {
		arr[i] = std::rand();
	}
}


template <class T> 
T MultyEvenElemnts(T* arr, int32_t size) {
	T multy{ 1 };
	for (size_t i = 1; i < size; i += 2)
	{
		multy *= arr[i];
	}
	return multy;
}

template <class T>
T SumZerosElemnts(T* arr, int32_t size) {
	T sum{ 0 };
	int32_t FirstZeroIndex{ -1 };
	int32_t SecondZeroIndex{ -1 };
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == 0) {
			if (FirstZeroIndex == -1) {
				FirstZeroIndex = i;
			}
			else
			{
				SecondZeroIndex = i;
			}
		}
	}

	if (SecondZeroIndex != -1) {

		for (FirstZeroIndex++; FirstZeroIndex < SecondZeroIndex; FirstZeroIndex++)
		{
			sum += arr[FirstZeroIndex];
		}

	}
	return sum;

}

template <class T>
void Module(T* arr, int32_t& size) {
	for (int32_t i = 0; i < size; ++i) {
		if (std::abs(arr[i]) > 1) {
			arr[i] = 0;
			std::swap(arr[i], arr[--size]);
		}
	}
}