// ��������� ����� ��� ������
#define s2  2
#define s3  3
#define out 4
// ����������� ������ ��� ����������
byte red = 0;
byte green = 0;
byte blue = 0;

void setup() // ��������� setup
{
 pinMode(s2, OUTPUT);
 pinMode(s3, OUTPUT);
 pinMode(out, INPUT);
 Serial.begin(9600);
} 
 
void loop() // ��������� loop
{ 
 color();
 // ������� �������� ������
 Serial.print(" RED :" + String(red));
 Serial.print(" GREEN : " + String(green));
 Serial.println(" BLUE : " + String(blue));
 delay(500);
}
 
void color() // ��������� color
{
 // ���� 2 � 3 ����� ���������, �� ������� �������� �������� �����
 digitalWrite(s2, LOW);
 digitalWrite(s3, LOW);
 red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

 // ���� 3 ���� ��������, � 2 ���������, �� ������� ����� ����
 digitalWrite(s3, HIGH);
 blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

 // ���� 2 ��������, � 3 ���������, �� ������� ������� ����
 digitalWrite(s2, HIGH);
 green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
}
