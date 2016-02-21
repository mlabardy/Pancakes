SRC = src/
INCL = include/
inc = -I./include

PROJECT = main.o list.o rank.o

TARGET = list

CFLAGS = -Wall -ansi -pedantic


CC = gcc

all: $(TARGET)

$(TARGET) : $(PROJECT)
	@echo "Création de l'exécutable -> $@"
	@$(CC) $(PROJECT) $(LDLIBS) -o $@ $(LDFLAGS)

main.o : $(SRC)main.c $(INCL)list.h $(INCL)rank.h
	@echo "Création de l'objet $@"
	@$(CC) $(CFLAGS) $(inc) -c $< -o $@

list.o : $(SRC)list.c $(INCL)list.h
	@echo "Création de l'objet $@"
	@$(CC) $(CFLAGS) $(inc) -c $< -o $@

rank.o : $(SRC)rank.c $(INCL)rank.h $(INCL)list.h
	@echo "Création de l'objet $@"
	@$(CC) $(CFLAGS) $(inc) -c $< -o $@


clean :
	@echo "Suppression des fichiers objets : "
	rm -f *.o

mrproper : clean
	rm -f $(TARGET)
	
