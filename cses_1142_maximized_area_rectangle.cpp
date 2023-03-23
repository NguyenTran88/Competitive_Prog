#include <iostream>
#include <stack>
#include <math.h>
std::stack<int> stack;
int n;
int a[200005];
int prePos[200005], sufPos[200005];
/*
8
4 1 5 3 3 2 4 1*/

int main()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    stack.push(0);
    for (size_t i = 01; i <= n; i++)
    {
        while (!stack.empty() && a[stack.top()] >= a[i])
        {
            stack.pop();
        }
        // no need for these if/else statement since we pushed in 0, and a[0] = 0, so it's always
        //  going to stay in the stack and not get popped by the while loop condition up there
        if (!stack.empty())
        {
            prePos[i] = stack.top();
        }
        else
        {
            prePos[i] = 1;
        }
        stack.push(i);
    }
    while (!stack.empty())
    {
        stack.pop();
    }
    // 9 7 6   8
    stack.push(n + 1);
    for (size_t i = 01; i <= n; i++)
    {
        while (!stack.empty() && a[stack.top()] >= a[i])
        {
            sufPos[stack.top()] = i;
            stack.pop();
        }
        stack.push(i);
    }
    long long ans = -1;
    for (int i = 1; i <= n; i++)
    {
        ans = std::max(ans, 1LL * a[i] * (sufPos[i] - prePos[i] - 1));
        std::cout << a[i] << " and length ";
        std::cout << sufPos[i] - prePos[i] - 1 << std::endl;
    }
    std::cout << ans;
    return 0;
}