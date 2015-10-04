#-------------------------------------------------
#
# Project created by QtCreator 2015-01-14T14:46:33
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = INF585-Risk
TEMPLATE = app

copydata.commands = $(COPY_DIR) $$PWD/data $$OUT_PWD
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata

SOURCES += \
    utils/textutils.cpp \
    debug_main.cpp \
    shared_structures/army.cpp \
    shared_structures/card.cpp \
    shared_structures/continent.cpp \
    shared_structures/country.cpp \
    shared_structures/game_state.cpp \
    shared_structures/global_settings.cpp \
    interfaces/player.cpp \
    shared_structures/objective.cpp \
    shared_structures/base_player.cpp \
    utils/utils.cpp \
    shared_structures/initial_settings.cpp

HEADERS  += \
    interfaces/player.h \
    utils/textutils.h \
    shared_structures/army.h \
    shared_structures/card.h \
    shared_structures/continent.h \
    shared_structures/country.h \
    shared_structures/game_state.h \
    shared_structures/global_settings.h \
    shared_structures/initial_settings.h \
    shared_structures/moves.h \
    shared_structures/steps.h \
    headers.h \
    pseudo_engine/objectives.h \
    utils/utils.h \
    shared_structures/base_player.h \
    shared_structures/objective.h \
    interfaces/interface_engine_network.h

FORMS    +=

RESOURCES += \
    maps.qrc \
    cards.qrc \
    settings.qrc

DISTFILES += \
    data/standard_risk_configurations.dat

