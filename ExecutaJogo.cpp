#include "stdafx.h"
#include "ExecutaJogo.h"

ExecutaJogo::ExecutaJogo()
{

}

ExecutaJogo::~ExecutaJogo()
{

}

void ExecutaJogo::lerRecord() {
	ifstream stream;
	
	stream.open("record.txt");

	if (!stream.is_open()) {
		cout << "Nao foi possivel abrir o arquivo\n";
		stream.close();
		return;
	}

	char rcdStr[100];
	int record;
	while (!stream.eof()) {
		stream.getline(rcdStr, 100);
		record = atoi(rcdStr);
		iJogo.setRecord(record);
		cout << record << endl;
	}
	stream.close();
}
void ExecutaJogo::salvarRecord(){
	ofstream stream;
	
	stream.open("record.txt");

	if (!stream.is_open()) {
		cout << "Nao foi possivel abrir o arquivo\n";
		stream.close();
		return;
	}
	if(iJogo.getPontAtual() >= iJogo.getRecord()){
		stream << iJogo.getPontAtual();
	}
	else {
		stream << iJogo.getRecord();
	}
	stream.close();
}

int ExecutaJogo::CompararCores(int cor) {
	Mat cartao = imread("cartao.jpg");
	Mat compara;
	int ehCor;
	
	//Scalar(Blue, Green, Red)
	switch (cor){
	case 1: // Quando a cor for AMARELO
		inRange(cartao, Scalar(0,150,150), Scalar(100, 255, 255), compara); //Vê se a cor do cartao está na faixa de intervalo da cor correta
		ehCor = countNonZero(compara); // conta a quantidade de pixels brancos indicando a presença da cor correta ou não							   
		if (ehCor > 100) {
			return 1;
		}
		else {
			return -1;
		}
	case 2: // Quando a cor for AZUL
		inRange(cartao, Scalar(120, 0, 0), Scalar(255, 100, 100), compara);
		ehCor = countNonZero(compara);
		if (ehCor > 100) {
			return 1;
		}
		else {
			return -1;
		}
	case 3: // Quando a cor for BRANCO
		inRange(cartao, Scalar(180, 180, 180), Scalar(255, 255, 255), compara);
		ehCor = countNonZero(compara);
		if (ehCor > 100) {
			return 1;
		}
		else {
			return -1;
		}
	case 4:	// Quando a cor for PRETO
		inRange(cartao, Scalar(0, 0, 0), Scalar(50, 50, 50), compara);
		ehCor = countNonZero(compara);
		if (ehCor > 100) {
			return 1;
		}
		else {
			return -1;
		}
	case 5:	// Quando a cor for VERDE
		inRange(cartao, Scalar(0, 100, 0), Scalar(100, 255, 100), compara);
		ehCor = countNonZero(compara);
		if (ehCor > 100) {
			return 1;
		}
		else {
			return -1;
		}
	case 6:	// Quando a cor for VERMELHO
		inRange(cartao, Scalar(0, 0, 150), Scalar(50, 50, 255), compara);
		ehCor = countNonZero(compara);
		if (ehCor > 100) {
			return 1;
		}
		else {
			return -1;
		}
	default:
		return -1;
	}
}

void ExecutaJogo::ExecJogo() {
	lerRecord();
	while (iJogo.getTentativas() > 0) {
		int a = cor.geraCorRandom();
		
		iJogo.exibeInterface(a);
		if (CompararCores(a) == 1) {
			cout << "VOCE ACERTOU" << endl;
			iJogo.setPontAtual(25);
		}else {
			cout << "VOCE ERROU" << endl;
			iJogo.setTentativas(1);
		}
		salvarRecord();
	}
}
