// Combsort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;

    numbers.push_back(7);
    numbers.push_back(4);
    numbers.push_back(18);
    numbers.push_back(8);
    numbers.push_back(12);
    numbers.push_back(6);
    numbers.push_back(3);
    numbers.push_back(-5);
    numbers.push_back(9);
    numbers.push_back(5);
    numbers.push_back(1);
    numbers.push_back(16);
    numbers.push_back(17);
    numbers.push_back(19);
    numbers.push_back(-14);
    numbers.push_back(2);
    numbers.push_back(13);
    numbers.push_back(10);
    numbers.push_back(15);
    numbers.push_back(11);

    for (int gap = numbers.size(); gap > 0; gap--) {
        for (int i = 0; i + gap < numbers.size(); i++) {
            if (numbers[i] > numbers[i + gap]) {
                int temp = numbers[i + gap];
                numbers[i + gap] = numbers[i];
                numbers[i] = temp;
            }
        }
    }
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " " << std::endl;
    }
}