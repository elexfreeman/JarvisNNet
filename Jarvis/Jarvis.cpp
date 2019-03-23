// Jarvis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"


#include <iostream>
#include <math.h>
#include "MultilayerPerceptron.h"
using namespace std;
int main()
{
	int i;
	float err;
	vector<float> teInput;
	vector<float> teOutput;
	vector<float> teTest;
	MultilayerPerceptron *mlp;
	vector<MultilayerPerceptron::TrainingElement> trainingSet;
	
	mlp = new MultilayerPerceptron(2, 1);
	mlp->addHiddenLayer(10);
	mlp->addHiddenLayer(10);
	mlp->init();	
	

	teInput.push_back(0);
	teInput.push_back(0);	
	teOutput.push_back(0);
	trainingSet.push_back(MultilayerPerceptron::TrainingElement(teInput, teOutput));

	teInput.clear();
	teOutput.clear();
	teInput.push_back(0);
	teInput.push_back(1);
	teOutput.push_back(1);
	trainingSet.push_back(MultilayerPerceptron::TrainingElement(teInput, teOutput));

	teInput.clear();
	teOutput.clear();
	teInput.push_back(1);
	teInput.push_back(0);
	teOutput.push_back(1);
	trainingSet.push_back(MultilayerPerceptron::TrainingElement(teInput, teOutput));
	teInput.clear();
	teOutput.clear();
	teInput.push_back(1);
	teInput.push_back(1);
	teOutput.push_back(0);
	trainingSet.push_back(MultilayerPerceptron::TrainingElement(teInput, teOutput));
	mlp->setTrainingSet(trainingSet);

	for (i = 0; i < 990; i++) {
		err = mlp->train(0.9f);
		cout << "iteration: " << i << ", error: " << err << "\n";
	}

	//классификация///
	teInput.clear();
	teOutput.clear();
	teInput.push_back(1);
	teInput.push_back(0);
	teOutput = mlp->classify(teInput);

	cout << " 1 0 = " << teOutput[0];


	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
