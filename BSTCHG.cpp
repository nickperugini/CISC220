/*Note: you must create the BST.cpp file.  I'm only including a few 
Otherwise, as specified in the directions, you must write the BST.cpp.
including the method definitions to accompany the method declarations 
in BST.hpp
*/
#include "BST.hpp"
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

BST::BST() {
	root = NULL;
}
BST::BST(string s) {
	root = new TNode(s);
}

void BST::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}


void BST::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}


void BST::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}


void BST::clearTree() {
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}

void BST::clearTree(TNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode();
		delete(tmp);
	}
}

TNode *BST::insertRec(TNode *root,string s){		//helper function
	if(root==NULL){
			return new TNode(s);
		}
	else if(s<=root->data->phrase){
		root->left=insertRec(root->left,s);
	}
	else if(s>root->data->phrase){
		root->right=insertRec(root->right,s);
	}
	return root;
}

bool BST::insert(string s) {
        if (root == NULL) {
                root = new TNode(s);
                return true;
        }
        else {
                TNode * n = root;
                while (n != NULL) {
                        if (s < n->data->phrase) {
                                if (n->left == NULL) {
                                        n->left = new TNode(s);
                                        n->left->parent = n;
                                        return true;
                                }
                                else {
                                        n->left = n;
                                }
                        }
                        else if (s > n->data->phrase) {
                                if (n->right == NULL) {
                                        n->right = new TNode(s);
                                        n->right->parent = n;
                                        return true;
                                }
                                else {
                                        n->right = n;
                                }
                        }
                        else {
                                return false;
                        }
                }
        }
        return false;
}

TNode * BST::findRec(TNode *root, string s){
	if (root==NULL){
		return NULL;
	}

	else if ((root->data->phrase).compare(s)==0){
		return root;
	}

	else if ((root->data->phrase).compare(s)<0){
		return findRec(root->right,s);
	}

		return findRec(root->left,s);
	}

TNode* BST::find(string s){
        while (root != NULL) {
                if (s > root->data->phrase) {
                        root = root->right;
                }
                else if (s < root->data->phrase) {
                        root = root->left;
                }
                else {
                        return root;
                }
        }
        return NULL;
}


void BST::printTreeIO(TNode *n) {   //recursive!!!! function
	if (n == NULL) {
		cout << "Empty Tree"<< endl;
		return;
	}
	else {
		printTreeIO(n->left);
		n->printNode();
		printTreeIO(n->right);
	}
}

void BST::printTreePre(TNode *n){
	if (n == NULL) {
		cout << "Empty Tree"<< endl;
			return;
		}
		else {
			n->printNode();
			printTreePre(n->left);
			printTreePre(n->right);
		}
	}

void BST::printTreePost(TNode *n){
	if (n == NULL) {
		cout << "Empty Tree"<< endl;
			return;
		}
		else {
			printTreePost(n->left);
			printTreePost(n->right);
			n->printNode();
		}
	}

TNode *BST::remove(string s){
	TNode *tmp=find(s);
	if((tmp->left==NULL) & (tmp->right==NULL)){
		removeNoKids(tmp);
		return tmp;
	}
	else if((tmp->left!=NULL) & (tmp->right==NULL)){
		removeOneKid(tmp,false);
		return tmp;
	}
	else if((tmp->left==NULL) & (tmp->right!=NULL)){
		removeOneKid(tmp,true);
		return tmp;
		}
	else{
		if(tmp->left->right==NULL){	//condition if left node does not have a child to the right
			tmp->left->parent=tmp->parent;
			tmp->parent->left=tmp->left;
			return(tmp);
		}
		else{
			TNode *rmving=tmp;
			tmp=tmp->left;
			while(tmp->right!=NULL){
				tmp=tmp->right;
			}
			rmving->data=tmp->data;
			return(tmp);
		}
	}
}

TNode *BST::removeNoKids(TNode *tmp){
	TNode *returnVal=tmp;
	delete(tmp);
	return returnVal;				//Can i return tmp after deleting it?
}

TNode *BST::removeOneKid(TNode *tmp,bool leftFlag){
	if(leftFlag==false){
		tmp->right->parent=tmp->parent;
		if(tmp->parent->right==tmp){
			tmp->parent->right=tmp->right;
		}
		else{
			tmp->parent->left=tmp->right;
		}
		return tmp;
	}
	else{
		tmp->left->parent=tmp->parent;
		if(tmp->parent->left==tmp){
		tmp->parent->left=tmp->left;
		}
		else{
			tmp->parent->right=tmp->left;
		}
		return tmp;
	}
}

void BST::setHeight(TNode * n){
        int oldH = 1;
        int newH = 0;
        n = n->parent;
        while(oldH != newH && n->parent != NULL){
                oldH = n->height;
                if(n->right->height < n->left->height){
                	newH= n->left->height;                }
                else{
                	newH=n->right->height;

                }
                newH++;
                n->height = newH;
        }
}

