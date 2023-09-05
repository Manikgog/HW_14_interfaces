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
#include "FirTree.hpp"
#include "AspenTree.hpp"
#include "BirchTree.hpp"
#include "PineTree.hpp"
#include "ForestConstructor.hpp"
#include "ForestBuilder.hpp"
#include "Garden.hpp"
#include "Backpack.hpp"
#include "Interfaces.h"


int main() {
    ForestBuilder* gardenBuilder;

    ForestConstructor* forestConstructor = new ForestConstructor();

    gardenBuilder = new GardenBuilder();

    forestConstructor->Construct(gardenBuilder);

    gardenBuilder->GetGarden()->PrintGarden();

    delete gardenBuilder;

    ForestBuilder* forestBuilder;

    forestBuilder = new ConiferousForest();

    forestConstructor->Construct(forestBuilder);

    forestBuilder->GetGarden()->PrintGarden();

    delete forestBuilder;

    forestBuilder = new DeciduousForest();

    forestConstructor->Construct(forestBuilder);

    forestBuilder->GetGarden()->PrintGarden();

    delete forestBuilder;

    delete forestConstructor;


    return 0;
}


