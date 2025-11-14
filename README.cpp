# Fun-es-matem-ticas-e-trigonom-tricas-e-de-texto-Jacques
atividade Sistemas Embarcados 
-----------------------------------------------------------------------------------------------------/🟢Exercicio1🟢/-------------------------------------------------------------------------------------------------------------------------------------
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

---------------------------------------------------------------------------------------------------------------🟢/Exercicio2/🟢---------------------------------------------------------------------------------------------------------
  void setup() 
{
 
   pinMode(7, OUTPUT);
}

void loop()
 
{
  digitalWrite(7, HIGH);
  delay(2000);
  digitalWrite(7, LOW);
  delay(2000);
}
--------------------------------------------------------------------------------------------------------------------🟢/Exercicio3/🟢----------------------------------------------------------------------------------------------------------------------
  void setup() {
  Serial.begin(9600);

  // Mensagem inicial pra orientar o que o usuário deve digitar
  Serial.println("Digite valores de X e Y separados por espaco (ex: 10 5):");
}

void loop() {
  // Só entra quando o usuário realmente digita algo
  if (Serial.available() > 0) {

    // Ler o primeiro numero que o usuario digitou (X)
    float x = Serial.parseFloat();

    // Agora leio o segundo numero digitado (Y)
    float y = Serial.parseFloat();

    if (x == 0.0 && y == 0.0) {
      Serial.println("Valores invalidos (0 0). Digite outros valores.");

      // Limpa o buffer caso tenha sobrado algo da leitura anterior
      while (Serial.available() > 0) Serial.read();

      Serial.println("\nDigite novos valores de X e Y:");
      return;
    }

    // Calcula o angulo em radianos usando atan2
    // Essa funcao já resolve tudo, inclusive qual quadrante estamos
    float anguloRad = atan2(y, x);

    // Conversão de radianos pra graus (a fórmula clássica)
    float anguloGraus = anguloRad * 180.0 / PI;

    // Mostra o resultado bonitinho no monitor serial
    Serial.print("Angulo calculado: ");
    Serial.print(anguloGraus);
    Serial.println(" graus");

    // Mensagem pra avisar que o usuário já pode mandar novos valores
    Serial.println("\nDigite novos valores de X e Y:");
  }
}

--------------------------------------------------------------------------------------------------------------------------------------🟢/Exercicio4/🟢-------------------------------------------------------------------------------------------------------
  char texto[50];

void setup() {
  Serial.begin(9600);

  // Só pra avisar o usuário que estamos esperando uma palavra
  Serial.println("Digite uma palavra:");
}

void loop() {
  // Só entra aqui quando realmente tem algo digitado no Serial
  if (Serial.available() > 0) {

    // Leio tudo até o ENTER. Aqui guardo na variavel 'texto'
    // e guardo também o tamanho que foi lido.
    int tamanho = Serial.readBytesUntil('\n', texto, 50);

    // Coloco o '\0' pra terminar a string certinho
    texto[tamanho] = '\0';

    // Mostro quantos caracteres o usuário digitou
    Serial.print("Tamanho da palavra: ");
    Serial.println(strlen(texto));

    // Aqui eu pego cada letra da palavra e transformo em maiúscula
    for (int i = 0; i < strlen(texto); i++) {
      texto[i] = toupper(texto[i]);
    }

    // Agora mostro a versão em maiúsculas
    Serial.print("Em maiusculas: ");
    Serial.println(texto);

    // Aqui monto uma frase tipo "Ola, PALAVRA!"
    char saudacao[60] = "Ola, ";

    // Junto a palavra já convertida para maiúscula
    strcat(saudacao, texto);

    // Só adiciono a exclamação no final pra fechar a frase
    strcat(saudacao, "!");

    // E mostro tudo no Serial Monitor
    Serial.println(saudacao);
  }
}

