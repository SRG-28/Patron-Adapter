#include<iostream>     //Adapter con delegacion
#include<sstream>
using namespace std;

class Motor {
public:
	virtual void encender() = 0;
	virtual void acelerar() = 0;
	virtual void apagar() = 0; //MVP 
};

class MotorGaston  : public Motor{
public:
	MotorGaston() {   //constrctor 
		cout << "Creando un motor gaston" << endl;
	}
	void encender(){
		cout << "Encendiendo el motor gaston" << endl;
	}
	void acelerar() {
		cout << "Acelerando el motor gaston" << endl;
	}
	void apagar() {
		cout << "Apagando el motor gaston" << endl;
	}
};


class MotorEconomico : public Motor {
public:
	MotorEconomico() {   //constrctor 
		cout << "Creando un motor economico" << endl;
	}
	void encender() {
		cout << "Encendiendo el motor economico" << endl;
	}
	void acelerar() {
		cout << "Acelerando el motor economico" << endl;
	}
	void apagar() {
		cout << "Apagando el motor economico" << endl;
	}
};

//Aqui vamos a crear un motor electrico que nada tiene que ver con la herencia anterior
//pero hay que adaptarlo
class MotorElectrico {  //Adaptee... (no se debe cambiar...)
private:
	bool conectado;
public:
	MotorElectrico() { //constructor
		cout << "Creando motor electrico" << endl;
		conectado = false;
	}

	void conectar() {
		cout << "Conectando un motor electrico..." << endl;
		conectado = true;
	}

	void activa() {
		if (conectado)
			cout << "Activando un motor electrico..." << endl;
		else
			cout << "No se puede activar, no esta conectado el motor" << endl;
	}

	void moverMasRapido() {
		if (conectado)
			cout << "Moviendose mas rapido...aumentando voltaje" << endl;
		else
			cout << "No se puede mover mas rapido porque no esta conectado" << endl;
	}

	void detener() {
		if (conectado)
			cout << "Deteniendo el motor electrico" << endl;
		else
			cout << "No se puede detener el motor porque no esta conectado" << endl;
	}
	void desconectar() {
		cout << "Desconectando el motor electrico" << endl;
		conectado = false;
	}
};

//Aqui realizaremos la clase que nos ayuda a adaptar la clase MotorElectrico a la Hernecia
//Esta es la clase que se incluye simulando que es motorElectrico
class MotorElectricoAdapter : public Motor {
private:
	MotorElectrico * mot;
public:
	MotorElectricoAdapter() { //constructor
		mot = new MotorElectrico();
		cout << "Creando un motor electrico adapter" << endl;
	}

	void encender() {
		cout << "Encendiendo el motor electrico adapter" << endl;  
		mot->conectar();  //estas dos acciones son lo equivalente a encender
		mot->activa();
	}

	void acelerar() {
		cout << "Acelerando motor electrico adapter" << endl;
		mot->moverMasRapido();
	}

	void apagar() {
		cout << "Apagando el motor electrico adapter" << endl;
		mot->detener();
		mot->desconectar();
	}
};

//-------------------------------MAIN-----------------------------------------
int main() {
	Motor* motor1 = new MotorEconomico();
	motor1->encender();
	motor1->acelerar();
	motor1->apagar();
	cout << endl << endl;
	cout << "-------------------------------------------------------------------" <<endl;
	Motor* motor2 = new MotorGaston();
	motor2->encender();
	motor2->acelerar();
	motor2->apagar();
	cout << endl << endl;
	cout << "-------------------------------------------------------------------" << endl;
	Motor* motor3 = new MotorElectricoAdapter();
	motor3->encender();
	motor3->acelerar();
	motor3->apagar();
	cout << endl << endl;
	cout << "-------------------------------------------------------------------" << endl;

	delete motor1;
	delete motor2;
	delete motor3;
	system("pause");
	return 0;
}
