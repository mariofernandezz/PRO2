/** @file Sesion.hh
    @brief Especificación de la clase Sesion
*/


#ifndef _SESION_HH_
#define _SESION_HH_

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#include <vector>
#include "BinTree.hh"
#endif


#include "Usuario.hh"

/** @class Sesion
    @brief Representa una sesión de la plataforma

		Ofrece operaciones para modificar, consultar, leer y escribir una sesión.
*/

class Sesion
{
public:
  //Constructoras

  /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar una sesion.
      \pre <em>cierto</em>
      \post El resultado es una sesion sin inicializar.
  */
  Sesion();


  //Modificadoras

	/** @brief Actualiza los problemas enviables en un envio

			\pre El usuario existe y está registrado en algun curso y tiene el problema
			p como enviable.
			\post Se actualizan los problemas enviables del usuario usu después de
			un comando de envío.
	*/
	bool buscar_interseccion_2(string p, Usuario& usu);

	/** @brief Actualiza los problemas enviables al inscribir el usuario a un curso

			\pre El usuario usu existe y se está registrando en algun curso.
			\post Se actualizan los problemas enviables del usuario usu después de
			inscribir el usuario en un curso nuevo.
	*/
	bool buscar_interseccion_inscribirse_2(string p, Usuario& usu);


  //Consultoras

  /** @brief Consulta si existe el problema en la sesión

      \pre <em>cierto</em>
      \post El resultado es true si el problema p se encuentra en la sesión y
			false si no existe.
  */
  bool buscar_prob_sesion(string p) const;

  /** @brief Consulta el total de problemas de una sesion

      \pre <em>cierto</em>
      \post Devuelve el número total de problemas que contiene la sesión.
  */
  int tot_problemas() const;

	/** @brief Consulta el primer problema de la sesion

			\pre <em>cierto</em>
			\post Devuelve el identificador del primer problema de la sesión el cual
			no tiene prerequisitos.
	*/
	string raiz() const;

	/** @brief Consulta el identificador de una sesion

			\pre Hay al menos un número de sesiones igual a posicion.
			\post Devuelve el identificador de la sesión que ocupa la posicion
			determinada por el parámetro "posicion".
	*/
	string devolver_sesion_2(int posicion) const;


  //Escritura

  /** @brief Operación de escritura de una sesion

      \pre La sesion existe.
      \post Se escribe los problemas de la sesión ordenados por sus
      prerequisitos.
  */
  void escribirses();


  //Lectura

  /** @brief Operación de lectura de una sesion

      \pre <em>cierto</em>
      \post Se han leido los parametros de la entrada y guardado en una
			variable Sesion.
  */
  void leer_sesion();


private:
	/** @brief Problemas totales de los que consta la sesión*/
  int problemas_totales;
	/** @brief BinTree de los problemas.

	Ordenados en preorden con prerequisitos */
  BinTree<string> requisitos;
	/** @brief Identificadores de los problemas(para que acceder a todos sea
	más fácil)*/
	vector<string> prob;

  //Lectura

  /** @brief Operación de lectura de una sesion

      \pre <em>cierto</em>
      \post Se han leido los parametros de la entrada y guardado
      en una variable Sesion.
  */
  void leer(BinTree<string>& a, string marca);

  //Escritura

  /** @brief Operación de escritura de una sesion

      \pre La sesion existe.
      \post Se escribe los problemas de la sesión ordenados por sus
      prerequisitos.
  */
  static void escribir(const BinTree<string> &requisitos);


	//Consultoras

	/** @brief Consulta si el problema p esta en la seión

			\pre <em>cierto</em>
			\post El resultado es true si el problema existe en la sesión y false
			si no existe.
	*/
	static bool buscar(const BinTree<string>& a,string p);


	//Modificadoras

	/** @brief Actualiza los problemas enviables en un envio

			\pre El usuario existe y está registrado en algun curso y tiene el problema
			p como enviable.
			\post Se actualizan los problemas enviables del usuario usu después de
			un comando de envío.
	*/
	static bool buscar_int(const BinTree<string>& a, string p, Usuario& usu);

	/** @brief Actualiza los problemas enviables al inscribir el usuario a un curso

			\pre El usuario usu existe y se está registrando en algun curso.
			\post Se actualizan los problemas enviables del usuario usu después de
			incribir el usuario en un curso nuevo.
	*/
	static bool buscar_int_insc(const BinTree<string>& a, string p, Usuario& usu);

};
#endif
