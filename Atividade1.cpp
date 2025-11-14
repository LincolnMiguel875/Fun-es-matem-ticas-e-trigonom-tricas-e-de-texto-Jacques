Atividade 1 
void setup() {
  Serial.begin(9600);
  while (!Serial) { }
}

void loop() {
  int leitura1 = analogRead(A0);
  delay(50);
  int leitura2 = analogRead(A0);
  delay(50);
  int leitura3 = analogRead(A0);

  float media = (leitura1 + leitura2 + leitura3) / 3.0;
  float raiz = sqrt(media);

  Serial.print("Leituras: ");
  Serial.print(leitura1);
  Serial.print(", ");
  Serial.print(leitura2);
  Serial.print(", ");
  Serial.println(leitura3);

  Serial.print("Media (float): ");
  Serial.println(media);
  Serial.print("Media (arredondada): ");
  Serial.println(round(media));

  Serial.print("Raiz quadrada da media (float): ");
  Serial.println(raiz);
  Serial.print("Raiz quadrada da media (arredondada para cima): ");
  Serial.println(ceil(raiz));

  Serial.println("-----------------------------");

  delay(2000);
}
