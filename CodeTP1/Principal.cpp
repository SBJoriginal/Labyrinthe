/**
 * \file Principal.cpp
 * \brief Ce fichier contient un main pour tester le labyrinthe.
 * \author IFT-2008, Étudiant(e)
 * \version 0.1
 * \date Automne 2023
 * 
 */

#include "Labyrinthe.h"

using namespace std;
using namespace TP1;

int main()
{
	try
	{
		Labyrinthe lab;

        string reponse = "";
        ifstream entree;

        cout << "Entrez le nom du labyrinthe (exp: 2x3, 10x10, .., 50x65) : ";
        getline(cin, reponse);


		entree.open("data/Lab" + reponse + "/rouge" + reponse + ".txt", ios::in);
		if (!entree.is_open())
		{
			cout << "Fichier rouge introuvable.\n";
			return 1;
		}

        cout << "\nChargement du labyrinthe rouge...\n";
		lab.chargeLabyrinthe(Rouge, entree);
		entree.close(); //on ferme le fichier

        entree.open("data/Lab" + reponse + "/vert" + reponse + ".txt", ios::in);
        if (!entree.is_open())
		{
			cout << "Fichier vert introuvable.\n";
			return 1;
		}
        cout << "\nChargement du labyrinthe vert...\n";
		lab.chargeLabyrinthe(Vert, entree);
		entree.close();

        entree.open("data/Lab" + reponse + "/bleu" + reponse + ".txt", ios::in);
        if (!entree.is_open())
		{
			cout << "Fichier bleu introuvable.\n";
			return 1;
		}
        cout << "\nChargement du labyrinthe bleu...\n";
		lab.chargeLabyrinthe(Bleu, entree);
		entree.close();

        entree.open("data/Lab" + reponse + "/jaune" + reponse + ".txt", ios::in);
        if (!entree.is_open())
		{
			cout << "Fichier jaune introuvable.\n\n";
			return 1;
		}
        cout << "\nChargement du labyrinthe jaune...\n";
		lab.chargeLabyrinthe(Jaune, entree);
		entree.close();

		cout << "\nLe joueur rouge peut solutionner le labyrinthe en "
				<< lab.solutionner(Rouge) << " deplacements.\n";
		cout << "\nLe joueur vert peut solutionner le labyrinthe en "
				<< lab.solutionner(Vert) << " deplacements.\n";
		cout << "\nLe joueur bleu peut solutionner le labyrinthe en "
				<< lab.solutionner(Bleu) << " deplacements.\n";
		cout << "\nLe joueur jaune peut solutionner le labyrinthe en "
				<< lab.solutionner(Jaune) << " deplacements.\n";

        cout << "\nRecherche du gagnant...\n";
		Couleur LeGagnant = lab.trouveGagnant();
		switch (LeGagnant)
		{
		case 0:
			cout << endl << "Le joueur gagnant: Rouge" << endl << endl; break;
		case 1:
			cout << endl << "Le joueur gagnant: Vert" << endl << endl; break;
		case 2:
			cout << endl << "Le joueur gagnant: Bleu" << endl << endl; break;
		case 3:
			cout << endl << "Le joueur gagnant: Jaune" << endl << endl; break;
		default:
			cout << endl << "Le joueur gagnant: Aucun!!" << endl << endl; break;
		}

	} catch (exception & e)
	{
		cerr << e.what() << endl;
	}

	return 0;
}
