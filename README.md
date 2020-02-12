# automatic_assignations

L'outil d'assignation automatique pour les Asteks !

## Compilation
```C
mkdir build && cd build/
cmake ..
make
```

## Utilisation

```
./automatic_assignation Astek Planning Disponibilités Preferences Aeviter AssignAllDay
```

### Astek

C'est un fichier comportant la liste de tous les Asteks ainsi que leur nombre de jours par semaine de travail.

```
$> cat LabAstek
Toto 2
Tata 3
Titi 3
```

### Planning

C'est un fichier ou chaque ligne correspond a une demie journée d'activité. Chaque ligne est composée de :
```
[Type d'activité] [Projet] [Module] [Jour] [Mois] [AM ou PM] [Nombre d'Astek] [Salle]
```

Exemple : 
```
BS my_ls PSU Tue Feb AM 4 SM24
```
#### Activités
Les valeurs possibles sont :
- BS -> Bootstrap
- FU -> Follow-up
- REVIEW
- CR -> Code Review
- TAM
- PISCINE
- STUMPER

#### Modules
Les valeurs possibles sont :
- PSU
- SHELL
- CPE
- CORE
- MAT
- MUL
- AIA
- SAD
- SYS
- ALL

#### Jours
Il faut prendre les 3 premières lettres du jour en anglais.
```
Monday -> Mon
Tuesday -> Tue
...
```

#### Salles
Les valeurs possibles sont :
- SM20
- SM21
- SM22
- SM23
- SM24
- SM25
- 501
- 502

### Disponibilités

C'est le csv exporté du google form. Il faut enlever la première colonne contenant l'horodatage

### Préférences

Fichier contenant les modules préférés pour chaque Astek

```
$> cat Preferences
Toto:PSU,MUL
Tata:MAT
Titi:CPE,CORE,SHELL
```

### A Eviter

Fichier sous le même format que les préférences.

### Assign All Day

C'est un booléen (true ou false) qui définit si les Astek quand ils sont assignés une demie journée sur une activité
