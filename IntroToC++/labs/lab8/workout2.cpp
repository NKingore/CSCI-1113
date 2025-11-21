#include <iostream>
#include <cstdlib>
using namespace std;

//generates a random vector
double* randVec(){
//allocate space for the 3 element array
    double* arr = (double*)malloc(3 * sizeof(double));

//fill array with random values from -100 to 100
    for (int i = 0; i < 3; i++){
        double val = ((double)rand() / RAND_MAX) * 200.0 - 100.0;
        arr[i] = val;
    }

    return arr;
}

//returns momentum when given velocity as a vector and mass
double* momentum(double velocity[], double mass){
	double *val = new double[3];
	for (int i = 0; i < 3; i++){
		 val[i] = velocity[i] * mass;
	}
	return val;
    delete[] val;
    delete[] velocity;
}

int main(){
//seed random number
    srand((unsigned int)time(NULL));\

//declare variables    
    double mass = 1.0 + ((double)rand() / RAND_MAX) * (10.0 - 1.0);
    double* final[1000];

    for (int i = 0; i < 1000; i++){
        double* v = randVec();
        final[i] = momentum(v, mass);
        std::free(v);
    }

//find the average momentum vector
    double avg[3] = {0.0, 0.0, 0.0};
    for (int i = 0; i < 1000; i++){
        avg[0] += final[i][0];
        avg[1] += final[i][1];
        avg[2] += final[i][2];    
    }
    for (int j = 0; j < 3; j++){
        avg[j] /= 1000;
    }

//display average momentum vector
    cout << "The average momentum is " << avg[0] << ", " << avg[1] << ", " << avg[2] << endl;

    for (int i = 0; i < 1000; i++){
        delete[] final[i];
    }
    
    return 0;
}