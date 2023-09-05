#ifndef _CONE_HPP_
#define _CONE_HPP_

#include "Harvest.hpp"

/*!
\brief Пример конкретной реализации класса Плоды - "Шишка"
*/
class Cone : public Harvest {
public:
    Cone(const std::string& name = "Fir Cone", const std::string& color = "Brawn", const std::string& size = "Small", double weight = 0.1)
        : Harvest(name, color, size, weight) {}
};



#endif // !_CONE_HPP_

