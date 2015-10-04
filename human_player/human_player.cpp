#include "human_player.h"

Human_Player::Human_Player()
{
}

Human_Player::receive_global_settings(Global_Settings gs)
{
    graph = gs.graph;
    continents = gs.continents;
    objectives = gs.objectives;
    reward_values = gs.reward_values;
}

Human_Player::first_move(Initial_Settings is)
{
    map<Player*, set<Country*>> territories;

    players = is.players;
    my_objective = is.objectives[this];

    //GUI - draw_init_cards (is.territories[this])
    //GUI - draw_mission (my_objective)

    Dispatch_Move answer = null;//GUI - dispatch_troops (is.step.number_of_troops) -> Dispatch_Move
    answer.id = step.id;
    return answer;
}

Human_Player::next_move(Game_State gs)
{
    Player* current_player;
    Step* current_step;
    map <Country*, Army*> current_armies;
    map <Player*, set<Card*>> hands;
    stack <Card*> deck;
    int reward_index;

    switch(gs.current_step->id)
    {
        case 1:
            Change_Cards_Move answer = null;//GUI - want_change_cards() -> Change_Cards_Move
            return answer;
        case 2:
            Change_Cards_Move answer = null;//GUI - change_cards() -> Change_Cards_Move
            return answer;
        case 3:
            Dispatch_Move answer = null;//GUI - dispatch_backup() -> Change_Cards_Move
            return answer;
        case 4:
            Attack_Move answer = null;//GUI - want_attack() -> Change_Cards_Move
            return answer;
        case 5:
            Displacement_Move answer = null;//GUI - move() -> Change_Cards_Move
            return answer;
        case 6:
            //GUI - end()
            return null;
    }
}
