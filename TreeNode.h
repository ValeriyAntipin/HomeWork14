#pragma once
#include <iostream>
#include <string>
#define SIZE 26
using namespace std;


struct TreeNode {
	TreeNode* children[SIZE];
	bool isEndOfWord;
	int childCount = 0;
};


// ¬озвращает новый узел с пустыми детьми
TreeNode* getNewNode(void);

//вставка
void insert(struct TreeNode* root, string key);
//поиск
bool search(struct TreeNode* root, string key);
// ¬озвращает true если root имеет лист, иначе false
bool isEmpty(TreeNode* root);


bool symCompare(std::string& prefix, std::string& endWord);
void wordAuCom(TreeNode* root, std::string& prefix, std::string endWord);