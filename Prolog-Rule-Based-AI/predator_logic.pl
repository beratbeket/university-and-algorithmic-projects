saldiri_tahmin(lufer,kopekbaligi_saldirir):- !.
saldiri_tahmin(levrek,kopekbaligi_saldirir):- !.
saldiri_tahmin(hamsi,kopekbaligi_saldirir):- !.
saldiri_tahmin(kopekbaligi,saldirmaz):- !.
saldiri_tahmin(orca,kopekbaligi_kacar):- !.
saldiri_tahmin(yunus,Sonuc):-
    writeln('Karsilasilan yunusun ebadını giriniz (buyuk=2,orta=1,kucuk=0???)'),
    read(Ebatyunus),
    writeln('Kopekbaliginin ebadını giriniz (buyuk=2,orta=1,kucuk=0???)'),
    read(Ebatkopekbaligi),
    karar(Ebatyunus,Ebatkopekbaligi,Sonuc),
    !.
saldiri_tahmin(balina,Sonuc):-
    write('Karsilasilan balinanın yavrusu var mı (evet,hayir)???'),nl,
    read(Yavru),
    yavruya_gore_tahmin(Yavru,Sonuc),
    !.
saldiri_tahmin(_,yanlis_girilen_deger):-
    writeln('Canlı listesi: lufer, levrek, hamsi, yunus, kopekbaligi, orca, balina').

yavruya_gore_tahmin(hayir,saldirmaz).
yavruya_gore_tahmin(evet,Sonuc):-
    write('Kopekbaligi sayisini giriniz'),
    read(Sayi),
    sayiya_gore_tahmin(Sayi,Sonuc).


karar(Ebatyunus,Ebatkopekbaligi,Sonuc):-
    Ebatkopekbaligi>Ebatyunus,
    ebada_gore_tahmin(buyuk,Sonuc).
karar(Ebatyunus,Ebatkopekbaligi,Sonuc):-
    Ebatkopekbaligi=<Ebatyunus,
    ebada_gore_tahmin(buyukdegil,Sonuc).


ebada_gore_tahmin(buyuk,kopekbaligi_saldirir).
ebada_gore_tahmin(buyukdegil,saldirmaz).

sayiya_gore_tahmin(Sayi,kopekbaligi_saldirir):-
    Sayi>1.
sayiya_gore_tahmin(Sayi,saldirmaz):-
    Sayi=<1.
    

basla:-
    repeat,
    write('---BU UYGULAMA BİR DÖNGÜYLE ÇALIŞMAKTADIR. SORGUYA DEVAM İÇİN BİR SAYI, BİTİRMEK İÇİN 0 GİRİNİZ---'),
    read(X),
    (   X=0->  !,write('---ÇIKIŞ YAPTINIZ---')
    ;
    writeln('Karsilasilan Canli Nedir?'),
    read(Canli),
    saldiri_tahmin(Canli,Sonuc),
    write(Sonuc),nl,
    fail).