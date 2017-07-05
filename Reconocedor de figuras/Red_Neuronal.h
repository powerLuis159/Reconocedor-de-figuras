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
	//clase de cada uno 0: cuadrado, 1: triangulo y 2:circulo
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
	void cargar_data(std::string archivo,int tipo);
	//cambiado
	void entrenar();
	//obsoleto
	void predecir();
	Red_Neuronal();
	// devuelve 0 si es cuadrado ,1 si es triangulo ó 2 si es circulo
	int predecir(std::string archivo);
	// muestra como se ve una imagen luego de ser procesada
	void mostrar(std::string archivo);
	// devuelve una matriz ya procesada para ser trabajada con la red
	cv::Mat preprocesar(std::string archivo);
};

