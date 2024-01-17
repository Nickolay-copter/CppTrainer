#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    int Q, stop_count;
    string command, stop, bus, stop_list, bus_list;
    map<string, vector<string>> list_bus_stop;
    map<string, vector<string>> list_bus_track;
    vector<string> command_history;
    cin >> Q;
    for ( int q = 0; q < Q; q++){
        cin >> command;
        if (command == "NEW_BUS"){
            cin >> bus;
            cin >> stop_count;
            for (int sc = 0; sc < stop_count; sc++){
                cin >> stop;
                list_bus_track[bus].push_back(stop);
                list_bus_stop[stop].push_back(bus);                
            }
        } else if (command == "BUSES_FOR_STOP"){
            cin >> stop;
            if (list_bus_stop.count(stop) == 0){
                bus_list = "No stop";
            } else {
                bus_list = "";
                for (const string& num : list_bus_stop[stop]){
                   bus_list += num + " "; 
                }
            }
            command_history.push_back(bus_list);
        } else if (command == "STOPS_FOR_BUS"){
            cin >> bus;
            if (list_bus_track.count(bus) == 1){
                for (const string& stop : list_bus_track[bus]){
                    bus_list = "Stop "+ stop + ": ";
                    if (list_bus_stop[stop].size() > 1){
                        for (const string num : list_bus_stop[stop]){
                            if (num != bus){
                                bus_list += num + " ";
                            }
                        }
                    } else {
                        bus_list += "no interchange";
                    }
                    command_history.push_back(bus_list);
                }
            } else {
                bus_list = "No bus";
                command_history.push_back(bus_list);
            }
        } else if (command == "ALL_BUSES"){
            if (list_bus_track.size() == 0){
                bus_list = "No buses";
                command_history.push_back(bus_list);
            } else {
                for (const auto& track : list_bus_track){
                    bus_list = "Bus "+ track.first + ": ";
                    for (const string& name : track.second){
                        bus_list += name + " ";
                    }
                    command_history.push_back(bus_list);
                }
            }
            
        } else {
            cout << "Нет такой команды";
        }
    }
    for (const string& res : command_history)
        cout << res << endl;
    return 0;
}
/*
Пожалуй, самое сложное в этой задаче — внимательно прочитать 
условие и аккуратно реализовать все его требования, выбрав при
этом правильные контейнеры.

Поскольку необходимо было получать как список остановок для
конкретного автобуса, так и список автобусов для 
конкретной остановки, логичнее всего было определить 
два словаря — buses_to_stops и stops_to_buses
со строковыми ключами и значениями типа vector<string>.

Ответы на большинство запросов вынесем в отдельные функции: 
это позволит повысить читаемость кода. Заметьте, что при этом
не всегда удаётся передавать словари по константным ссылкам: 
это происходит из-за того, что использование квадратных скобок 
(например, в коде stops_to_buses[stop]) теоретически может
изменить словарь. В этой ситуации стоило бы использовать 
метод at вместо квадратных скобок — мы рассмотрим его 
в следующем курсе.
*/