#include <iostream>
#include <string>
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

    void addPoints(string x){
        int points=model->retrivePoints();
        if(x=="b"){
            points+=1;

            model->storePoints(points);
            view->prompt("+1 point! \n");
        }
    }

    void checkLevel(){
        int points=model->retrivePoints();
        int level=model->retriveLevel();
        if(points==5){
            points=0;
            level+=1;

            model->storePoints(points);
            model->storeLevel(level);
            view->prompt("+1 level!!! \n");
        }
    }

    void launch(){
            string s="";
        do {
            //Funkcjonalnosc
            view->prompt("Podaj znak (b-punkty , e-wyjscie): ");
            s = view->getInput();
            model->storeString(s);

            string x=model->retriveString();

            addPoints(x);
            checkLevel();

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

        }while(s!="e");

    }
private:
    View* view;
    Model* model;

};



int main() {
    View view;
    Model model;
    Controller controller(&view , &model);
    return 0;
}
