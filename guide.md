# mimalloc覆盖指南
1. 链接mimalloc.lib.dll
2. 将mimalloc.dll和mimalloc-redirect.dll放置到可执行文件同目录
3. target_link_options(mimalloc_demo PRIVATE "/INCLUDE:mi_version")让mimalloc尽可能早地加载
