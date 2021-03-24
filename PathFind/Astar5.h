#pragma once
#include "Math.h"
#include "Node.h"
#include <iostream>
static class Astar5
{
	static std::vector<Node*> GetPath(std::vector<Node*> navNodes, Node* start, Node* end);
public:
	static std::vector<Node*> ComputePath(std::vector<Node*> navNodes, Node* start, Node* end);
};

