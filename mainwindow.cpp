#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pixmap(":/new/images/Abstract_Factory-2x.png");

    int width  = ui->graphicsView->geometry().width();
    int height = ui->graphicsView->geometry().height();

    QGraphicsScene* scene = new QGraphicsScene(QRectF(0, 0, width, height), 0);
    QGraphicsPixmapItem *item = scene->addPixmap(pixmap.scaled(QSize(
            (int)scene->width(), (int)scene->height()),
            Qt::KeepAspectRatio, Qt::SmoothTransformation));

    ui->graphicsView->fitInView(QRectF(0, 0, width, height),
            Qt::KeepAspectRatio);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

    platformClassesModel = new QStandardItemModel(this);
    productClassesModel  = new QStandardItemModel(this);

    ui->PlatformClasseslistView->setModel(platformClassesModel);    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddPlatformClasspushButton_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Enter Platform Class"),
                                         tr("Platform Class Name:"), QLineEdit::Normal,
                                         "Platform", &ok);
    if (ok && !text.isEmpty())
    {
        QList<QStandardItem*> items;
        items = platformClassesModel->findItems(text,Qt::MatchCaseSensitive);
        if( items.size() == 0 )
        {
            platformClassesModel->appendRow(new QStandardItem(text));
        }
        else
        {
            QMessageBox::warning(this, tr("DesignPatternToCode"),
                                 tr("Platform class already present.\n"),
                                 QMessageBox::Ok);
        }
    }
}

void MainWindow::on_DeletePlatformClasspushButton_clicked()
{
    QModelIndexList selectedIndexes(ui->PlatformClasseslistView->selectionModel()->selectedIndexes());

    for (QModelIndexList::const_iterator it = selectedIndexes.constEnd() - 1;
            it >= selectedIndexes.constBegin(); --it) {
        platformClassesModel->removeRow(it->row());
    }
}

void MainWindow::on_AddProductClasspushButton_clicked()
{
    if( ui->ProductBaseClasseslistWidget_2->count() <= 0 )
    {
        int ret = QMessageBox::warning(this, tr("DesignPatternToCode"),
                                       tr("The Product Base Class list is empty.\n"
                                          "Click Populate button. If it is still empty, Add product bases classes and try"),
                                       QMessageBox::Ok);

        ui->AddProductClasspushButton->setFocus();
    }
    else
    {
        bool ok;
        QString text = QInputDialog::getText(this, tr("Enter Product Class"),
                                             tr("Product Class Name:"), QLineEdit::Normal,
                                             "Product", &ok);
        if (ok && !text.isEmpty())
        {            
            ui->ProductClasseslistView->addItem(text);
            QString baseclass = ui->ProductBaseClasseslistWidget_2->currentText();
            ProductClassesMap[baseclass].push_back(text);
        }
    }
}

void MainWindow::on_DeleteProductClasspushButton_clicked()
{
    QModelIndexList selectedIndexes(ui->ProductClasseslistView->selectionModel()->selectedIndexes());

    for (QModelIndexList::const_iterator it = selectedIndexes.constEnd() - 1;
            it >= selectedIndexes.constBegin(); --it) {
        productClassesModel->removeRow(it->row());
    }
}

void MainWindow::on_AddPlatformMethodspushButton_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Enter Platform Methods"),
                                         tr("Platform Method:"), QLineEdit::Normal,
                                         "", &ok);
    if (ok && !text.isEmpty())
    {
        QList<QListWidgetItem *> items;
        items = ui->PlatformMethodslistWidget->findItems(text,Qt::MatchCaseSensitive);
        if( items.size() == 0 )
        {
            QListWidgetItem *newItem = new QListWidgetItem;
            newItem->setText(text);
            ui->PlatformMethodslistWidget->addItem(newItem);
        }
        else
        {
            QMessageBox::warning(this, tr("DesignPatternToCode"),
                                 tr("Platform method is already present.\n"),
                                 QMessageBox::Ok);
        }
    }
}


void MainWindow::on_AddProductListpushButton_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Enter Product Base Class"),
                                         tr("Product Base Class Name:"), QLineEdit::Normal,
                                         "AbstractProductOne", &ok);
    if (ok && !text.isEmpty())
    {
        QList<QListWidgetItem *> items;
        items = ui->ProductBaseClasseslistWidget->findItems(text,Qt::MatchCaseSensitive);
        if( items.size() == 0 )
        {
            QListWidgetItem *newItem = new QListWidgetItem;
            newItem->setText(text);
            ui->ProductBaseClasseslistWidget->addItem(newItem);
        }
        else
        {
            QMessageBox::warning(this, tr("DesignPatternToCode"),
                                 tr("Product class already present.\n"),
                                 QMessageBox::Ok);
        }
    }
}


void MainWindow::on_ClearProductListpushButton_clicked()
{
    ui->ProductBaseClasseslistWidget->clear();
    ui->ProductBaseClasseslistWidget_2->clear();
}


void MainWindow::on_PopulateProductClassesPushButton_clicked()
{
    ProductClassesMap.clear();
    ui->ProductBaseClasseslistWidget_2->clear();
    for(int i=0; i<ui->ProductBaseClasseslistWidget->count(); i++)
    {
        ui->ProductBaseClasseslistWidget_2->addItem(ui->ProductBaseClasseslistWidget->item(i)->text());
    }
}

void MainWindow::on_ProductBaseClasseslistWidget_2_currentIndexChanged(const QString &arg1)
{
    qDebug()<<"Item="<<arg1<<endl;

    ui->ProductClasseslistView->clear();
    QVector<QString> vec;

    vec = ProductClassesMap[arg1];
    for(int i=0; i<vec.size(); i++)
    {
        ui->ProductClasseslistView->addItem(vec[i]);
    }
}

void MainWindow::on_GeneratepushButton_clicked()
{
    CodeGenerator G;

    G.setPath(ui->SrcDirectorylineEdit->text().toStdString());

    shared_ptr<CodeGenerator::Class> MainClass;
    MainClass =  G.addClass(ui->ProductBaseClasseslistWidget->item(0)->text().toStdString());

    auto Base1 = G.addClass(ui->PlatformBaseClasslineEdit->text().toStdString());

    MainClass->addBaseClass(Base1);
    shared_ptr<CodeGenerator::Function>  f1 = MainClass->addPublicFunction();
    f1->addArgument();
    G.setMainClass(MainClass);
    G.generate();
}

void MainWindow::on_BrowsepushButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    ui->SrcDirectorylineEdit->setText(dir);
}

void MainWindow::on_DeletePlatformMethodspushButton_clicked()
{
    qDeleteAll(ui->PlatformMethodslistWidget->selectedItems());
}

void MainWindow::on_AddProductMethodspushButton_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Enter Product Methods"),
                                         tr("Product Method:"), QLineEdit::Normal,
                                         "", &ok);
    if (ok && !text.isEmpty())
    {
        QList<QListWidgetItem *> items;
        items = ui->ProductMethodslistWidget->findItems(text,Qt::MatchCaseSensitive);
        if( items.size() == 0 )
        {
            QListWidgetItem *newItem = new QListWidgetItem;
            newItem->setText(text);
            ui->ProductMethodslistWidget->addItem(newItem);
        }
        else
        {
            QMessageBox::warning(this, tr("DesignPatternToCode"),
                                 tr("Product method is already present.\n"),
                                 QMessageBox::Ok);
        }
    }
}

void MainWindow::on_DeleteProductMethodspushButton_clicked()
{
    qDeleteAll(ui->ProductMethodslistWidget->selectedItems());
}
