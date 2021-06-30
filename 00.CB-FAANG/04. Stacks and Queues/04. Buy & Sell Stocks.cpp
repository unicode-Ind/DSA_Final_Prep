/*
Consider an array for which on day i, ith element is the price of a given stock.
we are permitted at most only one transaction(i.e buy one and sell one share of stock).Find the maximum profit.

Note:Buying a stock is mandatory before selling.

Input Format
First line contains integer n as size of array. Next n lines contains n integer as element of array.

Constraints
None

Output Format
Print the maximum profit.

Sample Input
6
7
1
5
3
6
4
Sample Output
5
Explanation
None
*/

#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;

	vector<int> input(n);
	for (int i = 0; i < n; i++)
		cin >> input[i];

	int ans = 0;
	int shdBeBoughtAt = input[0];
	//minimum [0,i-1] price to buy , so as to sell at i
	for (int i = 1; i < n; i++) {
		int profit = input[i] - shdBeBoughtAt;
		if (profit > 0)
			ans = max(ans, profit);
		else
			// -ve profit, means minimun till now => update minimum
			shdBeBoughtAt = input[i];
	}
	cout << ans;
	return 0;
}

/*
Question : Buy & Sell Stock

Time Complexity:The loop runs from i=3 till i<=n.So overall time complexity is O(n).

Algorithm: A simple approach to solve the problem when we are only permitted to complete at most one transaction(ie, buy one and sell one share of the stock.)and to find the maximum profit is as under :

Step 1: Initialize one variable n (int n)and vector ‘v’ of integer type(vector v).(n is the number of elements to be pushed in the vector ‘v’).

Step 2: Make a function maxProfit and pass ‘v’ as parameter(call by refrence). Ie,
maxProfit(v)
Int maxProfit(vector& prices)

Step 3: Make three global variables inside the function, n which keeps value equal to size of vector ‘prices’ , maxprofit with initial value =0 and variable item with initial value equal to the last element of the vector ‘prices’ .
Int n=prices.size()
Int maxprofit=0
Int item=prices[n-1]

Step 4: loop from value i=n-1 till i>=0.

Step 5: Inside the loop make a variable p which keeps value equal to prices[i] subtracted from variable item and then update the maxprofit equal to maximum of p and maxprofit.
Int p=item -prices[i]
maxprofit=max(p,maxprofit)

Step 6: If current value of prices[i] is greater than value of item update the value of item equal to prices[i] and now decrement the value of i and continue the process.
if(prices[i]>item){
item=prices[i].
}

Step 7: Return the value of maxprofit when value of i becomes less then 0 and then print its value.
Return maxprofit .

Solution link: https://ide.codingblocks.com/s/182146

#include<iostream>
#include<vector>
using namespace std;

//  LEETCODE FUNCTION
//  COPY AND PASTE THIS THERE
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxprofit = 0;
        if(n==0)  return 0;
        int item = prices[n-1];
        for(int i=n-1;i>=0;i--){
            int p = item - prices[i];
            maxprofit = max(p,maxprofit);
            if(prices[i]>item)
                item=prices[i];
        }
        return maxprofit;
    }


int main(){
    int n,d;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        cin>>d;
        v.push_back(d);
    }
    cout<<maxProfit(v);
}
*/