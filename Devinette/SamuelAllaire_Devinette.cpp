/*
Complétez un programme pour qu’il donne la possibilité à l’utilisateur de deviner le nombre contenu dans iRandom.
L’utilisateur a un maximum de 5 chances.Le programme vérifie que l’utilisateur a bien entré un nombre entre 0 et
100 et lui indique s’il gagne ou dans le cas contraire lui indique le nombre d’essais restant et lui redemande un
nombre.
*/
// Auteur : Samuel Allaire
// Date : 2020-10-04

#include <iostream> // Pour communiquer avec l'utilisateur.
#include <time.h> // Pour ajouter la variable iRandom.

using namespace std; // Pour éviter d'écrire std:: dans les instructions comme cout, cin, endl, ...			

int main() // Porte d'entrée du programme.
{
	setlocale(LC_ALL, ""); // Pour afficher correctement les accents dans la console.

	// Déclaration des variables.
	int iRandom; // Permet de mémoriser le nombre choisi aléatoirement par l’ordinateur
	int choix; // Le nombre que l'utilisateur devine. 
	int nombreChances = 5; // Le nombre de chances restant a l'utilisateur.

	// Le programme calcule un nombre aléatoire.
	srand(time(0)); // Pour activer l’aléatoire dans le programme.
	iRandom = 1; //rand() % 101; // L’ordinateur calcule un nombre aléatoire entre 0 et 100 et le stocke dans iRandom

	// Le programme demande a l'utilisateur d'entrer un nombre de 0 à 100. 
	cout << "Veuillez entrer le nombre que vous pensez être le chiffre aléatoire (0 à 100), vous avez : " << nombreChances << " chances! : " << endl;
	cin >> choix; // L'utilisateur entre son choix.

	// Tant que le choix est entre 0 et 100.
	while (choix >= 0 && choix <= 100)
	{
		if (choix != iRandom) // Si le choix n'est pas le même qu'iRandom 
		{
			nombreChances = nombreChances--; // Le nombre de chances est réduit de 1.

			// Le programme demande a l'utilisateur d'entrer un autre nombre.
			cout << "Vous n'avez pas choisis le bon chiffre! Veuillez entrer le nombre que vous pensez être le chiffre aléatoire (0 à 100), vous avez : " << nombreChances << " chances! : " << endl;
			cin >> choix; // L'utilisateur entre son choix.
			if (nombreChances == 0) // Si l'utilisateur atteint 0 chances
			{
				// Le programme affiche a l'utilisateur qu'il a perdu.
				cout << "Vous avez perdu! Le nombre était : " << iRandom << endl;
				system("pause"); // Le programme affiche l'erreur jusqu'à ce que l'utilisateur veut continuer.

				// Le programme efface l'écran cls (clear screen) pour afficher de nouveau la question à l'utilisateur.
				system("cls");

				// Le nombre de chances re-devient 5.
				nombreChances = 5;
				iRandom = rand() % 101; // Le nombre change.

				// Le programme re-demande a l'utilisateur d'entrer un nombre de 0 à 100. 
				cout << "Veuillez entrer le nombre que vous pensez être le chiffre aléatoire (0 à 100), vous avez : " << nombreChances << " chances! : " << endl;
				cin >> choix; // L'utilisateur entre son choix.
			}
		}
		else
		{
			// Si l'utilisateur choisis le bon nombre, le programme affiche qu'il a gagné,
			cout << "Vous avez gagné! Le nombre était : " << iRandom << endl;
			system("pause"); // Le programme affiche l'erreur jusqu'à ce que l'utilisateur veut continuer.

			return 0; // Le programme se ferme.
		}
	}
	cout << "Le nombre doit etre entre 0 et 100! "; // Si l'utilisateur entre une valeur qui n'est pas entre 0 et 100, le programme se ferme.
	system("pause"); // Le programme affiche l'erreur jusqu'à ce que l'utilisateur veut continuer.
	system("cls"); // Le programme efface l'écran cls (clear screen) pour afficher de nouveau la question à l'utilisateur.
	
	return 0;
}


/*
Fiche des tests:
Choix:				Le programme affiche:
-1					Le nombre doit etre entre 0 et 100!
5 choix mauvais		Vous avez perdu!
1 bon choix         Vous avez gagné!
*/
