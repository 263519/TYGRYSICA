/*
 * pid.h
 *
 *  Created on: May 26, 2024
 *      Authors: Szymon Wesołowski, Michał Suski
 *      * based on Wojciech Domski - https://edu.domski.pl/wp-content/uploads/2017/02/sr_lab04b.pdf
 */
#include "stm_esp_transfer.h"
#include "motor.h"
#include <math.h>
#include <stdlib.h>

#ifndef INC_PID_H_
#define INC_PID_H_

typedef struct {
    float p;
    float i;
    float d;
    float integral;
    float previous_error;
} pid_controller_t;

void pid_init(pid_controller_t *pid, float p, float i, float d);
void pid_calc(pid_controller_t *pid, float x, float y, msg_t *msg, motors_t *motor);

#endif /* INC_PID_H_ */
