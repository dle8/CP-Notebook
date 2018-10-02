/*
Author: Dung Tuan Le
University of Rochester
Created: 08/30/2018
*/

/*
Tested: https://www.spoj.com/problems/DICT/
*/

struct node {
	long count;
	node* c[255];
};

class Trie {
	public:
		node* root;
		
	Trie() { add(root); }		

	~Trie() { del(root); }
	
	void add(node* &p) {
		p = new node;
		p->count = 0;
		for (char ch='a'; ch<='z'; ch++) p->c[ch] = nullptr;
	}
	
	void del(node* &p) {
		for (char ch='a'; ch<='z'; ch++) {
			if (p->c[s[i]]!=nullptr) del(p->c[s[i]]);
		}
		delete p;
	}
	
	void insert(string s) {
		long lengths = s.length();
		node* p = root;
		FOR(i, 0, lengths-1) {
			if (p->c[s[i]]==nullptr) add(p->c[s[i]]);
			p = p->c[s[i]];
		}
		p->count++;
	}
	
	bool find(string s) {
		long lengths = s.length();
		node* p = root;
		FOR(i, 0, lengths-1) {
			if (p->c[s[i]]==nullptr) return false;
			p = p->c[s[i]];
		}
		return (p->count>0);
	}
	
};

