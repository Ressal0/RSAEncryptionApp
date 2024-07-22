#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cryptopp/rsa.h>
#include <cryptopp/osrng.h>
#include <cryptopp/base64.h>
#include <cryptopp/files.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateKeys()
{
    using namespace CryptoPP;

    AutoSeededRandomPool rng;

    InvertibleRSAFunction privkey;
    privkey.Initialize(rng, 2048);

    RSA::PrivateKey privateKey(privkey);
    RSA::PublicKey publicKey(privkey);

    ByteQueue queue;
    publicKey.Save(queue);
    FileSink file("public.key");
    queue.CopyTo(file);
    file.MessageEnd();

    queue.Clear();
    privateKey.Save(queue);
    FileSink file2("private.key");
    queue.CopyTo(file2);
    file2.MessageEnd();
}

std::string MainWindow::encrypt(const std::string &message)
{
    using namespace CryptoPP;

    RSA::PublicKey publicKey;
    ByteQueue queue;
    FileSource file("public.key", true);
    file.TransferTo(queue);
    queue.MessageEnd();
    publicKey.Load(queue);

    AutoSeededRandomPool rng;
    std::string cipher;
    RSAES_OAEP_SHA_Encryptor e(publicKey);

    StringSource(message, true,
        new PK_EncryptorFilter(rng, e,
            new StringSink(cipher)
        )
    );

    return cipher;
}

std::string MainWindow::decrypt(const std::string &cipher)
{
    using namespace CryptoPP;

    RSA::PrivateKey privateKey;
    ByteQueue queue;
    FileSource file("private.key", true);
    file.TransferTo(queue);
    queue.MessageEnd();
    privateKey.Load(queue);

    AutoSeededRandomPool rng;
    std::string recovered;
    RSAES_OAEP_SHA_Decryptor d(privateKey);

    StringSource(cipher, true,
        new PK_DecryptorFilter(rng, d,
            new StringSink(recovered)
        )
    );

    return recovered;
}

void MainWindow::on_generateKeysButton_clicked()
{
    generateKeys();
    QMessageBox::information(this, "Keys", "Keys generated successfully.");
}

void MainWindow::on_encryptButton_clicked()
{
    QString plaintext = ui->plaintextEdit->text();
    std::string cipher = encrypt(plaintext.toStdString());
    ui->ciphertextEdit->setPlainText(QString::fromStdString(cipher));
}

void MainWindow::on_decryptButton_clicked()
{
    QString ciphertext = ui->ciphertextEdit->toPlainText();
    std::string recovered = decrypt(ciphertext.toStdString());
    ui->recoveredTextEdit->setPlainText(QString::fromStdString(recovered));
}