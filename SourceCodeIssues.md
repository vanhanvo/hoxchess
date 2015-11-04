# Introduction #

This page describes the main issues in HOXChess' s source code.
Developers should be aware of them.


# Details #

  * The class **hoxCoreBoard** overrides the parent function _wxPanel::DoGetBestSize()_ in order to auto-adjust the **9x10** ratio of a Xiangqi Board. Currently, we have to manually adjust the height so that the _core_ board can be displayed correctly. Note the _magic_ number **75**...
```
wxSize 
hoxCoreBoard::DoGetBestSize() const
{
    wxSize availableSize = GetParent()->GetClientSize();    

    int proposedHeight = 
        availableSize.GetHeight() - 75 /* TODO: The two players' info + The command bar */;
   ....
}
```