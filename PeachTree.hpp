﻿#ifndef _PEACH_TREE_HPP_
#define _PEACH_TREE_HPP_

#include <iostream>
#include <string>
#include <memory>
#include <ctime>

#include "Plants.hpp"
#include "Peach.hpp"

/*!
\brief Пример конкретной реализации класса Растения - "Персиковое дерево"
*/
class PeachTree : public Plants {
private:
    int fruitCount_; // Количество плодов на персиковом дереве

public:
    PeachTree(const std::string& color, const std::string& size, const std::string& name, int fruitCount)
        : Plants(color, size, name), fruitCount_(fruitCount) {}

    void printInfo() const override {
        Plants::printInfo();
        std::cout << "Fruit count: " << fruitCount_ << std::endl;
    }

    /*!
    \brief метод возвращающий случайное число от 0.3 до 0.4 (случайный вес персика)
    */
    double GetRandom()
    {
        std::random_device rd;   // non-deterministic generator
        std::mt19937 gen(rd());  // to seed mersenne twister.
        int randomNum = gen() % 11 + 30;
        return randomNum / 100.0;
    }

    /*!
   \brief метод возвращающий умный указатель на объект класса Harvest, уменьшающий на единицу количество плодов на дереве
   \param[out] std::unique_ptr<Harvest> умный указатель на объект класса Harvest
   */
    std::unique_ptr<Harvest> harvestFruit() override {
        --fruitCount_;
        return std::make_unique<Harvest>("Peach Prince", "Yellow", "Large", GetRandom()); // Возвращение объекта Peach через фабричный метод
    }

    /*!
    \brief метод возвращающий количество плодов на дереве
    */
    int GetFruitCount() override
    {
        return fruitCount_;
    }
};

#endif // !_PEACH_TREE_HPP_

