
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

    ForestConstructor* forestConstructor = new ForestConstructor(); // создаём указатель на объект директора

    gardenBuilder = new GardenBuilder();        // создаём указатель на строителя, который создаёт сад фруктовых деревьев

    forestConstructor->Construct(gardenBuilder);    // создаём фруктовый сад

    gardenBuilder->GetGarden()->PrintGarden();      // выводим на экран список деревьев сада

    delete gardenBuilder;

    gardenBuilder = new ConiferousForest();         // создаём указатель на строителя, который создаёт лес хвойных деревьев

    forestConstructor->Construct(gardenBuilder);     // создаём лес

    gardenBuilder->GetGarden()->PrintGarden();       // выводим на экран список деревьев хвойного леса

    delete gardenBuilder;

    gardenBuilder = new DeciduousForest();          // создаём указатель на строителя, который создаёт лес лиственных деревьев

    forestConstructor->Construct(gardenBuilder);    // создаём лес

    gardenBuilder->GetGarden()->PrintGarden();      // выводим на экран список деревьев лиственного леса

    delete gardenBuilder;

    delete forestConstructor;


    return 0;
}


