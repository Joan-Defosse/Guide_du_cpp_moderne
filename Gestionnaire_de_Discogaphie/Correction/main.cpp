#include "utils.hpp"
#include "donnees_disco_tests.hpp"
#include "discographie.hpp"
#include "systeme_commandes.hpp"

#include <stdexcept>

int main()
{
    // Tests unitaires :
    test_creation_morceau_entree_complete();
    test_creation_morceau_entree_espaces_partout();
    test_creation_morceau_entree_vide();
    test_creation_morceau_entree_chanson_artiste();
    test_creation_morceau_entree_chanson_uniquement();

    // Principal :
    Discographie discographie{};

    bool continuer{ true };
    do
    {
        try
        {
            std::string entree{ recuperer_commande() };
            auto [commande, instructions] { analyser_commande(entree) };
            instructions = traitement_chaine(instructions);
            continuer = executer_commande(discographie, commande, instructions);
        }
        catch (std::runtime_error const& exception)
        {
            std::cout << "Erreur : " << exception.what() << std::endl;
        }

    } while (continuer);


    return 0;
}