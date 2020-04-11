
#ifndef __DANHSACHDOCGIA_H__
#define __DANHSACHDOCGIA_H__

#pragma once
#include "DocGia.h"

class DanhSachDocGia
{
private:
	vector<DocGia> list_DocGia; //Vector lưu danh sách Đọc Giả.
	vector<DocGia> list_Them; ////Vector lưu danh sách Đọc Giả thêm.
public:
	//NHẬP, XUẤT
	void Input();
	void Output();

	// TÌM KIẾM, THÊM, XÓA, SỬA:
	DocGia *TimKiemQuaCMND(string);
	void ThemDocGia(int);
	void XoaDocGia();
	void CapNhatThongTinDocGiaQuaCMND(string);

	//LIỆT KÊ ĐỌC GIẢ MƯỢN SÁCH QUÁ HẠN & TIỀN PHẠT:
	void LietKeDocGiaMuonSachQuaHan();
	DanhSachDocGia();
	~DanhSachDocGia();
};

#endif