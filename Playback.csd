<CsoundSynthesizer>
<CsInstruments>
instr testing
 a1 oscili 10000, p5, 1
 k1 linen 1, .2, p3, .1
 out a1 * k1
endin
</CsInstruments>
<CsScore>
f 1  0 8192 10   1 ; GEN10 to compute a sine wave
i "testing" 0 .2 0 987.770020
e 0.3
</CsScore>
</CsoundSynthesizer>
