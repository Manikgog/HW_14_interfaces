#ifndef _BIRCH_TREE_HPP_
#define _BIRCH_TREE_HPP_

#include <iostream>
#include <string>
#include <memory>
#include <ctime>
#include <random>

#include "Plants.hpp"
#include "PineCone.hpp"

/*!
\brief ������ ���������� ���������� ������ �������� - "�����"
*/
class BirchTree : public Plants {
private:
    int fruitCount_; // ���������� ������ �� �����

public:
    BirchTree(const std::string& color, const std::string& size, const std::string& name, int fruitCount)
        : Plants(color, size, name), fruitCount_(fruitCount) {}

    void printInfo() const override {
        Plants::printInfo();
        std::cout << "Brunka count: " << fruitCount_ << std::endl;
    }

    /*!
    \brief ����� ������������ ��������� ����� �� 0.006 �� 0.015 (��������� ��� �������)
    */
    double GetRandom()
    {
        std::random_device rd;   // non-deterministic generator
        std::mt19937 gen(rd());  // to seed mersenne twister.
        int randomNum = gen() % 6 + 10;
        return randomNum / 1000.0;
    }

    /*!
   \brief ����� ������������ ����� ��������� �� ������ ������ Harvest, ����������� �� ������� ���������� ������ �� ������
   \param[out] std::unique_ptr<Harvest> ����� ��������� �� ������ ������ Harvest
   */
    std::unique_ptr<Harvest> harvestFruit() override {
        --fruitCount_;
        return std::make_unique<Harvest>("Birch brunka", "Brawn", "Very small", GetRandom()); // ����������� ������� Brunka ����� ��������� �����
    }

    /*!
    \brief ����� ������������ ���������� ������ �� ������
    */
    int GetFruitCount() override
    {
        return fruitCount_;
    }
};


#endif // !_BIRCH_TREE_HPP_
