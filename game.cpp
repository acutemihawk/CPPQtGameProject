#include "game.h"
#include "entity.h"

Game::Game()
{
     map=new Map(QImage(":/sprites/bg.png"));
     player=new Player();
}

Game::~Game()
{
    free(map);
}

void Game::keyPressEvent(QKeyEvent *event)
{
    player->getKeys()[event->key()] = true;
    movePlayer();
}

void Game::keyReleaseEvent(QKeyEvent *event)
{
    player->getKeys()[event->key()] = false;
}

void Game::movePlayer()
{
    qDebug("oui");
    if(player->getKeys()[68] == true) // key D
    {

        if(isColliding() == false)
        {
            player->setPixMap(QPixmap(":/sprites/droite1.png"));
            player->setPosition(player->getX()+10, player->getY());
        }
        else{
            if(player->getX() > player->getXCollision() - 5){
                player->setPixMap(QPixmap(":/sprites/droite1.png"));
                 player->setPosition(player->getX()+10,player->getY());
            }
        }
    }

    if(player->getKeys()[81] == true) // key Q
    {


        if(isColliding() == false)
        {
            player->setPixMap(QPixmap(":/sprites/gauche1.png"));
            player->setPosition(player->getX()-10, player->getY());
        }
        else{
            if(player->getX() - 5 < player->getXCollision()){
                player->setPixMap(QPixmap(":/sprites/gauche1.png"));
                 player->setPosition(player->getX()-10, player->getY());
            }
        }

    }

    if(player->getKeys()[90] == true) // key Z
    {


        if(isColliding() == false)
        {
            player->setPixMap(QPixmap(":/sprites/derriere1.png"));
            player->setPosition(player->getX(), player->getY()-10);
        }
        else{
            if(player->getY() - 5 < player->getYCollision()){
                player->setPixMap(QPixmap(":/sprites/derriere1.png"));
                player->setPosition(player->getX(), player->getY()-10);
            }
        }
    }

    if(player->getKeys()[83] == true) // key S
    {
        if(isColliding() == false)
        {
            player->setPixMap(QPixmap(":/sprites/devant1.png"));
            player->setPosition(player->getX(), player->getY()+10);
        }
        else{
            if(player->getY() > player->getYCollision() - 5){
                player->setPixMap(QPixmap(":/sprites/devant1.png"));
                player->setPosition(player->getX(), player->getY()+10);
            }
        }

    }


}

bool Game::isColliding()
{
    for (int i = 0, n = player->getColliding_items().size(); i < n; ++i){
        if (typeid(*(player->getColliding_items()[i])) == typeid(Entity)){
            qDebug("PUTAIN CA FAIT MAL ENFOIRE");
            //delete colliding_items[i];
            //delete this;
            player->setXCollision(player->getColliding_items()[i]->pos().x());
            player->setYCollision(player->getColliding_items()[i]->pos().y());
            return true;
        }
        if (typeid(*(player->getColliding_items()[i]))==typeid(Gate)){
            qDebug("TPPPPPPPPP");

        }
    }
    return false;
}

//Level 1
void Game::startGame()
{
    Entity *entity1 = new Entity("un premier test", 100, 100, QPixmap(":/sprites/treelimit.png"));
    map->getScene()->addItem(entity1);
    map->getScene()->addItem(player);

}

//Level 2
void Game::level2()
{
    map->loadNewBackground(QImage(":/sprites/derriere1.png"));
}
