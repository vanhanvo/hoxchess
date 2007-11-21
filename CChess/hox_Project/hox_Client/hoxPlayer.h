/***************************************************************************
 *  Copyright 2007 Huy Phan  <huyphan@playxiangqi.com>                     *
 *                                                                         * 
 *  This file is part of HOXChess.                                         *
 *                                                                         *
 *  HOXChess is free software: you can redistribute it and/or modify       *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, either version 3 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  HOXChess is distributed in the hope that it will be useful,            *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with HOXChess.  If not, see <http://www.gnu.org/licenses/>.      *
 ***************************************************************************/

/////////////////////////////////////////////////////////////////////////////
// Name:            hoxPlayer.h
// Created:         10/06/2007
//
// Description:     The Player.
/////////////////////////////////////////////////////////////////////////////

#ifndef __INCLUDED_HOX_PLAYER_H_
#define __INCLUDED_HOX_PLAYER_H_

#include <wx/wx.h>
#include "hoxEnums.h"
#include "hoxTypes.h"
#include "hoxPlayerEvent.h"

/* Forward declarations */
class hoxTable;
class hoxConnection;

// ----------------------------------------------------------------------------
// Declare player-event types
// ----------------------------------------------------------------------------

BEGIN_DECLARE_EVENT_TYPES()
  DECLARE_EVENT_TYPE(hoxEVT_PLAYER_TABLE_CLOSED, wxID_ANY)
  DECLARE_EVENT_TYPE(hoxEVT_PLAYER_NEW_MOVE, wxID_ANY)
END_DECLARE_EVENT_TYPES()

/* 
 * New player-event based on wxCommandEvent.
 */
DECLARE_EVENT_TYPE(hoxEVT_PLAYER_WALL_MSG, wxID_ANY)
DECLARE_EVENT_TYPE(hoxEVT_PLAYER_APP_SHUTDOWN, wxID_ANY)

// ----------------------------------------------------------------------------
// The Player class
// ----------------------------------------------------------------------------

// NOTE **** According to wxWidgets documentation regarding wxEvtHandler:
//
//         When using multiple inheritance it is imperative that 
//         the wxEvtHandler(-derived) class be the first class inherited 
//         such that the "this" pointer for the overall object will be 
//         identical to the "this" pointer for the wxEvtHandler portion.
//

/**
 * An interface for a Player.
 * Other more advanced Players derived from this class.
 */
class hoxPlayer :  public wxEvtHandler
{
public:
    hoxPlayer(); // DUMMY default constructor required for event handler.
    hoxPlayer( const wxString& name,
               hoxPlayerType   type,
               int             score = 1500);

    virtual ~hoxPlayer();

    /***************************
     * Event-handle API
     ***************************/

    virtual void OnClose_FromTable( hoxPlayerEvent&  event );
    virtual void OnNewMove_FromTable( hoxPlayerEvent&  event );

    virtual void OnWallMsg_FromTable( wxCommandEvent&  event );
    virtual void OnShutdown_FromApp( wxCommandEvent&  event );

    /***************************
     * Accessor API
     ***************************/

    wxString      GetName() const               { return m_name; }
    void          SetName(const wxString& name) { m_name = name; }

    hoxPlayerType GetType() const { return m_type; }

    const hoxRoleList& GetRoles() const { return m_roles; }
    void               AddRole( hoxRole role );
    void               RemoveRole( hoxRole role );
    bool               RemoveRoleAtTable( const wxString& tableId );
    bool               HasRole( hoxRole role );

    int                GetScore() const    { return m_score; }
    void               SetScore(int score) { m_score = score; }

    
    /***************************
     * Basic action API
     ***************************/

    virtual hoxResult JoinTable( hoxTable* table );
    virtual hoxResult LeaveTable( hoxTable* table );
    virtual hoxResult LeaveAllTables();

    /**
     * Set the connection to the "outside" world.
     *
     * @return true  - If this connection can be set.
     *         false - If some other existing connection has been set.
     */
    virtual bool SetConnection( hoxConnection* connection );

    /**
     * Return the connection.
     */
    virtual hoxConnection* GetConnection() const { return m_connection; }
  
    /**
     * Reset connection to NULL.    
     */
    virtual void ResetConnection();

protected:
    /**
     * Handle the incoming data from the connection.
     */
    virtual hoxResult HandleIncomingData( const wxString& commandStr );
    virtual hoxResult HandleIncomingData_Move( hoxCommand& command, wxString& response );
    virtual hoxResult HandleIncomingData_Leave( hoxCommand& command, wxString& response );
    virtual hoxResult HandleIncomingData_WallMsg( hoxCommand& command, wxString& response );
    virtual hoxResult HandleIncomingData_List( hoxCommand& command, wxString& response );
    virtual hoxResult HandleIncomingData_Join( hoxCommand& command, wxString& response );

    virtual void StartConnection();
    virtual void ShutdownConnection();

    virtual void AddRequestToConnection( hoxRequest* request );

    void DecrementOutstandingRequests();

private:
    void _ShutdownMyself();

private:
    hoxConnection*  m_connection;
            /* The connection to "outside" world.
             * For Host and Dummy player, it will be NULL.
             * NOTE: This variable is placed here even though some players
             *       (such as Host and Dummy) do not need it because most
             *       players do. Also, placing it here simplifies the code
             *       and design.
             */

    wxString       m_name;   // The player's name.

    hoxPlayerType  m_type;       
            /* Is it a Local, Network,... player? */

    hoxRoleList    m_roles;
            /* Which tables, which side (color) I am playing (RED or BLACK)?
             */

    int            m_score;  // The player's Score.

    int            m_nOutstandingRequests;

    bool           m_shutdownRequested;

    DECLARE_DYNAMIC_CLASS(hoxPlayer)
    DECLARE_EVENT_TABLE()
};

// ----------------------------------------------------------------------------
// Player event macros
// ----------------------------------------------------------------------------

typedef void (wxEvtHandler::*hoxPlayerEventFunction)(hoxPlayerEvent&);

#define EVT_PLAYER_TABLE_CLOSED(id, fn) DECLARE_EVENT_TABLE_ENTRY(hoxEVT_PLAYER_TABLE_CLOSED, id, wxID_ANY, (wxObjectEventFunction) (wxEventFunction) (wxCommandEventFunction) (wxNotifyEventFunction)  wxStaticCastEvent( hoxPlayerEventFunction, & fn ), (wxObject *) NULL ),
#define EVT_PLAYER_NEW_MOVE(id, fn) DECLARE_EVENT_TABLE_ENTRY(hoxEVT_PLAYER_NEW_MOVE, id, wxID_ANY, (wxObjectEventFunction) (wxEventFunction) (wxCommandEventFunction) (wxNotifyEventFunction)  wxStaticCastEvent( hoxPlayerEventFunction, & fn ), (wxObject *) NULL ),

#endif /* __INCLUDED_HOX_PLAYER_H_ */
