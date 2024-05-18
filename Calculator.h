#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include<QWidget>
namespace Ui { class Calculator; }

class Calculator : public QWidget
{
public:
	Calculator(QWidget* parent = nullptr);
	void init();
	void initUi();
	~Calculator();
	void drawMessageBox();
protected:
	void paintEvent(QPaintEvent* ev)override;
private:
	void getMod();

	void getDaoshu();

	void getGenhao();

	void getPingfang();

	void getAns();

	bool is_operator(char c);
	int precedence(char op);
	double apply_operator(double a, double b, char op);
	double evaluate_expression(const QString& expression);
private:
	Ui::Calculator* ui{};
};

#endif // !CALCULATOR_H_
