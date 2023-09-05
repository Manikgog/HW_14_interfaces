#ifndef _PINE_CONE_HPP_
#define _PINE_CONE_HPP_

#include "Harvest.hpp"

/*!
\brief Пример конкретной реализации класса Плоды - "Coсновая шишка"
*/
class PineCone : public Harvest {
public:
    PineCone(const std::string& name = "Pine Cone", const std::string& color = "Brawn", const std::string& size = "Big", double weight = 0.2)
        : Harvest(name, color, size, weight) {}
};



#endif // !_PINE_CONE_HPP_

