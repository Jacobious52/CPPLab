// calcuate fib nums recursively
// Benchmark for fib.* for n = 40
// Rust: 2.9s
// Python: 93.6s
// C/C++: 1.8s

#include <cstdio>
#include <thread>

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fib(n-1) + fib(n-2);
    }
}

void print_fib(int i)
{
    printf("fib %d = %d\n", i, fib(i));
}

int main()
{
    const int n = 40;
    std::thread t[n];
    for (int i = 0; i < n; ++i)
    {
        t[i] = std::thread(print_fib, i);
    }

    for (int i = 0; i < n; ++i)
    {
        t[i].join();
    }

    return 0;
}
