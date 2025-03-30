#include <iostream>
#include "UI.h"

using namespace std;


int main() {
    setlocale(LC_ALL, "Ru");
    UI* ui = new UI();
    ui->run();
}
