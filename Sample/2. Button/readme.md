# Button

Button을 통해 click이 가능합니다. 

1. ClickButton을 incldue 하고, 변수를 선언해줍니다.

<img src="https://user-images.githubusercontent.com/39338850/58264456-df943f80-7db8-11e9-9e6c-1f64fd41fa28.png" width="90%"></img>

2. button 의 setTexture, setPos 를 정해주고, draw 를 해줍니다.

<img src="https://user-images.githubusercontent.com/39338850/58264664-2eda7000-7db9-11e9-8d7e-fed0d3fd7152.png" width="90%"></img>

3. 만약 click event가 필요하다면, Scene의 mouseDownEvent 를 override 하여 사용합니다.
( 꼭 override 를 하기 싫다면, D_INPUT 에서 currentMousePos 를 가져와 사용할 수도 있습니다. )

<img src="https://user-images.githubusercontent.com/39338850/58264833-8547ae80-7db9-11e9-80d2-ef0146e74129.png" width="90%"></img>

클릭을 하면 Event가 발생합니다.

<img src="https://user-images.githubusercontent.com/39338850/58264946-b922d400-7db9-11e9-80b8-02c888437618.png" width="50%"></img>


만약 개발자가 필요하다면, button 을 상속하여 새로운 button을 만들어낼 수 있습니다.
button은 update 와 draw를 필수적으로 재정의 ( override ) 하여야 합니다.

<img src="https://user-images.githubusercontent.com/39338850/58265058-eec7bd00-7db9-11e9-9460-d83e93e44201.png" width="50%"></img>
