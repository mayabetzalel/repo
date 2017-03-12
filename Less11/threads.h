#include <string>
#include <fstream>
#include <iostream>
#include<vector>

using namespace std;


void I_Love_Threads();
void call_I_Love_Threads();

void printVector(vector<int> primes);

void getPrimes(int begin, int end, vector<int>& primes);
vector<int> callGetPrimes(int begin, int end);


void writePrimesToFile(int begin, int end, ofstream& file);
void callWritePrimesMultipleThreads(int begin, int end, string filePath, int N);