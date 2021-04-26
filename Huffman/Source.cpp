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

//comparaison pour les priority queue
struct comp 
{
	bool operator()(Node* g, Node* d) 
	{
		return g->getFreq() > d->getFreq();
	}
};

//affichage priority queue type Node croissant

void showQNode(priority_queue<Node*, vector<Node*>, comp> q)
{
	while (!q.empty())
	{
		cout << '\t' << q.top()->getVal() << ":" << q.top()->getFreq();
		q.pop();
	}
	cout << '\n';
}

//creation de l'arbre

Node* createTree(priority_queue<Node*, vector<Node*>, comp> tree)
{
	while (tree.size() > 1)
	{
		Node* gauche = tree.top(); 
		tree.pop();

		Node* droite = tree.top(); 
		tree.pop();

		int somme = gauche->getFreq() + droite->getFreq();
		tree.push(new Node('$', somme, gauche, droite));
	}

	return tree.top();
}

void encodage(Node* r, string s, map<char, string>& e) 
{
	if ( r == nullptr)
	{
		return;
	}
	else 
	{
		e[r->getVal()] = s;
		
		encodage(r->getGauche(), s + "0", e);
		encodage(r->getDroite(), s + "1", e);
	}
}

string textToCode(string t, map<char, string> e) 
{
	string result;
	for (char c : t)
	{ 
		result += e[c];
	}
	return result;
}

void decodage() 
{

}

string translate() 
{
	return "";
}

int main()
{
	fstream fs;

	char c;

	string texte = "";
	map<char, int> inv;
	map<char, int>::iterator it;

	map<char, string> encoding;

	//croissant
	priority_queue<Node*, vector<Node*>, comp> tree;

	fs.open("Lyrics.txt");
	
	//parcourt du texte et comptage des occurences pour chaque caractère

	while (fs.get(c))
	{
		cout << c;
		texte += c;
		if (inv.find(c) != inv.end())
		{
			inv.find(c)->second += 1;
		}
		else
		{
			inv.emplace(c, 1);
		}
	}

	for (auto i : inv) //auto au lieu de pair<string, string> - ça détecte le type tout seul
	{
		//mise en place des priority queue
		tree.push(new Node(i.first, i.second));
	}

	cout << endl;
	cout << "------------------------------" << endl << endl;

	//priority queue version node

	cout << "La priority queue tree contient : ";
	showQNode(tree);

	cout << "\n tree.size() : " << tree.size();
	cout << "\n tree.top() : " << tree.top()->getVal() << ":" << tree.top()->getFreq();

	Node* racine = createTree(tree);

	cout << endl;
	cout << "------------------------------" << endl << endl;

	cout << "racine : " << racine->getVal() << " : " << racine->getFreq() << endl;

	cout << endl;
	cout << "------------------------------" << endl << endl;

	encodage(racine, "", encoding);
	cout << "Encodage :" << endl;

	for (auto i : encoding) 
	{
		cout << i.first << " : " << i.second << endl;
	}

	string textCode = textToCode(texte, encoding);

	cout << "Code :" << endl;
	cout << textCode << endl;

	return 0;
}