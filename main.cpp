#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;
using namespace std::chrono;

#define MAX 20000

int main()
{
    vector<double> y(MAX, 0);
    vector<vector<double>> A(MAX, vector<double>(MAX, 0));
    vector<double> x(MAX, 0);
    
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            y[i] += A[i][j] * x[j];
        
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    duration<double> time = duration_cast<nanoseconds>(t2 - t1);

    fill(y.begin(), y.end(), 0);

    high_resolution_clock::time_point t3 = high_resolution_clock::now();
    
    for (int j = 0; j < MAX; j++)
        for (int i = 0; i < MAX; i++)
            y[i] += A[i][j] * x[j];

    high_resolution_clock::time_point t4 = high_resolution_clock::now();

    duration<double> time1 = duration_cast<nanoseconds>(t4 - t3);
    
    cout << "PRIMER BUCLE: " << time.count() << endl;
    cout << "SEGUNDO BUCLE: " << time1.count() << endl;

    return 0;
}
