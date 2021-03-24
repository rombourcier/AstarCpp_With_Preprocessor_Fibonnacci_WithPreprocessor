#include "Astar8.h"

const std::vector<Node*> Astar8::GetPath(std::vector<Node*> navNodes, Node* start, Node* end)
{
    std::vector<Node*> toReturn;
    Node* current = end;
    while (current != start)
    {
        toReturn.push_back(current);
        current = navNodes[current->m_Predecessor];
    }
    toReturn.push_back(current);
    std::reverse(toReturn.begin(),toReturn.end());
    return toReturn;
}

const std::vector<Node*> Astar8::ComputePath(std::vector<Node*> navNodes, Node* start, Node* end)
{
    if(start == nullptr ||end ==nullptr)
     return std::vector<Node*>();
    //Init
    std::vector<Node*> openList, closeList;
    Node* current = start;
    start->m_G = 0;
    openList.push_back(start);
    while (openList.size() > 0)
    {
        current = openList[0];
        if (current == end)
        {
            std::cout << "PathSuccess" << std::endl;
            return GetPath(navNodes, start, end);
        }
        openList.erase(openList.begin());
        closeList.push_back(current);
        for (int i = 0; i < current->m_Neighbours.size(); ++i)
        {
            Node* successor =  navNodes[current->m_Neighbours[i]];
            float g = current->m_G + Math::Magnitude(successor->m_Position, current->m_Position);
            float h = Math::Magnitude(successor->m_Position, end->m_Position);
            if (g + h < successor->m_F() && std::find(closeList.begin(), closeList.end(), successor) == closeList.end())
            {
                successor->m_G = g;
                successor->m_H = h;
                successor->m_Predecessor = current->m_GridIndex;

                if (std::find(openList.begin(), openList.end(), successor) == openList.end() && successor->m_Walkable)
                {
                    openList.push_back(successor);
                }
            }
        }
    }
    std::cout << "PathFailed" << std::endl;
    return std::vector<Node*>();
}
