# Change Scene

당신이 Window를 띄우는 것까지 달성했다면, Scene을 관리하여야 합니다.
당신이 만들고 싶은 Scene 의 class 를 h 와 cpp 에 작성해야 하며, Scene 이라는 class 를 상속 받아야 합니다.
Scene.h 는 다음과 같습니다.

<img src="https://user-images.githubusercontent.com/39338850/58261324-0c455880-7db3-11e9-9ffe-962a1f79be48.png" width="50%"></img>

1. 만들고싶은 Scene의 h 와 cpp 파일을 만들어 주고, 꼭 필요한 함수를 재정의 (override) 해줍니다.
꼭 필요한 함수는 다음과 같습니다

- init
  Scene이 Change 될 때 딱 한번 불립니다. 모든 변수의 초기화는 이곳에서 진행시켜야 합니다.
  
- update
  Scene 내에서 Object 의 Update 용도로 사용됩니다.
  
- draw
  Scene 내에서 Object draw 용도로 사용됩니다.
  
- destroy
  Scene에서 사용한 할당된 변수를 삭제시키는 곳입니다. 삭제는 꼭 이곳에서 진행시켜야 합니다.
  
  <img src="https://user-images.githubusercontent.com/39338850/58261666-b45b2180-7db3-11e9-95a0-6b44d7eab156.png" width="90%"></img>
  <img src="https://user-images.githubusercontent.com/39338850/58261809-fb491700-7db3-11e9-8b6c-51de4e6f3e00.png" width="50%"></img>
  
 2. 선언과 정의가 되었다면 이 Scene을 commit 할 수 있습니다. 
 commit 은 main문 내에서 실행됩니다.

 <img src="https://user-images.githubusercontent.com/39338850/58261905-26cc0180-7db4-11e9-86a2-95913ff9d4bf.png" width="90%"></img>
 
 Scene은 언제든 변경할 수 있습니다. 
 
 <img src="https://user-images.githubusercontent.com/39338850/58262015-609d0800-7db4-11e9-8d25-99bfab48cb65.png" width="90%"></img>
 
 Scene 을 변경할 때는 ChangeScene 함수와 ChangeSceneFade 함수가 있습니다.
 - ChangeScene
   가장 기본적인 Scene 변경 방법으로, 실행 시 바로 해당 Scene 으로 변경됩니다.
 - ChangeSceneFade
   Scene 변경시 Fade In, Fade Out 효과를 줍니다.
