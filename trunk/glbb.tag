<?xml version='1.0' encoding='ISO-8859-1' standalone='yes' ?>
<tagfile>
  <compound kind="class">
    <name>BB</name>
    <filename>classBB.html</filename>
    <member kind="function">
      <type></type>
      <name>BB</name>
      <anchorfile>classBB.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB</name>
      <anchorfile>classBB.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>compare</name>
      <anchorfile>classBB.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const void *a, const void *b)</arglist>
    </member>
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
    <member kind="variable" static="yes">
      <type>static QRegExp</type>
      <name>regExpAlphanumeric</name>
      <anchorfile>classBB.html</anchorfile>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static QRegExp</type>
      <name>regExpNumeric</name>
      <anchorfile>classBB.html</anchorfile>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static QRegExpValidator *</type>
      <name>validAlphanumeric</name>
      <anchorfile>classBB.html</anchorfile>
      <anchor>s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static QRegExpValidator *</type>
      <name>validNumeric</name>
      <anchorfile>classBB.html</anchorfile>
      <anchor>s3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_AbstractTool</name>
    <filename>classBB__AbstractTool.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_AbstractTool</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~BB_AbstractTool</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>move</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me, bool overX, bool overY)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>release</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>click</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(QMouseEvent *me)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>deleteObject</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(BB_DrawObject *delObject)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>deleteSelection</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>reset</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_DrawObject *</type>
      <name>getClickedObject</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(const C2dVector &amp;posLogic, const std::type_info &amp;type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setTransformer</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(BB_Transformer *transformer)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_Transformer *</type>
      <name>getTransformer</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setSelectionVector</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>(QVector&lt; BB_DrawObject * &gt; *selectionVector)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual QVector&lt; BB_DrawObject * &gt; *</type>
      <name>getSelectionVector</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setToolObjects</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>(QVector&lt; BB_DrawObject * &gt; *theValue)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual QVector&lt; BB_DrawObject * &gt; *</type>
      <name>getToolObjects</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a14</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>clearSelection</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a15</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setAction</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a16</anchor>
      <arglist>(QAction *theValue)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual QAction *</type>
      <name>getAction</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a17</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setDocComponent</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a18</anchor>
      <arglist>(BB_DocComponent *theValue)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_DocComponent *</type>
      <name>getDocComponent</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a19</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setObjects</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a20</anchor>
      <arglist>(QVector&lt; BB_DrawObject * &gt; *objects)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getShowDrawObjects</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a21</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_AbstractToolWidget *</type>
      <name>getToolWidget</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a22</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setWorkFrame</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a23</anchor>
      <arglist>(BB_WorkFrame *value)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateWidget</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a24</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>documentChanged</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a25</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setIcon</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a26</anchor>
      <arglist>(const QIcon &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>QIcon</type>
      <name>getIcon</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a27</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>selectObject</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>a28</anchor>
      <arglist>(BB_DrawObject *object)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_LastLogicMouseClick</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QWidget *</type>
      <name>m_ParentWidget</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QAction *</type>
      <name>m_Action</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_WorkFrame *</type>
      <name>m_WorkFrame</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_pLogic</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPoint</type>
      <name>m_pScreen</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>m_Objects</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>m_Selection</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Transformer *</type>
      <name>m_Transformer</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>m_ToolObjects</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_DocComponent *</type>
      <name>m_Component</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_ShowDrawObjects</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractToolWidget *</type>
      <name>m_ToolWidget</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p12</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QIcon</type>
      <name>m_Icon</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_DrawObject *</type>
      <name>m_FirstSelectedObject</name>
      <anchorfile>classBB__AbstractTool.html</anchorfile>
      <anchor>p14</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_AbstractToolWidget</name>
    <filename>classBB__AbstractToolWidget.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_AbstractToolWidget</name>
      <anchorfile>classBB__AbstractToolWidget.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_AbstractTool *parentTool, QWidget *parent=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~BB_AbstractToolWidget</name>
      <anchorfile>classBB__AbstractToolWidget.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateWidget</name>
      <anchorfile>classBB__AbstractToolWidget.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setSelection</name>
      <anchorfile>classBB__AbstractToolWidget.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QVector&lt; BB_DrawObject * &gt; *vector)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>clearToolWidget</name>
      <anchorfile>classBB__AbstractToolWidget.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setWidgetEnabled</name>
      <anchorfile>classBB__AbstractToolWidget.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(bool value)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_ParentTool</name>
      <anchorfile>classBB__AbstractToolWidget.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_DrawObject *</type>
      <name>m_Tmp_DrawObject</name>
      <anchorfile>classBB__AbstractToolWidget.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>m_Selection</name>
      <anchorfile>classBB__AbstractToolWidget.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Building</name>
    <filename>classBB__Building.html</filename>
    <base>BB_DocComponent</base>
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
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>keyBoardEdit</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QTextStream &amp;out)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remove</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addLevel</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(BB_Level *level)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; BB_Level * &gt; *</type>
      <name>getLevels</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeLevel</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(BB_Level *level)</arglist>
    </member>
    <member kind="function">
      <type>BB_Level *</type>
      <name>getLevel</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(int index)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getLevelCount</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>getHeight</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>createGl</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>(QVector&lt; C3dTriangle &gt; &amp;triangles, C3dVector vector, double rotation, double scale, double height)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_Level * &gt;</type>
      <name>m_Levels</name>
      <anchorfile>classBB__Building.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_BuildingPosition</name>
    <filename>classBB__BuildingPosition.html</filename>
    <base>BB_TerrainPoint</base>
    <member kind="function">
      <type></type>
      <name>BB_BuildingPosition</name>
      <anchorfile>classBB__BuildingPosition.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Building *building, int buildingId, BB_DocComponent *component, C2dVector &amp;pos, double height, double angle)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_BuildingPosition</name>
      <anchorfile>classBB__BuildingPosition.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>show</name>
      <anchorfile>classBB__BuildingPosition.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(BB_Transformer &amp;transformer, QPainter &amp;painter) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__BuildingPosition.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>generateXElement</name>
      <anchorfile>classBB__BuildingPosition.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(QTextStream &amp;out, int depth)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRotation</name>
      <anchorfile>classBB__BuildingPosition.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getRotation</name>
      <anchorfile>classBB__BuildingPosition.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resolveBuildingId</name>
      <anchorfile>classBB__BuildingPosition.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(BB_Doc *doc)</arglist>
    </member>
    <member kind="function">
      <type>BB_Building *</type>
      <name>getBuilding</name>
      <anchorfile>classBB__BuildingPosition.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>createGl</name>
      <anchorfile>classBB__BuildingPosition.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(QVector&lt; C3dTriangle &gt; &amp;triangles, C3dVector vector, double rotation, double scale, double height)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_Rotation</name>
      <anchorfile>classBB__BuildingPosition.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>m_BuildingId</name>
      <anchorfile>classBB__BuildingPosition.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Building *</type>
      <name>m_Building</name>
      <anchorfile>classBB__BuildingPosition.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_DocComponent *</type>
      <name>m_ParentDocComponent</name>
      <anchorfile>classBB__BuildingPosition.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_BuildingTriangle</name>
    <filename>classBB__BuildingTriangle.html</filename>
    <base>BB_Triangle</base>
    <member kind="function">
      <type></type>
      <name>BB_BuildingTriangle</name>
      <anchorfile>classBB__BuildingTriangle.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Point *p1, BB_Point *p2, BB_Point *p3)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_BuildingTriangle</name>
      <anchorfile>classBB__BuildingTriangle.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__BuildingTriangle.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>createGl</name>
      <anchorfile>classBB__BuildingTriangle.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QVector&lt; C3dTriangle &gt; &amp;triangles, C3dVector vector, double rotation, double scale, double height)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Config</name>
    <filename>classBB__Config.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_Config</name>
      <anchorfile>classBB__Config.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_Config</name>
      <anchorfile>classBB__Config.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
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
    <name>BB_ConstructionElement</name>
    <filename>classBB__ConstructionElement.html</filename>
    <base>BB_Rect</base>
    <member kind="function">
      <type></type>
      <name>BB_ConstructionElement</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(C2dVector v1, C2dVector v2)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ConstructionElement</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTextureFileName</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const QString &amp;Value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTextureAbsoluteFileName</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const QString &amp;Value)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getTextureFileName</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>openTextureDlg</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>show</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(BB_Transformer &amp;transformer, QPainter &amp;painter) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setWallPosition1</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(const C2dVector &amp;Value)</arglist>
    </member>
    <member kind="function">
      <type>C2dVector</type>
      <name>getWallPosition1</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setWallPosition2</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(const C2dVector &amp;Value)</arglist>
    </member>
    <member kind="function">
      <type>C2dVector</type>
      <name>getWallPosition2</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCoefficientPos1</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>(const C2dVector &amp;Value)</arglist>
    </member>
    <member kind="function">
      <type>C2dVector</type>
      <name>getCoefficientPos1</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCoefficientPos2</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>(const C2dVector &amp;Value)</arglist>
    </member>
    <member kind="function">
      <type>C2dVector</type>
      <name>getCoefficientPos2</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>a14</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QString</type>
      <name>m_TextureFileName</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QImage</type>
      <name>m_Image</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_WallPosition1</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_WallPosition2</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_CoefficientPos1</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_CoefficientPos2</name>
      <anchorfile>classBB__ConstructionElement.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_DlgBuildingEdit</name>
    <filename>classBB__DlgBuildingEdit.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_DlgBuildingEdit</name>
      <anchorfile>classBB__DlgBuildingEdit.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_DlgBuildingEdit</name>
      <anchorfile>classBB__DlgBuildingEdit.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const QString</type>
      <name>getName</name>
      <anchorfile>classBB__DlgBuildingEdit.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const QString</type>
      <name>getDescription</name>
      <anchorfile>classBB__DlgBuildingEdit.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDescription</name>
      <anchorfile>classBB__DlgBuildingEdit.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(const QString &amp;desc)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setName</name>
      <anchorfile>classBB__DlgBuildingEdit.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const QString &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getPlanFile</name>
      <anchorfile>classBB__DlgBuildingEdit.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPlanFile</name>
      <anchorfile>classBB__DlgBuildingEdit.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(QString &amp;file)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Ui_BuildingEditDialog</type>
      <name>m_Dlg</name>
      <anchorfile>classBB__DlgBuildingEdit.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_DlgLevelEdit</name>
    <filename>classBB__DlgLevelEdit.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_DlgLevelEdit</name>
      <anchorfile>classBB__DlgLevelEdit.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_DlgLevelEdit</name>
      <anchorfile>classBB__DlgLevelEdit.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const QString</type>
      <name>getDescription</name>
      <anchorfile>classBB__DlgLevelEdit.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const QString</type>
      <name>getName</name>
      <anchorfile>classBB__DlgLevelEdit.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const QString</type>
      <name>getPlanFile</name>
      <anchorfile>classBB__DlgLevelEdit.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDescription</name>
      <anchorfile>classBB__DlgLevelEdit.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const QString &amp;desc)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setName</name>
      <anchorfile>classBB__DlgLevelEdit.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const QString &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPlanFile</name>
      <anchorfile>classBB__DlgLevelEdit.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(const QString &amp;file)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Ui::LevelEditDialog</type>
      <name>m_Dlg</name>
      <anchorfile>classBB__DlgLevelEdit.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_DlgOpenTexture</name>
    <filename>classBB__DlgOpenTexture.html</filename>
    <member kind="slot">
      <type>void</type>
      <name>slotTextureFileSearch</name>
      <anchorfile>classBB__DlgOpenTexture.html</anchorfile>
      <anchor>i0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>BB_DlgOpenTexture</name>
      <anchorfile>classBB__DlgOpenTexture.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getTextureFile</name>
      <anchorfile>classBB__DlgOpenTexture.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTextureFile</name>
      <anchorfile>classBB__DlgOpenTexture.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QString pfad)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Ui_textureOpenDialog</type>
      <name>m_Dlg</name>
      <anchorfile>classBB__DlgOpenTexture.html</anchorfile>
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
      <type></type>
      <name>~BB_DlgProjectNew</name>
      <anchorfile>classBB__DlgProjectNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
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
    <name>BB_DlgTerrainEdit</name>
    <filename>classBB__DlgTerrainEdit.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_DlgTerrainEdit</name>
      <anchorfile>classBB__DlgTerrainEdit.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_DlgTerrainEdit</name>
      <anchorfile>classBB__DlgTerrainEdit.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const QString</type>
      <name>getName</name>
      <anchorfile>classBB__DlgTerrainEdit.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const QString</type>
      <name>getDescription</name>
      <anchorfile>classBB__DlgTerrainEdit.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDescription</name>
      <anchorfile>classBB__DlgTerrainEdit.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(const QString &amp;desc)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setName</name>
      <anchorfile>classBB__DlgTerrainEdit.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const QString &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getPlanFile</name>
      <anchorfile>classBB__DlgTerrainEdit.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPlanFile</name>
      <anchorfile>classBB__DlgTerrainEdit.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(QString &amp;file)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Ui_TerrainEditDialog</type>
      <name>m_Dlg</name>
      <anchorfile>classBB__DlgTerrainEdit.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_DlgWallEdit</name>
    <filename>classBB__DlgWallEdit.html</filename>
    <member kind="slot">
      <type>void</type>
      <name>slotToolDoor</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>i0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>slotToolWindow</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>i1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>slotToolMove</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>i2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>slotToolTexture</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>i3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>slotToolDelete</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>i4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>BB_DlgWallEdit</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Wall *wall, BB_DocComponent *docComponent, double hohe=3.2, QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_DlgWallEdit</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLevel</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(BB_DocComponent *Value)</arglist>
    </member>
    <member kind="function">
      <type>BB_DocComponent *</type>
      <name>getLevel</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setWall</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(BB_Wall *Value)</arglist>
    </member>
    <member kind="function">
      <type>BB_Wall *</type>
      <name>getWall</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>openTextureDlg</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>paintEvent</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(QPaintEvent *pe)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>resizeEvent</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(QResizeEvent *re)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>initilize</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>b2</anchor>
      <arglist>(BB_Wall *wall, BB_DocComponent *docComponent, double hohe=3.2)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>initSingals</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>b3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>unsetButton</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>b4</anchor>
      <arglist>(QToolButton *button)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_DocComponent *</type>
      <name>m_level</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Wall *</type>
      <name>m_wall</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_DlgWallEditArea *</type>
      <name>m_CentralWidget</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_DlgWallEditPreview *</type>
      <name>m_PreviewWidget</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QToolButton *</type>
      <name>m_ButtonWindow</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QToolButton *</type>
      <name>m_ButtonDoor</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QToolButton *</type>
      <name>m_ButtonMove</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>p6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QToolButton *</type>
      <name>m_ButtonTexture</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>p7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QToolButton *</type>
      <name>m_ButtonDelete</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>p8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; QToolButton * &gt; *</type>
      <name>m_Buttons</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>p9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_ToolDoorNew *</type>
      <name>m_ToolDoorNew</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>p10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_ToolWindowNew *</type>
      <name>m_ToolWindowNew</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>p11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_ToolMove *</type>
      <name>m_ToolMove</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>p12</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_ToolTexture *</type>
      <name>m_ToolTexture</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>p13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_ToolDelete *</type>
      <name>m_ToolDelete</name>
      <anchorfile>classBB__DlgWallEdit.html</anchorfile>
      <anchor>p14</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_DlgWallEditArea</name>
    <filename>classBB__DlgWallEditArea.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_DlgWallEditArea</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Wall *wall, BB_DocComponent *docComponent, double hohe=3.2, QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_DlgWallEditArea</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTool</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(BB_AbstractTool *tool)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>loadTexture</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>paintEvent</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(QPaintEvent *re)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>resizeEvent</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(QResizeEvent *re)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>mousePressEvent</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>b2</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>mouseReleaseEvent</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>b3</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>mouseMoveEvent</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>b4</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>makeWallTexture</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>b5</anchor>
      <arglist>(QPainter *p)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>generatePositionOnWall</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>b6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Map *</type>
      <name>m_currentMap</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Wall *</type>
      <name>m_Wall</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_Height</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_Width</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_PixelHeight</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_PixelWidth</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_Proportion</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>p6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_ProportionWidth</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>p7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_ProportionHeight</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>p8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_Tool</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>p9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>m_DrawObjects</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>p10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>m_Selection</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>p11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>m_ToolObjects</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>p12</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Transformer</type>
      <name>m_transformer</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>p13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPixmap</type>
      <name>m_WallTexture</name>
      <anchorfile>classBB__DlgWallEditArea.html</anchorfile>
      <anchor>p14</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_DlgWallEditPreview</name>
    <filename>classBB__DlgWallEditPreview.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_DlgWallEditPreview</name>
      <anchorfile>classBB__DlgWallEditPreview.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Wall *wall, BB_DocComponent *docComponent, QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_DlgWallEditPreview</name>
      <anchorfile>classBB__DlgWallEditPreview.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>initilize</name>
      <anchorfile>classBB__DlgWallEditPreview.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(BB_Wall *wall, BB_DocComponent *docComponent)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>paintEvent</name>
      <anchorfile>classBB__DlgWallEditPreview.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(QPaintEvent *pe)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Doc</name>
    <filename>classBB__Doc.html</filename>
    <base>BB_FileObject</base>
    <member kind="function">
      <type></type>
      <name>BB_Doc</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_Doc</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>BB_Terrain *</type>
      <name>getTerrain</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; BB_Building * &gt; *</type>
      <name>getBuildings</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; BB_Level * &gt; *</type>
      <name>getLevels</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>open</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(QString fileName)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>close</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>createNew</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(const QString &amp;name, const QString &amp;desc, const QDir &amp;path)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>write</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(QTextStream &amp;out)</arglist>
    </member>
    <member kind="function">
      <type>BB_Building *</type>
      <name>newBuilding</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type>BB_Level *</type>
      <name>newLevel</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>(BB_Building *building, QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type>BB_Building *</type>
      <name>newBuilding</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>(QDir &amp;path, QString &amp;fileName)</arglist>
    </member>
    <member kind="function">
      <type>BB_Level *</type>
      <name>newLevel</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>(BB_Building *building, QDir &amp;path, QString &amp;fileName)</arglist>
    </member>
    <member kind="function">
      <type>BB_Terrain *</type>
      <name>newTerrain</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>(QDir &amp;path, QString &amp;fileName)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>deleteBuilding</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a14</anchor>
      <arglist>(QListWidgetItem *item)</arglist>
    </member>
    <member kind="function">
      <type>BB_Building *</type>
      <name>getBuilding</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a15</anchor>
      <arglist>(QListWidgetItem *item)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addObserver</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a16</anchor>
      <arglist>(BB_Tab *tab)</arglist>
    </member>
    <member kind="function">
      <type>BB_Building *</type>
      <name>getBuilding</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a17</anchor>
      <arglist>(int index)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>deleteLevel</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a18</anchor>
      <arglist>(BB_Level *level)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteLevels</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a19</anchor>
      <arglist>(BB_Building *building)</arglist>
    </member>
    <member kind="function">
      <type>BB_Building *</type>
      <name>getBuildingById</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a20</anchor>
      <arglist>(int objectId)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>showGl</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a21</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>createGlObjects</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a22</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>CVector3 *</type>
      <name>getCollisionVector</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a23</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; C3dTriangle &gt; &amp;</type>
      <name>getTriangles</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>a24</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>documentChanged</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>clear</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>b1</anchor>
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
    <member kind="variable" protection="protected">
      <type>QList&lt; BB_Tab * &gt;</type>
      <name>m_Observer</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>m_MaxId</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>p6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; C3dTriangle &gt;</type>
      <name>m_Triangles</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>p7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>CVector3 *</type>
      <name>m_CollisionVector</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>p8</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend" protection="protected">
      <type>friend class</type>
      <name>BB_XDocHandler</name>
      <anchorfile>classBB__Doc.html</anchorfile>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_DocComponent</name>
    <filename>classBB__DocComponent.html</filename>
    <base>BB_FileObject</base>
    <base>BB_Map</base>
    <base>BB_DrawDevice</base>
    <member kind="function">
      <type></type>
      <name>BB_DocComponent</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const QDir &amp;path, const QString &amp;fileName, const QString &amp;name)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_DocComponent</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>open</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>BB_Point *</type>
      <name>getScalePoint_1</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>BB_Point *</type>
      <name>getScalePoint_2</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setScaleReal</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getScaleReal</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>double *</type>
      <name>getScaleRealPointer</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getMeterPerPixel</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(double pixel)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getPixelPerMeter</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(double meter)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>keyBoardEdit</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>generateXElement</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>(QTextStream &amp;out, int depth)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>createGl</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>(QVector&lt; C3dTriangle &gt; &amp;triangles, double scale)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>getHeight</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>mapChanged</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point *</type>
      <name>m_ScalePoint_1</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point *</type>
      <name>m_ScalePoint_2</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_ScaleValue</name>
      <anchorfile>classBB__DocComponent.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Door</name>
    <filename>classBB__Door.html</filename>
    <base>BB_ConstructionElement</base>
    <member kind="function">
      <type></type>
      <name>BB_Door</name>
      <anchorfile>classBB__Door.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(C2dVector v1, C2dVector v2)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_Door</name>
      <anchorfile>classBB__Door.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>generateXElement</name>
      <anchorfile>classBB__Door.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QTextStream &amp;out, int depth)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_DrawDevice</name>
    <filename>classBB__DrawDevice.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_DrawDevice</name>
      <anchorfile>classBB__DrawDevice.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~BB_DrawDevice</name>
      <anchorfile>classBB__DrawDevice.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual QVector&lt; BB_DrawObject * &gt; *</type>
      <name>getDrawObjects</name>
      <anchorfile>classBB__DrawDevice.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setOffset</name>
      <anchorfile>classBB__DrawDevice.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const C2dVector &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>const C2dVector &amp;</type>
      <name>getOffset</name>
      <anchorfile>classBB__DrawDevice.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt;</type>
      <name>m_DrawObjects</name>
      <anchorfile>classBB__DrawDevice.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_Offset</name>
      <anchorfile>classBB__DrawDevice.html</anchorfile>
      <anchor>p1</anchor>
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
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>isHit</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(const C2dVector &amp;hit)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isHit</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const QRectF &amp;rect)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSelected</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(bool theValue)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isSelected</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setBrush</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(const QBrush &amp;theValue)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPen</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>(const QPen &amp;theValue)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>moveEvent</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>createGl</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>(QVector&lt; C3dTriangle &gt; &amp;triangles, C3dVector vector, double rotation, double scale, double height)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTextureFileName</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>(const QString &amp;Value)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getTextureFileName</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a14</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTextureAbsoluteFileName</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>a15</anchor>
      <arglist>(const QString &amp;Value)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>m_hitRange</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_Selected</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPen</type>
      <name>m_Pen</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPen</type>
      <name>m_PenSelected</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QBrush</type>
      <name>m_Brush</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QBrush</type>
      <name>m_BrushSelected</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QString</type>
      <name>m_TextureFileName</name>
      <anchorfile>classBB__DrawObject.html</anchorfile>
      <anchor>p6</anchor>
      <arglist></arglist>
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
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>save</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>open</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getFileName</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QDir</type>
      <name>getFilePath</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFileName</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const QString &amp;theValue)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFilePath</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(const QDir &amp;theValue)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual QListWidgetItem *</type>
      <name>getListWidgetItem</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setName</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>(const QString &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>read</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>(QXmlDefaultHandler &amp;handler, QIODevice *dev)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual QString</type>
      <name>getErrorString</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setModified</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>(bool value)</arglist>
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
    <member kind="variable" protection="protected">
      <type>QListWidgetItem *</type>
      <name>m_ListWidgetItem</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QXmlDefaultHandler *</type>
      <name>m_Handler</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QString</type>
      <name>m_ErrorString</name>
      <anchorfile>classBB__FileObject.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Level</name>
    <filename>classBB__Level.html</filename>
    <base>BB_DocComponent</base>
    <member kind="function">
      <type></type>
      <name>BB_Level</name>
      <anchorfile>classBB__Level.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Building *building, const QDir &amp;path, const QString &amp;fileName, const QString &amp;name=QString(&quot;&quot;))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~BB_Level</name>
      <anchorfile>classBB__Level.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
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
    <member kind="function">
      <type>void</type>
      <name>setHeight</name>
      <anchorfile>classBB__Level.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(double Value)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual double</type>
      <name>getHeight</name>
      <anchorfile>classBB__Level.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>BB_Building *</type>
      <name>getBuilding</name>
      <anchorfile>classBB__Level.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>keyBoardEdit</name>
      <anchorfile>classBB__Level.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>createGl</name>
      <anchorfile>classBB__Level.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(QVector&lt; C3dTriangle &gt; &amp;triangles, C3dVector vector, double rotation, double scale, double height)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_Height</name>
      <anchorfile>classBB__Level.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Building *</type>
      <name>m_Building</name>
      <anchorfile>classBB__Level.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_LevelTriangle</name>
    <filename>classBB__LevelTriangle.html</filename>
    <base>BB_Triangle</base>
    <member kind="function">
      <type></type>
      <name>BB_LevelTriangle</name>
      <anchorfile>classBB__LevelTriangle.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Point *p1, BB_Point *p2, BB_Point *p3)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_LevelTriangle</name>
      <anchorfile>classBB__LevelTriangle.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>createGl</name>
      <anchorfile>classBB__LevelTriangle.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QVector&lt; C3dTriangle &gt; &amp;triangles, C3dVector vector, double rotation, double scale, double height)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__LevelTriangle.html</anchorfile>
      <anchor>a3</anchor>
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
    <member kind="function">
      <type></type>
      <name>~BB_Line</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isHit</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const C2dVector &amp;hit)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isHit</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const QRectF &amp;rect)</arglist>
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
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getLength</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getWinkel</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>moveEvent</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const C2dVector &amp;</type>
      <name>getMiddle</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>a13</anchor>
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
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_Middle</name>
      <anchorfile>classBB__Line.html</anchorfile>
      <anchor>p3</anchor>
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
    <member kind="variable" protection="protected">
      <type>QStatusBar *</type>
      <name>m_StatusBar</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QTabWidget *</type>
      <name>m_TabWidget</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Config</type>
      <name>m_Config</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Doc</type>
      <name>m_Doc</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QMenuBar *</type>
      <name>m_MainMenuBar</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QMenu *</type>
      <name>m_MenuFile</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QMenu *</type>
      <name>m_MenuView</name>
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
      <type>QAction *</type>
      <name>m_aProjectClose</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QAction *</type>
      <name>m_aProjectNew</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QAction *</type>
      <name>m_aProjectOpen</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QAction *</type>
      <name>m_aViewOptions</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QAction *</type>
      <name>m_aFileSave</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p12</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QAction *</type>
      <name>m_aFileExit</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_TabBuilding *</type>
      <name>m_TabBuilding</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p14</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_TabTerrain *</type>
      <name>m_TabTerrain</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p15</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_TabLevel *</type>
      <name>m_TabLevel</name>
      <anchorfile>classBB__MainWindow.html</anchorfile>
      <anchor>p16</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Map</name>
    <filename>classBB__Map.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_Map</name>
      <anchorfile>classBB__Map.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~BB_Map</name>
      <anchorfile>classBB__Map.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMap</name>
      <anchorfile>classBB__Map.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const QPixmap &amp;map)</arglist>
    </member>
    <member kind="function">
      <type>QPixmap &amp;</type>
      <name>getMap</name>
      <anchorfile>classBB__Map.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setZoom</name>
      <anchorfile>classBB__Map.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(double z)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getZoom</name>
      <anchorfile>classBB__Map.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMapFileName</name>
      <anchorfile>classBB__Map.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const QString &amp;filename)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getMapFileName</name>
      <anchorfile>classBB__Map.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>loadMap</name>
      <anchorfile>classBB__Map.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(QDir &amp;path)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>mapChanged</name>
      <anchorfile>classBB__Map.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPixmap</type>
      <name>m_Map</name>
      <anchorfile>classBB__Map.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_Zoom</name>
      <anchorfile>classBB__Map.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QString</type>
      <name>m_MapFileName</name>
      <anchorfile>classBB__Map.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_NavigationLine</name>
    <filename>classBB__NavigationLine.html</filename>
    <base>BB_Line</base>
    <member kind="function">
      <type></type>
      <name>BB_NavigationLine</name>
      <anchorfile>classBB__NavigationLine.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Point *p1, BB_Point *p2)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_NavigationLine</name>
      <anchorfile>classBB__NavigationLine.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__NavigationLine.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_NavigationPoint</name>
    <filename>classBB__NavigationPoint.html</filename>
    <base>BB_Point</base>
    <member kind="function">
      <type></type>
      <name>BB_NavigationPoint</name>
      <anchorfile>classBB__NavigationPoint.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(C2dVector p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_NavigationPoint</name>
      <anchorfile>classBB__NavigationPoint.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setIndexed</name>
      <anchorfile>classBB__NavigationPoint.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(bool value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>getIndexed</name>
      <anchorfile>classBB__NavigationPoint.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__NavigationPoint.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_Indexed</name>
      <anchorfile>classBB__NavigationPoint.html</anchorfile>
      <anchor>p0</anchor>
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
      <type>const QString &amp;</type>
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
      <type>const QString &amp;</type>
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
    <member kind="friend" protection="private">
      <type>friend class</type>
      <name>BB_XBuildingHandler</name>
      <anchorfile>classBB__Object.html</anchorfile>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend" protection="private">
      <type>friend class</type>
      <name>BB_XLevelHandler</name>
      <anchorfile>classBB__Object.html</anchorfile>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend" protection="private">
      <type>friend class</type>
      <name>BB_XTerrainHandler</name>
      <anchorfile>classBB__Object.html</anchorfile>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend" protection="private">
      <type>friend class</type>
      <name>BB_XDocHandler</name>
      <anchorfile>classBB__Object.html</anchorfile>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend" protection="private">
      <type>friend class</type>
      <name>BB_Doc</name>
      <anchorfile>classBB__Object.html</anchorfile>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend" protection="private">
      <type>friend class</type>
      <name>BB_XHandler</name>
      <anchorfile>classBB__Object.html</anchorfile>
      <anchor>n5</anchor>
      <arglist></arglist>
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
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>BB_Point</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(C2dVector p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>BB_Point</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QPoint p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_Point</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>moveBy</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(C2dVector pMove)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>show</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(BB_Transformer &amp;transformer, QPainter &amp;painter) const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getRadius</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRadius</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(double r)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isHit</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(const C2dVector &amp;hit)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isHit</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(const QRectF &amp;rect)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPos</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>(const C2dVector &amp;theValue)</arglist>
    </member>
    <member kind="function">
      <type>const C2dVector &amp;</type>
      <name>getPos</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; BB_Line * &gt; *</type>
      <name>getLines</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setX</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a14</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setY</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a15</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getX</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a16</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getY</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a17</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>generateXElement</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a18</anchor>
      <arglist>(QTextStream &amp;out, int depth)</arglist>
    </member>
    <member kind="function">
      <type>QStandardItemModel *</type>
      <name>getItemModel</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a19</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setScale</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a20</anchor>
      <arglist>(double theValue)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteLinkedObject</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a21</anchor>
      <arglist>(BB_DrawObject *object)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeLinkedObject</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a22</anchor>
      <arglist>(BB_DrawObject *object)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteLinkedObjects</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a23</anchor>
      <arglist>(QVector&lt; BB_DrawObject * &gt; *objects)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addObject</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a24</anchor>
      <arglist>(BB_DrawObject *newObject)</arglist>
    </member>
    <member kind="function">
      <type>QPoint</type>
      <name>getQPoint</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a25</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>bringToLineHorizontal</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a26</anchor>
      <arglist>(BB_Point *point)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>bringToLineVertikal</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a27</anchor>
      <arglist>(BB_Point *point)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>moveEvent</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>a28</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_Pos</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt;</type>
      <name>m_Links</name>
      <anchorfile>classBB__Point.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Rect</name>
    <filename>classBB__Rect.html</filename>
    <base>BB_Line</base>
    <member kind="function">
      <type></type>
      <name>BB_Rect</name>
      <anchorfile>classBB__Rect.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>BB_Rect</name>
      <anchorfile>classBB__Rect.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(BB_Point *p1, BB_Point *p2)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_Rect</name>
      <anchorfile>classBB__Rect.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__Rect.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>show</name>
      <anchorfile>classBB__Rect.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(BB_Transformer &amp;transformer, QPainter &amp;painter) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isHit</name>
      <anchorfile>classBB__Rect.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const C2dVector &amp;hit)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>moveBy</name>
      <anchorfile>classBB__Rect.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(C2dVector pMove)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Stair</name>
    <filename>classBB__Stair.html</filename>
    <base>BB_Rect</base>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>show</name>
      <anchorfile>classBB__Stair.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(BB_Transformer &amp;transformer, QPainter &amp;painter) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isHit</name>
      <anchorfile>classBB__Stair.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const C2dVector &amp;hit)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>generateXElement</name>
      <anchorfile>classBB__Stair.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(QTextStream &amp;out, int depth)</arglist>
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
      <name>~BB_Tab</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>initTab</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unsetToolButton</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QAction *action)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unsetDocComponent</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateWidget</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>clear</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>saveCurrent</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>resetTool</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>documentChanged</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateLists</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual QAction *</type>
      <name>addTool</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(BB_AbstractTool *tool, const QString &amp;name, const QString &amp;info)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>setTool</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(BB_AbstractTool *tool)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>initLayout</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>b2</anchor>
      <arglist>(bool leftFrame, bool rightFrame)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>createToolButton</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>b3</anchor>
      <arglist>(QAction *action, BB_AbstractTool *tool)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>toolChanged</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>b4</anchor>
      <arglist>(QAction *action)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>setTool</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>b5</anchor>
      <arglist>(QAction *action)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>addWidgetLeft</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>b6</anchor>
      <arglist>(QWidget *widget, int stretchFaktor=0)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>addWidgetRight</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>b7</anchor>
      <arglist>(QWidget *widget)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Doc *</type>
      <name>m_Doc</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>m_DrawObjects</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt;</type>
      <name>m_Selection</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_WorkArea *</type>
      <name>m_Center</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QFrame *</type>
      <name>m_LeftFrame</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QStackedWidget *</type>
      <name>m_RightFrame</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QGridLayout *</type>
      <name>m_ToolsGridLayout</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>p6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>m_ToolButtonCount</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>p7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QList&lt; BB_AbstractTool * &gt;</type>
      <name>m_Tools</name>
      <anchorfile>classBB__Tab.html</anchorfile>
      <anchor>p8</anchor>
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
      <type></type>
      <name>~BB_TabBuilding</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>createBuildingList</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>clear</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateLists</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_Building * &gt; *</type>
      <name>m_Buildings</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QListWidget *</type>
      <name>m_BuildingsListWidget</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPushButton *</type>
      <name>m_ButtonBuildingDelete</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPushButton *</type>
      <name>m_ButtonBuildingNew</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPushButton *</type>
      <name>m_ButtonBuildingProperties</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_BuildingsListCreated</name>
      <anchorfile>classBB__TabBuilding.html</anchorfile>
      <anchor>p5</anchor>
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
    <member kind="function">
      <type></type>
      <name>~BB_TabLevel</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateLists</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>saveCurrent</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>initWidgetLeft</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>initTools</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>updateBuildingList</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>b2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>updateLevelList</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>b3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>documentChanged</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>b4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>setBuilding</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>b5</anchor>
      <arglist>(BB_Building *building)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>setLevel</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>b6</anchor>
      <arglist>(BB_Level *level)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>setWidgetEnabled</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>b7</anchor>
      <arglist>(bool value)</arglist>
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
      <type>QVector&lt; BB_Building * &gt; *</type>
      <name>m_Buildings</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_Level * &gt; *</type>
      <name>m_Levels</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QListWidget *</type>
      <name>m_ListWidgetLevels</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QComboBox *</type>
      <name>m_ComboBoxBuildings</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>p6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Building *</type>
      <name>m_Building</name>
      <anchorfile>classBB__TabLevel.html</anchorfile>
      <anchor>p7</anchor>
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
    <member kind="function">
      <type></type>
      <name>~BB_TabTerrain</name>
      <anchorfile>classBB__TabTerrain.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateWidget</name>
      <anchorfile>classBB__TabTerrain.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>saveCurrent</name>
      <anchorfile>classBB__TabTerrain.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_ToolZoom</name>
      <anchorfile>classBB__TabTerrain.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_ToolTerrainPointNew</name>
      <anchorfile>classBB__TabTerrain.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_ToolMove</name>
      <anchorfile>classBB__TabTerrain.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_ToolTriangleNew</name>
      <anchorfile>classBB__TabTerrain.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_AbstractTool *</type>
      <name>m_ToolScale</name>
      <anchorfile>classBB__TabTerrain.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Terrain *</type>
      <name>m_Terrain</name>
      <anchorfile>classBB__TabTerrain.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Terrain</name>
    <filename>classBB__Terrain.html</filename>
    <base>BB_DocComponent</base>
    <member kind="function">
      <type></type>
      <name>BB_Terrain</name>
      <anchorfile>classBB__Terrain.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(const QDir &amp;path, const QString &amp;fileName, const QString &amp;name=QString(&quot;&quot;))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~BB_Terrain</name>
      <anchorfile>classBB__Terrain.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>write</name>
      <anchorfile>classBB__Terrain.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QTextStream &amp;out)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>keyBoardEdit</name>
      <anchorfile>classBB__Terrain.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>open</name>
      <anchorfile>classBB__Terrain.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__Terrain.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resolveBuildingIds</name>
      <anchorfile>classBB__Terrain.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(BB_Doc *doc)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>buildingDeleted</name>
      <anchorfile>classBB__Terrain.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(BB_Building *building)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>createGl</name>
      <anchorfile>classBB__Terrain.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(QVector&lt; C3dTriangle &gt; &amp;triangles, double scale)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_TerrainPoint</name>
    <filename>classBB__TerrainPoint.html</filename>
    <base>BB_Point</base>
    <member kind="function">
      <type></type>
      <name>BB_TerrainPoint</name>
      <anchorfile>classBB__TerrainPoint.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(C2dVector &amp;pos)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_TerrainPoint</name>
      <anchorfile>classBB__TerrainPoint.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setHeight</name>
      <anchorfile>classBB__TerrainPoint.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getHeight</name>
      <anchorfile>classBB__TerrainPoint.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__TerrainPoint.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>generateXElement</name>
      <anchorfile>classBB__TerrainPoint.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(QTextStream &amp;out, int depth)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_Height</name>
      <anchorfile>classBB__TerrainPoint.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_TerrainTriangle</name>
    <filename>classBB__TerrainTriangle.html</filename>
    <base>BB_Triangle</base>
    <member kind="function">
      <type></type>
      <name>BB_TerrainTriangle</name>
      <anchorfile>classBB__TerrainTriangle.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Point *p1, BB_Point *p2, BB_Point *p3)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_TerrainTriangle</name>
      <anchorfile>classBB__TerrainTriangle.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>createGl</name>
      <anchorfile>classBB__TerrainTriangle.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QVector&lt; C3dTriangle &gt; &amp;triangles, C3dVector vector, double rotation, double scale, double height)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__TerrainTriangle.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolBuildingPositionNew</name>
    <filename>classBB__ToolBuildingPositionNew.html</filename>
    <base>BB_ToolPointNew</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolBuildingPositionNew</name>
      <anchorfile>classBB__ToolBuildingPositionNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Doc *doc, QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolBuildingPositionNew</name>
      <anchorfile>classBB__ToolBuildingPositionNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_AbstractToolWidget *</type>
      <name>getToolWidget</name>
      <anchorfile>classBB__ToolBuildingPositionNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_Point *</type>
      <name>createNewPoint</name>
      <anchorfile>classBB__ToolBuildingPositionNew.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(C2dVector &amp;pos)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_Point *</type>
      <name>getClickedPoint</name>
      <anchorfile>classBB__ToolBuildingPositionNew.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(C2dVector &amp;pos)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setBuilding</name>
      <anchorfile>classBB__ToolBuildingPositionNew.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(BB_Building *value)</arglist>
    </member>
    <member kind="function">
      <type>BB_Building *</type>
      <name>getBuilding</name>
      <anchorfile>classBB__ToolBuildingPositionNew.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="variable">
      <type>BB_Doc *</type>
      <name>m_Doc</name>
      <anchorfile>classBB__ToolBuildingPositionNew.html</anchorfile>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>BB_Building *</type>
      <name>m_Building</name>
      <anchorfile>classBB__ToolBuildingPositionNew.html</anchorfile>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolBuildingTriangleNew</name>
    <filename>classBB__ToolBuildingTriangleNew.html</filename>
    <base>BB_ToolTriangleNew</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolBuildingTriangleNew</name>
      <anchorfile>classBB__ToolBuildingTriangleNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolBuildingTriangleNew</name>
      <anchorfile>classBB__ToolBuildingTriangleNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual BB_Triangle *</type>
      <name>createNewSurface</name>
      <anchorfile>classBB__ToolBuildingTriangleNew.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolDelete</name>
    <filename>classBB__ToolDelete.html</filename>
    <base>BB_AbstractTool</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolDelete</name>
      <anchorfile>classBB__ToolDelete.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolDelete</name>
      <anchorfile>classBB__ToolDelete.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>click</name>
      <anchorfile>classBB__ToolDelete.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolDoorNew</name>
    <filename>classBB__ToolDoorNew.html</filename>
    <base>BB_AbstractTool</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolDoorNew</name>
      <anchorfile>classBB__ToolDoorNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolDoorNew</name>
      <anchorfile>classBB__ToolDoorNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>click</name>
      <anchorfile>classBB__ToolDoorNew.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>move</name>
      <anchorfile>classBB__ToolDoorNew.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(QMouseEvent *me, bool overX, bool overY)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>release</name>
      <anchorfile>classBB__ToolDoorNew.html</anchorfile>
      <anchor>b2</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolLevelTriangleNew</name>
    <filename>classBB__ToolLevelTriangleNew.html</filename>
    <base>BB_ToolTriangleNew</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolLevelTriangleNew</name>
      <anchorfile>classBB__ToolLevelTriangleNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolLevelTriangleNew</name>
      <anchorfile>classBB__ToolLevelTriangleNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_Triangle *</type>
      <name>createNewSurface</name>
      <anchorfile>classBB__ToolLevelTriangleNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
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
      <anchor>a0</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolLineNew</name>
      <anchorfile>classBB__ToolLineNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>click</name>
      <anchorfile>classBB__ToolLineNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>move</name>
      <anchorfile>classBB__ToolLineNew.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QMouseEvent *me, bool overX, bool overY)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>release</name>
      <anchorfile>classBB__ToolLineNew.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_AbstractToolWidget *</type>
      <name>getToolWidget</name>
      <anchorfile>classBB__ToolLineNew.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual BB_Point *</type>
      <name>getClickedPoint</name>
      <anchorfile>classBB__ToolLineNew.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(C2dVector &amp;pos)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual BB_Line *</type>
      <name>createNewLine</name>
      <anchorfile>classBB__ToolLineNew.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(BB_Point *p1, BB_Point *p2)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual BB_Line *</type>
      <name>getClickedLine</name>
      <anchorfile>classBB__ToolLineNew.html</anchorfile>
      <anchor>b2</anchor>
      <arglist>(C2dVector &amp;pos)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Line *</type>
      <name>m_Tmp_Line</name>
      <anchorfile>classBB__ToolLineNew.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point</type>
      <name>m_MovePoint</name>
      <anchorfile>classBB__ToolLineNew.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolMove</name>
    <filename>classBB__ToolMove.html</filename>
    <base>BB_AbstractTool</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolMove</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolMove</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>click</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>move</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QMouseEvent *me, bool overX, bool overY)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>release</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_AbstractToolWidget *</type>
      <name>getToolWidget</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>selectAll</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point *</type>
      <name>m_ComparePoint</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point</type>
      <name>m_Point2</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point</type>
      <name>m_Point1</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Rect</type>
      <name>m_Rect</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_ClickPos</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_select</name>
      <anchorfile>classBB__ToolMove.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolNavigationLineNew</name>
    <filename>classBB__ToolNavigationLineNew.html</filename>
    <base>BB_ToolLineNew</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolNavigationLineNew</name>
      <anchorfile>classBB__ToolNavigationLineNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolNavigationLineNew</name>
      <anchorfile>classBB__ToolNavigationLineNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_Line *</type>
      <name>createNewLine</name>
      <anchorfile>classBB__ToolNavigationLineNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(BB_Point *p1, BB_Point *p2)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_Line *</type>
      <name>getClickedLine</name>
      <anchorfile>classBB__ToolNavigationLineNew.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(C2dVector &amp;pos)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_Point *</type>
      <name>getClickedPoint</name>
      <anchorfile>classBB__ToolNavigationLineNew.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(C2dVector &amp;pos)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolNavigationPointNew</name>
    <filename>classBB__ToolNavigationPointNew.html</filename>
    <base>BB_ToolPointNew</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolNavigationPointNew</name>
      <anchorfile>classBB__ToolNavigationPointNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolNavigationPointNew</name>
      <anchorfile>classBB__ToolNavigationPointNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_AbstractToolWidget *</type>
      <name>getToolWidget</name>
      <anchorfile>classBB__ToolNavigationPointNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual BB_Point *</type>
      <name>createNewPoint</name>
      <anchorfile>classBB__ToolNavigationPointNew.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(C2dVector &amp;pos)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual BB_Point *</type>
      <name>getClickedPoint</name>
      <anchorfile>classBB__ToolNavigationPointNew.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(C2dVector &amp;pos)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolPointNew</name>
    <filename>classBB__ToolPointNew.html</filename>
    <base>BB_AbstractTool</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolPointNew</name>
      <anchorfile>classBB__ToolPointNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolPointNew</name>
      <anchorfile>classBB__ToolPointNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_AbstractToolWidget *</type>
      <name>getToolWidget</name>
      <anchorfile>classBB__ToolPointNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>click</name>
      <anchorfile>classBB__ToolPointNew.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>release</name>
      <anchorfile>classBB__ToolPointNew.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>move</name>
      <anchorfile>classBB__ToolPointNew.html</anchorfile>
      <anchor>b2</anchor>
      <arglist>(QMouseEvent *me, bool overX, bool overY)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual BB_Point *</type>
      <name>getClickedPoint</name>
      <anchorfile>classBB__ToolPointNew.html</anchorfile>
      <anchor>b3</anchor>
      <arglist>(C2dVector &amp;pos)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual BB_Point *</type>
      <name>createNewPoint</name>
      <anchorfile>classBB__ToolPointNew.html</anchorfile>
      <anchor>b4</anchor>
      <arglist>(C2dVector &amp;pos)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point *</type>
      <name>m_Point</name>
      <anchorfile>classBB__ToolPointNew.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolScale</name>
    <filename>classBB__ToolScale.html</filename>
    <base>BB_AbstractTool</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolScale</name>
      <anchorfile>classBB__ToolScale.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolScale</name>
      <anchorfile>classBB__ToolScale.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>click</name>
      <anchorfile>classBB__ToolScale.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>move</name>
      <anchorfile>classBB__ToolScale.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QMouseEvent *me, bool overX, bool overY)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>release</name>
      <anchorfile>classBB__ToolScale.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setDocComponent</name>
      <anchorfile>classBB__ToolScale.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(BB_DocComponent *component)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>reset</name>
      <anchorfile>classBB__ToolScale.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateWidget</name>
      <anchorfile>classBB__ToolScale.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_AbstractToolWidget *</type>
      <name>getToolWidget</name>
      <anchorfile>classBB__ToolScale.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point *</type>
      <name>m_MovePoint</name>
      <anchorfile>classBB__ToolScale.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Line *</type>
      <name>m_ScaleLine</name>
      <anchorfile>classBB__ToolScale.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QWidget *</type>
      <name>m_Parent</name>
      <anchorfile>classBB__ToolScale.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_Tmp_v1</name>
      <anchorfile>classBB__ToolScale.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_Tmp_v2</name>
      <anchorfile>classBB__ToolScale.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolStair</name>
    <filename>classBB__ToolStair.html</filename>
    <base>BB_AbstractTool</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolStair</name>
      <anchorfile>classBB__ToolStair.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolStair</name>
      <anchorfile>classBB__ToolStair.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>click</name>
      <anchorfile>classBB__ToolStair.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>move</name>
      <anchorfile>classBB__ToolStair.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QMouseEvent *me, bool overX, bool overY)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>release</name>
      <anchorfile>classBB__ToolStair.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function">
      <type>BB_AbstractToolWidget *</type>
      <name>getToolWidget</name>
      <anchorfile>classBB__ToolStair.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Stair *</type>
      <name>m_Stair</name>
      <anchorfile>classBB__ToolStair.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point</type>
      <name>m_Point1</name>
      <anchorfile>classBB__ToolStair.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point</type>
      <name>m_Point2</name>
      <anchorfile>classBB__ToolStair.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Rect</type>
      <name>m_Rect</name>
      <anchorfile>classBB__ToolStair.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_ClickPos</name>
      <anchorfile>classBB__ToolStair.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolTerrainPointNew</name>
    <filename>classBB__ToolTerrainPointNew.html</filename>
    <base>BB_ToolPointNew</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolTerrainPointNew</name>
      <anchorfile>classBB__ToolTerrainPointNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolTerrainPointNew</name>
      <anchorfile>classBB__ToolTerrainPointNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_AbstractToolWidget *</type>
      <name>getToolWidget</name>
      <anchorfile>classBB__ToolTerrainPointNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual BB_Point *</type>
      <name>createNewPoint</name>
      <anchorfile>classBB__ToolTerrainPointNew.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(C2dVector &amp;pos)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual BB_Point *</type>
      <name>getClickedPoint</name>
      <anchorfile>classBB__ToolTerrainPointNew.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(C2dVector &amp;pos)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolTerrainTriangleNew</name>
    <filename>classBB__ToolTerrainTriangleNew.html</filename>
    <base>BB_ToolTriangleNew</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolTerrainTriangleNew</name>
      <anchorfile>classBB__ToolTerrainTriangleNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolTerrainTriangleNew</name>
      <anchorfile>classBB__ToolTerrainTriangleNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_AbstractToolWidget *</type>
      <name>getToolWidget</name>
      <anchorfile>classBB__ToolTerrainTriangleNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_Point *</type>
      <name>getClickedPoint</name>
      <anchorfile>classBB__ToolTerrainTriangleNew.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(C2dVector &amp;pos)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_Triangle *</type>
      <name>createNewSurface</name>
      <anchorfile>classBB__ToolTerrainTriangleNew.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolTexture</name>
    <filename>classBB__ToolTexture.html</filename>
    <base>BB_AbstractTool</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolTexture</name>
      <anchorfile>classBB__ToolTexture.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolTexture</name>
      <anchorfile>classBB__ToolTexture.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>click</name>
      <anchorfile>classBB__ToolTexture.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolTriangleNew</name>
    <filename>classBB__ToolTriangleNew.html</filename>
    <base>BB_AbstractTool</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolTriangleNew</name>
      <anchorfile>classBB__ToolTriangleNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolTriangleNew</name>
      <anchorfile>classBB__ToolTriangleNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>click</name>
      <anchorfile>classBB__ToolTriangleNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>reset</name>
      <anchorfile>classBB__ToolTriangleNew.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_AbstractToolWidget *</type>
      <name>getToolWidget</name>
      <anchorfile>classBB__ToolTriangleNew.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual BB_Point *</type>
      <name>getClickedPoint</name>
      <anchorfile>classBB__ToolTriangleNew.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(C2dVector &amp;pos)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual BB_Triangle *</type>
      <name>createNewSurface</name>
      <anchorfile>classBB__ToolTriangleNew.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point *</type>
      <name>m_P1</name>
      <anchorfile>classBB__ToolTriangleNew.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point *</type>
      <name>m_P2</name>
      <anchorfile>classBB__ToolTriangleNew.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point *</type>
      <name>m_P3</name>
      <anchorfile>classBB__ToolTriangleNew.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolWallNew</name>
    <filename>classBB__ToolWallNew.html</filename>
    <base>BB_ToolLineNew</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolWallNew</name>
      <anchorfile>classBB__ToolWallNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolWallNew</name>
      <anchorfile>classBB__ToolWallNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_AbstractToolWidget *</type>
      <name>getToolWidget</name>
      <anchorfile>classBB__ToolWallNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual BB_Line *</type>
      <name>createNewLine</name>
      <anchorfile>classBB__ToolWallNew.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(BB_Point *p1, BB_Point *p2)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual BB_Line *</type>
      <name>getClickedLine</name>
      <anchorfile>classBB__ToolWallNew.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(C2dVector &amp;pos)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_ToolWindowNew</name>
    <filename>classBB__ToolWindowNew.html</filename>
    <base>BB_AbstractTool</base>
    <member kind="function">
      <type></type>
      <name>BB_ToolWindowNew</name>
      <anchorfile>classBB__ToolWindowNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolWindowNew</name>
      <anchorfile>classBB__ToolWindowNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>click</name>
      <anchorfile>classBB__ToolWindowNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>move</name>
      <anchorfile>classBB__ToolWindowNew.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QMouseEvent *me, bool overX, bool overY)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>release</name>
      <anchorfile>classBB__ToolWindowNew.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(QMouseEvent *me)</arglist>
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
      <arglist>(BB_WorkArea *area, QWidget *paret)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_ToolZoom</name>
      <anchorfile>classBB__ToolZoom.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>click</name>
      <anchorfile>classBB__ToolZoom.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setDocComponent</name>
      <anchorfile>classBB__ToolZoom.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(BB_DocComponent *component)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual BB_AbstractToolWidget *</type>
      <name>getToolWidget</name>
      <anchorfile>classBB__ToolZoom.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
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
      <type></type>
      <name>BB_Transformer</name>
      <anchorfile>classBB__Transformer.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_Transformer</name>
      <anchorfile>classBB__Transformer.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setOffset</name>
      <anchorfile>classBB__Transformer.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const C2dVector &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>C2dVector</type>
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
      <arglist>(double value)</arglist>
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
    <name>BB_Triangle</name>
    <filename>classBB__Triangle.html</filename>
    <base>BB_Line</base>
    <member kind="function">
      <type></type>
      <name>BB_Triangle</name>
      <anchorfile>classBB__Triangle.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Point *p1, BB_Point *p2, BB_Point *p3)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_Triangle</name>
      <anchorfile>classBB__Triangle.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isHit</name>
      <anchorfile>classBB__Triangle.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const QRectF &amp;rect)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isHit</name>
      <anchorfile>classBB__Triangle.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const C2dVector &amp;hit)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const QString</type>
      <name>getClassName</name>
      <anchorfile>classBB__Triangle.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>moveEvent</name>
      <anchorfile>classBB__Triangle.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>normalize</name>
      <anchorfile>classBB__Triangle.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>show</name>
      <anchorfile>classBB__Triangle.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(BB_Transformer &amp;transformer, QPainter &amp;painter) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setPos3</name>
      <anchorfile>classBB__Triangle.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(BB_Point *value)</arglist>
    </member>
    <member kind="function">
      <type>BB_Point *</type>
      <name>getPos3</name>
      <anchorfile>classBB__Triangle.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>generateXElement</name>
      <anchorfile>classBB__Triangle.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>(QTextStream &amp;out, int depth)</arglist>
    </member>
    <member kind="variable">
      <type>BB_Point *</type>
      <name>m_Pos3</name>
      <anchorfile>classBB__Triangle.html</anchorfile>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>createGl</name>
      <anchorfile>classBB__Triangle.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(QVector&lt; C3dTriangle &gt; &amp;triangles, C3dVector vector, double rotation, double scale, double height)</arglist>
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
    <member kind="function">
      <type></type>
      <name>~BB_Wall</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
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
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>show</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(BB_Transformer &amp;transformer, QPainter &amp;painter) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>editDlg</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(BB_DocComponent *docComponent)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>moveEvent</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setObjects</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(QVector&lt; BB_DrawObject * &gt; *Value)</arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>getObjects</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>getObjectsWithPoints</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>getPoints</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>openTextureDlg</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>swap</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>BB_Door *</type>
      <name>hastDoor</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_Direction</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_ShowDirection</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QPen</type>
      <name>m_PenDirection</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>m_Objects</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_Hight</name>
      <anchorfile>classBB__Wall.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_WidgetToolBuildingPositionNew</name>
    <filename>classBB__WidgetToolBuildingPositionNew.html</filename>
    <base>BB_AbstractToolWidget</base>
    <member kind="function">
      <type></type>
      <name>BB_WidgetToolBuildingPositionNew</name>
      <anchorfile>classBB__WidgetToolBuildingPositionNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Doc *doc, BB_AbstractTool *parentTool, QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_WidgetToolBuildingPositionNew</name>
      <anchorfile>classBB__WidgetToolBuildingPositionNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>clearToolWidget</name>
      <anchorfile>classBB__WidgetToolBuildingPositionNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setWidgetEnabled</name>
      <anchorfile>classBB__WidgetToolBuildingPositionNew.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(bool value)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateWidget</name>
      <anchorfile>classBB__WidgetToolBuildingPositionNew.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Ui::WidgetToolBuildingPositionNew</type>
      <name>m_Ui</name>
      <anchorfile>classBB__WidgetToolBuildingPositionNew.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Building *</type>
      <name>m_Building</name>
      <anchorfile>classBB__WidgetToolBuildingPositionNew.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_BuildingPosition *</type>
      <name>m_BPos</name>
      <anchorfile>classBB__WidgetToolBuildingPositionNew.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Doc *</type>
      <name>m_Doc</name>
      <anchorfile>classBB__WidgetToolBuildingPositionNew.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_WidgetToolLineNew</name>
    <filename>classBB__WidgetToolLineNew.html</filename>
    <base>BB_AbstractToolWidget</base>
    <member kind="function">
      <type></type>
      <name>BB_WidgetToolLineNew</name>
      <anchorfile>classBB__WidgetToolLineNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_AbstractTool *parentTool, QWidget *parent=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~BB_WidgetToolLineNew</name>
      <anchorfile>classBB__WidgetToolLineNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateWidget</name>
      <anchorfile>classBB__WidgetToolLineNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setWidgetEnabled</name>
      <anchorfile>classBB__WidgetToolLineNew.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(bool value)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>clearToolWidget</name>
      <anchorfile>classBB__WidgetToolLineNew.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_WidgetToolNavigationPointNew</name>
    <filename>classBB__WidgetToolNavigationPointNew.html</filename>
    <base>BB_AbstractToolWidget</base>
    <member kind="function">
      <type></type>
      <name>BB_WidgetToolNavigationPointNew</name>
      <anchorfile>classBB__WidgetToolNavigationPointNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_AbstractTool *parentTool, QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_WidgetToolNavigationPointNew</name>
      <anchorfile>classBB__WidgetToolNavigationPointNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>clearToolWidget</name>
      <anchorfile>classBB__WidgetToolNavigationPointNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setWidgetEnabled</name>
      <anchorfile>classBB__WidgetToolNavigationPointNew.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(bool value)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateWidget</name>
      <anchorfile>classBB__WidgetToolNavigationPointNew.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Ui::WidgetToolNavigationPointNew</type>
      <name>m_Ui</name>
      <anchorfile>classBB__WidgetToolNavigationPointNew.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point *</type>
      <name>m_Tmp_Point</name>
      <anchorfile>classBB__WidgetToolNavigationPointNew.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_Tmp_Vector</name>
      <anchorfile>classBB__WidgetToolNavigationPointNew.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_WidgetToolPointNew</name>
    <filename>classBB__WidgetToolPointNew.html</filename>
    <base>BB_AbstractToolWidget</base>
    <member kind="function">
      <type></type>
      <name>BB_WidgetToolPointNew</name>
      <anchorfile>classBB__WidgetToolPointNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_AbstractTool *parentTool, QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_WidgetToolPointNew</name>
      <anchorfile>classBB__WidgetToolPointNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateWidget</name>
      <anchorfile>classBB__WidgetToolPointNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>clearToolWidget</name>
      <anchorfile>classBB__WidgetToolPointNew.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setWidgetEnabled</name>
      <anchorfile>classBB__WidgetToolPointNew.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(bool value)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point *</type>
      <name>m_Tmp_Point</name>
      <anchorfile>classBB__WidgetToolPointNew.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C2dVector</type>
      <name>m_Tmp_Vector</name>
      <anchorfile>classBB__WidgetToolPointNew.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_WidgetToolScale</name>
    <filename>classBB__WidgetToolScale.html</filename>
    <base>BB_AbstractToolWidget</base>
    <member kind="function">
      <type></type>
      <name>BB_WidgetToolScale</name>
      <anchorfile>classBB__WidgetToolScale.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_AbstractTool *parentTool, QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_WidgetToolScale</name>
      <anchorfile>classBB__WidgetToolScale.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLogicalScale</name>
      <anchorfile>classBB__WidgetToolScale.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRealScale</name>
      <anchorfile>classBB__WidgetToolScale.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(double *real)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Ui::WidgetToolScale</type>
      <name>m_Ui</name>
      <anchorfile>classBB__WidgetToolScale.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double *</type>
      <name>m_RealScale</name>
      <anchorfile>classBB__WidgetToolScale.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_WidgetToolSelect</name>
    <filename>classBB__WidgetToolSelect.html</filename>
    <base>BB_AbstractToolWidget</base>
    <member kind="function">
      <type></type>
      <name>BB_WidgetToolSelect</name>
      <anchorfile>classBB__WidgetToolSelect.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_ToolMove *parentTool)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_WidgetToolSelect</name>
      <anchorfile>classBB__WidgetToolSelect.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateWidget</name>
      <anchorfile>classBB__WidgetToolSelect.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Ui::WidgetToolSelect</type>
      <name>m_Ui</name>
      <anchorfile>classBB__WidgetToolSelect.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_WidgetToolTerrainPointNew</name>
    <filename>classBB__WidgetToolTerrainPointNew.html</filename>
    <base>BB_AbstractToolWidget</base>
    <member kind="function">
      <type></type>
      <name>BB_WidgetToolTerrainPointNew</name>
      <anchorfile>classBB__WidgetToolTerrainPointNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_AbstractTool *parentTool, QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_WidgetToolTerrainPointNew</name>
      <anchorfile>classBB__WidgetToolTerrainPointNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>clearToolWidget</name>
      <anchorfile>classBB__WidgetToolTerrainPointNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setWidgetEnabled</name>
      <anchorfile>classBB__WidgetToolTerrainPointNew.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(bool value)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateWidget</name>
      <anchorfile>classBB__WidgetToolTerrainPointNew.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Point *</type>
      <name>m_Tmp_Point</name>
      <anchorfile>classBB__WidgetToolTerrainPointNew.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Ui::WidgetToolTerrainPointNew</type>
      <name>m_Ui</name>
      <anchorfile>classBB__WidgetToolTerrainPointNew.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_WidgetToolTerrainTriangleNew</name>
    <filename>classBB__WidgetToolTerrainTriangleNew.html</filename>
    <base>BB_AbstractToolWidget</base>
    <member kind="function">
      <type></type>
      <name>BB_WidgetToolTerrainTriangleNew</name>
      <anchorfile>classBB__WidgetToolTerrainTriangleNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_AbstractTool *parentTool, QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_WidgetToolTerrainTriangleNew</name>
      <anchorfile>classBB__WidgetToolTerrainTriangleNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>clearToolWidget</name>
      <anchorfile>classBB__WidgetToolTerrainTriangleNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setWidgetEnabled</name>
      <anchorfile>classBB__WidgetToolTerrainTriangleNew.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(bool value)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateWidget</name>
      <anchorfile>classBB__WidgetToolTerrainTriangleNew.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getTextureFileName</name>
      <anchorfile>classBB__WidgetToolTerrainTriangleNew.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Ui::WidgetToolTerrainTriangleNew</type>
      <name>m_Ui</name>
      <anchorfile>classBB__WidgetToolTerrainTriangleNew.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_WidgetToolTriangleNew</name>
    <filename>classBB__WidgetToolTriangleNew.html</filename>
    <base>BB_AbstractToolWidget</base>
    <member kind="function">
      <type></type>
      <name>BB_WidgetToolTriangleNew</name>
      <anchorfile>classBB__WidgetToolTriangleNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_AbstractTool *parentTool, QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_WidgetToolTriangleNew</name>
      <anchorfile>classBB__WidgetToolTriangleNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>clearToolWidget</name>
      <anchorfile>classBB__WidgetToolTriangleNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setWidgetEnabled</name>
      <anchorfile>classBB__WidgetToolTriangleNew.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(bool value)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateWidget</name>
      <anchorfile>classBB__WidgetToolTriangleNew.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Ui::WidgetToolTriangleNew</type>
      <name>m_Ui</name>
      <anchorfile>classBB__WidgetToolTriangleNew.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_WidgetToolWallNew</name>
    <filename>classBB__WidgetToolWallNew.html</filename>
    <base>BB_AbstractToolWidget</base>
    <member kind="function">
      <type></type>
      <name>BB_WidgetToolWallNew</name>
      <anchorfile>classBB__WidgetToolWallNew.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_AbstractTool *parentTool, QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_WidgetToolWallNew</name>
      <anchorfile>classBB__WidgetToolWallNew.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>clearToolWidget</name>
      <anchorfile>classBB__WidgetToolWallNew.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setWidgetEnabled</name>
      <anchorfile>classBB__WidgetToolWallNew.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(bool value)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateWidget</name>
      <anchorfile>classBB__WidgetToolWallNew.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Ui::WidgetToolWallNew</type>
      <name>m_Ui</name>
      <anchorfile>classBB__WidgetToolWallNew.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_WidgetToolZoom</name>
    <filename>classBB__WidgetToolZoom.html</filename>
    <base>BB_AbstractToolWidget</base>
    <member kind="function">
      <type></type>
      <name>BB_WidgetToolZoom</name>
      <anchorfile>classBB__WidgetToolZoom.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_AbstractTool *parentTool, QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_WidgetToolZoom</name>
      <anchorfile>classBB__WidgetToolZoom.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setZoomFaktor</name>
      <anchorfile>classBB__WidgetToolZoom.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Ui::WidgetToolZoom</type>
      <name>m_Ui</name>
      <anchorfile>classBB__WidgetToolZoom.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_Window</name>
    <filename>classBB__Window.html</filename>
    <base>BB_ConstructionElement</base>
    <member kind="function">
      <type></type>
      <name>BB_Window</name>
      <anchorfile>classBB__Window.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(C2dVector v1, C2dVector v2)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_Window</name>
      <anchorfile>classBB__Window.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>generateXElement</name>
      <anchorfile>classBB__Window.html</anchorfile>
      <anchor>a2</anchor>
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
      <arglist>(QVector&lt; BB_DrawObject * &gt; *selectVector, QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_WorkArea</name>
      <anchorfile>classBB__WorkArea.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
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
      <type>BB_DocComponent *</type>
      <name>getDocComponent</name>
      <anchorfile>classBB__WorkArea.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDocComponent</name>
      <anchorfile>classBB__WorkArea.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(BB_DocComponent *component)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getZoom</name>
      <anchorfile>classBB__WorkArea.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_WorkFrame *</type>
      <name>m_WorkFrame</name>
      <anchorfile>classBB__WorkArea.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Map *</type>
      <name>m_Map</name>
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
      <arglist>(QVector&lt; BB_DrawObject * &gt; *selectVector, QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_WorkFrame</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
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
      <name>setDocComponent</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(BB_DocComponent *theValue)</arglist>
    </member>
    <member kind="function">
      <type>BB_DocComponent *</type>
      <name>getDocComponent</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>documentChanged</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>()</arglist>
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
      <type>BB_AbstractTool *</type>
      <name>m_Tool</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>m_Selection</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Transformer</type>
      <name>m_Transformer</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt;</type>
      <name>m_ToolObjects</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_DocComponent *</type>
      <name>m_Component</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>m_DrawObjects</name>
      <anchorfile>classBB__WorkFrame.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_XBuildingHandler</name>
    <filename>classBB__XBuildingHandler.html</filename>
    <base>BB_XHandler</base>
    <member kind="function">
      <type></type>
      <name>BB_XBuildingHandler</name>
      <anchorfile>classBB__XBuildingHandler.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Building *building)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_XBuildingHandler</name>
      <anchorfile>classBB__XBuildingHandler.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>endElement</name>
      <anchorfile>classBB__XBuildingHandler.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const QString &amp;namespaceURI, const QString &amp;localName, const QString &amp;qName)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>startElement</name>
      <anchorfile>classBB__XBuildingHandler.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const QString &amp;namespaceURI, const QString &amp;localName, const QString &amp;qName, const QXmlAttributes &amp;atts)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Building *</type>
      <name>m_Building</name>
      <anchorfile>classBB__XBuildingHandler.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_XBuildingTag</name>
      <anchorfile>classBB__XBuildingHandler.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>m_DrawObjects</name>
      <anchorfile>classBB__XBuildingHandler.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_XDocHandler</name>
    <filename>classBB__XDocHandler.html</filename>
    <base>BB_XHandler</base>
    <member kind="function">
      <type></type>
      <name>BB_XDocHandler</name>
      <anchorfile>classBB__XDocHandler.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Doc *doc)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_XDocHandler</name>
      <anchorfile>classBB__XDocHandler.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>endElement</name>
      <anchorfile>classBB__XDocHandler.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const QString &amp;namespaceURI, const QString &amp;localName, const QString &amp;qName)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>startElement</name>
      <anchorfile>classBB__XDocHandler.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const QString &amp;namespaceURI, const QString &amp;localName, const QString &amp;qName, const QXmlAttributes &amp;atts)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Doc *</type>
      <name>m_Doc</name>
      <anchorfile>classBB__XDocHandler.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_XDocTag</name>
      <anchorfile>classBB__XDocHandler.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QDir</type>
      <name>m_Path</name>
      <anchorfile>classBB__XDocHandler.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>m_ObjectId</name>
      <anchorfile>classBB__XDocHandler.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>m_BuidingNr</name>
      <anchorfile>classBB__XDocHandler.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_XHandler</name>
    <filename>classBB__XHandler.html</filename>
    <member kind="function">
      <type></type>
      <name>BB_XHandler</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_DocComponent *docComponent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_XHandler</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>characters</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const QString &amp;ch)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>endElement</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const QString &amp;namespaceURI, const QString &amp;localName, const QString &amp;qName)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>startElement</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(const QString &amp;namespaceURI, const QString &amp;localName, const QString &amp;qName, const QXmlAttributes &amp;atts)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>fatalError</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const QXmlParseException &amp;exception)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>parseTexture</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(const QXmlAttributes &amp;atts)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>parseTriangle</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(const QXmlAttributes &amp;atts)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>parseTerrainTriangle</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>b2</anchor>
      <arglist>(const QXmlAttributes &amp;atts)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>parsePoint</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>b3</anchor>
      <arglist>(const QXmlAttributes &amp;atts)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>parseTerrainPoint</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>b4</anchor>
      <arglist>(const QXmlAttributes &amp;atts)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>parseWindow</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>b5</anchor>
      <arglist>(const QXmlAttributes &amp;atts)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>parseLevelTriangle</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>b6</anchor>
      <arglist>(const QXmlAttributes &amp;atts)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>parseBuildingTriangle</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>b7</anchor>
      <arglist>(const QXmlAttributes &amp;atts)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>parseDoor</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>b8</anchor>
      <arglist>(const QXmlAttributes &amp;atts)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>parseStair</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>b9</anchor>
      <arglist>(const QXmlAttributes &amp;atts)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>parseWall</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>b10</anchor>
      <arglist>(const QXmlAttributes &amp;atts)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>parseScale</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>b11</anchor>
      <arglist>(const QXmlAttributes &amp;atts)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QString</type>
      <name>m_CurrentText</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QString</type>
      <name>m_ErrorStr</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_DrawObject *</type>
      <name>m_Object</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_ConstructionElement *</type>
      <name>m_ConstructionElement</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_XScale</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_DocComponent *</type>
      <name>m_DocComponent</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>m_ScalePointIndex</name>
      <anchorfile>classBB__XHandler.html</anchorfile>
      <anchor>p6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_XLevelHandler</name>
    <filename>classBB__XLevelHandler.html</filename>
    <base>BB_XHandler</base>
    <member kind="function">
      <type></type>
      <name>BB_XLevelHandler</name>
      <anchorfile>classBB__XLevelHandler.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Level *level)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_XLevelHandler</name>
      <anchorfile>classBB__XLevelHandler.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>endElement</name>
      <anchorfile>classBB__XLevelHandler.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const QString &amp;namespaceURI, const QString &amp;localName, const QString &amp;qName)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>startElement</name>
      <anchorfile>classBB__XLevelHandler.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const QString &amp;namespaceURI, const QString &amp;localName, const QString &amp;qName, const QXmlAttributes &amp;atts)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Level *</type>
      <name>m_Level</name>
      <anchorfile>classBB__XLevelHandler.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_XLevelTag</name>
      <anchorfile>classBB__XLevelHandler.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; BB_DrawObject * &gt; *</type>
      <name>m_DrawObjects</name>
      <anchorfile>classBB__XLevelHandler.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BB_XTerrainHandler</name>
    <filename>classBB__XTerrainHandler.html</filename>
    <base>BB_XHandler</base>
    <member kind="function">
      <type></type>
      <name>BB_XTerrainHandler</name>
      <anchorfile>classBB__XTerrainHandler.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Terrain *terrain)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BB_XTerrainHandler</name>
      <anchorfile>classBB__XTerrainHandler.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>startElement</name>
      <anchorfile>classBB__XTerrainHandler.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const QString &amp;namespaceURI, const QString &amp;localName, const QString &amp;qName, const QXmlAttributes &amp;atts)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>endElement</name>
      <anchorfile>classBB__XTerrainHandler.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const QString &amp;namespaceURI, const QString &amp;localName, const QString &amp;qName)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Terrain *</type>
      <name>m_Terrain</name>
      <anchorfile>classBB__XTerrainHandler.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_XTerrainTag</name>
      <anchorfile>classBB__XTerrainHandler.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BR_Camera</name>
    <filename>classBR__Camera.html</filename>
    <member kind="function">
      <type></type>
      <name>BR_Camera</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BR_Camera</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>rotateY</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(double angle)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>rotateX</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(double angle)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>apply</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setAspect</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(double aspect)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>strafe</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(double speed)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>move</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(double speed)</arglist>
    </member>
    <member kind="function">
      <type>C3dVector</type>
      <name>getViewPoint</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>C3dVector</type>
      <name>getPos</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>CheckCameraCollision</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>(CVector3 *pVertices, int numOfVerts)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_Aspect</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_FoVY</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_Near</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_Far</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_ViewPoint</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_Camera</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>CVector3</type>
      <name>m_vPosition</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>p6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>float</type>
      <name>m_Radius</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>p7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_Strave</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>p8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_Up</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>p9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_tmpV1</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>p10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_tmpV2</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>p11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_tmpV3</name>
      <anchorfile>classBR__Camera.html</anchorfile>
      <anchor>p12</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BR_InfoWidget</name>
    <filename>classBR__InfoWidget.html</filename>
    <member kind="function">
      <type></type>
      <name>BR_InfoWidget</name>
      <anchorfile>classBR__InfoWidget.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Doc *doc, QWidget *parent=0, Qt::WFlags f=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BR_InfoWidget</name>
      <anchorfile>classBR__InfoWidget.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>printFPS</name>
      <anchorfile>classBR__InfoWidget.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(int fps)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setText</name>
      <anchorfile>classBR__InfoWidget.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(QString &amp;text)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QTextEdit *</type>
      <name>m_Text</name>
      <anchorfile>classBR__InfoWidget.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QLabel *</type>
      <name>m_FpsLabel</name>
      <anchorfile>classBR__InfoWidget.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BR_KeyHandler</name>
    <filename>classBR__KeyHandler.html</filename>
    <member kind="function">
      <type></type>
      <name>BR_KeyHandler</name>
      <anchorfile>classBR__KeyHandler.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~BR_KeyHandler</name>
      <anchorfile>classBR__KeyHandler.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isPressed</name>
      <anchorfile>classBR__KeyHandler.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(int key)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>pressed</name>
      <anchorfile>classBR__KeyHandler.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(int key)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>released</name>
      <anchorfile>classBR__KeyHandler.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(int key)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BR_MainWindow</name>
    <filename>classBR__MainWindow.html</filename>
    <member kind="function">
      <type></type>
      <name>BR_MainWindow</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(QWidget *parent=0, Qt::WFlags flags=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BR_MainWindow</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BR_View *</type>
      <name>m_ViewWidget</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QMenu *</type>
      <name>m_MenuFile</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QMenu *</type>
      <name>m_MenuView</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QMenu *</type>
      <name>m_MenuNavi</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QStatusBar *</type>
      <name>m_StatusBar</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QMenuBar *</type>
      <name>m_MainMenuBar</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QAction *</type>
      <name>m_aFileExit</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>p6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QAction *</type>
      <name>m_aViewFullScreen</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>p7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QTimer *</type>
      <name>m_TimerAnimate</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>p8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QTimer *</type>
      <name>m_TimerFPS</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>p9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Doc</type>
      <name>m_Doc</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>p10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BR_InfoWidget *</type>
      <name>m_InfoWidget</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>p11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QAction *</type>
      <name>m_aProjectClose</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>p12</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QAction *</type>
      <name>m_aProjectOpen</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>p13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QAction *</type>
      <name>m_aViewWireFrame</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>p14</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QAction *</type>
      <name>m_aViewGhostMode</name>
      <anchorfile>classBR__MainWindow.html</anchorfile>
      <anchor>p15</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BR_View</name>
    <filename>classBR__View.html</filename>
    <member kind="function">
      <type></type>
      <name>BR_View</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(BB_Doc *doc, BR_InfoWidget *info, QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~BR_View</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>showCurrentFPS</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setWireFrame</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(bool value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setGhostMode</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(bool value)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>initializeGL</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>resizeGL</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>b1</anchor>
      <arglist>(int width, int height)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>paintGL</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>b2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>drawGrid</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>b3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>keyPressEvent</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>b4</anchor>
      <arglist>(QKeyEvent *ke)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>keyReleaseEvent</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>b5</anchor>
      <arglist>(QKeyEvent *ke)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>mousePressEvent</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>b6</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>mouseMoveEvent</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>b7</anchor>
      <arglist>(QMouseEvent *me)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BR_Camera</type>
      <name>m_Camera</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BR_KeyHandler</type>
      <name>m_Keys</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>m_MousePosX</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>m_MousePosY</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>unsigned int</type>
      <name>m_FPS</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>unsigned int</type>
      <name>m_CurrentFPS</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BR_InfoWidget *</type>
      <name>m_Info</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>p6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>BB_Doc *</type>
      <name>m_Doc</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>p7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>CGLLight *</type>
      <name>m_Light</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>p8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_GhostMode</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>p9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_WireFrame</name>
      <anchorfile>classBR__View.html</anchorfile>
      <anchor>p10</anchor>
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
      <type>virtual double</type>
      <name>getWinkel</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual C2dVector</type>
      <name>operator+</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>(const C2dVector &amp;v2) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual C2dVector</type>
      <name>operator-</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>(const C2dVector &amp;v2) const </arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>getClassName</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>print</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>(char c[]=&quot;&quot;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a14</anchor>
      <arglist>(const C2dVector &amp;v2) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual C2dVector</type>
      <name>operator *</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a15</anchor>
      <arglist>(const double value) const </arglist>
    </member>
    <member kind="function">
      <type>C2dVector</type>
      <name>rotate</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a16</anchor>
      <arglist>(double angle) const </arglist>
    </member>
    <member kind="function">
      <type>C2dVector</type>
      <name>unitVector</name>
      <anchorfile>classC2dVector.html</anchorfile>
      <anchor>a17</anchor>
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
  <compound kind="class">
    <name>C3dBody</name>
    <filename>classC3dBody.html</filename>
    <base>C3dQuad</base>
    <member kind="function">
      <type></type>
      <name>C3dBody</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~C3dBody</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const C3dVector &amp;</type>
      <name>getV4</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>moveBy</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const C3dVector &amp;vMove)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>rotate</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(const C3dVector &amp;vAxis, double Angle)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setV4</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const C3dVector &amp;_newVal)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>copy</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const C3dBody &amp;toCopy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>makeSurface</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>surfaceExists</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>draw</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>show</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>GLuint</type>
      <name>getTexture</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>QString &amp;</type>
      <name>getTextureFileName</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTextureFileName</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>(QString &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>makeTransformations</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>a14</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual bool</type>
      <name>createTexture</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_V4</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_SurfaceExists</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; C3dTriangle * &gt;</type>
      <name>m_Triangles</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; C3dQuad * &gt;</type>
      <name>m_Quads</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>GLuint</type>
      <name>m_Texture</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QString</type>
      <name>m_TextureFileName</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QVector&lt; CGLMatrix * &gt;</type>
      <name>m_Transformations</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>p6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_TexGenError</name>
      <anchorfile>classC3dBody.html</anchorfile>
      <anchor>p7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>C3dCylinder</name>
    <filename>classC3dCylinder.html</filename>
    <base>C3dBody</base>
    <member kind="function">
      <type></type>
      <name>C3dCylinder</name>
      <anchorfile>classC3dCylinder.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(double radius, double height, unsigned int sides)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>makeSurface</name>
      <anchorfile>classC3dCylinder.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>C3dGlobe</name>
    <filename>classC3dGlobe.html</filename>
    <base>C3dBody</base>
    <member kind="function">
      <type></type>
      <name>C3dGlobe</name>
      <anchorfile>classC3dGlobe.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>(C3dVector &amp;pos, double Radius, int Longitudes, int Latitudes, CColorRGBA &amp;color)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>makeSurface</name>
      <anchorfile>classC3dGlobe.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>C3dVector &amp;</type>
      <name>getPosition</name>
      <anchorfile>classC3dGlobe.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPosition</name>
      <anchorfile>classC3dGlobe.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(C3dVector &amp;_pos)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>C3dLine</name>
    <filename>classC3dLine.html</filename>
    <member kind="function">
      <type></type>
      <name>C3dLine</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~C3dLine</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const C3dVector &amp;</type>
      <name>getV1</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const C3dVector &amp;</type>
      <name>getVN1</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const C3dVector &amp;</type>
      <name>getVTex1</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setV1</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(const C3dVector &amp;_newVal)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setVN1</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const C3dVector &amp;_newVal)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setVTex1</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(const C3dVector &amp;_newVal)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>draw</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>drawNormals</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>moveBy</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>(const C3dVector &amp;vMove)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>rotate</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>(const C3dVector &amp;vAxis, double Angle)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>stretch</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>(double sx, double sy, double sz)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>copy</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>(const C3dLine &amp;toCopy)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>C3dLine</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>a14</anchor>
      <arglist>(const C3dVector &amp;v0, const C3dVector &amp;v1, const C3dVector &amp;n0, const C3dVector &amp;n1, const C3dVector &amp;t0=v_Zero, const C3dVector &amp;t1=v_Zero, const CColorRGBA &amp;color=cl_Red)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>C3dLine</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>a15</anchor>
      <arglist>(C3dPoint &amp;p1, C3dPoint &amp;p2, CColorRGBA &amp;color)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual GLenum</type>
      <name>getClassEnum</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>a16</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_V1</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_VN1</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_VTex1</name>
      <anchorfile>classC3dLine.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>C3dQuad</name>
    <filename>classC3dQuad.html</filename>
    <base>C3dTriangle</base>
    <member kind="function">
      <type></type>
      <name>C3dQuad</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const C3dVector &amp;v0, const C3dVector &amp;v1, const C3dVector &amp;v2, const C3dVector &amp;v3, const C3dVector &amp;t0, const C3dVector &amp;t1, const C3dVector &amp;t2, const C3dVector &amp;t3, const CColorRGBA &amp;color)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>C3dQuad</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const C3dVector &amp;v0, const C3dVector &amp;v1, const C3dVector &amp;v2, const C3dVector &amp;v3, const C3dVector &amp;n0, const C3dVector &amp;n1, const C3dVector &amp;n2, const C3dVector &amp;n3, const C3dVector &amp;t0, const C3dVector &amp;t1, const C3dVector &amp;t2, const C3dVector &amp;t3, const CColorRGBA &amp;color)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>C3dQuad</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(C3dPoint &amp;p1, C3dPoint &amp;p2, C3dPoint &amp;p3, C3dPoint &amp;p4, CColorRGBA &amp;color)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~C3dQuad</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const C3dVector &amp;</type>
      <name>getV3</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const C3dVector &amp;</type>
      <name>getVN3</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const C3dVector &amp;</type>
      <name>getVTex3</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual GLenum</type>
      <name>getClassEnum</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>draw</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>drawNormals</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>moveBy</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>(const C3dVector &amp;vMove)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>rotate</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>(const C3dVector &amp;vAxis, double Angle)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setV3</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>(const C3dVector &amp;_newVal)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setVN3</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a14</anchor>
      <arglist>(const C3dVector &amp;_newVal)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setVTex3</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a15</anchor>
      <arglist>(const C3dVector &amp;_newVal)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>stretch</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a16</anchor>
      <arglist>(double sx, double sy, double sz)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>copy</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a17</anchor>
      <arglist>(const C3dQuad &amp;toCopy)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>checkPlanarity</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>a18</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_V3</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_VN3</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_VTex3</name>
      <anchorfile>classC3dQuad.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>C3dTriangle</name>
    <filename>classC3dTriangle.html</filename>
    <base>C3dLine</base>
    <member kind="function">
      <type></type>
      <name>C3dTriangle</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>C3dTriangle</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(const C3dVector &amp;v0, const C3dVector &amp;v1, const C3dVector &amp;v2, const C3dVector &amp;t0, const C3dVector &amp;t1, const C3dVector &amp;t2, const CColorRGBA &amp;color)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>C3dTriangle</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(const C3dVector &amp;v0, const C3dVector &amp;v1, const C3dVector &amp;v2, const C3dVector &amp;n0, const C3dVector &amp;n1, const C3dVector &amp;n2, const C3dVector &amp;t0, const C3dVector &amp;t1, const C3dVector &amp;t2, const CColorRGBA &amp;color)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>C3dTriangle</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(C3dPoint &amp;p1, C3dPoint &amp;p2, C3dPoint &amp;p3, CColorRGBA &amp;color)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual GLenum</type>
      <name>getClassEnum</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>draw</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>drawNormals</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>moveBy</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(const C3dVector &amp;vMove)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>rotate</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(const C3dVector &amp;vAxis, double Angle)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>stretch</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>(double sx, double sy, double sz)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>copy</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>(const C3dTriangle &amp;toCopy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const C3dVector &amp;</type>
      <name>getV2</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const C3dVector &amp;</type>
      <name>getVN2</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const C3dVector &amp;</type>
      <name>getVTex2</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a14</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setVN2</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a15</anchor>
      <arglist>(const C3dVector &amp;_newVal)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setVTex2</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a16</anchor>
      <arglist>(const C3dVector &amp;_newVal)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setV2</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a17</anchor>
      <arglist>(const C3dVector &amp;_newVal)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>show</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a18</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setCollision</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a19</anchor>
      <arglist>(bool value)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getCollision</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a20</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>createTexture</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a21</anchor>
      <arglist>(const QImage &amp;texture)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setVisible</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a22</anchor>
      <arglist>(bool Value)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>getVisible</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>a23</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_V2</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_VN2</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_VTex2</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_Collision</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_Visible</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>GLuint</type>
      <name>m_Texture</name>
      <anchorfile>classC3dTriangle.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>C3dVector</name>
    <filename>classC3dVector.html</filename>
    <member kind="function">
      <type></type>
      <name>C3dVector</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~C3dVector</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>C3dVector</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>(double x, double y, double z)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>C3dVector</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(int angleMode, double radius, double longitude, double latitude)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>C3dVector</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(const C3dVector &amp;toCopy)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>x</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setX</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(double _newVal)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>y</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setY</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(double _newVal)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>z</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setZ</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>(double _newVal)</arglist>
    </member>
    <member kind="function">
      <type>const C3dVector &amp;</type>
      <name>unitVector</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator *</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>(const C3dVector &amp;v2) const </arglist>
    </member>
    <member kind="function">
      <type>const C3dVector &amp;</type>
      <name>vectorMult</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>(const C3dVector &amp;v2) const </arglist>
    </member>
    <member kind="function">
      <type>const C3dVector &amp;</type>
      <name>getNormalVector</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a14</anchor>
      <arglist>(const C3dVector &amp;v2) const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getLength</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a15</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const C3dVector</type>
      <name>rotateVector</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a16</anchor>
      <arglist>(const C3dVector &amp;Axis, double Angle) const </arglist>
    </member>
    <member kind="function">
      <type>const C3dVector &amp;</type>
      <name>operator-</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a17</anchor>
      <arglist>(const C3dVector &amp;v2) const </arglist>
    </member>
    <member kind="function">
      <type>const C3dVector &amp;</type>
      <name>operator+</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a18</anchor>
      <arglist>(const C3dVector &amp;v2) const </arglist>
    </member>
    <member kind="function">
      <type>GLdouble *</type>
      <name>dv</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a19</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const C3dVector &amp;</type>
      <name>stretchVector</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a20</anchor>
      <arglist>(double sx, double sy, double sz) const </arglist>
    </member>
    <member kind="function">
      <type>const C3dVector &amp;</type>
      <name>operator *</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a21</anchor>
      <arglist>(double f) const </arglist>
    </member>
    <member kind="function">
      <type>GLfloat *</type>
      <name>fv</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a22</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNull</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a23</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a24</anchor>
      <arglist>(const C3dVector &amp;v2) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a25</anchor>
      <arglist>(const C3dVector &amp;v2) const </arglist>
    </member>
    <member kind="function">
      <type>C3dVector &amp;</type>
      <name>operator=</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a26</anchor>
      <arglist>(const C3dVector &amp;toCopy)</arglist>
    </member>
    <member kind="function">
      <type>const C3dVector &amp;</type>
      <name>operator *</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a27</anchor>
      <arglist>(const CGLMatrix &amp;m) const </arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>debugString</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a28</anchor>
      <arglist>(const QString &amp;caption) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>debugOutput</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a29</anchor>
      <arglist>(const QString &amp;caption) const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getLatitude</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a30</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getTheta</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a31</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getRadius</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a32</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>toDegree</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a33</anchor>
      <arglist>(double angle) const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getLongitude</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a34</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getPhi</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a35</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const C3dVector &amp;</type>
      <name>operator/</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a36</anchor>
      <arglist>(double f) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRadiusPhiTheta</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a37</anchor>
      <arglist>(double radius, double phi, double theta)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRadiusLongitudeLatitude</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a38</anchor>
      <arglist>(double radius, double longitude, double latitude)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>toRadian</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a39</anchor>
      <arglist>(double angle) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>vertex</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a40</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>scalarMult</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>a41</anchor>
      <arglist>(const C3dVector &amp;v2) const </arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>debugOutputStatistics</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>e0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>setAngleMode</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>e1</anchor>
      <arglist>(const int &amp;_newVal)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static const int &amp;</type>
      <name>getAngleMode</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>e2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>debugResetCounters</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>e3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>Use360Degree</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>Use400NewDegree</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>UseRadian</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>AvailableOpBuffers</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>s3</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>copy</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(const C3dVector &amp;toCopy)</arglist>
    </member>
    <member kind="function" protection="protected" static="yes">
      <type>static const C3dVector &amp;</type>
      <name>getNextBuffer</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>f0</anchor>
      <arglist>(double x, double y, double z)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_X</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_Y</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_Z</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static int</type>
      <name>m_AngleMode</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>t0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static C3dVector</type>
      <name>OpBufferVectors</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>t1</anchor>
      <arglist>[AvailableOpBuffers]</arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static int</type>
      <name>n_Buffer</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>t2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static int</type>
      <name>n_MaxBuffers</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>t3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static int</type>
      <name>n_OperatorCalls</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>t4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static int</type>
      <name>n_CopyCalls</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>t5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static int</type>
      <name>n_ConstructorCalls</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>t6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static int</type>
      <name>n_VertexCalls</name>
      <anchorfile>classC3dVector.html</anchorfile>
      <anchor>t7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CColorRGBA</name>
    <filename>classCColorRGBA.html</filename>
    <member kind="function">
      <type></type>
      <name>CColorRGBA</name>
      <anchorfile>classCColorRGBA.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>CColorRGBA</name>
      <anchorfile>classCColorRGBA.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(GLfloat r, GLfloat g, GLfloat b, GLfloat a=1.0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~CColorRGBA</name>
      <anchorfile>classCColorRGBA.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const GLfloat *</type>
      <name>fv</name>
      <anchorfile>classCColorRGBA.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>CColorRGBA</type>
      <name>operator *</name>
      <anchorfile>classCColorRGBA.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(double f)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getR</name>
      <anchorfile>classCColorRGBA.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>CColorRGBA</type>
      <name>operator=</name>
      <anchorfile>classCColorRGBA.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const CColorRGBA &amp;toCopy)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getG</name>
      <anchorfile>classCColorRGBA.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>CColorRGBA</name>
      <anchorfile>classCColorRGBA.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(const CColorRGBA &amp;toCopy)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getB</name>
      <anchorfile>classCColorRGBA.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getA</name>
      <anchorfile>classCColorRGBA.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>copy</name>
      <anchorfile>classCColorRGBA.html</anchorfile>
      <anchor>b0</anchor>
      <arglist>(const CColorRGBA &amp;toCopy)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CGLLight</name>
    <filename>classCGLLight.html</filename>
    <member kind="function">
      <type></type>
      <name>CGLLight</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>CGLLight</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(C3dVector &amp;pos, CColorRGBA &amp;ambient, CColorRGBA &amp;diffuse, CColorRGBA &amp;specular, double brightness, bool directional)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOn</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>switchOff</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>switchOn</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isDirectional</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>C3dVector</type>
      <name>getPosition</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>CColorRGBA</type>
      <name>getAmbientColor</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>CColorRGBA</type>
      <name>getDiffuseColor</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>CColorRGBA</type>
      <name>getSpecularColor</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getBrightness</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>moveBy</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>(const C3dVector &amp;move)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setAmbientColor</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>(const CColorRGBA &amp;_color)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setBrightness</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a14</anchor>
      <arglist>(const double _brightness)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDiffuseColor</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a15</anchor>
      <arglist>(const CColorRGBA &amp;_color)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSpecularColor</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a16</anchor>
      <arglist>(const CColorRGBA &amp;_color)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPosition</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a17</anchor>
      <arglist>(const C3dVector &amp;_pos)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>show</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>a18</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>CColorRGBA</type>
      <name>m_AmbientColor</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>CColorRGBA</type>
      <name>m_DiffuseColor</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>CColorRGBA</type>
      <name>m_SpecularColor</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_Directional</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>m_On</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>GLenum</type>
      <name>m_LightNumber</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>m_Brightness</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>p6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dVector</type>
      <name>m_Position</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>p7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>C3dGlobe *</type>
      <name>m_Globe</name>
      <anchorfile>classCGLLight.html</anchorfile>
      <anchor>p8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CGLMatrix</name>
    <filename>classCGLMatrix.html</filename>
    <member kind="function">
      <type></type>
      <name>CGLMatrix</name>
      <anchorfile>classCGLMatrix.html</anchorfile>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>CGLMatrix</name>
      <anchorfile>classCGLMatrix.html</anchorfile>
      <anchor>a1</anchor>
      <arglist>(GLfloat M[16])</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~CGLMatrix</name>
      <anchorfile>classCGLMatrix.html</anchorfile>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setMatrix</name>
      <anchorfile>classCGLMatrix.html</anchorfile>
      <anchor>a3</anchor>
      <arglist>(const GLfloat *_newVal)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual GLfloat *</type>
      <name>getMatrix</name>
      <anchorfile>classCGLMatrix.html</anchorfile>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>loadIdentity</name>
      <anchorfile>classCGLMatrix.html</anchorfile>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>CGLMatrix</name>
      <anchorfile>classCGLMatrix.html</anchorfile>
      <anchor>a6</anchor>
      <arglist>(const CGLMatrix &amp;toCopy)</arglist>
    </member>
    <member kind="function">
      <type>const CGLMatrix</type>
      <name>operator=</name>
      <anchorfile>classCGLMatrix.html</anchorfile>
      <anchor>a7</anchor>
      <arglist>(const CGLMatrix &amp;toCopy)</arglist>
    </member>
    <member kind="function">
      <type>const CGLMatrix</type>
      <name>operator *</name>
      <anchorfile>classCGLMatrix.html</anchorfile>
      <anchor>a8</anchor>
      <arglist>(const CGLMatrix &amp;m2) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>debug</name>
      <anchorfile>classCGLMatrix.html</anchorfile>
      <anchor>a9</anchor>
      <arglist>(QString caption=&quot;&quot;)</arglist>
    </member>
    <member kind="function">
      <type>GLfloat</type>
      <name>m</name>
      <anchorfile>classCGLMatrix.html</anchorfile>
      <anchor>a10</anchor>
      <arglist>(int row, int column)</arglist>
    </member>
    <member kind="function">
      <type>CGLMatrix</type>
      <name>transpose</name>
      <anchorfile>classCGLMatrix.html</anchorfile>
      <anchor>a11</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>GLfloat</type>
      <name>determinant</name>
      <anchorfile>classCGLMatrix.html</anchorfile>
      <anchor>a12</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>GLfloat</type>
      <name>calcSarrus</name>
      <anchorfile>classCGLMatrix.html</anchorfile>
      <anchor>a13</anchor>
      <arglist>(int deletedColumn)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setM</name>
      <anchorfile>classCGLMatrix.html</anchorfile>
      <anchor>a14</anchor>
      <arglist>(int row, int column, GLfloat value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>loadModelview</name>
      <anchorfile>classCGLMatrix.html</anchorfile>
      <anchor>a15</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>multToStack</name>
      <anchorfile>classCGLMatrix.html</anchorfile>
      <anchor>a16</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="dir">
    <name>editor/</name>
    <path>/home/alex/Studium/SE.Projekt/glbb/editor/</path>
    <filename>dir_000000.html</filename>
    <file>bb.cpp</file>
    <file>bb.h</file>
    <file>bb_abstracttool.cpp</file>
    <file>bb_abstracttool.h</file>
    <file>bb_abstracttoolwidget.cpp</file>
    <file>bb_abstracttoolwidget.h</file>
    <file>bb_building.cpp</file>
    <file>bb_building.h</file>
    <file>bb_buildingposition.cpp</file>
    <file>bb_buildingposition.h</file>
    <file>bb_buildingtriangle.cpp</file>
    <file>bb_buildingtriangle.h</file>
    <file>bb_config.cpp</file>
    <file>bb_config.h</file>
    <file>bb_constructionelement.cpp</file>
    <file>bb_constructionelement.h</file>
    <file>bb_dlgbuildingedit.cpp</file>
    <file>bb_dlgbuildingedit.h</file>
    <file>bb_dlgleveledit.cpp</file>
    <file>bb_dlgleveledit.h</file>
    <file>bb_dlgopentexture.cpp</file>
    <file>bb_dlgopentexture.h</file>
    <file>bb_dlgprojectnew.cpp</file>
    <file>bb_dlgprojectnew.h</file>
    <file>bb_dlgterrainedit.cpp</file>
    <file>bb_dlgterrainedit.h</file>
    <file>bb_dlgwalledit.cpp</file>
    <file>bb_dlgwalledit.h</file>
    <file>bb_dlgwalleditarea.cpp</file>
    <file>bb_dlgwalleditarea.h</file>
    <file>bb_dlgwalleditpreview.cpp</file>
    <file>bb_dlgwalleditpreview.h</file>
    <file>bb_doc.cpp</file>
    <file>bb_doc.h</file>
    <file>bb_doccomponent.cpp</file>
    <file>bb_doccomponent.h</file>
    <file>bb_door.cpp</file>
    <file>bb_door.h</file>
    <file>bb_drawdevice.cpp</file>
    <file>bb_drawdevice.h</file>
    <file>bb_drawobject.cpp</file>
    <file>bb_drawobject.h</file>
    <file>bb_fileobject.cpp</file>
    <file>bb_fileobject.h</file>
    <file>bb_globals.cpp</file>
    <file>bb_globals.h</file>
    <file>bb_level.cpp</file>
    <file>bb_level.h</file>
    <file>bb_leveltriangle.cpp</file>
    <file>bb_leveltriangle.h</file>
    <file>bb_line.cpp</file>
    <file>bb_line.h</file>
    <file>bb_mainwindow.cpp</file>
    <file>bb_mainwindow.h</file>
    <file>bb_map.cpp</file>
    <file>bb_map.h</file>
    <file>bb_navigationline.cpp</file>
    <file>bb_navigationline.h</file>
    <file>bb_navigationpoint.cpp</file>
    <file>bb_navigationpoint.h</file>
    <file>bb_object.cpp</file>
    <file>bb_object.h</file>
    <file>bb_point.cpp</file>
    <file>bb_point.h</file>
    <file>bb_rect.cpp</file>
    <file>bb_rect.h</file>
    <file>bb_stair.cpp</file>
    <file>bb_stair.h</file>
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
    <file>bb_terrainpoint.cpp</file>
    <file>bb_terrainpoint.h</file>
    <file>bb_terraintriangle.cpp</file>
    <file>bb_terraintriangle.h</file>
    <file>bb_toolbuildingpositionnew.cpp</file>
    <file>bb_toolbuildingpositionnew.h</file>
    <file>bb_toolbuildingtrianglenew.cpp</file>
    <file>bb_toolbuildingtrianglenew.h</file>
    <file>bb_tooldelete.cpp</file>
    <file>bb_tooldelete.h</file>
    <file>bb_tooldoornew.cpp</file>
    <file>bb_tooldoornew.h</file>
    <file>bb_toolleveltrianglenew.cpp</file>
    <file>bb_toolleveltrianglenew.h</file>
    <file>bb_toollinenew.cpp</file>
    <file>bb_toollinenew.h</file>
    <file>bb_toolmove.cpp</file>
    <file>bb_toolmove.h</file>
    <file>bb_toolnavigationlinenew.cpp</file>
    <file>bb_toolnavigationlinenew.h</file>
    <file>bb_toolnavigationpointnew.cpp</file>
    <file>bb_toolnavigationpointnew.h</file>
    <file>bb_toolpointnew.cpp</file>
    <file>bb_toolpointnew.h</file>
    <file>bb_tools.h</file>
    <file>bb_toolscale.cpp</file>
    <file>bb_toolscale.h</file>
    <file>bb_toolstair.cpp</file>
    <file>bb_toolstair.h</file>
    <file>bb_toolterrainpointnew.cpp</file>
    <file>bb_toolterrainpointnew.h</file>
    <file>bb_toolterraintrianglenew.cpp</file>
    <file>bb_toolterraintrianglenew.h</file>
    <file>bb_tooltexture.cpp</file>
    <file>bb_tooltexture.h</file>
    <file>bb_tooltrianglenew.cpp</file>
    <file>bb_tooltrianglenew.h</file>
    <file>bb_toolwallnew.cpp</file>
    <file>bb_toolwallnew.h</file>
    <file>bb_toolwindownew.cpp</file>
    <file>bb_toolwindownew.h</file>
    <file>bb_toolzoom.cpp</file>
    <file>bb_toolzoom.h</file>
    <file>bb_transformer.cpp</file>
    <file>bb_transformer.h</file>
    <file>bb_triangle.cpp</file>
    <file>bb_triangle.h</file>
    <file>bb_wall.cpp</file>
    <file>bb_wall.h</file>
    <file>bb_widgettoolbuildingpositionnew.cpp</file>
    <file>bb_widgettoolbuildingpositionnew.h</file>
    <file>bb_widgettoollinenew.cpp</file>
    <file>bb_widgettoollinenew.h</file>
    <file>bb_widgettoolnavigationpointnew.cpp</file>
    <file>bb_widgettoolnavigationpointnew.h</file>
    <file>bb_widgettoolpointnew.cpp</file>
    <file>bb_widgettoolpointnew.h</file>
    <file>bb_widgettoolscale.cpp</file>
    <file>bb_widgettoolscale.h</file>
    <file>bb_widgettoolselect.cpp</file>
    <file>bb_widgettoolselect.h</file>
    <file>bb_widgettoolterrainpointnew.cpp</file>
    <file>bb_widgettoolterrainpointnew.h</file>
    <file>bb_widgettoolterraintrianglenew.cpp</file>
    <file>bb_widgettoolterraintrianglenew.h</file>
    <file>bb_widgettooltrianglenew.cpp</file>
    <file>bb_widgettooltrianglenew.h</file>
    <file>bb_widgettoolwallnew.cpp</file>
    <file>bb_widgettoolwallnew.h</file>
    <file>bb_widgettoolzoom.cpp</file>
    <file>bb_widgettoolzoom.h</file>
    <file>bb_window.cpp</file>
    <file>bb_window.h</file>
    <file>bb_workarea.cpp</file>
    <file>bb_workarea.h</file>
    <file>bb_workframe.cpp</file>
    <file>bb_workframe.h</file>
    <file>bb_xbuildinghandler.cpp</file>
    <file>bb_xbuildinghandler.h</file>
    <file>bb_xdochandler.cpp</file>
    <file>bb_xdochandler.h</file>
    <file>bb_xhandler.cpp</file>
    <file>bb_xhandler.h</file>
    <file>bb_xlevelhandler.cpp</file>
    <file>bb_xlevelhandler.h</file>
    <file>bb_xterrainhandler.cpp</file>
    <file>bb_xterrainhandler.h</file>
    <file>c2dvector.cpp</file>
    <file>c2dvector.h</file>
    <file>main.cpp</file>
  </compound>
  <compound kind="dir">
    <name>renderer/</name>
    <path>/home/alex/Studium/SE.Projekt/glbb/renderer/</path>
    <filename>dir_000001.html</filename>
    <file>3dmath.cpp</file>
    <file>3dmath.h</file>
    <file>br_camera.cpp</file>
    <file>br_camera.h</file>
    <file>br_globals.cpp</file>
    <file>br_globals.h</file>
    <file>br_infowidget.cpp</file>
    <file>br_infowidget.h</file>
    <file>br_keyhandler.cpp</file>
    <file>br_keyhandler.h</file>
    <file>br_mainwindow.cpp</file>
    <file>br_mainwindow.h</file>
    <file>br_view.cpp</file>
    <file>br_view.h</file>
    <file>c3dbody.cpp</file>
    <file>c3dbody.h</file>
    <file>c3dcylinder.cpp</file>
    <file>c3dcylinder.h</file>
    <file>c3dglobe.cpp</file>
    <file>c3dglobe.h</file>
    <file>c3dline.cpp</file>
    <file>c3dline.h</file>
    <file>c3dpoint.cpp</file>
    <file>c3dpoint.h</file>
    <file>c3dquad.cpp</file>
    <file>c3dquad.h</file>
    <file>c3dtriangle.cpp</file>
    <file>c3dtriangle.h</file>
    <file>c3dvector.cpp</file>
    <file>c3dvector.h</file>
    <file>ccolorrgba.cpp</file>
    <file>ccolorrgba.h</file>
    <file>cgllight.cpp</file>
    <file>cgllight.h</file>
    <file>cglmatrix.cpp</file>
    <file>cglmatrix.h</file>
    <file>main.cpp</file>
  </compound>
</tagfile>
