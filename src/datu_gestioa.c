/*
 * datu_bistaratzeak.c
 *
 *  Created on: 2019 api. 19
 *      Author: igor
 */

#include "datu_karga.h"
#include "datu_gestioa.h"

int ID_eskatu(char* ID_izena);


int ID_eskatu(char* ID_izena)
{
	int ret_ID=-1;
	char msg[INPUT_BUFFER_SIZE];

	printf("\n%s:\n",ID_izena);
	fgets(msg,INPUT_BUFFER_SIZE,stdin);
	sscanf(msg,"%i",&ret_ID);

	return ret_ID;
}

void bistaratu_ikasle_notak()
{
	int ikasle_id;
	int kont;

	ikasle_id=ID_eskatu("Ikasle ID-a");

	for(kont=0;kont<nota_kop;kont++)
	{
		if(notak[kont].ikasle_id==ikasle_id)
		{
			for(int kontas=0;kontas<ikasgai_kop;kontas++)
			{
				if(ikasgaiak[kontas].id==notak[kont].ikasgai_id)
				{
					printf("\n Ikasgaia: %s Nota: %i\n",ikasgaiak[kontas].izena,notak[kont].nota);
					kontas=ikasgai_kop;
				}
			}
		}
	}
}

void bistaratu_ikasle_ikasgai_nota()
{
	int ikasle_id;
	int ikasgai_id;
	int kont;

	ikasle_id=ID_eskatu("Ikasle ID-a");

	ikasgai_id=ID_eskatu("Ikasgai ID-a");

	for(kont=0;kont<nota_kop;kont++)
	{
		if((notak[kont].ikasle_id==ikasle_id)&&(notak[kont].ikasgai_id==ikasgai_id))
		{
			for(int kontas=0;kontas<ikasgai_kop;kontas++)
			{
				printf("\n Nota: %i\n",notak[kont].nota);
				kontas=ikasgai_kop;
			}
		}
	}
}

void bistaratu_ikasgai_batazbesteko_nota()
{
	int ikasgai_id=-1;
	int nota_batura=0;
	int batutako_nota_kop=0;
	int kont;
	float nota_batazbestekoa=0;

	ikasgai_id=ID_eskatu("Ikasgai ID-a");

	nota_batura=0;
	batutako_nota_kop=0;

	for(kont=0;kont<nota_kop;kont++)
	{
		if((notak[kont].ikasgai_id==ikasgai_id))
		{
			nota_batura+=notak[kont].nota;
			batutako_nota_kop++;
		}
	}

	nota_batazbestekoa=(float)nota_batura/(float)batutako_nota_kop;

	printf("\n Media: %.2f\n", nota_batazbestekoa);
}

void bistaratu_ikasle_batazbesteko_nota()
{
	int ikasle_id=-1;
	int nota_batura=0;
	int batutako_nota_kop=0;
	int kont;
	float nota_batazbestekoa=0;

	ikasle_id=ID_eskatu("Ikasle ID-a");

	nota_batura=0;
	batutako_nota_kop=0;

	for(kont=0;kont<nota_kop;kont++)
	{
		if((notak[kont].ikasle_id==ikasle_id))
		{
			nota_batura+=notak[kont].nota;
			batutako_nota_kop++;
		}
	}

	nota_batazbestekoa=(float)nota_batura/(float)batutako_nota_kop;

	printf("\n Batazbestekoa: %.2f\n", nota_batazbestekoa);
}

void bistaratu_ikastaro_batazbesteko_nota()
{
	int ikastaro_id=-1;
	int ikasgai_id=-1;
	int nota_batura=0;
	int batutako_nota_kop=0;
	int kont;
	int aux_kont;
	float nota_batazbestekoa=0;

	ikastaro_id=ID_eskatu("Ikastaro ID-a");

	nota_batura=0;
	batutako_nota_kop=0;

	for(kont=0;kont<ikasgai_kop;kont++)
	{
		if(ikasgaiak[kont].ikastaro_id==ikastaro_id)
		{
			ikasgai_id=ikasgaiak[kont].id;

			for(aux_kont=0;aux_kont<nota_kop;aux_kont++)
			{
				if((notak[aux_kont].ikasgai_id==ikasgai_id))
				{
					nota_batura+=notak[aux_kont].nota;
					batutako_nota_kop++;
				}
			}
		}
	}

	nota_batazbestekoa=(float)nota_batura/(float)batutako_nota_kop;

	printf("\n Batazbestekoa: %.2f\n", nota_batazbestekoa);
}

void bistaratu_ikasleak_bastazbestekoz_ordenatuta()
{
	Ikasle_batazbesteko ikasle_batazbesteko[ikasle_kop];
	Ikasle_batazbesteko aux_ikasle_batazbesteko;

	int kont=0;
	int aux_kont=0;
	int nota_batura=0;
	int batutako_nota_kop=0;
	int batazbesteko_ordenatuak=0;
	float nota_batazbestekoa=0;

	for(kont=0;kont<ikasle_kop;kont++)
	{
		nota_batura=0;
		batutako_nota_kop=0;

		for(aux_kont=0;aux_kont<nota_kop;aux_kont++)
		{
			if((notak[aux_kont].ikasle_id==ikasleak[kont].id))
			{
				nota_batura+=notak[aux_kont].nota;
				batutako_nota_kop++;
			}
		}

		nota_batazbestekoa=(float)nota_batura/(float)batutako_nota_kop;


		ikasle_batazbesteko[kont].ikasle=ikasleak[kont];
		ikasle_batazbesteko[kont].batzbesteko_nota=nota_batazbestekoa;
	}

	while(!batazbesteko_ordenatuak)
	{
		batazbesteko_ordenatuak=1;

		for(kont=0;kont<ikasle_kop-1;kont++)
		{
			if(ikasle_batazbesteko[kont].batzbesteko_nota>ikasle_batazbesteko[kont+1].batzbesteko_nota)
			{
				batazbesteko_ordenatuak=0;
				aux_ikasle_batazbesteko=ikasle_batazbesteko[kont+1];
				ikasle_batazbesteko[kont+1]=ikasle_batazbesteko[kont];
				ikasle_batazbesteko[kont]=aux_ikasle_batazbesteko;
			}
		}
	}

	printf("\n");

	for(kont=0;kont<ikasle_kop;kont++)
	{
		printf(" Ikaslea: %i %s %s %s Batazbesteko nota: %f\n",ikasle_batazbesteko[kont].ikasle.id
													,ikasle_batazbesteko[kont].ikasle.izena
													,ikasle_batazbesteko[kont].ikasle.abizena_1
													,ikasle_batazbesteko[kont].ikasle.abizena_2
													,ikasle_batazbesteko[kont].batzbesteko_nota);
	}

	printf("\n");


}

void bistaratu_ikastaroko_ikasleak()
{
	int ikastaro_id=-1;
	int kont;
	int aux_kont;
	int aux2_kont;
	int ikasle_kont=0;

	Ikasle ikasle_aux[4];


	ikastaro_id=ID_eskatu("Ikastaro ID-a");

	for(kont=0;kont<ikasle_kop;kont++)
	{
		for(aux_kont=0;aux_kont<nota_kop;aux_kont++)
		{
			if((notak[aux_kont].ikasle_id==ikasleak[kont].id))
			{
				for(aux2_kont=0;aux2_kont<ikasgai_kop;aux2_kont++)
				{
					if((notak[aux_kont].ikasgai_id==ikasgaiak[aux2_kont].id)&&(ikasgaiak[aux2_kont].ikastaro_id==ikastaro_id))
					{
						ikasle_aux[ikasle_kont]=ikasleak[kont];
						ikasle_kont++;
						aux2_kont=ikasgai_kop;
						aux_kont=nota_kop;
					}
				}
			}
		}
	}

	printf("\n");

	for(kont=0;kont<ikasle_kont;kont++)
	{
		printf("%i %s %s %s ikaslea\n",ikasle_aux[kont].id
													,ikasle_aux[kont].izena
													,ikasle_aux[kont].abizena_1
													,ikasle_aux[kont].abizena_2);
	}

	printf("\n");

}
