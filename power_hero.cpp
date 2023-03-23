#include <iostream>
#include <queue>

int numTest;
int num_mon;
int a[200005];
/*
7
1 2 5 0 4 3 0
*/
int main(int argc, char const *argv[])
{
    std::cin >> numTest;
    for (size_t i = 0; i < numTest; i++)
    {
        std::cin >> num_mon;
        int ans = 0;
        std::priority_queue<int> pqueue;
        for (size_t i = 0; i < num_mon; i++)
        {
            std::cin >> a[i];
            if (a[i] == 0)
            {
                if (!pqueue.empty())
                {
                    ans += pqueue.top();
                    pqueue.pop();
                }
            }
            pqueue.push(a[i]);
        }
        std::cout << ans << std::endl;
    }

    return 0;
}
