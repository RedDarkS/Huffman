#include "Node.h"
#include <iostream>

using namespace std;

//CONSTRUCTEURS / DESTRUCTEURS
Node::Node() 
{

}

Node::Node(char v, int f) 
{
	setVal(v);
	setfreq(f);
}

Node::Node(char v, int f, Node *g, Node *d) 
{
	setVal(v);
	setfreq(f);
	setGauche(*g);
	setDroite(*d);
}
Node::~Node()
{
	//cout << "Detruit" << endl;
}

//GETTERS
char Node::getVal()const 
{
	return val;
}
int Node::getFreq() const 
{
	return freq;
}
Node Node::getGauche() const 
{
	return *gauche;
}
Node Node::getDroite() const 
{
	return *droite;
}

//SETTERS
void Node::setVal(char v) 
{
	val = v;
}
void Node::setfreq(int f) 
{
	freq = f;
}
void Node::setGauche(Node &g) 
{
	gauche = &g;
}
void Node::setDroite(Node &d) 
{
	droite = &d;
}