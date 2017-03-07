/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *quit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layout_scene;
    QWidget *gridLayoutWidget;
    QGridLayout *scoreLayout;
    QLabel *label_score;
    QLabel *score_value;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        quit = new QPushButton(centralwidget);
        quit->setObjectName(QStringLiteral("quit"));
        quit->setGeometry(QRect(670, 430, 92, 27));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 20, 721, 381));
        layout_scene = new QVBoxLayout(verticalLayoutWidget);
        layout_scene->setObjectName(QStringLiteral("layout_scene"));
        layout_scene->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(350, 420, 111, 42));
        scoreLayout = new QGridLayout(gridLayoutWidget);
        scoreLayout->setObjectName(QStringLiteral("scoreLayout"));
        scoreLayout->setContentsMargins(0, 0, 0, 0);
        label_score = new QLabel(gridLayoutWidget);
        label_score->setObjectName(QStringLiteral("label_score"));

        scoreLayout->addWidget(label_score, 1, 0, 1, 1);

        score_value = new QLabel(gridLayoutWidget);
        score_value->setObjectName(QStringLiteral("score_value"));

        scoreLayout->addWidget(score_value, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Casse Brique", 0));
        quit->setText(QApplication::translate("MainWindow", "Quit", 0));
        label_score->setText(QApplication::translate("MainWindow", "Score :", 0));
        score_value->setText(QApplication::translate("MainWindow", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
