#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QInputDialog>
#include <QStringListModel>
#include <QStandardItem>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_AddPlatformClasspushButton_clicked();

    void on_DeletePlatformClasspushButton_clicked();

    void on_AddProductClasspushButton_clicked();

    void on_DeleteProductClasspushButton_clicked();

    void on_AddPlatformMethodspushButton_clicked();

    void on_AddProductListpushButton_clicked();

    void on_DeleteProductListpushButton_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* platformClassesModel;
    QStandardItemModel* productClassesModel;
};

#endif // MAINWINDOW_H
