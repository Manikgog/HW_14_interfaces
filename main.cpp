/*!
������������ - ����������
������� �� ����������
��� ������������� ������� ������� � ������ ������� ����������:
�������:
��� ���� - ��������� ��������� � ������� ������� � �������
��� ������ - ��������� ������������� ������� � �������� � ��� �����
������:
��� ������ - ��������� ��������� � ������� ����� �� �������
��� ���� - ������ ������������� ���������� ��� ���������
������������������ ��������� ��������� �������� ������ ��� �������� �� �� ������
�����������.
``` ������� ������ � ���� ������ ������� ���� ������ �� �����������
*/
#include <iostream>
#include "AppleTree.hpp"
#include "PeachTree.hpp"
#include "CherryTree.hpp"
#include "Garden.hpp"
#include "Backpack.hpp"
#include "Interfaces.h"


int main() {
    Garden garden;

    garden.PrintGarden();
    std::cout << "In the garden " << garden.Size() << " trees, and " << garden.AmountOfHarvest() << " harvests.\n";
    Backpack backpack;
    for (size_t i = 0; i < garden.Size(); i++)
    {
        while (garden[i]->GetFruitCount() > 0)
        {
            backpack.Push_back(*(garden[i]->harvestFruit())); //> ���������� ������� ������ Harvest � ������ ������ Backpack (������)
        }
    }
    std::cout << "In the backpack " << backpack.Size() << " harvests." << " Total weight - " << backpack.GetWeight() << " kg.\n";

    Harvest apple(*(backpack.GetFruit("Apple").release())); //> ���������� ������ �� �������
    std::cout << "In the backpack " << backpack.Size() << " harvests." << " Total weight - " << backpack.GetWeight() << " kg.\n";
    Harvest peach(*(backpack.GetFruit("Peach Prince").release())); //> ���������� ������� �� �������
    std::cout << "In the backpack " << backpack.Size() << " harvests." << " Total weight - " << backpack.GetWeight() << " kg.\n";
    Harvest cherry(*(backpack.GetFruit("Cherry").release()));       //> ����������� ������� �� �������
    std::cout << "In the backpack " << backpack.Size() << " harvests." << " Total weight - " << backpack.GetWeight() << " kg.\n";

    garden.AddRandomTree();

    garden.DeleteTree("Apple Tree");
    garden.DeleteTree("Peach Tree");
    garden.DeleteTree("Cherry Tree");

    Harvest h = garden.GetHarvest("Apple Tree");

    return 0;
}


