#ifndef _FOREST_BUILDER_HPP_
#define _FOREST_BUILDER_HPP_

#include <random>

#include "Garden.hpp"

// абстрактный класс строителя
class ForestBuilder
{
public:
	ForestBuilder() : garden_(new Garden()){}
	virtual ~ForestBuilder() {}
protected:
	Garden* garden_;
public:
	Garden* GetGarden() {
		return garden_;
	}

	virtual void BuildFirstTree() = 0;

	virtual void BuildSecondTree() = 0;

};

class GardenBuilder : public ForestBuilder
{
public:
	~GardenBuilder() {
		if (garden_)
			delete garden_;
		std::cout << "GardenBuilder destructor" << std::endl;
	}

	void BuildFirstTree() {
		for(int i = 0; i < 5; i++)
			garden_->AddAppleTree();
	}

	void BuildSecondTree() {
		for (int i = 0; i < 5; i++)
			garden_->AddCherryTree();
	}

};

class ConiferousForest : public ForestBuilder
{
public:
	~ConiferousForest() {
		if (garden_)
			delete garden_;
	}

	void BuildFirstTree() {
		for (int i = 0; i < 5; i++)
			garden_->AddFirTree();
	}

	void BuildSecondTree() {
		for (int i = 0; i < 5; i++)
			garden_->AddPineConeTree();
	}
};

class DeciduousForest : public ForestBuilder
{
public:
	~DeciduousForest() {
		if (garden_)
			delete garden_;
	}

	void BuildFirstTree() {
		for (int i = 0; i < 5; i++)
			garden_->AddAspenTree();
	}

	void BuildSecondTree() {
		for (int i = 0; i < 5; i++)
			garden_->AddBirchTree();
	}
};


#endif // !_FOREST_BUILDER_HPP_