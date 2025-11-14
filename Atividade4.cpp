/Atividade4

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
