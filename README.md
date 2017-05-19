Ngnix 代码研究，基于nginx-1.12.0

为了方便阅读和调度代码，我将代码组织成了一个Xcode project：nginx-1.12.0_proj/nginx.xcodeproj

nginx-1.12.0_proj 是将源代码解压后，运行./configure --with-debug 所得，除了在阅读代码时，对源代码添加少量注释外，未对源代码做其他修改。

test 目录为阅读代码时做的一些测试。

为了方便调度，对conf/nginx.conf 做了修改：

#for development
daemon off;
master_process off;

请修改运行时参数：
Product >> Scheme >> Edit Scheme
Run 设置里的 Arguments 选项，把Arguments Passed On Launch 设成正确的config 文件路径


