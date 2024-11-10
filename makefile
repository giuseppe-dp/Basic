main: main.o sorting.o
	g++ main.o sorting.o  -o main
main.o: main.cpp sorting.h
	g++ -c main.cpp -o main.o
sorting.o: sorting.cpp sorting.h
	g++ -c sorting.cpp -o sorting.o
compila: main

clean:
	rm *.o
cleanall: clean 
	rm main