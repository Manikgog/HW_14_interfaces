#ifndef _GARDEN_HPP_
#define _GARDEN_HPP_

#include <vector>
#include <memory>
#include <random>
#include <set>

#include "Plants.hpp"
#include "AppleTree.hpp"
#include "PeachTree.hpp"
#include "CherryTree.hpp"
#include "FirTree.hpp"
#include "AspenTree.hpp"
#include "BirchTree.hpp"
#include "PineTree.hpp"
#include "Interfaces.h"

/*!
\brief класс Garden
*/
class Garden : virtual public IGameGarden, virtual public IPlayerGarden
{
private:
	std::vector<std::unique_ptr<Plants>> Garden_;

public:
	Garden();

	void PrintGarden();

	size_t Size();


	std::vector<std::unique_ptr<Plants>>& GetGarden();

	Plants* operator[](size_t index)override;

	size_t AmountOfHarvest();

	void AddAppleTree()override;

	void AddPeachTree()override;

	void AddCherryTree()override;

	void AddAspenTree()override;

	void AddBirchTree() override;

	void AddPineConeTree() override;

	void AddFirTree() override;


	void AddRandomTree()override;

	void  DeleteTree(std::string nameTree)override;

	Harvest GetHarvest(const std::string& nameOfTree) override;

	void ShowStatistic() override;
};


#endif // !_GARDEN_HPP_
