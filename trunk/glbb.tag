<?xml version='1.0' encoding='ISO-8859-1' standalone='yes' ?>
<tagfile>
  <compound kind="class">
    <name>BB</name>
    <filename>classBB.html</filename>
    <member kind="function" static="yes">
      <type>static QString</type>
      <name>indent</name>
      <anchorfile>classBB.html</anchorfile>
      <anchor>e0</anchor>
      <arglist>(int depth)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static QString</type>
      <name>escapedAttribute</name>
      <anchorfile>classBB.html</anchorfile>
      <anchor>e1</anchor>
      <arglist>(const QString &amp;str)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static QString</type>
      <name>escapedText</name>
      <anchorfile>classBB.html</anchorfile>
      <anchor>e2</anchor>
      <arglist>(const QString &amp;str)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_AbstractTool</name>
    <filename>classBB__AbstractTool.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>move</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>release</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>click</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>remove</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(QVector&lt; BB_DrawObject * &gt; *objects, BB_DrawObject *delObject)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_LastLogicMouseClick</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_pLogic</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPoint</type>
      <name>m_pScreen</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QWidget *</type>
      <name>parentWidget</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Building</name>
    <filename>classBB__Building.html</filename>
    <base>BB_FileObject</base>
    <member kind="function">
      <type></type>
      <name>BB_Building</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const QDir &amp;path, const QString &amp;fileName, const QString &amp;name=QString(&quot;&quot;))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~BB_Building</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>keyBoardEdit</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>getDrawObjects</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(QTextStream &amp;out)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>generateXElement</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(QTextStream &amp;out, int depth)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_Level &gt; *</type>
      <name>m_Levels</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>m_DrawObject</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Config</name>
    <filename>classBB__Config.html</filename>
    <member kind="function">
      <type>void</type>
      <name>setCurrentProjectPath</name>
      <anchorfile>classBB__Config.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const QString &amp;path)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getCurrentProjectPath</name>
      <anchorfile>classBB__Config.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>save</name>
      <anchorfile>classBB__Config.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>open</name>
      <anchorfile>classBB__Config.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QString</type>
      <name>m_CurrentProjectPath</name>
      <anchorfile>classBB__Config.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_DlgProjectNew</name>
    <filename>classBB__DlgProjectNew.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_DlgProjectNew</name>
      <anchorfile>classBB__DlgProjectNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getProjectDir</name>
      <anchorfile>classBB__DlgProjectNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QDir</type>
      <name>getProjectPath</name>
      <anchorfile>classBB__DlgProjectNew.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getProjectName</name>
      <anchorfile>classBB__DlgProjectNew.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getProjectDescription</name>
      <anchorfile>classBB__DlgProjectNew.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Ui_ProjectNewDialog</type>
      <name>m_Dlg</name>
      <anchorfile>classBB__DlgProjectNew.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QDir</type>
      <name>m_Dir</name>
      <anchorfile>classBB__DlgProjectNew.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QString</type>
      <name>m_ProjectPath</name>
      <anchorfile>classBB__DlgProjectNew.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QString</type>
      <name>m_ProjectDir</name>
      <anchorfile>classBB__DlgProjectNew.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QString</type>
      <name>m_ProjectName</name>
      <anchorfile>classBB__DlgProjectNew.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QString</type>
      <name>m_ProjectDescription</name>
      <anchorfile>classBB__DlgProjectNew.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Doc</name>
    <filename>classBB__Doc.html</filename>
    <base>BB_FileObject</base>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_Terrain *</type>
      <name>getTerrain</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual QVector&lt; BB_Building * &gt; *</type>
      <name>getBuildings</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual QVector&lt; BB_Level * &gt; *</type>
      <name>getLevels</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>open</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(QString &amp;fileName)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>close</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>createNew</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(const QString &amp;name, const QString &amp;desc, const QDir &amp;path)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(QTextStream &amp;out)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_Building *</type>
      <name>newBuilding</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_Level *</type>
      <name>newLevel</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>clear</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Terrain *</type>
      <name>m_Terrain</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_Building * &gt;</type>
      <name>m_Buildings</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_Level * &gt;</type>
      <name>m_Levels</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QDir</type>
      <name>m_ProjectPath</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QString</type>
      <name>m_ProjectFile</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>p4</anchor>
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
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QString name=&quot;&quot;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>moveBy</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(C2dVector pMove)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>show</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(BB_Transformer &amp;transformer, QPainter &amp;painter) const =0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QColor &amp;</type>
      <name>getColor</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setColor</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const QColor &amp;_newVal=&quot;Green&quot;)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>isHit</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(C2dVector hit)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QColor</type>
      <name>m_Color</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>m_hitRange</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_DWPoint</name>
    <filename>classBB__DWPoint.html</filename>
    <base>BB_DrawObject</base>
    <member kind="function">
      <type></type>
      <name>BB_DWPoint</name>
      <anchorfile>classBB__DWPoint.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Wall *wall, bool first=false)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isFirst</name>
      <anchorfile>classBB__DWPoint.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__DWPoint.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_FileObject</name>
    <filename>classBB__FileObject.html</filename>
    <base>BB_Object</base>
    <member kind="function">
      <type></type>
      <name>BB_FileObject</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const QDir &amp;path, const QString &amp;filename, const QString &amp;name=QString(&quot;&quot;))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~BB_FileObject</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>save</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getFileName</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QDir</type>
      <name>getFilePath</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFileName</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const QString &amp;theValue)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFilePath</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const QDir &amp;theValue)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(QTextStream &amp;out)=0</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_Modified</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QString</type>
      <name>m_FileName</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QDir</type>
      <name>m_FilePath</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Level</name>
    <filename>classBB__Level.html</filename>
    <base>BB_FileObject</base>
    <member kind="function">
      <type></type>
      <name>BB_Level</name>
      <anchorfile>classBB__Level.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const QDir &amp;path, const QString &amp;fileName, const QString &amp;name=QString(&quot;&quot;))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>generateXElement</name>
      <anchorfile>classBB__Level.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QTextStream &amp;out, int depth)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classBB__Level.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QTextStream &amp;out)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__Level.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Line</name>
    <filename>classBB__Line.html</filename>
    <base>BB_DrawObject</base>
    <member kind="function">
      <type></type>
      <name>BB_Line</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Point *p1, BB_Point *p2)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isHit</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(C2dVector hit)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>show</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(BB_Transformer &amp;transformer, QPainter &amp;painter) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setPos1</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(BB_Point *Value)</arglist>
    </member>
    <member kind="function">
      <type>BB_Point *</type>
      <name>getPos1</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setPos2</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(BB_Point *Value)</arglist>
    </member>
    <member kind="function">
      <type>BB_Point *</type>
      <name>getPos2</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remove</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(BB_Point *point)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point *</type>
      <name>m_Pos1</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point *</type>
      <name>m_Pos2</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_Richtung</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_MainWindow</name>
    <filename>classBB__MainWindow.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_MainWindow</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent=0, Qt::WFlags flags=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_MainWindow</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>initActions</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>keyPressEvent</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(QKeyEvent *e)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>keyReleaseEvent</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(QKeyEvent *e)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QMenuBar *</type>
      <name>m_MainMenuBar</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QMenu *</type>
      <name>m_MenuFile</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QMenu *</type>
      <name>m_MenuView</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QStatusBar *</type>
      <name>m_StatusBar</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QTabWidget *</type>
      <name>m_TabWidget</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_Keys</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p5</anchor>
      <arglist>[256]</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Doc *</type>
      <name>m_Doc</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QMenu *</type>
      <name>m_MenuProject</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Config</type>
      <name>m_Config</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QAction *</type>
      <name>m_aProjectClose</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QAction *</type>
      <name>m_aProjectNew</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QAction *</type>
      <name>m_aProjectOpen</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p11</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Object</name>
    <filename>classBB__Object.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_Object</name>
      <anchorfile>classBB__Object.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QString name=&quot;&quot;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~BB_Object</name>
      <anchorfile>classBB__Object.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getObjectNr</name>
      <anchorfile>classBB__Object.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setName</name>
      <anchorfile>classBB__Object.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const QString &amp;theValue)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getName</name>
      <anchorfile>classBB__Object.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDescription</name>
      <anchorfile>classBB__Object.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const QString &amp;theValue)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getDescription</name>
      <anchorfile>classBB__Object.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>generateXElement</name>
      <anchorfile>classBB__Object.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(QTextStream &amp;out, int depth)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__Object.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Point</name>
    <filename>classBB__Point.html</filename>
    <base>BB_DrawObject</base>
    <member kind="function">
      <type></type>
      <name>BB_Point</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(C2dVector p)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>moveBy</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(C2dVector pMove)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>show</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(BB_Transformer &amp;transformer, QPainter &amp;painter) const </arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getRadius</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRadius</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(int r)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isHit</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(C2dVector hit)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPos</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(const C2dVector &amp;theValue)</arglist>
    </member>
    <member kind="function">
      <type>C2dVector</type>
      <name>getPos</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; BB_Line * &gt; *</type>
      <name>getLines</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeLine</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>(BB_Line *line)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addLine</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>(BB_Line *line)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteLines</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>(QVector&lt; BB_DrawObject * &gt; *objects)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a14</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setX</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a15</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setY</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a16</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getX</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a17</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getY</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a18</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>generateXElement</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a19</anchor>
      <arglist>(QTextStream &amp;out, int depth)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_Pos</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_Line * &gt;</type>
      <name>m_Lines</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Tab</name>
    <filename>classBB__Tab.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_Tab</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Doc *doc, QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>BB_Tab</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(BB_Doc *doc, bool leftFrame, bool rightFrame, QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>initTab</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unsetToolButton</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(QAction *action)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>addWidgetLeft</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(QWidget *widget, int stretchFaktor=0)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>addWidgetRight</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(QWidget *widget, int stretchFaktor=0)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>createToolButton</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>b2</anchor>
      <arglist>(QAction *action, const char *method)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Doc *</type>
      <name>m_Doc</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_WorkArea *</type>
      <name>m_Center</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QFrame *</type>
      <name>m_LeftFrame</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QFrame *</type>
      <name>m_RightFrame</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QGridLayout *</type>
      <name>m_ToolsGridLayout</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>m_ToolButtonCount</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QList&lt; QAction * &gt; *</type>
      <name>m_ToolButtonActions</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>p6</anchor>
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
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Doc *doc, QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateBuildingList</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_ToolZoom</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_ToolPointNew</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_ToolMove</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_ToolLineNew</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_Building * &gt; *</type>
      <name>m_Buildings</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QListWidget *</type>
      <name>m_BuildingsListWidget</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPushButton *</type>
      <name>m_ButtonBuildingDelete</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>p6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPushButton *</type>
      <name>m_ButtonBuildingNew</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>p7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPushButton *</type>
      <name>m_ButtonBuildingProperties</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>p8</anchor>
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
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Doc *doc, QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPushButton *</type>
      <name>m_ButtonLevelProperties</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPushButton *</type>
      <name>m_ButtonLevelDelete</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPushButton *</type>
      <name>m_ButtonLevelNew</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_ToolZoom</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
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
      <anchorfile>classBB__TabTerrain.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Doc *doc, QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Terrain</name>
    <filename>classBB__Terrain.html</filename>
    <base>BB_FileObject</base>
    <member kind="function">
      <type></type>
      <name>BB_Terrain</name>
      <anchorfile>classBB__Terrain.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const QDir &amp;path, const QString &amp;fileName, const QString &amp;name=QString(&quot;&quot;))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>generateXElement</name>
      <anchorfile>classBB__Terrain.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QTextStream &amp;out, int depth)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classBB__Terrain.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QTextStream &amp;out)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolLineNew</name>
    <filename>classBB__ToolLineNew.html</filename>
    <base>BB_AbstractTool</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolLineNew</name>
      <anchorfile>classBB__ToolLineNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>click</name>
      <anchorfile>classBB__ToolLineNew.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>move</name>
      <anchorfile>classBB__ToolLineNew.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>release</name>
      <anchorfile>classBB__ToolLineNew.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_DrawObject *</type>
      <name>m_movedPoint</name>
      <anchorfile>classBB__ToolLineNew.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Wall *</type>
      <name>tmpWall</name>
      <anchorfile>classBB__ToolLineNew.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolMove</name>
    <filename>classBB__ToolMove.html</filename>
    <base>BB_AbstractTool</base>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>click</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>move</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>release</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt;</type>
      <name>m_Selection</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point *</type>
      <name>comparePoint</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>p1</anchor>
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
      <anchorfile>classBB__ToolPointNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>move</name>
      <anchorfile>classBB__ToolPointNew.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>release</name>
      <anchorfile>classBB__ToolPointNew.html</anchorfile>
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
      <anchorfile>classBB__ToolZoom.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_WorkArea *area)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>click</name>
      <anchorfile>classBB__ToolZoom.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>move</name>
      <anchorfile>classBB__ToolZoom.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>release</name>
      <anchorfile>classBB__ToolZoom.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(QMouseEvent *me, QVector&lt; BB_DrawObject * &gt; *objects, BB_Transformer *transformer)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_WorkArea *</type>
      <name>m_WorkArea</name>
      <anchorfile>classBB__ToolZoom.html</anchorfile>
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
      <anchorfile>classBB__Transformer.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const QPoint &amp;theValue)</arglist>
    </member>
    <member kind="function">
      <type>QPoint</type>
      <name>getOffset</name>
      <anchorfile>classBB__Transformer.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setScale</name>
      <anchorfile>classBB__Transformer.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(double theValue)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getScale</name>
      <anchorfile>classBB__Transformer.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>screenToLogical</name>
      <anchorfile>classBB__Transformer.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(C2dVector &amp;dest, const QPoint &amp;source) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logicalToScreen</name>
      <anchorfile>classBB__Transformer.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(QPoint &amp;dest, const C2dVector &amp;source) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Wall</name>
    <filename>classBB__Wall.html</filename>
    <base>BB_Line</base>
    <member kind="function">
      <type></type>
      <name>BB_Wall</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Point *p1, BB_Point *p2)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>generateXElement</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QTextStream &amp;out, int depth)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_WorkArea</name>
    <filename>classBB__WorkArea.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_WorkArea</name>
      <anchorfile>classBB__WorkArea.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>zoom</name>
      <anchorfile>classBB__WorkArea.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(double faktor)</arglist>
    </member>
    <member kind="function">
      <type>BB_AbstractTool *</type>
      <name>getTool</name>
      <anchorfile>classBB__WorkArea.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTool</name>
      <anchorfile>classBB__WorkArea.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(BB_AbstractTool *tool)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setZoomFaktor</name>
      <anchorfile>classBB__WorkArea.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(double zoom)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>getDrawObjects</name>
      <anchorfile>classBB__WorkArea.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDrawObjects</name>
      <anchorfile>classBB__WorkArea.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(QVector&lt; BB_DrawObject * &gt; *objectsVector)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_WorkFrame *</type>
      <name>m_WorkFrame</name>
      <anchorfile>classBB__WorkArea.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_ZoomFaktor</name>
      <anchorfile>classBB__WorkArea.html</anchorfile>
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
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setZoomFaktor</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(double faktor)</arglist>
    </member>
    <member kind="function">
      <type>BB_AbstractTool *</type>
      <name>getTool</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTool</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(BB_AbstractTool *tool)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDrawObjects</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(QVector&lt; BB_DrawObject * &gt; *theValue)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>getDrawObjects</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>mousePressEvent</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>mouseReleaseEvent</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>paintEvent</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>b2</anchor>
      <arglist>(QPaintEvent *pe)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>mouseMoveEvent</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>b3</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>drawCenter</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>b4</anchor>
      <arglist>(QPainter &amp;painter)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_ZoomFaktor</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_Tool</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>m_DrawObjects</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Transformer</type>
      <name>m_Transformer</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_XDocGenerator</name>
    <filename>classBB__XDocGenerator.html</filename>
    <base>BB_XGenerator</base>
    <member kind="function">
      <type></type>
      <name>BB_XDocGenerator</name>
      <anchorfile>classBB__XDocGenerator.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Doc *doc)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classBB__XDocGenerator.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QIODevice *device)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Doc *</type>
      <name>m_Doc</name>
      <anchorfile>classBB__XDocGenerator.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_XGenerator</name>
    <filename>classBB__XGenerator.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_XGenerator</name>
      <anchorfile>classBB__XGenerator.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~BB_XGenerator</name>
      <anchorfile>classBB__XGenerator.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classBB__XGenerator.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QIODevice *device)=0</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static QString</type>
      <name>indent</name>
      <anchorfile>classBB__XGenerator.html</anchorfile>
      <anchor>e0</anchor>
      <arglist>(int depth)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QTextStream</type>
      <name>m_Stream</name>
      <anchorfile>classBB__XGenerator.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>C2dVector</name>
    <filename>classC2dVector.html</filename>
    <member kind="function">
      <type></type>
      <name>C2dVector</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(double x=0, double y=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~C2dVector</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setX</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const double &amp;_newVal)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const double &amp;</type>
      <name>x</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setY</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(const double &amp;_newVal)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const double &amp;</type>
      <name>y</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>C2dVector</type>
      <name>getNormalVector</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>getLength</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>getAbstand</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(C2dVector v2)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual C2dVector</type>
      <name>operator+</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(const C2dVector &amp;v2) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual C2dVector</type>
      <name>operator-</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>(const C2dVector &amp;v2) const </arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>getClassName</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>print</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_X</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_Y</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="dir">
    <name>editor/</name>
    <path>/home/high/devel/bbuilder/editor/</path>
    <filename>dir_000000.html</filename>
    <file>bb.cpp</file>
    <file>bb.h</file>
    <file>bb_abstracttool.cpp</file>
    <file>bb_abstracttool.h</file>
    <file>bb_building.cpp</file>
    <file>bb_building.h</file>
    <file>bb_config.cpp</file>
    <file>bb_config.h</file>
    <file>bb_dlgprojectnew.cpp</file>
    <file>bb_dlgprojectnew.h</file>
    <file>bb_doc.cpp</file>
    <file>bb_doc.h</file>
    <file>bb_drawobject.cpp</file>
    <file>bb_drawobject.h</file>
    <file>bb_dwpoint.cpp</file>
    <file>bb_dwpoint.h</file>
    <file>bb_fileobject.cpp</file>
    <file>bb_fileobject.h</file>
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
    <file>bb_toollinenew.cpp</file>
    <file>bb_toollinenew.h</file>
    <file>bb_toolmove.cpp</file>
    <file>bb_toolmove.h</file>
    <file>bb_toolpointnew.cpp</file>
    <file>bb_toolpointnew.h</file>
    <file>bb_toolzoom.cpp</file>
    <file>bb_toolzoom.h</file>
    <file>bb_transformer.cpp</file>
    <file>bb_transformer.h</file>
    <file>bb_wall.cpp</file>
    <file>bb_wall.h</file>
    <file>bb_workarea.cpp</file>
    <file>bb_workarea.h</file>
    <file>bb_workframe.cpp</file>
    <file>bb_workframe.h</file>
    <file>bb_xdocgenerator.cpp</file>
    <file>bb_xdocgenerator.h</file>
    <file>bb_xgenerator.cpp</file>
    <file>bb_xgenerator.h</file>
    <file>c2dvector.cpp</file>
    <file>c2dvector.h</file>
    <file>main.cpp</file>
    <file>moc_bb_dlgprojectnew.cpp</file>
    <file>moc_bb_mainwindow.cpp</file>
    <file>moc_bb_tab.cpp</file>
    <file>moc_bb_tabbuilding.cpp</file>
    <file>moc_bb_tablevel.cpp</file>
    <file>moc_bb_tabterrain.cpp</file>
    <file>moc_bb_workarea.cpp</file>
    <file>ui_buildingEdit.h</file>
    <file>ui_projectNew.h</file>
  </compound>
  <compound kind="dir">
    <name>renderer/</name>
    <path>/home/high/devel/bbuilder/renderer/</path>
    <filename>dir_000001.html</filename>
    <file>main.cpp</file>
  </compound>
</tagfile>
