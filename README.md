# get_next_line

*Ce projet a été réalisé dans le cadre du cursus de l'école 42.*

## Description

**get_next_line** est une fonction qui permet de lire un fichier **ligne par ligne** à partir d'un descripteur de fichier. À chaque appel, elle retourne la ligne suivante, terminée par `\n` (sauf pour la dernière ligne si elle n'en contient pas). Elle fonctionne aussi bien sur un fichier que sur l'entrée standard.

L'objectif est de comprendre le fonctionnement des variables statiques, de la lecture de fichiers avec `read` et de la gestion de la mémoire dynamique.

## Prototype

```c
char *get_next_line(int fd);
```

La fonction retourne **la ligne lue** (avec le `\n` final), ou `NULL` à la fin du fichier ou en cas d'erreur.

## Fonctionnement

| Étape | Description |
|-------|-------------|
| Lecture | Lit `BUFFER_SIZE` octets à la fois avec `read` |
| Stockage | Conserve les données lues dans une variable statique |
| Extraction | Retourne la ligne dès qu'un `\n` est trouvé |
| Reste | Garde le surplus lu pour l'appel suivant |
| Fin | Libère la mémoire et retourne `NULL` à la fin du fichier |

## Fonctions autorisées

| Fonction | Rôle |
|----------|------|
| `read` | Lit les données depuis le descripteur de fichier |
| `malloc` | Alloue la mémoire |
| `free` | Libère la mémoire |

## Compilation

La taille du buffer se définit à la compilation avec l'option `-D BUFFER_SIZE=n` :

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o programme
```

## Utilisation

Inclure le header et appeler la fonction en boucle jusqu'à obtenir `NULL` :

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}
```

```bash
./programme
```

## Normes

- Respect de la **Norme** de 42
- Compilation avec `-Wall -Wextra -Werror`
- Aucune fuite mémoire
- Utilisation d'une seule variable statique

## Auteur

@prsadamm
