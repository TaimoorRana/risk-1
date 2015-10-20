#include "game.h"
#include "./../utils/utils.h"

Game::Game(std::set<Player*> players) {
    // TODO: verify the settings file and use it
    global_settings_ = new GlobalSettings("name of the file");
    for(Player* player : players) {
        player->receive_global_settings(global_settings_);
    }
    initial_settings_ = initialize_game(players);
}

Game::~Game() {

}

InitialSettings* Game::initialize_game(std::set<Player*> players) {
    std::vector<Player*> ordered_players = shuffle(set_to_vector(players));
    std::map<Player*, set<Country*>> territories = deal(ordered_players, global_settings_->get_countries());
    std::map<Player*, Objective*> objectives = deal_one(ordered_players, global_settings_->get_objectives());
    return new InitialSettings(ordered_players, territories, objectives);
}

void Game::play() {
    game_state_ = new GameState();
    game_state_->current_armies_ = first_move();

}

std::map<Player*, Army*> Game::first_move() {
    map<Country*, Army*> current_state;
    for(Player* player : initial_settings_->all_players_) {
        DispatchStep dispatch_step;
        dispatch_step.id_ = 3;
        dispatch_step.number_of_troops_ = number_of_backups(initial_settings_->territories_[player].size());
        DispatchMove* dispatch_move = player->first_move(initial_settings_);
        for(Country* country : dispatch_move->distribution_) {
            current_state[country] = new Army(player, dispatch_move->distribution_[country]);
        }
    }
    return current_state;
}

int Game::number_of_backups(int number_of_territories) {
    return number_of_territories / 3;
}
