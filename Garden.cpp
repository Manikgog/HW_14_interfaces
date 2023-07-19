#include "Garden.hpp"

/*!
\brief ����������� �� 30 �� 100 �������� Plants � ����������� ��� ������ std::vector<std::unique_ptr<Plants>> Garden_;
���������� �������� �� ����� ����������� ��������� �������.
���������� ������� �� ������ ������ ����������� ���� ��������.
*/
Garden::Garden()
{
	std::random_device rd;   // non-deterministic generator
	std::mt19937 gen(rd());  // to seed mersenne twister.

	int AllTress = gen() % 71 + 30;;
	int numberOfAppleTrees = gen() % 30 + 10;
	int numberOfPeachTrees = gen() % 30 + 10;
	int numberOfCherryTrees = AllTress - numberOfAppleTrees - numberOfPeachTrees;

	int fruitCount = 0;
	while (numberOfAppleTrees-- > 0)
	{
		fruitCount = gen() % 11 + 5;
		Garden_.push_back(std::make_unique<AppleTree>("Green", "Large", "Apple Tree", fruitCount));
	}

	while (numberOfPeachTrees-- > 0)
	{
		fruitCount = gen() % 16 + 10;
		Garden_.push_back(std::make_unique<PeachTree>("Green", "Medium", "Peach Tree", fruitCount));
	}

	while (numberOfCherryTrees-- > 0)
	{
		fruitCount = gen() % 51 + 10;
		Garden_.push_back(std::make_unique<CherryTree>("Dark green", "Medium", "Cherry Tree", fruitCount));
	}
}

void Garden::PrintGarden()
{
	for (const auto& el : Garden_)
	{
		el.get()->printInfo();
		std::cout << std::endl;
	}
}

/*!
\brief ����� ������������ ���������� ��������� � ������� std::vector<std::unique_ptr<Plants>> Garden_.
���������� ���������� �������� � ����.
\param[out] size_t ���������� ��������
*/
size_t Garden::Size()
{
	return Garden_.size();
}

/*
\brief ����� ������������ ������ �� ������ ����� ���������� ��  ������� Plants
*/
std::vector<std::unique_ptr<Plants>>& Garden::GetGarden()
{
	return Garden_;
}

/*!
\brief ����� ���������� ��������� �� ������ ������ Plants
\param[in] index ������ ������� ������ Plants � ������� std::vector<std::unique_ptr<Plants>> Garden_;
\param[out] Plants* ��������� �� ������ Plants
*/
Plants* Garden::operator[](size_t index)
{
	return Garden_.at(index).get();
}

/*!
\brief ����� ���������� ���������� ������ � ����
*/
size_t Garden::AmountOfHarvest()
{
	size_t amount = 0;
	for (const auto& el : Garden_)
	{
		amount += el.get()->GetFruitCount();
	}
	return amount;
}

void Garden::AddAppleTree()
{
	std::random_device rd;   // non-deterministic generator
	std::mt19937 gen(rd());  // to seed mersenne twister.
	
	size_t fruitCount = gen() % 11 + 5;
	Garden_.push_back(std::make_unique<AppleTree>("Green", "Large", "Apple Tree", fruitCount));
}

void  Garden::AddPeachTree()
{
	std::random_device rd;   // non-deterministic generator
	std::mt19937 gen(rd());  // to seed mersenne twister.
	size_t fruitCount = gen() % 16 + 10;
	Garden_.push_back(std::make_unique<PeachTree>("Green", "Medium", "Peach Tree", fruitCount));
}

void  Garden::AddCherryTree()
{
	std::random_device rd;   // non-deterministic generator
	std::mt19937 gen(rd());  // to seed mersenne twister.
	size_t fruitCount = gen() % 51 + 10;
	Garden_.push_back(std::make_unique<CherryTree>("Dark green", "Medium", "Cherry Tree", fruitCount));
}

void  Garden::AddRandomTree()
{
	std::random_device rd;   // non-deterministic generator
	std::mt19937 gen(rd());  // to seed mersenne twister.

	size_t randomTree = gen() % 3;

	if (randomTree == 0)
	{
		this->AddAppleTree();
	}
	else if (randomTree == 1)
	{
		this->AddPeachTree();
	}
	else if (randomTree == 2)
	{
		this->AddCherryTree();
	}

}

void  Garden::DeleteTree(std::string nameTree)
{
	for (size_t i = 0; i < Size(); i++)
	{
		if (Garden_.at(i).get()->GetName() == nameTree)
		{
			Garden_.erase(Garden_.begin() + i);
			break;
		}
	}
}


Harvest Garden::GetHarvest(const std::string& nameTree)
{
	for (size_t i = 0; i < Size(); i++)
	{
		if (Garden_.at(i).get()->GetName() == nameTree)
		{
			return *(Garden_.at(i).get()->harvestFruit().get());
		}
	}
	Harvest h;
	return h;
}

