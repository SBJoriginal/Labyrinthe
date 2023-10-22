/**
 * \file Piece.h
 * \brief Ce fichier contient l'interface d'une pièce.
 * \author IFT-2008
 * \version 0.1
 * \date Automne 2023
 * 
 */

#ifndef PIECE_H_
#define PIECE_H_

#include <string>
#include <list>	// pour utiliser la liste de la STL

#include "Porte.h"

namespace TP1
{
/**
 *  \class Piece
 *  \brief classe représentant une pièce dans un labyrinthe
 */
class Piece
{
public:
	//constructeur par défaut
	Piece();

	//Surcharge du constructeur, le nom de la pièce en argument
	Piece(const std::string & s);

	//constructeur de copie
	Piece(const Piece& source);

	//destructeur
	~Piece();

	//Surcharge de l'opérateur =
	const Piece& operator =(const Piece& source);

	//Accesseur du nom d'une pièce (fourni inline)
	std::string getNom() const{
        return nom;
    };

	//Pour initialiser l'attribut parcourue à true ou false
	void setParcourue(bool p);

	//Pour initialiser l'attribut distanceDuDebut
	void setDistanceDuDebut(int d);

	//Acceder au membre parcourue (fourni inline)
	bool getParcourue() const{
        return parcourue;
	};

	//Accéder à la liste des portes qui partent de la pièce (fourni inline)
	const std::list<Porte> & getPortes() const{
        return portes;
    };

	//Accéder au membre distanceDuDebut (fourni inline)
	int getDistanceDuDebut() const{
        return distanceDuDebut;
    };

	//Ajouter une porte à la liste des portes qui partent de la pièce
	void ajoutePorte(const Porte& p);

private:
	std::list<Porte> portes; /*!< Les portes qui partent de la pièce. */
	/*!<Cette liste peut ne pas contenir toutes les portes qui
	communiquent avec la pièce. Une partie de ces portes peut être placée dans la liste de portes
	de l'autre pièce associée à la porte (utilise la liste STL).*/

	bool parcourue; /*!< Indique si la pièce a été parcourue*/
	/*!< Le champ "parcourue" sert uniquement à la méthode solutionner() de la classe labyrinthe, afin de ne pas passer
	plusieurs fois par une même pièce et risquer de tourner en rond, et donc boucler sans fin. */

	std::string nom; /*!< Le nom de la pièce. Il doit être unique pour un même labyrinthe.*/

	int distanceDuDebut; /*!< Le nombre de déplacements qu'il est nécessaire d'effectuer depuis la pièce de départ pour se rendre à cette pièce. */

};

}

#endif /* PIECE_H_ */
