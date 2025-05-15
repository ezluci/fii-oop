#include <iostream>
#include "Array.h"

class CompareInt : public Compare {
public:
    int CompareElements(void* e1, void* e2) {
        int a = *static_cast<int*>(e1);
        int b = *static_cast<int*>(e2);
        return a - b;
    }
};

int compareInt(const int& a, const int& b) {
    return b - a;
}

int main() {
    Array<int> arr;

    arr.Insert(0, 10);
    arr.Insert(1, 5);
    arr.Insert(2, 20);
    arr.Insert(3, 15);

    for (int i = 0; i < arr.GetSize(); ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';

    arr += 25;

    for (int i = 0; i < arr.GetSize(); ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';

    Array<int> arr2 = arr;

    arr.Delete(2);

    for (int i = 0; i < arr.GetSize(); ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';

    Array<int> arr3;
    arr3 = arr2;

    for (int i = 0; i < arr3.GetSize(); ++i)
        std::cout << arr3[i] << ' ';
    std::cout << '\n';

    arr.Sort(compareInt);

    for (int i = 0; i < arr.GetSize(); ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';

    CompareInt cmp;
    arr.Sort(&cmp);

    for (int i = 0; i < arr.GetSize(); ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';

    int index = arr.BinarySearch(15, compareInt);

    index = arr.Find(15);
    std::cout << "bs " << index << '\n';

    return 0;
}
