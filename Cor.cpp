#include "stdafx.h"
#include "Cor.h"

Cor::Cor()
{
}

Cor::~Cor()
{
}

int Cor::geraCorRandom()
{
	int c = rand() % 6 + 1;
	return c;
}

string Cor::exibeCor(int n)
{
	switch (n)
	{
		case 1:
			return "AMARELO";
		case 2:
			return "AZUL";
		case 3:
			return "BRANCO";
		case 4:
			return "PRETO";
		case 5:
			return "VERDE";
		case 6:
			return "VERMELHO";
		default:
			return "BRANCO";
	}
}