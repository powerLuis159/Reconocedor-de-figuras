#include "Red_Neuronal.h"



Red_Neuronal::Red_Neuronal(cv::Mat layers)
{
	red = cv::ml::ANN_MLP::create();
	red->setLayerSizes(layers);
	red->setActivationFunction(cv::ml::ANN_MLP::ActivationFunctions::SIGMOID_SYM);
}

void Red_Neuronal::cargar_data()
{
	cv::Mat temp;
	cv::Mat testData(50, 40 * 40, CV_32F);
	std::vector<std::vector<cv::Point>> v_contornos;

	std::string path = "C:/Users/LRona/Downloads/Imagenes geometricas Ale/CUADRADOS-IMAGEN/CUADRADOS IMAGEN/Cuadrado";


	for (size_t k = 0; k < 30; k++)
	{
		temp = cv::imread((path + std::to_string(k + 1) + ".jpg"), cv::ImreadModes::IMREAD_GRAYSCALE);
		cv::findContours(temp, v_contornos, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
		for (size_t i = 0; i < v_contornos.size(); i++)
		{
			cv::drawContours(temp, v_contornos, (int)i, 0, 15, cv::LineTypes::LINE_8);
		}

		cv::resize(temp, temp, cv::Size(40, 40));

		for (size_t i = 0; i < temp.rows; i++)
		{
			for (size_t j = 0; j < temp.cols; j++)
			{
				testData.at<float>(k, i * 40 + j) = (float)temp.at<unsigned char>(i, j) / 256;
			}

		}
	}

	path = "C:/Users/LRona/Downloads/Imagenes geometricas Ale/triangulos/t";

	for (size_t k = 0; k < 20; k++)
	{
		temp = cv::imread((path + std::to_string(k + 1) + ".jpg"), cv::ImreadModes::IMREAD_GRAYSCALE);
		cv::findContours(temp, v_contornos, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
		for (size_t i = 0; i < v_contornos.size(); i++)
		{
			cv::drawContours(temp, v_contornos, (int)i, 0, 15, cv::LineTypes::LINE_8);
		}

		cv::resize(temp, temp, cv::Size(40, 40));
		for (size_t i = 0; i < temp.rows; i++)
		{
			for (size_t j = 0; j < temp.cols; j++)
			{
				testData.at<float>(k + 30, i * 40 + j) = (float)temp.at<unsigned char>(i, j) / 256;
			}

		}
	}

	cv::Mat testClass(50, 1, CV_32F);
	for (size_t i = 0; i < 30; i++)
	{
		testClass.at<float>(i, 0) = 1.0;
	}
	for (size_t i = 30; i < 50; i++)
	{
		testClass.at<float>(i, 0) = -1.0;
	}


	//tData = cv::ml::TrainData::create(testData, cv::ml::SampleTypes::ROW_SAMPLE, testClass);
}

void Red_Neuronal::cargar_data(std::string archivo, int tipo)
{
	cv::Mat temp = preprocesar(archivo);
	for (size_t i = 0; i < temp.rows; i++)
	{
		for (size_t j = 0; j < temp.cols; j++)
		{
			tData.at<float>(numTrainingdata, i * 40 + j) = (float)temp.at<unsigned char>(i, j) / 256;
		}

	}
	tClass.at<float>(numTrainingdata, 0) = -1.0f;//cuadrado
	tClass.at<float>(numTrainingdata, 1) = -1.0f;//triangulo
	tClass.at<float>(numTrainingdata, 2) = -1.0f;//circulo
	tClass.at<float>(numTrainingdata, (tipo % 3)) += 2.0f;//truco para evitarnos el switch

	numTrainingdata++;
}

void Red_Neuronal::entrenar()
{
	tData.resize(numTrainingdata);
	tClass.resize(numTrainingdata);
	cv::Ptr<cv::ml::TrainData> trainData = cv::ml::TrainData::create(tData, cv::ml::SampleTypes::ROW_SAMPLE, tClass);
	red->train(trainData);
}

void Red_Neuronal::predecir()
{
	cv::Mat temp;
	cv::Mat testData(60, 40 * 40, CV_32F);
	std::vector<std::vector<cv::Point>> v_contornos;

	std::string path = "C:/Users/LRona/Downloads/Imagenes geometricas Ale/images/";


	for (size_t k = 0; k < 60; k++)
	{
		temp = cv::imread((path + std::to_string(k + 1) + ".png"), cv::ImreadModes::IMREAD_GRAYSCALE);
		cv::findContours(temp, v_contornos, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);

		for (size_t i = 0; i < v_contornos.size(); i++)
		{
			cv::drawContours(temp, v_contornos, (int)i, 0, 15, cv::LineTypes::LINE_8);
		}

		cv::resize(temp, temp, cv::Size(40, 40));

		for (size_t i = 0; i < temp.rows; i++)
		{
			for (size_t j = 0; j < temp.cols; j++)
			{
				testData.at<float>(k, i * 40 + j) = (float)temp.at<unsigned char>(i, j) / 256;
			}

		}
	}
	cv::Mat resultado;
	float a = red->predict(testData, resultado);
	
}

Red_Neuronal::Red_Neuronal()
{
	cv::Mat layers = cv::Mat(4, 1, CV_32SC1);
	layers.row(0) = cv::Scalar(1600);
	layers.row(1) = cv::Scalar(400);
	layers.row(2) = cv::Scalar(40);
	layers.row(3) = cv::Scalar(3);

	red = cv::ml::ANN_MLP::create();
	red->setLayerSizes(layers);
	red->setActivationFunction(cv::ml::ANN_MLP::ActivationFunctions::SIGMOID_SYM);
	tData=cv::Mat(1000,40*40,CV_32F);
	tClass=cv::Mat(1000,3,CV_32F);
}


// devuelve true si es cuadrado o false si es triangulo
int Red_Neuronal::predecir(std::string archivo)
{
	cv::Mat temp = preprocesar(archivo);
	cv::Mat entrada, salida;
	entrada = cv::Mat(1, 40 * 40, CV_32F);
	for (size_t i = 0; i < temp.rows; i++)
	{
		for (size_t j = 0; j < temp.cols; j++)
		{
			entrada.at<float>(0, i * 40 + j) = (float)temp.at<unsigned char>(i, j) / 256;
		}

	}
	red->predict(entrada, salida);
	//devolvemos 0 si es cuadrado, 1 si es triangulo o 2 si es circulo
	int resultado = 0;
	float resultado0 = salida.at<float>(0, 0);
	float resultado1 = salida.at<float>(0, 1);
	float resultado2 = salida.at<float>(0, 2);
	if (resultado0 > resultado1)
		if (resultado0 > resultado2)
			resultado = 0;
		else
			resultado = 2;
	else
		if (resultado1 > resultado2)
			resultado = 1;
		else
			resultado = 2;
	return resultado;
}


// muestra como se ve una imagen luego de ser procesada
void Red_Neuronal::mostrar(std::string archivo)
{
	cv::Mat temp = preprocesar(archivo);
	cv::imshow("imagen procesada", temp);
	cv::waitKey();
}


// devuelve una matriz ya procesada para ser trabajada con la red
cv::Mat Red_Neuronal::preprocesar(std::string archivo)
{
	cv::Mat temp = cv::imread(archivo.data(), cv::ImreadModes::IMREAD_GRAYSCALE);
	std::vector<std::vector<cv::Point>> v_contornos;
	cv::findContours(temp, v_contornos, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
	for (size_t i = 0; i < v_contornos.size(); i++)
	{
		cv::drawContours(temp, v_contornos, (int)i, 0, 15, cv::LineTypes::LINE_8);
	}

	cv::resize(temp, temp, cv::Size(40, 40));
	return temp;
}
