/*Victor Hugo Vazquez Luna 23310163 2P
Programacion Orienteda a Objetos
*/

#include <stdlib.h>
#include<iostream>
using namespace std; 

 class Usuario{
 private:
    string nombre;
    int telefono;
    int edad;
 public:
    Usuario(string,int,int);
    virtual void datos();
    void indatos();
 };

    Usuario::Usuario(string _nombre, int _telefono, int _edad){
      nombre = _nombre;
      telefono = _telefono;
      edad = _edad;
    }
 
    void Usuario::datos(){
      cout << "Nombre : " << nombre << endl;
      cout << "Telefono : " << telefono << endl;
      cout << "Edad : " << edad << endl;
    }

 class Cliente : public Usuario{
 private:
   float comprar;
 public:
   Cliente(string,int,int,float);
   void datos();
 };

   Cliente::Cliente(string _nombre, int _telefono, int _edad, float _comprar) 
   : Usuario(_nombre,_telefono,_edad){
     comprar = _comprar;
   }

   void Cliente::datos(){
     Usuario::datos();
     cout << "Compraste con $ " << comprar << endl;
   }

class Vendedor : public Usuario{
private:
   float vender;
public:
   Vendedor(string,int,int,float);
   void datos();
};

   Vendedor::Vendedor(string _nombre, int _telefono, int _edad, float _vender)
   : Usuario(_nombre,_telefono,_edad){
     vender = _vender; 
   }

   void Vendedor::datos(){
    Usuario::datos();
    cout << "Vendiste $ : " << vender << endl;
   }


////////////////////
class Login {
private:
    string nombreUsuario;
    string contraseña;
    bool logueado;

public:
    Login() : nombreUsuario("vic"), contraseña("741"), logueado(false) {}
    void Menu();
    bool login();
    void logout();
    void cambiarContraseña();
};

void Login::Menu() {
    cout << "\n--- Menu ---\n";
    cout << "1. Iniciar sesion\n";
    cout << "2. Cerrar sesion\n";
    cout << "3. Cambiar contrasena\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opcion: ";
}


 void tipo(){
    cout << "Escoge que tipo de usuario eres" << endl;
    cout << "1) Vendedor" << endl;
    cout << "2) Cliente" << endl;
    cout << "3) Usuario" << endl;
    cout << "4) Salir" << endl;
    int opcion2; cin >> opcion2;

  switch (opcion2){
    case 1:{
     Vendedor x3 ("Juan", 33181923,70,45.9);
      x3.datos();
     break;}
    case 2:{
     Cliente x2 ("Lol",3323131,45,46.8);
      x2.datos();
     break;}
    case 3:{
     Usuario x1 ("Vic",33190525,20);
      x1.datos();
     break;}
    case 4:{
     cout << "Saliendo del programa.";
     break;}
    default:
     cout << "Opcion no valida. Intente de nuevo.";
    }
  }

bool Login::login() {
    string nombreUsuario, contraseña;
    cout << "Ingrese nombre de usuario: ";
    cin >> nombreUsuario;
    cout << "Ingrese contrasena: ";
    cin >> contraseña;

    if (nombreUsuario == this->nombreUsuario && contraseña == this->contraseña) {
        this->logueado = true;
        cout << "Inicio de sesion exitoso" << endl;
        tipo();
    } else {
        cout << "Inicio de sesión fallido. Usuario o contrasena incorrectos.\n";
        return false;
    }
}

void Login::logout() {
    this->logueado = false;
    cout << "Cierre de sesion exitoso\n";
}

void Login::cambiarContraseña() {
    if (!logueado) {
        cout << "Debe iniciar sesión antes de cambiar la contrasena.\n";
        return;
    }

   string nuevaContraseña;
    cout << "Ingrese nueva contrasena: ";
    cin >> nuevaContraseña;
    this->contraseña = nuevaContraseña;
    cout << "Contrasena cambiada con exito.\n";
}


int main(){
  /*Usuario x1 ("Vic",33190525,20);
  Cliente x2 ("Lol",3323131,45,46.8);
  Vendedor x3 ("Juan", 33181923,70,45.9);
   x1.datos();
   cout<<endl;
   x2.datos();
   cout<<endl;
   x3.datos();*/
 Login usuario;

    while (true) {
        usuario.Menu();
        int opcion; cin >> opcion;

        switch (opcion) {
            case 1:
                usuario.login();
                break;
            case 2:
                usuario.logout();
                break;
            case 3:
                usuario.cambiarContraseña();
                break;
            case 4:
                cout << "Saliendo del programa.\n";
                return 0;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }
    }

    return 0;
   
}