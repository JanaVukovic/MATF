public class Psenicno extends Pivo{
    int procenatPsenice;

    public Psenicno(String zemljaPorekla, String naziv, double abv, int procenatPsenice) {
        super(zemljaPorekla, naziv, abv);
        this.procenatPsenice = procenatPsenice;
    }

    @Override
    double cena(double kolicina) {
        return (300.0*kolicina + 10.0*abv + procenatPsenice);
    }
}
