#include "threads.h"

int main()
{
	call_I_Love_Threads();

	vector<int> primes1;
	getPrimes(58, 100, primes1);

	vector<int> primes3 = callGetPrimes(0, 100);

	callWritePrimesMultipleThreads(0, 100000000, "primes2.txt", 2);

	system("pause");
	return 0;
}