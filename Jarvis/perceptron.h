#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h> 

using namespace std;
class perceptron
{
public:	
	~perceptron();
	perceptron(float eta, int epochs);
	float netInput(vector<float> X);
	int predict(vector<float> X);
	void fit(vector< vector<float> > X, vector<float> y);
	void printErrors();
	void exportWeights(string filename);
	void importWeights(string filename);
	void printWeights();
private:
	float m_eta;
	int m_epochs;
	vector < float > m_w;
	vector < float > m_errors;

};

