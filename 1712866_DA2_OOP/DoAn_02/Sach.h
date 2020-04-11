
/*
	MSSV: 1712866
	Name: Nguyen Ba Tuan
	Class: 17CTT7
	Bai tap: Quan Ly Thu Vien
	Deadline: 18h, 10/01/2019
*/

#ifndef __SACH__
#define __SACH__

#pragma once
#include <iostream>
using namespace std;
#include <string>

class Sach
{
protected:
	string MaSach, TenSach, TacGia, NhaXuatBan;
	float GiaSach;
	int ID; // Phân biệt 2 loại Sách. 1: Sách Tiếng Việt, 2: Sách Ngoại Văn
public:
	// NHẬP, XUẤT:
	virtual void Input();
	virtual void Output();

	//LẤY RA MÃ SÁCH ĐỂ KIỂM TRA:
	string Getter_MaSach();
	void Setter_MaSach(string);

	//LẤY RA ID ĐỂ PHÂN BIỆT SÁCH:
	int Getter_ID();
	void Setter_ID(int);

	Sach();
	virtual ~Sach();
};

#endif