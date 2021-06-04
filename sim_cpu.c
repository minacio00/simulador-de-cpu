#include <stdio.h> 
#include <stdlib.h>

char mem[154], ir, ro0, ro1, e, l, g;
int mbr;
short int mar, imm, pc, reg[4];


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
        mem[adress] = content;
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

void decode(){
    int opcode;
    // mbr = (mem[0]<<8)|abs(mem[1]); // concatena dois bytes em mbr;
         mbr = (mem[0]<<16)|(abs(mem[1]<<8)|abs(mem[2])); // concatena 3 bytes
//     if (mem[0] < 16)
//     { // pensando em mascara para recuperar instrução do mbr
//         //codigo 0    8     8     0
// //               0000 0000 0000 0000 0000 1000 1000 0000
// //                  0 0    0    0     1    8    0   0 
//         int mask =0x000000f1; // mascara para add;
//         opcode = mbr >>11; //num&mask;
//         opcode = opcode&mask; 
//         // printf("\n %0x", mbr);
//     }
        opcode = mbr >>19; //11; //num&mask;
        printf("\n%x",opcode);
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
    switch (opcode) // descobre qual a instrução a ser chamada;
    {
    case 0b00001:
        mask =0x000000f1; // mascara para add;
        opcode = opcode&mask;
        printf("\n opcode de add \n");
        break;
    case 0b00010:
        mask =0x000000f8; // mascara para subtracao;
        opcode = opcode&mask;
        printf("\n opcode de sub \n");
        break;
    
    default:
        break;
    }
   // printf(" \n %0x",mem[1]);
}


int main(){
    // int num;
    // //printf("%d \n",num);
    // scanf("%x",&num);
    // printf("%d",num);
     memEdit();
      printMem();
      decode();
//     int num = 0b00000000000000000000100010000000;
//     int mask =0x000000f1; 
//     num = num >>11; //num&mask;
//     num = num&mask; 
//    printf("%0d",num);
//    if(num == 0b00001)
//     printf("funciona");
//    else printf("nao funciona");
}