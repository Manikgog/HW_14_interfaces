#ifndef _GARDEN_HPP_
#define _GARDEN_HPP_

#include <vector>
#include <memory>
#include <random>

#include "Plants.hpp"
#include "AppleTree.hpp"
#include "PeachTree.hpp"
#include "CherryTree.hpp"
#include "Interfaces.h"

class Garden : public IGameGarden, public IGamerGarden
{
private:
	std::vector<std::unique_ptr<Plants>> Garden_;

public:
	Garden();

	void PrintGarden();

	size_t Size();


	std::vector<std::unique_ptr<Plants>>& GetGarden() override;

	Plants* operator[](size_t index)override;

	size_t AmountOfHarvest();

	void AddAppleTree()override;

	void AddPeachTree()override;

	void AddCherryTree()override;

	void AddRandomTree()override;

	void  DeleteTree(std::string nameTree)override;

	Harvest GetHarvest(const std::string& nameOfTree) override;
};


#endif // !_GARDEN_HPP_
