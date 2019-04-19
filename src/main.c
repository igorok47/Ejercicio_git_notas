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

		case 7:

			mostrar_alumnos_curso();

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

	id_alumno=pedir_ID("Ikasle ID-a");

	for(kont=0;kont<num_notas;kont++)
	{
		if(notas[kont].alumno_id==id_alumno)
		{
			for(int kontas=0;kontas<num_asignaturas;kontas++)
			{
				if(asignaturas[kontas].id==notas[kont].asignatura_id)
				{
					printf("\n Ikasgaia: %s Nota: %i\n",asignaturas[kontas].nombre,notas[kont].nota);
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

	id_alumno=pedir_ID("Ikasle ID-a");

	id_asignatura=pedir_ID("Ikasgai ID-a");

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

	id_asignatura=pedir_ID("Ikasgai ID-a");

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

	id_alumno=pedir_ID("Ikasle ID-a");

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

	printf("\n Batazbestekoa: %.2f\n", media_notas);
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

	id_curso=pedir_ID("Ikastaro ID-a");

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

	printf("\n Batazbestekoa: %.2f\n", media_notas);
}

void nota_media_alumnos_ordenado()
{
	Media_alumno medias_alumnos[num_alumnos];
	Media_alumno aux_medias_alumnos;

	int kont=0;
	int aux_kont=0;
	int sum_notas=0;
	int num_notas_sumadas=0;
	int medias_ordenadas=0;
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

	while(!medias_ordenadas)
	{
		medias_ordenadas=1;

		for(kont=0;kont<num_alumnos-1;kont++)
		{
			if(medias_alumnos[kont].nota_media>medias_alumnos[kont+1].nota_media)
			{
				medias_ordenadas=0;
				aux_medias_alumnos=medias_alumnos[kont+1];
				medias_alumnos[kont+1]=medias_alumnos[kont];
				medias_alumnos[kont]=aux_medias_alumnos;
			}
		}
	}

	printf("\n");

	for(kont=0;kont<num_alumnos;kont++)
	{
		printf(" Ikaslea: %i %s %s %s Batazbesteko nota: %f\n",medias_alumnos[kont].alumno.id
													,medias_alumnos[kont].alumno.nombre
													,medias_alumnos[kont].alumno.apellido_1
													,medias_alumnos[kont].alumno.apellido_2
													,medias_alumnos[kont].nota_media);
	}

	printf("\n");


}

void mostrar_alumnos_curso()
{
	int id_curso=-1;
	int kont;
	int aux_kont;
	int aux2_kont;
	int alumno_kont=0;

	Alumno alumnos_aux[4];


	id_curso=pedir_ID("Ikastaro ID-a");

	for(kont=0;kont<num_alumnos;kont++)
	{
		for(aux_kont=0;aux_kont<num_notas;aux_kont++)
		{
			if((notas[aux_kont].alumno_id==alumnos[kont].id))
			{
				for(aux2_kont=0;aux2_kont<num_asignaturas;aux2_kont++)
				{
					if((notas[aux_kont].asignatura_id==asignaturas[aux2_kont].id)&&(asignaturas[aux2_kont].curso_id==id_curso))
					{
						alumnos_aux[alumno_kont]=alumnos[kont];
						alumno_kont++;
						aux2_kont=num_asignaturas;
						aux_kont=num_notas;
					}
				}
			}
		}
	}

	printf("\n");

	for(kont=0;kont<alumno_kont;kont++)
	{
		printf("%i %s %s %s ikaslea\n",alumnos_aux[kont].id
													,alumnos_aux[kont].nombre
													,alumnos_aux[kont].apellido_1
													,alumnos_aux[kont].apellido_2);
	}

	printf("\n");

}





void cargar_datos()
{
	char msg[INPUT_BUFFER_SIZE];
	int kont=0;
	int end_msg=0;
	int datos_alumnos=0;
	int datos_cursos=0;
	int datos_asignaturas=0;
	int datos_notas=0;

	FILE *fp;

	fp=fopen("ikasle_fitxategia.ftx","r");

	while((!datos_alumnos)||(!datos_cursos)||(!datos_asignaturas)||(!datos_notas))
	{
		fgets(msg,INPUT_BUFFER_SIZE,fp);

		if((!datos_alumnos)&&(strcmp(msg,"Ikasleak\n")==0))
		{
			kont=0;
			end_msg=0;

			do
			{
				alumnos[kont].nombre=malloc(20);
				alumnos[kont].apellido_1=malloc(20);
				alumnos[kont].apellido_2=malloc(20);
				alumnos[kont].correo=malloc(40);

				fgets(msg,INPUT_BUFFER_SIZE,fp);

				if(strcmp(msg,"\n")==0)
				{
					end_msg=1;
				}

				if(!end_msg)
				{
					sscanf(msg,"%i %s %s %s %s",&alumnos[kont].id,alumnos[kont].nombre,alumnos[kont].apellido_1,alumnos[kont].apellido_2,alumnos[kont].correo);
					kont++;
				}

			}while(!end_msg);

			num_alumnos=kont;
			datos_alumnos=1;
		}
		else
		{
			if((!datos_cursos)&&(strcmp(msg,"Ikastaroak\n")==0))
			{
				kont=0;
				end_msg=0;

				do
				{
					cursos[kont].nombre=malloc(20);

					fgets(msg,INPUT_BUFFER_SIZE,fp);

					if(strcmp(msg,"\n")==0)
					{
						end_msg=1;
					}

					if(!end_msg)
					{
						sscanf(msg,"%i %s",&cursos[kont].id,cursos[kont].nombre);
						kont++;
					}

				}while(!end_msg);

				num_cursos=kont;
				datos_cursos=1;
			}
			else
			{
				if((!datos_asignaturas)&&(strcmp(msg,"Ikasgaiak\n")==0))
				{
					kont=0;
					end_msg=0;

					do
					{
						asignaturas[kont].nombre=malloc(20);

						fgets(msg,INPUT_BUFFER_SIZE,fp);

						if(strcmp(msg,"\n")==0)
						{
							end_msg=1;
						}

						if(!end_msg)
						{
							sscanf(msg,"%i %i %s",&asignaturas[kont].id,&asignaturas[kont].curso_id,asignaturas[kont].nombre);
							kont++;
						}

					}while(!end_msg);

					num_asignaturas=kont;
					datos_asignaturas=1;
				}
				else
				{
					if((!datos_notas)&&(strcmp(msg,"Notak\n")==0))
					{
						kont=0;
						end_msg=0;

						do
						{
							fgets(msg,INPUT_BUFFER_SIZE,fp);

							if(strcmp(msg,"\n")==0)
							{
								end_msg=1;
							}

							if(!end_msg)
							{
								sscanf(msg,"%i %i %i",&notas[kont].alumno_id,&notas[kont].asignatura_id,&notas[kont].nota);
								kont++;
							}

						}while(!end_msg);

						num_notas=kont;
						datos_notas=1;
					}
				}
			}
		}
	}




	fclose(fp);
}

int menu()
{
	char msg[INPUT_BUFFER_SIZE];
	int ret=0;

	printf("\n Aukerak:\n"
			 "         %i) Bistaratu ikaslearen notak\n"
			 "         %i) Bistaratu ikaslearen ikasgai bateko notak\n"
			 "         %i) Ikasgaiko batezbesteko nota\n"
			 "         %i) Ikasle baten batezbesteko nota\n"
			 "         %i) Ikastaro bateko batazbesteko nota\n"
			 "         %i) Bistaratu ikasleak batazbesteko notaren arabera ordenatuta\n"
			 "         %i) Bistaratu ikasgai batean inskribatutako ikasleak\n",MOST_NOTAS_ALUMNO,MOST_NOTA_ASIGNATUA_ALUMNO
			 	 	 	 	 	 	 	 	 	 	 	 	 	 ,MOST_NOTA_MEDIA_ASIGNATURA
																 ,MOST_NOTA_MEDIA_ALUMNO
																 ,MOST_NOTA_MEDIA_CURSO
																 ,6
																 ,7);

	fgets(msg,INPUT_BUFFER_SIZE,stdin);
	sscanf(msg,"%i",&ret);

	return ret;
}
