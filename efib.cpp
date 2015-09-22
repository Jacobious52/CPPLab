#include <map>
#include <iostream>

class EfficientFib
{
public:
    uint calc(uint n)
    {
        if (n < 2)
        {
            return n;
        }

        std::map<uint, uint>::iterator it = _cache.find(n);
        if (it != _cache.end())
        {
           return it->second;
        }
        else
        {
        uint fibn = calc(n-1) + calc(n-2);
        _cache[n] = fibn;
        return fibn;
    }
}

private:
    std::map<uint, uint> _cache;
};

int main()
{
    EfficientFib efib;
    std::cout << efib.calc(40) << std::endl;

    return 0;
}
