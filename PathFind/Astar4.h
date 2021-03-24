#pragma once
#include "Node.h"
#include "Math.h"
#include <iostream>
static class Astar4
{
	static const std::vector<Node*> GetPath(std::vector<Node*> navNode, Node* start, Node* end);
public:
	static const std::vector<Node*> ComputePath(std::vector<Node*> navNode, Node* start, Node* end);
};

