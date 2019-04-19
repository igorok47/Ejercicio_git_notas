/*
 * datu_karga.c
 *
 *  Created on: 2019 api. 19
 *      Author: igor
 */

#include "datu_gestioa.h"
#include "datu_karga.h"

void ikasle_karga(FILE *fp);
void ikastaro_karga(FILE *fp);
void ikasgai_karga(FILE *fp);
void nota_karga(FILE *fp);

void datu_karga()
{
	char msg[INPUT_BUFFER_SIZE];

	int ikasle_datuak=0;
	int ikastaro_datuak=0;
	int ikasgai_datuak=0;
	int nota_datuak=0;

	FILE *fp;

	fp=fopen("ikasle_fitxategia.ftx","r");

	while((!ikasle_datuak)||(!ikastaro_datuak)||(!ikasgai_datuak)||(!nota_datuak))
	{
		fgets(msg,INPUT_BUFFER_SIZE,fp);

		if((!ikasle_datuak)&&(strcmp(msg,"Ikasleak\n")==0))
		{
			ikasle_karga(fp);
			ikasle_datuak=1;
		}
		else
		{
			if((!ikastaro_datuak)&&(strcmp(msg,"Ikastaroak\n")==0))
			{
				ikastaro_karga(fp);
				ikastaro_datuak=1;
			}
			else
			{
				if((!ikasgai_datuak)&&(strcmp(msg,"Ikasgaiak\n")==0))
				{
					ikasgai_karga(fp);
					ikasgai_datuak=1;
				}
				else
				{
					if((!nota_datuak)&&(strcmp(msg,"Notak\n")==0))
					{
						nota_karga(fp);
						nota_datuak=1;
					}
				}
			}
		}
	}

	fclose(fp);
}

void ikasle_karga(FILE *fp)
{
	char msg[INPUT_BUFFER_SIZE];
	int kont=0;
	int end_msg=0;

	kont=0;
	end_msg=0;

	do
	{
		ikasleak[kont].izena=malloc(20);
		ikasleak[kont].abizena_1=malloc(20);
		ikasleak[kont].abizena_2=malloc(20);
		ikasleak[kont].emaila=malloc(40);

		fgets(msg,INPUT_BUFFER_SIZE,fp);

		if(strcmp(msg,"\n")==0)
		{
			end_msg=1;
		}

		if(!end_msg)
		{
			sscanf(msg,"%i %s %s %s %s",&ikasleak[kont].id,ikasleak[kont].izena,ikasleak[kont].abizena_1,ikasleak[kont].abizena_2,ikasleak[kont].emaila);
			kont++;
		}

	}while(!end_msg);

	ikasle_kop=kont;
}

void ikastaro_karga(FILE *fp)
{
	char msg[INPUT_BUFFER_SIZE];
	int kont=0;
	int end_msg=0;

	kont=0;
	end_msg=0;

	do
	{
		ikastaroak[kont].izena=malloc(20);

		fgets(msg,INPUT_BUFFER_SIZE,fp);

		if(strcmp(msg,"\n")==0)
		{
			end_msg=1;
		}

		if(!end_msg)
		{
			sscanf(msg,"%i %s",&ikastaroak[kont].id,ikastaroak[kont].izena);
			kont++;
		}

	}while(!end_msg);

	ikastaro_kop=kont;
}
void ikasgai_karga(FILE *fp)
{
	char msg[INPUT_BUFFER_SIZE];
	int kont=0;
	int end_msg=0;

	kont=0;
	end_msg=0;

	do
	{
		ikasgaiak[kont].izena=malloc(20);

		fgets(msg,INPUT_BUFFER_SIZE,fp);

		if(strcmp(msg,"\n")==0)
		{
			end_msg=1;
		}

		if(!end_msg)
		{
			sscanf(msg,"%i %i %s",&ikasgaiak[kont].id,&ikasgaiak[kont].ikastaro_id,ikasgaiak[kont].izena);
			kont++;
		}

	}while(!end_msg);

	ikasgai_kop=kont;
}

void nota_karga(FILE *fp)
{
	char msg[INPUT_BUFFER_SIZE];
	int kont=0;
	int end_msg=0;

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
			sscanf(msg,"%i %i %i",&notak[kont].ikasle_id,&notak[kont].ikasgai_id,&notak[kont].nota);
			kont++;
		}

	}while(!end_msg);

	nota_kop=kont;
}
