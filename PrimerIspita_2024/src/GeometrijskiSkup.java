import java.lang.reflect.Array;

public class GeometrijskiSkup {
    GeometrijskaFigura[] niz;

    public GeometrijskiSkup(GeometrijskaFigura[] niz) {
        this.niz = niz;
    }

    public GeometrijskaFigura[] getNiz() {
        return niz;
    }

    public double ukupnaPovrsina(){
        double S = 0;
        int n = niz.length;
        for(int i = 0; i < n ; i ++){
            S += niz[i].povrsina();
        }
        return S;
    }
}
