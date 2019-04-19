/*
 * main.c
 *
 *  Created on: 2019 api. 10
 *      Author: igor
 */

#include "main.h"

int main()
{
	cargar_datos();

	while(1)
	{
		switch(menu())
		{
		case MOST_NOTAS_ALUMNO:

			mostrar_notas_alumno();

			break;

		case MOST_NOTA_ASIGNATUA_ALUMNO:

			mostrar_nota_por_asignatura_por_alumno();

			break;

		case MOST_NOTA_MEDIA_ASIGNATURA:

			mostrar_nota_media_asignatura();

			break;

		case MOST_NOTA_MEDIA_ALUMNO:

			mostrat_nota_media_alumno();

			break;

		case MOST_NOTA_MEDIA_CURSO:

			mostrar_nota_media_curso();

			break;

		case 6:

			nota_media_alumnos_ordenado();

			break;
		}
	}
}

int pedir_ID(char* nombre_ID)
{
	int ret_ID=-1;
	char msg[INPUT_BUFFER_SIZE];

	printf("\n%s:\n",nombre_ID);
	fgets(msg,INPUT_BUFFER_SIZE,stdin);
	sscanf(msg,"%i",&ret_ID);

	return ret_ID;
}

void mostrar_notas_alumno()
{
	int id_alumno;
	int kont;

	id_alumno=pedir_ID("ID alumno");

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
}

void mostrar_nota_por_asignatura_por_alumno()
{
	int id_alumno;
	int id_asignatura;
	int kont;

	id_alumno=pedir_ID("ID alumno");

	id_asignatura=pedir_ID("ID asignatura");

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
}

void mostrar_nota_media_asignatura()
{
	int id_asignatura=-1;
	int sum_notas=0;
	int num_notas_sumadas=0;
	int kont;
	float media_notas=0;

	id_asignatura=pedir_ID("ID asignatura");

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
}

void mostrat_nota_media_alumno()
{
	int id_alumno=-1;
	int sum_notas=0;
	int num_notas_sumadas=0;
	int kont;
	float media_notas=0;

	id_alumno=pedir_ID("ID alumno");

	sum_notas=0;
	num_notas_sumadas=0;

	for(kont=0;kont<num_notas;kont++)
	{
		if((notas[kont].alumno_id==id_alumno))
		{
			sum_notas+=notas[kont].nota;
			num_notas_sumadas++;
		}
	}

	media_notas=(float)sum_notas/(float)num_notas_sumadas;

	printf("\n Media: %.2f\n", media_notas);
}

void mostrar_nota_media_curso()
{
	int id_curso=-1;
	int id_asignatura=-1;
	int sum_notas=0;
	int num_notas_sumadas=0;
	int kont;
	int aux_kont;
	float media_notas=0;

	id_curso=pedir_ID("ID curso");

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
}

void nota_media_alumnos_ordenado()
{
	Media_alumno medias_alumnos[num_alumnos];
	Media_alumno medias_alumnos_ordenadas[num_alumnos];

	int kont=0;
	int aux_kont=0;
	int sum_notas=0;
	int num_notas_sumadas=0;
	float media_notas=0;

	for(kont=0;kont<num_alumnos;kont++)
	{
		sum_notas=0;
		num_notas_sumadas=0;

		for(aux_kont=0;aux_kont<num_notas;aux_kont++)
		{
			if((notas[aux_kont].alumno_id==alumnos[kont].id))
			{
				sum_notas+=notas[aux_kont].nota;
				num_notas_sumadas++;
			}
		}

		media_notas=(float)sum_notas/(float)num_notas_sumadas;


		medias_alumnos[kont].alumno=alumnos[kont];
		medias_alumnos[kont].nota_media=media_notas;
	}

	for(kont=0;kont<num_alumnos;kont++)
	{
		medias_alumnos_ordenadas[kont]=medias_alumnos[kont];
	}

	printf("\n");

	for(kont=0;kont<num_alumnos;kont++)
	{
		printf(" Alumno %i %s %s %s Nota media: %f\n",medias_alumnos_ordenadas[kont].alumno.id
													,medias_alumnos_ordenadas[kont].alumno.nombre
													,medias_alumnos_ordenadas[kont].alumno.apellido_1
													,medias_alumnos_ordenadas[kont].alumno.apellido_2
													,medias_alumnos_ordenadas[kont].nota_media);
	}

	printf("\n");


}





void cargar_datos()
{
	char msg[INPUT_BUFFER_SIZE];
	int kont=0;
	FILE *fp;

	fp=fopen("fichero_alumnos.fch","r");

	for(kont=0;kont<4;kont++)
	{
		alumnos[kont].nombre=malloc(20);
		alumnos[kont].apellido_1=malloc(20);
		alumnos[kont].apellido_2=malloc(20);
		alumnos[kont].correo=malloc(40);

		fgets(msg,INPUT_BUFFER_SIZE,fp);
		sscanf(msg,"%i %s %s %s %s",&alumnos[kont].id,alumnos[kont].nombre,alumnos[kont].apellido_1,alumnos[kont].apellido_2,alumnos[kont].correo);
	}

	num_alumnos=kont;

	fgets(msg,INPUT_BUFFER_SIZE,fp);

	for(kont=0;kont<2;kont++)
	{
		cursos[kont].nombre=malloc(20);

		fgets(msg,INPUT_BUFFER_SIZE,fp);
		sscanf(msg,"%i %s",&cursos[kont].id,cursos[kont].nombre);
	}

	num_cursos=kont;

	fgets(msg,INPUT_BUFFER_SIZE,fp);

	for(kont=0;kont<10;kont++)
	{
		asignaturas[kont].nombre=malloc(20);

		fgets(msg,INPUT_BUFFER_SIZE,fp);
		sscanf(msg,"%i %i %s",&asignaturas[kont].id,&asignaturas[kont].curso_id,asignaturas[kont].nombre);
	}

	num_asignaturas=kont;

	fgets(msg,INPUT_BUFFER_SIZE,fp);

	for(kont=0;kont<40;kont++)
	{
		fgets(msg,INPUT_BUFFER_SIZE,fp);
		sscanf(msg,"%i %i %i",&notas[kont].alumno_id,&notas[kont].asignatura_id,&notas[kont].nota);
	}

	num_notas=kont;

	fclose(fp);
}

int menu()
{
	char msg[INPUT_BUFFER_SIZE];
	int ret=0;

	printf("\n Opciones:\n"
			 "         %i) Mostrar notas de alumno\n"
			 "         %i) Mostrar nota por asignatura por alumno\n"
			 "         %i) Nota media de asignatura\n"
			 "         %i) Nota media de alumno\n"
			 "         %i) Nota media por curso\n"
			 "         %i) Mostrar alumnos ordenados por nota media\n",MOST_NOTAS_ALUMNO,MOST_NOTA_ASIGNATUA_ALUMNO,MOST_NOTA_MEDIA_ASIGNATURA,MOST_NOTA_MEDIA_ALUMNO,MOST_NOTA_MEDIA_CURSO,6);

	fgets(msg,INPUT_BUFFER_SIZE,stdin);
	sscanf(msg,"%i",&ret);

	return ret;
}
