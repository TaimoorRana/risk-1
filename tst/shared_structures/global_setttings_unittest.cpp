#include "shared_structures/global_settings.h"

void test_global_settings_initialization(){
    std::set<Objective*> objectives;
    char file_name [] = "standard_risk_configuration.dat";
    GlobalSettings *global_settings = new GlobalSettings(file_name, objectives);
}
