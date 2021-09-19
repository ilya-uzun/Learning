#include <iostream>

struct Array {
    int val;
    Array* previous;

    Array(int val, Array* previous) : val(val), previous(previous) {}

    int& operator[](size_t index) {
        if (index == 0) {
            return val;
        }
        return (*previous)[index - 1];
    }
};

void generator(size_t n, void(*payload)(Array), Array* previous = 0) {
    Array element(0, previous);
    if (n == 1) {
        payload(element);
    } else {
        generator(n - 1, payload, &element);
    }
}

size_t N;

void test(Array array) {
    for (size_t i = 0; i < N; ++i) {
        std::cin >> array[i];
    }
    for(size_t i = 0 ; i < N - 1; ++i) { 
        for(size_t j = 0 ; j < N - i - 1 ; ++j) {  
            if(array[j] > array[j+1]) {           
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp; 
            }
        }
    }
    for (size_t i = 0; i < N; ++i) {
        std::cout << array[i] << ' ';
    }
}

int main() {
    std::cin >> N;
    generator(N, test);
}