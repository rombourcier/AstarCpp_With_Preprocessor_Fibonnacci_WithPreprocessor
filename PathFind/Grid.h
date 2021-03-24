#pragma once
#include "Node.h"
#include "Astar.h"
#include <iostream>
#include <vector>
#include <algorithm>
class Grid
{
	void ClearGrid();
	void InitNeighbours();
	int m_Width;
	int m_Height;

	std::vector<Node*> Nodes;
	void CreateGrid();
	void CreateWall();
	void DisplayGreed();
public:
	std::vector<Node*> ComputePathOnGrid(int indexStart, int indexEnd);
	void ResetPath();
	Grid(int _width, int _height);
	const Node* GetAt(int index) const;

	void DisplayPath(std::vector<Node*> path);
};

