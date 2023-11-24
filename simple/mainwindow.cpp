#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtEvents>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize variables
    currentValue = 0;
    secondValue = 0;
    currentOperation = NoOperation;

    // Create the user interface
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Add a QLabel to display the result
    label = new QLabel("0", this);
    label->setAlignment(Qt::AlignRight);
    label->setStyleSheet("font: 18pt;");
    layout->addWidget(label);

    // Create a grid layout for buttons
    QGridLayout *buttonLayout = new QGridLayout;

    // Create digit buttons (0-9)
    for (int i = 0; i <= 9; ++i)
    {
        buttons[i] = new QPushButton(QString::number(i), this);
        buttonLayout->addWidget(buttons[i], i / 3, i % 3);
        buttons[i]->setObjectName(QString("button_%1").arg(i));
        connect(buttons[i], SIGNAL(clicked()), this, SLOT(onDigitButtonClicked()));
    }

    // Create operator buttons (+, -, =)
    QPushButton *addButton = new QPushButton("+", this);
    buttonLayout->addWidget(addButton, 3, 0);
    addButton->setObjectName("button_add");
    connect(addButton, SIGNAL(clicked()), this, SLOT(onOperationButtonClicked()));

    QPushButton *subtractButton = new QPushButton("-", this);
    buttonLayout->addWidget(subtractButton, 3, 1);
    subtractButton->setObjectName("button_subtract");
    connect(subtractButton, SIGNAL(clicked()), this, SLOT(onOperationButtonClicked()));

    QPushButton *mulButton = new QPushButton("*", this);
    buttonLayout->addWidget(mulButton, 3, 2);
    mulButton->setObjectName("button_mul");
    connect(mulButton, SIGNAL(clicked()), this, SLOT(onOperationButtonClicked()));

    QPushButton *divButton = new QPushButton("-", this);
    buttonLayout->addWidget(divButton, 3, 3);
    divButton->setObjectName("button_division");
    connect(divButton, SIGNAL(clicked()), this, SLOT(onOperationButtonClicked()));

    QPushButton *equalButton = new QPushButton("=", this);
    buttonLayout->addWidget(equalButton, 3, 2);
    equalButton->setObjectName("button_equal");
    connect(equalButton, SIGNAL(clicked()), this, SLOT(onEqualButtonClicked()));

    layout->addLayout(buttonLayout);

    setWindowTitle("Simple Calculator");

    // Enable keyboard input by setting focus to the calculator window
    setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_0:
    case Qt::Key_1:
    case Qt::Key_2:
    case Qt::Key_3:
    case Qt::Key_4:
    case Qt::Key_5:
    case Qt::Key_6:
    case Qt::Key_7:
    case Qt::Key_8:
    case Qt::Key_9:
        onDigitButtonClicked(event->key() - Qt::Key_0);
        break;
    case Qt::Key_Plus:
        onOperationButtonClicked("+");
        break;
    case Qt::Key_Minus:
        onOperationButtonClicked("-");
        break;
    case Qt::Key_division:
        onOperationButtonClicked("/");
        break;
    case Qt::Key_multiply:
        onOperationButtonClicked("*");
        break;
    case Qt::Key_Equal:
    case Qt::Key_Return:
        onEqualButtonClicked();
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
}

void MainWindow::onDigitButtonClicked(int digit)
{
    currentValue = currentValue * 10 + digit;
    updateDisplay();
}

void MainWindow::onOperationButtonClicked(const QString &operation)
{
    if (currentOperation != NoOperation)
    {
        onEqualButtonClicked();
    }

    if (operation == "+")
    {
        currentOperation = Addition;
    }
    else if (operation == "-")
    {
        currentOperation = Subtraction;
    }
    else if (operation == "/")
    {
        currentOperation = Division;
    }
    else if (operation == "*")
    {
        currentOperation = Multiply;
    }

    secondValue = currentValue;
    currentValue = 0;
    updateDisplay();
}

void MainWindow::onEqualButtonClicked()
{
    if (currentOperation == Addition)
    {
        currentValue += secondValue;
    }
    else if (currentOperation == Subtraction)
    {
        currentValue = secondValue - currentValue;
    }
    else if (currentOperation == Division)
    {
        currentValue = secondValue / currentValue;
    }
    else if (currentOperation == Multiply)
    {
        currentValue = secondValue * currentValue;
    }
    secondValue = 0;
    currentOperation = NoOperation;
    updateDisplay();
}

void MainWindow::updateDisplay()
{
    label->setText(QString::number(currentValue));
}
