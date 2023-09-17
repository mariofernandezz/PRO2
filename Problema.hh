/** @file Problema.hh
    @brief Especificación de la clase Problema
*/


#ifndef _PROBLEMA_HH_
#define _PROBLEMA_HH_

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

/** @class Problema
    @brief Representa un problema de la plataforma

		Ofrece operaciones para modificar y consultar un problema.
*/

class Problema
{
public:
  //Constructoras

  /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un problema.
      \pre <em>cierto</em>
      \post El resultado es un problema sin inicializar.
  */
  Problema();

	/** @brief Creadora con valores concretos.

			\pre <em>cierto</em>
			\post El resultado es un problema con el numero de intentos totales igual a tot.
	*/
	Problema(int tot);


	//Modificadoras

	/** @brief Actualiza el número de veces que ha sido resuelto el problema.

			\pre <em>cierto</em>
			\post Suma uno al número de veces que ha sido resuelto el problema.
	*/
	void sumar_aciertos_2();

	/** @brief Actualiza el número de veces que se ha intentado resolver.

			\pre <em>cierto</em>
			\post Suma uno al número de veces que se ha intentado resolver el
			problema.
	*/
	void sumar_intentos_2();



  //Consultoras


  /** @brief Consulta el número de envíos a un problema

      \pre <em>cierto</em>
      \post El resultado es el número de envíos al problema.
  */
  int consultar_envios() const;

  /** @brief Consulta el número correcto de envíos a un problema.

      \pre <em>cierto</em>
      \post El resultado es el número de envíos correctos al problema.
  */
  int consultar_en_correctos() const;



private:
	/** @brief Intentos totales de respuesta a este problema */
  int totales;
	/** @brief Intentos totales correctos de respuesta a este problema */
  int correctos;
};
#endif
