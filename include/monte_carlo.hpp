#pragma once

#include <vector>

using namespace std; 

class Monte_Carlo
{

public:
	Monte_Carlo();
	Monte_Carlo(double sP, double T, double V, double M, int step, int sim);
	vector < vector <double> > Simulate(); 

private:

	double normal_dist(double sigma);

	double stockPrice;
	double time;
	double vol;
	double mu;
	double dt;
	int steps;
	int sims;
};