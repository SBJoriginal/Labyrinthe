/**
 * \file Labyrinthe.cpp
 * \brief Le code des méthodes membres et privés de la classe Labyrinthe.
 * \author IFT-2008, Étudiant(e)
 * \version 0.1
 * \date Automne 2023
 *
 */

//Fichiers à compléter par les autres méthodes de la classe Labyrinthes demandées

#include "Labyrinthe.h"

namespace TP1
{
 using namespace std;

// --------------------------
//	Méthodes à implémenter
// --------------------------

    Labyrinthe::Labyrinthe(): dernier(nullptr), depart(nullptr), arrivee(nullptr){}

    Labyrinthe::Labyrinthe(const Labyrinthe& source): dernier(source.dernier){
        NoeudListePieces* sentinelle = source.dernier;
        if (sentinelle != nullptr){
            do {
                this->ajoutePieceLabyrinthe(sentinelle->piece);
                for (auto porte : sentinelle->piece.getPortes()){
                    sentinelle->piece.ajoutePorte(porte);
                }
                sentinelle = sentinelle->suivant;
            }while (sentinelle != source.dernier);
            placeDepart(source.depart->getNom());
            placeArrivee(source.arrivee->getNom());
        }
    }//finish contttructeur de copie

    Labyrinthe::~Labyrinthe() {}

    const Labyrinthe& Labyrinthe::operator =(const Labyrinthe& source) {
        if (this != &source){
            NoeudListePieces *sentinelle_delete = dernier;
            do{
                NoeudListePieces* temp = dernier->suivant;
                delete dernier;
                dernier = temp;
            }while (sentinelle_delete != dernier);

            NoeudListePieces *sentinelle = source.dernier;
            if (sentinelle != nullptr) {
                do {
                    this->ajoutePieceLabyrinthe(sentinelle->piece);
                    for (auto porte: sentinelle->piece.getPortes()) {
                        sentinelle->piece.ajoutePorte(porte);
                    }
                    sentinelle = sentinelle->suivant;
                } while (sentinelle != source.dernier);
                placeDepart(source.depart->getNom());
                placeArrivee(source.arrivee->getNom());
                dernier = source.dernier;
            }
        }
     return *this;
    }

// -------------------------
//	Méthodes fournies
// -------------------------

/**
 * \fn	void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream &entree)
 * \param[in]	couleur, la couleur du jouer auquel le labyrinthe chargé s'applique
 * \param[in]	entree, fichier contenant la définition du labyrinthe
 */
void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream &entree)
 {
	int nbCols, nbRangs;

    if (!entree.is_open())
        throw logic_error("Labyrinthe::chargeLabyrinthe: Le fichier n'est pas ouvert !");

	entree >> nbCols >> nbRangs;
	entree.ignore(); //pour consommer le \n (le caractère fin de ligne)

	const int MAX_LIGNE = 1000;
	char ligne[MAX_LIGNE];

	entree.getline(ligne, MAX_LIGNE);
	entree.getline(ligne, MAX_LIGNE);

	std::ostringstream s; //Une chaîne pour écrire dedans, cette chaîne servira pour nommer les pièces du labyrinthe

	for (int i = 0; i < nbCols; i++)
	{
		for (int j = 0; j < nbRangs; j++)
		{
			s << i << "," << j;
			Piece p(s.str());
			s.str("");
			ajoutePieceLabyrinthe(p);
		}
	}

	for (int i = 0; i < nbCols; i++)
	{
		if (ligne[i * 4 + 1] == 'D' || ligne[i * 4 + 1] == 'd')
		{
			std::string nom;
			s << i << ",0";
			nom = s.str();
			s.str("");
			placeDepart(nom);
		}
		if (ligne[i * 4 + 1] == 'F' || ligne[i * 4 + 1] == 'f' || ligne[i * 4
				+ 1] == 'A' || ligne[i * 4 + 1] == 'a')
		{
			std::string nom;
			s << i << ",0";
			nom = s.str();
			s.str("");
			placeArrivee(nom);
		}
	}

	for (int j = 0; j < nbRangs; j++)
	{
		entree.getline(ligne, MAX_LIGNE);

		for (int i = (j == nbRangs - 1 && (j & 1)) ? 1 : 0; i < nbCols; i++)
		{
			if (j & 1)
			{
				if (j < nbRangs - 2 && ligne[i * 4 + 3] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 2);
				}
				if (j < nbRangs - 1 && ligne[i * 4 + 2] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 1);
				}
				if (j < nbRangs - 1 && ligne[i * 4 + 0] == ' ')
				{
					ajoutePassage(couleur, i - 1, j, i, j + 1);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 1] == 'D' || ligne[i * 4
						+ 1] == 'd'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeDepart(nom);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 1] == 'F' || ligne[i * 4
						+ 1] == 'f' || ligne[i * 4 + 1] == 'A' || ligne[i * 4
						+ 1] == 'a'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeArrivee(nom);
				}
			}
			else
			{
				if (j < nbRangs - 1 && ligne[i * 4 + 0] == ' ')
				{
					ajoutePassage(couleur, i - 1, j + 1, i, j);
				}
				if (j < nbRangs - 2 && ligne[i * 4 + 1] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 2);
				}
				if (j < nbRangs - 1 && ligne[i * 4 + 2] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 1);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 3] == 'D' || ligne[i * 4
						+ 3] == 'd'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeDepart(nom);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 3] == 'F' || ligne[i * 4
						+ 3] == 'f' || ligne[i * 4 + 3] == 'A' || ligne[i * 4
						+ 3] == 'a'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeArrivee(nom);
				}
			}
		}
	}
 }

/**
 * \fn	Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
 * \param[in]	Couleur couleur Couleur de la porte à ajouter
 * \param[in]	int i1
 * \param[in]	int j1
 * \param[in]	int i2
 * \param[in]	int j2
 */
 void Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
 {

	NoeudListePieces *piece1, *piece2;
	string nomPiece1, nomPiece2;
	ostringstream s;

	s << i1 << "," << j1;
	nomPiece1 = s.str();

	s.str("");

	s << i2 << "," << j2;
	nomPiece2 = s.str();

	s.str("");

	piece1 = trouvePiece(nomPiece1);
	piece2 = trouvePiece(nomPiece2);

	Porte nouvellePorte(couleur, &(piece2->piece));


    //std::cout<<"La piece : "<<piece1->piece.getNom()<<std::endl;
	piece1->piece.ajoutePorte(nouvellePorte);
 }


/**
 * \fn	Labyrinthe::ajoutePieceLabyrinthe(Piece& p)
 * \brief ajoute une pièce au labyrinthe (si elle ne s'y trouve pas déjà)
 * \param[in]	p La pièce à ajouter
 * \post	la pièce appartient au labyrinthe;
 */

 void Labyrinthe::ajoutePieceLabyrinthe(const Piece& p) {

    if (appartient(p)) return;
	else
	{	Labyrinthe::NoeudListePieces* noeud = new Labyrinthe::NoeudListePieces;
        noeud->piece = p;

        if (dernier == 0)
        {	noeud->suivant = noeud;
            dernier = noeud;
        }
        else
		{	noeud->suivant = dernier->suivant;
            dernier->suivant = noeud;
        }
	}
 }

// -------------------------------
//	Autres méthodes à implémenter
// -------------------------------

    /**
   * \fn int Labyrinthe::solutionner(Couleur joueur)
   * \brief Solutionne le labyrinthe pour un joueur donné.
   * \param joueur La couleur du joueur.
   * \return Le nombre minimum d'étapes nécessaires pour solutionner le labyrinthe.
   *
   * Cette méthode utilise l'algorithme de recherche en largeur (BFS) pour trouver le nombre minimum d'étapes
   * nécessaires pour qu'un joueur solutionne le labyrinthe en ne passant que par les portes de sa couleur.
   * Si le labyrinthe ne peut pas être solutionné par le joueur, la méthode retourne -1.
   */
    int Labyrinthe::solutionner(Couleur joueur){
        NoeudListePieces* sentinelle = dernier;
        if (sentinelle == nullptr) {
            return -1;
        }

        do {
            sentinelle->piece.setParcourue(false);
            sentinelle = sentinelle->suivant;
        } while (sentinelle != dernier);

        std::queue<std::pair<Piece*, int>> file;
        file.push(std::make_pair(depart, 0));

        while (!file.empty()) {
            Piece* currentPiece = file.front().first;
            int currentDistance = file.front().second;

            file.pop();
            currentPiece->setParcourue(true);

            if (currentPiece == arrivee) {
                return currentDistance;
            }

            const std::list<Porte>& portes = currentPiece->getPortes();
            for (const Porte& porte : portes) {
                if (porte.getCouleur() == joueur && !porte.getDestination()->getParcourue()) {
                    file.push(std::make_pair(porte.getDestination(), currentDistance + 1));
                }
            }

            sentinelle = dernier;
            do {
                const std::list<Porte>& portesAutrePiece = sentinelle->piece.getPortes();
                for (const Porte& porte : portesAutrePiece) {
                    if (porte.getCouleur() == joueur && porte.getDestination() == currentPiece && !sentinelle->piece.getParcourue()) {
                        file.push(std::make_pair(&(sentinelle->piece), currentDistance + 1));
                    }
                }
                sentinelle = sentinelle->suivant;
            } while (sentinelle != dernier);
        }
        return -1;
    }


    /**
    * \fn Couleur Labyrinthe::trouveGagnant()
    * \brief Trouve le joueur gagnant qui peut solutionner le labyrinthe en moins d'étapes.
    * \return La couleur du joueur gagnant.
    *
    * Cette méthode appelle la méthode solutionner() pour chaque couleur de joueur et détermine quel joueur
    * peut solutionner le labyrinthe en le moins d'étapes. En cas d'égalité, la priorité est donnée dans l'ordre
    * à Rouge, Vert, Bleu, puis Jaune.
    */
    Couleur Labyrinthe::trouveGagnant() {
        const Couleur couleurs[] = {Jaune, Bleu, Vert, Rouge};//make sure it is in the order
        int minDistance = -1;
        Couleur gagnant = Aucun;

        for (int i = 0; i < 4; i++) {
            int distance = solutionner(couleurs[i]);

            if (distance >= 0 && (minDistance == -1 || distance <= minDistance)) {
                minDistance = distance;
                gagnant = couleurs[i];
            }
        }

        return gagnant;
    }

    /**
    * \fn bool Labyrinthe::appartient(const Piece& p) const
    * \brief Vérifie si une pièce donnée appartient au labyrinthe.
    * \param p La pièce à vérifier.
    * \return true si la pièce appartient au labyrinthe, sinon false.
    */
    bool Labyrinthe::appartient(const Piece& p) const {
        Labyrinthe::NoeudListePieces* sentinelle = dernier;
        if (sentinelle == nullptr)
            return false;
        do{
            if (sentinelle->piece.getNom() == p.getNom()){
                return true;
            }
            sentinelle = sentinelle->suivant;
        }while (sentinelle != dernier);
            return false;
    }

    /**
     * \fn void Labyrinthe::placeDepart(const std::string& nom)
     * \brief Place la pièce de départ du labyrinthe.
     * \param nom Le nom de la pièce de départ.
     *
     * Cette méthode place la pièce de départ du labyrinthe en utilisant son nom.
     */
    void Labyrinthe::placeDepart(const std::string& nom) {
        Labyrinthe::NoeudListePieces* sentinelle = trouvePiece(nom);
        depart = &(sentinelle->piece);
 }

    /**
     * \fn void Labyrinthe::placeArrivee(const std::string& nom)
     * \brief Place la pièce d'arrivée du labyrinthe.
     * \param nom Le nom de la pièce d'arrivée.
     *
     * Cette méthode place la pièce d'arrivée du labyrinthe en utilisant son nom.
     */
    void Labyrinthe::placeArrivee(const std::string& nom) {
        Labyrinthe::NoeudListePieces* sentinelle = trouvePiece(nom);
        arrivee = &(sentinelle->piece);
 }


    /**
        * \fn Labyrinthe::NoeudListePieces* Labyrinthe::trouvePiece(const std::string& nom) const
        * \brief Trouve le noeud de la liste de pièces correspondant à un nom de pièce donné.
        * \param nom Le nom de la pièce à rechercher.
        * \return Un pointeur vers le noeud correspondant à la pièce.
        *
        * Cette méthode recherche le noeud de la liste de pièces correspondant au nom de pièce fourni.
        * Elle lance une exception en cas d'erreur (pièce introuvable, nom vide, labyrinthe vide).
        */
    Labyrinthe::NoeudListePieces* Labyrinthe::trouvePiece(const std::string& nom) const {
        Labyrinthe::NoeudListePieces* sentinelle = dernier;
        if (sentinelle == nullptr)
            throw std::logic_error("Labyrinthe::trouvePiece: Labyrinthe est vide");
        if (nom == "")
            throw std::invalid_argument("Labyrinthe::trouvePiece: Le nom est vide");
        do {
            if (sentinelle->piece.getNom() == nom){
                    return sentinelle;
            }
            sentinelle = sentinelle->suivant;
        }while (sentinelle != dernier);

        throw std::logic_error("Labyrinthe::trouvePiece: La piece est introuvable");
    }
 }//fin du namespace
