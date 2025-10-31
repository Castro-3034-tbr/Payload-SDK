#include <iostream>
#include <thread>

#include <drone_controller/drone_controller.cpp>


//Definimos las variables globales para los valores de los widgets
int stateProject = 0; // 0: No iniciado 1: Iniciado

/**
 * @brief Funcion main que controla el proyecto LIDIA
 * 
 */
void main_lidia(){
    while (stateProject == 1){
        //Aqui va la logica del proyecto LIDIA
        
    }
}

/**
 * @brief Funcion para inicializa el proyecto LIDIA
 * 
 */
void init_lidia_project(){
    if (stateProject == 0){
        
        //Inicializamos el controlador del dron
        stateProject = 1;

        //Iniciamos el main del proyecto LIDIA en un hilo separado
        std::thread lidiaThread(main_lidia);
        lidiaThread.detach();
    }
}

/**
 * @brief Funcion para desinicializa el proyecto LIDIA
 * 
 */
void deinit_lidia_project(){
    if (stateProject == 1){
        
        //Desinicializamos el controlador del dron
        stateProject = 0;
    }
}


