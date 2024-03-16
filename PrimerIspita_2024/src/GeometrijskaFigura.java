public abstract class GeometrijskaFigura implements Ispis{
    String ime;

    public GeometrijskaFigura(String ime) {
        this.ime = ime;
    }

    public abstract double povrsina();
}
