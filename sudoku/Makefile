all:transform generate solve

transform:sudoku.h sudoku.o transform.o
	g++ -o transform transform.o sudoku.o
sudoku.o:sudoku.h sudoku.cpp
	g++ -c sudoku.cpp
transform.o:sudoku.h transform.cpp
	g++ -c transform.cpp
generate:sudoku.h sudoku.o generate.o
	g++ -o generate sudoku.o generate.o
generate.o:sudoku.h generate.cpp
	g++ -c generate.cpp
solve:sudoku.h sudoku.o solve.o
	g++ -o solve sudoku.o solve.o
solve.o:sudoku.h solve.cpp
	g++ -c solve.cpp

clean:
	rm *.o
