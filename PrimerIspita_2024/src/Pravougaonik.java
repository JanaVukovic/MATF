public class Pravougaonik extends GeometrijskaFigura implements Ispis{
    double duzina, visina;

    public Pravougaonik(String ime, double duzina, double visina) {
        super(ime);
        this.duzina = duzina;
        this.visina = visina;
    }

    @Override
    public double povrsina() {
        return this.visina*this.duzina;
    }

    @Override
    public void prikazi() {
        System.out.println("Pravougaonik "+ime+" : a = " + duzina + " b = "+ visina);
    }
}
