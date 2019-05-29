이번 Sample 은 Sound Resource 가 없습니다. Sample 을 실행하기 위해선 mp3 파일을 다운로드 받아 Resource 폴더에 넣어 사용하셔야 합니다.

# SoundManager

SoundManager 를 통해, Sound 를 저장하고 효과적으로 Play 할 수 있습니다.

1. winMain 에서 SoundManager를 Init 합니다.

<img src="https://user-images.githubusercontent.com/39338850/58545967-5b6e0c00-823f-11e9-8ba9-05a457a0647c.png" width="60%"></img>

- Init에 들어가는 인자는 총 사용되는 Sound의 갯 수입니다.
이를 SoundManager 에선 Channel 이라고 칭합니다. Channel 은 한 Channel 당 1 개의 Sound만 플레이 할 수 있습니다. 
그러므로 SoundManager는 Sound 의 중복 적재를 피하기 위해 한 Sound 당 1 개의 Channel 을 사용합니다.

( A라는 Channel 에서 exam1 Sound를 플레이 하고 있는데, exam2 Sound를 플레이 시킨다면 오류가 납니다. )

2. Sound들을 Commit 합니다. 

<img src="https://user-images.githubusercontent.com/39338850/58546153-bef83980-823f-11e9-8b57-5e6578cd841f.png" width="60%"></img>

- Commit에 들어가는 인자는 이 Sound가 Looping 할 것인지 입니다.
0 을 넣는다면 loop를 하지 않고 종료됩니다. 2를 넣는다면 Loop 합니다.

3. 사용할 Sound를 Play 합니다.

<img src="https://user-images.githubusercontent.com/39338850/58546285-f7981300-823f-11e9-91c4-70a94eeaa5b2.png" width="50%"></img>

- PlaySound에 들어가는 인자는 Commit 된 순서에 따른 번호입니다. 
우리는 Sample에서 MiniGame2.mp3 라는 Sound를 0 번째로 commit 하였기 때문에, 0의 sequence 를 부여 받습니다.
만약 다른 Commit 된 Sound들이 있을 시, Commit 의 순서에 따라 번호를 가집니다. 
( 첫번째로 commit된 Sound는 0 번, 두번째로 commit된 Sound는 1 번..... )


# 응용. 

Sound들의 sequence 를 Number로 관리하지 마십시오. 대신 전역적으로 쓰이는 enum형을 통해 관리하십시오.
enum 형을 Define.h 에 저장하고, Sound가 쓰일 모든 Scene 에서 이 곳을 참조 하십시오.

<img src="https://user-images.githubusercontent.com/39338850/58546882-44c8b480-8241-11e9-939a-13d7d19c1c42.png" width="60%"></img>

<img src="https://user-images.githubusercontent.com/39338850/58546897-4db98600-8241-11e9-9dc3-3747d37fb07b.png" width="60%"></img>

- enum class 에 작성된 순서와 사용 될 Sound 의 commit 순서는 동일해야 합니다.

<img src="https://user-images.githubusercontent.com/39338850/58546953-70e43580-8241-11e9-93a0-181ee55f1e7d.png" width="60%"></img>

<img src="https://user-images.githubusercontent.com/39338850/58546988-7c376100-8241-11e9-91f0-2da3c15a40e0.png" width="60%"></img>

- 각 Scene 에서 위와 같이 작성하여 사용할 수 있습니다.

<img src="https://user-images.githubusercontent.com/39338850/58547148-d20c0900-8241-11e9-974d-34f09ff6640f.png" width="60%"></img>

SoundManager 는 Sound에 대한 정보를 다 가지고 있습니다. 사용할 함수를 꼭 확인하시고 사용하시기 바랍니다.
기타 필요한 함수가 있다면 Issue 또는 Gmail 부탁드립니다.




