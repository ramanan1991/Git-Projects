#include "Mainwindow.h"
#include "ui_mainwindow.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QPushButton>
#include<QGroupBox>
#include"Puzzleblock.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set a window title
    setWindowTitle("15 Puzzle");
    setFixedSize(this->maximumSize());
    this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(430, 410);
    QGraphicsScene *scene = new QGraphicsScene();

    PuzzleBlock * block;

//    PuzzleBlock * bdr1;
//    PuzzleBlock * bdr2;
//    PuzzleBlock * bdr3;
//    PuzzleBlock * bdr4;

    int noBlocks=4;

//    //Add 4 Invisible Borders - For Collsion

//    bdr1=new PuzzleBlock();
//    bdr2=new PuzzleBlock();
//    bdr3=new PuzzleBlock();
//    bdr4=new PuzzleBlock();

//    bdr1->setRect(2,5,1,305);
//    bdr2->setRect(307,5,1,305);
//    bdr3->setRect(5,2,305,1);
//    bdr4->setRect(5,307,305,1);

//    scene->addItem(bdr1);
//    scene->addItem(bdr2);
//    scene->addItem(bdr3);
//    scene->addItem(bdr4);

//    bdr1->setAttribute(Qt::WA_TranslucentBackground, false);

     //add the Blocks to the scene
    for(int i=0; i<noBlocks; i++){
        for(int j=0; j<noBlocks; j++){
            if(!(i==noBlocks-1 && j== noBlocks-1)){
                block = new PuzzleBlock();
                block->setRect((i*70)+((i+1)*5),(j*70)+((j+1)*5),70,70);
                block->setBrush(Qt::blue);
                scene->addItem(block);
            }
        }
    }

    // create a view and add scene to it
    QGraphicsView *view = new QGraphicsView(scene);



    // disabling view scroll bar
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // set fixed view size
    view->setFixedSize(305,305);
    scene->setSceneRect(0,0,305,305);
    gridLayout = new QGridLayout;
    gridLayout->addWidget(view,0,0);

//

    QPushButton *ShuffleButton = new QPushButton("Shuffle");
    QPushButton *sovleButton = new QPushButton("Solve");
    QGroupBox *groupBox = new QGroupBox(tr("Game Actions"));
    QVBoxLayout *verticalBox = new QVBoxLayout;
    verticalBox->addWidget(ShuffleButton);
    verticalBox->addWidget(sovleButton);
    groupBox->setLayout(verticalBox);

    gridLayout->addWidget(groupBox,0,1);
    //gridLayout->addWidget(sovleButton,1,1);
    widget = new QWidget();
    widget->setLayout(gridLayout);
    widget->setFixedSize(430,400);
    setCentralWidget(widget);
    QObject::connect(ShuffleButton, SIGNAL(clicked()),
                     this, SLOT(on_shuffle_button_clicked()));
    QObject::connect(sovleButton, SIGNAL(clicked()),
                     this, SLOT(on_solve_button_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Game_triggered()
{
    // To open a New Game
    qDebug() << "New Game created";
}

void MainWindow::on_shuffle_button_clicked()
{
    qDebug() << "shuffle_button_clicked";

}

void MainWindow::on_solve_button_clicked()
{
    qDebug() << "solve_button_clicked";
}
