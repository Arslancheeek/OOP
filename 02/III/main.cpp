#include <iostream>
#include "func.h"

int main()
{
    int CelsINT;
    double CelsDOU;

    std::cout << "Цельсия (int): ";
    std::cin >> CelsINT;

    std::cout << "Фаренгейт: " << far(CelsINT) << "\n\n";

    std::cout << "Цельсия (double): ";
    std::cin >> CelsDOU;

    std::cout << "Фаренгейт: " << far(CelsDOU) << "\n";

    return 0;
}