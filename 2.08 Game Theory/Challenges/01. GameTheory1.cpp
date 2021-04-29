/*
You are given N piles of stones.
Each pile has same number of stones M.
Two players 1 and 2 play a game in which player 1 always moves first.
The rules are :-
1.Player will randomly choose 1 pile whose height is A and reduce the number of stones in that pile to B such that B is a divisor of A and B != A ( 1<= B < A).
2.Player who cannot make a move looses that is if all the piles are of size 1 the player will loose.
You have to find the winner.

Input Format
First line consists of number of test cases T. Each test case consists of two integers N and M.

Constraints
1 <= T <= 100 1 <= N,M <= 1000000

Output Format
Print 1 if player 1 wins else print 2.

Sample Input
2
2 2
1 4
Sample Output
2
1
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> grundy;

int findMEX(const unordered_set<int> &s) {
	int mex = 0;
	while (s.find(mex) != s.end())
		mex++;
	return mex;
}

int findGrundy(int n) {
	int g = 0;

	if (n) {
		if (grundy[n] == -1) {
			unordered_set<int> s;
			for (int i = 1; i < n; i++) {
				if (n % i == 0)
					s.insert(findGrundy(i));
			}

			grundy[n]  = findMEX(s);
		}

		g = grundy[n];

	}

	return g;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		grundy = vector<int> (m + 5, -1);
		int conclusion = 0;
		int grundyM = findGrundy(m);
		for (int i = 0; i < n; i++)
			conclusion ^= grundyM;

		if (conclusion)
			cout << "1" << endl;
		else
			cout << "2" << endl;
	}
	return 0;
}

/*
Editorial
X
C++ Code

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> primes;

vector<bool> primeSieve(ll n){

    vector<bool> p(n+1,false);

    p[0] = p[1] = 0;
    p[2] = 1;

    //Let us Mark all Odd Numbers as Prime(Initialisations)
    for(ll i=3;i<=n;i+=2){
        p[i] = 1;
    }

    //Sieve Login to mark non prime numbers as 0
    //1. Optimsation : Iterate only over odd Numbers
    for(ll i=3;i<=sqrt(n);i+=2){

        if(p[i]){
            //Mark all the multiples of that number as not prime.
            //2. Optimisation Take a jump of 2i starting from i*i
            for(ll j=i*i;j<=n;j+=2*i){
                p[j] = 0;
            }
        }

    }
    return p;
}

// 1E6 - 1000000
vector<ll> prime_numbers(){
    vector<bool> p = primeSieve(1E6);
    vector<ll> primes;
    primes.push_back(2);

   for(ll i=3; i<1E6; i++){
       if(p[i]){
            primes.push_back(i);
       }
   }
   return primes;
}

unordered_set<ll> divisors(ll n){
    unordered_set<ll> div;
    div.insert(1);
    for (ll i = 0; primes[i]  <= sqrt(n) ; ++i)
    {
        if(n%primes[i]==0){
            ll num = n;
            div.insert(primes[i]);

            while(num){
                num/=primes[i];
                div.insert(num);
            }
        }
    }
    return div;
}

ll calculateMex(unordered_set<ll> &Set)
{
    ll Mex = 0;
    while (Set.find(Mex) != Set.end())
        Mex++;
    return (Mex);
}

ll calculateGrundy(ll n){
    // if there are 0 or 1 stones, first player will lose as
    //it can't be reduced A.T.Q

    if (n==0)
        return 0;

    if(n==1)
        return 0;

    unordered_set<ll> set;

    // these are the substates
    unordered_set<ll> divisor = divisors(n);
    ll ans = 0;

    for (auto it = divisor.begin(); it!=divisor.end(); it++)
    {
        // calculating grundy numbers of all states and putting them in a set
         set.insert(calculateGrundy(*it));
    }
    return calculateMex(set);
}

ll winner(ll n,ll m){
    if (n%2==0)
        return 0;
    else
        return calculateGrundy(m);
}

int main(){
    primes = prime_numbers();
    ll t;
    cin>>t;
    while(t--) {
        ll n,m;
        cin>>n>>m;
        ll ans = winner(n,m);
        if(ans!=0)
            cout<<1<<endl;
        else
            cout<<2<<endl;
    }
    return 0;
}
*/