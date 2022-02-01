#include <iostream>

constexpr
class null_ptr_t
{
public:
    template<typename T>
    constexpr operator T*()const {return 0;}  // for non-member pointer

    template<typename C, typename T>
    constexpr operator T C::* () const { return 0; } // for member pointer
    void operator&() = delete;
private:
} null_ptr;


void func(int) 
{
    std::cout << "func(int)" << '\n'; 
}

void func(int *)
{
    std::cout << "func(int *)" << '\n';
}

void foo(char*) { std::cout << "foo char*" << std::endl; }

class Nec {
public:
    void f() {}
};

int main()
{
    int* p1 = null_ptr;
    
    if (!p1) 
        std::cout << "p1 is null_ptr" << std::endl;
    
    if (p1 == null_ptr) 
        std::cout << "p1 is null_ptr" << '\n';

    int x = 10;
    int* p2 = &x;
    
    if (p2 != null_ptr) 
        std::cout << "p2 is not null_ptr" << '\n';

    void (Nec::*fp)() = null_ptr;

    func(null_ptr);
    foo(null_ptr);
    func(NULL);
}
