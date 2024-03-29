# **Minibankingsystem**  

# **개요**  
•MiniBanking System은 보통예금 계좌, 신용신뢰 계좌로 나눠서 개설하였다.  
•보통예금 계좌는 기본 이율을 적용하고 신용신뢰 계좌는 신용등급에 따라 기본 이율에 추가 이율을 적용하였다.   

# **시스템 구조도**  
![클래스다이어그램](./개발기술문서/클래스다이어그램.png)  
• Banking System 프로그램은 배열클래스를 이용하여 구현되어 있으며, 프로그램 시작 시 파일을 읽고 계좌 생성, 입금, 출금 시 데이터를 저장하여 고객의 계좌 정보 데이터를 유지할 수 있도록 하였다. 생성된 파일은 텍스트 형식이고 이름은 ‘AccountList’이다.  
• 클래스들의 구성은 위 그림과 같이 Account클래스에 기본 정보 멤버 변수를 가지고 있고, 자식 클래스로 NormalAccount 클래스, HighCreditAccount 클래스를 가지고 있다.   
• Account클래스의 멤버변수 중 cusName은 String클래스를 이용하여 작성하였고 AccountHandler클래스에 계좌개설, 입금/출금, 전체고객 잔액조회기능 등이 가능하도록 구현하였다.  
• 입금할 때 0보다 작은 값을 입력하는 경우, 출금할 때 출금액이 잔액보다 크거나 0보다 작은 값을 입력하는 경우, 배열클래스의 저장가능한 공간의 범위를 벗어나는 경우 등의 예외발생을 처리할 수 있도록 Exception 클래스를 설계하였다.  

# **개발환경**  
•운영 체제 : Windows 7 Professional K  
•CPU : IntelⓇ Core™ i7-4790 CPU @ 3.60GHz  
•메모리 : 8GB  
•IDE : Microsoft Visual Studio Community 2017 버전 15.9.7  
•컴파일 버전 : _MSC_VER 1916   
•언어 :C++  

# **구동 영상 URL**  
https://youtu.be/7fy89UQboJU  
# **결과**  
• 간단한 기능을 가진 Banking System이지만, 객체지향적인 C++언어를 사용하여 객체지향언어의 특징인 캡슐화, 추상화, 상속성, 다형성 등을 구현하였다. 또한 파일 입출력을 통해 계좌관련 데이터들의 관리가 편리하다.  

# **개선사항**
• 송금 및 고객별 입/출금 거래내역 조회 등 더 다양한 기능을 추가할 필요가 있다.  
• 계좌개설메뉴, 전체고객 잔액조회 메뉴에 대한 접근은 관리자만 가능하고 입금/출금 메뉴에 대한 접근은 고객만이 가능할 수 있도록 통제하는 기능이 필요하다.  
• 개설한 계좌를 삭제하는 기능도 구현하여 계좌관리가 더 원활하게 할 수 있도록 해야 한다.  
• 입력받은 데이터들을 데이터베이스와 연동하여 안정적으로 데이터 관리를 하도록 해야 한다.  
