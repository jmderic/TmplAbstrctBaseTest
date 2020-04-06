// Quick Start file for testing ideas/snippets

#include "blue.h"
#include "green.h"
#include <iostream>

int main (int /*argc*/, char */*argv*/[])
{
    Blue b(std::cout);
    Green g(std::cout);

    b.print_my_color();
    g.print_my_color();
    return 0;
}
