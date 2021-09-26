#pragma once

class Neuron
{
	private:
		double weight = 0.1;
		double lastError = 0;
		double smoothing = 0.00001;

	public:
		Neuron()
		{

		}
		
		double GetWeight();
		double GetLastError();
		double GetSmoothing();
		double ProcessInputData(double input);
		double RestoreInputData(double output);
		void Train(double input, double expectedResult);
};