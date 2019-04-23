# sistemliOdev
Sistem programlama ödevi [github repository](https://github.com/user12043/sistemliOdev)

Ödev gönderim süresi geçene kadar private repository olarak kalmıştır.
## Yapılan İşler

- Muaz: parametreleri okuyup isleme

### Birleştirme

- Mikail Yusuf: dosya okunacak (objelerde tutulacak)

- İbrahim: ilk bölüm oluşturulacak, gerisine dosya içerikleri

### Parçalama

- Yusuf Taha: ilk bölüm ve dosya içerikleri okunacak (değerler objelere atanacak)

- Nuh: Dosyalar oluşturulacak ve içerikleri yazılacak, izinleri ayarlanacak

  
### Projede Görev Alanlar

- Muaz KARATAŞ B161210039
- Mikail Yusuf KARADENİZ B161210105
- İbrahim KUBALAS B161210370
- Yusuf Taha ÖZTÜRK B151210036
- Nuh YURDUSEVEN B161210018


### Projenin çalışma şekli ve yapılanlar
Proje dökümanda istenen tüm isterleri içermektedir.

Proje makefile ile derlendikten sonra çalıştırılabilir dosya `bin` dizininde oluşur.(tarsau). Arşivlenmesi istenen dosyalar parametre olarak verildikten sonra .sau uzantılı arşiv dosyası oluşturulur. Parametrelerin hangi sırada verileceği parametreIsle.c dosyası içerisinde kontrol edilip kullanıcı için bir yönlendirme yapılmıştır. e.g

        noaahhh@noaahhh-pc sistemliOdev]$ ./bin/tarsau
        usage:
        Compressing
                ./bin/tarsau -b <input_files> -o <output_file>
        Extracting
                ./bin/tarsau -a <archive_file> <output_folder>  


Proje tasarımında modüler bir yapı tercih edilmiştir.

Proje, include dizininde `.h` uzantılı header dosyaları src dizininde `.c` uzantılı kaynak dosyaları, lib içinde `.o` uzantılı obje dosyaları(derlendikten sonra oluşur) ve makefile dan oluşmaktadır. 
`parametreIsle.c`  içerisinde terminalden gelen inputlar kontrol edilir,hata fırlatma yapılır, `-a` veya `-b` parametrelerine göre hangi kodun çalıştırılacağına karar verilir. `main()` metodu içerisinde sadece `parametrIsle()` metodu çağırılır. 

`birlestir.c` içerisinde verilen dosyaların `sys/stat.h` kütüphanesi içerisindeki metodlar (st_size,st_mode) ile boyutları ve izinleri alınıp nesnelerde tutuluyor. dosya boyutlarının kontrolü yapılıyor. Dosyaların binary dosya olup olmadığı kontrol ediliyor(ASCII aralığı kontrol edilerek). Arşiv dosyası oluşturulup `fseek()` ,`fprintf()`, `fwrite()` fonksiyonları kullanılarak arşiv dosyasının birinci bölümü yazılıyor. Ardından ikinci bölüme dosya içerikleri yazılıyor.

`parcala.h` icerisinde tanımlamalar ve arsiv dosyasındaki dosyaların ismi,boyutu,izinleri ve text özellikleri olan bir struct ve bir nesne dizisi tanımlandı. `parcala.c` icerisinde output dosyalarının açılacağı dizin oluşturuluyor. Arşiv dosyasının `.sau` uzantılı olup olmadığı kontrol ediliyor. Arşiv dosyası açılıp birinci bölümde okunan nesne dizisine propertyler atanıyor. İkinci bölüm okunurken birinci bölümden okunan size property si kullanılıyor. Dosyalar açılırken izinleri veriliyor ve içerikleri yazılıyor.
