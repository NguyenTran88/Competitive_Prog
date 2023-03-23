#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
/*STDIN       Function
-----       --------
5           Q = 5
1 4         insert 4
1 9         insert 9
3           print minimum
2 4         delete 4
3           print minimum*/

int main()
{
    int num, ope, para;
    std::cin >> num; // 5
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq, pq2;
    for (int i = 1; i <= num; i++)
    {
        std::cin >> ope;
        if (ope == 1)
        {
            std::cin >> para; // check if needs to reset ?
            pq.push(para);
        }
        else if (ope == 2)
        {
            std::cin >> para;
            pq2.push(para);
        }
        else
        {
            while (!pq.empty() && !pq2.empty() && pq.top() == pq2.top())
            {
                pq.pop();
                pq2.pop();
            }
            // if pq is empty ?
            // if top !=top
            std::cout << pq.top() << endl;
        }
    }
    return 0;
}
