#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct SinhVien {
    int ma_so;
    char ho_va_dem[21];
    char ten[41];
    int ngay_sinh;
    int thang_sinh;
    int nam_sinh;
    char phai[4];
    float diem_tb;
};

void nhap_danh_sach_sinh_vien(SinhVien danh_sach_sv[], int& n, const char* file_input) {
    ifstream file(file_input);
    if (!file) {
        cerr << "Không thể mở file input!" << endl;
        return;
    }
    n = 0;
    while (file >> danh_sach_sv[n].ma_so) {
        file.ignore();
        file.getline(danh_sach_sv[n].ho_va_dem, 21);
        file.getline(danh_sach_sv[n].ten, 41);
        file >> danh_sach_sv[n].ngay_sinh >> danh_sach_sv[n].thang_sinh >> danh_sach_sv[n].nam_sinh;
        file.ignore();
        file.getline(danh_sach_sv[n].phai, 4);
        file >> danh_sach_sv[n].diem_tb;
        n++;
    }
    file.close();
}

void luu_danh_sach_sinh_vien(SinhVien danh_sach_sv[], int n, const char* file_name) {
    ofstream file(file_name, ios::binary);
    file.write(reinterpret_cast<const char*>(danh_sach_sv), n * sizeof(SinhVien));
    file.close();
}

void doc_danh_sach_sinh_vien(SinhVien danh_sach_sv[], int& n, const char* file_name) {
    ifstream file(file_name, ios::binary);
    file.read(reinterpret_cast<char*>(danh_sach_sv), n * sizeof(SinhVien));
    n = file.gcount() / sizeof(SinhVien);
    file.close();
}

void in_danh_sach_sinh_vien(SinhVien danh_sach_sv[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Mã số: " << danh_sach_sv[i].ma_so << ", Họ và đệm: " << danh_sach_sv[i].ho_va_dem << ", Tên: " << danh_sach_sv[i].ten
             << ", Ngày sinh: " << danh_sach_sv[i].ngay_sinh << "/" << danh_sach_sv[i].thang_sinh << "/" << danh_sach_sv[i].nam_sinh
             << ", Phái: " << danh_sach_sv[i].phai << ", Điểm trung bình: " << danh_sach_sv[i].diem_tb << endl;
    }
}

void sap_xep_theo_ma_so(SinhVien danh_sach_sv[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (danh_sach_sv[i].ma_so > danh_sach_sv[j].ma_so) {
                swap(danh_sach_sv[i], danh_sach_sv[j]);
            }
        }
    }
}

void sap_xep_theo_ten(SinhVien danh_sach_sv[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(danh_sach_sv[i].ten, danh_sach_sv[j].ten) > 0 ||
                (strcmp(danh_sach_sv[i].ten, danh_sach_sv[j].ten) == 0 && strcmp(danh_sach_sv[i].ho_va_dem, danh_sach_sv[j].ho_va_dem) > 0)) {
                swap(danh_sach_sv[i], danh_sach_sv[j]);
            }
        }
    }
}

void sap_xep_theo_diem_tb(SinhVien danh_sach_sv[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (danh_sach_sv[i].diem_tb < danh_sach_sv[j].diem_tb) {
                swap(danh_sach_sv[i], danh_sach_sv[j]);
            }
        }
    }
}

void luu_chi_muc(SinhVien danh_sach_sv[], int n, const char* file_name) {
    ofstream file(file_name, ios::binary);
    file.write(reinterpret_cast<const char*>(danh_sach_sv), n * sizeof(SinhVien));
    file.close();
}

int main() {
    const int max_sv = 100;
    SinhVien danh_sach_sv[max_sv];
    int n;

    // Nhập danh sách sinh viên từ file input
    nhap_danh_sach_sinh_vien(danh_sach_sv, n, "input.txt");
    luu_danh_sach_sinh_vien(danh_sach_sv, n, "SINHVIEN.DAT");

    // Sắp xếp theo Mã sinh viên tăng dần và lưu chỉ mục
    sap_xep_theo_ma_so(danh_sach_sv, n);
    luu_chi_muc(danh_sach_sv, n, "SVMASO.IDX");

    // Sắp xếp theo Tên sinh viên từ A → Z và lưu chỉ mục
    sap_xep_theo_ten(danh_sach_sv, n);
    luu_chi_muc(danh_sach_sv, n, "SVTH.IDX");

    // Sắp xếp theo Điểm trung bình giảm dần và lưu chỉ mục
    sap_xep_theo_diem_tb(danh_sach_sv, n);
    luu_chi_muc(danh_sach_sv, n, "SVDTB.IDX");

    // Đọc và in danh sách sinh viên theo từng chỉ mục
    cout << "Danh sách theo Mã sinh viên:" << endl;
    doc_danh_sach_sinh_vien(danh_sach_sv, n, "SVMASO.IDX");
    in_danh_sach_sinh_vien(danh_sach_sv, n);

    cout << "\nDanh sách theo Tên sinh viên:" << endl;
    doc_danh_sach_sinh_vien(danh_sach_sv, n, "SVTH.IDX");
    in_danh_sach_sinh_vien(danh_sach_sv, n);

    cout << "\nDanh sách theo Điểm trung bình:" << endl;
    doc_danh_sach_sinh_vien(danh_sach_sv, n, "SVDTB.IDX");
    in_danh_sach_sinh_vien(danh_sach_sv, n);

    return 0;
}