//General Data and Trading Service Protocol (GSP)

//Documentation: http://www.sierrachart.com/index.php?file=doc/doc_GSPMessageDocumentation.php

#pragma once

namespace GSP
{
#pragma pack(8)

	const int CURRENT_VERSION = 2;
	const int SYMBOL_LENGTH = 64;
	const int EXCHANGE_LENGTH= 16;
	const int UNDERLYING_LENGTH= 32;
	const int SYMBOL_DESCRIPTION_LENGTH = 48;
	const int ORDER_ID_LENGTH = 32;
	const int TRADE_ACCOUNT_LENGTH = 32;
	const int TEXT_DESCRIPTION_LENGTH = 96;

	//----Message types----
	const unsigned short LOGON_REQUEST = 1;

	const unsigned short LOGON_RESPONSE = 2;

	const unsigned short HEARTBEAT = 3;

	const unsigned short DISCONNECT_FROM_SERVER_NO_RECONNECT = 4;

	const unsigned short MARKET_DATA_FEED_STATUS = 100;

	const unsigned short MARKET_DATA_REQUEST = 101;

	const unsigned short MARKET_DEPTH_REQUEST = 102;

	const unsigned short MARKET_DATA_REJECT = 103;

	const unsigned short MARKET_DATA_SNAPSHOT = 104;

	const unsigned short MARKET_DEPTH_FULL_UPDATE = 105;

	const unsigned short MARKET_DEPTH_INCREMENTAL_UPDATE = 106;

	const unsigned short TRADE_INCREMENTAL_UPDATE = 107;

	const unsigned short QUOTE_INCREMENTAL_UPDATE = 108;

	const unsigned short MARKET_DEPTH_FULL_UPDATE_LARGE = 109;

	const unsigned short FUNDAMENTAL_DATA_RESPONSE = 110;

	const unsigned short TRADE_INCREMENTAL_UPDATE_WITH_FULL_DEPTH = 111;

	const unsigned short TRADE_INCREMENTAL_UPDATE_COMPACT = 112;

	const unsigned short DAILY_VOLUME_INCREMENTAL_UPDATE = 113;

	const unsigned short DAILY_HIGH_INCREMENTAL_UPDATE = 114;

	const unsigned short DAILY_LOW_INCREMENTAL_UPDATE = 115;

	const unsigned short MARKET_DATA_FEED_SYMBOL_STATUS = 116;

	const unsigned short SUBMIT_NEW_SINGLE_ORDER = 200;

	const unsigned short SUBMIT_NEW_OCO_ORDER = 201;

	const unsigned short CANCEL_REPLACE_ORDER = 202;

	const unsigned short CANCEL_ORDER = 203;

	const unsigned short CANCEL_REPLACE_ORDER_2 = 204;

	const unsigned short OPEN_ORDERS_REQUEST = 300;

	const unsigned short ORDER_UPDATE_REPORT = 301;

	const unsigned short OPEN_ORDERS_REQUEST_REJECT = 302;

	const unsigned short REQUEST_HISTORICAL_ORDER_FILLS = 303;

	const unsigned short HISTORICAL_ORDER_FILL_REPORT = 304;

	const unsigned short CURRENT_POSITIONS_REQUEST = 305;

	const unsigned short POSITION_REPORT = 306;

	const unsigned short CURRENT_POSITIONS_REQUEST_REJECT = 307;

	const unsigned short REQUEST_ACCOUNTS = 400;

	const unsigned short ACCOUNTS_LIST_RESPONSE = 401;

	const unsigned short EXCHANGE_LIST_REQUEST = 500;

	const unsigned short EXCHANGE_LIST_RESPONSE = 501;

	const unsigned short SYMBOLS_FOR_EXCHANGE_REQUEST = 502;

	const unsigned short UNDERLYING_SYMBOLS_FOR_EXCHANGE_REQUEST = 503;

	const unsigned short SYMBOLS_FOR_UNDERLYING_REQUEST = 504;

	//const unsigned short SYMBOL_RESPONSE = 505;

	const unsigned short SECURITY_DEFINITION_FOR_SYMBOL_REQUEST = 506;

	const unsigned short SECURITY_DEFINITION_RESPONSE = 507;

	const unsigned short ACCOUNT_BALANCE_UPDATE = 600;

	const unsigned short USER_MESSAGE = 700;

	const unsigned short GENERAL_LOG_MESSAGE = 701;

	const unsigned short HISTORICAL_PRICE_DATA_REQUEST= 800;

	const unsigned short HISTORICAL_PRICE_DATA_HEADER_RESPONSE = 801;

	const unsigned short HISTORICAL_PRICE_DATA_REJECT = 802;

	const unsigned short HISTORICAL_PRICE_DATA_RECORD_RESPONSE = 803;

	const unsigned short HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE = 804;

	/*==========================================================================*/
	//Nonstandard messages which are not considered part of the standard specification.  A standard GSP server and client do not need to implement these.
	//----------------------------------------------

	const unsigned short CONFIGURATION_REQUEST_FROM_CLIENT = 10001; //Client >> Server

	const unsigned short SERVER_READY_TO_RECEIVE =  10002;//Server  >> Client


	/*==========================================================================*/
	//Standard UNIX date and time value
	typedef __int64 t_DateTime;

	// This is a 4 byte DateTime value used in messages where compactness is an important consideration.
	typedef unsigned int t_DateTime4Byte;

	/*==========================================================================*/
	enum LogonStatusEnum : int
	{ LOGON_SUCCESS = 1
	, LOGON_ERROR = 2
	, LOGON_ERROR_NO_RECONNECT = 3

	//You can use this logon status in the LOGON_RESPONSE message instruct the Client to reconnect to the Server at a different address.  This supports dynamic connections to a server farm.
	, LOGON_RECONNECT_NEW_ADDRESS = 4
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
	{ ORDER_STATUS_UNSPECIFIED = 0
	, ORDER_STATUS_ORDERSENT = 1
	, ORDER_STATUS_PENDINGOPEN = 2
	, ORDER_STATUS_PENDINGCHILD = 3
	, ORDER_STATUS_OPEN = 4
	, ORDER_STATUS_PENDING_CANCEL_REPLACE = 5
	, ORDER_STATUS_PENDING_CANCEL = 6
	, ORDER_STATUS_FILLED = 7
	, ORDER_STATUS_CANCELED = 8
	, ORDER_STATUS_REJECTED = 9
	};

	/*==========================================================================*/
	enum ExecutionTypeEnum : int

	{ ET_UNSET = 0
	, ET_OPEN_ORDERS_REQUEST = 1
	, ET_NEW_ORDER_ACCEPTED = 2
	, ET_ORDER_UPDATE = 3
	, ET_FILLED = 4
	, ET_PARTIAL_FILL = 5
	, ET_CANCELED = 6
	, ET_CANCEL_REPLACE_COMPLETE = 7
	, ET_NEW_ORDER_REJECT = 8
	, ET_ORDER_CANCEL_REJECT = 9
	, ET_ORDER_CANCEL_REPLACE_REJECT = 10
	};


	enum BidOrAskEnum : unsigned short
	{ BID_ASK_UNSET = 0
	, AT_BID = 1
	, AT_ASK = 2
	};

	enum MarketDepthIncrementalUpdateTypeEnum : unsigned char
	{ DEPTH_UNSET = 0
	, DEPTH_INSERT_UPDATE = 1 // Insert or update depth at the given price level
	, DEPTH_DELETE = 2 // Delete depth at the given price level
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
	, TIF_GOOD_TILL_CANCELED = 2
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

	// Upon a connection to the server, this is assumed to be the status.  It is not until there has been expressly given MARKET_DATA_FEED_LOST, will the data feed be considered lost. The Client will resubscribe to all symbols using MARKET_DATA_REQUEST messages, when this status is received and.
	, MARKET_DATA_FEED_RESTORED = 2
	};

	/*==========================================================================*/
	enum DisplayFormatEnum : int
	{ DISPLAY_FORMAT_UNSET =  -1
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

	//The following formats are fractional formats
	, DISPLAY_FORMAT_DENOMINATOR_256 = 356
	, DISPLAY_FORMAT_DENOMINATOR_128 = 228
	, DISPLAY_FORMAT_DENOMINATOR_64 = 164
	, DISPLAY_FORMAT_DENOMINATOR_32_QUARTERS = 136
	, DISPLAY_FORMAT_DENOMINATOR_32_HALVES = 134
	, DISPLAY_FORMAT_DENOMINATOR_32 = 132 
	, DISPLAY_FORMAT_DENOMINATOR_16 = 116
	, DISPLAY_FORMAT_DENOMINATOR_8 = 108
	, DISPLAY_FORMAT_DENOMINATOR_4 = 104
	, DISPLAY_FORMAT_DENOMINATOR_2 = 102
	};

	/*==========================================================================*/
	enum SecurityTypeEnum : int
	{ ST_UNSET = 0
	, ST_FUTURE = 1
	, ST_STOCK = 2
	, ST_FOREX = 3 // Bitcoins also go into this category
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

		char  Username[32];
		char Password[32];

		char  GeneralTextData[64];

		int Integer_1;
		int Integer_2;

		int  HeartbeatIntervalInSeconds; 

		TradeModeEnum TradeMode;

		char TradeAccount[TRADE_ACCOUNT_LENGTH];
 
		char HardwareIdentifier[64];

		char ClientName[32];

		s_LogonRequest()
		{
			memset(this, 0,sizeof(s_LogonRequest));
			Type=LOGON_REQUEST;
			Size=sizeof(s_LogonRequest);
			ProtocolVersion = CURRENT_VERSION;
		}

		// The following functions are only for convenience.  They are not required to be used.  You can directly access the structure data members.
		
		unsigned short GetMessageSize();
		void CopyFrom(void * p_SourceData);
		
		int GetProtocolVersion();
		const char * GetUsername();
		void SetUsername(const char * NewValue);
		char * GetPassword();
		void SetPassword(const char * NewValue);
		char * GetGeneralTextData();
		void SetGeneralTextData(const char * NewValue);
		int GetInteger_1();
		void SetInteger_1(int NewValue);
		int GetInteger_2();
		void SetInteger_2(int NewValue);
		int GetInHeartbeatIntervalInSeconds();
		void SetHeartbeatIntervalInSeconds(int NewValue);
		TradeModeEnum GetTradeMode();
		void SetTradeMode(TradeModeEnum NewValue);
		char * GetTradeAccount();
		void SetTradeAccount(const char * NewValue);
		char * GetHardwareIdentifier();
		void SetHardwareIdentifier(const char * NewValue);

	};

	/*==========================================================================*/
	struct s_LogonResponse
	{
		unsigned short Size;
		unsigned short Type;

		int ProtocolVersion;

		LogonStatusEnum Result;

		char ResultText[TEXT_DESCRIPTION_LENGTH];

		char ReconnectAddress [64];

		int Integer_1;

		char ServerVersion[12]; 
		char ServerName[24];
		char ServiceProviderName[24];

		unsigned char MarketDepthUpdatesBestBidAndAsk;

		unsigned char TradingIsSupported;

		unsigned char OCOOrdersSupported;

		unsigned char OrderCancelReplaceSupported;

		char SymbolExchangeDelimiter[4];

		unsigned char SecurityDefinitionsSupported;

		unsigned char HistoricalPriceDataSupported;

		unsigned char ResubscribeWhenMarketDataFeedRestored;



		s_LogonResponse()
		{
			memset(this, 0,sizeof(s_LogonResponse));
			Type=LOGON_RESPONSE;
			Size=sizeof(s_LogonResponse);
			ProtocolVersion = CURRENT_VERSION;
			OrderCancelReplaceSupported = 1;
		}

		int GetProtocolVersion();

		unsigned short GetMessageSize();
		LogonStatusEnum GetResult();
		void SetResult(LogonStatusEnum NewValue);
		char * GetResultText();
		void SetResultText(const char * NewValue);

		unsigned char GetMarketDepthUpdatesBestBidAndAsk();
		void SetMarketDepthUpdatesBestBidAndAsk(unsigned char NewValue);
		unsigned char GetTradingIsSupported();
		void SetTradingIsSupported(unsigned char NewValue);
		unsigned char GetOCOOrdersSupported();
		void SetOCOOrdersSupported(unsigned char NewValue);
		unsigned char GetOrderCancelReplaceSupported();
		void SetOrderCancelReplaceSupported(unsigned char NewValue);
		char * GetSymbolExchangeDelimiter();
		void SetSymbolExchangeDelimiter(const char * NewValue);
		unsigned char GetSecurityDefinitionsSupported();
		void SetSecurityDefinitionsSupported(unsigned char NewValue);
		unsigned char GetHistoricalPriceDataSupported();
		void SetHistoricalPriceDataSupported(unsigned char NewValue);
		char * GetReconnectAddress();
		void SetReconnectAddress(const char * NewValue);

	};

	/*==========================================================================*/
	struct s_Heartbeat
	{
		unsigned short Size;
		unsigned short Type;

		unsigned int DroppedMessages;

		s_Heartbeat()
		{
			memset(this, 0,sizeof(s_Heartbeat));
			Type=HEARTBEAT;
			Size=sizeof(s_Heartbeat);
		}
		
		unsigned short GetMessageSize();
	};

	/*==========================================================================*/
	struct s_DisconnectFromServer
	{
		unsigned short Size;
		unsigned short Type;

		char DisconnectReason[TEXT_DESCRIPTION_LENGTH];

		s_DisconnectFromServer()
		{
			memset(this, 0,sizeof(s_DisconnectFromServer));
			Type=DISCONNECT_FROM_SERVER_NO_RECONNECT;
			Size=sizeof(s_DisconnectFromServer);
		}
		
		unsigned short GetMessageSize();
		char * GetDisconnectReason();
		void SetDisconnectReason(const char * NewValue);

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
		
		unsigned short GetMessageSize();
		MarketDataFeedStatusEnum GetStatus();
		void SetStatus(MarketDataFeedStatusEnum NewValue);

	};

	/*==========================================================================*/
	struct s_MarketDataFeedSymbolStatus
	{
		unsigned short Size;
		unsigned short Type;
		unsigned short MarketDataSymbolID;
		MarketDataFeedStatusEnum Status;

		s_MarketDataFeedSymbolStatus()
		{
			memset(this, 0,sizeof(s_MarketDataFeedSymbolStatus));
			Type=MARKET_DATA_FEED_SYMBOL_STATUS;
			Size=sizeof(s_MarketDataFeedSymbolStatus);
		}

	};
	
	/*==========================================================================*/
	struct s_MarketDataRequest
	{
		unsigned short Size;
		unsigned short Type;
		RequestActionEnum RequestActionValue;

		unsigned short MarketDataSymbolID;

		char Symbol[SYMBOL_LENGTH];

		char Exchange[EXCHANGE_LENGTH];

		s_MarketDataRequest()
		{
			memset(this, 0,sizeof(s_MarketDataRequest));
			Type=MARKET_DATA_REQUEST;
			Size=sizeof(s_MarketDataRequest);
			RequestActionValue=SUBSCRIBE;
		}
		
		unsigned short GetMessageSize();
		RequestActionEnum GetRequestActionValue();
		void SetRequestActionValue(RequestActionEnum NewValue);
		unsigned short GetMarketDataSymbolID();
		void SetMarketDataSymbolID(unsigned short NewValue);
		char * GetSymbol();
		void SetSymbol(const char * NewValue);
		char * GetExchange();
		void SetExchange(const char * NewValue);
	};

	/*==========================================================================*/
	struct s_MarketDepthRequest
	{
		unsigned short Size;
		unsigned short Type;

		RequestActionEnum RequestActionValue;

		unsigned short MarketDataSymbolID;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];
		int NumberOfLevels;

		s_MarketDepthRequest()
		{
			memset(this, 0,sizeof(s_MarketDepthRequest));
			Type=MARKET_DEPTH_REQUEST;
			Size=sizeof(s_MarketDepthRequest);

			RequestActionValue=SUBSCRIBE;
			NumberOfLevels= 10;
		}
		
		unsigned short GetMessageSize();
		RequestActionEnum GetRequestActionValue();
		void SetRequestActionValue(RequestActionEnum NewValue);
		unsigned short GetMarketDataSymbolID();
		void SetMarketDataSymbolID(unsigned short NewValue);
		char * GetSymbol();
		void SetSymbol(const char * NewValue);
		char * GetExchange();
		void SetExchange(const char * NewValue);
		int GetNumberOfLevels();
		void SetNumberOfLevels(int NewValue);
	};

	/*==========================================================================*/
	struct s_MarketDataReject
	{
		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;
		char RejectText[TEXT_DESCRIPTION_LENGTH];

		s_MarketDataReject()
		{
			memset(this, 0,sizeof(s_MarketDataReject));
			Type=MARKET_DATA_REJECT;
			Size=sizeof(s_MarketDataReject);
		}
		
		unsigned short GetMessageSize();
		unsigned short GetMarketDataSymbolID();
		void SetMarketDataSymbolID(unsigned short NewValue);
		char * GetRejectText();
		void SetRejectText(const char * NewValue);
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
		double DailyVolume;
		unsigned int DailyNumberOfTrades;

		union
		{
			unsigned int SharesOutstanding;
			unsigned int OpenInterest;
			unsigned int UnitsOutstanding;
		};

		double Bid;
		double Ask;
		unsigned int AskSize;
		unsigned int BidSize;

		double LastTradePrice;
		unsigned int LastTradeSize;
		t_DateTime LastTradeDateTimeUnix;
		short LastTradeMilliseconds;

		s_MarketDataSnapshot()
		{
			memset(this, 0,sizeof(s_MarketDataSnapshot));
			Type=MARKET_DATA_SNAPSHOT;
			Size=sizeof(s_MarketDataSnapshot);
		}
		
		unsigned short GetMessageSize();
		unsigned short GetMarketDataSymbolID();
		void SetMarketDataSymbolID(unsigned short NewValue);
		double GetDailyOpen();
		void SetDailyOpen(double NewValue);
		double GetDailyHigh();
		void SetDailyHigh(double NewValue);
		double GetDailyLow();
		void SetDailyLow(double NewValue);
		double GetDailyVolume();
		void SetDailyVolume(double NewValue);
		unsigned int GetDailyNumberOfTrades();
		void SetDailyNumberOfTrades(unsigned int NewValue);
		unsigned int GetSharesOutstanding();
		void SetSharesOutstanding(unsigned int NewValue);
		unsigned int GetOpenInterest();
		void SetOpenInterest(unsigned int NewValue);
		unsigned int GetUnitsOutstanding();
		void SetUnitsOutstanding(unsigned int NewValue);
		double GetBid();
		void SetBid(double NewValue);
		double GetAsk();
		void SetAsk(double NewValue);
		unsigned int GetAskSize();
		void SetAskSize(unsigned int NewValue);
		unsigned int GetBidSize();
		void SetBidSize(unsigned int NewValue);
		double GetLastTradePrice();
		void SetLastTradePrice(double NewValue);
		unsigned int GetLastTradeSize();
		void SetLastTradeSize(unsigned int NewValue);
		t_DateTime GetLastTradeDateTimeUnix();
		void SetLastTradeDateTimeUnix(t_DateTime NewValue);
		short GetLastTradeMilliseconds();
		void SetLastTradeMilliseconds(short NewValue);
		void SetToUnsetValues ();

	};
	/*==========================================================================*/
	struct s_FundamentalDataResponse
	{
		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;

		char SymbolDescription[SYMBOL_DESCRIPTION_LENGTH];

		float TickSize;

		float TickCurrencyValue;

		DisplayFormatEnum DisplayFormat;

		float BuyRolloverInterest;
		float SellRolloverInterest;

		s_FundamentalDataResponse()
		{
			memset(this, 0,sizeof(s_FundamentalDataResponse));
			Type=FUNDAMENTAL_DATA_RESPONSE;
			Size=sizeof(s_FundamentalDataResponse);
			DisplayFormat = DISPLAY_FORMAT_UNSET;
		}


		unsigned short GetMessageSize();
		unsigned short GetMarketDataSymbolID();
		void SetMarketDataSymbolID(unsigned short NewValue);
		char * GetSymbolDescription();
		void SetSymbolDescription(const char * NewValue);
		float GetTickSize();
		void SetTickSize(float NewValue);
		float GetTickCurrencyValue();
		void SetTickCurrencyValue(float NewValue);
		DisplayFormatEnum GetDisplayFormat();
		void SetDisplayFormat(DisplayFormatEnum NewValue);
		float GetBuyRolloverInterest();
		void SetBuyRolloverInterest(float NewValue);
		float GetSellRolloverInterest();
		void SetSellRolloverInterest(float NewValue);

		void SetDisplayFormatFromTickSize();

	};

	/*==========================================================================*/
	struct s_TradeIncrementalUpdateWithFullDepth
	{
		static const int NUM_DEPTH_LEVELS =10;
		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;

		BidOrAskEnum TradeAtBidOrAsk;

		double Price;
		unsigned int TradeVolume;
		unsigned int TotalDailyVolume;
		t_DateTime4Byte TradeDateTimeUnix;
		short LastTradeMilliseconds;

		struct 
		{
			double Price;
			unsigned int Volume;
		} BidDepth[NUM_DEPTH_LEVELS], AskDepth[NUM_DEPTH_LEVELS];


		s_TradeIncrementalUpdateWithFullDepth()
		{
			memset(this, 0,sizeof(s_TradeIncrementalUpdateWithFullDepth));
			Type=TRADE_INCREMENTAL_UPDATE_WITH_FULL_DEPTH;
			Size=sizeof(s_TradeIncrementalUpdateWithFullDepth);
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
	
		unsigned short GetMessageSize();
		unsigned short GetMarketDataSymbolID();
		void SetMarketDataSymbolID(unsigned short NewValue);
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

		BidOrAskEnum TradeAtBidOrAsk;

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
			return Price;
		}
	};

	/*==========================================================================*/

	struct s_QuoteIncrementalUpdate
	{
		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;

		double BidPrice;
		unsigned int BidSize;
		double AskPrice;
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
				return BidPrice;
		}

		double GetAskPrice()
		{
				return AskPrice;
		}
	};

	/*==========================================================================*/

	struct s_TradeIncrementalUpdateCompact
	{
		unsigned short Size;
		unsigned short Type;
	
		float Price;
		unsigned int TradeVolume;
		t_DateTime4Byte TradeDateTimeUnix;
		unsigned short MarketDataSymbolID;
		//BidOrAskEnum TradeAtBidOrAsk;

		s_TradeIncrementalUpdateCompact()
		{
			memset(this, 0,sizeof(s_TradeIncrementalUpdateCompact));
			Type=TRADE_INCREMENTAL_UPDATE_COMPACT;
			Size=sizeof(s_TradeIncrementalUpdateCompact);

		}
		double GetPrice()
		{
			return Price;
		}
	};

	/*==========================================================================*/
	struct s_DailyVolumeIncrementalUpdate
	{
		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;
		double DailyVolume;

		s_DailyVolumeIncrementalUpdate()
		{
			memset(this, 0,sizeof(s_DailyVolumeIncrementalUpdate));
			Type=DAILY_VOLUME_INCREMENTAL_UPDATE;
			Size=sizeof(s_DailyVolumeIncrementalUpdate);
		}
	};
	/*==========================================================================*/
	struct s_DailyHighIncrementalUpdate
	{
		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;
		double DailyHigh;

		s_DailyHighIncrementalUpdate()
		{
			memset(this, 0,sizeof(s_DailyHighIncrementalUpdate));
			Type=DAILY_HIGH_INCREMENTAL_UPDATE;
			Size=sizeof(s_DailyHighIncrementalUpdate);

		}
	};
	/*==========================================================================*/
	struct s_DailyLowIncrementalUpdate
	{
		unsigned short Size;
		unsigned short Type;

		unsigned short MarketDataSymbolID;
		double DailyLow;

		s_DailyLowIncrementalUpdate()
		{
			memset(this, 0,sizeof(s_DailyLowIncrementalUpdate));
			Type=DAILY_LOW_INCREMENTAL_UPDATE;
			Size=sizeof(s_DailyLowIncrementalUpdate);

		}
	};
	/*==========================================================================*/

	struct s_SubmitNewSingleOrder
	{

		unsigned short Size;
		unsigned short Type;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		char ClientOrderID[ORDER_ID_LENGTH];

		OrderTypeEnum OrderType;
		BuySellEnum BuySell;

		double Price1;

		double Price2;

		TimeInForceEnum TimeInForce;
		t_DateTime GoodTillDateTimeUnix;
		unsigned int OrderQuantity;
		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		char IsAutomatedOrder;

		char IsParentOrder;

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

		char ServerOrderID[ORDER_ID_LENGTH];
		char ClientOrderID[ORDER_ID_LENGTH];

		double Price1;
		double Price2;

		unsigned int OrderQuantity;

		char TradeAccount [TRADE_ACCOUNT_LENGTH];//Not required by GSP

		s_CancelReplaceOrder()
		{
			memset(this, 0,sizeof(s_CancelReplaceOrder));
			Type=CANCEL_REPLACE_ORDER;
			Size=sizeof(s_CancelReplaceOrder);
		}

	};
	/*==========================================================================*/
	//Custom Cancel/Replace order request
	struct s_CancelReplaceOrder2
	{

		unsigned short Size;
		unsigned short Type;

		char ServerOrderID[ORDER_ID_LENGTH];
		char ClientOrderID[ORDER_ID_LENGTH];

		double Price1;
		double Price2;

		unsigned int OrderQuantity;

		char TradeAccount [TRADE_ACCOUNT_LENGTH];//Not required by GSP

		char Symbol[SYMBOL_LENGTH];//Not required by GSP
		char Exchange[EXCHANGE_LENGTH];//Not required by GSP
		OrderTypeEnum OrderType;//Not required by GSP
		TimeInForceEnum TimeInForce;//Not required by GSP

		s_CancelReplaceOrder2()
		{
			memset(this, 0,sizeof(s_CancelReplaceOrder2));
			Type=CANCEL_REPLACE_ORDER_2;
			Size=sizeof(s_CancelReplaceOrder2);
		}

	};
	/*==========================================================================*/

	struct s_CancelOrder
	{

		unsigned short Size;
		unsigned short Type;
		
		char ServerOrderID[ORDER_ID_LENGTH];
		char ClientOrderID[ORDER_ID_LENGTH];
		char TradeAccount [TRADE_ACCOUNT_LENGTH];

		char Symbol[SYMBOL_LENGTH];//Not required by GSP
		char Exchange[EXCHANGE_LENGTH];//Not required by GSP

		s_CancelOrder()
		{
			memset(this, 0,sizeof(s_CancelOrder));
			Type=CANCEL_ORDER;
			Size=sizeof(s_CancelOrder);
		}
	};

	/*==========================================================================*/

	struct s_SubmitNewOCOOrder
	{
		unsigned short Size;
		unsigned short Type;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

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

		char IsAutomatedOrder;

		char ParentTriggerOrderID[ORDER_ID_LENGTH];

		s_SubmitNewOCOOrder()
		{
			memset(this, 0,sizeof(s_SubmitNewOCOOrder));
			Type=SUBMIT_NEW_OCO_ORDER;
			Size=sizeof(s_SubmitNewOCOOrder);

		}

	};


	/*==========================================================================*/

	struct s_OpenOrdersRequest
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;

		int RequestAllOpenOrders;
		char ServerOrderID[ORDER_ID_LENGTH];

		s_OpenOrdersRequest()
		{

			memset(this, 0,sizeof(s_OpenOrdersRequest));
			Type=OPEN_ORDERS_REQUEST;
			Size=sizeof(s_OpenOrdersRequest);
			RequestAllOpenOrders = 1;
		}

	};
	/*==========================================================================*/

	struct s_RequestHistoricalOrderFills
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;

		char ServerOrderID[ORDER_ID_LENGTH];

		int NumberOfDays;

		s_RequestHistoricalOrderFills()
		{
			memset(this, 0,sizeof(s_RequestHistoricalOrderFills));
			Type=REQUEST_HISTORICAL_ORDER_FILLS;
			Size=sizeof(s_RequestHistoricalOrderFills);

		}

	};

	/*==========================================================================*/
	
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
		char RejectText[TEXT_DESCRIPTION_LENGTH];

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

		int RequestID;

		int TotalNumberMessages;

		int MessageNumber;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		char PreviousServerOrderID[ORDER_ID_LENGTH];

		char ServerOrderID[ORDER_ID_LENGTH];

		char ClientOrderID[ORDER_ID_LENGTH];


		char ExchangeOrderID[ORDER_ID_LENGTH];

		OrderStatusEnum OrderStatus;

		ExecutionTypeEnum ExecutionType;

		OrderTypeEnum OrderType;

		BuySellEnum BuySell;

		double Price1;

		double Price2;

		TimeInForceEnum TimeInForce;
		t_DateTime GoodTillDateTimeUnix;
		unsigned int OrderQuantity;
		unsigned int FilledQuantity;
		unsigned int RemainingQuantity;
		double AverageFillPrice;

		double LastFillPrice;
		t_DateTime LastFillDateTimeUnix;
		unsigned int LastFillQuantity;
		char UniqueFillExecutionID[64];

		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		char InfoText[TEXT_DESCRIPTION_LENGTH];

		char NoneOrders;

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

		char * GetSymbol();
		void SetSymbol(const char * NewValue);
		char * GetExchange();
		void SetExchange(const char * NewValue);
		char * GetPreviousServerOrderID();
		void SetPreviousServerOrderID(const char * NewValue);
		char * GetServerOrderID();
		void SetServerOrderID(const char * NewValue);
		char * GetClientOrderID();
		void SetClientOrderID(const char * NewValue);
		char * GetExchangeOrderID();
		void SetExchangeOrderID(const char * NewValue);
		void SetUniqueFillExecutionID(const char * NewValue);
		void SetTradeAccount(const char * NewValue);
		void SetInfoText(const char * NewValue);
		
	};



	/*==========================================================================*/
	struct s_OpenOrdersRequestReject
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;
		char RejectText[TEXT_DESCRIPTION_LENGTH];

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

		int TotalNumberMessages;

		int MessageNumber;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];
		char ServerOrderID[ORDER_ID_LENGTH];
		BuySellEnum BuySell;
		double FillPrice;
		t_DateTime FillDateTimeUnix;
		unsigned int FillQuantity;
		char UniqueFillExecutionID[64];
		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		OpenCloseTradeEnum OpenClose; 

		char NoneOrderFills;

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

		int RequestID;

		int TotalNumberMessages;

		int MessageNumber;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		int PositionQuantity;
		double AveragePrice;

		char PositionIdentifier [ORDER_ID_LENGTH];

		char TradeAccount[TRADE_ACCOUNT_LENGTH];
		char NonePositions;

		char Unsolicited;

		s_PositionReport()
		{

			memset(this, 0,sizeof(s_PositionReport));
			Type=POSITION_REPORT;
			Size=sizeof(s_PositionReport);

		}

		void SetSymbol(const char * NewValue);
		void SetTradeAccount(const char * NewValue);
	};

	/*==========================================================================*/

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
	struct s_AccountsListResponse
	{

		unsigned short Size;
		unsigned short Type;

		int TotalNumberMessages;

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

	struct s_ExchangeListResponse
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;
		char Exchange[EXCHANGE_LENGTH];
		char FinalMessage;

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

	/*==========================================================================

	struct s_SymbolResponse
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;
		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		SecurityTypeEnum SecurityType;
		char FinalMessage;

		s_SymbolResponse()
		{

			memset(this, 0,sizeof(s_SymbolResponse));
			Type=SYMBOL_RESPONSE;
			Size=sizeof(s_SymbolResponse);
		}

	};
	==========================================================================*/

	struct s_SecurityDefinitionResponse
	{
		unsigned short Size;
		unsigned short Type;

		int RequestID;

		char Symbol[SYMBOL_LENGTH];

		char Exchange[EXCHANGE_LENGTH];

		SecurityTypeEnum SecurityType;
		
		char SymbolDescription[SYMBOL_DESCRIPTION_LENGTH];
		float TickSize;
		DisplayFormatEnum PriceDisplayFormat;
		float TickCurrencyValue;

		char FinalMessage;

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

		double CurrentCashBalance;

		double CurrentBalanceAvailableForNewPositions;

		char AccountCurrency[8];

		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		s_AccountBalanceUpdate()
		{
			memset(this, 0,sizeof(s_AccountBalanceUpdate));
			Type=ACCOUNT_BALANCE_UPDATE;
			Size=sizeof(s_AccountBalanceUpdate);
		}

		void SetAccountCurrency(const char * NewValue);
		void SetTradeAccount(const char * NewValue);

	};
	/*==========================================================================*/

	struct s_UserMessage
	{
		unsigned short Size;
		unsigned short Type;

		char UserMessage[256];

		char PopupMessage;

		s_UserMessage()
		{
			memset(this, 0,sizeof(s_UserMessage));
			Type=USER_MESSAGE;
			Size=sizeof(s_UserMessage);
			PopupMessage = 1;
		}

	};
	/*==========================================================================*/

	struct s_GeneralLogMessage
	{
		unsigned short Size;
		unsigned short Type;

		char MessageText[128];

		s_GeneralLogMessage()
		{
			memset(this, 0,sizeof(s_GeneralLogMessage));
			Type=GENERAL_LOG_MESSAGE;
			Size=sizeof(s_GeneralLogMessage);
		}

	};
	/*==========================================================================*/

	struct s_HistoricalPriceDataRequest
	{
		unsigned short Size;
		unsigned short Type;

		int RequestIdentifier;
		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];
		HistoricalDataIntervalEnum DataInterval;
		t_DateTime StartDateTime;
		t_DateTime EndDateTime;

		char  UseZLibCompression;

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

		char RecordsUseZLibCompression;
		
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
		int RequestIdentifier;

		char RejectText[TEXT_DESCRIPTION_LENGTH];

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
		unsigned int Volume;
		union
		{
			unsigned int OpenInterest;
			unsigned int NumberTrades;
		};
		unsigned int BidVolume;
		unsigned int AskVolume;

		char FinalRecord;
		s_HistoricalPriceDataRecordResponse()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataRecordResponse));
			Type=HISTORICAL_PRICE_DATA_RECORD_RESPONSE;
			Size=sizeof(s_HistoricalPriceDataRecordResponse);
		}

	};

	/*==========================================================================*/

	struct s_HistoricalPriceDataTickRecordResponse
	{
		unsigned short Size;
		unsigned short Type;
		int RequestIdentifier;

		t_DateTime TradeDateTime;
		short Milliseconds;
		BidOrAskEnum BidOrAsk;

		double TradePrice;
		unsigned int TradeVolume;

		char FinalRecord;

		s_HistoricalPriceDataTickRecordResponse()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataTickRecordResponse));
			Type=HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE;
			Size=sizeof(s_HistoricalPriceDataTickRecordResponse);
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

		unsigned short GetMessageSize();
	};


	/*==========================================================================*/
	struct s_ServerReadyToReceive
	{
		unsigned short Size;
		unsigned short Type;

		char ServerName[25];
		char ServerVersion[25]; 
		char ServiceProviderName[25];

		int ProtocolVersion;

		s_ServerReadyToReceive()
		{			
			memset(this, 0,sizeof(s_ServerReadyToReceive));
			Type=SERVER_READY_TO_RECEIVE;
			Size=sizeof(s_ServerReadyToReceive);
			ProtocolVersion=  CURRENT_VERSION;
		}

		int GetProtocolVersion();

		unsigned short GetMessageSize();
		char * GetServerName();
		void SetServerName(const char * NewValue);
		char * GetServerVersion();
		void SetServerVersion(const char * NewValue);
		char * GetServiceProviderName();
		void SetServiceProviderName(const char * NewValue);
	};

#pragma pack()
}
