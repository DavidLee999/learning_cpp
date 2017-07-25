#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> v = { 3, 9, 1, 4, 2, 5, 9 };

    std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> result = std::minmax_element(v.begin(), v.end());
    std::cout << "min element at: " << (result.first - v.begin()) << '\n';
    std::cout << "max element at: " << (result.second - v.begin()) << '\n';

    std::string ss { "Fleetwood Mac." };
    std::string ss2 { ss, 2, std::string::npos };
    std::string ss3 { ss, 10, 9 };

    std::cout << ss2 << '\n' << ss3 << '\n';
    return 0;
}
