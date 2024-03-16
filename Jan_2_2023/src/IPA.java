import java.text.DecimalFormat;

public class IPA extends Pivo{
    int IBU;

    public IPA(String zemljaPorekla, String naziv, double abv, int IBU) {
        super(zemljaPorekla, naziv, abv);
        this.IBU = IBU;
    }

    @Override
    double cena(double kolicina) {
        return (400.0*kolicina + (double)2*IBU);
    }

    @Override
    public String toString() {
        DecimalFormat dec = new DecimalFormat("#.##");
        return "("+zemljaPorekla+") "+naziv+" "+ dec.format(abv)+"% "+ "IBU" + IBU;
    }
}
