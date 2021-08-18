// https://www.codewars.com/kata/52a89c2ea8ddc5547a000863

#include <unordered_map>

class Node
{
public:
	void setNext(Node* nextNode) { next = nextNode; }
	Node* getNext() { return next; }

private:
	Node* next = nullptr;
};

int getLoopSize(Node* startNode)
{
	std::unordered_map<Node*, int> hashMap = {};
	int result = 0;
	auto currentNode = startNode;
	while (hashMap.find(currentNode) == hashMap.end())
	{
		result++;
		hashMap[currentNode] = result;
		currentNode = currentNode->getNext();
	}
	return ++result - hashMap[currentNode];
}