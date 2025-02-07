#include <iostream>
using namespace std;

// Clase base: Computadora
class Computadora {
protected:
    string marca;
    string modelo;
    int anio;

public:
    Computadora(string _marca, string _modelo, int _anio) {
        marca = _marca;
        modelo = _modelo;
        anio = _anio;
    }

    virtual void mostrarDatos() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << anio << endl;
    }
};

// Clase derivada: Laptop
class Laptop : public Computadora {
private:
    float peso;

public:
    Laptop(string _marca, string _modelo, int _anio, float _peso)
        : Computadora(_marca, _modelo, _anio), peso(_peso) {
    }

    void mostrarDatos() override {
        Computadora::mostrarDatos();
        cout << "Peso: " << peso << " kg" << endl;
    }
};

// Clase derivada: PC de Escritorio
class PCDeEscritorio : public Computadora {
private:
    string tipoGabinete;

public:
    PCDeEscritorio(string _marca, string _modelo, int _anio, string _tipoGabinete)
        : Computadora(_marca, _modelo, _anio), tipoGabinete(_tipoGabinete) {
    }

    void mostrarDatos() override {
        Computadora::mostrarDatos();
        cout << "Tipo de gabinete: " << tipoGabinete << endl;
    }
};

// Función principal
int main() {
    Laptop miLaptop("Dell", "XPS 13", 2023, 1.2);
    PCDeEscritorio miPC("HP", "Omen", 2022, "ATX");

    cout << "Datos de la Laptop:" << endl;
    miLaptop.mostrarDatos();
    cout << endl;

    cout << "Datos de la PC de Escritorio:" << endl;
    miPC.mostrarDatos();

    return 0;
}