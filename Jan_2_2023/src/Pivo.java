import java.text.DecimalFormat;

public abstract class Pivo implements Comparable<Pivo>{
    String zemljaPorekla, naziv;
    double abv;

    public Pivo(String zemljaPorekla, String naziv, double abv) {
        this.zemljaPorekla = zemljaPorekla;
        this.naziv = naziv;
        this.abv = abv;
    }

    public String getZemljaPorekla() {
        return zemljaPorekla;
    }

    public String getNaziv() {
        return naziv;
    }

    public double getAbv() {
        return abv;
    }
    abstract double cena(double kolicina);

    @Override
    public String toString() {
        DecimalFormat dec = new DecimalFormat("#.##");
        return "("+zemljaPorekla+") "+naziv+" "+ dec.format(abv)+"%";
    }
    public int compareTo(Pivo p){
        if(zemljaPorekla.equals(p.getZemljaPorekla())){
            double drugi = p.getAbv();
            if(drugi == abv) return 0;
            return (abv > drugi)? 1 : -1;
        }
        else return zemljaPorekla.compareTo(p.getZemljaPorekla());
    }
}
