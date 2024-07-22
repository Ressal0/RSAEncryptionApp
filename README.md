# RSA Encryption & Decryption Application

This is a simple RSA encryption and decryption application with a graphical user interface (GUI) built using C++ and Qt.

## Features

- Generate RSA public and private keys.
- Encrypt plaintext messages using the RSA public key.
- Decrypt ciphertext messages using the RSA private key.

## Requirements

- Qt 5 or higher
- Crypto++ library

## Installation

### Qt Installation

1. Download and install Qt from the [Qt official website](https://www.qt.io/download).
2. Ensure that you have Qt Creator installed.

### Crypto++ Installation

1. Download Crypto++ from the [Crypto++ official website](https://www.cryptopp.com/).
2. Extract the Crypto++ files into the `cryptopp` directory inside your project directory.

## Building the Project

1. Open the `RSAEncryptionApp.pro` file in Qt Creator.
2. Click on the "Configure Project" button.
3. Build and run the project using the Qt Creator build tools.

## File Structure

- `main.cpp`: The main entry point for the application.
- `mainwindow.h`: The header file for the main window.
- `mainwindow.cpp`: The source file for the main window.
- `mainwindow.ui`: The user interface file.
- `project.pro`: The Qt project file.
- `cryptopp`: The directory containing the Crypto++ library files.

## Usage

1. **Generate Keys**: Click the "Generate Keys" button to generate RSA public and private keys. The keys will be saved as `public.key` and `private.key` files in the application directory.
2. **Encrypt Message**: Enter the plaintext message in the provided input field and click the "Encrypt" button. The encrypted message will be displayed in the text area below.
3. **Decrypt Message**: Enter the ciphertext message in the provided input field and click the "Decrypt" button. The decrypted message will be displayed in the text area below.

## License

This project is licensed under the MIT License. See the LICENSE file for more information.

## Acknowledgements

- [Qt](https://www.qt.io/) - Cross-platform software development for embedded & desktop.
- [Crypto++](https://www.cryptopp.com/) - A free C++ class library of cryptographic schemes.
