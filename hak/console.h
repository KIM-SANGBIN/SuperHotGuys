#define WIDTH 81   // 가로 80줄 +1은 NULL을 넣어주기 위함.
#define HEIGHT 30    // 세로 24줄

void Initial();  //커서를 안보이게 해주는 함수

void MoveCursor(int x, int y);     // 커서를 움직이는 함수

void ClearScreen();        // 화면에 공백을 도배하여 비어있는 효과를 내는 함
