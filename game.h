
#ifndef GAME_H
#define GAME_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow

{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

private:
    Ui::Game *ui;
    void gamelogic();
    void enemyResult();
    void restarResult();
    void endCom();


};

#endif // GAME_H
