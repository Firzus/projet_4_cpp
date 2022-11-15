class Biberon
{
public:
    void creerRappel(int m_heure_prise, int m_intervalle_rappel);
    void rejouterHeureDePrise(int m_heure_prise, int m_intervalle_rappel);
    void rajouterQuantiteDeLaitIngeree(int quantite_restante, int m_quantite_min);
    bool regurgiteBiberon();

private:
    int m_intervalle_rappel;
    int m_biberon_max;
    int m_quantite_lait_ingere;
    int m_heure_prise;
    int m_quantite_min;
    int m_quantite_restante;
};