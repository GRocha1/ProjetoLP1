#pragma once

#ifndef EXECUTAJOGO_H
#define EXECUTAJOGO_H

#include "InterfaceJogo.h"
#include "Cor.h"

using namespace std;
using namespace cv;

class ExecutaJogo
{
public:
	ExecutaJogo();
	virtual ~ExecutaJogo();
	void ExecJogo();
	int CompararCores(int);
	void lerRecord();
	void salvarRecord();
private:
	InterfaceJogo iJogo;
	Cor cor;
};

#endif
