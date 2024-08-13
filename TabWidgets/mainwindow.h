#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include "customgraphicsview.h"

class QLabel;
class QVBoxLayout;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void addNewPlantTab(int index);
    void addNewPageTab(int index);
    void closePlantTab(int index);
    void closePageTab(int index);
private:
    void setupUI();
    void createTabs();

private:
    QWidget *centralWidget;
    QTabWidget *tabPlant;
    QTabWidget *tabPage;
    CustomGraphicsView *graphicsView;
    int currentPlantStageIndex;
};

#endif // MAINWINDOW_H
