#### non-virtual interface

+ Bu idiyom _template method_ tasarım kalıbının özel bir kullanım senaryosu olarak görülebilir.

+ Sınıfın sanal fonksiyonlarını _public_ yapmak yerine _private_ ya da _protected_ yapıyoruz. 
Böylece bu fonksiyonlar sınıfın public arayüzünde yer almıyorlar. 
Eğer taban sınıfın sanal fonksiyonlarının implementasyonu üremiş sınıf kodları tarafından kullanılacak ise bu fonksiyonlar  _protected_ aksi halde _private_ oluyorlar. 
+ Sınıfın public arayüzünde sanal fonksiyon bulunmuyor.

#### neden böyle yapıyoruz?

+ Sınıfın sanal fonksiyonları türemiş sınıflar için aslında bir customization/specialization noktası. 
Dolayısıyla çoğunlukla bu kodlar implementasyona ilişkin. 
Sanal fonksiyonları public yaptığımızda bunları interface ile implementasyon'ı birbirinden ayırmamış oluyoruz.
+ public sanal arayüz bir sınıfın arayüzünde türemiş sınıflara pre-conditions/post_conditions dayatmasını sağlamıyor. 
Çünkü bu fonksiyonlar çağrıldığında türemiş sınıfların override'ları çağrılmış olacak.

+ implementasyondaki bir değişiklik sınıfın _public_ arayüzünde bir değişimi gerektirmiyor. Taban sınıf daha sağlam _(robust)_ oluyor. 
Böylece client kodlarda değişiklik yapılması gerekmiyor.

+ taban sınıf kendi sözleşmesini dayatabiliyor. (preconditions - postconditions)
