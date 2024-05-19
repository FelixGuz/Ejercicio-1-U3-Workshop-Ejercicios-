/*****************************************************************************
 *  FileName:        BSP.h
 *  Dependencies:    None.
 *  Processor:       MSP432
 *  Board:           MSP432P401R
 *  Program version: CCS V10.4 TI
 *  Company:         TecNM /IT Chihuahua
 *  Description:     Incluye la capa de abstraccion de los drivers.
 *  Authors:         Alfredo Chacon
 *   Created on:     18 nov. 2021
 *   Updated:
  **/
/************************************************************************************************
 * * Copyright (C) 2021 by Alfredo Chacon - TecNM /IT Chihuahua
 *
 * Se permite la redistribucion, modificacion o uso de este software en formato fuente o binario
 * siempre que los archivos mantengan estos derechos de autor.
 * Los usuarios pueden modificar esto y usarlo para aprender sobre el campo de software embebido.
 * Alfredo Chacon y el TecNM /IT Chihuahua no son responsables del mal uso de este material.
 *************************************************************************************************/
#ifndef BSP_H_
#define BSP_H_
// Si hay problemas con los 'includes', busque la direccion o ruta.
//#include <C:/ti_v10_1/ccs/ccs_base/arm/include/msp.h>
#include "DRIVERS\gpio_2021.h"

/* Definición de botones con su respectivo puerto. */
#define PUSH_BOTON_1    GPIO_PIN1
#define PUSH_BOTON_1_PORT    GPIO_PORT_P1

/* Definición de led's plasmados en tarjeta con su respectivo puerto. */
#define LED_RGB_RED     GPIO_PIN0
#define LED_RGB_GREEN   GPIO_PIN1
#define LED_RGB_BLUE    GPIO_PIN2
#define RGB_PORT        GPIO_PORT_P2

#define LED_ROJO        GPIO_PIN0
#define LED_ROJO_PORT   GPIO_PORT_P1
#endif /* BSP_H_ */
