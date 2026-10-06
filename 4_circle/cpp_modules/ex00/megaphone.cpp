#include <string>
#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    int a = 1;
    int i = 0;

    if(ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    while(a < ac)
    {
        i = 0;
        while(av[a][i])
        {
            std::cout << (char)std::toupper(av[a][i]);
            i++;
        }
        a++;
    }
    std::cout << std::endl;
    return 0;
}
