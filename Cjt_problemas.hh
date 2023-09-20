/** @file Cjt_problemas.hh
    @brief Especificación de la clase Cjt_problemas
*/


#ifndef _CJT_PROBLEMAS_HH_
#define _CJT_PROBLEMAS_HH_

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <map>
#endif


#include "Problema.hh"


/** @class Cjt_problemas
    @brief Representa un conjunto de problemas

		Ofrece operaciones para modificar, consultar, leer y escribir un conjunto de problemas.
*/

class Cjt_problemas
{
public:

  //Constructoras

  /** @brief Creadora por defecto.

			Se ejecuta automáticamente al declarar un conjunto de problemas.
      \pre <em>cierto</em>
      \post El resultado es un conjunto de problemas vacío
  */
  Cjt_problemas();


  // Consultoras

  /** @brief Consulta si el problema está en el cjt_problemas

      \pre <em>cierto</em>
      \post El resultado es true si el problema está y false si no existe
      ningun problema con ese identificador.
  */
  bool buscar_problema(string p) const;

  /** @brief Consulta el total de problemas que hay en un cjt de problemas
      \pre <em>cierto</em>
      \post El resultado es el número total de problemas que hay en el cjt de problemas.
  */
  int total_cjt_problemas() const;


  //Modificadoras

  /** @brief Añade un nuevo problema a un conjunto de problemas

  \pre <em>cierto</em>
  \post Se añade un problema al conjunto de problemas ordenado por su identificador
	en el caso que no existe ningun problema con el mismo identicador y devuelve
	true. Altramente, devuelve false.
 */
  bool nuevo_problema(string idenp);

  /** @brief Actualiza los parámetros de un problema después de enviar una
  posible solución.
      \pre Existe el problema p.
      \post Se actualiza las estadisticas del problema p después de enviar
      una solución.
  */
  void actualizar_problema(string p, int resultado);


  //Escritura

  /** @brief Operación de escritura de los problemas de la colecció de problemas

      \pre <em>cierto</em>
      \post Se listan los problemas de la colección, indicando para cada problema
      el número t de envíos totales y el número e de envíos con éxito a dicho
      problema, en ambos casos de usuarios presentes o pasados. También se ha de
      escribir el ratio (t + 1)/(e + 1), y los problemas han de listarse en
      orden creciente por dicho ratio. En caso de empate, se han de listar por
      orden creciente de identificador.
  */
  void escribir_cjt_problemas();

  /** @brief Operación de escritura de un problema

      \pre El problema p existe en la plataforma.
      \post Se escribe el identificador del problema p indicando el número t de
      envíos totales y el número e de envíos con éxito. También se ha de
      escribir el ratio (t + 1)/(e + 1).
  */
  void escribir_problema(string p);


  //Lectura

  /** @brief Operación de lectura de un numero de problemas

      \pre <em>cierto</em>
      \post Se han leido los parametros de la entrada y se guardan en el
			conjunto de problemas.
  */
  void leer_cjt_problemas();

private:
	/** @brief Map de los problemas de la plataforma.

	Ordenado por el identificador de los problemas. */
  map<string, Problema> c_problema;

	//Modificadora

	/** @brief Operación de ordenación de un vector

			\pre El vector no está vacío.
			\post Se ordenan los elementos de un vector de pairs, en primer lugar por
			el ratio de (envíos totales + 1)/(envíos con éxito + 1) en orden creciente
			y en el caso que sea el mismo por su identificador.
	*/
	static bool comp(const pair<string,double>& num1, const pair<string,double>& num2);


	//Consultora

	/** @brief Consulta el número de envíos a un problema

			\pre El problema p existe en la plataforma.
			\post El resultado es el número de envíos al problema p.
	*/
	int consultar_envios2(const string p) const;

	/** @brief Consulta el número correcto de envíos a un problema.

			\pre El problema p existe en la plataforma.
			\post El resultado es el número de envíos correctos del problema p.
	*/
	int consultar_en_correctos2(const string p) const;
};
#endif
