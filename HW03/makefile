CC := gcc
std := c99

all: task1 task2 task3 task5

# This time, we use automatic variables in place of filenames.
# $< refers to the names of any dependencies and $@ refers to the target
task1: task1.o output.o
	$(CC) $^ -o $@ -std=$(std)

task2: task2.o output.o
	$(CC) $^ -o $@ -std=$(std) -lm

task3: task3.o output.o
	$(CC) $^ -o $@ -std=$(std) -g

task5: task5.o output.o
	$(CC) $^ -o $@ -std=$(std) -lm

# This generic target matches any file with the pattern BASENAME.o
# which is built from a dependency called BASENAME.c
%.o: %.c
	$(CC) -c $< -o $@ -std=$(std) -g

clean:
	@rm -f *.o task1 task2 task3 task5

# shortcut for running task1 you have to use:
# be aware of the use of quotation marks
# $ make run_task1 n="'insert a string here'"
run_task1:
	@make -s task1
	@./task1 $(n)

run_task2:
	@make -s task2
	@./task2 $(n)

run_task5:
	@make -s task5
	@./task5 $(n)

# shortcut for running task3
run_task3:
	@make -s task3
	@./task3 $(n)
