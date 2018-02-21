// Copyright (C) 2017, Bodnar Peter, sajtos0007@gmail.com
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// Ez a program szabad szoftver; terjeszthetõ illetve módosítható a
// Free Software Foundation által kiadott GNU General Public License
// dokumentumában leírtak; akár a licenc 3-as, akár (tetszõleges) késõbbi
// változata szerint.
//
// Ez a program abban a reményben kerül közreadásra, hogy hasznos lesz,
// de minden egyéb GARANCIA NÉLKÜL, az ELADHATÓSÁGRA vagy VALAMELY CÉLRA
// VALÓ ALKALMAZHATÓSÁGRA való származtatott garanciát is beleértve.
// További részleteket a GNU General Public License tartalmaz.
//
// A felhasználónak a programmal együtt meg kell kapnia a GNU General
// Public License egy példányát; ha mégsem kapta meg, akkor
// tekintse meg a <http://www.gnu.org/licenses/> oldalon.
//
//
#include <iostream>
using namespace std;

struct Tree
{
	char data;
	Tree *left;
	Tree *right; 
	Tree *parent; 
 
};

Tree* lookUp(struct Tree *node, char key)
{
	if(node == NULL) return node;

	if(node->data == key) return node;
	else {
	    if(node->data < key)
		return lookUp(node->right, key) ;
	    else
		return lookUp(node->left, key);
	}
}

Tree* leftMost(struct Tree *node)
{
	if(node == NULL) return NULL;
	while(node->left != NULL)
		node = node->left;
	return node;
}

struct Tree *newTreeNode(int data) 
{
	Tree *node = new Tree;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;

	return node;
}

struct Tree* insertTreeNode(struct Tree *node, int data)
{
	static Tree *p;
	Tree *retNode;

	if(node == NULL)  {
	    retNode = newTreeNode(data);
	    retNode->parent = p;
	    return retNode;
	}
	if(data <= node->data ) { 
	    p = node;
	    node->left = insertTreeNode(node->left,data);
	} 
	else {
	    p = node;
	    node->right = insertTreeNode(node->right,data);
	} 
	return node;
}


int treeMeret(struct Tree *node)
{
	if(node == NULL) return 0;
	else
	    return treeMeret(node->left) + 1 + treeMeret(node->right);
}

int maxMelyseg(struct Tree *node)
{
	if(node == NULL || (node->left == NULL && node->right == NULL)) 
            return 0;

	int leftMelyseg = maxMelyseg(node->left);
	int rightMelyseg = maxMelyseg(node->right);

	return leftMelyseg > rightMelyseg ? 
				leftMelyseg + 1 : rightMelyseg + 1;
}

int minMelyseg(struct Tree *node)
{
	if(node == NULL || (node->left == NULL && node->right == NULL)) 
            return 0;

	int leftMelyseg = minMelyseg(node->left);
	int rightMelyseg = minMelyseg(node->right);

	return leftMelyseg < rightMelyseg ? 
				leftMelyseg+ 1 : rightMelyseg + 1;
}

bool kisuly(struct Tree *node)
{
	if(maxMelyseg(node)-minMelyseg(node) == 0) 
	    return true;
	else
	    return false;
}

Tree* minErtek(struct Tree *node)
{
	if(node == NULL) return NULL;
	while(node->left) 
	    node = node -> left;
	return node;
}

Tree* maxErtek(struct Tree *node)
{
	while(node->right) 
	    node = node -> right;
	return node;
}

int main()
{
	char charnum[9] 
	    = {'A','B','C','D','E','F','G','H','I'};

	Tree *root = newTreeNode('F');
	insertTreeNode(root,'B');
	insertTreeNode(root,'A');
	insertTreeNode(root,'D');
	insertTreeNode(root,'C');  
	insertTreeNode(root,'E');
	insertTreeNode(root,'G');
	insertTreeNode(root,'I');
	insertTreeNode(root,'H');

	
	cout << "Meret = " << treeMeret(root) << endl;


	cout << "Maximum melyseg = " << maxMelyseg(root) << endl;


	cout << "Minimum melyseg = " << minMelyseg(root) << endl;


	if(kisuly(root))
	    cout << "A fa kiegyensulyozott\n";
	else
	    cout << "A fa kiegyensulyozatlan!\n";


	if(root) 
	    cout << "Minimalis ertek = " << minErtek(root)->data << endl;


	if(root) 
	    cout << "Maximalis ertek = " << maxErtek(root)->data << endl;

return 0;
}
