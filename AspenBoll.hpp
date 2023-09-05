#ifndef _BOLL_HPP_
#define _BOLL_HPP_

#include "Harvest.hpp"

/*!
\brief Пример конкретной реализации класса Плоды - "Брунька"
*/
class Boll : public Harvest {
public:
    Boll(const std::string& name = "Aspen boll", const std::string& color = "Brawn", const std::string& size = "Very small", double weight = 0.005)
        : Harvest(name, color, size, weight) {}
};



#endif // !_PINE_CONE_HPP_