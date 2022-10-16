#include<iostream>
#include <stack>

using namespace std;

#include"hanoi.h"


/* Constructeur de la classe */
hanoi::hanoi(int n)
{
    // Remplir initialement la tige indicé 0
    for (int Disque=n; Disque > 0;  Disque--){

            // Remplissage du disque le plus grand au plus petit disque sur la tige la plus à gauche
            Tiges[0].push(Disque);
    }

}


void hanoi::etat()
{
// Affiche l'état (le contenu) des tours sous la forme suivante.

/* 
Tiges[0] : numéros, séparés par des espaces, des disques s'y trouvant
Le numéro le plus à gauche correspondra au disque le plus bas.
Tiges[1] : idem
Tiges[2] : idem
---------------------------
 */ 

for (int i=0; i < 3; i++){
int sizeContenuTiges= Tiges[i].size();
int T[sizeContenuTiges];

cout << "Tiges[" << i << "] : "; 

    // Depilage et affectation tableau
    for (int lecture=sizeContenuTiges-1; lecture > -1; lecture--){

            T[lecture] = Tiges[i].top();
            //cout << "T[" << lecture << "]:" << T[lecture];
            Tiges[i].pop();
    }
    // Affichage
      for (int j=0; j < sizeContenuTiges; j++){

        (j < (sizeContenuTiges-1)) ? cout << T[j] << " ": cout << T[j];
           
    }  
   
   // Empilage sur la pile à partir du tableau
    for (int j=0; j < sizeContenuTiges; j++){

        Tiges[i].push(T[j]);
           
    }  




cout << endl;


        } // fin boucle for

cout << "--------------------------" << endl;
} // Fin method Hanoi

void hanoi::mouvements(int n)
{
// Calcul et affichage de tous les mouvements de disques à effectuer.  Les mouvements seront affichés grâce à
// la méthode "etat().
// Par exemple, avec 3 disques, initialement l'état est :
/*
Tiges[0] : 3 2 1
Tiges[1] :
Tiges[2] :
---------------------------
*/ 
// Si le disque 1 est déplacé vers la tige 1 alors le nouvel état est :
/*
Tiges[0] : 3 2
Tiges[1] :
Tiges[2] : 1
---------------------------
*/


//Les deux mouvements successifs seront donc affichés
/*
Tiges[0] : 3 2 1
Tiges[1] :
Tiges[2] :
---------------------------
Tiges[0] : 3 2
Tiges[1] :
Tiges[2] : 1
---------------------------
*/

// Appel de la fonction deplacer 
deplacer(n, 0, 1, 2);
}

void hanoi::deplacer(int n, int gauche, int milieu, int droite)
{
    if (n==1)
    {
        // 
        // Déplacer l'unique disque se trouvant sur "origine" vers "destination"
        Tiges[droite].push(Tiges[gauche].top());
        Tiges[gauche].pop();
        // Affichage etat
        etat();
    }
    else
    {
        // Permet de déplacer les n-1 disques du haut de la tige origine vers la tige milieu en utilisant comme tige intermédiaire la tige destination.
        deplacer(n-1,gauche,droite,milieu);

        // Déplacer le disque restant (le plus gros) de la tige "origine" vers la tige destination.
        deplacer(1,gauche,milieu,droite);

        // Permet de déplacer les n-1 disques de la tige du milieu vers la tige destination en utilisant comme tige intermédiaire la tige origine.
        deplacer(n-1,milieu,gauche,droite);

    }
}