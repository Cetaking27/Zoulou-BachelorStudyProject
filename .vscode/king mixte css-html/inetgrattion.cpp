#include <cmath>
#include <iostream>
#include <iomanip>
 
auto f(double x)
{
    return x * std::sin(x);
}
 
auto print_row(int n)
{
    constexpr auto a = 0;
    constexpr auto b = M_PI;
 
    const auto lr = riemann_sum(a, b, n, f);
    const auto rr = riemann_sum<riennam_sum_type::right>(a, b, n, f);
    const auto tp = trapz(a, b, n, f);
    const auto sp = simpson(a, b, n, f);
 
    std::cout << '|' << std::setw(15) << n
              << '|' << std::setw(15) << M_PI 
              << '|' << std::setw(15) << lr 
              << '|' << std::setw(15) << rr 
              << '|' << std::setw(15) << tp 
              << '|' << std::setw(15) << sp << "|\n";
}
 
template <typename Method>
auto print_table(int n_start, int n_rows, int step, Method method, const std::string& name)
{
    constexpr auto a = 0;
    constexpr auto b = M_PI;
 
    std::cout << "+---------------+---------------+---------------+---------------+\n";
    std::cout << "|       N       |    integral   |"<<   name  <<"|     error     |\n";
    std::cout << "+---------------+---------------+---------------+---------------+\n";
    
    for(int i = n_start; i <= n_start + n_rows; i += step)
    {
        const auto val = method(a, b, i, f);
        
        std::cout << '|' << std::setw(15) << i
            << '|' << std::setw(15) << M_PI 
            << '|' << std::setw(15) << val 
            << '|' << std::setw(15) << std::abs(val - M_PI) << "|\n";
    }
    std::cout << "+---------------+---------------+---------------+---------------+\n";
}
 
int main()
{
        
    constexpr auto n = 16;
    
    std::cout << "+---------------+---------------+---------------+---------------+---------------+---------------+\n";
    std::cout << "|       N       |    integral   |   lriemann    |    rriemann   |     trapz     |    simpson    |\n";
    std::cout << "+---------------+---------------+---------------+---------------+---------------+---------------+\n";
    print_row(n);
    print_row(2 * n);
    print_row(5 * n);
    print_row(10 * n);
    std::cout << "+---------------+---------------+---------------+---------------+---------------+---------------+\n";
 
    std::cout << '\n';
    print_table(16, 4, 1, riemann_sum<riennam_sum_type::left, decltype(f)>, "   lriemann    ");
 
    std::cout << '\n';
 //   print_table(16, 4, 1, riemann_sum<riennam_sum_type::right, decltype(f)>, "   rriemann    ");
 
  //  std::cout << '\n';
//    print_table(20, 4, 1, trapz<decltype(f)>, "     trapz     ");
 
 //    std::cout << '\n';
  //  print_table(11, 4, 1, simpson<decltype(f)>, "    simpson    ");

enum riennam_sum_type {left, right};
template<riennam_sum_type sum_type = left, typename Callable>
auto riemann_sum(double a, double b, int n, Callable& f)

assert(n > 1);
const auto dx = (b - a) / (n - 1)
 

}
