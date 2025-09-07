#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

    LinkedList<int> list;
    list.push_front(10);
    list.push_front(1000);
    list.push_back(200);
    list.push_back(5000);
    list.push_back(70);
    list.push_back(9000);
    cout << list.front() << endl;
    list.print();
    cout << list[0] << endl; // 1
    cout << list.empty() << endl;
    list.sort();
    list.print();
}