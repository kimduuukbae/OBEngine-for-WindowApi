 # Camera
 
 Camera 는 게임이 실제로 보여질 viewport 입니다.
 유저가 코드를 통해 컴파일 타임이든, 런타임이든 Camera 를 control 할 수 있습니다.

<img src="https://user-images.githubusercontent.com/39338850/64238335-36252400-cf39-11e9-9a31-96d6feee27fa.png" width="50%"></img>

Camera는 기본적으로 정적으로 정해진 window 사이즈의 최대 10배를 지원합니다.

함수를 통해 카메라에 대한 조작을 할 수 있습니다.

사용 방법을 가장 쉽게 알 수 있는 방법은, 화면의 흔들림을 구현하는 것입니다.

<img src="https://user-images.githubusercontent.com/39338850/64238542-90be8000-cf39-11e9-9d6e-ee7951c33ca4.png" width="50%"></img>


각 함수를 통해

- 카메라의 위치를 한번에 변환하거나

- 카메라의 위치를 각 프레임에 맞춰 값을 더해 주거나

- 현재 카메라의 위치를 알아오거나

할 수 있습니다.

카메라는 D_CAMERA 라는 define 객체를 통해 접근할 수 있습니다.

