#include "story.h"
#include "../LinkedList/linkedlist.h"
#include "../DoubleLinkedList/doubleLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

// -- PROTOTYPES -- //

Scene *stuk_2;
Scene *stuk_3;
Scene *stuk_4;
Scene *stuk_5;
Scene *stuk_6;
Scene *stuk_7;
Scene *stuk_8;
Scene *stuk_9;
Scene *stuk_10;
Scene *stuk_11;
Scene *stuk_12;
Scene *stuk_13;
Scene *stuk_14;
Scene *stuk_15;
Scene *stuk_16;
Scene *stuk_17;
Scene *stuk_18;
Scene *stuk_19;
Scene *stuk_20;
Scene *stuk_21;
Option *option;

// -- END OF PROTOTYPES -- //

void setupStory()
{

    // ----------- setup of the `scene's` --------- //
    first = newScene("Jij bent Zafir, geboren te Herat. Je bent 43 jaar.\n"
                     "Door een aanslag van de Taliban, ben jij jouw familie kwijtgeraakt.\n"
                     "Door het verder oprukken van de Taliban, besluit jij om het land uit te vluchten.\n\n\n"
                     "Ik wist altijd al dat de taliban terug zou komen. Het was haast onvermijdelijk.\n"
                     "In de tijd dat de Taliban minder prominent, mochten mijn vrouw en\n"
                     "dochter vrij naar school en zonder man over straat lopen.\n"
                     "Sinds de aanslag is er veel veranderd in mijn leven: mijn huis is verwoest; ik ben mijn\n"
                     "familie kwijt en heb sindsdien veel verdriet en angst. Vanaf dit moment komt het vaak\n"
                     "in mijn gedachten dat ik wil vluchten.\n"
                     "Nu is alleen de vraag: hoe?");

    stuk_2 = newScene("Wellicht is het een optie om zelf te gaan vluchten, alleen weet ik nog niet waarheen?");
    stuk_3 = newScene("Ik zou door een smokkelaar Europa in kunnen worde gebracht. Alleen hoe wil ik in Europa komen?");
    stuk_4 = newScene("Misschien is het een goed idee als ik in de buurt van Afghanistan blijf.\n"
                      "Dus naar welk land zal ik gaan?");

    stuk_5 = newScene("Naar Europa klinkt als een goed idee, daarlijkt het me veilig!\n"
                      "Hoe zal ik Europa binnen proberen te komen?");

    stuk_6 = newScene("Ik kan ook direct naar Nederland middels het NL Actief Evacuatieplan!\n"
                      "Helaas kom ik hier niet voor in aanmerking.");

    stuk_7 = newScene("Na een lange, zware tocht is het gelukt om de grens van Turkije te bereiken en\n"
                      "omdat jij jouw paspoort bij je had, mocht je turkije ook binnenkomen\n\n"
                      "Ik ben nu in Turije! Hoe zal ik verder gaan? Griekenland of over de Zwarte Zee?");

    stuk_8 = newScene("Op wonderbaarlijke wijze is het me gelukt om door Iran heen in Syrië terecht te\n"
                      "komen en met de boot in Italië. Voor de kust zelf kapseisde de boot, maar gelukkig\n"
                      "waren we gered door de kustwacht. Ook ben ik in Italië in een Asielzoekerscentrum\n"
                      "terecht gekomen.Op wonderbaarlijke ");

    stuk_9 = newScene("Na een zware tocht is het me uiteindelijk toch gelukt om de grens van Turkije te bereiken.\n"
                      "Wil ik nu Turkije binnengaan of voor de grens blijven in een kamp?");

    stuk_10 = newScene("Je blijft voor de grens van Turkije in een kamp zitten. Hier blijf je circa 3 jaar en\n"
                       "vervolgens keer je weer terug naar Afghanistan waar jij jouw oude werk weer oppakt.\n"
                       "In Afghanistan is de rust weer wedergekeerd. Het begint zelfs werkelijk een\n"
                       "welvarend land te worden.");

    stuk_11 = newScene("Het lukt je om via Turkije Griekenland binnen te komen omdat je een paspoort hebt.\n"
                       "Je kiest ervoor om in Griekenland te blijven omdat het je daar redelijk bevalt. Hier\n"
                       "bouw jij opnieuw jouw leven op: je krijgt een baan en wordt hierdoor gelukkig.");

    stuk_12 = newScene("Ik ga kijken of ik verder Europa in kan komen.\n"
                       "Zal ik Nederland in proberen te komen of Duitsland?");

    stuk_13 = newScene("Het lijkt met best handig als ik hier papieren ga aanvragen. Zal ik op een legale\n"
                       "manier aan papieren komen of op illegale wijze?");

    stuk_14 = newScene("Wellicht is ‘t het beste als de Italiaanse overheid niet weet dat ik een illegale\n"
                       "immigrant ben.\n"
                       "Ik zal dus kijken of ik ergens aan illegale papieren kan komen.\n"
                       "Zal ik hierna naar Nederland of Duitsland gaan?");

    stuk_15 = newScene("Je kijkt of je papieren kan aanvragen bij een gemeentehuis in de buurt. Alleen vindt\n"
                       "het bestuur het niet acceptabel dat een illegale zo het land binnen is gekomen.\n"
                       "Je wordt opgesloten in een gevangenis onder dermate slechte omstandigheden dat\n"
                       "je in je cel komt te overlijden.");

    stuk_16 = newScene("Het is me gelukt om via Turkije in Griekenland te komen.\n"
                       "Er vond een herverdeling van Immigranten plaats en hierdoor ben ik in Oostenrijk\n"
                       "terecht gekomen. Het lukt mij om de Duitse taal te leren en een succesvolle toekomst\n"
                       "op te bouwen.");

    stuk_17 = newScene("Het lukte mij om via de Zwarte Zee in Wit-Rusland te komen en via Wit-Rusland in\n"
                       "Polen. Zal ik nu naar Nederland gaan of Duitsland?");

    stuk_18 = newScene("Je gaat naar Duitsland om daar een toekomst op te bouwen. Je leert de Duitse taal\n"
                       "en je gaat werken. Het lukt je om succesvol en gelukkig te worden.");

    stuk_19 = newScene("Je gaat naar Nederland om daar een toekomst op te bouwen. Je leert de\n"
                       "Nederlandse taal en je gaat werken. Het lukt je om succesvol en gelukkig te worden.");

    stuk_20 = newScene("Je besloot om in de regio te blijven en naar Pakistan te gaan. Het leek jou veiliger\n"
                       "dan Afghanistan en dit bleek ook zo te zijn. In Pakistan probeer je een toekomst op\n"
                       "te bouwen, je krijgt er werk én het lukt je zelfs om weer een familie op te bouwen.");

    stuk_21 = newScene("Je besloot om door Pakistan naar India te gaan en daar een nieuw leven op te\n"
                       "bouwen. Het lukte je om er werk te vinden en vrienden te maken.");

    // ----------- setup of the `Options` --------- //
    // first scene
    option = newOption("Zelf vluchten", "paspoort", NULL, stuk_2, basicHandler);
    list_append(first->options, option);
    option = newOption("Gesmokkeld worden", NULL, NULL, stuk_3, basicHandler);
    list_append(first->options, option);

    // stuk_2
    option = newOption("In de region blijven", NULL, NULL, stuk_4, basicHandler);
    list_append(stuk_2->options, option);
    option = newOption("Buiten de regio gaan", NULL, "paspoort", stuk_5, basicHandler);
    list_append(stuk_2->options, option);

    // stuk _3
    option = newOption("Richting Syrie en dan met de boot naar Italie", NULL, NULL, stuk_8, basicHandler);
    list_append(stuk_3->options, option);
    option = newOption("Richting Turijke en dan over land naar Griekenland", NULL, NULL, stuk_9, basicHandler);
    list_append(stuk_3->options, option);

    // stuk_4
    option = newOption("Pakistan", NULL, NULL, stuk_20, basicHandler);
    list_append(stuk_4->options, option);
    option = newOption("India", NULL, NULL, stuk_21, basicHandler);
    list_append(stuk_4->options, option);

    // stuk 5
    option = newOption("NL Actief Evacuatieplan", NULL, NULL, stuk_6, basicHandler);
    list_append(stuk_5->options, option);
    option = newOption("Via Turkije", NULL, NULL, stuk_7, basicHandler);
    list_append(stuk_5->options, option);

    // stuk 6
    option = newOption("Alsnog gesmokkeld gaan", NULL, NULL, stuk_3, basicHandler);
    list_append(stuk_6->options, option);
    option = newOption("Alsnog via Turkije", NULL, NULL, stuk_7, basicHandler);
    list_append(stuk_6->options, option);

    // stuk 7
    option = newOption("Via Griekenland in de EU komen", NULL, NULL, stuk_16, basicHandler);
    list_append(stuk_7->options, option);
    option = newOption("Over de Zwarte Zee via Wit-Rusland Polen binnen gaan", NULL, NULL, stuk_17, basicHandler);
    list_append(stuk_7->options, option);

    // stuk 8
    option = newOption("Verder Europa in", NULL, "paspoort", stuk_12, basicHandler);
    list_append(stuk_8->options, option);
    option = newOption("Papieren aanvragen in Italie", NULL, NULL, stuk_13, basicHandler);
    list_append(stuk_8->options, option);

    // stuk 9
    option = newOption("Turkije binnengaan", NULL, "paspoort", stuk_11, basicHandler);
    list_append(stuk_9->options, option);
    option = newOption("Voor de grens blijven", NULL, NULL, stuk_10, basicHandler);
    list_append(stuk_9->options, option);

    // stuk 10

    // stuk 11

    // stuk 12
    option = newOption("Duitsland", NULL, NULL, stuk_18, basicHandler);
    list_append(stuk_12->options, option);
    option = newOption("Nederland", NULL, NULL, stuk_19, basicHandler);
    list_append(stuk_12->options, option);

    // stuk 13
    option = newOption("Illegale", "paspoort", NULL, stuk_14, basicHandler);
    list_append(stuk_13->options, option);
    option = newOption("Legale", NULL, NULL, stuk_15, basicHandler);
    list_append(stuk_13->options, option);

    // stuk 14
    option = newOption("Duitsland", NULL, NULL, stuk_18, basicHandler);
    list_append(stuk_14->options, option);
    option = newOption("Nederland", NULL, NULL, stuk_19, basicHandler);
    list_append(stuk_14->options, option);

    // stuk 15

    // stuk 16

    // stuk 17
    option = newOption("Duitsland", NULL, NULL, stuk_18, basicHandler);
    list_append(stuk_17->options, option);
    option = newOption("Nederland", NULL, NULL, stuk_19, basicHandler);
    list_append(stuk_17->options, option);

    // stuk 18

    // stuk 19

    // stuk 20

    // stuk 21
}