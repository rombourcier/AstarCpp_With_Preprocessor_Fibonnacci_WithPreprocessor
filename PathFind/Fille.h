#pragma once
#include "Mere.h"
#include <assert.h>
class Fille : public Mere
{
public:
	Fille(int index);
	int getIndex();
	void Afficher();
	void SetIndex(int _index);
};

