/*
Author: Dung Tuan Le
University of Rochester
Created: 06/08/2018
*/

/*
Def: Euler's totient function is the number of positive integers up to n that are relatively prime to n.
This method returns an Euler's totient function of a given long n.
*/

long eulerPhi(long n) {
	if (n==0) return 0;
	long euler = n;
	FOR(i, 2, sqrt(n)) {
		if (n%i==0) {
			euler-=euler/i;
			while (n%i==0) n/=i;
		}
	}
	if (n>1) euler-=euler/n;//in case n is a prime -> there is no i from 2 to sqrt(n) that is divisible by n
	return euler;
}

// a ^ φ(n) ≡ 1 (mod n) whenever (a,n) = 1

/*
Tested: https://www.spoj.com/problems/ETF/
*/
