#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

struct paciente
{
    char nome[30];
    int cpf[11];
    int telefone[15];
    char rua[30];
    int numero[4];
    char bairro[15];
    char cidade[20];
    char uf[2];
    int cep[12];
    int nascimento[4];
    char email[30];
    int diagnostico[10];
    char comorbidade[30];
};

struct paciente pac;

void SetColor(int ForgC)
{
     WORD wordcolor;
     HANDLE studentHandleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO conscrbufinfo;
     if(GetConsoleScreenBufferInfo(studentHandleOutput, &conscrbufinfo))
     {
          wordcolor = (conscrbufinfo.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(studentHandleOutput, wordcolor);
     }
     return;
}

void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wordColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);

     HANDLE studentHandleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

     COORD coordinates = {0, 0};

     DWORD counting;

     CONSOLE_SCREEN_BUFFER_INFO conscrbufinfo;

     SetConsoleTextAttribute(studentHandleOutput, wordColor);
     if(GetConsoleScreenBufferInfo(studentHandleOutput, &conscrbufinfo))
     {

          FillConsoleOutputCharacter(studentHandleOutput, (TCHAR) 32, conscrbufinfo.dwSize.X * conscrbufinfo.dwSize.Y, coordinates, &counting);
          FillConsoleOutputAttribute(studentHandleOutput, conscrbufinfo.wAttributes, conscrbufinfo.dwSize.X * conscrbufinfo.dwSize.Y, coordinates, &counting );

          SetConsoleCursorPosition(studentHandleOutput, coordinates);
     }
     return;
}

void Setting_Color_And_Background(int ForgC, int BackC)
{
     WORD wordColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wordColor);
     return;
}

COORD coordinates = {0,0};
void x_and_y_coordinates(int x, int y){
    coordinates.X = x; coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void Drawing_Rectangle(){
    int a, b;
    x_and_y_coordinates(0,0);
    printf("%c",201);
    for(a = 1; a < 78; a++){
        x_and_y_coordinates(a, 0);
        printf("%c",205);
    }
    x_and_y_coordinates(78,0);
    printf("%c",187);
    for(a = 1; a < 25; a++){
        x_and_y_coordinates(78, a);
        if(a == 6){
            printf("%c",185);
        }else{
            printf("%c",186);
        }
    }
    x_and_y_coordinates(78, 25);
    printf("%c",188);
    for(a = 77; a > 0; a--){
        x_and_y_coordinates(a,25);
        if(a == 35){
            printf("%c",202);
        }else{
            printf("%c",205);
        }
    }
    x_and_y_coordinates(0,25);
    printf("%c",200);
    for(a = 24; a > 0; a--){
        x_and_y_coordinates(0,a);
        if(a == 6){
            printf("%c",204);
        }else{
            printf("%c",186);
        }
    }

    for(a = 1; a < 78; a++){
        x_and_y_coordinates(a,6);
        if(a == 35){
            printf("%c",203);
        }else{
            printf("%c",205);
        }
    }

    for(a = 7; a < 25; a++){
        x_and_y_coordinates(35,a);
        printf("%c",186);
    }

}

void Reset_Window(){
    int a,b;
    for(a = 37; a < 78; a++){
        for(b = 7; b < 25; b++){
            x_and_y_coordinates(a,b);printf(" ");
        }
    }
    return;
}

void window()
  {
    Drawing_Rectangle();
    x_and_y_coordinates(16,2);
    SetColor(13);

    printf("Cadastro de Pacientes - COVID 19");
    x_and_y_coordinates(20,3);

    printf("PIM IV - Guilherme Thomas");
    x_and_y_coordinates(31,4);

    printf("UNIP");
    x_and_y_coordinates(22,24);
    SetColor(12);
  }


void print_heading(const char st[])
   {
    Setting_Color_And_Background(31,28);

    x_and_y_coordinates(38,8);printf("Cadastro de Pacientes : %s",st);

    Setting_Color_And_Background(17,15);
  }

int configuration_record(char id[])
{

}

void cadastro_paciente()
{
    Reset_Window();
    print_heading("Cadastrar Paciente: ");

    int print = 37;

    FILE *openfile;
    openfile = fopen("registros.txt","ab+");
    SetColor(45);

    if(openfile == NULL)

      {
        MessageBox(0,"Erro ao abrir arquivo","Erro",0);
      }

    else

      {
        fflush(stdin);
        x_and_y_coordinates(print,10);printf("Nome: ");gets(pac.nome);
        x_and_y_coordinates(print,11);printf("CPF: ");gets(pac.cpf);
        x_and_y_coordinates(print,12);printf("Telefone: ");gets(pac.telefone);
        x_and_y_coordinates(print,13);printf("Endereço *Rua: ");gets(pac.rua);
        x_and_y_coordinates(print,14);printf("Endereço *Num: ");gets(pac.numero);
        x_and_y_coordinates(print,15);printf("Endereço *Bairro: ");gets(pac.bairro);
        x_and_y_coordinates(print,16);printf("Endereço *Cidade: ");gets(pac.cidade);
        x_and_y_coordinates(print,17);printf("Endereço *UF: ");gets(pac.uf);
        x_and_y_coordinates(print,18);printf("Endereço *CEP: ");gets(pac.cep);
        x_and_y_coordinates(print,19);printf("Ano de nascimento: ");gets(pac.nascimento);
        x_and_y_coordinates(print,20);printf("Email: ");gets(pac.email);
        x_and_y_coordinates(print,21);printf("Data de Diagnostico: ");gets(pac.diagnostico);
        x_and_y_coordinates(print,22);printf("Alguma comorbidade? Preencher: ");gets(pac.comorbidade);
        fwrite(&pac, sizeof(pac), 1, openfile);
        x_and_y_coordinates(40,24); printf("Paciente cadastrado.");
    }

    SetColor(28);
    fclose(openfile);

    return;
}


void pesquisa_paciente()

{
    Reset_Window();
    print_heading("Pesquisa");
    SetColor(45);

    char cpf[11];
    int isFound = 0;


    x_and_y_coordinates(37,10);printf("CPF a pesquisar: ");fflush(stdin);
    gets(cpf);

    FILE *openfile;
    openfile = fopen("registros.txt","rb");

    while(fread(&pac,sizeof(pac),1,openfile) == 1)

     {
        if(strcmp(cpf,pac.cpf) == 0)

         {
            isFound = 1;
            break;
         }
     }
    if(isFound == 1)

      {
        x_and_y_coordinates(37,8);printf("Registro encontrado");
        x_and_y_coordinates(37,14);printf("Nome: %s",pac.nome);
        x_and_y_coordinates(37,14);printf("CPF: %o",pac.cpf);
        x_and_y_coordinates(37,14);printf("Telefone: %o",pac.telefone);
        x_and_y_coordinates(37,14);printf("Endereco *Rua: %s",pac.rua);
        x_and_y_coordinates(37,15);printf("Endereco *Cid: %s",pac.cidade);
        x_and_y_coordinates(37,16);printf("Endereco *UF: %s",pac.uf);
        x_and_y_coordinates(37,17);printf("Endereco *CEP: %o" ,pac.cep);
        x_and_y_coordinates(37,18);printf("Idade : %o",pac.nascimento);
        x_and_y_coordinates(37,19);printf("Email: %s",pac.email);
        x_and_y_coordinates(37,20);printf("Data do Diagnostico: %s",pac.diagnostico);
        x_and_y_coordinates(37,21);printf("Comorbidade: %s",pac.comorbidade);

      }

    else

       {
        x_and_y_coordinates(37,12);printf("CPF nao localizado");
       }

    SetColor(28);
    fclose(openfile);
    return;
}

/*
void modify_student()
{
    Reset_Window();
    print_heading("Modify Record");
    SetColor(45);
    char student_id[15];
    int isFound = 0, print = 37;
    x_and_y_coordinates(37,10);printf("Enter ID to Modify: ");fflush(stdin);
    gets(student_id);
    FILE *openfile;
    openfile = fopen("record.txt","rb+");
    while(fread(&stu, sizeof(stu),1,openfile) == 1){
        if(strcmp(student_id, stu.stud_id) == 0){
            fflush(stdin);
            x_and_y_coordinates(print,12);printf("ID: ");gets(stu.stud_id);
            x_and_y_coordinates(print,13);printf("Name: ");gets(stu.stud_name);
            x_and_y_coordinates(print,14);printf("Address: ");gets(stu.stud_address);
            x_and_y_coordinates(print,15);printf("Parent's name: ");gets(stu.stud_parentName);
            x_and_y_coordinates(print,16);printf("Class: ");scanf("%d",&stu.stud_class);
            x_and_y_coordinates(print,17);printf("Contact Number: ");scanf("%ld",&stu.stud_contact_number);
            fseek(openfile,-sizeof(stu), SEEK_CUR);
            fwrite(&stu,sizeof(stu), 1, openfile);
            x_and_y_coordinates(40,22); printf("New Student is Updated Successfully");
            isFound = 1;
            break;
        }
    }
    if(!isFound){
        x_and_y_coordinates(print, 12);printf("No Record Found");
    }
    fclose(openfile);
    SetColor(28);
    return;
}

*/

void main_window()
  {
    int opcao_menu;
    SetColor(28);
    int x = 2;
    while(1)
      {
        x_and_y_coordinates(x,8);printf("1 - Cadastrar Paciente ");
        x_and_y_coordinates(x,10);printf("2 - Pesquisar Paciente ");
        x_and_y_coordinates(x,12);printf("3 - Exportar Registros SecSaude");
        x_and_y_coordinates(x,14);printf("4 - Fechar Sistema");
        x_and_y_coordinates(x,17);printf("Digite sua opcao: ");

        scanf("%d",&opcao_menu);

        switch(opcao_menu)

         {
            case 1:
                cadastro_paciente();
                break;
            case 2:
                pesquisa_paciente();
                break;
            case 3:
                pesquisa_paciente();
                break;
            case 4:
                exit(0);
                break;
            default:
                break;
        }

    }

}

int main()
 {
    ClearConsoleToColors(17,15);
    SetConsoleTitle("Sistema de Cadastro - COVID 19");
    window();
    main_window();
    return 0;
 }

