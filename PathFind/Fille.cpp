#include "Fille.h"

Fille::Fille(int _index) : Mere(_index)
{
}

int Fille::getIndex()
{
	return m_index;
}

void Fille::Afficher()
{
	Mere::Afficher();
	std::cout << "Fille";
}

void Fille::SetIndex(int _index)
{
	std::cerr << "index erroné"<<std::endl;
	assert(_index != 0);
	m_index = _index;
}
