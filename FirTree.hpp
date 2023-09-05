#ifndef _FIR_HPP_
#define _FIR_HPP_

#include <iostream>
#include <string>
#include <memory>
#include <ctime>
#include <random>

#include "Plants.hpp"
#include "Cone.hpp"

/*!
\brief ������ ���������� ���������� ������ �������� - "���"
*/
class FirTree : public Plants {
private:
    int fruitCount_; // ���������� ����� �� ���

public:
    FirTree(const std::string& color, const std::string& size, const std::string& name, int fruitCount)
        : Plants(color, size, name), fruitCount_(fruitCount) {}

    void printInfo() const override {
        Plants::printInfo();
        std::cout << "Fruit count: " << fruitCount_ << std::endl;
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
        return std::make_unique<Harvest>("Peach Prince", "Yellow", "Large", GetRandom()); // ����������� ������� Peach ����� ��������� �����
    }

    /*!
    \brief ����� ������������ ���������� ������ �� ������
    */
    int GetFruitCount() override
    {
        return fruitCount_;
    }
};


#endif // !_FIR_HPP_

