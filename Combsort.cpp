#include <bits/stdc++.h>
using namespace std;

int getNextGap(int gap)
{
    gap = (gap * 10) / 13;

    if (gap < 1)
        return 1;
    return gap;
}

void combSort(int a[], int n)
{
    // Инициализация зазора
    int gap = n;

    // Инициализация swapped как true, чтобы убедиться, что
    // цикл выполняется
    bool swapped = true;

    while (gap != 1 || swapped == true) {
        // Найти следующий зазор
        gap = getNextGap(gap);

        // Инициализация swapped как false, чтобы мы могли
        // проверить, произошла замена или нет
        swapped = false;

        // Сравнить все элементы с текущим пробелом
        for (int i = 0; i < n - gap; i++) {
            if (a[i] > a[i + gap]) {
                swap(a[i], a[i + gap]);
                swapped = true;
            }
        }
    }
}

int main()
{
    int a[] = { 8, 4, 1, 56, 3, -44, 23, -6, 28, 0 };
    int n = sizeof(a) / sizeof(a[0]);

    combSort(a, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}