#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Cadastro {

    char nome[20];
    char sobrenome[60];
    int CPF, RG;
};

struct ReservaQuarto
{

    int diaCheckin;
    int diaCheckout;
};

int main(int argc, char const *argv[])
{


    int i;
    struct ReservaQuarto reserva_qrt[100]; // vetor que vai armazenar as reservas
    struct Cadastro cad;
    int diaCheckin = 0, diaCheckout = 0;
    int op, opcao_hotel, tipo_quarto;
    int num_resv_suite1 = 0; // número de reservas dessa suíte
    int num_resv_suite2 = 0;
    int num_resv_luxo1 = 0;
    int num_resv_luxo2 = 0;
    int num_resv_standart1 = 0;
    int num_resv_standart2 = 0;
    bool quarto_reservado = false;

    printf("***Menu***\n");
    printf("[1]Cadastro do cliente\n"); //Falta colocar a verificação dos dados, perguntar ao cliente se deseja editar algum dado e fazer o relatório com todos os registros.
    printf("[2]Reserva de quartos\n"); //Falta a opção de colocar se deseja fazer outra reserva, validar as informações e fazer o relatório com todos os registros.
    printf("[3]Sistemas de Tarifas\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);

    switch (op)
    {

    case 1:
       
        printf("Você escolheu: Cadastro do Cliente\n");
        printf("Para efetuar o cadastro preencha as seguintes informações: \n");
        printf("Nome:\n");
        scanf("%f", cad.nome);
        fflush(stdin);
        printf("Sobrenome:\n");
        scanf("%f", cad.sobrenome);
        fflush(stdin);
        printf("CPF:\n");
        scanf("%f", cad.CPF);
        printf("RG: \n");
        
       break;

    case 2:
        printf("Você escolheu: Reserva de quartos\n");

        printf("Seleção da rede de hotel desejada\n");
        printf("[1]Rede de Hotel 1\n");
        printf("[2]Rede de Hotel 2\n");
        scanf("%d", &opcao_hotel);

        switch (opcao_hotel)
        {

        case 1:

            printf("Reserva de quartos referente à rede de hotel 1\n");
            printf("Seleção do tipo de quarto desejado\n");
            printf("[1]Suíte\n");
            printf("[2]Quarto de luxo\n");
            printf("[3]Quarto Standart\n");
            printf("Digite o número do tipo de quarto desejado: \n");
            scanf("%d", &tipo_quarto);

            if (tipo_quarto != 1 && tipo_quarto != 2 && tipo_quarto != 3)
            {

                printf("Digite o número do tipo de quarto válido: \n");
                scanf("%d", &tipo_quarto);
                break;
            }

            switch (tipo_quarto)
            {

            case 1:
                
                printf("Digite a data do check-in:\n ");
                scanf("%d", &diaCheckin);
                printf("Digite a data do check-out:\n");
                scanf("%d", &diaCheckout);

                if (diaCheckin <= 0 || diaCheckout <= 0 || diaCheckin > 360 || diaCheckout > 360)
                {
                    printf("As datas de check-in e check-out devem estar entre 1 e 360.\n");
                }

                for (i = 0; i < num_resv_suite1; i++)
                {

                    if (reserva_qrt[i].diaCheckin == diaCheckin && reserva_qrt[i].diaCheckout == diaCheckout)
                    {
                        quarto_reservado = true;
                        break;
                    }
                }

                if (quarto_reservado)
                {
                    printf("O quarto já está ocupado.\n");
                }
                else
                {
                    reserva_qrt[num_resv_suite1].diaCheckin = diaCheckin;
                    reserva_qrt[num_resv_suite1].diaCheckout = diaCheckout;
                    num_resv_suite1++;
                    printf("As datas de check-in e de check-out foram agendadas.\n");
                }
                break;

            case 2:
                printf("Digite a data do check-in:\n ");
                scanf("%d", &diaCheckin);
                printf("Digite a data do check-out:\n");
                scanf("%d", &diaCheckout);

                if (diaCheckin <= 0 || diaCheckout <= 0 || diaCheckin > 360 || diaCheckout > 360)
                {
                    printf("As datas de check-in e check-out devem estar entre 1 e 360.\n");
                }

                for (i = 0; i < num_resv_luxo1; i++)
                {

                    if (reserva_qrt[i].diaCheckin == diaCheckin && reserva_qrt[i].diaCheckout == diaCheckout)
                    {
                        quarto_reservado = true;
                        break;
                    }
                }

                if (quarto_reservado)
                {
                    printf("O quarto já está ocupado.\n");
                }
                else
                {
                    reserva_qrt[num_resv_luxo1].diaCheckin = diaCheckin;
                    reserva_qrt[num_resv_luxo1].diaCheckout = diaCheckout;
                    num_resv_luxo1++;
                    printf("As datas de check-in e de check-out foram agendadas.\n");
                }
                break;

            case 3:
                printf("Digite a data do check-in:\n ");
                scanf("%d", &diaCheckin);
                printf("Digite a data do check-out:\n");
                scanf("%d", &diaCheckout);

                if (diaCheckin <= 0 || diaCheckout <= 0 || diaCheckin > 360 || diaCheckout > 360)
                {
                    printf("As datas de check-in e check-out devem estar entre 1 e 360.\n");
                }

                for (i = 0; i < num_resv_standart1; i++)
                {

                    if (reserva_qrt[i].diaCheckin == diaCheckin && reserva_qrt[i].diaCheckout == diaCheckout)
                    {
                        quarto_reservado = true;
                        break;
                    }
                }

                if (quarto_reservado)
                {
                    printf("O quarto já está ocupado.\n");
                }
                else
                {
                    reserva_qrt[num_resv_standart1].diaCheckin = diaCheckin;
                    reserva_qrt[num_resv_standart1].diaCheckout = diaCheckout;
                    num_resv_standart1++;
                    printf("As datas de check-in e de check-out foram agendadas.\n");
                }
                break;
            }

            break;
        case 2:
            printf("Reserva de quartos referente à rede de hotel 2\n");
            printf("Seleção do tipo de quarto desejado\n");
            printf("[1]Suíte\n");
            printf("[2]Quarto de luxo\n");
            printf("[3]Quarto Standart\n");
            printf("Digite o número do tipo de quarto desejado: \n");
            scanf("%d", &tipo_quarto);

            if (tipo_quarto != 1 && tipo_quarto != 2 && tipo_quarto != 3)
            {
                printf("Digite uma opcao de quarto válida: \n");
                scanf("%d", &tipo_quarto);
            }
            else
            {
                printf("Digite a data do check-in:\n ");
                scanf("%d", &diaCheckin);
                printf("Digite a data do check-out:\n");
                scanf("%d", &diaCheckout);

                if (diaCheckin <= 0 || diaCheckout <= 0 || diaCheckin > 360 || diaCheckout > 360)
                {
                    printf("As datas de check-in e check-out devem estar entre 1 e 360.\n");
                }

                if (tipo_quarto = 1)
                {

                    for (i = 0; i < num_resv_suite2; i++)
                    {

                        if (reserva_qrt[i].diaCheckin == diaCheckin && reserva_qrt[i].diaCheckout == diaCheckout)
                        {
                            quarto_reservado = true;
                            break;
                        }
                    }

                    if (quarto_reservado)
                    {
                        printf("O quarto já está ocupado.\n");
                    }
                    else
                    {
                        reserva_qrt[num_resv_suite2].diaCheckin = diaCheckin;
                        reserva_qrt[num_resv_suite2].diaCheckout = diaCheckout;
                        num_resv_suite2++;
                        printf("As datas de check-in e de check-out foram agendadas.\n");
                    }
                }
                if (tipo_quarto = 2)
                {

                    for (i = 0; i < num_resv_luxo2; i++)
                    {

                        if (reserva_qrt[i].diaCheckin == diaCheckin && reserva_qrt[i].diaCheckout == diaCheckout)
                        {
                            quarto_reservado = true;
                            break;
                        }
                    }

                    if (quarto_reservado)
                    {
                        printf("O quarto já está ocupado.\n");
                    }
                    else
                    {
                        reserva_qrt[num_resv_luxo2].diaCheckin = diaCheckin;
                        reserva_qrt[num_resv_luxo2].diaCheckout = diaCheckout;
                        num_resv_luxo2++;
                        printf("As datas de check-in e de check-out foram agendadas.\n");
                    }
                }
                if (tipo_quarto = 3)
                {

                    for (i = 0; i < num_resv_standart1; i++)
                    {

                        if (reserva_qrt[i].diaCheckin == diaCheckin && reserva_qrt[i].diaCheckout == diaCheckout)
                        {
                            quarto_reservado = true;
                            break;
                        }
                    }

                    if (quarto_reservado)
                    {
                        printf("O quarto já está ocupado.\n");
                    }
                    else
                    {
                        reserva_qrt[num_resv_standart2].diaCheckin = diaCheckin;
                        reserva_qrt[num_resv_standart2].diaCheckout = diaCheckout;
                        num_resv_standart1++;
                        printf("As datas de check-in e de check-out foram agendadas.\n");
                    }
                }
            }


            break;

        case 3:
            printf("Você escolheu: Sistema de Tarifas\n");
            break;
        default:
            printf("Escolha uma opção válida\n");
            break;

            system("pause");
            system("cls");
        }
    }
}
