/Atividade3

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
