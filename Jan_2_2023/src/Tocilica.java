import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class Tocilica extends Application {
    private static List<Bure> burad = new LinkedList<>();
    private static final Map<Pivo, Double> mapa = new TreeMap<>();

    public static void main(String[] args) {
        try {
            List<String> linije = Files.readAllLines(Paths.get("piva.txt"));
            for(String linija : linije){
                String[] arr = linija.split(" ", 0);
                double kolicina, abv;
                String naziv, zemlja;
                kolicina = Double.parseDouble(arr[1]);
                abv = Double.parseDouble(arr[3]);
                naziv = String.valueOf(arr[2]);
                zemlja = String.valueOf(arr[4]);
                if(arr[0].equals("Lager")){
                    Lager l = new Lager(zemlja, naziv, abv);
                    Bure<Lager> b = new Bure<>(l, kolicina);
                    burad.add(b);
                    mapa.put((Pivo)l, 0.0);
                }else if(arr[0].equals("Psenicno")){
                    int psenica = Integer.parseInt(arr[5]);
                    Psenicno p = new Psenicno(zemlja, naziv, abv, psenica);
                    Bure<Psenicno> b = new Bure<>(p, kolicina);
                    burad.add(b);
                    mapa.put((Pivo)p, 0.0);
                }else{
                    int ibu = Integer.parseInt(arr[5]);
                    IPA i = new IPA(zemlja, naziv, abv, ibu);
                    Bure<IPA> b = new Bure<>(i, kolicina);
                    burad.add(b);
                    mapa.put((Pivo)i, 0.0);
                }
            }
            launch(args);
        } catch (IOException e){
            throw new RuntimeException(e);
        }
    }
    public void start(Stage stage) throws Exception {
        HBox root = new HBox(10);
        root.setPadding(new Insets(10, 10, 10, 10));

        VBox levo = new VBox(10);
        VBox desno = new VBox(10);
        HBox mali = new HBox(10);
        RadioButton psenica = new RadioButton("Psenicno");
        RadioButton lag = new RadioButton("Lager");
        RadioButton ipa = new RadioButton("IPA");
        ToggleGroup tg = new ToggleGroup();
        lag.setToggleGroup(tg);
        ipa.setToggleGroup(tg);
        psenica.setToggleGroup(tg);
        HBox unos = new HBox(10);
        Label litri = new Label("L");
        TextField litar = new TextField();
        TextArea prikaz = new TextArea();
        prikaz.setEditable(false);
        Label vrsta = new Label("Vrsta piva:");
        Button natoci = new Button("Natoci");
        Button stanje = new Button("Stanje na tocilici");
        Button popijeno = new Button("Popijeno");
        unos.getChildren().addAll(litar, litri);
        mali.getChildren().addAll(stanje, popijeno);
        mali.setAlignment(Pos.CENTER);
        levo.getChildren().addAll(prikaz, mali);
        desno.getChildren().addAll(vrsta, lag, psenica, ipa, unos, natoci);
        root.getChildren().addAll(levo, desno);

        stanje.setOnAction(e-> {
                Collections.sort(burad);
                StringBuilder string = new StringBuilder();
                for(Bure b : burad){
                    string = string.append(b.toString() + "\n");
                }
                prikaz.setText(String.valueOf(string));
        });

        popijeno.setOnAction(e-> {
            List<Bure> sortirano = new ArrayList<>();
            for(Map.Entry<Pivo, Double> entry : mapa.entrySet()){
                sortirano.add(new Bure(entry.getKey(), entry.getValue()));
            }
            Comparator<Bure> comparator = new Comparator<Bure>() {
                public int compare(Bure o1, Bure o2) {
                    if(o1.getKolicina() == o2.getKolicina()) return 0;
                    else if(o1.getKolicina() < o2.getKolicina())return 1;
                    else return -1;
                }
            };
            StringBuilder string = new StringBuilder("Popijeno je:"+'\n');
            Collections.sort(sortirano, comparator);
            for(int i = 0; i < sortirano.size(); i++) {
                string.append(sortirano.get(i).getKolicina() + " litara " +
                        sortirano.get(i).getPivo().toString() + '\n');
            }
            prikaz.setText(String.valueOf(string));
        });

        natoci.setOnAction(e-> {
            String kol = litar.getText();
            if(kol.isEmpty())
                return;
            double kolicina = Double.parseDouble(kol);
            if(kolicina <= 0.0) return;
            String tip = new String();
            if(lag.isSelected()){
                tip = String.copyValueOf("Lager".toCharArray());
            }
            else if(psenica.isSelected()){
                tip = String.copyValueOf("Psenicno".toCharArray());
            }else if(ipa.isSelected()){
                tip = String.copyValueOf("IPA".toCharArray());
            }else return;
            int index = 0;
            for(index = 0;index < burad.size(); index++){
                Bure b = burad.get(index);
                if((tip.equals("IPA") && b.getPivo() instanceof IPA) ||
                        (tip.equals("Lager") && b.getPivo() instanceof Lager) ||
                        (tip.equals("Psenicno") && b.getPivo() instanceof Psenicno)){
                    if(b.dovoljnoZaTocenje(kolicina)) break;
                }
            }
            if(index == burad.size()){
                prikaz.setText("Nema dovoljno piva na stanju!");
                return;
            }
            Bure b = burad.get(index);
            StringBuilder str = new StringBuilder("Natocili ste " + kolicina + "litara " +
                    b.getPivo().toString() + '\n' + "Vas racun je " + b.getPivo().cena(kolicina)+ " din");
            prikaz.setText(String.valueOf(str));
            b.setKolicina(b.getKolicina()-kolicina);
            burad.set(index, b);
            Double k = mapa.get(b.getPivo());
            mapa.remove(b.getPivo());
            mapa.put(b.getPivo(),kolicina+k);
        });

        Scene scene = new Scene(root, 500,650);
        stage.setTitle("Tocilica");
        stage.setScene(scene);
        stage.show();
    }
}
