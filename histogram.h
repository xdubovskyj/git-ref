#define VELKOSTPOLA 1001
#define STREND '\0'
#define NOMSGEDITED "Nie je k dispozicii upravena sprava\n"

void histogramprint(float pocty[26], int max);
void histogramlegenda(void);
int histogrammax(float pocty[26], int celok);
void histogram(char pole2[VELKOSTPOLA], int isu);

