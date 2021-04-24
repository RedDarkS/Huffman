#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <queue>
#include <vector>

#include "Node.h"

/*Questions

1/la table ascii code les caractères sur 7 bits.

2/en ascii "Coucou" serait codé sur 6*7 = 42 bits.

3/un arbre est une variante des tableaux de données, à chaque case du tableau ou "noeud", on y stocke 2 données, des références à une donnée brut si la branche se termine, 
on nomme ce la une "feuille", et sinon une référence au noeud suivant.
Et donc on enchaine les noueuds jusqu'à former toutes les branches et les feuilles.

5/Avec cet encodage on code Coucou sur 12 bits au lieu de 42. On gagne donc 30 bits.

6/Il est difficile de connaitre ou de deviner l'encodage de chaques caractères, car certains sont codés sur 1 bit, et d'autres sur plusieurs.

*/

using namespace std;

void showVec(vector<Node*> v)
{
	for(int i = 0; i<v.size(); i++)
	{
		cout << '\t' << v[i]->getVal() << ":" << v[i]->getFreq();
	}
	cout << endl;
}

//affichage priority queue type int

void showpq(priority_queue<int> gq)
{
	priority_queue<int> g = gq;

	while (!g.empty()) 
	{
		cout << '\t' << g.top();
		g.pop();
	}
	cout << endl;
}

//affichage priority queue type char

void showpqChar(priority_queue<char> t)
{
	priority_queue<char> g = t;

	while (!g.empty()) 
	{
		cout << '\t' << g.top();
		g.pop();
	}
	cout << endl;
}

//affichage priority queue type Node

void showpqNode(priority_queue<Node*> t)
{
	priority_queue<Node*> g = t;

	while (!g.empty()) 
	{
		cout << '\t' << g.top()->getVal() << ":" << g.top()->getFreq();
		g.pop();
	}
	cout << endl;
}

//affichage priority queue type int croissant

void showQ(priority_queue<int, vector<int>, greater<int> > q)
{
	priority_queue<int, vector<int>, greater<int> > g = q;

	while (!g.empty()) 
	{
		cout << '\t' << g.top();
		g.pop();
	}
	cout << '\n';
}

//affichage priority queue type Node croissant

void showQNode(priority_queue<Node*, vector<Node*>, greater<Node*> > q)
{
	priority_queue<Node*, vector<Node*>, greater<Node*> > g = q;

	while (!g.empty())
	{
		cout << '\t' << g.top()->getVal() << ":" << g.top()->getFreq();
		g.pop();
	}
	cout << '\n';
}

//creation de l'arbre

void createTree(vector<Node*> q)
{
	vector<Node*> g = q;

	priority_queue<Node*, vector<Node*>, greater<Node*> > tree;

	Node* n1 = g[0];
	Node* n2 = g[0];

	Node* sec = g[0];

	while (g.size() > 2)
	{
		for (int i = 0; i < g.size(); i++) 
		{
			if (g[i]->getFreq() <= n1->getFreq())
			{
				g.push_back(n1);

				n1 = g[i];

				g.pop_back();
			}
			else 
			{
				g.pop_back();
			}
		}
		for (int i = 0; i < g.size(); i++)
		{
			if (g[i]->getFreq() <= n2->getFreq())
			{

				g.push_back(n2);

				n2 = g[i];

				g.pop_back();
			}
			else
			{
				g.pop_back();
			}
		}

		int temp = n1->getFreq() + n2->getFreq();
		cout << "temp = " << temp << endl;

		Node* n3 = new Node(' ', temp, n1, n2);

		g.push_back(&*n3);
		tree.push(&*n3);
	}

	cout << "g: ";
	showVec(g);
	cout << "g.size() = " << g.size() << endl;

	cout << "tree: ";
	showQNode(tree);
	cout << "tree.size() = " << tree.size() << endl;

	cout << "min1 =" << min1 << endl;
	cout << n1->getVal() << ":" << n1->getFreq() << endl;

	cout << "min2 =" << min2 << endl;
	cout << n2->getVal() << ":" << n2->getFreq() << endl;
}


int main()
{
	fstream fs;

	char c;
	map<char, int> inv;
	map<char, int>::iterator it;

	//décroissant
	priority_queue<char> test;
	priority_queue<int> test2;
	priority_queue<Node*> test3;

	//croissant
	priority_queue<int, vector<int>, greater<int> > test4;
	priority_queue<Node*, vector<Node*>, greater<Node*> > test5;

	vector<Node*> tab;

	fs.open("Lyrics.txt");
	
	//parcourt du texte et comptage des occurences pour chaque caractère

	while (fs.get(c))
	{
		cout << c;
		if (inv.find(c) != inv.end())
		{
			inv.find(c)->second += 1;
		}
		else
		{
			inv.emplace(c, 1);
		}
	}

	//parcourt et affichage de chaque lettre et son occurence. Et mise en place des priority queue

	for (auto i : inv) //auto au lieu de pair<string, string> - ça détecte le type tout seul
	{
		//cout << "i.first : " << i.first << " : i.second : " << i.second << endl;

		test.push(i.first);

		test2.push(i.second);

		test4.push(i.second);

		Node *n = new Node(i.first, i.second);

		test3.push(&*n);
		test5.push(&*n);
		tab.push_back(&*n);

		cout << i.first << " : " << i.second << endl << endl;
	}

	cout << endl;
	cout << "------------------------------" << endl << endl;

	//lettres

	cout << "La priority queue test contient : ";
	showpqChar(test);

	cout << "\n test.size() : " << test.size();
	cout << "\n test.top() : " << test.top();

	cout << "\n test.pop() : "<<endl;
	test.pop();
	showpqChar(test);

	cout << endl;
	cout << "------------------------------" << endl << endl;

	//chiffres

	cout << "La priority queue test2 contient : ";
	showpq(test2);

	cout << "\n test2.size() : " << test2.size();
	cout << "\n test2.top() : " << test2.top();

	cout << "\n test2.pop() : "<<endl;
	test2.pop();
	showpq(test2);

	cout << endl;
	cout << "------------------------------" << endl << endl;

	//Node

	cout << "La priority queue test3 contient : ";
	showpqNode(test3);

	cout << "\n test3.size() : " << test3.size();
	cout << "\n test3.top() : " << test3.top()->getVal() << ":" << test3.top()->getFreq();

	cout << "\n test3.pop() : " << endl;
	test3.pop();
	showpqNode(test3);

	cout << endl;
	cout << "------------------------------" << endl << endl;

	//l'autre priority queue

	cout << "La priority queue test4 contient : ";
	showQ(test4);

	cout << "\n test4.size() : " << test4.size();
	cout << "\n test4.top() : " << test4.top();

	cout << "\n test4.pop() : " << endl;
	test4.pop();
	showQ(test4);

	cout << endl;
	cout << "------------------------------" << endl << endl;

	//l'autre priority queue version node

	cout << "La priority queue test5 contient : ";
	showQNode(test5);

	cout << "\n test5.size() : " << test5.size();
	cout << "\n test5.top() : " << test5.top()->getVal() << ":" << test5.top()->getFreq();

	cout << "\n test5.pop() : " << endl;
	test5.pop();
	showQNode(test5);

	cout << endl;
	cout << "------------------------------" << endl << endl;

	createTree(tab);

	return 0;
}