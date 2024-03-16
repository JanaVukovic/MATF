import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Hackathon extends Application {
    public static List<Tim> timovi = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        try {
            Path unos = Paths.get("rezultati.txt");
            Scanner sc = new Scanner(unos);
            while(sc.hasNext()){
                String ime = sc.next();
                if(sc.hasNextInt()){
                    int p = sc.nextInt();
                    Tim t = new Tim(ime, p);
                    timovi.add(t);
                }else{
                    char c = sc.next().charAt(0);
                    if(c == 'd'){
                        Tim t = new Tim(ime, -1);
                        timovi.add(t);
                    }
                }
            }
            Collections.sort(timovi);
            launch(args);
        }catch(IOException e){
            System.out.println(e);
        }
    }
    @Override
    public void start(Stage stage) throws Exception {
        VBox root = new VBox(10);
        root.setPadding(new Insets(10, 10, 10, 10));
        root.setAlignment(Pos.CENTER);
        Label instrukcije = new Label("Odaberite prikaz rezultata:");
        Label warning = new Label("Molim vas...Nista odabrali... :c");
        warning.setTextFill(Color.DEEPPINK);
        RadioButton rbRastuce = new RadioButton("Rastuce");
        RadioButton rbOpadajuce = new RadioButton("Opadajuce");
        ToggleGroup tg = new ToggleGroup();
        rbOpadajuce.setToggleGroup(tg);
        rbRastuce.setToggleGroup(tg);
        HBox dugmici = new HBox();
        dugmici.getChildren().addAll(rbRastuce, rbOpadajuce);
        Button prikaz = new Button("Prikazi");
        Button cisti = new Button("Ocisti");
        TextArea text = new TextArea();
        root.getChildren().addAll(instrukcije, warning, dugmici, prikaz, cisti, text);
        text.setEditable(false);
        cisti.setOnAction(e->{
            text.setText("");
            warning.setText("");
            rbOpadajuce.setSelected(false);
            rbRastuce.setSelected(false);
        });
        prikaz.setOnAction(e -> {
            if(!rbRastuce.isSelected() && !rbOpadajuce.isSelected()){
                warning.setText("BIRAJ PLS");
                return;
            }
            StringBuilder string = new StringBuilder();
            if(rbRastuce.isSelected()){
                for (int i = 0; i < timovi.size(); i++) {
                    string.append(timovi.get(i).toString() + '\n');
                }
                text.setText(String.valueOf(string));
            }else{
                for (int i = timovi.size()-1; i >= 0; i--) {
                    string.append(timovi.get(i).toString() + '\n');
                }
                text.setText(String.valueOf(string));
            }
        });
        Scene scene = new Scene(root, 600, 300);
        stage.setTitle("HACKATHON");
        stage.setScene(scene);
        stage.show();
    }
}
