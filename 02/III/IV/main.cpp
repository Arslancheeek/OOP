#include <iostream>
#include "func.h"

int main()
{
    int CelsINT;
    double CelsIDOU;

    std::cout << "Цельсия (int): ";
    std::cin >> CelsINT;

    std::cout << "Без рандома: " << far(CelsINT) << "\n";
    std::cout << "С рандомом: " << Mfar(CelsINT) << "\n\n";

    std::cout << "Цельсия (double): ";
    std::cin >> CelsIDOU;

    std::cout << "Без рандома: " << far(CelsIDOU) << "\n";
    std::cout << "С рандомом: " << Mfar(CelsIDOU) << "\n";

    return 0;
}