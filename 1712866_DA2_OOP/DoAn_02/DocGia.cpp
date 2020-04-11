#include "DocGia.h"

DocGia::DocGia()
{
}

DocGia::~DocGia()
{
}

//NHẬP:
void DocGia::Input()
{
	rewind(stdin);
	////Không nhập chỗ này, để nhập trong DanhSachDocGia để kiểm tra trùng.
	//cout << "\nNhap vao CMND: "; getline(cin, CMND);
	cout << "\nNhap vao ten: "; getline(cin, ten);
	cout << "\nNhap vao so tuoi: "; cin >> tuoi;
	cout << "\nNhap vao danh sach SACH: " << endl;
	List_Sach.Input();

	//Nhập vào ngày mượn & ngày tối đa phải trả Sách.
	cout << "\nNhap vao ngay muon Sach: ";
	Ngay_Muon.Input();
	cout << "\nNhap vao ngay tra Sach: ";
	Ngay_Tra.Input();
}

//XUẤT:
void DocGia::Output()
{
	DanhSachSach::Fout << "\n\nCMND: " << CMND;
	DanhSachSach::Fout << "\n\nTen: " << ten;
	DanhSachSach::Fout << "\n\nTuoi: " << tuoi;
	List_Sach.Output();

	DanhSachSach::Fout << "\n\nNgay muon Sach: ";
	Ngay_Muon.Output();
	DanhSachSach::Fout << "\nNgay tra Sach: ";
	Ngay_Tra.Output();
}

string DocGia::Getter_CMND()
{
	return CMND;
}
void DocGia::Setter_CMND(string x)
{
	CMND = x;
}

//KIỂM TRA CÓ QUÁ HẠN TRẢ KHÔNG?
bool DocGia::KiemTraCoQuaHanTraKhong()
{
	int n; // Số ngày mượn Sách, nếu n > 7 Quá Hạn.

	int NgayMuon, ThangMuon, NamMuon; // Lấy ngày tháng năm trả Sách ra:

	NgayMuon = Ngay_Muon.Getter_Ngay();
	ThangMuon = Ngay_Muon.Getter_Thang();
	NamMuon = Ngay_Muon.Getter_Nam();

	int NgayTra, ThangTra, NamTra; // Lấy ngày tháng năm trả Sách ra:

	NgayTra= Ngay_Tra.Getter_Ngay();
	ThangTra = Ngay_Tra.Getter_Thang();
	NamTra = Ngay_Tra.Getter_Nam();

	int MANG_NGAY[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// Xét năm nhuận
	if ((NamTra % 4 == 0 && NamTra % 100 != 0) || NamTra % 400 == 0)
	{
		MANG_NGAY[1] = 29;
	}

	n = (NamTra - NamMuon) * 365; // Tính ra sự chênh lệch năm * 12 * 365 => ngày.

	// Xét sự chênh lệch tháng
	if (ThangTra > ThangMuon)
	{
		n += (ThangTra - ThangMuon) * MANG_NGAY[ThangTra - 1]; // Trừ 1 bởi vì MẢNG bắt đầu từ 0.
	}
	else if (ThangTra < ThangMuon)
	{
		n -= (ThangMuon - ThangTra) * MANG_NGAY[ThangTra - 1];
	}

	// Xét sự chênh lệch ngày
	if (NgayTra > NgayMuon)
	{
		n += NgayTra - NgayMuon; // Trừ 1 bởi vì mảng THÁNG bắt đầu từ 0.
	}
	else if (NgayTra < NgayMuon)
	{
		n--;
		n += MANG_NGAY[ThangTra - 1] - (NgayMuon - NgayTra);
	}

	// Nếu số ngày lớn hơn 7 thì Đọc Giả đã trả quá thời hạn
	if (n > 7)
		return true; // Nếu quá hạn.
	return false; // Không quá hạn.
}

//Tính tiền đọc giả sẽ phải đóng nếu trả muộn.
void DocGia::TinhTienPhatDocGiaPhaiDongNeuTraMuon()
{
	int TongTien = 0;
	TongTien += List_Sach.TinhSoLuongSachNgoaiVan() * 20000;
	TongTien += List_Sach.TinhSoLuongSachTiengViet() * 10000;
	DanhSachSach::Fout << "\n\n\tTIEN PHAT = " << TongTien << " dong!";
}

