# Natalia Perez Lab 7

lab7: lab7.o get_data.o open_out_file.o print_all.o get_stats.o
	gcc lab7.o get_data.o open_out_file.o print_all.o get_stats.o -o lab7 -lm

lab7.o: lab7.c lab7.h
	gcc -c lab7.c -lm

get_data.o: get_data.c lab7.h
	gcc -c get_data.c -lm

open_out_file.o: open_out_file.c lab7.h
	gcc -c open_out_file.c -lm

print_all.o: print_all.c lab7.h
	gcc -c print_all.c -lm

get_stats.o: get_stats.c lab7.h
	gcc -c get_stats.c -lm
