public class Lager extends Pivo{
    public Lager(String zemljaPorekla, String naziv, double abv) {
        super(zemljaPorekla, naziv, abv);
    }
    @Override
    double cena(double kolicina) {
        return (kolicina*200)+10*abv;
    }
}
