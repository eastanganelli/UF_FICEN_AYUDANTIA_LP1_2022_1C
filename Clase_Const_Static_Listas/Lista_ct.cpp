#include "Lista_ct.h"

cUnlistedBarcos::cUnlistedBarcos(unsigned int longitud = MAX, bool eliminar = false) {
	this->eliminarNodos = eliminar;
	this->MiFlota = new cBarcos * [longitud];
	cBarcos::set_ct(longitud);
	for (unsigned int i = 0; i < cBarcos::get_ct(); i++)
		this->MiFlota[i] = NULL;
}

cUnlistedBarcos::~cUnlistedBarcos() {
	if (eliminarNodos) {
		for (unsigned int i = 0; i < cBarcos::get_ct(); i++)
			if (this->MiFlota[i] != NULL)
				delete this->MiFlota[i];
	}
	delete[] this->MiFlota;
	cBarcos::set_ct(0);
}

bool cUnlistedBarcos::Agregar(cBarcos* NuevoNodo) {
	for (unsigned int i = 0; i < cBarcos::get_ct(); i++) {
		if (this->MiFlota[i] == NULL) {
			this->MiFlota[i] = NuevoNodo;
			return true;
		}
	} return false;
}

#pragma region Metodos_Modificar
bool cUnlistedBarcos::Modificar(int Posicion, cBarcos* NuevoValor) {
	if (Posicion >= 0 && this->MiFlota[Posicion] != NULL) {
		cBarcos* Aux = this->MiFlota[Posicion];
		this->MiFlota[Posicion] = NuevoValor;
		delete Aux;
		return true;
	} return false;
}

bool cUnlistedBarcos::Modificar(unsigned int ID_Barco, cBarcos* NuevoValor) {
	for (int i = 0; i < cBarcos::get_ct(); i++) {
		if (this->MiFlota[i] != NULL && this->MiFlota[i]->get_ID() == ID_Barco) {
			cBarcos* Aux = this->MiFlota[i];
			this->MiFlota[i] = NuevoValor;
			delete Aux;
			return true;
		}
	} return false;
}

bool cUnlistedBarcos::Modificar(cBarcos* ptr_Barco, cBarcos* NuevoValor) {
	for (int i = 0; i < cBarcos::get_ct(); i++) {
		if (this->MiFlota[i] != NULL && this->MiFlota[i] == ptr_Barco) {
			cBarcos* Aux = this->MiFlota[i];
			this->MiFlota[i] = NuevoValor;
			delete Aux;
			return true;
		}
	} return false;
}
#pragma endregion

#pragma region Metodos_Eliminar
bool cUnlistedBarcos::Eliminar(int Posicion) {
	if (Posicion >= 0 && this->MiFlota[Posicion] != NULL) {
		delete this->MiFlota[Posicion];
		this->MiFlota[Posicion] = NULL;
		return true;
	} return false;
}

bool cUnlistedBarcos::Eliminar(unsigned int ID_Barco) {
	for (int i = 0; i < cBarcos::get_ct(); i++) {
		if (this->MiFlota[i] != NULL && this->MiFlota[i]->get_ID() == ID_Barco) {
			delete this->MiFlota[i];
			this->MiFlota[i] = NULL;
			return true;
		}
	} return false;
}

bool cUnlistedBarcos::Eliminar(cBarcos* MiBarco) {
	for (int i = 0; i < cBarcos::get_ct(); i++) {
		if (this->MiFlota[i] != NULL && this->MiFlota[i] == MiBarco) {
			delete this->MiFlota[i];
			this->MiFlota[i] = NULL;
			return true;
		}
	} return false;
}
#pragma endregion

#pragma region Metodos_Quitar
cBarcos* cUnlistedBarcos::Quitar(int Posicion) {
	if (Posicion >= 0 && this->MiFlota[Posicion] != NULL) {
		cBarcos* Aux = this->MiFlota[Posicion];
		this->MiFlota[Posicion] = NULL;
		return Aux;
	} return NULL;
}

cBarcos* cUnlistedBarcos::Quitar(unsigned int ID_Barco) {
	for (int i = 0; i < cBarcos::get_ct(); i++) {
		if (this->MiFlota[i] != NULL && this->MiFlota[i]->get_ID() == ID_Barco) {
			cBarcos* Aux = this->MiFlota[i];
			this->MiFlota[i] = NULL;
			return Aux;
		}
	} return NULL;
}

cBarcos* cUnlistedBarcos::Quitar(cBarcos* MiBarco) {
	for (int i = 0; i < cBarcos::get_ct(); i++) {
		if (this->MiFlota[i] != NULL && this->MiFlota[i] == MiBarco) {
			cBarcos* Aux = this->MiFlota[i];
			this->MiFlota[i] = NULL;
			return Aux;
		}
	} return NULL;
}
#pragma endregion

#pragma region Metodos_Buscar
int cUnlistedBarcos::Buscar(unsigned int ID_Barco) {
	for (int i = 0; i < cBarcos::get_ct(); i++)
		if (this->MiFlota[i] != NULL && this->MiFlota[i]->get_ID() == ID_Barco)
			return i;
	return -1;
}

int cUnlistedBarcos::Buscar(cBarcos* ptr_Barco) {
	for (int i = 0; i < cBarcos::get_ct(); i++)
		if (this->MiFlota[i] != NULL && this->MiFlota[i] == ptr_Barco)
			return i;
	return -1;
}
#pragma endregion

#pragma region Metodos_Filtrar
cBarcos** cUnlistedBarcos::Filtrar(unsigned int FiltroEslora) {
	cBarcos** Aux = NULL;
	Aux = new cBarcos * [cBarcos::get_ca()];

	if (Aux != NULL) {
		for (int i = 0; i < cBarcos::get_ct(); i++)
			if (this->MiFlota[i] != NULL && this->MiFlota[i]->get_eslora() == FiltroEslora)
				Aux[i] = this->MiFlota[i];
	}
	return Aux;
}

cBarcos** cUnlistedBarcos::Filtrar(string fabricante) {
	cBarcos** Aux = NULL;
	Aux = new cBarcos * [cBarcos::get_ca()];

	if (Aux != NULL) {
		for (int i = 0; i < cBarcos::get_ct(); i++)
			if (this->MiFlota[i] != NULL && this->MiFlota[i]->get_fabricante() == fabricante)
				Aux[i] = this->MiFlota[i];
	}
	return Aux;
}
#pragma endregion

void cUnlistedBarcos::Imprimir() {
	cout << "Mi Listado: " << endl;
	for (unsigned int i = 0; i < cBarcos::get_ct(); i++)
		if (this->MiFlota[i] != NULL) {
			cout << this->MiFlota[i]->get_nombre() << " " <<
					this->MiFlota[i]->get_codigoBarco() << " " <<
					this->MiFlota[i]->get_fechaFabricacion() << " " <<
					this->MiFlota[i]->get_fabricante() << endl;
		}
	cout << endl;
}