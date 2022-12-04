#include <iostream>
#include <raylib.h>
using std::string;
using std::to_string;

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const int k = 10; //thickness of grid bars
const Color OCol = {255, 51, 153, 255};
const Color XCol = {102, 255, 153,255};
const Color BG = {0, 0, 26, 255};
const Color GRID = {128, 229, 255, 255};
const string title = "Tic Tac Toe";

class Board
{
  int Cells[3][3];
  float ci, cj;
bool newGame = true;
int available = 9;
public:

  int Player = 1;
  Board()
  {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        Cells[i][j] = 0;
  }
  void Update()
  {
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && newGame){
      
      Vector2 mPos = GetMousePosition();
    for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      if((mPos.x > 5+(j*(SCREEN_WIDTH-10)/3) && mPos.x <  5+((j+1)*(SCREEN_WIDTH-10)/3)) && (mPos.y > 5+(i*(SCREEN_HEIGHT-10)/3)) && mPos.y < 5+((i+1)*(SCREEN_HEIGHT-10)/3)){
             if(Cells[i][j] == 0){
                 Cells[i][j] = Player, Player = changePlayer(Player);
                 ci = i, cj = j;
                 --available;
        
                 }
    }
    } 
  }
  void draw()
  {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
      {
        Vector2 pos = {(float)(5 + SCREEN_WIDTH / 6) + j * (SCREEN_WIDTH / 3), (float)(5 + SCREEN_HEIGHT / 6 + (SCREEN_HEIGHT / 3) * i)};
        if (Cells[i][j] == 1){
            DrawPoly(pos,3,8 + SCREEN_WIDTH/12,180,XCol);
            DrawPoly(pos,3,-8 + SCREEN_WIDTH/12,180,BG);
        }else if(Cells[i][j] == 2){
          DrawCircleV(pos,6 + SCREEN_WIDTH/15,OCol);
          DrawCircleV(pos,-6 + SCREEN_WIDTH/15,BG);
}
      }

    if(win({ci,cj})&& win({ci,cj}) != 3 && available != 9 ){
      newGame =false;
      DrawRectangle(-150 + SCREEN_WIDTH/2,-50 + SCREEN_HEIGHT/2,300,100,Fade(YELLOW,0.8f));
      DrawText(("Player" + to_string(win({ci,cj}) )+ " Won!").c_str(),-130 + SCREEN_WIDTH/2,-20 + SCREEN_HEIGHT/2,40,Fade(BLACK,0.8f));
      
    }else if(win({ci,cj}) == 3 && available != 9)
    {newGame = false;
      DrawRectangle(-150 + SCREEN_WIDTH/2,-50 + SCREEN_HEIGHT/2,300,100,Fade(YELLOW,0.8f));
      DrawText("Tie!",-40 + SCREEN_WIDTH/2,-20 + SCREEN_HEIGHT/2,40,Fade(BLACK,0.8f));
      
      }

  }
  void reset(){
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        Cells[i][j] = 0;
    available = 9;
    Player = 1;
    newGame = true;
  }
  int win(Vector2 cell){
    if(cell.x == 0 ){
      switch ((int)cell.y)
      {
      case 0: {
        if(Cells[0][0]==Cells[0][1] && Cells[0][2] == Cells[0][0])
              return changePlayer(Player);
        else if(Cells[0][0] == Cells[1][0] && Cells[2][0] == Cells[0][0])
              return changePlayer(Player);
        else if(Cells[0][0] == Cells[1][1] && Cells[2][2] == Cells[0][0])
             return changePlayer(Player);
      }
      break;
       case 1: {
        if(Cells[0][1]==Cells[0][0] && Cells[0][2] == Cells[0][1])
              return changePlayer(Player);
        else if(Cells[0][1] == Cells[1][1] && Cells[2][1] == Cells[0][1])
              return changePlayer(Player);
      }
      break;
       case 2: {
        if(Cells[0][2]==Cells[0][1] && Cells[0][2] == Cells[0][0])
              return changePlayer(Player);
        else if(Cells[0][2] == Cells[1][2] && Cells[2][2] == Cells[0][2])
              return changePlayer(Player);
        else if(Cells[0][2] == Cells[1][1] && Cells[2][0] == Cells[0][2])
             return changePlayer(Player);
      }
      break;
       
      }
    }
    else if(cell.x == 1 ){
      switch ((int)cell.y)
      {
         case 0: {
        if(Cells[1][0]==Cells[0][0] && Cells[2][0] == Cells[1][0])
              return changePlayer(Player);
        else if(Cells[1][0] == Cells[1][1] && Cells[1][2] == Cells[1][0])
              return changePlayer(Player);
        
      }
      break;
       case 1: {
        if(Cells[1][1]==Cells[0][1] && Cells[2][1] == Cells[1][1])
              return changePlayer(Player);
        else if(Cells[1][1] == Cells[0][0] && Cells[1][1] == Cells[2][2])
              return changePlayer(Player);
        else if(Cells[1][0] == Cells[1][1] && Cells[1][1] == Cells[1][2])
             return changePlayer(Player);
        else if(Cells[2][0] == Cells[1][1] && Cells[1][1] == Cells[0][2])
           return changePlayer(Player);
      }
      break;
      case 2:{
    
        if(Cells[1][2]==Cells[0][2] && Cells[0][2] == Cells[2][2])
              return changePlayer(Player);
        else if(Cells[1][2] == Cells[1][1] && Cells[1][0] == Cells[1][2])
              return changePlayer(Player);
        
      }
break;
      }

    }
    else if(cell.x == 2 ){
      switch ((int)cell.y)
      {
       case 0: {
        if(Cells[2][0]==Cells[2][1] && Cells[2][2] == Cells[0][0])
              return changePlayer(Player);
        else if(Cells[2][0] == Cells[1][0] && Cells[2][0] == Cells[0][0])
              return changePlayer(Player);
        else if(Cells[2][0] == Cells[1][1] && Cells[2][0] == Cells[0][2])
             return changePlayer(Player);
      }break;
       case 1: {
        if(Cells[2][1]==Cells[2][0] && Cells[2][1] == Cells[2][2])
              return changePlayer(Player);
        else if(Cells[2][1] == Cells[1][1] && Cells[2][1] == Cells[0][1])
              return changePlayer(Player);
      }break;
       case 2: {
        if(Cells[2][2]==Cells[2][1] && Cells[2][2] == Cells[2][0])
              return changePlayer(Player);
        else if(Cells[2][2] == Cells[1][2] && Cells[2][2] == Cells[0][2])
              return changePlayer(Player);
        else if(Cells[2][2] == Cells[1][1] && Cells[2][2] == Cells[0][0])
             return changePlayer(Player);
      }
      break;
      }
    }
    if(available == 0)
      return 3;
    return 0;
  }
  int changePlayer(int plyr){
    return (plyr == 1)?2:1;
  }
  
};

void drawGrid(int l, int h, Color col)
{
  float x = l / 3;
  float y = h / 3;

  Color col1 = {0, 255, 205, 255};
  DrawRectangleRounded({5, y - k / 2, float(l - 10), k}, 1, 10, col1);
  DrawRectangleRounded({5, 2 * y - k / 2, float(l - 10), k}, 1, 10, col1);
  DrawRectangleRounded({x - k / 2, 5, k, float(h - 10)}, 1, 10, col1);
  DrawRectangleRounded({2 * x - k / 2, 5, k, float(h - 10)}, 1, 10, col1);
  DrawRectangleRounded({5, y - k / 3, float(l - 10), k / 2}, 1, 10, col);
  DrawRectangleRounded({5, 2 * y - k / 3, float(l - 10), k / 2}, 1, 10, col);
  DrawRectangleRounded({x - k / 3, 5, k / 2, float(h - 10)}, 1, 10, col);
  DrawRectangleRounded({2 * x - k / 3, 5, k / 2, float(h - 10)}, 1, 10, col);
  // for(int i = 0;i < 3; i++){
  //   for(int j = 0; j < 3; j++)
  //   DrawText(("[" + to_string(i)+","+to_string(j)+"]").c_str(),20+((SCREEN_WIDTH-10)/3)*j,20+((SCREEN_HEIGHT-10)/3)*i,15,GRAY);
  // }
}

int main()
{
  Board myboard;
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, title.c_str());
  SetTargetFPS(10);
  while (!WindowShouldClose())
  {
    if(IsKeyPressed(KEY_R))
        myboard.reset(); 

      myboard.Update();

    BeginDrawing();
    ClearBackground(BG);

    DrawText((std::to_string(myboard.Player)).c_str(),SCREEN_WIDTH-30,5,50,Fade(WHITE,0.8f));  
    drawGrid(SCREEN_WIDTH, SCREEN_HEIGHT, GRID);
    myboard.draw();  
    
    EndDrawing();
  }

  return 0;
}