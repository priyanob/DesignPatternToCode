#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QInputDialog>
#include <QStringListModel>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QListWidgetItem>
#include <QMap>
#include <QVector>
#include <QMessageBox>
#include <CodeGenerator.h>
#include <QFileDialog>

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

    void on_ClearProductListpushButton_clicked();

    void on_PopulateProductClassesPushButton_clicked();

    void on_ProductBaseClasseslistWidget_2_currentIndexChanged(const QString &arg1);

    void on_GeneratepushButton_clicked();

    void on_BrowsepushButton_clicked();

    void on_DeletePlatformMethodspushButton_clicked();

    void on_AddProductMethodspushButton_clicked();

    void on_DeleteProductMethodspushButton_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* platformClassesModel;
    QStandardItemModel* productClassesModel;
    QMap<QString, QVector<QString>> ProductClassesMap;
};

#endif // MAINWINDOW_H
