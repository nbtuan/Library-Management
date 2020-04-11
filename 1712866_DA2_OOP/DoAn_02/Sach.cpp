#include "Sach.h"
#include "DanhSachSach.h"

Sach::Sach()
{
}

Sach::~Sach()
{
}

void Sach::Input()
{
	rewind(stdin);
	//cout << "\nNhap vao Ma Sach: "; getline(cin, MaSach); //Không nhập chỗ này để nhập trong DanhSachSach để kiểm tra trùng.
	cout << "\nNhap vao Ten Sach: "; getline(cin, TenSach);
	cout << "\nNhap vao Tac Gia: "; getline(cin, TacGia);
	cout << "\nNhap vao Nha Xuat Ban: "; getline(cin, NhaXuatBan);
	cout << "\nNhap vao Gia Sach: "; cin >> GiaSach;
}

void Sach::Output()
{
	DanhSachSach::Fout << "\n\n\tMa Sach: " << MaSach;
	DanhSachSach::Fout << "\n\n\tTen Sach: " << TenSach;
	DanhSachSach::Fout << "\n\n\tTac Gia: " << TacGia;
	DanhSachSach::Fout << "\n\n\tNha Xuat Ban: " << NhaXuatBan;
	DanhSachSach::Fout << "\n\n\tGia Sach: " << GiaSach;
}

string Sach::Getter_MaSach()
{
	return MaSach;
}

void Sach::Setter_MaSach(string ms)
{
	MaSach = ms;
}

int Sach::Getter_ID()
{
	return ID;
}

void Sach::Setter_ID(int x)
{
	ID = x;
}