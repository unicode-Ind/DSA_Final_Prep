#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();


int main()
{
	INPUT();

	char notWanted = '9' + 1;

	string input;
	cin >> input;

	int m;
	cin >> m;

	while (m--) {
		string ans = "";
		for (auto cur : input) {
			char teemp = cur + 1;

			if (teemp == notWanted) {
				ans.push_back('1');
				ans.push_back('0');
			} else {
				ans.push_back(teemp);
			}
		}

		input = ans;
	}



	cout << input;


	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}







function getTable(head_arr, tbody) {
	var res = new Array();

	//add table heads
	var HeadRow = new Array();
	for (let i = 0; i < head_arr.length; i++) {
		var element = {text: head_arr[i], style: 'tableHeader'};
		HeadRow.push(element);

	}









	res.push(HeadRow);
	//head row added

	//adding rows (data)
	for (let index = 0; index < tbody.length; index++) {
		var row = new Array();
		for (let i = 0; i < tbody[0].length; i++) {
			row.push({
				//colspan: 1,
text: tbody[index][i], style: 'defaultStyle'
			});
		}

		//add ith row
		res.push(row);
	}


	//return table with heads
	return res;

}