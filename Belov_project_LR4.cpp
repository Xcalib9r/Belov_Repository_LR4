#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

int x,y;
//Функция ввода данных
function<void()> EnterNumber(int& varLink, string label)
{
      return [&varLink, label]() {
        int input;
        while (true) {
            cout << label << " (положительное число): ";
            cin >> input;

            if (cin.fail() || input <= 0) {
                cout << "Ошибка! Введите положительное целое число.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            } else {
                varLink = input;
                break;
            }
        }
    };
}
void CalcSr()
{

}
void CalcGr()
{

}

//структура меню
struct MenuItem {
    string title;
    function<void()> action;
};
int main(){
    map<int, MenuItem> menu= {
        {1,{"Ввод положительного числа X", EnterNumber(x, "Input x")}},
        {2,{"Ввод положительного числа Y", EnterNumber(y, "Input y")}},
        {3,{"Вычислить среднее арифметическое Sr = (Х+ У)/2",CalcSr}},
        {4,{"вычислить среднее геометрическое Gr = Sqrt(X*У)",CalcGr}},
    };

    int choice=0;

    while(true)
    {
        cout<<"Меню:"<<endl;
        for(const auto& item : menu){
            cout<<"Task "<<item.first<<". "<<item.second.title<<endl;
        }
        cout<<"0.Выход"<<endl;
        cout<<"Введите номер пункта: ";
        cin>>choice;

        if(choice==0){
            cout<<"@ 2025 FirstName LastName"<<endl;
            break;
        }
        cout<<endl;
        if(menu.find(choice)!=menu.end()){
            menu[choice].action();
        } else{
            cout<<"Некорректный ввод.";
        }
        cout<<endl;
    }
    return 0;
};