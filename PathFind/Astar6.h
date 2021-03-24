#pragma once
#include "Node.h"
#include "Math.h"
#include <iostream>
#include <algorithm>
class Astar6
{
	const static std::vector<Node*> GetPath(std::vector<Node*> navNode, Node* start, Node* end);
public:
	const static std::vector<Node*> ComputePath(std::vector<Node*> navNode, Node* start, Node* end);
};

