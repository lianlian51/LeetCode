#include<iostream>
using namespace std;

typedef long long LL;
struct Fraction{
	LL up, down;
};
//�����Լ�� 
LL gcd(LL a, LL b){
	return b == 0 ? a : gcd(b, a%b);
}
//������ 
Fraction reduction(Fraction res){
	if (res.down<0){
		res.down = -res.down;
		res.up = -res.up;
	}
	if (res.up == 0){
		res.down = 1;
	}
	else{
		LL factor = gcd(abs(res.up), res.down);
		res.up /= factor;
		res.down /= factor;
	}
	return res;
}
//������� 
void showRes(Fraction res){
	res = reduction(res);
	if (res.up<0){//������Ҫ������ 
		cout << "(";
	}
	if (res.down == 1){//���� 
		printf("%lld", res.up);
	}
	else if (abs(res.up)>res.down){//�ٷ��� 
		printf("%lld %lld/%lld", res.up / res.down, abs(res.up) % res.down, res.down);
	}
	else {//����� 
		printf("%lld/%lld", res.up, res.down);
	}
	if (res.up<0){//������Ҫ������ 
		cout << ")";
	}
}
//�ӷ� 
Fraction add(Fraction a, Fraction b){
	Fraction res;
	res.up = a.up*b.down + a.down*b.up;
	res.down = a.down*b.down;
	return reduction(res);
}
//����
Fraction diff(Fraction a, Fraction b){
	Fraction res;
	res.up = a.up*b.down - a.down*b.up;
	res.down = a.down*b.down;
	return reduction(res);
}
//�˷�
Fraction sub(Fraction a, Fraction b){
	Fraction res;
	res.up = a.up*b.up;
	res.down = a.down*b.down;
	return reduction(res);
}
//����
Fraction div(Fraction a, Fraction b){
	Fraction res;
	res.up = a.up*b.down;
	res.down = a.down*b.up;
	return reduction(res);
}
int main(){
	Fraction a, b;
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	showRes(a); cout << " + "; showRes(b); cout << " = "; showRes(add(a, b)); cout << endl;
	showRes(a); cout << " - "; showRes(b); cout << " = "; showRes(diff(a, b)); cout << endl;
	showRes(a); cout << " * "; showRes(b); cout << " = "; showRes(sub(a, b)); cout << endl;
	showRes(a); cout << " / "; showRes(b); cout << " = ";
	if (b.up != 0){//������Ϊ0 
		showRes(div(a, b));
	}
	else cout << "Inf";
	cout << endl;
	return 0;
}
