#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "surprise_window.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(640, 640);
    ui->input_line->setPlaceholderText("请点击这里输入算式");
    ui->answers->setPlaceholderText("答案会显示在这里哦!!");
}


MainWindow::~MainWindow()
{
    delete ui;
}

void caculation(std::stack<double> &s1, std::stack<char>& s2, int& flag){
    if (s1.size() < 2){flag = 0; return;}
    double a = s1.top();
    s1.pop();
    double b = s1.top(), d = 1;
    s1.pop();
    char op = s2.top();
    s2.pop();
    switch(op){
        case('+'): s1.push(b + a); break;
        case('-'): s1.push(b - a); break;
        case('*'): s1.push(b * a); break;
        case('/'): if(a == 0) {flag = 0;break;}s1.push(b / a); break;
        case('^'): while(a--) d *= b;s1.push(d); break;
        default: flag = 0;
    }
}


//计算环节
void MainWindow::get_result(){
    if (input.size() < 2){ans = "ERROR_INPUT!!!"; return;} //长度不够可以直接报错
    s = input.toStdString();
    //16bit的×和÷转化为*和/
    for (int i = 0; i < s.size() - 1; ++i){
       // std::cout << int(s[i]) << std::endl;
        if (s[i] == -61){
            if (s[i + 1] == -105){s[i] = '*';s.erase(i + 1, 1); i-= 1;}
            else if (s[i + 1] == -73){s[i] = '/'; s.erase(i + 1, 1);i -= 1;}
        }
    }
   // std::cout << s << std::endl;
    //写个检查括号数量的函数吧,哎!
    int cnt = 0, flag = 1;
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == '(') {cnt += 1;}
        else if(s[i] == ')'){ cnt -= 1;}
        if (cnt < 0){ans = "ERROR_INPUT!!!"; return;} //右括号过多
    }
    if (cnt != 0){ans = "ERROR_INPUT!!!"; return;}  //左括号过多
    s = '(' + s + ')';//加个括号方便中缀表达式边界条件计算
    int n = s.size();
    std::stack<double> s1;
    std::stack<char> s2;
    for (int i = 0; i < n && flag; ++i){
        if ('0' <= s[i] && s[i] <= '9'){
            double t = 0;
            while(i < n && s[i] >= '0' && s[i] <= '9'  && flag){t *= 10; t += s[i] - '0'; i += 1;}
            //如果后面还有整数部分的话，小数部分不能漏
            if(s[i] == '.'){
                i += 1;
                double tt = 0;
                while(i < n && s[i] >= '0' && s[i] <= '9'  && flag){tt *= 10;tt += s[i] - '0'; i += 1;}
                while(tt > 1){tt /= 10;}
                t += tt;
            }
            i -= 1;
            s1.push(t);
        }
        else if (s[i] == '+'){
            while(s2.top() != '('  && flag){caculation(s1, s2, flag);}
            s2.push(s[i]);
        }
        else if (s[i] == '-'){
            if (i == 0 || (i && !(s[i - 1] >= '0' && s[i - 1] <= '9') && s[i - 1] != ')')){
                double t = 0;
                i += 1;
                while (i < n && s[i] <= '9' && s[i] >= '0'  && flag){t *= 10; t += s[i] - '0';i += 1;}
                 s1.push(t * -1);
                i -= 1;
            }
            else{
                while(s2.top() != '('  && flag){caculation(s1, s2, flag);}
                s2.push(s[i]);
            }
        }
        else if (s[i] == '*' || s[i] == '/'){
            while (s2.top() != '(' && (s2.top() == '*' || s2.top() == '/' || s2.top() == '^') && flag){caculation(s1, s2, flag);}
            s2.push(s[i]);
        }
        else if (s[i] == '^'){
            while (s2.top() != '(' && s2.top() == '^'  && flag){caculation(s1, s2, flag);}
            s2.push(s[i]);
        }
        else if (s[i] == ')'){
            while (s2.top() != '(' && flag){caculation(s1, s2, flag);}
            s2.pop();
        }
        else if(s[i] == '('){
            s2.push(s[i]);
        }
    }
    if (!flag || s2.size() != 0 || s1.size() == 0){ans = "ERROR_INPUT!!!";} //如果因为字符串违规退出或者栈中仍有符号或者栈中没有数字
    else{
        std::string ss = std::to_string(s1.top());
        int i = ss.size() - 1;
        //std::cout << ss << std::endl;
        while(ss[i] != '.' && ss[i] == '0'){ss.erase(i, 1); i -= 1;}
        if(ss[i] == '.') ss.erase(i, 1);
        //std::cout << ss << std::endl;
        ans = QString::fromStdString(ss);
    }
}

void MainWindow::sur_win(){
    surprise_window* ww = new surprise_window();
    ww->show();
}

void MainWindow::on_p1_clicked(){input = input + "1";ui->input_line->setText(input);tag = 1;}

void MainWindow::on_p2_clicked(){input = input + "2";ui->input_line->setText(input);tag = 1;}

void MainWindow::on_p3_clicked(){input = input + "3";ui->input_line->setText(input);tag = 1;}

void MainWindow::on_p4_clicked(){input = input + "4";ui->input_line->setText(input);tag = 1;}

void MainWindow::on_p5_clicked(){input = input + "5";ui->input_line->setText(input);tag = 1;}

void MainWindow::on_p6_clicked(){input = input + "6";ui->input_line->setText(input);tag = 1;}

void MainWindow::on_p7_clicked(){input = input + "7";ui->input_line->setText(input);tag = 1;}

void MainWindow::on_p8_clicked(){input = input + "8";ui->input_line->setText(input);tag = 1;}

void MainWindow::on_p9_clicked(){input = input + "9";ui->input_line->setText(input);tag = 1;}

void MainWindow::on_p0_clicked(){input = input + "0";ui->input_line->setText(input);tag = 1;}

void MainWindow::on_backspace_clicked(){input = input.left(input.size() - 1);ui->input_line->setText(input); tag = 1;}

void MainWindow::on_AC_clicked(){input = ""; ui->input_line->setText(input); ui->answers->setText("");}


void MainWindow::on_brackestl_clicked(){input = input + "(";ui->input_line->setText(input);}

void MainWindow::on_brackestr_clicked(){input = input + ")";ui->input_line->setText(input);}

void MainWindow::on_pequal2_clicked(){input = ans;ui->input_line->setText(input);}


//下面的按键是运算符

void MainWindow::on_padd_clicked(){
    if(tag) {input = input + "+";}
    else {input = input.left(input.size() - 1) + "+";}
    ui->input_line->setText(input); tag = 0;
}
void MainWindow::on_psubstract_clicked(){
    if(tag) {input = input + "-";}
    else {input = input.left(input.size() - 1) + "-";}
    ui->input_line->setText(input); tag = 0;
}
void MainWindow::on_pmultiple_clicked(){
    if(tag) {input = input + "×";}
    else {input = input.left(input.size() - 1) + "×";}
    ui->input_line->setText(input); tag = 0;
}
void MainWindow::on_pdivide_clicked(){
    if(tag) {input = input + "÷";}
    else {input = input.left(input.size() - 1) + "÷";}
    ui->input_line->setText(input); tag = 0;
}
void MainWindow::on_ppow_clicked(){
    if(tag) {input = input + "^";}
    else {input = input.left(input.size() - 1) + "^";}
    ui->input_line->setText(input); tag = 0;
}
//将结果赋值到input，方便利用当前结果计算计算
void MainWindow::on_pequal_clicked(){
    get_result(); ui->answers->setText(ans);
}
void MainWindow::on_pdot_clicked(){
    if (input.size() > 0 && input[input.size() - 1] != '.'){input = input + ".";ui->input_line->setText(input);tag = 1;}//不能连续输入2个'.'
}
void MainWindow::on_jingxi_clicked(){
    sur_win();
}

