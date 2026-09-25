#include <iostream>

using namespace std;

int main() {
    int* number = new int(42);
    int maxSize = 6;
    int currentSize = 5;
    int* numbers = new int[maxSize];

    for (int i = 0; i < currentSize; ++i) 
    {
        numbers[i] = (i + 1) * 10;
    }

    cout << "тсходный массив: ";
    for (int i = 0; i < currentSize; ++i) 
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    int* oldNumber = number;
    delete number;
    number = nullptr;

    cout << "читаем через висячий указатель oldNumber: " << *oldNumber << endl;
    oldNumber = nullptr;

    int place = 2;
    int newNumber = 999;

    for (int i = currentSize; i > place; --i) 
    {
        numbers[i] = numbers[i - 1];
    }

    numbers[place] = newNumber;
    currentSize++;

    cout << "массив после вставки " << newNumber << " в середину: ";
    for (int i = 0; i < currentSize; ++i) 
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    delete[] numbers;
    numbers = nullptr;

    return 0;
}