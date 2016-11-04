#ifndef PROCESO_H
#define PROCESO_H
#include <iostream>
#include <QDebug>

#define LIMITE_SCENE 500

class Proceso{
private:
    int numero;
    std::string nombre;
    int inicio;
    int duracion;
    int tiempo_transcurrido;
    int tiempo_restante;
    int tiempo_fin;
    bool terminado;
    bool print;
public:
    int tiempoDuracionSinModificar;
    Proceso();
    Proceso(int numero,std::string nombre,int inicio,int duracion):numero(numero),nombre(nombre),inicio(inicio),duracion(duracion){
        tiempo_restante=duracion;
        tiempo_transcurrido=0;
        tiempoDuracionSinModificar=duracion;
        terminado = false;
        print = true;
    }
    void set_nombre(std::string nombre){
        this->nombre=nombre;
    }
    void set_inicio(int inicio){
        this->inicio=inicio;
    }
    void set_duracion(int duracion){
        this->duracion=duracion;
    }
    void set_numero(int numero){
        this->numero=numero;
    }
    std::string get_nombre(){
        return nombre;
    }
    int get_inicio(){
        return inicio;
    }
    int get_duracion(){
        return duracion;
    }
    int get_numero(){
        return numero;
    }
    int get_tiempo_transcurrido(){
        return tiempo_transcurrido;
    }
    int get_tiempo_fin(){
        return inicio+duracion;
    }
    int get_tiempo_restante(){
        return duracion-tiempo_transcurrido;
    }
    void reduce_tiempo_restante(){
        tiempo_restante--;
    }
    void aumenta_tiempo_transcurrido(){
        tiempo_transcurrido++;
    }
    int getInicioGrafico(int tiempoMayor){
        int tiempo=LIMITE_SCENE*get_inicio();
        if(get_inicio()==0){
            return -500;
        }
        tiempo=tiempo/tiempoMayor;
        if(tiempo<=500){
            tiempo=tiempo-500;
        }else{
            tiempo=tiempo-500;
        }
        qDebug() << tiempo;
        return tiempo;
    }

    int getFinGrafico(int tiempoMayor){
        int tiempo=LIMITE_SCENE*get_tiempo_fin();
        tiempo=tiempo/tiempoMayor;
        return tiempo;
    }
    bool get_terminado(){
        return terminado;
    }
    void set_terminado(bool terminado){
        this->terminado=terminado;
    }
    bool get_print(){
        return print;
    }
    void set_print(bool print){
        this->print=print;
    }

    int getAvanceGrafico(int tiempoMayor){
        return LIMITE_SCENE/tiempoMayor;
    }
};

#endif // PROCESO_H
