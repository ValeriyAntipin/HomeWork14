#include "TreeNode.h"

int main()
{
	TreeNode* root = new TreeNode{};
	insert(root, "car");
	insert(root, "corn");
	insert(root, "cat");
	insert(root, "apple");
	insert(root, "atom");
	insert(root, "approach");


	cout << "Hello, it is test word autocomplite programm, q - for exit" << endl;
	bool work = true;
	while (work)
	{
		std::cout << "Enter text: " << std::endl;

		std::string strIn;
		std::cin >> strIn;
		if (strIn == "q")
		{
			work = false;
			continue;
		}
		std::cout << " Word options:" << std::endl;
		wordAuCom(root, strIn, "");
	}

	delete root;
	return 0;
}