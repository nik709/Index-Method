#pragma once

struct TInterval {
	double a;
	double b;
	TInterval(double _a, double _b);
	TInterval();
	TInterval& operator=(const TInterval &interval);
};

TInterval::TInterval(double _a, double _b) {
	a = _a;
	b = _b;
}

TInterval::TInterval() {
	a = b = 0;
}

TInterval& TInterval::operator=(const TInterval &interval){
	a = interval.a;
	b = interval.b;
	return *this;
}