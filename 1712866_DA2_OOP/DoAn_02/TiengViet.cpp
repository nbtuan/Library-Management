#include "TiengViet.h"
#include "DanhSachSach.h"

TiengViet::TiengViet()
{
}

TiengViet::~TiengViet()
{
}

void TiengViet::Input()
{
	ID = 1; // Đánh dấu Sách Tiếng Việt.
	Sach::Input();
}
void TiengViet::Output()
{
	Sach::Output();
}