#pragma once
#ifndef COR_H
#define COR_H

#include "stdafx.h"

using namespace std;
using namespace cv;

class Cor
{
public:
	Cor();
	virtual ~Cor();
	int geraCorRandom();
	string exibeCor(int);
};

#endif // !COR_H