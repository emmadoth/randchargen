global rdrand32

section .text
rdrand32:
        rdrand eax
        jnc rdrand32
        ret

