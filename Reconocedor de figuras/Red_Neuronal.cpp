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

void Red_Neuronal::cargar_data(std::string archivo, bool tipo)
{
	cv::Mat temp=cv::imread(archivo.data(), cv::ImreadModes::IMREAD_GRAYSCALE);
	std::vector<std::vector<cv::Point>> v_contornos;
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
			tData.at<float>(numTrainingdata, i * 40 + j) = (float)temp.at<unsigned char>(i, j) / 256;
		}

	}
	if (tipo)
		tClass.at<float>(numTrainingdata, 0) = 1.0f;
	else
		tClass.at<float>(numTrainingdata, 0) = -1.0f;
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
	layers.row(3) = cv::Scalar(1);

	red = cv::ml::ANN_MLP::create();
	red->setLayerSizes(layers);
	red->setActivationFunction(cv::ml::ANN_MLP::ActivationFunctions::SIGMOID_SYM);
	tData=cv::Mat(1000,40*40,CV_32F);
	tClass=cv::Mat(1000,1,CV_32F);
}


// devuelve true si es cuadrado o false si es triangulo
bool Red_Neuronal::predecir(std::string archivo)
{
	cv::Mat temp = cv::imread(archivo.data(), cv::ImreadModes::IMREAD_GRAYSCALE);
	std::vector<std::vector<cv::Point>> v_contornos;
	cv::findContours(temp, v_contornos, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
	for (size_t i = 0; i < v_contornos.size(); i++)
	{
		cv::drawContours(temp, v_contornos, (int)i, 0, 15, cv::LineTypes::LINE_8);
	}

	cv::resize(temp, temp, cv::Size(40, 40));
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
	float resultado = salida.at<float>(0, 0);
	if (resultado > 0)
		return true;
	return false;
}
