# Add more folders to ship with the application, here
folder_01.source = qml/RiskQtApplication
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

symbian:TARGET.UID3 = 0xEA823B81

# Smart Installer package's UID
# This UID is from the protected range and therefore the package will
# fail to install if self-signed. By default qmake uses the unprotected
# range value if unprotected UID is defined for the application and
# 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# Speed up launching on MeeGo/Harmattan when using applauncherd daemon
# CONFIG += qdeclarative-boostable

# Add dependency to Symbian components
# CONFIG += qt-components

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    shared_structures/army.h \
    shared_structures/base_player.h \
    shared_structures/card.h \
    shared_structures/continent.h \
    shared_structures/country.h \
    shared_structures/game_state.h \
    shared_structures/global_settings.h \
    shared_structures/initial_settings.h \
    shared_structures/moves.h \
    shared_structures/objective.h \
    shared_structures/steps.h \
    shared_structures/structure.h

HEADERS += \
    interfaces/player.h

HEADERS += \
    utils/textutils.h


SOURCES += \
    shared_structures/army.cpp \
    shared_structures/base_player.cpp \
    shared_structures/card.cpp \
    shared_structures/continent.cpp \
    shared_structures/country.cpp \
    shared_structures/game_state.cpp \
    shared_structures/global_settings.cpp \
    shared_structures/initial_settings.cpp \
    shared_structures/objective.cpp


SOURCES += \
    interfaces/player.cpp

SOURCES += \
    utils/textutils.cpp
