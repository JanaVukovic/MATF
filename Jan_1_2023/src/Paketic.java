import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Paketic {
    Dete dete;
    int budzet;
    List<Poklon> pokloni = new ArrayList<>();

    public Paketic(Dete dete, int budzet) {
        this.dete = dete;
        this.budzet = budzet;
    }
    public void napuniPaketic(List<UredjeniPar<Poklon, Integer>> spisakPoklona){
        int min = -1;
        int n = spisakPoklona.size();
        for(int i = 0; i < n; i++){
            if(min == -1) min = spisakPoklona.get(i).getPrvi().getCena();
            if(min > spisakPoklona.get(i).getPrvi().getCena()){
                min = spisakPoklona.get(i).getPrvi().getCena();
            }
        }
        Random rand = new Random();
        int trenutnaCena;
        int nasumican;
        while(budzet >= min){
            nasumican = rand.nextInt(n) % n;
            trenutnaCena = spisakPoklona.get(nasumican).getPrvi().getCena();
            if(trenutnaCena <= budzet && spisakPoklona.get(nasumican).getPrvi().prikladanPoklon(dete.pol)){
                UredjeniPar<Poklon, Integer> par = new UredjeniPar<>(spisakPoklona.get(nasumican).getPrvi(),
                        spisakPoklona.get(nasumican).getDrugi()+1);
                spisakPoklona.set(nasumican, par);
                budzet -= trenutnaCena;
            }
        }
        for(int i = 0; i < n; i++){
            if(spisakPoklona.get(i).getDrugi() > 0){
                pokloni.add(spisakPoklona.get(i).getPrvi());
            }
        }
    }

    @Override
    public String toString() {
        StringBuilder text = new StringBuilder("Paketic za dete:" + dete.toString() + '\n' + '\n');
        for(Poklon p : pokloni){
            text.append(p.toString());
            text.append('\n');
        }
        return String.valueOf(text);
    }
}
