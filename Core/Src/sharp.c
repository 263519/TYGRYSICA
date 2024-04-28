#include "sharp.h"
//https://www.arduinopak.com/Prd_Detail.aspx?Prd_ID=20041

void SHARP_get_distance(uint16_t *sharp_distance){
	if(*sharp_distance ==0)
		return;
	*sharp_distance = (37376/(*sharp_distance)) - 4;
}
