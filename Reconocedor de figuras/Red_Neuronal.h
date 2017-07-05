#pragma once
#include <stdio.h>
#include <tchar.h>
#include <opencv2\opencv.hpp>
#include <opencv2\ml.hpp>
#include <vector>
#include <string>
class Red_Neuronal
{
public:
	//Red perceptron multicapa
	cv::Ptr<cv::ml::ANN_MLP> red;
	//Datos de prueba
	cv::Mat tData;
	//clase de cada uno /true: cuadrado, false: triangulo
	cv::Mat tClass;
	//numero de datos a entrenar.
	int numTrainingdata = 0;
	//tamaño de los datos dataSize*dataSize
	int dataSize = 40;
	//constructor layers debe ser el modelo
	Red_Neuronal(cv::Mat layers);
	//obsoleto
	void cargar_data();
	//carga una imagen a los datos de entrenamiento e indicando de que clase es
	void cargar_data(std::string archivo,bool tipo);
	//cambiado
	void entrenar();
	//obsoleto
	void predecir();
	Red_Neuronal();
	// devuelve true si es cuadrado o false si es triangulo
	bool predecir(std::string archivo);
};

