#pragma once
#include "Node.h"
#include "Math.h"
#include <iostream>
class Astar3
{
	Astar3();
	static const std::vector<Node*> GetPath(std::vector<Node*> navNodes, Node* start, Node* End);
public:
	static const std::vector<Node*> ComputePath(std::vector<Node*> navNodes, Node* start, Node* end);

};

