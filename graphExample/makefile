

main : main.o graph_adj_mat.o
	gcc main.o graph_adj_mat.o -o graph

main.o : main.c graph_adj_mat.o
	gcc -c main.c

graph_adj_mat.o : graph_adj_mat.c graph_adj_mat.h
	gcc -c graph_adj_mat.c 

vis: main
	.\graph.exe | dot -Tpdf > vis.pdf
	
clean:
	rm -f *.o graph