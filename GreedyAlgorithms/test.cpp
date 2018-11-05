#include <iostream>
#include <algorithm>
#include <vector>
struct Point
{
	float x;
	float y;
	Point(float _x,float _y){
		x=_x;
		y=_y;
	}
	
};
std::vector<std::vector<int> > Map;
float x=10,y=10;
float angle=0;
int col=0,row=0;
void setMap(int x,int y,int probality){
	// std::cout<<x<<"\t"<<y<<"\t"<<probality<<std::endl;
	Map[x][y]=probality;
    if(x-1>=0&&Map[x-1][y]<probality-1)setMap(x-1,y,probality-1);
    if(y-1>=0&&Map[x][y-1]<probality-1)setMap(x,y-1,probality-1);
    if(x+1<col&&Map[x+1][y]<probality-1)setMap(x+1,y,probality-1);
    if(y+1<row&&Map[x][y+1]<probality-1)setMap(x,y+1,probality-1);
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
  setMap(s_x,s_y,100);
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
	int _x=(int)x,_y=(int)y;
	int max_probality=Map[_x][_y];
	Point aim_point(_x,_y);
	std::vector<Point> max_point{Point(_x-1,_y-1),Point(_x,_y-1),Point(_x+1,_y-1),
								Point(_x-1,_y),Point(_x+1,_y),
								Point(_x-1,_y+1),Point(_x,_y+1),Point(_x+1,_y+1)};
	for_each(max_point.begin(),max_point.end(),[&](Point &elem){
		if(elem.x>=0&&elem.x<col&&elem.y>=0&&elem.y<row){
			if(Map[elem.x][elem.y] > max_probality){
				aim_point.x=elem.x;
				aim_point.y=elem.y;
				max_probality=Map[elem.x][elem.y];
			}
		}
	});

	//send command
	// std::cout<<aim_point.x<<"\t"<<aim_point.y<<"\t"<<std::endl;
}


int main(int argc, char const *argv[])
{
	/* code */
	col=20,row=20;
	int s_x=10,s_y=10;
	InitMap(col,row,s_x,s_y);
	std::cout<<Map.size()<<std::endl;
	UpdataMap();
	return 0;
}