/*
 * main.c
 *
 *  Created on: 2019 api. 10
 *      Author: igor
 */

#include "datu_karga.h"
#include "datu_gestioa.h"
#include "main.h"

int main()
{
	datu_karga();

	while(1)
	{
		switch(menua())
		{
		case BIST_IKALSE_NOTAK:

			bistaratu_ikasle_notak();

			break;

		case BIST_IKAGSAI_IKASLE_NOTA:

			bistaratu_ikasle_ikasgai_nota();

			break;

		case BIST_BATAZB_IKASGAI_NOTA:

			bistaratu_ikasgai_batazbesteko_nota();

			break;

		case BIST_BATAZB_IKASLE_NOTA:

			bistaratu_ikasle_batazbesteko_nota();

			break;

		case BIST_BATAZB_IKASTARO_NOTA:

			bistaratu_ikastaro_batazbesteko_nota();

			break;

		case BIST_IKASLE_BATAZB_ORDENA:

			bistaratu_ikasleak_bastazbestekoz_ordenatuta();

			break;

		case BIST_IKASTARO_IKASLEAK:

			bistaratu_ikastaroko_ikasleak();

			break;
		}
	}
}

int menua()
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
			 "         %i) Bistaratu ikasgai batean inskribatutako ikasleak\n",BIST_IKALSE_NOTAK
			 	 	 	 	 	 	 	 	 	 	 	 	 	 ,BIST_IKAGSAI_IKASLE_NOTA
			 	 	 	 	 	 	 	 	 	 	 	 	 	 ,BIST_BATAZB_IKASGAI_NOTA
																 ,BIST_BATAZB_IKASLE_NOTA
																 ,BIST_BATAZB_IKASTARO_NOTA
																 ,BIST_IKASLE_BATAZB_ORDENA
																 ,BIST_IKASTARO_IKASLEAK);

	fgets(msg,INPUT_BUFFER_SIZE,stdin);
	sscanf(msg,"%i",&ret);

	return ret;
}
