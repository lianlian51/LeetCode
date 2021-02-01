// ��������Ľ���
// �����ڼ��ò��չ�ʽ

#include <iostream>
#include <cstdio>
using namespace std;
// ���� ��-��-�� ͨ�����չ�ʽ���㵱ǰ���ڼ�
int day_of_week(int year, int month, int day){
	if (month == 1 || month == 2){
		month += 12;
		year -= 1;
	}
	int century = year / 100;
	year %= 100;
	int week = century / 4 - 2 * century + year + year / 4 + (13 * (month + 1)) / 5 + day - 1;
	week = (week % 7 + 7) % 7;
	if (week == 0){
		week = 7;
	}
	return week;
}
// �������º͵ڼ��ܵ����ڼ�������Ǹ��µļ��ż���
int day_of_demand(int year, int month, int count, int d_of_week){
	int week = day_of_week(year, month, 1);// �������1�������ڼ�
	// 1 + 7(n - 1) + (���������� + 7 - 1��������) % 7
	int day = 1 + (count - 1) * 7 + (7 + d_of_week - week) % 7;
	return day;
}
// Ԫ��
void new_year_day(int year){
	printf("%d-01-01\n", year);
}
// ����·�¡�������գ�1�µĵ���������һ��
void martin_luther_king_day(int year){
	printf("%d-01-%02d\n", year, day_of_demand(year, 1, 3, 1));
}
// ��ͳ�գ�2�µĵ���������һ��
void president_day(int year){
	printf("%d-02-%02d\n", year, day_of_demand(year, 2, 3, 1));
}
// ������ʿ�����գ�5�µ����һ������һ��
void memorial_day(int year){
	// �� 6 ����ǰ��
	int week = day_of_week(year, 6, 1);
	// ����һ�Ļ����� 31 ����ǰ�� 6 �죬������ week - 2 ��
	int day = 31 - ((week == 1) ? 6 : (week - 2));
	printf("%d-05-%02d\n", year, day);
}
// ����
void independence_day(int year){
	printf("%d-07-04\n", year);
}
// �Ͷ��ڣ�9�µĵ�һ������һ��
void labor_day(int year){
	printf("%d-09-%02d\n", year, day_of_demand(year, 9, 1, 1));
}
// �ж��ڣ�11�µĵ��ĸ������ģ�
void thanks_giving_day(int year){
	printf("%d-11-%02d\n", year, day_of_demand(year, 11, 4, 4));
}
// ʥ����
void christmas(int year){
	printf("%d-12-25\n\n", year);
}
// ��������
void holiday_of_usa(int year){
	new_year_day(year);
	martin_luther_king_day(year);
	president_day(year);
	memorial_day(year);
	independence_day(year);
	labor_day(year);
	thanks_giving_day(year);
	christmas(year);
}
int main(){
	int year;
	while (cin >> year){
		holiday_of_usa(year);
	}
	return 0;
}