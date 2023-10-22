/**
 * \file Piece.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Piece.
 * \author Étudiant(e)
 * \version 0.1
 * \date Automne 2023
 *
 */

#include "Piece.h"
#include <iostream>

namespace TP1
{
    // -----------------------
    // Méthodes de la classe Piece
    // -----------------------

    /**
     * \brief Constructeur par défaut de la classe Piece.
     *
     * Ce constructeur initialise une pièce avec un nom vide, non parcourue et une distance du début de 0.
     */
    Piece::Piece() : nom(""), parcourue(false), distanceDuDebut(0) {}

    /**
     * \brief Constructeur de la classe Piece avec un nom spécifié.
     *
     * Ce constructeur permet de créer une pièce avec un nom donné, initialement non parcourue et une distance du début de 0.
     *
     * \param s Le nom de la pièce.
     */
    Piece::Piece(const std::string &s) : nom(s), parcourue(false), distanceDuDebut(0) {}

    /**
     * \brief Constructeur de copie de la classe Piece.
     *
     * Ce constructeur de copie crée une nouvelle pièce à partir d'une pièce source.
     *
     * \param source La pièce source à partir de laquelle créer la nouvelle pièce.
     */
    Piece::Piece(const Piece& source) : nom(source.nom), parcourue(source.parcourue), distanceDuDebut(source.distanceDuDebut) {
        for (auto& element : source.portes) {
            this->ajoutePorte(element);
        }
    }

    /**
     * \brief Destructeur de la classe Piece.
     *
     * Le destructeur de la classe Piece ne fait rien de spécial, car il n'y a pas de ressources allouées dynamiquement.
     */
    Piece::~Piece() {}

    /**
     * \brief Surcharge de l'opérateur d'assignation (=) de la classe Piece.
     *
     * Cette méthode permet de copier les attributs d'une pièce source dans la pièce actuelle.
     *
     * \param source La pièce source à partir de laquelle copier les attributs.
     * \return Une référence vers la pièce actuelle après la copie.
     */
    const Piece& Piece::operator =(const Piece& source) {
        if (!(this == &source)) {
            nom = source.nom;
            parcourue = source.parcourue;
            distanceDuDebut = source.distanceDuDebut;
            portes.clear();
            for (auto porte : source.portes) {
                this->ajoutePorte(porte);
            }
        }
        return *this;
    }

    /**
     * \brief Setter pour l'attribut "parcourue" de la pièce.
     *
     * Cette méthode permet de définir l'état "parcourue" de la pièce.
     *
     * \param p La valeur booléenne à définir pour l'attribut "parcourue."
     */
    void Piece::setParcourue(bool p) {
        parcourue = p;
    }

    /**
     * \brief Setter pour l'attribut "distanceDuDebut" de la pièce.
     *
     * Cette méthode permet de définir la distance du début de la pièce.
     *
     * \param d La distance du début à définir pour la pièce.
     */
    void Piece::setDistanceDuDebut(int d) {
        distanceDuDebut = d;
    }

    /**
     * \brief Ajouter une porte à la liste des portes qui partent de la pièce.
     *
     * Cette méthode permet d'ajouter une porte à la liste des portes qui partent de la pièce.
     *
     * \param p La porte à ajouter à la liste des portes de la pièce.
     */
    void Piece::ajoutePorte(const Porte& p) {
        this->portes.push_back(p);
    }
}
