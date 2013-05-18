//General Data and Trading Service Protocol (GSP)

//Client = Any application program supporting GSP. This can be a charting program, trading program, automated trading program.  A combination of these, or whatever.
//Server = Any service/program that provides Market Data and Trading functionality that follows this GSP protocol.

namespace GSP
{
#pragma pack(8)

	const int CURRENT_VERSION = 1;
	const int 	SYMBOL_LENGTH = 64;
	const int EXCHANGE_LENGTH= 32;
	const int  UNDERLYING_LENGTH= 32;
	const int ORDER_ID_LENGTH = 32;
	const int TRADE_ACCOUNT_LENGTH = 32;

	//----Message types----
	const unsigned short LOGON_REQUEST=  1;//Client >> Server
	const unsigned short LOGON_RESPONSE =  2;//Server  >> Client

	//Each side sends each other a heartbeat at the interval specified by the HeartbeatIntervalInSeconds member in the LOGON_REQUEST
	const unsigned short HEARTBEAT =  3;//Client >> Server and Server  >> Client

	//This is a command from the Server to tell the Client to disconnect and do not reconnect.  The Server can gracefully close the socket after sending this.
	const unsigned short DISCONNECT_FROM_SERVER_NO_RECONNECT =  4;//Server  >> Client


	//When the Server accepts the network connection from the Client and it is ready to receive, it needs to reply with this message.
	//Messages from the Client starting with the LOGON_REQUEST, will be sent after 10 seconds if this is not received. 
	const unsigned short SERVER_READY_TO_RECEIVE =  5;//Server  >> Client


	const unsigned short MARKET_DATA_FEED_STATUS = 100;//Server  >> Client

	//This request will subscribe to market data for a particular symbol.  In response to this you can also return market depth data and not rely on MARKET_DEPTH_REQUEST
	const unsigned short MARKET_DATA_REQUEST =  101;//Client >> Server

	const unsigned short MARKET_DEPTH_REQUEST = 102;//Client >> Server

	//For rejecting a market data or market depth request
	const unsigned short MARKET_DATA_REJECT = 103;//Server >> Client


	// Send after requesting market data for a symbol and at the start of a new trading session.   Or when the DailyHigh and DailyLow need to be reset.
	// This can be sent more often, but it is not intended to be sent frequently.
	// This message type does not signify a trade has occurred.  It should never be interpreted in that way.
	// There is no need to send this when there is a new high or low during the trading day.  It is intended that the Client will maintain those based upon the TRADE_INCREMENTAL_UPDATE message.
	const unsigned short MARKET_DATA_SNAPSHOT = 104;//Server >> Client

	// Send to update the entire market depth book (20 levels)
	const unsigned short MARKET_DEPTH_FULL_UPDATE = 105;//Server >> Client

	//Send to update a market depth level
	const unsigned short MARKET_DEPTH_INCREMENTAL_UPDATE = 106;//Server >> Client

	//Send when a trade occurs
	const unsigned short TRADE_INCREMENTAL_UPDATE = 107;//Server >> Client

	//Send when the best bid and ask changes
	const unsigned short QUOTE_INCREMENTAL_UPDATE = 108;//Server >> Client

	// Send to update the entire market depth book (100 levels)
	const unsigned short MARKET_DEPTH_FULL_UPDATE_LARGE = 109;//Server >> Client

	// This needs to be returned in response to a MARKET_DATA_REQUEST if the Server can provide data for at least one of the structure members.
	// The server should send this response initially after the request and any time the fundamental data changes.
	const unsigned short FUNDAMENTAL_DATA_RESPONSE = 110;//Server >> Client

	//This is a combination of TRADE_INCREMENTAL_UPDATE and MARKET_DEPTH_FULL_UPDATE (Only 10 levels)
	const unsigned short TRADE_INCREMENTAL_UPDATE_WITH_FULL_DEPTH = 111;//Server >> Client

	// This message is for submitting a new single order. All updates to the order are communicated through a ORDER_UPDATE_REPORT message.
	// A rejected order is communicated through a ORDER_UPDATE_REPORT message with a ExecutionType of ET_NEW_ORDER_REJECT
	const unsigned short SUBMIT_NEW_SINGLE_ORDER = 200;//Client >> Server

	//For details about the new OCO order message, refer to the s_SubmitNewOCOOrder structure 
	const unsigned short SUBMIT_NEW_OCO_ORDER = 201;//Client >> Server

	const unsigned short CANCEL_REPLACE_ORDER =  202;//Client >> Server

	const unsigned short CANCEL_ORDER = 203;//Client >> Server

	//Only return open orders in response to this request.  No need to return Canceled or Filled orders.  A separate message type can be added for that.
	//When responding to this request, respond with a separate ORDER_UPDATE_REPORT for each order.
	//When responding to this request, s_OrderUpdateReport::ExecutionType  needs to be set to ET_OPEN_ORDERS_REQUEST
	//If there are no open orders, send back 1 ORDER_UPDATE_REPORT with only the	TotalNumberMessages, MessageNumber, RequestID, ExecutionType, NoneOrders = 1 set in the s_OrderUpdateReport structure.
	const unsigned short OPEN_ORDERS_REQUEST = 300;//Client >> Server

	const unsigned short ORDER_UPDATE_REPORT = 301;//Server >> Client

	//If the Server is unable to serve the request for Open orders  for a reason other than there not being any Open orders, then use this message.
	const unsigned short OPEN_ORDERS_REQUEST_REJECT = 302;//Server >> Client

	//Return individual order fills / executions in response to this request.
	const unsigned short REQUEST_HISTORICAL_ORDER_FILLS = 303;//Client >> Server
	const unsigned short HISTORICAL_ORDER_FILL_REPORT = 304;//Server >> Client

	//This message type requests all of the current open Positions for all of the accounts on the logged in username.
	const unsigned short CURRENT_POSITIONS_REQUEST = 305;//Client >> Server

	//If there are no open Positions, send back 1 POSITION_REPORT with only the TotalNumberMessages, MessageNumber, RequestID, NonePositions = 1 set in the s_PositionReport structure.
	const unsigned short POSITION_REPORT = 306;//Server >> Client

	//If the Server is unable to serve the request for Positions for a reason other than there not being any Positions, then use this message.
	const unsigned short CURRENT_POSITIONS_REQUEST_REJECT = 307;//Server >> Client

	//Requests all of the trading account numbers for the logged in username
	const unsigned short REQUEST_ACCOUNTS = 400;//Client >> Server
	const unsigned short ACCOUNTS_LIST_RESPONSE=401;//Server >> Client

	//For requesting a list of all available exchanges from the server.
	//In the case where the Server does not specify an exchange with its symbols, then this will just return a single response with an empty exchange.
	const unsigned short EXCHANGE_LIST_REQUEST = 500;//Client >> Server
	//The server will return one of these messages for each supported exchange.
	const unsigned short EXCHANGE_LIST_RESPONSE =  501;//Server >> Client

	//For requesting all of the symbols on a particular exchange
	const unsigned short SYMBOLS_FOR_EXCHANGE_REQUEST=502;//Client >> Server

	//For requesting all of the underlying symbols on a particular Exchange.  For example all of the underlying futures symbols on a particular exchange.
	const unsigned short UNDERLYING_SYMBOLS_FOR_EXCHANGE_REQUEST   =503;//Client >> Server

	//For requesting all of the symbols for a particular underlying.  For example all of the futures contracts for a particular underlying futures symbol or all of the option symbols for a particular futures or stock symbol.
	const unsigned short SYMBOLS_FOR_UNDERLYING_REQUEST = 504;//Client >> Server

	//The Server response message containing a single Symbol and Exchange in response to : SYMBOLS_FOR_EXCHANGE_REQUEST, UNDERLYING_SYMBOLS_FOR_EXCHANGE_REQUEST, SYMBOLS_FOR_UNDERLYING_REQUEST 
	const unsigned short SYMBOL_RESPONSE =  505;//Server >> Client

	//For requesting a security definition for a specific symbol
	const unsigned short SECURITY_DEFINITION_FOR_SYMBOL_REQUEST = 506;//Client >> Server

	//The response for a security definition request
	const unsigned short SECURITY_DEFINITION_RESPONSE =  507;//Server >> Client


	const unsigned short ACCOUNT_BALANCE_UPDATE = 600;//Server >> Client

	const unsigned short USER_MESSAGE = 700;//Server >> Client

	const unsigned short HISTORICAL_PRICE_DATA_REQUEST= 800;//Client >> Server
	const unsigned short HISTORICAL_PRICE_DATA_HEADER_RESPONSE = 801;//Server >> Client
	const unsigned short HISTORICAL_PRICE_DATA_REJECT = 802; //Server >> Client
	const unsigned short HISTORICAL_PRICE_DATA_RECORD_RESPONSE = 803;//Server >> Client
	const unsigned short HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE= 804; //Server >> Client

	/*==========================================================================*/

	//Nonstandard messages which are not considered part of the standard GSP but for specialized uses.  A standard GSP server and client do not need to implement these.
	//----------------------------------------------

	//This will be sent from the client to the server when a "Configuration Request" button is pressed in the Client.
	//It is intended to be used by a server executable program running on the local machine to display a configuration window.
	const unsigned short CONFIGURATION_REQUEST_FROM_CLIENT = 10001; //Client >> Server



	/*==========================================================================*/
	//Standard UNIX date and time value
	typedef __int64 t_DateTime;

	// This is a 4 byte DateTime value used in messages where compactness is an important consideration.
	typedef unsigned int t_DateTime4Byte;

	/*==========================================================================*/
	enum LogonStatusEnum : int
	{ LOGON_SUCCESS = 1
	, LOGON_ERROR = 2

	//You can use this logon status in the LOGON_RESPONSE message instruct the Client to reconnect to the Server at a different address.  This supports dynamic connections to a server farm.
	, LOGON_RECONNECT_NEW_ADDRESS = 3
	};

	/*==========================================================================*/
	enum MessageSupportedEnum : int
	{ MESSAGE_UNSUPPORTED = 0
	, MESSAGE_SUPPORTED = 1
	};

	/*==========================================================================*/
	enum TradeModeEnum : int
	{ TRADE_MODE_DEMO = 1
	, TRADE_MODE_SIMULATED = 2
	, TRADE_MODE_LIVE = 3
	};

	/*==========================================================================*/
	enum RequestActionEnum : int
	{ SUBSCRIBE = 1
	, UNSUBSCRIBE = 2
	};

	/*==========================================================================*/
	enum OrderStatusEnum : int
	{ ORDER_STATUS_UNSPECIFIED = 0//The status of the order is unset
	, ORDER_STATUS_ORDERSENT = 1  //When a Client sends an order to the Server, then the Client internally will set the status to Order Sent.  The Server will not set this Status.
	, ORDER_STATUS_PENDINGOPEN = 2//This means the Server has accepted the order but it is not yet considered in a fully working state for any reason.

	// This is meant to be used only on the Client side and indicates a child order part of a bracket order, is waiting to be sent when the parent fills.
	, ORDER_STATUS_PENDINGCHILD = 3

	, ORDER_STATUS_OPEN = 4//Order is open and working.
	, ORDER_STATUS_PENDING_CANCEL_REPLACE = 5//Order is pending a Cancel and Replace operation.
	, ORDER_STATUS_PENDING_CANCEL = 6//Order is pending cancellation
	, ORDER_STATUS_FILLED = 7//Order is filled and no longer working.
	, ORDER_STATUS_CANCELED = 8//Order is canceled.
	, ORDER_STATUS_REJECTED = 9//Order has been rejected and is no longer working.  This can be for any reason.
	};

	/*==========================================================================*/
	enum ExecutionTypeEnum : int

	//Always set the execution type.  This is not considered a valid execution type.
	{ ET_UNSET = 0

	//Set this when the order is sent based on a OPEN_ORDERS_REQUEST request
	, ET_OPEN_ORDERS_REQUEST = 1

	//When a new order has been accepted, this is the execution type
	, ET_NEW_ORDER_ACCEPTED = 2

	//A general order update.  For example, when an order is in the process of being canceled,  you can set the order status to indicate that the order is pending a cancellation. It is not mandatory to indicate the order is pending a cancellation.
	, ET_ORDER_UPDATE = 3

	//Upon a complete fill of the order, this is the execution type
	, ET_FILLED = 4

	//Upon a partial fill, this is the execution type
	, ET_PARTIAL_FILL = 5

	//The order cancellation is complete
	, ET_CANCELED = 6

	//The order cancel and replace operation is complete.
	, ET_CANCEL_REPLACE_COMPLETE = 7

	// After an order has been submitted and it has been rejected and is no longer working, send through an order report with this execution type
	// In this case the Server needs to set the OrderStatus in the order report to ORDER_STATUS_REJECTED
	, ET_NEW_ORDER_REJECT = 8

	// A request to cancel the order has been rejected.  Be sure to set the current status of the order in the OrderStatus member of the ORDER_UPDATE_REPORT message 

	//In the event where the given ServerOrderID in a CANCEL_ORDER message from the Client is not found, then respond with a ORDER_UPDATE_REPORT message and set the execution type to ET_ORDER_CANCEL_REJECT.  In this case, ServerOrderID does not need to be set in the ORDER_UPDATE_REPORT message.  However, you must set the ClientOrderID in the ORDER_UPDATE_REPORT message to the given ClientOrderID in the CANCEL_ORDER message.
	, ET_ORDER_CANCEL_REJECT = 9

	//A request to cancel/replace the order has been rejected.  Be sure to set the current status of the order in the OrderStatus member of the ORDER_UPDATE_REPORT message 

		//In the event where the given ServerOrderID in a CANCEL_REPLACE_ORDER message from the Client is not found, then respond with a ORDER_UPDATE_REPORT message and set the execution type to ET_ORDER_CANCEL_REPLACE_REJECT.  In this case, ServerOrderID does not need to be set in the ORDER_UPDATE_REPORT message.  However, you must set the ClientOrderID in the ORDER_UPDATE_REPORT message to the given ClientOrderID in the CANCEL_REPLACE_ORDER message.
	, ET_ORDER_CANCEL_REPLACE_REJECT = 10
	};


	enum BidOrAskEnum : unsigned short
	{ BID_ASK_UNSET = 0
	, AT_BID = 1
	, AT_ASK = 2
	};

	enum MarketDepthIncrementalUpdateTypeEnum : unsigned char
	{ DEPTH_UNSET = 0
	, DEPTH_INSERT_UPDATE = 1  //Insert or update depth at the given price level
	, DEPTH_DELETE = 2  //Delete depth at the given price level
	};

	enum OrderTypeEnum : int
	{ ORDER_TYPE_UNSET = 0
	, ORDER_TYPE_MARKET = 1
	, ORDER_TYPE_LIMIT = 2
	, ORDER_TYPE_STOP = 3
	, ORDER_TYPE_STOP_LIMIT = 4
	, ORDER_TYPE_MARKET_IF_TOUCHED = 5
	};

	enum TimeInForceEnum : int
	{ TIF_UNSET = 0
	, TIF_DAY = 1
	, TIF_GTC = 2
	, TIF_GOOD_TILL_DATE_TIME = 3
	, TIF_IMMEDIATE_OR_CANCEL = 4
	, TIF_ALL_OR_NONE = 5
	, TIF_FILL_OR_KILL = 6
	};

	enum BuySellEnum : int
	{ BUY_SELL_UNSET = 0
	, BUY = 1
	, SELL = 2
	};

	/*==========================================================================*/
	enum OpenCloseTradeEnum : int
	{ TRADE_UNSET = 0
	, TRADE_OPEN = 1
	, TRADE_CLOSE = 2
	};

	/*==========================================================================*/
	// These statuses apply to all  symbols that have been subscribed to.
	enum MarketDataFeedStatusEnum : int
	{ MARKET_DATA_FEED_LOST = 1

	//  Upon a connection to the server, this is assumed to be the status.  It is not until there has been expressly given MARKET_DATA_FEED_LOST, will the data feed be considered lost. The Client can optionally resubscribe to all symbols using MARKET_DATA_REQUEST messages, when this status is received.
	, MARKET_DATA_FEED_RESTORED = 2
	};

	/*==========================================================================*/
	enum DisplayFormatEnum : int
	{ DISPLAY_FORMAT_DENOMINATOR_256 = 356
	, DISPLAY_FORMAT_DENOMINATOR_128 = 228
	, DISPLAY_FORMAT_DENOMINATOR_64 = 164
	, DISPLAY_FORMAT_DENOMINATOR_32 = 132  //This also supports .25 and .5 32nds
	, DISPLAY_FORMAT_DENOMINATOR_16 = 116
	, DISPLAY_FORMAT_DENOMINATOR_8 = 108
	, DISPLAY_FORMAT_DENOMINATOR_4 = 104
	, DISPLAY_FORMAT_DENOMINATOR_2 = 102

	//The following formats indicate the number of decimal places to be displayed
	, DISPLAY_FORMAT_DECIMAL_0 = 0
	, DISPLAY_FORMAT_DECIMAL_1 = 1
	, DISPLAY_FORMAT_DECIMAL_2 = 2
	, DISPLAY_FORMAT_DECIMAL_3 = 3
	, DISPLAY_FORMAT_DECIMAL_4 = 4
	, DISPLAY_FORMAT_DECIMAL_5 = 5
	, DISPLAY_FORMAT_DECIMAL_6 = 6
	, DISPLAY_FORMAT_DECIMAL_7 = 7
	, DISPLAY_FORMAT_DECIMAL_8 = 8
	, DISPLAY_FORMAT_DECIMAL_9 = 9
	};

	/*==========================================================================*/
	enum SecurityTypeEnum : int
	{ ST_UNSET = 0
	, ST_FUTURE = 1
	, ST_STOCK = 2
	, ST_FOREX = 3  //Bitcoins also go into this category
	, ST_INDEX = 4
	, ST_FUTURES_STRATEGY = 5
	, ST_STOCK_OPTION = 6
	, ST_FUTURES_OPTION = 7
	, ST_INDEX_OPTION = 8
	};

	enum HistoricalDataIntervalEnum : int
	{ INTERVAL_TICK = 0
	, INTERVAL_1_SECOND = 1
	, INTERVAL_1_MINUTE = 60
	, INTERVAL_1_DAY = 86400
	, INTERVAL_1_WEEK = 604800
	};

	/*==========================================================================*/
	struct s_SymbolExchange
	{
		char Symbol[SYMBOL_LENGTH];
		char Exchange[ EXCHANGE_LENGTH];

	};

	/*==========================================================================*/
	struct s_LogonRequest
	{
		unsigned short Size;
		unsigned short Type;
		int ProtocolVersion;

		char  Username[32];//Optional if authentication is not needed
		char Password[32];//Optional if authentication is not needed

		char  GeneralTextData[64];//Optional.  General-purpose text string.
		int Integer_1;//Optional.  General-purpose integer.
		int Integer_2;//Optional.  General-purpose integer.

		// The interval in seconds that each side needs to use to send heartbeat messages to the other side.
		int  HeartbeatIntervalInSeconds; 

		//Optional: To indicate Demo, Simulated, Live
		TradeModeEnum TradeMode;

		//This should only be set to a trade account identifier if that is required to login.  
		//Usually this would be the case if the log in is bound to a particular account and not changeable after the log in.
		//Otherwise, this should be blank and Client will discover the accounts through an Account List Request.
		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		// Computer hardware ID.  This will be implemented on a case-by-case basis with specific Data/Trading service providers.   It will be a reasonable implementation to uniquely identify a system and will not be publicly disclosed. It will never contain personally identifiable information. 
		char HardwareIdentifier[64];


		s_LogonRequest ()
		{
			memset(this, 0,sizeof(s_LogonRequest));
			Type=LOGON_REQUEST;
			Size=sizeof(s_LogonRequest);
			ProtocolVersion = CURRENT_VERSION;
		}

		char * GetUsername()
		{
			// Example to check if member actually exists. This is not needed in this case because this member exists in the first version of this structure.
			if( (byte*)&Username - (byte*)this   > Size)
				return   "";

			Username[sizeof(Username) - 1 ] = '\0';//Ensure that the null terminator exists

			return Username;
		}

		void SetUsername(const char * NewValue)
		{
			strncpy(Username, NewValue, sizeof(Username) - 1);
		}

		char * GetPassword()
		{
			return Password;
		}

		void SetPassword(const char * NewValue)
		{
			strncpy(Password, NewValue, sizeof(Password) - 1);
		}

		char * GetGeneralTextData()
		{
			return GeneralTextData;
		}

		void SetGeneralTextData(const char * NewValue)
		{
			strncpy(GeneralTextData, NewValue, sizeof(GeneralTextData) - 1);
		}

		int GetInteger_1()
		{
			return Integer_1;
		}

		void SetInteger_1(int NewValue)
		{
			Integer_1 = NewValue;
		}

		int GetInteger_2()
		{
			return Integer_2;
		}

		void SetInteger_2(int NewValue)
		{
			Integer_2 = NewValue;
		}

		int GetInHeartbeatIntervalInSeconds()
		{
			return HeartbeatIntervalInSeconds;
		}

		void SetHeartbeatIntervalInSeconds(int NewValue)
		{
			HeartbeatIntervalInSeconds = NewValue;
		}

		TradeModeEnum GetTradeMode()
		{
			return TradeMode;
		}

		void SetTradeMode(TradeModeEnum NewValue)
		{
			TradeMode = NewValue;
		}

		char * GetTradeAccount()
		{
			return TradeAccount;
		}

		void SetTradeAccount(const char * NewValue)
		{
			strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
		}
		
		char * GetHardwareIdentifier()
		{
			return HardwareIdentifier;
		}

		void SetHardwareIdentifier(const char * NewValue)
		{
			strncpy(HardwareIdentifier, NewValue, sizeof(HardwareIdentifier) - 1);
		}

	};

	/*==========================================================================*/

	struct s_LogonResponse
	{
		unsigned short Size;
		unsigned short Type;
		int ProtocolVersion;
		LogonStatusEnum Result;
		char ErrorText[128];//Optional error text
		char  LogonText[256];//Optional text to provide the client upon logon.


		//Set this to 1 to indicate that you will only be sending market depth updates and not best bid and ask updates. 
		//The client will use depth at level 1 to update the best bid and ask prices.
		//Some Clients will maintain separate best bid and ask prices from market depth data.
		unsigned char MarketDepthUpdatesBestBidAndAsk;

		// Set this to 1 to indicate the server supports trading.  Otherwise, the Client will not send through any trading messages.
		unsigned char TradingIsSupported;

		//Set this to 1 to indicate the server supports OCO orders.
		unsigned char OCOOrdersSupported;

		//Be sure to set this to 0 if you do not support CANCEL_REPLACE_ORDER
		unsigned char OrderCancelReplaceSupported;


		// The Client will usually consider a Symbol as a single text string.
		// If there is a separate Exchange text string required, it could be combined with a Symbol using a format like this: Symbol-Exchange or Symbol.Exchange.
		// If your symbol format requires a separate Exchange text string, then specify the delimiter between the Symbol and the Exchange with this member.  
		// If this is left blank, the Exchange member in the structures in this header file, is not used.

		// Even if the symbols supported by a Server have an Exchange text string, does not mean that you have to use the Exchange member in the structures. 
		// You can simply combine the Symbol and the Exchange in security definition requests into the Symbol member or specify them as one text string in your documentation. Internally you can parse out the Exchange from the Symbol.
		char SymbolExchangeDelimiter[4];

		unsigned char SecurityDefinitionsSupported;

		unsigned char HistoricalPriceDataSupported;

		//Server address/IP number and optional port number to reconnect to. Format: [Server address: port number].  Only used if Result is set to LOGON_RECONNECT_NEW_ADDRESS
		char ReconnectAddress [64];

		s_LogonResponse()
		{

			memset(this, 0,sizeof(s_LogonResponse));
			Type=LOGON_RESPONSE;
			Size=sizeof(s_LogonResponse);
			ProtocolVersion = CURRENT_VERSION;
			OrderCancelReplaceSupported = 1;
		}

	};


	/*==========================================================================*/

	struct s_Heartbeat
	{
		unsigned short Size;
		unsigned short Type;

		s_Heartbeat()
		{
			memset(this, 0,sizeof(s_Heartbeat));
			Type=HEARTBEAT;
			Size=sizeof(s_Heartbeat);
		}

	};

	/*==========================================================================*/

	struct s_DisconnectFromServer
	{
		unsigned short Size;
		unsigned short Type;

		s_DisconnectFromServer()
		{
			memset(this, 0,sizeof(s_DisconnectFromServer));
			Type=DISCONNECT_FROM_SERVER_NO_RECONNECT;
			Size=sizeof(s_DisconnectFromServer);
		}

	};
	/*==========================================================================*/

	struct s_ServerReadyToReceive
	{
		unsigned short Size;
		unsigned short Type;
		char ServerName[25];//Optional free-form text for the Server to fill out if needed
		char ServerVersion[25];//Optional free-form text for the server to fill out
		char ServiceProviderName[25];//Optional free-form text for the server to fill out

		s_ServerReadyToReceive()
		{			
			memset(this, 0,sizeof(s_ServerReadyToReceive));
			Type=SERVER_READY_TO_RECEIVE;
			Size=sizeof(s_ServerReadyToReceive);

		}
	};

	/*==========================================================================*/

	struct s_ConfigurationRequestFromClient
	{
		unsigned short Size;
		unsigned short Type;

		s_ConfigurationRequestFromClient()
		{
			memset(this, 0,sizeof(s_ConfigurationRequestFromClient));
			Type=CONFIGURATION_REQUEST_FROM_CLIENT;
			Size=sizeof(s_ConfigurationRequestFromClient);
		}

	};
	/*==========================================================================*/

	struct s_MarketDataFeedStatus
	{
		unsigned short Size;
		unsigned short Type;
		MarketDataFeedStatusEnum Status;

		s_MarketDataFeedStatus()
		{

			memset(this, 0,sizeof(s_MarketDataFeedStatus));
			Type=MARKET_DATA_FEED_STATUS;
			Size=sizeof(s_MarketDataFeedStatus);
		}

	};

	/*==========================================================================*/

	struct s_MarketDataRequest
	{
		unsigned short Size;
		unsigned short Type;
		RequestActionEnum RequestActionValue;

		//This is the ID which will be used in all of the market data response structures.  This is so that the Symbol does not have to be passed back.
		//If you receive a market data request for a symbol to Subscribe to data that has already been subscribed to previously and this ID is different, then reject it (The Client should never do this).
		unsigned short MarketDataSymbolID;

		//This can be any format. Needs to be null-terminated. Not specified when unsubscribing.
		char Symbol[SYMBOL_LENGTH];

		//Optional.  Needs to be null-terminated.
		char Exchange[EXCHANGE_LENGTH];

		s_MarketDataRequest()
		{

			memset(this, 0,sizeof(s_MarketDataRequest));
			Type=MARKET_DATA_REQUEST;
			Size=sizeof(s_MarketDataRequest);
			RequestActionValue=SUBSCRIBE;
		}

	};

	/*==========================================================================*/

	struct s_MarketDepthRequest
	{
		unsigned short Size;
		unsigned short Type;

		RequestActionEnum RequestActionValue;

		//This is the ID which will be used in the market depth data response structure. This is so that the Symbol does not have to be passed back.
		unsigned short MarketDataSymbolID;

		char Symbol[SYMBOL_LENGTH];//This can be any format. Needs to be null-terminated.
		char Exchange[EXCHANGE_LENGTH];//Optional.  Needs to be null-terminated.
		int NumberOfLevels;  // Number of depth levels requested. Not set when unsubscribing.

		s_MarketDepthRequest()
		{

			memset(this, 0,sizeof(s_MarketDepthRequest));
			Type=MARKET_DEPTH_REQUEST;
			Size=sizeof(s_MarketDepthRequest);

			RequestActionValue=SUBSCRIBE;
			NumberOfLevels= 10;
		}

	};
	/*==========================================================================*/

	struct s_MarketDataReject
	{

		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;
		char RejectText[128];//Explanation for reject

		s_MarketDataReject()
		{
			memset(this, 0,sizeof(s_MarketDataReject));
			Type=MARKET_DATA_REJECT;
			Size=sizeof(s_MarketDataReject);
		}

	};
	/*==========================================================================*/

	struct s_MarketDataSnapshot
	{
		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;

		double SettlementPrice;
		double DailyOpen;
		double DailyHigh;
		double DailyLow;
		double LastTradePrice;
		unsigned int LastTradeSize;
		double DailyVolume;
		unsigned int DailyNumberOfTrades;

		//Can be any of the following: Futures open interest.  Shares outstanding for stocks.  Bitcoins outstanding
		unsigned int OpenInterest;

		double Bid;
		double Ask;
		unsigned int AskSize;
		unsigned int BidSize;

		t_DateTime LastTradeDateTimeUnix;
		short LastTradeMilliseconds;


		s_MarketDataSnapshot()
		{

			memset(this, 0,sizeof(s_MarketDataSnapshot));
			Type=MARKET_DATA_SNAPSHOT;
			Size=sizeof(s_MarketDataSnapshot);

		}


	};
	/*==========================================================================*/

	// Send after requesting market data for a symbol 
	struct s_FundamentalDataResponse
	{
		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;
		char SymbolDescription[64];
		float TickSize;
		float TickCurrencyValue;
		DisplayFormatEnum DisplayFormat;

		//For Forex trading
		float BuyRolloverInterest;
		float SellRolloverInterest;

		//Various stock fundamental data fields can be added here.  We will leave this to data providers which provide stock data.

		s_FundamentalDataResponse()
		{

			memset(this, 0,sizeof(s_FundamentalDataResponse));
			Type=FUNDAMENTAL_DATA_RESPONSE;
			Size=sizeof(s_FundamentalDataResponse);

		}


	};

	/*==========================================================================*/

	struct s_TradeIncrementalUpdateWithFullDepth
	{
		static const int NUM_DEPTH_LEVELS =10;
		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;

		BidOrAskEnum TradeAtBidOrAsk;//Indicator whether the trade occurred at the bid or ask.

		double Price;
		unsigned int TradeVolume;
		unsigned int TotalDailyVolume;
		t_DateTime4Byte TradeDateTimeUnix;
		short LastTradeMilliseconds;

		struct 
		{
			double Price;
			unsigned int Volume;
		}BidDepth[NUM_DEPTH_LEVELS], AskDepth[NUM_DEPTH_LEVELS];



		s_TradeIncrementalUpdateWithFullDepth()
		{
			memset(this, 0,sizeof(s_TradeIncrementalUpdateWithFullDepth));
			Type=TRADE_INCREMENTAL_UPDATE_WITH_FULL_DEPTH;
			Size=sizeof(s_TradeIncrementalUpdateWithFullDepth);

		}
		double GetPrice()
		{
			return Price;
		}
	};

	/*==========================================================================*/

	struct s_MarketDepthFullUpdate
	{
		static const int NUM_DEPTH_LEVELS =20;

		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;

		struct 
		{
			double Price;
			unsigned int Volume;
		}BidDepth[NUM_DEPTH_LEVELS], AskDepth[NUM_DEPTH_LEVELS];


		s_MarketDepthFullUpdate()
		{
			memset(this, 0,sizeof(s_MarketDepthFullUpdate));
			Type=MARKET_DEPTH_FULL_UPDATE;
			Size=sizeof(s_MarketDepthFullUpdate);

		}
	};

	/*==========================================================================*/

	struct s_MarketDepthFullUpdateLarge
	{
		static const int NUM_DEPTH_LEVELS = 100;

		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;

		struct 
		{
			double Price;
			unsigned int Volume;
		}BidDepth[NUM_DEPTH_LEVELS], AskDepth[NUM_DEPTH_LEVELS];


		s_MarketDepthFullUpdateLarge()
		{
			memset(this, 0,sizeof(s_MarketDepthFullUpdateLarge));
			Type=MARKET_DEPTH_FULL_UPDATE_LARGE;
			Size=sizeof(s_MarketDepthFullUpdateLarge);

		}

	};

	/*==========================================================================*/

	struct s_MarketDepthIncrementalUpdate
	{	 
		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;
		BidOrAskEnum Side;
		double Price;
		unsigned int Volume;

		MarketDepthIncrementalUpdateTypeEnum UpdateType;

		s_MarketDepthIncrementalUpdate()
		{

			memset(this, 0,sizeof(s_MarketDepthIncrementalUpdate));
			Type=MARKET_DEPTH_INCREMENTAL_UPDATE;
			Size=sizeof(s_MarketDepthIncrementalUpdate);

		}

	};

	/*==========================================================================*/

	struct s_TradeIncrementalUpdate
	{
		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;

		BidOrAskEnum TradeAtBidOrAsk;//Indicator whether the trade occurred at the bid or ask.

		double Price;
		unsigned int TradeVolume;
		unsigned int TotalDailyVolume;
		t_DateTime4Byte TradeDateTimeUnix;
		short LastTradeMilliseconds;

		s_TradeIncrementalUpdate()
		{
			memset(this, 0,sizeof(s_TradeIncrementalUpdate));
			Type=TRADE_INCREMENTAL_UPDATE;
			Size=sizeof(s_TradeIncrementalUpdate);

		}
		double GetPrice()
		{
			//if( (byte*)&Price - (byte*)this   > Size)// Check if member exists.
			//	return   0.0;
			return Price;
		}
	};

	/*==========================================================================*/

	struct s_QuoteIncrementalUpdate
	{
		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;

		double BidPrice;//Leave unset if there is no price available
		unsigned int BidSize;
		double AskPrice;//Leave unset if there is no price available
		unsigned int AskSize;
		t_DateTime4Byte QuoteDateTimeUnix;

		s_QuoteIncrementalUpdate()
		{

			memset(this, 0,sizeof(s_QuoteIncrementalUpdate));
			Type=QUOTE_INCREMENTAL_UPDATE;
			Size=sizeof(s_QuoteIncrementalUpdate);
			BidPrice=DBL_MAX;
			AskPrice=DBL_MAX;

		}
		double GetBidPrice()
		{
			if(BidPrice == DBL_MAX)
				return 0.0;
			else
				return BidPrice;
		}

		double GetAskPrice()
		{
			if(AskPrice == DBL_MAX)
				return 0.0;
			else
				return AskPrice;
		}
	};

	/*==========================================================================*/

	//struct s_DailyVolumeIncrementalUpdate
	//{
	//	unsigned short Size;
	//	unsigned short Type;

	//	unsigned short MarketDataSymbolID;
	//	double DailyVolume;//total daily volume

	//	s_DailyVolumeIncrementalUpdate()
	//	{

	//		memset(this, 0,sizeof(s_DailyVolumeIncrementalUpdate));
	//		Type=DAILY_VOLUME_INCREMENTAL_UPDATE;
	//		Size=sizeof(s_DailyVolumeIncrementalUpdate);

	//	}
	//};

	/*==========================================================================*/

	struct s_SubmitNewSingleOrder
	{

		unsigned short Size;
		unsigned short Type;

		char Symbol[SYMBOL_LENGTH];//This can be any format. Needs to be null-terminated.
		char Exchange[EXCHANGE_LENGTH];//Optional.  Needs to be null-terminated.

		//This client order ID must be sent back in the ORDER_UPDATE_REPORT message.  
		// After the first order report acknowledging acceptance of the order, it does not need to be provided any longer.
		char ClientOrderID[ORDER_ID_LENGTH];

		OrderTypeEnum OrderType;
		BuySellEnum BuySell;

		//For orders that require a price, this is the order price
		double Price1;

		//For Stop-Limit orders this is the Limit price.
		double Price2;

		TimeInForceEnum TimeInForce;
		t_DateTime GoodTillDateTimeUnix;
		unsigned int OrderQuantity;
		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		char IsAutomatedOrder; //set to 1 for automated trading orders

		char IsParentOrder;//Set to 1 to flag that this is a parent order and an OCO order containing the children will follow and be awaited for by the Server

		s_SubmitNewSingleOrder()
		{
			memset(this, 0,sizeof(s_SubmitNewSingleOrder));
			Type=SUBMIT_NEW_SINGLE_ORDER;
			Size=sizeof(s_SubmitNewSingleOrder);
		}

	};
	/*==========================================================================*/

	struct s_CancelReplaceOrder
	{

		unsigned short Size;
		unsigned short Type;

		char ServerOrderID[ORDER_ID_LENGTH];//Must be set
		char ClientOrderID[ORDER_ID_LENGTH];//Must be set

		//For orders that require a price, this is the order price
		double Price1;

		//For Stop-Limit orders this is the Limit price.
		double Price2;

		unsigned int OrderQuantity;

		s_CancelReplaceOrder()
		{

			memset(this, 0,sizeof(s_CancelReplaceOrder));
			Type=CANCEL_REPLACE_ORDER;
			Size=sizeof(s_CancelReplaceOrder);

		}

	};
	/*==========================================================================*/

	struct s_CancelOrder
	{

		unsigned short Size;
		unsigned short Type;

		
		char ServerOrderID[ORDER_ID_LENGTH];//Must be set
		char ClientOrderID[ORDER_ID_LENGTH];//Must be set

		s_CancelOrder()
		{

			memset(this, 0,sizeof(s_CancelOrder));
			Type=CANCEL_ORDER;
			Size=sizeof(s_CancelOrder);

		}

	};


	/*==========================================================================*/

	//Notes:

	// This is for submitting an order cancels order pair.  So when one order is filled are canceled, the other order will be canceled. If one order partially fills, the other order will be reduced in quantity by the fill amount of its sibling order.

	//A service provider must implement OCO orders on the server so that they can independently be modified (cancel/replace) and canceled independently using each orders distinct ServerOrderID.  If one of the orders is canceled though, the other order will be canceled unless they have a parent order ( bracket order), in which case the other order will remain working.

	// The ParentTriggerOrderID member allows the submission of a OCO order pair which has a parent.  (Bracket order).

	// When an OCO order is rejected,  the server needs to send a separate order report message for each of the orders in the OCO pair that was not accepted
	struct s_SubmitNewOCOOrder
	{
		unsigned short Size;
		unsigned short Type;

		char Symbol[SYMBOL_LENGTH];//This can be any format. Needs to be null-terminated.
		char Exchange[EXCHANGE_LENGTH];//Optional.  Needs to be null-terminated.

		char ClientOrderID_1[ORDER_ID_LENGTH];
		OrderTypeEnum OrderType_1;
		BuySellEnum BuySell_1;
		double Price1_1;
		double Price2_1;
		unsigned int OrderQuantity_1;

		char ClientOrderID_2[ORDER_ID_LENGTH];
		OrderTypeEnum OrderType_2;
		BuySellEnum BuySell_2;
		double Price1_2;
		double Price2_2;
		unsigned int OrderQuantity_2;

		TimeInForceEnum TimeInForce;
		t_DateTime GoodTillDateTimeUnix;

		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		char IsAutomatedOrder; //set to 1 for automated trading orders

		//This can be optionally set.  When this is set, the OCO order becomes a child of the specified parent order.  This parent order will have been submitted first.
		//What this means is that the OCO order pair does not become active until the parent is filled or partially filled.  When the parent is partially filled, then the quantities of the OCO orders, only increase to the filled quantity of the parent.
		// If this OCO order pair is submitted after the parent has filled, then this order will become immediately active.  The quantity of the OCO orders will be to the filled quantity of the parent.
		char ParentTriggerOrderID[ORDER_ID_LENGTH];

		s_SubmitNewOCOOrder()
		{
			memset(this, 0,sizeof(s_SubmitNewOCOOrder));
			Type=SUBMIT_NEW_OCO_ORDER;
			Size=sizeof(s_SubmitNewOCOOrder);

		}

	};


	/*==========================================================================*/

	struct s_RequestOpenOrders
	{
		unsigned short Size;
		unsigned short Type;


		int RequestID;

		int RequestAllOpenOrders;//0 = request a specific order, 1 = for all orders (default).
		char ServerOrderID[ORDER_ID_LENGTH];//Leave blank if want all orders.  Otherwise specified order ID.

		s_RequestOpenOrders()
		{

			memset(this, 0,sizeof(s_RequestOpenOrders));
			Type=OPEN_ORDERS_REQUEST;
			Size=sizeof(s_RequestOpenOrders);
			RequestAllOpenOrders = 1;
		}

	};
	/*==========================================================================*/

	struct s_RequestHistoricalOrderFills
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;

		char ServerOrderID[ORDER_ID_LENGTH];//Leave blank if want all order fills.  Otherwise, fills for given order ID

		// If this is 0, return all historical order fills available.  Otherwise, counting from the current day, return the number of days requested. 
		// This member can be ignored.
		int NumberOfDays;

		s_RequestHistoricalOrderFills()
		{
			memset(this, 0,sizeof(s_RequestHistoricalOrderFills));
			Type=REQUEST_HISTORICAL_ORDER_FILLS;
			Size=sizeof(s_RequestHistoricalOrderFills);

		}

	};
	/*==========================================================================*/
	//Will request open positions for all accounts
	struct s_CurrentPositionsRequest
	{
		unsigned short Size;
		unsigned short Type;
		int RequestID;

		s_CurrentPositionsRequest()
		{

			memset(this, 0,sizeof(s_CurrentPositionsRequest));
			Type=CURRENT_POSITIONS_REQUEST;
			Size=sizeof(s_CurrentPositionsRequest);

		}

	};
	/*==========================================================================*/
	struct s_CurrentPositionsRequestReject
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;
		char RejectText[128];//Reject reason

		s_CurrentPositionsRequestReject()
		{
			memset(this, 0,sizeof(s_CurrentPositionsRequestReject));
			Type=CURRENT_POSITIONS_REQUEST_REJECT;
			Size=sizeof(s_CurrentPositionsRequestReject);

		}

	};


	/*==========================================================================*/

	struct s_OrderUpdateReport
	{
		unsigned short Size;
		unsigned short Type;

		// 0 unless this is in response to a OPEN_ORDERS_REQUEST, in which case this must be set to the previously given RequestID
		// If this order report is unsolicited, for example a real-time fill, then leave this at zero.
		int RequestID;

		//This should only be set when the report is in response to OPEN_ORDERS_REQUEST.   This indicates the total number of order reports when a batch of reports is being sent. If there is only one order being sent, this will be 1.
		 int TotalNumberMessages;

		 //This should only be set when the report is in response to OPEN_ORDERS_REQUEST.  This indicates the 1-based index of the order report when a batch of reports is being sent. If there is only one order being sent, this will be 1.
		 int MessageNumber;

		char Symbol[SYMBOL_LENGTH];//This can be any format. Needs to be null-terminated.
		char Exchange[EXCHANGE_LENGTH];//Optional.  Needs to be null-terminated.

		//Used upon a cancel and replace operation (ET_CANCEL_REPLACE_COMPLETE) where a new order ID is given.  In which case this needs to be set to the previous order ID.
		char PreviousServerOrderID[ORDER_ID_LENGTH];

		//External trading service order ID.  When a new order is submitted and you respond with this report, this needs to be set to the order ID which is good for the life of the order. This Order ID can optionally change on a cancel and replace operation.
		char ServerOrderID[ORDER_ID_LENGTH];

		//Client provided order ID.  The Client relies upon this upon this ID member being set when a new order is accepted (Execution type: ET_NEW_ORDER_ACCEPTED).
		//After a new order has been accepted, the client will rely upon the given ServerOrderID from the server to identify the order and will no longer rely upon ClientOrderID
		char ClientOrderID[ORDER_ID_LENGTH];


		char ExchangeOrderID[ORDER_ID_LENGTH];//Optional exchange order ID

		//This must be set to indicate the current status of the order unless NoneOrder = 1.
		OrderStatusEnum OrderStatus;

		//This must be set.
		ExecutionTypeEnum ExecutionType;

		OrderTypeEnum OrderType;

		BuySellEnum BuySell;

		//For orders that require a price, this is the order price
		double Price1;

		//For Stop-Limit orders this is the Limit price.
		double Price2;

		TimeInForceEnum TimeInForce;
		t_DateTime GoodTillDateTimeUnix;
		unsigned int OrderQuantity;
		unsigned int FilledQuantity;
		unsigned int RemainingQuantity;
		double AverageFillPrice;

		double LastFillPrice;//Set only if ExecutionType is ET_FILLED or ET_PARTIAL_FILL
		t_DateTime LastFillDateTimeUnix;//Set only if ExecutionType is ET_FILLED or ET_PARTIAL_FILL
		unsigned int LastFillQuantity;//Set only if ExecutionType is ET_FILLED or ET_PARTIAL_FILL
		char UniqueFillExecutionID[64];//Set only if ExecutionType is ET_FILLED or ET_PARTIAL_FILL

		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		// Free-form text with information to communicate about the order. 
		char InfoText[128];

		char NoneOrders;//Set to 1 to indicate there are no orders when Open orders have been requested.  Otherwise, leave at the default of 0.

		s_OrderUpdateReport()
		{

			memset(this, 0,sizeof(s_OrderUpdateReport));
			Type=ORDER_UPDATE_REPORT;
			Size=sizeof(s_OrderUpdateReport);

			//The following initializations indicate to the Client that these variables are in an unset state and their values should not be used
			Price1 = DBL_MAX;
			Price2 = DBL_MAX; 

			OrderQuantity = UINT_MAX;
			FilledQuantity = UINT_MAX;
			RemainingQuantity = UINT_MAX;
			AverageFillPrice = DBL_MAX;

			LastFillPrice = DBL_MAX;
			LastFillQuantity = UINT_MAX;
		}

	};



	/*==========================================================================*/
	struct s_OpenOrdersRequestReject
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;
		char RejectText[128];//Reject reason

		s_OpenOrdersRequestReject()
		{
			memset(this, 0,sizeof(s_OpenOrdersRequestReject));
			Type=OPEN_ORDERS_REQUEST_REJECT;
			Size=sizeof(s_OpenOrdersRequestReject);

		}

	};


	/*==========================================================================*/

	struct s_HistoricalOrderFillReport
	{

		unsigned short Size;
		unsigned short Type;

		int RequestID; 
		
		//This indicates the total number of Order fill reports when a batch of reports is being sent. If there is only one Order fill report being sent, this will be 1.
		int TotalNumberMessages;

		//This indicates the 1-based index of the Order fill report when a batch of reports is being sent. If there is only one Order fill report being sent, this will be 1.
		int MessageNumber;

		char Symbol[SYMBOL_LENGTH];//This can be any format. Needs to be null-terminated.
		char Exchange[EXCHANGE_LENGTH];//Optional.  Needs to be null-terminated.
		char ServerOrderID[ORDER_ID_LENGTH];
		BuySellEnum BuySell;
		double FillPrice;
		t_DateTime FillDateTimeUnix;
		unsigned int FillQuantity;
		char UniqueFillExecutionID[64];
		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		OpenCloseTradeEnum OpenClose; 

		s_HistoricalOrderFillReport()
		{

			memset(this, 0,sizeof(s_HistoricalOrderFillReport));
			Type=HISTORICAL_ORDER_FILL_REPORT;
			Size=sizeof(s_HistoricalOrderFillReport);

		}

	};



	/*==========================================================================*/

	struct s_PositionReport
	{

		unsigned short Size;
		unsigned short Type;


		int RequestID;//0 of this is a real-time position update.  Otherwise, when sending back positions in response to CURRENT_POSITIONS_REQUEST, pass back the given RequestID

		//This should only be set when the report is in response to CURRENT_POSITIONS_REQUEST.   This indicates the total number of Position reports when a batch of reports is being sent. If there is only one Position report being sent, this will be 1.
		int TotalNumberMessages;

		//This should only be set when the report is in response to CURRENT_POSITIONS_REQUEST.  This indicates the 1-based index of the Position report when a batch of reports is being sent. If there is only one Position report being sent, this will be 1.
		int MessageNumber;

		char Symbol[SYMBOL_LENGTH];//This can be any format. Needs to be null-terminated.
		char Exchange[EXCHANGE_LENGTH];//Optional.  Needs to be null-terminated.

		int PositionQuantity;
		double AveragePrice;

		//The Client can optionally use this.  It is intended to identify an individual trade position in the case where there are multiple positions for a particular symbol.
		//Currently this protocol does not have any notion of hedging or multiple positions per symbol, however this is intended to allow support for that.
		char PositionIdentifier [ORDER_ID_LENGTH];

		char TradeAccount[TRADE_ACCOUNT_LENGTH];
		char NonePositions;//Set to 1 to indicate there are no Positions when there is a request for Positions.  Otherwise, leave at the default of 0.

		s_PositionReport()
		{

			memset(this, 0,sizeof(s_PositionReport));
			Type=POSITION_REPORT;
			Size=sizeof(s_PositionReport);

		}

	};


	/*==========================================================================*/
	//If there are no accounts available, then no need to respond to this.
	struct s_RequestAccounts
	{
		unsigned short Size;
		unsigned short Type;


		s_RequestAccounts()
		{

			memset(this, 0,sizeof(s_RequestAccounts));
			Type=REQUEST_ACCOUNTS;
			Size=sizeof(s_RequestAccounts);

		}

	};


	/*==========================================================================*/
	//Always be sure to set MessagePosition.
	struct s_AccountsListResponse
	{

		unsigned short Size;
		unsigned short Type;

		//This indicates the total number of Account list messages when a batch of messages is being sent. If there is only one message being sent, this will be 1.
		int TotalNumberMessages;

		//This indicates the 1-based index of the Account list message when a batch of messages is being sent. If there is only one message being sent, this will be 1.
		int MessageNumber;

		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		s_AccountsListResponse()
		{
			memset(this, 0,sizeof(s_AccountsListResponse));
			Type=ACCOUNTS_LIST_RESPONSE;
			Size=sizeof(s_AccountsListResponse);

		}

	};


	/*==========================================================================*/

	struct s_ExchangeListRequest
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;


		s_ExchangeListRequest()
		{

			memset(this, 0,sizeof(s_ExchangeListRequest));
			Type=EXCHANGE_LIST_REQUEST;
			Size=sizeof(s_ExchangeListRequest);
		}

	};

	/*==========================================================================*/
	//Server will return one of these for each Exchange supported.
	struct s_ExchangeListResponse
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;
		char Exchange [EXCHANGE_LENGTH];
		char FinalMessage;// 1 = final message in batch

		s_ExchangeListResponse()
		{

			memset(this, 0,sizeof(s_ExchangeListResponse));
			Type=EXCHANGE_LIST_RESPONSE;
			Size=sizeof(s_ExchangeListResponse);
		}

	};

	/*==========================================================================*/

	struct s_SymbolsForExchangeRequest
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;
		char Exchange[EXCHANGE_LENGTH];

		SecurityTypeEnum SecurityType;

		s_SymbolsForExchangeRequest()
		{

			memset(this, 0,sizeof(s_SymbolsForExchangeRequest));
			Type=SYMBOLS_FOR_EXCHANGE_REQUEST;
			Size=sizeof(s_SymbolsForExchangeRequest);
		}

	};

	/*==========================================================================*/

	struct s_UnderlyingSymbolsForExchangeRequest
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;

		char Exchange[EXCHANGE_LENGTH];

		SecurityTypeEnum SecurityType;

		s_UnderlyingSymbolsForExchangeRequest()
		{

			memset(this, 0,sizeof(s_UnderlyingSymbolsForExchangeRequest));
			Type=UNDERLYING_SYMBOLS_FOR_EXCHANGE_REQUEST;
			Size=sizeof(s_UnderlyingSymbolsForExchangeRequest);
		}

	};

	/*==========================================================================*/

	struct s_SymbolsForUnderlyingRequest
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;

		char UnderlyingSymbol[UNDERLYING_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		SecurityTypeEnum SecurityType;

		s_SymbolsForUnderlyingRequest()
		{

			memset(this, 0,sizeof(s_SymbolsForUnderlyingRequest));
			Type=SYMBOLS_FOR_UNDERLYING_REQUEST;
			Size=sizeof(s_SymbolsForUnderlyingRequest);
		}
	};
	/*==========================================================================*/

	struct s_SecurityDefinitionForSymbolRequest
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		SecurityTypeEnum SecurityType;

		s_SecurityDefinitionForSymbolRequest()
		{

			memset(this, 0,sizeof(s_SecurityDefinitionForSymbolRequest));
			Type=SECURITY_DEFINITION_FOR_SYMBOL_REQUEST;
			Size=sizeof(s_SecurityDefinitionForSymbolRequest);
		}

	};

	/*==========================================================================*/

	struct s_SymbolResponse
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;
		char Symbol[SYMBOL_LENGTH];//Can also contain an underlying symbol
		char Exchange[EXCHANGE_LENGTH];

		SecurityTypeEnum SecurityType;
		char FinalMessage;// 1 = final message in batch

		s_SymbolResponse()
		{

			memset(this, 0,sizeof(s_SymbolResponse));
			Type=SYMBOL_RESPONSE;
			Size=sizeof(s_SymbolResponse);
		}

	};
	/*==========================================================================*/

	struct s_SecurityDefinitionResponse
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;
		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		SecurityTypeEnum SecurityType;
		
		char SymbolDescription [64];
		float TickSize;
		DisplayFormatEnum PriceDisplayFormat;
		float TickCurrencyValue;

		char FinalMessage;// 1 = final message in batch

		s_SecurityDefinitionResponse()
		{

			memset(this, 0,sizeof(s_SecurityDefinitionResponse));
			Type=SECURITY_DEFINITION_RESPONSE;
			Size=sizeof(s_SecurityDefinitionResponse);
		}

	};


	/*==========================================================================*/

	struct s_AccountBalanceUpdate
	{

		unsigned short Size;
		unsigned short Type;

		//The current balance of the account if it were immediately liquidated
		double CurrentCashBalance;

		//The CurrentCashBalance minus the amount used for margin requirements for current positions
		double CurrentBalanceAvailableForNewPositions;

		char AccountCurrency[8]; //ISO Currency Code

		s_AccountBalanceUpdate()
		{
			memset(this, 0,sizeof(s_AccountBalanceUpdate));
			Type=ACCOUNT_BALANCE_UPDATE;
			Size=sizeof(s_AccountBalanceUpdate);
		}

	};
	/*==========================================================================*/

	struct s_UserMessage
	{
		unsigned short Size;
		unsigned short Type;

		//General message to present to user in the Client
		char UserMessage[256];

		s_UserMessage()
		{
			memset(this, 0,sizeof(s_UserMessage));
			Type=USER_MESSAGE;
			Size=sizeof(s_UserMessage);
		}

	};
	/*==========================================================================*/

	struct s_HistoricalPriceDataRequest
	{
		unsigned short Size;
		unsigned short Type;

		//Unique ID to identify this request
		int RequestIdentifier;
		char Symbol [SYMBOL_LENGTH];
		char Exchange [EXCHANGE_LENGTH];
		HistoricalDataIntervalEnum DataInterval;
		t_DateTime StartDateTime;
		t_DateTime EndDateTime;

		char  UseZLibCompression;

		// In the case of a stock, will request dividend adjusted data.   It is optional for the Server to support this.
		char DividendAdjustedStockData;

		s_HistoricalPriceDataRequest()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataRequest));
			Type=HISTORICAL_PRICE_DATA_REQUEST;
			Size=sizeof(s_HistoricalPriceDataRequest);
		}

	};

	/*==========================================================================*/

	struct s_HistoricalPriceDataHeaderResponse
	{
		unsigned short Size;
		unsigned short Type;
		int RequestIdentifier;
		HistoricalDataIntervalEnum DataInterval;

		// 1 =All subsequent messages are using ZLib compression.  0 = no compression.
		char RecordsUseZLibCompression;
		
		//If there are no records to return in response to the request and there was no error, this will be set to 1
		char NoRecordsToReturn;

		s_HistoricalPriceDataHeaderResponse()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataHeaderResponse));
			Type=HISTORICAL_PRICE_DATA_HEADER_RESPONSE;
			Size=sizeof(s_HistoricalPriceDataHeaderResponse);
		}

	};
	/*==========================================================================*/

	struct s_HistoricalPriceDataReject
	{
		unsigned short Size;
		unsigned short Type;
		int RequestIdentifier;//Original historical price data request identifier

		//Text reason for rejection
		char RejectText [128];

		s_HistoricalPriceDataReject()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataReject));
			Type=HISTORICAL_PRICE_DATA_REJECT;
			Size=sizeof(s_HistoricalPriceDataReject);
		}

	};

	/*==========================================================================*/

	struct s_HistoricalPriceDataRecordResponse
	{
		unsigned short Size;
		unsigned short Type;
		int RequestIdentifier;

		t_DateTime StartingDateTime;
		double Open;
		double High;
		double Low;
		double Last;
		unsigned  int Volume;
		union
		{
			unsigned int OpenInterest;
			unsigned int NumberTrades;
		};
		unsigned int BidVolume;
		unsigned int AskVolume;

		//1 = Final record in response to the request
		char FinalRecord;
		s_HistoricalPriceDataRecordResponse()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataRecordResponse));
			Type=HISTORICAL_PRICE_DATA_RECORD_RESPONSE;
			Size=sizeof(s_HistoricalPriceDataRecordResponse);
		}

	};

	/*==========================================================================*/
	//This is the response type when t_HistoricalDataInterval in a historical data request is set to INTERVAL_TICK
	struct s_HistoricalPriceDataTickRecordResponse
	{
		unsigned short Size;
		unsigned short Type;
		int RequestIdentifier;

		t_DateTime TradeDateTime;
		short Milliseconds;
		BidOrAskEnum BidOrAsk;

		double TradePrice;
		unsigned  int TradeVolume;

		//1 = Final record in response to the request
		char FinalRecord;

		s_HistoricalPriceDataTickRecordResponse()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataTickRecordResponse));
			Type=HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE;
			Size=sizeof(s_HistoricalPriceDataTickRecordResponse);
		}

	};

#pragma pack()
}
