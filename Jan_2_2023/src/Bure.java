import java.text.DecimalFormat;
import java.util.Comparator;

public class Bure<T extends Pivo> implements Comparable{
    T pivo;
    double kolicina;

    public Bure(T pivo, double kolicina) {
        this.pivo = pivo;
        this.kolicina = kolicina;
    }

    public T getPivo() {
        return pivo;
    }

    public double getKolicina() {
        return kolicina;
    }

    public void setKolicina(double kolicina) {
        this.kolicina = kolicina;
    }

    boolean dovoljnoZaTocenje(double kolicina){
        if(this.kolicina >= (kolicina + 0.5)) return true;
        else return false;
    }
    public double natoci(double kolicina) throws UnsupportedOperationException{
        if(!dovoljnoZaTocenje(kolicina))
            throw new UnsupportedOperationException("Nema dovoljno!");
        else{
            this.kolicina -= kolicina;
            return pivo.cena(kolicina);
        }
    }

    @Override
    public String toString() {
        DecimalFormat dec = new DecimalFormat("#.#");
        return dec.format(kolicina)+"L " + pivo.toString();
    }

    @Override
    public int compareTo(Object o) {
        return this.getPivo().compareTo(((Bure<?>)o).getPivo());
    }
}
