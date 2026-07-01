<!-- reflection logbook

- Kies volgende keer alleen Nederlands alleen Engels, het wordt verwarrend doordat het steeds door elkaar is.
- De beschrijvingen zijn eigenlijk te uitgebreid. Het kan veel concreter. Misschien een klein stukje nadat je hebt gecommit. Dat is echt genoeg
- Het werkt nice om voor dat je begint een stukje te schrijven over wat je wilt gaan doen. Echter, je hebt hier alleen wat aan als je die dingen ook daadwerkelijk gaat doen.

________________________________26/02/26________________________________

-->

**20-2-26 ___ start: 13:30 ___ stop: 15:46**
Working on making an environment for myself and developing a workflow. For me this starts with having a clear and readable design document. Today I also learned LaTeX and math notation in markdown. I also figured out how to add images to markdown files. From now on I will try to keep track of my progress and time investment. 
2h 16m

**20-2-26 ___ start: 15:50 ___ stop: 18:45**
I first intended to finish the filters I started working on during the lesson with Daan. Instead I converted the 'sources.txt' file I used in semester CSD2b to markdown format and renamed it to syntax_reference. I don't expect to remember everything I look up. And I know C++ can be very confusing and specific. This way I, if i repeatedly forget how to do certain things, I can write it down and easily find it back using \[cmd + f]. 
4h 55m

**21-2-26 ___ start: 18:00 ___ stop:**  **22:00**
I decided to delve deeper into circular buffers. I read the wikipedia page and skimmed through a few sections in *(Pirkle, 2021)*[^1]. **(Ik ga vanaf nu verder in het Nederlands)** Echter, ik kon op deze plekken niet helemaal de informatie vinden waar ik naar op zoek was. Ik bekeek het andere boek van Pirkle dat ons werd aangeraden *(Pirkle, 2019)*[^2] De informatie die ik hier vond heb ik verwerkt voor mezelf in een markdown file. Ik probeer voor mezelf een soort knowledge tree te maken waardoor eerder opgedane informatie heel toegankelijk is voor mezelf. Op dezelfde manier hoe ik een syntax reference voor mezelf probeer te maken. Misschien dat ik dit document met wiskunde en DSP dingen uiteindelijk ook op mijn git zet. Ik kan me voorstellen dan andere CSD'ers hier ook baat bij hebben.
4h

**25-2-26 ___ start: 17:17 ___ stop: 21:30 ___ break: 1 hour**
Today I want to finish my study on circular buffers and start working on making diagrams for the various effects I want to incorporate in my design. I want to continue reading Pirkle's book. Also I want to see if I can wrap the circular buffer with pointer arithmetic which would be way more efficient. 
I didn't manage to start working on the diagrams. I did finish reading the code for the circular buffer. I reviewed the codebase of codeclinic 01 and retyped it to new files. This really helped me understand what was happening in the code. I still can't compile the code because of errors in the CMake files. I think this is happening because I opted for not using the csd_lib. Instead I want to have all the .cpp and header files stored locally in the project directory so that I can make changes to these files if I want to. 
3h 13m 

**26-2-26 ___ start: 14:45 ___ stop: 20:30 ___ break: 3 hour**
Ik wil vandaag uitzoeken hoe ik dingen kan plotten met het python script aanwezig in de csd_lib. Ik ben ook begonnen met een test project waarin ik pointer arithmetic gebruik om de write head en read head te bewegen door de buffer. 
3h 45m

**27-2-26 ___ start: 16:30 ___ stop: 18:30**
Vandaag wil ik focussen op interpolatie, en deze interpolatie algoritmes verwerken in code. Dit is de opdracht die hoort bij de tweede codeclinic. Misschien wil ik bij het maken van de eindopdracht de circular buffer nog een keer opnieuw bekijken om de diehard en die-diehard opdrachten te maken.
2h

**3-3-26 ___ start: 17:05 ___ stop: 20:00**
Ik ga vandaag werken aan de interpolatie algoritmes. 
Ik heb uiteindelijk een goede omgeving gemaakt voor mij om de algoritmes in te testen. Het schrijven van de algoritmes komt een volgende keer.
2h 55m

**5-3-26 ___ start: 19:00 ___ stop: 19:30**
Ik wil vandaag de interpolatie algoritmes afmaken, en misschien wat lezen over bicubic interpolation. 
Dit is uiteindelijk niet gelukt, ik heb wel al wat bugs kunnen halen uit de code. Gewoon door hoe dingen liepen ben ik uiteindelijk niet zo veel toegekomen aan veel coderen.
30m

**6-3-26 ___ start: 11:20 ___ stop: 14:10 ___ break: 0.5 hour**
Ik wil vandaag oppikken waar ik gisteren was gestopt. Dus het test systeem verder maken (misschien zelf het plotten uitvogelen? of het gewoon in de terminal doen, moet dat nog even beslissen). Ik zit ook na te denken over hoe ik het moet aanpakken als ik iets wil interpoleren wanneer het niet een verdubbeling is. Bijvoorbeeld ik heb 5 punten, en ik wil er 7 punten van maken. Op welke plekken voeg ik een sample toe aan de buffer? moet ik dit zo gelijk mogelijk verdelen? is dat dan??
- Difference = 7-5 = 2, 
- values_between = 5/difference = 2,5 -> round down (int)2,5 -> 2
**Result:** Ik ben uiteindelijk een heel eind gekomen. Maar de buffer was niet op de goede volgorde, dus er ging duidelijk nog iets mis. Volgende keer zal ik het afmaken.
2h 20m

**9-3-26 ___ start: 16:00 ___ stop: 17:00**
Ik ga vandaag aan de slag met de interpolatie algoritmes afmaken. Ik ben erachter dat inline functies niet out of line definitions kunnen hebben. Ik ben benieuwd of dit ook geld voor template functies. Ik wil ook een beetje verder werken aan de envelope test. Ik realiseer me dat het voor mij ook bestwel chill is om cmake helemaal uit te vogelen zodat ik weet wat ik aan het doen ben, maar dat komt vanzelf wel een keer. Voor nu  is dat out of scope. Uiteindelijk is het niet gelukt om de interpolatie algoritmes op een goede manier te kunnen testen. Ik zou ook graag nog een cubic interpolatie algoritme hebben, en dit begrijpen. maar voor nu is dat ook out of scope. Doordat het nu een behoorlijke time-crunch is zal ik genoegen moeten nemen met me niet verdiepen in deze dingen
1h

**8-4-26 ___ start: 23:36 ___ stop: 01:56**
Ik heb een lange pauze moeten nemen van werken aan csd. Ik zat in een erg stressvolle verhuizing en ik moest heel erg hard werken aan wiskunde om te zorgen dat ik bij was met de stof. Het wiskunde tentamen is gelukt. En alle ellende rond het verhuizen lijkt nu een beetje voorbij te zijn. Er was alleen ook een eindopdracht van psychoakoestiek die ik moest inhalen en ook het tentamen van Psychoakoestiek dat ik aanstaande vrijdag moet doen. Het lijkt nu behoorlijk onrealistisch dat ik de deadline ga halen. maar ik weet ook dat ik vorig blok al heel wat kennis heb opgedaan en dat het schrijven van de code me wellicht niet heel zwaar valt als ik een paar aanpassingen doe aan mijn werkwijze. Dit zijn de aanpassingen:
- Ik ga me niet verdiepen in syntax die ik nog niet weten. Ik wil werken met de kennis die ik al heb, of kennis die ik gemakkelijk kan vinden.
- Ik hoef niet alles te doorgronden, het is voor nu het belangrijkst dat ik een werkend programma heb. Het is okay als het in elkaar gehackt is en als ik gebruik maak van de code van andere mensen.
- Ik ga opnieuw dit blok voor het minimum viable product. Een design dat goed staat is belangrijk. Eerst de onderdelen schrijven, testen, en wanneer ze werken door gaan naar het volgende onderdeel.
Ik heb helaas uiteindelijk niet zo heel veel kunnen doen. Ik wilde blokdiagrammen opzoeken in het csound boek, maar ik kon het toen niet meteen vinden en ik heb wat stappen ondernomen om het boek wel te kunnen bekijken.
2h 20m

**11-4-26 ___ start: 16:09 ___ stop: 22:00**
Ik wil vandaag verder gaan bij waar ik gebleven was. Ik moet de circulaire buffer wat aanpassen zodat k niet werk met pointers om de waardes van de read en write heads uit te lezen maar met floating point index achtige dingen die ik vervolgens kan gebruiken om ook te interpoleren tussen de waardes in de buffer. (dit is handig voor de delay-tijd aanpassen in een delay effect).
Helaas heb ik uiteindelijk weer niet zo veel kunnen doen. Ik moest me weer flink inlezen en wat dingen ophalen. Ik heb ook een tijd pirkle gelezen. 
5h 51m

**12-4-26 ___ start: 12:30 ___ stop: 15:00**
Ik kon vandaag wat vroeger beginnen. Ik ging aan de slag met de blokdiagrammen van de effecten verzamelen. Ik heb een diagram gevonden voor een delay met feedback en voor een biquad filter. Ik heb nog niet een blokdiagram kunnen vinden voor een waveshaper, maar volgens mij is dit niet heel ingewikkeld om te maken. *Ik ga hier later vandaag naar kijken.* 
De circulaire buffer updaten zodat ik interleaving kan gebruiken is waarschijnlijk een goed idee.
2h 30m

**12-4-26 ___ start: 16:30 ___ stop: 19:00**
Ik ga nu interpolatie toevoegen aan de circulaire buffer.
Dit is gelukt! nu alleen nog een systeem waarmee je met floating point numbers door de buffers heen kan stappen zodat het resizen van de delay-size werkt en klopt enzo.
2h 30m

**13-4-26 ___ start: 12:00 ___ stop: 14:32 ___ break: 0.5 hour**
Ik ga vandaag aan de slag met het laatste stapje van de interpolatie en circulaire buffer.
Ik wil daarna beginnen aan het maken van een waveshaper. Eventueel later op de dag de biquad.
Ik heb deze dingen nog niet gedaan, in plaats daar van heb ik een blokdiagram gemaakt voor een asymmetrische waveshaper. Ik heb hierbij ook een grafiek gemaakt en uitgezocht hoe ik een soort s-curve kon maken met een formule. 
2h 2m

**13-4-26 ___ start: 15:30 ___ stop: 16:45**
I will finish the iterating through buffer part of the test code, after this I will start working on interleaving for stereo support in my plugin. 
I finished the thing!!
1h 15m

13-4-26 ___ start: 17:15 ___ stop: ??
Ik ga beginnen met interleaving support toevoegen aan de circulaire buffer en interpolatie. 
NVM ik heb besloten dat het gewoon prima is om geen interleaving te gebruiken. Komt later wel ooit een keer. Ik ga nu eerst beginnen met het maken van een biquad filter.

___ Ik heb afgelopen 2 maanden niet goed mijn uren bijgehouden. ___
**Dit is wat ik heb gedaan:** 
Ik heb een werkende biquad filter. Niet in de meest efficiënte vorm maar dat is okay. Ik heb een waveshaper werkend en ik heb een envelope class gemaakt zodat ik de feedback delay kan testen in de omgeving die ik voor mezelf heb gemaakt. 
±5h

**08-6-26 ___ start: 12:32 ___ stop: 17:58**
Ik wil zelf een feedback delay schrijven die code van een circulaire buffer gebruikt.
Dit is gelukt. ik heb het zo geïmplementeerd dat de feedback delay een has a relationship heeft met de circulaire buffer. 
De volgende stap wat de code betreft is het maken van de effect chain, het linken aan de parameter. 
Daarna hoef ik alleen de leerdoelen beter te formuleren een reflectie te schrijven een presentatie video te maken en het design the updaten. 
5h 26m

**11-6-26 ___ start: ?? ___ stop: 3:30**
Ik ben aan de slag gegaan waar ik vorige keer was gestopt. Ik had wat problemen met de cmakelist, maar ik had aardig snel door wat daar het probleem was. het is me gelukt om een waveshaper 
2h 30m

Bij de volgende dagen heb ik alleen mijn uren bijgehouden

12-6-26
3h 45m

13-6-26
4h 14m

14-6-25
6h 33m

15-6-26
7h 18m

18-6-26
41m

28-6-26
5h 39 m

29-6-26
5h

30-6-26
5h 45m

1-7-26 
final day, working on overall class diagram and presentation video
4h 47m


[^1]: Pirkle, W.C. (2021). _Designing Software Synthesizer Plugins in C++_. 2nd ed. New York, NY: Routledge.

[^2]: Pirkle, W.C. (2019). Designing audio effect plugins in C++ : for AAX, AU, and VST3 with DSP theory / Will C. Pirkle. 2nd ed. New York, Ny: Routledge.
