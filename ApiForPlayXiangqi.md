

# Introduction #

This page describes the public API supported by [PlayXiangqi server](http://www.playxiangqi.com)


# Overview #

A Request (to the server) or a Response (from the server) is a single string of key-value pairs, as follows:

```
key1=value1&key2=value1&...&keyN=valueN
```

  * **Request** (or _Command_)
    * Important parameters:
      * **op** - the _name_ of the _Request_
        * Examples of values: LOGIN, LOGOUT, LIST, JOIN, RESIGN,...
      * **pid** - the _required_ player ID for every Request

  * **Response** (or _Event_)
    * Important parameters:
      * **op** - the _name_ of the _Response_
        * Examples of values: LOGIN, LOGOUT, E\_END, E\_JOIN
      * **code** - the _status code_ of the response
        * Value code of **0** means _success_
      * **content** - the detailed _content_ of the _Response_
        * Example:
```
content=1;drawn;Players agree to draw
```


# Complete Reference #

  * **LOGIN** - Log in the server
    * Request
      * Parameters:
        * _pid_ - The Player's ID
        * _password_ - The Player's password
        * _ctype_ - The _optional_ client's type: _polling_ is the only value supported.
          * By default, the Client is required to maintain a _persistent_ TCP connection.
          * If _ctype_ = _polling_, then the connection can be dropped and re-established later by the Client (similar to a HTTP session).
      * Example:
```
op=LOGIN&pid=myid&password=mypw 
```
    * Response
      * To Player
        * op=LOGIN&code=0&content=playerid1;score1;sessionid1
        * Example:
```
op=LOGIN&code=0&content=myid;1501;312574
```
      * To Others:
        * op=LOGIN&code=0&content=playerid1;score1
```
op=LOGIN&code=0&content=myid
```

  * **LOGOUT** - Log out the server
    * Request
      * Parameters:
        * _pid_ - The Player's ID
```
op=LOGOUT&pid=myid
```
    * Response
      * To Player - _None_
      * To Others:
        * op=LOGOUT&pid=myid
```
op=LOGOUT&code=0&content=otherid
```

  * **I\_PLAYERS** - The event containing the list of online players
    * Response
      * To Player - The list of all online Players on in the server
```
op=I_PLAYERS&code=0&content=mypid;1500
Guest#t_4733;1500
hoxchess;1488

In this example, there are three online Players with player-ID = 'myid', 'Guest#t_4733', and 'hoxchess'
```

  * **LIST** - Get the list of Tables
    * Request
      * Parameters:
        * _pid_ - The Player's ID
```
op=LIST&pid=myid
```
    * Response
      * To Player - The list of all Tables in the server
```
op=LIST&code=0&content=1;0;0;1500/300/20;1500/300/20;1500/300/20;;0;AI_xqwlight;1579;
2;0;0;1500/300/20;1500/300/20;1500/300/20;myid;1397;;0;

In this example, there are two Tables with table-ID = 1 and 2
```

  * **NEW** - Create a new Table
    * Request
      * Parameters:
        * _pid_ - The Player's ID
        * _itimes_ - The _initial_ timers of (**Game**-time / **Move**-time / **Free**-time)
```
op=NEW&itimes=1500/300/20&pid=myid
```
    * Response
      * To Player - The **I\_TABLE** Response of the Table
```
op=I_TABLE&code=0&content=1;0;0;1500/300/20;1500/300/20;1500/300/20;myid;1398;;0;
```

  * **JOIN** - Join an existing Table
    * Request
      * Parameters:
        * _pid_ - The Player's ID
        * _tid_ - The ID of the Table to join
        * _color_ - The requested _color_ (or _role_)
          * Possible values: { **Red**, **Black**, **None** }
      * Example:
```
op=JOIN&color=None&pid=myid&tid=1
op=JOIN&color=Red&pid=myid&tid=1
```
    * Response
      * To Player - The **I\_TABLE** Response of the Table
```
op=I_TABLE&code=0&content=1;0;0;1500/300/20;1500/300/20;1500/300/20;;0;AI_xqwlight;1575;
op=E_JOIN&code=0&content=1;myid;1398;Red
```

  * **LEAVE** - Leave a Table
    * Request
      * Parameters:
        * _pid_ - The Player's ID
        * _tid_ - The ID of the Table to leave
      * Example:
```
op=LEAVE&pid=myid&tid=1
```
    * Response
      * To _all_ players that are present at the Table:
```
op=LEAVE&code=0&content=1;myid
```

  * **UPDATE** - Update the Table's Rating/Non-Rating or Timers.
    * Request
      * Parameters:
        * _pid_ - The Player's ID
        * _tid_ - The ID of the Table to leave
        * _itimes_ - The _initial_ timers of (**Game**-time / **Move**-time / **Free**-time)
        * _rated_ - The **Rated** or **Not-Rated** option.
          * Possible values: { 1, 0 }
      * Example:
```
op=UPDATE&pid=p1&tid=2&itimes=900/300/20&rated=1
```
    * Response
      * To _all_ players who are present at the Table:
```
op=UPDATE&code=0&content=2;p1;1;900/300/20
```

  * **MSG** - Post a _chat_ message to a Table
    * Request
      * Parameters:
        * _pid_ - The Player's ID
        * _msg_ - The message to be sent to others at the Table
        * _tid_ - _optional_ table-ID (the message is for everyone at this table)
        * _oid_ - _optional_ other player ID (the message is private only for this player)
      * Example:
```
op=MSG&pid=myid&tid=1&msg=Hi every at this table
op=MSG&pid=myid&oid=p1&msg=A private message from another player
```
    * Response
      * To Player - _None_
      * To Others:
```
op=MSG&code=0&tid=2&content=1;myid;Hello everyone at this table
op=MSG&code=0&content=hoxchess;hello from hoxchess
```

  * **PING** - Ping (keep-alive) the server to avoid being timed out.
    * Request
      * Parameters:
        * _pid_ - The Player's ID
      * Example:
```
op=PING&pid=myid
```
    * Response
      * To Player:
```
op=PING&code=0&content=PONG
```

  * **MOVE** - Make a new _Move_ in a Table
    * Request
      * Parameters:
        * _pid_ - The Player's ID
        * _tid_ - The ID of the Table
        * _move_ - The _move_ of format: x1y1x2y2
      * Example:
```
op=MOVE&pid=myid&tid=1&move=6665&game_time=1499
```
    * Response
      * To Player - _None_
      * To Others:
        * op=MOVE&code=0&content=tableid;playerid;move
```
op=MOVE&code=0&content=1;myid;6665
```

  * **RESIGN** - Resign the game at a Table
    * Request
      * Parameters:
        * _pid_ - The Player's ID
        * _tid_ - The ID of the Table
      * Example:
```
op=RESIGN&pid=p1&tid=1
```
    * Response
      * To _all_ players who are present at the Table and update the scores
```
op=E_END&code=0&content=1;black_win;Player resigned
op=E_SCORE&code=0&content=1;p1;1396
op=E_SCORE&code=0&content=1;AI_xqwlight;1580
```

  * **DRAW** - Request to _draw_ the game at a Table
    * Request
      * Parameters:
        * _pid_ - The Player's ID
        * _tid_ - The ID of the Table
      * Note: the game is ended if _both_ Players request a _draw_
      * Example:
```
op=DRAW&pid=p1&tid=2
```
    * Response
      * To _all_ players who are present at the Table
```
op=E_END&code=0&content=2;drawn;Players agree to draw
```

  * **RESET** - Reset (to _new_ status of the game) a Table
    * Request
      * Parameters:
        * _pid_ - The Player's ID
        * _tid_ - The ID of the Table
      * Note: the game is ended if _both_ Players request a _draw_
      * Example:
```
op=RESET&pid=p1&tid=2
```
    * Response
      * To _all_ players who are present at the Table
```
op=RESET&code=0&content=2
```

  * **INVITE** - Send an invitation to another Player
    * Request
      * Parameters:
        * _pid_ - The Player's ID
        * _oid_ - The (other) ID of the _invitee_
        * _tid_ - The _optional_ Id of a table
      * Example:
```
op=INVITE&pid=p1&oid=p2&tid=2
```
    * Response
      * To the other ( _invitee_ )
```
op=INVITE&code=0&tid=2&content=p1;1488;p2
```

  * **PLAYER\_INFO** - Query for a Player's information
    * Request
      * Parameters:
        * _pid_ - The Player's ID
        * _oid_ - The ID of the (other) Player to be queried
      * Example:
```
op=PLAYER_INFO&pid=p1&oid=p2
```
    * Response
      * To Player:
        * op=PLAYER\_INFO&code=0&content=playerid;score;wins;draws;losses
```
op=PLAYER_INFO&code=0&content=p2;1698;128;18;224
```

  * **POLL** - Poll for new events (specified used by _polling_ clients)
    * Request
      * Parameters:
        * _pid_ - The Player's ID
        * _sid_ - The _Session_ 's ID of the Player.
      * Example:
```
op=POLL&pid=p1&sid=841215

```
    * Response
      * To Player:
```
+ No events:
op=POLL&code=0&content=

+ With events (multiple events returned at the same time):
op=MOVE&code=0&content=1;AI_xqwlight;1022
op=LEAVE&code=0&more=1&content=1;AI_xqwlight
op=LEAVE&code=0&content=1;p1
```


# Sample Session #

```
op=LOGIN&pid=myid&password=mypw
... op=LOGIN&code=0&content=myid;1398;312574

op=LIST&pid=myid
... op=LIST&code=0&content=1;0;0;1500/300/20;1500/300/20;1500/300/20;;0;AI_xqwlight;1575;

op=JOIN&color=None&joined=0&pid=myid&tid=1
... op=I_TABLE&code=0&content=1;0;0;1500/300/20;1500/300/20;1500/300/20;;0;AI_xqwlight;1575;

op=JOIN&color=Red&joined=1&pid=myid&tid=1
... op=E_JOIN&code=0&content=1;myid;1398;Red

op=MOVE&game_time=1500&move=6947&pid=myid&tid=1
... op=MOVE&code=0&content=1;AI_xqwlight;7062

op=MOVE&game_time=1499&move=6665&pid=myid&tid=1
... op=MOVE&code=0&content=1;AI_xqwlight;2324

op=MSG&msg=Bye, now&pid=myid&tid=1
op=MSG&msg=let us draw this game&pid=myid&tid=1
op=DRAW&draw_response=&pid=myid&tid=1
... op=E_END&code=0&content=1;drawn;Players agree to draw

... op=LEAVE&code=0&content=1;AI_xqwlight

op=LEAVE&pid=myid&tid=1
... op=LEAVE&code=0&content=1;myid

op=NEW&itimes=1500/300/20&pid=myid
... op=I_TABLE&code=0&content=1;0;0;1500/300/20;1500/300/20;1500/300/20;myid;1398;;0;

op=LEAVE&pid=myid&tid=1
... op=LEAVE&code=0&content=1;myid

op=LOGOUT&pid=myid

```