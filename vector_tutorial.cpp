#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1 = {1, 2, 3};
    cout << v1[1] << endl;      // 2
    cout << v1.front() << endl; // 1
    cout << v1.back() << endl;  // 3

    // size: how many element currently in
    // capacity: vector doubles in size when meets its limit, capcity() returns current limit

    v1.push_back(9); // append 9 to the back => array is now 1,2,3,9
    v1.pop_back();   // remove and return last element in vector; => array is 1,2,3

    //  INSERT & ERASE in the middle of array
    v1.insert(v1.begin() + 3, 22); // insert 22 at index 3
    std::cout << v1[3] << endl;    // print 22
    // v1.erase(v1.size() - 1);   THIS WOULDN'T WORK SINCE ERASE'S PARAMETER IS AN ITERATOR
    v1.erase(v1.begin() + 2); // iterator returns v1[0], move that by 2 like pointer arithmetic
    // ^ above remove 2 from 1,2,3,22

    std::cout << "new array after deleting" << endl;
    // loop thru vector
    for (size_t i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << endl;
    }
}