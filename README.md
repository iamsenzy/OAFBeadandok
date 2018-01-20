# OAFBeadandok
ELTE Objektum elvű Alkalmazások Fejlesztése Beadandóim

01. beadandóm feladata:

Valósítsa meg az egész számokat tartalmazó zsák típust!
A zsákot dinamikusan lefoglalt tömb segítségével ábrázolja!
Implementálja a szokásos műveleteket (elem betevése, kivétele, üres-e a halmaz, egy elem hányszor van a zsákban), 
valamint két zsák unióját (a közös elemek előfordulása összegződik), 
továbbá egy zsák kiírását, és végül a másoló konstruktort és az értékadás operátort! 
Törekedjen az unióképzés műveletigényének minimalizálására, 
a dokumentációban mutasson rá a saját megoldásának műveletigényére!  

02. beadandóm feladata:

Ábrázoljon egy négyzetes ritka mátrixot láncolt ábrázolással úgy, hogy a mátrix minden nem nulla elemét 
tartalmazó listaelem két láncolt listába is be legyen fűzve: 
a mátrix adott sorát és adott oszlopát reprezentáló listába! 
A sorokat reprezentáló listák az oszlopindexek szerint, az oszlopokat reprezentáló listák sorindex
szerint rendezve tárolják a mátrix elemeket! Valósítsa meg a mátrix adott indexű elemének kiolvasását 
és felülírását elvégző műveletet a zárójel operátorral! 
Készítsen olyan műveletet, amely legfeljebb n*(n-1)/2 lépésben eldönti, hogy a mátrix diagonális-e!
Írja meg a mátrixot kiíró operátor<<-t!  

03. beadandóm feladata:

Szimuláljuk az alábbi egyszerűsített Capitaly társasjátékot! Adott néhány eltérő stratégiájú játékos 
és egy körpálya, amelyen különféle mezők sorakoznak egymás után.
A pályát körbe-körba újra és újra bejárják a játékosok úgy, hogy egy kockával dobva mindig annyit lépnek, 
amennyit a kocka mutat. A mezők három félék lehetnek: ingatlanok, szolgáltatások és szerencse mezők. 
Az ingatlant meg lehet vásárolni 1000 Petákért, majd újra rálépve házat is lehet rá építeni 4000 Petákért. 
Ha ezután más játékos erre a mezőre lép, akkor a mező tulajdonosának fizet: ha még nincs rajta ház, akkor 500 Petákot,
ha van rajta ház, akkor 2000 Petákot. A szolgáltatás mezőre lépve a banknak kell befizetni a mező paramétereként
megadott összeget. A szerencse mezőre lépve a mező paramétereként megadott összegű pénzt kap a játékos. 
Háromféle stratégiájú játékos vesz részt a játékban. Kezdetben mindenki kap egy induló tőkét (10000 Peták),
majd A „mohó” játékos ha egy még gazdátlan ingatlan mezőjére lépett, vagy övé az ingatlan, de még nincs rajta ház, 
továbbá van elég tőkéje, akkor vásárol. Az „óvatos” játékos egy körben csak a tőkéjének a felét vásárolja el,
a „taktikus” játékos minden második vásárlási lehetőséget kihagyja. 
Ha egy játékosnak fizetnie kell, de nincs elégendő pénze, akkor kiesik a játékból,
házai elvesznek, ingatlanjai megvásárolhatókká válnak.

A játék paramétereit egy szövegfájlból olvassuk be. Ez megadja a pálya hosszát, majd a pálya egyes mezőit. 
Minden mezőről megadjuk annak típusát, illetve ha szolgáltatás vagy szerencse mező, akkor annak pénzdíját. 
Ezt követően a fájl megmutatja a játékosok számát, majd sorban minden játékos nevét és stratégiáját.
A tesztelhetőséghez fel kell készíteni a megoldó programot olyan szövegfájl feldolgozására is,
amely előre rögzített módon tartalmazza a kockadobások eredményét.

Írjuk ki, hogy adott számú kör után hogyan állnak (mennyi a tőkéjük, milyen ingatlanokat birtokolnak) a versenyzők!

04. beadandóm feladata:

Egy szöveges állományban számlaszám-befizetés párokat tartalmazó sorokat helyeztünk el. 
(A számlaszám 8 karakter hosszú, utána egy szóköz jön, azt követően pedig egy egész szám.)
Az állomány számlaszám szerint növekedően rendezett. 
Írjuk ki egy szöveges állományba az egyes számlák összesített forgalmát számlaszám-forgalom párokat
tartalmazó sorok formájában! (A kiíratáson kívül csak egyetlenegy üres „else” ágú elágazást használjon!)
