### Quentin DUNAND et Elsa NAVARRO

# Projet CPS Dictionnaire
#####Réalisation d'un dictionnaire à partir des mots composant un texte quelconque, écrit en minuscules, sans accent et sans caractères spéciaux.

##Compilation et utilisation
###Compilation
Pour compiler le programme, il suffit de se rendre dans le dossier src, d'ouvrir un terminal et d’exécuter la commande make qui va généré un exécutable nommé "main".

###Utilisation
Pour lancer le programme, utilisez le de la façon suivante :
```
./main [nom_de_fichier]
```
Par exemple :
```
./main ../Examples/moyen_dico.txt
```

[nom_de_fichier] correspond au nom du fichier dont l'utilisateur souhaite connaître le dictionnaire.

Si aucun nom de fichier n'est saisi, l'utilisateur devra alors lui même taper le texte dont il veut connaître le dictionnaire, c'est le mode  "saisie de texte manuelle".

Exemple :
```
quentin@quentin-K72Jr:~/Documents/polytech/CPS/Projet/Projet_Dict/src$ ./main
salut comment ca va ? tres bien et vous ? ca va merci.
**************
Dictionnaire :
**************
bien (1, 28)
ca (1, 15) (1, 43)
comment (1, 7)
et (1, 33)
merci (1, 49)
salut (1, 1)
tres (1, 23)
va (1, 18) (1, 46)
vous (1, 36)
*******************************************
Fin du Dictionnaire, nombre de mots : 11
*******************************************
```

####Remarque :
1.	Le makefile est actuellement fait pour les systèmes Linux 64 bits, il est nécessaire de modifier le flag FLAGSSO de celui-ci afin de le rendre compatible avec votre système.
2.	Si vous optez pour l'utilisation de l'outil en mode "saisie de texte manuelle", il est nécessaire de terminer votre saisie par un appui sur la touche Entrée de votre clavier puis par la combinaison Ctrl + D pour les systèmes Linux (un équivalent de Ctrl + D doit exister pour les systèmes Mac OS)
