#include "Header.h"

int main()
{
    Vector <int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.printVector();
    v.erase(2);
    std::cout << v.getCapacity() << "\n";
    v.printVector();


    system("pause");
    return 0;
}