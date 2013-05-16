//General Data and Trading Service Protocol (GSP)

//Client = Any application program supporting GSP. This can be a charting program, trading program, automated trading program.  A combination of these, or whatever.
//Server = Any service/program that provides Market Data and Trading functionality that follows this GSP protocol.

namespace GSP
{
#pragma pack(8)
	const int CURRENT_VERSION = 1;
	const int 	SYMBOL_LENGTH = 64;
	const int EXCHANGE_LENGTH= 32;

	//----Message types----
	const unsigned short LOGON_REQUEST=  1;//Client >> Server
	const unsigned short LOGON_RESPONSE =  2;//Server  >> Client

	//Each side sends each other a heartbeat at the interval specified by the HeartbeatIntervalInSeconds member in the LOGON_REQUEST
	const unsigned short HEARTBEAT =  3;//Client >> Server and Server  >> Client

	//If the server requires some time to accept messages from the client, send this when you are ready.  We will allow up to 3 seconds.
	const unsigned short SERVER_READY_TO_RECEIVE =  4;//Server  >> Client

	//This will be sent from the client to the server when a "Configuration Request" button is pressed in the Client.
	//It is intended to be used by a server executable program running on the local machine to display a configuration window.
	//Both the Client and Server can ignore this message if it is not required.
	const unsigned short CONFIGURATION_REQUEST_FROM_CLIENT = 5; //Client >> Server

	const unsigned short MARKET_DATA_FEED_STATUS = 100;//Server  >> Client

	//In response to this request, you can also return market depth data and not rely on MARKET_DEPTH_REQUEST
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

	// This should be returned in response to a MARKET_DATA_REQUEST, if the Server can provide data for at least one of the structure members.
	const unsigned short FUNDAMENTAL_DATA_SNAPSHOT = 110;//Server >> Client

	//This is a combination of TRADE_INCREMENTAL_UPDATE and MARKET_DEPTH_FULL_UPDATE (Only 10 levels)
	const unsigned short TRADE_INCREMENTAL_UPDATE_WITH_FULL_DEPTH = 111;//Server >> Client

	const unsigned short SUBMIT_NEW_SINGLE_ORDER = 200;//Client >> Server
	const unsigned short SUBMIT_NEW_OCO_ORDER = 201;//Client >> Server
	const unsigned short NEW_ORDER_REJECT = 202;//Server >> Client

	const unsigned short CANCEL_REPLACE_ORDER =  203;//Client >> Server
	const unsigned short CANCEL_REPLACE_ORDER_REJECT =   204;//Server >> Client

	const unsigned short CANCEL_ORDER = 205;//Client >> Server
	const unsigned short CANCEL_ORDER_REJECT = 206;//Server >> Client

	//Only return open orders in response to this request.  No need to return Canceled or Filled orders.  A separate message type can be added for that.
	//When responding to this request, respond with a separate ORDER_UPDATE_REPORT for each order.
	//When responding to this request, s_OrderUpdateReport::ExecutionType  needs to be set to ET_OPEN_ORDERS_REQUEST
	// If there are no open orders, send back 1 ORDER_UPDATE_REPORT with only the	MessagePosition, RequestID, ExecutionType, NoneOrders = 1 set in the s_OrderUpdateReport structure.
	const unsigned short OPEN_ORDERS_REQUEST = 300;//Client >> Server

	const unsigned short ORDER_UPDATE_REPORT = 301;//Server >> Client

	//If the Server is unable to serve the request for Open orders  for a reason other than there not being any Open orders, then use this message.
	const unsigned short OPEN_ORDERS_REQUEST_REJECT = 302;//Server >> Client

	//Return individual order fills / executions in response to this request.
	const unsigned short REQUEST_HISTORICAL_ORDER_FILLS = 302;//Client >> Server
	const unsigned short HISTORICAL_ORDER_FILL_REPORT = 303;//Server >> Client

	//This message type requests all of the current open Positions for all of the accounts on the logged in username.
	const unsigned short CURRENT_POSITIONS_REQUEST = 304;//Client >> Server

	// If there are no open Positions, send back 1 POSITION_REPORT with only the MessagePosition, RequestID, NonePositions = 1 set in the response structure.
	const unsigned short POSITION_REPORT = 305;//Server >> Client

	//If the Server is unable to serve the request for Positions for a reason other than there not being any Positions, then use this message.
	const unsigned short CURRENT_POSITIONS_REQUEST_REJECT = 306;//Server >> Client

	//Requests all of the account numbers for the logged in username
	const unsigned short REQUEST_ACCOUNTS = 400;//Client >> Server
	const unsigned short ACCOUNTS_LIST_RESPONSE=401;//Server >> Client

	const unsigned short SECURITY_DEFINITION_REQUEST = 500;//Client >> Server
	const unsigned short SECURITY_DEFINITION_RESPONSE =  501;//Server >> Client

	const unsigned short ACCOUNT_BALANCE_UPDATE = 600;//Server >> Client

	const unsigned short USER_MESSAGE = 700;//Server >> Client

	const unsigned short HISTORICAL_PRICE_DATA_REQUEST= 800;//Client >> Server
	const unsigned short HISTORICAL_PRICE_DATA_HEADER_RESPONSE = 801;//Server >> Client
	const unsigned short HISTORICAL_PRICE_DATA_REJECT = 802; //Server >> Client
	const unsigned short HISTORICAL_PRICE_DATA_RECORD_RESPONSE = 803;//Server >> Client
	const unsigned short HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE= 804; //Server >> Client

	/*==========================================================================*/
	//Standard UNIX date and time value
	typedef __int64 t_DateTime;

	/*==========================================================================*/

	typedef  int t_LogonStatus ;
	const t_LogonStatus LOGON_SUCCESS= 1;
	const t_LogonStatus LOGON_ERROR= 2;

	//You can use this logon status in the LOGON_RESPONSE message instruct the Client to reconnect to the Server at a different address.  This supports dynamic connections to a server farm.
	const t_LogonStatus LOGON_RECONNECT_NEW_ADDRESS= 3;

	/*==========================================================================*/
	typedef int t_MessageSupported;
	const t_MessageSupported MESSAGE_UNSUPPORTED= 0;
	const t_MessageSupported MESSAGE_SUPPORTED= 1;


	/*==========================================================================*/

	typedef  int t_TradeMode;
	const t_TradeMode TRADE_MODE_DEMO= 1;
	const t_TradeMode TRADE_MODE_SIMULATED= 2;
	const t_TradeMode TRADE_MODE_LIVE=3;


	/*==========================================================================*/

	typedef int t_RequestAction;
	const t_RequestAction SUBSCRIBE = 1;
	const t_RequestAction UNSUBSCRIBE = 2;


	/*==========================================================================*/

	typedef int t_OrderStatus;

	const t_OrderStatus ORDER_STATUS_UNSPECIFIED = 0 ;
	const t_OrderStatus ORDER_STATUS_ORDERSENT = 1;//When a Client sends an order to the Server, then the Client internally will set the status to Order Sent
	const t_OrderStatus ORDER_STATUS_PENDINGOPEN = 2 ;

	// This is meant to be used only on the Client side and indicates a child order part of a bracket order, is waiting to be sent when the parent fills.
	const t_OrderStatus ORDER_STATUS_PENDINGCHILD = 3 ;

	const t_OrderStatus ORDER_STATUS_OPEN = 4 ;
	const t_OrderStatus ORDER_STATUS_PENDING_CANCEL_REPLACE = 5 ;
	const t_OrderStatus ORDER_STATUS_PENDING_CANCEL = 6 ;
	const t_OrderStatus ORDER_STATUS_FILLED = 7 ;
	const t_OrderStatus ORDER_STATUS_CANCELED = 8 ;
	const t_OrderStatus ORDER_STATUS_REJECTED = 9 ;


	/*==========================================================================*/

	typedef int t_ExecutionType; 
	const t_ExecutionType ET_UNSET = 0;
	const t_ExecutionType ET_OPEN_ORDERS_REQUEST = 1;//Set this when the order is sent based on a OPEN_ORDERS_REQUEST request
	const t_ExecutionType ET_NEW_ORDER_ACCEPTED = 2;
	const t_ExecutionType ET_ORDER_UPDATE = 3;//A general order update.  For example, when an order is in the process of being canceled,  you can set the order status to indicate that the order is pending a cancellation.
	const t_ExecutionType ET_FILLED = 4;
	const t_ExecutionType ET_PARTIAL_FILL =5;
	const t_ExecutionType ET_CANCELED= 6;
	const t_ExecutionType ET_CANCEL_REPLACE_COMPLETE = 7;

	typedef unsigned short t_BidOrAsk;
	const t_BidOrAsk BID_ASK_UNSET = 0;
	const t_BidOrAsk AT_BID = 1;
	const t_BidOrAsk AT_ASK = 2;

	typedef unsigned char t_MarketDepthIncrementalUpdateType;
	const t_MarketDepthIncrementalUpdateType DEPTH_UNSET = 0;
	const t_MarketDepthIncrementalUpdateType DEPTH_INSERT_UPDATE = 1;//Insert or update depth at the given price level
	const t_MarketDepthIncrementalUpdateType DEPTH_DELETE = 2;//Delete depth at the given price level

	typedef int t_OrderType;
	const t_OrderType ORDER_TYPE_UNSET = 0; 
	const t_OrderType ORDER_TYPE_MARKET = 1;
	const t_OrderType ORDER_TYPE_LIMIT = 2;
	const t_OrderType ORDER_TYPE_STOP = 3;
	const t_OrderType ORDER_TYPE_STOP_LIMIT = 4;
	const t_OrderType ORDER_TYPE_MARKET_IF_TOUCHED = 5;

	typedef int t_TimeInForce;
	const t_TimeInForce TIF_UNSET = 0;
	const t_TimeInForce TIF_DAY = 1;
	const t_TimeInForce TIF_GTC = 2;
	const t_TimeInForce TIF_GOOD_TILL_DATE_TIME = 3;
	const t_TimeInForce TIF_IMMEDIATE_OR_CANCEL = 4;
	const t_TimeInForce TIF_ALL_OR_NONE = 5;
	const t_TimeInForce TIF_FILL_OR_KILL = 6;

	typedef int t_BuySell;
	const t_BuySell BUY_SELL_UNSET = 0;
	const t_BuySell BUY = 1;
	const t_BuySell SELL = 2;

	/*==========================================================================*/

	typedef int t_OpenCloseTrade;
	const t_OpenCloseTrade TRADE_UNSET =0;
	const t_OpenCloseTrade TRADE_OPEN = 1;
	const t_OpenCloseTrade TRADE_CLOSE = 2;

	/*==========================================================================*/

	//In the case where a message structure is sent unsolicited (Example: Realtime position update), then a variable of this type needs to be left at the default of UNSOLICITED_MESSAGE.
	typedef int t_FirstLastMessageInBatch;

	const t_FirstLastMessageInBatch UNSOLICITED_MESSAGE = 0;

	//In the case when a series of message structures is being returned in response to a particular request,
	//  this indicates it is the first message.
	const t_FirstLastMessageInBatch FIRST_MESSAGE = 1;

	//In the case when a series of message structures is being returned in response to a particular request,
	// this indicates it is the last message.
	const t_FirstLastMessageInBatch LAST_MESSAGE = 2;

	//  In the case when there is only a single message being returned in response to a particular request, use this.
	const t_FirstLastMessageInBatch SINGLE_MESSAGE = 3;


	/*==========================================================================*/
	// These statuses apply to all  symbols that have been subscribed to.
	typedef int t_MarketDataFeedStatus;
	const t_OpenCloseTrade MARKET_DATA_FEED_LOST = 1;

	//  Upon a connection to the server, this is assumed to be the status.  It is not until there has been expressly given MARKET_DATA_FEED_LOST, will the data feed be considered lost.
	const t_OpenCloseTrade MARKET_DATA_FEED_RESTORED  = 2;


	/*==========================================================================*/

	typedef int t_DisplayFormat;
	const t_DisplayFormat  DISPLAY_FORMAT_DENOMINATOR_256 = 356;
	const t_DisplayFormat  DISPLAY_FORMAT_DENOMINATOR_128 = 228;
	const t_DisplayFormat  DISPLAY_FORMAT_DENOMINATOR_64 = 164;
	const t_DisplayFormat  DISPLAY_FORMAT_DENOMINATOR_32 = 132;//This also supports .25 and .5 32nds
	const t_DisplayFormat  DISPLAY_FORMAT_DENOMINATOR_16 = 116;
	const t_DisplayFormat  DISPLAY_FORMAT_DENOMINATOR_8 =108;
	const t_DisplayFormat  DISPLAY_FORMAT_DENOMINATOR_4 = 104;
	const t_DisplayFormat  DISPLAY_FORMAT_DENOMINATOR_2 =  102;

	//The following formats indicate the number of decimal places to be displayed
	const t_DisplayFormat  DISPLAY_FORMAT_DECIMAL_0= 0;
	const t_DisplayFormat  DISPLAY_FORMAT_DECIMAL_1= 1;
	const t_DisplayFormat  DISPLAY_FORMAT_DECIMAL_2= 2;
	const t_DisplayFormat  DISPLAY_FORMAT_DECIMAL_3= 3;
	const t_DisplayFormat  DISPLAY_FORMAT_DECIMAL_4= 4;
	const t_DisplayFormat  DISPLAY_FORMAT_DECIMAL_5= 5;
	const t_DisplayFormat  DISPLAY_FORMAT_DECIMAL_6= 6;
	const t_DisplayFormat  DISPLAY_FORMAT_DECIMAL_7= 7;
	const t_DisplayFormat  DISPLAY_FORMAT_DECIMAL_8= 8;
	const t_DisplayFormat  DISPLAY_FORMAT_DECIMAL_9= 9;

	/*==========================================================================*/

	typedef int t_SecurityType ;
	const t_SecurityType ST_UNSET = 0;
	const t_SecurityType ST_FUTURE = 1;
	const t_SecurityType ST_STOCK = 2;
	const t_SecurityType ST_FOREX = 3;//Bitcoins also go into this category
	const t_SecurityType ST_OPTION = 4;
	const t_SecurityType ST_INDEX = 5;
	const t_SecurityType ST_FUTURES_STRATEGY = 6;


	typedef  int t_HistoricalDataInterval ;
	const t_HistoricalDataInterval INTERVAL_TICK= 0;
	const t_HistoricalDataInterval INTERVAL_1_SECOND= 1;
	const t_HistoricalDataInterval INTERVAL_2_SECONDS= 2;
	const t_HistoricalDataInterval INTERVAL_5_SECONDS=  5;
	const t_HistoricalDataInterval INTERVAL_10_SECONDS=  10;
	const t_HistoricalDataInterval INTERVAL_30_SECONDS= 30;
	const t_HistoricalDataInterval INTERVAL_1_MINUTE= 60;
	const t_HistoricalDataInterval INTERVAL_1_DAY=86400;

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

		char  GeneralTextData[64];//Optional
		int Integer_1;//Optional.  General-purpose integer.
		int Integer_2;//Optional.  General-purpose integer.

		int  HeartbeatIntervalInSeconds; 

		//Optional: To indicate Demo, Simulated, Live
		t_TradeMode TradeMode;

		//This should only be set to a trade account identifier if that is required to login.  
		//Usually this would be the case if the log in is bound to a particular account and not changeable after the log in.
		//Otherwise, this should be blank and Client will discover the accounts through an account list request.
		char TradeAccount[32];

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
			//if( (byte*)&Username - (byte*)this   > Size)// Check if member exists. This is not necessary in this case.  Only an example.
			//return   "";

			return Username;
		}

		void SetUsername(const char * NewValue)
		{
			strncpy(Username, NewValue, sizeof(Username) - 1);
		}

		int GetInteger_1()
		{
			return Integer_1;
		}

		void SetInteger_1(int NewValue)
		{
			Integer_1 = NewValue;
		}
	};

	/*==========================================================================*/

	struct s_LogonResponse
	{
		unsigned short Size;
		unsigned short Type;
		int ProtocolVersion;
		t_LogonStatus  Result;
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

	struct s_ServerReadyToReceive
	{
		unsigned short Size;
		unsigned short Type;

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
		t_MarketDataFeedStatus Status;

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
		t_RequestAction RequestActionValue;

		//This is the ID which will be used in all of the market data response structures.  This is so that the Symbol does not have to be passed back.
		//If you receive a market data request for a symbol to Subscribe to data that has already been subscribed to previously and this ID is different, then reject it (The Client should never do this).
		unsigned short MarketDataSymbolID;

		//This can be any format. Needs to be null-terminated. Not specified when unsubscribing.
		char Symbol[SYMBOL_LENGTH];

		//Optional.  Needs to be null-terminated.
		char Exchange[32];

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

		t_RequestAction RequestActionValue;

		//This is the ID which will be used in the market depth data response structure. This is so that the Symbol does not have to be passed back.
		unsigned short MarketDataSymbolID;

		char Symbol[SYMBOL_LENGTH];//This can be any format. Needs to be null-terminated.
		char Exchange[32];//Optional.  Needs to be null-terminated.
		int NumberOfLevels;  // Not set when unsubscribing.

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
	struct s_FundamentalDataSnapshot
	{
		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;
		char SymbolDescription[64];
		float TickSize;
		float TickCurrencyValue;
		t_DisplayFormat DisplayFormat;

		//For Forex trading
		float BuyRolloverInterest;
		float SellRolloverInterest;

		//Various stock fundamental data fields can be added here.  We will leave this to data providers which provide stock data.

		s_FundamentalDataSnapshot()
		{

			memset(this, 0,sizeof(s_FundamentalDataSnapshot));
			Type=FUNDAMENTAL_DATA_SNAPSHOT;
			Size=sizeof(s_FundamentalDataSnapshot);

		}


	};

	/*==========================================================================*/

	struct s_TradeIncrementalUpdateWithFullDepth
	{
		static const int NUM_DEPTH_LEVELS =10;
		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;

		t_BidOrAsk TradeAtBidOrAsk;//Indicator whether the trade occurred at the bid or ask.

		double Price;
		unsigned int TradeVolume;
		unsigned int TotalDailyVolume;
		unsigned int TradeDateTimeUnix;
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
		t_BidOrAsk Side;
		double Price;
		unsigned int Volume;

		t_MarketDepthIncrementalUpdateType UpdateType;

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

		t_BidOrAsk TradeAtBidOrAsk;//Indicator whether the trade occurred at the bid or ask.

		double Price;
		unsigned int TradeVolume;
		unsigned int TotalDailyVolume;
		unsigned int TradeDateTimeUnix;
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
		unsigned int QuoteDateTimeUnix;

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
		char Exchange[32];//Optional.  Needs to be null-terminated.

		//This client order ID must be sent back in the ORDER_UPDATE_REPORT message.  
		// After the first order report acknowledging acceptance of the order, it does not need to be provided any longer.
		char ClientOrderID[32];

		t_OrderType OrderType;
		t_BuySell BuySell;

		//For orders that require a price, this is the order price
		double Price1;

		//For Stop-Limit orders this is the Limit price.
		double Price2;

		t_TimeInForce TimeInForce;
		t_DateTime GoodTillDateTimeUnix;
		unsigned int OrderQuantity;
		char TradeAccount[32];

		char IsAutomatedOrder; //set to 1 for automated trading orders

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

		char OrderID[32];

		double Price1;
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

		char OrderID[32];

		s_CancelOrder()
		{

			memset(this, 0,sizeof(s_CancelOrder));
			Type=CANCEL_ORDER;
			Size=sizeof(s_CancelOrder);

		}

	};
	/*==========================================================================*/

	struct s_CancelOrderReject
	{

		unsigned short Size;
		unsigned short Type;


		char OrderID[32];
		t_OrderStatus OrderStatus;
		char RejectText[128];//Explanation for reject

		s_CancelOrderReject()
		{

			memset(this, 0,sizeof(s_CancelOrderReject));
			Type=CANCEL_ORDER_REJECT;
			Size=sizeof(s_CancelOrderReject);
			OrderStatus = ORDER_STATUS_UNSPECIFIED;
		}

	};
	/*==========================================================================*/

	struct s_CancelReplaceOrderReject
	{

		unsigned short Size;
		unsigned short Type;

		char OrderID[32];
		t_OrderStatus OrderStatus;
		char RejectText[128];//Explanation for reject

		s_CancelReplaceOrderReject()
		{
			memset(this, 0,sizeof(s_CancelReplaceOrderReject));
			Type=CANCEL_REPLACE_ORDER_REJECT;
			Size=sizeof(s_CancelReplaceOrderReject);

		}

	};

	/*==========================================================================*/
	// When an OCO order is rejected, need to send a separate NEW_ORDER_REJECT message for each of the orders in the OCO pair that was not accepted
	struct s_SubmitNewOCOOrder
	{
		unsigned short Size;
		unsigned short Type;

		char Symbol[SYMBOL_LENGTH];//This can be any format. Needs to be null-terminated.
		char Exchange[32];//Optional.  Needs to be null-terminated.

		char ClientOrderID_1[32];
		t_OrderType OrderType_1;
		t_BuySell BuySell_1;
		double Price1_1;
		double Price2_1;
		unsigned int OrderQuantity_1;

		char ClientOrderID_2[32];
		t_OrderType OrderType_2;
		t_BuySell BuySell_2;
		double Price1_2;
		double Price2_2;
		unsigned int OrderQuantity_2;

		t_TimeInForce TimeInForce;
		t_DateTime GoodTillDateTimeUnix;

		char TradeAccount[32];

		char IsAutomatedOrder; //set to 1 for automated trading orders


		s_SubmitNewOCOOrder()
		{
			memset(this, 0,sizeof(s_SubmitNewOCOOrder));
			Type=SUBMIT_NEW_OCO_ORDER;
			Size=sizeof(s_SubmitNewOCOOrder);

		}

	};

	/*==========================================================================*/

	struct s_NewOrderReject
	{

		unsigned short Size;
		unsigned short Type;

		char ClientOrderID [32];
		char RejectText[128];//Explanation for reject

		s_NewOrderReject()
		{
			memset(this, 0,sizeof(s_NewOrderReject));
			Type=NEW_ORDER_REJECT;
			Size=sizeof(s_NewOrderReject);

		}

	};

	/*==========================================================================*/

	struct s_RequestOpenOrders
	{
		unsigned short Size;
		unsigned short Type;


		int RequestID;

		int RequestAllOpenOrders;//0 = request a specific order, 1 = for all orders.
		char OrderID[32];//Leave blank if want all orders.  Otherwise specified order ID.

		s_RequestOpenOrders()
		{

			memset(this, 0,sizeof(s_RequestOpenOrders));
			Type=OPEN_ORDERS_REQUEST;
			Size=sizeof(s_RequestOpenOrders);

		}

	};
	/*==========================================================================*/

	struct s_RequestHistoricalOrderFills
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;

		char OrderID[32];//Leave blank if want all order fills.  Otherwise, fills for given order ID

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

		int RequestID;//0 unless this is in response to a OPEN_ORDERS_REQUEST, in which case pass back the given RequestID
		t_FirstLastMessageInBatch MessagePosition;

		char Symbol[SYMBOL_LENGTH];//This can be any format. Needs to be null-terminated.
		char Exchange[32];//Optional.  Needs to be null-terminated.

		//Used upon a cancel and replace operation (ET_CANCEL_REPLACE_COMPLETE) where a new order ID is given.  In which case this needs to be set to the previous order ID.
		char PreviousOrderID[32];

		//External trading service order ID.  When a new order is submitted and you respond with this report, this needs to be set to the order ID which is good for the life of the order. This Order ID can optionally change on a cancel and replace operation.
		char OrderID[32];

		//Client provided order ID.  The Client relies upon this upon this ID member being set when a new order is accepted (Execution type: ET_NEW_ORDER_ACCEPTED).
		//After a new order has been accepted, the client will rely upon the given OrderID from the server to identify the order and will no longer rely upon ClientOrderID
		char ClientOrderID[32];

		t_OrderStatus OrderStatus;
		t_ExecutionType ExecutionType;
		t_OrderType OrderType;

		t_BuySell BuySell;
		double Price1;
		double Price2;

		t_TimeInForce TimeInForce;
		t_DateTime GoodTillDateTimeUnix;
		unsigned int OrderQuantity;
		unsigned int FilledQuantity;
		unsigned int RemainingQuantity;
		double AverageFillPrice;

		double LastFillPrice;//Set only if ExecutionType is ET_FILLED or ET_PARTIAL_FILL
		t_DateTime LastFillDateTimeUnix;//Set only if ExecutionType is ET_FILLED or ET_PARTIAL_FILL
		unsigned int LastFillQuantity;//Set only if ExecutionType is ET_FILLED or ET_PARTIAL_FILL
		char UniqueFillExecutionID[64];//Set only if ExecutionType is ET_FILLED or ET_PARTIAL_FILL

		char TradeAccount[32];

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
		t_FirstLastMessageInBatch MessagePosition;
		char Symbol[SYMBOL_LENGTH];//This can be any format. Needs to be null-terminated.
		char Exchange[32];//Optional.  Needs to be null-terminated.
		char OrderID[32];
		t_BuySell BuySell;
		double FillPrice;
		t_DateTime FillDateTimeUnix;
		unsigned int FillQuantity;
		char UniqueFillExecutionID[64];
		char TradeAccount[32];

		t_OpenCloseTrade OpenClose; 

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

		t_FirstLastMessageInBatch MessagePosition;

		char Symbol[SYMBOL_LENGTH];//This can be any format. Needs to be null-terminated.
		char Exchange[32];//Optional.  Needs to be null-terminated.

		int PositionQuantity;
		double AveragePrice;

		//The Client can optionally use this.  It is intended to identify an individual trade position in the case where there are multiple positions for a particular symbol.
		//Currently this protocol does not have any notion of hedging or multiple positions per symbol, however this is intended to allow support for that.
		char PositionIdentifier [32];

		char TradeAccount[32];
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

		t_FirstLastMessageInBatch MessagePosition;
		char TradeAccount[32];

		s_AccountsListResponse()
		{
			memset(this, 0,sizeof(s_AccountsListResponse));
			Type=ACCOUNTS_LIST_RESPONSE;
			Size=sizeof(s_AccountsListResponse);

		}

	};

	/*==========================================================================*/

	struct s_SecurityDefinitionRequest
	{
		unsigned short Size;
		unsigned short Type;

		//This can be any format. Needs to be null-terminated. If this is not specified, return all symbols supported.
		char Symbol[SYMBOL_LENGTH];

		//Optional.  Needs to be null-terminated.
		char Exchange[32];

		//Optional. In the case where a request wants to get all of the options, futures contracts or strategies for a particular underlying symbol, this will be set with the underlying symbol.
		char UnderlyingSymbol [32];

		t_SecurityType SecurityType;

		s_SecurityDefinitionRequest()
		{

			memset(this, 0,sizeof(s_SecurityDefinitionRequest));
			Type=SECURITY_DEFINITION_REQUEST;
			Size=sizeof(s_SecurityDefinitionRequest);
		}

	};
	/*==========================================================================*/

	struct s_SecurityDefinitionResponse
	{
		unsigned short Size;
		unsigned short Type;

		t_FirstLastMessageInBatch MessagePosition;

		//This can be any format. Needs to be null-terminated. 
		char Symbol[SYMBOL_LENGTH];

		//Optional.  Needs to be null-terminated.
		char Exchange[32];

		char SymbolDescription [64];
		float TickSize;
		t_DisplayFormat PriceDisplayFormat;
		float TickCurrencyValue;
		t_SecurityType SecurityType;

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

		char AccountCurrency[16]; //ISO Currency Code

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
		char Exchange [32];
		t_HistoricalDataInterval DataInterval;
		t_DateTime StartDateTime;
		t_DateTime EndDateTime;

		char  UseZLibCompression;

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
		t_HistoricalDataInterval DataInterval;

		// 1 =All subsequent messages are using ZLib compression.  0 = no compression.
		char RecordsUseZLibCompression;

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
		t_FirstLastMessageInBatch MessagePosition;
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
		t_FirstLastMessageInBatch MessagePosition;
		int RequestIdentifier;

		t_DateTime StartingDateTime;
		short Milliseconds;
		t_BidOrAsk BidOrAsk;

		double TradePrice;
		unsigned  int TradeVolume;

		s_HistoricalPriceDataTickRecordResponse()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataTickRecordResponse));
			Type=HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE;
			Size=sizeof(s_HistoricalPriceDataTickRecordResponse);
		}

	};

#pragma pack()
}
