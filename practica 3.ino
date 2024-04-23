#define avanzar 2
#define retroceder 3
#define setings(pin) pinMode(pin, INPUT)

struct datos_producto
{
  String tipo_producto;
  int stock;
};

int seleccion_producto = 0;

datos_producto snack[4]= {
  {"Lays", 30},
  {"Doritos", 28},
  {"Pepsi", 35},
  {"Snickers", 25}
};

void setup() {
  Serial.begin(9600);
  setings(avanzar);
  setings(retroceder);
  Serial.println("Bienvenido(a)");
  Serial.println("Selecciona un producto");
  Serial.println("Lays");
  Serial.println("Doritos");
  Serial.println("Pepsi");
  Serial.println("Snickers");
  Serial.println("Ahora se encuentra en: Lays");
  
}

void loop() {
  if(digitalRead(avanzar)==HIGH)  //Leo el estado digital del pin 2 y si este es bajo.
  {
   
   seleccion_producto = (seleccion_producto +1) %4;  //aumento en uno el contador
   Serial.print("El producto seleccionado es: ");
   Serial.println(snack[seleccion_producto].tipo_producto);
   Serial.print("Cantidad existente: ");
   Serial.println(snack[seleccion_producto].stock);
    delay(350);
  }
  
 if(digitalRead(retroceder)==HIGH)  //Leo el estado digital del pin 2 y si este es bajo.
  {
   
   seleccion_producto = (seleccion_producto -1 +4) %4;  //aumento en uno el contador
   Serial.print("El producto seleccionado es: ");
   Serial.println(snack[seleccion_producto].tipo_producto);
   Serial.print("Cantidad existente: ");
   Serial.println(snack[seleccion_producto].stock);
    delay(350);
  }
}  