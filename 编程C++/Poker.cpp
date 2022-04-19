/*�˿��Ƶ�˵����
string[] RANKS = {"A", "2", "3", "4", "5", "6", "7","8", "9", "10", "J", "Q", "K"};
string[] SUITS = {"c", "d", "h", "s"};
*/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

const int COLOR=4;
const int NUM=13;
string RANKS[] = {"A", "2", "3", "4", "5", "6", "7","8", "9", "10", "J", "Q", "K"};
string SUITS[] = {"c", "d", "h", "s"};

class Card{
public:
	string rank;
	string suit;
	bool bFaceUp;
	Card(){
		bFaceUp=true;
	}
	Card(string strrank,string strsuit,bool FaceUp){
		rank=strrank;
		suit=strsuit;
		bFaceUp=FaceUp;
	}
	void Print(){
		//cout<<"Suit="<<suit<<";Rank="<<rank<<"  ";
		if (bFaceUp)
			cout<<rank<<suit<<endl;
		else
			cout<<"**"<<endl;
	}
};
class Hand{
public:
	vector<Card> cards; 
	Hand(){}
	void Clear(){
		if (!cards.empty())
			cards.clear();
	}
	void Show(){
		/*
		for(int i=0;i<COLOR*NUM;i++){
				if (i%NUM==0)
					cout<<endl;
				cards[i].Print();
		}
		*/
		for(int i=0;i<cards.size();i++)
			cards.at(i).Print();
	}
	int Value(){
			
			//A������Ϊ11��Ҳ����Ϊ1�㣬������<10��������ʱ��=11�㣬����=1��
		int iRet=0;//�����ۼ����� 
		string str="";
		int iCountA=0;//��A���ۼ����� 
		for(int i=0;i<cards.size();i++){
			if(cards.at(i).rank!="A" && cards.at(i).rank!="J" && cards.at(i).rank!="Q" && cards.at(i).rank!="K")
				iRet+=stoi(cards.at(i).rank);//stoi����Ϊ<sting>��stringת��Ϊint; 
			else if (cards.at(i).rank=="J" || cards.at(i).rank=="Q" || cards.at(i).rank=="K")
				iRet+=10;
			else{
			
				iRet+=11;
				iCountA++;
			}
		}
		//�鿴A����Ҫʱ��A����1�㣻
		while (iRet>21){
			if (iCountA>0){
				iRet-=10;
				iCountA--;
			}
			if (iCountA==0)
				break;
		}
		
		return iRet;
	}

};
class Deck:public Hand{
private:
	Card tempcards[NUM*COLOR];
public:
	
	//vector<Card> cards;
	Deck(){
		int k=0;
		for(int i=0;i<COLOR;i++){
			for(int j=0;j<NUM;j++){
				tempcards[k].rank=RANKS[j];
				tempcards[k].suit=SUITS[i];
				k++;
				
				
			}
		}

	}
	void Shuffle(){
		//�������һ��0~51����������Ϊ�±���cards[i]������i��0ѭ����51��
		srand((int)time(0));
		int j=0;
		//swap
		for (int i=0;i<COLOR*NUM;i++){
			j=rand()%(COLOR*NUM);
			Card temp(tempcards[i]);
			//cout<<"temp��";
			//temp.Print();
			//cout<<"card[j]:";
			//cards[j].Print();
			tempcards[i]=tempcards[j];
			tempcards[j]=temp;
			//cout<<"-----------"<<endl;
		}
		for(int k=0;k<NUM*COLOR;k++){
			cards.push_back(tempcards[k]); 
		}

	}
	void Give(Hand &hand,bool faceup=true){//���������±�Ϊ0�� �˿��Ƹ�hand; 
		if (!cards.empty()){
			Card FirstCard=cards.at(0);
			if (!faceup)
				FirstCard.bFaceUp=false;
			hand.cards.push_back(FirstCard);
			cards.erase(cards.begin());
		}
	}

};
int main(){
	/*
	Deck deck;
	deck.Shuffle();
	deck.Show();
	Hand me;
	cout<<"----------"<<endl;
	deck.Give(me);
	deck.Give(me);
	deck.Give(me);
	deck.Show();
	cout<<"---------"<<endl;
	cout<<"me:"<<endl;
	me.Show();
	int point=me.Value();
	cout<<point<<endl;
	*/
	Deck deck;
	deck.Shuffle();
	Hand me,Pc;
	//����
	deck.Give(Pc,false);
	deck.Give(Pc);
	deck.Give(me);
	deck.Give(me);
	cout<<"���Ե���:"<<endl;
	Pc.Show();
	cout<<"���Եĵ���:**"<<endl;
	cout<<"�ҵ���:"<<endl;
	me.Show();
	cout<<"�ҵĵ���"<<me.Value()<<endl;
	//����Ҫ���� 
	while(me.Value()<=21){
		cout<<"�㻹Ҫ����(y/n)"<<endl;
		char choice;
		cin>>choice;
		if (choice=='n')
			break;
		else
		{
			deck.Give(me);
			cout<<"�ҵ���:"<<endl;
			me.Show();
			cout<<"�ҵĵ���:"<<me.Value()<<endl;
		}
		
	}
	//�������<=17,����Ҫ�ƣ�
	
	while(Pc.Value()<=17){
		deck.Give(Pc);
		if (Pc.Value()>=21)
		break;	
	}
	//���̯�ƣ�
	for(int i=0;i<Pc.cards.size();i++)
		Pc.cards.at(i).bFaceUp=true;
	cout<<"Game Over!"<<endl;
		cout<<"���Ե���:"<<endl;
	Pc.Show();
	cout<<"���Եĵ���:"<<Pc.Value()<<endl;
	cout<<"�ҵ���:"<<endl;
	me.Show();
	cout<<"�ҵĵ���"<<me.Value()<<endl;
	//�ж���Ӯ��
	if (Pc.Value()>21 &&me.Value()>21) 
		cout<<"ƽ�֣�"<<endl; 
	else if (Pc.Value()>21 &&me.Value()<=21) 
		cout<<"��Ӯ�ˣ�"<<endl; 
	else if (Pc.Value()<=21 &&me.Value()>21) 
		cout<<"����Ӯ�ˣ�"<<endl; 
	else{
		if (Pc.Value()>me.Value())
			cout<<"����Ӯ�ˣ�"<<endl; 
		else if (Pc.Value()<me.Value())
			cout<<"��Ӯ�ˣ�"<<endl;
		else 
			cout<<"ƽ�֣�"<<endl;
	}	
		

}

