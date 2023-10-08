
#include <cstdlib> // Para usar srand y rand
#include <chrono>
#include <iostream>
#include <fstream>
#include <vector>   //Para los vertices
#include <set>      //Para las aristas
#include <queue>    //Para el camino
#include <string>   
#include <fstream> // Para usar ficheros
using namespace std;

class accion{
    private:
        int precio;
        int beneficio;
        int comision;
        string empresa;

    public:

        string getEmpresa(){
            return empresa;
        }

        int getPrecio()const {
            return precio+comision;
        }

        int getBeneficio()const {
            return beneficio*precio - comision;
        }

        accion(string em, int p, int b, int c){
            precio = p;
            beneficio = b;
            comision = c;
            empresa = em;
        }

};

struct accion_compare{
    bool operator()(const accion & a, const accion & b) const{
        return a.getBeneficio()/a.getPrecio() < b.getBeneficio()/b.getPrecio();
    }
};

int maximoBeneficioBasico(vector<accion>& acciones, int presupuesto, int i) {
    if(i >= acciones.size()){                                                   //No quedan mas acciones 
        return 0; 
    }

    int beneficio = 0; 
    if(acciones[i].getPrecio() <= presupuesto){                                 //Me permite comprar la accion 
        beneficio = acciones[i].getBeneficio() + maximoBeneficioBasico(acciones, presupuesto - acciones[i].getPrecio(), i + 1);   //seguir comprando acciones si queda presupuesto 
    }

    int beneficio_aux = maximoBeneficioBasico(acciones, presupuesto, i + 1); 
    
    return max(beneficio, beneficio_aux); 
}

int main(int argc, char *argv[]) {

    int dineroMax, n_empresas;
    int a_p, a_b, a_c, n_acciones;
    string a_em;

    multiset<accion, accion_compare> acc_aux;
    vector<accion> acciones;

    chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
	double tejecucion; // tiempo de ejecucion del algoritmo en ms

	if (argc <= 1) {
		cerr<<"\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
		cerr<<argv[0]<<" NombreFicheroEntrada1 .. NombreFicheroEntradaN\n\n";
		return 0;
	}

    for (int argumento = 1; argumento<argc; argumento++) {

        ifstream ficheroProblema;
        string cadena;
        char delimitador = '\t';            //Usamos el tab como delimitador de linea
        int dato;

        ficheroProblema.open(argv[argumento]);

        if (ficheroProblema.is_open()){
            ficheroProblema >> cadena;
            dineroMax = stoi(cadena);

            ficheroProblema >> cadena;
            n_empresas = stoi(cadena);

            for(int i = 0; i < n_empresas; i++){

                ficheroProblema >> cadena;
                n_acciones = stoi(cadena);

                ficheroProblema >> cadena;
                a_em = cadena;

                ficheroProblema >> cadena;
                a_p = stoi(cadena);
                ficheroProblema >> cadena;
                a_b = stoi(cadena);
                ficheroProblema >> cadena;
                a_c = stoi(cadena);

                accion a_aux(a_em, a_p, a_b, a_c);

                for(int j = 0; j < n_acciones; j++){							//Si no es el final de los vertices que conectan
                    acc_aux.insert(a_aux);
                }
            }
        }

        ficheroProblema.close();

        for(auto it = acc_aux.begin(); it != acc_aux.end(); ++it){
            acciones.push_back(*it);
        }
        acc_aux.clear();
        cout<<endl;

        cout << "Buscamos maximizacion de ganancias teniendo un saldo de: " << dineroMax<< " y "<<acciones.size()<<" acciones."<<endl;
        
        t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
        int max_beneficio = maximoBeneficioBasico(acciones, dineroMax, 0);
        tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo

        cout << "Maximo beneficio conseguido: " << max_beneficio << endl; 

        tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();

        cout << "\tTiempo de ejec. (us): " << tejecucion <<endl;
        cout << "-------------------------------------------------------" <<endl;

        acciones.clear();

    }

	return 0;
}