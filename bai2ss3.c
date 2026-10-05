#include <stdio.h>

int main() {
    int tuoi;
    int ma_phim;
    int ma_ghe;
    int ma_doi_tuong;

    printf("--- HE THONG BAN VE PHIM CGV ---\n");
    printf("Nhap tuoi khang gia: ");
    if (scanf("%d", &tuoi) != 1) return 0;

    printf("Nhap ma loai phim (1-P, 2-T18): ");
    if (scanf("%d", &ma_phim) != 1) return 0;

    printf("Nhap ma loai ghe (1-Thuong, 2-VIP, 3-Couple): ");
    if (scanf("%d", &ma_ghe) != 1) return 0;

    printf("Nhap ma doi tuong (1-Thuong, 2-HS/SV): ");
    if (scanf("%d", &ma_doi_tuong) != 1) return 0;

    if (tuoi <= 0 || (ma_phim != 1 && ma_phim != 2) || (ma_ghe < 1 || ma_ghe > 3) || (ma_doi_tuong != 1 && ma_doi_tuong != 2)) {
        printf("\nLOI: Du lieu nhap vao khong hop le!\n");
        return 0;
    }

    if (ma_phim == 2 && tuoi < 18) {
        printf("\nTU CHOI BAN VE: Khang gia chua du 18 tuoi de xem phim T18!\n");
        return 0;
    }

    double phu_thu_ghe = 0.0;
    switch (ma_ghe) {
        case 1:
            phu_thu_ghe = 0.0;
            break;
        case 2:
            phu_thu_ghe = 15000.0;
            break;
        case 3:
            phu_thu_ghe = 30000.0;
            break;
    }

    double gia_ve_goc = 80000.0;
    double giam_gia = 0.0;
    if (ma_doi_tuong == 2) {
        giam_gia = gia_ve_goc * 0.20;
    } else {
        giam_gia = 0.0;
    }

    double gia_sau_giam = gia_ve_goc - giam_gia;
    double tong_tien = gia_sau_giam + phu_thu_ghe;

    printf("\n--- HOA DON THANH TOAN ---\n");
    printf("Doi tuong: %s\n", (ma_doi_tuong == 2 ? "Hoc sinh / Sinh vien" : "Khach hang thuong"));
    
    char* ten_ghe = "";
    if (ma_ghe == 1) ten_ghe = "Thuong";
    else if (ma_ghe == 2) ten_ghe = "VIP";
    else if (ma_ghe == 3) ten_ghe = "Couple";
    
    printf("Loai ghe: %s\n", ten_ghe);
    printf("Gia ve goc: %.0f VND\n", gia_ve_goc);
    printf("Giam gia uu dai: %.0f VND\n", giam_gia);
    printf("Phu thu ghe: %.0f VND\n", phu_thu_ghe);
    printf("Tong tien