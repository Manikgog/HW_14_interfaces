#ifndef _INTERFACES_H_
#define _INTERFACES_H_

#include <string>
#include "Harvest.hpp"

class IGame
{
public:
	IGame() = default;
	virtual ~IGame() {}
};

/*!
\brief класс IGameBackPack, имеющий методы для взаимодействия игры с классом Garden
*/
class IGameGarden : public IGame
{
public:
	IGameGarden() = default;
	virtual ~IGameGarden() {}
	virtual void AddAppleTree() = 0;
	virtual void AddPeachTree() = 0;
	virtual void AddCherryTree() = 0;
	virtual void AddAspenTree() = 0;
	virtual void AddBirchTree() = 0;
	virtual void AddPineConeTree() = 0;
	virtual void AddFirTree() = 0;
	virtual void AddRandomTree() = 0;
	virtual void  DeleteTree(std::string nameTree) = 0;

};

/*!
\brief класс IGameBackPack, имеющий методы для взаимодействия игры с классом Backpack
*/
class IGameBackPack : public IGame
{
public: 
	IGameBackPack() = default;
	~IGameBackPack() {}
	virtual Harvest* operator[](size_t index) = 0;				//> метод для просмотра плодов в рюкзаке
	virtual size_t Size() = 0;									//> метод возвращающий количество плодов в рюкзаке
	virtual void ShowStatistic() = 0;							//> метод выводящий на экран статистику по содержимому рюкзака
};

/*!
\brief класс IPlayerBackPack, имеющий методы для взаимодействия игрока с классом Backpack
*/
class IPlayerBackPack : public IGame
{
public:
	IPlayerBackPack() = default;
	~IPlayerBackPack() {}
	virtual void Push_back(const Harvest& harvest) = 0;			//> метод для добавления плода в рюкзак
	virtual std::unique_ptr<Harvest> GetFruit(const std::string& fruit) = 0;//> метод для извлечения плода из рюкзака

};

/*!
\brief класс IPlayerGarden, имеющий методы для взаимодействия игрока с классом Garden
*/
class IPlayerGarden : public IGame
{
public:
	IPlayerGarden() = default;
	virtual ~IPlayerGarden() {};
	virtual Plants* operator[](size_t index) = 0;					//> метод для получения указателя на дерево без его удаления
	virtual Harvest GetHarvest(const std::string& nameOfTree) = 0;	//> метод для получения объекта класса Harvest, при этом количество плодов на дереве уменьшается
	virtual void ShowStatistic() = 0;								//> метод выводящий на экран статистику по содержимому сада
};


#endif