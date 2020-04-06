
#include "green.h"
#include <ostream>

void KnowsAboutGreen::write_color(std::ostream& os)
{
    os << "I'm Green" << std::endl;
}

Green::Green(std::ostream& os)
        : ColorInterface<KnowsAboutGreen>(os)
{
}

void Green::print_my_color()
{
    KnowsAboutGreen kn_green;
    kn_green.write_color(os_);
}
