ogrenci(berat):- !.
ogrenci(semra):- !.
ogrenci(bektas):- !.
ogrenci(ozlem):- !.
ogrenci(yunus):- !.
ogrenci(_):-
    write('sistemde kayıtlı olmayan bir ogrenci girdiniz'),nl,
    fail,
    !.

devamsizlik_kontrol(Ad,evet,Gecer):-
    write('Öğrencinin Vize Notunu Giriniz'),
    read(Vize),
    write('Öğrencinin Final Notunu Giriniz'),
    read(Final),
    Ort is Final*0.6 + Vize*0.4,
    nota_gore_kontrol(Ad,Vize,Final,Ort,Gecer),
    !.
devamsizlik_kontrol(Ad,hayir,devamsizliktan_kaldi):-
    write('Öğrenci adı: '),
    write(Ad),nl,
    !.
    

nota_gore_kontrol(Ad,Vize,Final,Ort,finalden_kaldi):-
    Final<50,
    write('Öğrenci adı: '),
    write(Ad),nl,
    write('Vize notu: '),
    writeln(Vize),
    write('Final notu: '),
    writeln(Final),
    write('Ağırlıklı ortalama: '),
    writeln(Ort),
    writeln('Devam durumu: evet').
nota_gore_kontrol(Ad,Vize,Final,Ort,ortalamadan_kaldi):-
    Ort<50,
    write('Öğrenci adı: '),
    write(Ad),nl,
    write('Vize notu:'),
    writeln(Vize),
    write('Final notu: '),
    writeln(Final),
    write('Ağırlıklı ortalama: '),
    writeln(Ort),
    writeln('Devam durumu: evet').
nota_gore_kontrol(Ad,Vize,Final,Ort,gecti):-
    Ort>=50,
    Final>=50,
    write('Öğrenci adı: '),
    write(Ad),nl,
    write('Vize notu:'),
    writeln(Vize),
    write('Final notu: '),
    writeln(Final),
    write('Ağırlıklı ortalama: '),
    writeln(Ort),
    writeln('Devam durumu: evet').

basla:-
    repeat,
    write('---BU UYGULAMA BİR DÖNGÜYLE ÇALIŞMAKTADIR. SORGUYA DEVAM İÇİN BİR SAYI, BİTİRMEK İÇİN 0 GİRİNİZ---'),
    read(X),
    (   X=0->  !,write('---ÇIKIŞ YAPTINIZ---')
    ;
    writeln('Öğrencinin adını giriniz'),
    read(Ad),
    ogrenci(Ad),  
    writeln('Bu Öğrenci Devamlı Mı? (evet,hayir)'),
    read(Devamlılık),
    devamsizlik_kontrol(Ad,Devamlılık,Gecer),
    write('Geçme durumu: '),
    write(Gecer),nl,
    fail).