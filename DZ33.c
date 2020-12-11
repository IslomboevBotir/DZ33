#include<stdio.h>
#include<stdlib.h>
#define N 50

int teor_con(int edge, int point, int *vert, int *arr)
		{
			int i, check, j, k = 0;
			vert = (int *)malloc(2*edge*sizeof(int));
			if(vert == NULL)
			{
				printf("Memory is over...\n");
				exit(709);
			}
			check = 0;
			for(i = 0; i < point; i++)
			{
				for(j = 0; j < edge; j++)
		{
    		if(arr[i+j*point] == 1)
			{
    				check = 1;
			}
		}
		if(check == 0)
		{
			printf("The graph is disconnecting...\n");
			return 0;
		}
		else
		{
			check = 0;
		}
	}
	check = 0;
	for(i = 0; i < edge; i++)
	{
    		for(j = 0; j < point; j++)
		{
    			if((arr[i*point + j] == 1) && (check == 0))
			{
            		vert[k] = j+1;
            		++k;
            		check = 1;
			}
			else if((arr[i*point + j] == 1) && (check == 1))
			{
				vert[k] = j+1;
				++k;
           		check = 0;
			}
		}
		if(check == 1)
		{
			printf("The graph have loops...\nTheorem cannot be used...\n");
			return 0;
		}
	}
	check = 0;
	for(k = 0; k < (2*edge - 1); k+=2)
	{
		for(j = k + 2; j < (2*edge - 1); j+=2)
		{
			if(vert[k] == vert[j])
			{
				check = 1;
			}
			if(check == 1)
			{
				if(vert[k+1] == vert[j+1])
				{
					printf("The graph have multiple edges...\nTheorem cannot be used...\n");
						return 0;
				}
				else
				{
					check = 0;
				}
			}
		}
	}
	free(vert);
	return 1;
}

int main(void)
{
	FILE *graph;
	char name[N];
	int point = 0;
	int act = 0;
	int edge = 0;
	int i, j, k = 0;
	int val = 0;
	int first = 0;
	int second = 0;
	int check = 0;
	int *arr;
	int *vert;
	char e = 'A';
    	printf("+--------------+\n");
   	printf("|     Menu     |\n");
	printf("+---+----------+\n");
	printf("| 1 | File     |\n");
        printf("+---+----------+\n");
        printf("| 2 | Consol   |\n");
        printf("+---+----------+\n");    
	printf("Choose a way: ");
        scanf("%d", &act);
        switch(act){
    	case 1:
    	++edge;
    	printf("Name of file: ");
    	scanf("%s", name);
    	graph = fopen(name, "r");
    		if (graph == NULL)
			{
    			printf("File is not found...\n");
    			exit(404);
			}
			check = 0;
			while(!feof(graph))
			{
				e = getc(graph);
    				if(e == '0' || e == '1')
				{
    				++point;
    				if(e == '1')
					{
    					++check;
					}
				}
				else if(e == '\n')
				{
				++edge;
					if((check > 2) || (check == 0))
					{
    					printf("Incorrect matrix...\n");
    					exit(55);
					}
				check = 0;
				}
			}
			point = point/edge;
			fclose(graph);
			arr = (int *)malloc(point*edge*sizeof(int));
			if(arr == NULL)
			{
				printf("Memory is over...\n");
				exit(711);
			}
			graph = fopen(name, "r");
			i = 0;
			while(!feof(graph))
			{
				e = getc(graph);
    				if(e == '0' || e == '1')
				{
    				arr[i] = e - '0';
    				++i;
				}
			}
			e = 'A';
			fclose(graph);
    	break;
    	case 2:
    		printf("\n");
    		printf("Number of vertices: ");	
		scanf("%d", &point);
		printf("Number of edges: ");
    		scanf("%d", &edge);
    		arr = (int *)malloc(point*edge*sizeof(int));
    		if(arr == NULL)
			{
			printf("Memory is over...\n");
			exit(710);
			}
	 	printf("Example:\n\n");
    		printf("edges\n");
		printf("|\n");
    		printf("V\n");
			printf("   1 2 3 4 5 6 --> vertices\n");
			printf("A  0 0 1 0 0 1\n");
			printf("B  0 1 0 0 0 0\n");
			printf("C  0 0 0 1 0 1\n");
			printf("D  1 1 0 0 0 0\n");
			printf("E  0 0 1 0 0 1\n");
			printf("Enter the matrix:\n");
			printf("   ");
			for(i = 0; i < point; i++)
			{
    	    		printf("%d ", i + 1);
			}
			printf("\n");
			for(i = 0; i < edge; i++)
			{
			printf("%c  ", e);
			++e;
				for(j = 0; j < point; j++)
				{
				scanf("%d", &val);
					if ( (val != 0) && (val != 1) )
					{
					printf("Incorrect matrix\n");
					exit(505);
					}
					check = check + val;
					arr[i*point + j] = val;
				}
				if( (check > 2) || (check == 0) )
				{
				printf("Incorrect matrix\n");
				exit(303);
				}
				else
				{
					check = 0;
				}
			}
    	break;
   			default:
    			printf("Unknown operation...\n");
    			exit(99);
    	break;
	}

    printf("\n+--------------------------+\n");
    printf("|        Actions           |\n");
    printf("+---+----------------------+\n");
    printf("| 1 | Add point            |\n");
    printf("+---+----------------------+\n");
    printf("| 2 | Show matrix          |\n");
    printf("+---+----------------------+\n");
    printf("| 3 | Add edge             |\n");
    printf("+---+----------------------+\n");
    printf("| 4 | Delete edge          |\n");
    printf("+---+----------------------+\n");
    printf("| 5 | Delete vertice       |\n");
    printf("+---+----------------------+\n");
    printf("| 6 | Create image         |\n");
    printf("+---+----------------------+\n");
    printf("| 7 | Check connection     |\n");
    printf("+---+----------------------+\n");
    printf("| 8 | Unconnection couples |\n");
    printf("+---+----------------------+\n");
    printf("| 9 | Exit program         |\n");
    printf("+---+----------------------+\n");
    while(act!=9)
	{
        printf("Choose an action: ");
        scanf("%d", &act);
        switch (act)
		{
            	case 1:
            	++point;
            	arr = (int *)realloc(arr, (point*edge)*sizeof(int));
            	if(arr == NULL)
		{
		printf("Memory is over...\n");
		exit(756);
		}
            	for(i = point - 1; i < point*edge; i += point)
		{
            	for(j = point*edge; j > i; j--)
		{
            	arr[j] = arr[j - 1];
		}
		}
		for(i = point - 1; i < point*edge; i += point)
		{
		arr[i] = 0;
		}
		printf("The vertice %d was successfully added...\n", point);
		break;
                case 2:
            	printf("   ");
            	e = 'A';
            	for(i = 0; i < point; i++)
				{
        			printf("%d ", i + 1);
				}
				printf("\n");
            	for(i = 0; i < edge; i++)
				{
            			printf("%c  ", e);
            			++e;
            			for(j = 0; j < point; j++)
					{
					printf("%d ", arr[i*point + j]);
					}
					printf("\n");
				}
            break;
            case 3:
            	++edge;
            	check = 0;
            	vert = (int *)malloc(2*sizeof(int));
            	if(vert == NULL)
				{
					printf("Memory is over...\n");
					exit(712);
				}
            	arr = realloc(arr, (point*edge)*sizeof(int));
            	if(arr == NULL)
				{
					printf("Memory is over...\n");
					exit(757);
				}
				printf("Choose first vertice: ");
				scanf("%d", &vert[0]);
				printf("Choose second vertice: ");
				scanf("%d", &vert[1]);
            	for(i = point*(edge - 1); i < point*edge; i++)
				{
            		if(vert[0] == i + 1 - point*(edge - 1)){
            			++check;
            			arr[i] = 1;
					}
					else if(vert[1] == i + 1 - point*(edge - 1))
					{
            			++check;
            			arr[i] = 1;
					}
					else
					{
						arr[i] = 0;
					}
				}
            	if(!check)
				{
            		printf("Such vertices is not found...\n");
            		exit(606);
				}
				if((vert[0] != vert[1]) && (check!=2))
				{
					printf("Such vertices is not found...\n");
            		exit(606);
				}
				free(vert);
            break;	
            case 4:
            	printf("Edge: ");
            	getchar();
            	scanf("%c", &e);
            	if((e - 'A') >= edge)
				{
					printf("The edge is not found...");
					exit(202);
				}
            	for(i = point*(e - 'A'); i < (point*edge - point); i++)
				{
            		arr[i] = arr[i+point];
				}
				--edge;
				arr = (int *)realloc(arr, (edge*point)*sizeof(int));
				if(arr == NULL)
				{
					printf("Memory is over...\n");
					exit(758);
				}
				printf("The edge was deleted...\n");
            break;
            case 5:
            	printf("Vertice: ");
            	vert = (int *)malloc(sizeof(int));
            	if(vert == NULL)
				{
					printf("Memory is over...\n");
					exit(713);
				}
            	scanf("%d", &vert[0]);
            	if (vert[0] > point)
				{
            		printf("The vertice is not found...\n");
            		exit(101);
				}
				for(i = vert[0] - 1; i < point*edge; i+=point)
				{
					if(arr[i] == 1)
					{
						for(j = i - vert[0] + 1; j < (point*edge - point); j++)
						{
							arr[j] = arr[j + point];
						}
						--edge;
						i-=point;
					}
				}
				for(i = vert[0] - 1; i < point*edge; i+=(point-1))
				{
					for(j = i; j < point*edge; j++)
					{
						arr[j] = arr[j+1];
					}
				}
				--point;
				arr = (int *)realloc(arr, (edge*point)*sizeof(int));
				if(arr == NULL)
				{
					printf("Memory is over...\n");
					exit(709);
				}
				printf("The vertice was deleted...\n");
				free(vert);
            break;
            case 6:
            	graph = fopen("graph.dot", "w");
            	if(graph == NULL)
				{
            		printf("Failure...\n");
            		exit(307);
				}
            	check = 0;
            	fputs("graph test{\n", graph);
            	for(i = 0; i < point; i++)
				{
            		e = i +'1';
            		fputs("\t", graph);
            		fputs(&e, graph);
            		fputs(";\n", graph);
				}
            	for(i = 0; i < edge; i++)
				{
            		for(j = 0; j < point; j++)
					{
            			if((arr[i*point + j] == 1) && (check == 0))
						{
            				fputs("\t", graph);
            				e = j + '1';
            				fputs(&e, graph);
            				fputs("--", graph);
            				++check;
						}
						else if((arr[i*point + j] == 1) && (check == 1))
						{
            				e = j + '1';
            				fputs(&e, graph);
            				fputs(";\n", graph);
            				check = 0;
						}
					}
					if(check == 1)
					{
						fputs(&e, graph);
						fputs(";\n", graph);
						check = 0;
					}
				}
            	fputs("}\n", graph);
            	fclose(graph);
            	printf("Graph is successfully building...\n");
            	system("dot -Tpng -O graph.dot");                                                                                       
				system("xdg-open graph.dot.png");
            break;
            case 7:
            	j = teor_con(edge, point, vert, arr);
            	if(j)
				{
            		if(edge > (point - 1)*(point - 2)/2)
					{
            			printf("The graph is connecting...\n");
					}
					else
					{
						printf("It is impossible to check connection with theorem...\n");
					}
				}
            break; 
            case 8:
            	check = 0;
            	k = 0;
            	vert = (int *)malloc(2*edge*sizeof(int));
				for(i = 0; i < edge; i++)
				{
			    	for(j = 0; j < point; j++)
					{
			    		if((arr[i*point + j] == 1) && (check == 0))
						{
			            	vert[k] = j+1;
			            		++k;
			            		check = 1;
						}
						else if((arr[i*point + j] == 1) && (check == 1))
						{
							vert[k] = j+1;
							++k;
			           		check = 0;
						}
					}
				}
				val = 0;
				for(i = 1; i < point; i++)
				{
					for(j = i + 1; j <= point; j++)
					{
						for(k = 0; k < 2*edge; k+=2)
						{
							if(i == vert[k] && j == vert[k+1])
							{
								check = 1;
							}
						}
						if(check == 0)
						{
							val = 1;
							printf("%d -- %d\n", i, j);
						}
						else
						{
							check = 0;
						}
					}
				}
				if(!val)
				{
					printf("There are no disconnecting vertices...\n");
				}
				
            break;
            case 9:
            	printf("The program is finished...\n");
            	free(arr);
            	exit(0);
            break;
            default: 
            	printf("Unknown operation\n");
        }
    }
	return 0;
}


