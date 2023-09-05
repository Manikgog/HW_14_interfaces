#ifndef _BRUNKA_HPP_
#define _BRUNKA_HPP_

#include "Harvest.hpp"

/*!
\brief Пример конкретной реализации класса Плоды - "Брунька"
*/
class Brunka : public Harvest {
public:
    Brunka(const std::string& name = "Birch brunka", const std::string& color = "Brawn", const std::string& size = "Very small", double weight = 0.005)
        : Harvest(name, color, size, weight) {}
};



#endif // !_PINE_CONE_HPP_