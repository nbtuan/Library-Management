#include "NgoaiVan.h"
#include "DanhSachSach.h"

NgoaiVan::NgoaiVan()
{
}

NgoaiVan::~NgoaiVan()
{
}

void NgoaiVan::Input()
{
	ID = 2; // Đánh dấu Sách Ngoại Văn
	Sach::Input();
	rewind(stdin);
	cout << "\nNhap vao ISBN: "; getline(cin, ISBN);
}

void NgoaiVan::Output()
{
	Sach::Output();
	DanhSachSach::Fout << "\n\n\tISBN: " << ISBN;
}