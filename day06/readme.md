# git 연동
git repository 새로 만들었을 경우에
``` bash
echo "# git_test" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/sneak7581/git_test.git
git push -u origin master
```
기존 repository 에서 가져올 경우
``` bash
git remote add origin https://github.com/sneak7581/git_test.git
git push -u origin master
```
<<<<<<< HEAD

# Today Learning
  반복문
  makefile 문법
  이름 : 소스파일리스트 (공백으로 구분)
  $@ 이름 $<
=======
>>>>>>> 96042eaede8890e6c0a9451eb285cc288d8f667f
