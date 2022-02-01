#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
#include <set>

class Range {
    const size_t m_from, m_to;
public:
    Range(size_t from, size_t to) : m_from(from), m_to(to) 
    {
        if (m_from > m_to) 
          throw std::logic_error{"invalid range values\n"};
    }

    template<typename Con>
    operator Con() const
    {
        Con con;
        for (size_t i{ m_from }; i < m_to; ++i)
            con.insert(con.end(), i);
        
        return con;
    }
};



int main()
{
    std::vector<int> ivec = Range(19, 33);
    for (auto i : ivec)
        std::cout << i << ' ';

    std::cout << '\n';

    std::set<int> iset = Range(5, 12);
    for (auto i : iset)
        std::cout << i << ' ';
}
