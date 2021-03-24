#include "Astar7.h"

std::vector<Node*> Astar7::GetPath(std::vector<Node*> navNodes, Node * start, Node * end)
{
	std::vector<Node*> path;
	Node * current = end;
	while (current != start)
	{
		path.push_back(current);
		current = navNodes[current->m_Predecessor];
	}
	path.push_back(current);
	std::reverse(path.begin(), path.end());
	return path;
}

std::vector<Node*> Astar7::ComputePath(std::vector<Node*> navNodes, Node * start, Node * end)
{
	if (start == nullptr || end == nullptr) return std::vector<Node*>();
	Node* current;
	start->m_G = 0;
	std::vector<Node*> openList, closeList;
	openList.push_back(start);
	while (openList.size()>0)
	{
		current = openList[0];
		if (current == end)
		{
			return GetPath(navNodes, start, end);
		}
		openList.erase(openList.begin());
		closeList.push_back(current);
		for (int i = 0; i < current->m_Neighbours.size(); ++i)
		{
			Node* successor = navNodes[current->m_Neighbours[i]];
			float g = current->m_G + Math::Magnitude(current->m_Position, successor->m_Position);
			float h = Math::Magnitude(successor->m_Position, end->m_Position);
			if (g + h < successor->m_F() && std::find(closeList.begin(), closeList.end(), successor) == closeList.end())
			{
				successor->m_G = g;
				successor->m_H = h;
				successor->m_Predecessor = current->m_GridIndex;
				if (std::find(openList.begin(), openList.end(), successor) == openList.end() && successor->m_Walkable)
					openList.push_back(successor);

			}

		}
	}
	return std::vector<Node*>();
}
