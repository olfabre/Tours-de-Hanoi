<h1>L2 Computer Science & Mathematics</h1>
<h2>Algorithmique avancée et programmation C++</h2>
<h3>Exercice: Tours-de-Hanoi</h3>
L'objectif de ce TP est d'implémenter un algorithme récursif montrant les mouvements à effectuer pour déplacer n disques du jeu "les tours de Hanoi". Le jeu est constitué de trois tiges où sont empilées des disques de diamétres différents. L'objectif est de déplacer les disques de la tige la plus à gauche vers celle la plus à droite selon les régles suivantes.

On ne peut déplacer qu'un disque à la fois.
On a accès, sur une tige, qu'au disque en haut de la pile.
On peut déplacer un disque (auquel on a accès) de n'importe quelle tige vers n'importe quelle autre mais il est interdit, au cours de ces déplacements, de poser un disque sur un autre plus petit.
L''algorithme est basé sur le fait que pour déplacer les n disques de la gauche vers la droite, on peut commencer par déplacer les n-1 disques les plus hauts de la tige de gauche vers la tige du milieu. Ensuite, on déplace le disque restant (le plus grand) de la tige gauche vers la tige destination. Enfin, il ne reste plus qu'à déplacer les n-1 disques de la tige du milieu vers la tige de droite. Ceci est illustré par la vidéo suivant,e pour 4 disques, conçue par Xavier  Foisse.
Si "deplacer(n, origine, milieu, destination)" désigne la méthode récursive chargée de trouver la séquence de déplacement de ndisques d'une tige "origine" vers une tige "destination", en utilisant une tige dite "milieu", alors son pseudo-code peut s'écrire comme suit :

_________________________________________________________________________________________________

deplacer(n, origine,milieu, destination)

{

Si (n == 1)

Déplacer l'unique disque se trouvant sur "origine" vers "destination"
Sinon

deplacer(n-1,origne,destination,milieu) // Permet de déplacer les n-1 disques du haut de la tige origine vers la tige milieu en utilisant comme tige intermédiaire la tige destination.
Déplacer le disque restant (le plus gros) de la tige "origine" vers la tige destination.
deplacer(n-1,milieu,origine,destination) // Permet de déplacer les n-1 disques de la tige du milieu vers la tige destination en utilisant comme tige intermédiaire la tige origine.
FinSi

}

_________________________________________________________________________________________________

Pour coder en C++ cet algorithme, il nous faut opter pour une structure de données représentant les piles de disques sur chaque tige. Nous utiliserons pour cela la classe de librairie STL "stack" (voir note introduction à la librairie STL du cours). Le contenu de chaque tige sera donc représenté par une pile de nombres entiers. S'il y a n disques, ils seront numérotés par ordre croissant des tailles : 1,2,...,n (1 désignant le disque le plus petit, et n le disque le plus grand). On définit, grâce à cette classe, le tableau Pile  Tiges[3] représentant les piles de disques se trouvant sur chaque tige. Les tiges sont numérotées 0,1,2. "Tiges" sera l'attribut d'une classe "hanoi" décrite dans le fichier "hanoi.h". Celle-ci contiendra les méthodes permettant de trouver les mouvements à effectuer pour un nombre quelconque de disques. Notez que , par rapport aux explications précédentes, la méthode récursive à coder s'appelle "deplacer(n, gauche,milieu, droite)".

Vous devez implémenter les méthodes de cette classe. Vous pouvez rajouter des méthodes dans "hanoi.h" mais celles déjà écrites doivent être maintenues. Les commentaires données vous indiquent ce que les méthodes sont supposées faire.

Pour tester, vous pouvez comme d'habitude cliquer sur "run". Le main fournit lira alors un fichier d'entrée contenant le nombre de disques, et le système comparera les sorties avec un fichier de sortie contenant l'état des tiges à chaque itération de votre algorithme. Si votre algorithme fonctionne correctement, pour n=3, la méthode "mouvement(3)" devrait ainsi afficher :

Tiges[0] : 3 2 1
Tiges[1] :
Tiges[2] :
---------------------------
Tiges[0] : 3 2
Tiges[1] :
Tiges[2] : 1
---------------------------
Tiges[0] : 3
Tiges[1] : 2
Tiges[2] : 1
---------------------------
Tiges[0] : 3
Tiges[1] : 2 1
Tiges[2] :
---------------------------
Tiges[0] :
Tiges[1] : 2 1
Tiges[2] : 3
---------------------------
Tiges[0] : 1
Tiges[1] : 2
Tiges[2] : 3
---------------------------
Tiges[0] : 1
Tiges[1] :
Tiges[2] : 3 2
---------------------------
Tiges[0] :
Tiges[1] :
Tiges[2] : 3 2 1
---------------------------

L'évaluation du code se fait sur le même principe sauf qu'il est testé automatiquement pour n=3,4,5,6 disques.
