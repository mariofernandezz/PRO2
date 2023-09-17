/** @file Cjt_usuarios.hh
    @brief Especificación de la clase Cjt_usuarios
*/


#ifndef _CJT_USUARIOS_HH_
#define _CJT_USUARIOS_HH_

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#include <map>
#endif

#include "Usuario.hh"
#include "Cjt_sesiones.hh"
#include "Cjt_cursos.hh"


/** @class Cjt_usuarios
    @brief Representa un conjunto de usuarios

		Ofrece operaciones para modificar, consultar, leer y escribir un conjunto de usuarios.
*/

class Cjt_usuarios
{
public:

  //Constructoras

  /** @brief Creadora por defecto.

			Se ejecuta automáticamente al declarar un conjunto de usuarios.
      \pre <em>cierto</em>
      \post El resultado es un conjunto de usuarios vacío
  */
  Cjt_usuarios();


  //Modificadoras

  /** @brief Añade un nuevo usuario a un conjunto de usuario

      \pre El parametro implicito no contiene ningun usuario con el
      identificador idenu.
      \post Se añade un usuario al conjunto de usuarios de la plataforma
  */
  bool alta_usuario(string idenu);

  /** @brief Da de baja un usuario del conjunto de usuarios

      \pre Existe el usuario u en el cjt de usuarios
      \post El conjunto de usuarios pasa a tener un usuario menos y todos los
			datos del usuario borrado desaparecen.
  */
  void baja_usuario(const string u);

  /** @brief Actualiza los parámetros de un usuario después de enviar una
  solución a un problema.

      \pre El usuario existe y el problema enviado estaba en los problemas enviables.
      \post Se actualiza las estadisticas del usuario u después de enviar
      una solución.
  */
  void actualizar_usuario(string u, string p, int resultado, Cjt_sesiones& cs, Cjt_cursos& cc);

	/** @brief Actualiza los parámetros de un usuario después de inscribirlo en
	un curso nuevo.

			\pre El usuario existe y no está registrado en ningun curso y el curso
			existe.
			\post Se actualiza las estadisticas del usuario u después de inscribirse
			en un curso nuevo, actualizando también los problemas enviables de los
			que dispone el usuario.
	*/
	void inscribir(string u, int curs, Cjt_cursos& cc, Cjt_sesiones& cs);


  // Consultoras

  /** @brief Consulta si el usuario está inscrito en algun curso

      \pre Existe el usuario u.
      \post Indica true si el usuario u esta registrado en algun curso y false
      altramente.
  */
  bool consul_insc(const string u) const;


  /** @brief Consulta si el usuario u está en el cjt usuarios

      \pre <em>cierto</em>
      \post El resultado es true si el usuario está y false si no existe
      ningun usuario con ese identificador.
  */
  bool buscar_usuario(string u) const;

  /** @brief Consulta el identificador del curso en el que está incrito el usuario
        \pre Existe el usuario u.
        \post Devuelve el identificador del curso en el que está inscrito el usuario,
				sino pertenence a ningun curso devuelve un 0.
  */
  int consul_iden_usu(string u) const;

  /** @brief Consulta el total de usuarios
        \pre <em>cierto</em>
        \post Devuelve el total de usuarios que hay en el cjt usuario.
  */
  int total_cjt_usuarios() const;

	/** @brief Consulta si el curso u ha sido completado por el usuario

			\pre <em>cierto</em>
			\post El resultado es true si ya no hay mas problemas enviables y por
			tanto el curso u ha sido completado y si aun quedan problemas enviables
			es false.
	*/
  bool curso_acabado(string u) const;


  //Escritura

  /** @brief Operación de escritura de problemas enviables que tiene un usuario

      \pre <em>cierto</em>
      \post Se han escrito los problemas que el usuario no ha resuelto todavia
      pero tiene acceso a ellos
  */
  void cjt_problemas_enviables(string u);

  /** @brief Operación de escritura de usuarios registrados en la plataforma
  actualmente

      \pre <em>cierto</em>
      \post Se escribe los identificadores de los usuarios registrados en la
      plataforma actualmente ordenados crecientemente por su nombre y mostrando,
      para cada usuario, cuántos envíos en total ha realizado, cuántos
      problemas ha resuelto satisfactoriamente, cuántos problemas ha intentado
      resolver (al menos ha hecho un envío), y el identificador del curso en el
      que está inscrito o un cero si no está inscrito en ninguno.
  */
  void escribir_cjt_usuarios();

  /** @brief Operación de escritura de un usuario de la plataforma

      \pre Existe el usuario u en la plataforma
      \post Se escribe el nombre del usuario mostrando cuántos envíos en total
      ha realizado, cuántos problemas ha resuelto satisfactoriamente, cuántos
      problemas ha intentado resolver (al menos ha hecho un envío), y el
      identificador del curso en el que está inscrito o un cero si no está
      inscrito en ninguno.
  */
  void escribir_usuario(const string u);

  /** @brief Operación de escritura de problemas resueltos por el usuario

      \pre El usuario con iden. u existe en la plataforma.
      \post Se han escrito los problemas solucionados por el usuario u en orden
      creciente por identificador y el número de intentos realizados por
      problema.
  */
  void cjt_problemas_resueltos(string u);


  //Lectura

  /** @brief Operación de lectura de un numero de usuarios

      \pre <em>cierto</em>
      \post Se han leido los parametros de la entrada y guradado
      en un el conjunto de usuarios de la plataforma.
  */

  void leer_cjt_usuarios();

private:
	/** @brief Map de los usuarios de la plataforma.

	Ordenado por el identificador de los usuarios. */
  map<string, Usuario> c_usuario;
};
#endif
