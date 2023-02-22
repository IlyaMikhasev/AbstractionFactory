#include <iostream>
#include <memory>
#include <tuple>
class Button {
public:
	virtual void print() = 0;
	virtual ~Button() {};
};
class WinButton : public Button {
public:
	void print()override {
		std::cout << "Pain winButtom\n";
	}
};
class MacButton : public Button {
public:
	void print()override {
		std::cout << "Pain macButtom\n";
	}
};
class ChekBox {
public:
	virtual void paint() =0 ;
	virtual ~ChekBox() {}
};
class WinChekbox :public ChekBox {
public:
	void paint()override {
		std::cout << "Paint WinChekbox\n";
	}
};
class MacChekbox :public ChekBox {
public:
	void paint()override {
		std::cout << "Paint MacChekbox\n";
	}
};
class GUIFactory {
public:
	virtual std::shared_ptr<Button> creatButton() = 0;
	virtual std::shared_ptr<ChekBox> creatChekbox() = 0;
	virtual ~GUIFactory() {}
};
class WinFactory : public GUIFactory {
public:
	std::shared_ptr<Button> creatButton()override {
		return std::make_shared<WinButton>();
	}
	std::shared_ptr<ChekBox> creatChekbox()override {
		return std::make_shared<WinChekbox>();
	}
};
class MacFactory : public GUIFactory {
public:
	std::shared_ptr<Button> creatButton()override {
		return std::make_shared<MacButton>();
	}
	std::shared_ptr<ChekBox> creatChekbox() override{
		return std::make_shared<MacChekbox>();
	}
};
class Application {
public:
	Application(std::shared_ptr<GUIFactory> factory) :_factory(factory) {}
	void creatUI() {
		_button = _factory->creatButton();
		_chekbox = _factory->creatChekbox();
	}
	void paint() {
		_button->print();
		_chekbox->paint();
	}
private:
	std::shared_ptr<GUIFactory> _factory;
	std::shared_ptr<Button> _button;
	std::shared_ptr<ChekBox> _chekbox;
};
int main() {
	setlocale(LC_ALL, "Russian");
	std::string config;
	std::shared_ptr<GUIFactory> factory;
	std::cout << "Enter platform ()Mac,Windows):";
	std::cin >> config;
	if (config == "Mac")
		factory = std::make_shared<MacFactory>();
	else if (config == "Windows")
		factory = std::make_shared<WinFactory>();
	std::shared_ptr<Application> app= std::make_shared<Application>(factory);
	app->creatUI();
	app->paint();

	//tuple
	std::tuple<int, float, std::string> tup(5, 4.5, "Hello");
	std::cout << std::get<2>(tup);//возвращает элемент под индексом 2 из tuple

	return 0;
}