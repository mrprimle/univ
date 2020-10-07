#include <iostream>
using namespace std;

bool is_positive(int a) {
	if (a > 0) {
		return true;
	}
	else {
		return false;
	}
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

bool high_year (int year) {
	if ((year % 4 == 0) and !(year % 100 == 0 and year % 400 != 0)) {
		return true;
	}
	else {
		return false;
	}
}