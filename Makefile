
ifeq ($(OS),Windows_NT)
	DEL_CMD = del /Q /F
	PATH_SEP = \\
else
	DEL_CMD = rm -f
	PATH_SEP = /
endif


CC = gcc
CFLAGS = -Wall -g


ARRAYLIST_DIR = lists$(PATH_SEP)ArrayList
DLINKLIST_DIR = lists$(PATH_SEP)DoubleLinkedList


all: arraylist_program dlinklist_program sorts_program

arraylist_program: $(ARRAYLIST_DIR)$(PATH_SEP)main.o $(ARRAYLIST_DIR)$(PATH_SEP)arraylist.o
	$(CC) $^ -o $@ $(CFLAGS)

$(ARRAYLIST_DIR)$(PATH_SEP)main.o: $(ARRAYLIST_DIR)$(PATH_SEP)main.c $(ARRAYLIST_DIR)$(PATH_SEP)arraylist.h
	$(CC) $(CFLAGS) -c $< -o $@

$(ARRAYLIST_DIR)$(PATH_SEP)arraylist.o: $(ARRAYLIST_DIR)$(PATH_SEP)arraylist.c $(ARRAYLIST_DIR)$(PATH_SEP)arraylist.h
	$(CC) $(CFLAGS) -c $< -o $@


dlinklist_program: $(DLINKLIST_DIR)$(PATH_SEP)main.o $(DLINKLIST_DIR)$(PATH_SEP)doublelinkedlist.o
	$(CC) $^ -o $@ $(CFLAGS)

$(DLINKLIST_DIR)$(PATH_SEP)main.o: $(DLINKLIST_DIR)$(PATH_SEP)main.c $(DLINKLIST_DIR)$(PATH_SEP)doublelinkedlist.h
	$(CC) $(CFLAGS) -c $< -o $@

$(DLINKLIST_DIR)$(PATH_SEP)doublelinkedlist.o: $(DLINKLIST_DIR)$(PATH_SEP)doublelinkedlist.c $(DLINKLIST_DIR)$(PATH_SEP)doublelinkedlist.h
	$(CC) $(CFLAGS) -c $< -o $@


sorts_program: sorts$(PATH_SEP)main.o sorts$(PATH_SEP)sorts.o
	$(CC) $^ -o $@ $(CFLAGS)


sorts$(PATH_SEP)main.o: sorts$(PATH_SEP)main.c sorts$(PATH_SEP)sorts.h
	$(CC) $(CFLAGS) -c $< -o $@

sorts$(PATH_SEP)sorts.o: sorts$(PATH_SEP)sorts.c sorts$(PATH_SEP)sorts.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(DEL_CMD) "$(ARRAYLIST_DIR)$(PATH_SEP)*.o" 
	$(DEL_CMD) "$(DLINKLIST_DIR)$(PATH_SEP)*.o" 
	$(DEL_CMD) "sorts$(PATH_SEP)*.o"
	$(DEL_CMD) "arraylist_program*" 
	$(DEL_CMD) "dlinklist_program*"
	$(DEL_CMD) "sorts_program*"
