#include <stdio.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdbool.h>

#define TOTAL_QUARTOS_SUITE1 10
#define TOTAL_QUARTOS_LUXO1 10
#define TOTAL_QUARTOS_STANDART1 10
#define TOTAL_QUARTOS_SUITE2 10
#define TOTAL_QUARTOS_LUXO2 10
#define TOTAL_QUARTOS_STANDART2 10

struct Quarto
{
    int numero;
    bool disponivel;
};

struct Reserva
{
    int quarto_numero;
    int checkin;
    int checkout;
    int novo_checkin;
    int novo_checkout;
};

int main(int argc, char const *argv[])
{

    struct Quarto quartossuites1[TOTAL_QUARTOS_SUITE1];
    struct Quarto quartosluxo1[TOTAL_QUARTOS_LUXO1];
    struct Quarto quartosstandart1[TOTAL_QUARTOS_STANDART1];
    struct Quarto quartossuites2[TOTAL_QUARTOS_SUITE2];
    struct Quarto quartosluxo2[TOTAL_QUARTOS_LUXO2];
    struct Quarto quartosstandart2[TOTAL_QUARTOS_STANDART2];
    struct Reserva reservaSuite1[TOTAL_QUARTOS_SUITE1];
    int numeroReservasRealizadas_Suite1 = 0;
    struct Reserva reservaSuite2[TOTAL_QUARTOS_SUITE2];
    int numeroReservasRealizadas_Suite2 = 0;
    struct Reserva reservaLuxo1[TOTAL_QUARTOS_LUXO1];
    int numeroReservasRealizadas_Luxo1 = 0;
    struct Reserva reservaLuxo2[TOTAL_QUARTOS_LUXO2];
    int numeroReservasRealizadas_Luxo2 = 0;
    int numeroReservasRealizadas_Standart1 = 0;
    struct Reserva reservaStandart1[TOTAL_QUARTOS_STANDART1];
    int numeroReservasRealizadas_Standart2 = 0;
    struct Reserva reservaStandart2[TOTAL_QUARTOS_STANDART2];
    int opcao_edicao;
    int opcao_novotipo;

    int escolha_numero_luxo1;
    int escolha_numero_suite1;
    int escolha_numero_standart1;
    int checkin, checkout;
    int escolha;
    int op;
    int opcao_hotel;
    int tipo_quarto;
    int diaCheckin, diaCheckout;
    int opcao_verificacao;
    int escolha_numero_suite2;
    int escolha_numero_luxo2;
    int escolha_numero_standart2;
    int novo_checkin;
    int novo_checkout;

    for (int i = 0; i < TOTAL_QUARTOS_SUITE1; i++)
    {
        quartossuites1[i].numero = i + 1;
        quartossuites1[i].disponivel = true;
    }

    for (int i = 0; i < TOTAL_QUARTOS_LUXO1; i++)
    {
        quartosluxo1[i].numero = i + 1;
        quartosluxo1[i].disponivel = true;
    }

    for (int i = 0; i < TOTAL_QUARTOS_STANDART1; i++)
    {
        quartosstandart1[i].numero = i + 1;
        quartosstandart1[i].disponivel = true;
    }
    for (int i = 0; i < TOTAL_QUARTOS_SUITE2; i++)
    {
        quartossuites2[i].numero = i + 1;
        quartossuites2[i].disponivel = true;
    }

    for (int i = 0; i < TOTAL_QUARTOS_LUXO2; i++)
    {
        quartosluxo2[i].numero = i + 1;
        quartosluxo2[i].disponivel = true;
    }

    for (int i = 0; i < TOTAL_QUARTOS_STANDART2; i++)
    {
        quartosstandart2[i].numero = i + 1;
        quartosstandart2[i].disponivel = true;
    }

    printf("***Menu***\n");
    printf("[1]Cadastro do cliente\n");
    printf("[2]Reserva de quartos\n");
    printf("[3]Sistemas de Tarifas\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        printf("a.");
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

                while (1)
                {
                    printf("\nQuartos disponíveis:\n");
                    for (int i = 0; i < TOTAL_QUARTOS_SUITE1; i++)
                    {
                        if (quartossuites1[i].disponivel)
                        {
                            printf("Quarto %d\n", quartossuites1[i].numero);
                        }
                    }

                    printf("Escolha um número de quarto: ");
                    scanf("%d", &escolha_numero_suite1);

                    if (escolha_numero_suite1 < 1 || escolha_numero_suite1 > TOTAL_QUARTOS_SUITE1)
                    {
                        printf("Escolha um número de quarto válido.\n");
                        return 1;
                    }
                    else if (!quartossuites1[escolha_numero_suite1 - 1].disponivel)
                    {
                        printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                    }
                    else
                    {
                        printf("Digite a data de check-in (entre 1 e 365): ");
                        scanf("%d", &checkin);
                        printf("Digite a data de check-out (entre 1 e 365): ");
                        scanf("%d", &checkout);

                        if (checkin <= 0 || checkin > 365 || checkout <= 0 || checkout > 365 || checkin >= checkout)
                        {
                            printf("Datas de check-in e check-out inválidas.\n");
                            return 1;
                        }
                        else
                        {
                            quartossuites1[escolha_numero_suite1 - 1].disponivel = false; // Marca o quarto como ocupado.
                            printf("Reserva do quarto realizada com sucesso!\n");
                        }
                    }
                    reservaSuite1[numeroReservasRealizadas_Suite1].quarto_numero = escolha_numero_suite1;
                    reservaSuite1[numeroReservasRealizadas_Suite1].checkin = diaCheckin;
                    reservaSuite1[numeroReservasRealizadas_Suite1].checkout = diaCheckout;
                    

                    printf("Verificação dos dados da reserva: \n");
                    printf("O quarto escolhido foi: %d\n", escolha_numero_suite1);
                    printf("\nQuartos disponíveis:\n");
                    for (int i = 0; i < TOTAL_QUARTOS_SUITE1; i++)
                    {
                        if (quartossuites1[i].disponivel)
                        {
                            printf("Quarto %d\n", quartossuites1[i].numero);
                        }
                    }
                    printf("A data do check-in é: %d\n", checkin);
                    printf("A data do check-out é: %d\n", checkout);
                    numeroReservasRealizadas_Suite1++;

                    printf("Opções\n");
                    printf("[0] Digite 0 para voltar ao menu\n");
                    printf("[1] Digite 1 para editar os dados da reserva\n");
                    scanf("%d", &opcao_verificacao);

                    if (opcao_verificacao == 0)
                    {
                        break;
                        // Fazer voltar para o menu./
                    }
                   if (opcao_verificacao == 1)
                        {
                            printf("Digite o que deseja editar:\n ");
                            printf("[1] Tipo de Quarto\n");
                            printf("[2] Data de check-in\n");
                            printf("[3] Data de check-out\n");
                            scanf("%d", &opcao_edicao);
                        }
                         if (opcao_edicao == 1) {
                            quartossuites1[escolha_numero_suite1 - 1].disponivel = true;
                            printf("Digite o novo tipo de quarto\n");
                            printf("[1] Luxo\n");
                            printf("[2] Standart\n");
                            scanf("%d", &opcao_novotipo);
                           
                            if (opcao_novotipo == 1)
                            {

                                if (escolha_numero_suite1 < 1 || escolha_numero_suite1 > TOTAL_QUARTOS_LUXO1)
                                {
                                    printf("Escolha um número de quarto válido.\n");
                                    return 1;
                                }
                                else if (!quartosluxo1[escolha_numero_suite1 - 1].disponivel)
                                {
                                    printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                                }
                                else {
                                     quartosluxo1[escolha_numero_suite1- 1].disponivel = false;
                                      printf("Reserva do quarto atualizada com sucesso!\n");

                                }
                               
                                reservaLuxo1[numeroReservasRealizadas_Luxo1].quarto_numero = escolha_numero_suite1;
                                reservaLuxo1[numeroReservasRealizadas_Luxo1].checkin = diaCheckin;
                                reservaLuxo1[numeroReservasRealizadas_Suite1].checkout = diaCheckout;
                                numeroReservasRealizadas_Luxo1++;

                            }
                        }
                        if (opcao_novotipo == 2)
                        {

                            if (escolha_numero_suite1 < 1 || escolha_numero_suite1 > TOTAL_QUARTOS_STANDART1)
                            {
                                printf("Escolha um número de quarto válido.\n");
                                return 1;
                            }
                            else if (!quartosstandart1[escolha_numero_suite1 - 1].disponivel)
                            {
                                printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                            }
                            else {
                            quartosstandart1[escolha_numero_suite1 - 1].disponivel = false;
                            printf("Reserva do quarto atualizada com sucesso!\n");
                            }     

                               
                        }
                                reservaStandart1[numeroReservasRealizadas_Standart1].quarto_numero = escolha_numero_suite1;
                                reservaStandart1[numeroReservasRealizadas_Standart1].checkin = diaCheckin;
                                reservaStandart1[numeroReservasRealizadas_Standart1].checkout = diaCheckout;
                                numeroReservasRealizadas_Standart1++;
                        
                        if (opcao_edicao == 2)
                       
                        {
                             reservaSuite1[escolha_numero_suite1 - 1].checkin = 0;
                            printf("Digte a nova data do check-in: \n");
                            scanf("%d", &novo_checkin);
                            if (novo_checkin <= 0 || novo_checkin > 365 || checkout <= 0 || checkout > 365 || novo_checkin >= checkout)
                            {
                                printf("Data de check-in inválida.\n");
                            }
                            else
                            {
                                reservaSuite1[numeroReservasRealizadas_Suite1].novo_checkin = diaCheckin;
                                printf("A data do check-in foi atualizada!\n");
                                printf("Verificacao dos dados atualizados:\n");
                                printf("O quarto escolhido foi: %d\n", escolha_numero_suite1);
                                printf("\nQuartos disponíveis:\n");
                                for (int i = 0; i < TOTAL_QUARTOS_SUITE1; i++)
                                {
                                    if (quartossuites1[i].disponivel)
                                    {
                                        printf("Quarto %d\n", quartossuites1[i].numero);
                                    }
                                }

                                printf("A data do check-in é: %d\n", novo_checkin);
                                printf("A data do check-out é: %d\n", checkout);
                                numeroReservasRealizadas_Suite1++;
                            }
                        }
                        
                        if (opcao_edicao == 3)
                        {
                            
                            printf("Digte a nova data do check-in: \n");
                            scanf("%d", &novo_checkout);
                            if (checkin <= 0 || checkin > 365 || novo_checkout <= 0 || novo_checkout > 365 || checkin >= novo_checkout)
                            {
                                printf("Data de check-out inválida.\n");
                            }
                            else
                            {
                                reservaSuite1[numeroReservasRealizadas_Suite1].novo_checkout = diaCheckout;
                                printf("A data do check-out foi atualizada!\n");
                                printf("Verificacao dos dados atualizados:\n");
                                printf("O quarto escolhido foi: %d\n", escolha_numero_suite1);
                                printf("\nQuartos disponíveis:\n");
                                for (int i = 0; i < TOTAL_QUARTOS_SUITE1; i++)
                                {
                                    if (quartossuites1[i].disponivel)
                                    {
                                        printf("Quarto %d\n", quartossuites1[i].numero);
                                    }
                                }

                                printf("A data do check-in é: %d\n", checkin);
                                printf("A data do check-out é: %d\n", novo_checkout);
                                numeroReservasRealizadas_Suite1++;
                            }
                        }
                    }
                }
                break;

            case 2:
                while (1)
                {
                    printf("\nQuartos disponíveis:\n");
                    for (int i = 0; i < TOTAL_QUARTOS_LUXO1; i++)
                    {
                        if (quartosluxo1[i].disponivel)
                        {
                            printf("Quarto %d\n", quartosluxo1[i].numero);
                        }
                    }

                    printf("Escolha um número de quarto: ");
                    scanf("%d", &escolha_numero_luxo1);

                    if (escolha_numero_luxo1 < 1 || escolha_numero_luxo1 > TOTAL_QUARTOS_LUXO1)
                    {
                        printf("Escolha um número de quarto válido.\n");
                        return 1;
                    }
                    else if (!quartosluxo1[escolha_numero_luxo1 - 1].disponivel)
                    {
                        printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                    }
                    else
                    {
                        printf("Digite a data de check-in (entre 1 e 365): ");
                        scanf("%d", &checkin);
                        printf("Digite a data de check-out (entre 1 e 365): ");
                        scanf("%d", &checkout);

                        if (checkin <= 0 || checkin > 365 || checkout <= 0 || checkout > 365 || checkin >= checkout)
                        {
                            printf("Datas de check-in e check-out inválidas.\n");
                            return 1;
                        }
                        else
                        {
                            quartosluxo1[escolha_numero_luxo1 - 1].disponivel = false; // Marca o quarto como ocupado.
                            printf("Reserva do quarto realizada com sucesso!\n");
                        }
                    }

                    reservaLuxo1[numeroReservasRealizadas_Luxo1].quarto_numero = escolha_numero_luxo1;
                    reservaLuxo1[numeroReservasRealizadas_Luxo1].checkin = diaCheckin;
                    reservaLuxo1[numeroReservasRealizadas_Luxo1].checkout = diaCheckout;

                    printf("Verificação dos dados da reserva: \n");
                    printf("O quarto escolhido foi: %d\n", escolha_numero_luxo1);
                    printf("\nQuartos disponíveis:\n");
                    for (int i = 0; i < TOTAL_QUARTOS_LUXO1; i++)
                    {
                        if (quartosluxo1[i].disponivel)
                        {
                            printf("Quarto %d\n", quartosluxo1[i].numero);
                        }
                    }
                    printf("A data do check-in é: %d\n", checkin);
                    printf("A data do check-out é: %d\n", checkout);
                    numeroReservasRealizadas_Luxo1++;
                    printf("Opções\n");
                    printf("[0] Digite 0 para voltar ao menu\n");
                    printf("[1] Digite 1 para editar os dados da reserva\n");
                    scanf("%d", &opcao_verificacao);

                    if (opcao_verificacao == 0)
                    {
                        break;
                        // Fazer voltar para o menu.
                    }
                  
                         if (opcao_verificacao == 1)
                        {
                            printf("Digite o que deseja editar:\n ");
                            printf("[1] Tipo de Quarto\n");
                            printf("[2] Data de check-in\n");
                            printf("[3] Data de check-out\n");
                            scanf("%d", &opcao_edicao);
                        }
                         if (opcao_edicao == 1)
                        {
                            printf("Digite o novo tipo de quarto\n");
                            printf("[1] Suíte\n");
                            printf("[2] Standart\n");
                            scanf("%d", &opcao_novotipo);
                            quartosluxo1[escolha_numero_luxo1 - 1].disponivel = true;

                            if (opcao_novotipo == 1)
                            {

                                if (escolha_numero_luxo1 < 1 || escolha_numero_luxo1 > TOTAL_QUARTOS_SUITE1)
                                {
                                    printf("Escolha um número de quarto válido.\n");
                                    return 1;
                                }
                                else if (!quartossuites1[escolha_numero_luxo1 - 1].disponivel)
                                {
                                    printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                                }
                                else{
                                    quartossuites1[escolha_numero_luxo1- 1].disponivel = false;
                                printf("Reserva do quarto atualizada com sucesso!\n");
                            }
                                
                            }
                                reservaSuite1[numeroReservasRealizadas_Suite1].quarto_numero = escolha_numero_luxo1;
                                reservaSuite1[numeroReservasRealizadas_Suite1].checkin = diaCheckin;
                                reservaSuite1[numeroReservasRealizadas_Suite1].checkout = diaCheckout;
                                numeroReservasRealizadas_Suite1++;

                        }
                        if (opcao_novotipo == 2)
                        {

                            if (escolha_numero_luxo1 < 1 || escolha_numero_luxo1 > TOTAL_QUARTOS_STANDART1)
                            {
                                printf("Escolha um número de quarto válido.\n");
                                return 1;
                            }
                            else if (!quartosstandart1[escolha_numero_luxo1 - 1].disponivel)
                            {
                                printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                            }
                            else  {
                            quartosstandart1[escolha_numero_luxo1 - 1].disponivel = false;
                            printf("Reserva do quarto atualizada com sucesso!\n");
                            }
                              

                                
                        }
                                 reservaStandart1[numeroReservasRealizadas_Standart1].quarto_numero = escolha_numero_luxo1;
                                reservaStandart1[numeroReservasRealizadas_Standart1].checkin = diaCheckin;
                                reservaStandart1[numeroReservasRealizadas_Standart1].checkout = diaCheckout;
                                numeroReservasRealizadas_Standart1++;
                        
                        if (opcao_edicao == 2)
                        {
                            reservaLuxo1[escolha_numero_luxo1 - 1].checkin = 0;
                            printf("Digte a nova data do check-in: \n");
                            scanf("%d", &novo_checkin);
                            if (novo_checkin <= 0 || novo_checkin > 365 || checkout <= 0 || checkout > 365 || novo_checkin >= checkout)
                            {
                                printf("Data de check-in inválida.\n");
                            }
                            else
                            
                            {
                                reservaLuxo1[numeroReservasRealizadas_Luxo1].novo_checkin = diaCheckin;
                                printf("A data do check-in foi atualizada!\n");
                                printf("Verificacao dos dados atualizados:\n");
                                printf("O quarto escolhido foi: %d\n", escolha_numero_luxo1);
                                printf("\nQuartos disponíveis:\n");
                                for (int i = 0; i < TOTAL_QUARTOS_LUXO1; i++)
                                {
                                    if (quartosluxo1[i].disponivel)
                                    {
                                        printf("Quarto %d\n", quartosluxo1[i].numero);
                                    }
                                }

                                printf("A data do check-in é: %d\n", novo_checkin);
                                printf("A data do check-out é: %d\n", checkout);
                                numeroReservasRealizadas_Luxo1++;
                            }
                        }
                        if (opcao_edicao == 3)
                        {
                            reservaLuxo1[escolha_numero_luxo1 - 1].checkout = 0;
                            printf("Digte a nova data do check-in: \n");
                            scanf("%d", &novo_checkout);
                            if (checkin <= 0 || checkin > 365 || novo_checkout <= 0 || novo_checkout > 365 || checkin >= novo_checkout)
                            {
                                printf("Data de check-out inválida.\n");
                            }
                            else
                            {
                                reservaLuxo1[numeroReservasRealizadas_Luxo1].novo_checkout = diaCheckout;
                                printf("A data do check-out foi atualizada!\n");
                                printf("Verificacao dos dados atualizados:\n");
                                printf("O quarto escolhido foi: %d\n", escolha_numero_luxo1);
                                printf("\nQuartos disponíveis:\n");
                                for (int i = 0; i < TOTAL_QUARTOS_LUXO1; i++)
                                {
                                    if (quartosluxo1[i].disponivel)
                                    {
                                        printf("Quarto %d\n", quartosluxo1[i].numero);
                                    }
                                }

                                printf("A data do check-in é: %d\n", checkin);
                                printf("A data do check-out é: %d\n", novo_checkout);
                                numeroReservasRealizadas_Luxo1++;
                            }
                        }
                    
                       
                    }
                   
                   
                }

                break;

            case 3:
                while (1)
                {
                    printf("\nQuartos disponíveis:\n");
                    for (int i = 0; i < TOTAL_QUARTOS_STANDART1; i++)
                    {
                        if (quartosstandart1[i].disponivel)
                        {
                            printf("Quarto %d\n", quartosstandart1[i].numero);
                        }
                    }

                    printf("Escolha um número de quarto: ");
                    scanf("%d", &escolha_numero_standart1);

                    if (escolha_numero_standart1 < 1 || escolha_numero_standart1 > TOTAL_QUARTOS_STANDART1)
                    {
                        printf("Escolha um número de quarto válido.\n");
                        return 1;
                    }
                    else if (!quartosstandart1[escolha_numero_standart1 - 1].disponivel)
                    {
                        printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                    }
                    else
                    {
                        printf("Digite a data de check-in (entre 1 e 365): ");
                        scanf("%d", &checkin);
                        printf("Digite a data de check-out (entre 1 e 365): ");
                        scanf("%d", &checkout);

                        if (checkin <= 0 || checkin > 365 || checkout <= 0 || checkout > 365 || checkin >= checkout)
                        {
                            printf("Datas de check-in e check-out inválidas.\n");
                            return 1;
                        }
                        else
                        {
                            quartosstandart1[escolha_numero_standart1 - 1].disponivel = false; // Marca o quarto como ocupado.
                            printf("Reserva do quarto realizada com sucesso!\n");
                        }
                    }

                    reservaStandart1[numeroReservasRealizadas_Standart1].quarto_numero = escolha_numero_standart1;
                    reservaStandart1[numeroReservasRealizadas_Standart1].checkin = diaCheckin;
                    reservaStandart1[numeroReservasRealizadas_Standart1].checkout = diaCheckout;

                    printf("Verificação dos dados da reserva: \n");
                    printf("O quarto escolhido foi: %d\n", escolha_numero_standart1);
                    printf("\nQuartos disponíveis:\n");
                    printf("\nQuartos disponíveis:\n");
                    for (int i = 0; i < TOTAL_QUARTOS_STANDART1; i++)
                    {
                        if (quartosstandart1[i].disponivel)
                        {
                            printf("Quarto %d\n", quartosstandart1[i].numero);
                        }
                    }
                    printf("A data do check-in é: %d\n", checkin);
                    printf("A data do check-out é: %d\n", checkout);
                    numeroReservasRealizadas_Standart1++;

                    printf("Opções\n");
                    printf("[0] Digite 0 para voltar ao menu\n");
                    printf("[1] Digite 1 para editar os dados da reserva\n");
                    printf("[2] Digite 2 para excluir a reserva\n");
                    scanf("%d", &opcao_verificacao);

                    if (opcao_verificacao == 0)
                    {
                        break;
                        // Fazer voltar para o menu.
                    }
                    else if (opcao_verificacao == 1)
                    {
                        if (opcao_edicao == 1)
                        {
                            printf("Digite o novo tipo de quarto\n");
                            printf("[1] Suíte\n");
                            printf("[2] Luxo\n");
                            scanf("%d", &opcao_novotipo);
                            quartosstandart1[escolha_numero_standart1 - 1].disponivel = true;

                            if (opcao_novotipo == 1)
                            {

                                if (escolha_numero_standart1 < 1 || escolha_numero_standart1 > TOTAL_QUARTOS_SUITE1)
                                {
                                    printf("Escolha um número de quarto válido.\n");
                                    return 1;
                                }
                                else if (!quartossuites1[escolha_numero_standart1 - 1].disponivel)
                                {
                                    printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                                }
                                else
                                    quartossuites1[escolha_numero_standart1 - 1].disponivel = false;
                                printf("Reserva do quarto atualizada com sucesso!\n");
                                reservaSuite1[numeroReservasRealizadas_Suite1].quarto_numero = escolha_numero_standart1;
                                reservaSuite1[numeroReservasRealizadas_Suite1].checkin = diaCheckin;
                                reservaStandart1[numeroReservasRealizadas_Suite1].checkout = diaCheckout;
                                numeroReservasRealizadas_Suite1++;

                            }
                        }
                        if (opcao_novotipo == 2)
                        {

                            if (escolha_numero_standart1 < 1 || escolha_numero_standart1 > TOTAL_QUARTOS_LUXO1)
                            {
                                printf("Escolha um número de quarto válido.\n");
                                return 1;
                            }
                            else if (!quartosluxo1[escolha_numero_standart1 - 1].disponivel)
                            {
                                printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                            }
                            else {
                                quartosluxo1[escolha_numero_standart1 - 1].disponivel = false;
                            printf("Reserva do quarto atualizada com sucesso!\n");
                            }
                        }
                            reservaLuxo1[numeroReservasRealizadas_Luxo1].quarto_numero = escolha_numero_standart1;
                                reservaLuxo1[numeroReservasRealizadas_Luxo1].checkin = diaCheckin;
                                reservaLuxo1[numeroReservasRealizadas_Luxo1].checkout = diaCheckout;
                                numeroReservasRealizadas_Luxo1++;
                        

                        if (opcao_edicao == 2)
                        {
                            reservaStandart1[escolha_numero_standart1 - 1].checkin = 0;
                            printf("Digte a nova data do check-in: \n");
                            scanf("%d", &novo_checkin);
                            if (novo_checkin <= 0 || novo_checkin > 365 || checkout <= 0 || checkout > 365 || novo_checkin >= checkout)
                            {
                                printf("Data de check-in inválida.\n");
                            }
                            else
                            {
                                reservaStandart1[numeroReservasRealizadas_Standart1].novo_checkin = diaCheckin;
                                printf("A data do check-in foi atualizada!\n");
                                printf("Verificacao dos dados atualizados:\n");
                                printf("O quarto escolhido foi: %d\n", escolha_numero_standart1);
                                printf("\nQuartos disponíveis:\n");
                                for (int i = 0; i < TOTAL_QUARTOS_STANDART1; i++)
                                {
                                    if (quartosstandart1[i].disponivel)
                                    {
                                        printf("Quarto %d\n", quartosstandart1[i].numero);
                                    }
                                }

                                printf("A data do check-in é: %d\n", novo_checkin);
                                printf("A data do check-out é: %d\n", checkout);
                                numeroReservasRealizadas_Standart1++;
                            }
                        }
                        if (opcao_edicao == 3)
                        {
                            reservaStandart1[escolha_numero_standart1 - 1].checkout = 0;
                            printf("Digte a nova data do check-in: \n");
                            scanf("%d", &novo_checkout);
                            if (checkin <= 0 || checkin > 365 || novo_checkout <= 0 || novo_checkout > 365 || checkin >= novo_checkout)
                            {
                                printf("Data de check-out inválida.\n");
                            }
                            else
                            {
                                reservaStandart1[numeroReservasRealizadas_Standart1].novo_checkout = diaCheckout;
                                printf("A data do check-out foi atualizada!\n");
                                printf("Verificacao dos dados atualizados:\n");
                                printf("O quarto escolhido foi: %d\n", escolha_numero_standart1);
                                printf("\nQuartos disponíveis:\n");
                                for (int i = 0; i < TOTAL_QUARTOS_STANDART1; i++)
                                {
                                    if (quartosstandart1[i].disponivel)
                                    {
                                        printf("Quarto %d\n", quartosstandart1[i].numero);
                                    }
                                }

                                printf("A data do check-in é: %d\n", checkin);
                                printf("A data do check-out é: %d\n", novo_checkout);
                                numeroReservasRealizadas_Standart1++;
                            
                            }
                        }
                    
            
    
                
                break;
                }
                
    


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
                printf("Digite o número do tipo de quarto válido: \n");
                scanf("%d", &tipo_quarto);
                break;
            }
                }
            switch (tipo_quarto)
            {
            case 1:

                while (1)
                {
                    printf("\nQuartos disponíveis:\n");
                    for (int i = 0; i < TOTAL_QUARTOS_SUITE2; i++)
                    {
                        if (quartossuites2[i].disponivel)
                        {
                            printf("Quarto %d\n", quartossuites2[i].numero);
                        }
                    }

                    printf("Escolha um número de quarto: ");
                    scanf("%d", &escolha_numero_suite2);

                    if (escolha_numero_suite2 < 1 || escolha_numero_suite2 > TOTAL_QUARTOS_SUITE2)
                    {
                        printf("Escolha um número de quarto válido.\n");
                        return 1;
                    }
                    else if (!quartossuites2[escolha_numero_suite2 - 1].disponivel)
                    {
                        printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                    }
                    else
                    {
                        printf("Digite a data de check-in (entre 1 e 365): ");
                        scanf("%d", &checkin);
                        printf("Digite a data de check-out (entre 1 e 365): ");
                        scanf("%d", &checkout);

                        if (checkin <= 0 || checkin > 365 || checkout <= 0 || checkout > 365 || checkin >= checkout)
                        {
                            printf("Datas de check-in e check-out inválidas.\n");
                            return 1;
                        }
                        else
                        {
                            quartossuites2[escolha_numero_suite2 - 1].disponivel = false; // Marca o quarto como ocupado.
                            printf("Reserva do quarto realizada com sucesso!\n");
                        }
                    }
                    reservaSuite2[numeroReservasRealizadas_Suite2].quarto_numero = escolha_numero_suite2;
                    reservaSuite2[numeroReservasRealizadas_Suite2].checkin = diaCheckin;
                    reservaSuite2[numeroReservasRealizadas_Suite2].checkout = diaCheckout;

                    printf("Verificação dos dados da reserva: \n");
                    printf("O quarto escolhido foi: %d\n", escolha_numero_suite2);
                    printf("\nQuartos disponíveis:\n");
                    for (int i = 0; i < TOTAL_QUARTOS_SUITE2; i++)
                    {
                        if (quartossuites2[i].disponivel)
                        {
                            printf("Quarto %d\n", quartossuites2[i].numero);
                        }
                    }
                    printf("A data do check-in é: %d\n", checkin);
                    printf("A data do check-out é: %d\n", checkout);
                    numeroReservasRealizadas_Suite2++;

                    printf("Opções\n");
                    printf("[0] Digite 0 para voltar ao menu\n");
                    printf("[1] Digite 1 para editar os dados da reserva\n");
                    printf("[2] Digite 2 para excluir a reserva\n");
                    scanf("%d", &opcao_verificacao);

                    if (opcao_verificacao == 0)
                    {
                        break;
                        // Fazer voltar para o menu.
                    }
                   
                        if (opcao_verificacao == 1)
                        {
                            printf("Digite o que deseja editar:\n ");
                            printf("[1] Tipo de Quarto\n");
                            printf("[2] Data de check-in\n");
                            printf("[3] Data de check-out\n");
                            scanf("%d", &opcao_edicao);
                        }
                         if (opcao_edicao == 1)
                        {
                            printf("Digite o novo tipo de quarto\n");
                            printf("[1] Luxo\n");
                            printf("[2] Standart\n");
                            scanf("%d", &opcao_novotipo);
                            quartossuites2[escolha_numero_suite2 - 1].disponivel = true;

                            if (opcao_novotipo == 1)
                            {

                                if (escolha_numero_suite2 < 1 || escolha_numero_suite2 > TOTAL_QUARTOS_LUXO2)
                                {
                                    printf("Escolha um número de quarto válido.\n");
                                    return 1;
                                }
                                else if (!quartosluxo2[escolha_numero_suite2 - 1].disponivel)
                                {
                                    printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                                }
                                else {
                               quartosluxo2[escolha_numero_suite2- 1].disponivel = false;
                                
                                printf("Reserva do quarto atualizada com sucesso!\n");
                                }
                                
                              

                            }
                                reservaLuxo2[numeroReservasRealizadas_Luxo2].quarto_numero = escolha_numero_suite2;
                                reservaLuxo2[numeroReservasRealizadas_Luxo2].checkin = diaCheckin;
                                reservaLuxo2[numeroReservasRealizadas_Suite2].checkout = diaCheckout;
                                numeroReservasRealizadas_Luxo2++;
                        }
                        if (opcao_novotipo == 2)
                        {

                            if (escolha_numero_suite2 < 1 || escolha_numero_suite2 > TOTAL_QUARTOS_STANDART2)
                            {
                                printf("Escolha um número de quarto válido.\n");
                                return 1;
                            }
                            else if (!quartosstandart2[escolha_numero_suite2 - 1].disponivel)
                            {
                                printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                            }
                            else {
                                 quartosstandart2[escolha_numero_suite2 - 1].disponivel = false;
                            printf("Reserva do quarto atualizada com sucesso!\n");

                            }
                               
                                reservaStandart2[numeroReservasRealizadas_Standart2].quarto_numero = escolha_numero_suite2;
                                reservaStandart2[numeroReservasRealizadas_Standart2].checkin = diaCheckin;
                                reservaStandart2[numeroReservasRealizadas_Standart2].checkout = diaCheckout;
                                numeroReservasRealizadas_Standart2++;
                        
                        
                        if (opcao_edicao == 2)
                        {
                            reservaSuite2[escolha_numero_suite2 - 1].checkin = 0;
                            reservaSuite2[numeroReservasRealizadas_Suite2].novo_checkin = diaCheckin;
                            printf("Digte a nova data do check-in: \n");
                            scanf("%d", &novo_checkin);
                            if (novo_checkin <= 0 || novo_checkin > 365 || checkout <= 0 || checkout > 365 || novo_checkin >= checkout)
                            {
                                printf("Data de check-in inválida.\n");
                            }
                            
                            else
                            {
                                
                                printf("A data do check-in foi atualizada!\n");
                                printf("Verificacao dos dados atualizados:\n");
                                printf("O quarto escolhido foi: %d\n", escolha_numero_suite2);
                                printf("\nQuartos disponíveis:\n");
                                for (int i = 0; i < TOTAL_QUARTOS_SUITE2; i++)
                                {
                                    if (quartossuites2[i].disponivel)
                                    {
                                        printf("Quarto %d\n", quartosluxo2[i].numero);
                                    }
                                }

                                printf("A data do check-in é: %d\n", novo_checkin);
                                printf("A data do check-out é: %d\n", checkout);
                                numeroReservasRealizadas_Suite2++;
                            }
                        }
                        if (opcao_edicao == 3)
                        {
                            reservaSuite2[escolha_numero_suite2 - 1].checkout = 0;
                            printf("Digte a nova data do check-in: \n");
                            scanf("%d", &novo_checkout);
                            if (checkin <= 0 || checkin > 365 || novo_checkout <= 0 || novo_checkout > 365 || checkin >= novo_checkout)
                            {
                                printf("Data de check-out inválida.\n");
                            }
                            else
                            {
                                reservaSuite2[numeroReservasRealizadas_Suite2].novo_checkout = diaCheckout;
                                printf("A data do check-out foi atualizada!\n");
                                printf("Verificacao dos dados atualizados:\n");
                                printf("O quarto escolhido foi: %d\n", escolha_numero_suite2);
                                printf("\nQuartos disponíveis:\n");
                                for (int i = 0; i < TOTAL_QUARTOS_SUITE2; i++)
                                {
                                    if (quartossuites2[i].disponivel)
                                    {
                                        printf("Quarto %d\n", quartossuites2[i].numero);
                                    }
                                }

                                printf("A data do check-in é: %d\n", checkin);
                                printf("A data do check-out é: %d\n", novo_checkout);
                                numeroReservasRealizadas_Suite2++;
                            }
                        }
                    }
                   
                  
                break;
                
            case 2:
                while (1)
                {
                    printf("\nQuartos disponíveis:\n");
                    for (int i = 0; i < TOTAL_QUARTOS_LUXO2; i++)
                    {
                        if (quartosluxo2[i].disponivel)
                        {
                            printf("Quarto %d\n", quartosluxo2[i].numero);
                        }
                    }

                    printf("Escolha um número de quarto: ");
                    scanf("%d", &escolha_numero_luxo2);

                    if (escolha_numero_luxo2 < 1 || escolha_numero_luxo2 > TOTAL_QUARTOS_LUXO2)
                    {
                        printf("Escolha um número de quarto válido.\n");
                        return 1;
                    }
                    else if (!quartosluxo2[escolha_numero_luxo2 - 1].disponivel)
                    {
                        printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                    }
                    else
                    {
                        printf("Digite a data de check-in (entre 1 e 365): ");
                        scanf("%d", &checkin);
                        printf("Digite a data de check-out (entre 1 e 365): ");
                        scanf("%d", &checkout);

                        if (checkin <= 0 || checkin > 365 || checkout <= 0 || checkout > 365 || checkin >= checkout)
                        {
                            printf("Datas de check-in e check-out inválidas.\n");
                            return 1;
                        }
                        else
                        {
                            quartosluxo2[escolha_numero_luxo2 - 1].disponivel = false; // Marca o quarto como ocupado.
                            printf("Reserva do quarto realizada com sucesso!\n");
                        }
                    }

                    reservaLuxo2[numeroReservasRealizadas_Luxo2].quarto_numero = escolha_numero_luxo2;
                    reservaLuxo2[numeroReservasRealizadas_Luxo1].checkin = diaCheckin;
                    reservaLuxo2[numeroReservasRealizadas_Luxo2].checkout = diaCheckout;

                    printf("Verificação dos dados da reserva: \n");
                    printf("O quarto escolhido foi: %d\n", escolha_numero_luxo2);
                    printf("\nQuartos disponíveis:\n");
                    for (int i = 0; i < TOTAL_QUARTOS_LUXO2; i++)
                    {
                        if (quartosluxo2[i].disponivel)
                        {
                            printf("Quarto %d\n", quartosluxo2[i].numero);
                        }
                    }

                    printf("A data do check-in é: %d\n", checkin);
                    printf("A data do check-out é: %d\n", checkout);
                    numeroReservasRealizadas_Luxo2++;
                    printf("Opções\n");
                    printf("[0] Digite 0 para voltar ao menu\n");
                    printf("[1] Digite 1 para editar os dados da reserva\n");
                    printf("[2] Digite 2 para excluir a reserva\n");
                    scanf("%d", &opcao_verificacao);

                    if (opcao_verificacao == 0)
                    {
                        break;
                        // Fazer voltar para o menu.
                        if (opcao_verificacao == 1)
                        {
                            printf("Digite o que deseja editar:\n ");
                            printf("[1] Tipo de Quarto\n");
                            printf("[2] Data de check-in\n");
                            printf("[3] Data de check-out\n");
                            scanf("%d", &opcao_edicao);
                        }
                         if (opcao_edicao == 1)
                        {
                            printf("Digite o novo tipo de quarto\n");
                            printf("[1] Suíte\n");
                            printf("[2] Standart\n");
                            scanf("%d", &opcao_novotipo);
                            quartosluxo2[escolha_numero_luxo2 - 1].disponivel = true;

                            if (opcao_novotipo == 1)
                            {

                                if (escolha_numero_luxo2 < 1 || escolha_numero_luxo2 > TOTAL_QUARTOS_SUITE2)
                                {
                                    printf("Escolha um número de quarto válido.\n");
                                    return 1;
                                }
                                else if (!quartossuites2[escolha_numero_luxo2 - 1].disponivel)
                                {
                                    printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                                }
                                else {
                                    quartossuites2[escolha_numero_luxo2- 1].disponivel = false;
                                printf("Reserva do quarto atualizada com sucesso!\n");
                                }
                                    
                                reservaSuite2[numeroReservasRealizadas_Suite2].quarto_numero = escolha_numero_luxo2;
                                reservaSuite2[numeroReservasRealizadas_Suite2].checkin = diaCheckin;
                                reservaSuite2[numeroReservasRealizadas_Suite2].checkout = diaCheckout;
                                numeroReservasRealizadas_Suite2++;

                            
                        }
                        }
                    }
                        if (opcao_novotipo == 2)
                        {

                            if (escolha_numero_luxo2 < 1 || escolha_numero_luxo2 > TOTAL_QUARTOS_STANDART2)
                            {
                                printf("Escolha um número de quarto válido.\n");
                                return 1;
                            }
                            else if (!quartosstandart2[escolha_numero_luxo2 - 1].disponivel)
                            {
                                printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                            }
                                else {
                                    quartosstandart2[escolha_numero_luxo2 - 1].disponivel = false;
                            printf("Reserva do quarto atualizada com sucesso!\n");
                                }
                                

                                reservaStandart2[numeroReservasRealizadas_Standart2].quarto_numero = escolha_numero_luxo2;
                                reservaStandart2[numeroReservasRealizadas_Standart2].checkin = diaCheckin;
                                reservaStandart2[numeroReservasRealizadas_Standart2].checkout = diaCheckout;
                                numeroReservasRealizadas_Standart2++;
                        
                        
                        if (opcao_edicao == 2)
                        {
                            reservaLuxo2[escolha_numero_luxo2 - 1].checkin = 0;
                            printf("Digte a nova data do check-in: \n");
                            scanf("%d", &novo_checkin);
                            if (novo_checkin <= 0 || novo_checkin > 365 || checkout <= 0 || checkout > 365 || novo_checkin >= checkout)
                            {
                                printf("Data de check-in inválida.\n");
                            }
                            else
                            {
                                reservaLuxo2[numeroReservasRealizadas_Luxo2].novo_checkin = diaCheckin;
                                printf("A data do check-in foi atualizada!\n");
                                printf("Verificacao dos dados atualizados:\n");
                                printf("O quarto escolhido foi: %d\n", escolha_numero_luxo2);
                                printf("\nQuartos disponíveis:\n");
                                for (int i = 0; i < TOTAL_QUARTOS_LUXO2; i++)
                                {
                                    if (quartosluxo2[i].disponivel)
                                    {
                                        printf("Quarto %d\n", quartosluxo2[i].numero);
                                    }
                                }

                                printf("A data do check-in é: %d\n", novo_checkin);
                                printf("A data do check-out é: %d\n", checkout);
                                numeroReservasRealizadas_Luxo2++;
                            }
                        }
                        if (opcao_edicao == 3)
                        {
                            reservaLuxo2[escolha_numero_luxo2 - 1].checkout = 0;
                            printf("Digte a nova data do check-in: \n");
                            scanf("%d", &novo_checkout);
                            if (checkin <= 0 || checkin > 365 || novo_checkout <= 0 || novo_checkout > 365 || checkin >= novo_checkout)
                            {
                                printf("Data de check-out inválida.\n");
                            }
                            else
                            {
                                reservaLuxo2[numeroReservasRealizadas_Luxo2].novo_checkout = diaCheckout;
                                printf("A data do check-out foi atualizada!\n");
                                printf("Verificacao dos dados atualizados:\n");
                                printf("O quarto escolhido foi: %d\n", escolha_numero_luxo2);
                                printf("\nQuartos disponíveis:\n");
                                for (int i = 0; i < TOTAL_QUARTOS_LUXO2; i++)
                                {
                                    if (quartosluxo2[i].disponivel)
                                    {
                                        printf("Quarto %d\n", quartosluxo2[i].numero);
                                    }
                                }

                                printf("A data do check-in é: %d\n", checkin);
                                printf("A data do check-out é: %d\n", novo_checkout);
                                numeroReservasRealizadas_Luxo2++;
                            }
                        }
                    }

                    break;
                case 3:
                    while (1)
                    {
                        printf("\nQuartos disponíveis:\n");
                        for (int i = 0; i < TOTAL_QUARTOS_STANDART2; i++)
                        {
                            if (quartosstandart2[i].disponivel)
                            {
                                printf("Quarto %d\n", quartosstandart2[i].numero);
                            }
                        }

                        printf("Escolha um número de quarto: ");
                        scanf("%d", &escolha_numero_standart2);

                        if (escolha_numero_standart2 < 1 || escolha_numero_standart2 > TOTAL_QUARTOS_STANDART2)
                        {
                            printf("Escolha um número de quarto válido.\n");
                            return 1;
                        }
                        else if (!quartosstandart2[escolha_numero_standart2 - 1].disponivel)
                        {
                            printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                        }
                        else
                        {
                            printf("Digite a data de check-in (entre 1 e 365): ");
                            scanf("%d", &checkin);
                            printf("Digite a data de check-out (entre 1 e 365): ");
                            scanf("%d", &checkout);

                            if (checkin <= 0 || checkin > 365 || checkout <= 0 || checkout > 365 || checkin >= checkout)
                            {
                                printf("Datas de check-in e check-out inválidas.\n");
                                return 1;
                            }
                            else
                            {
                                quartosstandart2[escolha_numero_standart2 - 1].disponivel = false; // Marca o quarto como ocupado.
                                printf("Reserva do quarto realizada com sucesso!\n");
                            }
                        }

                        reservaStandart2[numeroReservasRealizadas_Standart2].quarto_numero = escolha_numero_standart2;
                        reservaStandart2[numeroReservasRealizadas_Standart2].checkin = diaCheckin;
                        reservaStandart2[numeroReservasRealizadas_Standart2].checkout = diaCheckout;

                        printf("Verificação dos dados da reserva: \n");
                        printf("O quarto escolhido foi: %d\n", escolha_numero_standart2);
                        printf("\nQuartos disponíveis:\n");
                        for (int i = 0; i < TOTAL_QUARTOS_STANDART2; i++)
                        {
                            if (quartosstandart2[i].disponivel)
                            {
                                printf("Quarto %d\n", quartosstandart2[i].numero);
                            }
                        }

                        printf("A data do check-in é: %d\n", checkin);
                        printf("A data do check-out é: %d\n", checkout);
                        numeroReservasRealizadas_Standart2++;

                        printf("Opções\n");
                        printf("[0] Digite 0 para voltar ao menu\n");
                        printf("[1] Digite 1 para editar os dados da reserva\n");
                        printf("[2] Digite 2 para excluir a reserva\n");
                        scanf("%d", &opcao_verificacao);

                        if (opcao_verificacao == 0)
                        {
                            break;
                            // Fazer voltar para o menu.
                        }
                        if (opcao_verificacao == 1)
                        {
                            printf("Digite o que deseja editar: \n ");
                            printf("[1] Tipo de Quarto\n");
                            printf("[2] Data de check-in\n");
                            printf("[3] Data de check-out\n");
                            scanf("%d", &opcao_edicao);
                        }
                        if (opcao_edicao == 1)
                        {
                            printf("Digite o novo tipo de quarto\n");
                            printf("[1] Suíte\n");
                            printf("[2] Luxo\n");
                            scanf("%d", &opcao_novotipo);
                            quartosstandart2[escolha_numero_standart2 - 1].disponivel = true;

                            if (opcao_novotipo == 1)
                            {

                                if (escolha_numero_standart2 < 1 || escolha_numero_standart2 > TOTAL_QUARTOS_SUITE2)
                                {
                                    printf("Escolha um número de quarto válido.\n");
                                    return 1;
                                }
                                else if (!quartossuites1[escolha_numero_standart2 - 1].disponivel)
                                {
                                    printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                                }
                                else {
                                    quartossuites1[escolha_numero_standart2 - 1].disponivel = false;
                                printf("Reserva do quarto atualizada com sucesso!\n");
                                }
                                reservaSuite2[numeroReservasRealizadas_Suite2].quarto_numero = escolha_numero_standart2;
                                reservaSuite2[numeroReservasRealizadas_Suite2].checkin = diaCheckin;
                                reservaStandart2[numeroReservasRealizadas_Suite2].checkout = diaCheckout;
                                numeroReservasRealizadas_Suite2++;

                            }
                        }
                        if (opcao_novotipo == 2)
                        {

                            if (escolha_numero_standart2 < 1 || escolha_numero_standart2 > TOTAL_QUARTOS_LUXO2)
                            {
                                printf("Escolha um número de quarto válido.\n");
                                return 1;
                            }
                            else if (!quartosluxo2[escolha_numero_standart2 - 1].disponivel)
                            {
                                printf("Este quarto já está ocupado. Escolha outro quarto.\n");
                            }
                            else {
                                 quartosluxo2[escolha_numero_standart2 - 1].disponivel = false;
                            printf("Reserva do quarto atualizada com sucesso!\n");
                            }
                               
                            reservaLuxo2[numeroReservasRealizadas_Luxo2].quarto_numero = escolha_numero_standart2;
                                reservaLuxo2[numeroReservasRealizadas_Luxo2].checkin = diaCheckin;
                                reservaLuxo2[numeroReservasRealizadas_Luxo2].checkout = diaCheckout;
                                numeroReservasRealizadas_Luxo2++;
                        }

                        if (opcao_edicao == 2)
                        {
                            reservaStandart2[escolha_numero_standart2 - 1].checkin = 0;
                            printf("Digte a nova data do check-in: \n");
                            scanf("%d", &novo_checkin);
                            if (novo_checkin <= 0 || novo_checkin > 365 || checkout <= 0 || checkout > 365 || novo_checkin >= checkout)
                            {
                                printf("Data de check-in inválida.\n");
                            }
                            else
                            {
                                reservaStandart2[numeroReservasRealizadas_Standart2].novo_checkin = diaCheckin;
                                printf("A data do check-in foi atualizada!\n");
                                printf("Verificacao dos dados atualizados:\n");
                                printf("O quarto escolhido foi: %d\n", escolha_numero_standart2);
                                printf("\nQuartos disponíveis:\n");
                                for (int i = 0; i < TOTAL_QUARTOS_STANDART2; i++)
                                {
                                    if (quartosstandart2[i].disponivel)
                                    {
                                        printf("Quarto %d\n", quartosstandart2[i].numero);
                                    }
                                }

                                printf("A data do check-in é: %d\n", novo_checkin);
                                printf("A data do check-out é: %d\n", checkout);
                                numeroReservasRealizadas_Standart2++;
                            }
                        }
                        if (opcao_edicao == 3)
                        {
                            reservaStandart2[escolha_numero_standart2 - 1].checkout = 0;
                            printf("Digte a nova data do check-in: \n");
                            scanf("%d", &novo_checkout);
                            if (checkin <= 0 || checkin > 365 || novo_checkout <= 0 || novo_checkout > 365 || checkin >= novo_checkout)
                            {
                                printf("Data de check-out inválida.\n");
                            }
                            else
                            {
                                reservaStandart2[numeroReservasRealizadas_Standart2].novo_checkout = diaCheckout;
                                printf("A data do check-out foi atualizada!\n");
                                printf("Verificacao dos dados atualizados:\n");
                                printf("O quarto escolhido foi: %d\n", escolha_numero_standart2);
                                printf("\nQuartos disponíveis:\n");
                                for (int i = 0; i < TOTAL_QUARTOS_STANDART2; i++)
                                {
                                    if (quartosstandart2[i].disponivel)
                                    {
                                        printf("Quarto %d\n", quartosstandart2[i].numero);
                                    }
                                }

                                printf("A data do check-in é: %d\n", checkin);
                                printf("A data do check-out é: %d\n", novo_checkout);
                                numeroReservasRealizadas_Standart2++;
                            }
                        }
                        
                 case 3:
            printf("Você escolheu: Sistema de Tarifas\n");
            break;
        default:
            printf("Escolha uma opção válida\n");
            break;