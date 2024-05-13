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


// ���������� ����� ���� � ������� ������
TreeNode* getNewNode(void);

//�������
void insert(struct TreeNode* root, string key);
//�����
bool search(struct TreeNode* root, string key);
// ���������� true ���� root ����� ����, ����� false
bool isEmpty(TreeNode* root);


bool symCompare(std::string& prefix, std::string& endWord);
void wordAuCom(TreeNode* root, std::string& prefix, std::string endWord);