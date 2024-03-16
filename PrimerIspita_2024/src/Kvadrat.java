public class Kvadrat extends GeometrijskaFigura implements Ispis{
    double duzinaStranice;

    public Kvadrat(String ime, double duzinaStranice) {
        super(ime);
        this.duzinaStranice = duzinaStranice;
    }

    @Override
    public double povrsina() {
        return this.duzinaStranice*this.duzinaStranice;
    }

    @Override
    public void prikazi() {
        System.out.println("Kvadrat " + ime + " : a = " + duzinaStranice);
    }
}
