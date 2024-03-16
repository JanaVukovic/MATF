import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class DedaMraz extends Application {
    public static List<Paketic> paketici = new ArrayList<>();
    public static List<UredjeniPar<Poklon, Integer>> spisakPoklona = new ArrayList<>();
    public static void main(String[] args) {
        launch(args);
    }

    public void start(Stage primaryStage) {
        HBox root = new HBox(10);
        VBox levo = new VBox(10);
        VBox desno = new VBox(10);
        HBox dole = new HBox(10);
        root.setPadding(new Insets(10, 10, 10, 10));
        Label lbIme = new Label("Ime i prezime:");
        Label lbPol = new Label("Pol deteta:");
        Label lbBudzet = new Label("Budzet za paketic:");
        ToggleGroup tPol = new ToggleGroup();
        RadioButton rbM = new RadioButton("Muski");
        RadioButton rbZ = new RadioButton("Zenski");
        rbM.setToggleGroup(tPol);
        rbZ.setToggleGroup(tPol);
        TextField ime = new TextField();
        TextField budzet = new TextField();
        TextArea spisak = new TextArea();
        spisak.setEditable(false);
        Button napuni = new Button("Napuni paketic");
        Button ucitaj = new Button("Ucitaj poklone");
        Button prikaz = new Button("Prikazi spisak za Deda Mraza");
        dole.getChildren().addAll(ucitaj, prikaz);
        desno.getChildren().addAll(spisak, dole);
        levo.getChildren().addAll(lbIme, ime, lbPol, rbM, rbZ, lbBudzet, budzet, napuni);
        root.getChildren().addAll(levo, desno);
        Scene scene = new Scene(root, 500, 700);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Deda Mrazov pomocnik");
        prikaz.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent actionEvent) {
                StringBuilder text = new StringBuilder();
                for(UredjeniPar<Poklon, Integer> k : spisakPoklona){
                    text.append(k.getPrvi().toString()).append(" - kom ").append(k.getDrugi().toString()).append('\n');
                }
                spisak.setText(text.toString());
            }
        });
        ucitaj.setOnAction(new EventHandler<ActionEvent>(){
            @Override
            public void handle(ActionEvent actionEvent) {
                ucitaj.setDisable(true);
                Path ulaz = Paths.get("pokloni.txt");
                try {
                    List<String> linije = Files.readAllLines(ulaz, StandardCharsets.UTF_8);
                    String[] jedan;
                    for (String linija: linije){
                        jedan = linija.split(", ", 0);
                        System.out.println(Arrays.toString(jedan));
                        if(jedan[0].charAt(0) == 'I'){
                            if(jedan[0].charAt(1) == 'M'){
                                Igracka k = new Igracka(jedan[1], jedan[0], Integer.parseInt(jedan[2]), VrstaIgracke.MUSKA);
                                UredjeniPar<Poklon, Integer> to = new UredjeniPar<>(k, 0);
                                spisakPoklona.add(to);
                            }
                            else if(jedan[0].charAt(1) == 'Z'){
                                Igracka k = new Igracka(jedan[1], jedan[0], Integer.parseInt(jedan[2]), VrstaIgracke.ZENSKA);
                                UredjeniPar<Poklon, Integer> to = new UredjeniPar<>(k, 0);
                                spisakPoklona.add(to);
                            }else{
                                Igracka k = new Igracka(jedan[1], jedan[0], Integer.parseInt(jedan[2]), VrstaIgracke.NEUTRALNA);
                                UredjeniPar<Poklon, Integer> to = new UredjeniPar<>(k, 0);
                                spisakPoklona.add(to);
                            }
                        }else if(jedan[0].charAt(1) == 'T'){
                            Slatkis k = new Slatkis(jedan[1], jedan[0], Integer.parseInt(jedan[2]));
                            UredjeniPar<Poklon, Integer> to = new UredjeniPar<>(k, 0);
                            spisakPoklona.add(to);
                        }else{
                            Slanis k = new Slanis(jedan[1], jedan[0], Integer.parseInt(jedan[2]));
                            UredjeniPar<Poklon, Integer> to = new UredjeniPar<>(k, 0);
                            spisakPoklona.add(to);
                        }
                    }
                } catch (IOException e) {
                    System.err.println("Neuspelo otvaranje ulazne datoteke!");
                    e.printStackTrace();
                }
            }
        });
        napuni.setOnAction(new EventHandler<ActionEvent>() {
               @Override
               public void handle(ActionEvent event) {
                   if (napuni.isDisabled()) {
                       spisak.setText("Nije ucitan spisak poklona!");
                       return;
                   }
                   String ImePrezime = ime.getText();
                   if (ImePrezime.isEmpty()) {
                       spisak.setText("Molimo unesite neki tekst.");
                       return;
                   }
                   PolDeteta pol = PolDeteta.odSkracenice('N');
                   if (rbZ.isSelected()) {
                       pol = PolDeteta.odSkracenice('Z');
                   } else if (rbM.isSelected()) {
                       pol = PolDeteta.odSkracenice('M');
                   }
                   String Novac = budzet.getText();
                   int novac;
                   if (Novac.isEmpty()) {
                       spisak.setText("Molimo unesite neki broj.");
                       return;
                   } else {
                       try {
                           novac = Integer.parseInt(Novac);
                       } catch (NumberFormatException e) {
                           spisak.setText("Molimo unesite broj.");
                           return;
                       }
                   }
                   Dete k = new Dete(ImePrezime, pol);
                   Paketic pak = new Paketic(k, novac);
                   pak.napuniPaketic(spisakPoklona);
                   paketici.add(pak);
                   spisak.setText(pak.toString());
               }
        });
        primaryStage.show();
    }
}
