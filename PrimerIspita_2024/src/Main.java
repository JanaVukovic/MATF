public class Main {
    public static void main(String[] args) {
        GeometrijskaFigura[] niz = {
                new Krug("Sunce", 100), new Pravougaonik("Sundjer Bob", 13,8),
                new Kvadrat("Blok", 8), new Krug("Krusko", 5.6)};
        GeometrijskiSkup gs = new GeometrijskiSkup(niz);
        System.out.println("Ukupna povrsina = " + gs.ukupnaPovrsina());
        for(GeometrijskaFigura g : gs.getNiz()){
            g.prikazi();
        }
    }
}
