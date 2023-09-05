#ifndef _ASPEN_TREE_HPP_
#define _ASPEN_TREE_HPP_

#include <iostream>
#include <string>
#include <memory>
#include <ctime>
#include <random>

#include "Plants.hpp"
#include "PineCone.hpp"

/*!
\brief Пример конкретной реализации класса Растения - "Сосна"
*/
class AspenTree : public Plants {
private:
    int fruitCount_; // Количество брунек на берёзе

public:
    AspenTree(const std::string& color, const std::string& size, const std::string& name, int fruitCount)
        : Plants(color, size, name), fruitCount_(fruitCount) {}

    void printInfo() const override {
        Plants::printInfo();
        std::cout << "Boll count: " << fruitCount_ << std::endl;
    }

    /*!
    \brief метод возвращающий случайное число от 0.006 до 0.015 (случайный вес коробочки)
    */
    double GetRandom()
    {
        std::random_device rd;   // non-deterministic generator
        std::mt19937 gen(rd());  // to seed mersenne twister.
        int randomNum = gen() % 6 + 10;
        return randomNum / 1000.0;
    }

    /*!
   \brief метод возвращающий умный указатель на объект класса Harvest, уменьшающий на единицу количество плодов на дереве
   \param[out] std::unique_ptr<Harvest> умный указатель на объект класса Harvest
   */
    std::unique_ptr<Harvest> harvestFruit() override {
        --fruitCount_;
        return std::make_unique<Harvest>("Aspen boll", "Brawn", "Very small", GetRandom()); // Возвращение объекта Brunka через фабричный метод
    }

    /*!
    \brief метод возвращающий количество плодов на дереве
    */
    int GetFruitCount() override
    {
        return fruitCount_;
    }
};


#endif // !_ASPEN_TREE_HPP_
