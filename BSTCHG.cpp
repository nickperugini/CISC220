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

bool BST::insert(string s){
	TNode *x = new TNode(s);
	if (root == NULL){
		root = x;
		//setHeight(x);
		return true;
	}
	else{
		TNode *tmp = root;
		while (tmp != NULL){
			if (x->data->phrase < tmp->data->phrase){
				if(tmp->left == NULL){
					tmp->left = x;
					x->parent = tmp;
					//setHeight(x);
					return true;
				}
				tmp = tmp->left;
			}
			else if(x->data->phrase > (tmp->data->phrase)){
				if(tmp->right == NULL){
					tmp->right = x;
					x->parent = tmp;
					//setHeight(x);
					return true;
				}
				tmp = tmp ->right;
			}
			else if (x->data->phrase == s){
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

TNode *BST::find(string s){
		return findRec(root,s);
	}


void BST::printTreeIO(TNode *n) {   //recursive!!!! function
	if (n == NULL) {
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
			return;
		}
		else {
			printTreePost(n->left);
			printTreePost(n->right);
			n->printNode();
		}
	}

TNode *BST::remove(string s){
	TNode * tmp = find(s);
	        if(tmp->right == NULL && tmp->left == NULL){
	                return removeNoKids(tmp);
	        }
	        else if(((tmp->right == NULL) && (tmp->left != NULL)) | ((tmp->right != NULL) && (tmp->left == NULL))){
	                if(tmp->left == NULL){
	                        return removeOneKid(tmp, false);
	                }
	                else if(tmp->right == NULL){
	                        return removeOneKid(tmp, true);
	                }
	        }
	        else if(tmp->right != NULL && tmp->left != NULL){
	                TNode * tmp2 = tmp;
	                tmp2 = tmp2->left;
	                while(tmp2->right != NULL){
	                        tmp2 = tmp2->right;
	                }
	                tmp->data->phrase = tmp2->data->phrase;
	                if(tmp2->left == NULL){
	                        removeNoKids(tmp2);
	                }
	                else{
	                        removeOneKid(tmp2, true);
	                }
	                return tmp;
	        }
}

TNode *BST::removeNoKids(TNode *tmp){
	TNode *tPar=tmp->parent;
	if(tmp==root){
		return tmp;
	}
	else if(tPar->data->phrase > tmp->data->phrase){
		tPar->left=NULL;
		return tmp;
	}
	else{
		tPar->right=NULL;
		return tmp;
	}
}

TNode *BST::removeOneKid(TNode *tmp,bool leftFlag){
	 if(tmp->parent->left==tmp){                         //Our node is to the left
	                if(leftFlag){                                                           //Child is on the left
	                        tmp->parent->left = tmp->left;
	                        tmp->left->parent = tmp->parent;
	                }
	                else{                                                                           //Child is on the right
	                        tmp->parent->left = tmp->right;
	                        tmp->right->parent = tmp->parent;
	                }
	        }
	        else{                                                                                   //Our node is to the right
	                if(leftFlag){                                                           //Child is on the left
	                        tmp->parent->right = tmp->left;
	                        tmp->left->parent = tmp->parent;
	                }
	                else{                                                                           //Child is on the right
	                        tmp->parent->right = tmp->right;
	                        tmp->right->parent = tmp->parent;
	                }
	        }
	        return tmp;
}

void BST::setHeight(TNode * n){
        int prevHeight = 1;
        int newHeight = 0;
        n = n->parent;
        while(prevHeight != newHeight && n->parent != NULL){
                prevHeight = n->height;
                newHeight = (n->right->height < n->left->height) ? n->left->height : n->right->height;
                newHeight++;
                n->height = newHeight;
        }
}
