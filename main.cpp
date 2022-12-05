#include <iostream>
#include <cstdlib> // содержит srand() и rand()

//Quick Sort

template <typename T>
static int partition(T arr[], int idx_start, int idx_end)
{
    int idx_pivot = rand()%sizeof(arr)-1 +0; // выбираем рандомный элемент по которому будет делится исходный массив
    // rand
    int pivot = arr[idx_start];

    int counter = 0, i = 0, j = 0;

    for (int i = idx_start + 1; i <= idx_end; ++i) // сравниваем числа из массива с пайвотом, если он меньше его то идет на лево, наоборот-направо
        if (arr[i] <= pivot)
            counter++;

    idx_pivot = counter + idx_start;

    std::swap(arr[idx_pivot], arr[idx_start]);

    i = idx_start;
    j = idx_end;

    while (i < idx_pivot && j > idx_pivot) // 2 счестчика чисел слева и справа
    {
        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < idx_pivot && j > idx_pivot)
            std::swap(arr[i], arr[j]); //свапаем их если
    }
    return idx_pivot;
}

template <typename T>
void quickSort(T arr[], int idx_start, int idx_end)
{
    if (idx_start >= idx_end)
        return;
//  теперь пайвот находится в нужном месте
    int idx_pivot = partition(arr, idx_start, idx_end); //  теперь пайвот находится в нужном месте

    quickSort(arr, idx_start, idx_pivot - 1); // здесь мы сортируем элементы справа и слева, то есть до разделителя и после
    quickSort(arr, idx_pivot + 1, idx_end);

}




int main()
{
    srand (time(NULL)); // инициализируем рандом
    int i, n;           //переменные цикла, кол-во элементов массива
    std::cout << "put in n: " ; //Кол-во элементов массива
    std::cin >> n;
    double arr[n];// целевой массив

    for (i = 0; i < n; i++){
        arr[i] = (rand()%n)+1;
        std::cout << arr[i];
        std::cout << " ";
    }
    std::cout << std::endl;


    int size_arr = sizeof(arr) / sizeof(arr[0]);
    std::cout << "size_arr = " << size_arr << std::endl;

    quickSort(arr, 0, size_arr - 1);

    for (int i = 0; i < size_arr; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}