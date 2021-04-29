#include <iostream>
using namespace std;

bool isPrime(int number) {
	if (number < 2)
		return false;
	if (number == 2)
		return 2;

	for (int i = 2; i * i <= number; ++i)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		int number;
		cin >> number;

		cout << isPrime(number) << endl;
	}
	return 0;
}