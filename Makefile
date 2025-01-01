
CC = gcc
CFLAGS = -Wall -g


ARRAYLIST_DIR = lists/ArrayList
DLINKLIST_DIR = lists/DoubleLinkedList


all: arraylist_program dlinklist_program

arraylist_program: $(ARRAYLIST_DIR)/main.o $(ARRAYLIST_DIR)/arraylist.o
	$(CC) $^ -o $@ $(CFLAGS)

$(ARRAYLIST_DIR)/main.o: $(ARRAYLIST_DIR)/main.c $(ARRAYLIST_DIR)/arraylist.h
	$(CC) $(CFLAGS) -c $< -o $@

$(ARRAYLIST_DIR)/arraylist.o: $(ARRAYLIST_DIR)/arraylist.c $(ARRAYLIST_DIR)/arraylist.h
	$(CC) $(CFLAGS) -c $< -o $@


dlinklist_program: $(DLINKLIST_DIR)/main.o $(DLINKLIST_DIR)/doublelinkedlist.o
	$(CC) $^ -o $@ $(CFLAGS)

$(DLINKLIST_DIR)/main.o: $(DLINKLIST_DIR)/main.c $(DLINKLIST_DIR)/doublelinkedlist.h
	$(CC) $(CFLAGS) -c $< -o $@

$(DLINKLIST_DIR)/doublelinkedlist.o: $(DLINKLIST_DIR)/doublelinkedlist.c $(DLINKLIST_DIR)/doublelinkedlist.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(ARRAYLIST_DIR)/*.o $(DLINKLIST_DIR)/*.o arraylist_program dlinklist_program
