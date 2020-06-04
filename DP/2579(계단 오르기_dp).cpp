/*
계단마다 점수가 있고, 계단은 연속해서 3개를 오르거나, 3칸 이상 건너뛸 수 없음.
마지막 계단은 꼭 밟아야 함. 
n개의 계단(300이하의 자연수)
계단의 각 점수는 10,000이하 자연수.
점수의 최댓값 산출. 

마지막 칸을 꼭 밟아야하니 마지막 칸에서부터 수식을 완성해보자. 
문제의 예제를 기준으로 생각해보면,
마지막 층에서의 선택지는 10 혹은 25이다.
10을 선택하면 15와 20을 선택하거나 15와 10을 선택해야한다.
각 45와 35이다. 시작값인 20을 포함하면 65, 55. 
25를 선택하면 15와 10을 선택하거나 20과 10을 선택해야한다.
각 50과 55이다. 시작값인 20을 포함하면 70, 75. 
따라서 최댓값인 75이다. 

경우의 수를 꼭대기 계단(n번째 계단)에서부터 크게 나눠서 보자면 n-1번째 계단을 선택하는 경우와 n-2번째 계단을 선택하는 경우로 나눠볼 수 있다. 
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAX 10001

using namespace std;

int stairs[MAX];//계단 점수 정보. 
int values[MAX];//인덱스가 계단의 칸 수 - 1. 경우의 수는 항상 2개 중 하나. 
int n; 


int main(void){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &stairs[i]);
	}//계단 갯수와 각 계단의 점수 입력.
	
	values[0] = stairs[0];//1칸 오르기. 
	values[1] = max(stairs[0] + stairs[1], stairs[1]);//1칸씩 둘 다 오르기 vs 2칸 오르기. 
	values[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);//1칸 오르고 2칸 오르기 vs 2칸 오르고 1칸 오르기.
	for(int i = 3; i < n; i++){
		values[i] = max(values[i-2] + stairs[i], values[i-3] + stairs[i-1] + stairs[i]);
	}
	//엑셀로 생각해보면 보인다. 
	//매번 i+1번째 계단의 최댓값의 경우의 수는 2가지이다. 2칸 전까지의 경로 + 마지막 계단 or 3칸 전까지의 경로 + i-1계단 + 마지막 계단.
	//이 두 가지 중 3칸 전까지의 경로 + i-1계단 + 마지막 계단의 경우는 마지막에 2개의 연속된 계단을 오른 것이므로 반드시 i-3까지의 경로로부터 연산을 해주는 것이다. 
	printf("%d\n", values[n-1]);
	return 0;
} 
