
// Data and Trading Communications Protocol (DTC Protocol)

// This protocol is in the public domain and freely usable by anyone.

// Documentation: http://DTCprotocol.org/index.php?page=doc_DTCMessageDocumentation.php

// The byte ordering is little endian. 

#pragma once

#include <cstdint>

using std::int16_t;   //   signed 16-bit integer
using std::int32_t;   //   signed 32-bit integer
using std::int64_t;   //   signed 64-bit integer
using std::uint16_t;  // unsigned 16-bit integer
using std::uint32_t;  // unsigned 32-bit integer
using std::uint64_t;  // unsigned 64-bit integer

typedef unsigned char byte;


namespace DTC
{
#pragma pack(8)

	// DTC protocol version
	const int32_t CURRENT_VERSION = 6;

	// Text string lengths. 
	const int32_t USERNAME_PASSWORD_LENGTH = 32;
	const int32_t SYMBOL_EXCHANGE_DELIMITER_LENGTH = 4;
	const int32_t SYMBOL_LENGTH = 64;
	const int32_t EXCHANGE_LENGTH= 16;
	const int32_t UNDERLYING_SYMBOL_LENGTH= 32;
	const int32_t SYMBOL_DESCRIPTION_LENGTH = 48;
	const int32_t EXCHANGE_DESCRIPTION_LENGTH = 48;
	const int32_t ORDER_ID_LENGTH = 32;
	const int32_t TRADE_ACCOUNT_LENGTH = 32;
	const int32_t TEXT_DESCRIPTION_LENGTH = 96;
	const int32_t TEXT_MESSAGE_LENGTH = 256;
	const int32_t ORDER_FREE_FORM_TEXT_LENGTH = 48;
	const int32_t CLIENT_SERVER_NAME_LENGTH = 48;
	const int32_t GENERAL_IDENTIFIER_LENGTH = 64;

	//----Message types----

	// Authentication and connection monitoring
	const uint16_t LOGON_REQUEST = 1;
	const uint16_t LOGON_RESPONSE = 2;
	const uint16_t HEARTBEAT = 3;
	const uint16_t LOGOFF = 5;
	const uint16_t ENCODING_REQUEST = 6;
	const uint16_t ENCODING_RESPONSE = 7;

	// Market data
	const uint16_t MARKET_DATA_REQUEST = 101;
	const uint16_t MARKET_DATA_REJECT = 103;
	const uint16_t MARKET_DATA_SNAPSHOT = 104;
	const uint16_t MARKET_DATA_SNAPSHOT_INT = 125;

	const uint16_t MARKET_DATA_UPDATE_TRADE = 107;
	const uint16_t MARKET_DATA_UPDATE_TRADE_COMPACT = 112;
	const uint16_t MARKET_DATA_UPDATE_TRADE_INT = 126;
	const uint16_t MARKET_DATA_UPDATE_LAST_TRADE_SNAPSHOT = 134;

	const uint16_t MARKET_DATA_UPDATE_BID_ASK = 108;
	const uint16_t MARKET_DATA_UPDATE_BID_ASK_COMPACT = 117;
	const uint16_t MARKET_DATA_UPDATE_BID_ASK_INT = 127;

	const uint16_t MARKET_DATA_UPDATE_DAILY_OPEN = 120;
	const uint16_t MARKET_DATA_UPDATE_DAILY_OPEN_INT = 128;
	const uint16_t MARKET_DATA_UPDATE_DAILY_HIGH = 114;
	const uint16_t MARKET_DATA_UPDATE_DAILY_HIGH_INT = 129;
	const uint16_t MARKET_DATA_UPDATE_DAILY_LOW = 115;
	const uint16_t MARKET_DATA_UPDATE_DAILY_LOW_INT = 130;
	const uint16_t MARKET_DATA_UPDATE_DAILY_VOLUME = 113;
	const uint16_t MARKET_DATA_UPDATE_OPEN_INTEREST = 124;
	const uint16_t MARKET_DATA_UPDATE_DAILY_SETTLEMENT = 119;
	const uint16_t MARKET_DATA_UPDATE_DAILY_SETTLEMENT_INT = 131;

	const uint16_t MARKET_DEPTH_REQUEST = 102;
	const uint16_t MARKET_DEPTH_REJECT = 121;
	const uint16_t MARKET_DEPTH_SNAPSHOT_LEVEL = 122;
	const uint16_t MARKET_DEPTH_SNAPSHOT_LEVEL_INT = 132;
	const uint16_t MARKET_DEPTH_UPDATE_LEVEL = 106;
	const uint16_t MARKET_DEPTH_UPDATE_LEVEL_COMPACT = 118;
	const uint16_t MARKET_DEPTH_UPDATE_LEVEL_INT = 133;
	const uint16_t MARKET_DEPTH_FULL_UPDATE_10 = 123;
	const uint16_t MARKET_DEPTH_FULL_UPDATE_20 = 105;

	const uint16_t FUNDAMENTAL_DATA_REQUEST = 109;
	const uint16_t FUNDAMENTAL_DATA_RESPONSE = 110;

	const uint16_t MARKET_DATA_FEED_STATUS = 100;
	const uint16_t MARKET_DATA_FEED_SYMBOL_STATUS = 116;

	// Order entry and modification
	const uint16_t SUBMIT_NEW_SINGLE_ORDER = 208;
	const uint16_t SUBMIT_NEW_SINGLE_ORDER_INT = 206;

	const uint16_t SUBMIT_NEW_OCO_ORDER = 201;
	const uint16_t SUBMIT_NEW_OCO_ORDER_INT = 207;

	const uint16_t CANCEL_ORDER = 203;

	const uint16_t CANCEL_REPLACE_ORDER = 204;
	const uint16_t CANCEL_REPLACE_ORDER_INT = 205;

	// Trading related
	const uint16_t OPEN_ORDERS_REQUEST = 300;
	const uint16_t OPEN_ORDERS_REJECT = 302;

	const uint16_t ORDER_UPDATE = 301;

	const uint16_t HISTORICAL_ORDER_FILLS_REQUEST = 303;
	const uint16_t HISTORICAL_ORDER_FILL_RESPONSE = 304;

	const uint16_t CURRENT_POSITIONS_REQUEST = 305;
	const uint16_t CURRENT_POSITIONS_REJECT = 307;

	const uint16_t POSITION_UPDATE = 306;

	// Account list
	const uint16_t TRADE_ACCOUNTS_REQUEST = 400;
	const uint16_t TRADE_ACCOUNT_RESPONSE = 401;

	// Symbol discovery and security definitions
	const uint16_t EXCHANGE_LIST_REQUEST = 500;
	const uint16_t EXCHANGE_LIST_RESPONSE = 501;

	const uint16_t SYMBOLS_FOR_EXCHANGE_REQUEST = 502;
	const uint16_t UNDERLYING_SYMBOLS_FOR_EXCHANGE_REQUEST = 503;
	const uint16_t SYMBOLS_FOR_UNDERLYING_REQUEST = 504;
	const uint16_t SECURITY_DEFINITION_FOR_SYMBOL_REQUEST = 506;
	const uint16_t SECURITY_DEFINITION_RESPONSE = 507;

	const uint16_t SYMBOL_SEARCH_BY_DESCRIPTION = 508;

	// Account balance
	const uint16_t ACCOUNT_BALANCE_REQUEST = 601;
	const uint16_t ACCOUNT_BALANCE_REJECT = 602;	
	const uint16_t ACCOUNT_BALANCE_UPDATE = 600;

	// Logging
	const uint16_t USER_MESSAGE = 700;
	const uint16_t GENERAL_LOG_MESSAGE = 701;

	// Historical price data
	const uint16_t HISTORICAL_PRICE_DATA_REQUEST= 800;
	const uint16_t HISTORICAL_PRICE_DATA_RESPONSE_HEADER = 801;
	const uint16_t HISTORICAL_PRICE_DATA_REJECT = 802;
	const uint16_t HISTORICAL_PRICE_DATA_RECORD_RESPONSE = 803;
	const uint16_t HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE = 804;
	const uint16_t HISTORICAL_PRICE_DATA_RECORD_RESPONSE_INT = 805;
	const uint16_t HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE_INT = 806;

	/*==========================================================================*/
	//Standard UNIX Date-Time value
	typedef int64_t t_DateTime;

	// This is a 4 byte UNIX Date-Time value used in messages where compactness is an important consideration. Or, where only the Date is needed.
	typedef uint32_t t_DateTime4Byte;

	//UNIX Date-Time value with fractional portion for milliseconds.
	typedef double t_DateTimeWithMilliseconds;

	/*==========================================================================*/
	enum EncodingEnum : int32_t
	{ BINARY_ENCODING = 0
	, BINARY_WITH_VARIABLE_LENGTH_STRINGS = 1
	, JSON_ENCODING = 2
	, JSON_COMPACT_ENCODING = 3
	};

	/*==========================================================================*/
	enum LogonStatusEnum : int32_t
	{ LOGON_SUCCESS = 1
	, LOGON_ERROR = 2
	, LOGON_ERROR_NO_RECONNECT = 3
	, LOGON_RECONNECT_NEW_ADDRESS = 4
	};

	/*==========================================================================*/
	enum MessageSupportedEnum : int32_t
	{ MESSAGE_UNSUPPORTED = 0
	, MESSAGE_SUPPORTED = 1
	};

	/*==========================================================================*/
	enum TradeModeEnum : int32_t
	{ TRADE_MODE_DEMO = 1
	, TRADE_MODE_SIMULATED = 2
	, TRADE_MODE_LIVE = 3
	};

	/*==========================================================================*/
	enum RequestActionEnum : int32_t
	{ SUBSCRIBE = 1
	, UNSUBSCRIBE = 2
	, SNAPSHOT = 3
	};

	/*==========================================================================*/
	enum OrderStatusEnum : int32_t
	{ ORDER_STATUS_UNSPECIFIED = 0
	, ORDER_STATUS_ORDER_SENT = 1
	, ORDER_STATUS_PENDING_OPEN = 2
	, ORDER_STATUS_PENDING_CHILD = 3
	, ORDER_STATUS_OPEN = 4
	, ORDER_STATUS_PENDING_CANCEL_REPLACE = 5
	, ORDER_STATUS_PENDING_CANCEL = 6
	, ORDER_STATUS_FILLED = 7
	, ORDER_STATUS_CANCELED = 8
	, ORDER_STATUS_REJECTED = 9
	};

	/*==========================================================================*/
	enum OrderUpdateReasonEnum : int32_t
	{ ORDER_UPDATE_REASON_UNSET = 0
	, OPEN_ORDERS_REQUEST_RESPONSE = 1
	, NEW_ORDER_ACCEPTED = 2
	, GENERAL_ORDER_UPDATE = 3
	, ORDER_FILLED = 4
	, ORDER_FILLED_PARTIALLY = 5
	, ORDER_CANCELED = 6
	, ORDER_CANCEL_REPLACE_COMPLETE = 7
	, NEW_ORDER_REJECTED = 8
	, ORDER_CANCEL_REJECTED = 9
	, ORDER_CANCEL_REPLACE_REJECTED = 10
	};
	
	/*==========================================================================*/
	enum AtBidOrAskEnum : uint16_t
	{ BID_ASK_UNSET = 0
	, AT_BID = 1
	, AT_ASK = 2
	};
	
	/*==========================================================================*/
	enum MarketDepthUpdateTypeEnum : byte
	{ DEPTH_UNSET = 0
	, MARKET_DEPTH_INSERT_UPDATE_LEVEL = 1 // Insert or update depth at the given price level
	, MARKET_DEPTH_DELETE_LEVEL = 2 // Delete depth at the given price level
	};
	
	/*==========================================================================*/
	enum OrderTypeEnum : int32_t
	{ ORDER_TYPE_UNSET = 0
	, ORDER_TYPE_MARKET = 1
	, ORDER_TYPE_LIMIT = 2
	, ORDER_TYPE_STOP = 3
	, ORDER_TYPE_STOP_LIMIT = 4
	, ORDER_TYPE_MARKET_IF_TOUCHED = 5
	};
	
	/*==========================================================================*/
	enum TimeInForceEnum : int32_t
	{ TIF_UNSET = 0
	, TIF_DAY = 1
	, TIF_GOOD_TILL_CANCELED = 2
	, TIF_GOOD_TILL_DATE_TIME = 3
	, TIF_IMMEDIATE_OR_CANCEL = 4
	, TIF_ALL_OR_NONE = 5
	, TIF_FILL_OR_KILL = 6
	};
	
	/*==========================================================================*/
	enum BuySellEnum : int32_t
	{ BUY_SELL_UNSET = 0
	, BUY = 1
	, SELL = 2
	};

	/*==========================================================================*/
	enum OpenCloseTradeEnum : int32_t
	{ TRADE_UNSET = 0
	, TRADE_OPEN = 1
	, TRADE_CLOSE = 2
	};

	/*==========================================================================*/
	enum MarketDataFeedStatusEnum : int32_t
	{ MARKET_DATA_FEED_UNAVAILABLE = 1
	, MARKET_DATA_FEED_AVAILABLE = 2
	};

	/*==========================================================================*/
	enum PriceDisplayFormatEnum : int32_t
	{ PRICE_DISPLAY_FORMAT_UNSET =  -1
	//The following formats indicate the number of decimal places to be displayed
	, PRICE_DISPLAY_FORMAT_DECIMAL_0 = 0
	, PRICE_DISPLAY_FORMAT_DECIMAL_1 = 1
	, PRICE_DISPLAY_FORMAT_DECIMAL_2 = 2
	, PRICE_DISPLAY_FORMAT_DECIMAL_3 = 3
	, PRICE_DISPLAY_FORMAT_DECIMAL_4 = 4
	, PRICE_DISPLAY_FORMAT_DECIMAL_5 = 5
	, PRICE_DISPLAY_FORMAT_DECIMAL_6 = 6
	, PRICE_DISPLAY_FORMAT_DECIMAL_7 = 7
	, PRICE_DISPLAY_FORMAT_DECIMAL_8 = 8
	, PRICE_DISPLAY_FORMAT_DECIMAL_9 = 9
	//The following formats are fractional formats
	, PRICE_DISPLAY_FORMAT_DENOMINATOR_256 = 356
	, PRICE_DISPLAY_FORMAT_DENOMINATOR_128 = 228
	, PRICE_DISPLAY_FORMAT_DENOMINATOR_64 = 164
	, PRICE_DISPLAY_FORMAT_DENOMINATOR_32_QUARTERS = 136
	, PRICE_DISPLAY_FORMAT_DENOMINATOR_32_HALVES = 134
	, PRICE_DISPLAY_FORMAT_DENOMINATOR_32 = 132 
	, PRICE_DISPLAY_FORMAT_DENOMINATOR_16 = 116
	, PRICE_DISPLAY_FORMAT_DENOMINATOR_8 = 108
	, PRICE_DISPLAY_FORMAT_DENOMINATOR_4 = 104
	, PRICE_DISPLAY_FORMAT_DENOMINATOR_2 = 102
	};

	/*==========================================================================*/
	enum SecurityTypeEnum : int32_t
	{ SECURITY_TYPE_UNSET = 0
	, SECURITY_TYPE_FUTURE = 1
	, SECURITY_TYPE_STOCK = 2
	, SECURITY_TYPE_FOREX = 3 // Bitcoins also go into this category
	, SECURITY_TYPE_INDEX = 4
	, SECURITY_TYPE_FUTURES_STRATEGY = 5
	, SECURITY_TYPE_FUTURES_OPTION = 7
	, SECURITY_TYPE_STOCK_OPTION = 6
	, SECURITY_TYPE_INDEX_OPTION = 8
	, SECURITY_TYPE_BOND = 9
	, SECURITY_TYPE_MUTUAL_FUND = 10
	};
	
	/*==========================================================================*/
	enum HistoricalDataIntervalEnum : int32_t
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
	struct s_EncodingRequest
	{
		uint16_t Size;
		uint16_t Type;
		int32_t ProtocolVersion;
		EncodingEnum Encoding;

		s_EncodingRequest()
		{
			memset(this, 0,sizeof(s_EncodingRequest));
			Type=ENCODING_REQUEST;
			Size=sizeof(s_EncodingRequest);
			ProtocolVersion = CURRENT_VERSION;
			Encoding = BINARY_ENCODING;
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);		
		int32_t GetProtocolVersion();
		EncodingEnum GetEncoding();
	};

	/*==========================================================================*/
	struct s_EncodingResponse
	{
		uint16_t Size;
		uint16_t Type;
		int32_t ProtocolVersion;
		EncodingEnum Encoding;

		s_EncodingResponse()
		{
			memset(this, 0,sizeof(s_EncodingResponse));
			Type=ENCODING_RESPONSE;
			Size=sizeof(s_EncodingResponse);
			ProtocolVersion = CURRENT_VERSION;
			Encoding = BINARY_ENCODING;
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		int32_t GetProtocolVersion();
		EncodingEnum GetEncoding();
	};

	/*==========================================================================*/
	struct s_LogonRequest
	{
		uint16_t Size;
		uint16_t Type;
		int32_t ProtocolVersion;
		char Username[USERNAME_PASSWORD_LENGTH];
		char Password[USERNAME_PASSWORD_LENGTH];
		char GeneralTextData[GENERAL_IDENTIFIER_LENGTH];
		int32_t Integer_1;
		int32_t Integer_2;
		int32_t  HeartbeatIntervalInSeconds; 
		TradeModeEnum TradeMode;
		char TradeAccount[TRADE_ACCOUNT_LENGTH]; 
		char HardwareIdentifier[GENERAL_IDENTIFIER_LENGTH];
		char ClientName[32];

		s_LogonRequest()
		{
			memset(this, 0,sizeof(s_LogonRequest));
			Type=LOGON_REQUEST;
			Size=sizeof(s_LogonRequest);
			ProtocolVersion = CURRENT_VERSION;
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);		
		int32_t GetProtocolVersion();
		const char* GetUsername();
		void SetUsername(const char* NewValue);
		const char* GetPassword();
		void SetPassword(const char* NewValue);
		const char* GetGeneralTextData();
		void SetGeneralTextData(const char* NewValue);
		int32_t GetInteger_1();
		int32_t GetInteger_2();
		int32_t GetHeartbeatIntervalInSeconds();
		TradeModeEnum GetTradeMode();
		const char* GetTradeAccount();
		void SetTradeAccount(const char* NewValue);
		const char* GetHardwareIdentifier();
		void SetHardwareIdentifier(const char* NewValue);
		const char* GetClientName();
		void SetClientName(const char* NewValue);
	};

	/*==========================================================================*/
	struct s_LogonResponse
	{
		uint16_t Size;
		uint16_t Type;
		int32_t ProtocolVersion;
		LogonStatusEnum Result;
		char ResultText[TEXT_DESCRIPTION_LENGTH];
		char ReconnectAddress [64];
		int32_t Integer_1;
		char ServerName[60];
		byte MarketDepthUpdatesBestBidAndAsk;
		byte TradingIsSupported;
		byte OCOOrdersSupported;
		byte OrderCancelReplaceSupported;
		char SymbolExchangeDelimiter[SYMBOL_EXCHANGE_DELIMITER_LENGTH];
		byte SecurityDefinitionsSupported;
		byte HistoricalPriceDataSupported;
		byte ResubscribeWhenMarketDataFeedAvailable;
		byte MarketDepthIsSupported;
		byte OneHistoricalPriceDataRequestPerConnection;
		byte BracketOrdersSupported;
		byte UseIntegerPriceOrderMessages;

		s_LogonResponse()
		{
			memset(this, 0,sizeof(s_LogonResponse));
			Type=LOGON_RESPONSE;
			Size=sizeof(s_LogonResponse);
			ProtocolVersion = CURRENT_VERSION;
			OrderCancelReplaceSupported = 1;
			MarketDepthIsSupported = 1;
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		int32_t GetProtocolVersion();
		LogonStatusEnum GetResult();
		const char* GetResultText();
		void SetResultText(const char* NewValue);
		const char* GetReconnectAddress();
		void SetReconnectAddress(const char* NewValue);
		int32_t GetInteger_1();
		const char* GetServerName();
		void SetServerName(const char* NewValue);		
		byte GetMarketDepthUpdatesBestBidAndAsk();
		byte GetTradingIsSupported();
		byte GetOCOOrdersSupported();
		byte GetOrderCancelReplaceSupported();
		const char* GetSymbolExchangeDelimiter();
		void SetSymbolExchangeDelimiter(const char* NewValue);
		byte GetSecurityDefinitionsSupported();
		byte GetHistoricalPriceDataSupported();
		byte GetResubscribeWhenMarketDataFeedAvailable();
		byte GetMarketDepthIsSupported();
		byte GetOneHistoricalPriceDataRequestPerConnection();
		byte GetUseIntegerPriceOrderMessages();
		byte GetBracketOrdersSupported();
	};

	/*==========================================================================*/
	struct s_Logoff
	{
		uint16_t Size;
		uint16_t Type;
		char Reason[TEXT_DESCRIPTION_LENGTH];
		byte DoNotReconnect;

		s_Logoff()
		{
			memset(this, 0, sizeof(s_Logoff));
			Type = LOGOFF;
			Size=sizeof(s_Logoff);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		const char* GetReason();
		void SetReason(const char* NewValue);
		byte GetDoNotReconnect();

	};

	/*==========================================================================*/
	struct s_Heartbeat
	{
		uint16_t Size;
		uint16_t Type;
		uint32_t NumDroppedMessages;
		t_DateTime CurrentDateTime;

		s_Heartbeat()
		{
			memset(this, 0,sizeof(s_Heartbeat));
			Type=HEARTBEAT;
			Size=sizeof(s_Heartbeat);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		uint32_t GetNumDroppedMessages();
		t_DateTime GetCurrentDateTime();
	};

	/*==========================================================================*/
	struct s_MarketDataFeedStatus
	{
		uint16_t Size;
		uint16_t Type;
		MarketDataFeedStatusEnum Status;

		s_MarketDataFeedStatus()
		{
			memset(this, 0,sizeof(s_MarketDataFeedStatus));
			Type=MARKET_DATA_FEED_STATUS;
			Size=sizeof(s_MarketDataFeedStatus);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		MarketDataFeedStatusEnum GetStatus();
	};

	/*==========================================================================*/
	struct s_MarketDataFeedSymbolStatus
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t SymbolID;
		MarketDataFeedStatusEnum Status;

		s_MarketDataFeedSymbolStatus()
		{
			memset(this, 0,sizeof(s_MarketDataFeedSymbolStatus));
			Type=MARKET_DATA_FEED_SYMBOL_STATUS;
			Size=sizeof(s_MarketDataFeedSymbolStatus);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		uint16_t GetSymbolID();
		MarketDataFeedStatusEnum GetStatus();
	};
	
	/*==========================================================================*/
	struct s_MarketDataRequest
	{
		uint16_t Size;
		uint16_t Type;
		RequestActionEnum RequestAction;
		uint16_t SymbolID;
		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		s_MarketDataRequest()
		{
			memset(this, 0,sizeof(s_MarketDataRequest));
			Type=MARKET_DATA_REQUEST;
			Size=sizeof(s_MarketDataRequest);
			RequestAction=SUBSCRIBE;
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		RequestActionEnum GetRequestAction();
		uint16_t GetSymbolID();
		const char* GetSymbol();
		void SetSymbol(const char* NewValue);
		const char* GetExchange();
		void SetExchange(const char* NewValue);
	};

	/*==========================================================================*/
	struct s_MarketDepthRequest
	{
		uint16_t Size;
		uint16_t Type;
		RequestActionEnum RequestAction;
		uint16_t SymbolID;
		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];
		int32_t NumLevels;

		s_MarketDepthRequest()
		{
			memset(this, 0,sizeof(s_MarketDepthRequest));
			Type=MARKET_DEPTH_REQUEST;
			Size=sizeof(s_MarketDepthRequest);

			RequestAction=SUBSCRIBE;
			NumLevels= 10;
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		RequestActionEnum GetRequestAction();
		uint16_t GetSymbolID();
		const char* GetSymbol();
		void SetSymbol(const char* NewValue);
		const char* GetExchange();
		void SetExchange(const char* NewValue);
		int32_t GetNumLevels();
	};

	/*==========================================================================*/
	struct s_MarketDataReject
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t SymbolID;
		char RejectText[TEXT_DESCRIPTION_LENGTH];

		s_MarketDataReject()
		{
			memset(this, 0,sizeof(s_MarketDataReject));
			Type=MARKET_DATA_REJECT;
			Size=sizeof(s_MarketDataReject);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		uint16_t GetSymbolID();
		const char* GetRejectText();
		void SetRejectText(const char* NewValue);
	};

	/*==========================================================================*/
	struct s_MarketDataSnapshot
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t SymbolID;
		double DailySettlementPrice;
		double DailyOpenPrice;
		double DailyHighPrice;
		double DailyLowPrice;
		double DailyVolume;
		uint32_t DailyNumTrades;
		union
		{
			uint32_t SharesOutstanding;
			uint32_t OpenInterest;
			uint32_t UnitsOutstanding;
		};

		double BidPrice;
		double AskPrice;
		double AskQuantity;
		double BidQuantity;
		double LastTradePrice;
		double LastTradeVolume;
		t_DateTimeWithMilliseconds LastTradeDateTime;
		t_DateTimeWithMilliseconds BidAskDateTime;

		s_MarketDataSnapshot()
		{
			memset(this, 0,sizeof(s_MarketDataSnapshot));
			Type=MARKET_DATA_SNAPSHOT;
			Size=sizeof(s_MarketDataSnapshot);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		uint16_t GetSymbolID();
		double GetDailySettlementPrice();
		double GetDailyOpenPrice();
		double GetDailyHighPrice();
		double GetDailyLowPrice();
		double GetDailyVolume();
		uint32_t GetDailyNumTrades();
		uint32_t GetSharesOutstanding();
		uint32_t GetOpenInterest();
		uint32_t GetUnitsOutstanding();
		double GetBidPrice();
		double GetAskPrice();
		double GetAskQuantity();
		double GetBidQuantity();
		double GetLastTradePrice();
		double GetLastTradeVolume();
		t_DateTimeWithMilliseconds GetLastTradeDateTime();
		t_DateTimeWithMilliseconds GetBidAskDateTime();
		void SetToUnsetValues();
	};

	/*==========================================================================*/
	struct s_MarketDataSnapshot_Int
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t SymbolID;
		int32_t DailySettlementPrice;
		int32_t DailyOpenPrice;
		int32_t DailyHighPrice;
		int32_t DailyLowPrice;
		int32_t DailyVolume;
		uint32_t DailyNumTrades;
		union
		{
			uint32_t SharesOutstanding;
			uint32_t OpenInterest;
			uint32_t UnitsOutstanding;
		};

		int32_t BidPrice;
		int32_t AskPrice;
		int32_t AskQuantity;
		int32_t BidQuantity;
		int32_t LastTradePrice;
		int32_t LastTradeVolume;
		t_DateTimeWithMilliseconds LastTradeDateTime;
		t_DateTimeWithMilliseconds BidAskDateTime;

		s_MarketDataSnapshot_Int()
		{
			memset(this, 0,sizeof(s_MarketDataSnapshot_Int));
			Type=MARKET_DATA_SNAPSHOT_INT;
			Size=sizeof(s_MarketDataSnapshot_Int);
			SetToUnsetValues();
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		uint16_t GetSymbolID();
		int32_t GetDailySettlementPrice();
		int32_t GetDailyOpenPrice();
		int32_t GetDailyHighPrice();
		int32_t GetDailyLowPrice();
		int32_t GetDailyVolume();
		uint32_t GetDailyNumTrades();
		uint32_t GetSharesOutstanding();
		uint32_t GetOpenInterest();
		uint32_t GetUnitsOutstanding();
		int32_t GetBidPrice();
		int32_t GetAskPrice();
		int32_t GetAskQuantity();
		int32_t GetBidQuantity();
		int32_t GetLastTradePrice();
		int32_t GetLastTradeVolume();
		t_DateTimeWithMilliseconds GetLastTradeDateTime();
		t_DateTimeWithMilliseconds GetBidAskDateTime();
		void SetToUnsetValues();
	};

	/*==========================================================================*/
	struct s_FundamentalDataRequest
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t SymbolID;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		s_FundamentalDataRequest()
		{
			memset(this, 0,sizeof(s_FundamentalDataRequest));
			Type=FUNDAMENTAL_DATA_REQUEST;
			Size=sizeof(s_FundamentalDataRequest);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		uint16_t GetSymbolID();

		const char* GetSymbol();
		void SetSymbol(const char* NewValue);
		const char* GetExchange();
		void SetExchange(const char* NewValue);
	};

	/*==========================================================================*/
	struct s_FundamentalDataResponse
	{
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;
		char SymbolDescription[SYMBOL_DESCRIPTION_LENGTH];
		float MinPriceIncrement;
		float CurrencyValuePerIncrement;
		PriceDisplayFormatEnum PriceDisplayFormat;
		float BuyRolloverInterest;
		float SellRolloverInterest;
		float OrderIntPriceMultiplier;
		float MarketDataIntPriceDivisor;
		SecurityTypeEnum SecurityType;

		t_DateTime4Byte SecurityExpirationDate;

		uint16_t ShortInterest;

		float EarningsPerShare;

		float DividendYield;
		float DividendAmount;
		t_DateTime4Byte ExDividendDate;

		float StrikePrice;//For options

		s_FundamentalDataResponse()
		{
			memset(this, 0,sizeof(s_FundamentalDataResponse));
			Type=FUNDAMENTAL_DATA_RESPONSE;
			Size=sizeof(s_FundamentalDataResponse);
			PriceDisplayFormat = PRICE_DISPLAY_FORMAT_UNSET;
			//OrderIntPriceMultiplier = 1.0f;
			//MarketDataIntPriceDivisor = 1.0f;
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		uint16_t GetSymbolID();
		const char* GetSymbolDescription();
		void SetSymbolDescription(const char* NewValue);
		float GetMinPriceIncrement();
		float GetCurrencyValuePerIncrement();
		PriceDisplayFormatEnum GetPriceDisplayFormat();
		float GetBuyRolloverInterest();
		float GetSellRolloverInterest();
		float GetOrderIntPriceMultiplier();
		float GetMarketDataIntPriceDivisor();
		SecurityTypeEnum GetSecurityType();
		t_DateTime4Byte GetSecurityExpirationDate();
		uint16_t GetShortInterest();
		float GetEarningsPerShare();
		float GetDividendYield();
		float GetDividendAmount();
		t_DateTime4Byte GetExDividendDate();
		float GetStrikePrice();
	};

	struct s_DepthEntry
	{
		double Price;
		float Quantity;
	};

	/*==========================================================================*/
	struct s_MarketDepthFullUpdate20
	{
		static const int32_t NUM_DEPTH_LEVELS = 20;

		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;

		s_DepthEntry BidDepth[NUM_DEPTH_LEVELS];
		s_DepthEntry AskDepth[NUM_DEPTH_LEVELS];


		s_MarketDepthFullUpdate20()
		{
			memset(this, 0,sizeof(s_MarketDepthFullUpdate20));
			Type=MARKET_DEPTH_FULL_UPDATE_20;
			Size=sizeof(s_MarketDepthFullUpdate20);
		}
	
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint16_t GetSymbolID();	
	};

	/*==========================================================================*/
	struct s_MarketDepthFullUpdate10
	{
		static const int32_t NUM_DEPTH_LEVELS = 10;

		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;

		s_DepthEntry BidDepth[NUM_DEPTH_LEVELS];
		s_DepthEntry AskDepth[NUM_DEPTH_LEVELS];


		s_MarketDepthFullUpdate10()
		{
			memset(this, 0,sizeof(s_MarketDepthFullUpdate10));
			Type=MARKET_DEPTH_FULL_UPDATE_10;
			Size=sizeof(s_MarketDepthFullUpdate10);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint16_t GetSymbolID();
	};

	/*==========================================================================*/
	struct s_MarketDepthSnapshotLevel
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t SymbolID;
		AtBidOrAskEnum Side;
		double Price;
		double Quantity;
		uint16_t  Level;

		byte IsFirstMessageInBatch;
		byte IsLastMessageInBatch;


		s_MarketDepthSnapshotLevel()
		{
			memset(this, 0,sizeof(s_MarketDepthSnapshotLevel));
			Type=MARKET_DEPTH_SNAPSHOT_LEVEL;
			Size=sizeof(s_MarketDepthSnapshotLevel);

		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint16_t GetSymbolID();
		AtBidOrAskEnum GetSide();
		double GetPrice();
		double GetQuantity();
		uint16_t GetLevel();
		byte GetIsFirstMessageInBatch();
		byte GetIsLastMessageInBatch();
	};

	/*==========================================================================*/
	struct s_MarketDepthSnapshotLevel_Int
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t SymbolID;
		AtBidOrAskEnum Side;
		int32_t Price;
		int32_t Quantity;
		uint16_t  Level;

		byte IsFirstMessageInBatch;
		byte IsLastMessageInBatch;


		s_MarketDepthSnapshotLevel_Int()
		{
			memset(this, 0,sizeof(s_MarketDepthSnapshotLevel_Int));
			Type=MARKET_DEPTH_SNAPSHOT_LEVEL_INT;
			Size=sizeof(s_MarketDepthSnapshotLevel_Int);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint16_t GetSymbolID();
		AtBidOrAskEnum GetSide();
		int32_t GetPrice();
		int32_t GetQuantity();
		uint16_t GetLevel();
		byte GetIsFirstMessageInBatch();
		byte GetIsLastMessageInBatch();
	};

	/*==========================================================================*/
	struct s_MarketDepthUpdateLevel
	{	 
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;
		AtBidOrAskEnum Side;
		double Price;
		double Quantity;

		MarketDepthUpdateTypeEnum UpdateType;

		s_MarketDepthUpdateLevel()
		{

			memset(this, 0,sizeof(s_MarketDepthUpdateLevel));
			Type=MARKET_DEPTH_UPDATE_LEVEL;
			Size=sizeof(s_MarketDepthUpdateLevel);

		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		uint16_t GetSymbolID();
		AtBidOrAskEnum GetSide();
		double GetPrice();
		double GetQuantity();
		MarketDepthUpdateTypeEnum GetUpdateType();
	};

	/*==========================================================================*/
	struct s_MarketDepthUpdateLevel_Int
	{	 
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;
		AtBidOrAskEnum Side;
		int32_t Price;
		int32_t Quantity;

		MarketDepthUpdateTypeEnum UpdateType;

		s_MarketDepthUpdateLevel_Int()
		{

			memset(this, 0,sizeof(s_MarketDepthUpdateLevel_Int));
			Type=MARKET_DEPTH_UPDATE_LEVEL_INT;
			Size=sizeof(s_MarketDepthUpdateLevel_Int);

		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		uint16_t GetSymbolID();
		AtBidOrAskEnum GetSide();
		int32_t GetPrice();
		int32_t GetQuantity();
		MarketDepthUpdateTypeEnum GetUpdateType();        
	};

	/*==========================================================================*/
	struct s_MarketDepthUpdateLevelCompact
	{	 
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;
		AtBidOrAskEnum Side;
		float Price;
		float Quantity;

		MarketDepthUpdateTypeEnum UpdateType;

		s_MarketDepthUpdateLevelCompact()
		{
			memset(this, 0,sizeof(s_MarketDepthUpdateLevelCompact));
			Type=MARKET_DEPTH_UPDATE_LEVEL_COMPACT;
			Size=sizeof(s_MarketDepthUpdateLevelCompact);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint16_t GetSymbolID() const;
		AtBidOrAskEnum GetSide() const;
		float GetPrice() const;
		float GetQuantity() const;
		MarketDepthUpdateTypeEnum GetUpdateType() const;
	};

	/*==========================================================================*/
	struct s_MarketDataUpdateDailySettlement
	{
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;
		double Price;

		s_MarketDataUpdateDailySettlement()
		{
			memset(this, 0, sizeof(s_MarketDataUpdateDailySettlement));
			Type = MARKET_DATA_UPDATE_DAILY_SETTLEMENT;
			Size = sizeof(s_MarketDataUpdateDailySettlement);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint16_t GetSymbolID() const;
		double GetPrice() const;
	};

	/*==========================================================================*/
	struct s_MarketDataUpdateDailySettlement_Int
	{
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;
		int32_t Price;

		s_MarketDataUpdateDailySettlement_Int()
		{
			memset(this, 0, sizeof(s_MarketDataUpdateDailySettlement_Int));
			Type = MARKET_DATA_UPDATE_DAILY_SETTLEMENT_INT;
			Size = sizeof(s_MarketDataUpdateDailySettlement_Int);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint16_t GetSymbolID() const;
		int32_t GetPrice() const;
	};

	/*==========================================================================*/
	struct s_MarketDataUpdateDailyOpen
	{
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;
		double Price;

		s_MarketDataUpdateDailyOpen()
		{
			memset(this, 0, sizeof(s_MarketDataUpdateDailyOpen));
			Type = MARKET_DATA_UPDATE_DAILY_OPEN;
			Size = sizeof(s_MarketDataUpdateDailyOpen);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint16_t GetSymbolID() const;
		double GetPrice() const;
	};

	/*==========================================================================*/
	struct s_MarketDataUpdateDailyOpen_Int
	{
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;
		int32_t Price;

		s_MarketDataUpdateDailyOpen_Int()
		{
			memset(this, 0, sizeof(s_MarketDataUpdateDailyOpen_Int));
			Type = MARKET_DATA_UPDATE_DAILY_OPEN_INT;
			Size = sizeof(s_MarketDataUpdateDailyOpen_Int);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint16_t GetSymbolID() const;
		int32_t GetPrice() const;
	};

	/*==========================================================================*/
	struct s_MarketDepthReject
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t SymbolID;
		char RejectText[TEXT_DESCRIPTION_LENGTH];

		s_MarketDepthReject()
		{
			memset(this, 0, sizeof(s_MarketDepthReject));
			Type = MARKET_DEPTH_REJECT;
			Size = sizeof(s_MarketDepthReject);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		uint16_t GetSymbolID();
		const char* GetRejectText();
		void SetRejectText(const char* NewValue);
	};

	/*==========================================================================*/
	struct s_MarketDataUpdateTrade
	{
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;

		AtBidOrAskEnum AtBidOrAsk;

		double Price;
		double Volume;
		t_DateTimeWithMilliseconds DateTime;


		s_MarketDataUpdateTrade()
		{
			memset(this, 0,sizeof(s_MarketDataUpdateTrade));
			Type=MARKET_DATA_UPDATE_TRADE;
			Size=sizeof(s_MarketDataUpdateTrade);

		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		uint16_t GetSymbolID() ;
		AtBidOrAskEnum GetAtBidOrAsk();
		double GetPrice();
		double GetVolume();
		t_DateTimeWithMilliseconds GetDateTime();

	};

	/*==========================================================================*/
	struct s_MarketDataUpdateTrade_Int
	{
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;

		AtBidOrAskEnum AtBidOrAsk;

		int32_t Price;
		int32_t Volume;
		t_DateTimeWithMilliseconds DateTime;


		s_MarketDataUpdateTrade_Int()
		{
			memset(this, 0,sizeof(s_MarketDataUpdateTrade_Int));
			Type=MARKET_DATA_UPDATE_TRADE_INT;
			Size=sizeof(s_MarketDataUpdateTrade_Int);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		uint16_t GetSymbolID() ;
		AtBidOrAskEnum GetAtBidOrAsk() ;
		int32_t GetPrice();
		int32_t GetVolume();
		t_DateTimeWithMilliseconds GetDateTime();

	};

	/*==========================================================================*/
	struct s_MarketDataUpdateBidAsk
	{
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;

		double BidPrice;
		float BidQuantity;
		double AskPrice;
		float AskQuantity;
		t_DateTime4Byte DateTime;

		s_MarketDataUpdateBidAsk()
		{
			memset(this, 0,sizeof(s_MarketDataUpdateBidAsk));
			Type=MARKET_DATA_UPDATE_BID_ASK;
			Size=sizeof(s_MarketDataUpdateBidAsk);
			BidPrice=DBL_MAX;
			AskPrice=DBL_MAX;
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint16_t GetSymbolID() const;
		double GetBidPrice() const;
		float GetBidQuantity() const;
		double GetAskPrice() const;
		float GetAskQuantity() const;
		t_DateTime4Byte GetDateTime() const;
	};

	/*==========================================================================*/
	struct s_MarketDataUpdateBidAsk_Int
	{
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;

		int32_t BidPrice;
		int32_t BidQuantity;
		int32_t AskPrice;
		int32_t AskQuantity;
		t_DateTime4Byte DateTime;

		s_MarketDataUpdateBidAsk_Int()
		{
			memset(this, 0,sizeof(s_MarketDataUpdateBidAsk_Int));
			Type=MARKET_DATA_UPDATE_BID_ASK_INT;
			Size=sizeof(s_MarketDataUpdateBidAsk_Int);
			BidPrice=INT_MAX;
			AskPrice=INT_MAX;
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint16_t GetSymbolID() const;
		int32_t GetBidPrice() const;
		int32_t GetBidQuantity() const;
		int32_t GetAskPrice() const;
		int32_t GetAskQuantity() const;
		t_DateTime4Byte GetDateTime() const;
	};

	/*==========================================================================*/
	struct s_MarketDataUpdateBidAskCompact
	{
		uint16_t Size;
		uint16_t Type;

		float BidPrice;
		float BidQuantity;
		float AskPrice;
		float AskQuantity;

		t_DateTime4Byte DateTime;

		uint16_t SymbolID;

		s_MarketDataUpdateBidAskCompact()
		{
			memset(this, 0,sizeof(s_MarketDataUpdateBidAskCompact));
			Type=MARKET_DATA_UPDATE_BID_ASK_COMPACT;
			Size=sizeof(s_MarketDataUpdateBidAskCompact);
			BidPrice=FLT_MAX;
			AskPrice=FLT_MAX;
		}

		uint16_t GetMessageSize();
		float GetBidPrice() const;
		float GetBidQuantity() const;
		float GetAskPrice() const;
		float GetAskQuantity() const;
		t_DateTime4Byte GetDateTime() const;
		uint16_t GetSymbolID() const;
	};

	/*==========================================================================*/
	struct s_MarketDataUpdateTradeCompact
	{
		uint16_t Size;
		uint16_t Type;
	
		float Price;
		float Volume;
		t_DateTime4Byte DateTime;
		uint16_t SymbolID;
		AtBidOrAskEnum AtBidOrAsk;

		s_MarketDataUpdateTradeCompact()
		{
			memset(this, 0,sizeof(s_MarketDataUpdateTradeCompact));
			Type=MARKET_DATA_UPDATE_TRADE_COMPACT;
			Size=sizeof(s_MarketDataUpdateTradeCompact);

		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		float GetPrice() const;
		float GetVolume() const;
		t_DateTime4Byte GetDateTime() const;
		uint16_t GetSymbolID() const;
		AtBidOrAskEnum GetAtBidOrAsk() const;
	};

	/*==========================================================================*/
	struct s_MarketDataUpdateDailyVolume
	{
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;
		double Volume;

		s_MarketDataUpdateDailyVolume()
		{
			memset(this, 0,sizeof(s_MarketDataUpdateDailyVolume));
			Type=MARKET_DATA_UPDATE_DAILY_VOLUME;
			Size=sizeof(s_MarketDataUpdateDailyVolume);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint16_t GetSymbolID() const;
		double GetVolume() const;
	};
	/*==========================================================================*/
	struct s_MarketDataUpdateOpenInterest
	{
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;
		uint32_t OpenInterest;

		s_MarketDataUpdateOpenInterest()
		{
			memset(this, 0,sizeof(s_MarketDataUpdateOpenInterest));
			Type=MARKET_DATA_UPDATE_OPEN_INTEREST;
			Size=sizeof(s_MarketDataUpdateOpenInterest);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint16_t GetSymbolID() const;
		uint32_t GetOpenInterest() const;
	};
	/*==========================================================================*/
	struct s_MarketDataUpdateDailyHigh
	{
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;
		double Price;

		s_MarketDataUpdateDailyHigh()
		{
			memset(this, 0,sizeof(s_MarketDataUpdateDailyHigh));
			Type=MARKET_DATA_UPDATE_DAILY_HIGH;
			Size=sizeof(s_MarketDataUpdateDailyHigh);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint16_t GetSymbolID() const;
		double GetPrice() const;
	};

	/*==========================================================================*/
	struct s_MarketDataUpdateDailyHigh_Int
	{
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;
		int32_t Price;

		s_MarketDataUpdateDailyHigh_Int()
		{
			memset(this, 0,sizeof(s_MarketDataUpdateDailyHigh_Int));
			Type=MARKET_DATA_UPDATE_DAILY_HIGH_INT;
			Size=sizeof(s_MarketDataUpdateDailyHigh_Int);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint16_t GetSymbolID() const;
		int32_t GetPrice() const;
	};

	/*==========================================================================*/
	struct s_MarketDataUpdateDailyLow
	{
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;
		double Price;

		s_MarketDataUpdateDailyLow()
		{
			memset(this, 0,sizeof(s_MarketDataUpdateDailyLow));
			Type=MARKET_DATA_UPDATE_DAILY_LOW;
			Size=sizeof(s_MarketDataUpdateDailyLow);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint16_t GetSymbolID() const;
		double GetPrice() const;
	};

	/*==========================================================================*/
	struct s_MarketDataUpdateDailyLow_Int
	{
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;
		int32_t Price;

		s_MarketDataUpdateDailyLow_Int()
		{
			memset(this, 0,sizeof(s_MarketDataUpdateDailyLow_Int));
			Type=MARKET_DATA_UPDATE_DAILY_LOW_INT;
			Size=sizeof(s_MarketDataUpdateDailyLow_Int);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint16_t GetSymbolID() const;
		int32_t GetPrice() const;
	};

	/*==========================================================================*/
	struct s_MarketDataUpdateLastTradeSnapshot
	{
		uint16_t Size;
		uint16_t Type;

		uint16_t SymbolID;
		double LastTradePrice;
		double LastTradeVolume;
		t_DateTimeWithMilliseconds LastTradeDateTime;

		s_MarketDataUpdateLastTradeSnapshot()
		{
			memset(this, 0, sizeof(s_MarketDataUpdateLastTradeSnapshot));
			Type = MARKET_DATA_UPDATE_LAST_TRADE_SNAPSHOT;
			Size = sizeof(s_MarketDataUpdateLastTradeSnapshot);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void* p_SourceData);

		uint16_t GetSymbolID() const;
		double GetLastTradePrice() const;
		double GetLastTradeVolume() const;
		t_DateTimeWithMilliseconds GetLastTradeDateTime() const;
	};

	/*==========================================================================*/
	struct s_SubmitNewSingleOrder
	{
		uint16_t Size;
		uint16_t Type;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		char TradeAccount[TRADE_ACCOUNT_LENGTH];
		char ClientOrderID[ORDER_ID_LENGTH];

		OrderTypeEnum OrderType;

		BuySellEnum BuySell;

		double Price1;
		double Price2;

		double Quantity;

		TimeInForceEnum TimeInForce;

		t_DateTime GoodTillDateTime;
		
		byte IsAutomatedOrder;

		byte IsParentOrder;

		char FreeFormText[ORDER_FREE_FORM_TEXT_LENGTH];

		s_SubmitNewSingleOrder()
		{
			memset(this, 0,sizeof(s_SubmitNewSingleOrder));
			Type=SUBMIT_NEW_SINGLE_ORDER;
			Size=sizeof(s_SubmitNewSingleOrder);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		const char* GetSymbol();
		void SetSymbol(const char* NewValue);
		const char* GetExchange();
		void SetExchange(const char* NewValue);
		const char* GetClientOrderID();
		void SetClientOrderID(const char* NewValue);
		OrderTypeEnum GetOrderType();	
		BuySellEnum GetBuySell();	
		double GetPrice1();
		double GetPrice2();
		double GetQuantity();	
		TimeInForceEnum GetTimeInForce();	
		t_DateTime GetGoodTillDateTime();
		const char* GetTradeAccount();
		void SetTradeAccount(const char* NewValue);
		byte GetIsAutomatedOrder();	
		byte GetIsParentOrder();	
		const char* GetFreeFormText();
		void SetFreeFormText(const char* NewValue);
	};

	/*==========================================================================*/
	struct s_SubmitNewSingleOrderInt
	{
		uint16_t Size;
		uint16_t Type;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		char TradeAccount[TRADE_ACCOUNT_LENGTH];
		char ClientOrderID[ORDER_ID_LENGTH];

		OrderTypeEnum OrderType;
		BuySellEnum BuySell;

		int32_t Price1;
		int32_t Price2;
		float Divisor;
		double Quantity;

		TimeInForceEnum TimeInForce;
		t_DateTime GoodTillDateTime;
		
		byte IsAutomatedOrder;
		byte IsParentOrder;

		char FreeFormText[ORDER_FREE_FORM_TEXT_LENGTH];

		s_SubmitNewSingleOrderInt()
		{
			memset(this, 0,sizeof(s_SubmitNewSingleOrderInt));
			Type=SUBMIT_NEW_SINGLE_ORDER_INT;
			Size=sizeof(s_SubmitNewSingleOrderInt);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		const char* GetSymbol();
		void SetSymbol(const char* NewValue);
		const char* GetExchange();
		void SetExchange(const char* NewValue);
		const char* GetTradeAccount();
		void SetTradeAccount(const char* NewValue);
		const char* GetClientOrderID();
		void SetClientOrderID(const char* NewValue);

		OrderTypeEnum GetOrderType();	
		BuySellEnum GetBuySell();	
		int32_t GetPrice1();
		int32_t GetPrice2();
		float GetDivisor();	
		double GetQuantity();	
		TimeInForceEnum GetTimeInForce();	
		t_DateTime GetGoodTillDateTime();	
		byte GetIsAutomatedOrder();	
		byte GetIsParentOrder();	

		const char* GetFreeFormText();
		void SetFreeFormText(const char* NewValue);
	};

	/*==========================================================================*/
	struct s_CancelReplaceOrder
	{
		uint16_t Size;
		uint16_t Type;

		char ServerOrderID[ORDER_ID_LENGTH];
		char ClientOrderID[ORDER_ID_LENGTH];

		double Price1;
		double Price2;
		double Quantity;
		int8_t Price1IsSet;
		int8_t Price2IsSet;

		s_CancelReplaceOrder()
		{
			memset(this, 0,sizeof(s_CancelReplaceOrder));
			Type=CANCEL_REPLACE_ORDER;
			Size=sizeof(s_CancelReplaceOrder);
			Price1IsSet = 1;
			Price2IsSet = 1;
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		const char* GetServerOrderID();
		void SetServerOrderID(const char* NewValue);
		const char* GetClientOrderID();
		void SetClientOrderID(const char* NewValue);
		double GetPrice1();
		double GetPrice2();
		double GetQuantity();
		int8_t GetPrice1IsSet();
		int8_t GetPrice2IsSet();

	};

	/*==========================================================================*/
	struct s_CancelReplaceOrderInt
	{
		uint16_t Size;
		uint16_t Type;

		char ServerOrderID[ORDER_ID_LENGTH];
		char ClientOrderID[ORDER_ID_LENGTH];

		int32_t Price1;
		int32_t Price2;
		float Divisor;
		double Quantity;
		int8_t Price1IsSet;
		int8_t Price2IsSet;

		s_CancelReplaceOrderInt()
		{
			memset(this, 0,sizeof(s_CancelReplaceOrderInt));
			Type=CANCEL_REPLACE_ORDER_INT;
			Size=sizeof(s_CancelReplaceOrderInt);
			Divisor = 1.0f;
			Price1IsSet = 1;
			Price2IsSet = 1;

		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		const char* GetServerOrderID();
		void SetServerOrderID(const char* NewValue);
		const char* GetClientOrderID();
		void SetClientOrderID(const char* NewValue);
		int32_t GetPrice1();
		int32_t GetPrice2();
		float GetDivisor();
		double GetQuantity();
		int8_t GetPrice1IsSet();
		int8_t GetPrice2IsSet();
	};

	/*==========================================================================*/
	struct s_CancelOrder
	{
		uint16_t Size;
		uint16_t Type;
		
		char ServerOrderID[ORDER_ID_LENGTH];
		char ClientOrderID[ORDER_ID_LENGTH];

		s_CancelOrder()
		{
			memset(this, 0,sizeof(s_CancelOrder));
			Type=CANCEL_ORDER;
			Size=sizeof(s_CancelOrder);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		const char* GetServerOrderID();
		void SetServerOrderID(const char* NewValue);
		const char* GetClientOrderID();
		void SetClientOrderID(const char* NewValue);
	};

	/*==========================================================================*/
	struct s_SubmitNewOCOOrder
	{
		uint16_t Size;
		uint16_t Type;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		char ClientOrderID_1[ORDER_ID_LENGTH];
		OrderTypeEnum OrderType_1;
		BuySellEnum BuySell_1;
		double Price1_1;
		double Price2_1;
		double Quantity_1;

		char ClientOrderID_2[ORDER_ID_LENGTH];
		OrderTypeEnum OrderType_2;
		BuySellEnum BuySell_2;
		double Price1_2;
		double Price2_2;
		double Quantity_2;

		TimeInForceEnum TimeInForce;
		t_DateTime GoodTillDateTime;

		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		byte IsAutomatedOrder;

		char ParentTriggerClientOrderID[ORDER_ID_LENGTH];

		char FreeFormText[ORDER_FREE_FORM_TEXT_LENGTH];

		s_SubmitNewOCOOrder()
		{
			memset(this, 0,sizeof(s_SubmitNewOCOOrder));
			Type=SUBMIT_NEW_OCO_ORDER;
			Size=sizeof(s_SubmitNewOCOOrder);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		void SetClientOrderID_1(const char* NewValue);
		void SetClientOrderID_2(const char* NewValue);
		const char* GetFreeFormText();
		void SetFreeFormText(const char* NewValue);
		const char* GetClientOrderID_1();
		const char* GetClientOrderID_2();
		const char* GetSymbol();
		void SetSymbol(const char* NewValue);
		const char* GetExchange();
		void SetExchange(const char* NewValue);
		OrderTypeEnum GetOrderType_1();
		OrderTypeEnum GetOrderType_2();
		BuySellEnum GetBuySell_1();
		BuySellEnum GetBuySell_2();	
		TimeInForceEnum GetTimeInForce();
		t_DateTime GetGoodTillDateTime();
		void SetParentTriggerClientOrderID(const char* NewValue);
		const char* GetParentTriggerClientOrderID();
		byte GetIsAutomatedOrder();
		double GetPrice1_1();
		double GetPrice2_1();
		double GetPrice1_2();
		double GetPrice2_2();
		double GetQuantity_1();
		double GetQuantity_2();
		const char* GetTradeAccount();
		void SetTradeAccount(const char* NewValue);
	};

	/*==========================================================================*/
	struct s_SubmitNewOCOOrderInt
	{
		uint16_t Size;
		uint16_t Type;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		char ClientOrderID_1[ORDER_ID_LENGTH];
		OrderTypeEnum OrderType_1;
		BuySellEnum BuySell_1;
		int32_t Price1_1;
		int32_t Price2_1;
		double Quantity_1;

		char ClientOrderID_2[ORDER_ID_LENGTH];
		OrderTypeEnum OrderType_2;
		BuySellEnum BuySell_2;
		int32_t Price1_2;
		int32_t Price2_2;
		double Quantity_2;

		TimeInForceEnum TimeInForce;
		t_DateTime GoodTillDateTime;

		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		byte IsAutomatedOrder;

		char ParentTriggerClientOrderID[ORDER_ID_LENGTH];

		char FreeFormText[ORDER_FREE_FORM_TEXT_LENGTH];

		float Divisor;

		s_SubmitNewOCOOrderInt()
		{
			memset(this, 0,sizeof(s_SubmitNewOCOOrderInt));
			Type=SUBMIT_NEW_OCO_ORDER_INT;
			Size=sizeof(s_SubmitNewOCOOrderInt);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		void SetClientOrderID_1(const char* NewValue);
		void SetClientOrderID_2(const char* NewValue);
		const char* GetFreeFormText();
		void SetFreeFormText(const char* NewValue);
		const char* GetClientOrderID_1();
		const char* GetClientOrderID_2();
		const char* GetSymbol();
		void SetSymbol(const char* NewValue);
		const char* GetExchange();
		void SetExchange(const char* NewValue);
		OrderTypeEnum GetOrderType_1();
		OrderTypeEnum GetOrderType_2();
		BuySellEnum GetBuySell_1();
		BuySellEnum GetBuySell_2();	
		TimeInForceEnum GetTimeInForce();
		t_DateTime GetGoodTillDateTime();
		void SetParentTriggerClientOrderID(const char* NewValue);
		const char* GetParentTriggerClientOrderID();
		byte GetIsAutomatedOrder();
		int32_t GetPrice1_1();
		int32_t GetPrice2_1();
		int32_t GetPrice1_2();
		int32_t GetPrice2_2();
		double GetQuantity_1();
		double GetQuantity_2();
		const char* GetTradeAccount();
		void SetTradeAccount(const char* NewValue);
		float GetDivisor();
	};

	/*==========================================================================*/
	struct s_OpenOrdersRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		int32_t RequestAllOrders;

		char ServerOrderID[ORDER_ID_LENGTH];

		s_OpenOrdersRequest()
		{
			memset(this, 0,sizeof(s_OpenOrdersRequest));
			Type=OPEN_ORDERS_REQUEST;
			Size=sizeof(s_OpenOrdersRequest);
			RequestAllOrders = 1;
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		int32_t GetRequestID();
		int32_t GetRequestAllOrders();
		void SetServerOrderID(const char* NewValue);
		const char* GetServerOrderID();
	};

	/*==========================================================================*/
	struct s_HistoricalOrderFillsRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		char ServerOrderID[ORDER_ID_LENGTH];

		int32_t NumberOfDays;

		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		s_HistoricalOrderFillsRequest()
		{
			memset(this, 0,sizeof(s_HistoricalOrderFillsRequest));
			Type=HISTORICAL_ORDER_FILLS_REQUEST;
			Size=sizeof(s_HistoricalOrderFillsRequest);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		int32_t GetRequestID();
		int32_t GetNumberOfDays();
		void SetServerOrderID(const char* NewValue);
		const char* GetServerOrderID();
		void SetTradeAccount(const char* NewValue);
		const char* GetTradeAccount();
	};

	/*==========================================================================*/
	struct s_CurrentPositionsRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		char  TradeAccount[TRADE_ACCOUNT_LENGTH];

		s_CurrentPositionsRequest()
		{
			memset(this, 0,sizeof(s_CurrentPositionsRequest));
			Type=CURRENT_POSITIONS_REQUEST;
			Size=sizeof(s_CurrentPositionsRequest);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		int32_t GetRequestID();
		void SetTradeAccount(const char* NewValue);
		const char* GetTradeAccount();
	};

	/*==========================================================================*/
	struct s_CurrentPositionsReject
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		char RejectText[TEXT_DESCRIPTION_LENGTH];

		s_CurrentPositionsReject()
		{
			memset(this, 0,sizeof(s_CurrentPositionsReject));
			Type=CURRENT_POSITIONS_REJECT;
			Size=sizeof(s_CurrentPositionsReject);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		int32_t GetRequestID();
		void SetRejectText(const char* NewValue);
		const char* GetRejectText();
	};

	/*==========================================================================*/
	struct s_OrderUpdate
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		int32_t TotalNumMessages;
		int32_t MessageNumber;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		char PreviousServerOrderID[ORDER_ID_LENGTH];

		char ServerOrderID[ORDER_ID_LENGTH];

		char ClientOrderID[ORDER_ID_LENGTH];

		char ExchangeOrderID[ORDER_ID_LENGTH];

		OrderStatusEnum OrderStatus;

		OrderUpdateReasonEnum OrderUpdateReason;

		OrderTypeEnum OrderType;

		BuySellEnum BuySell;

		double Price1;

		double Price2;

		TimeInForceEnum TimeInForce;
		t_DateTime GoodTillDateTime;
		double OrderQuantity;
		double FilledQuantity;
		double RemainingQuantity;
		double AverageFillPrice;

		double LastFillPrice;
		t_DateTime LastFillDateTime;
		double LastFillQuantity;
		char UniqueFillExecutionID[64];

		char TradeAccount[TRADE_ACCOUNT_LENGTH];
		char InfoText[TEXT_DESCRIPTION_LENGTH];

		byte NoOrders;
		char ParentServerOrderID[ORDER_ID_LENGTH];
		char OCOLinkedOrderServerOrderID[ORDER_ID_LENGTH];

		s_OrderUpdate()
		{
			memset(this, 0,sizeof(s_OrderUpdate));
			Type=ORDER_UPDATE;
			Size=sizeof(s_OrderUpdate);

			//The following initializations indicate to the Client that these variables are in an unset state and their values should not be used
			Price1 = DBL_MAX;
			Price2 = DBL_MAX; 

			OrderQuantity = DBL_MAX;
			FilledQuantity = DBL_MAX;
			RemainingQuantity = DBL_MAX;
			AverageFillPrice = DBL_MAX;

			LastFillPrice = DBL_MAX;
			LastFillQuantity = DBL_MAX;
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		const char* GetSymbol();
		void SetSymbol(const char* NewValue);
		const char* GetExchange();
		void SetExchange(const char* NewValue);
		const char* GetPreviousServerOrderID();
		void SetPreviousServerOrderID(const char* NewValue);
		const char* GetServerOrderID();
		void SetServerOrderID(const char* NewValue);
		const char* GetClientOrderID();
		void SetClientOrderID(const char* NewValue);
		const char* GetExchangeOrderID();
		void SetExchangeOrderID(const char* NewValue);
		void SetUniqueFillExecutionID(const char* NewValue);
		double GetOrderQuantity();
		double GetFilledQuantity();
		double GetRemainingQuantity();
		double GetLastFillQuantity();

		int32_t GetRequestID();
		int32_t GetMessageNumber();
		int32_t GetTotalNumMessages();
		OrderStatusEnum GetOrderStatus();	
		OrderUpdateReasonEnum GetOrderUpdateReason();	
		OrderTypeEnum GetOrderType();	
		BuySellEnum GetBuySell();	
		double GetPrice1();
		double GetPrice2();		
		TimeInForceEnum GetTimeInForce();	
		t_DateTime GetGoodTillDateTime();	
		double GetAverageFillPrice();
		double GetLastFillPrice();	
		t_DateTime GetLastFillDateTime();	
		const char* GetUniqueFillExecutionID();

		const char* GetTradeAccount();
		void SetTradeAccount(const char* NewValue);
		const char* GetInfoText();
		void SetInfoText(const char* NewValue);
		byte GetNoOrders();
		const char* GetParentServerOrderID();
		void SetParentServerOrderID(const char* NewValue);
		const char* GetOCOLinkedOrderServerOrderID();
		void SetOCOLinkedOrderServerOrderID(const char* NewValue);
	};
	
	/*==========================================================================*/
	struct s_OpenOrdersReject
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		char RejectText[TEXT_DESCRIPTION_LENGTH];

		s_OpenOrdersReject()
		{
			memset(this, 0,sizeof(s_OpenOrdersReject));
			Type = OPEN_ORDERS_REJECT;
			Size=sizeof(s_OpenOrdersReject);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		int32_t GetRequestID();
		const char* GetRejectText();
		void SetRejectText(const char* NewValue);
	};

	/*==========================================================================*/
	struct s_HistoricalOrderFillResponse
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID; 

		int32_t TotalNumberMessages;

		int32_t MessageNumber;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];
		char ServerOrderID[ORDER_ID_LENGTH];
		BuySellEnum BuySell;
		double Price;
		t_DateTime DateTime;
		double Quantity;
		char UniqueExecutionID[64];
		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		OpenCloseTradeEnum OpenClose; 

		byte NoOrderFills;

		s_HistoricalOrderFillResponse()
		{
			memset(this, 0,sizeof(s_HistoricalOrderFillResponse));
			Type=HISTORICAL_ORDER_FILL_RESPONSE;
			Size=sizeof(s_HistoricalOrderFillResponse);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		int32_t GetRequestID();
		int32_t GetMessageNumber();
		int32_t GetTotalNumberMessages();		
		const char* GetSymbol();
		void SetSymbol(const char* NewValue);
		const char* GetExchange();
		void SetExchange(const char* NewValue);
		const char* GetServerOrderID();
		void SetServerOrderID(const char* NewValue);
		BuySellEnum GetBuySell();
		double GetPrice();
		t_DateTime GetDateTime();
		double GetQuantity();
		void SetTradeAccount(const char* NewValue);
		const char* GetTradeAccount();
		void SetUniqueExecutionID(const char* NewValue);
		const char* GetUniqueExecutionID();
		OpenCloseTradeEnum GetOpenClose();	
		byte GetNoOrderFills();	
	};

	/*==========================================================================*/
	struct s_PositionUpdate
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		int32_t TotalNumberMessages;

		int32_t MessageNumber;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		double Quantity;
		double AveragePrice;

		char PositionIdentifier [ORDER_ID_LENGTH];

		char TradeAccount[TRADE_ACCOUNT_LENGTH];
		byte NoPositions;

		byte Unsolicited;

		s_PositionUpdate()
		{
			memset(this, 0,sizeof(s_PositionUpdate));
			Type=POSITION_UPDATE;
			Size=sizeof(s_PositionUpdate);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		int32_t GetRequestID();
		int32_t GetTotalNumberMessages();
		int32_t GetMessageNumber();
		void SetSymbol(const char* NewValue);
		const char* GetSymbol();
		void SetExchange(const char* NewValue);
		const char* GetExchange();
		double GetQuantity();
		double GetAveragePrice();
		void SetPositionIdentifier(const char* NewValue);
		const char* GetPositionIdentifier();
		void SetTradeAccount(const char* NewValue);
		const char* GetTradeAccount();
		byte GetNoPositions();
		byte GetUnsolicited();
	};

	/*==========================================================================*/
	struct s_TradeAccountsRequest
	{
		uint16_t Size;
		uint16_t Type;

		s_TradeAccountsRequest()
		{
			memset(this, 0,sizeof(s_TradeAccountsRequest));
			Type=TRADE_ACCOUNTS_REQUEST;
			Size=sizeof(s_TradeAccountsRequest);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
	};

	/*==========================================================================*/
	struct s_TradeAccountResponse
	{
		uint16_t Size;
		uint16_t Type;

		int32_t TotalNumberMessages;

		int32_t MessageNumber;

		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		s_TradeAccountResponse()
		{
			memset(this, 0,sizeof(s_TradeAccountResponse));
			Type=TRADE_ACCOUNT_RESPONSE;
			Size=sizeof(s_TradeAccountResponse);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		int32_t GetTotalNumberMessages();
		int32_t GetMessageNumber();
		void SetTradeAccount(const char* NewValue);
		const char* GetTradeAccount();
	};

	/*==========================================================================*/
	struct s_ExchangeListRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		s_ExchangeListRequest()
		{
			memset(this, 0,sizeof(s_ExchangeListRequest));
			Type=EXCHANGE_LIST_REQUEST;
			Size=sizeof(s_ExchangeListRequest);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		int32_t GetRequestID();
	};

	/*==========================================================================*/
	struct s_ExchangeListResponse
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		char Exchange[EXCHANGE_LENGTH];
		byte IsFinalMessage;
		char Description[EXCHANGE_DESCRIPTION_LENGTH];

		s_ExchangeListResponse()
		{
			memset(this, 0,sizeof(s_ExchangeListResponse));
			Type=EXCHANGE_LIST_RESPONSE;
			Size=sizeof(s_ExchangeListResponse);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		int32_t GetRequestID();
		const char* GetExchange();
		void SetExchange(const char* NewValue);
		const char* GetDescription();
		void SetDescription(const char* NewValue);
		byte GetIsFinalMessage();
	};

	/*==========================================================================*/
	struct s_SymbolsForExchangeRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		char Exchange[EXCHANGE_LENGTH];

		SecurityTypeEnum SecurityType;

		s_SymbolsForExchangeRequest()
		{
			memset(this, 0,sizeof(s_SymbolsForExchangeRequest));
			Type=SYMBOLS_FOR_EXCHANGE_REQUEST;
			Size=sizeof(s_SymbolsForExchangeRequest);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		int32_t GetRequestID();
		const char* GetExchange();
		void SetExchange(const char* NewValue);
		SecurityTypeEnum GetSecurityType();
	};

	/*==========================================================================*/
	struct s_UnderlyingSymbolsForExchangeRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		char Exchange[EXCHANGE_LENGTH];

		SecurityTypeEnum SecurityType;

		s_UnderlyingSymbolsForExchangeRequest()
		{
			memset(this, 0,sizeof(s_UnderlyingSymbolsForExchangeRequest));
			Type=UNDERLYING_SYMBOLS_FOR_EXCHANGE_REQUEST;
			Size=sizeof(s_UnderlyingSymbolsForExchangeRequest);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		int32_t GetRequestID();
		const char* GetExchange();
		void SetExchange(const char* NewValue);
		SecurityTypeEnum GetSecurityType();
	};

	/*==========================================================================*/
	struct s_SymbolsForUnderlyingRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		char UnderlyingSymbol[UNDERLYING_SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		SecurityTypeEnum SecurityType;

		s_SymbolsForUnderlyingRequest()
		{
			memset(this, 0,sizeof(s_SymbolsForUnderlyingRequest));
			Type=SYMBOLS_FOR_UNDERLYING_REQUEST;
			Size=sizeof(s_SymbolsForUnderlyingRequest);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		int32_t GetRequestID();
		const char* GetUnderlyingSymbol();
		void SetUnderlyingSymbol(const char* NewValue);
		const char* GetExchange();
		void SetExchange(const char* NewValue);
		SecurityTypeEnum GetSecurityType();
	};

	/*==========================================================================*/
	struct s_SymbolSearchByDescription
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		char Exchange[EXCHANGE_LENGTH];
		char SymbolDescription[SYMBOL_DESCRIPTION_LENGTH];

		SecurityTypeEnum SecurityType;

		s_SymbolSearchByDescription()
		{
			memset(this, 0, sizeof(s_SymbolSearchByDescription));
			Type = SYMBOL_SEARCH_BY_DESCRIPTION;
			Size=sizeof(s_SymbolSearchByDescription);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		int32_t GetRequestID();
		const char* GetExchange();
		void SetExchange(const char* NewValue);
		const char* GetSymbolDescription();
		void SetSymbolDescription(const char* NewValue);
		SecurityTypeEnum GetSecurityType();
	};

	/*==========================================================================*/
	struct s_SecurityDefinitionForSymbolRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		SecurityTypeEnum SecurityType;

		s_SecurityDefinitionForSymbolRequest()
		{
			memset(this, 0,sizeof(s_SecurityDefinitionForSymbolRequest));
			Type=SECURITY_DEFINITION_FOR_SYMBOL_REQUEST;
			Size=sizeof(s_SecurityDefinitionForSymbolRequest);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		int32_t GetRequestID();
		void SetSymbol(const char* NewValue);
		const char* GetSymbol();
		void SetExchange(const char* NewValue);
		const char* GetExchange();

		SecurityTypeEnum GetSecurityType();
	};

	/*==========================================================================*/
	struct s_SecurityDefinitionResponse
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];

		SecurityTypeEnum SecurityType;
		
		char Description[SYMBOL_DESCRIPTION_LENGTH];
		float MinPriceIncrement;
		PriceDisplayFormatEnum PriceDisplayFormat;
		float CurrencyValuePerIncrement;

		byte IsFinalMessage;

		float OrderIntPriceMultiplier;
		float MarketDataIntPriceDivisor;
		char UnderlyingSymbol[UNDERLYING_SYMBOL_LENGTH];

		s_SecurityDefinitionResponse()
		{
			memset(this, 0,sizeof(s_SecurityDefinitionResponse));
			Type=SECURITY_DEFINITION_RESPONSE;
			Size=sizeof(s_SecurityDefinitionResponse);
			PriceDisplayFormat = PRICE_DISPLAY_FORMAT_UNSET;
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		int32_t GetRequestID() const;
		void SetSymbol(const char* NewValue);
		const char* GetSymbol();
		void SetExchange(const char* NewValue);
		const char* GetExchange();
		SecurityTypeEnum GetSecurityType() const;
		void SetDescription(const char* NewValue);
		const char* GetDescription();
		float GetMinPriceIncrement() const;
		PriceDisplayFormatEnum GetPriceDisplayFormat() const;
		float GetCurrencyValuePerIncrement() const;
		byte GetIsFinalMessage() const;
		float GetOrderIntPriceMultiplier();
		float GetMarketDataIntPriceDivisor();
		const char* GetUnderlyingSymbol();
		void SetUnderlyingSymbol(const char* NewValue);
	};

	/*==========================================================================*/
	struct s_AccountBalanceRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		char TradeAccount[TRADE_ACCOUNT_LENGTH];

		s_AccountBalanceRequest()
		{
			memset(this, 0,sizeof(s_AccountBalanceRequest));
			Type=ACCOUNT_BALANCE_REQUEST;
			Size=sizeof(s_AccountBalanceRequest);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		int32_t GetRequestID();

		void SetTradeAccount(const char* NewValue);
		const char* GetTradeAccount();
	};

	/*==========================================================================*/
	struct s_AccountBalanceReject
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		char RejectText[TEXT_DESCRIPTION_LENGTH];

		s_AccountBalanceReject()
		{
			memset(this, 0,sizeof(s_AccountBalanceReject));
			Type=ACCOUNT_BALANCE_REJECT;
			Size=sizeof(s_AccountBalanceReject);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		uint32_t GetRequestID();

		void SetRejectText(const char* NewValue);
		const char* GetRejectText();
	};

	/*==========================================================================*/
	struct s_AccountBalanceUpdate
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		double CashBalance;

		double BalanceAvailableForNewPositions;

		char AccountCurrency[8];

		char TradeAccount[TRADE_ACCOUNT_LENGTH];
		double SecuritiesValue;  // Not including cash
		double MarginRequirement;


		s_AccountBalanceUpdate()
		{
			memset(this, 0,sizeof(s_AccountBalanceUpdate));
			Type=ACCOUNT_BALANCE_UPDATE;
			Size=sizeof(s_AccountBalanceUpdate);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		int32_t GetRequestID();
		double GetCashBalance();
		double GetBalanceAvailableForNewPositions();
		void SetAccountCurrency(const char* NewValue);
		const char* GetAccountCurrency();
		void SetTradeAccount(const char* NewValue);
		const char* GetTradeAccount();
		double GetSecuritiesValue();
		double GetMarginRequirement();
	};

	/*==========================================================================*/
	struct s_UserMessage
	{
		uint16_t Size;
		uint16_t Type;

		char UserMessage[TEXT_MESSAGE_LENGTH];

		byte IsPopupMessage;

		s_UserMessage()
		{
			memset(this, 0,sizeof(s_UserMessage));
			Type=USER_MESSAGE;
			Size=sizeof(s_UserMessage);
			IsPopupMessage = 1;
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		void SetUserMessage(const char* NewValue);
		const char* GetUserMessage();
		byte GetIsPopupMessage();
	};

	/*==========================================================================*/
	struct s_GeneralLogMessage
	{
		uint16_t Size;
		uint16_t Type;

		char MessageText[128];

		s_GeneralLogMessage()
		{
			memset(this, 0,sizeof(s_GeneralLogMessage));
			Type=GENERAL_LOG_MESSAGE;
			Size=sizeof(s_GeneralLogMessage);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		void SetMessageText(const char* NewValue);
		const char* GetMessageText();
	};

	/*==========================================================================*/
	struct s_HistoricalPriceDataRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		char Symbol[SYMBOL_LENGTH];
		char Exchange[EXCHANGE_LENGTH];
		HistoricalDataIntervalEnum RecordInterval;
		t_DateTime StartDateTime;
		t_DateTime EndDateTime;
		uint32_t MaxDaysToReturn;
		byte  UseZLibCompression;
		byte RequestDividendAdjustedStockData;
		byte Flag_1;

		s_HistoricalPriceDataRequest()
		{
			Clear();
		}

		void Clear()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataRequest));
			Type=HISTORICAL_PRICE_DATA_REQUEST;
			Size=sizeof(s_HistoricalPriceDataRequest);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		int32_t GetRequestID();
		void SetSymbol(const char* NewValue);
		const char* GetSymbol();
		void SetExchange(const char* NewValue);
		const char* GetExchange();
		HistoricalDataIntervalEnum GetRecordInterval();
		t_DateTime GetStartDateTime();
		t_DateTime GetEndDateTime();
		uint32_t GetMaxDaysToReturn();
		byte GetUseZLibCompression();
		byte GetRequestDividendAdjustedStockData();
		byte GetFlag_1();
	};

	/*==========================================================================*/
	struct s_HistoricalPriceDataResponseHeader
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		HistoricalDataIntervalEnum RecordInterval;

		byte UseZLibCompression;
		
		byte NoRecordsToReturn;

		float IntPriceDivisor;

		s_HistoricalPriceDataResponseHeader()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataResponseHeader));
			Type=HISTORICAL_PRICE_DATA_RESPONSE_HEADER;
			Size=sizeof(s_HistoricalPriceDataResponseHeader);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		int32_t GetRequestID();
		HistoricalDataIntervalEnum GetRecordInterval();
		byte GetUseZLibCompression();
		byte GetNoRecordsToReturn();
		float GetIntPriceDivisor();
	};

	/*==========================================================================*/
	struct s_HistoricalPriceDataReject
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		char RejectText[TEXT_DESCRIPTION_LENGTH];

		s_HistoricalPriceDataReject()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataReject));
			Type=HISTORICAL_PRICE_DATA_REJECT;
			Size=sizeof(s_HistoricalPriceDataReject);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		int32_t GetRequestID();
		void SetRejectText(const char* NewValue);
		const char* GetRejectText();
	};

	/*==========================================================================*/
	struct s_HistoricalPriceDataRecordResponse
	{
		uint16_t Size;
		uint16_t Type;
		int32_t RequestID;

		t_DateTime StartDateTime;
		double OpenPrice;
		double HighPrice;
		double LowPrice;
		double LastPrice;
		double Volume;
		union
		{
			uint32_t OpenInterest;
			uint32_t NumTrades;
		};
		double BidVolume;
		double AskVolume;

		byte IsFinalRecord;

		s_HistoricalPriceDataRecordResponse()
		{
			Clear(); 
		}

		void Clear()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataRecordResponse));
			Type=HISTORICAL_PRICE_DATA_RECORD_RESPONSE;
			Size=sizeof(s_HistoricalPriceDataRecordResponse);
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		int32_t GetRequestID();
		t_DateTime GetStartDateTime();
		double GetOpenPrice();
		double GetHighPrice();
		double GetLowPrice();
		double GetLastPrice();
		double GetVolume();
		uint32_t GetOpenInterest();
		uint32_t GetNumTrades();
		double GetBidVolume();
		double GetAskVolume();
		byte GetIsFinalRecord();
	};

	/*==========================================================================*/
	struct s_HistoricalPriceDataTickRecordResponse
	{
		uint16_t Size;
		uint16_t Type;
		int32_t RequestID;

		t_DateTimeWithMilliseconds DateTime;
		AtBidOrAskEnum AtBidOrAsk;

		double Price;
		double Volume;

		byte IsFinalRecord;

		s_HistoricalPriceDataTickRecordResponse()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		void Clear()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataTickRecordResponse));
			Type=HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE;
			Size=sizeof(s_HistoricalPriceDataTickRecordResponse);
		}

		int32_t GetRequestID();
		t_DateTimeWithMilliseconds GetDateTime();
		double GetPrice();
		double GetVolume();
		AtBidOrAskEnum GetAtBidOrAsk();	
		byte GetIsFinalRecord();
	};

	/*==========================================================================*/
	struct s_HistoricalPriceDataRecordResponse_Int
	{
		uint16_t Size;
		uint16_t Type;
		int32_t RequestID;

		t_DateTime StartDateTime;
		int32_t OpenPrice;
		int32_t HighPrice;
		int32_t LowPrice;
		int32_t LastPrice;
		int32_t Volume;
		union
		{
			uint32_t OpenInterest;
			uint32_t NumTrades;
		};
		int32_t BidVolume;
		int32_t AskVolume;

		byte IsFinalRecord;

		s_HistoricalPriceDataRecordResponse_Int()
		{
			Clear();
		}

		void Clear()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataRecordResponse_Int));
			Type=HISTORICAL_PRICE_DATA_RECORD_RESPONSE_INT;
			Size=sizeof(s_HistoricalPriceDataRecordResponse_Int);
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);

		int32_t GetRequestID();
		t_DateTime GetStartDateTime();
		int32_t GetOpenPrice();
		int32_t GetHighPrice();
		int32_t GetLowPrice();
		int32_t GetLastPrice();
		int32_t GetVolume();
		uint32_t GetOpenInterest();
		uint32_t GetNumTrades();
		int32_t GetBidVolume();
		int32_t GetAskVolume();
		byte GetIsFinalRecord();
	};

	/*==========================================================================*/
	struct s_HistoricalPriceDataTickRecordResponse_Int
	{
		uint16_t Size;
		uint16_t Type;
		int32_t RequestID;

		t_DateTimeWithMilliseconds DateTime;

		int32_t Price;
		int32_t Volume;

		AtBidOrAskEnum AtBidOrAsk;
		byte IsFinalRecord;

		s_HistoricalPriceDataTickRecordResponse_Int()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		void CopyFrom(void * p_SourceData);
		void Clear()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataTickRecordResponse_Int));
			Type=HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE_INT;
			Size=sizeof(s_HistoricalPriceDataTickRecordResponse_Int);
		}

		int32_t GetRequestID();
		t_DateTimeWithMilliseconds GetDateTime();
		AtBidOrAskEnum GetAtBidOrAsk();	
		int32_t GetPrice();
		int32_t GetVolume();
		byte GetIsFinalRecord();
	};


#pragma pack()
}
