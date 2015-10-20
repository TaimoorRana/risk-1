TEMPLATE = app
CONFIG += console
QMAKE_CXXFLAGS += -std=c++0x

HEADERS += shared_structures/army.h \
    utils/treeset.h \
    utils/utils.h \
    engine/game.h
HEADERS += shared_structures/base_player.h
HEADERS += shared_structures/card.h
HEADERS += shared_structures/continent.h
HEADERS += shared_structures/country.h
HEADERS += shared_structures/game_state.h
HEADERS += shared_structures/global_settings.h
HEADERS += shared_structures/initial_settings.h
HEADERS += shared_structures/objective.h
HEADERS += shared_structures/steps.h
HEADERS += shared_structures/moves.h
HEADERS += utils/textutils.h
HEADERS += interfaces/player.h



SOURCES += shared_structures/army.cpp \
    utils/treeset.cpp \
    utils/utils.cpp \
    engine/game.cpp
SOURCES += shared_structures/base_player.cpp
SOURCES += shared_structures/card.cpp
SOURCES += shared_structures/continent.cpp
SOURCES += shared_structures/country.cpp
SOURCES += shared_structures/game_state.cpp
SOURCES += shared_structures/global_settings.cpp
SOURCES += shared_structures/initial_settings.cpp
SOURCES += shared_structures/objective.cpp
SOURCES += utils/textutils.cpp
SOURCES += interfaces/player.cpp
SOURCES += main.cpp
