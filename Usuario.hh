/** @file Usuario.hh
    @brief Especificación de la clase Usuario
*/


#ifndef _USUARIO_HH_
#define _USUARIO_HH_

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#include <map>
#endif

#include "Problema.hh"

/** @class Usuario
    @brief Representa un usuario de la plataforma

		Ofrece operaciones para modificar, consultar, leer y escribir un usuario.
*/

class Usuario
{
public:
  //Constructoras

  /** @brief Creadora por defecto.

			Se ejecuta automáticamente al declarar un usuario.
      \pre <em>cierto</em>
      \post El resultado es un usuario con todo inicializado a 0.
  */
  Usuario();


  //Modificadoras

  /** @brief Actualiza el registro del usuario

      \pre El usuario no estaba registrado en algun curso.
      \post El usuario pasa a estar registrado en el curso c y se guarda el
			identificador de ese curso.
  */
  void registrar_usuario(int c);

	/** @brief Actualiza los intentos.

      \pre El usuario está registrado en algun curso.
      \post Se le suma 1 al número de intentos del usuario.
  */
	void sumar_intentos(string p);

	/** @brief Actualiza los aciertos.

      \pre El usuario está registrado en algun curso.
      \post Se le suma 1 al número de aciertos del usuario.
  */
	void sumar_aciertos(string p);

	/** @brief Actualiza el registro.

			\pre El usuario está registrado en algun curso
			\post El usuario pasa a no pertenecer a ningun curso.
	*/
  void baja_usuario_2();

	/** @brief Calcula cuantos problemas ha intentado resolver

			\pre <em>cierto</em>
			\post El resultado es el número de problemas que ha intantado resolver
			al menos una vez.
	*/
	int intentos_problemas();

	/** @brief Actualiza los problemas enviables.

			\pre El usuario está registrado en algun curso y el problema p nunca ha
			sido resuelto por el usuario.
			\post El map de enviables (envi) se actualiza con el nuevo problema enviable p.
	*/
	void insertar_enviable(string p);

	/** @brief Actualiza los problemas enviables.

			\pre El usuario está registrado en algun curso y el problema p acaba de ser
			resuelto.
			\post Al map de enviables se le quita el problema con identificador p
			que ya ha sido resuelto.
	*/
	void restar_enviable(string p);



  //Consultoras

  /** @brief Consulta los problemas realizados correctamente

      \pre <em>cierto</em>
      \post El resultado es el número de problemas resultos correctamente.
  */
  int intentos_correctos() const;

  /** @brief Consulta los envios totales

      \pre <em>cierto</em>
      \post El resultado es el número de envios de posibles totales a todos los
      problemas.
  */
  int intentos_envios() const;

  /** @brief Consulta si el usuario está registrado en algun curso

      \pre <em>cierto</em>
      \post El resultado true si está registrado en algun curso y false
      altramente.
  */
  bool consultar_registro() const;

  /** @brief Consulta el identificador del Curso donde está registrado

      \pre <em>cierto</em>
      \post El resultado es el identificador del curso donde está inscrito
      el usuario.
  */
  int id_registro() const;

	/** @brief Consulta si el curso ha sido completado por el usuario

			\pre <em>cierto</em>
			\post El resultado es true si ya no hay más problemas por resolver y por
			tanto el curso ha sido completado y si aun quedan problemas enviables
 			es false.
	*/
  bool curso_acabado_2() const;

	/** @brief Consulta si el problema ya está resuelto

			\pre <em>cierto</em>
			\post El resultado es true si el problema ya ha sido resuelto por el
			usuario y por tanto no puedo volver a ser resuelto y false si aun no lo
			ha resuelto.
	*/
	bool comprovar_historico(string p) const;


  //Escritura

  /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se escriben los problemas resueltos por el usuario.
  */
  void escribir_resul();

	/** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se escriben los problemas que son enviables por el usuario.
  */
	void escribir_enviables();



private:
/** @brief Indica si el usuario esta registrado en algun curso: regsitrado(true)
y no registrado (false) */
bool registrado;
/** @brief Identificador del curso en el que está registrado */
int curs;
/** @brief Intentos totales del usuario por resolver algun problema */
int intentos;
/** @brief Total de problemas resueltos con éxito */
int aciertos;
/** @brief Total de problemas intentados al menos una vez */
int problemas_tot;

/** @brief Map de los problemas resueltos por el usuario

Contiene el identificador de los problemas ordenados por su identificador y
sus estadísticas */
map<string, Problema> res;

/** @brief Map de los problemas que son enviables por el usuario

Contiene el identificador de los problemas ordenados por su identificador y
sus estadísticas */
map<string, Problema> envi;

};
#endif
