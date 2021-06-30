/*
Given an array of String, return the k most frequent elements.

Note:
Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
Input words contain only lowercase letters.

Input Format
Take input N and K.Next line contains N String, denoting the word of array.

Constraints
None

Output Format
print k most frequent word.

Sample Input
15 4
i did did i did it for the rock i did it for the people
Sample Output
did i for it
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

#define pq_str priority_queue<string, vector<string>, greater<string>> //min PQ



int main()
{
	INPUT();

	int n, k;
	cin >> n >> k;

	string inp;
	unordered_map<string, int> hm;
	for (int i = 0; i < n; ++i)
	{
		cin >> inp;
		hm[inp]++;
	}

	vector<pq_str> v(n + 1, pq_str ());

	for (auto cur : hm) {
		string word = cur.first;
		int freq = cur.second;

		v[freq].push(word);
	}

	vector<string> ans;
	for (int i = n; ~i and k ; --i)
	{
		while (!v[i].empty() and k) {
			ans.push_back(v[i].top());
			v[i].pop();

			k--;
		}
	}

	for (string cur : ans)
		cout << cur << " ";

	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}

/*
Editorial
X
K Most Frequent Words
Time Complexity O(n log n), where n is the array’s size.
Given a non-empty list of words, return the k most frequent elements.
Note: Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency,
then the word with the lower alphabetical order comes first. Input words contain only lowercase letters.
Algorithm: Steps:

Make a function kMostFrequent and pass array a[ ] and K as parameter
kMostFrequent(String a[ ],int k)
Create ArrayList ans of Size N, inside the Function
ans will be store K Most Frequent Elements
3.Create HashMString,Integer> m,inside the Function
Use a map and store the frequency of the word
for ( String i : a) m.put(i, m.containsKey(i) ? m.get(i) + 1 : 1);
4.Create an array freq of priority queue(min heap) with (a.length) as its size.
// every indices are contains a priorityqueue
Same frequency elements are stored together
for(String w : m.keySet())
freq[m.get(w)-1].add(w);//m.get (w)will provide the frequency of the corresponding w
5. Now, iterate over the freq keep a counter to match with the input value k.
for (int i = freq.length - 1; i >= 0 && k > 0; i--) {
while (freq[i].size() != 0 && k > 0) {
k--;
ans.add(freq[i].remove(0));
}
}
6.return ans
Solution Link :https://ide.codingblocks.com/s/196658


import java.util.*;
public class Main {

    public static List<String> kMostFrequentWords(String[] words, int k) {

        List<String> ans = new ArrayList<>();
        HashMap<String,Integer> m = new HashMap<>();

        for(String w : words)
            m.put(w, m.containsKey(w) ? m.get(w) + 1 : 1);

        PriorityQueue<String> freq[] = new PriorityQueue[words.length];
        for(int i=0;i<freq.length;i++)
            freq[i] = new PriorityQueue<>();

        for(String w : m.keySet())
            freq[m.get(w)-1].add(w);

        for(int i=freq.length-1;i>=0 && k>0;i--)
            while(k > 0 && !freq[i].isEmpty())
            {
                ans.add(freq[i].remove());
                k--;
            }
        return ans;

    }
    public static void main(String args[]) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt(), k = scn.nextInt();
        String a[] = new String[n];
        for(int i=0;i<n;i++) a[i] = scn.next();
        List<String> ans = kMostFrequentWords(a,k);
        for(String w : ans)
            System.out.print(w + " ");
        System.out.println();
    }
}

*/