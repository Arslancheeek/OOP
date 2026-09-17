#ifndef FUNC_H
#define FUNC_H

#include <random>

template <typename T1>
T1 far(const T1& cel)
{
    return cel * 9.0 / 5.0 + 32.0;
}

template <typename T1>
T1 Mfar(const T1& cel)
{
    static std::mt19937 gen(std::random_device{}());

    T1 res = far(cel);

    if (std::bernoulli_distribution(0.5)(gen))
    {
        res += static_cast<T>(std::uniform_int_distribution<int>(1, 52)(gen));
    }

    return res;
}

#endif