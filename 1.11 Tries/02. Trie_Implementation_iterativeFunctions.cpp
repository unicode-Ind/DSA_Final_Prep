#include <iostream>
#include <cstring>
#include <vector>

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

	TrieNode(char data) {
		this->data = data;
		this->isTerminating = false;
		this->noOfChildren = 0;
		children = vector<TrieNode*> (26, NULL);
	}
};

class Trie
{
	TrieNode* root;
	void remove(TrieNode* root, string &s, int &curIndex, int &len) {
		if (curIndex == len) {
			root->isTerminating = false;
			return;
		}

		int childIndex = s[curIndex] - 'a';
		// if(root->children[childindex]==NULL)
		// 	return;
		//coomented bcz we have checked via search

		remove(root->children[childIndex], s, ++curIndex, len);

		if (!root->children[childIndex]->isTerminating and root->children[childIndex]->noOfChildren == 0) {
			TrieNode* temp = root->children[childIndex];
			root->children[childIndex] = NULL;
			delete(temp);

			root->noOfChildren--;
		}

	}
public:
	Trie() {
		root = new TrieNode('\0');
	}

	void add(string s) {
		TrieNode* current = root;

		for (char c : s) {
			int childIndex = c - 'a';
			if (current->children[childIndex] == NULL) {
				current->children[childIndex] = new TrieNode(c);
				current->noOfChildren ++;
			}

			current = current->children[childIndex];
		}
		current->isTerminating = true;
	}

	bool search(string s) {
		TrieNode * current = root;

		for (char c : s) {
			int childIndex = c - 'a';
			if (current->children[childIndex] == NULL) {
				return false;
			}

			current = current->children[childIndex];
		}
		return current->isTerminating;
	}

	void remove(string s) {
		if (!search(s))
			return;

		//remove is recursive, Why ??? => remove unnecessary nodes after return from recursive call
		//or maintain stack of pointers for removal, afterwards
		int curIndex = 0, len = s.size();
		remove(root, s, curIndex, len);

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

	//trie.remove("news");
	trie.remove("new");
	cout << trie.search("new") << endl;
	cout << trie.search("news") << endl;

	// cout << trie.search("news") << endl;
	// cout << trie.search("baloon") << endl;


	return 0;
}