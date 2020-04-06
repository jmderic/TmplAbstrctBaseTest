#ifndef _BLUE_H__
#define _BLUE_H__ 1

#include "color_interface.h"
#include <iosfwd>

class KnowsAboutBlue
{
public:
    void write_color(std::ostream& os);
};

class Blue : public ColorInterface<KnowsAboutBlue>
{
public:
    explicit Blue(std::ostream& os);
    virtual void print_my_color();
};

#endif // _BLUE_H__
