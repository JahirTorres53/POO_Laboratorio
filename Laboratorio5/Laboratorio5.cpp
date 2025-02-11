#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Producto {
private:
    string nombre;
    int codigo;
    float precio;
    int stock;
    string categoria;
    string proveedor;
    string descripcion;

public:
    // Constructor que inicializa los 7 atributos
    Producto(string nom, int cod, float prec, int stk, string cat, string prov, string desc)
        : nombre(nom), codigo(cod), precio(prec), stock(stk),
        categoria(cat), proveedor(prov), descripcion(desc) {
    }

    // Método para mostrar la información del producto
    void mostrar() const {
        cout << "Código: " << codigo
            << "\nProducto: " << nombre
            << "\nCategoría: " << categoria
            << "\nPrecio: Q" << precio
            << "\nStock: " << stock
            << "\nProveedor: " << proveedor
            << "\nDescripción: " << descripcion << "\n"
            << "-----------------------------" << endl;
    }

    int obtenerCodigo() const { return codigo; }
    int obtenerStock() const { return stock; }

    // Actualiza el stock descontando la cantidad indicada
    void actualizarStock(int cantidad) {
        if (cantidad > stock) {
            cerr << "Error: No hay suficiente stock disponible." << endl;
        }
        else {
            stock -= cantidad;
            cout << "Stock actualizado. Nuevo stock: " << stock << endl;
        }
    }

    float obtenerValor() const {
        return stock * precio;
    }
};

// Función para agregar un nuevo producto al inventario
void agregarProducto(vector<Producto>& inventario) {
    string nombre, categoria, proveedor, descripcion;
    int codigo, stock;
    float precio;

    cout << "Ingrese el nombre del producto: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
    getline(cin, nombre);

    cout << "Ingrese el código: ";
    while (!(cin >> codigo)) {
        cout << "Código inválido, ingrese un número entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese el precio: ";
    while (!(cin >> precio) || precio < 0) {
        cout << "Precio inválido, ingrese un valor positivo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese la cantidad en stock: ";
    while (!(cin >> stock) || stock < 0) {
        cout << "Stock inválido, ingrese un número positivo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese la categoría: ";
    getline(cin, categoria);

    cout << "Ingrese el proveedor: ";
    getline(cin, proveedor);

    cout << "Ingrese la descripción: ";
    getline(cin, descripcion);

    inventario.push_back(Producto(nombre, codigo, precio, stock, categoria, proveedor, descripcion));
    cout << "Producto agregado exitosamente." << endl;
}

// Función para mostrar todo el inventario
void mostrarInventario(const vector<Producto>& inventario) {
    if (inventario.empty()) {
        cout << "No hay productos en el inventario." << endl;
        return;
    }
    for (const Producto& producto : inventario) {
        producto.mostrar();
    }
}

// Función para buscar un producto por su código
void buscarProducto(const vector<Producto>& inventario) {
    int codigo;
    cout << "Ingrese el código del producto a buscar: ";
    cin >> codigo;

    auto it = find_if(inventario.begin(), inventario.end(), [codigo](const Producto& p) {
        return p.obtenerCodigo() == codigo;
        });

    if (it != inventario.end()) {
        cout << "Producto encontrado:" << endl;
        it->mostrar();
    }
    else {
        cerr << "Producto no encontrado." << endl;
    }
}

// Función para actualizar el stock de un producto
void actualizarStock(vector<Producto>& inventario) {
    int codigo, cantidad;
    cout << "Ingrese el código del producto a actualizar: ";
    cin >> codigo;

    auto it = find_if(inventario.begin(), inventario.end(), [codigo](Producto& p) {
        return p.obtenerCodigo() == codigo;
        });

    if (it != inventario.end()) {
        cout << "Ingrese la cantidad a restar del stock: ";
        cin >> cantidad;
        it->actualizarStock(cantidad);
    }
    else {
        cerr << "Producto no encontrado." << endl;
    }
}

// Función para calcular el valor total del inventario
void calcularValorTotal(const vector<Producto>& inventario) {
    float total = 0;
    for (const Producto& producto : inventario) {
        total += producto.obtenerValor();
    }
    cout << "Valor total del inventario: Q" << total << endl;
}

int main() {
    vector<Producto> inventario;
    int opcion;

    do {
        cout << "\nSistema de Inventario\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar inventario\n";
        cout << "3. Buscar producto por código\n";
        cout << "4. Actualizar stock\n";
        cout << "5. Calcular valor total del inventario\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: agregarProducto(inventario); break;
        case 2: mostrarInventario(inventario); break;
        case 3: buscarProducto(inventario); break;
        case 4: actualizarStock(inventario); break;
        case 5: calcularValorTotal(inventario); break;
        case 6: cout << "Saliendo del programa...\n"; break;
        default: cout << "Opción no válida, intente de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}
