// PathFind.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Astar.h"
#include "Grid.h"
#include "InputManager.h"
#include "Fille.h"
#include <algorithm>

#pragma region Fibonnacci Preprocessor
template<int n>
struct fibonacci
{
	enum
	{
		valeur = fibonacci<n - 1>::valeur
		+ fibonacci<n - 2>::valeur
	};

};
template<>
struct fibonacci<1>
{
	enum
	{
		valeur = 1
	};
};
template<>
struct fibonacci<0>
{
	enum
	{
		valeur = 0
	};
};
#pragma endregion

unsigned long long Fibonnacci_rec(unsigned int n)
{
	if (n == 0)
		return 0;
	if (n <= 1)
		return 1;
	return Fibonnacci_rec(n - 1) + Fibonnacci_rec(n - 2);
}
int main()
{

	
#pragma region Test Astar && InputManager avec abonnement

	Grid grille(10,10);
	InputManager* inputManager = new InputManager();
	inputManager->SubscribeToOnInputPressed(std::bind(&Grid::DisplayPath, &grille,grille.ComputePathOnGrid(0,99)));
	inputManager->SubscribeToOnInputPressed(std::bind(&Grid::DisplayPath, &grille,grille.ComputePathOnGrid(9,79)));
	inputManager->PressInput();

#pragma endregion

#pragma region Test Fibonnacci Preprocessor & Eratostène

	// Fibonnacci preprocessor
	std::cout << std::endl;
	std::cout << "Fibonnacci" << std::endl;
	std::cout << fibonacci<7>::valeur;


#pragma endregion
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
