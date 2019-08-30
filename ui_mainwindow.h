/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_2;
    QLineEdit *ClientClasslineEdit;
    QLabel *label_3;
    QLineEdit *PlatformBaseClasslineEdit;
    QLabel *label_4;
    QGroupBox *groupBox;
    QListView *PlatformClasseslistView;
    QPushButton *AddPlatformClasspushButton;
    QPushButton *DeletePlatformClasspushButton;
    QListWidget *PlatformMethodslistWidget;
    QPushButton *DeletePlatformMethodspushButton;
    QPushButton *AddPlatformMethodspushButton;
    QLabel *label_8;
    QLabel *label_9;
    QGroupBox *groupBox_2;
    QPushButton *DeleteProductClasspushButton;
    QPushButton *AddProductClasspushButton;
    QListWidget *ProductMethodslistWidget;
    QPushButton *DeleteProductMethodspushButton;
    QPushButton *AddProductMethodspushButton;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *ProductBaseClasseslistWidget_2;
    QLabel *label_10;
    QPushButton *PopulateProductClassesPushButton;
    QListWidget *ProductClasseslistView;
    QGraphicsView *graphicsView;
    QListWidget *ProductBaseClasseslistWidget;
    QPushButton *AddProductListpushButton;
    QPushButton *ClearProductListpushButton;
    QWidget *tab_2;
    QLabel *label;
    QComboBox *DesignPatternscomboBox;
    QGroupBox *groupBox_3;
    QPushButton *GeneratepushButton;
    QLabel *label_5;
    QLineEdit *SrcDirectorylineEdit;
    QPushButton *BrowsepushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1050, 921);
        MainWindow->setMinimumSize(QSize(1050, 921));
        MainWindow->setMaximumSize(QSize(1050, 921));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 100, 1031, 751));
        tabWidget->setMinimumSize(QSize(1031, 751));
        tabWidget->setMaximumSize(QSize(1031, 751));
        QFont font;
        font.setPointSize(14);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 34, 171, 17));
        QFont font1;
        font1.setPointSize(16);
        label_2->setFont(font1);
        ClientClasslineEdit = new QLineEdit(tab);
        ClientClasslineEdit->setObjectName(QStringLiteral("ClientClasslineEdit"));
        ClientClasslineEdit->setGeometry(QRect(260, 25, 241, 41));
        QFont font2;
        font2.setPointSize(15);
        ClientClasslineEdit->setFont(font2);
        ClientClasslineEdit->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 94, 201, 17));
        label_3->setFont(font1);
        PlatformBaseClasslineEdit = new QLineEdit(tab);
        PlatformBaseClasslineEdit->setObjectName(QStringLiteral("PlatformBaseClasslineEdit"));
        PlatformBaseClasslineEdit->setGeometry(QRect(260, 84, 241, 41));
        PlatformBaseClasslineEdit->setFont(font2);
        PlatformBaseClasslineEdit->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 159, 201, 17));
        label_4->setFont(font1);
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(530, 0, 481, 331));
        PlatformClasseslistView = new QListView(groupBox);
        PlatformClasseslistView->setObjectName(QStringLiteral("PlatformClasseslistView"));
        PlatformClasseslistView->setGeometry(QRect(20, 71, 281, 91));
        AddPlatformClasspushButton = new QPushButton(groupBox);
        AddPlatformClasspushButton->setObjectName(QStringLiteral("AddPlatformClasspushButton"));
        AddPlatformClasspushButton->setGeometry(QRect(320, 71, 151, 41));
        DeletePlatformClasspushButton = new QPushButton(groupBox);
        DeletePlatformClasspushButton->setObjectName(QStringLiteral("DeletePlatformClasspushButton"));
        DeletePlatformClasspushButton->setGeometry(QRect(320, 118, 151, 41));
        PlatformMethodslistWidget = new QListWidget(groupBox);
        PlatformMethodslistWidget->setObjectName(QStringLiteral("PlatformMethodslistWidget"));
        PlatformMethodslistWidget->setGeometry(QRect(20, 227, 281, 91));
        DeletePlatformMethodspushButton = new QPushButton(groupBox);
        DeletePlatformMethodspushButton->setObjectName(QStringLiteral("DeletePlatformMethodspushButton"));
        DeletePlatformMethodspushButton->setGeometry(QRect(320, 274, 151, 41));
        AddPlatformMethodspushButton = new QPushButton(groupBox);
        AddPlatformMethodspushButton->setObjectName(QStringLiteral("AddPlatformMethodspushButton"));
        AddPlatformMethodspushButton->setGeometry(QRect(320, 227, 151, 41));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 197, 301, 17));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(19, 46, 301, 17));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(530, 340, 481, 351));
        DeleteProductClasspushButton = new QPushButton(groupBox_2);
        DeleteProductClasspushButton->setObjectName(QStringLiteral("DeleteProductClasspushButton"));
        DeleteProductClasspushButton->setGeometry(QRect(320, 170, 151, 41));
        AddProductClasspushButton = new QPushButton(groupBox_2);
        AddProductClasspushButton->setObjectName(QStringLiteral("AddProductClasspushButton"));
        AddProductClasspushButton->setGeometry(QRect(320, 121, 151, 41));
        ProductMethodslistWidget = new QListWidget(groupBox_2);
        ProductMethodslistWidget->setObjectName(QStringLiteral("ProductMethodslistWidget"));
        ProductMethodslistWidget->setGeometry(QRect(20, 249, 281, 91));
        DeleteProductMethodspushButton = new QPushButton(groupBox_2);
        DeleteProductMethodspushButton->setObjectName(QStringLiteral("DeleteProductMethodspushButton"));
        DeleteProductMethodspushButton->setGeometry(QRect(320, 296, 151, 41));
        AddProductMethodspushButton = new QPushButton(groupBox_2);
        AddProductMethodspushButton->setObjectName(QStringLiteral("AddProductMethodspushButton"));
        AddProductMethodspushButton->setGeometry(QRect(320, 249, 151, 41));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 219, 301, 17));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 38, 301, 17));
        ProductBaseClasseslistWidget_2 = new QComboBox(groupBox_2);
        ProductBaseClasseslistWidget_2->setObjectName(QStringLiteral("ProductBaseClasseslistWidget_2"));
        ProductBaseClasseslistWidget_2->setGeometry(QRect(20, 58, 281, 31));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 100, 291, 17));
        PopulateProductClassesPushButton = new QPushButton(groupBox_2);
        PopulateProductClassesPushButton->setObjectName(QStringLiteral("PopulateProductClassesPushButton"));
        PopulateProductClassesPushButton->setGeometry(QRect(320, 64, 151, 41));
        ProductClasseslistView = new QListWidget(groupBox_2);
        ProductClasseslistView->setObjectName(QStringLiteral("ProductClasseslistView"));
        ProductClasseslistView->setGeometry(QRect(20, 120, 281, 91));
        graphicsView = new QGraphicsView(tab);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(20, 260, 481, 441));
        ProductBaseClasseslistWidget = new QListWidget(tab);
        ProductBaseClasseslistWidget->setObjectName(QStringLiteral("ProductBaseClasseslistWidget"));
        ProductBaseClasseslistWidget->setGeometry(QRect(260, 140, 241, 51));
        AddProductListpushButton = new QPushButton(tab);
        AddProductListpushButton->setObjectName(QStringLiteral("AddProductListpushButton"));
        AddProductListpushButton->setGeometry(QRect(260, 200, 121, 41));
        ClearProductListpushButton = new QPushButton(tab);
        ClearProductListpushButton->setObjectName(QStringLiteral("ClearProductListpushButton"));
        ClearProductListpushButton->setGeometry(QRect(390, 200, 111, 41));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 201, 31));
        label->setFont(font2);
        DesignPatternscomboBox = new QComboBox(centralWidget);
        DesignPatternscomboBox->addItem(QString());
        DesignPatternscomboBox->setObjectName(QStringLiteral("DesignPatternscomboBox"));
        DesignPatternscomboBox->setGeometry(QRect(170, 30, 341, 41));
        DesignPatternscomboBox->setFont(font);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(550, 0, 491, 121));
        GeneratepushButton = new QPushButton(groupBox_3);
        GeneratepushButton->setObjectName(QStringLiteral("GeneratepushButton"));
        GeneratepushButton->setGeometry(QRect(340, 70, 121, 41));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 30, 141, 31));
        label_5->setFont(font2);
        SrcDirectorylineEdit = new QLineEdit(groupBox_3);
        SrcDirectorylineEdit->setObjectName(QStringLiteral("SrcDirectorylineEdit"));
        SrcDirectorylineEdit->setGeometry(QRect(200, 30, 261, 31));
        SrcDirectorylineEdit->setReadOnly(true);
        BrowsepushButton = new QPushButton(groupBox_3);
        BrowsepushButton->setObjectName(QStringLiteral("BrowsepushButton"));
        BrowsepushButton->setGeometry(QRect(200, 70, 121, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1050, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Client Class Name", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Platform (Base class)", nullptr));
        PlatformBaseClasslineEdit->setText(QApplication::translate("MainWindow", "AbstractPlatform", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Product (Base class)", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Platform Information", nullptr));
#ifndef QT_NO_TOOLTIP
        PlatformClasseslistView->setToolTip(QApplication::translate("MainWindow", "Add All platform classes", nullptr));
#endif // QT_NO_TOOLTIP
        AddPlatformClasspushButton->setText(QApplication::translate("MainWindow", "&Add Class", nullptr));
        DeletePlatformClasspushButton->setText(QApplication::translate("MainWindow", "&Delete Class", nullptr));
#ifndef QT_NO_TOOLTIP
        PlatformMethodslistWidget->setToolTip(QApplication::translate("MainWindow", "Add All patform functions", nullptr));
#endif // QT_NO_TOOLTIP
        DeletePlatformMethodspushButton->setText(QApplication::translate("MainWindow", "&Delete Method", nullptr));
        AddPlatformMethodspushButton->setText(QApplication::translate("MainWindow", "&Add  Method", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Add Platform Methods in below list ", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Add Platform classes in below list ", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Product Information", nullptr));
        DeleteProductClasspushButton->setText(QApplication::translate("MainWindow", "&Delete", nullptr));
        AddProductClasspushButton->setText(QApplication::translate("MainWindow", "&Add", nullptr));
#ifndef QT_NO_TOOLTIP
        ProductMethodslistWidget->setToolTip(QApplication::translate("MainWindow", "Add All product functions", nullptr));
#endif // QT_NO_TOOLTIP
        DeleteProductMethodspushButton->setText(QApplication::translate("MainWindow", "&Delete Method", nullptr));
        AddProductMethodspushButton->setText(QApplication::translate("MainWindow", "&Add  Method", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Add Product Methods in below list ", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Select Base Product  Class Below", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Add Product classes in below list ", nullptr));
        PopulateProductClassesPushButton->setText(QApplication::translate("MainWindow", "Populate", nullptr));
        AddProductListpushButton->setText(QApplication::translate("MainWindow", "Add", nullptr));
        ClearProductListpushButton->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Abstract Factory", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", nullptr));
        label->setText(QApplication::translate("MainWindow", "Design Pattern", nullptr));
        DesignPatternscomboBox->setItemText(0, QApplication::translate("MainWindow", "AbstractFactory", nullptr));

        groupBox_3->setTitle(QApplication::translate("MainWindow", "Settings", nullptr));
        GeneratepushButton->setText(QApplication::translate("MainWindow", "&Generate", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "O/p Directory", nullptr));
        BrowsepushButton->setText(QApplication::translate("MainWindow", "&Browse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
