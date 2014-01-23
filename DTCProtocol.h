
// Data and Trading Communications Protocol (DTC Protocol)

// This protocol is in the public domain and freely usable by anyone.

// Documentation: http://www.sierrachart.com/index.php?file=doc/doc_DTCMessageDocumentation.php

// Integers of type "__int32" are 32 bits.

// The byte ordering is little endian. 

#pragma once

namespace DTC
{
#pragma pack(8)

	// DTC protocol version
	const __int32 CURRENT_VERSION = 3;

	// Text string lengths. The protocol is intended to be updated to support variable length strings making these irrelevant at that time.
	const __int32 SYMBOL_LENGTH = 64;
	const __int32 EXCHANGE_LENGTH= 16;
	const __int32 UNDERLYING_SYMBOL_LENGTH= 32;
	const __int32 SYMBOL_DESCRIPTION_LENGTH = 48;
	const __int32 ORDER_ID_LENGTH = 32;
	const __int32 TRADE_ACCOUNT_LENGTH = 32;
	const __int32 TEXT_DESCRIPTION_LENGTH = 96;
	const __int32 TEXT_MESSAGE_LENGTH = 256;

	//----Message types----

	// Authentication and connection monitoring
	const unsigned __int16 LOGON_REQUEST = 1;
	const unsigned __int16 LOGON_RESPONSE = 2;
	const unsigned __int16 HEARTBEAT = 3;
	const unsigned __int16 DISCONNECT_FROM_SERVER_NO_RECONNECT = 4;

	// Market data
	const unsigned __int16 MARKET_DATA_FEED_STATUS = 100;
	const unsigned __int16 MARKET_DATA_REQUEST = 101;
	const unsigned __int16 MARKET_DEPTH_REQUEST = 102;
	const unsigned __int16 MARKET_DATA_REJECT = 103;
	const unsigned __int16 MARKET_DATA_SNAPSHOT = 104;
	const unsigned __int16 MARKET_DEPTH_FULL_UPDATE = 105;
	const unsigned __int16 MARKET_DEPTH_INCREMENTAL_UPDATE = 106;
	const unsigned __int16 TRADE_INCREMENTAL_UPDATE = 107;
	const unsigned __int16 QUOTE_INCREMENTAL_UPDATE = 108;
	const unsigned __int16 FUNDAMENTAL_DATA_RESPONSE = 110;
	
	const unsigned __int16 TRADE_INCREMENTAL_UPDATE_COMPACT = 112;
	const unsigned __int16 DAILY_VOLUME_INCREMENTAL_UPDATE = 113;
	const unsigned __int16 DAILY_HIGH_INCREMENTAL_UPDATE = 114;
	const unsigned __int16 DAILY_LOW_INCREMENTAL_UPDATE = 115;
	const unsigned __int16 MARKET_DATA_FEED_SYMBOL_STATUS = 116;
	const unsigned __int16 QUOTE_INCREMENTAL_UPDATE_COMPACT = 117;
	const unsigned __int16 MARKET_DEPTH_INCREMENTAL_UPDATE_COMPACT = 118;
	const unsigned __int16 SETTLEMENT_INCREMENTAL_UPDATE = 119;
	const unsigned __int16 DAILY_OPEN_INCREMENTAL_UPDATE = 120;
	const unsigned __int16 MARKET_DEPTH_REJECT = 121;
	const unsigned __int16 MARKET_DEPTH_SNAPSHOT_LEVEL = 122;

	// Order entry and modification
	const unsigned __int16 SUBMIT_NEW_SINGLE_ORDER = 200;
	const unsigned __int16 SUBMIT_NEW_OCO_ORDER = 201;
	const unsigned __int16 CANCEL_REPLACE_ORDER = 202;
	const unsigned __int16 CANCEL_ORDER = 203;

	// Trading related
	const unsigned __int16 OPEN_ORDERS_REQUEST = 300;
	const unsigned __int16 ORDER_UPDATE_REPORT = 301;
	const unsigned __int16 OPEN_ORDERS_REQUEST_REJECT = 302;
	const unsigned __int16 HISTORICAL_ORDER_FILLS_REQUEST = 303;
	const unsigned __int16 HISTORICAL_ORDER_FILL_REPORT = 304;
	const unsigned __int16 CURRENT_POSITIONS_REQUEST = 305;
	const unsigned __int16 POSITION_REPORT = 306;
	const unsigned __int16 CURRENT_POSITIONS_REQUEST_REJECT = 307;

	// Account list
	const unsigned __int16 ACCOUNTS_REQUEST = 400;
	const unsigned __int16 ACCOUNT_LIST_RESPONSE = 401;

	// Symbol discovery and security definitions
	const unsigned __int16 EXCHANGE_LIST_REQUEST = 500;
	const unsigned __int16 EXCHANGE_LIST_RESPONSE = 501;
	const unsigned __int16 SYMBOLS_FOR_EXCHANGE_REQUEST = 502;
	const unsigned __int16 UNDERLYING_SYMBOLS_FOR_EXCHANGE_REQUEST = 503;
	const unsigned __int16 SYMBOLS_FOR_UNDERLYING_REQUEST = 504;
	const unsigned __int16 SECURITY_DEFINITION_FOR_SYMBOL_REQUEST = 506;
	const unsigned __int16 SECURITY_DEFINITION_RESPONSE = 507;

	// Account balance
	const unsigned __int16 ACCOUNT_BALANCE_UPDATE = 600;

	// Logging
	const unsigned __int16 USER_MESSAGE = 700;
	const unsigned __int16 GENERAL_LOG_MESSAGE = 701;

	// Historical price data
	const unsigned __int16 HISTORICAL_PRICE_DATA_REQUEST= 800;
	const unsigned __int16 HISTORICAL_PRICE_DATA_HEADER_RESPONSE = 801;
	const unsigned __int16 HISTORICAL_PRICE_DATA_REJECT = 802;
	const unsigned __int16 HISTORICAL_PRICE_DATA_RECORD_RESPONSE = 803;
	const unsigned __int16 HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE = 804;


	/*==========================================================================*/
	//Standard UNIX date and time value
	typedef __int64 t_DateTime;

	// This is a 4 byte DateTime value used in messages where compactness is an important consideration.
	typedef unsigned __int32 t_DateTime4Byte;

	/*==========================================================================*/
	enum LogonStatusEnum : __int32
	{ LOGON_SUCCESS = 1
	, LOGON_ERROR = 2
	, LOGON_ERROR_NO_RECONNECT = 3
	, LOGON_RECONNECT_NEW_ADDRESS = 4
	};

	/*==========================================================================*/
	enum MessageSupportedEnum : __int32
	{ MESSAGE_UNSUPPORTED = 0
	, MESSAGE_SUPPORTED = 1
	};

	/*==========================================================================*/
	enum TradeModeEnum : __int32
	{ TRADE_MODE_DEMO = 1
	, TRADE_MODE_SIMULATED = 2
	, TRADE_MODE_LIVE = 3
	};

	/*==========================================================================*/
	enum RequestActionEnum : __int32
	{ SUBSCRIBE = 1
	, UNSUBSCRIBE = 2
	, SNAPSHOT = 3
	};

	/*==========================================================================*/
	enum OrderStatusEnum : __int32
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
	enum ExecutionTypeEnum : __int32
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
	
	/*==========================================================================*/
	enum BidOrAskEnum : unsigned __int16
	{ BID_ASK_UNSET = 0
	, AT_BID = 1
	, AT_ASK = 2
	};
	
	/*==========================================================================*/
	enum MarketDepthIncrementalUpdateTypeEnum : unsigned char
	{ DEPTH_UNSET = 0
	, DEPTH_INSERT_UPDATE = 1 // Insert or update depth at the given price level
	, DEPTH_DELETE = 2 // Delete depth at the given price level
	};
	
	/*==========================================================================*/
	enum OrderTypeEnum : __int32
	{ ORDER_TYPE_UNSET = 0
	, ORDER_TYPE_MARKET = 1
	, ORDER_TYPE_LIMIT = 2
	, ORDER_TYPE_STOP = 3
	, ORDER_TYPE_STOP_LIMIT = 4
	, ORDER_TYPE_MARKET_IF_TOUCHED = 5
	};
	
	/*==========================================================================*/
	enum TimeInForceEnum : __int32
	{ TIF_UNSET = 0
	, TIF_DAY = 1
	, TIF_GOOD_TILL_CANCELED = 2
	, TIF_GOOD_TILL_DATE_TIME = 3
	, TIF_IMMEDIATE_OR_CANCEL = 4
	, TIF_ALL_OR_NONE = 5
	, TIF_FILL_OR_KILL = 6
	};
	
	/*==========================================================================*/
	enum BuySellEnum : __int32
	{ BUY_SELL_UNSET = 0
	, BUY = 1
	, SELL = 2
	};

	/*==========================================================================*/
	enum OpenCloseTradeEnum : __int32
	{ TRADE_UNSET = 0
	, TRADE_OPEN = 1
	, TRADE_CLOSE = 2
	};

	/*==========================================================================*/
	
	enum MarketDataFeedStatusEnum : __int32
	{ MARKET_DATA_FEED_LOST = 1
	, MARKET_DATA_FEED_RESTORED = 2
	};

	/*==========================================================================*/
	enum DisplayFormatEnum : __int32
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
	enum SecurityTypeEnum : __int32
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
	
	/*==========================================================================*/
	enum HistoricalDataIntervalEnum : __int32
	{ INTERVAL_TICK = 0
	, INTERVAL_1_SECOND = 1
	, INTERVAL_2_SECONDS = 2
	, INTERVAL_4_SECONDS = 4
	, INTERVAL_5_SECONDS = 5
	, INTERVAL_10_SECONDS = 10
	, INTERVAL_30_SECONDS = 30
	, INTERVAL_1_MINUTE = 60
	, INTERVAL_1_DAY = 86400
	, INTERVAL_1_WEEK = 604800
	};

	/*==========================================================================*/
	struct s_SymbolExchange
	{
		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];
	};

	/*==========================================================================*/
	struct s_LogonRequest
	{
		unsigned __int16 Size;
		unsigned __int16 Type;
		__int32 ProtocolVersion;
		char Username[32];
		char Password[32];
		char GeneralTextData[64];
		__int32 Integer_1;
		__int32 Integer_2;
		__int32  HeartbeatIntervalInSeconds; 
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


		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);		
		__int32 GetProtocolVersion();
		const char * GetUsername();
		void SetUsername(const char * NewValue);
		char * GetPassword();
		void SetPassword(const char * NewValue);
		char * GetGeneralTextData();
		void SetGeneralTextData(const char * NewValue);
		__int32 GetInteger_1();
		__int32 GetInteger_2();
		__int32 GetInHeartbeatIntervalInSeconds();
		TradeModeEnum GetTradeMode();
		char * GetTradeAccount();
		void SetTradeAccount(const char * NewValue);
		char * GetHardwareIdentifier();
		void SetHardwareIdentifier(const char * NewValue);
		char * GetClientName();
		void SetClientName(const char * NewValue);
	};

	/*==========================================================================*/
	struct s_LogonResponse
	{
		unsigned __int16 Size;
		unsigned __int16 Type;
		__int32 ProtocolVersion;
		LogonStatusEnum Result;
		char ResultText[TEXT_DESCRIPTION_LENGTH];
		char ReconnectAddress [64];
		__int32 Integer_1;
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
		unsigned char MarketDepthIsSupported;
		unsigned char OneHistoricalPriceDataRequestPerConnection;

		s_LogonResponse()
		{
			memset(this, 0,sizeof(s_LogonResponse));
			Type=LOGON_RESPONSE;
			Size=sizeof(s_LogonResponse);
			ProtocolVersion = CURRENT_VERSION;
			OrderCancelReplaceSupported = 1;
			MarketDepthIsSupported = 1;
		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
		__int32 GetProtocolVersion();
		LogonStatusEnum GetResult();
		char * GetResultText();
		void SetResultText(const char * NewValue);
		char * GetReconnectAddress();
		void SetReconnectAddress(const char * NewValue);
		__int32 GetInteger_1();		
		char * GetServerVersion();
		void SetServerVersion(const char * NewValue);		
		char * GetServerName();
		void SetServerName(const char * NewValue);		
		char * GetServiceProviderName();
		void SetServiceProviderName(const char * NewValue);
		unsigned char GetMarketDepthUpdatesBestBidAndAsk();
		unsigned char GetTradingIsSupported();
		unsigned char GetOCOOrdersSupported();
		unsigned char GetOrderCancelReplaceSupported();
		char * GetSymbolExchangeDelimiter();
		void SetSymbolExchangeDelimiter(const char * NewValue);
		unsigned char GetSecurityDefinitionsSupported();
		unsigned char GetHistoricalPriceDataSupported();
		unsigned char GetResubscribeWhenMarketDataFeedRestored();
	};

	/*==========================================================================*/
	struct s_Heartbeat
	{
		unsigned __int16 Size;
		unsigned __int16 Type;
		unsigned __int32 DroppedMessages;
		t_DateTime CurrentDateTime;

		s_Heartbeat()
		{
			memset(this, 0,sizeof(s_Heartbeat));
			Type=HEARTBEAT;
			Size=sizeof(s_Heartbeat);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
		unsigned __int32 GetDroppedMessages();
	};

	/*==========================================================================*/
	struct s_DisconnectFromServer
	{
		unsigned __int16 Size;
		unsigned __int16 Type;
		char DisconnectReason[TEXT_DESCRIPTION_LENGTH];

		s_DisconnectFromServer()
		{
			memset(this, 0,sizeof(s_DisconnectFromServer));
			Type=DISCONNECT_FROM_SERVER_NO_RECONNECT;
			Size=sizeof(s_DisconnectFromServer);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
		char * GetDisconnectReason();
		void SetDisconnectReason(const char * NewValue);
	};

	/*==========================================================================*/
	struct s_MarketDataFeedStatus
	{
		unsigned __int16 Size;
		unsigned __int16 Type;
		MarketDataFeedStatusEnum Status;

		s_MarketDataFeedStatus()
		{
			memset(this, 0,sizeof(s_MarketDataFeedStatus));
			Type=MARKET_DATA_FEED_STATUS;
			Size=sizeof(s_MarketDataFeedStatus);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
		MarketDataFeedStatusEnum GetStatus();
	};

	/*==========================================================================*/
	struct s_MarketDataFeedSymbolStatus
	{
		unsigned __int16 Size;
		unsigned __int16 Type;
		unsigned __int16 MarketDataSymbolID;
		MarketDataFeedStatusEnum Status;

		s_MarketDataFeedSymbolStatus()
		{
			memset(this, 0,sizeof(s_MarketDataFeedSymbolStatus));
			Type=MARKET_DATA_FEED_SYMBOL_STATUS;
			Size=sizeof(s_MarketDataFeedSymbolStatus);
		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
		unsigned __int16 GetMarketDataSymbolID();
		MarketDataFeedStatusEnum GetStatus();
	};
	
	/*==========================================================================*/
	struct s_MarketDataRequest
	{
		unsigned __int16 Size;
		unsigned __int16 Type;
		RequestActionEnum RequestActionValue;
		unsigned __int16 MarketDataSymbolID;
		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		s_MarketDataRequest()
		{
			memset(this, 0,sizeof(s_MarketDataRequest));
			Type=MARKET_DATA_REQUEST;
			Size=sizeof(s_MarketDataRequest);
			RequestActionValue=SUBSCRIBE;
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
		RequestActionEnum GetRequestActionValue();
		unsigned __int16 GetMarketDataSymbolID();
		char * GetSymbol();
		void SetSymbol(const char * NewValue);
		char * GetExchange();
		void SetExchange(const char * NewValue);
	};

	/*==========================================================================*/
	struct s_MarketDepthRequest
	{
		unsigned __int16 Size;
		unsigned __int16 Type;
		RequestActionEnum RequestActionValue;
		unsigned __int16 MarketDataSymbolID;
		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];
		__int32 NumberOfLevels;

		s_MarketDepthRequest()
		{
			memset(this, 0,sizeof(s_MarketDepthRequest));
			Type=MARKET_DEPTH_REQUEST;
			Size=sizeof(s_MarketDepthRequest);

			RequestActionValue=SUBSCRIBE;
			NumberOfLevels= 10;
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
		RequestActionEnum GetRequestActionValue();
		unsigned __int16 GetMarketDataSymbolID();
		char * GetSymbol();
		void SetSymbol(const char * NewValue);
		char * GetExchange();
		void SetExchange(const char * NewValue);
		__int32 GetNumberOfLevels();
	};

	/*==========================================================================*/
	struct s_MarketDataReject
	{
		unsigned __int16 Size;
		unsigned __int16 Type;
		unsigned __int16 MarketDataSymbolID;
		char RejectText[TEXT_DESCRIPTION_LENGTH];

		s_MarketDataReject()
		{
			memset(this, 0,sizeof(s_MarketDataReject));
			Type=MARKET_DATA_REJECT;
			Size=sizeof(s_MarketDataReject);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
		unsigned __int16 GetMarketDataSymbolID();
		char * GetRejectText();
		void SetRejectText(const char * NewValue);
	};

	/*==========================================================================*/
	struct s_MarketDataSnapshot
	{
		unsigned __int16 Size;
		unsigned __int16 Type;
		unsigned __int16 MarketDataSymbolID;
		double SettlementPrice;
		double DailyOpen;
		double DailyHigh;
		double DailyLow;
		double DailyVolume;
		unsigned __int32 DailyNumberOfTrades;
		union
		{
			unsigned __int32 SharesOutstanding;
			unsigned __int32 OpenInterest;
			unsigned __int32 UnitsOutstanding;
		};

		double Bid;
		double Ask;
		unsigned __int32 AskSize;
		unsigned __int32 BidSize;
		double LastTradePrice;
		unsigned __int32 LastTradeSize;
		double LastTradeDateTimeUnix;
		

		s_MarketDataSnapshot()
		{
			memset(this, 0,sizeof(s_MarketDataSnapshot));
			Type=MARKET_DATA_SNAPSHOT;
			Size=sizeof(s_MarketDataSnapshot);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
		unsigned __int16 GetMarketDataSymbolID();
		void SetMarketDataSymbolID(unsigned __int16 NewValue);
		double GetSettlementPrice();
		
		double GetDailyOpen();
		
		double GetDailyHigh();
		
		double GetDailyLow();
		
		double GetDailyVolume();
		
		unsigned __int32 GetDailyNumberOfTrades();
		
		unsigned __int32 GetSharesOutstanding();
		
		unsigned __int32 GetOpenInterest();
		
		unsigned __int32 GetUnitsOutstanding();
		
		double GetBid();
		
		double GetAsk();
		
		unsigned __int32 GetAskSize();
		
		unsigned __int32 GetBidSize();
		
		double GetLastTradePrice();
		
		unsigned __int32 GetLastTradeSize();
		
		double GetLastTradeDateTimeUnix();
		
		void SetToUnsetValues();
	};

	/*==========================================================================*/
	struct s_FundamentalDataResponse
	{
		unsigned __int16 Size;
		unsigned __int16 Type;
		unsigned __int16 MarketDataSymbolID;
		char SymbolDescription[SYMBOL_DESCRIPTION_LENGTH];
		float TickSize;
		float TickCurrencyValue;
		DisplayFormatEnum DisplayFormat;
		float BuyRolloverInterest;
		float SellRolloverInterest;
		float OrderPriceMultiplier;

		s_FundamentalDataResponse()
		{
			memset(this, 0,sizeof(s_FundamentalDataResponse));
			Type=FUNDAMENTAL_DATA_RESPONSE;
			Size=sizeof(s_FundamentalDataResponse);
			DisplayFormat = DISPLAY_FORMAT_UNSET;
		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
		unsigned __int16 GetMarketDataSymbolID();
		void SetMarketDataSymbolID(unsigned __int16 NewValue);
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
		float GetOrderPriceMultiplier();
		void SetOrderPriceMultiplier(float NewValue);
		void SetDisplayFormatFromTickSize();
	};

	/*==========================================================================*/
	struct s_MarketDepthFullUpdate
	{
		static const __int32 NUM_DEPTH_LEVELS =20;

		unsigned __int16 Size;
		unsigned __int16 Type;

		unsigned __int16 MarketDataSymbolID;

		struct 
		{
			double Price;
			unsigned __int32 Volume;
		}BidDepth[NUM_DEPTH_LEVELS], AskDepth[NUM_DEPTH_LEVELS];


		s_MarketDepthFullUpdate()
		{
			memset(this, 0,sizeof(s_MarketDepthFullUpdate));
			Type=MARKET_DEPTH_FULL_UPDATE;
			Size=sizeof(s_MarketDepthFullUpdate);
		}
	
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

		unsigned __int16 GetMarketDataSymbolID();
		
	};

	/*==========================================================================*/
	struct s_MarketDepthSnapshotLevel
	{

		unsigned __int16 Size;
		unsigned __int16 Type;
		unsigned __int16 MarketDataSymbolID;
		BidOrAskEnum Side;
		double Price;
		double Volume;
		unsigned __int16  Level;

		unsigned char FirstMessageInBatch;
		unsigned char LastMessageInBatch;


		s_MarketDepthSnapshotLevel()
		{
			memset(this, 0,sizeof(s_MarketDepthSnapshotLevel));
			Type=MARKET_DEPTH_SNAPSHOT_LEVEL;
			Size=sizeof(s_MarketDepthSnapshotLevel);

		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

		unsigned __int16 GetMarketDataSymbolID();
		BidOrAskEnum GetSide();
		double GetPrice();
		double GetVolume();
		unsigned __int16 GetLevel();
		unsigned char GetFirstMessageInBatch();
		unsigned char GetLastMessageInBatch();
	};


	/*==========================================================================*/
	struct s_MarketDepthIncrementalUpdate
	{	 
		unsigned __int16 Size;
		unsigned __int16 Type;

		unsigned __int16 MarketDataSymbolID;
		BidOrAskEnum Side;
		double Price;
		unsigned __int32 Volume;

		MarketDepthIncrementalUpdateTypeEnum UpdateType;

		s_MarketDepthIncrementalUpdate()
		{

			memset(this, 0,sizeof(s_MarketDepthIncrementalUpdate));
			Type=MARKET_DEPTH_INCREMENTAL_UPDATE;
			Size=sizeof(s_MarketDepthIncrementalUpdate);

		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
        
	};
	/*==========================================================================*/
	struct s_MarketDepthIncrementalUpdateCompact
	{	 
		unsigned __int16 Size;
		unsigned __int16 Type;

		unsigned __int16 MarketDataSymbolID;
		BidOrAskEnum Side;
		float Price;
		unsigned __int32 Volume;

		MarketDepthIncrementalUpdateTypeEnum UpdateType;

		s_MarketDepthIncrementalUpdateCompact()
		{

			memset(this, 0,sizeof(s_MarketDepthIncrementalUpdateCompact));
			Type=MARKET_DEPTH_INCREMENTAL_UPDATE_COMPACT;
			Size=sizeof(s_MarketDepthIncrementalUpdateCompact);

		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

		unsigned __int16 GetMarketDataSymbolID() const;
		BidOrAskEnum GetSide() const;
		float GetPrice() const;
		unsigned __int32 GetVolume() const;
		MarketDepthIncrementalUpdateTypeEnum GetUpdateType() const;
	};

	/*==========================================================================*/
	struct s_SettlementIncrementalUpdate
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		unsigned __int16 MarketDataSymbolID;
		double SettlementPrice;

		s_SettlementIncrementalUpdate()
		{
			memset(this, 0, sizeof(s_SettlementIncrementalUpdate));
			Type = SETTLEMENT_INCREMENTAL_UPDATE;
			Size = sizeof(s_SettlementIncrementalUpdate);
		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

		unsigned __int16 GetMarketDataSymbolID() const;
		double GetSettlementPrice() const;
	};

	/*==========================================================================*/
	struct s_DailyOpenIncrementalUpdate
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		unsigned __int16 MarketDataSymbolID;
		double DailyOpen;

		s_DailyOpenIncrementalUpdate()
		{
			memset(this, 0, sizeof(s_DailyOpenIncrementalUpdate));
			Type = DAILY_OPEN_INCREMENTAL_UPDATE;
			Size = sizeof(s_DailyOpenIncrementalUpdate);
		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

		unsigned __int16 GetMarketDataSymbolID() const;
		double GetDailyOpen() const;
	};

	/*==========================================================================*/
	struct s_MarketDepthReject
	{
		unsigned __int16 Size;
		unsigned __int16 Type;
		unsigned __int16 MarketDataSymbolID;
		char RejectText[TEXT_DESCRIPTION_LENGTH];

		s_MarketDepthReject()
		{
			memset(this, 0, sizeof(s_MarketDepthReject));
			Type = MARKET_DEPTH_REJECT;
			Size = sizeof(s_MarketDepthReject);
		}
	};

	/*==========================================================================*/

	struct s_TradeIncrementalUpdate
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		unsigned __int16 MarketDataSymbolID;

		BidOrAskEnum TradeAtBidOrAsk;

		double Price;
		unsigned __int32 TradeVolume;
		unsigned __int32 TotalDailyVolume;
		double TradeDateTimeUnix;
		//__int16 LastTradeMilliseconds;

		s_TradeIncrementalUpdate()
		{
			memset(this, 0,sizeof(s_TradeIncrementalUpdate));
			Type=TRADE_INCREMENTAL_UPDATE;
			Size=sizeof(s_TradeIncrementalUpdate);

		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
	};

	/*==========================================================================*/

	struct s_QuoteIncrementalUpdate
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		unsigned __int16 MarketDataSymbolID;

		double BidPrice;
		unsigned __int32 BidSize;
		double AskPrice;
		unsigned __int32 AskSize;
		double QuoteDateTimeUnix;

		s_QuoteIncrementalUpdate()
		{
			memset(this, 0,sizeof(s_QuoteIncrementalUpdate));
			Type=QUOTE_INCREMENTAL_UPDATE;
			Size=sizeof(s_QuoteIncrementalUpdate);
			BidPrice=DBL_MAX;
			AskPrice=DBL_MAX;

		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

		unsigned __int16 GetMarketDataSymbolID() const;
		double GetBidPrice() const;
		unsigned __int32 GetBidSize() const;
		double GetAskPrice() const;
		unsigned __int32 GetAskSize() const;
		double GetQuoteDateTimeUnix() const;
	};

	/*==========================================================================*/

	struct s_QuoteIncrementalUpdateCompact
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		float BidPrice;
		unsigned __int32 BidSize;
		float AskPrice;
		unsigned __int32 AskSize;

		t_DateTime4Byte QuoteDateTimeUnix;

		unsigned __int16 MarketDataSymbolID;

		s_QuoteIncrementalUpdateCompact()
		{
			memset(this, 0,sizeof(s_QuoteIncrementalUpdateCompact));
			Type=QUOTE_INCREMENTAL_UPDATE_COMPACT;
			Size=sizeof(s_QuoteIncrementalUpdateCompact);
			BidPrice=FLT_MAX;
			AskPrice=FLT_MAX;
		}

		float GetBidPrice() const;
		unsigned __int32 GetBidSize() const;
		float GetAskPrice() const;
		unsigned __int32 GetAskSize() const;
		t_DateTime4Byte GetQuoteDateTimeUnix() const;
		unsigned __int16 GetMarketDataSymbolID() const;
	};

	/*==========================================================================*/

	struct s_TradeIncrementalUpdateCompact
	{
		unsigned __int16 Size;
		unsigned __int16 Type;
	
		float Price;
		unsigned __int32 TradeVolume;
		t_DateTime4Byte TradeDateTimeUnix;
		unsigned __int16 MarketDataSymbolID;
		BidOrAskEnum TradeAtBidOrAsk;

		s_TradeIncrementalUpdateCompact()
		{
			memset(this, 0,sizeof(s_TradeIncrementalUpdateCompact));
			Type=TRADE_INCREMENTAL_UPDATE_COMPACT;
			Size=sizeof(s_TradeIncrementalUpdateCompact);

		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

		float GetPrice() const;
		unsigned __int32 GetTradeVolume() const;
		t_DateTime4Byte GetTradeDateTimeUnix() const;
		unsigned __int16 GetMarketDataSymbolID() const;
		BidOrAskEnum GetTradeAtBidOrAsk() const;
	};

	/*==========================================================================*/
	struct s_DailyVolumeIncrementalUpdate
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		unsigned __int16 MarketDataSymbolID;
		double DailyVolume;

		s_DailyVolumeIncrementalUpdate()
		{
			memset(this, 0,sizeof(s_DailyVolumeIncrementalUpdate));
			Type=DAILY_VOLUME_INCREMENTAL_UPDATE;
			Size=sizeof(s_DailyVolumeIncrementalUpdate);
		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

		unsigned __int16 GetMarketDataSymbolID() const;
		double GetDailyVolume() const;
	};
	/*==========================================================================*/
	struct s_DailyHighIncrementalUpdate
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		unsigned __int16 MarketDataSymbolID;
		double DailyHigh;

		s_DailyHighIncrementalUpdate()
		{
			memset(this, 0,sizeof(s_DailyHighIncrementalUpdate));
			Type=DAILY_HIGH_INCREMENTAL_UPDATE;
			Size=sizeof(s_DailyHighIncrementalUpdate);

		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

		unsigned __int16 GetMarketDataSymbolID() const;
		double GetDailyHigh() const;
	};
	/*==========================================================================*/
	struct s_DailyLowIncrementalUpdate
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		unsigned __int16 MarketDataSymbolID;
		double DailyLow;

		s_DailyLowIncrementalUpdate()
		{
			memset(this, 0,sizeof(s_DailyLowIncrementalUpdate));
			Type=DAILY_LOW_INCREMENTAL_UPDATE;
			Size=sizeof(s_DailyLowIncrementalUpdate);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

		unsigned __int16 GetMarketDataSymbolID() const;
		double GetDailyLow() const;
	};
	/*==========================================================================*/

	struct s_SubmitNewSingleOrder
	{

		unsigned __int16 Size;
		unsigned __int16 Type;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		char ClientOrderID[ORDER_ID_LENGTH];

		OrderTypeEnum OrderType;
		BuySellEnum BuySell;

		double Price1;

		double Price2;

		TimeInForceEnum TimeInForce;
		t_DateTime GoodTillDateTimeUnix;
		unsigned __int32 OrderQuantity;
		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		char IsAutomatedOrder;

		char IsParentOrder;

		__int32 Price1AsInteger;
		__int32 Price2AsInteger;
		float Divisor;
		double OrderQuantityAsFloat;

		s_SubmitNewSingleOrder()
		{
			memset(this, 0,sizeof(s_SubmitNewSingleOrder));
			Type=SUBMIT_NEW_SINGLE_ORDER;
			Size=sizeof(s_SubmitNewSingleOrder);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

	};
	/*==========================================================================*/

	struct s_CancelReplaceOrder
	{

		unsigned __int16 Size;
		unsigned __int16 Type;

		char ServerOrderID[ORDER_ID_LENGTH];
		char ClientOrderID[ORDER_ID_LENGTH];

		double Price1;
		double Price2;

		unsigned __int32 OrderQuantity;

		char TradeAccount [TRADE_ACCOUNT_LENGTH];//Not required by DTC

		__int32 Price1AsInteger;
		__int32 Price2AsInteger;
		float Divisor;

		double OrderQuantityAsFloat;

		s_CancelReplaceOrder()
		{
			memset(this, 0,sizeof(s_CancelReplaceOrder));
			Type=CANCEL_REPLACE_ORDER;
			Size=sizeof(s_CancelReplaceOrder);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
	};

	/*==========================================================================*/

	struct s_CancelOrder
	{

		unsigned __int16 Size;
		unsigned __int16 Type;
		
		char ServerOrderID[ORDER_ID_LENGTH];
		char ClientOrderID[ORDER_ID_LENGTH];
		char TradeAccount [TRADE_ACCOUNT_LENGTH];

		char Symbol[SYMBOL_LENGTH];//Not required by DTC
		char Exchange[EXCHANGE_LENGTH];//Not required by DTC

		s_CancelOrder()
		{
			memset(this, 0,sizeof(s_CancelOrder));
			Type=CANCEL_ORDER;
			Size=sizeof(s_CancelOrder);
		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
	};

	/*==========================================================================*/

	struct s_SubmitNewOCOOrder
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		char ClientOrderID_1[ORDER_ID_LENGTH];
		OrderTypeEnum OrderType_1;
		BuySellEnum BuySell_1;
		double Price1_1;
		double Price2_1;
		double OrderQuantity_1;

		char ClientOrderID_2[ORDER_ID_LENGTH];
		OrderTypeEnum OrderType_2;
		BuySellEnum BuySell_2;
		double Price1_2;
		double Price2_2;
		double OrderQuantity_2;

		TimeInForceEnum TimeInForce;
		t_DateTime GoodTillDateTimeUnix;

		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		char IsAutomatedOrder;

		char ParentTriggerClientOrderID[ORDER_ID_LENGTH];

		s_SubmitNewOCOOrder()
		{
			memset(this, 0,sizeof(s_SubmitNewOCOOrder));
			Type=SUBMIT_NEW_OCO_ORDER;
			Size=sizeof(s_SubmitNewOCOOrder);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
	};


	/*==========================================================================*/

	struct s_OpenOrdersRequest
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		__int32 RequestID;

		__int32 RequestAllOpenOrders;
		char ServerOrderID[ORDER_ID_LENGTH];

		s_OpenOrdersRequest()
		{

			memset(this, 0,sizeof(s_OpenOrdersRequest));
			Type=OPEN_ORDERS_REQUEST;
			Size=sizeof(s_OpenOrdersRequest);
			RequestAllOpenOrders = 1;
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
	};
	/*==========================================================================*/

	struct s_HistoricalOrderFillsRequest
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		__int32 RequestID;

		char ServerOrderID[ORDER_ID_LENGTH];

		__int32 NumberOfDays;

		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		s_HistoricalOrderFillsRequest()
		{
			memset(this, 0,sizeof(s_HistoricalOrderFillsRequest));
			Type=HISTORICAL_ORDER_FILLS_REQUEST;
			Size=sizeof(s_HistoricalOrderFillsRequest);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
	};

	/*==========================================================================*/
	
	struct s_CurrentPositionsRequest
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		__int32 RequestID;
		char  TradeAccount[TRADE_ACCOUNT_LENGTH];

		s_CurrentPositionsRequest()
		{
			memset(this, 0,sizeof(s_CurrentPositionsRequest));
			Type=CURRENT_POSITIONS_REQUEST;
			Size=sizeof(s_CurrentPositionsRequest);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

	};

	/*==========================================================================*/
	struct s_CurrentPositionsRequestReject
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		__int32 RequestID;
		char RejectText[TEXT_DESCRIPTION_LENGTH];

		s_CurrentPositionsRequestReject()
		{
			memset(this, 0,sizeof(s_CurrentPositionsRequestReject));
			Type=CURRENT_POSITIONS_REQUEST_REJECT;
			Size=sizeof(s_CurrentPositionsRequestReject);
		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

	};

	/*==========================================================================*/

	struct s_OrderUpdateReport
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		__int32 RequestID;

		__int32 TotalNumberMessages;
		__int32 MessageNumber;

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
		unsigned __int32 OrderQuantity;
		unsigned __int32 FilledQuantity;
		unsigned __int32 RemainingQuantity;
		double AverageFillPrice;

		double LastFillPrice;
		t_DateTime LastFillDateTimeUnix;
		unsigned __int32 LastFillQuantity;
		char UniqueFillExecutionID[64];

		char TradeAccount[TRADE_ACCOUNT_LENGTH];
		char InfoText[TEXT_DESCRIPTION_LENGTH];

		char NoneOrders;
		double OrderQuantityAsFloat;

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
			OrderQuantityAsFloat=DBL_MAX;
		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

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
		double GetOrderQuantity();
		
	};



	/*==========================================================================*/
	struct s_OpenOrdersRequestReject
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		__int32 RequestID;
		char RejectText[TEXT_DESCRIPTION_LENGTH];

		s_OpenOrdersRequestReject()
		{
			memset(this, 0,sizeof(s_OpenOrdersRequestReject));
			Type=OPEN_ORDERS_REQUEST_REJECT;
			Size=sizeof(s_OpenOrdersRequestReject);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
	};
	/*==========================================================================*/

	struct s_HistoricalOrderFillReport
	{

		unsigned __int16 Size;
		unsigned __int16 Type;

		__int32 RequestID; 

		__int32 TotalNumberMessages;

		__int32 MessageNumber;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];
		char ServerOrderID[ORDER_ID_LENGTH];
		BuySellEnum BuySell;
		double FillPrice;
		t_DateTime FillDateTimeUnix;
		unsigned __int32 FillQuantity;
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
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
	};

	/*==========================================================================*/

	struct s_PositionReport
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		__int32 RequestID;

		__int32 TotalNumberMessages;

		__int32 MessageNumber;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		__int32 PositionQuantity;
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
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

		void SetSymbol(const char * NewValue);
		void SetTradeAccount(const char * NewValue);
	};

	/*==========================================================================*/

	struct s_AccountsRequest
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		s_AccountsRequest()
		{
			memset(this, 0,sizeof(s_AccountsRequest));
			Type=ACCOUNTS_REQUEST;
			Size=sizeof(s_AccountsRequest);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
	};


	/*==========================================================================*/
	struct s_AccountListResponse
	{

		unsigned __int16 Size;
		unsigned __int16 Type;

		__int32 TotalNumberMessages;

		__int32 MessageNumber;

		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		s_AccountListResponse()
		{
			memset(this, 0,sizeof(s_AccountListResponse));
			Type=ACCOUNT_LIST_RESPONSE;
			Size=sizeof(s_AccountListResponse);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
	};


	/*==========================================================================*/

	struct s_ExchangeListRequest
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		__int32 RequestID;

		s_ExchangeListRequest()
		{

			memset(this, 0,sizeof(s_ExchangeListRequest));
			Type=EXCHANGE_LIST_REQUEST;
			Size=sizeof(s_ExchangeListRequest);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

	};

	/*==========================================================================*/

	struct s_ExchangeListResponse
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		__int32 RequestID;
		char Exchange[EXCHANGE_LENGTH];
		char FinalMessage;

		s_ExchangeListResponse()
		{
			memset(this, 0,sizeof(s_ExchangeListResponse));
			Type=EXCHANGE_LIST_RESPONSE;
			Size=sizeof(s_ExchangeListResponse);
		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

	};

	/*==========================================================================*/

	struct s_SymbolsForExchangeRequest
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		__int32 RequestID;
		char Exchange[EXCHANGE_LENGTH];

		SecurityTypeEnum SecurityType;

		s_SymbolsForExchangeRequest()
		{

			memset(this, 0,sizeof(s_SymbolsForExchangeRequest));
			Type=SYMBOLS_FOR_EXCHANGE_REQUEST;
			Size=sizeof(s_SymbolsForExchangeRequest);
		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

	};

	/*==========================================================================*/

	struct s_UnderlyingSymbolsForExchangeRequest
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		__int32 RequestID;

		char Exchange[EXCHANGE_LENGTH];

		SecurityTypeEnum SecurityType;

		s_UnderlyingSymbolsForExchangeRequest()
		{
			memset(this, 0,sizeof(s_UnderlyingSymbolsForExchangeRequest));
			Type=UNDERLYING_SYMBOLS_FOR_EXCHANGE_REQUEST;
			Size=sizeof(s_UnderlyingSymbolsForExchangeRequest);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

	};

	/*==========================================================================*/

	struct s_SymbolsForUnderlyingRequest
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		__int32 RequestID;

		char UnderlyingSymbol[UNDERLYING_SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		SecurityTypeEnum SecurityType;

		s_SymbolsForUnderlyingRequest()
		{
			memset(this, 0,sizeof(s_SymbolsForUnderlyingRequest));
			Type=SYMBOLS_FOR_UNDERLYING_REQUEST;
			Size=sizeof(s_SymbolsForUnderlyingRequest);
		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

	};
	/*==========================================================================*/

	struct s_SecurityDefinitionForSymbolRequest
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		__int32 RequestID;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		SecurityTypeEnum SecurityType;

		s_SecurityDefinitionForSymbolRequest()
		{
			memset(this, 0,sizeof(s_SecurityDefinitionForSymbolRequest));
			Type=SECURITY_DEFINITION_FOR_SYMBOL_REQUEST;
			Size=sizeof(s_SecurityDefinitionForSymbolRequest);
		}

		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
		char * GetSymbol();
		void SetSymbol(const char * NewValue);
		char * GetExchange();
		void SetExchange(const char * NewValue);
	};

	/*==========================================================================*/

	struct s_SecurityDefinitionResponse
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		__int32 RequestID;

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
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

		__int32 GetRequestID() const;
		const char* GetSymbol();
		const char* GetExchange();
		SecurityTypeEnum GetSecurityType() const;
		const char* GetSymbolDescription();
		float GetTickSize() const;
		DisplayFormatEnum GetPriceDisplayFormat() const;
		float GetTickCurrencyValue() const;
		char GetFinalMessage() const;
	};


	/*==========================================================================*/

	struct s_AccountBalanceUpdate
	{

		unsigned __int16 Size;
		unsigned __int16 Type;

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
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

		void SetAccountCurrency(const char * NewValue);
		void SetTradeAccount(const char * NewValue);

	};
	/*==========================================================================*/

	struct s_UserMessage
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		char UserMessage[TEXT_MESSAGE_LENGTH];

		char PopupMessage;

		s_UserMessage()
		{
			memset(this, 0,sizeof(s_UserMessage));
			Type=USER_MESSAGE;
			Size=sizeof(s_UserMessage);
			PopupMessage = 1;
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

	};
	/*==========================================================================*/

	struct s_GeneralLogMessage
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		char MessageText[128];

		s_GeneralLogMessage()
		{
			memset(this, 0,sizeof(s_GeneralLogMessage));
			Type=GENERAL_LOG_MESSAGE;
			Size=sizeof(s_GeneralLogMessage);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

	};
	/*==========================================================================*/

	struct s_HistoricalPriceDataRequest
	{
		unsigned __int16 Size;
		unsigned __int16 Type;

		__int32 RequestIdentifier;
		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];
		HistoricalDataIntervalEnum DataInterval;
		t_DateTime StartDateTime;
		t_DateTime EndDateTime;
		unsigned __int32 MaximumDaysToReturn;
		char  UseZLibCompression;

		char DividendAdjustedStockData;
		char DelayedData;

		s_HistoricalPriceDataRequest()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataRequest));
			Type=HISTORICAL_PRICE_DATA_REQUEST;
			Size=sizeof(s_HistoricalPriceDataRequest);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);


		char * GetSymbol();
		void SetSymbol(const char * NewValue);
		char * GetExchange();
		void SetExchange(const char * NewValue);

	};

	/*==========================================================================*/

	struct s_HistoricalPriceDataHeaderResponse
	{
		unsigned __int16 Size;
		unsigned __int16 Type;
		__int32 RequestIdentifier;
		HistoricalDataIntervalEnum DataInterval;

		char RecordsUseZLibCompression;
		
		char NoRecordsToReturn;

		s_HistoricalPriceDataHeaderResponse()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataHeaderResponse));
			Type=HISTORICAL_PRICE_DATA_HEADER_RESPONSE;
			Size=sizeof(s_HistoricalPriceDataHeaderResponse);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

	};
	/*==========================================================================*/

	struct s_HistoricalPriceDataReject
	{
		unsigned __int16 Size;
		unsigned __int16 Type;
		__int32 RequestIdentifier;

		char RejectText[TEXT_DESCRIPTION_LENGTH];

		s_HistoricalPriceDataReject()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataReject));
			Type=HISTORICAL_PRICE_DATA_REJECT;
			Size=sizeof(s_HistoricalPriceDataReject);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

	};

	/*==========================================================================*/

	struct s_HistoricalPriceDataRecordResponse
	{
		unsigned __int16 Size;
		unsigned __int16 Type;
		__int32 RequestIdentifier;

		t_DateTime StartingDateTime;
		double Open;
		double High;
		double Low;
		double Last;
		unsigned __int32 Volume;
		union
		{
			unsigned __int32 OpenInterest;
			unsigned __int32 NumberTrades;
		};
		unsigned __int32 BidVolume;
		unsigned __int32 AskVolume;

		char FinalRecord;

		s_HistoricalPriceDataRecordResponse()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataRecordResponse));
			Type=HISTORICAL_PRICE_DATA_RECORD_RESPONSE;
			Size=sizeof(s_HistoricalPriceDataRecordResponse);
		}

		void Clear()
		{

			RequestIdentifier = 0;
			StartingDateTime = 0;
			Open = 0;
			High = 0;
			Low = 0;
			Last = 0;
			Volume = 0;
			OpenInterest = 0;
			BidVolume = 0;
			AskVolume = 0;
			FinalRecord = 0;
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);

	};

	/*==========================================================================*/

	struct s_HistoricalPriceDataTickRecordResponse
	{
		unsigned __int16 Size;
		unsigned __int16 Type;
		__int32 RequestIdentifier;

		double TradeDateTimeWithMilliseconds;
		BidOrAskEnum BidOrAsk;

		double TradePrice;
		unsigned __int32 TradeVolume;

		char FinalRecord;

		s_HistoricalPriceDataTickRecordResponse()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataTickRecordResponse));
			Type=HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE;
			Size=sizeof(s_HistoricalPriceDataTickRecordResponse);
		}
		
		unsigned __int16 GetMessageSize();
		void CopyFrom(void * p_SourceData);
		void Clear();
	};


#pragma pack()
}