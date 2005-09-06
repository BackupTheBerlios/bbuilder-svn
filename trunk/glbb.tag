<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
<tagfile>
  <compound kind="class">
    <name>BB_AbstractTool</name>
    <filename>classBB__AbstractTool.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>move</name>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>release</name>
      <anchor>a3</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>click</name>
      <anchor>a4</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Building</name>
    <filename>classBB__Building.html</filename>
    <base>BB_Object</base>
    <member kind="function">
      <type></type>
      <name>~BB_Building</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>keyBoardEdit</name>
      <anchor>a2</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>getDrawObjects</name>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_Level &gt; *</type>
      <name>m_Levels</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>m_DrawObject</name>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Data</name>
    <filename>classBB__Data.html</filename>
  </compound>
  <compound kind="class">
    <name>BB_Doc</name>
    <filename>classBB__Doc.html</filename>
    <member kind="function">
      <type>BB_Terrain *</type>
      <name>getTerrain</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; BB_Building * &gt; *</type>
      <name>getBuildings</name>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; BB_Level &gt; *</type>
      <name>getLevels</name>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Terrain *</type>
      <name>m_Terrain</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_Building * &gt; *</type>
      <name>m_Buildings</name>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_Level &gt; *</type>
      <name>m_Levels</name>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_DrawObject</name>
    <filename>classBB__DrawObject.html</filename>
    <base>BB_Object</base>
    <member kind="function">
      <type></type>
      <name>BB_DrawObject</name>
      <anchor>a1</anchor>
      <arglist>(QPoint p)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>moveBy</name>
      <anchor>a3</anchor>
      <arglist>(QPoint pMove)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>show</name>
      <anchor>a4</anchor>
      <arglist>(BB_Transformer &amp;transformer, QPainter &amp;painter) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QColor &amp;</type>
      <name>getColor</name>
      <anchor>a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setColor</name>
      <anchor>a6</anchor>
      <arglist>(const QColor &amp;_newVal=&quot;Green&quot;)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setP0</name>
      <anchor>a7</anchor>
      <arglist>(const QPoint &amp;theValue)</arglist>
    </member>
    <member kind="function">
      <type>QPoint</type>
      <name>getP0</name>
      <anchor>a8</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isHit</name>
      <anchor>a9</anchor>
      <arglist>(QPoint hit)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPoint</type>
      <name>m_P0</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QColor</type>
      <name>m_Color</name>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>m_hitRange</name>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Level</name>
    <filename>classBB__Level.html</filename>
    <base>BB_Object</base>
  </compound>
  <compound kind="class">
    <name>BB_Line</name>
    <filename>classBB__Line.html</filename>
    <base>BB_DrawObject</base>
    <member kind="function">
      <type></type>
      <name>BB_Line</name>
      <anchor>a0</anchor>
      <arglist>(BB_Point *p1, BB_Point *p2)</arglist>
    </member>
    <member kind="function">
      <type>QPoint</type>
      <name>getP0</name>
      <anchor>a2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isHit</name>
      <anchor>a3</anchor>
      <arglist>(QPoint hit)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QColor &amp;</type>
      <name>getColor</name>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>moveBy</name>
      <anchor>a5</anchor>
      <arglist>(QPoint pMove)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setColor</name>
      <anchor>a6</anchor>
      <arglist>(const QColor &amp;_newVal)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>show</name>
      <anchor>a7</anchor>
      <arglist>(BB_Transformer &amp;transformer, QPainter &amp;painter) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setP0</name>
      <anchor>a8</anchor>
      <arglist>(const QPoint &amp;theValue)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPos1</name>
      <anchor>a9</anchor>
      <arglist>(BB_Point *Value)</arglist>
    </member>
    <member kind="function">
      <type>BB_Point *</type>
      <name>getPos1</name>
      <anchor>a10</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPos2</name>
      <anchor>a11</anchor>
      <arglist>(BB_Point *Value)</arglist>
    </member>
    <member kind="function">
      <type>BB_Point *</type>
      <name>getPos2</name>
      <anchor>a12</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point *</type>
      <name>m_Pos1</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point *</type>
      <name>m_Pos2</name>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_MainWindow</name>
    <filename>classBB__MainWindow.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_MainWindow</name>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent=0, Qt::WFlags flags=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_MainWindow</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>keyPressEvent</name>
      <anchor>b0</anchor>
      <arglist>(QKeyEvent *e)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>keyReleaseEvent</name>
      <anchor>b1</anchor>
      <arglist>(QKeyEvent *e)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QMenuBar *</type>
      <name>m_MainMenuBar</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QMenu *</type>
      <name>m_MenuFile</name>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QMenu *</type>
      <name>m_MenuView</name>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QStatusBar *</type>
      <name>m_StatusBar</name>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QTabWidget *</type>
      <name>m_TabWidget</name>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_Keys</name>
      <anchor>p5</anchor>
      <arglist>[256]</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Doc *</type>
      <name>m_Doc</name>
      <anchor>p6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Object</name>
    <filename>classBB__Object.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_Object</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>BB_Object</name>
      <anchor>a1</anchor>
      <arglist>(QString &amp;name)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_Object</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getObjectNr</name>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setName</name>
      <anchor>a4</anchor>
      <arglist>(const QString &amp;theValue)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getName</name>
      <anchor>a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDescription</name>
      <anchor>a6</anchor>
      <arglist>(const QString &amp;theValue)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getDescription</name>
      <anchor>a7</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Point</name>
    <filename>classBB__Point.html</filename>
    <base>BB_DrawObject</base>
    <member kind="function">
      <type></type>
      <name>BB_Point</name>
      <anchor>a1</anchor>
      <arglist>(QPoint p)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>moveBy</name>
      <anchor>a3</anchor>
      <arglist>(QPoint pMove)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>show</name>
      <anchor>a4</anchor>
      <arglist>(BB_Transformer &amp;transformer, QPainter &amp;painter) const </arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getRadius</name>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRadius</name>
      <anchor>a6</anchor>
      <arglist>(int r)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isHit</name>
      <anchor>a7</anchor>
      <arglist>(QPoint hit)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Tab</name>
    <filename>classBB__Tab.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_Tab</name>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>BB_Tab</name>
      <anchor>a1</anchor>
      <arglist>(bool leftFrame, bool rightFrame, QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>initTab</name>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unsetToolButton</name>
      <anchor>a4</anchor>
      <arglist>(QAction *action)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>addWidgetLeft</name>
      <anchor>b0</anchor>
      <arglist>(QWidget *widget, int stretchFaktor=0)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>addWidgetRight</name>
      <anchor>b1</anchor>
      <arglist>(QWidget *widget, int stretchFaktor=0)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>createToolButton</name>
      <anchor>b2</anchor>
      <arglist>(QAction *action, const char *method)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_WorkArea *</type>
      <name>m_Center</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QFrame *</type>
      <name>m_LeftFrame</name>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QFrame *</type>
      <name>m_RightFrame</name>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QGridLayout *</type>
      <name>m_ToolsGridLayout</name>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>m_ToolButtonCount</name>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QList&lt; QAction * &gt; *</type>
      <name>m_ToolButtonActions</name>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_TabBuilding</name>
    <filename>classBB__TabBuilding.html</filename>
    <base>BB_Tab</base>
    <member kind="function">
      <type></type>
      <name>BB_TabBuilding</name>
      <anchor>a0</anchor>
      <arglist>(QVector&lt; BB_Building * &gt; *buildings, QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateBuildingList</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_ToolZoom</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_ToolPointNew</name>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_ToolMove</name>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_Building * &gt; *</type>
      <name>m_Buildings</name>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QListWidget *</type>
      <name>m_BuildingsListWidget</name>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPushButton *</type>
      <name>m_ButtonBuildingDelete</name>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPushButton *</type>
      <name>m_ButtonBuildingNew</name>
      <anchor>p6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPushButton *</type>
      <name>m_ButtonBuildingProperties</name>
      <anchor>p7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_TabLevel</name>
    <filename>classBB__TabLevel.html</filename>
    <base>BB_Tab</base>
    <member kind="function">
      <type></type>
      <name>BB_TabLevel</name>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPushButton *</type>
      <name>m_ButtonLevelProperties</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPushButton *</type>
      <name>m_ButtonLevelDelete</name>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPushButton *</type>
      <name>m_ButtonLevelNew</name>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_ToolZoom</name>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_TabTerrain</name>
    <filename>classBB__TabTerrain.html</filename>
    <base>BB_Tab</base>
    <member kind="function">
      <type></type>
      <name>BB_TabTerrain</name>
      <anchor>a0</anchor>
      <arglist>(BB_Terrain *terrain, QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Terrain</name>
    <filename>classBB__Terrain.html</filename>
    <base>BB_Object</base>
  </compound>
  <compound kind="class">
    <name>BB_ToolMove</name>
    <filename>classBB__ToolMove.html</filename>
    <base>BB_AbstractTool</base>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>click</name>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>move</name>
      <anchor>a3</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>release</name>
      <anchor>a4</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPoint</type>
      <name>m_LastLogicMouseClick</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt;</type>
      <name>m_Selection</name>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPoint</type>
      <name>m_pLogic</name>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPoint</type>
      <name>m_pScreen</name>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolPointNew</name>
    <filename>classBB__ToolPointNew.html</filename>
    <base>BB_AbstractTool</base>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>click</name>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>move</name>
      <anchor>a3</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>release</name>
      <anchor>a4</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolZoom</name>
    <filename>classBB__ToolZoom.html</filename>
    <base>BB_AbstractTool</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolZoom</name>
      <anchor>a0</anchor>
      <arglist>(BB_WorkArea *area)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>click</name>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>move</name>
      <anchor>a3</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>release</name>
      <anchor>a4</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_WorkArea *</type>
      <name>m_WorkArea</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Transformer</name>
    <filename>classBB__Transformer.html</filename>
    <member kind="function">
      <type>void</type>
      <name>setOffset</name>
      <anchor>a2</anchor>
      <arglist>(const QPoint &amp;theValue)</arglist>
    </member>
    <member kind="function">
      <type>QPoint</type>
      <name>getOffset</name>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setScale</name>
      <anchor>a4</anchor>
      <arglist>(double theValue)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getScale</name>
      <anchor>a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>screenToLogical</name>
      <anchor>a6</anchor>
      <arglist>(QPoint &amp;dest, const QPoint &amp;source) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logicalToScreen</name>
      <anchor>a7</anchor>
      <arglist>(QPoint &amp;dest, const QPoint &amp;source) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_WorkArea</name>
    <filename>classBB__WorkArea.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_WorkArea</name>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>zoom</name>
      <anchor>a2</anchor>
      <arglist>(double faktor)</arglist>
    </member>
    <member kind="function">
      <type>BB_AbstractTool *</type>
      <name>getTool</name>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTool</name>
      <anchor>a4</anchor>
      <arglist>(BB_AbstractTool *tool)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setZoomFaktor</name>
      <anchor>a5</anchor>
      <arglist>(double zoom)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>getDrawObjects</name>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDrawObjects</name>
      <anchor>a7</anchor>
      <arglist>(QVector&lt; BB_DrawObject * &gt; *objectsVector)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_WorkFrame *</type>
      <name>m_WorkFrame</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_ZoomFaktor</name>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_WorkFrame</name>
    <filename>classBB__WorkFrame.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_WorkFrame</name>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setZoomFaktor</name>
      <anchor>a2</anchor>
      <arglist>(double faktor)</arglist>
    </member>
    <member kind="function">
      <type>BB_AbstractTool *</type>
      <name>getTool</name>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTool</name>
      <anchor>a4</anchor>
      <arglist>(BB_AbstractTool *tool)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDrawObjects</name>
      <anchor>a5</anchor>
      <arglist>(QVector&lt; BB_DrawObject * &gt; *theValue)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>getDrawObjects</name>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>mousePressEvent</name>
      <anchor>b0</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>mouseReleaseEvent</name>
      <anchor>b1</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>paintEvent</name>
      <anchor>b2</anchor>
      <arglist>(QPaintEvent *pe)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>mouseMoveEvent</name>
      <anchor>b3</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_ZoomFaktor</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_Tool</name>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>m_DrawObjects</name>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Transformer</type>
      <name>m_Transformer</name>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="dir">
    <name>editor/</name>
    <path>/home/high/develop/bbuilder/editor/</path>
    <filename>dir_000000.html</filename>
    <file>bb_abstracttool.cpp</file>
    <file>bb_abstracttool.h</file>
    <file>bb_building.cpp</file>
    <file>bb_building.h</file>
    <file>bb_data.cpp</file>
    <file>bb_data.h</file>
    <file>bb_doc.cpp</file>
    <file>bb_doc.h</file>
    <file>bb_drawobject.cpp</file>
    <file>bb_drawobject.h</file>
    <file>bb_level.cpp</file>
    <file>bb_level.h</file>
    <file>bb_line.cpp</file>
    <file>bb_line.h</file>
    <file>bb_mainwindow.cpp</file>
    <file>bb_mainwindow.h</file>
    <file>bb_object.cpp</file>
    <file>bb_object.h</file>
    <file>bb_point.cpp</file>
    <file>bb_point.h</file>
    <file>bb_tab.cpp</file>
    <file>bb_tab.h</file>
    <file>bb_tabbuilding.cpp</file>
    <file>bb_tabbuilding.h</file>
    <file>bb_tablevel.cpp</file>
    <file>bb_tablevel.h</file>
    <file>bb_tabterrain.cpp</file>
    <file>bb_tabterrain.h</file>
    <file>bb_terrain.cpp</file>
    <file>bb_terrain.h</file>
    <file>bb_toolmove.cpp</file>
    <file>bb_toolmove.h</file>
    <file>bb_toolpointnew.cpp</file>
    <file>bb_toolpointnew.h</file>
    <file>bb_toolzoom.cpp</file>
    <file>bb_toolzoom.h</file>
    <file>bb_transformer.cpp</file>
    <file>bb_transformer.h</file>
    <file>bb_workarea.cpp</file>
    <file>bb_workarea.h</file>
    <file>bb_workframe.cpp</file>
    <file>bb_workframe.h</file>
    <file>main.cpp</file>
    <file>ui_buildingEdit.h</file>
  </compound>
  <compound kind="dir">
    <name>renderer/</name>
    <path>/home/high/develop/bbuilder/renderer/</path>
    <filename>dir_000001.html</filename>
    <file>main.cpp</file>
  </compound>
</tagfile>
