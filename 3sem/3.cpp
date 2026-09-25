#include <iostream>
#include <memory>

using namespace std;

int main() {
    cout << "--- 1. unique_ptr ---" << endl;
    {
        unique_ptr<int> num1 = make_unique<int>(100);

        cout << "значение num1: " << *num1 << endl;
    }

    cout << "\n--- 2. shared_ptr ---" << endl;
    {
        shared_ptr<int> num1 = make_shared<int>(200);
        shared_ptr<int> num2 = num1;

        cout << "значение num1: " << *num1<< ", счетчик: " << num1.use_count() << endl;

        num1.reset();

        if (num1 == nullptr) {
            cout << "num1 теперь nullptr, но num2 всё ещё работает: " << *num2 << endl;
            cout << "счетчик ссылок num2: " << num2.use_count() << endl;
        }
    }

    return 0;
}