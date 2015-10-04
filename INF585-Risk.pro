#-------------------------------------------------
#
# Project created by QtCreator 2015-01-14T14:46:33
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = INF585-Risk
TEMPLATE = app


SOURCES += \
    ai1/attack.cpp \
    ai1/evaluate.cpp \
    ai1/nbtriangles.cpp \
    ai1/player_ai1.cpp \
    ai1/ai1_engine.cpp \
    ai1/random_reinforcement.cpp \
    ai2/connectedcomponent.cpp \
    ai2/enemy.cpp \
    ai2/evaluation.cpp \
    ai2/probabilities.cpp \
    main.cpp \
    mainai1.cpp \
    mainai2.cpp \
    mainai3.cpp \
    mainengine.cpp \
    maingui.cpp \
    mainnetwork.cpp \
    mainwindow.cpp \
    ai3/agent.cpp \
    ai3/bid.cpp \
    ai3/card_agent.cpp \
    ai3/central_unit.cpp \
    ai3/path.cpp \
    ai3/proba.cpp \
    ai3/pseudo-engine/continentai.cpp \
    ai3/pseudo-engine/graph.cpp \
    ai3/pseudo-engine/state.cpp \
    engine/game.cpp \
    engine/o1.cpp \
    engine/objective.cpp \
    gui/battledisplay.cpp \
    gui/cardbox.cpp \
    gui/countrygui.cpp \
    gui/form.cpp \
    gui/infobox.cpp \
    gui/mapbox.cpp \
    net/FenClient.cpp \
    net/FenServeur.cpp \
    net/mainclient.cpp \
    net/mainserveur.cpp \
    pseudo_engine/game.cpp \
    random_player/random_player.cpp \
    human_player/human_player.cpp \
    utils.cpp \
    network/army.cpp \
    network/card.cpp \
    network/continent.cpp \
    network/country.cpp \
    network/game_state.cpp \
    network/global_settings.cpp \
    network/initial_settings.cpp \
    network/moves.cpp \
    network/objective.cpp \
    network/steps.cpp \
    network/symbol.cpp \
    gui/gui.cpp \
    net/continent.cpp \
    net/interfaceEngineNetwork.cpp \
    loadingwindow.cpp \
    attack_move.cpp \
    utils/treeset.cpp \
    utils/textutils.cpp \
    server_app.cpp \
    pseudo_net/fake_client.cpp \
    pseudo_net/server_utils.cpp \
    pseudo_net/client_utils.cpp \
    client_app.cpp \
    pseudo_engine/objectives.cpp \
    gui/createbox.cpp \
    gui/dices.cpp \
    gui/joinbox.cpp \
    debug_main.cpp \
    interfaces/client.cpp \
    shared_structures/army.cpp \
    shared_structures/card.cpp \
    shared_structures/continent.cpp \
    shared_structures/country.cpp \
    shared_structures/game_state.cpp \
    shared_structures/global_settings.cpp \
    shared_structures/objective.cpp \
    shared_structures/base_player.cpp \
    interfaces/player.cpp \
    net/army_serialize.cpp \
    net/attack_move_serialize.cpp \
    net/card_serialize.cpp \
    net/change_cards_move_serialize.cpp \
    net/continent_serialize.cpp \
    net/country_serialize.cpp \
    net/dispatch_step_serialize.cpp \
    net/displacement_move_serialize.cpp \
    net/game_state_serialize.cpp \
    net/global_settings_serialize.cpp \
    net/initial_settings_serialize.cpp \
    net/move_serialize.cpp \
    net/objective_serialize.cpp \
    net/step_serialize.cpp \
    net/client.cpp \
    net/server.cpp \
    ai2/initialisation.cpp \
    ai2/player_ai2.cpp \
    ai2/fortifying.cpp \
    ai2/connected_component.cpp \
    ai2/country_parameters.cpp \
    engine/abstract_objectives.cpp \
    engine/army.cpp \
    engine/Attack.cpp \
    engine/attack_move.cpp \
    engine/continent.cpp \
    engine/country.cpp \
    engine/deck.cpp \
    engine/globalSettings.cpp \
    engine/map.cpp \
    gui/attackbox.cpp \
    gui/attackshow.cpp \
    gui/battleresults.cpp \
    gui/battleresultsintermediate.cpp \
    gui/dialogbox.cpp \
    gui/missionbox.cpp \
    gui/yesnodialogbox.cpp \
    interfaces/mainclient.cpp \
    shared_structures/initial_settings.cpp \
    utils/utils.cpp \
    attackshow.cpp \
    ai2/test/probabilities.cpp \
    ai2/test/group.cpp

HEADERS  += \
    ai1/attack.h \
    ai1/dispatch_move_ai.h \
    ai1/evaluate.h \
    ai1/random_reinforcement.h \
    ai1/player_ai1.h \
    ai1/prob_state.h \
    ai1/ai1_engine.h \
    ai2/connectedcomponent.h \
    ai2/enemy.h \
    ai2/evaluation.h \
    ai2/probabilities.h \
    mainwindow.h \
    ai3/agent.h \
    ai3/bid.h \
    ai3/card_agent.h \
    ai3/central_unit.h \
    ai3/path.h \
    ai3/proba.h \
    ai3/pseudo-engine/continentai.h \
    ai3/pseudo-engine/graph.h \
    ai3/pseudo-engine/state.h \
    engine/game.h \
    engine/o1.h \
    engine/objective.h \
    interfaces/player.h \
    gui/battledisplay.h \
    gui/cardbox.h \
    gui/countrygui.h \
    gui/form.h \
    gui/infobox.h \
    gui/mapbox.h \
    net/FenClient.h \
    net/FenServeur.h \
    pseudo_engine/game.h \
    random_player/random_player.h \
    shared_structures/army.h \
    shared_structures/card.h \
    shared_structures/continent.h \
    shared_structures/country.h \
    shared_structures/game_state.h \
    shared_structures/global_settings.h \
    shared_structures/initial_settings.h \
    shared_structures/moves.h \
    shared_structures/objective.h \
    shared_structures/steps.h \
    shared_structures/symbol.h \
    shared_structures/base_player.h \
    human_player/human_player.h \
    utils.h \
    gui/gui.h \
    interfaces/interface_engine_network.h \
    loadingwindow.h \
    attack_move.h \
    utils/treeset.h \
    utils/textutils.h \
    interfaces/client.h \
    pseudo_net/fake_client.h \
    pseudo_net/server_utils.h \
    pseudo_net/client_utils.h \
    headers.h \
    pseudo_engine/objectives.h \
    shared_structures/color.h \
    gui/createbox.h \
    gui/dices.h \
    gui/joinbox.h \
    utils/utils.h \
    net/server.h \
    net/client.h \
    ai2/initialisation.h \
    ai2/player_ai2.h \
    ai2/fortifying.h \
    ai2/connected_component.h \
    ai2/country_parameters.h \
    engine/abstract_objectives.h \
    engine/attack.h \
    engine/attack_move.h \
    engine/deck.h \
    engine/game.hpp \
    engine/globalSettings.h \
    engine/map.hpp \
    engine/player.hpp \
    gui/attackbox.h \
    gui/attackshow.h \
    gui/battleresults.h \
    gui/battleresultsintermediate.h \
    gui/dialogbox.h \
    gui/missionbox.h \
    gui/yesnodialogbox.h \
    attackshow.h

FORMS    += mainwindow.ui \
    gui/form.ui \
    gui/infobox.ui \
    net/FenClient.ui \
    net/Client.ui\
    gui/cardbox.ui

RESOURCES += \
    maps.qrc \
    cards.qrc \
    settings.qrc

DISTFILES += \
    engine/Country.txt \
    engine/neigh.txt \
    maps/countrylegend.png \
    data/standard_risk_configurations.dat

