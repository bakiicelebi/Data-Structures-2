all: build run

build:
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/StackNode.o -c ./src/StackNode.cpp
	g++ -I ./include/ -o ./lib/TreeNode.o -c ./src/TreeNode.cpp
	g++ -I ./include/ -o ./lib/BinarySearchTree.o -c ./src/BinarySearchTree.cpp
	g++ -I ./include/ -o ./lib/LinkedList.o -c ./src/LinkedList.cpp
	g++ -I ./include/ -o ./bin/program ./lib/Node.o ./lib/StackNode.o ./lib/TreeNode.o ./lib/BinarySearchTree.o ./lib/LinkedList.o ./src/main.cpp

run:
	./bin/program