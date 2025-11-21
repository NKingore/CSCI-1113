#include <iostream>
using namespace std;

double* momentum(double velocity[], double mass){
	double *val = new double[3];
	for (int i = 0; i < 3; i++){
		 val[i] = velocity[i] * mass;
	}
	return val;
}

int main(){
	double velocity[3], mass;
	double* hhh;
	cout << "Input velocity in components" << endl;
	cin >> velocity[0] >> velocity[1] >> velocity[2];
	cout << "Input mass" << endl;
	cin >> mass;

	hhh = momentum(velocity, mass);
	
	for (int i = 0; i < 3; i++){
		cout << "Momentum: " << hhh[i] << endl;
	}
	
	delete[] hhh;
	
	return 0;
}
