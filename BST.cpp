/*Note: you must create the BST.cpp file.  I'm only including a few 
Otherwise, as specified in the directions, you must write the BST.cpp.
including the method definitions to accompany the method declarations 
in BST.hpp
*/
#include "BST.hpp"
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
	else if(s<=root->data){
		root->left=insertRec(root->left,s);
	}
	else if(s>root->data){
		root->right=insertRec(root->right,s);
	}
	return root;
}

bool BST::insert(string s){
	TNode *newNode= insertRec(root,s);
	if(newNode==NULL){
		return false;
	}
	root=newNode;
	setHeight;
	return true;
}

TNode * findRec(TNode *root, string s){
	if (root==NULL){
		return NULL;
	}

	else if (root->data==0){
		return root;
	}

	else if (root->data<0){
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
			printTreeIO(n->left);
			printTreeIO(n->right);
		}
	}

void BST::printTreePost(TNode *n){
	if (n == NULL) {
			return;
		}
		else {
			printTreeIO(n->left);
			printTreeIO(n->right);
			n->printNode();
		}
	}

TNode *BST::remove(string s){
	TNode *tmp=find(s);
	if(tmp->left==NULL & tmp->right==NULL){
		removeNoKids(tmp);
		return tmp;
	}
	else if(tmp->left!=NULL & tmp->right==NULL){
		removeOneKid(tmp,false);
	}
	else if(tmp->left==NULL & tmp->right!=NULL){
		removeOneKid(tmp,true);
		}
	else{
		if(tmp->left->right==NULL){	//condition if left node does not have a child to the right
			tmp->left->parent=tmp->parent;
			tmp->parent->left=tmp->left;
			delete(tmp);
		}
		else{
			TNode *rmving=tmp;
			tmp=tmp->left;
			while(tmp->right!=NULL){
				tmp=tmp->right;
			}
			rmving->data=tmp->data;
			delete(tmp);
		}
	}
}

TNode *BST::removeNoKids(TNode *tmp){

	delete(tmp);
	return tmp;				//Can i return tmp after deleting it?
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
		delete(tmp);
	}
	else{
		tmp->left->parent=tmp->parent;
		if(tmp->parent->left==tmp){
		tmp->parent->left=tmp->left;
		}
		else{
			tmp->parent->right=tmp->left;
		}
		delete(tmp);
	}
}

void BST::setHeight(TNode *n){

	if(root==NULL){
		return;
	}
	else {
		int left_height = setHeight(root->left);
		int right_height = setHeight(root->right);

		return max(left_height, right_height)+1
	}

