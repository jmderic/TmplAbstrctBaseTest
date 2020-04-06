#ifndef _COLOR_INTERFACE_H__
#define _COLOR_INTERFACE_H__ 1

#include <iosfwd>

template<typename KnowsAboutColor>
class ColorInterface
{
public:
    ColorInterface(std::ostream& os) : os_(os) {}
    virtual void print_my_color() = 0;
protected:
    std::ostream& os_;
};

#endif // _COLOR_INTERFACE_H__
