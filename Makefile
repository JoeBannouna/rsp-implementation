all:

graph:
	g++ LinkedList.cpp Graph.cpp main-graph.cpp -o ./output
	./output

binarytree:
	g++ BinaryTree.cpp main-binarytree.cpp -o ./output
	./output

linkedlist:
	g++ LinkedList.cpp main-linkedlist.cpp -o ./output
	./output