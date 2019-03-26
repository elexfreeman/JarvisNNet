// Jarvis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"


#include <iostream>
#include <math.h>
#include "MultilayerPerceptron.h"
#include <time.h> 
using namespace std;

void fnc_xor() {
	int i;
	float err;
	vector<float> teInput;
	vector<float> teOutput;
	vector<float> teTest;
	MultilayerPerceptron *mlp;
	vector<MultilayerPerceptron::TrainingElement> trainingSet;

	mlp = new MultilayerPerceptron(2, 1);
	mlp->addHiddenLayer(3);
	mlp->addHiddenLayer(3);
	mlp->addHiddenLayer(3);
	/*mlp->addHiddenLayer(10);*/
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

	for (i = 0; i < 5000; i++) {
		err = mlp->train(0.9f);
		if (err < .0001f) {
			break;
		}

		cout << "iteration: " << i << ", error: " << err << "\n";
	}
	cout << "iteration: " << i << ", error: " << err << "\n";
	//классификация///
	teInput.clear();
	teOutput.clear();
	teInput.push_back(1);
	teInput.push_back(0);
	teOutput = mlp->classify(teInput);

	cout << " 1 0 = " << round(teOutput[0]);
	delete mlp;
}

/*конвертирует it в массив битов*/
vector<float> intToBin(int n) {
	int i, bottom, top;
	int m[8];
	vector<float> outBin;
	int number = n;

	for (i = 0; i < 8; i++)
	{
		m[i] = number % 2;
		number = number / 2;
	}

	for (bottom = 0, top = 7; bottom < 8; bottom++, top--)
	{
		outBin.push_back(m[top]);
	}
	return outBin;
}

void convertMBin() {
	char character;
	int number;
	int i;
	int m[8];
	vector<float> outBin;

	cout << "Please enter a character: ";
	cin >> number;
	cout << "You've entered " << number << endl;

	outBin = intToBin(number);

	for (i = 0; i < outBin.size(); i++) {
		cout << outBin[i];
	}
}

void testVectorMem() {
	std::vector<float> vec;

	for (long long ii = 0; ii < 1000000; ++ii) {
		vec.push_back(12.0f);
	}
}

int main()
{
	

	clock_t start = clock();
	
	fnc_xor();

	clock_t end = clock();
	double sec = (double)((end - start) / (CLOCKS_PER_SEC)*1000);
	printf("The time: %f ms\n", sec);
	std::cin.get();

	
	return 0;
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
