#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>

template <class T>
T MultyElemntsSandwichMinMax(T* arr, int32_t size);

template <class T>
void RemoveNSmallestElements(T* arr, int32_t& size, int32_t n);

template <class T>
void Module(T* arr, int32_t size);

template <class T>
void InputArray(T* arr, int32_t size);

int32_t InputSize(int32_t& size);

template <class T>
void InputRandomArray(T* arr, int32_t size);

template <class T>
void OutputArray(T* arr, int32_t size);

void InputN(int32_t& n, int32_t size);

int main() {
    setlocale(LC_ALL, "Russian");

    int32_t size{};
    int32_t choice{};
    int32_t n{};

    std::cout << "Выберите режим:\n1. Ввести массив вручную\n2. Заполнить массив случайно\n";
    std::cin >> choice;

    InputSize(size);

    auto* arr = new double[size];

    switch (choice) {
    case 1:
        InputArray(arr, size);
        break;

    case 2:
        InputRandomArray(arr, size);
        break;

    default:
        std::cerr << "Некорректный выбор режима.\n";
        delete[] arr; 
        return 1;
    }

    std::cout << "Произведение элементов между минимальным и максимальным элементами: "
        << MultyElemntsSandwichMinMax(arr, size) << '\n';

    InputN(n, size);

    RemoveNSmallestElements(arr, size, n);

    std::cout << "Массив после удаления " << n << " наименьших элементов: " << std::endl;
    OutputArray(arr, size);

    std::cout << "Упорядочивание массива по возрастанию после модуляции: " << std::endl;
    Module(arr, size);
    OutputArray(arr, size);

    delete[] arr;

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
    for (int32_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

template <class T>
void InputRandomArray(T* arr, int32_t size) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int32_t i = 0; i < size; ++i) {
        arr[i] = static_cast<T>(std::rand() % 100);
    }
}

template <class T>
T MultyElemntsSandwichMinMax(T* arr, int32_t size) {
    T multy{ 1 };
    int32_t Min_element{ 0 }, Max_element{ 0 };

    for (int32_t i = 1; i < size; ++i) {
        if (arr[i] < arr[Min_element]) {
            Min_element = i;
        }
        if (arr[i] > arr[Max_element]) {
            Max_element = i;
        }
    }

    if (Min_element > Max_element) {
        std::swap(Min_element, Max_element);
    }

    for (int32_t i = Min_element + 1; i < Max_element; ++i) {
        multy *= arr[i];
    }

    return multy;
}

void InputN(int32_t& n, int32_t size) {
    do {
        std::cout << "Введите количество наименьших чисел для удаления из массива: ";
        std::cin >> n;
        if (n <= 0 || n > size) {
            std::cerr << "Ошибка: n должно быть больше 0 и меньше или равно размеру массива.\n";
        }
    } while (n <= 0 || n > size);
}

template <class T>
void RemoveNSmallestElements(T* arr, int32_t& size, int32_t n) {
    if (n <= 0 || n > size) {
        std::cerr << "Количество элементов для удаления некорректно.\n";
        return;
    }

    for (int32_t k = 0; k < n; ++k) {
        int32_t minIndex = 0;

        for (int32_t i = 1; i < size; ++i) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }

        for (int32_t i = minIndex; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }

        --size;
    }
}

template <class T>
void Module(T* arr, int32_t size) {
    std::sort(arr, arr + size, [](T a, T b) { 
        return std::abs(a) < std::abs(b);
        });
}

