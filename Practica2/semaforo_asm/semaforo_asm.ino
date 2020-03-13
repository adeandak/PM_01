void setup() {
  asm(
    "sbi 0x04, 7 \n\t"
    "sbi 0x04, 6 \n\t"
    "sbi 0x04, 5 \n\t"
    "sbi 0x04, 4 \n\t"
    "sbi 0x04, 3 \n\t"
    "sbi 0x04, 2 \n\t"
  );  
}

void loop() {
  asm (
    "inicio: \n\t"
    "sbi 0x05, 7 \n\t"
    "sbi 0x05, 2 \n\t"

    "call segundo \n\t"
    "call segundo \n\t"
    "call segundo \n\t"
    "call segundo \n\t"
    "call segundo \n\t"
    "call segundo \n\t"

    "cbi 0x05, 2 \n\t"
    "sbi 0x05, 3 \n\t"

    "call segundo \n\t"

    "cbi 0x05, 3 \n\t"
    "cbi 0x05, 7 \n\t"
    "sbi 0x05, 4 \n\t"
    "sbi 0x05, 5 \n\t"

    "call segundo \n\t"
    "call segundo \n\t"
    "call segundo \n\t"
    "call segundo \n\t"
    "call segundo \n\t"

    "cbi 0x05, 5 \n\t"
    "sbi 0x05, 6 \n\t"

    "call segundo \n\t"

    "cbi 0x05, 6 \n\t"
    "cbi 0x05, 4 \n\t"
    
    "jmp inicio \n\t"

    "segundo: \n\t"
    "call mediosegundo \n\t"
    "call mediosegundo \n\t"
    "ret \n\t"
    
    "mediosegundo: \n\t"
    "LDI r22, 40 \n\t"
    "LOOP_3: \n\t" //loop externo cuenta 40 con 11 instrucciones
    "LDI r21, 255 \n\t"
    "LOOP_2: \n\t" //loop intermedio cuenta 255 con 7 instrucciones
    "LDI r20, 255 \n\t"
    "LOOP_1: \n\t" //loop mas interno cuenta 255 con 3 instrucciones
    "DEC r20 \n\t"
    "BRNE LOOP_1 \n\t"
    "DEC r21 \n\t"
    "BRNE LOOP_2 \n\t"
    "DEC r22 \n\t"
    "BRNE LOOP_3 \n\t"
    "ret \n\t"
  );
}
