#include <iostream>
#include <algorithm>
#include <vector>
std::vector<std::vector<int> > Map;
void setMap(int x,int y,int col,int row,int probality){
	// std::cout<<x<<"\t"<<y<<"\t"<<probality<<std::endl;
	Map[x][y]=probality;
    if(x-1>=0&&Map[x-1][y]<probality-1)setMap(x-1,y,col,row,probality-1);
    if(y-1>=0&&Map[x][y-1]<probality-1)setMap(x,y-1,col,row,probality-1);
    if(x+1<col&&Map[x+1][y]<probality-1)setMap(x+1,y,col,row,probality-1);
    if(y+1<row&&Map[x][y+1]<probality-1)setMap(x,y+1,col,row,probality-1);
}
void PrintMap(void){
  std::for_each(Map.begin(),Map.end(),[](std::vector<int> &elem){
    std::for_each(elem.begin(),elem.end(),[](int &i){
      std::cout<<i<<" ";
    });
    std::cout<<std::endl;
  });
}
// Init Map
void InitMap(int &col,int &row,int &s_x,int &s_y){
  Map=std::vector<std::vector<int> >(col,std::vector<int>(row,0));
  // PrintMap();
  setMap(s_x,s_y,col,row,100);
  PrintMap();
}

// using control updata Map
void UpdataMap(void){
  // static double last_time=what_time_is_it_now();
  // static geometry_msgs::Twist last_control=control;
	


  // last_control=control;
  // last_time= what_time_is_it_now();
}
// using Map get a control
void UsingMap(void){

}


int main(int argc, char const *argv[])
{
	/* code */
	int col=20,row=20,s_x=0,s_y=0;
	InitMap(col,row,s_x,s_y);
	return 0;
}