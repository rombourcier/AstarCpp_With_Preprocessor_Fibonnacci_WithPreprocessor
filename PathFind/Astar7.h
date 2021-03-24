#pragma once
#include "Node.h"
#include "Math.h"
#include <iostream>
#include <algorithm>
class Astar7
{
	static  std::vector<Node*> GetPath(std::vector<Node*> navNodes, Node* start, Node* end);
	public:
	static  std::vector<Node*> ComputePath(std::vector<Node*> navNodes, Node* start, Node* end);

};

