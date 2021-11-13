#include <vector>
#include <cassert>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cmath>

template <typename Container>
auto linspace(typename Container::value_type a, typename Container::value_type b, size_t n)
{
    assert(b > a);
    assert(n > 1);

    Container res(n);
    const auto step = (b - a) / (n - 1);
    auto val = a;
    for(auto& e: res)
    {
        e = val;
        val += step;
    }
    return res;
}

template<typename RandomAcessContainer>
class newton
{
    std::vector<std::vector<double>> divided_differences;
    double x0, y0, step;

public:
    newton(double x0, double step, const RandomAcessContainer& ys);

    double operator()(double x);
};


template<typename RandomAcessContainer>
newton<RandomAcessContainer>::newton(double x0, double step, const RandomAcessContainer& ys): 
                                            step(step), x0(x0), y0(ys[0]), divided_differences(ys.size())
{
    divided_differences[0].resize(ys.size());
    std::copy(ys.begin(), ys.end(), divided_differences[0].begin());

    for(size_t i = 1; i < ys.size(); i++)
    {
        auto& pdd = divided_differences[i - 1]; // previous divided differences
        auto& cdd = divided_differences[i];     // current  divided differences

        cdd.resize(pdd.size() - 1);

        std::transform(std::next(pdd.begin()), pdd.end(), pdd.begin(), cdd.begin(), std::minus{});
    }
}

template<typename RandomAcessContainer>
double newton<RandomAcessContainer>::operator()(double x)
{
    auto res  = y0;
    auto q    = (x - x0) / step;
    auto poly = q;

    for(int i = 1; i < divided_differences.size(); i++)
    {
        res  += poly * divided_differences[i][0];
        poly *= (q - i) / (i + 1);
    }
    return res;
} 


int main(int argc, char** argv)
{
    double a = 0.0;
    double b = 1.0;
    int n = 10;
    int m = 20;
    auto pi = 3.14159265358979323846;

    auto xs = std::vector<double>({0.1 * pi, 0.2 * pi, 0.3 * pi, 0.4 * pi });
    auto ys = std::vector<double>(xs.size());
    
    auto f = [](double x)
    {
        return x * x + 2 + std::sin(x * x + 2);
    };
 
    std::transform(xs.begin(), xs.end(), ys.begin(), f);
 
    auto interpolator = newton(xs[0], (b - a) / (n - 1),  ys);
    
    std::cout << "interpolator(x): " << interpolator(pi/4.0) << '\n';
    std::cout << "f(x)           : " << f(pi/4.0) << '\n';
}