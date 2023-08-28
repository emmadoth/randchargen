global rdrand

section .text
rdrand:
        rdrand eax
        jnc rdrand
        ret

