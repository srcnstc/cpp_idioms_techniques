#include <stdexcept>
#include <iostream>
#include <cassert>

struct X {
    X(int) 
    {
        throw std::runtime_error("X error"); 
    }
};

struct Y {
    Y(int) 
    {
        throw std::runtime_error("Y error"); 
    }
};

class Nec {
private:
    X mx;
    Y my;
    enum Tracker { NONE, FIRST, SECOND };
public:
    Nec(Tracker tracker = NONE)
        try    
        : mx((tracker = FIRST, 1)) 
        , my((tracker = SECOND, 2)) 
    {
        assert(tracker == SECOND);
        // ... constructor body ...
    }
    catch (const std::exception& e)
    {
        if (tracker == FIRST) {
            std::cout << "X threw: " << e.what() << '\n';
        }
        else if (tracker == SECOND) {
            std::cout << "Y threw: " << e.what() << '\n';
        }
        throw;
    }
};

int main()
{
    try {
        Nec nec;
    }
    catch (const std::exception &e) {
        std::cout << "exception caught: " << e.what() << std::endl;
    }
}
