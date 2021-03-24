#pragma once
#include <vector>
class Node
{
	Node();
public :
	Node(int _gridIndex,int _position[2]);
	int m_G = 50000; // Dist From Start
	int m_H = 50000; // Dist From End
	int m_F() { return m_G + m_H; };
	int m_GridIndex = 0;
	int m_Predecessor = 0;
	int m_Position[2];
	int m_Walkable = true;
	
	std::vector<int> m_Neighbours;
};

