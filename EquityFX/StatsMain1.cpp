#include "VanillaOption2.h"
#include "SimpleMC6.h"
#include "MCStatistics.h"
#include <iostream>

using namespace std;

int main()
{
	double Expiry, Strike, Spot, Vol, r;
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;
	cout << "\nStrike\n";
	cin >> Strike;
	cout << "\nEnter spot\n";
	cin >> Spot;
	cout << "\nEnter vol\n";
	cin >> Vol;
	cout << "\nr\n";
	cin >> r;
	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

	PayOffPut thePayOff(Strike);
	VanillaOption theOption(thePayOff, Expiry);
	ParametersConstant VolParam(Vol);
	ParametersConstant rParam(r);
	StatisticsMean gatherer;

	SimpleMonteCarlo5(theOption, Spot, VolParam, rParam, NumberOfPaths, gatherer);

	vector<vector<double>> results = gatherer.GetResultsSoFar();
	cout << "\nthe put price are  \n";

	for (unsigned long i = 0; i < results.size(); ++i) {
		for (unsigned long j = 0; j < results[i].size(); ++j) {
			cout << results[i][j] << " ";
		}
		cout << "\n";
	}

	double tmp;
	cin >> tmp;
	return 0;

}