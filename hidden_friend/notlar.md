#### hidden friends

+ Sınıf nesneleri üstünde işlem yapacak bir fonksiyonun sınıfın içinde _friend_ anahtar sözcüğü ile namespace kapsamında (namespace scope) tanımlanması.
+ Özellikle operator fonksiyonları için tercih ediliyor.
+ Bu durumda fonksiyon ismi _ADL_ ile bulunuyor. Böylece bu fonksiyonları _ADL_ dışında çağırmak mükün olmadığında bu fonksiyonlar gizlenmiş oluyor. 
+ Hata mesajları daha kısa oluyor. Verilen örneklere bakınız. 
+ Derleme süresi kısalıyor.
+ _hidden friend_'ler ile _customization point_ oluşturuluyor. (Derste anlatıyorum)
+ İstenmeyen örtülü tür dönüşümleri engellenmiş oluyor. (Örneğe bakınız)

Derste ayrıntılı olarak anlatıyorum.

okumakta fayda olan bağlantılar:

https://www.justsoftwaresolutions.co.uk/cplusplus/hidden-friends.html


