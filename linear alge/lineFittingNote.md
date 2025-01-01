# Basic theory of LS (Least Squares) and fitting

## 1. Least Square

- **조건**

  - 어떤 경우에는 \(\displaystyle Ax = b\)를 만족하는 해가 존재하지 않음 (즉, \(b \notin \mathcal{C}(A)\))
  - 미지수(unknown) 개수 < 방정식 개수

- **목표**  
  \[
  \min \|Ax - b\|^2
  \]

- **해법 (프로젝션 관점)**
  - \(b\)를 \(\mathcal{C}(A)\) 위로 사영(projection)하여 \(x\)를 찾음
  - \(Ax - b \perp \mathcal{C}(A)\quad\Longrightarrow\quad A^T(Ax - b) = 0\)
  - **해**  
    \[
    x = (A^T A)^{-1} A^T b
    \]

---

## 2. Weighted Least Square

- 가중치 \(w_i\)가 주어졌을 때의 최소제곱 문제  
  \[
  \min \Bigl(w_i \,\|A_i x - b_i\|\Bigr)^2
  \quad\Longrightarrow\quad
  \min \|W A x - W b\|^2
  \]

- 대각 가중 행렬 \(W\)는 다음과 같이 표현 가능:
  \[
  W = \begin{bmatrix}
  w_1 & 0 & \cdots & 0 \\
  0 & w_2 & \cdots & 0 \\
  \vdots & \vdots & \ddots & \vdots \\
  0 & 0 & \cdots & w_n
  \end{bmatrix}
  \]

- **해**  
  \[
  x = (A^T W^T W A)^{-1} \; A^T W^T W \; b
  \]

---

## 예제 (Examples)

### 예제 1. 2차함수 피팅 \(\displaystyle y = a x^2 + b x + c\)

- 주어진 데이터 점 \((x*i, y_i)\)에 대해,
  \[
  \min \sum*{i=1}^{n} \bigl(a x_i^2 + b x_i + c - y_i\bigr)^2
  \]

- 이를 행렬 형태(도표)로 표현하면,
  \[
  \underbrace{
  \begin{pmatrix}
  x*1^2 & x_1 & 1 \\
  x_2^2 & x_2 & 1 \\
  \vdots & \vdots & \vdots \\
  x_n^2 & x_n & 1
  \end{pmatrix}
  }*{A}
  \quad
  \underbrace{
  \begin{pmatrix}
  a \\[6pt]
  b \\[6pt]
  c
  \end{pmatrix}
  }_{x}
  \;=\;
  \underbrace{
  \begin{pmatrix}
  y_1 \\[4pt]
  y_2 \\[4pt]
  \vdots \\[2pt]
  y_n
  \end{pmatrix}
  }_{b}
  \]

- 최소제곱 해는
  \[
  x = (A^T A)^{-1} A^T b
  \]
  를 이용하여 \(\displaystyle a, b, c\)를 구할 수 있음.

---

### 예제 2. 직선 피팅 \(\displaystyle y = m x + n\)

- 직선을 결정하려면, 미지수 \((m, n)\)은 2개이므로 점이 2개면 직선을 하나 정할 수 있음.  
  하지만 실제로는 \(n\)개의 점에 대해서 최소제곱 해를 구함 (초과구속 문제).
- 동일한 방식으로 \(b\)를 \(\mathcal{C}(A)\) 위로 사영(projection)하여 해를 구함.
- 행렬 \(A\)와 \(b\)는 다음과 같이 설정:
  \[
  A =
  \begin{pmatrix}
  x_1 & 1 \\
  x_2 & 1 \\
  \vdots & \vdots \\
  x_n & 1
  \end{pmatrix}
  ,\quad
  b =
  \begin{pmatrix}
  y_1 \\
  y_2 \\
  \vdots \\
  y_n
  \end{pmatrix}
  ,\quad
  x =
  \begin{pmatrix}
  m \\
  n
  \end{pmatrix}.
  \]

- 마찬가지로
  \[
  x = (A^T A)^{-1} A^T b
  \]
  를 통해 \(\displaystyle m\)과 \(\displaystyle n\)을 구하면 됨
