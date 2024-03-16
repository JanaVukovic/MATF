module com.example.primer_2024 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.primer_2024 to javafx.fxml;
    exports com.example.primer_2024;
}