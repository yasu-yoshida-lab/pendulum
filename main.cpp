#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

namespace
{
	constexpr double dX0 = 10.0;
	constexpr double dDeltaTime = 2.0;
	constexpr double dEndTime = 500.0;
	constexpr double dG = 9.8;
	constexpr double dL = 10.0;
	constexpr double dM = 2.0;
	constexpr auto dK = 0.02;
	constexpr double dMU = 0.01;
}

void output(std::vector<double>& vecX, std::vector<double>& vecY)
{
	std::ofstream ofs("result.txt");
	for (size_t i = 0; i < vecX.size(); ++i)
	{
		ofs << vecX[i] << '\t' << vecY[i] << std::endl;
	}
	ofs.close();
}

int main()
{
	int iPlotNumber = 0;
	double dDeltaTheta = 0.0;
	double dDeltaY = 10.0;

	std::vector<double> vecTime;
	std::vector<double> vecThetaDot;
	std::vector<double> vecX;
	std::vector<double> vecY;

	vecX.push_back(dX0);
	vecThetaDot.push_back(0.0);

	for (double t = 0.0; t < dEndTime; t+=dDeltaTime)
	{
		vecTime.push_back(t);
		dDeltaTheta = - dG / dL * sin(vecX[iPlotNumber] / 2.0 / M_PI) - dK / dM * vecThetaDot[iPlotNumber];
		dDeltaY = dL - (dG / dL) * cos(vecX[iPlotNumber] / 2.0 / M_PI);
		vecThetaDot.push_back(vecThetaDot[iPlotNumber] + dDeltaTheta * dDeltaTime);
		vecX.push_back(vecX[iPlotNumber] + vecThetaDot[iPlotNumber + 1] + dDeltaTime);
		vecY.push_back(dDeltaY);
		++iPlotNumber;
	}
	output(vecX, vecY);
	return 0;
}

