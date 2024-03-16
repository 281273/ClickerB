#include <iostream>
#include <string>
//#include <conio.h> not in CLion
using namespace std;

//View
class View{
public:
    void prompt(int i){
        cout<<i;
    }
    void prompt(string s){
        cout<<s;
    }
    string getInput(){
        string x;
        //bez getcha bo i tak trzeba potwierdzac enterem. Trzeba zmieniac opcje Clion
        cin>>x;
        return x;
    }
private:

};

//Model
class Model{
public:
    void storeString(string n){
        x=n;
    }
    void storePoints(int n){
        points=n;
    }
    void storeLevel(int n){
        level=n;
    }

    string retriveString(){
        return x;
    }
    int retrivePoints(){
        return points;
    }
    int retriveLevel(){
        return level;
    }

    void addPoints(){
        points+=1;
        storePoints(points);
        if(points%5==0){
            addLevel();
        }

    }

    void addLevel(){
        level=points/5;
        storePoints(points);
        storeLevel(level);

    }

private:
    string x=" ";
    int points=0;
    int level=0;

};

//Controller
class Controller{

public:
    Controller(View* _view,Model* _model){
        view = _view;
        model = _model;

        launch();
    }

    void checkStats(){
        string x=model->retriveString();
        int oldlevel=model->retriveLevel();
        if(x=="b"){
            model->addPoints();
            view->prompt("+1pkt \r");
            int level=model->retriveLevel();
            if(oldlevel<level){
                view->prompt("+1lvl!!! \t");
            }
        }else if(x=="e"){
            end=false;
            view->prompt("\n Koniec gry. Twoj wynik ostateczny to: \n");
        };
    }

    void launch(){
        string s="";
        view->prompt("Instrukcje: \n (b-> +1pkt , e-> wyjscie ,Kazde 5 pkt to +1lv) \n\n ");

        while(end){
            //Funkcjonalnosc
            //clrscr(); not working in Clion
            view->prompt("Podaj znak: ");
            s = view->getInput();
            model->storeString(s);

            string x=model->retriveString();

            checkStats();

            //Wypisanie
            int points=model->retrivePoints();
            int level=model->retriveLevel();

            view->prompt("Points: ");
            view->prompt(points);
            view->prompt("\t Level: ");
            view->prompt(level);
            //view->prompt("\t Here is your input: ");
            //view->prompt(x);
            view->prompt("\n");

        }

    }
private:
    View* view;
    Model* model;
    bool end;
};



int main() {
    View view;
    Model model;
    Controller controller(&view , &model);
    return 0;
}

