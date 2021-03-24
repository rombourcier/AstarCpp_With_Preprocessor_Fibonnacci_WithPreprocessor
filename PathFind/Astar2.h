#pragma once
#include "Node.h"
class Astar2
{
	Astar2();
	static const std::vector<Node*> GetPath(std::vector<Node*> navNodes, Node* start, Node* end);
public:
	static const std::vector<Node*>  ComputePath(std::vector<Node*> navNodes, Node* start, Node* end);
};

