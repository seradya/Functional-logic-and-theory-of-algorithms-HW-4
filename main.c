#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>
#include <ShellApi.h> 
#define LEN 255

int maximum(int* A){
	int max = 0;
	int index = -1;
	for(int i = 0; i < LEN; i++){
		if(A[i]>max){
			max = A[i];
			index = i;
		}
	}
	A[index] = 0;
	return index;
}

int main(void){

	int a = 0, b = 0;
	int count[LEN];
	for (int i = 0; i < LEN; i++)
		count[i] = 0;
	int input_count = 0;
	int input[2][LEN];
	for (int i = 0; i < LEN; i++)
		input[0][i] = input[1][i] = -1;


	printf("%s\n", "Введите граф в формате \"номер вершины\"-\"номер вершины\"");
	while(scanf("%d-%d", &a, &b) != 0){
		count[a]++;
		count[b]++;
		input[0][input_count] = a;
		input[1][input_count] = b;
		input_count++;
	}
	getchar();
	FILE *mod_graph;
	mod_graph = fopen("mod_graph.dot", "w");
	fprintf(mod_graph, "%s\n", "graph My_graph {");

	printf("%s\n", "Введите ребро, которое необходимо удалить");
	scanf("%d-%d", &a, &b);
	count[a]--;
	count[b]--;
	for (int i = 0; i < input_count; i++){
		if ((input[0][i] == a)&&(input[1][i] == b)){
			input[0][i] = -1;
			input[1][i] = -1;
		}
		else{
			fprintf(mod_graph, "%d -- %d;\n", input[0][i],input[1][i]);
		}
	}
	fprintf(mod_graph, "%s", "}");
	fclose(mod_graph);

	printf("%s\n", "Вершины, отсортированные по убыванию степени:");
	int ind = 0;
	while((ind = maximum(count)) != -1){
		printf("%d; ", ind);
	}
	
	system("dot C:/Users/serad/Documents/univer/FLAT/dz3/mod_graph.dot -Tbmp -o mod_graph.bmp");
	ShellExecuteA(GetDesktopWindow(),"open","C:/Users/serad/Documents/univer/FLAT/dz3/mod_graph.bmp",NULL,NULL,SW_SHOW);
	return 0;

}
	