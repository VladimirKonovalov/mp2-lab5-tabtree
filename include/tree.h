#include "stdio.h"
#include "stdlib.h"
#include <iostream>
//#include <polinom.h>
#include <string>

using namespace std;
//---------
typedef struct tr {
	string val;
//	polinom pol;
	tr *l, *r, *par;
} tree, *ptree;

//---------
//ptree root; //root
//---------

class bintree {
public:
	ptree root;
	bintree();
	~bintree();
	ptree create(ptree root, ptree p, string value);
	void print(int deep, ptree p);
	void del(ptree p);
	ptree search(string x, ptree p);
	ptree findmin(ptree p);
	void removeroot(ptree p);
	void remove(string x, ptree p);
};
bintree::bintree() {
	root = NULL;
}
bintree::~bintree() {
	while (root) remove(root->val,root);
}
ptree bintree::create(ptree root, ptree p, string value) {
	if (!p) {
		p = new tree;
		p->l = NULL;
		p->r = NULL;
		p->par = NULL;
		p->val = value;
	//	p->pol = polinom();
		if (!root) return p;
		if (value < root->val) {
			root->l = p; p->par = root;
		}
		else {
			root->r = p; p->par = root;
		}

		return p;
	}
	if (value < p->val) create(p, p->l, value);
	else create(p, p->r, value);

	return root;
}
//----------
void bintree::print(int deep, ptree p) {
	if (p) {
		print(deep + 1, p->l);
		for (int i = 0; i < deep; i++) {
			printf("  ");
		}
		cout << ">" << p->val << endl;//printf(">%s", p->val);
									  //	printf("\n");
		print(deep + 1, p->r);
	}
}
void bintree::del(ptree p) {
	if ((p->l) && (p->r)) {
		del(p->l);
		del(p->r);
		delete p;
	}
	else if (p->l) {
		del(p->l);
		delete p;
	}
	else if (p->r) {
		del(p->r);
		delete p;
	}
	else if (!(p->l) && !(p->r)) delete p;
}
ptree bintree::search(string x, ptree p) {
	ptree temp = NULL;
	if (x == p->val) return p;
	else if (x < p->val) temp = search(x, p->l);
	else if (x > p->val) temp = search(x, p->r);
	return temp;
}
ptree bintree::findmin(ptree p) {
	if (p->l) findmin(p->l);
	else return p;
}
void bintree::remove(string x, ptree p) {
	if (p == NULL)
		return;/*-----------------------------*/
	if ((p->val == x) && (p->par == NULL)) {
		removeroot(p);
		/*-------------------------------------------------*/
	}
	else if (x < p->val)
		remove(x, p->l);
	else if (x > p->val)
		remove(x, p->r);
	else {                              // случай 1
		if ((p->l == NULL) && (p->r == NULL)) {
			if (p->par->r == p)	p->par->r = NULL;
			else p->par->l = NULL;
			delete p;
		}
		else if (p->l == NULL) {
			ptree old = p;
			if (p->par->r == p) { p->par->r = old->r; old->r->par = p->par; }
			else { p->par->l = old->r; old->r->par = p->par; }
			delete old;
		}
		else if (p->r == NULL) {     // случай 2
			ptree old = p;
			if (p->par->r == p) { p->par->r = old->l; old->l->par = p->par; }
			else { p->par->l = old->l; old->l->par = p->par; }
			delete old;
		}
		else {	                          // случай 3
			ptree m = findmin(p->r);
			p->val = m->val;
		//	p->pol = m->pol;
			remove(m->val, p->r);
		}
	}
}
void bintree::removeroot(ptree p) {
	if (p == NULL) return;
	if ((p->l == NULL) && (p->r == NULL)) {
		delete p; this->root = NULL;
	}
	else if (p->l == NULL) {
		p->val = p->r->val;
		remove(p->r->val, p->r);
	}
	else if (p->r == NULL) {
		p->val = p->l->val;
		remove(p->l->val, p->l);
	}
	else {
		ptree m = findmin(p->r);
		p->val = m->val;
	//	p->pol = m->pol;
		remove(m->val, m);
	}
}
//-----------