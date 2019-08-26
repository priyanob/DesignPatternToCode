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
    ui->ProductClasseslistView->setModel(productClassesModel);
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
                                         "IPlatform", &ok);
    if (ok && !text.isEmpty())
    {
        qDebug()<<"Adding to Listview"<<endl;
        platformClassesModel->appendRow(new QStandardItem(text));
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
    bool ok;
    QString text = QInputDialog::getText(this, tr("Enter Product Class"),
                                         tr("Product Class Name:"), QLineEdit::Normal,
                                         "IProduct", &ok);
    if (ok && !text.isEmpty())
    {
        productClassesModel->appendRow(new QStandardItem(text));
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

}

void MainWindow::on_AddProductListpushButton_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Enter Product Class"),
                                         tr("Product Class Name:"), QLineEdit::Normal,
                                         "IProduct", &ok);
    if (ok && !text.isEmpty())
    {
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText(text);
        ui->AddProducClasseslistWidget->addItem(newItem);
    }
}

void MainWindow::on_DeleteProductListpushButton_clicked()
{
    ui->AddProducClasseslistWidget->clear();
}
