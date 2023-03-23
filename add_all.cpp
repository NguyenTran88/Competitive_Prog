#include <iostream>
#include <queue>
#include <functional>
#include <vector>
/*
int main()
{
    while (true)
    {
        int m;
        std::cin >> m;
        if (m == 0)
        {
            break; // break when we read in input 0
        }
            // idea: go in, push all to min heap. Loop till size==1: each loop pop twice => get 2 min
            // add them together to get y, add y to count, and now push y back. lets say we start with 3+3 =>
            // pop empty and get 6=> push 6 back. we are done here but size == 1 => thats the stop condi

        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i = 1; i <= m; i++)
        {
            int x;
            std::cin >> x;
            pq.push(x);
        }
        int n, k, j;
        int ans;
        while (pq.size() > 1)
        {
            n = pq.top();
            pq.pop();
            k = pq.top();
            pq.pop();
            j = n + k;
            ans = ans + j;
            pq.push(j);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}*/

int main()
{
    while (true)
    {
        int n;
        std::cin >> n;
        if (n == 0)
        {
            break;
        }
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i = 1; i <= n; i++)
        {
            int x;
            std::cin >> x;
            pq.push(x);
        }
        long long ans = 0;
        while ((int)pq.size() > 1)
        {
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            ans += top1 + top2;
            pq.push(top1 + top2);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
