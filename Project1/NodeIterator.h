#include "Node.h";

#pragma once
using namespace std;
class NodeIterator
{
	private:
		Node* current;
	public:
		NodeIterator(Node* starNode);
		int& operator*();
		NodeIterator& operator++();
		bool operator!=(const NodeIterator& other) const;
		bool operator==(const NodeIterator& other) const;
		NodeIterator end() const;
};

