/**
 ********************************************************************
 * @file    main.cpp
 * @brief
 *
 * @copyright (c) 2021 DJI. All rights reserved.
 *
 * All information contained herein is, and remains, the property of DJI.
 * The intellectual and technical concepts contained herein are proprietary
 * to DJI and may be covered by U.S. and foreign patents, patents in process,
 * and protected by trade secret or copyright law.  Dissemination of this
 * information, including but not limited to data and other proprietary
 * material(s) incorporated within the information, in any form, is strictly
 * prohibited without the express written consent of DJI.
 *
 * If you receive this source code without DJI’s authorization, you may not
 * further disseminate the information, and you must immediately remove the
 * source code and notify DJI of its removal. DJI reserves the right to pursue
 * legal actions against you for any loss(es) or damage(s) caused by your
 * failure to do so.
 *
 *********************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include <liveview/test_liveview_entry.hpp>
#include <perception/test_perception_entry.hpp>
#include <perception/test_lidar_entry.hpp>
#include <perception/test_radar_entry.hpp>
#include <flight_control/test_flight_control.h>
#include <gimbal/test_gimbal_entry.hpp>
#include "application.hpp"
#include <dji_logger.h>
#include "widget/test_widget.h"
#include "widget/test_widget_speaker.h"
#include <widget_manager/test_widget_manager.hpp>
#include <power_management/test_power_management.h>
#include "data_transmission/test_data_transmission.h"
#include <flight_controller/test_flight_controller_entry.h>
#include <positioning/test_positioning.h>
#include <hms_manager/hms_manager_entry.h>
#include "camera_manager/test_camera_manager_entry.h"
#include <hms_manager/hms_manager_entry.h>
#include <liveview/dji_liveview_object_detection.hpp>
#include "liveview/test_liveview.h"
#include <signal.h>
/* Private constants ---------------------------------------------------------*/

/* Private types -------------------------------------------------------------*/

/* Private values -------------------------------------------------------------*/

/* Private functions declaration ---------------------------------------------*/

/* Exported functions definition ---------------------------------------------*/

//Definimos las variables globales para los valores de los widgets
int ActiveProject = 0; // 0: No 1: Si

int main(int argc, char **argv)
{
    signal(SIGINT, [](int signalNum) -> void { exit(0); });
    Application application(argc, argv);
    char inputChar;
    T_DjiOsalHandler *osalHandler = DjiPlatform_GetOsalHandler();
    T_DjiReturnCode returnCode;
    E_DjiMountPosition mountPosition = DJI_MOUNT_POSITION_PAYLOAD_PORT_NO1;

start:

    //Bucle que obtiene el valor de un widget
    while (true){
        //Comprobamos que el valor del widget SWITCH es 1 o 0
        if (ValueSWITCH == 1){
            std::cout << "El proyecto está " << ActiveProject << " ACTIVO" << std::endl;
            std::cout << "Proyecto seleccionado: " << ValueLIST << std::endl;

            if (ActiveProject != 1){
                //Iniciamos las funcionalidades del proyecto seleccionado
                if (ValueLIST == "Proyecto LIDIA"){
                    USER_LOG_INFO("Iniciando Proyecto LIDIA...");
                    //Llamamos a la función run de la clase DroneControl

                }
                else if (ValueLIST == "Proyecto 2"){
                    USER_LOG_INFO("Iniciando Proyecto 2...");

                }
                else if (ValueLIST == "Proyecto 3"){
                    USER_LOG_INFO("Iniciando Proyecto 3...");
                }
                else if (ValueLIST == "Proyecto 4"){
                    USER_LOG_INFO("Iniciando Proyecto 4...");
                }
            }
            ActiveProject = 1;
        }
        else{
            USER_LOG_INFO("El proyecto está INACTIVO");

            //Mensaje de parada de proyecto
            if (ActiveProject != 0){
                USER_LOG_INFO("Deteniendo el proyecto %s...", ValueLIST);
            }
            ActiveProject = 0;
        }
            break; // Salimos del bucle si el proyecto no está activo

    }

    osalHandler->TaskSleepMs(2000);

    goto start;
}

/* Private functions definition-----------------------------------------------*/

/****************** (C) COPYRIGHT DJI Innovations *****END OF FILE****/
