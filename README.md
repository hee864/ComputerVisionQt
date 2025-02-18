# Robot Vision Application

## 📌 프로젝트 개요
**Robot Vision Application**은 Qt 프레임워크를 기반으로 한 영상 처리 프로그램입니다.
사용자는 GUI 환경에서 **이미지 필터링, 이진화, 형태학적 연산(팽창, 침식), 히스토그램 변환** 등의 기능을 수행할 수 있습니다.

## 🛠 주요 기능
### 1️⃣ 이미지 불러오기 및 표시
- 다양한 이미지 형식(`.bmp`, `.ppm`, `.pgm`, `.png`)을 지원합니다.
- 여러 개의 이미지 창을 동시에 열어 처리할 수 있습니다.

### 2️⃣ 이미지 처리 기능
- **이진화 (Thresholding, Otsu's Algorithm)**: 자동 또는 수동 이진화 지원
- **형태학적 연산**:
  - **팽창(Dilation)**: 밝은 영역 확장
  - **침식(Erosion)**: 밝은 영역 축소
  - **경계 추출(Boundary Extraction)**
- **히스토그램 변환**:
  - **히스토그램 평활화(Histogram Equalization)**
  - **히스토그램 매칭(Histogram Matching)**
- **대비 변환 (Contrast Transformation)**

### 3️⃣ 그래픽 처리 기능
- 기본적인 도형 그리기 지원: **타원, 다각형, 선, 점**
- 마우스 이벤트 처리 가능: **이미지 클릭 및 드래그**

### 4️⃣ 수학적 연산 지원 (`kfc.h`)
- 벡터 및 행렬 연산 (`KVector`, `KMatrix`)
- 이미지 데이터 변환 (`RGB ↔ HSI` 변환 지원)
- 랜덤 생성 (`KRandom`)

---

## 📂 프로젝트 구조
```
├── src/
│   ├── main.cpp           # 프로그램 실행 엔트리
│   ├── mainframe.cpp      # 메인 GUI 윈도우
│   ├── imageform.cpp      # 개별 이미지 처리 창
│   ├── kfc.cpp            # 수학 및 이미지 처리 유틸리티
│   ├── mainframe.h        # mainframe 클래스 헤더
│   ├── imageform.h        # imageform 클래스 헤더
│   ├── kfc.h              # 수학 라이브러리 헤더
│   ├── imageform.ui       # 개별 이미지 창 UI 파일
│   ├── mainframe.ui       # 메인 프레임 UI 파일
│   └── practiceCV.pro     # Qt 프로젝트 설정 파일
└── README.md
```

---

## 💻 설치 및 실행 방법
### **1️⃣ 요구 사항**
- **Qt 5 이상**이 설치되어 있어야 합니다.
- **C++ 컴파일러 (GCC, MSVC, Clang)** 필요

### **2️⃣ 빌드 및 실행**
#### **(1) Qt Creator 사용 시**
1. `practiceCV.pro` 파일을 Qt Creator에서 엽니다.
2. `Build` 버튼을 눌러 프로젝트를 컴파일합니다.
3. 실행 버튼을 눌러 프로그램을 실행합니다.

#### **(2) 터미널에서 직접 실행**
```bash
# 프로젝트 디렉토리로 이동
cd /path/to/project

# qmake로 Makefile 생성
qmake practiceCV.pro

# 빌드 실행
make -j$(nproc)  # (Linux/macOS)
nmake  # (Windows, Visual Studio 사용 시)

# 실행
./robotVisionApp  # (Windows에서는 robotVisionApp.exe)
```

---

## 🛠 개발 환경 및 사용 라이브러리
- **프로그래밍 언어:** C++
- **GUI 프레임워크:** Qt (Core, GUI, Widgets)
- **이미지 처리:** OpenCV (옵션)



