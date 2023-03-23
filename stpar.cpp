#include <iostream>
#include <stack>

int n;
int a[1000];
int main()
{
    /* code */
    std::cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::stack<int> stack;
    int tracker = 1; // since we are looking for the next elemetn: 1 (there's no 0)
    for (size_t i = 0; i < n; i++)
    {
        while (stack.empty() == false && stack.top() == tracker)
        {
            tracker++;
            stack.pop();
        }
        if (a[i] != tracker)
        {
            stack.push(a[i]);
        }
        else
        {
            tracker++;
        }
    }
    // after, processing the whole arr, clear stack
    while (stack.empty() == false && stack.top() == tracker)
    {
        tracker++;
        stack.pop();
    }
    if (tracker == n + 1)
    {
        std::cout << "yes" << std::endl;
    }
    else
    {
        std::cout << "no" << std::endl;
    }

    return 0;
}
