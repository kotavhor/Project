#include<iostream>
#include "Function.h"

const int MAX_SIZE = 100;

int main() {

	int32_t size{};
	int32_t arr[MAX_SIZE];
	int32_t choice{};
	std::cout << "choise 1 sami vvodite 2 random" << '\n';
	std::cin >> choice;
	InputSize(size);

	switch (choice)
	{
		case 1:
			InputArray(arr, size);

		case 2:
			InputRandomArray(arr, size);


		default:
			return -1;
	}

	MultyEvenElemnts(arr, size);
	SumZerosElemnts(arr, size);
	Module(arr, size);

}