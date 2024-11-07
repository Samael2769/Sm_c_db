# Nom de l'exécutable
NAME = sm_db

# Compilateur et options
CC = gcc
CFLAGS = 

# Dossiers des fichiers d'en-tête et sources
INCLUDES = -I includes
SRCDIR = sources/

# Recherche automatique des fichiers sources dans le dossier sources/
SRCS = $(wildcard $(SRCDIR)*.c)

# Objets correspondants aux fichiers sources
OBJS = $(SRCS:.c=.o)

# Commande pour générer l'exécutable
all: $(NAME)

# Compilation des objets et lien final pour créer l'exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Compilation des fichiers objets avec l'inclusion des headers
$(SRCDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: all
	bundle exec rspec

# Règle pour nettoyer les fichiers objets (.o)
clean:
	rm -f $(OBJS)

# Règle pour nettoyer les fichiers objets et l'exécutable
fclean: clean
	rm -f $(NAME)

# Règle pour recompiler tout
re: fclean all

# Indique à make que ces règles ne sont pas des fichiers
.PHONY: all clean fclean re
