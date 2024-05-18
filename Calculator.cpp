#include "Calculator.h"
#include "ui_Calculator.h"
#include<QFile>
#include<QMessageBox>
#include<stack>
#include<strstream>
#include<string>
#include<QPainter>
#include<QBrush>
#include<strstream>
using namespace std;

Calculator::Calculator(QWidget* parent)
	:QWidget(parent)
	,ui(new Ui::Calculator)
{
	ui->setupUi(this);
	init();
}

void Calculator::init()
{
	this->setWindowIcon(QIcon(":/Resource/jisuanqi.png"));
	QFile file(":/Resource/style.css");
	if (!file.open(QIODevice::ReadOnly)) {
		qDebug() << "文件打开失败";
	}
	QString styleStr = file.readAll();
	this->setStyleSheet(styleStr);
	initUi();

}

void Calculator::initUi()
{
	
	
	//设置Icon
	ui->btn12->setIcon(QIcon(":/Resource/kuohao.png"));
	ui->btn13->setIcon(QIcon(":/Resource/qingkong.png"));
	ui->btn14->setIcon(QIcon(":/Resource/huitui.png"));
	ui->btn21->setIcon(QIcon(":/Resource/daoshu.png"));
	ui->btn22->setIcon(QIcon(":/Resource/kaipingfang.png"));
	ui->btn23->setIcon(QIcon(":/Resource/pingfang.png"));
	//设置图片大小
	ui->btn12->setIconSize(QSize(40, 40));
	ui->btn13->setIconSize(QSize(40, 40));
	ui->btn14->setIconSize(QSize(40,40));
	ui->btn21->setIconSize(QSize(100,100));
	ui->btn22->setIconSize(QSize(100,100));
	ui->btn23->setIconSize(QSize(100,100));
	//设置图片背景透明
	/*
	* setFlat只能让按钮背景透明，图片背景仍然存在 。
	ui->btn12->setFlat(true);
	ui->btn21->setFlat(true);
	ui->btn22->setFlat(true);
	ui->btn23->setFlat(true);
	*/
	//解决办法 ： 使用矢量图（扣掉背景的图），或者自己用图片处理工具将图片背景扣掉
	
	//按键触发信号
	connect(ui->btn11, &QPushButton::clicked, this, &Calculator::getMod);
	connect(ui->btn12, &QPushButton::clicked, [=] {ui->lineEdit->insert("()"); });
	connect(ui->btn13, &QPushButton::clicked, [=] {ui->lineEdit->clear(); });
	connect(ui->btn14, &QPushButton::clicked, [=] {ui->lineEdit->backspace(); });
	connect(ui->btn21, &QPushButton::clicked, this ,&Calculator::getDaoshu);
	connect(ui->btn22, &QPushButton::clicked, this, &Calculator::getGenhao);
	connect(ui->btn23, &QPushButton::clicked, this, &Calculator::getPingfang);
	connect(ui->btn24, &QPushButton::clicked, [=] {ui->lineEdit->insert("/"); });
	connect(ui->btn31, &QPushButton::clicked, [=] {ui->lineEdit->insert("7"); });
	connect(ui->btn32, &QPushButton::clicked, [=] {ui->lineEdit->insert("8"); });
	connect(ui->btn33, &QPushButton::clicked, [=] {ui->lineEdit->insert("9"); });
	connect(ui->btn34, &QPushButton::clicked, [=] {ui->lineEdit->insert("*"); });
	connect(ui->btn41, &QPushButton::clicked, [=] {ui->lineEdit->insert("4"); });
	connect(ui->btn42, &QPushButton::clicked, [=] {ui->lineEdit->insert("5"); });
	connect(ui->btn43, &QPushButton::clicked, [=] {ui->lineEdit->insert("6"); });
	connect(ui->btn44, &QPushButton::clicked, [=] {ui->lineEdit->insert("-"); });
	connect(ui->btn51, &QPushButton::clicked, [=] {ui->lineEdit->insert("1"); });
	connect(ui->btn52, &QPushButton::clicked, [=] {ui->lineEdit->insert("2"); });
	connect(ui->btn53, &QPushButton::clicked, [=] {ui->lineEdit->insert("3"); });
	connect(ui->btn54, &QPushButton::clicked, [=] {ui->lineEdit->insert("+"); });
	connect(ui->btn61, &QPushButton::clicked, [=] {this->close(); });
	connect(ui->btn62, &QPushButton::clicked, [=] {ui->lineEdit->insert("0"); });
	connect(ui->btn63, &QPushButton::clicked, [=] {ui->lineEdit->insert("."); });
	connect(ui->btn64, &QPushButton::clicked, this, &Calculator::getAns);

}

Calculator::~Calculator()
{
	delete ui;
}

void Calculator::getMod()
{
	const QString str = ui->lineEdit->text();
	if (str.isEmpty()) {
		drawMessageBox();
		return;
	}
	for (auto& val : str) {
		if (val == '+' || val == '-' || val == 'x' || val == char('÷') || val == '%' || val == '(' || val == ')')
		{
			drawMessageBox();
			return;
		}
	}
	double num = str.toDouble();
	num = num * 0.01;
	ui->fillLab->setText(QString::number(num));
	ui->lineEdit->setText(QString::number(num));
}

void Calculator::getDaoshu()
{
	const QString str = ui->lineEdit->text();
	if (str.isEmpty()) {
		drawMessageBox();
		return;
	}
	for (auto& val : str) {
		if (val == '+' || val == '-' || val == 'x' || val == char('÷') || val == '%' || val == '(' || val == ')')
		{
			drawMessageBox();
			return;
		}
	}
	double num = str.toDouble();
	num = 1.0 / num;
	ui->fillLab->setText(QString::number(num));
	ui->lineEdit->setText(QString::number(num));
}

void Calculator::getGenhao()
{
	const QString str = ui->lineEdit->text();
	if (str.isEmpty()) {
		drawMessageBox();
		return;
	}
	for (auto& val : str) {
		if (val == '+' || val == '-' || val == 'x' || val == char('÷') || val == '%' || val == '(' || val == ')')
		{
			drawMessageBox();
			return;
		}
	}
	double num = str.toDouble();
	num = sqrt(num);
	ui->fillLab->setText(QString::number(num));
	ui->lineEdit->setText(QString::number(num));
}

void Calculator::getPingfang()
{
	const QString str = ui->lineEdit->text();
	if (str.isEmpty()) {
		drawMessageBox();
		return;
	}
	for (auto& val : str) {
		if (val == '+' || val == '-' || val == 'x' || val == char('÷') || val == '%' || val == '(' || val == ')')
		{
			drawMessageBox();
			return;
		}
	}
	double num = str.toDouble();
	num = num * num;
	ui->fillLab->setText(QString::number(num));
	ui->lineEdit->setText(QString::number(num));
}

void Calculator::getAns()
{
	const QString& str = ui->lineEdit->text();
	double ans = evaluate_expression(str);
	ui->fillLab->setText(QString::number(ans));
	ui->lineEdit->setText(QString::number(ans));
}

void Calculator::drawMessageBox()
{
	QMessageBox box(this);
	box.setIconPixmap(QPixmap(":/Resource/error.png").scaled(100,100));
	box.setText("参数错误");
	box.exec();
}

void Calculator::paintEvent(QPaintEvent* ev)
{
	QPixmap pix(":/Resource/background.png");
	pix = pix.scaled(50, 50);
	QPainter painter(this);
	painter.save();
	painter.drawPixmap(0, 0, pix);
	painter.fillRect(ui->verticalLayout->geometry(), QColor("#66FFCC"));

	painter.restore();
}

bool Calculator::is_operator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}
int Calculator::precedence(char op) {
	if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '*' || op == '/') {
		return 2;
	}
	else {
		return 0;
	}
}
double Calculator::apply_operator(double a, double b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	default: drawMessageBox();
	}
}
double Calculator::evaluate_expression(const QString& expression_) {
	string expression = expression_.toStdString();
	std::stack<double> num_stack;
	std::stack<char> op_stack;
	for (size_t i = 0; i < expression.length(); ++i) {
		if (expression[i] == ' ') { continue; }
		else if (isdigit(expression[i]) || expression[i] == '.') {
			size_t j = i;
			while (j < expression.length() && (isdigit(expression[j]) || expression[j] == '.')) {
				++j;
			}
			double number;
			strstream ss;
			ss << expression.substr(i, j - i);
			ss >> number;
			num_stack.push(number);
			i = j - 1;
		}
		else if (is_operator(expression[i])) {
			while (!op_stack.empty() && precedence(op_stack.top()) >= precedence(expression[i])) {
				double b = num_stack.top();
				num_stack.pop();
				double a = num_stack.top();
				num_stack.pop();
				char op = op_stack.top();
				op_stack.pop();
				num_stack.push(apply_operator(a, b, op));
			}
			op_stack.push(expression[i]);
		}
		else if (expression[i] == '(') {
			op_stack.push(expression[i]);
		}
		else if (expression[i] == ')') {
			while (!op_stack.empty() && op_stack.top() != '(') {
				double b = num_stack.top();
				num_stack.pop();
				double a = num_stack.top();
				num_stack.pop();
				char op = op_stack.top();
				op_stack.pop();
				num_stack.push(apply_operator(a, b, op));
			}
			if (op_stack.empty() || op_stack.top() != '(') {
				drawMessageBox();
				return 0;
			}
			op_stack.pop();
		}
		else {
			drawMessageBox();
			return 0;
		}
	}
	while (!op_stack.empty()) {
		double b = num_stack.top();
		num_stack.pop();
		double a = num_stack.top();
		num_stack.pop();
		char op = op_stack.top();
		op_stack.pop();
		num_stack.push(apply_operator(a, b, op));
	}
	if (num_stack.size() != 1) {
		drawMessageBox();
		return 0;
	}
	return num_stack.top();
}

