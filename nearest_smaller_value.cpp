#include <iostream>
#include <stack>

/*Input:
8
2 5 1 4 8 3 2 5

Output:
0 1 0 3 4 3 3 7*/
int main()
{
    int n;
    std::cin >> n;
    int a[10000];
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::stack<int> stack;
    stack.push(0); // the array is indexed 1 => push index 0 in because there's nothing on the left.
    for (size_t i = 0; i < n; i++)
    {
        while (!stack.empty() && a[stack.top() - 1] >= a[i])
        {
            stack.pop();
        }
        if (!stack.empty())
        {
            std::cout << stack.top();
        }
        else
        {
            std::cout << 0;
        }
        stack.push(i + 1);
    }
}