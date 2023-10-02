#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Reservas
{

    int dia_checkin;
    int dia_chekout;

} reserva_qrt;

void main(int argc, char const *argv[])
{

    int op, opcao_hotel, tipo_quarto, i;
    int num_resv_suite1 = 0, num_resv_suite2 = 0, num_rsv_luxo1 = 0, num_rsv_luxo2 = 0, num_rsv_stnd1 = 0, num_rsv_stnd2 = 0;
    bool quarto_reservado;

    printf("***Menu***\n");
    printf("[1]Reserva de quartos\n");
    printf("[2]Gerenciamento de Estadia\n");
    printf("[3]Sistemas de Tarifas\n");
    printf("Escolha uma opção:");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
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
            if (tipo_quarto != 1 && 2 && 3)
            {
                printf("Digite uma opcao de quarto válida\n");
            }
            struct Reservas reserva_qrt;
            int dia_checkin, dia_checkout;
            bool quarto_reservado = false;
            if (tipo_quarto = 1)
            {
                printf("Digite a data do check-in e do check-out que deseja: \n");
                scanf("%d, %d", &dia_checkin, &dia_checkout);
                for (i = 0; i < num_resv_suite1; i++)
                {
                    if (reserva_qrt[i].dia_checkin == dia_checkin && reserva_qrt[i].dia_checkout)
                    {
                        quarto_reservado = true;
                        break;
                    }
                }
            }
            if (quarto_reservado)
            {
                printf("O quarto já está ocupado.\n");
            }
            else
            {
                reserva_qrt[num_resv_suite1].dia_checkin = dia_checkin;
                reserva_qrt[num_resv_suite1].dia_checkout = dia_checkout;
                num_resv_suite1++;
                printf("As datas de check-in e de check-out foram agendadas.\n");
            }
        }
      break;
    case 2:
        printf("Você escolheu: Gerencimaneto de Estadia\n");
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
