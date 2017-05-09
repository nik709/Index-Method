#pragma once

#include "Map.h"
#include "TTrial.h"
#include "TInterval.h"
#include <vector>

class TIndexMethod {
public:
	TIndexMethod(const TInterval &_y1, const TInterval &_y2, double _r, int _m, int _source);
	void solve();
	double **getY(int &size);
private:
	//---------------parameters------------
	TInterval y1, y2;
	double r;
	int m;
	int source;
	int functionsQuantity;
	//---------------data------------------
	std::vector<TTrial> trials;
	//---------------functions-------------
	void init(const TInterval &_y1, const TInterval &_y2, double _r, int _m, int _source);
	double calculateFunction(const TTrial &trial);
	double calculateValue(const TTrial &trial, int numFunc);
	void makeTrial(TTrial &trial);
	void calculateIndex(TTrial &trial);
	void insert(const TTrial &trial);
	void calculateI(std::vector<TTrial> *I);
	int findMaxV();
	void calculateM(double *M, std::vector<TTrial> *I);
	void calculateZ(double *Z, int maxIndex);
	double findMinValue();
	int calculateR(double *M, double *Z);
	void insertNewX(int interval, double *M);
	bool checkStop(int interval);
};

TIndexMethod::TIndexMethod(const TInterval &_y1,const TInterval &_y2, double _r, int _m, int _source) {
	init(_y1, _y2, _r, _m, _source);

	TTrial t1;
	t1.x = 0;
	t1.v = -1;
	trials.push_back(t1);

	TTrial t2;
	t2.x = 1;
	t2.v = -1;
	trials.push_back(t2);

	TTrial t3;
	t3.x = 0.5;
	t3.y = new double[2];
	makeTrial(t3);
	insert(t3);
}

void TIndexMethod::init(const TInterval &_y1, const TInterval &_y2, double _r, int _m, int _source) {
	y1 = _y1;
	y2 = _y2;
	r = _r;
	m = _m;
	source = _source;
	functionsQuantity = 4;
}

double TIndexMethod::calculateFunction(const TTrial &trial) {
	return (-1.5)*(trial.y[0] * trial.y[0])*exp(1 - trial.y[0] * trial.y[0] - 20.25*(trial.y[0] - trial.y[1])*(trial.y[0] - trial.y[1])) -
		pow(0.5*(trial.y[0] - 1)*(trial.y[1] - 1), 4)*exp(2 - pow(0.5*(trial.y[0] - 1), 4) - pow((trial.y[1] - 1), 4));
}

double TIndexMethod::calculateValue(const TTrial &trial, int numFunc) {
	switch (numFunc) {
	case 0:
		return 0.01 * ((trial.y[0] - 2.2)*(trial.y[0] - 2.2) + (trial.y[1] - 1.2)*(trial.y[1] - 1.2) - 2.25);
	case 1:
		return 100 * (1 - ((trial.y[0] - 2)*(trial.y[0] - 2) / 1.44) - (0.5*trial.y[1])*(0.5*trial.y[1]));
	case 2:
		return 10 * (trial.y[1] - 1.5 - 1.5*sin(6.283*(trial.y[0] - 1.75)));
	case 3:
		return calculateFunction(trial);
	}
}

void TIndexMethod::makeTrial(TTrial &trial) {
	double *y = new double[2];
	mapd(trial.x, m, y, 2, 1);
	y[0] = y1.a + (y1.b - y1.a)*(y[0] + 0.5);
	y[1] = y2.a + (y2.b - y2.a)*(y[1] + 0.5);
	trial.y[0] = y[0];
	trial.y[1] = y[1];
	calculateIndex(trial);
	delete[]y;
}

void TIndexMethod::calculateIndex(TTrial &trial) {
	for (int i = 0; i < functionsQuantity; i++) {
		trial.z = calculateValue(trial, i);
		if (i == functionsQuantity-1 || trial.z >0) {
			trial.v = i;
			break;
		}
	}
}

void TIndexMethod::insert(const TTrial &trial) {
	for (int i = 0; i < trials.size(); i++) {
		if (trial < trials.at(i)){
			trials.insert(trials.begin() + i, trial);
			break;
		}
	}
}




void TIndexMethod::solve() {
	bool isEnd = false;
	while (!isEnd) {
		std::vector<TTrial> *I = new std::vector<TTrial>[functionsQuantity];
		double *M = new double[functionsQuantity];
		double *Z = new double[functionsQuantity];

		calculateI(I);
		int maxV = findMaxV();

		calculateM(M, I);

		calculateZ(Z, maxV);

		int t = calculateR(M, Z);

		insertNewX(t, M);

		if (checkStop(t)) {
			isEnd = true;
		}

		delete[]I;
		delete[]M;
		delete[]Z;
		I = nullptr;
		M = nullptr;
		Z = nullptr;
	}
}

void TIndexMethod::calculateI(std::vector<TTrial> *I) {
	for (int i = 0; i < functionsQuantity; i++) {
		I[i].clear();
	}

	for (int i = 0; i < functionsQuantity; i++) {
		for (TTrial trial : trials) {
			if (i == trial.v) {
				I[i].push_back(trial);
			}
		}
	}
}

int TIndexMethod::findMaxV() {
	int max = 0;
	for (TTrial trial : trials) {
		if (trial.v > max) {
			max = trial.v;
		}
	}
	return max;
}

void TIndexMethod::calculateM(double *M, std::vector<TTrial> *I) {
	for (int i = 0; i < functionsQuantity; i++) {
		if (I[i].size() < 2) {
			M[i] = 1;
			continue;
		}
		double MaxM = -HUGE_VAL;
		double tm;
		for (unsigned j = 1; j < I[i].size(); j++) {
			double dx =
				tm = fabs(I[i].at(j).z - I[i].at(j - 1).z) / (pow(I[i].at(j).x - I[i].at(j - 1).x, 1.0 / 2.0));
			if (MaxM < tm)
				MaxM = tm;
		}
		if (MaxM > 0)
			M[i] = MaxM;
		else
			M[i] = 1;
	}
}

void TIndexMethod::calculateZ(double *Z, int maxIndex) {
	memset(Z, 0, sizeof(double)*functionsQuantity);
	for (int i = 0; i < functionsQuantity; i++) {
		if (i < maxIndex) {
			continue;
		}
		Z[i] = findMinValue();
		break;
	}
}

double TIndexMethod::findMinValue() {
	double min = trials.at(1).z;
	for (int i = 2; i < trials.size() - 1; i++) {
		if (min > trials.at(i).z) {
			min = trials.at(i).z;
		}
	}
	return min;
}

int TIndexMethod::calculateR(double *M, double *Z) {
	int t = 0;
	double R;
	double maxR = -HUGE_VAL;

	for (int i = 1; i < trials.size(); i++) {
		TTrial t1 = trials.at(i - 1);
		TTrial t2 = trials.at(i);
		double dx = pow((t2.x - t1.x), (1.0 / 2.0));
		if (t1.v == t2.v) {
			int v = t1.v;
			R = dx + (t2.z - t1.z)*(t2.z - t1.z) / (dx*M[v] * M[v] * r*r) - 2 * (t2.z + t1.z - 2 * Z[v]) / (r*M[v]);
		}
		if (t2.v > t1.v) {
			int v = t2.v;
			R = 2 * dx - 4 * (t2.z - Z[v]) / (r*M[v]);
		}
		if (t1.v > t2.v) {
			int v = t1.v;
			R = 2 * dx - 4 * (t1.z - Z[v]) / (r*M[v]);
		}
		if (R > maxR) {
			maxR = R;
			t = i;
		}
	}

	return t;
}

void TIndexMethod::insertNewX(int interval, double *M) {
	TTrial t1 = trials.at(interval - 1);
	TTrial t2 = trials.at(interval);
	
	TTrial newX;
	newX.y = new double[2];

	if (t1.v != t2.v) {
		newX.x = (t2.x + t1.x) / 2.0;
	}
	else {
		double centre = (t2.x + t1.x) / 2.0;
		int sign = 1;
		if (t2.z < t1.z)
			sign *= -1;
		double coef = 1.0 / (2.0 * r);
		double dx = pow(abs(t2.z - t1.z) / (M[t1.v]), 2);
		newX.x = centre - sign * coef * dx;
	}
	makeTrial(newX);
	insert(newX);
}

bool TIndexMethod::checkStop(int interval) {
	TTrial t1 = trials.at(interval - 1);
	TTrial t2 = trials.at(interval);

	if (pow(t2.x - t1.x, 1.0 / 2.0) < 1e-3)
		return true;
	if (source < trials.size())
		return true;
	return false;
}



double** TIndexMethod::getY(int &size) {
	size = trials.size() - 2;
	double **y = new double*[trials.size()];
	for (int i = 1; i < trials.size()-1; i++) {
		y[i-1] = new double[2];
		y[i-1][0] = trials.at(i).y[0];
		y[i-1][1] = trials.at(i).y[1];
	}

	return y;
}