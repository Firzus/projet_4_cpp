class Biberon
{
public:
    void reglerBiberonMax(int biberonMax);
    void reglerHeureDePrise(int heurePrise);
    void prochainBiberon(int intervalleDeRappel);
    void quantiteLaitIngere(int quantiteLaitIngere);

private:
    int m_temps_apres_regurgitation;
    bool m_regurgite_biberon;
};