#include "createbox.h"
#include <iostream>

CreateBox::CreateBox():QDialog()
{
    // Creation et disposition des widgets de la fen�tre !!!!!!!!
    etatServeur = new QLabel;
    boutonQuitter = new QPushButton(tr("Cancel"));
    connect(boutonQuitter, SIGNAL(clicked()), this, SLOT(close()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(etatServeur);
    layout->addWidget(boutonQuitter);
    setLayout(layout);

    setWindowTitle(tr("Create party"));
    // Gestion du serveur
    server = new IServer(etatServeur);
    this->setModal(true);

}


