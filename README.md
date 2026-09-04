
# prototype Ucapan Ulang Tahun Interaktif 

Proyek ini adalah sebuah purwarupa (prototipe) alat interaktif berbasis mikrokontroler (Arduino/ESP32). Saat alat berada dalam posisi standby, layar akan menampilkan instruksi untuk disentuh. Ketika pengguna menyentuh sensor, alat akan menjalankan serangkaian skenario: memutar animasi, menampilkan teks ucapan ulang tahun diiringi melodi "Happy Birthday", dan diakhiri dengan menampilkan gambar wajah/foto statis.

# 🛠️ Komponen yang Dibutuhkan
- Mikrokontroler (Arduino Uno, Nano, atau ESP32)
- Layar OLED 0.96 inci
- Sensor Sentuh Kapasitif TTP223
- Passive Buzzer
- Kabel Jumper secukupnya

## 🔌 Skema Rangkaian (Wiring)

| Komponen | Pin Komponen | Sambungan ke Arduino | Sambungan ke ESP32 |
| :--- | :--- | :--- | :--- |
| **OLED 0.96"** | VCC | 5V / 3.3V | 3.3V |
| | GND | GND | GND |
| | SCL | 22 | D22 |
| | SDA | 21 | D21 |
| **Sensor TTP223** | VCC | 5V / 3.3V | 3.3V |
| | GND | GND | GND |
| | I/O (SIG) | **Pin 2** | **D1** |
| **Passive Buzzer** | VCC / + | **Pin 8** | **D2** |
| | GND / - | GND | GND |

## 📁 Struktur Proyek (Modular)
Proyek ini menggunakan pendekatan *modular programming* agar kode rapi, mudah dibaca, dan tidak membebani memori RAM mikrokontroler (memanfaatkan `PROGMEM` untuk aset visual).

```text
BirthdayProject/
├── BirthdayProject.ino  # File utama (Main Controller & Logika Sensor)
├── config.h             # Konfigurasi pin dan ukuran layar
├── DisplayUI.h          # Deklarasi fungsi-fungsi visual layar OLED
├── DisplayUI.cpp        # Logika layar & penyimpanan aset Hexadecimal (Animasi & Gambar)
├── sound.h              # Deklarasi fungsi audio/buzzer
└── sound.cpp            # Logika melodi "Happy Birthday"

## Documentation

[Documentation](https://linktodocumentation)

📚 Library yang Digunakan
Pastikan Anda telah menginstal library berikut melalui Library Manager di Arduino IDE sebelum melakukan compile:

Adafruit GFX Library oleh Adafruit

Adafruit SSD1306 oleh Adafruit

🚀 Cara Penggunaan & Kustomisasi
Buka file BirthdayProject.ino menggunakan Arduino IDE.

Jika Anda ingin mengubah aset gambar atau animasi:

Buat gambar hitam-putih (.bmp / .png).

Konversikan gambar menjadi kode Hexadecimal (array C++) menggunakan tools online seperti image2cpp.

Buka file DisplayUI.cpp, lalu paste kode tersebut ke dalam variabel array yang tersedia (misal: frame_00, epd_diraFace).

Penting: Pastikan selalu menggunakan atribut PROGMEM pada array gambar agar disimpan di memori Flash.

Jika ingin mengubah nada/lagu, buka sound.cpp dan sesuaikan array nada[] (frekuensi) dan durasi[] (ketukan delay).

Lakukan Verify / Compile untuk memastikan tidak ada error.

Upload ke papan mikrokontroler Anda.

📝 Catatan Tambahan
Jika layar OLED tidak menyala, periksa kembali alamat I2C pada file config.h. Biasanya alamat default adalah 0x3C, namun beberapa layar menggunakan 0x3D.

Gunakan Passive Buzzer (bukan Active Buzzer) agar fungsi tone() dapat menghasilkan berbagai macam nada (frekuensi) untuk lagu.