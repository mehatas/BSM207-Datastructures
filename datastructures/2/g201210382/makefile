hepsi: derle calistir 

derle: 
	g++ -I ./include/ -o ./lib/DosyaOku.o -c ./src/DosyaOku.cpp 
	g++ -I ./include/ -o ./lib/AVL.o -c ./src/AVL.cpp 
	g++ -I ./include/ -o ./lib/DogruKuyrugu.o -c ./src/DogruKuyrugu.cpp 
	g++ -I ./include/ -o ./bin/Test ./lib/DogruKuyrugu.o ./lib/AVL.o ./lib/DosyaOku.o ./src/Test.cpp
calistir:
	./bin/Test