/*
Given a list of processes where each process have a unique id and a unique parent id . Parent id is the id of the process that initiated that process . You want to kill a particular process given by an integer kill . Print id of all the processes that will be killed to kill that process.You should print them in sorted order by id.
In order to kill a process , all its child processes should be killed as well . Also, only one process have parent id as 0 ie. that process started itself.

Input Format
The first line contains two integer - n (number of process ) and k (id of process to be killed).
Next line contains n integer equal to id of ith process.
Next line contains n integer equal to parent id of ith process.

Constraints
1<=n<=10^5

Output Format
Print id of all the process that will be killed in sorted order.

Sample Input
3 2
1 2 3
0 1 1
Sample Output
2
Explanation
Since , process with id 2 have no child , so it will only be killed.
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {

	unordered_map<int, list<int>> adjList;
public:
	void addNode(int b) {
		adjList[b] = list<int>();
	}
	void addEdge(int p, int c) {
		adjList[p].push_back(c);
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

	vector<int> bfs(int toKill) {
		vector<int> ans;
		unordered_map<int, bool> visited;
		queue<int> q;

		visited[toKill] = true;
		q.push(toKill);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			ans.push_back(cur);

			for (auto child : adjList[cur]) {
				if (visited[child])
					continue;

				visited[child] = true;
				q.push(child);
			}
		}

		return ans;
	}

};

int main() {
	int n;
	cin >> n;

	int toKill;
	cin >> toKill;

	Graph g;
	vector<int> process_id;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		process_id.push_back(input);
		g.addNode(input);
	}

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		if (input == 0)
			continue;

		g.addEdge(input, process_id[i]);
	}

	//g.print();
	vector<int> ans = g.bfs(toKill);

	sort(ans.begin(), ans.end());
	for (int i : ans) {
		cout << i << " ";
	}

	return 0;
}

/*
Editorial
X
Explanation: Run a bfs. Initially queue will have only one element which is the given process. While queue is not empty, pop the element at front and push all its child in the queue.Repeat the process for the child and child's child and so on.All the nodes that comes in the bfs are process that will be killed.


#include <bits/stdc++.h>
using namespace std;
vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    map<int,vector<int> >m;
    map<int, bool>killed;
    vector<int>v;
    for(int i=0;i<pid.size();i++)
    {
        m[ppid[i]].push_back(pid[i]);
        killed[pid[i]]=false;
    }
    queue<int>q;
    q.push(kill);
    v.push_back(kill);
    killed[kill]=true;
    while(!q.empty())
    {
            int temp=q.front();
            q.pop();
            vector<int>::iterator i;
            for(i = m[temp].begin();i!=m[temp].end();i++)
            {
                killed[*i]=true;
                v.push_back(*i);
                q.push(*i);
            }
    }

    return v;
}
int main() {
    int n,k;
    cin>>n>>k;

    vector<int>nodes;
    vector<int>parents;
    int a;

    for(int i=0;i<n;i++)
    {
        cin>>a;
        nodes.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        cin>>a;
        parents.push_back(a);
    }
    vector<int>ans;
    ans=killProcess(nodes,parents,k);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
*/