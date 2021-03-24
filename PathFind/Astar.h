#pragma once
#include <vector>
#include <iostream>
#include "Node.h"
#include "Math.h"
class Astar
{
	static const std::vector<Node*> GetPath(std::vector<Node*> navNodes, Node* start, Node* end);
public:
	static const std::vector<Node*> ComputePath(std::vector<Node*> navNodes, Node* start, Node* end);
};

