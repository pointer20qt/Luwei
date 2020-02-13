#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;

class Complex{
	
	
public:
	int a;
	int b;
public:
	Complex(){
		this->a = 0;
		this->b = 0;
	}
	Complex(int a, int b){
		this->a = a;
		this->b = b;
	}
	Complex(Complex* a){
		this->a = a->a;
		this->b = a->b;
	}
	void show(){
		cout << this->a << endl;
		cout << this->b << endl;
	}
	void operator = (Complex & c1){
		this->a = c1.a;
		this->b = c1.b;
	}
	virtual Complex operator << (Complex & c1){
		cout << c1.a << " + " << c1.b << "i" << endl;
		return *this;
	}
	Complex operator * (Complex & c1){
		Complex tmp;
		tmp.a = this->a * c1.a + this->b * c1.b *(-1);
		tmp.b = this->a*c1.b + this->b*c1.a;
		return tmp;
	}
	Complex operator + (Complex &c1){
		Complex tmp;
		tmp.a = c1.a + this->a;
		tmp.b = c1.b + this->b;
		return tmp;
	}
	virtual  ~Complex(){
		cout << "父类析构函数" << endl;
	}
};

class nums: public Complex
{
public:
	nums(int a,int b):Complex(a,b){
		
	}
	virtual Complex operator << (Complex & c1){
		cout << c1.a << "+" << c1.b << "i" << endl;
		return *this;
	}
	Complex operator + (Complex &c1){
		Complex tmp;
		tmp.a = c1.a + this->a;
		tmp.b = c1.b + this->b;
		return tmp;
	}
	~nums(){
		cout << "子类析构函数" << endl;
	}
};



int main(){
	Complex* k = new nums(1,1);
	delete k;
	system("pause");

}