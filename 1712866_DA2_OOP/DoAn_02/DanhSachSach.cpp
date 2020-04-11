#include "DanhSachSach.h"

//STATIC:
ofstream DanhSachSach::Fout;

DanhSachSach::DanhSachSach()
{
}

DanhSachSach::~DanhSachSach()
{
}

//NHẬP:
void DanhSachSach::Input()
{
	int LuaChon;
	Sach *x;

	do {
		cout << "\n------------------MENU-------------------\n";
		cout << "\n1.Nhap vao thong tin Sach Tieng Viet";
		cout << "\n2.Nhap vao thong tin Sach Ngoai Van";
		cout << "\n0.Ket thuc!";
		cout << "\n-----------------------------------------\n";

		do {
			cout << "\nNhap vao lua chon cua ban: "; cin >> LuaChon;

			if (LuaChon < 0 || LuaChon > 2)
			{
				cout << "\nLua chon cua ban khong hop le. Vui long kiem tra lai!";
			}
			
		} while (LuaChon < 0 || LuaChon > 2);

		if (LuaChon == 1)
		{
			x = new TiengViet;
		}
		else if (LuaChon == 2)
		{
			x = new NgoaiVan;
		}

		//Kiểm tra Mã Sách có trùng không?
		if (LuaChon != 0)
		{
			bool check;
			string MA_SACH;
			do {
				check = true;

				rewind(stdin);
				cout << "\nNhap vao Ma Sach: "; getline(cin, MA_SACH);

				for (int i = 0; i < list.size(); i++)
				{
					if (list[i]->Getter_MaSach() == MA_SACH)
					{
						check = false;
						break;
					}
				}

				if (check == false)
				{
					cout << "\nMa Sach da bi trung. Vui long kiem tra lai!";
				}

			} while (check == false);

			//Nhập tiếp tục nếu Mã Sách không trùng.
			x->Input();
			x->Setter_MaSach(MA_SACH);
			list.push_back(x);

		}

	} while (LuaChon != 0);
}

//XUẤT:
void DanhSachSach::Output()
{
	DanhSachSach::Fout << "\n\n\t**DANH SACH SACH: **";
	int size = list.size();
	int n = 1, m = 1;
	for (int i = 0; i < size; i++)
	{
		if (list[i]->Getter_ID() == 1)
		{
			DanhSachSach::Fout << "\n\nSach Tieng Viet thu " << n++ << ": ";
			list[i]->Output();
		}
		else if (list[i]->Getter_ID() == 2)
		{
			DanhSachSach::Fout << "\n\nSach Ngoai Van thu " << m++ << ": ";
			list[i]->Output();
		}
	}
}

//TÌM KIẾM SÁCH QUA MÃ SÁCH:
Sach* DanhSachSach::TimKiemQuaMaSach(string MaSoSachCanTim)
{
	int size = list.size();
	for (int i = 0; i < size; i++)
	{
		if (list[i]->Getter_MaSach() == MaSoSachCanTim)
			return list[i];
	}
	return NULL;
}
//XÓA SÁCH: (Có nhiều kiểu xóa, nên em không truyền tham số vào.)
void DanhSachSach::XoaSach()
{
	//list.pop_back(); //Xóa phần tử vừa chèn vào.
	//list.erase(list.begin() + 1, list.begin() + 3); //Xóa phần tử từ vị trí 1 đến vị trí 3. (Nghĩa là xóa 1 và 2)
	list.erase(list.begin() + 1); //Xóa phần tử ở vị trí 1.
	//list.clear(); //Xóa tất cả phần tử.
}
//THÊM SÁCH:
void DanhSachSach::ThemSach(int ViTriCanChen)
{
	cout << "\n\n\tNHAP VAO SACH CAN THEM: ";
	int LuaChon;
	Sach *x;
	do {
		cout << "\n---------MENU-----------\n";
		cout << "\n1.Nhap vao sach Tieng Viet";
		cout << "\n2.Nhap vao sach Ngoai Van";
		cout << "\n0.Thoat";
		cout << "\n------------------------\n";

		do {
			cout << "\nNhap vao lua chon cua ban: "; cin >> LuaChon;
			if (LuaChon < 0 || LuaChon > 2)
				cout << "\nLua chon khong hop le. Xin kiem tra lai!";
		} while (LuaChon < 0 || LuaChon > 2);

		if (LuaChon == 1)
		{
			x = new TiengViet;
		}
		else if (LuaChon == 2)
		{
			x = new NgoaiVan;
		}

		//Kiểm tra Mã Sách có trùng không?
		if (LuaChon != 0)
		{
			bool check;
			string Ma_Sach;
			do {
				check = true;

				rewind(stdin);
				cout << "\nNhap vao Ma Sach: "; getline(cin, Ma_Sach);

				for (int i = 0; i < arr.size(); i++)
				{
					if (arr[i]->Getter_MaSach() == Ma_Sach)
					{
						check = false;
						break;
					}
				}

				if (check == false)
				{
					cout << "\nMa Sach da bi trung. Vui long kiem tra lai!";
				}

			} while (check == false);

			//Nhập tiếp tục nếu Mã Sách không trùng.
			x->Input();
			x->Setter_MaSach(Ma_Sach);
			arr.push_back(x);
		}

	} while (LuaChon != 0);

	//CHÈN
	list.insert(list.begin() + ViTriCanChen, arr.begin(), arr.end()); //Chèn các phần tử trong vector arr vào "ViTriCanChen" trong vector list.
}
//SỬA THÔNG TIN SÁCH:
void DanhSachSach::CapNhatThongTinQuaMaSach(string MaSoSachCanSua)
{
	int size = list.size();
	int ViTriCanCapNhat = -1;
	for (int i = 0; i < size; i++)
	{
		if (list[i]->Getter_MaSach() == MaSoSachCanSua)
		{
			ViTriCanCapNhat = i;
			list.erase(list.begin() + i); // Xóa thông tin Sách tại vị trí i.
			ThemSach(ViTriCanCapNhat);
			break;
		}
	}
	if (ViTriCanCapNhat == -1)
		cout << "\nKhong ton tai Ma So Sach can chinh sua!!";
}

//TÍNH SỐ LƯỢNG SÁCH TIẾNG VIỆT:
int DanhSachSach::TinhSoLuongSachTiengViet()
{
	int SoLuong = 0;
	int size = list.size();
	for (int i = 0; i < size; i++)
	{
		if (list[i]->Getter_ID() == 1)
			SoLuong += 1;
	}
	return SoLuong;
}

//TÍNH SỐ LƯỢNG SÁCH NGOẠI VĂN:
int DanhSachSach::TinhSoLuongSachNgoaiVan()
{
	int SoLuong = 0;
	int size = list.size();
	for (int i = 0; i < size; i++)
	{
		if (list[i]->Getter_ID() == 2)
			SoLuong += 1;
	}
	return SoLuong;
}