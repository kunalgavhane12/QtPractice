#include "mainwindow.h"
#include "customgraphicsview.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , centralWidget(new QWidget(this))
    , tabPlant(new QTabWidget(this))
    , tabPage(new QTabWidget(this))
{
    setupUI();
}

void MainWindow::setupUI()
{
    createTabs();
    setCentralWidget(centralWidget);
    QHBoxLayout *hlayout = new QHBoxLayout(centralWidget);
    hlayout->setMargin(2);
    hlayout->addWidget(tabPlant);
    centralWidget->setLayout(hlayout);
    setMinimumSize(800, 650);

    connect(tabPlant, &QTabWidget::tabCloseRequested, this, &MainWindow::closePlantTab);
    connect(tabPage, &QTabWidget::tabCloseRequested, this, &MainWindow::closePageTab);
    connect(tabPage, &QTabWidget::currentChanged, this, &MainWindow::addNewPageTab);
    connect(tabPlant, &QTabWidget::currentChanged, this, &MainWindow::addNewPlantTab);
}

void MainWindow::createTabs()
{
    QWidget *tab1 = new QWidget(this);
    QVBoxLayout *tab1Layout = new QVBoxLayout(tab1);
    tab1Layout->addWidget(tabPage);
    tab1->setLayout(tab1Layout);
    tabPlant->addTab(tab1, "Plant Stage #1");

    QWidget *tab2 = new QWidget(this);
    tabPlant->addTab(tab2, "+ Stage");

    CustomGraphicsView *initialGraphicsView = new CustomGraphicsView(this);
    initialGraphicsView->setFixedSizeAndScene(QSize(600, 400));  // Set fixed size
    tabPage->addTab(initialGraphicsView, "Page #1");
    tabPage->addTab(new QWidget(this), "+ Page");

    tabPlant->setTabsClosable(true);
    tabPage->setTabsClosable(true);
}

void MainWindow::addNewPlantTab(int index)
{
    if (index == tabPlant->count() - 1) {
        QWidget *newStage = new QWidget(this);
        QVBoxLayout *layout = new QVBoxLayout(newStage);
        newStage->setLayout(layout);

        QTabWidget *newPageTabWidget = new QTabWidget(this);
        layout->addWidget(newPageTabWidget);

        tabPlant->insertTab(tabPlant->count() - 1, newStage, tr("Plant Stage #%1").arg(tabPlant->count()));
        tabPlant->setCurrentIndex(tabPlant->count() - 2);

        CustomGraphicsView *newGraphicsView = new CustomGraphicsView(this);
        newGraphicsView->setFixedSizeAndScene(QSize(600, 400));  // Set fixed size
        newPageTabWidget->addTab(newGraphicsView, "Page #1");
        newPageTabWidget->addTab(new QWidget(this), "+ Page");
        newPageTabWidget->setTabsClosable(true);
    }
}

void MainWindow::addNewPageTab(int index)
{
    if (index == tabPage->count() - 1) {
        CustomGraphicsView *newGraphicsView = new CustomGraphicsView(this);
        newGraphicsView->setFixedSizeAndScene(QSize(600, 400));  // Set fixed size
        tabPage->insertTab(tabPage->count() - 1, newGraphicsView, tr("Page #%1").arg(tabPage->count()));
        tabPage->setCurrentIndex(tabPage->count() - 2);
    }
}

void MainWindow::closePlantTab(int index)
{
    if (index <= 0 || index >= tabPlant->count() - 1) {
        qDebug() << "Cannot close tab at index" << index;
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Close",
        "Do you want to save changes before closing?",
        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

    if (reply == QMessageBox::Cancel) {
        return;
    }

    if (reply == QMessageBox::Yes) {
        int newIndex = (index > 0) ? index - 1 : 0;
        tabPlant->setCurrentIndex(newIndex);
    }

    qDebug() << "Closing Plant tab at index" << index;

    QWidget* tabItem = tabPlant->widget(index);
    if (tabItem) {
        tabPlant->removeTab(index);
        delete tabItem;
    } else {
        qDebug() << "No widget found at index" << index;
    }
}

void MainWindow::closePageTab(int index)
{
    if (index <= 0 || index >= tabPage->count() - 1) {
        qDebug() << "Cannot close tab at index" << index;
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Close",
        "Do you want to save changes before closing?",
        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

    if (reply == QMessageBox::Cancel) {
        return;
    }

    if (reply == QMessageBox::Yes) {
        int newIndex = (index > 0) ? index - 1 : 0;
        tabPage->setCurrentIndex(newIndex);
    }

    qDebug() << "Closing Page tab at index" << index;

    QWidget* tabItem = tabPage->widget(index);
    if (tabItem) {
        tabPage->removeTab(index);
        delete tabItem;
    } else {
        qDebug() << "No widget found at index" << index;
    }
}
