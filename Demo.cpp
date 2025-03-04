#include "Player.hpp"
#include "Governor.hpp"
#include "Spy.hpp"
#include "Baron.hpp"
#include "General.hpp"
#include "Judge.hpp"
#include "Merchant.hpp"
#include "Game.hpp"

#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main() {
    Game game_1{};

    Governor governor(game_1, "Moshe");
    Spy spy(game_1, "Yossi");
    Baron baron(game_1, "Meirav");
    General general(game_1, "Reut");
    Judge judge(game_1, "Gilad");
    Merchant merchant(game_1, "Daniel");

    vector<string> players = game_1.players();
    for(string name : players){
        cout << name << endl;
    }

    cout << game_1.turn() << endl;

    governor.gather();
    spy.gather();
    baron.gather();
    general.gather();
    judge.gather();
    merchant.gather();

    try{
        spy.gather();
    } catch (const std::exception &e){
        std::cerr << e.what() << '\n';
    }

    governor.tax();  
    spy.spy_on(baron); 
    baron.invest();  
    general.prevent_coup(judge);  
    judge.block_bribe(merchant);  
    merchant.gather(); 

  
    try{
        judge.block_bribe(governor);  
    } catch (const std::exception &e){
        std::cerr << e.what() << '\n';
    }

    cout << "מטבעות של הברון: " << baron.coins() << endl;
    cout << "מטבעות של הסוחר: " << merchant.coins() << endl;

    try{
        general.coup(governor);
    } catch (const std::exception &e){
        std::cerr << e.what() << '\n';
    }

    return 0;
}
