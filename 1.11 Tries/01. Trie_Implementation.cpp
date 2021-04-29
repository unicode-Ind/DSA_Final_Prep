#include <iostream>
#include<vector>
#include<map>
using namespace std;

void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}

class TrieNode
{
public:
	char data;
	bool isTerminating;
	int noOfChildren;
	vector<TrieNode*> children;

	TrieNode() {
		this->data = '\0';
		this->isTerminating = false;
		this->noOfChildren = 0;
		children = vector<TrieNode*> (26, NULL);
	}

	TrieNode(char data) {
		this->data = data;
		this->isTerminating = false;
		this->noOfChildren = 0;
		children = vector<TrieNode*> (26, NULL);
	}

};

class Trie
{
	TrieNode * root;
	void add(TrieNode* root, string &s, int &curIndex, int &length) {
		if (curIndex == length) {
			root->isTerminating = true;
			return;
		}

		int child_index = s[curIndex] - 'a';
		if (root->children[child_index] == NULL) {
			root->children[child_index] = new TrieNode(child_index + 'a');
			root->noOfChildren++;
		}
		add(root->children[child_index], s, ++curIndex, length);
	}

	bool search(TrieNode* root, string &s, int &curIndex, int &length) {
		if (curIndex == length)
			return root->isTerminating;

		int child_index = s[curIndex] - 'a';
		if (root->children[child_index] == NULL)
			return false;

		return search(root->children[child_index], s, ++curIndex, length);
	}

	void remove(TrieNode *root, string &s, int &curIndex, int &length) {
		if (curIndex == length) {
			root->isTerminating = false;
			return;
		}

		int child_index = s[curIndex] - 'a';
		// if(root->children[child_index]==NULL)
		// 	return;
		//coomented bcz we have checked via search

		remove(root->children[child_index], s, ++curIndex, length);

		//important -> istreminating
		if (!root->children[child_index]->isTerminating and  root->children[child_index]->noOfChildren == 0) {
			TrieNode * temp = root->children[child_index];
			delete(temp);
			root->children[child_index] = NULL;
			root->noOfChildren--;
		}
	}

public:
	Trie() {
		root = new TrieNode('\0');
	}

	void add(string s) {
		int curIndex = 0;
		int length = (int)s.size();
		add(root, s, curIndex, length);
	}

	bool search(string s) {
		int curIndex = 0;
		int length = s.size();
		return search(root, s, curIndex, length);
	}

	void remove(string s) {
		if (search(s)) {
			int curIndex = 0;
			int length = (int)s.size();
			remove(root, s, curIndex, length);
		}
	}
};



int main(int argc, char const *argv[])
{
	INPUT();

	Trie trie;

	trie.add("a");
	trie.add("and");
	trie.add("new");
	trie.add("news");
	trie.add("top");
	trie.add("ball");
	trie.add("balloon");

	cout << trie.search("new") << endl;
	cout << trie.search("news") << endl;

	trie.remove("news");
	cout << trie.search("new") << endl;
	cout << trie.search("news") << endl;

	// cout << trie.search("news") << endl;
	// cout << trie.search("baloon") << endl;



	return 0;
}