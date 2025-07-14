
功能描述：
    1. 主窗体实现可拖拉
    2. 实现ComboBox样式
    3. 实现各类按钮样式
    4. 添加配置读取文件类
    
    5. 添加语言切换功能
       步骤： 
           1. 生成.ts文件：
               1. 在pro中添加 TRANSLATIONS += lang_english.ts
               2. 然后点击工具-->外部-->Qt语言家-->更新翻译 -->自动生成lang_english.ts文件
           2. 生成.qm文件
               1. 运行Lingusit,将.ts文件拉进来进行翻译，
               2. 点击发布，生成.qm文件
           3. 调用QTranslator 
