#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

/* Define o struct chamado paciente, onde entram todos os dados */

struct paciente
{
    char nome[50];
    int cpf[11];
    int telefone[10];
    char endereco[60];
    int nascimento[10];
    char email[40];
    int diagnostico[30];
    char comorbidade[30];
};

struct endereco
{
    char rua[40];
    int numero[5];
    char bairro[20];
    char cidade[20];
    char estado[2];
    int cep[12];
};

int ano;
ano = 2021;

struct endereco ender;

struct paciente pac;

void SetColor(int ForgC)
{
     WORD wordcolor;
     HANDLE pacienteHandleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO conscrbufinfo;
     if(GetConsoleScreenBufferInfo(pacienteHandleOutput, &conscrbufinfo))
     {
          wordcolor = (conscrbufinfo.wAttributes & 0xF0) + (ForgC & 0xF0);
          SetConsoleTextAttribute(pacienteHandleOutput, wordcolor);
     }
     return;
}

void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wordColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);

     HANDLE pacienteHandleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

     COORD coordinates = {0, 0};

     DWORD counting;

     CONSOLE_SCREEN_BUFFER_INFO conscrbufinfo;

     SetConsoleTextAttribute(pacienteHandleOutput, wordColor);
     if(GetConsoleScreenBufferInfo(pacienteHandleOutput, &conscrbufinfo))
     {

          FillConsoleOutputCharacter(pacienteHandleOutput, (TCHAR) 32, conscrbufinfo.dwSize.X * conscrbufinfo.dwSize.Y, coordinates, &counting);
          FillConsoleOutputAttribute(pacienteHandleOutput, conscrbufinfo.wAttributes, conscrbufinfo.dwSize.X * conscrbufinfo.dwSize.Y, coordinates, &counting );

          SetConsoleCursorPosition(pacienteHandleOutput, coordinates);
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
void x_and_y_coordinates(int x, int y)
  {
    coordinates.X = x; coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
  }

void Drawing_Rectangle()
 {
    int a, b;
    x_and_y_coordinates(0,0);
    printf("%c",201);
    for(a = 1; a < 78; a++)
      {
        x_and_y_coordinates(a, 0);
        printf("%c",205);
      }
    x_and_y_coordinates(78,0);
    printf("%c",187);
    for(a = 1; a < 25; a++)
       {
        x_and_y_coordinates(78, a);
        if(a == 6)
         {
            printf("%c",185);
         }
    else
          {
            printf("%c",186);
          }
    }
    x_and_y_coordinates(78, 25);
    printf("%c",188);
    for(a = 77; a > 0; a--)
{
        x_and_y_coordinates(a,25);
        if(a == 35)
         {
            printf("%c",202);
         }
    else
        {
            printf("%c",205);
        }
}
    x_and_y_coordinates(0,25);
    printf("%c",200);
    for(a = 24; a > 0; a--)
      {
        x_and_y_coordinates(0,a);
        if(a == 6)
          {
            printf("%c",300);
          }
    else
         {
            printf("%c",186);
         }
      }

    for(a = 1; a < 78; a++)
    {
        x_and_y_coordinates(a,6);
        if(a == 35)
          {
            printf("%c",203);
          }
        else
         {
            printf("%c",205);
         }
    }

    for(a = 7; a < 25; a++)
     {
        x_and_y_coordinates(35,a);
        printf("%c",186);
     }

}

void Reset_Window()
{
    int a,b;

    for(a = 37; a < 78; a++)
    {
        for(b = 7; b < 25; b++)
          {
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
    Setting_Color_And_Background(15,1);
    x_and_y_coordinates(38,8);printf("Cadastro de Pacientes : %s",st);
    Setting_Color_And_Background(17,15);
 }

int configuration_record(char id[])
{

}

void cadastro_paciente()
{
    Reset_Window();
    print_heading("Inserir dados");
    int print = 37;
    FILE *openfile;
    openfile = fopen("record.txt","ab+");
    SetColor(45);

    if(openfile == NULL)

     {
        MessageBox(0,"Erro ao executar arquivo","ERRO!",0);

     }

    else
    {
        fflush(stdin);
        x_and_y_coordinates(print,10);printf("Nome do Paciente: ");gets(pac.nome);
        x_and_y_coordinates(print,11);printf("CPF: ");gets(pac.cpf);
        x_and_y_coordinates(print,12);printf("Telefone: ");gets(pac.telefone);
        x_and_y_coordinates(print,13);printf("Endereco /RUA: ");gets(ender.rua);
        x_and_y_coordinates(print,14);printf("Endereco /NUM: ");gets(ender.numero);
        x_and_y_coordinates(print,15);printf("Endereco /BAIRRO: ");gets(ender.bairro);
        x_and_y_coordinates(print,16);printf("Endereco /CID: ");gets(ender.cidade);
        x_and_y_coordinates(print,17);printf("Endereco /UF: ");gets(ender.estado);
        x_and_y_coordinates(print,18);printf("Endereco /CEP: ");gets(ender.cep);
        x_and_y_coordinates(print,19);printf("Ano de Nascimento: ");gets(pac.nascimento);
        x_and_y_coordinates(print,20);printf("E-email ");gets(pac.email);
        x_and_y_coordinates(print,21);printf("Data do Diagnostico: ");gets(pac.diagnostico);
        x_and_y_coordinates(print,22);printf("Alguma comorbidade? Preencher: ");gets(pac.comorbidade);
        fwrite(&pac, sizeof(pac), 1, openfile);
        x_and_y_coordinates(40,24); printf("Paciente cadastrado com sucesso.");
    }
    SetColor(28);
    fclose(openfile);
    return;
}

void search_paciente()
{
    Reset_Window();
    print_heading("Pesquisa");
    SetColor(45);
    char cpf_paciente[11];
    int isFound = 0;
    x_and_y_coordinates(37,9);printf("CPF a pesquisar: ");fflush(stdin);
    gets(pac.cpf);
    FILE *openfile;
    openfile = fopen("record.txt","rb");

    while(fread(&pac,sizeof(pac),1,openfile) == 1)

    {
        if(strcmp(pac.cpf, pac.cpf) == 0)

        {
            isFound = 1;
            break;
        }
    }
    if(isFound == 1)
    {
        x_and_y_coordinates(37,10);printf("CPF Encontrado");
        x_and_y_coordinates(37,12);printf("Nome: %s",pac.nome);
        x_and_y_coordinates(37,13);printf("CPF: %d",pac.cpf);
        x_and_y_coordinates(37,14);printf("Telefone: %d",pac.telefone);
        x_and_y_coordinates(37,15);printf("Endereco: %s",ender.rua);
        x_and_y_coordinates(37,16);printf("Endereco /NUM: %d", ender.numero);
        x_and_y_coordinates(37,17);printf("Endereco /BAIRRO: %s", ender.bairro);
        x_and_y_coordinates(37,18);printf("Endereco /CID: %s", ender.cidade);
        x_and_y_coordinates(37,19);printf("Endereco /UF: %s", ender.estado);
        x_and_y_coordinates(37,20);printf("Endereco /CEP: %ld", ender.cep);
        x_and_y_coordinates(37,21);printf("Idade: %d",pac.nascimento);
        x_and_y_coordinates(37,22);printf("E-mail : %s",pac.email);
        x_and_y_coordinates(37,23);printf("Data de Diagnostico : %d",pac.diagnostico);
        x_and_y_coordinates(37,24);printf("Comorbidade : %s",pac.comorbidade);
    }

    else

     {
        x_and_y_coordinates(37,12);printf("CPF nao encontrado");
     }

    SetColor(28);
    fclose(openfile);
    return;
}

void modifica_paciente()

{
    Reset_Window();
    print_heading("Atualizar dados - Paciente");
    SetColor(45);
    char cpf[15];
    int isFound = 0, print = 37;
    x_and_y_coordinates(37,10);printf("Digite CPF: ");fflush(stdin);
    gets(pac.cpf);
    FILE *openfile;
    openfile = fopen("record.txt","rb+");

    while(fread(&pac, sizeof(pac),1,openfile) == 1)
        {
        if(strcmp(cpf, pac.cpf) == 0)
           {
            fflush(stdin);
            x_and_y_coordinates(print,10);printf("Nome do Paciente: ");gets(pac.nome);
            x_and_y_coordinates(print,11);printf("CPF: ");gets(pac.cpf);
            x_and_y_coordinates(print,12);printf("Telefone: ");gets(pac.telefone);
            x_and_y_coordinates(print,13);printf("Endereco /RUA: ");gets(ender.rua);
            x_and_y_coordinates(print,14);printf("Endereco /NUM: ");gets(ender.numero);
            x_and_y_coordinates(print,15);printf("Endereco /BAIRRO: ");gets(ender.bairro);
            x_and_y_coordinates(print,16);printf("Endereco /CID: ");gets(ender.cidade);
            x_and_y_coordinates(print,17);printf("Endereco /UF: ");gets(ender.estado);
            x_and_y_coordinates(print,18);printf("Endereco /CEP: ");gets(ender.cep);
            x_and_y_coordinates(print,19);printf("Ano de Nascimento: ");gets(pac.nascimento);
            x_and_y_coordinates(print,20);printf("E-email ");gets(pac.email);
            x_and_y_coordinates(print,21);printf("Data do Diagnostico: ");gets(pac.diagnostico);
            x_and_y_coordinates(print,22);printf("Alguma comorbidade? Preencher: ");gets(pac.comorbidade);

            fseek(openfile,-sizeof(pac), SEEK_CUR);
            fwrite(&pac,sizeof(pac), 1, openfile);
            x_and_y_coordinates(40,22); printf("Dados atualizados com sucesso!");
            isFound = 1;
            break;
           }
        }
    if(!isFound)

    {
        x_and_y_coordinates(print, 12);printf("CPF nao localizado");
    }

    fclose(openfile);
    SetColor(28);
    return;
}


void exporta_pac()
{
    Reset_Window();
    print_heading("Exportar Casos positivos");
    int print = 37;
    FILE *openfile;
    openfile = fopen("casos.txt","ab+");
    SetColor(45);

    if(openfile == NULL)

     {
        MessageBox(0,"Erro ao executar arquivo","ERRO!",0);

     }

    else
    {
        fflush(stdin);

        x_and_y_coordinates(print,14);printf("Idade paciente ");gets(pac.nascimento - ano);
        x_and_y_coordinates(print,15);printf("Alguma comorbidade? Preencher: ");gets(pac.comorbidade);
        fwrite(&pac, sizeof(pac), 1, openfile);

        x_and_y_coordinates(20,26); printf("Arquivo exportado");
    }

    SetColor(28);
    fclose(openfile);
    return;


}

/* janela com opcoes com comando switch */

void main_window()
{
    int option;
    SetColor(28);
    int x = 2;
    while(1)
    {
        x_and_y_coordinates(x,8);printf("Opcao 01 - Cadastrar Paciente");
        x_and_y_coordinates(x,10);printf("Opcao 02 - Pesquisar Paciente");
        x_and_y_coordinates(x,12);printf("Opcao 03 - Modificar Paciente");
        x_and_y_coordinates(x,14);printf("Opcao 04 - Exportar Registros");
        x_and_y_coordinates(x,16);printf("Opcao 05 - Fechar sistema");
        x_and_y_coordinates(x,19);printf("Escolher opcao: ");
        scanf("%d",&option);

        switch(option)
       {
            case 1:
                cadastro_paciente();
                break;

            case 2:
                search_paciente();
                break;

            case 3:
                modifica_paciente();
                break;

            case 4:
                exporta_pac();
                break;

            case 5:
                exit(0);
                break;

            default:
                break;
        }
    }
}

int main()
{
    ClearConsoleToColors(8,15);
    SetConsoleTitle("Cadastro de Pacientes - COVID 19");
    window();
    main_window();
    return 0;
}
