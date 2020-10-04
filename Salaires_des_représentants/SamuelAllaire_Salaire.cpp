// But : Développez un programme qui entre les ventes brutes hebdomadaires de chaque représentant et qui calcule et
// affiche son salaire. Entrez - 1 à la valeur des ventes pour quitter le programme.
// Auteur : Samuel Allaire
// Date : 2020-10-04

#include <iostream> // Pour communiquer avec l'utilisateur.

using namespace std; // Pour éviter d'écrire std:: dans les instructions comme cout, cin, endl, ...			

int main() // Porte d'entrée du programme.
{
	setlocale(LC_ALL, ""); // Pour afficher correctement les accents dans la console.

	// Déclaration des variables.
	// Les informations fournis par l'utilisateur.
	float venteBrute; // Le total des ventes brutes de l'utilisateur pour une semaine.

	// Le résultat affiché par le programme.
	float salaireTotale; // Salaire totale d'un utilisateur pour une semaine.

	// Le programme demande à l'utilisateur d'entrer la somme de ses ventes brutes à chaque semaine, ou -1 pour quitter le programme.
	cout << "Veuillez entrer la somme de vos ventes brutes (ou -1 pour quitter) : ";
	cin >> venteBrute; // L'utilisateur entre le total de ses ventes brutes pour la semaine.


	// Si l'utilisateur entre -1, le programme se ferme.
	while (venteBrute != -1)
	{
		while (!(venteBrute >= 0) && venteBrute != -1) // Si le total entré est plus petit que 0, le programme affiche une erreur et demande à l'utilisateur d'entrer une autre valeur.
		{
			cout << "Erreur : la somme des ventes brutes pour une semaine doit etre positif. ";
			system("pause"); // Le programme affiche l'erreur jusqu'à ce que l'utilisateur veut continuer.

			// Le programme efface l'écran cls (clear screen) pour afficher de nouveau la question à l'utilisateur.
			system("cls");

			// Le programme re-demande a l'utilisateur d'entrer la somme de ses ventes brutes à chaque semaine.
			cout << "Veuillez entrer la somme de vos ventes brutes (ou -1 pour quitter) : ";
			cin >> venteBrute;
		}
		while (venteBrute >= 0 && venteBrute != -1) // Si le total entré est plus grand que 0, le programme calcul le salaire totale pour une semaine.
		{
			// Calcul du salaire totale pour une semaine.
			float pourcentageVentebrute = (venteBrute * 7.5 / 100);  // Calcul de la valeur du pourcentage à ajouter au salaire totale. (7.5%)
			salaireTotale = pourcentageVentebrute + 250; // Calcul du salaire total.
			cout << "Votre salaire pour cette semaine est de : " << salaireTotale << "$" << endl; // Le programme affiche à l'utilisateur son salaire totale pour la semaine. 

			// Le programme re-demande a l'utilisateur d'entrer la somme de ses ventes brutes a chaque semaine tant que l'utilisateur n'entre pas -1.
			cout << "Veuillez entrer la somme de vos ventes brutes (ou -1 pour quitter) : ";
			cin >> venteBrute;
		}
	}
	return 0;
}


/*
Fiche des tests:
Vente Brute:	Le programme affiche:
-1				(Le programme se ferme)
25				251.875$	
-25				Erreur : la somme des ventes brutes pour une semaine doit etre positif.
0				250$
750.1			306.258$
-750.1			Erreur : la somme des ventes brutes pour une semaine doit etre positif.
ABC				Erreur : la somme des ventes brutes pour une semaine doit etre positif.
*/