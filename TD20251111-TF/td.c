/*
============================================================
 ÉVALUATION DU CODE
------------------------------------------------------------
Points positifs
- Les unités sont cohérentes (conversion de D en mètres correcte).
- L’affichage du tableau est clair et lisible (positions, vitesses, écart).
- Les formules de cinématique pendant l’accélération sont bien appliquées 
  (x = 1/2 a t², v = a t).

Problèmes majeurs / non conformité au cahier des charges
1) Calcul de meetingT incorrect :
   - La ligne `meetingT = (D - 182.35)/(13.3 + 10.4)` repose sur des constantes arbitraires.
   - Le programme doit simuler seconde par seconde jusqu’à ce que les trains se croisent,
     puis calculer l’instant exact du croisement (avec fraction de seconde).
   - ⇒ Il faut supprimer `meetingT` et la formule correspondante, et boucler 
     jusqu’à détection du croisement.

2) Bornes d’accélération erronées :
   - Vous testez `i <= 10` et `i <= 20`. Si l’accélération dure 10 s, 
     elle doit être appliquée pour 0 ≤ t < 10, et non à t = 10.
   - ⇒ Conditions correctes : `if (i < 10)` pour A, `if (i < 20)` pour B.

3) Absence de calcul exact du croisement :
   - Le programme doit, dès que l’écart devient ≤ 0 entre deux secondes n et n+1,
     interpoler l’instant exact τ ∈ [0,1] dans cet intervalle.
   - On résout : 0.5 a_rel τ² + v_rel τ − s0 = 0 (ou τ = s0 / v_rel si a_rel ≈ 0),
     avec s0 = D − (xA_n + xB_n), v_rel = vA_n + vB_n, a_rel = aA + aB.
   - Puis : t_exact = n + τ, dA = xA_n + vA_n τ + 0.5 aA τ², et idem pour B.

4) Constante DT non utilisée :
   - `DELTA_TIME` est définie mais jamais employée, et de type `int`.
   - ⇒ Déclarer `const double DT = 1.0;` et l’utiliser dans les mises à jour
     (positions, vitesses, incrément du temps).

5) Méthode d’intégration incohérente :
   - Pendant l’accélération, vous recalculez directement x(t) et v(t) à l’instant i,
     puis, après, vous ajoutez simplement la vitesse (`position += speed`).
   - Cela fonctionne pour Δt = 1 s, mais le cahier des charges attend une approche uniforme :
     x_{k+1} = x_k + v_k*DT + 0.5*a*DT² ; v_{k+1} = v_k + a*DT.
   - ⇒ Cette forme est plus claire et fidèle à la cinématique.

Points de style / qualité
- Préférez des noms explicites avec unités : `posA_m`, `vB_ms`, `D_m`.
- Pensez à afficher explicitement la ligne t=0 (déjà présent via i=0, c’est bien).
- Évitez les nombres magiques (182.35, 13.3, 10.4).

Ce qu’il faut corriger pour valider le cahier des charges
- Supprimer `meetingT` et boucler jusqu’à `ecart <= 0`.
- Corriger les bornes d’accélération (`<` au lieu de `<=`).
- Mettre à jour positions et vitesses avec Δt et les formules correctes.
- Ajouter le calcul exact du croisement dans le dernier intervalle et afficher :
  t exact, distance parcourue par A, distance parcourue par B.
- Conserver l’affichage à chaque seconde (t, pA, vA, pB, vB, écart).

Verdict
- Travail partiel : la simulation et l’affichage sont présents,
  mais la logique d’arrêt, le calcul exact du croisement et certaines bornes
  doivent être corrigés pour répondre pleinement au cahier des charges.

============================================================
*/


#include <stdio.h>
#include <math.h>

int main(void)
{
    // Constante
    const double ACCEL_A = 1.33;
    const double ACCEL_TIME_A = 10;
    const double ACCEL_B = 0.52;
    const double ACCEL_TIME_B = 20;
    const int DELTA_TIME = 1;

    // Variables
    double D = 0;
    double meetingT = 0;
    double positionA = 0;
    double speedA = 0;
    double positionB = 0;
    double speedB = 0;
    double remainingD = 0;


    // Input
    printf("Distance entre gares D (km) : ");
    scanf("%lf", &D);
    
    
    D *= 1000; // Convert to meter
    meetingT = (D - 182.35)/(13.3 + 10.4); // ???Redo

    printf("\n");
    printf(" t        pA(m)    vA(m/s)        pB(m)    vB(m/s)     ecart(m)\n");

    for(int i = 0; i < meetingT; i++)
    {
        if (i <= 10)
        {
            positionA = 0.5 * ACCEL_A * (i * i); // d = (v₀ t) + (½ a * t²)
            speedA = ACCEL_A * i;
        }

        else
        {
            positionA += speedA;
        }

        if (i <= 20)
        {
            positionB = 0.5 * ACCEL_B * (i * i);
            speedB = ACCEL_B * i;
        }

        else
        {
            positionB += speedB;
        }

        remainingD = D - positionA - positionB;
        
        printf("%2d", i);
        printf("%13.1lf", positionA);
        printf("%11.2lf", speedA);
        printf("%13.1lf", positionB);
        printf("%11.2lf", speedB);
        printf("%13.1lf\n", remainingD);
    }

    printf("\n");
    printf("=== RENCONTRE ===\n");
    printf("t = "); // TODO
    printf("Positions: pA = m, pB = m"); // TODO

    return 0;
}