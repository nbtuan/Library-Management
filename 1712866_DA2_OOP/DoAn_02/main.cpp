//#include "DanhSachSach.h"
//#include "DocGia.h"
#include "DanhSachDocGia.h"

int main()
{
	//=========================================================== CÂU 1 =================================================================//

	//DanhSachSach x;
	//x.Input();

	//DanhSachSach::Fout.open("output.txt", ios_base::out);

	//x.Output();

	////***TÌM KIẾM QUA MÃ SỐ SÁCH:

	//string MaSoCanTim;
	//rewind(stdin);
	//cout << "\nNhap vao Ma So Can Tim: "; getline(cin, MaSoCanTim);

	//Sach *z = new Sach;
	//z = x.TimKiemQuaMaSach(MaSoCanTim);
	//if (z == NULL)
	//	DanhSachSach::Fout << "\n\n\tKhong ton tai Ma So can tim!";
	//else
	//{
	//	DanhSachSach::Fout << "\n\n\tTim thay Ma So can tim!";
	//}

	////***XÓA SÁCH:

	//x.XoaSach();
	//x.Output();

	////***THÊM SÁCH:

	//x.ThemSach(1);
	//x.Output();

	////***SỬA THÔNG TIN SÁCH QUA MA SACH: 

	//rewind(stdin);
	//string MA_SO; cout << "\nNhap vao Ma So sach can chinh sua: "; getline(cin, MA_SO);
	//x.CapNhatThongTinQuaMaSach(MA_SO);
	//x.Output();

	//=================================================================================================================================//



	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CÂU 2 + 3 + 4 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	DanhSachSach::Fout.open("output.txt", ios_base::out);
	
	DanhSachDocGia x;
	x.Input();
	//LIỆT KÊ ĐỌC GIẢ MƯỢN SÁCH QUÁ HẠN & TIỀN PHẠT
	x.LietKeDocGiaMuonSachQuaHan();
	//x.Output();

	////========== TÌM KIẾM THÔNG QUA CMND:

	//string cmnd;
	//rewind(stdin);
	//cout << "\nNhap vao cmnd can tim: "; getline(cin, cmnd);
	//
	//DocGia *find = x.TimKiemQuaCMND(cmnd);
	//if (find == NULL)
	//	DanhSachSach::Fout << "\nKhong ton tai CMND can tim!";
	//else
	//{
	//	DanhSachSach::Fout << "\nTim thay thong tin CMND Doc Gia can tim!";
	//	DanhSachSach::Fout << "\nThong tin cua Doc Gia co CMND can tim: ";
	//	find->Output();
	//}

	////========== XÓA:
	//x.XoaDocGia();
	//x.Output();

	////========== THÊM:
	//int ViTriThem; cout << "\nNhap vao vi tri them: "; cin >> ViTriThem;
	//x.ThemDocGia(ViTriThem);
	//x.Output();

	////========== SỬA:
	//rewind(stdin);
	//string cmnd; cout << "\nNhap vao CMND can chinh sua: "; getline(cin, cmnd);
	//x.CapNhatThongTinDocGiaQuaCMND(cmnd);
	//x.Output();




	DanhSachSach::Fout.close();

	return 0;
}