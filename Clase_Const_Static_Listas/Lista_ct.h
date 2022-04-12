#include "global.h"
#define MAX 5

#include "cBarcos.h"
/// <summary>
/// Unlisted: Sin listar, es decir, desordenado, puede haber
/// NULLs entre nodo y nodo.
/// </summary>

class cUnlistedBarcos {
	private:
		bool eliminarNodos;
		cBarcos** MiFlota;
	public:
		cUnlistedBarcos(unsigned int longitud, bool eliminar);
		~cUnlistedBarcos();
		
		/// <summary>
		/// Agrega un nodo en la lista en la posicion
		/// que valga null
		/// </summary>
		/// <param name="Valor"></param>
		/// <returns>True/False</returns>
		bool Agregar(cBarcos* NuevoNodo);
	#pragma region Metodos_Modificar
		/// <summary>
		/// Modifica el nodo de la lista en la posicion indicada por el parametro Posicion
		/// </summary>
		/// <param name="Posicion"></param>
		/// <param name="NuevoValor"></param>
		/// <returns>True/False</returns>
		bool Modificar(int Posicion, cBarcos* NuevoValor);

		/// <summary>
		/// Modifica el nodo de la lista en la posicion indicada por el parametro ID_Barco
		/// </summary>
		/// <param name="ID_Barco"></param>
		/// <param name="NuevoValor"></param>
		/// <returns>True/False</returns>
		bool Modificar(unsigned int ID_Barco, cBarcos* NuevoValor);

		/// <summary>
		/// Modifica el nodo de la lista en la posicion indicada por el parametro ptr_Barco
		/// </summary>
		/// <param name="ptr_Barco"></param>
		/// <param name="NuevoValor"></param>
		/// <returns>True/False</returns>
		bool Modificar(cBarcos* ptr_Barco, cBarcos* NuevoValor);
	#pragma endregion
	#pragma region Metodos_Eliminar
		/// <summary>
		/// Elimina un nodo de la lista en la posicion indicada por el parametro Posicion.
		/// </summary>
		/// <param name="Posicion"></param>
		/// <returns>True/False</returns>
		bool Eliminar(int Posicion);

		/// <summary>
		/// Elimina un nodo de la lista en la posicion indicada por el parametro ID_Barco
		/// </summary>
		/// <param name="ID_Barco"></param>
		/// <returns>True/False</returns>
		bool Eliminar(unsigned int ID_Barco);

		/// <summary>
		/// Elimina un nodo de la lista en la posicion indicada por el parametro ptr_Barco
		/// </summary>
		/// <param name="MiBarco"></param>
		/// <returns>True/False</returns>
		bool Eliminar(cBarcos* MiBarco);
	#pragma endregion
	#pragma region Metodos_Quitar
		/// <summary>
		/// Quita un nodo de la lista en la posicion indicada por el parametro Posicion.
		/// </summary>
		/// <param name="Posicion"></param>
		/// <returns>Puntero cBarcos/NULL</returns>
		cBarcos* Quitar(int Posicion);

		/// <summary>
		/// Quita un nodo de la lista en la posicion indicada por el parametro ID_Barco.
		/// </summary>
		/// <param name="ID_Barco"></param>
		/// <returns>Puntero cBarcos/NULL</returns>
		cBarcos* Quitar(unsigned int ID_Barco);

		/// <summary>
		/// Quita un nodo de la lista en la posicion indicada por el parametro MiBarco.
		/// </summary>
		/// <param name="MiBarco"></param>
		/// <returns>Puntero cBarcos/NULL</returns>
		cBarcos* Quitar(cBarcos* MiBarco);
	#pragma endregion
	#pragma region Metodos_Buscar
		/// <summary>
		/// Busca un nodo de la lista en la posicion indicada por el parametro Posicion.
		/// </summary>
		/// <param name="Posicion"></param>
		/// <returns>Posicion del Barco</returns>
		int Buscar(unsigned int ID_Barco);

		/// <summary>
		/// Busca un nodo de la lista en la posicion indicada por el parametro ID_Barco.
		/// </summary>
		/// <param name="ID_Barco"></param>
		/// <returns>Posicion del Barco</returns>
		int Buscar(cBarcos*);
	#pragma endregion
	#pragma region Metodos_Filtrar
		/// <summary>
		/// Filtra que Barcos en la lista tienen la eslora buscada
		/// </summary>
		/// <param name="FiltroEslora"></param>
		/// <returns>cBarcos**/NULL</returns>
		cBarcos** Filtrar(unsigned int FiltroEslora);

		/// <summary>
		/// Filtra que Barcos en la lista tienen el fabricante buscado
		/// </summary>
		/// <param name="FiltroEslora"></param>
		/// <returns>cBarcos**/NULL</returns>
		cBarcos** Filtrar(string fabricante);
	#pragma endregion
	// Imprimir
		void Imprimir();
			
		//void Redimension(int);
};