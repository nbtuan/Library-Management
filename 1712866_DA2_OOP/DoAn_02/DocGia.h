
#ifndef __DOCGIA_H__
#define __DOCGIA_H__

#pragma once
#include "DanhSachSach.h"
#include "Ngay.h"

class DocGia
{
private:
	string CMND, ten;
	int tuoi;
	DanhSachSach List_Sach; // Danh sách Sách.
	Ngay Ngay_Muon; //Ngày mượn.
	Ngay Ngay_Tra; //Ngày trả.
public:
	// NHẬP, XUẤT:
	void Input();
	void Output();

	string Getter_CMND();
	void Setter_CMND(string);

	bool KiemTraCoQuaHanTraKhong(); //Kiểm tra quá hạn trả ko? có: TRUE, không: FALSE.
	void TinhTienPhatDocGiaPhaiDongNeuTraMuon(); //Tính tiền đọc giả sẽ phải đóng nếu trả muộn.

	DocGia();
	~DocGia();
};

#endif