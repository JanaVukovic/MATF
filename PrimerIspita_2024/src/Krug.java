public class Krug extends GeometrijskaFigura implements Ispis{
    double poluprecnik;

    public Krug(String ime, double poluprecnik) {
        super(ime);
        this.poluprecnik = poluprecnik;
    }

    @Override
    public double povrsina() {
        return Math.PI*this.poluprecnik*this.poluprecnik;
    }

    @Override
    public void prikazi() {
        System.out.println("Krug " + ime + " : r = " + poluprecnik);
    }
}
