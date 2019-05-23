# Sprite 

Sprite 사용을 통해 background, image 등 bitmap resource 를 사용할 수 있습니다.

1. sprite.h 를 include 하고 Sprite 변수를 선언합니다.

<img src="https://user-images.githubusercontent.com/39338850/58266152-0f911200-7dbc-11e9-8a34-1bf0b60c5fdf.png" width="60%"></img>

2. spirte 의 값을 정의하고 draw 합니다. sprite instance 는 alphablend가 가능합니다.

<img src="https://user-images.githubusercontent.com/39338850/58267093-e1accd00-7dbd-11e9-9e41-d1ebdee5c6cd.png" width="60%"></img>

sprite 는 원한다면, 상속하여 새로운 sprite instance 를 만들 수 있습니다.
sprite.h 는 다음과 같이 되어 있습니다.

<img src="https://user-images.githubusercontent.com/39338850/58267256-35b7b180-7dbe-11e9-969c-930cad6ff4a2.png" width="60%"></img>

