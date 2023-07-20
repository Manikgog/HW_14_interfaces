#ifndef _BACK_PACK_HPP_
#define _BACK_PACK_HPP_

#include <vector>
#include <memory>
#include <set>

#include "Harvest.hpp"

/*!
\brief класс Backpack (рюкзак) 
*/
class Backpack : virtual public IGameBackPack, virtual public IPlayerBackPack
{
private:
	std::vector<std::unique_ptr<Harvest>> backpack_;

public:
	Backpack() {}

	void Push_back(const Harvest& harvest)
	{
		backpack_.push_back(std::make_unique<Harvest>(harvest));
	}

	size_t Size()
	{
		return backpack_.size();
	}

	/*!
	\brief метод возвращающий умный указатель на объект класса Harvest
	\param[in] fruit строку названия плода
	\param[out] std::unique_ptr<Harvest> умный указатель на объект класса Harvest
	*/
	std::unique_ptr<Harvest> GetFruit(const std::string& fruit)
	{
		if (this->Size() == 0)
		{
			std::cout << "Backpack is empty.\n";
			return std::make_unique<Harvest>();
		}
		for (size_t i = 0; i < this->Size(); i++)
		{
			if (backpack_.at(i)->getName() == fruit)
			{
				Harvest* apple = backpack_.at(i).release();
				backpack_.erase(backpack_.begin() + i);
				return std::make_unique<Harvest>(*apple);
			}
		}
		std::cout << "There are no " << fruit << " in the backpack.\n";
		return std::make_unique<Harvest>();
	}

	/*!
	\brief метод возвращающий полный вес плодов в рюкзаке
	\param[out] вещественное число, выражающее вес содержимого рюкзака
	*/
	double GetWeight()
	{
		double weight = 0;
		for (const auto& el : backpack_)
		{
			weight += el.get()->getWeight();
		}
		return weight;
	}

	/*!
	\brief метод для просмотра плодов в рюкзаке
	param[in] index индекс плода в векторе backpack_
	param[out] указатель на объект класса Harvest
	*/
	Harvest* operator[](size_t index)
	{
		if (index < 0 || index >= backpack_.size())
			return nullptr;
		return backpack_.at(index).get();
	}

	/*!
	\brief метод для просмотра статистики плодов
	Выводит названия плодов и их количество по названиям.
	*/
	void ShowStatistic()
	{
		std::set <std::string> NamesOfHarvest;
		for (const auto& el : backpack_)
		{
			NamesOfHarvest.insert(el->getName());
		}


		std::cout << "The backpack contains:\n";
		for (const auto& el : NamesOfHarvest)
		{
			std::cout << el << " - ";
			size_t count = 0;
			for (const auto& el1 : backpack_)
			{
				if (el1.get()->getName() == el)
					count++;
			}
			std::cout << count << " pieces.\n";
		}
	}

	

};


#endif // !_BACK_PACK_HPP_
