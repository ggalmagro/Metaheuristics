#include <iostream>
#include "QAP.h"
#include <math.h>
#include <vector>


using namespace std;

int main (int argc, char **argv){

	if(argc != 3){
	
		cerr << "Uso: <main> <fichero_datos> <semilla>" << endl;
		return -1;

	}


	//INICIALIZACION//

	char *nombre = argv[1];
	int semilla = atoi(argv[2]);
	vector<int> v_solution;
	int weight_solution, dimension;

	QAP qap(nombre, semilla);

	dimension = qap.GetDimension();

	//SOLUCION: METODO DE ESCALADA PRIMERO DEL MEJOR//

	
	qap.IterativeLocalSearchSA(25, 4, 50000, 10*dimension, ceil(0.1*dimension), 0.001);

	v_solution = qap.GetSolPermutation();
	weight_solution = qap.GetSolution();

	cout << "Valor de la solucion ILSSA: " << weight_solution << endl;
	/*cout << "Permutación solucion:" << endl;

	for(int i=0; i<dimension; i++){
		cout << v_solution[i] << " ";
	}*/
	
	cout << endl;

	return 0;

}