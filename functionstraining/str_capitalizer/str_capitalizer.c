#include <unistd.h>

int main(int ac, char **av) {
  if (ac > 1) {
    int a = 1;
    int i = 0;
    char c;
    while (a < ac) {
      i = 0;
      while (av[a][i]) {
        if ((av[a][i - 1] == ' ' || av[a][i - 1] == '\t' || i == 0) &&
            (av[a][i] >= 'a' && av[a][i] <= 'z'))
          c = av[a][i] - 32;
        else if ((av[a][i] >= 'A' && av[a][i] <= 'Z') &&
                 !(av[a][i - 1] == ' ' || av[a][i - 1] == '\t' || i == 0))
          c = av[a][i] + 32;
        else
          c = av[a][i];
        write(1, &c, 1);
        i++;
      }
      a++;
      write(1, "\n", 1);
    }
  } else
    write(1, "\n", 1);
}