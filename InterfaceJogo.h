#pragma once

#ifndef INTERFACEJOGO_H
#define INTERFACEJOGO_H

#include "Cor.h"

using namespace std;
using namespace cv;

class InterfaceJogo
{
public:
	InterfaceJogo();
	virtual ~InterfaceJogo();
	void setTentativas(int);
	int getTentativas();
	void setPontAtual(int);
	int getPontAtual();
	void setRecord(int);
	int getRecord();
	void exibeInterface(int);
private:
	int tentativas;
	int pontAtual;
	int record;
	Cor cor;
};

#endif
