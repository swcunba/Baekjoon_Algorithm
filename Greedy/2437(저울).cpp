#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000000000 + 1;
int N;
vector<int> v;
int main(void)

{
	ios_base::sync_with_stdio(0);
	cin.tie(0); //cin 실행속도 향상
	cin >> N;
	v.resize(N);//배열의 원소 개수 N으로 설정 나머지는 디폴트 0으로 채워짐 
	for (int i = 0; i < N; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	//1이 없다면 1이 최솟값
	if (v[0] != 1)
		cout << 1 << "\n";
	else
	{//1이 있다면
		int sum = 1; //누적합 1로 시작
					 //현재까지의 합 + 1 보다 큰 값이 다음 인덱스에 저장된 수라면
					 //이전의 추들로 무게를 구할 수 없다
		for (int i = 1; i < N; i++)
		{
			if (v[i] > sum + 1)
				break;
			sum += v[i];
		}
		cout << sum + 1 << "\n";
	}
	return 0;
}
//다양한 방법을 떠올릴 수 있도록 많이 접해봐야한다.