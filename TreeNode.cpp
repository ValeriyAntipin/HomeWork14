#include "TreeNode.h"

TreeNode* getNewNode(void)
{
	TreeNode* node = new TreeNode;

	node->isEndOfWord = false;
	for (int i = 0; i < SIZE; i++)
	{
		node->children[i] = nullptr;
	}

	return node;
}


void insert(TreeNode* root, string key)
{
	struct TreeNode* pSym = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pSym->children[index])
			pSym->children[index] = getNewNode();
		pSym = pSym->children[index];
		pSym->childCount++;
	}
	pSym->isEndOfWord = true;
}

bool search(TreeNode* root, string key)
{
	struct TreeNode* node = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!node->children[index])
			return false;
		node = node->children[index];
	}
	return(node != nullptr && node->isEndOfWord);
}

bool isEmpty(TreeNode* root)
{
	for (int i = 0; i < SIZE; i++)
		if (root->children[i])
			return false;
	return true;
}




bool symCompare(std::string& prefix, std::string& endWord)
{
	int count = 0;
	int lenght = 0;

	if (prefix.size() <= endWord.size())
		lenght = prefix.size();
	else
		lenght = endWord.size();

	for (int i = 0; i < lenght; ++i)
	{
		if (prefix[i] == endWord[i])
			++count;
	}
	return count == lenght;
}

void wordAuCom(TreeNode* root, string& prefix, string endWord)
{
	TreeNode* node = root;
	for (int i = 0; i < SIZE; i++)
	{
		if (node->children[i])
		{
			endWord.push_back(i + 'a');
			if (node->children[i]->isEndOfWord)
			{
				if (symCompare(prefix, endWord))
					std::cout << endWord << std::endl;
			}
			wordAuCom(node->children[i], prefix, endWord);
			endWord.pop_back();
		}
	}
}