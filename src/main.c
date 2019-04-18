/*
 * main.c
 *
 *  Created on: 2019 api. 10
 *      Author: igor
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void cargar_datos();
int menu();

int main()
{
	char msg[128];
	int id_alumno=-1;
	int id_asignatura=-1;
	int id_curso=-1;
	int kont=0;
	int aux_kont=0;
	int sum_notas=0;
	int num_notas_sumadas=0;
	float media_notas=0;

	cargar_datos();

	while(1)
	{
		switch(menu())
		{
		case 1:

			printf("\nID alumno:\n");
			fgets(msg,128,stdin);
			sscanf(msg,"%i",&id_alumno);

			for(kont=0;kont<num_notas;kont++)
			{
				if(notas[kont].alumno_id==id_alumno)
				{
					for(int kontas=0;kontas<num_asignaturas;kontas++)
					{
						if(asignaturas[kontas].id==notas[kont].asignatura_id)
						{
							printf("\n Asignatura: %s Nota: %i\n",asignaturas[kontas].nombre,notas[kont].nota);
							kontas=num_asignaturas;
						}
					}
				}
			}

			break;

		case 2:

			printf("\nID alumno:\n");
			fgets(msg,128,stdin);
			sscanf(msg,"%i",&id_alumno);

			printf("\nID asignatura:\n");
			fgets(msg,128,stdin);
			sscanf(msg,"%i",&id_asignatura);

			for(kont=0;kont<num_notas;kont++)
			{
				if((notas[kont].alumno_id==id_alumno)&&(notas[kont].asignatura_id==id_asignatura))
				{
					for(int kontas=0;kontas<num_asignaturas;kontas++)
					{
						printf("\n Nota: %i\n",notas[kont].nota);
						kontas=num_asignaturas;
					}
				}
			}

			break;

		case 3:

			printf("\nID asignatura:\n");
			fgets(msg,128,stdin);
			sscanf(msg,"%i",&id_asignatura);

			sum_notas=0;
			num_notas_sumadas=0;

			for(kont=0;kont<num_notas;kont++)
			{
				if((notas[kont].asignatura_id==id_asignatura))
				{
					sum_notas+=notas[kont].nota;
					num_notas_sumadas++;
				}
			}

			media_notas=(float)sum_notas/(float)num_notas_sumadas;

			printf("\n Media: %.2f\n", media_notas);

			break;

		case 4:

			printf("\nID alumno:\n");
			fgets(msg,128,stdin);
			sscanf(msg,"%i",&id_alumno);

			sum_notas=0;
			num_notas_sumadas=0;

			for(aux_kont=0;aux_kont<num_notas;aux_kont++)
			{
				if((notas[aux_kont].alumno_id==id_alumno))
				{
					sum_notas+=notas[aux_kont].nota;
					num_notas_sumadas++;
				}
			}

			media_notas=(float)sum_notas/(float)num_notas_sumadas;

			printf("\n Media: %.2f\n", media_notas);

			break;

		case 5:

			printf("\nID curso:\n");
			fgets(msg,128,stdin);
			sscanf(msg,"%i",&id_curso);

			sum_notas=0;
			num_notas_sumadas=0;

			for(kont=0;kont<num_asignaturas;kont++)
			{
				if(asignaturas[kont].curso_id==id_curso)
				{
					id_asignatura=asignaturas[kont].id;

					for(aux_kont=0;aux_kont<num_notas;aux_kont++)
					{
						if((notas[aux_kont].asignatura_id==id_asignatura))
						{
							sum_notas+=notas[aux_kont].nota;
							num_notas_sumadas++;
						}
					}
				}
			}

			media_notas=(float)sum_notas/(float)num_notas_sumadas;

			printf("\n Media: %.2f\n", media_notas);

			break;
		}
	}
}

void cargar_datos()
{
	char msg[128];
	int kont=0;
	FILE *fp;

	fp=fopen("fichero_alumnos.fch","r");

	for(kont=0;kont<4;kont++)
	{
		alumnos[kont].nombre=malloc(20);
		alumnos[kont].apellido_1=malloc(20);
		alumnos[kont].apellido_2=malloc(20);
		alumnos[kont].correo=malloc(40);

		fgets(msg,128,fp);
		sscanf(msg,"%i %s %s %s %s",&alumnos[kont].id,alumnos[kont].nombre,alumnos[kont].apellido_1,alumnos[kont].apellido_2,alumnos[kont].correo);
	}

	num_alumnos=kont;

	fgets(msg,128,fp);

	for(kont=0;kont<2;kont++)
	{
		cursos[kont].nombre=malloc(20);

		fgets(msg,128,fp);
		sscanf(msg,"%i %s",&cursos[kont].id,cursos[kont].nombre);
	}

	num_cursos=kont;

	fgets(msg,128,fp);

	for(kont=0;kont<10;kont++)
	{
		asignaturas[kont].nombre=malloc(20);

		fgets(msg,128,fp);
		sscanf(msg,"%i %i %s",&asignaturas[kont].id,&asignaturas[kont].curso_id,asignaturas[kont].nombre);
	}

	num_asignaturas=kont;

	fgets(msg,128,fp);

	for(kont=0;kont<40;kont++)
	{
		fgets(msg,128,fp);
		sscanf(msg,"%i %i %i",&notas[kont].alumno_id,&notas[kont].asignatura_id,&notas[kont].nota);
	}

	num_notas=kont;

	fclose(fp);
}

int menu()
{
	char msg[128];
	int ret=0;

	printf("\n Opciones:\n"
			 "         1) Mostrar notas de alumno\n"
			 "         2) Mostrar nota por asignatura por alumno\n"
			 "         3) Nota media de asignatura\n"
			 "         4) Nota media de alumno\n"
			 "         5) Nota media por curso\n");

	fgets(msg,128,stdin);
	sscanf(msg,"%i",&ret);

	return ret;
}
