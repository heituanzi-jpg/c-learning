# Week 07 讲义：Git 与 GitHub（完全自学版）

> **本讲义的用法（老规矩，再过一遍）**
>
> 这不是任务清单，是教材。**你不需要看任何视频**——B站课程继续当"可选配菜"，哪个点看不懂，才去搜对应的视频片段。
>
> 通关路径固定四步：**读 → 敲 → 练 → 考**
> - **读**：每节正文，全部用大白话写成
> - **敲**：本周命令多、代码少——**命令可以复制粘贴**（老规矩），但每敲一条，先看一眼讲义里它"是干嘛的"
> - **练**：第 7 章分层练习 + **第 8 章每日加餐题库（每天 4 道，硬指标）**
> - **考**：第 9 章验收，交卷发我
>
> 每天学多少：看第 11 章的每日安排，**一天 1~1.5 小时**，做不完顺延。

> 📍 **你在地图上的位置**：
>
> ```
> ✅ W01~W06 全部通关（语法六件套集齐）
> 🔵 W07 Git 与 GitHub  ← 你在这里，本周结束 = 7/8
> 🏆 W08 毕业项目：命令行计算器
> ```
>
> 前六周你攒了六个语法器官；本周不学语法，学**程序员的工作方式本身**——给你的代码装上"时光机 + 云备份"。你论文线的 README 一直在手动记版本，本周升级正规军。

---

## 第 0 章 开课前的两个闸口（先过闸，再开学）

### 🚪 闸口 A：Week 06 验收卷

把上周 3 题答案发我：

1. **题 1 · 实操**：`reverse.c` 反转机（两组数据的终端记录）
2. **题 2 · 大白话**：scanf 读 int 要 `&`、读字符串为什么不加；sizeof 为什么在函数里失灵
3. **题 3 · 找茬**：5 个错误全找出、改正、跑通，至少 2 条进了 mistakes.md

还没做完就先做，30 分钟。

### 🚪 闸口 B：验明正身（10 分钟，只做一次）

**① 确认 git 在岗**（W01 装过）：

```bash
git --version
```

✅ 看到 `git version 2.x.x`。没有就 `sudo apt install -y git`。

**② 登记你的身份**（每条存档都会署名，换成你的 GitHub 用户名和邮箱）：

```bash
git config --global user.name "heituanzi-jpg"
git config --global user.email "你的GitHub注册邮箱"
```

✅ 无任何输出 = 成功。验证：`git config user.name` 回显你的用户名。

**③ 确认 GitHub 账号**：能登录 github.com（你的账号 `heituanzi-jpg`），科学上网开着更稳。

**④ 更新进度快照**：`~/code/notes/INDEX.md` 当前周改成 `week07`，薄弱点档案扫一眼——本周找茬题里有它们值班。

**笔记规矩（不变）**：glossary 周末批量补录 10 分钟；mistakes 最低剂量 ≥2 条；week07.md 每天三行。

---

## 第 1 章 先建立直觉：时光机 + 云备份（5 分钟）

**画面一：每个人都经历过的命名地狱。** `报告.docx`、`报告v2.docx`、`报告最终版.docx`、`报告最终版真的最后.docx`——手动管版本，一周就崩。你 W03 留 `bmi_v2.c`、W05 留 `bmi_v3.c`，其实已经在手动干这件事了。

**画面二：游戏存档。** 打 Boss 前先存档，翻车就读档重来。写代码也一样：每完成一个小功能存一个档，改坏了随时回到上一个好状态。

**Git = 自动存档系统（时光机）**：你在本地给代码存档，每个存档点带一句说明，随时翻看历史、随时穿越回去。

**GitHub = 云端存档库 + 展示橱窗**：把本地存档上传云端——电脑炸了代码还在；别人（和你三个月后复试时的导师）能看到你的全部成长记录。

> 📌 **本周的通关标志**：你六周的全部代码出现在你自己的 GitHub 仓库里，带着连续的存档记录。这就是毕业标准里"有连续的 commit 记录"的意思。

> 📒 本周生词（先划线，周末批量补录）：`Git` `GitHub` `版本控制`

---

## 第 2 章 三个核心概念 + 一个类比（10 分钟）

### 2.1 三个词，先混脸熟

| 词 | 大白话 |
|---|---|
| **仓库（repository / repo）** | 一个被 Git 接管的文件夹。接管后，里面的一切变化都被盯着 |
| **提交（commit）** | 一个存档点 = 这次改了什么 + 一句说明 + 时间 + 你的名字 |
| **推送（push）** | 把本地存档上传到 GitHub 云端 |

### 2.2 关键类比：拍照

Git 存档分两步，这是新手最容易晕的地方，一个类比讲透：

```
git add     = 把要拍的东西【摆进拍照区】
git commit  = 【按快门】，咔嚓，存档完成
git push    = 把拍好的照片【上传云相册】
```

为什么要有"拍照区"（学名暂存区）？因为一次快门你可能只想拍一部分东西——比如改了三个文件，只想把其中两个相关的存进"这一张"。**先把要拍的摆好（add），再按快门（commit）。** 忘了 add 直接 commit，等于对着空背景按快门。

还有一个高频词：`git status` = **看看现状**（哪些文件变了、哪些摆进拍照区了）。它是你的仪表盘，拿不准就敲它，敲一百遍也不嫌多。

> 📒 生词：`仓库（repo）` `提交（commit）` `推送（push）` `暂存区`

---

## 第 3 章 【动手】本地时光机：人生第一次存档（30 分钟）

### 3.1 让 Git 接管你的代码文件夹

```bash
cd ~/code/c-learning
git init
```

- `git init` = 在这个文件夹里启动存档系统。它会悄悄建一个隐藏的 `.git` 文件夹（存档仓库本体，**永远别动它**）。

✅ 看到 `Initialized empty Git repository in .../c-learning/.git/`。

⚠️ 从此以后，**所有 git 命令都要在这个文件夹（或它的子文件夹）里敲**，否则报错 `not a git repository`——本周第一坑，先打预防针。

### 3.2 看看现状 + 摆进拍照区 + 按快门

```bash
git status
```

✅ 看到一大串**红色**文件名（你六个周的 .c 和编译产物全在）——红色 = "变了/新来的，但还没摆进拍照区"。

先只拿第一周练手（⚠️ 编译产物不传，第 5 章细说，现在只挑源码）：

```bash
git add week01/hello.c
git status
```

✅ `hello.c` 变**绿色**——绿色 = "已摆进拍照区，等待按快门"。

按快门（`-m` 后面是存档说明，**必须写，写人话**）：

```bash
git commit -m "第一周：人生第一个程序 hello.c"
```

✅ 看到 `[master (root-commit) xxxx] 第一周：...`，`1 file changed`。

### 3.3 翻看存档 + 体验时光机

```bash
git log --oneline
```

✅ 看到一行：一串乱码编号 + 你的存档说明。`--oneline` = 每条存档只显示一行，清爽。

**时光机体验（30 秒）**：往 hello.c 里加一行注释保存，然后：

```bash
git status
```

✅ hello.c 又变红了（"改了，还没摆"）。再 `git add week01/hello.c` → `git commit -m "给 hello.c 加注释"` → `git log --oneline`——**两条存档了**。你的时光机正式开始运转。

> 📝 顺手记进 mistakes.md 候选：`not a git repository` = 没在仓库文件夹里敲命令 → `cd ~/code/c-learning` 再来。

### 3.4 本节坑与预防针

| 症状 | 病因 | 解法 |
|---|---|---|
| `not a git repository` | 没在仓库文件夹里 | `cd ~/code/c-learning` |
| commit 了个寂寞（0 个文件） | 忘了 add 就按快门 | 先 `git add`，`git status` 看绿了再 commit |
| 卡在满屏说明出不来 | 忘写 `-m`，掉进了编辑器 | 按 `Esc` 输入 `:q!` 回车逃出；以后 commit 必带 `-m "说明"` |
| 报错让你先配置身份 | 闸口 B 第②步没做 | 回去补 `git config --global` 两条 |

---

## 第 4 章 【动手】连上 GitHub：上传云相册（40 分钟）

> 本章一次性操作多，跟着走，每步都有 ✅。网络卡住别硬刚，看 4.5 的风险预案。

### 4.1 在 GitHub 上建一个空相册（网页操作，2 分钟）

1. 浏览器打开 github.com，登录
2. 右上角 **【+】→【New repository】**
3. `Repository name` 填：`c-learning`
4. 选 **Public**（公开，才能当展示橱窗）
5. ⚠️ **三个勾选框（Add a README / .gitignore / license）一个都不勾**——我们要传本地已有的仓库，云端必须空着
6. 点【Create repository】

✅ 进入一个"空仓库指引页"，上面有一串 `git@github.com:heituanzi-jpg/c-learning.git` 之类的地址——**复制它备用**。

### 4.2 配一把 SSH 钥匙（一次配置，终身免密）

GitHub 不让用密码上传，要配钥匙（你 ssh 进 MT6000 玩过的那套，升级版）：

```bash
ssh-keygen -t ed25519 -C "你的GitHub注册邮箱"
```

- 连问三个问题（存哪 / 密码 / 确认密码），**全部直接回车**（默认即可）

```bash
cat ~/.ssh/id_ed25519.pub
```

✅ 屏幕打出一长串 `ssh-ed25519 AAAA...` ——**这是公钥（可以示人），全行复制**。

⚠️ 同一个文件夹里还有个**没有 `.pub` 后缀**的 `id_ed25519`——那是**私钥，绝不外传、绝不截图发任何人**（包括我）。公钥是锁，私钥是钥匙。

贴到 GitHub：网页右上角头像 →【Settings】→ 左侧【SSH and GPG keys】→【New SSH key】→ Title 随便写（如 `wsl-ubuntu`），Key 粘贴公钥 →【Add SSH key】。

验证钥匙通了：

```bash
ssh -T git@github.com
```

- 第一次会问 `Are you sure...?`，输 `yes` 回车
- ✅ 看到 `Hi heituanzi-jpg! You've successfully authenticated...` = 钥匙配对成功

❌ 卡住超时（`Connection timed out`）？校园网/宽带常拦 22 端口，换 443 通道（一次配置）：

```bash
printf "Host github.com\n  Hostname ssh.github.com\n  Port 443\n" >> ~/.ssh/config
```

再 `ssh -T git@github.com` 重试。还不行 → 看 4.5 风险预案。

### 4.3 绑定地址 + 上传

```bash
cd ~/code/c-learning
git remote add origin 你复制的仓库地址
git branch -M main
git push -u origin main
```

逐条拆解：

- `git remote add origin 地址` = 把云端相册的地址登记进来，起个小名叫 `origin`（登记一次，终身有效）
- `git branch -M main` = 把本地存档的分支改名为 `main`（GitHub 的默认叫法，对齐）
- `git push -u origin main` = 把本地 `main` 的存档上传到 `origin`；`-u` = 记住这个对应关系，**以后只敲 `git push` 就行**

✅ 看到一排进度 + `* [new branch] main -> main`。

**刷新 GitHub 网页——你的 `hello.c` 和存档说明躺在那里了。** 🎉 截图存好：你的代码第一次上云。

### 4.4 本节坑与预防针

| 症状 | 病因 | 解法 |
|---|---|---|
| `Permission denied (publickey)` | SSH 钥匙没配好/没贴上 | 重做 4.2；确认贴的是 `.pub` 公钥 |
| `ssh -T` 超时 | 22 端口被拦 | 用 4.2 的 443 配置；科学上网保持开 |
| push 报 `src refspec main does not match any` | 一条存档都还没有 | 回第 3 章先 commit 至少一条 |
| 网页让输密码 | 用了 HTTPS 地址又没 token | 换 SSH 地址（`git@github.com:` 开头），回 4.3 重新 add |

### 4.5 风险预案（网络不行时）

**push 不上 ≠ 本周失败。** 本地 commit 已经拿到时光机 80% 的价值。顺序：① 科学上网开全局重试 → ② 443 通道 → ③ 换个时间再 push。本地存档照常进行，网络是早晚的事，别让它卡死你的周节奏。

> 📒 生词：`远程仓库（remote）` `SSH 密钥` `分支（branch/main）`

---

## 第 5 章 .gitignore 与日常三板斧

### 5.1 什么东西不该进相册

你的 `c-learning` 里除了 `.c` 源码，还有几十个**编译出来的可执行文件**（`hello`、`card`、`bmi_v2`……）。它们不该上传：

- 每台电脑都能从源码再编译一份，传它是垃圾重复
- 二进制文件大、变化快，会把存档历史撑得又肥又乱

**`.gitignore` = 一张"免拍清单"**：写在里面的东西，Git 自动无视，不用你每次挑。

在 `~/code/c-learning` 里新建文件 `.gitignore`（注意名字以点开头），内容照抄：

```
# 免拍清单：编译产物（没有扩展名的可执行文件）
*
!*.c
!*.md
!.gitignore
!*/
```

**四行带 `!` 的是"例外"**：默认全忽略（`*`），但 `.c` 源码、`.md` 笔记、`.gitignore` 自己、以及所有文件夹（`!*/`）除外。这套规则正好适配你"可执行文件和源码同名不同后缀"的现状——**照抄即可，原理 ❓悬念**（通配符规则，以后自然懂）。

✅ 验证：`git status`——原来满屏的可执行文件全消失了，只剩 `.c` 和 `.md`。

### 5.2 日常三板斧（以后每周的标准动作）

```bash
git status                          # ① 看现状：改了啥
git add .                           # ② 全摆进拍照区（有 .gitignore 把关，放心的用 .）
git commit -m "第六周：成绩统计器"   # ③ 按快门，写人话
git push                            # ④（联网时）上云
```

**节奏建议**：每完成一个练习/一个版本存一条。存档说明 = 动词开头说人话：`完成`、`修复`、`新增`——第 6 章细讲。

### 5.3 本节坑与预防针

| 症状 | 病因 | 解法 |
|---|---|---|
| 仓库里混进一堆可执行文件 | 没建 `.gitignore` 或写错 | 回 5.1 照抄；已传上去的让我看一眼，有专门的清理命令 |
| `.gitignore` 不生效 | 文件名写错（少了开头的点） | 必须是 `.gitignore`，`ls -a` 检查 |
| `git add .` 之后全绿了慌 | 正常！绿 = 待拍 | 接 commit 就行 |

---

## 第 6 章 程序员基本功（本周增量）

### 6.1 存档说明（commit message）的写法

存档说明是写给三个月后的自己看的（老熟人 again）。对比：

| 烂说明（三个月后看不懂） | 好说明 |
|---|---|
| `update` | `完成成绩统计器：最高/最低/平均` |
| `111` | `修复 BMI 边界：22.6 该判标准` |
| `asdfg` | `新增历史记录功能（v2）` |

规矩：**动词开头，一句话说清"这次干了什么"**。你半年后的 GitHub 绿格子和这一排排说明，就是复试时能摊开讲的成长证据。

### 6.2 两个救场命令（认识即可，别背）

| 场景 | 命令 | 干嘛的 |
|---|---|---|
| 想看看这次到底改了哪几行 | `git diff` | 红绿对比显示改动 |
| 文件改乱了、还没存档，想回到上次存档的样子 | `git restore 文件名` | ⚠️ 丢弃未存档的改动，想清楚再敲 |

### 6.3 顺手播个种子：论文线也配拥有仓库

你的 `~/code/paper-research`（10 对漏洞样本 + README + 实验记录）比 c-learning 更需要时光机——实验跑崩了能读档，改动有据可查，和导师协作也能直接发仓库链接。**本周挑战层就是给它建仓。** 学习线练手，论文线上岗，一套功夫两处用。

---

## 第 7 章 本周练习（分层设计）

> 本周是工具周，练习全是实操。**命令可以复制，但每敲一条，停顿三秒说出"它是干嘛的"**——说不出来就回对应章节。

### 练习 1（跟做层）· 完整走一遍三板斧

**要求**：给 `c-learning` 仓库补上"门面"并上传。

**手把手**：

① `cd ~/code/c-learning`，新建 `README.md`，写两行（这是仓库的门面，GitHub 首页会显示）：

```markdown
# c-learning
我的 C 语言第一阶段学习仓库（W01~W08）。
```

② 建好 5.1 的 `.gitignore`（如果还没建）。

③ 三板斧：

```bash
git status
git add .
git commit -m "补齐六周源码，新增 README 和 .gitignore"
git push
```

✅ 验收：刷新 GitHub，六个 week 文件夹的**源码**都在（没有可执行文件），首页显示你的 README 两行字。

### 练习 2（半独立层）· 时光机体验：改坏，再读档

**要求**：故意"改坏"一个文件，再用 Git 恢复。

**💡 提示**：打开 `week01/hello.c`，把 `printf` 那行删掉，保存 → `git status` 看它变红 → `git diff week01/hello.c` 看你删了哪行 → `git restore week01/hello.c` → 打开文件确认它回来了。

✅ 验收：文件恢复原样，`git status` 干净了。自查：能说出"restore 丢弃的是**没存档**的改动"这句话的意思。

<details><summary>操作清单（做完再点开）</summary>

```bash
# 1. 用 VS Code 删掉 hello.c 里 printf 那行，Ctrl+S 保存
git status                    # 变红：modified
git diff week01/hello.c       # 看到红色删除行
git restore week01/hello.c    # 读档
git status                    # 干净了
```
</details>

### 练习 3（独立层）· 🏆 本周主项目：六周代码全部上云

**要求**：
1. `c-learning` 仓库里 week01~week06 的**全部 .c 源码**都在 GitHub 上（可执行文件不在）
2. `README.md` 扩充成"学习地图"：列出六周，每周一行主题（如 `- W03 判断与分支：BMI 判断版`）
3. 本地 `git log --oneline` 至少 3 条存档（含本周新增的）
4. 把**仓库公开链接**发我（形如 `https://github.com/heituanzi-jpg/c-learning`）

✅ 验收（我这边打开链接核对）：六周源码齐、README 有地图、存档记录连续。

### 练习 4（挑战层·可选）· 论文仓库上岗

**要求**：给 `~/code/paper-research` 也走一遍全流程：`git init` → `.gitignore`（同样的编译产物问题，照抄改改）→ 首次 commit → GitHub 建仓（名字如 `paper-research`，**这个建议 Private 私有**，论文未发表）→ push。

**💡 提示**：流程和练习 3 一模一样，只是换个文件夹。私有仓库建法和 4.1 相同，第 4 步改选 Private。

---

## 第 8 章 每日加餐题库（每天 4 道小练习 · 硬指标）

> 用法不变：每天学完正文做当天 4 题，每题 5~15 分钟。题型：【找茬】【补全】【预测】【微写作】。答案按天折叠，先做再点。

### Day 1（概念日）

1. 【排序】把四步排成日常顺序：`push` / `add` / `status` / `commit`
2. 【补全】拍照类比：add = ______，commit = ______，push = ______
3. 【找茬】`git comit -m "test"`
4. 【微写作】给"修好了九九乘法表的对齐"写一条存档说明

<details><summary>Day 1 答案</summary>

1. `status → add → commit → push`（看现状 → 摆进拍照区 → 按快门 → 上云）
2. 摆进拍照区 / 按快门 / 上传云相册
3. `comit` 拼错了：`commit`（终端不惯着拼写，报错 `not a git command`）
4. 示例：`修复九九乘法表：式子间用制表符对齐`（动词开头说人话即可）
</details>

### Day 2（本地存档日）

1. 【预测】`git status` 里文件名是红色，说明什么？
2. 【找茬】新建了 `test.c`，直接 `git commit -m "加测试"`，结果存了 0 个文件
3. 【补全】只看一行一条的存档历史：`git log ______`
4. 【微写作】给你这周三次存档各写一条说明（W07 建仓 / 传六周源码 / 加 README）

<details><summary>Day 2 答案</summary>

1. 变了/新来的，但还没摆进拍照区（还没 add）
2. 忘了先 `git add test.c`——对着空背景按快门
3. `--oneline`
4. 示例：`初始化仓库` / `补齐 W01~W06 源码` / `新增 README 学习地图`
</details>

### Day 3（GitHub 日）

1. 【排序】绑定上传三步：`push -u origin main` / `branch -M main` / `remote add origin 地址`
2. 【找茬】配 SSH 时，把 `id_ed25519`（没后缀那个）的内容贴到了 GitHub
3. 【预测】`ssh -T git@github.com` 成功时屏幕上最关键的两个词是什么？
4. 【微写作】给你的 c-learning 写两句 README 开头

<details><summary>Day 3 答案</summary>

1. `remote add → branch -M main → push -u origin main`（登记地址 → 对齐分支名 → 上传并记住对应关系）
2. 贴错成了**私钥**！公钥是 `.pub` 结尾那个。私钥绝不外传；已泄露要删掉重新生成一对
3. `Hi 你的用户名!` + `successfully authenticated`
4. 示例：`# c-learning` + `我的 C 语言第一阶段学习仓库（W01~W08）。`
</details>

### Day 4（.gitignore 日）

1. 【找茬】仓库里混进了几十个可执行文件，GitHub 页面又肥又乱
2. 【预测】`.gitignore` 里写一行 `*.out`，管什么？
3. 【补全】只把源码摆进拍照区（不用 `.`）：`git add ______`
4. 【预测】改乱了还没存档，想回到上次存档的样子，用哪个命令？

<details><summary>Day 4 答案</summary>

1. 没建/写错 `.gitignore`——回 5.1 照抄五行；二进制不该进仓库（能再编译、又大又乱历史）
2. 所有 `.out` 结尾的文件都被无视
3. `git add *.c`（通配符只挑源码；有 .gitignore 把关时 `git add .` 也行）
4. `git restore 文件名`（丢弃未存档的改动，想清楚再敲）
</details>

### Day 5（救场日）

1. 【找茬】在 `~/code` 里敲 `git status`，报 `not a git repository`
2. 【预测】改了 `stat.c` 还没 add，`git status` 里它是什么颜色？
3. 【补全】看这次改了哪几行：`git ______`
4. 【微写作】给论文仓库起个名 + 写它的第一条存档说明

<details><summary>Day 5 答案</summary>

1. 没在仓库文件夹里——`cd ~/code/c-learning`（仓库是这个子文件夹，不是它的上级）
2. 红色（变了没摆）
3. `diff`
4. 示例：`paper-research` + `初始化：10 对 CWE 漏洞样本与验证记录`
</details>

### Day 6（复习日）

1. 【排序】从"改完代码"到"云端可见"五步（含看现状）
2. 【找茬】push 失败，第一反应是"GitHub 坏了"，折腾一小时
3. 【找茬】`git push` 之后发现本地改动根本没上传——因为只 push 没 commit
4. 【微写作】给本周写一条"周总结"存档说明

<details><summary>Day 6 答案</summary>

1. `status → add → commit → push →（刷新网页确认）`
2. 排查顺序错：先看自己网络（科学上网/443 通道），GitHub 很少坏
3. push 只传**已存档**的内容；没 commit 的改动还在工作区——三板斧缺一不可
4. 示例：`第七周：接入 Git，六周代码上云`
</details>

### Day 7（验收预热日）

1. 【找茬】`git push origin master` 报错（你的分支叫 main）
2. 【预测】`push -u origin main` 之后，以后上传只敲 `git push` 行不行？
3. 【补全】验收要看存档历史：`git log ______`
4. 【微写作】列出本周验收要交的三样东西（不看第 9 章先写）

<details><summary>Day 7 答案</summary>

1. 分支名错：你是 `main` 不是 `master`——`git push origin main`（或已 `-u` 过就直接 `git push`）
2. 行：`-u` 已经记住了对应关系
3. `--oneline`
4. 仓库公开链接 / `git log --oneline` 记录 / 题 2 大白话 + 题 3 找茬
</details>

---

## 第 9 章 Week 07 验收（仓库链接 + 3 题 + 硬性条件）

**题 1 · 实操**：把你的 **c-learning 仓库公开链接**发我，附本地 `git log --oneline` 的终端记录（≥ 3 条存档，含本周的）。

**题 2 · 大白话**（周末批量补录 glossary 后一起发我）：
① `git add` 和 `git commit` 的区别是什么？（用"拍照"说，不许抄书）
② `.gitignore` 是干嘛的？为什么编译出来的可执行文件不该传上 GitHub？（至少说出两个理由）

**题 3 · 找茬**：下面这段操作记录有 **5 处错误**。找出来、写出正确做法，至少挑 2 条记进 mistakes.md：

```bash
cd ~/code
git init
git add week01/hello.c
git commit
git remote add origin git@github.com:heituanzi-jpg/c-learning.git
git push origin master
# （想把编译产物 hello 也传上去，直接 git add hello）
```

**硬性条件**：仓库链接 + `glossary.md` 批量补录后新增 ≥ 4 条 + `mistakes.md` 新增 ≥ 2 条，一起发我。这是通关要件。

---

## 第 10 章 本周避坑大全（一页速查，卡住了先翻这页）

| # | 症状 | 病因 | 解法 |
|---|---|---|---|
| 1 | `not a git repository` | 没在仓库文件夹里 | `cd ~/code/c-learning` |
| 2 | commit 存了 0 个文件 | 忘 add 就按快门 | 先 add，`status` 看绿了再 commit |
| 3 | 卡进满屏英文出不来 | 忘 `-m` 掉进编辑器 | `Esc` → `:q!` → 回车；以后必带 `-m "说明"` |
| 4 | commit 报错要配置身份 | 没做闸口 B | `git config --global user.name/user.email` |
| 5 | `Permission denied (publickey)` | SSH 钥匙没配好 | 重做 4.2；贴的是 `.pub` 公钥 |
| 6 | 把私钥贴给了别人/网页 | 公私钥不分 | `.pub` 才是公钥；私钥泄露立刻换一对 |
| 7 | `ssh -T` 超时 | 22 端口被拦 | 443 通道（4.2）；科学上网保持开 |
| 8 | push 说 main 不存在 | 还没有任何存档 | 先完成首次 commit 再 push |
| 9 | 仓库里一堆可执行文件 | 没建 `.gitignore` | 回 5.1 照抄五行 |
| 10 | `.gitignore` 不生效 | 文件名少了开头的点 | 必须叫 `.gitignore`，`ls -a` 检查 |
| 11 | 存档说明写的 update/111 | 没养成习惯 | 动词开头说人话：完成/修复/新增 + 具体内容 |
| 12 | push 失败干着急 | 排查顺序错 | 科学上网 → 443 → 改天再试；本地 commit 照跑 |

---

## 第 11 章 每日安排（一天 1~1.5 小时，做不完顺延）

| 天 | 内容 | 预计 | 对应 |
|---|---|---|---|
| Day 1 | 过闸口（含身份配置）+ 读第 1~2 章 + **加餐 Day 1** | 1h | 0~2 章 + 8.1 |
| Day 2 | 第 3 章本地时光机（init/add/commit/log 全实操）+ **加餐 Day 2** | 1.5h | 3 章 + 8.2 |
| Day 3 | 第 4 章连 GitHub（建仓 + SSH + push）+ **加餐 Day 3** | 1.5h | 4 章 + 8.3 |
| Day 4 | 第 5 章 .gitignore + 三板斧 + 练习 1、2 + **加餐 Day 4** | 1.5h | 5~6 章 + 7.1/7.2 + 8.4 |
| Day 5 | 🏆 练习 3：六周代码全部上云 + README 学习地图 + **加餐 Day 5** | 1.5h | 7.3 + 8.5 |
| Day 6 | 批量补录 glossary（10 分钟封顶）+ 复习避坑大全 +（可选）练习 4 论文仓库 + **加餐 Day 6** | 1h | 10 章 + 7.4 + 8.6 |
| Day 7 | 第 9 章验收 + **加餐 Day 7（验收预热）**，交卷发我 | 1h | 9 章 + 8.7 |

**风险预案（三条够用，老规矩）：**

- **卡壳超过 2 天**：把卡住的命令和屏幕上的字原样发我，说一句"卡这了"就算完成任务。
- **某天完全不想学**：最低剂量 = 打开终端，`cd ~/code/c-learning && git log --oneline`，看一眼存档，关上。
- **顺延超过一周**：砍掉练习 4（挑战层）；**push 网络问题不算卡壳**——本地 commit 照跑，网络按 4.5 预案处理。撞上强制休息的周日，顺延。

**配菜（可选）**：卡住了去 B站搜"Git 入门"播放量高的那几集，只看卡住的那个操作。

> 📍 交卷后下一站：🏆 **W08 毕业项目周**——前七周的每一块积木，拼成命令行计算器。你的第一阶段，下周毕业。

---

## 附录 · 本周命令速查卡（截图存手机）

```
一次性配置：
  git config --global user.name "用户名"
  git config --global user.email "邮箱"
  ssh-keygen -t ed25519 -C "邮箱"   → 公钥贴 GitHub
建仓与绑定：
  git init                          启动存档系统（在仓库文件夹里）
  git remote add origin 地址        登记云端地址（一次）
  git branch -M main                对齐分支名
日常三板斧：
  git status                        看现状（红=没摆，绿=待拍）
  git add .                         全摆进拍照区（有 .gitignore 把关）
  git commit -m "动词开头说人话"     按快门
  git push                          上云（首次用 git push -u origin main）
翻看与救场：
  git log --oneline                 存档历史（一行一条）
  git diff 文件名                   看改了哪几行
  git restore 文件名                丢弃未存档改动（想清楚再敲）
免拍清单 .gitignore：* / !*.c / !*.md / !.gitignore / !*/
救命：私钥（无 .pub）绝不外传；not a git repository = 先进仓库文件夹
```

---

*Week 07 讲义 v1.0（完全自学版）｜ 配套主手册 v1.1 + Week03-08 规划 v1.0 ｜ 沿用反馈协议：glossary 周末批量补录、压缩提速（1~1.5h/天）、挑战层可选、每日 4 道加餐题 ｜ 求助顺序：第 10 章避坑大全 → git status 看现状 → Kimi 咒语 → 找导师*
