#ifndef _INTERFACES_H_
#define _INTERFACES_H_

#include <string>
#include "Harvest.hpp"

class IGameGarden
{
public:
	IGameGarden() = default;
	virtual ~IGameGarden() {}
	virtual void AddAppleTree() = 0;
	virtual void AddPeachTree() = 0;
	virtual void AddCherryTree() = 0;
	virtual void AddRandomTree() = 0;
	virtual void  DeleteTree(std::string nameTree) = 0;

};

class IGamerGarden
{
public:
	IGamerGarden() = default;
	virtual ~IGamerGarden() {};
	virtual std::vector<std::unique_ptr<Plants>>& GetGarden() = 0;
	virtual Plants* operator[](size_t index) = 0;
	virtual Harvest GetHarvest(const std::string& nameOfTree) = 0;
};


#endif