#include "controlador.h"

#define TAMANIO_TOTAL 1000
#define LIMITE_INF -500
#define LIMITE_SUP 500
#define PROFUNDIDAD 500
#include <QDebug>
/*
Controlador::Controlador(QObject *parent):QObject(parent){
    cronometro=new QTimer(this);
    connect(cronometro,SIGNAL(timeout()),this,SLOT(onTimeOut()));
}

void Controlador::onTimeOut(){
    ejecuta();
    add();
    if(*contador==final) cronometro->stop();
    this->lcd->display((*contador)++);
}

void Controlador::add(){
    Proceso *proceso;
    int fila;
    for(int i=0,j=procesos->size();i!=j;i++){
        proceso = procesos->at(i);
        if(proceso->get_inicio()==*contador){
            fila=tabla_pendientes->rowCount();
            tabla_pendientes->insertRow(fila);
            tabla_pendientes->setItem(fila,0,new QTableWidgetItem(QString::fromStdString(proceso->get_nombre())));
            tabla_pendientes->setItem(fila,1,new QTableWidgetItem(QString::number(proceso->get_inicio())));
            tabla_pendientes->setItem(fila,2,new QTableWidgetItem(QString::number(proceso->get_duracion())));
            tabla_pendientes->setItem(fila,3,new QTableWidgetItem(QString::number(proceso->get_tiempo_restante())));
            tabla_pendientes->setItem(fila,4,new QTableWidgetItem(QString::number(proceso->get_tiempo_transcurrido())));
            procesos_pendientes->push_back(proceso);
        }
    }
}

void Controlador::ejecuta(){
    Proceso *p;
       int contador=0;
       int  x=-316;
        int temp=x;
        qreal division=PROFUNDIDAD/procesos->size();
        qreal anchuraLinea=division/2;
        int cantidadDeProcesos=procesos->size();
        if(cantidadDeProcesos>40){
            division=15;
            anchuraLinea=8;
        }
        for(std::vector<Proceso*>::iterator i=procesos_pendientes->begin();i!=procesos_pendientes->end();i++){
            p=*i;
            qDebug() << p->get_tiempo_restante();
            if(p->get_tiempo_restante()>0){
                 p->aumenta_tiempo_transcurrido();
                 QBrush colorBrush(colores->at(p->get_numero()));
                 qreal avance=p->getAvanceGrafico(final)*(p->get_tiempo_transcurrido());
                 temp+=division*(p->get_numero());
                 rectangle=new QGraphicsRectItem(p->getInicioGrafico(final),temp,avance,anchuraLinea);
                rectangle->setBrush(colorBrush);
                rectangle->setPen(Qt::NoPen);
                panel->addItem(rectangle);
                tabla_pendientes->setItem(contador,0,new QTableWidgetItem(QString::fromStdString(p->get_nombre())));
                tabla_pendientes->setItem(contador,1,new QTableWidgetItem(QString::number(p->get_inicio())));
                tabla_pendientes->setItem(contador,2,new QTableWidgetItem(QString::number(p->get_duracion())));
                tabla_pendientes->setItem(contador,3,new QTableWidgetItem(QString::number(p->get_tiempo_restante())));
                tabla_pendientes->setItem(contador,4,new QTableWidgetItem(QString::number(p->get_tiempo_transcurrido())));
                if(p->get_tiempo_transcurrido()==p->get_duracion()) p->set_terminado(true);
            }
            if(p->get_terminado() && p->get_print()){
                p->set_print(false);
                tabla_terminados->insertRow(contador);
                tabla_terminados->setItem(contador,0,new QTableWidgetItem(QString::fromStdString(p->get_nombre())));
                tabla_terminados->setItem(contador,1,new QTableWidgetItem(QString::number(p->get_tiempo_fin())));
            }
            contador++;
            temp=x;
        }
}

void Controlador::coloca_mayor_duracion(){
    Proceso* p;
    int mayorTiempo=0;
    for(std::vector<Proceso*>::iterator i=procesos->begin();i!=procesos->end();++i){
        p=*i;
        if(mayorTiempo<p->get_tiempo_fin()) mayorTiempo=p->get_tiempo_fin();
    }
    final=mayorTiempo;
}
void Controlador::init(){
    cronometro->start(1000);
}
*/
