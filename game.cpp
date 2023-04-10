
#include "game.h"
#include "./ui_game.h"
#include <cstdlib>
#include <ctime>
#include <QWidget>


Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    connect(ui->paper, &QPushButton::clicked, this, &Game::gamelogic);
    connect(ui->rock, &QPushButton::clicked, this, &Game::gamelogic);
    connect(ui->scissor, &QPushButton::clicked, this, &Game::gamelogic);
    connect(ui->restar, &QPushButton::clicked, this, &Game::restarResult);
    srand(time(NULL));
    ui->finish->setVisible(false);
       ui->restar->setVisible(false);
}

void Game::restarResult() {
    // Cerrar ventana actual
    close();
    // Crear una nueva instancia de la ventana principal
    srand(time(NULL));
    Game *newGame = new Game();
    // Mostrar la ventana
    newGame->show();
}
int playerOption;

#include <random>
#include <chrono>

// ...

#include <random>

// ...



void Game::enemyResult(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 3);
    int enemyChoice = dist(gen);
    srand(time(NULL));
    std::string direction = "C:/Users/Daniel/Desktop/build-Game-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/";
    if(enemyChoice==1){
        direction = direction + "rock.png";
        ui->Image->setPixmap(QString::fromStdString(direction));
        ui->result->setText("Enemy: Rock");
        if(playerOption==1){
            ui->finish->setVisible(true);
             ui->restar->setVisible(true);

            ui->finish->setText("DRAW");

        }
        if(playerOption==2){
            ui->finish->setVisible(true);
              ui->restar->setVisible(true);
            ui->finish->setText("YOU LOSE");

        }
        if(playerOption==3){
            ui->finish->setVisible(true);
             ui->restar->setVisible(true);
            ui->finish->setText("YOU WIN");

        }



    }
    if(enemyChoice==2){
        direction = direction + "scissor.png";
        ui->Image->setPixmap(QString::fromStdString(direction));
        ui->result->setText("Enemy: Scissor");
        if(playerOption==1){
             ui->finish->setVisible(true);
             ui->restar->setVisible(true);
            ui->finish->setText("YOU WIN");

        }
        if(playerOption==2){
            ui->finish->setVisible(true);
             ui->restar->setVisible(true);
            ui->finish->setText("DRAW");

        }
        if(playerOption==3){
            ui->finish->setVisible(true);
             ui->restar->setVisible(true);
            ui->finish->setText("YOU LOSE");

        }


    }
    if(enemyChoice==3){
         direction = direction + "paper.png";
        ui->Image->setPixmap(QString::fromStdString(direction));
        ui->result->setText("Enemy: Paper");
        if(playerOption==1){
            ui->finish->setVisible(true);
            ui->restar->setVisible(true);
            ui->finish->setText("YOU LOSE");

        }
        if(playerOption==2){
            ui->finish->setVisible(true);
            ui->restar->setVisible(true);
            ui->finish->setText("YOU WIN");

        }
        if(playerOption==3){
            ui->finish->setVisible(true);
            ui->restar->setVisible(true);
            ui->finish->setText("DRAW");

        }

    }
}

void Game::gamelogic()

{

        // Inicializar la semilla


    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
        if (button->objectName() == "rock")
        {
            playerOption = 1;
            enemyResult();
            ui->rock->setStyleSheet("QPushButton{color: #0078d7;background-color:black;border: 5px;border-radius: 20px;}");
        }
        else if (button->objectName() == "scissor")
        {
          playerOption = 2;
          enemyResult();
          ui->scissor->setStyleSheet("QPushButton{color:#E26060;background-color:black;;border: 5px;border-radius: 20px;}");
        }
        else if (button->objectName() == "paper")
        {
           playerOption = 3;
           enemyResult();
           ui->paper->setStyleSheet("QPushButton{color: yellow;background-color:black;;border: 5px;border-radius: 20px;}");
        }
    }

}







Game::~Game()
{
    delete ui;
}


