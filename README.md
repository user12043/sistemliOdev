# sistemliOdev
Sistem programlama ödevi

## Yapılacak İşler

Muaz-> parametreleri okuyup isleme

### BİRLEŞTİRME

(Mikail Yusuf)-> dosya okunacak (objelerde tutulacak)

İbrahim-> ilk bölüm oluşturulacak, gerisine dosya içerikleri

### PARÇALAMA

Yusuf Taha -> ilk bölüm ve dosya içerikleri okunacak (değerler objelere atanacak)

Nuh-> Dosyalar oluşturulacak ve içerikleri yazılacak, izinleri ayarlanacak

  
### Projede Görev Alanlar

-> Muaz KARATAŞ B161210039
-> Mikail Yusuf KARADENİZ B161210105
-> Ibrahim KUBALAŞ B161210370
-> Yusuf Taha ÖZTÜRK B151210036
-> Nuh YURDUSEVEN 161210018


### Projenin çalışma şekli ve yapılanlar

Proje makefile ile derlendikten sonra çalıştırılabilir dosya bin dizininde oluşur(tarsau). Arşivlenmesi istenen dosyalar parametre olarak verildikten sonra .sau uzantılı arşiv dosyası oluşturulur. Parametrelerin hangi sırada verileceği parametreIsle.c dosyası içerisinde kontrol edilip kullanıcı için bir yönlendirme yapılmıştır. e.g

noaahhh@noaahhh-pc sistemliOdev]$ ./bin/tarsau 
usage: 
Compressing
        ./bin/tarsau -b <input_files> -o <output_file>
Extracting
        ./bin/tarsau -a <archive_file> <output_folder>  


Proje tasarımında modüler bir yapı tercih edilmiştir.

Proje, include dizininde .h uzantılı header dosyaları src dizininde .c uzzantılı code dosyaları, lib içinde .o uzantılı obje dosyaları(derlendikten oluşur) ve makefile dan oluşmaktadır. 
parametreIsle.c  içerisinde terminalden gelen inputlar kontrol edilir,hata fırlatma yapılır, '-a' veya '-b' option'larına göre hangi kodun çalıştırılacağına karar verilir. main() metodu içerisinde sadece parametrIsle(..,..) metodu çağırılır. 

birlestir.c içerisinde verilen dosyaların "sys/stat.h" kütüphanesi içerisindeki metodlar(st_size,st_mode) ile boyutları ve izinleri alınıp nesnelerde tutuluyor. dosya boyutlarının kontrolü yapılıyor. Dosyaların binary dosya olup olmadığı kontrol ediliyor.(Ascii aralığı kontrol edilerek(okunan karakter 0'dan küçükse ve 127 den büyükse hata döndür)) Arsiv dosyası oluşturulup fseek() ,fprintf(), fwrite() fonksiyonları kullanılarak arşiv dosyasının birinci bölümü yazılıyor. Ardından ikinci bölüme dosya içerikleri yazılıyor.

parcala.h icerisinde tanımlamalar ve arsiv dosyasındaki dosyaların ismi,boyutu,izinleri ve text öllikleri olan bir struct ve bir nesne dizisi tanımlandı.paracala.c icerisinde output filelarının açılacağı dizin oluşturuluyor. Arşiv dosyasının .sau uzantılı olup olmadığı kontrol ediliyor. Arsiv dosyası acılıp birinci bölüm okunun nesne dizisine property ler atanıyor. ikinci bölüm okunurken birinci bölümden okunan size property si kullnaılıyor. Dosyalar açılırken izinleri veriliyor ve içerikleri yazılıyor.



