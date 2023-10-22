/**
 * \file Porte.h
 * \brief Ce fichier contient l'interface d'une porte.
 * \author IFT-2008
 * \version 0.1
 * \date Automne 2023
 *
 */

#ifndef PORTE_H_
#define PORTE_H_


namespace TP1
{
/**
 * \enum Couleur
 * \brief La couleur d'un joueur
 *
 * elle peut prendre 5 valeurs : Rouge, Bleu, Jaune ou Vert ainsi que la
 * valeur "Aucun" qui est une valeur spéciale utilisée dans la fonction "trouveGagnant".
 */
typedef enum
{
	Rouge, Vert, Bleu, Jaune, Aucun
} Couleur;

// La ligne qui suit sert à signifier au compilateur que la classe "Piece" existe.
// On le fait, car la structure "Porte" comporte des pointeurs vers la classe "Piece", et vice versa.
class Piece;

/**
 * \class Porte
 * \brief classe qui représente une porte d'une couleur donnée entre deux pièces
 */

class Porte
{
public:

	//constructeur par défaut
	Porte();

	//Constructeur, en argument la couleur de la porte ainsi que la pièce de destination
	Porte(Couleur c, Piece * d);

	//Constructeur de copie
	Porte(const Porte& source);

	//un destructeur qui ne fera rien
	~Porte();

	//Surcharge de l'opérateur =
	const Porte& operator =(const Porte& source);

	//Surcharge de l'opérateur ==
	bool operator ==(const Porte& source) const;

	//accesseur de la couleur d'une porte (fourni inline)
	Couleur getCouleur() const {
	    return color;
	};

	//Accesseur de la piece de destination (fourni inline)
	Piece * getDestination() const{
        return destination;
    };

private:
	Piece * destination; /*!< Vers où la porte mène.*/
	Couleur color; /*< Couleur de la porte.*/
	/*!< Cette couleur spécifie en même temps quel est le joueur qui a le droit de franchir cette porte.*/

};

}

#endif /* PORTE_H_ */
