# Lampu Otomatis dengan Sensor LDR

Proyek ini akan menyalakan LED secara otomatis ketika cahaya di sekitarnya gelap dan mematikannya saat terang. Kontrol manual juga bisa dilakukan lewat Blynk.

## Kebutuhan Hardware

-   ESP32
-   Sensor LDR (Light Dependent Resistor)
-   Resistor 10kΩ
-   LED
-   Resistor 220Ω
-   Breadboard dan Kabel Jumper

## Koneksi

-   **LDR:**
    -   Satu kaki -> 3V3 ESP32
    -   Kaki lainnya -> Resistor 10kΩ -> GND ESP32
    -   Sambungkan juga kaki yang terhubung ke resistor ke **GPIO 34** ESP32.
-   **LED:**
    -   Kaki `Anode (+)` -> Resistor 220Ω -> **GPIO 2** ESP32
    -   Kaki `Cathode (-)` -> GND ESP32

## Cara Penggunaan

1.  **Setup Software:**
    -   Install library `Blynk` dari Arduino IDE Library Manager.

2.  **Setup Blynk:**
    -   Buat project baru di aplikasi Blynk, pilih device ESP32.
    -   Salin `Auth Token`.
    -   Tambahkan widget:
        -   **Button** (Manual Control) -> Output Pin `V1`, Mode `Switch`

3.  **Upload Kode:**
    -   Buka file `smart_light_ldr.ino`.
    -   Ganti kredensial WiFi dan Blynk Auth Token.
    -   Upload kode ke ESP32.

4.  **Jalankan:**
    -   Secara default, LED akan menyala jika ruangan gelap.
    -   Gunakan tombol di Blynk untuk mengontrol LED secara manual.
