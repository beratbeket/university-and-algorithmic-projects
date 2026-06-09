# Prolog Rule-Based Expert Systems

This repository contains two different rule-based expert systems developed in Prolog. Both systems process user inputs interactively through a decision loop and make logical deductions based on predefined rules.

---

## 🦈 Project 1: Predator Logic Simulator (Shark Behavior Model)

Bir köpekbalığının karşılaştığı deniz canlısına göre nasıl davranacağı Prolog ile modellenmiştir. Sistem, kullanıcıdan karşılaşılan canlıyı almalı ve gerekiyorsa ek sorular sorarak karar vermelidir.

### 📋 Rules (Kurallar)

- **Küçük Balıklar (Lüfer, Levrek, Hamsi):** Köpekbalığı lüfer gibi küçük balıklarla karşılaşırsa sonuç `saldiri` olmalıdır.
- **Yunus (Dolphin):** Yunus ile karşılaşırsa önce yunusun boyutu değerlendirilmelidir. Yunus köpekbalığından küçükse sonuç `saldiri`, değilse `saldirmaz` olmalıdır.
- **Orca:** Orca ile karşılaşırsa sonuç her zaman `kacis` olmalıdır.
- **Balina (Whale):** Balina ile karşılaşırsa sistem önce _‘balina yavrusu mu?’_ diye sormalıdır. Cevap hayır ise sonuç `saldirmaz` olmalıdır. Eğer cevap evet ise sistem bu kez _‘kaç köpekbalığı var?’_ diye sormalıdır. Köpekbalığı sayısı birden fazlaysa sonuç `saldirir`, değilse `saldirmaz` olmalıdır.

### 📊 Decision Tree Diagram / Screenshot

Below is the execution flow or the decision tree diagram for the Shark Behavior Model:

![Shark Behavior Logic Screenshot](./Prolog-Rule-Based-AI/predator.png)

---

## 🎓 Project 2: Student Performance Analyzer (Academic Grading System)

Bir öğrencinin dersten geçip geçmediğini belirleyen Prolog sistemi geliştirilecektir. Sistem kullanıcıdan öğrenci adı, ders adı, vize notu, final notu ve devamsızlık durumunu almalıdır.

### 📋 Rules (Kurallar)

- **Başarı Notu Hesaplama:** Genel başarı notu vizenin %40’ı ve finalin %60’ı alınarak hesaplanmalıdır.
- **Final Barajı:** Final notu 50’nin altındaysa öğrenci `finaldenkaldi` sonucunu almalıdır.
- **Ortalama Barajı:** Ortalama 60’ın altındaysa `ortalamadankaldi` sonucu verilmelidir.
- **Devamsızlık Durumu:** Devamsızlık sınırı aşılmışsa notlara bakılmadan sonuç `devamsizliktankaldi` olmalıdır.
- **Geçme Durumu:** Tüm şartlar sağlanıyorsa sonuç `gecti` olmalıdır.

### 📊 System Output / Screenshot

Below is the terminal output or the execution flow screenshot for the Student Grading System:

![Student Performance Logic Screenshot](./Prolog-Rule-Based-AI/pass_fail.png)
