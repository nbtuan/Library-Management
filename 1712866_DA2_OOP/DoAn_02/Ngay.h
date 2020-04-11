
#ifndef __NGAY_H__
#define __NGAY_H__

#include "DanhSachSach.h" //Để dùng được file mình đã khai báo.
#pragma once

class Ngay
{
private:
	int ngay, thang, nam;
public:
	//NHẬP, XUẤT:
	void Input();
	void Output();
	// LẤY RA NGÀY, THÁNG, NĂM:
	int Getter_Ngay();
	int Getter_Thang();
	int Getter_Nam();
	Ngay();
	~Ngay();
};

#endif