# Basic RDR4 Tester Qt Projesi

Bu proje, çeşitli temel sistem ayarlarına (parlaklık, ses kontrolü) erişim sağlayan, sistem bilgilerini gösteren ve basit bir müzik çalma özelliği sunan bir **Qt tabanlı GUI uygulamasıdır**. Özellikle Raspberry Pi tabanlı gömülü sistemler veya benzeri Linux ortamları için tasarlanmıştır.

## İçindekiler

  * [Proje Hakkında]
  * [Özellikler]
  * [Gereksinimler]
  * [Derleme ve Kurulum]
  * [Kullanım]
  * [Ekran Görüntüleri]
  * [Katkıda Bulunma]
  * [Lisans]

-----

## Proje Hakkında

Bu proje, kullanıcıların bir grafik arayüzü üzerinden sistemleriyle etkileşim kurmasını sağlayan basit ve işlevsel bir araçtır. Özellikle dokunmatik ekranlı cihazlar gibi minimalist arayüzlere sahip sistemler için uygun olabilir. `amixer`, `aplay`, `ip addr`, `hostname`, `uname`, `uptime` gibi standart Linux komutlarını kullanarak sistemle etkileşim kurar.

## Özellikler

  * **Değer Kaydırıcı**: Ana ekran üzerinde 0-100 arasında bir değeri ayarlayabileceğiniz bir kaydırıcı ve bu değeri artıran/azaltan butonlar.
  * **Parlaklık Kontrolü**: `/sys/class/backlight/backlight/brightness` yolu üzerinden ekran parlaklığını okuma ve ayarlama imkanı sunan ayrı bir diyalog.
  * **Sistem Bilgileri**: Cihazın **IP adresini**, **Hostname'ini**, **Kernel sürümünü** ve **Uptime süresini** gösteren bir bilgi ekranı.
  * **Ses Kontrolü**: `amixer` komutu aracılığıyla "Headphone" çıkışının ses seviyesini ayarlayabilme ve sessizden çıkarabilme özelliği sunan diyalog.
  * **Müzik Çalar**: `/usr/share/sounds/alsa/` dizinindeki `.wav` dosyalarını `aplay` komutunu kullanarak çalabilen basit bir müzik çalar.

## Gereksinimler

Bu projeyi derlemek ve çalıştırmak için aşağıdaki yazılımlara ihtiyacınız vardır:

  * **Qt 5**: Qt Widgets modülü gereklidir.
  * **GCC/G++**: C++ derleyicisi.
  * **Make**: Derleme sistemi.
  * **Linux İşletim Sistemi**: Proje, `amixer`, `aplay`, `ip`, `hostname`, `uname`, `uptime` gibi Linux komutlarına bağımlıdır. Özellikle `/sys/class/backlight/` yolu üzerinden parlaklık kontrolü Linux çekirdeği tarafından sunulan bir özelliktir.

### Çalışma Zamanı Bağımlılıkları (Linux Komutları)

  * `amixer` (alsa-utils paketi içinde bulunur)
  * `aplay` (alsa-utils paketi içinde bulunur)
  * `ip` (iproute2 paketi içinde bulunur)
  * `hostname`
  * `uname`
  * `uptime`

## Derleme ve Kurulum

Projeyi derlemek ve çalıştırmak için aşağıdaki adımları izleyin:

1.  **Gerekli Paketleri Yükleyin (Debian/Ubuntu tabanlı sistemler için örnek):**

    ```bash
    sudo apt update
    sudo apt install qt5-default qtcreator build-essential alsa-utils iproute2
    ```

2.  **Projeyi Klonlayın:**

    ```bash
    git clone https://github.com/ilhanuzunoglu/Basic-RDR4-Tester-Qt-Project.git
    cd Basic-RDR4-Tester-Qt-Project
    ```

3.  **Projeyi Derleyin:**

    ```bash
    qmake
    make
    ```

4.  **Uygulamayı Çalıştırın:**

    ```bash
    ./ilhan_test1
    ```

## Kullanım

Uygulama çalıştırıldığında, ana pencerede bir kaydırıcı ve çeşitli butonlar göreceksiniz:

  * **Değer Kaydırıcı**: Üst kısımdaki kaydırıcıyı kullanarak veya **"Değeri Azalt (-)"** ve **"Değeri Artır (+)"** butonlarıyla merkezi değeri ayarlayabilirsiniz. Bu, ana penceredeki bir örnek değer göstericisidir.
  * **Parlaklık Butonu**: Tıkladığınızda, ekran parlaklığını ayarlayabileceğiniz yeni bir diyalog penceresi açılır.
  * **Cihaz Bilgileri Butonu**: Tıkladığınızda, sisteminizin IP adresi, hostname, kernel sürümü ve uptime gibi bilgilerini gösteren bir tam ekran pencere açılır. "Geri Dön" butonu ile ana ekrana dönebilirsiniz.
  * **Ses Kontrolü Butonu**: Tıkladığınızda, sisteminizin "Headphone" çıkışının ses seviyesini kontrol edebileceğiniz bir diyalog penceresi açılır.
  * **Müzik Çalar Butonu**: Tıkladığınızda, sisteminizdeki `/usr/share/sounds/alsa/` dizininden `.wav` dosyalarını çalabileceğiniz basit bir müzik çalar penceresi açılır.

## Ekran Görüntüleri

------

## Katkıda Bulunma

Geliştirmelere ve katkılara açığız\! Eğer projeye katkıda bulunmak isterseniz:

1.  Projeyi forklayın.
2.  Yeni bir özellik veya hata düzeltme için bir dal oluşturun (`git checkout -b feature/YeniOzellik` veya `bugfix/HataDüzeltme`).
3.  Değişikliklerinizi yapın ve commit edin (`git commit -m 'Yeni özellik: Açıklama'`).
4.  Değişikliklerinizi orijinal depoya push edin (`git push origin feature/YeniOzellik`).
5.  Bir Pull Request (Çekme İsteği) oluşturun.

## Lisans

Bu proje açık kaynaklıdır ve MIT Lisansı altında yayımlanmıştır. Daha fazla bilgi için `LICENSE` dosyasına bakınız.

-----
