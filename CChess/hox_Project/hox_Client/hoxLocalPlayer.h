/////////////////////////////////////////////////////////////////////////////
// Name:            hoxLocalPlayer.h
// Program's Name:  Huy's Open Xiangqi
// Created:         10/28/2007
//
// Description:     The LOCAL Player.
/////////////////////////////////////////////////////////////////////////////

#ifndef __INCLUDED_HOX_LOCAL_PLAYER_H_
#define __INCLUDED_HOX_LOCAL_PLAYER_H_

#include <wx/wx.h>
#include "hoxPlayer.h"
#include "hoxEnums.h"
#include "hoxTypes.h"

/* Forward declarations */
class hoxThreadConnection;

/**
 * The LOCAL player.
 */

class hoxLocalPlayer :  public hoxPlayer
{
public:
    hoxLocalPlayer(); // DUMMY default constructor required for RTTI info.
    hoxLocalPlayer( const wxString& name,
                    hoxPlayerType   type,
                    int             score );

    virtual ~hoxLocalPlayer();

public:

    /*******************************************
     * Override the parent's event-handler API
     *******************************************/

    virtual void OnClose_FromTable( hoxPlayerEvent&  event );

    /*******************************
     * MY-specific Network API
     *******************************/

    virtual hoxResult ConnectToNetworkServer( const wxString& sHostname, 
                                              int             nPort, 
                                              wxEvtHandler*   sender );

    virtual hoxResult QueryForNetworkTables( wxEvtHandler* sender );
    virtual hoxResult JoinNetworkTable( const wxString& tableId,
                                        wxEvtHandler*   sender );
    virtual hoxResult OpenNewNetworkTable( wxEvtHandler*   sender );
    virtual hoxResult LeaveNetworkTable( const wxString& tableId,
                                         wxEvtHandler*   sender );

protected:
    virtual void AddRequestToConnection( hoxRequest* request );

private:
    void _StartConnection();

private:
    wxString         m_sHostname; 
    int              m_nPort;

    DECLARE_ABSTRACT_CLASS(hoxLocalPlayer)
};


#endif /* __INCLUDED_HOX_LOCAL_PLAYER_H_ */
