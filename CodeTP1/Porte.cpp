/**
 * \file Porte.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Porte.
 * \author Étudiant(e)
 * \version 0.1
 * \date Automne 2023
 *
 */

#include "Porte.h"

namespace TP1
{
    // -----------------------
    // Méthodes de la classe Porte
    // -----------------------

    /**
     * \brief Constructeur par défaut de la classe Porte.
     *
     * Ce constructeur initialise une porte avec la couleur "Aucun" et sans pièce de destination.
     */
    Porte::Porte() : color(Aucun), destination(nullptr) {}

    /**
     * \brief Constructeur de la classe Porte.
     *
     * Ce constructeur permet de créer une porte avec une couleur donnée et une pièce de destination spécifiée.
     *
     * \param c La couleur de la porte.
     * \param d La pièce de destination vers laquelle cette porte mène.
     */
    Porte::Porte(Couleur c, Piece* d) : color(c), destination(d) {}

    /**
     * \brief Constructeur de copie de la classe Porte.
     *
     * Ce constructeur de copie crée une nouvelle porte à partir d'une porte source.
     *
     * \param source La porte source à partir de laquelle créer la nouvelle porte.
     */
    Porte::Porte(const Porte& source) : color(source.color), destination(source.destination) {}

    /**
     * \brief Destructeur de la classe Porte.
     *
     * Le destructeur de la classe Porte ne fait rien de spécial, car il n'y a pas de ressources allouées dynamiquement.
     */
    Porte::~Porte() {}

    /**
     * \brief Surcharge de l'opérateur d'assignation (=) de la classe Porte.
     *
     * Cette méthode permet de copier les attributs d'une porte source dans la porte actuelle.
     *
     * \param source La porte source à partir de laquelle copier les attributs.
     * \return Une référence vers la porte actuelle après la copie.
     */
    const Porte& Porte::operator =(const Porte& source) {
        if (!(this == &source)) {
            destination = source.destination;
            color = source.color;
        }
        return *this;
    }

    /**
     * \brief Surcharge de l'opérateur d'égalité (==) de la classe Porte.
     *
     * Cette méthode permet de vérifier si deux portes sont égales en comparant leur couleur et leur pièce de destination.
     *
     * \param source La porte à comparer avec la porte actuelle.
     * \return `true` si les portes sont égales, `false` sinon.
     */
    bool Porte::operator ==(const Porte& source) const {
        return (destination == source.destination && color == source.color);
    }
}
