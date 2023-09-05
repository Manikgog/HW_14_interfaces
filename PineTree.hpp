#ifndef _PINE_TREE_HPP_
#define _PINE_TREE_HPP_

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
class PineTree : public Plants {
private:
    int fruitCount_; // ���������� ����� �� �����

public:
    PineTree(const std::string& color, const std::string& size, const std::string& name, int fruitCount)
        : Plants(color, size, name), fruitCount_(fruitCount) {}

    void printInfo() const override {
        Plants::printInfo();
        std::cout << "Cone count: " << fruitCount_ << std::endl;
    }

    /*!
    \brief ����� ������������ ��������� ����� �� 0.1 �� 0.2 (��������� ��� �����)
    */
    double GetRandom()
    {
        std::random_device rd;   // non-deterministic generator
        std::mt19937 gen(rd());  // to seed mersenne twister.
        int randomNum = gen() % 11 + 30;
        return randomNum / 100.0;
    }

    /*!
   \brief ����� ������������ ����� ��������� �� ������ ������ Harvest, ����������� �� ������� ���������� ������ �� ������
   \param[out] std::unique_ptr<Harvest> ����� ��������� �� ������ ������ Harvest
   */
    std::unique_ptr<Harvest> harvestFruit() override {
        --fruitCount_;
        return std::make_unique<Harvest>("Cone", "Brawn", "Large", GetRandom()); // ����������� ������� Peach ����� ��������� �����
    }

    /*!
    \brief ����� ������������ ���������� ������ �� ������
    */
    int GetFruitCount() override
    {
        return fruitCount_;
    }
};


#endif // !_PINE_TREE_HPP_