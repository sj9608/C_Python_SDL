# git 연동
git repository 새로 만들었을 경우에
'''bash
echo "# git_test" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/sneak7581/git_test.git
git push -u origin master
'''
기존 repository 에서 가져올 경우
'''bash
git remote add origin https://github.com/sneak7581/git_test.git
git push -u origin master
'''