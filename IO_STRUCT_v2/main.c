/**********************************************************
 * FileName:        main.c
 * Dependencies:    msp.h, stdint.h
 * Processor:       MSP432
 * Board:           MSP432P401R
 * Program version: CCS V10 TI
 * Company:         TecNM /IT Chihuahua
 * Description:     ACCESO A MEMORIA DE REGISTROS DE PERIFERICO GPIO CON "ESTRUCTURAS_V2"
 * Authors:         ALFREDO CHACON
 * Updated:         03/2021
 * Nota: no se están usando las estructuras definidas en los sorucefiles dados por el BSP de TI, Aqui se declran las estructuras
 *       los punteros declarados se incializan con las direcciones de memoria de los registros de los perifericos en cuestión
 * Created on: 6 oct. 2021
 * updated: 20/11/2021
 **************************************************/

/************************************************************************************************
 * * Copyright (C) 2021 by Alfredo Chacon - TecNM /IT Chihuahua
 *
 * Se permite la redistribución, modificación o uso de este software en formato fuente o binario
 * siempre que los archivos mantengan estos derechos de autor.
 * Los usuarios pueden modificar esto y usarlo para aprender sobre el campo de software embebido.
 * Alfredo Chacon y el TecNM /IT Chihuahua no son responsables del mal uso de este material.
 *************************************************************************************************/
/************************************************
  HEADER FILES
 ************************************************/
#include<stdint.h>
#include "msp.h"
#include "DRIVERS\BSP.h"

void GPIO_init(void);

void main(void)
{
    /************************************************
              DECLARACION DE VARIABLES
     ************************************************/
    uint32_t i;
    uint8_t bandera = 0;

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;           // DETIENE EL TIMER DEL WATCHDOG
    /************************************************
        CONFIGURACION DE GPIO
    ************************************************/
    GPIO_init();
    while(1)
    {
        if ( Gpio_Pin_in(PUSH_BOTON_1) != 1)                // ENTRA AL PRESIONAR EL SWITCH DEL PUERTO P1.4 (CUANDO ESTA EN BAJO)
        {
            GPIO_setPinBajo(LED_ROJO_PORT,LED_ROJO);
            if(bandera == FALSE)
            {
                bandera = TRUE;                                 //BANDERA EN ALTO
                while (bandera==TRUE){
                    GPIO_setPinBajo(RGB_PORT, LED_RGB_BLUE);    //APAGA BLUE
                    GPIO_setPinAlto(RGB_PORT,LED_RGB_RED);    //ENCIENDE RED
                    for(i=RETARDO; i>0 ;i--);
                    GPIO_setPinBajo(RGB_PORT, LED_RGB_RED);    //APAGA RED
                    GPIO_setPinAlto(RGB_PORT,LED_RGB_GREEN);    //ENCIENDE GREEN
                    for(i=RETARDO; i>0 ;i--);
                    GPIO_setPinBajo(RGB_PORT, LED_RGB_GREEN);    //APAGA GREEN
                    GPIO_setPinAlto(RGB_PORT,LED_RGB_BLUE);    //ENCIENDE BLUE
                    for(i=RETARDO; i>0 ;i--);
                 if ( Gpio_Pin_in(PUSH_BOTON_1) != 1) bandera=FALSE;    // ENTRA CUANDO PRESIONAMOS BOTON DE P1.4
                 while( Gpio_Pin_in(PUSH_BOTON_1) != 1);                //MIENTRAS ESTE PRESIONADO EL BOTON
                }
            }
            GPIO_setPinAlto(LED_ROJO_PORT,LED_ROJO);
            GPIO_setPinBajo(RGB_PORT, LED_RGB_RED | LED_RGB_GREEN |LED_RGB_BLUE);  //APAGA TODOS
        }
        for(i=RETARDO; i>0 ;i--);

        if ( Gpio_Pin_in_P2(GPIO_PIN7) != 1)
        {
            GPIO_setPinBajo(LED_ROJO_PORT,LED_ROJO);
        }
    }
}

void GPIO_init(void){
    GPIO_setPinEntradaconPullUp(PUSH_BOTON_1_PORT,PUSH_BOTON_1);                 //PIN P1.1 COMO ENTRADA
    GPIO_setPinEntradaconPullUp(GPIO_PORT_P2,GPIO_PIN7);

    GPIO_setPinSalida(LED_ROJO_PORT,LED_ROJO);
    GPIO_setPinAlto(LED_ROJO_PORT,LED_ROJO);

    GPIO_setPinSalida(RGB_PORT, LED_RGB_RED | LED_RGB_GREEN |LED_RGB_BLUE);   // CONFIGURA PINES 2.0,2.1,2.2  COMO SALIDA (LEDS RGB)"
    GPIO_setPinBajo(RGB_PORT, LED_RGB_RED | LED_RGB_GREEN |LED_RGB_BLUE);
}
