hepsi: derle calistir 

derle : 
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp 
	g++ -I ./include/ -o ./lib/DoublyLinkedList.o -c ./src/DoublyLinkedList.cpp
	g++ -I ./include/ -o ./lib/DosyaOku.o -c ./src/DosyaOku.cpp 
	g++ -I ./include/ -o ./bin/Main ./lib/Node.o ./lib/DoublyLinkedList.o ./lib/DosyaOku.o ./src/Main.cpp 
calistir :
	./bin/Main