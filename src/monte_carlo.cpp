#include "monte_carlo.hpp"
#include <iostream>
#include <random>
#include <vector>
#include <chrono>

Monte_Carlo::Monte_Carlo()
{
	stockPrice = 0;
	time = 0;
	vol = 0;
	mu = 0;
	steps = 0;
	dt = 0;
	sims = 0;
}

Monte_Carlo::Monte_Carlo(double sP, double T, double V, double M, int step, int sim)
{
	stockPrice = sP;
	time = T;
	vol = V;
	mu = M;
	steps = step;

	dt = time / steps;
	sims = sim;
}

vector < vector <double> > Monte_Carlo::Simulate()
{
	// declare variables 
	vector <double> prices;
	vector < vector <double> > paths;
	double newPrice;
	int j, k;

	j = 1;

	for (k = 0; k < sims; k++)
	{
		// clear prices and push stockPrice onto the prices vector 
		prices.clear();
		prices.push_back(stockPrice);
		while (j < steps)
		{
		
			// generate price using GBM
			newPrice = prices[j - 1] * (exp((mu - .5 * vol * vol) * dt + vol * normal_dist(sqrt(dt))));
			prices.push_back(newPrice);
			j++;
		}

		// push back onto paths and reset variables
		paths.push_back(prices);
		j = 1;
		
	}

	return paths;
}

// randomly select values from normal distribution 
double Monte_Carlo::normal_dist(double sigma)
{
	unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	normal_distribution<double> dist(0, sigma);

	return dist(generator);
}