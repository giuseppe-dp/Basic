main: main.o search.o
	g++ main.o search.o  -o main
main.o: main.cpp search.h
	g++ -c main.cpp -o main.o
search.o: search.cpp search.h
	g++ -c search.cpp -o search.o
compila: main

clean:
	rm *.o
cleanall: clean 
	rm main