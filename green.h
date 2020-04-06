#ifndef _GREEN_H__
#define _GREEN_H__ 1

#include "color_interface.h"
#include <iosfwd>

class KnowsAboutGreen
{
public:
    void write_color(std::ostream& os);
};

class Green : public ColorInterface<KnowsAboutGreen>
{
public:
    explicit Green(std::ostream& os);
    virtual void print_my_color();
};

#endif // _GREEN_H__
