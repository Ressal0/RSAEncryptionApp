#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_generateKeysButton_clicked();
    void on_encryptButton_clicked();
    void on_decryptButton_clicked();

private:
    Ui::MainWindow *ui;
    void generateKeys();
    std::string encrypt(const std::string &message);
    std::string decrypt(const std::string &cipher);
};

#endif // MAINWINDOW_H