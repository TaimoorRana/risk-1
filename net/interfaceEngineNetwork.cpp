#include "interfaces/interface_engine_network.h"





InterfaceEngineNetwork::receive_global_settings(Global_Settings gs);
InterfaceEngineNetwork::first_move(Initial_Settings is);
InterfaceEngineNetwork::next_move(Game_State gs){
    //sendMessage(gs.toJSON());
    //return receiveMessage().toMove();
}

InterfaceEngineNetwork::InterfaceClient(/*Ici Connexion*/){

}

InterfaceEngineNetwork::sendMessage(string s){
    //send message
}

InterfaceEngineNetwork::receiveMessage(){

}
