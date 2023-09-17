/** @file Cjt_sesiones.hh
    @brief Especificación de la clase Cjt_sesiones
*/


#ifndef _CJT_SESIONES_HH_
#define _CJT_SESIONES_HH_

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#include <map>
#endif


#include "Sesion.hh"
#include "Usuario.hh"

/** @class Cjt_sesiones
    @brief Representa un conjunto de sesiones

		Ofrece operaciones para modificar, consultar, leer y escribir un conjunto de sesiones.
*/


class Cjt_sesiones
{
public:

  //Constructoras

  /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un conjunto de sesiones.
      \pre <em>cierto</em>
      \post El resultado es un conjunto de sesiones vacío.
  */
  Cjt_sesiones();


  //Modificadoras

  /** @brief Añade una nueva sesion al conjunto de sesiones

  \pre El parametro implicito no contiene ninguna sesion con
  el identificador idens.
  \post Se añade una sesion al conjunto de sesiones de la plataforma.
 */
  bool nueva_sesion(string idens);


  //Consultora

  /** @brief Consulta el total de sesiones que hay en un cjt de sesiones
      \pre <em>cierto</em>
      \post El resultado es el número total de sesiones que hay en el conjunto
			de sesiones.
  */
  int total_cjt_sesiones() const;

  /** @brief Consulta si la sesion s está en el cjt de sesiones

      \pre <em>cierto</em>
      \post El resultado es true si la sesión está y false si no existe
      ninguna sesión con ese identificador.
  */
  bool buscar_sesion(string iden) const;

  /** @brief Consulta el identificador de una sesion

      \pre Existe una sesión con identificador s
      \post Devuelve el identificador de la sesion s donde esta el problema p.
  */
  bool buscar_prob_ses(string iden, string p) const;

	/** @brief Consulta el primer problema de la sesion ses

			\pre <em>cierto</em>
			\post Devuelve el identificador del primer problema de la sesión ses, el cual
			no tiene prerequisitos.
	*/
	string buscar_raiz(string ses) const;

	/** @brief Consulta el identificador de la sesión ses

			\pre <em>cierto</em>
			\post Devuelve el identificador de la sesión que ocupa la posicion
			determinada por el parámetro "posicion".
	*/
	string devolver_sesion(string ses, int posicion) const;

	/** @brief Consulta el total de problemas de la sesion ses

			\pre Existe la sesión ses.
			\post Devuelve el número total de problemas que contiene la sesión ses.
	*/
	int problemas_totales(string ses) const;

	/** @brief Actualiza los problemas enviables en un envio de la sesion ses.

			\pre <em>cierto</em>
			\post Se actualizan los problemas enviables del usuario usu después de
			un comando de envío, los problemas pertenecen a la sesión ses.
	*/
	bool buscar_interseccion(const string p, const string ses, Usuario& usu);

	/** @brief Actualiza los problemas enviables al inscribir el usuario a un
	curso de la sesion ses.

			\pre <em>cierto</em>
			\post Se actualizan los problemas enviables pertenecientes a la sesion
			ses del usuario usu después de inscribir el usuario en un curso nuevo.
	*/
	bool buscar_interseccion_inscribirse(const string p, const string ses, Usuario& usu);


  //Escritura

  /** @brief Operación de escritura de las sesiones actuales en la plataforma

      \pre <em>cierto</em>
      \post Se escribe ordenadas crecientemente por identificador las sesiones
      de la plataforma junto con el num. de problemas que la forman y los
      identificadores de dichos problemas siguiendo la estructura de
      prerequisitos.
  */
  void escribir_cjt_sesiones();

  /** @brief Operación de escritura de una sesion de la plataforma

      \pre La sesion s existe en la plataforma.
      \post Se escribe el identificador de la sesion junto al num. de problemas
      que la forman y sus identificadores siguiendo el orden de prerequisitos.
  */
  void escribir_sesion(string s);


  //Lectura

  /** @brief Operación de lectura de un numero de sesiones

      \pre <em>cierto</em>
      \post Se han leido los parametros de la entrada y guardado
      en el conjunto de sesiones de la plataforma.
  */
  void leer_cjt_sesiones();

private:
	/** @brief Map de las sesiones de la plataforma.

	Ordenado por el identificador de las sesiones. */
  map<string, Sesion> c_sesion;
};
#endif
