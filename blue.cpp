
#include "blue.h"
#include <ostream>

void KnowsAboutBlue::write_color(std::ostream& os)
{
    os << "I'm Blue" << std::endl;
}

Blue::Blue(std::ostream& os)
        : ColorInterface<KnowsAboutBlue>(os)
{
}

void Blue::print_my_color()
{
    KnowsAboutBlue kn_blue;
    kn_blue.write_color(os_);
}
