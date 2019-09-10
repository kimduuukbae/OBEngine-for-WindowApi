# CLOSED 
소스를 잘못 붙혀넣어서 Event 부터 개발이 불가능합니다. 
형상관리를 꼭 하도록 합시다 여러분


# OBEngine-for-WindowApi
for WindowApi -> DirectX -> include GUI


# How To Use ?

1. OBEngine.dll 와 OBEngine.lib 를 프로젝트 폴더 내에 넣습니다.

<img src="https://user-images.githubusercontent.com/39338850/58188765-2d933f80-7cf4-11e9-8fae-e4de89c255c0.png" width="40%"></img>

2. 각 header 파일을 프로젝트 폴더 내에 넣습니다.

-) dll은 꼭 프로젝트 내부에 있어야하며, lib 과 각 header 들은 프로젝트 내의 다른 폴더에 있어도 됩니다. 경로만 잘 설정해 주세요.

3. 각 header 파일중 Define.h 파일을 include 합니다.
4. #pragma comment(lib, "OBEngine.lib") 를 통해 lib 를 읽어옵니다.
5. winMain을 작성합니다.

<img src="https://user-images.githubusercontent.com/39338850/58188962-8531ab00-7cf4-11e9-98c1-ee03e123cdf5.png" width="40%"></img>

이렇게 하면 첫 윈도우를 띄울 수 있습니다.

# Request?

1. 필요한 함수들은 직접 Request 할 수 있습니다. Mail 또는 Issue를 통해 알려 주세요.

2. dll 과 lib 를 업로드 하지만 header, cpp 파일 또한 업로드 합니다. 사용자 본인이 수정하여 사용할 수 있으며 fork 를 통한 dll 새 제작도 가능합니다.


