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
	cv::Ptr<cv::ml::ANN_MLP> red;//Red
	cv::Ptr<cv::ml::TrainData> tData;//Datos de prueba
	int numTrainingpoints = 30;//numero de puntos a entrenar.
	int numTestPoints = 100;//menor que la data para entrenar.
	int dataSize = 40;
	Red_Neuronal(cv::Mat layers);
	void cargar_data();
	void entrenar();
	void predecir();
	Red_Neuronal();
};

