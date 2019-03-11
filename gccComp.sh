#!/bin/bash

#On vérifie la validité du fichier : si plusieurs arguments : erreur, si 1 un argument : on vérifie que c'est un cpp 
if [ $# -ne 1 ] 
then 
	echo "Erreur dans le nombre d'argument passé"
else 
	FICHIER=$1
	EXT_FICHIER=${FICHIER##*.}
	if [ $EXT_FICHIER != "cpp" ] 
	then
		echo "Erreur dans l'extension du fichier"
	else
		# On lance l'exec avec le nom du fichier si tout est ok
		./exe fichierTest/$1
	fi
fi
