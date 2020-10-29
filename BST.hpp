/*
 * BST.hpp
 *
 *  Created on: Apr 10, 2020
 *      Author: 13027
 */

#ifndef BST_HPP_
#define BST_HPP_

#include "TNode.hpp"

class BST {
	TNode *root;

public:
	BST();
	BST(string s);
	bool insert(string s);
	TNode *find(string s);
	void printTreeIO();
	void printTreeIO(TNode *n);
	void printTreePre();
	void printTreePre(TNode *n);
	void printTreePost();
	void printTreePost(TNode *n);
	void clearTree();
	void clearTree(TNode *tmp);
	TNode *removeNoKids(TNode *tmp);
	TNode *removeOneKid(TNode *tmp, bool leftFlag);
	TNode *remove(string s);
	void setHeight(TNode *n);
	TNode *insertRec(TNode *root,string s);
	TNode *findRec(TNode *root,string s);
};





#endif /* BST_HPP_ */
