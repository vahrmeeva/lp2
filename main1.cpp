#include <iostream>

//Bubble sort

template <typename T>
static int BubbleSort(T arr[], int arr_size) {
    for (int i = 0; i < arr_size-1; i++) { // 2 вложенных цикла из-за того, чтобы уйти сравнивая за последний элемент
        for (int j = 0; j < arr_size-1; j++) {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j+1]);//свапаем соседние элементы, если левый меньше правого
        }
    }
}

int main() {
    srand (time(NULL)); // инициализируем рандом
    int i, n;           //переменные цикла, кол-во элементов массива
    std::cout << "put in n: " ; //Кол-во элементов массива
    std::cin >> n;
    int arr[n];     // целевой массив

    for (i = 0; i < n; i++){
        arr[i] = rand()%n+1;
        std::cout << arr[i];
        std::cout << " ";
    }
    std::cout << std::endl;

    int size_arr = sizeof(arr) / sizeof(arr[0]);
    std::cout << "size_arr = " << size_arr << std::endl;

    BubbleSort(arr, n);

    for (int i = 0; i < size_arr; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
