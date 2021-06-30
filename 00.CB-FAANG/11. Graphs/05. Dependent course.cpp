/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Input Format
First Line contains single integer n (total courses) Second Line contains single integer m (total pairs) Next m lines contain m pairs

Constraints
1<=n<=10000

Output Format
print "Yes" or "No" (without quotes)

Sample Input
2
2
1 0
0 1
Sample Output
No
Explanation
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/


#include <bits/stdc++.h>
using namespace std;

class Graph {

	unordered_map<int, list<int>> adjList;
	unordered_map<int, int> indegree;
public:
	void addNode(int b) {
		adjList[b] = list<int>();
	}
	void addEdge(int p, int c) {
		adjList[p].push_back(c);
		indegree[c]++;
	}

	void print() {
		for (auto i : adjList) {
			cout << i.first << " ->";
			for (auto j : i.second) {
				cout << j << " ";
			}
			cout << endl;
		}
	}

	bool bfs(int n) {
		queue<int> q;
		int total_courses = n;
		int done_courses = 0;
		for (auto cur : indegree) {
			if (cur.second == 0)
				q.push(cur.first);
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			done_courses++;

			for (auto child : adjList[cur]) {
				indegree[child]--;
				if (indegree[child] == 0)
					q.push(child);
			}
		}

		return total_courses == done_courses;
	}

};

int main() {
	int courses, edges;
	cin >> courses >> edges;

	Graph g;

	int u, v;
	for (int i = 0; i < edges; i++) {
		cin >> u >> v;
		g.addEdge(v, u);
	}

	bool ans = g.bfs(courses);
	if (ans)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}

/*
Editorial
X
Algorithm
Solution Steps:

Create the adjacency list graph from the given prerequisites pair / edges
Fill the indegree array of each courses based on their prerequisites.
Add all the course which are not depends on any other in Queue.
Run BFS and updated the indegree of all course which has current course has prerequisite.
Check if indegree of course 0 add in queue.
Subtract numCourses which attended.
Repeat step 4 to 6 until no course left or can't attend anymore course (cyclic dependency).
CODE:

//Input Format
//1. n (No. of courses)
//2. m (no. of pairs)
//3. m lines where each line contains a pair

#include <bits/stdc++.h>
using namespace std;

 bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> graph;
        int indegree[numCourses] = {0};
        int n = prerequisites.size();
        for(int i=0;i<n;i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        int edges_removed = 0;
        queue<int> zero_indegree;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                zero_indegree.push(i);
            }
        }
        while(!zero_indegree.empty()){
            int course = zero_indegree.front();
            zero_indegree.pop();
            for(auto child:graph[course]){
                edges_removed++;
                indegree[child]--;
                if(indegree[child] == 0){
                    zero_indegree.push(child);
                }
            }
        }
        if(edges_removed == n){
            return true;
        }
        else return false;
    }

int main() {
    int n,m;
    cin>>n;
    vector< vector<int> > prerequisites;
    cin>>m;
    for(int i=0;i<m;i++){
        vector<int> temp;
        int a,b;
        cin>>a>>b;
        temp.push_back(a);
        temp.push_back(b);
        prerequisites.push_back(temp);
    }
    if(canFinish(n,prerequisites)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}
*/