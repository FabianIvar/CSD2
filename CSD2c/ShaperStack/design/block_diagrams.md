<!--
  Block diagrams for each implemented effect

  - DELAY <-[feedback]-|
  - biquad filter 1    |
  - Waveshaper 1       |
  - biquad filter 2    |
  - Waveshaper 2       |      
  - biquad filter 3    |
  - Waveshaper 3       |
  - DELAY ->-[out]->---|

  Overall block diagram displaying the effect chain together with the mapping of the one overarching parameter into multiple parameters
-->

# Block Diagrams

#### Digital delay line with feedback
<img src="/CSD2c/ShaperStack/design/assets/block_diagrams/ddl_pirkle.png" height="300"> <br>
Pirkle, W.C. (2019). _Designing Audio Effect Plugins in C++_. 2nd ed. Routledge, p.386.
___
#### Asymmetric waveshaper

*work in progress*

___
#### Biquad filter
<img src="/CSD2c/ShaperStack/design/assets/block_diagrams/biquad_pirkle.png" height="300"> <br>
Pirkle, W.C. (2019). _Designing Audio Effect Plugins in C++_. 2nd ed. Routledge, p.249.
___
