#include <iostream>
#include <locale.h>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillingArray(int *a, int N)
{
    int x;
    cout << "Заполните массив из " << N  << " элементов: " << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        a[i] = x;
    }
}

void randomArray(int* a, int N)
{
    srand(time(0));
    cout << "Полученный массив из " << N << " элементов: " << endl;
    for (int i = 0; i < N; i++)
    {
        a[i] = 1 + rand() % 100;
    }
}

void printArray(int* a, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
}

bool isPalindrome(int* arr, int N) {
    for (int i = 0; i < N / 2; i++) {
        if (arr[i] != arr[N - 1 - i]) {
            return false;
        }
    }
    return true;
}

void func1()
{
    int N;
    cout << "Введите количество элементов массива " << endl;
    cin >> N;
    int* arr = new int[N];
    fillingArray(arr, N);

    int MAX = 0;

    for (int i = 0; i < N-1; i++)
    {
        if (arr[i] > MAX)
            MAX = arr[i];
    }

    cout << "Наибольший элемент массива :" << MAX << endl;
}

void func6() {
    int N;
    cout << "Введите количество элементов массива: ";
    cin >> N;

    int* arr = new int[N];
    randomArray(arr, N);
    printArray(arr, N);

    double max1 = 0;
    double max2 = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2 && arr[i] < max1) {
            max2 = arr[i];
        }
    }

    cout << "Второй максимальный элемент массива: " << max2 << endl;
}

void func7() {
    int N;
    cout << "Введите N: ";
    cin >> N;

    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }
    printArray(arr, N);

    srand(time(0));
    for (int i = N - 1; i > 0; i--) {
        int j = rand() % (i + 1); //cлучайный индекс от 0 до i
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    cout << "Массив в случайном порядке: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
}

void func11()
{
    int N;
    cout << "Введите количество элементов массива: ";
    cin >> N;

    int* arr = new int[N];
    fillingArray(arr, N);
    printArray(arr, N);

    if (isPalindrome(arr, N)) {
        cout << "Массив является палиндромом." << endl;
    }
    else {
        cout << "Массив не является палиндромом." << endl;
    }
}

int main()
{
    int choice;

    setlocale(LC_ALL, "Russian");
    cout << "Выберите функцию для выполнения:" << endl;
    cout << "6 - func6" << endl;
    cout << "7 - func7" << endl;
    cout << "11 - func11" << endl;

    cout << "Ваш выбор: ";
    cin >> choice;

    switch (choice) {
    case 6:
        func6();
        break;
    case 7:
        func7();
        break;
    case 11:
        func11();
        break;
    default:
        cout << "Неверный выбор. Попробуйте снова." << endl;
        break;
    }
    return 1;
}