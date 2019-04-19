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

typedef enum opciones
{
	BIST_IKALSE_NOTAK=1,
	BIST_IKAGSAI_IKASLE_NOTA=2,
	BIST_BATAZB_IKASGAI_NOTA=3,
	BIST_BATAZB_IKASLE_NOTA=4,
	BIST_BATAZB_IKASTARO_NOTA=5,
	BIST_IKASLE_BATAZB_ORDENA=6,
	BIST_IKASTARO_IKASLEAK=7
}Filtro_nota;

int menua();

#endif /* SRC_MAIN_H_ */
