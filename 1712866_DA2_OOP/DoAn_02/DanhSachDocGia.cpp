#include "DanhSachDocGia.h"

DanhSachDocGia::DanhSachDocGia()
{
}

DanhSachDocGia::~DanhSachDocGia()
{
}

void DanhSachDocGia::Input()
{
	int n; cout << "\nNhap vao so luong Doc Gia: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap vao thong tin Doc Gia thu " << i + 1 << ": ";
		DocGia x;

		//Kiểm tra CMND có trùng không??
		bool check;
		string CMND;
		do {
			check = true;
			rewind(stdin);
			cout << "\nNhap vao CMND: "; getline(cin, CMND);
			for (int i = 0; i < list_DocGia.size(); i++)
			{
				if (list_DocGia[i].Getter_CMND() == CMND)
				{
					check = false;
					break;
				}
			}
			if (check == false)
				cout << "\nCMND da bi trung. Vui long kiem tra lai!";
		} while (check == false);

		x.Setter_CMND(CMND);
		x.Input();
		list_DocGia.push_back(x);
	}
}
void DanhSachDocGia::Output()
{
	DanhSachSach::Fout << "\n\n\t===================== DANH SACH DOC GIA: =====================\n\n";
	int size = list_DocGia.size();
	for (int i = 0; i < size; i++)
	{
		DanhSachSach::Fout << "\n\n---------- Thong tin DOC GIA thu " << i + 1 << ": ----------";
		list_DocGia[i].Output();
	}
}

//TÌM KIẾM THÔNG QUA CMND:
DocGia* DanhSachDocGia::TimKiemQuaCMND(string cmnd)
{
	int size = list_DocGia.size();
	for (int i = 0; i < size; i++)
	{
		if (list_DocGia[i].Getter_CMND() == cmnd)
			return &list_DocGia[i];
	}
	return NULL;
}

//XÓA ĐỘC GIẢ
void DanhSachDocGia::XoaDocGia()
{
	//list_DocGia.pop_back(); //Xóa phần tử vừa chèn vào.
	//list_DocGia.erase(list_DocGia.begin() + 1, list_DocGia.begin() + 3); //Xóa phần tử từ vị trí 1 đến vị trí 3. (Nghĩa là xóa 1 và 2)
	list_DocGia.erase(list_DocGia.begin() + 1); //Xóa phần tử ở vị trí 1.
	//list_DocGia.clear(); //Xóa tất cả phần tử.
}

//THÊM ĐỘC GIẢ:
void DanhSachDocGia::ThemDocGia(int ViTriThem)
{
	cout << "\n\nNHAP VAO THONG TIN DOC GIA CAN THEM: ";
	int n; cout << "\nNhap vao so luong Doc Gia can them: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap vao thong tin Doc Gia thu " << i + 1 << ": ";
		DocGia x;

		//Kiểm tra CMND có trùng không??
		bool check;
		string CMND;
		do {
			check = true;
			rewind(stdin);
			cout << "\nNhap vao CMND: "; getline(cin, CMND);
			for (int i = 0; i < list_Them.size(); i++)
			{
				if (list_Them[i].Getter_CMND() == CMND)
				{
					check = false;
					break;
				}
			}
			if (check == false)
				cout << "\nCMND da bi trung. Vui long kiem tra lai!";
		} while (check == false);

		x.Setter_CMND(CMND);
		x.Input();
		list_Them.push_back(x);
	}

	//CHÈN
	list_DocGia.insert(list_DocGia.begin() + ViTriThem, list_Them.begin(), list_Them.end()); //Chèn các phần tử trong vector arr vào "ViTriThem" trong vector list.

}

//CẬP NHẬT THÔNG TIN THÔNG QUA CMND:
void DanhSachDocGia::CapNhatThongTinDocGiaQuaCMND(string cmnd)
{
	int size = list_DocGia.size();
	int ViTriCanCapNhat = -1;

	for (int i = 0; i < size; i++)
	{
		if (list_DocGia[i].Getter_CMND() == cmnd)
		{
			ViTriCanCapNhat = i;
			list_DocGia.erase(list_DocGia.begin() + i); // Xóa thông tin Sách tại vị trí i.
			ThemDocGia(ViTriCanCapNhat);
			break;
		}
	}
	if (ViTriCanCapNhat == -1)
		cout << "\nKhong ton tai CMND can tim!";
}

// LIỆT KÊ ĐỌC GIẢ MƯỢN SÁCH QUÁ HẠN VÀ TIỀN PHẠT:
void DanhSachDocGia::LietKeDocGiaMuonSachQuaHan()
{
	int size = list_DocGia.size();
	for (int i = 0; i < size; i++)
	{
		if (list_DocGia[i].KiemTraCoQuaHanTraKhong() == true)
		{
			list_DocGia[i].Output();
			list_DocGia[i].TinhTienPhatDocGiaPhaiDongNeuTraMuon();
		}
	}
}