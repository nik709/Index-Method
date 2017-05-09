#pragma once

struct TTrial {
	double x;
	double *y;
	double z;
	int v;
};

inline bool operator<(const TTrial &t1, const TTrial &t2){
	return t1.x < t2.x;
}