#include <iostream>
#include <chrono>
#include <thread>
#include "neuron.h"

#define sleep(x) std::this_thread::sleep_for(std::chrono::milliseconds(x));

int main()
{
    double RUB = 74119;
    double USD = 1000;

    Neuron* neuron = new Neuron();
    int i = 0;

    do {
        i++;
        neuron->Train(RUB, USD);

        if (i % 100 == 0) {
            std::cout
                << "Iteration "
                << i
                << ": "
                << RUB
                << " RUB = "
                << neuron->ProcessInputData(RUB)
                << " USD\n"
                << "Weight: "
                << neuron->GetWeight() << "\n"
                << "LastError: "
                << neuron->GetLastError() << "\n";

            // sleep(150);
        }
    }
    while (std::abs(neuron->GetLastError()) > neuron->GetSmoothing());
}