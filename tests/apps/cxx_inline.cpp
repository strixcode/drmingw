#include <windows.h>

#include "macros.h"

class Test
{
public:
    Test();
    int length() const;
private:
    int size;
};


Test::Test()
    :size(0)
{}

FORCE_INLINE int Test::length() const
{
    return size;
}

int main()
{
    Test *a;
    a = NULL;
    int l = a->length();
    return l != 0;
}

// CHECK_STDERR: /  cxx_inline\.exe\!main  \[.*\bcxx_inline\.cpp @ (21|28)\]/
// CHECK_EXIT_CODE: 0xc0000005
