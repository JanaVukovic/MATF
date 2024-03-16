import javafx.application.Application;
import javafx.stage.Stage;



//--module-path C:\Users\strah\.jdks\javafx-sdk-21.0.1\lib --add-modules javafx.controls,javafx.fxml
public class PracenjeStavki extends Application {
    public static ListaPitanja pitanja = new ListaPitanja();
    public static SkupBagova bagovi = new SkupBagova();
    public static void main(String[] args) {
        launch(args);
    }
    @Override
    public void start(Stage stage) throws Exception {
        
        Scene scene = new Scene(fxmlLoader.load(), 320, 240);
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
    }
}
