
#ifndef __NGOAIVAN_H__
#define __NGOAIVAN_H__

#pragma once
#include "Sach.h"

class NgoaiVan : public Sach
{
private:
	string ISBN;
public:
	NgoaiVan();
	~NgoaiVan();
	// NHẬP, XUẤT:
	void Input();
	void Output();
};

#endif