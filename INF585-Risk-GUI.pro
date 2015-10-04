#-------------------------------------------------
#
# Project created by QtCreator 2015-01-14T14:46:33
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = INF585-Risk
TEMPLATE = app


SOURCES +=\
        mainwindow.cpp \
    gui/form.cpp \
    maingui.cpp \
    gui/mapbox.cpp \
    gui/countrygui.cpp \
    gui/infobox.cpp \
    gui/battledisplay.cpp \
    gui/cardbox.cpp \
    gui/joinbox.cpp \
    gui/createbox.cpp \
    gui/yesnodialogbox.cpp \
    gui/gui.cpp \
    pseudo_net/server_utils.cpp \
    pseudo_net/client_utils.cpp \
    gui/battleresults.cpp \
    gui/battleresultsintermediate.cpp \
    gui/dialogbox.cpp \
    gui/attackbox.cpp \
    gui/missionbox.cpp \
    gui/dices.cpp \
    gui/attackshow.cpp

HEADERS  += mainwindow.h \
    gui/form.h \
    gui/mapbox.h \
    gui/countrygui.h \
    gui/infobox.h \
    gui/battledisplay.h \
    gui/cardbox.h \
    gui/joinbox.h \
    shared_structures/global_settings.h \
    shared_structures/card.h \
    shared_structures/symbol.h \
    shared_structures/country.h \
    shared_structures/continent.h \
    shared_structures/color.h \
    shared_structures/objective.h \
    shared_structures/moves.h \
    shared_structures/initial_settings.h \
    shared_structures/game_state.h \
    shared_structures/army.h \
    shared_structures/steps.h \
    gui/gui.h \
    gui/createbox.h \
    gui/yesnodialogbox.h \
    interfaces/player.h \
    pseudo_net/server_utils.h \
    pseudo_net/client_utils.h \
    gui/battleresults.h \
    gui/battleresultsintermediate.h \
    gui/dialogbox.h \
    gui/missionbox.h \
    gui/dices.h \
    gui/attackbox.h \
    gui/attackshow.h


FORMS    += mainwindow.ui \
    gui/form.ui \
    gui/infobox.ui \
    gui/cardbox.ui \
    gui/joinbox.ui \
    gui/createbox.ui \
    gui/yesnodialogbox.ui \
    gui/battleresults.ui \
    gui/battleresultsintermediate.ui \
    gui/dialogbox.ui \
    gui/missionbox.ui \
    gui/dices.ui \
    gui/attackbox.ui \
    gui/attackshow.ui


RESOURCES += \
    maps1.qrc \
    maps2.qrc \
    cards.qrc

