#include <stdio.h> 
#include <stdlib.h>

char mem[154], ir = 0, ro0 = 0, ro1=0, e=0 , l=0, g=0;
int mbr = 0;
short int mar = 0, imm = 0, pc = 0, reg[4] = {0,0,0,0};


int printMem(){// mostra toda a memoria em hexadecimal
 for(int i=0; i<154;i++){
        printf("\n endreco: %X  conteudo: %02x",
        i, mem[i]&0xff);
    }
    // printf("decimal: %x",mem[1]);
    return 0;
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
    return 0;

}   

int add(){//instru add
    printf("cheguei aqui");
    return 0; 
}
int sub(){

}

void busca(){ // busca instrucoes para o mbr
    //pc = 0 no primeiro ciclo; 0,1,2;
    mbr = (mem[pc]<<16)|(abs(mem[pc+1]<<8)|abs(mem[pc+2])); // concatena 3 bytes
    mbr = mbr&0x00ffffff; //transforma em 0 os bits sobrando a esquerda;
    decode();
    
}
void decode(){
    int opcode=  0;
    // mbr = (mem[0]<<8)|abs(mem[1]); // concatena dois bytes em mbr;
    // mbr = (mem[pc]<<16)|(abs(mem[pc+1]<<8)|abs(mem[pc+2])); // concatena 3 bytes
    // mbr = mbr&0x00ffffff;  
        opcode = mbr >>19; //11; //num&mask;
        printf("\nmem  %x %x %x \n",mem[0],mem[1],mem[2]);
        printf("\n%x \nopcode: %x ",mbr,opcode);
    // deprecated (eu acho)
    //  if(opcode == 0b00001){
    //     int mask =0x000000f1; // mascara para add;
    //     opcode = opcode&mask;
    //     printf("\n opcode de add \n");
    // }
    // if(opcode == 0b00010){
    //     //0001 0000 1000 0000
    //     int mask =0x000000f8; // mascara para subtracao;
    //     opcode = opcode&mask;
    //     printf("\n opcode de sub \n");
    // }
    int mask;
    switch (opcode){ // descobre qual instrução foi lida;
    case 0b00001:
        mask =0x000000f1; // mascara para add;
        opcode = opcode&mask;
        printf("\n opcode de add \n");
        ir = opcode;
        printf("%x",ir);
        break;

    case 0b00010:
        mask =0x000000f8; // mascara para subtracao;
        opcode = opcode&mask;
        printf("\n opcode de sub \n");
        ir = opcode;
        break;
    case 0b00011:
        mask;
        printf("\n opcode de mul\n");
        ir = opcode;
        break;
    case 0b00100:
        printf("\n opcode de div\n");
        ir = opcode;
        break;
    case 0b00110:
        printf("\n opcode de movrr \n");
        ir = opcode;
        break;
    case 0b00111:
        printf("\n opcode de and \n");
        ir = opcode;
        break;
    case 0b01000:
        printf ("\n opcode de or");
        ir = opcode;
        break;
    case 0b01001:
        printf("\n xor \n");
        ir = opcode;
        break;
    case 0b01010:
        printf("\n not \n");
        ir = opcode;
        break;
    case 0b01011:
        printf("\n je \n");
        ir = opcode;
        break;
    case 0b01101:
        printf("\n jl \n");
        ir = opcode;
        break;
    case 0b01110:
        printf("\n jle \n");
        ir = opcode;
        break;
    case 0b01111:
        printf("\n jg \n");
        ir = opcode;
        break;
    case 0b10000:
        printf("\n jge \n");
        ir = opcode;
        break;
    case 0b10001:
        printf("\n jmp \n");
        ir = opcode;
        break;
    case 0b10010:
        mask = 0x0000001f;
        printf("\n ld \n");
        ir = opcode;
        break;
    case 0b10011:
        printf("\n st \n");
        ir = opcode;
        break;
    case 0b10100:
        printf("\n movi \n");
        ir = opcode;
        break;
    case 0b10101:
        printf("\n addi \n");
        ir = opcode;
        break;
    default:
        printf("\ni dunno");
        break;
    }
   // printf(" \n %0x",mem[1]);
}


int main(){
    
     memEdit();
      printMem();
     busca();
      decode();

}