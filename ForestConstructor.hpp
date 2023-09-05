#ifndef _FOREST_CONSTRUCTOR_HPP_
#define _FOREST_CONSTRUCTOR_HPP_

#include "ForestBuilder.hpp"

// ����� ��������� ����� ��������� ���������� ������� � ������� ���������
class ForestConstructor
{
public:
	ForestConstructor() {}
	virtual ~ForestConstructor() {}
	void Construct(ForestBuilder* forestBuilder) {
		forestBuilder->BuildFirstTree();
		forestBuilder->BuildSecondTree();
	}
};

#endif 

