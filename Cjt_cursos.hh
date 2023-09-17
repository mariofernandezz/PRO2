/** @file Cjt_cursos.hh
    @brief Especificación de la clase Cjt_cursos
*/


#ifndef _CJT_CURSOS_HH_
#define _CJT_CURSOS_HH_

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#include <vector>
#endif

#include "Curso.hh"
#include "Cjt_sesiones.hh"

/** @class Cjt_cursos
    @brief Representa un conjunto de cursos

		Ofrece operaciones para modificar, consultar, leer y escribir un conjunto de cursos.
*/

class Cjt_cursos
{
public:

  //Constructoras y destructoras

  /** @brief Creadora por defecto.

			Se ejecuta automáticamente al declarar un conjunto de cursos.
      \pre <em>cierto</em>
      \post El resultado es un conjunto de cursos vacío
  */
  Cjt_cursos();

	/** @brief Destruye el último curso.

			\pre Hay mínimo un curso
			\post Se elimina del conjunto de cursos el último curso.
	*/
	void borrar_curso();


  //Modificadoras

  /** @brief Añade un nuevo curso a un conjunto de cursos

      \pre No existe intersección de problemas entre sesiones del mismo curso.
      \post Se añade un curso nuevo al conjunto de cursos de la plataforma.
  */
  bool nuevo_curso(string ses, string p);

  /** @brief Inscribe un usuario nuevo a un curso

      \pre Existe tanto el curso c como el usuario u y este último no está
      registrado en ningun otro curso
      \post Se inscribe un usuario al curso con identificador c y se actualizan
			las estadísticas del curso.
  */
  int inscribir_c(int c);

	/** @brief Modifica los usuarios cursando el curso

      \pre Hay como mínimo un usuario cursando el curso
      \post Se resta un usuario al total de usuarios que cursan el curso actualmente.
  */
  void borrar_usu_actual(int c);

	/** @brief Añade un curso vacío

			\pre <em>cierto</em>
			\post Se añade un nuevo curso vacío al conjunto de cursos.
	*/
	void curso_vacio();

	/** @brief Modifica el numero de sesiones de un curso

			\pre No existe intersección de problemas entre las sesiones que pertenecen
			al mismo grupo.
			\post Se suma una sesió nueva al número total de sesiones y se guarda su
			identificador.
	*/
	void nuevo_curso_ses(string s);

	/** @brief Modifica el numero usuarios actuales y historicos de un curso

			\pre Había como mínimo un usuario cursando el curso.
			\post Se suma un usuario al número total de ellos que han completado el
			curso y se resta un usuario al número total de los que lo están cursando
			actualmente, ya que ya ha completado el curso.
	*/
  void sumar_acabado(int x);

	/** @brief Añade un nuevo curso al recibir el comando nuevo curso

			\pre No hay intersección de problemas entre sesiones del mismo curso.
			\post Se añade un nuevo curso al conjunto de cursos y se inicaliza
			con los datos correspondientes.
	*/
	void crear_nuevo_curso(Cjt_sesiones& cs, Cjt_cursos& cc);

	/** @brief Añade un nuevo curso

			\pre <em>cierto</em> (No se comprueba que hay intersección de problemas
		porque se asegura en el enunciado que no hay)
			\post Se añade un nuevo curso al conjunto de cursos y se inicaliza
			con los datos correspondientes.
	*/
	void crear_nuevo_curso_2(Cjt_sesiones& cs, Cjt_cursos& cc);


  // Consultoras

  /** @brief Consulta si el curso está en el cjt_cursos

      \pre <em>cierto</em>
      \post El resultado es true si el curso está y false si no existe
      ningun curso con ese identificador.
  */
  bool buscar_curso(int c) const;

  /** @brief Consulta el identificador de la sesión

      \pre Existe curso con iden. c y hay como mínimo i sesiones.
      \post El resultado es el string de la sesión del curso c que ocupa la
			posición i.
  */
  string buscar_id_sesion(int c, int i) const;

	/** @brief Consulta el número total de sesiones de un curso

      \pre <em>cierto</em>
      \post El resultado es el número total de sesiones que hay en el curso c.
  */
	int total_sesiones(int c) const;

	/** @brief Consulta el número total de cursos

			\pre <em>cierto</em>
			\post El resultado es el número total de cursos que hay en la plataforma.
	*/
	int total_cursos() const;

	/** @brief Consulta el identificador de la sesion a la que pertenece un problema

			\pre <em>cierto</em>
			\post El resultado es el identificador de la sesion a la cual pertenece el
			problema p, si el problema p no esta en el curso, devuelve "no".
	*/
	string problema_pertenece_ses(string p, int c) const;


  //Escritura

  /** @brief Operación de escritura de cursos en la plataforma actualmente

      \pre <em>cierto</em>
      \post Se listan los cursos actuales de la plataforma ordenados
      crecientemente por su identificador y mostrando el num. de usuarios que
      lo han completado, el num. de usuarios registrados actualmente, el num.
      de sesiones que hay y los identificadores de dichas ordenadas por el orden
      de su lectura.
  */
  void escribir_cjt_cursos();

  /** @brief Operación de escritura de un curso concreto en la plataforma.

      \pre Existe el curso con identificador c
      \post Se escribe el identificador del curso mostrando el num. de
      usuarios que lo han completado, el num. de usuarios registrados
      actualmente, el num. de sesiones que hay y los identificadores de dichas
      ordenadas por el orden de su lectura.
  */
  void escribir_curso(int c);


  //Lectura

  /** @brief Operación de lectura de un numero de cursos

      \pre <em>cierto</em>
      \post Se han leido los parametros de la entrada y guardado
      en el conjunto de cursos de la plataforma.
  */

  void leer_cjt_cursos(Cjt_sesiones& cs, Cjt_cursos& cc);

private:
	/** @brief Contiene todos los cursos de la plataforma */
  vector<Curso> c_curso;

};
#endif
