public class Igracka extends Poklon{
    VrstaIgracke vrsta;

    public Igracka(String naziv, String ID, int cena, VrstaIgracke vrsta) {
        super(naziv, ID, cena);
        this.vrsta = vrsta;
    }

    @Override
    public boolean prikladanPoklon(PolDeteta polDeteta) {
        return (vrsta.getSkracenica() == polDeteta.getSkracenica()
                || vrsta.equals(VrstaIgracke.NEUTRALNA));
    }
}
