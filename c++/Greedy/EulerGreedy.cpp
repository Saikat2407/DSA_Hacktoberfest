#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

void dfs(int v, vector<int>& camino, int n, bool **g) { //funcion para buscar el siguiente vertice 
    for (int i = 0; i < n; i++) {
        if (g[v][i]) {
            g[v][i] = g[i][v] = false;
            dfs(i, camino, n, g);  //recursion 
        }
    }
    camino.push_back(v);
}

vector<int> encontrar_camino_euler(int n, int * grado, bool **g) {
    int num_impares = 0; 
    int inicio = -1;
    vector<int> camino;

    for (int i = 0; i < n; i++) {
        if (grado[i] % 2 == 1) {    //comprobar si hay impar 
            num_impares++;
            if (inicio == -1) {
                inicio = i;
            }
        }
    }

    if (num_impares == 0) { //todos los vertices son pares
        inicio = 0;
    }

    if (num_impares == 0 || num_impares == 2) { //cumple la propiedades de camino de euler 
        dfs(inicio, camino, n, g);
        reverse(camino.begin(), camino.end());  //revertir camino 
    }

    return camino;
}

int main(int argc, char * argv[]) {
    ifstream fentrada; 
    ofstream fsalida; 

    if (argc != 3){
        cerr << "\nError: Inserte fichero de entrada.\n\n"; 
        return 0; 
    }

    fentrada.open(argv[1]); 
    if(!fentrada.is_open()){
        cerr << "\nNo se pudo abrir fichero de entrada\n\n"; 
        return 0; 
    }

    int n; 
    int a;  
   
    fentrada >> n;  
    fentrada >> a; 
    cout <<"Vamos a trabajar con "<< n << " vertices y  " << a << " aristas" << endl; 
 
    bool ** g = new bool * [n]; // matriz de adyaciencia; 
    for (int i = 0; i < n; i++){
        g[i] = new bool [n];    //inicializar valores 
    }
    int * grado = new int [n]; //grado de un vertice
    
    for (int i = 1; i < n; i++){
        //int u, v; 
        string aux;
        getline(fentrada, aux); 
        cout << aux << endl; 

        int u = stoi(aux.substr(0, aux.find(' ')));
        int v = stoi(aux.substr(aux.find(' ') + 1));

        //u = aux[0]; 
        //v = aux[1];

        g[u][v] = g[v][u] = true;
        grado[u]++;
        grado[v]++;
    }

    fsalida.open(argv[2]); 
    if(!fsalida.is_open()){
        cerr << "\nNo se pudo abrir fichero de salida\n\n"; 
        return 0; 
    }




    //Ejemplo de funcionamiento 
    /*int n = 6; //numero de vertices 
    int a = 10; // numero de aristas  

    bool ** g = new bool * [n]; // matriz de adyaciencia; 
    for (int i = 0; i < n; i++){
        g[i] = new bool [n];    //inicializar valores 
    }
    int * grado = new int [n]; //grado de un vertice

    g[0][1] = g[1][0] = true; 
    grado[0]++;
    grado[1]++; 
    g[0][2] = g[2][0] = true; 
    grado[0]++; 
    grado[2]++; 

    g[1][2] = g[2][1] = true; 
    grado[1]++; 
    grado[2]++; 
    g[1][4] = g[4][1] = true; 
    grado[1]++; 
    grado[4]++; 
    g[1][3] = g[3][1] = true; 
    grado[1]++; 
    grado[3]++; 

    g[2][3] = g[3][2] = true; 
    grado[2]++; 
    grado[3]++; 
    g[2][4] = g[4][2] = true; 
    grado[2]++; 
    grado[4]++; 


    g[3][4] = g[4][3] = true; 
    grado[3]++; 
    grado[4]++;     
    g[3][5] = g[5][3] = true; 
    grado[3]++; 
    grado[5]++; 

    g[4][5] = g[5][4] = true; 
    grado[5]++; 
    grado[4]++;*/

    //Entrada por terminal
    /*for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = true;
        grado[u]++;
        grado[v]++;
    }*/

    vector<int> camino = encontrar_camino_euler(n, grado, g);  

    if (camino.empty()) {
        //cout << "No hay camino de Euler" << endl;
        fsalida << "No hay camino de Euler" << endl;
    } else {
        for (int i = 0; i < camino.size(); i++) {
            //cout << camino[i] << " ";
            fsalida << camino[i] << " "; 
        }
        fsalida << endl;
    }

    for(int i = 0; i < n; i++){
        delete [] g[n]; 
    }
    delete [] g; 
    delete [] grado; 

    fentrada.close(); 
    fsalida.close(); 

    return 0;
}
