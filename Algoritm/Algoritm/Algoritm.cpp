#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

using NodeRef = shared_ptr<struct Node>;

struct Node
{
	Node() {}
	Node(const string& data) : data(data) {}

	string data;
	vector<NodeRef> childern;
};

NodeRef CreateTree()
{
	NodeRef root = make_shared<Node>("R1 개발부");
	{
		NodeRef node = make_shared<Node>("디자인팀");
		root->childern.push_back(node);
		{
			NodeRef leaf = make_shared<Node>("전투");
			node->childern.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("경제");
			node->childern.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("스토리");
			node->childern.push_back(leaf);
		}
	}

	{
		NodeRef node = make_shared<Node>("프로그래밍팀");
		root->childern.push_back(node);
		{
			NodeRef leaf = make_shared<Node>("서버");
			node->childern.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("클라");
			node->childern.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("엔진");
			node->childern.push_back(leaf);
			{
				NodeRef dummy = make_shared<Node>("더미");
				leaf->childern.push_back(dummy);
			}
		}
	}

	{
		NodeRef node = make_shared<Node>("아트팀");
		root->childern.push_back(node);
		{
			NodeRef leaf = make_shared<Node>("배경");
			node->childern.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("캐릭터");
			node->childern.push_back(leaf);
		}
	}


	return root;
}

void PrintTree(NodeRef root, int depth)
{
	

	for (int i = 0; i < depth; i++)
		cout << "-";
	cout << root->data << endl;

	for (NodeRef& child : root->childern)
		PrintTree(child, depth + 1);

}

int GetHeight(NodeRef root)
{
	int height = 1;

	for (NodeRef& child : root->childern)
	{
		height = max(height, GetHeight(child) + 1);
	}

	return height;
}

int main()
{
	NodeRef root = CreateTree();
	PrintTree(root, 0);

	int height = GetHeight(root);
	cout << "Height : " << height << endl;

	return 0;
}
