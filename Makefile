# Compilador
CC = gcc

# Flags del compilador
CFLAGS = -Wall -Wextra -Iincludes

# Directorios
SRC_DIR = src
INC_DIR = includes
OBJ_DIR = obj

# Archivos
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
TARGET = main

# Regla por defecto
all: $(TARGET)

# Linkeo final
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compilar .c a .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Crear directorio obj si no existe
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpiar compilados
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Limpiar y recompilar
re: clean all
