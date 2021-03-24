#include "Grid.h"

void Grid::ClearGrid()
{
	while (Nodes.size() > 0)
	{
		Node* temps = Nodes[Nodes.size() -1];
		Nodes.pop_back();
		free(temps);
	}
}

void Grid::InitNeighbours()
{
	for (int i = 0; i < m_Width * m_Height; ++i)
	{
		bool canRight = i % m_Width != m_Width - 1;
		bool canLeft = i % m_Width != 0;
		bool canTop = i < m_Width * (m_Height - 1);
		bool canBot = i >= m_Width;

		if (canRight)
		{
			Nodes[i]->m_Neighbours.push_back(i + 1);
		}

		//Add Left
		if (canLeft)
		{
			Nodes[i]->m_Neighbours.push_back(i - 1);
		}
		//AddTop
		if (canTop)
		{
			Nodes[i]->m_Neighbours.push_back(i + m_Width);
		}
		//Add Bottom
		if (canBot)
		{
			Nodes[i]->m_Neighbours.push_back(i - m_Width);
		}
		//add TopLeft
		if (canLeft && canTop)
		{
			Nodes[i]->m_Neighbours.push_back(i - 1 + m_Width);
		}
		//add BotLeft
		if (canLeft && canBot)
		{
			Nodes[i]->m_Neighbours.push_back(i - 1 - m_Width);
		}

		//add TopRight
		if (canRight && canTop)
		{
			Nodes[i]->m_Neighbours.push_back(i + 1 + m_Width);
		}

		// add BotRight
		if (canRight && canBot)
		{
			Nodes[i]->m_Neighbours.push_back(i + 1 - m_Width);
		}
	}
}

Grid::Grid(int _width, int _height)
{
	m_Width = _width;
	m_Height = _height;
	CreateGrid();
}

std::vector<Node*> Grid::ComputePathOnGrid(int indexStart, int indexEnd)
{
	ResetPath();
	return Astar::ComputePath(Nodes,Nodes[indexStart],Nodes[indexEnd]);
}

void Grid::ResetPath()
{
	for (int i = 0; i < Nodes.size(); ++i)
	{
		Nodes[i]->m_G = 9999999;
		Nodes[i]->m_H = 9999999;
	}
}

void Grid::CreateGrid()
{
	ClearGrid();
	for (int i = 0; i < m_Width * m_Height; ++i)
	{
		int pos[2] = { i % m_Width,i / m_Width};
		Nodes.push_back(new Node(i, pos));
	}
	InitNeighbours();
	CreateWall();
}

void Grid::CreateWall()
{
	Nodes[10]->m_Walkable = false;
	Nodes[11]->m_Walkable = false;
	Nodes[3]->m_Walkable = false;
	Nodes[5]->m_Walkable = false;
	Nodes[7]->m_Walkable = false;
	Nodes[54]->m_Walkable = false;
	Nodes[51]->m_Walkable = false;
	Nodes[53]->m_Walkable = false;
	Nodes[52]->m_Walkable = false;
	Nodes[50]->m_Walkable = false;
	Nodes[55]->m_Walkable = false;
	Nodes[56]->m_Walkable = false;
	Nodes[57]->m_Walkable = false;
	Nodes[59]->m_Walkable = false;
	Nodes[69]->m_Walkable = false;
	Nodes[68]->m_Walkable = false;
	Nodes[75]->m_Walkable = false;
	Nodes[85]->m_Walkable = false;
	Nodes[78]->m_Walkable = false;
	Nodes[88]->m_Walkable = false;
	Nodes[87]->m_Walkable = false;
	Nodes[86]->m_Walkable = false;
}

void Grid::DisplayGreed()
{
	for (int i = 0; i < Nodes.size(); ++i)
	{
		if (i %m_Width == 0)
			std::cout << std::endl;
		if (Nodes[i]->m_Walkable)
			std::cout << " 0";
		else
			std::cout << " _";
	}
}

const Node * Grid::GetAt(int index) const
{
	return Nodes[index];
}

void Grid::DisplayPath(std::vector<Node*> path)
{
	for (int i = 0; i < Nodes.size(); ++i)
	{
		if (i %m_Width == 0)
			std::cout << std::endl;

		if (std::find(path.begin(), path.end(), Nodes[i]) != path.end())
		{
			std::cout << " X";
		}
		else
		{


			if (Nodes[i]->m_Walkable)
				std::cout << " 0";
			else
				std::cout << " =";
		}
		
		
	}
}
