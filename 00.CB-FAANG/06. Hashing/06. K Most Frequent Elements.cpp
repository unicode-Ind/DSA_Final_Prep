/*
Given a non-empty array of integers, return the k most frequent elements.
Note:
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.

Input Format
Take input N and K.Next line contains N integers, denoting the elements of array.

Constraints
None

Output Format
print k most frequent elements.

Sample Input
6 2
1 4 4 3 3 3
Sample Output
3 4
*/


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> solve(vector<int> &nums, int k) {
	unordered_map<int, int> hm;
	for (int cur : nums)
		hm[cur] = 0;

	int max_freq = 0;
	for (int cur : nums) {
		hm[cur]++;

		max_freq = max(max_freq, hm[cur]);
	}

	unordered_map<int, vector<int>> freq_vector;
	for (auto i : hm) {
		freq_vector[i.second].push_back(i.first);
	}

	vector<int> ans;

	while (max_freq and k) {
		if (freq_vector.find(max_freq) != freq_vector.end()) {
			for (int cur : freq_vector[max_freq]) {
				ans.push_back(cur);
				k--;
			}
		}
		max_freq--;
	}

	return ans;


}

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];

	vector<int> ans = solve(nums, k);

	for (int i : ans)
		cout << i << " ";

	return 0;
}

/*
K Most Frequent Elements
Time Complexity O(n log n), where n is the array’s size.
Given a non-empty array of integers, return the k most frequent elements.

Algorithm:
Steps:
1. Make a function kMostFrequent and pass array a[ ] and K as parameter
kMostFrequent(int a[ ],int k)

Create ArrayList ans of Size N, inside the Function
ans will be store K Most Frequent Elements
3.Create HashMap m,inside the Function
Use a map and store the frequency of the number
for (int i : a) m.put(i, m.containsKey(i) ? m.get(i) + 1 : 1);

Create an array freq of ArrayList with (a.length) as its size.
// every indices are contains a ArrayList
Same frequency elements are stored together
for (int key : m.keySet())
freq[m.get(key) - 1].add(key); // m.get (key) will provide the frequency of the corresponding key
Now, iterate over the freq keep a counter to match with the input value k.
for (int i = freq.length - 1; i >= 0 && k > 0; i--) {
while (freq[i].size() != 0 && k > 0) {

    k--;
    ans.add(freq[i].remove(0));
    }
}
6.return ans

Solution Link :https://ide.codingblocks.com/s/196747
(different than below)



import java.util.*;
public class Main {
        public static int  [] topKFrequent(int[] nums, int k) {
    //count the frequency for each element
    HashMap<Integer, Integer> map = new HashMap<>();
    for (int num : nums) {
        map.put(num, map.getOrDefault(num, 0) + 1);
    }

    // create a min heap
    PriorityQueue<Map.Entry<Integer, Integer>> queue
                  = new PriorityQueue<>(Comparator.comparing(e -> e.getValue()));

    //maintain a heap of size k.
    for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
        queue.offer(entry);
        if (queue.size() > k) {
            queue.poll();
        }
    }

    //get all elements from the heap

     int result [] = new int [k];
     int i=0;
     while (queue.size() > 0) {
        result[i]=queue.poll().getKey();
         i++;
    }


      i=0; int j=k-1;
     while(i<j){
        int t = result[i];
         result[i] =result[j];
         result[j]=t;
         i++;
         j--;
     }

    return result;
}

    public static void main(String args[]) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt(), k = scn.nextInt();
        int a[] = new int[n];
        for(int i=0;i<n;i++) a[i] = scn.nextInt();
        int []  ans = topKFrequent(a,k);
        for(int w : ans)
            System.out.print(w + " ");
        System.out.println();
    }
}
*/