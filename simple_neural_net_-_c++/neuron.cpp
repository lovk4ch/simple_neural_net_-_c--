#include "neuron.h"

double Neuron::GetWeight()
{
	return weight;
}

double Neuron::GetLastError()
{
	return lastError;
}

double Neuron::GetSmoothing()
{
	return smoothing;
}

double Neuron::ProcessInputData(double input)
{
	return weight * input;
}

double Neuron::RestoreInputData(double output)
{
	return output / weight;
}

void Neuron::Train(double input, double expectedResult)
{
	double actualResult = input * weight;
	lastError = expectedResult - actualResult;
	double correction = (lastError / actualResult) * smoothing;
	weight += correction;
}