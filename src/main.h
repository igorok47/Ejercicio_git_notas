/*
 * main.h
 *
 *  Created on: 2019 api. 19
 *      Author: igor
 */

#ifndef SRC_MAIN_H_
#define SRC_MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_BUFFER_SIZE 128

typedef enum opciones
{
	MOST_NOTAS_ALUMNO=1,
	MOST_NOTA_ASIGNATUA_ALUMNO=2,
	MOST_NOTA_MEDIA_ASIGNATURA=3,
	MOST_NOTA_MEDIA_ALUMNO=4,
	MOST_NOTA_MEDIA_CURSO=5
}Filtro_nota;

typedef struct alumno
{
	int id;
	char* nombre;
	char* apellido_1;
	char* apellido_2;
	char* correo;
}Alumno;

typedef struct curso
{
	int id;
	char* nombre;

}Curso;

typedef struct asignatura
{
	int id;
	int curso_id;
	char* nombre;
}Asignatura;

typedef struct nota
{
	int alumno_id;
	int asignatura_id;
	int nota;
}Nota;

Alumno alumnos[4];
Curso cursos[2];
Asignatura asignaturas[10];
Nota notas[40];

int num_alumnos;
int num_cursos;
int num_asignaturas;
int num_notas;

int pedir_ID(char* nombre_ID);
void mostrar_notas_alumno();
void mostrar_nota_por_asignatura_por_alumno();
void mostrar_nota_media_asignatura();
void mostrat_nota_media_alumno();
void mostrar_nota_media_curso();
void cargar_datos();
int menu();

#endif /* SRC_MAIN_H_ */
