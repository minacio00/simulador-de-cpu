#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

char mem[154], ir = 0, ro0 = 0, ro1=0, e=0 , l=0, g=0;
int mbr = 0;
short int mar = 0, imm = 0, pc = 0, reg[4] = {0,0,0,0};


int add(){//instru add
    printf("cheguei aqui");
    ro0 = (mbr>>17)&0x00000003;
    ro1 = (mbr>>15)&0x00000003;
    printf("\n %x %x",ro0,ro1);
    printf("\n %0x",mbr);
    printf("\n %x",mbr>>17);
    printf("\n %x",mbr>>15);
    getchar();
    getchar();
    return 0; 
}
int decode();
int printMem(){// mostra toda a memoria em hexadecimal
 for(int i=0; i<154;i++){
        printf("\n endreco: %X  conteudo: %02x",
        i, mem[i]&0xff);
    }
    // printf("decimal: %x",mem[1]);
    return 0;
} 
void printReg(){
    printf(
        "\nir: %x ro0:%x ro1:%x e: %x l: %x g: %x  mbr: %06x \n",
        ir, ro0, ro1,e,l,g,mbr);
    printf("mar: %x imm: %x pc: %x r0: %x r1: %x r2: %x r3: %x \n",mar, imm, pc, reg[0],reg[1],reg[2],reg[3]);
}
int memEdit(){ // preenche os valores na memoria

    int adress = 0, content = 0; // int pq f01 são 3 digitos :(
    printf(
        "insira em hexadecimal o endereco de memoria e o contúdo: \n"   
    );
    do{
        // f01 f01 finaliza o laço
       scanf("%x %x",&adress,&content);

    //   printf("%x",content);
       if (adress == 0xf01 && content == 0xf01 ){
         break;
       }
        mem[adress] = abs(content);
    } while (adress != 0Xf01 && content != 0xF01);
    printf("\nedicao de memoria finalizada");
    getchar();
    getchar();
    return 0;
}   

int findOpcode(int opcode){
     int mask;
    switch (opcode){ // descobre qual instrução foi lida, carrega o opcode para o ir
    case 0b00001:    // e incrementa o pc de acordo com o tamanho da instruição;
        mask =0x000000f1; // mascara para add;
        opcode = opcode&mask;
        printf("\n opcode de add \n");
        ir = opcode;
        pc = pc+2;
        add();
        printf("%x",ir);
        break;
    case 0b00000:   
        opcode = opcode&mask;
        printf("\n hlt \n");
        ir = opcode;
        return 1;
        break;
    case 0b00010:
        mask =0x000000f8; // mascara para subtracao;
        opcode = opcode&mask;
        printf("\n opcode de sub \n");
        ir = opcode;
        pc = pc+2;
        break;
    case 0b00011:
        mask;
        printf("\n opcode de mul\n");
        ir = opcode;
        pc = pc+2;
        break;
    case 0b00100:
        printf("\n opcode de div\n");
        ir = opcode;
        pc = pc+2;
        break;
    case 0b00101:
        printf("\n opcode de cmp\n");
        ir = opcode;
        pc = pc+2;
        break;
    case 0b00110:
        printf("\n opcode de movrr \n");
        ir = opcode;
        pc = pc+2;
        break;
    case 0b00111:
        printf("\n opcode de and \n");
        ir = opcode;
        pc = pc+2;
        break;
    case 0b01000:
        printf ("\n opcode de or");
        ir = opcode;
        pc = pc+2;
        break;
    case 0b01001:
        printf("\n xor \n");
        ir = opcode;
        pc = pc+2;
        break;
    case 0b01010:
        printf("\n not \n");
        ir = opcode;
        pc = pc+1;
        break;
    case 0b01011:
        printf("\n je \n");
        ir = opcode;
        pc = pc+3;
        break;
    case 0b01101:
        printf("\n jl \n");
        ir = opcode;
        pc = pc+3;
        break;
    case 0b01100:
        printf("\n jne \n");
        ir = opcode;
        pc = pc+3;
        break;
    case 0b01110:
        printf("\n jle \n");
        ir = opcode;
        pc = pc+3;
        break;
    case 0b01111:
        printf("\n jg \n");
        ir = opcode;
        pc = pc+3;
        break;
    case 0b10000:
        printf("\n jge \n");
        ir = opcode;
        pc = pc+3;
        break;
    case 0b10001:
        printf("\n jmp \n");
        ir = opcode;
        pc = pc+3;
        break;
    case 0b10010:
        mask = 0x0000001f;
        printf("\n ld \n");
        ir = opcode;
        pc = pc+3; // faz o pc ter o endereço do inicio da proxima palavra;
        break;
    case 0b10011:
        printf("\n st \n");
        ir = opcode;
        pc = pc+3;
        break;
    case 0b10100:
        printf("\n movi \n");
        ir = opcode;
         pc = pc+3;
        break;
    case 0b10101:
        printf("\n addi \n");
        ir = opcode;
         pc = pc+3;
        break;
    case 0b10110:
        printf("\n subi \n");
        ir = opcode;
         pc = pc+3;
        break;
    case 0b10111:
        printf("\n muli \n");
        ir = opcode;
         pc = pc+3;
        break;
    case 0b11000:
        printf("\n divi \n");
        ir = opcode;
         pc = pc+3;
        break;
    case 0b11001:
        printf("\n lsh \n");
        ir = opcode;
         pc = pc+3;
        break;
    case 0b11010:
        printf("\n rsh \n");
        ir = opcode;
         pc = pc+3;
        break;    
    default:
        printf("\ni dunno");
        break;
    }
    return 0;
}

int sub(){

}

void busca(){ // busca instrucoes para o mbr
    //pc = 0 no primeiro ciclo; 0,1,2;
    int hltFlag=0;
    // printMem();
    while (!hltFlag){
        printMem();
        printf("\n\n registradores:\n");
        printReg();
        printf("pressione qualquer tecla para continuar");
        getchar();
        getchar();
        mbr = (mem[pc]<<16)|(abs(mem[pc+1]<<8)|abs(mem[pc+2])); // concatena 3 bytes
        mbr = mbr&0x00ffffff; //transforma em 0 os bits sobrando(devido ao fato da variavel ter 32 bits) a esquerda;
        hltFlag = decode();
        if (hltFlag){
        printf("\n fim do programa \n");
    }
    }
}
int decode(){
    int opcode=  0, hltFlag=0; 
        opcode = mbr >>19; //11; //num&mask;
    hltFlag = findOpcode(opcode);
    if (hltFlag)
        return 1;
    else return 0;
}


int main(){
    
     memEdit();
      //printMem();
     busca();
    //   decode();

}