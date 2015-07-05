#ifndef PTR_H
#define PTR_H

#include <cstdio>

namespace Tools
{
// Automatic Reference Counting Smart Pointer
template <typename T>
class Ptr
{
public:
    Ptr(T *ptr_value)
        : _ptr_value(ptr_value)
    {
        _ref_count = new int(0);
        _alloc();
    }

    ~Ptr()
    {
        _release();
    }

    T *get_ptr_value() const
    {
        return _ptr_value;
    }

    int *get_ref_count() const
    {
        return _ref_count;
    }

    T *operator->()
    {
        return _ptr_value;
    }

    T &operator*()
    {
        return *_ptr_value;
    }

    Ptr<T> &operator=(const Ptr<T> &ptr)
    {
        if (this == &ptr)
        {
            return *this;
        }

        _ptr_value = ptr.get_ptr_value();
        _ref_count = ptr.get_ref_count();
        _alloc();
        printf("alloc %d\n", *_ref_count);

        return *this;
    }

private:
    T *_ptr_value;
    int *_ref_count;

    void _alloc()
    {
        (*_ref_count)++;
    }

    void _release()
    {
        (*_ref_count)--;
        printf("dealloc %d\n", *_ref_count);
        if (*_ref_count == 0)
        {
            printf("_release\n");
           delete _ptr_value;
           delete _ref_count;
        }
        else
        {
            printf("null\n");
        }
    }
};


} // Tools

#endif // PTR_H
