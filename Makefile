# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: theog <theog@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 02:18:59 by theog             #+#    #+#              #
#    Updated: 2024/12/05 02:19:09 by theog            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du compilateur
CC = cc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror -pthread -I includes -fsanitize=thread

# Dossiers
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = includes

# Fichiers source et objets
SRC_NAMES = alone_philo.c check.c close.c eating.c ft_atoi.c init.c main.c \
            message.c mutex_utils.c philo.c time.c
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC_NAMES))
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Nom de l'exécutable
NAME = philo

# Règle principale
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Création du dossier obj s'il n'existe pas
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

# Reconstruire tout
re: fclean all

.PHONY: all clean fclean re
