#include "stdafx.h"
#include "InterfaceJogo.h"

InterfaceJogo::InterfaceJogo()
{
	tentativas = 5;
	pontAtual = 0;
}

InterfaceJogo::~InterfaceJogo()
{

}

void InterfaceJogo::setTentativas(int a)
{
	tentativas -= a;
}

int InterfaceJogo::getTentativas()
{
	return tentativas;
}

void InterfaceJogo::setPontAtual(int a)
{
	pontAtual += a;
}

int InterfaceJogo::getPontAtual()
{
	return pontAtual;
}

void InterfaceJogo::setRecord(int a)
{
	record = a;
}

int InterfaceJogo::getRecord()
{
	return record;
}

void InterfaceJogo::exibeInterface(int a)
{
	cout << "\t Tentativas restantes: " << tentativas << endl;
	cout << "Pontuacao atual: " << pontAtual << "\t" << "Record: " << record << endl;

	VideoCapture WebCAM(0); // Abre a WebCAM

	if (!WebCAM.isOpened())  // Verifica se foi possível abrir a WebCAM
	{
		cout << "Não foi possivel abrir a WebCAM." << endl;
		return;
	}

	cout << "Mostre o cartao correspondente a cor: " << cor.exibeCor(a) << endl;
	cout << "Voce tem 10s para responder\n";
	namedWindow("WebCAM", CV_WINDOW_AUTOSIZE); //Cria uma janela chamada "WebCAM"
	
	Mat aux;			// (650, 600, CV_16UC3);

	while (1)
	{
		Mat frame;

		bool bSuccess = WebCAM.read(frame); // Lê um novo frame da WebCAM

		if (!bSuccess) // Vefica se o frame foi lido corretamente
		{
			cout << "Nao foi possivel ler um novo frame da WebCAM" << endl;
			break;
		}

		aux = frame;
		imshow("WebCAM", frame); // Mostra o frame na janela "WebCAM"

		if (waitKey(30) == 27) // Espera o usuario pressionar 'Esc' para fechar a WebCAM
		{	
			if (aux.empty()) // Verifica se a imagem foi carregada corretamente
			{
				cout << "ERRO: Nao foi possivel abrir a imagem" << endl;
				system("PAUSE");
				return;
			}

			vector<int> compression_params; // Vetor que armazena os parâmetros de compressão da imagem
			compression_params.push_back(CV_IMWRITE_JPEG_QUALITY); // Especifica a técnica de compressão da imagem
			compression_params.push_back(98); // Especifica a qualidade da compressão da imagem

			bool bSuccess = imwrite("cartao.jpg", aux, compression_params); // Grava a imagem no arquivo

			if (!bSuccess){
				cout << "ERRO: Nao foi possivel salvar a imagem" << endl;
				system("PAUSE");
			}
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}

	return;
}