#ifndef APPLE_TREE_HPP
#define APPLE_TREE_HPP

#include <iostream>
#include <string>
#include <random>
#include <memory>
#include "Plants.hpp"
#include "Apple.hpp"

/*!
\brief Пример конкретной реализации класса Растения - "Яблоня" 
*/
class AppleTree : public Plants {
private:
    int fruitCount_; //> Количество плодов на яблоне

public:
    AppleTree(const std::string& color, const std::string& size, const std::string& name, int fruitCount)
        : Plants(color, size, name), fruitCount_(fruitCount) {}

    void printInfo() const override {
        Plants::printInfo();
        std::cout << "Fruit count: " << fruitCount_ << std::endl;
    }

    /*!
    \brief метод возвращающий случайное число от 0.2 до 0.3 (случайный вес яблока)
    */
    double GetRandom()
    {
        std::random_device rd;   //> non-deterministic generator / генератор энтропии
        
        int randomNum = rd() % 11 + 20;
        return randomNum / 100.0;
    }

    /*!
    \brief метод возвращающий умный указатель на объект класса Harvest, уменьшающий на единицу количество плодов на дереве
    \param[out] std::unique_ptr<Harvest> умный указатель на объект класса Harvest
    */
    std::unique_ptr<Harvest> harvestFruit() override {
        --fruitCount_;
        return std::make_unique<Harvest>("Apple", "Red", "Medium", GetRandom()); //> Возвращение объекта Apple через фабричный метод
    }

    /*!
    \brief метод возвращающий количество плодов на дереве
    */
    int GetFruitCount() override
    {
        return fruitCount_;
    }
};

#endif // !1

