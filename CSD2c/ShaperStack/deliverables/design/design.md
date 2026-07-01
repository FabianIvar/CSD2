# Overall Design

### The chosen focus
Ik heb gekozen voor **pluginFocus**. Plugins maken voor audio workstations is iets wat heel goed aansluit bij wat ik wil doen in het werkveld. Ook wil ik graag een eindresultaat hebben dat ik kan gebruiken in mijn eigen muziek.

### Design process, proposed effects and reasoning

Ik heb bij mijn design voor deze opdracht veel inspiratie gehaald uit de Advanced Synthesis lessen van Sjef. Veel van de technieken die we krijgen aangeleerd in deze lessen vereisen een ingewikkelde effect chain, waardoor het effect niet toegankelijk is voor muzikanten die zich niet in deze mate willen verdiepen in synthese. Ik wil deze technieken versimpelen door effect chains te bundelen in een plugin. <br> Ik wil voor deze opdracht een techniek versimpelen waarbij je een effect chain maakt met waveshapers en equalizers. In deze chain wisselen de equalizers en waveshapers elkaar af. De equalizers duwen bepaalde frequenties in de ceiling van de waveshapers. <br> Doordat dit meerdere keren achter elkaar gebeurt gaan de harmonics die eerder in de effect chain zijn ontstaan opnieuw distorten en weer nieuwe harmonische creëren. Dit resulteert in een interessante textuur die met name heel geschikt is voor bass design.<br>
<!-- NOTE: waveshapers in afbeelding zijn symmetrisch -->
In mijn multi-effect plugin zitten drie **asymmetrische waveshapers**, drie **biquad filters** en een **feedback delay**.

### Mapping

<img src="/CSD2c/ShaperStack/deliverables/assets/mapping.png" width="400"> <br>

Geel = equalizer 1 dry/wet
- $y=\frac{-10^{-x}+1}{0,9}$
Oranje = equalizer 2 dry/wet
- $y=\frac{-16^{-x+0,25}+1}{0,875}$
Rood = equalizer 3 dry/wet
- $y=\frac{-25^{-x+0,5}+1}{0,8}$
Bruin = Feedback-delay dry/wet
- $y=\frac{10^{5x}-1}{10^{5}-1}$

Verder heb ik een lineaire mapping voor de delay-time van de feedback delay.

Ik heb deze mapping gekozen omdat wilde dat het boosten van de peaks enigszins onverwacht voelt. Ik wil de feedback delay pas op het einde infaden. Ik hoop dat dit een soort 'gevaarlijk' gevoel geeft. Alsof het systeem op instorten staat.
