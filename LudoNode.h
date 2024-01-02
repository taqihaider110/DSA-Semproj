#include<iostream>
using namespace std;

#ifndef LUDONODE_H
#define LUDONODE_H

class Node {
	public:
		int* piececount;
		bool kill;
		Node* next;

		// Constructor
		Node(bool nodeKill = false) : next(nullptr), kill(nodeKill), piececount(new int) {
		}

		// Virtual destructor to make the class polymorphic
		virtual ~Node() {}
};

// Definition of the ColoredNode class
class ColoredNode : public Node {
	public:
		string color;

		// Constructor
		ColoredNode(const string& nodeColor, bool nodeKill = false) : Node(nodeKill), color(nodeColor) {}
};

// Definition of the ExtendedColoredNode class
class ExtendedColoredNode : public ColoredNode {
	public:
		Node* home;

		// Constructor
		ExtendedColoredNode(const string& nodeColor, Node* nodeHome, bool nodeKill = false) : ColoredNode(nodeColor, nodeKill), home(nodeHome) {}
};

#endif