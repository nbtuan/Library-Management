#include "Ngay.h"

Ngay::Ngay()
{
}
Ngay::~Ngay()
{
}

void Ngay::Input()
{
	cout << "\nNhap vao ngay: "; cin >> ngay;
	cout << "\nNhap vao thang: "; cin >> thang;
	cout << "\nNhap vao nam: "; cin >> nam;
}
void Ngay::Output()
{
	DanhSachSach::Fout << ngay << "/" << thang << "/" << nam;
}

int Ngay::Getter_Ngay()
{
	return ngay;
}
int Ngay::Getter_Thang()
{
	return thang;
}
int Ngay::Getter_Nam()
{
	return nam;
}