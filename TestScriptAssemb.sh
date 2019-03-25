# Lancer le script avec ce format: ./nomScript nomFichier.cpp {-a,-c,-o}
#On vérifie la validité du fichier : si plus de 4 ou moins de 1 parametres: erreur, si 1 un argument : on vérifie que c'est un cpp 
if [ $# -gt 4 ] || [ $# -lt 1 ] 
then 
	echo "Erreur dans le nombre d'argument passé"
else	#Nombre parametres correct, voir si le fichier est .c
	
	FICHIER=${@: -1}
	EXT_FICHIER=${FICHIER##*.}
	if [ $EXT_FICHIER != "c" ] 
	then
		echo "Erreur dans l'extension du fichier"
	else	#On regarde les options
		if [ $# -gt 1 ]
		then
			ANALYSE=0	#Initialiser variables a 0
			OPTIMISATION=0
			CODE_GEN=0
			argc=$#		# Nombre de parametres total
			argv=($@)	# Vecteur de parametres
			for (( j=0; j<argc-1; j++)); 
			do    			
				case ${argv[j]} in
				"-a") ANALYSE=1 ;;
				"-o") OPTIMISATION=1 ;;
				"-c") CODE_GEN=1 ;;
				esac
			done
		#Ici observation de parametres pour lancer le programme
			if [ $ANALYSE -eq 1 -a $OPTIMISATION -eq 0 -a $CODE_GEN -eq 0 ]; then 	# Que Analyse statique
				./exe -a test/$FICHIER
			elif [ $ANALYSE -eq 0 -a $OPTIMISATION -eq 1 -a $CODE_GEN -eq 0 ]; then 
				echo "OPTIMISATION"
			elif [ $ANALYSE -eq 0 -a $OPTIMISATION -eq 0 -a $CODE_GEN -eq 1 ]; then
			# 4 instructions sur les sujet
				./exe -c test/$FICHIER
				as -o main.o main.s
				gcc main.o
				./a.out
				echo $?
			elif [ $ANALYSE -eq 1 -a $OPTIMISATION -eq 1 -a $CODE_GEN -eq 0 ]; then
				./exe -a test/$FICHIER
				echo "OPTIMISATION"
			elif [ $ANALYSE -eq 1 -a $OPTIMISATION -eq 0 -a $CODE_GEN -eq 1 ]; then
				./exe -a -c test/$FICHIER
				as -o main.o main.s
				gcc main.o
				./a.out
				echo $?
			elif [ $ANALYSE -eq 0 -a $OPTIMISATION -eq 1 -a $CODE_GEN -eq 1 ]; then
				echo "OPTIMISATION"
				./exe -c test/$FICHIER
				as -o main.o main.s
				gcc main.o
				./a.out
				echo $?
			elif [ $ANALYSE -eq 1 -a $OPTIMISATION -eq 1 -a $CODE_GEN -eq 1 ]; then
				echo "OPTIMISATION"
				./exe -a -c test/$FICHIER
				as -o main.o main.s
				gcc main.o
				./a.out
				echo $?
			fi
		#---------------------------------------
		else
		# On lance l'exec avec le nom du fichier si tout est ok
		echo "./exe test/$1"
		fi
	fi
fi