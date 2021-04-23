#include <iostream>
#include <fstream>
#include <map>

#include <queue>

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


int main()
{
	fstream fs;

	char c;
	map<char, int> inv;
	map<char, int>::iterator it;

	priority_queue<char> test;
	priority_queue<int> test2;
	priority_queue<Node*> test3;

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

		Node *n = new Node(i.first, i.second);
		test3.push(&*n);

		cout << i.first << " : " << i.second << endl << endl;
	}

	//lettres

	cout << "La priority queue test contient : ";
	showpqChar(test);

	cout << "\n test.size() : " << test.size();
	cout << "\n test.top() : " << test.top();

	cout << "\n test.pop() : "<<endl;
	test.pop();
	showpqChar(test);

	cout << endl;

	//chiffres

	cout << "La priority queue test2 contient : ";
	showpq(test2);

	cout << "\n test2.size() : " << test2.size();
	cout << "\n test2.top() : " << test2.top();

	cout << "\n test2.pop() : "<<endl;
	test2.pop();
	showpq(test2);

	cout << endl;

	//Node

	cout << "La priority queue test3 contient : ";
	showpqNode(test3);

	cout << "\n test3.size() : " << test3.size();
	cout << "\n test3.top() : " << test3.top()->getVal() << ":" << test3.top()->getFreq();

	cout << "\n test3.pop() : " << endl;
	test3.pop();
	showpqNode(test3);

	return 0;
}