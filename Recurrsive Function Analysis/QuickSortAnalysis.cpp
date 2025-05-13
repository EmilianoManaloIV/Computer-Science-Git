#include <iostream>
#include <random>
#include <chrono>

// Fill the array with random integers
void fillRandom(int* array, size_t size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1000);

    for (size_t i = 0; i < size; ++i) {
        array[i] = dis(gen);
    }
}
void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int p = i + 1;

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}


// Your function to time — can be replaced with your own logic
void yourFunction(int* array, size_t size) {
    // Example operation: compute sum
    long long sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += array[i];
    }
}

int main() {
    size_t size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* array = new int[size]; // Fixed-size array on the heap

    fillRandom(array, size);

    // Time measurement
    auto start = std::chrono::high_resolution_clock::now();

    // === Insert your function here ===
    quickSort(array, 0, size);
    // ================================

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;

    std::cout << "Function execution time: " << elapsed.count() << " ms\n";

    delete[] array;
    return 0;
}
