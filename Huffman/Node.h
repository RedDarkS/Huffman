#pragma once

class Node
{
	private :
		char val;
		int freq = 0;
		Node *gauche;
		Node *droite;

	public :

        //CONSTRUCTEURS / DESTRUCTEURS
        Node();
        Node(char v, int f);
        Node(char v, int f, Node *g, Node *d);
        ~Node();

        //GETTERS
        char getVal()const;
        int getFreq() const;
        Node getGauche() const;
        Node getDroite() const;

        //SETTERS
        void setVal(char v);
        void setfreq(int f);
        void setGauche(Node &g);
        void setDroite(Node &d);
};

