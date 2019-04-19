/*
 * datu_gestioa.h
 *
 *  Created on: 2019 api. 19
 *      Author: igor
 */

#ifndef SRC_DATU_GESTIOA_H_
#define SRC_DATU_GESTIOA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ikalse
{
	int id;
	char* izena;
	char* abizena_1;
	char* abizena_2;
	char* emaila;
}Ikasle;

typedef struct ikastaro
{
	int id;
	char* izena;

}Ikastaro;

typedef struct ikasgai
{
	int id;
	int ikastaro_id;
	char* izena;
}Ikasgai;

typedef struct nota
{
	int ikasle_id;
	int ikasgai_id;
	int nota;
}Nota;

typedef struct ikasle_batazbesteko
{
	Ikasle ikasle;
	float batzbesteko_nota;
}Ikasle_batazbesteko;

Ikasle ikasleak[128];
Ikastaro ikastaroak[128];
Ikasgai ikasgaiak[128];
Nota notak[128];

int ikasle_kop;
int ikastaro_kop;
int ikasgai_kop;
int nota_kop;

void bistaratu_ikasle_notak();
void bistaratu_ikasle_ikasgai_nota();
void bistaratu_ikasgai_batazbesteko_nota();
void bistaratu_ikasle_batazbesteko_nota();
void bistaratu_ikastaro_batazbesteko_nota();
void bistaratu_ikasleak_bastazbestekoz_ordenatuta();
void bistaratu_ikastaroko_ikasleak();



#endif /* SRC_DATU_GESTIOA_H_ */
