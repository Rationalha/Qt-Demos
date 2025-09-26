********************************QTableView样式***************************
QTableView {
    color: white;                               /*表格内文字颜色*/
    gridline-color: #2b4c8e;                  /*表格内框颜色*/
    background-color: #172844;               /*表格内背景色*/
    border: 2px solid  #2b4c8e;
    border-radius: 0px;
    padding: 2px 4px;
}

QHeaderView {
    color: white;
    font: bold 10pt;
    background-color: #193057;/*设置表头空白区域背景色*/
    border: 0px solid rgb(144, 144, 144);
    border-left-color: rgba(255, 255, 255, 0);
    border-top-color: rgba(255, 255, 255, 0);
    border-radius:0px;
}
QHeaderView::section {
    color: white;
    background-color: #193057;
    border: 1px solid transparent;
    border-left-color: #2b4c8e;
    border-right-color: #2b4c8e;
    border-radius:0px;
} 

********************************QPushButton样式***************************
QPushButton#btn_start_run{
	border-image: url(:/icons/btn_run_normal.png);
}
QPushButton#btn_start_run::hover{
	border-image: url(:/icons/btn_run_hover.png);
}
QPushButton#btn_start_run::pressed{
	border-image: url(:/icons/btn_run_pressed.png);
}

QPushButton#btn_stop_run{
	border-image: url(:/icons/btn_stop_normal.png);
}
QPushButton#btn_stop_run::hover{
	border-image: url(:/icons/btn_stop_hover.png);
}
QPushButton#btn_stop_run::pressed{
	border-image: url(:/icons/btn_stop_pressed.png);
}

QPushButton#btn_pause{
	border-image: url(:/icons/btn_pause_normal.png);
}
QPushButton#btn_pause::hover{
	border-image: url(:/icons/btn_pause_hover.png);
}
QPushButton#btn_pause::pressed{
	border-image: url(:/icons/btn_pause_pressed.png);
}
********************************QGroupBox样式***************************
QGroupBox {
	line-height:18px;
	font-weight:700;
	font: 25 18pt "Microsoft YaHei";
	font-size: 18px; 
	font-weight: bold;
	border:1px solid #254e93;
	border-radius:8px;
	margin-top: 1ex;        /* 标题与内容的间距 */
	color: rgba(190, 190, 190, 1);
}

QGroupBox::title {
    subcontrol-origin: margin; /* 标题位于边框内 */
    subcontrol-position: top center; /* 标题居中 */
    padding: 0 3px;              /* 标题内边距 */
}
********************************QCheckBox样式***************************
QCheckBox { 
    border: 0px solid #FFFFFF; /*设置qcheckbox控件的边框为0px（无边框）*/
    border-radius: 20px; 
    padding: 4px; 
    spacing: 10px; 
} 
/*设置qcheckbox控件中的勾选框的属性*/
 QCheckBox::indicator{
width: 16px;/*勾选框的大小*/
height: 16px;
}
/*勾选框未选中时的图像*/
QCheckBox::indicator:unchecked {
    border: 1px solid white; 
    image: url(:/images/check_normal.png); 
}
/*勾选框选中时的图像*/
QCheckBox::indicator:checked {
    border: none; 
	image: url(:/icons/check_checked.png);
}
********************************QCombobox样式***************************
  /*QCombobox主体*/
QComboBox {
   font: 25 14pt "Microsoft YaHei";
   border: 1px solid;
   border-color: #254e93;
   border-radius: 2px;
	padding-left: 5px; /* 文本距离左边界有5px */
	background-color: #172844;
	color: #bebebe; /* 文本颜色 */
   padding: 1px 2px 1px 2px;  /*针对于组合框中的文本内容*/
	text-align:bottom;
	border-image: url(:/icons/lineedit_normal.png);
}
/*QCombobox右侧按钮*/
QComboBox::drop-down {
    width: 30px;
    subcontrol-origin: padding;
    subcontrol-position: top right;/*放于右方顶部*/
    border-top-right-radius: 3px;/*设置边框圆角*/
    border-bottom-right-radius: 3px;
}
/*QCombobox右侧按钮的箭头图标*/
QComboBox::down-arrow {
	border-image: url(:/icons/dow_arraw.png);
	width: 16px;/*设置该图标的宽高*/
	height: 12px;
}
/* 下拉后，整个下拉窗体样式 */
QComboBox QAbstractItemView {
    font: 25 14pt "Microsoft YaHei";
    color: #bebebe; /* 文本颜色 */
    border: none;/*边框宽度、线形、颜色*/
	 background-color: rgb(0, 66, 97);
    padding: 1px 5px 1px 5px;  /*针对于组合框中的文本内容*/
}

/* 下拉后，整个下拉窗体每项的样式 */
QComboBox QAbstractItemView::item {
   height: 40px;   /* 项的高度（设置pComboBox->setView(new QListView());后，该项才起作用*/
	background-color: rgb(23, 40, 68);
   font: 25 14pt "Microsoft YaHei";
   color: #bebebe; /* 文本颜色 */
}

***************************QScrollBar 样式**************************
QScrollBar:vertical
{
    width:8px;
    background:rgba(0,0,0,0%);
    margin:0px,0px,0px,0px;
    padding-top:9px;    
    padding-bottom:9px;
}
QScrollBar::handle:vertical
{
    width:8px;
    background:rgba(0,0,0,25%);
    border-radius:4px;  
    min-height:20;
}
QScrollBar::handle:vertical:hover
{
    width:8px;
    background:rgba(0,0,0,50%);  
    border-radius:4px;
    min-height:20;
}
QScrollBar::add-line:vertical  
{
    height:9px;width:8px;
    border-image:url(:/images/a/3.png);
    subcontrol-position:bottom;
}
QScrollBar::sub-line:vertical   
{
    height:9px;width:8px;
    border-image:url(:/images/a/1.png);
    subcontrol-position:top;
}
QScrollBar::add-line:vertical:hover  
{
    height:9px;width:8px;
    border-image:url(:/images/a/4.png);
    subcontrol-position:bottom;
}
QScrollBar::sub-line:vertical:hover 
{
    height:9px;width:8px;
    border-image:url(:/images/a/2.png);
    subcontrol-position:top;
}
QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical   
{
    background:rgba(0,0,0,10%);
    border-radius:4px;
}
