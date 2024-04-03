#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include "monte_carlo.hpp"

using namespace std;

int main()
{
	// declare variables
	int steps, sims;
  unsigned int j, k;
	double stockPrice, rate, time, vol, strike;
	double payoff, avgPayoff, callPrice;
	vector < vector <double> > paths;
	ofstream output;
	

	// get input
	cout << "STOCK_PRICE STRIKE TIME(days) VOLATILITY(decimal) INTEREST_RATE(decimal) STEPS SIMULATIONS" << endl;
	cin >> stockPrice >> strike >> time >> vol >> rate >> steps >> sims;

	// run simulation and retrun paths
	Monte_Carlo mc(stockPrice, time, vol, rate, steps, sims);
	paths = mc.Simulate();

	avgPayoff = 0;

	// compute payoff for each ending price and take average 
	for (j = 0; j < paths.size(); j++)
	{
		// calculate option payoff
		payoff = paths[j][paths[j].size() - 1] - strike;
		
		// add payoff to avgPayoff
		if (payoff > 0) avgPayoff += payoff;
	}

	// write to file
	output.open("simulation.txt");
  for (j = 0; j < paths.size(); j++) {
		for (k = 0; k < paths[j].size(); k++) {
			output << paths[j][k];
			output << "\n";
		}
		output << "-";
		output << "\n";
	}
	

	// take average of payoffs
	avgPayoff = avgPayoff / sims;

	// discount average option back to present value 
	callPrice = avgPayoff * exp(((time/252) * rate * -1));

	// print call price 
	cout << "CALL PRICE " << callPrice << endl;
	output << stockPrice << " " << strike << " " << vol << " " << time << " " << callPrice << endl;
  output.close();

	return 0;
}
