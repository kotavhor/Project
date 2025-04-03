#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

const int MAX_SIZE = 100;

template <class T>
T MultyEvenElemnts(T* arr, int32_t size);
template <class T>
T SumZerosElemnts(T* arr, int32_t size);

template <class T>
void Module(T* arr, int32_t size);

template <class T>
void InputArray(T* arr, int32_t size);

int32_t InputSize(int32_t& size);

template <class T>
void InputRandomArray(T* arr, int32_t size);

template <class T>
void OutputArray(T* arr, int32_t size);

int main() {
    setlocale(LC_ALL, "Russian");

    int32_t size{};
    int32_t choice{};
    double arr[MAX_SIZE];

    std::cout << "Выберите режим:\n1. Ввести массив вручную\n2. Заполнить массив случайно\n";
    std::cin >> choice;

    InputSize(size);

    switch (choice) {
    case 1:
        InputArray(arr, size);
        break;

    case 2:
        InputRandomArray(arr, size);
        break;
    }

    std::cout << "Произведение: " << MultyEvenElemnts(arr, size) << '\n';
    std::cout << "Сумма элементов между нулями: " << SumZerosElemnts(arr, size) << '\n';
    std::cout << "Массив после модуляции: " << std::endl;

    Module(arr, size);
    OutputArray(arr, size);

    return 0;
}

template <class T>
void InputArray(T* arr, int32_t size) {
    std::cout << "Введите " << size << " элементов массива:" << std::endl;
    for (int32_t i = 0; i < size; ++i) {
        std::cout << "Элемент " << i + 1 << ": ";
        std::cin >> arr[i];
    }
}

int32_t InputSize(int32_t& size) {
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    return size;
}

template <class T>
void OutputArray(T* arr, int32_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << '\n';
    }
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
    for (size_t i = 1; i < size; i += 2) {
        multy *= arr[i];
    }
    return multy;
}

template <class T>
T SumZerosElemnts(T* arr, int32_t size) {
    T sum{ 0 };
    int32_t FirstZeroIndex{ -1 };
    int32_t SecondZeroIndex{ -1 };
    for (size_t i = 0; i < size; i++) {
        if (arr[i] == 0) {
            if (FirstZeroIndex == -1) {
                FirstZeroIndex = i;
            }
            else {
                SecondZeroIndex = i;
            }
        }
    }

    if (SecondZeroIndex != -1) {
        for (FirstZeroIndex++; FirstZeroIndex < SecondZeroIndex; FirstZeroIndex++) {
            sum += arr[FirstZeroIndex];
        }
    }
    return sum;
}

template <class T>
void Module(T* arr, int32_t size) {
    int32_t new_size = size;
    for (int32_t i = 0; i < new_size;) {
        if (std::abs(arr[i]) >= 1) {
            std::swap(arr[i], arr[--new_size]);
            arr[new_size] = 0;
        }
        else {
            ++i;
        }
    }
}
