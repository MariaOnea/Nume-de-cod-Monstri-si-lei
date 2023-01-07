#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

const string file1 = "team.csv"; // fisierul cu echipa de productie
const string file2 = "cast_with_extras.csv"; // fisierul cu actori si figuranti
const string file3 = "fullteam.csv"; //fisierul cu toata lumea

// clasa Person
class Person {
public:
    string name;
    string role;
    int monster_class;
    string diet;


};


// clasa MonsterAssigner
class MonsterAssigner {
private:
    mt19937 rng;
    uniform_int_distribution<int> dist;
    vector<int> remaining;

public:
    // constructorul clasei MonsterAssigner
    MonsterAssigner(vector<int> monster_counts) {
        random_device rd;
        rng = mt19937(rd());
        dist = uniform_int_distribution<int>(0, 4); //(0-vampir, 1-varcolac, 2-sirena, 3-clarvazator,4-om)
        remaining = monster_counts;
    }

    // metoda assign_monster
    int assign_monster() {
        int monster = dist(rng);
        while (remaining[monster] == 0) {
            monster = dist(rng);
        }
        remaining[monster]--;
        return monster;
    }
};

// clasa DietAssigner
class DietAssigner {
private:
mt19937 rng;
uniform_int_distribution<int> dist;

public:
// constructorul clasei DietAssigner
DietAssigner() {
random_device rd;
rng = mt19937(rd());
dist = uniform_int_distribution<int>(0, 2);
}
// metoda assign_diet
string assign_diet() {
    int diet_index = dist(rng);
    string diets[3] = {"orice/anything", "vegetarian", "flexitarian"};
    return diets[diet_index];
}

};

class MenuGenerator {

public:
    // constructorul clasei MenuGenerator
    MenuGenerator()
    {
            generate_menu();
    }

    // metoda generate_menu
    void generate_menu() {

        ofstream meniu("meniu.csv");

        meniu<<"Pentru cei care mananca orice/For those who can eat anything: "<<','<<"Pentru vegetarieni/For vegetarians: "<<','<<"Pentru flexitarieni/For flexitarians: "<<"\n" ;
        string omni[9] = {"supa crema de legume/vegetable cream soup"," piept de pui la gratar cu piure de cartofi/grilled chicken breast with mashed potatoes","papanasi/cheese dumplings","ciorba de pui a la grec/chicken soup a la greek","chicken curry cu orez/chicken curry with rice", "eclere/eclairs", "ciorba radauteana/sour chicken soup", "lasagna", "cheesecake cu afine/blueberry cheesecake"};
        string veg[9]={"supa crema de dovleac/pumpkin cream soup", "tofu stir fry", "papanasi/cheese dumplings ", "supa de rosii/tomato soup", "ratatouille", "placinta cu mere/apple pie", "supa crema de ciuperci/mushroom cream soup", "pizza vegetariana/vegetarian pizza", "prajitura cu morcov/carrot cake"};
        string flex[9]={"supa crema de dovleac/pumpkin cream soup", "tofu stir fry", "papanasi/cheese dumplings", "supa de rosii/tomato soup", "lasagna vegana/vegan lasagna", "placinta cu dovleac/pumpkin pie", "supa crema de ciuperci/mushroom cream soup", "dorada in crusta de sare/sea bream in salt crust", "negresa/brownies"};


         meniu<<"Ziua 1/Day 1"<<','<<"Ziua 1/Day 1"<<','<<"Ziua 1/Day 1"<<"\n";

        for(int i = 0; i < 9; i++)
           {

                if(i == 3)
               {
                   meniu<<"Ziua 2/Day 2"<<','<<"Ziua 2/Day 2"<<','<<"Ziua 2/Day 2"<<"\n";
               }
                if(i == 6)
                {
                   meniu<<"Ziua 3/Day 3"<<','<<"Ziua 3/Day 3"<<','<<"Ziua 3/Day 3"<<"\n";
                }

                meniu<<omni[i]<<','<<veg[i]<<','<<flex[i]<<"\n";

           }
       meniu.close();

    }
};

class Calcule {
public:
    string name;
    string role;
    int monster_class;
    string diet;
    Calcule()
    {
        calcul_total();
    }
    int calcul_total(){
    ifstream machiaj(file2);

    if (!machiaj)
            throw "File does not exist!";
    ofstream calcule;
    calcule.open("calcule.csv");

    if (!calcule)
            throw "File does not exist!";
    int v = 0, vr = 0, s = 0, c = 0, o = 0;

    vector<string> ls;
    string l;
    while (getline(machiaj, l)) {
        ls.push_back(l);
    }

    // creare  vector de persoane
    vector<Person> pers;
    // parcurge liniile și citiți fiecare linie într-un obiect de tip Person
    for (string l : ls) {
        stringstream ss(l);
        Person h;
        getline(ss, h.name, ',');
        getline(ss, h.role, ',');
        string monster_class_str;
        getline(ss, monster_class_str, ',');
        h.monster_class = atoi(monster_class_str.c_str());
        pers.push_back(h);


        if(h.monster_class == 0) v++;
            else if(h.monster_class == 1) vr++;
                else if(h.monster_class == 2) s++;
                    else if(h.monster_class == 3) c++;
                        else if(h.monster_class == 4) o++;




    }

    //calcul machiaj

    int cost_vampir = 0;
    int cost_varcolac = 0;
    int cost_sirene = 0;
    int cost_clarv = 0;
    int cost_om = 0;

    int cost_machiaj_total = 0;

    cost_vampir = v * 230;
    cost_varcolac = vr * 555;
    cost_sirene = s * 345;
    cost_clarv = c * 157;
    cost_om = o * 55;

    cost_machiaj_total = cost_vampir + cost_clarv + cost_om + cost_sirene + cost_varcolac;




    ifstream everyone(file3);

    if (!everyone)
            throw "File does not exist!";

   //cate persoane sunt in total
    int numP = 0;
    string line;
    // citire fiecare linie din fișier
    while (getline(everyone, line))
        {
        //  stream pentru a citi câmpurile din linie
        istringstream lineStream(line);

        // citire numele și funcția persoanei
        string name, role;
        getline(lineStream, name, ',');
        getline(lineStream, role, ',');


        // adauga 1 la numărul total de persoane
        numP++;
    }



    // capacitatea unui autocar
    int bus_capacity = 50;
    // costul închirierii unui autocar
    int bus_rental_cost = 5680;

    int drumuri = 2;

    // numărul total de autocare necesare
    int total_buses = ceil((double)numP / bus_capacity);
    // costul total pentru închirierea autocarelor
    int total_cost = total_buses * bus_rental_cost * drumuri;

    calcule << "Numarul total de autocare necesare pentru un singur drum/The total number of buses needed for a single road: " << total_buses <<"\n";

    everyone.close();


    //calcul meniuri
    int num_omni = 0, num_veg = 0, num_flex = 0;

    ifstream all("lista_diete.csv");

    if (!all)
            throw "File does not exist!";

    string lista;

    // citire fiecare linie din fișier

    while (getline(all, lista))
        {

        //  stream pentru a citi câmpurile din linie
        istringstream lineStream(lista);

        string name,diet;
        // citire numele și dieta persoanei


        getline(lineStream, name, ',');
        getline(lineStream, diet, ',');



        if(diet == "vegetarian")
        {
            num_veg++;
        }

        else if(diet == "orice/anything") num_omni++;
        else num_flex++;
    }
        int cost, omni_cost, veg_cost, flex_cost;


        cost = 40;
        omni_cost = cost * num_omni;


        cost = 33;
        veg_cost = cost * num_veg;


        cost = 46;
        flex_cost = cost * num_flex;

        int food_cost = omni_cost + veg_cost + flex_cost;


        //calcul preturi apa,cafea si suc
        float water_amount = numP * 1;
        float coffee_amount = numP * 0.5;
        float juice_amount = numP * 0.8;

        float water_cost = water_amount * 3;
        float coffee_cost = coffee_amount * 15;
        float juice_cost = juice_amount * 3.2;
        float drink_total = water_cost + coffee_cost + juice_cost;




        ifstream fisier;

        fisier.open("full_team.csv");

        if (!fisier)
            throw "File does not exist!";


        int nr_figuranti = 0;
        int nr_cast_initial = 0;


        while (getline(fisier, name, ','))
        {
            getline(fisier, role, '\n');


            if (role == "figurant/extra")
                nr_figuranti++;
            else nr_cast_initial++;
        }

        int nr_camere_de_2;
        int nr_camere_de_3;

        nr_camere_de_2 = nr_cast_initial/2;
        if (nr_cast_initial%2 != 0)
            nr_camere_de_2++;

        nr_camere_de_3 = nr_figuranti/3;
        if (nr_figuranti%3 != 0)
            nr_camere_de_3++;

        int pret_camera_de_2 = 350;
        int pret_camera_de_3 = 420;

        int pret_final_camera_de_2 = pret_camera_de_2 * nr_camere_de_2;
        int pret_final_camera_de_3 = pret_camera_de_3 * nr_camere_de_3;

        calcule<<"Numarul de camere pentru doua persoane este/The number of rooms for two people is: "<<nr_camere_de_2<<"\n";
        calcule<<"Numarul de camere pentru 3 persoane este/The number of rooms for three people is: "<<nr_camere_de_3<<"\n";


        //calcul inchiriere castel
        int cost_zi = 10000;
        int zile_pt_reducere = 10;

        int cost_zile_pt_reducere = cost_zi * zile_pt_reducere;
        float discount = cost_zile_pt_reducere * 0.02;

        int pret_cu_reducere =  cost_zile_pt_reducere - discount;
        int pret_cu_reducere_30_zile = pret_cu_reducere * 3;
        int pret_cu_reducere_45_zile = pret_cu_reducere * 4 + cost_zi * 5;
        int pret_cu_reducere_60_zile = pret_cu_reducere * 6;
        int pret_cu_reducere_100_zile = pret_cu_reducere * 10;


        calcule<<"Pret pentru 30 zile/Price for 30 days: "<<"\n";
        calcule<<"Pret castel/Castle renting price: "<<pret_cu_reducere_30_zile<<"\n";
        calcule<<"Pretul pentru toate camerele de 2 persoane/Price for all rooms for 2 people: "<<pret_final_camera_de_2 * 30 * 0.22<< " $" <<"\n";
        calcule<<"Pretul pentru toate camerele de 3 persoane/Price for all rooms for 3 people: "<<pret_final_camera_de_3 * 30* 0.22<< " $" <<"\n";
        calcule<<"Costul pentru meniurile omnivore/The cost for omnivorous menus: "<<omni_cost * 30* 0.22<< " $" <<"\n";
        calcule<<"Costul pentru meniurile vegetariene/The cost of vegetarian meals: "<<veg_cost * 30* 0.22<< " $" <<"\n";
        calcule<<"Costul pentru meniurile flexitariene/The cost of flexitarian menus: "<<flex_cost * 30* 0.22<< " $" <<"\n";
        calcule<<"Pretul tuturor meniurilor/Price of all menus: "<< food_cost * 30* 0.22<< " $" << "\n";
        calcule<<"Pretul pentru toate bauturile/The price for all drinks: "<<drink_total * 30* 0.22<< " $" <<"\n";
        calcule << "Costul total pentru machiaj este/The total cost of makeup is: "<<cost_machiaj_total * 30* 0.22<< " $" <<"\n";


        calcule<<"Pret pentru 45 zile/Price for 45 days: "<<"\n";
        calcule<<"Pret castel/Castle renting price: "<<pret_cu_reducere_45_zile<<"\n";
        calcule<<fixed<<"Pretul pentru toate camerele de 2 persoane/Price for all rooms for 2 people: "<<pret_final_camera_de_2 * 45* 0.22<< " $" <<"\n";
        calcule<<"Pretul pentru toate camerele de 3 persoane/Price for all rooms for 3 people: "<<pret_final_camera_de_3 * 45* 0.22<< " $" <<"\n";
        calcule<<"Costul pentru meniurile omnivore/The cost for omnivorous menus: "<<omni_cost * 45* 0.22<< " $" <<"\n";
        calcule<<"Costul pentru meniurile vegetariene/The cost of vegetarian meals: "<<veg_cost * 45* 0.22<< " $" <<"\n";
        calcule<<"Costul pentru meniurile flexitariene/The cost of flexitarian menus: "<<flex_cost * 45* 0.22<< " $" <<"\n";
        calcule<<"Pretul tuturor meniurilor/Price of all menus: "<< food_cost * 45* 0.22 << " $" << "\n";
        calcule<<"Pretul pentru toate bauturile/The price for all drinks: "<<drink_total * 45* 0.22<< " $" <<"\n";
        calcule << "Costul total pentru machiaj este/The total cost of makeup is: "<<cost_machiaj_total * 45* 0.22<< " $" <<"\n";


        calcule<<"Pret pentru 60 zile/Price for 60 days: "<<"\n";
        calcule<<"Pret castel/Castle renting price: "<<pret_cu_reducere_60_zile<<"\n";
        calcule<<fixed<<"Pretul pentru toate camerele de 2 persoane/Price for all rooms for 2 people: "<<pret_final_camera_de_2 * 60* 0.22<< " $" <<"\n";
        calcule<<"Pretul pentru toate camerele de 3 persoane/Price for all rooms for 3 people: "<<pret_final_camera_de_3 * 60* 0.22<< " $" <<"\n";
        calcule<<"Costul pentru meniurile omnivore/The cost for omnivorous menus: "<<omni_cost * 60* 0.22<< " $" <<"\n";
        calcule<<"Costul pentru meniurile vegetariene/The cost of vegetarian meals: "<<veg_cost * 60* 0.22<< " $" <<"\n";
        calcule<<"Costul pentru meniurile flexitariene/The cost of flexitarian menus: "<<flex_cost * 60* 0.22<< " $" <<"\n";
        calcule<<"Pretul tuturor meniurilor/Price of all menus: "<< food_cost * 60 * 0.22<< " $" << "\n";
        calcule<<"Pretul pentru toate bauturile/The price for all drinks: "<<drink_total * 60* 0.22<< " $" <<"\n";
        calcule << "Costul total pentru machiaj este/The total cost of makeup is: "<<cost_machiaj_total * 60* 0.22<< " $" <<"\n";


        calcule<<"Pret pentru 100 zile/Price for 100 days: "<<"\n";
        calcule<<"Pret castel/Castle renting price: "<<pret_cu_reducere_100_zile<<"\n";
        calcule<<fixed<<"Pretul pentru toate camerele de 2 persoane/Price for all rooms for 2 people: "<<pret_final_camera_de_2 * 100* 0.22<< " $" <<"\n";
        calcule<<"Pretul pentru toate camerele de 3 persoane/Price for all rooms for 3 people: "<<pret_final_camera_de_3 * 100* 0.22<< " $" <<"\n";
        calcule<<"Costul pentru meniurile omnivore/The cost for omnivorous menus: "<<omni_cost * 100* 0.22<< " $" <<"\n";
        calcule<<"Costul pentru meniurile vegetariene/The cost of vegetarian meals: "<<veg_cost * 100* 0.22<< " $" <<"\n";
        calcule<<"Costul pentru meniurile flexitariene/The cost of flexitarian menus: "<<flex_cost * 100* 0.22<< " $" <<"\n";
        calcule<<"Pretul tuturor meniurilor/Price of all menus: "<< food_cost * 100* 0.22 << " $" << "\n";
        calcule<<"Pretul pentru toate bauturile/The price for all drinks: "<<drink_total * 100* 0.22<< " $" <<"\n";
        calcule <<fixed<< "Costul total pentru machiaj este/The total cost of makeup is: "<<cost_machiaj_total * 100* 0.22<< " $" <<"\n";

        calcule << "Costul total pentru inchirierea autocarelor dus-intors/Total cost of renting round-trip buses: " << total_cost * 0.22  << " $" <<"\n";

        fisier.close();

        calcule.close();
    }

};

int main() {
    // deschide fișierul CSV
    ifstream file("cast.csv");

    // citire liniile din fișier într-un vector de string-uri
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    //  un vector de persoane
    vector<Person> cast;

    // parcurgere liniile și citiți fiecare linie într-un obiect de tip Person
    for (string line : lines) {
        stringstream ss(line);
        Person p;
        getline(ss, p.name, ',');
        getline(ss, p.role, ',');
        cast.push_back(p);
    }

    //  numărul de persoane în cast și creeați un obiect de tip MonsterAssigner
    int cast_size = cast.size();
    vector<int> monster_counts = {100, 150, 200, 200, 185};
    MonsterAssigner ma(monster_counts);

    // atribuire clasele de monștri pentru fiecare persoană din cast
    for (Person& p : cast)
    {
            p.monster_class = ma.assign_monster();
    }

    // creeare 132 de figuranți random și atribuire clase de monștri
    mt19937 rng;
    vector<string> names = {"Jesse Cisneros", "Billy Barry", "Gunner Soto", "Deja Eaton", "Leonidas Alvarez", "Elisha Chandler", "Walter Hays","Eleanor Baldwin","Kade Cuevas","Sonia Horn","Katherine Fischer","Isabella Cisneros","Barrett Mcintyre", "Adalyn Anthony", "Kyla Jimenez", "Kayden Cantu", "Travis Buck", "Rebecca Pitts","Daisy Kline", "Jazlyn House", "Susan Burke", "Carsen Jenkins", "Aaliyah Krueger","Mariyah Levine", "Lucy Thompson", "Aydin Reynolds", "Bailey Hester", "Leonardo Butler","Sarai Boyer", "Ray Gould", "Jessie Townsend", "Reese Spears", "Beau Watkins","Ada Peterson", "Tiana Reese", "Charles Rowland", "Ryann Good", "Pedro Nash","Hallie Andersen", "Maddison Brennan", "Dania Pugh", "Reagan Serrano", "Jade Hull" };

    uniform_int_distribution<int> dist(0, names.size() - 1);
    for(int i = 0; i < 132; i++)
    {
        Person extra;
        extra.name = names[dist(rng)];
        extra.role = "figurant/extra";
        extra.monster_class = ma.assign_monster();
        cast.push_back(extra);

    }


    // deschide un fișier CSV pentru a scrie rezultatele
    ofstream output_file(file2);


    // scrie fiecare persoană în fișierul CSV
    for (Person& p : cast) {
        output_file << p.name << "," << p.role << "," << p.monster_class << endl;
    }

    // închide fișierul CSV
    output_file.close();

    ifstream team(file1);
    ifstream cast_with_extras(file2);

    ofstream fullteam(file3);

    // copiază linie cu linie din primul fișier în fișierul de ieșire
    string linie;
    while (getline(team, linie)) {
        fullteam << linie << endl;
    }

    // copiază linie cu linie din cel de-al doilea fișier în fișierul de ieșire
    while (getline(cast_with_extras, linie)) {
        fullteam << linie << endl;
    }


    // închide fișierele
    team.close();
    cast_with_extras.close();
    fullteam.close();

    //dieta
    // deschide fișierul CSV
    ifstream mancatori(file3);

    ofstream diete("lista_diete.csv");

    // citire liniile din fișier într-un vector de string-uri
    vector<string> liniute;
    string liniuta;
    while (getline(mancatori, liniuta)) {
        liniute.push_back(liniuta);
    }

    // creeare un vector de persoane
    vector<Person> mancaciosi;

    // parcurge liniile și citiți fiecare linie într-un obiect de tip Person
    for (string liniuta : liniute) {
        stringstream ss(liniuta);
        Person a;
        getline(ss, a.name, ',');
        getline(ss, a.role, ',');
        mancaciosi.push_back(a);
    }

    // creeare  obiect de tip DietAssigner
    DietAssigner da;

    // atribuire diete la întâmplare fiecărei persoane din cast
    for (Person& a : mancaciosi) {
        a.diet = da.assign_diet();
    }

    // afișare dietele alocate
    for (Person a : mancaciosi) {
        diete << a.name <<','<< a.diet << endl;
    }

    diete.close();
    mancatori.close();


    Calcule ca;


    // obiect de tip MenuGenerator
    MenuGenerator mg;





        return 0;
}




























