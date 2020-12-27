#include "Health.h"
#include <QFont>
#include <QMessageBox>
#include "Game.h"
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){

    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
}

int Health::getHealth(){
    return health;
}

extern Game *game;
void Health::checkHealth(){
    if (game->health->getHealth()<=0){

        QMessageBox::StandardButton reply;
        game->pause=true;
        reply = QMessageBox::question(game, "You lose!", ("    Your score is " + QString::number(game->score->getScore())+  "\nWould you like to try again?"),
                                                          QMessageBox::Yes | QMessageBox::No);
        //ask for restarting the game
            if (reply == QMessageBox::No)
            {
                game->scene->clear();
                game->close();
            }
            else
            {
                game->scene->clear();
                game->close();
                game = new Game();
                game->show();
            }

    }
}
