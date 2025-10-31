#include <iostream>
#include "dji_logger.h"
#include "dji_gimbal.h"
#include "dji_gimbal_manager.h"
#include "dji_aircraft_info.h"
#include "dji_fc_subscription.h"

/**
 * @brief Funcion que inicializa control del gimbal
 * @throw std::runtime_error Si la inicializacion falla
 */
void initGimbal() {
    std::cout << "Iniciando control del gimbal..." << std::endl;
    
    // Inicializacion del gimbal
    T_DjiReturnCode returnCode;
    returnCode = DjiGimbalManager_Init();
    if (returnCode != DJI_ERROR_SYSTEM_MODULE_CODE_SUCCESS) {
        USER_LOG_ERROR("Init gimbal manager error, return code 0x%08X", returnCode);
        throw std::runtime_error("Failed to initialize gimbal manager");
    }
}
