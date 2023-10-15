# So Long
Et merci pour le poisson !

**Résumé:**
Ce projet est un jeu 2D simple conçu pour vous faire utiliser des textures, des sprites et quelques éléments basiques de gameplay.

**Version:** 3

## Table des matières
1. Introduction
2. Objectifs
3. Règles communes
4. Partie obligatoire
   4.1 Le jeu
   4.2 Gestion graphique
   4.3 La carte
5. Partie bonus
6. Exemples
7. Rendu et peer-évaluation

## Chapitre I - Introduction

Être dev, c’est super pour créer son propre jeu. Cependant, un bon jeu nécessite de bonnes ressources. Afin de créer des jeux 2D, vous devrez rechercher des tiles, tilesets, des sprites et des sprite sheets. Fort heureusement, des artistes de talent partagent leur travail sur des plateformes telles que :
- [itch.io](https://itch.io/)

Bien entendu, veuillez respecter le travail d’autrui.

## Chapitre II - Objectifs

Il est temps pour vous d’attaquer votre premier projet graphique ! "So Long" vous donnera des bases dans les compétences suivantes : gestion de fenêtre, gestion des événements, choix de couleurs et de textures. Vous allez maintenant prendre en main la bibliothèque graphique de l’école : la MiniLibX ! Cette bibliothèque a été développée en interne et inclut des outils basiques permettant d’ouvrir une fenêtre, de créer des images et de gérer des événements clavier et souris. Les objectifs de ce projet sont similaires à tous ceux de votre première année : faire preuve de rigueur, vous améliorer en programmation C, utiliser des algorithmes basiques, chercher des informations en autonomie, etc.

## Chapitre IV - Partie obligatoire

**Nom du programme:** so_long

**Fichiers de rendu:** Makefile, *.h, *.c, quelques cartes, textures

### 4.1 Le jeu

- Le but du joueur est de collecter tous les items présents sur la carte, puis de s’échapper en empruntant le chemin le plus court possible.
- Les touches W, A, S et D doivent être utilisées afin de mouvoir le personnage principal.
- Le joueur doit être capable de se déplacer dans ces 4 directions : haut, bas, gauche, droite.
- Le joueur ne doit pas pouvoir se déplacer dans les murs.
- À chaque mouvement, le compte total de mouvement doit être affiché dans le shell.
- Vous devez utiliser une vue 2D (vue de haut ou de profil).
- Le jeu n’a pas à être en temps réel.
- Bien que les exemples donnés montrent un thème dauphin, vous êtes libre de créer l’univers que vous voulez.

### 4.2 Gestion graphique

- Votre programme doit afficher une image dans une fenêtre.
- La gestion de la fenêtre doit rester fluide (changer de fenêtre, la réduire, etc.).
- Appuyer sur la touche ESC doit fermer la fenêtre et quitter le programme proprement.
- Cliquer sur la croix en haut de la fenêtre doit fermer celle-ci et quitter le programme proprement.
- Utiliser les images de la MiniLibX est obligatoire.

### 4.3 La carte

- La carte sera construite en utilisant 3 éléments : les murs, les items à collecter, et l’espace vide.
- Votre carte peut être composée de ces 5 caractères :
  - 0 pour un emplacement vide,
  - 1 pour un mur,
  - C pour un item à collecter (C pour collectible),
  - E pour une sortie (E pour exit),
  - P pour la position de départ du personnage.

**Exemple de carte basique:**
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111

markdown
Copy code

- La carte doit contenir 1 sortie, au moins 1 item et 1 position de départ. Si la map contient des doublons, vous devez afficher un message d’erreur.
- La carte doit être de forme rectangulaire.
- La carte doit être fermée en étant encadrée par des murs. Si ce n’est pas le cas, le programme retourne une erreur.
- Vous devez vérifier s’il existe un chemin valide (i.e. qu’il est possible d’emprunter) dans la carte.
- Vous devez pouvoir parser tout type de carte du moment qu’elle respecte les règles énoncées ci-dessus.

**Un autre exemple de carte .ber basique:**
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111

Si une erreur de configuration est détectée, le programme doit quitter proprement et retourner "Error\n" suivi d’un message d’erreur explicite de votre choix.
## Compilation et Exécution
-make (Cela vous permettra de compiler et d'exécuter votre jeu en suivant les instructions fournies)
-make re recompilation
- ./so_long [fichier de carte]

