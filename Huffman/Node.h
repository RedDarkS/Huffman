#pragma once

class Node
{
	private :
		char val;
		int freq = 0;
		Node* gauche = nullptr;
		Node* droite = nullptr;

	public :

        //CONSTRUCTEURS / DESTRUCTEURS
        Node();
        Node(char v, int f);
        Node(char v, int f, Node *g, Node *d);

        //GETTERS
        char getVal();
        int getFreq();
        Node getGauche();
        Node getDroite();

        //SETTERS
        void setVal(char v);
        void setfreq(int f);
        void setGauche(Node &g);
        void setDroite(Node &d);
};

