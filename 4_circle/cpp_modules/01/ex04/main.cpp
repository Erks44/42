
#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: ./sed filename s1 s2" << std::endl;
        return (1);
    }

    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return (1);
    }

    std::ifstream input(av[1]);
    if (!input.is_open())
    {
        std::cerr << "Error: cannot open file" << std::endl;
        return (1);
    }

    std::string filename = std::string(av[1]) + ".replace";
    std::ofstream output(filename.c_str());

    if (!output.is_open())
    {
        std::cerr << "Error: cannot create file" << std::endl;
        return (1);
    }

    std::string line;
    while (std::getline(input, line))
    {
        std::string result;
        size_t pos = 0;
        size_t found;

        while ((found = line.find(s1, pos)) != std::string::npos)
        {
            result += line.substr(pos, found - pos);
            result += s2;
            pos = found + s1.length();
        }

        result += line.substr(pos);
        output << result;

        if (!input.eof())
            output << '\n';
    }

    if (input.bad() || !output)
    {
        std::cerr << "Error: file read or write failed" << std::endl;
        return (1);
    }

    input.close();
    output.close();

    return (0);
}
