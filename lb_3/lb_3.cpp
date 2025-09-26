#include "Header.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    short number_task;
    do {
        cout << "1 - Приоритетная очередь;\n2 - Очередь;\n3 - Стек;\n0 - выйти\n";
        cout << "------------------------------------------------------------------------------------------------------------------------\n";
        cin >> number_task;
        switch (number_task) {
        case 1: {
            int TmpFlag;
            do {
                cout << "0 - назад, 1 - добавить элемент, 2 - найти, 3 - удалить, 4 - вывод на экран\n";
                cout << "------------------------------------------------------------------------------------------------------------------------\n";
                cin >> TmpFlag;
                switch (TmpFlag) {
                case 0:
                    continue;
                case 1:
                    spstore();
                    break;
                case 2: {
                    char name[32];
                    int priority;
                    node* Output;
                    bool tmpFlag;
                    cout << "0 - поиск по названию, 1 - по приоритетному номеру\n";
                    cout << "------------------------------------------------------------------------------------------------------------------------\n";
                    cin >> tmpFlag;
                    if (tmpFlag == 0) {
                        cout << "Введите название объекта:\n";
                        cin >> name;
                        Output = find(name);
                        if (Output)
                            cout << "Приоритетный номер найденного элемента - " << Output->priority << '\n';
                    }
                    else if (tmpFlag == 1) {
                        cout << "Введите приоритетный номер:\n";
                        cin >> priority;
                        Output = find_priority(priority);
                        if (Output)
                            cout << "Название найденного элемента - " << Output->inf << '\n';
                    }
                    break;
                }
                case 3: {
                    char name_2[32];
                    int priority_2;
                    bool tmpFlag_2;
                    cout << "удалить 0 - по названию, 1 - по приоритетному номеру\n";
                    cout << "------------------------------------------------------------------------------------------------------------------------\n";
                    cin >> tmpFlag_2;
                    if (tmpFlag_2 == 0) {
                        cout << "Введите название объекта, который хотите удалить:\n";
                        cin >> name_2;
                        del(name_2);
                    }
                    else if (tmpFlag_2 == 1) {
                        cout << "Введите приоритетный номер объекта, который хотите удалить:\n";
                        cin >> priority_2;
                        del_prior(priority_2);
                    }
                    break;
                }
                case 4:
                    review();
                    break;
                }
            } while (TmpFlag != 0);
            break;
        }

        case 2: {
            int FLAG;
            do {
                cout << "1 - добавить, 2 - удалить, 3 - вывод очереди, 0 - назад\n";
                cin >> FLAG;
                switch (FLAG) {
                case 1: 
                    spstore_queue();
                    break;
                case 2: 
                    del_queue(); 
                    break;
                case 3:
                    review_queue();
                    break;
                case 0: 
                    break;
                default: 
                    cout << "Неверная команда\n";
                }
            } while (FLAG != 0);
        } break;

        case 3:
            int FLAG;
            do {
                cout << "1 - добавить, 2 - удалить, 3 - вывод стека, 0 - назад\n";
                cin >> FLAG;
                switch (FLAG) {
                case 1:
                    spstore_stack();
                    break;
                case 2:
                    del_stack();
                    break;
                case 3:
                    review_stack();
                    break;
                case 0:
                    break;
                default:
                    cout << "Неверная команда\n";
                }
            } while (FLAG != 0);
            break;

        case 0: break;
        default: cout << "Неверный пункт меню\n";
        }
    } while (number_task != 0);

    return 0;
}
