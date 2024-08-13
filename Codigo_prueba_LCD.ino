#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define POT A2

#define DHTTYPE DHT22
#define DHTPIN 2
DHT dht(DHTPIN, DHTTYPE);
int rele1= 9;



//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27,16,2);  //

void setup() {
  // Inicializar el LCD
  lcd.init();

  //Encender la luz de fondo.
  lcd.backlight();
  
  // Escribimos el Mensaje en el LCD.
  lcd.print("Temperatura");
    dht.begin();

  pinMode(rele1, OUTPUT);

}

void loop() {
   // Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)

  lcd.setCursor(0, 1);
           float temperature = dht.readTemperature();
           int potval = analogRead(POT);
             int mappedValue = map(potval, 0, 1023, 1, 5);
 switch (mappedValue) {
    case 1:

     
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temperatura");
    lcd.setCursor(0,1);
  lcd.print(temperature);
  lcd.print(" Grados");

  if (temperature> 20) {
      digitalWrite(rele1, LOW);
  }
  else {
          digitalWrite(rele1, HIGH);

  }
      break;
    case 2:
    lcd.clear();

        lcd.setCursor(0,0);
    lcd.print("Ventiladores"); //Estado Ventilador derecho, por ejemplo
          lcd.setCursor(0,1);
          lcd.print("Encendidos");
break;
    case 3:
        lcd.clear();

    lcd.setCursor(0,0);

lcd.print("Los alfajores");
    lcd.setCursor(0,1);

    lcd.print("A medio cocinar");

      break;
    case 4:
      Serial.println("El valor es 4");
      break;
    case 5:
      Serial.println("El valor es 5");
      break;
    default:
      Serial.println("Valor fuera de rango");
      break;
  }
  delay(500 );
}
