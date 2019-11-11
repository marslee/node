1.新建本地git仓库，并将本地库关联远程仓库GitHub


1.1. git拉取远程分支并创建本地分支
1.1.1 查看远程分支    git branch -r 查看所有远程分支：
1.1.2 拉取远程分支并创建本地分支
        方法一    git checkout -b 本地分支名 origin/远程分支名 使用该方式会在本地新建分支，并自动切换到该本地分支。
        方式二    git fetch origin 远程分支名:本地分支名 使用该方式会在本地新建分支，但是不会自动切换到该本地分支，需要手动checkout。
    git init   // 初始化版本库
    git add .   // 添加文件到版本库（只是添加到缓存区），.代表添加文件夹下所有文件 
    git commit -m "first commit" // 把添加的文件提交到版本库，并填写提交备注
2.更新代码步骤  （先检查当前状态，再更新，避免发生冲突）

2.1 git status  查看当前状态，查看本地分支文件信息

2.2 git check out -[file name] 若文件有修改，可以还原到最初状态; 若文件需要更新到服务器上，应该先merge到服务器，再更新到本地

2.3 git branch 查看本地所有分支，当前分支

2.4 git checkout remote branch   若分支为本地分支，则需切换到服务器的远程分支

2.5 git pull 更新本地代码

3.提交代码步骤（先更新，在提交，避免冲突）

3.1 git status  查看当前状态，查看本地分支文件信息

3.2 git branch 查看本地所有分支，当前分支

3.3 

3.4 git checkout remote branch   若分支为本地分支，则需切换到服务器的远程分支

3.5 git push -u origin master    // 第一次推送时

      git push origin master  // 第一次推送后，直接使用该命令即可推送修

4.常用git命令大全

http://blog.csdn.net/liyayunwxc/article/details/10342573
————————————————
版权声明：本文为CSDN博主「miaoca」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/miaoca/article/details/79408748