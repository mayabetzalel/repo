#include "threads.h"
#include <iostream>
#include <thread>
#include <vector>
#include <math.h>
#include <time.h>
#include <iomanip> 
#include <chrono> 

using namespace std;

/////////A

/**
Prints to screen.
*/
void I_Love_Threads()
{
	cout << "I Love Threads" << "\n";
}


/**
Calls anouther function using thread
*/
void call_I_Love_Threads()
{
	std::thread t1(I_Love_Threads);
	t1.join();
}


/////////B

/**
Input: range of numbers and vector to all the primes numbers 
between the range.
*/
void getPrimes(int begin, int end, vector<int>& primes)
{
	bool isPrime = true;
	for (int i = begin; i < end; i++)
	{
		for (int j = 2; j < sqrt(i); j++)
		{
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			primes.push_back(i);
		isPrime = true;
	}
}

/**
Input: vector to print.
*/
void printVector(vector<int> primes)
{
	for (auto it = primes.begin(); it != primes.end(); ++it)
		cout << *it << endl;
}


/**
Create thread of function and calculate the running time of the thread.
Input: range of two numbers.
output: integers vector.
*/
vector<int> callGetPrimes(int begin, int end)
{
	vector<int> primes;
	clock_t tStart = clock();
	std::thread t1(getPrimes, ref(begin), ref(end), ref(primes));
	t1.join();
	cout << "\nTime taken: " << (clock() - tStart) / CLOCKS_PER_SEC << endl;
	return primes;
}

/**
Written into file all the primes between range. 
Input: range of numbers.
*/
void writePrimesToFile(int begin, int end, ofstream& file)
{
	bool isPrime = true;
	if (file.is_open())
	{
		for (int i = begin; i < end; i++)
		{
			for (int j = 2; j < sqrt(i); j++)
			{
				if (i % j == 0)
				{
					isPrime = false;
					break;
				}
			}
			if (isPrime)
				file << i << "\n";
			isPrime = true;
		}
	}
}


/**
Calculate the time of running threads.
*/
void callWritePrimesMultipleThreads(int begin, int end, string filePath, int N)
{
	ofstream file;
	file.open(filePath);

	int beg = begin, en;
	thread* arr = new thread[N];
	clock_t tStart = clock();

	thread* arr = new thread[N];

	for (int i = 0; i < N; i++)
	{
		en = (((end - begin) / N) * i) + begin;
		arr[i] = thread(writePrimesToFile, beg, en, ref(file));
		beg = en;
	}
	for (int i = 0; i < N; i++)
	{
		arr[i].join();
	}
	cout << "Time taken: " << (clock() - tStart) / CLOCKS_PER_SEC << endl;
}