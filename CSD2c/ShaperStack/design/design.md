#### The chosen focus
Ik heb gekozen voor **pluginFocus**. Plugins maken voor audio workstations is iets wat heel goed aansluit bij wat ik wil doen in het werkveld. Ook wil ik graag een eindresultaat hebben dat ik kan gebruiken in mijn eigen muziek.

#### Design process, proposed effects and reasoning

<img src="/assets/eqs.png"> <br>
<img src="/assets/waveshapers.png">

Ik heb bij mijn design voor deze opdracht veel inspiratie gehaald uit de Advanced Synthesis lessen van Sjef. Veel van de technieken die we krijgen aangeleerd in deze lessen vereisen een ingewikkelde effect chain, waardoor het effect niet toegankelijk is voor muzikanten die zich niet in deze mate willen verdiepen in synthese. Ik wil deze technieken versimpelen door effect chains te bundelen in plugins. <br>
Ik wil voor deze opdracht een techniek versimpelen waarbij je een effect chain maakt met waveshapers en equalizers. In deze effect chain wisselen de equalizers en waveshapers elkaar af. De equalizers gebruik je om specifieke frequenties in de ceiling van de waveshaper te duwen, of juist om te voorkomen dat bepaalde frequenties gaan distorten. <br>
Doordat dit meerdere keren achter elkaar gebeurt gaan de harmonische die eerder in de effect chain zijn ontstaan opnieuw distorten en weer nieuwe harmonische creëren. Dit resulteert in een interessante textuur die met name heel geschikt is voor bass design. <br>
Ook wil ik een extra feedback delay toevoegen aan de effect chain die de input meerdere keren door de effect chain heen laat gaan. Ik verwacht dat dit een interessant resultaat geeft.

Ik ga gebruik maken van drie **asymmetrische waveshapers**, drie **biquad filters** en een **feedback delay**.

#### Mapping

<img src="/assets/mapping.png"> <br>

Rood = equalizer 1 dry/wet $`y=x`$

Oranje = equalizer 2 dry/wet $`y=\frac{4^x-1}{3}`$

Geel = equalizer 3 dry/wet $`y=\frac{20^x-1}{19}`$

Groen = Feedback-delay dry/wet
  $`\begin{multline} &&y=\frac{10^{3x}-1}{10^3-1}\end{multline}`$

Ik heb deze mapping gekozen omdat ik een minder lineair verloop wil in het effect. Ik wil het boosten van specifieke frequenties op een enigszins onverwachte manier laten gebeuren. Ik wil de feedback delay pas op het einde infaden. Ik verwacht dat dit het gevoel zal geven dat het systeem op springen staat, of dat er wat gevaarlijks dreigt te gebeuren.
