#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <random>
#include <fstream>
#include <string>
#include <set>
#include <iomanip>
#include <sstream>

using namespace std;

const int M = 12;
const int N = 40;

// Функция складывает два значения
template <typename T2, typename T1>
T2 extMod(T1 val, T1 arg)
{
    return static_cast<T2>(val + arg);
}

// Вспомогательная функция для красивого форматирования float (2 знака после точки)
string formatFloat(float val) {
    ostringstream ss;
    ss << fixed << setprecision(2) << val;
    return ss.str();
}

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(-N, N);

    float arg = dist(gen);

    array<float, M> arr;
    vector<float> vec;
    list<float> lst;
    deque<float> deq;

    set<float> uniq;
    while (uniq.size() < M * 4)
    {
        uniq.insert(dist(gen));
    }

    set<float>::iterator it = uniq.begin();

    for (int i = 0; i < M; ++i) arr[i] = *it++;
    for (int i = 0; i < M; ++i) vec.push_back(*it++);
    for (int i = 0; i < M; ++i) lst.push_back(*it++);
    for (int i = 0; i < M; ++i) deq.push_back(*it++);

    // array -> vector
    vector<long> arrRez;
    for (int i = 0; i < M; ++i) {
        arrRez.push_back(extMod<long>(arr[i], arg));
    }

    // vector -> list
    list<long> vecRez;
    for (vector<float>::iterator iter = vec.begin(); iter != vec.end(); ++iter) {
        vecRez.push_back(extMod<long>(*iter, arg));
    }

    // list -> deque
    deque<long> lstRez;
    for (float x : lst) {
        lstRez.push_back(extMod<long>(x, arg));
    }

    // deque -> array
    array<long, M> deqRez;
    int k = 0;
    for (float x : deq) {
        deqRez[k++] = extMod<long>(x, arg);
    }

    vector<string> tablica;
    string names[4] = {"array", "vector", "list", "deque"};

    vector<vector<float>> inputs = {
        vector<float>(arr.begin(), arr.end()),
        vec,
        vector<float>(lst.begin(), lst.end()),
        vector<float>(deq.begin(), deq.end())
    };

    vector<vector<long>> outputs = {
        arrRez,
        vector<long>(vecRez.begin(), vecRez.end()),
        vector<long>(lstRez.begin(), lstRez.end()),
        vector<long>(deqRez.begin(), deqRez.end())
    };

    // Формируем строки таблицы
    for (int i = 0; i < 4; ++i)
    {
        string stroka = "| " + names[i] + " | ";

        for (float x : inputs[i])
        {
            stroka += formatFloat(x) + " ";
        }

        stroka += "| ";

        for (long x : outputs[i])
        {
            stroka += to_string(x) + " ";
        }

        stroka += "|";
        tablica.push_back(stroka);
    }

    ofstream file("result.md");
    if (!file.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }

    file << "# Результаты работы с контейнерами\n\n";
    file << "Общий второй аргумент функции: " << formatFloat(arg) << "\n\n";

    file << "| Контейнер | Исходные значения (float) | Результат (long) |\n";
    file << "|---|---|---|\n";

    for (const string& s : tablica)
    {
        file << s << "\n";
    }

    file.close();
    cout << "Файл result.md пересобран и стал компактным!" << endl;

    return 0;
}