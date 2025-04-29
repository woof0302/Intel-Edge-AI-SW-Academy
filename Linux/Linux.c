// LINUX 쉡 스크립트 및 서버 구축 김성호 교수님 진행(2025.1.6 ~ 2025.1.13) 교재 내 실습 문제 및 모의고사 풀이


// A0 디렉터리 관리 p.37

#if 0

(1) 홈 디렉터리 (~ 또는 /home/user)로 이동 후 tdir1을 생성한다
cd
mkdir tdir1

(2) /etc로 이동 후 tdir1 아래에 tdir2를 생성한다
cd / etc
mkdir ~/ tdir1 / tdir2

(3) 한번에 tdir2로 이동한다
cd ~/ tdir1 / tdir2

(4) 홈 디렉터리로 이동 후 tdir1을 삭제한다
cd
rmdir ~/ tdir1 / tdir2
rmdir ~/ tdir1

#endif


// A1 파일 관리 p.41

#if 0

1

(1) /etc 디렉터리를 통째로 홈 디렉터리에 복사한다
cd
cp - rf / etc .

(2) 홈 디렉터리에 복사한 etc 디렉터리의 이름을 my_etc로 변경한다
mv etc my_etc

(3) 홈 디렉터리에 my_backup 디렉터리를 생성한다
mkdir my_backup

(4) my_etc를 my_backup으로 이동한다
mv my_etc my_backup

(5) my_backup 디렉터리를 삭제한다
rm - rf my_backup

#endif


// A2 파일 및 텍스트 검색 p.54

#if 0

(1) /etc 디렉터리에서 (하위 디렉터리 제외) 접근 권한이 755인 디렉터리를 모두 출력하라
ls - l / etc | grep drwxr - xr - x	// d 디렉토리만 찾으라 했으니 빼먹지 말자

(2) /etc 디렉터리에서 (하위 디렉터리 제외) 파일명에 "bash"와 "comp"를 동시에 포함한 파일(디렉터리 포함)을 모두 출력하라
ls / etc | grep bash | grep comp

(3) /etc/services 파일에서 "tcp"와 "daemon"은 포함하지만 "services"는 포함하지 않는 행을 모두 출력하라
cat / etc / services | grep tcp | grep daemon | grep - v service
// 출력하지말고 log.txt에 출력
cat / etc / services | grep tcp | grep daemon | grep - v service > log.txt

(4) 저장된 커널 메시지를 출력하는 명력 "& dmesg"의 결과 중 "Success"를 포함한 행을 모두 출력하라
sudo dmesg | grep Success	// 내가 작성한 답 sudo | grep Success /usr/bin/dmesg

#endif


// A3 파일 검색 및 텍스트 조작 p.66

#if 0

(1) /etc에서 사이즈가 512바이트를 초과하는 파일의 수를 출력하라
find / etc - size + 512c 2 > / dev / null | wc - l	// 2 > dev/ null  에러 버리는 기법
1045

(2) /var/log에서 수정시간이 100분 미만인 파일을 모두 /home/user/backup디렉터리에 복사하라
mkdir ~/ backup
find / var / log - mmin - 100 - exec cp - f{} / home / user / backup \;	 // 중간에 뭐 물어볼 수도 있는거 방지하기 위해 -f 옵션 쓰는게 좋다
ls ~/ backup /
user - 1000.journal

(3) "$ date"명령의 결과에서 시:분:초 부분만 추출하여 출력하라
date | cut - d " " - f4
09:55 : 35

(4) "$date"명령의 결과에서 시:분 부분만 추출하여 출력하라
date | cut - d " " - f4 | cut - d ":" - f1, 2
09 : 55

/etc/fonts/conf.d/README 파일에 대해 다음을 수행하라

(5) 총 단어의 수를 출력하라
cat / etc / fonts / conf.d / README | wc - w
138

(6) 고유한 단어의 총 수를 출력하라
# "wc -w" doesn't count blank line
cat / etc / fonts / conf.d / README | tr " \t" "\n\n" | sort | uniq | wc - w	// 공백과 탭을 개행문자로 바꿔라
104																				// 결과에 공백행이 하나 남는데(tab이나 공백을 개행으로 바꾸고 sort에서 공백 행도 하나 남겨서)
																				// wc -l로 하면 그 행까지 세기 때문에 
#endif																			// wc -w로 해줘야 한다.


// A4 변수에 문자열 대입 p.88
#if 0

변수 var에 문자열을 저장한 후 출력하는 스크립트를 완성하라

#!/bin/bash

name = "linux"
course = "expert"

# "linux expert"
var = "$name $course"
echo $var

# "$linux \expert"
var = "\$$name \\$course"
echo $var

# "$$linux \\expert"
var = "\$\$$name \\\\$course"
echo $var

# "experted linux"
var = "${course}ed $name"
echo $var

#endif


// A5 mycp p.106

#if 0

파일 복사 후 성공 여부를 출력하는 mycp.sh를 작성하라

# 솔루션1

#!/bin/bash

cp $1 $2 > / dev / null 2 > & 1

if[$ ? -eq 0]		// cp 성공했을 때 반환 값이 0(참) 
then
echo "Copy success"
else
echo "Copy failed"
fi


# 솔루션2

#!/bin/bash

if cp $1 $2 > / dev / null 2 > & 1
then
echo "Copy success"
else
echo "Copy failed"
fi


#endif


// A6 타임아웃 p.111

#if 0

3초간 암호를 입력하지 않으면 경고를 출력 후 종료하라

// # 솔루션1

#!/bin/bash

TIMEOUT = 3
echo - n "Enter your id: "
read ID

if[["$ID" == [0 - 9] * ]]
then
echo "Invalid ID format"
exit - 1;
fi

echo - n "Enter your password: "

# Implement script
read - t $TIMEOUT PW

if[-n "$PW"]
then
	:			// 할거 없을 때 명령 eof  help : 하면 나온다(null command)
else
echo "Time out!!!"
exit - 1;
fi

echo "registered successfully"
echo "id: $ID, password: $PW"



// # 솔루션2

#!/bin/bash

TIMEOUT = 3
echo - n "Enter your id: "
read ID

if[["$ID" == [0 - 9] * ]]
then
echo "Invalid ID format"
exit - 1;
fi

echo - n "Enter your password: "
read - t $TIMEOUT PW

if[$ ? -ne 0]
then
echo "Time out!!!"
exit - 1;
fi

echo "registered successfully"
echo "id: $ID, password: $PW"

#endif


// A7 최신 파일 찾기 p.117

#if 0 

가장 최신에 수정된 파일 N개를 찾아라

#!/bin/bash

DIR = $1
NUM = $2	// 변수에 저장(인식하기 쉽게)
count = 0

FILES = `ls - t $DIR`

for fname in $FILES
do
if[-f $DIR / $fname]  // 경로까지 알려줘야 한다
then
echo "$fname"
let 'count++'
if[$count - eq $NUM]
then
break
fi
fi
done


#endif


// 모의고사

#if 0

1. 접근 권한이 0744 인 myfile의 접근 권한을 0755로 바꾸는 명령을 쓰시오. (단, 기호모드를 사용해야 하며 여러 개의 명령을 써도 무관함)
답: sudo chmod a + x myfile

	2. / sbin 디렉터리에서(하위 디렉터리 제외) 파일명에 sys가 포함된 파일을 모두 찾아 files.txt에 저장하는 명령을 쓰시오.

	답 : ls / sbin | grep sys > files.txt

	3. / bin 디렉터리에서 파일의 크기가 4KB를 초과하는 파일들을 검색하는 명령을 쓰시오.

	답: find / bin –size + 4K

	4. 변수 var에 문자열 “great”가 저장되어 있는 상황에서, 변수 var을 이용하여 “$great$”를 출력하는 명령을 쓰시오.큰 따옴표는 출력되지 않고 $great$ 만 출력되어야 하고, echo 명령을 사용한다.

	답 : echo \$$var\$

	5. 다음 코드의 출력 결과를 쓰시오.
	echo "aa bb aa cc" | tr " " "\n" | sort | uniq | wc –l

	답 : 3

	6. 다음 코드의 출력 결과를 쓰시오.

	<test.sh의 내용>
#!/bin/bash
	export var = ”good”

	<실행한 명령>
	. / test.sh
	echo var : $var

	답 : var:

7. 다음 명령의 출력 결과를 쓰시오.
echo first && var = YYY || var = ZZZ
echo $var

답 :
first
YYY

8. / etc 디렉터리에서.conf로 끝나는 파일 중 파일의 이름에 us를 포함하고 있는 파일을 찾아 최대 3개까지 출력하는 쉘 스크립트를 완성하시오.만일 해당하는 파일이 3개 미만인 경우 찾은 파일만 출력한다.

답 :

#!/bin/bash

	NUM = 3
	count = 0
	for fname in / etc/*.conf
	do
			# Implement code

			echo $fname | grep us
			if [ $? -eq 0 ]
			then
					let count++
					if [ $count -eq $NUM ]
					then
							break
					fi
			fi
	done

#endif