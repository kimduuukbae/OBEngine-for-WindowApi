# Animation

Animation 은 많은 Sprite 를 모아 동작을 이어주는 Class 입니다.

1. Animation.h 를 include 하고 변수를 선언해줍니다.

<img src="https://user-images.githubusercontent.com/39338850/58758740-b9119980-855a-11e9-8270-66a2432e46ea.png" width="90%"></img>

2. Scene 내에서 setTexture를 통해 이미지들을 읽어냅니다.

<img src="https://user-images.githubusercontent.com/39338850/58758773-51a81980-855b-11e9-8f37-df028bae10f6.png" width="90%"></img>

3. Animation을 update 해주고 draw 해 줍니다.

<img src="https://user-images.githubusercontent.com/39338850/58758779-7603f600-855b-11e9-8722-d9b2680fdd70.png" width="90%"></img>

이렇게 하면 변하는 이미지를 만들어 낼 수 있습니다.

# 응용 

 - Animation 은 1초를 기준으로 변경됩니다. 만약 이 기준을 바꾸고 싶다면 setTime 함수를 사용하시면 됩니다.

<img src="https://user-images.githubusercontent.com/39338850/58758797-c5e2bd00-855b-11e9-8cae-8bd3716d0391.png" width="90%"></img>

 - Animation 의 기준점은 xPos 와 yPos 입니다. 만약 기준점을 바꾸고 싶다면 setOffset 함수를 사용하시면 됩니다.

<img src="https://user-images.githubusercontent.com/39338850/58758813-1a863800-855c-11e9-85e9-f1da1b47356a.png" width="90%"></img>

<img src="https://user-images.githubusercontent.com/39338850/58758834-70f37680-855c-11e9-9b14-40cc2032b5fe.png" width="90%"></img>
 

- 주의 : 
Winapi 에서의 Image Rotate 는 되지 않습니다. 이는 많은 DC 와 operation 이 필요하기 때문에 따로 작성하지 않았고, STATE 로 관리하여야 합니다.
