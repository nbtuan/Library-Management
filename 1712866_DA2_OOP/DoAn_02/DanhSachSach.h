
#ifndef __DANHSACHSACH_H__
#define __DANHSACHSACH_H__

#pragma once
#include "NgoaiVan.h"
#include "TiengViet.h"
#include <vector>
#include <fstream>

class DanhSachSach
{
private:
	vector<Sach *> list; //Vector lưu danh sách Sách.
	vector<Sach *> arr; //Vector lưu danh sách Sách thêm.
public:
	static ofstream Fout;
public:
	// NHẬP, XUẤT:
	void Input();
	void Output();

	// TÌM KIẾM, THÊM, XÓA, SỬA:
	Sach *TimKiemQuaMaSach(string);
	void ThemSach(int);
	void XoaSach();
	void CapNhatThongTinQuaMaSach(string);

	//TÍNH SỐ LƯỢNG SÁCH TIẾNG VIỆT
	int TinhSoLuongSachTiengViet();

	//TÍNH SỐ LƯỢNG SÁCH NGOẠI VĂN
	int TinhSoLuongSachNgoaiVan();


	DanhSachSach();
	~DanhSachSach();
};

#endif