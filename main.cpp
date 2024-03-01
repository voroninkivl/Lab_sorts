//
//  main.cpp
//  Lab_1
//
//  Created by Кирилл Воронин on 26.02.2024.
//

#include <ctime>
#include <iostream>
#include <vector>

template<typename Type>

void printArray(const std::vector<Type>& array) {
    
    
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    
    std::cout << std::endl;
}

// Функция для рандомного заполнения вектора числами в заданном диапазоне
template<typename Type>

void randomFill(std::vector<Type> &arr, Type lower, Type upper) {
    std::srand(std::time(nullptr)); //установка начального значения для генератора случайных чисел

    Type range = upper - lower + 1;
    
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = rand() % range + lower; //генерация случайного числа в заданном диапазоне
    }
}


//функция для разделения массива на две части относительно pivot
template<typename Type>

int partition(std::vector<Type> &arr, int low, int high) {
    //выбираем случайный индекс в пределах диапазона минимум и максимум
    
    std::srand(std::time(0));
    int randomInd = low + std::rand() % (high - low + 1);
    
    Type pivot = arr[randomInd]; //опорный элемент (pivot)

    //меняем местами опорный элемент (pivot) и последний элемент
    std::swap(arr[randomInd], arr[high]);

    int i = low; //индекс элемента, который меньше или равен опорному элементу

    for (int j = low; j < high; ++j) {
        //если текущий элемент меньше или равен опорному (pivot )
        if (arr[j] <= pivot) {
            Type temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            ++i;
        }
    }
    //меняем местами опорный элемент (pivot)) и элемент, находящийся на его финальной позиции
    Type temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    
    return i;
}

template<typename Type>

void quickSort(std::vector<Type> &arr, int low, int high) {
    if (low < high) {
        
        int divide = partition(arr, low, high); //вызываем функцию partition для разделения вектора
        quickSort(arr, low, divide - 1); //сортируем левую часть с помощью рекурсии
        quickSort(arr, divide + 1, high); //сортируем правую часть с помощью рекурсии
    }
}


/*int main() {
    
    int num = 0, max = 0, min = 0;
    std::cout << "Введите размер массива: ";
    std::cin >> num;
    std::vector<int> arr(num);
    std::cout << "Введите максимальное число массива: ";
    
    
    std::cin >> max;
    std::cout << "Введите минимальное число массива: ";
    std::cin >> min;

    randomFill(arr, min, max); //заполняем вектор случайными числами от минимального заданного числа до максимального

    std::cout << "Исходный массив: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Отсортированный массив: ";
    printArray(arr);


    return 0;
}*/





//Insection Sort


template<typename Type>

void insertionSort(std::vector<Type>& array) {
    int n = array.size();
    for (int i = 1; i < n; ++i) {
        Type position = array[i];
        int j = i - 1;
        while ((j >= 0) && (array[j] > position)) {
            
            
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = position;
    }
}


//функция для вывода вектора на экран

template<typename Type>

void printTArray(const std::vector<Type> &array) {
    for (const auto& element : array) {
        std::cout << element << " ";
        
    }
    std::cout << std::endl;
}


/*int main() {
    
   int num = 0, max = 0, min = 0;
    std::cout << "Введите размер массива: " << " ";
 
    std::cin >> num;
    std::vector<int> arr(num);
    std::cout << "Введите максимальное число массива: " << " ";
    std::cin >> max;
    std::cout << "Введите минимальное число массива: " << " ";
    std::cin >> min;
 
    randomFill(arr, min, max); //заполняем вектор случайными числами от минимального заданного числа до максимального

    std::cout << "Исходный массив: ";
    printArray(arr);

    insertionSort(arr);

    std::cout << "Отсортированный массив: ";
    printArray(arr);
    return 0;
}*/


//Bubble Sort

template<typename Type>

void bubbleSort(std::vector<Type> &array) {
    int n = array.size();
    bool swapped; //флаг, который показывает, были ли какие-либо свапы на текущей итерации
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            
            
            if (array[j] > array[j + 1]) {
                Type temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) { //если на текущей итерации не было свапов, значит массив уже отсортирован
            break;
        }
    }
}



int main() {
    int num = 0, max = 0, min = 0;
    std::cout << "Введите размер массива: " << " ";
    std::cin >> num;
 
    std::vector<int> arr(num);
    std::cout << "Введите максимальное число массива: " << " ";
    std::cin >> max;
    std::cout << "Введите минимальное число массива: " << " ";
    std::cin >> min;
 
 
    randomFill(arr, min, max); //заполняем вектор случайными числами от минимального заданного числа до максимального

    std::cout << "Исходный массив: ";
 
    printArray(arr);

    bubbleSort(arr);

    std::cout << "Отсортированный массив: ";
    printArray(arr);

    return 0;
}
