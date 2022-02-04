#include <utility>

template <class F>
class scope_guard
{
public:
    explicit scope_guard(F f) noexcept
        : f_(std::move(f)), invoke_(true) {}

    scope_guard(scope_guard&& other) noexcept
        : f_(std::move(other.f_)),
        invoke_(other.invoke_)
    {
        other.invoke_ = false;
    }

    scope_guard(const scope_guard&) = delete;
    scope_guard& operator=(const scope_guard&) = delete;

    ~scope_guard() noexcept
    {
        if (invoke_) f_();
    }

    void release()noexcept
    {
        invoke_ = false;
    }

private:
    F f_;
    bool invoke_;
};

template <class F>
scope_guard<F> finally(const F& f) noexcept
{
    return scope_guard<F>(f);
}

#include <iostream>


using namespace std;

int main()
{
    std::cout << "1...\n";
    auto f = [] {
        cout << "necati ergin\n";
    };
    if (1) {
        scope_guard _{ f };
        //...
    }
    std::cout << "2...\n";

}
