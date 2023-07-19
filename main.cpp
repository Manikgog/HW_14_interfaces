/*!
Наследование - Интерфейсы
Задание на композицию
Для реализованных классов Локация и Рюкзак создать интерфейсы:
Локация:
Для игры - позволяет добавлять и удалять деревья с локации
Для игрока - позволяет просматривать деревья и собирать с них плоды
Рюкзак:
Для игрока - позволяет добавлять и удалять плоды из рюкзака
Для игры - только просматривать содержимое без изменений
Продемонстрировать различное поведение объектов класса при передаче их по разным
интерфейсам.
``` задание сдаётся в виде архива проекта либо ссылки на репозиторий
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
            backpack.Push_back(*(garden[i]->harvestFruit())); //> добавление объекта класса Harvest в объект класса Backpack (рюкзак)
        }
    }
    std::cout << "In the backpack " << backpack.Size() << " harvests." << " Total weight - " << backpack.GetWeight() << " kg.\n";

    Harvest apple(*(backpack.GetFruit("Apple").release())); //> извлечение яблока из рюкзака
    std::cout << "In the backpack " << backpack.Size() << " harvests." << " Total weight - " << backpack.GetWeight() << " kg.\n";
    Harvest peach(*(backpack.GetFruit("Peach Prince").release())); //> извледение персика из рюкзака
    std::cout << "In the backpack " << backpack.Size() << " harvests." << " Total weight - " << backpack.GetWeight() << " kg.\n";
    Harvest cherry(*(backpack.GetFruit("Cherry").release()));       //> извелечение черешни из рюкзака
    std::cout << "In the backpack " << backpack.Size() << " harvests." << " Total weight - " << backpack.GetWeight() << " kg.\n";

    garden.AddRandomTree();

    garden.DeleteTree("Apple Tree");
    garden.DeleteTree("Peach Tree");
    garden.DeleteTree("Cherry Tree");

    Harvest h = garden.GetHarvest("Apple Tree");

    return 0;
}


