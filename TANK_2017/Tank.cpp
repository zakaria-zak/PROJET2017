#include "Tank.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <typeinfo>
#include <iostream>

using namespace std;
extern int aqt;


//extern fenetre * fenetre;


Tank::Tank(contenu_case pere[10][6])
{

    setPixmap(QPixmap("image_tank.jpg"));
    direction = 0;
    comptobus1 = 10;
    comptobus2 = 3;
    typeobus =  1;
    canon_tank= new Canon();
    canon_tank->setFlag(QGraphicsItem::ItemIsFocusable);
    canon_tank->setTransformOriginPoint(5,30);
    int i,j;
    for(i=0; i<10 ;i++)
        for(j=0; j<6 ;j++)
            plateau[i][j] = pere[i][j] ;


    obus2 = new Obus(0);
    obus3 = new Obus(0); //inutile ?
    setZValue(1);// tank superieur a tout les elements de la scene(a part canon)

}


void Tank::keyPressEvent(QKeyEvent *event){


        if (event->key() == Qt::Key_1){
        typeobus = 1;
        }
        if (event->key() == Qt::Key_2){
        typeobus = 2;
        }
        if (event->key() == Qt::Key_3){
        typeobus = 3;
        }
        if (event->key() == Qt::Key_Left){
                setRotation(270);
                if(direction == 0){
                    setPos(x()+10,y()+50);
                    direction = 3;

                   }
                    if(direction == 2){
                    setPos(x()-40,y()-25);
                    direction = 3;

                    }
                    if(direction == 1){
                    setPos(x()-65,y()+50);
                    direction = 3;

                    }
                    //

                    canon_tank->setRotation(-90);
                     canon_tank->setPos(x()+15,y()-53);
                    //
                if (pos().x() > 0){ // pour pas que il sorte de la fenetre
                    int a =(x()/100)-1;
                    int b =y()/100;
                    int c = x();
                   int a2 =((y()-50)/100);// test pour les 2 cotes avant du tank
                    if( ( (c % 100) > 10) || ((a >= 0) && (plateau[a][b] == rien) && (plateau[a][a2] == rien) ))
                setPos(x()-10,y());
}
             }
            else if (event->key() == Qt::Key_Right){
                setRotation(90);
                if(direction == 0){
                    setPos(x()+65,y());
                    direction = 1;

                   }
                    if(direction == 2){
                    setPos(x()+15,y()-70);
                    direction = 1;

                    }
                    if(direction == 3){
                    setPos(x()+65,y()-50);
                    direction = 1;

                    }
                    //
                     canon_tank->setRotation(90);
                      canon_tank->setPos(x()-25,y()-5);
                      //
                if (pos().x() < 1000){
                    int a =((x())/100)+1;
                    int b =y()/100;
                    int c = x();
                 int a2 =((y()+50)/100);
                    if( ( (c % 100) < 90) || ((a < 10) && (plateau[a][b] == rien) && (plateau[a][a2] == rien)))
                    setPos(x()+10,y());
             }
            }

            else if (event->key() == Qt::Key_Up){//si jappuie up
                setRotation(0);
                if(direction == 2){ //si direction est bas
                setPos(x()-50,y()-65);
                direction = 0;

                }
                if(direction == 1){ //si direction est droite
                setPos(x()-73,y()+12);
                direction = 0;

                }
                if(direction == 3){ //si direction est gauche
                setPos(x(),y()-40);
                direction = 0;

                }

                canon_tank->setRotation(0);
                 canon_tank->setPos(x()+20,y()-10);
                if (pos().y()>0){
                    int a =(x()/100);
                    int a2 =((x()+50)/100);
                    int b =(y()/100) - 1;
                    int c = y();
                    if( ( (c % 100) > 10) || ((b >= 0) && (plateau[a][b] == rien) && (plateau[a2][b] == rien)))
                setPos(x(),y()-10);
             }
            }


           else if (event->key() == Qt::Key_Down){
                setRotation(180);
                if(direction == 0){
                    setPos(x()+50,y()+65);
                    direction = 2;
                   }
                    if(direction == 1){
                    setPos(x()-25,y()+65);
                    direction = 2;
                    }
                    if(direction == 3){
                    setPos(x()+50,y()+15);
                    direction = 2;

                    }

                    canon_tank->setRotation(-180);
                     canon_tank->setPos(x()-28,y()-50);
                if (pos().y()<600){
                    int a =(x()/100);
                    int b =(y()/100) + 1;
                    int c = y();
                    int a2 =((x()-50)/100);
                    if( ( (c % 100) < 90) || ((b < 6) && (plateau[a][b] == rien) && (plateau[a2][b] == rien)))

                setPos(x(),y()+10);
        }
    }
            else if (event->key() == Qt::Key_Q){
              canon_tank->setRotation(canon_tank->angleH - 10);
              canon_tank->angleH -= 10;

             }
            else if (event->key() == Qt::Key_W){
                canon_tank->setRotation(canon_tank->angleH + 10);
                canon_tank->angleH += 10;
             }
            else if ((event->key() == Qt::Key_S)&&(canon_tank->angleV < 90)){
              canon_tank->angleV += 10;
              cout << canon_tank->angleV << endl;

             }
            else if ((event->key() == Qt::Key_X)&&(canon_tank->angleV > 0)){
                canon_tank->angleV -= 10;
                cout << canon_tank->angleV << endl;
             }





   else if (event->key() == Qt::Key_I && comptobus1 > 0 && typeobus == 1){

                obus1 = new Obus(0);// creation obus pour chaque impact
                comptobus1 = comptobus1 - 1;

        if ((direction==0) && (canon_tank->angleV<30))
        {
            int a =((x()+50)/100);
            int b =(y()/100) - 1;

       obus1->setPos(a*100,b*100);
       plateau[a][b]=rien;
        scene()->addItem(obus1);
        adversaire->setFocus();// si on tire, on "set" le focus sur l'autre adversaire
        }


        else if ((direction==1) && (canon_tank->angleV<30))
        {
            int a =((x())/100)+1;
            int b =y()/100;

       obus1->setPos(a*100,b*100);
       plateau[a][b]=rien;
        scene()->addItem(obus1);
        adversaire->setFocus();
        }


        else if ((direction==2) && (canon_tank->angleV<30))
        {
            int a =(x()/100);
            int b =(y()/100) + 1;

       obus1->setPos(a*100,b*100);
       plateau[a][b]=rien;
        scene()->addItem(obus1);
       adversaire->setFocus();
        }

        else if ((direction==3) && (canon_tank->angleV<30))
        {
            int a =(x()/100)-1;
            int b =y()/100;
       obus1->setPos(a*100,b*100);
       //stockage impact
       plateau[a][b]=rien;
        scene()->addItem(obus1);
      adversaire->setFocus();
        }

  }// fin key I obus type 1 _____________________________________________________


        else if (event->key() == Qt::Key_I && comptobus2 > 0 && typeobus == 2){

                     obus2 = new Obus(0);// creation obus pour chaque impact
                     obus3 = new Obus(0);
                     comptobus2 = comptobus2 - 1;

             if ((direction==0) && (canon_tank->angleV<30))
             {
                 int a =((x()+50)/100);
                 int b =(y()/100) - 1;

            obus2->setPos(a*100,b*100);
            plateau[a][b]=rien;
             scene()->addItem(obus2);

             obus3->setPos(a*100,b*100 -100);
             plateau[a][b-1]=rien;
              scene()->addItem(obus3);
                adversaire->setFocus();
             }


             else if ((direction==1) && (canon_tank->angleV<30))
             {
                 int a =((x())/100)+1;
                 int b =y()/100;

            obus2->setPos(a*100,b*100);
            plateau[a][b]=rien;
             scene()->addItem(obus2);

             obus3->setPos(a*100 +100,b*100);
             plateau[a+1][b]=rien;
              scene()->addItem(obus3);
             adversaire->setFocus();
             }


             else if ((direction==2) && (canon_tank->angleV<30))
             {
                 int a =(x()/100);
                 int b =(y()/100) + 1;

            obus2->setPos(a*100,b*100);
            plateau[a][b]=rien;
             scene()->addItem(obus2);

             obus3->setPos(a*100,b*100 +100);
             plateau[a][b+1]=rien;
              scene()->addItem(obus3);
            adversaire->setFocus();
             }

             else if ((direction==3) && (canon_tank->angleV<30))
             {
                 int a =(x()/100)-1;
                 int b =y()/100;
            obus2->setPos(a*100,b*100);
            //stockage impact
            plateau[a][b]=rien;
             scene()->addItem(obus2);

             obus3->setPos(a*100 -100,b*100);
             plateau[a-1][b]=rien;
              scene()->addItem(obus3);
                adversaire->setFocus();
             }



         }// fin key I obus type 2____________________________________________________________________________


/*
        else if (event->key() == Qt::Key_I && comptobus2 > 0 && typeobus == 3){
                     obus2 = new Obus(0);// creation obus pour chaque impact
                     obus3 = new Obus(0);
                     comptobus2 = comptobus2 - 1;
             if ((direction==0) && (canon_tank->angleV<30))
             {
                 int a =((x()+50)/100);
                 int b =(y()/100) - 1;
            obus2->setPos(a*100,b*100);
            plateau[a][b]=rien;
             scene()->addItem(obus2);
             obus3->setPos(a*100,b*100 -100);
             plateau[a][b-1]=rien;
              scene()->addItem(obus3);
              obus4->setPos(a*100+100,b*100); //BUG ICI ! FAIRE APPARAITRE 3 OBUS FAIT PLANTER, REDIMENSIONNER UNE AUTRE IMAGE POUR LE
              plateau[a+1][b]=rien;             // setPos de obus4 et faire les affecations au plateau habituel.(probleme visuel)
               scene()->addItem(obus4);
             //actif += 1;
             }
             else if ((direction==1) && (canon_tank->angleV<30))
             {
                 int a =((x())/100)+1;
                 int b =y()/100;
            obus2->setPos(a*100,b*100);
            plateau[a][b]=rien;
             scene()->addItem(obus2);
             obus3->setPos(a*100 +100,b*100);
             plateau[a+1][b]=rien;
              scene()->addItem(obus3);
             // actif += 1;
             }
             else if ((direction==2) && (canon_tank->angleV<30))
             {
                 int a =(x()/100);
                 int b =(y()/100) + 1;
            obus2->setPos(a*100,b*100);
            plateau[a][b]=rien;
             scene()->addItem(obus2);
             obus3->setPos(a*100,b*100 +100);
             plateau[a][b+1]=rien;
              scene()->addItem(obus3);
             // actif += 1;
             }
             else if ((direction==3) && (canon_tank->angleV<30))
             {
                 int a =(x()/100)-1;
                 int b =y()/100;
            obus2->setPos(a*100,b*100);
            //stockage impact
            plateau[a][b]=rien;
             scene()->addItem(obus2);
             obus3->setPos(a*100 -100,b*100);
             plateau[a-1][b]=rien;
              scene()->addItem(obus3);
            // actif += 1;
             }
         }// fin key I obus type 3
*/


}// fin focntion key press event


void Tank::setAdversaire(Tank* T){
    adversaire = T;
}
// fonction qui permet de lier un tank a son adversaire
