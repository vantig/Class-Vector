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
   
   
    int* ptr=nullptr;
    std::cout << *v.find(ptr, 3);
  


    system("pause");
    return 0;
}