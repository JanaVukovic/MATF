public class Slanis extends Poklon{
    public Slanis(String naziv, String ID, int cena) {
        super(naziv, ID, cena);
    }

    @Override
    public boolean prikladanPoklon(PolDeteta polDeteta) {
        return true;
    }
}
