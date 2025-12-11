运行此文件需在终端输入以下指令
1. 进入目录：在终端中 cd 到代码所在目录（包含 Makefile 的目录）。
2. 清理旧文件：输入指令 make clean
3. 编译代码：输入指令 make
    如果编译成功，终端将显示链接过程，并生成名为 matrix_test 的可执行文件。
    ar rcs libCmatrixPro.a src/matrix_store.o src/matrix_free.o src/matrix_operation.o src/main.o
    Linking executable matrix_test
    gcc src/main.o libCmatrixPro.a -o matrix_test
4. 运行程序：输入指令 ./matrix_test 程序将自动运行并在屏幕上输出矩阵运算的结果和计算时间。