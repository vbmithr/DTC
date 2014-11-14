

#pragma unmanaged

#include <float.h>
#include <limits.h>
#include <string.h>
#include <memory.h> 
#include <stddef.h>

#pragma warning( disable : 4996 )	//	microsoft specific

#include "DTCProtocol.h"


#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

namespace DTC
{


	/****************************************************************************/
	// s_LogonRequest

	/*============================================================================
	Will get the size of the message received over the network
	----------------------------------------------------------------------------*/
	unsigned __int16 s_LogonRequest::GetMessageSize()
	{
		return Size;
	}

	/*============================================================================
	Performs a safe copy of data into this structure instance from the given
	data pointer.
	----------------------------------------------------------------------------*/
	void s_LogonRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_LogonRequest), *static_cast<unsigned __int16*>( p_SourceData)  ));
	}

	/*==========================================================================*/
	__int32 s_LogonRequest::GetProtocolVersion()
	{
		if (Size < offsetof(s_LogonRequest, ProtocolVersion) + sizeof(ProtocolVersion))
			return 0;

		return ProtocolVersion;
	}

	/*==========================================================================*/
	const char* s_LogonRequest::GetUsername()
	{
		if (Size < offsetof(s_LogonRequest, Username) + sizeof(Username))
			return "";

		Username[sizeof(Username) - 1] = '\0';  // Ensure that the null terminator exists

		return Username;
	}

	/*==========================================================================*/
	void s_LogonRequest::SetUsername(const char* NewValue)
	{
		strncpy(Username, NewValue, sizeof(Username) - 1);
	}

	/*==========================================================================*/
	char* s_LogonRequest::GetPassword()
	{
		if (Size < offsetof(s_LogonRequest, Password) + sizeof(Password))
			return "";

		Password[sizeof(Password) - 1] = '\0';

		return Password;
	}

	/*==========================================================================*/
	void s_LogonRequest::SetPassword(const char* NewValue)
	{
		strncpy(Password, NewValue, sizeof(Password) - 1);
	}

	/*==========================================================================*/
	char* s_LogonRequest::GetGeneralTextData()
	{
		if (Size < offsetof(s_LogonRequest, GeneralTextData) + sizeof(GeneralTextData))
			return "";

		GeneralTextData[sizeof(GeneralTextData) - 1] = '\0';

		return GeneralTextData;
	}

	/*==========================================================================*/
	void s_LogonRequest::SetGeneralTextData(const char* NewValue)
	{
		strncpy(GeneralTextData, NewValue, sizeof(GeneralTextData) - 1);
	}

	/*==========================================================================*/
	__int32 s_LogonRequest::GetInteger_1()
	{
		if (Size < offsetof(s_LogonRequest, Integer_1) + sizeof(Integer_1))
			return 0;

		return Integer_1;
	}
	
	/*==========================================================================*/
	__int32 s_LogonRequest::GetInteger_2()
	{
		if (Size < offsetof(s_LogonRequest, Integer_2) + sizeof(Integer_2))
			return 0;

		return Integer_2;
	}


	/*==========================================================================*/
	__int32 s_LogonRequest::GetInHeartbeatIntervalInSeconds()
	{
		if (Size < offsetof(s_LogonRequest, HeartbeatIntervalInSeconds) + sizeof(HeartbeatIntervalInSeconds))
			return 0;

		return HeartbeatIntervalInSeconds;
	}


	/*==========================================================================*/
	TradeModeEnum s_LogonRequest::GetTradeMode()
	{
		if (Size < offsetof(s_LogonRequest, TradeMode) + sizeof(TradeMode))
			return (TradeModeEnum)0;

		return TradeMode;
	}


	/*==========================================================================*/
	char* s_LogonRequest::GetTradeAccount()
	{
		if (Size < offsetof(s_LogonRequest, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}

	/*==========================================================================*/
	void s_LogonRequest::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}

	/*==========================================================================*/
	char* s_LogonRequest::GetHardwareIdentifier()
	{
		if (Size < offsetof(s_LogonRequest, HardwareIdentifier) + sizeof(HardwareIdentifier))
			return "";

		HardwareIdentifier[sizeof(HardwareIdentifier) - 1] = '\0';

		return HardwareIdentifier;
	}

	/*==========================================================================*/
	void s_LogonRequest::SetHardwareIdentifier(const char* NewValue)
	{
		strncpy(HardwareIdentifier, NewValue, sizeof(HardwareIdentifier) - 1);
	}

	/*==========================================================================*/
	char* s_LogonRequest::GetClientName()
	{
		if (Size < offsetof(s_LogonRequest, ClientName) + sizeof(ClientName))
			return "";

		ClientName[sizeof(ClientName) - 1] = '\0';

		return ClientName;
	}

	/*==========================================================================*/
	void s_LogonRequest::SetClientName(const char* NewValue)
	{
		strncpy(ClientName, NewValue, sizeof(ClientName) - 1);
	}

	/****************************************************************************/
	// s_LogonResponse

	/*==========================================================================*/
	unsigned __int16 s_LogonResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_LogonResponse::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_LogonResponse), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	__int32 s_LogonResponse::GetProtocolVersion()
	{
		if (Size < offsetof(s_LogonResponse, ProtocolVersion) + sizeof(ProtocolVersion))
			return 0;

		return ProtocolVersion;
	}

	/*==========================================================================*/
	LogonStatusEnum s_LogonResponse::GetResult()
	{
		if (Size < offsetof(s_LogonResponse, Result) + sizeof(Result))
			return (LogonStatusEnum)0;

		return Result;
	}
	
	/*==========================================================================*/
	char* s_LogonResponse::GetResultText()
	{
		if (Size < offsetof(s_LogonResponse, ResultText) + sizeof(ResultText))
			return "";

		ResultText[sizeof(ResultText) - 1] = '\0';

		return ResultText;
	}

	/*==========================================================================*/
	void s_LogonResponse::SetResultText(const char* NewValue)
	{
		strncpy(ResultText, NewValue, sizeof(ResultText) - 1);
	}

	/*==========================================================================*/
	char* s_LogonResponse::GetReconnectAddress()
	{
		if (Size < offsetof(s_LogonResponse, ReconnectAddress) + sizeof(ReconnectAddress))
			return "";

		ReconnectAddress[sizeof(ReconnectAddress) - 1] = '\0';

		return ReconnectAddress;
	}

	/*==========================================================================*/
	void s_LogonResponse::SetReconnectAddress(const char* NewValue)
	{
		strncpy(ReconnectAddress, NewValue, sizeof(ReconnectAddress) - 1);
	}

	/*==========================================================================*/
	__int32 s_LogonResponse::GetInteger_1()
	{
		if (Size < offsetof(s_LogonResponse, Integer_1) + sizeof(Integer_1))
			return 0;

		return Integer_1;
	}


	/*==========================================================================*/
	char* s_LogonResponse::GetServerName()
	{
		if (Size < offsetof(s_LogonResponse, ServerName) + sizeof(ServerName))
			return "";

		ServerName[sizeof(ServerName) - 1] = '\0';

		return ServerName;
	}

	/*==========================================================================*/
	void s_LogonResponse::SetServerName(const char* NewValue)
	{
		strncpy(ServerName, NewValue, sizeof(ServerName) - 1);
	}


	/*==========================================================================*/
	byte s_LogonResponse::GetMarketDepthUpdatesBestBidAndAsk()
	{
		if (Size < offsetof(s_LogonResponse, MarketDepthUpdatesBestBidAndAsk) + sizeof(MarketDepthUpdatesBestBidAndAsk))
			return 0;

		return MarketDepthUpdatesBestBidAndAsk;
	}

	/*==========================================================================*/
	byte s_LogonResponse::GetTradingIsSupported()
	{
		if (Size < offsetof(s_LogonResponse, TradingIsSupported) + sizeof(TradingIsSupported))
			return 0;

		return TradingIsSupported;
	}


	/*==========================================================================*/
	byte s_LogonResponse::GetOCOOrdersSupported()
	{
		if (Size < offsetof(s_LogonResponse, OCOOrdersSupported) + sizeof(OCOOrdersSupported))
			return 0;

		return OCOOrdersSupported;
	}

	/*==========================================================================*/
	byte s_LogonResponse::GetBracketOrdersSupported()
	{
		if (Size < offsetof(s_LogonResponse, BracketOrdersSupported) + sizeof(BracketOrdersSupported))
			return 0;

		return BracketOrdersSupported;
	}

	/*==========================================================================*/
	byte s_LogonResponse::GetOrderCancelReplaceSupported()
	{
		if (Size < offsetof(s_LogonResponse, OrderCancelReplaceSupported) + sizeof(OrderCancelReplaceSupported))
			return 0;

		return OrderCancelReplaceSupported;
	}


	/*==========================================================================*/
	char* s_LogonResponse::GetSymbolExchangeDelimiter()
	{
		if (Size < offsetof(s_LogonResponse, SymbolExchangeDelimiter) + sizeof(SymbolExchangeDelimiter))
			return "";

		SymbolExchangeDelimiter[sizeof(SymbolExchangeDelimiter) - 1] = '\0';

		return SymbolExchangeDelimiter;
	}

	/*==========================================================================*/
	void s_LogonResponse::SetSymbolExchangeDelimiter(const char* NewValue)
	{
		strncpy(SymbolExchangeDelimiter, NewValue, sizeof(SymbolExchangeDelimiter) - 1);
	}

	/*==========================================================================*/
	byte s_LogonResponse::GetSecurityDefinitionsSupported()
	{
		if (Size < offsetof(s_LogonResponse, SecurityDefinitionsSupported) + sizeof(SecurityDefinitionsSupported))
			return 0;

		return SecurityDefinitionsSupported;
	}


	/*==========================================================================*/
	byte s_LogonResponse::GetHistoricalPriceDataSupported()
	{
		if (Size < offsetof(s_LogonResponse, HistoricalPriceDataSupported) + sizeof(HistoricalPriceDataSupported))
			return 0;

		return HistoricalPriceDataSupported;
	}


	/*==========================================================================*/
	byte s_LogonResponse::GetResubscribeWhenMarketDataFeedRestored()
	{
		if (Size < offsetof(s_LogonResponse, ResubscribeWhenMarketDataFeedRestored) + sizeof(ResubscribeWhenMarketDataFeedRestored))
			return 0;

		return ResubscribeWhenMarketDataFeedRestored;
	}

	/*==========================================================================*/
	byte s_LogonResponse::GetMarketDepthIsSupported()
	{
		if (Size < offsetof(s_LogonResponse, MarketDepthIsSupported) + sizeof(MarketDepthIsSupported))
			return 0;

		return MarketDepthIsSupported;
	}
	/*==========================================================================*/
	byte s_LogonResponse::GetOneHistoricalPriceDataRequestPerConnection()
	{
		if (Size < offsetof(s_LogonResponse, OneHistoricalPriceDataRequestPerConnection) + sizeof(OneHistoricalPriceDataRequestPerConnection))
			return 0;

		return OneHistoricalPriceDataRequestPerConnection;
	}
	/*==========================================================================*/
	byte s_LogonResponse::GetUseIntegerPriceOrderMessages()
	{
		if (Size < offsetof(s_LogonResponse, UseIntegerPriceOrderMessages) + sizeof(UseIntegerPriceOrderMessages))
			return 0;

		return UseIntegerPriceOrderMessages;
	}
	
	/****************************************************************************/
	// s_LogoffRequest

	/*==========================================================================*/
	unsigned __int16 s_LogoffRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_LogoffRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_LogoffRequest), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	char * s_LogoffRequest::GetReason()
	{
		if (Size < offsetof(s_LogoffRequest, Reason) + sizeof(Reason))
			return "";

		Reason[sizeof(Reason) - 1] = '\0';

		return Reason;
	}
	/*==========================================================================*/
	void s_LogoffRequest::SetReason(const char * NewValue)
	{
		strncpy(Reason, NewValue, sizeof(Reason) - 1);
	}


	/****************************************************************************/
	// s_Heartbeat

	/*==========================================================================*/
	unsigned __int16 s_Heartbeat::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_Heartbeat::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_Heartbeat), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int32 s_Heartbeat::GetDroppedMessages()
	{
		if (Size < offsetof(s_Heartbeat, DroppedMessages) + sizeof(DroppedMessages))
			return 0;

		return DroppedMessages;
	}


	/*==========================================================================*/
	t_DateTime s_Heartbeat::GetCurrentDateTime()
	{
		if (Size < offsetof(s_Heartbeat, CurrentDateTime) + sizeof(CurrentDateTime))
			return 0;

		return CurrentDateTime;
	}


	/****************************************************************************/
	// s_DisconnectFromServer

	/*==========================================================================*/
	unsigned __int16 s_DisconnectFromServer::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_DisconnectFromServer::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_DisconnectFromServer), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	char* s_DisconnectFromServer::GetDisconnectReason()
	{
		if (Size < offsetof(s_DisconnectFromServer, DisconnectReason) + sizeof(DisconnectReason))
			return "";

		DisconnectReason[sizeof(DisconnectReason) - 1] = '\0';

		return DisconnectReason;
	}

	/*==========================================================================*/
	void s_DisconnectFromServer::SetDisconnectReason(const char* NewValue)
	{
		strncpy(DisconnectReason, NewValue, sizeof(DisconnectReason) - 1);
	}

	/****************************************************************************/
	// s_MarketDataFeedStatus

	/*==========================================================================*/
	unsigned __int16 s_MarketDataFeedStatus::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataFeedStatus::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataFeedStatus), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	MarketDataFeedStatusEnum s_MarketDataFeedStatus::GetStatus()
	{
		if (Size < offsetof(s_MarketDataFeedStatus, Status) + sizeof(Status))
			return (MarketDataFeedStatusEnum)0;

		return Status;
	}


	/****************************************************************************/
	// s_MarketDataFeedSymbolStatus

	/*==========================================================================*/
	unsigned __int16 s_MarketDataFeedSymbolStatus::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataFeedSymbolStatus::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataFeedSymbolStatus), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_MarketDataFeedSymbolStatus::GetMarketDataSymbolID()
	{
		if (Size < offsetof(s_MarketDataFeedSymbolStatus, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}


	/*==========================================================================*/
	MarketDataFeedStatusEnum s_MarketDataFeedSymbolStatus::GetStatus()
	{
		if (Size < offsetof(s_MarketDataFeedSymbolStatus, Status) + sizeof(Status))
			return (MarketDataFeedStatusEnum)0;

		return Status;
	}


	/****************************************************************************/
	// s_MarketDataRequest

	/*==========================================================================*/
	unsigned __int16 s_MarketDataRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataRequest), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	RequestActionEnum s_MarketDataRequest::GetRequestActionValue()
	{
		if (Size < offsetof(s_MarketDataRequest, RequestActionValue) + sizeof(RequestActionValue))
			return (RequestActionEnum)0;

		return RequestActionValue;
	}


	/*==========================================================================*/
	unsigned __int16 s_MarketDataRequest::GetMarketDataSymbolID()
	{
		if (Size < offsetof(s_MarketDataRequest, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}


	/*==========================================================================*/
	char* s_MarketDataRequest::GetSymbol()
	{
		if (Size < offsetof(s_MarketDataRequest, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}

	/*==========================================================================*/
	void s_MarketDataRequest::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	char* s_MarketDataRequest::GetExchange()
	{
		if (Size < offsetof(s_MarketDataRequest, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_MarketDataRequest::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}

	/****************************************************************************/
	// s_MarketDepthRequest

	/*==========================================================================*/
	unsigned __int16 s_MarketDepthRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDepthRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDepthRequest), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	RequestActionEnum s_MarketDepthRequest::GetRequestActionValue()
	{
		if (Size < offsetof(s_MarketDepthRequest, RequestActionValue) + sizeof(RequestActionValue))
			return (RequestActionEnum)0;

		return RequestActionValue;
	}


	/*==========================================================================*/
	unsigned __int16 s_MarketDepthRequest::GetMarketDataSymbolID()
	{
		if (Size < offsetof(s_MarketDepthRequest, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}


	/*==========================================================================*/
	char* s_MarketDepthRequest::GetSymbol()
	{
		if (Size < offsetof(s_MarketDepthRequest, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}

	/*==========================================================================*/
	void s_MarketDepthRequest::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	char* s_MarketDepthRequest::GetExchange()
	{
		if (Size < offsetof(s_MarketDepthRequest, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_MarketDepthRequest::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}

	/*==========================================================================*/
	__int32 s_MarketDepthRequest::GetNumberOfLevels()
	{
		if (Size < offsetof(s_MarketDepthRequest, NumberOfLevels) + sizeof(NumberOfLevels))
			return 0;

		return NumberOfLevels;
	}


	/****************************************************************************/
	// s_MarketDataReject

	/*==========================================================================*/
	unsigned __int16 s_MarketDataReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataReject::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataReject), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_MarketDataReject::GetMarketDataSymbolID()
	{
		if (Size < offsetof(s_MarketDataReject, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	char* s_MarketDataReject::GetRejectText()
	{
		if (Size < offsetof(s_MarketDataReject, RejectText) + sizeof(RejectText))
			return "";

		RejectText[sizeof(RejectText) - 1] = '\0';

		return RejectText;
	}

	/*==========================================================================*/
	void s_MarketDataReject::SetRejectText(const char* NewValue)
	{
		strncpy(RejectText, NewValue, sizeof(RejectText) - 1);
	}

	/****************************************************************************/
	// s_MarketDepthReject

	/*==========================================================================*/
	unsigned __int16 s_MarketDepthReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDepthReject::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDepthReject), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_MarketDepthReject::GetMarketDataSymbolID()
	{
		if (Size < offsetof(s_MarketDepthReject, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	char* s_MarketDepthReject::GetRejectText()
	{
		if (Size < offsetof(s_MarketDepthReject, RejectText) + sizeof(RejectText))
			return "";

		RejectText[sizeof(RejectText) - 1] = '\0';

		return RejectText;
	}

	/*==========================================================================*/
	void s_MarketDepthReject::SetRejectText(const char* NewValue)
	{
		strncpy(RejectText, NewValue, sizeof(RejectText) - 1);
	}

	/****************************************************************************/
	// s_MarketDataSnapshot

	/*==========================================================================*/
	unsigned __int16 s_MarketDataSnapshot::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataSnapshot::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataSnapshot), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_MarketDataSnapshot::GetMarketDataSymbolID()
	{
		if (Size < offsetof(s_MarketDataSnapshot, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}


	/*==========================================================================*/
	double s_MarketDataSnapshot::GetSettlementPrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot, SettlementPrice) + sizeof(SettlementPrice))
			return 0;

		return SettlementPrice;
	}


	/*==========================================================================*/
	double s_MarketDataSnapshot::GetDailyOpen()
	{
		if (Size < offsetof(s_MarketDataSnapshot, DailyOpen) + sizeof(DailyOpen))
			return 0;

		return DailyOpen;
	}


	/*==========================================================================*/
	double s_MarketDataSnapshot::GetDailyHigh()
	{
		if (Size < offsetof(s_MarketDataSnapshot, DailyHigh) + sizeof(DailyHigh))
			return 0;

		return DailyHigh;
	}


	/*==========================================================================*/
	double s_MarketDataSnapshot::GetDailyLow()
	{
		if (Size < offsetof(s_MarketDataSnapshot, DailyLow) + sizeof(DailyLow))
			return 0;

		return DailyLow;
	}


	/*==========================================================================*/
	double s_MarketDataSnapshot::GetDailyVolume()
	{
		if (Size < offsetof(s_MarketDataSnapshot, DailyVolume) + sizeof(DailyVolume))
			return 0;

		return DailyVolume;
	}


	/*==========================================================================*/
	unsigned __int32 s_MarketDataSnapshot::GetDailyNumberOfTrades()
	{
		if (Size < offsetof(s_MarketDataSnapshot, DailyNumberOfTrades) + sizeof(DailyNumberOfTrades))
			return 0;

		return DailyNumberOfTrades;
	}

	/*==========================================================================*/
	unsigned __int32 s_MarketDataSnapshot::GetSharesOutstanding()
	{
		if (Size < offsetof(s_MarketDataSnapshot, SharesOutstanding) + sizeof(SharesOutstanding))
			return 0;

		return SharesOutstanding;
	}


	/*==========================================================================*/
	unsigned __int32 s_MarketDataSnapshot::GetOpenInterest()
	{
		if (Size < offsetof(s_MarketDataSnapshot, OpenInterest) + sizeof(OpenInterest))
			return 0;

		return OpenInterest;
	}


	/*==========================================================================*/
	unsigned __int32 s_MarketDataSnapshot::GetUnitsOutstanding()
	{
		if (Size < offsetof(s_MarketDataSnapshot, UnitsOutstanding) + sizeof(UnitsOutstanding))
			return 0;

		return UnitsOutstanding;
	}


	/*==========================================================================*/
	double s_MarketDataSnapshot::GetBid()
	{
		if (Size < offsetof(s_MarketDataSnapshot, Bid) + sizeof(Bid))
			return 0;

		return Bid;
	}
	/*==========================================================================*/
	double s_MarketDataSnapshot::GetAsk()
	{
		if (Size < offsetof(s_MarketDataSnapshot, Ask) + sizeof(Ask))
			return 0;

		return Ask;
	}

	/*==========================================================================*/
	double s_MarketDataSnapshot::GetAskSize()
	{
		if (Size < offsetof(s_MarketDataSnapshot, AskSize) + sizeof(AskSize))
			return 0;

		return AskSize;
	}


	/*==========================================================================*/
	double s_MarketDataSnapshot::GetBidSize()
	{
		if (Size < offsetof(s_MarketDataSnapshot, BidSize) + sizeof(BidSize))
			return 0;

		return BidSize;
	}

	/*==========================================================================*/
	double s_MarketDataSnapshot::GetLastTradePrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot, LastTradePrice) + sizeof(LastTradePrice))
			return 0;

		return LastTradePrice;
	}

	/*==========================================================================*/
	double s_MarketDataSnapshot::GetLastTradeSize()
	{
		if (Size < offsetof(s_MarketDataSnapshot, LastTradeSize) + sizeof(LastTradeSize))
			return 0;

		return LastTradeSize;
	}
	/*==========================================================================*/
	double s_MarketDataSnapshot::GetLastTradeDateTimeUnix()
	{
		if (Size < offsetof(s_MarketDataSnapshot, LastTradeDateTimeUnix) + sizeof(LastTradeDateTimeUnix))
			return 0;

		return LastTradeDateTimeUnix;
	}


	/*==========================================================================*/
	void s_MarketDataSnapshot::SetToUnsetValues()
	{
		SettlementPrice = DBL_MAX;
		DailyOpen = DBL_MAX;
		DailyHigh = DBL_MAX;
		DailyLow = DBL_MAX;
		DailyVolume = DBL_MAX;
		DailyNumberOfTrades = UINT_MAX;

		SharesOutstanding = UINT_MAX;

		Bid = DBL_MAX;
		Ask = DBL_MAX;
		AskSize = DBL_MAX;
		BidSize = DBL_MAX;

		LastTradePrice = DBL_MAX;
		LastTradeSize = DBL_MAX;
	}


	/****************************************************************************/
	// s_MarketDataSnapshot_Int

	/*==========================================================================*/
	unsigned __int16 s_MarketDataSnapshot_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDataSnapshot_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDataSnapshot_Int), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_MarketDataSnapshot_Int::GetMarketDataSymbolID()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}


	/*==========================================================================*/
	__int32 s_MarketDataSnapshot_Int::GetSettlementPrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, SettlementPrice) + sizeof(SettlementPrice))
			return 0;

		return SettlementPrice;
	}


	/*==========================================================================*/
	__int32 s_MarketDataSnapshot_Int::GetDailyOpen()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, DailyOpen) + sizeof(DailyOpen))
			return 0;

		return DailyOpen;
	}


	/*==========================================================================*/
	__int32 s_MarketDataSnapshot_Int::GetDailyHigh()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, DailyHigh) + sizeof(DailyHigh))
			return 0;

		return DailyHigh;
	}


	/*==========================================================================*/
	__int32 s_MarketDataSnapshot_Int::GetDailyLow()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, DailyLow) + sizeof(DailyLow))
			return 0;

		return DailyLow;
	}


	/*==========================================================================*/
	double s_MarketDataSnapshot_Int::GetDailyVolume()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, DailyVolume) + sizeof(DailyVolume))
			return 0;

		return DailyVolume;
	}


	/*==========================================================================*/
	unsigned __int32 s_MarketDataSnapshot_Int::GetDailyNumberOfTrades()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, DailyNumberOfTrades) + sizeof(DailyNumberOfTrades))
			return 0;

		return DailyNumberOfTrades;
	}

	/*==========================================================================*/
	unsigned __int32 s_MarketDataSnapshot_Int::GetSharesOutstanding()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, SharesOutstanding) + sizeof(SharesOutstanding))
			return 0;

		return SharesOutstanding;
	}


	/*==========================================================================*/
	unsigned __int32 s_MarketDataSnapshot_Int::GetOpenInterest()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, OpenInterest) + sizeof(OpenInterest))
			return 0;

		return OpenInterest;
	}


	/*==========================================================================*/
	unsigned __int32 s_MarketDataSnapshot_Int::GetUnitsOutstanding()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, UnitsOutstanding) + sizeof(UnitsOutstanding))
			return 0;

		return UnitsOutstanding;
	}


	/*==========================================================================*/
	__int32 s_MarketDataSnapshot_Int::GetBid()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, Bid) + sizeof(Bid))
			return 0;

		return Bid;
	}
	/*==========================================================================*/
	__int32 s_MarketDataSnapshot_Int::GetAsk()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, Ask) + sizeof(Ask))
			return 0;

		return Ask;
	}

	/*==========================================================================*/
	double s_MarketDataSnapshot_Int::GetAskSize()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, AskSize) + sizeof(AskSize))
			return 0;

		return AskSize;
	}


	/*==========================================================================*/
	double s_MarketDataSnapshot_Int::GetBidSize()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, BidSize) + sizeof(BidSize))
			return 0;

		return BidSize;
	}

	/*==========================================================================*/
	__int32 s_MarketDataSnapshot_Int::GetLastTradePrice()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, LastTradePrice) + sizeof(LastTradePrice))
			return 0;

		return LastTradePrice;
	}

	/*==========================================================================*/
	double s_MarketDataSnapshot_Int::GetLastTradeSize()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, LastTradeSize) + sizeof(LastTradeSize))
			return 0;

		return LastTradeSize;
	}
	/*==========================================================================*/
	double s_MarketDataSnapshot_Int::GetLastTradeDateTimeUnix()
	{
		if (Size < offsetof(s_MarketDataSnapshot_Int, LastTradeDateTimeUnix) + sizeof(LastTradeDateTimeUnix))
			return 0;

		return LastTradeDateTimeUnix;
	}


	/*==========================================================================*/
	void s_MarketDataSnapshot_Int::SetToUnsetValues()
	{
		SettlementPrice = INT_MAX;
		DailyOpen = INT_MAX;
		DailyHigh = INT_MAX;
		DailyLow = INT_MAX;
		DailyVolume = DBL_MAX;
		DailyNumberOfTrades = UINT_MAX;

		SharesOutstanding = UINT_MAX;

		Bid = INT_MAX;
		Ask = INT_MAX;
		AskSize = FLT_MAX;
		BidSize = FLT_MAX;

		LastTradePrice = INT_MAX;
		LastTradeSize = DBL_MAX;
	}


	/****************************************************************************/
	// s_FundamentalDataRequest

	/*==========================================================================*/
	unsigned __int16 s_FundamentalDataRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_FundamentalDataRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_FundamentalDataRequest), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_FundamentalDataRequest::GetMarketDataSymbolID()
	{
		if (Size < offsetof(s_FundamentalDataRequest, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	char* s_FundamentalDataRequest::GetSymbol()
	{
		if (Size < offsetof(s_FundamentalDataRequest, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}

	/*==========================================================================*/
	void s_FundamentalDataRequest::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	char* s_FundamentalDataRequest::GetExchange()
	{
		if (Size < offsetof(s_FundamentalDataRequest, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_FundamentalDataRequest::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}


	/****************************************************************************/
	// s_FundamentalDataResponse

	/*==========================================================================*/
	unsigned __int16 s_FundamentalDataResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_FundamentalDataResponse::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_FundamentalDataResponse), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_FundamentalDataResponse::GetMarketDataSymbolID()
	{
		if (Size < offsetof(s_FundamentalDataResponse, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	char* s_FundamentalDataResponse::GetSymbolDescription()
	{
		if (Size < offsetof(s_FundamentalDataResponse, SymbolDescription) + sizeof(SymbolDescription))
			return "";

		SymbolDescription[sizeof(SymbolDescription) - 1] = '\0';

		return SymbolDescription;
	}

	/*==========================================================================*/
	void s_FundamentalDataResponse::SetSymbolDescription(const char* NewValue)
	{
		strncpy(SymbolDescription, NewValue, sizeof(SymbolDescription) - 1);
	}

	/*==========================================================================*/
	float s_FundamentalDataResponse::GetTickSize()
	{
		if (Size < offsetof(s_FundamentalDataResponse, TickSize) + sizeof(TickSize))
			return 0;

		return TickSize;
	}


	/*==========================================================================*/
	float s_FundamentalDataResponse::GetTickCurrencyValue()
	{
		if (Size < offsetof(s_FundamentalDataResponse, TickCurrencyValue) + sizeof(TickCurrencyValue))
			return 0;

		return TickCurrencyValue;
	}


	/*==========================================================================*/
	DisplayFormatEnum s_FundamentalDataResponse::GetDisplayFormat()
	{
		if (Size < offsetof(s_FundamentalDataResponse, DisplayFormat) + sizeof(DisplayFormat))
			return (DisplayFormatEnum)0;

		return DisplayFormat;
	}


	/*==========================================================================*/
	float s_FundamentalDataResponse::GetBuyRolloverInterest()
	{
		if (Size < offsetof(s_FundamentalDataResponse, BuyRolloverInterest) + sizeof(BuyRolloverInterest))
			return 0;

		return BuyRolloverInterest;
	}


	/*==========================================================================*/
	float s_FundamentalDataResponse::GetSellRolloverInterest()
	{
		if (Size < offsetof(s_FundamentalDataResponse, SellRolloverInterest) + sizeof(SellRolloverInterest))
			return 0;

		return SellRolloverInterest;
	}


	/*==========================================================================*/
	float s_FundamentalDataResponse::GetOrderPriceMultiplier()
	{
		if (Size < offsetof(s_FundamentalDataResponse, OrderPriceMultiplier) + sizeof(OrderPriceMultiplier))
			return 0;

		return OrderPriceMultiplier;
	}
	/*==========================================================================*/
	float s_FundamentalDataResponse::GetMarketDataPriceDivisor()
	{
		if (Size < offsetof(s_FundamentalDataResponse, MarketDataPriceDivisor) + sizeof(MarketDataPriceDivisor))
			return 0;

		return MarketDataPriceDivisor;
	}


	/****************************************************************************/
	// s_MarketDepthFullUpdate20

	/*==========================================================================*/
	unsigned __int16 s_MarketDepthFullUpdate20::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDepthFullUpdate20::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDepthFullUpdate20), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_MarketDepthFullUpdate20::GetMarketDataSymbolID()
	{
		if (Size < offsetof(s_MarketDepthFullUpdate20, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/****************************************************************************/
	// s_MarketDepthSnapshotLevel

	/*==========================================================================*/
	unsigned __int16 s_MarketDepthSnapshotLevel::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	unsigned __int16 s_MarketDepthSnapshotLevel::GetMarketDataSymbolID()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	BidOrAskEnum s_MarketDepthSnapshotLevel::GetSide()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel, Side) + sizeof(Side))
			return BID_ASK_UNSET;

		return Side;
	}

	/*==========================================================================*/
	double s_MarketDepthSnapshotLevel::GetPrice()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel, Price) + sizeof(Price))
			return 0.0;

		return Price;
	}

	/*==========================================================================*/
	double s_MarketDepthSnapshotLevel::GetVolume()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel, Volume) + sizeof(Volume))
			return 0.0;

		return Volume;
	}

	/*==========================================================================*/
	unsigned __int16 s_MarketDepthSnapshotLevel::GetLevel()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel, Level) + sizeof(Level))
			return 0;

		return Level;
	}

	/*==========================================================================*/
	byte s_MarketDepthSnapshotLevel::GetFirstMessageInBatch()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel, FirstMessageInBatch) + sizeof(FirstMessageInBatch))
			return 0;

		return FirstMessageInBatch;
	}

	/*==========================================================================*/
	byte s_MarketDepthSnapshotLevel::GetLastMessageInBatch()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel, LastMessageInBatch) + sizeof(LastMessageInBatch))
			return 0;

		return LastMessageInBatch;
	}

	/*==========================================================================*/
	void s_MarketDepthSnapshotLevel::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDepthSnapshotLevel), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/****************************************************************************/
	// s_MarketDepthSnapshotLevel_Int

	/*==========================================================================*/
	unsigned __int16 s_MarketDepthSnapshotLevel_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	unsigned __int16 s_MarketDepthSnapshotLevel_Int::GetMarketDataSymbolID()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel_Int, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	BidOrAskEnum s_MarketDepthSnapshotLevel_Int::GetSide()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel_Int, Side) + sizeof(Side))
			return BID_ASK_UNSET;

		return Side;
	}

	/*==========================================================================*/
	__int32 s_MarketDepthSnapshotLevel_Int::GetPrice()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel_Int, Price) + sizeof(Price))
			return 0;

		return Price;
	}

	/*==========================================================================*/
	double s_MarketDepthSnapshotLevel_Int::GetVolume()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel_Int, Volume) + sizeof(Volume))
			return 0.0;

		return Volume;
	}

	/*==========================================================================*/
	unsigned __int16 s_MarketDepthSnapshotLevel_Int::GetLevel()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel_Int, Level) + sizeof(Level))
			return 0;

		return Level;
	}

	/*==========================================================================*/
	byte s_MarketDepthSnapshotLevel_Int::GetFirstMessageInBatch()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel_Int, FirstMessageInBatch) + sizeof(FirstMessageInBatch))
			return 0;

		return FirstMessageInBatch;
	}

	/*==========================================================================*/
	byte s_MarketDepthSnapshotLevel_Int::GetLastMessageInBatch()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel_Int, LastMessageInBatch) + sizeof(LastMessageInBatch))
			return 0;

		return LastMessageInBatch;
	}

	/*==========================================================================*/
	void s_MarketDepthSnapshotLevel_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDepthSnapshotLevel_Int), *static_cast<unsigned __int16*>( p_SourceData) ));
	}


	/****************************************************************************/
	// s_MarketDepthIncrementalUpdate

	/*==========================================================================*/
	unsigned __int16 s_MarketDepthIncrementalUpdate::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDepthIncrementalUpdate::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDepthIncrementalUpdate), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	unsigned __int16 s_MarketDepthIncrementalUpdate::GetMarketDataSymbolID()
	{
		if (Size < offsetof(s_MarketDepthIncrementalUpdate, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	BidOrAskEnum s_MarketDepthIncrementalUpdate::GetSide()
	{
		if (Size < offsetof(s_MarketDepthIncrementalUpdate, Side) + sizeof(Side))
			return BID_ASK_UNSET;

		return Side;
	}
	/*==========================================================================*/
	double s_MarketDepthIncrementalUpdate::GetPrice() 
	{
		if (Size < offsetof(s_MarketDepthIncrementalUpdate, Price) + sizeof(Price))
			return 0;

		return Price;
	}

	/*==========================================================================*/
	double s_MarketDepthIncrementalUpdate::GetVolume() 
	{
		if (Size < offsetof(s_MarketDepthIncrementalUpdate, Volume) + sizeof(Volume))
			return 0;

		return Volume;
	}

	/*==========================================================================*/
	MarketDepthIncrementalUpdateTypeEnum s_MarketDepthIncrementalUpdate::GetUpdateType() 
	{
		if (Size < offsetof(s_MarketDepthIncrementalUpdate, UpdateType) + sizeof(UpdateType))
			return DEPTH_UNSET;

		return UpdateType;
	}


	/****************************************************************************/
	// s_MarketDepthIncrementalUpdate_Int

	/*==========================================================================*/
	unsigned __int16 s_MarketDepthIncrementalUpdate_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDepthIncrementalUpdate_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDepthIncrementalUpdate_Int), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	unsigned __int16 s_MarketDepthIncrementalUpdate_Int::GetMarketDataSymbolID()
	{
		if (Size < offsetof(s_MarketDepthIncrementalUpdate_Int, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	BidOrAskEnum s_MarketDepthIncrementalUpdate_Int::GetSide()
	{
		if (Size < offsetof(s_MarketDepthIncrementalUpdate_Int, Side) + sizeof(Side))
			return BID_ASK_UNSET;

		return Side;
	}


	/*==========================================================================*/
	__int32 s_MarketDepthIncrementalUpdate_Int::GetPrice() 
	{
		if (Size < offsetof(s_MarketDepthIncrementalUpdate_Int, Price) + sizeof(Price))
			return 0;

		return Price;
	}

	/*==========================================================================*/
	double s_MarketDepthIncrementalUpdate_Int::GetVolume() 
	{
		if (Size < offsetof(s_MarketDepthIncrementalUpdate_Int, Volume) + sizeof(Volume))
			return 0;

		return Volume;
	}

	/*==========================================================================*/
	MarketDepthIncrementalUpdateTypeEnum s_MarketDepthIncrementalUpdate_Int::GetUpdateType() 
	{
		if (Size < offsetof(s_MarketDepthIncrementalUpdate_Int, UpdateType) + sizeof(UpdateType))
			return DEPTH_UNSET;

		return UpdateType;
	}


	/****************************************************************************/
	// s_MarketDepthIncrementalUpdateCompact

	/*==========================================================================*/
	unsigned __int16 s_MarketDepthIncrementalUpdateCompact::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_MarketDepthIncrementalUpdateCompact::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_MarketDepthIncrementalUpdateCompact), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_MarketDepthIncrementalUpdateCompact::GetMarketDataSymbolID() const
	{
		if (Size < offsetof(s_MarketDepthIncrementalUpdateCompact, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	BidOrAskEnum s_MarketDepthIncrementalUpdateCompact::GetSide() const
	{
		if (Size < offsetof(s_MarketDepthIncrementalUpdateCompact, Side) + sizeof(Side))
			return BID_ASK_UNSET;

		return Side;
	}

	/*==========================================================================*/
	float s_MarketDepthIncrementalUpdateCompact::GetPrice() const
	{
		if (Size < offsetof(s_MarketDepthIncrementalUpdateCompact, Price) + sizeof(Price))
			return 0.0f;

		return Price;
	}

	/*==========================================================================*/
	float s_MarketDepthIncrementalUpdateCompact::GetVolume() const
	{
		if (Size < offsetof(s_MarketDepthIncrementalUpdateCompact, Volume) + sizeof(Volume))
			return 0;

		return Volume;
	}

	/*==========================================================================*/
	MarketDepthIncrementalUpdateTypeEnum s_MarketDepthIncrementalUpdateCompact::GetUpdateType() const
	{
		if (Size < offsetof(s_MarketDepthIncrementalUpdateCompact, UpdateType) + sizeof(UpdateType))
			return DEPTH_UNSET;

		return UpdateType;
	}

	/****************************************************************************/
	// s_SettlementIncrementalUpdate

	/*==========================================================================*/
	unsigned __int16 s_SettlementIncrementalUpdate::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SettlementIncrementalUpdate::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SettlementIncrementalUpdate), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_SettlementIncrementalUpdate::GetMarketDataSymbolID() const
	{
		if (Size < offsetof(s_SettlementIncrementalUpdate, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	double s_SettlementIncrementalUpdate::GetSettlementPrice() const
	{
		if (Size < offsetof(s_SettlementIncrementalUpdate, SettlementPrice) + sizeof(SettlementPrice))
			return 0;

		return SettlementPrice;
	}

		/****************************************************************************/
	// s_SettlementIncrementalUpdate_Int

	/*==========================================================================*/
	unsigned __int16 s_SettlementIncrementalUpdate_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SettlementIncrementalUpdate_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SettlementIncrementalUpdate_Int), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_SettlementIncrementalUpdate_Int::GetMarketDataSymbolID() const
	{
		if (Size < offsetof(s_SettlementIncrementalUpdate_Int, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	__int32 s_SettlementIncrementalUpdate_Int::GetSettlementPrice() const
	{
		if (Size < offsetof(s_SettlementIncrementalUpdate_Int, SettlementPrice) + sizeof(SettlementPrice))
			return 0;

		return SettlementPrice;
	}


	/****************************************************************************/
	// s_DailyOpenIncrementalUpdate

	/*==========================================================================*/
	unsigned __int16 s_DailyOpenIncrementalUpdate::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_DailyOpenIncrementalUpdate::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_DailyOpenIncrementalUpdate), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_DailyOpenIncrementalUpdate::GetMarketDataSymbolID() const
	{
		if (Size < offsetof(s_DailyOpenIncrementalUpdate, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	double s_DailyOpenIncrementalUpdate::GetDailyOpen() const
	{
		if (Size < offsetof(s_DailyOpenIncrementalUpdate, DailyOpen) + sizeof(DailyOpen))
			return 0;

		return DailyOpen;
	}

	/****************************************************************************/
	// s_DailyOpenIncrementalUpdate_Int

	/*==========================================================================*/
	unsigned __int16 s_DailyOpenIncrementalUpdate_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_DailyOpenIncrementalUpdate_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_DailyOpenIncrementalUpdate_Int), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_DailyOpenIncrementalUpdate_Int::GetMarketDataSymbolID() const
	{
		if (Size < offsetof(s_DailyOpenIncrementalUpdate_Int, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	__int32 s_DailyOpenIncrementalUpdate_Int::GetDailyOpen() const
	{
		if (Size < offsetof(s_DailyOpenIncrementalUpdate_Int, DailyOpen) + sizeof(DailyOpen))
			return 0;

		return DailyOpen;
	}


	/****************************************************************************/
	// s_TradeIncrementalUpdate

	/*==========================================================================*/
	unsigned __int16 s_TradeIncrementalUpdate::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_TradeIncrementalUpdate::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_TradeIncrementalUpdate), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	unsigned __int16 s_TradeIncrementalUpdate::GetMarketDataSymbolID() 
	{
		if (Size < offsetof(s_TradeIncrementalUpdate, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}
	/*==========================================================================*/
	BidOrAskEnum s_TradeIncrementalUpdate::GetTradeAtBidOrAsk() 
	{
		if (Size < offsetof(s_TradeIncrementalUpdate, TradeAtBidOrAsk) + sizeof(TradeAtBidOrAsk))
			return BID_ASK_UNSET;

		return TradeAtBidOrAsk;
	}

	/*==========================================================================*/
	double s_TradeIncrementalUpdate::GetPrice() 
	{
		if (Size < offsetof(s_TradeIncrementalUpdate, Price) + sizeof(Price))
			return 0;

		return Price;
	}

	/*==========================================================================*/
	double s_TradeIncrementalUpdate::GetTradeVolume() 
	{
		if (Size < offsetof(s_TradeIncrementalUpdate, TradeVolume) + sizeof(TradeVolume))
			return 0;

		return TradeVolume;
	}
	/*==========================================================================*/

	double s_TradeIncrementalUpdate::GetTradeDateTimeUnix() 
	{
		if (Size < offsetof(s_TradeIncrementalUpdate, TradeDateTimeUnix) + sizeof(TradeDateTimeUnix))
			return 0;

		return TradeDateTimeUnix;
	}


		/****************************************************************************/
	// s_TradeIncrementalUpdate_Int

	/*==========================================================================*/
	unsigned __int16 s_TradeIncrementalUpdate_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_TradeIncrementalUpdate_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_TradeIncrementalUpdate_Int), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	unsigned __int16 s_TradeIncrementalUpdate_Int::GetMarketDataSymbolID() 
	{
		if (Size < offsetof(s_TradeIncrementalUpdate_Int, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}
	/*==========================================================================*/
	BidOrAskEnum s_TradeIncrementalUpdate_Int::GetTradeAtBidOrAsk() 
	{
		if (Size < offsetof(s_TradeIncrementalUpdate_Int, TradeAtBidOrAsk) + sizeof(TradeAtBidOrAsk))
			return BID_ASK_UNSET;

		return TradeAtBidOrAsk;
	}
	/*==========================================================================*/
	__int32 s_TradeIncrementalUpdate_Int::GetPrice() 
	{
		if (Size < offsetof(s_TradeIncrementalUpdate_Int, Price) + sizeof(Price))
			return 0;

		return Price;
	}
	/*==========================================================================*/
	float s_TradeIncrementalUpdate_Int::GetTradeVolume() 
	{
		if (Size < offsetof(s_TradeIncrementalUpdate_Int, TradeVolume) + sizeof(TradeVolume))
			return 0;

		return TradeVolume;
	}
	/*==========================================================================*/
	double s_TradeIncrementalUpdate_Int::GetTradeDateTimeUnix() 
	{
		if (Size < offsetof(s_TradeIncrementalUpdate_Int, TradeDateTimeUnix) + sizeof(TradeDateTimeUnix))
			return 0;

		return TradeDateTimeUnix;
	}

	/****************************************************************************/
	// s_QuoteIncrementalUpdate

	/*==========================================================================*/
	unsigned __int16 s_QuoteIncrementalUpdate::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_QuoteIncrementalUpdate::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_QuoteIncrementalUpdate), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_QuoteIncrementalUpdate::GetMarketDataSymbolID() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdate, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	double s_QuoteIncrementalUpdate::GetBidPrice() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdate, BidPrice) + sizeof(BidPrice))
			return 0.0;

		return BidPrice;
	}

	/*==========================================================================*/
	float s_QuoteIncrementalUpdate::GetBidSize() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdate, BidSize) + sizeof(BidSize))
			return 0;

		return BidSize;
	}

	/*==========================================================================*/
	double s_QuoteIncrementalUpdate::GetAskPrice() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdate, AskPrice) + sizeof(AskPrice))
			return 0.0;

		return AskPrice;
	}

	/*==========================================================================*/
	float s_QuoteIncrementalUpdate::GetAskSize() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdate, AskSize) + sizeof(AskSize))
			return 0;

		return AskSize;
	}

	/*==========================================================================*/
	double s_QuoteIncrementalUpdate::GetQuoteDateTimeUnix() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdate, QuoteDateTimeUnix) + sizeof(QuoteDateTimeUnix))
			return 0;

		return QuoteDateTimeUnix;
	}

	/****************************************************************************/
	// s_QuoteIncrementalUpdate_Int

	/*==========================================================================*/
	unsigned __int16 s_QuoteIncrementalUpdate_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_QuoteIncrementalUpdate_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_QuoteIncrementalUpdate_Int), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_QuoteIncrementalUpdate_Int::GetMarketDataSymbolID() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdate_Int, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	__int32 s_QuoteIncrementalUpdate_Int::GetBidPrice() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdate_Int, BidPrice) + sizeof(BidPrice))
			return 0;

		return BidPrice;
	}

	/*==========================================================================*/
	float s_QuoteIncrementalUpdate_Int::GetBidSize() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdate_Int, BidSize) + sizeof(BidSize))
			return 0;

		return BidSize;
	}

	/*==========================================================================*/
	__int32 s_QuoteIncrementalUpdate_Int::GetAskPrice() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdate_Int, AskPrice) + sizeof(AskPrice))
			return 0;

		return AskPrice;
	}

	/*==========================================================================*/
	float s_QuoteIncrementalUpdate_Int::GetAskSize() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdate_Int, AskSize) + sizeof(AskSize))
			return 0;

		return AskSize;
	}

	/*==========================================================================*/
	double s_QuoteIncrementalUpdate_Int::GetQuoteDateTimeUnix() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdate_Int, QuoteDateTimeUnix) + sizeof(QuoteDateTimeUnix))
			return 0;

		return QuoteDateTimeUnix;
	}


	/****************************************************************************/
	// s_QuoteIncrementalUpdateCompact

	/*==========================================================================*/
	unsigned __int16 s_QuoteIncrementalUpdateCompact::GetMarketDataSymbolID() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdateCompact, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	float s_QuoteIncrementalUpdateCompact::GetBidPrice() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdateCompact, BidPrice) + sizeof(BidPrice))
			return 0.0;

		return BidPrice;
	}

	/*==========================================================================*/
	float s_QuoteIncrementalUpdateCompact::GetBidSize() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdateCompact, BidSize) + sizeof(BidSize))
			return 0;

		return BidSize;
	}

	/*==========================================================================*/
	float s_QuoteIncrementalUpdateCompact::GetAskPrice() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdateCompact, AskPrice) + sizeof(AskPrice))
			return 0.0;

		return AskPrice;
	}

	/*==========================================================================*/
	float s_QuoteIncrementalUpdateCompact::GetAskSize() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdateCompact, AskSize) + sizeof(AskSize))
			return 0;

		return AskSize;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_QuoteIncrementalUpdateCompact::GetQuoteDateTimeUnix() const
	{
		if (Size < offsetof(s_QuoteIncrementalUpdateCompact, QuoteDateTimeUnix) + sizeof(QuoteDateTimeUnix))
			return 0;

		return QuoteDateTimeUnix;
	}
	/*==========================================================================*/

	unsigned __int16 s_QuoteIncrementalUpdateCompact::GetMessageSize()
	{
		return Size;
	}

	/****************************************************************************/
	// s_TradeIncrementalUpdateCompact

	/*==========================================================================*/
	unsigned __int16 s_TradeIncrementalUpdateCompact::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_TradeIncrementalUpdateCompact::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_TradeIncrementalUpdateCompact), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	float s_TradeIncrementalUpdateCompact::GetPrice() const
	{
		if (Size < offsetof(s_TradeIncrementalUpdateCompact, Price) + sizeof(Price))
			return 0.0;

		return Price;
	}

	/*==========================================================================*/
	float s_TradeIncrementalUpdateCompact::GetTradeVolume() const
	{
		if (Size < offsetof(s_TradeIncrementalUpdateCompact, TradeVolume) + sizeof(TradeVolume))
			return 0;

		return TradeVolume;
	}

	/*==========================================================================*/
	t_DateTime4Byte s_TradeIncrementalUpdateCompact::GetTradeDateTimeUnix() const
	{
		if (Size < offsetof(s_TradeIncrementalUpdateCompact, TradeDateTimeUnix) + sizeof(TradeDateTimeUnix))
			return 0;

		return TradeDateTimeUnix;
	}

	/*==========================================================================*/
	unsigned __int16 s_TradeIncrementalUpdateCompact::GetMarketDataSymbolID() const
	{
		if (Size < offsetof(s_TradeIncrementalUpdateCompact, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	BidOrAskEnum s_TradeIncrementalUpdateCompact::GetTradeAtBidOrAsk() const
	{
		if (Size < offsetof(s_TradeIncrementalUpdateCompact, TradeAtBidOrAsk) + sizeof(TradeAtBidOrAsk))
			return BID_ASK_UNSET;

		return TradeAtBidOrAsk;
	}

	/****************************************************************************/
	// s_DailyVolumeIncrementalUpdate

	/*==========================================================================*/
	unsigned __int16 s_DailyVolumeIncrementalUpdate::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_DailyVolumeIncrementalUpdate::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_DailyVolumeIncrementalUpdate), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_DailyVolumeIncrementalUpdate::GetMarketDataSymbolID() const
	{
		if (Size < offsetof(s_DailyVolumeIncrementalUpdate, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	double s_DailyVolumeIncrementalUpdate::GetDailyVolume() const
	{
		if (Size < offsetof(s_DailyVolumeIncrementalUpdate, DailyVolume) + sizeof(DailyVolume))
			return 0.0;

		return DailyVolume;
	}


	/****************************************************************************/
	// s_OpenInterestIncrementalUpdate

	/*==========================================================================*/
	unsigned __int16 s_OpenInterestIncrementalUpdate::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_OpenInterestIncrementalUpdate::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_OpenInterestIncrementalUpdate), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_OpenInterestIncrementalUpdate::GetMarketDataSymbolID() const
	{
		if (Size < offsetof(s_DailyVolumeIncrementalUpdate, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	unsigned __int32 s_OpenInterestIncrementalUpdate::GetOpenInterest() const
	{
		if (Size < offsetof(s_OpenInterestIncrementalUpdate, OpenInterest) + sizeof(OpenInterest))
			return 0;

		return OpenInterest;
	}

	/****************************************************************************/
	// s_DailyHighIncrementalUpdate

	/*==========================================================================*/
	unsigned __int16 s_DailyHighIncrementalUpdate::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_DailyHighIncrementalUpdate::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_DailyHighIncrementalUpdate), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_DailyHighIncrementalUpdate::GetMarketDataSymbolID() const
	{
		if (Size < offsetof(s_DailyHighIncrementalUpdate, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	double s_DailyHighIncrementalUpdate::GetDailyHigh() const
	{
		if (Size < offsetof(s_DailyHighIncrementalUpdate, DailyHigh) + sizeof(DailyHigh))
			return 0.0;

		return DailyHigh;
	}

		/****************************************************************************/
	// s_DailyHighIncrementalUpdate_Int

	/*==========================================================================*/
	unsigned __int16 s_DailyHighIncrementalUpdate_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_DailyHighIncrementalUpdate_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_DailyHighIncrementalUpdate_Int), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_DailyHighIncrementalUpdate_Int::GetMarketDataSymbolID() const
	{
		if (Size < offsetof(s_DailyHighIncrementalUpdate_Int, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	__int32 s_DailyHighIncrementalUpdate_Int::GetDailyHigh() const
	{
		if (Size < offsetof(s_DailyHighIncrementalUpdate_Int, DailyHigh) + sizeof(DailyHigh))
			return 0;

		return DailyHigh;
	}


	/****************************************************************************/
	// s_DailyLowIncrementalUpdate

	/*==========================================================================*/
	unsigned __int16 s_DailyLowIncrementalUpdate::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_DailyLowIncrementalUpdate::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_DailyLowIncrementalUpdate), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_DailyLowIncrementalUpdate::GetMarketDataSymbolID() const
	{
		if (Size < offsetof(s_DailyLowIncrementalUpdate, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	double s_DailyLowIncrementalUpdate::GetDailyLow() const
	{
		if (Size < offsetof(s_DailyLowIncrementalUpdate, DailyLow) + sizeof(DailyLow))
			return 0.0;

		return DailyLow;
	}

		/****************************************************************************/
	// s_DailyLowIncrementalUpdate_Int

	/*==========================================================================*/
	unsigned __int16 s_DailyLowIncrementalUpdate_Int::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_DailyLowIncrementalUpdate_Int::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_DailyLowIncrementalUpdate_Int), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	unsigned __int16 s_DailyLowIncrementalUpdate_Int::GetMarketDataSymbolID() const
	{
		if (Size < offsetof(s_DailyLowIncrementalUpdate_Int, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
			return 0;

		return MarketDataSymbolID;
	}

	/*==========================================================================*/
	__int32 s_DailyLowIncrementalUpdate_Int::GetDailyLow() const
	{
		if (Size < offsetof(s_DailyLowIncrementalUpdate_Int, DailyLow) + sizeof(DailyLow))
			return 0;

		return DailyLow;
	}


	/****************************************************************************/
	// s_SubmitNewSingleOrder

	/*==========================================================================*/
	unsigned __int16 s_SubmitNewSingleOrder::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SubmitNewSingleOrder::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SubmitNewSingleOrder), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	char* s_SubmitNewSingleOrder::GetClientOrderID()
	{
		if (Size < offsetof( s_SubmitNewSingleOrder, ClientOrderID) + sizeof(ClientOrderID))
			return "";

		ClientOrderID[sizeof(ClientOrderID) - 1] = '\0';

		return ClientOrderID;
	}
	/*==========================================================================*/
	void s_SubmitNewSingleOrder::SetClientOrderID(const char* NewValue)
	{
		strncpy(ClientOrderID, NewValue, sizeof(ClientOrderID) - 1);
	}


	/*==========================================================================*/
	char* s_SubmitNewSingleOrder::GetSymbol()
	{
		if (Size < offsetof( s_SubmitNewSingleOrder, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}
	/*==========================================================================*/
	void s_SubmitNewSingleOrder::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}
	/*==========================================================================*/
	char* s_SubmitNewSingleOrder::GetExchange()
	{
		if (Size < offsetof( s_SubmitNewSingleOrder, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}
	/*==========================================================================*/
	void s_SubmitNewSingleOrder::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}	
	/*==========================================================================*/
	char* s_SubmitNewSingleOrder::GetTradeAccount()
	{
		if (Size < offsetof( s_SubmitNewSingleOrder, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	void s_SubmitNewSingleOrder::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}	

	/*==========================================================================*/
		char* s_SubmitNewSingleOrder::GetFreeFormText()
	{
		if (Size < offsetof( s_SubmitNewSingleOrder, FreeFormText) + sizeof(FreeFormText))
			return "";

		FreeFormText[sizeof(FreeFormText) - 1] = '\0';

		return FreeFormText;

	}
	/*==========================================================================*/
		void s_SubmitNewSingleOrder::SetFreeFormText(const char* NewValue)
	{
		strncpy(FreeFormText, NewValue, sizeof(FreeFormText) - 1);
	}
	/*==========================================================================*/
	double s_SubmitNewSingleOrder::GetPrice1()
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, Price1) + sizeof(Price1))
			return 0;

		return Price1;
	}
	/*==========================================================================*/
	double s_SubmitNewSingleOrder::GetPrice2()
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, Price2) + sizeof(Price2))
			return 0;

		return Price2;
	}
	/*==========================================================================*/
	double s_SubmitNewSingleOrder::GetOrderQuantity()
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, OrderQuantity) + sizeof(OrderQuantity))
			return DBL_MAX;

		return OrderQuantity;
	}
	/*==========================================================================*/
	OrderTypeEnum s_SubmitNewSingleOrder::GetOrderType()
	{			
		if (Size < offsetof(s_SubmitNewSingleOrder, OrderType) + sizeof(OrderType))
			return ORDER_TYPE_UNSET;

		return OrderType;	
	}
		 
	/*==========================================================================*/
	BuySellEnum s_SubmitNewSingleOrder::GetBuySell()
	{			
		if (Size < offsetof(s_SubmitNewSingleOrder, BuySell) + sizeof(BuySell))
			return BUY_SELL_UNSET;

		return BuySell;	
	}
	/*==========================================================================*/
	TimeInForceEnum s_SubmitNewSingleOrder::GetTimeInForce()
	{			
		if (Size < offsetof(s_SubmitNewSingleOrder, TimeInForce) + sizeof(TimeInForce))
			return TIF_UNSET;

		return TimeInForce;	
	}

	/*==========================================================================*/	 
	t_DateTime s_SubmitNewSingleOrder::GetGoodTillDateTimeUnix() 
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, GoodTillDateTimeUnix) + sizeof(GoodTillDateTimeUnix))
			return 0;

		return GoodTillDateTimeUnix;
	}
	/*==========================================================================*/
	byte s_SubmitNewSingleOrder::GetIsAutomatedOrder()
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, IsAutomatedOrder) + sizeof(IsAutomatedOrder))
			return 0;

		return IsAutomatedOrder;
	}
	/*==========================================================================*/
	byte s_SubmitNewSingleOrder::GetIsParentOrder()
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, IsParentOrder) + sizeof(IsParentOrder))
			return 0;

		return IsParentOrder;
	}

	/*==========================================================================*/
	__int32 s_SubmitNewSingleOrder::GetPrice1AsInteger()
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, Price1AsInteger) + sizeof(Price1AsInteger))
			return 0;

		return Price1AsInteger;
	}
	/*==========================================================================*/
	__int32 s_SubmitNewSingleOrder::GetPrice2AsInteger()
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, Price2AsInteger) + sizeof(Price2AsInteger))
			return 0;

		return Price2AsInteger;
	}
	/*==========================================================================*/
	float s_SubmitNewSingleOrder::GetDivisor()
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, Divisor) + sizeof(Divisor))
			return 0.0;

		return Divisor;
	}

	/****************************************************************************/
	// s_CancelReplaceOrder

	/*==========================================================================*/
	unsigned __int16 s_CancelReplaceOrder::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_CancelReplaceOrder::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_CancelReplaceOrder), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	char* s_CancelReplaceOrder::GetServerOrderID()
	{
		if (Size < offsetof( s_CancelReplaceOrder, ServerOrderID) + sizeof(ServerOrderID))
			return "";

		ServerOrderID[sizeof(ServerOrderID) - 1] = '\0';

		return ServerOrderID;
	}
	/*==========================================================================*/
	void s_CancelReplaceOrder::SetServerOrderID(const char* NewValue)
	{
		strncpy(ServerOrderID, NewValue, sizeof(ServerOrderID) - 1);
	}
	/*==========================================================================*/
	char* s_CancelReplaceOrder::GetClientOrderID()
	{
		if (Size < offsetof( s_CancelReplaceOrder, ClientOrderID) + sizeof(ClientOrderID))
			return "";

		ClientOrderID[sizeof(ClientOrderID) - 1] = '\0';

		return ClientOrderID;
	}
	/*==========================================================================*/
	void s_CancelReplaceOrder::SetClientOrderID(const char* NewValue)
	{
		strncpy(ClientOrderID, NewValue, sizeof(ClientOrderID) - 1);
	}
	/*==========================================================================*/
	/*==========================================================================*/
	double s_CancelReplaceOrder::GetPrice1()
	{
		if (Size < offsetof(s_CancelReplaceOrder, Price1) + sizeof(Price1))
			return 0;

		return Price1;
	}
	/*==========================================================================*/
	double s_CancelReplaceOrder::GetPrice2()
	{
		if (Size < offsetof(s_CancelReplaceOrder, Price2) + sizeof(Price2))
			return 0;

		return Price2;
	}
	/*==========================================================================*/
	double s_CancelReplaceOrder::GetOrderQuantity()
	{
		if (Size < offsetof(s_CancelReplaceOrder, OrderQuantity) + sizeof(OrderQuantity))
			return DBL_MAX;

		return OrderQuantity;
	}
	/*==========================================================================*/
	char* s_CancelReplaceOrder::GetTradeAccount()
	{
		if (Size < offsetof( s_CancelReplaceOrder, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	void s_CancelReplaceOrder::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}	
	/*==========================================================================*/
	__int32 s_CancelReplaceOrder::GetPrice1AsInteger()
	{
		if (Size < offsetof(s_CancelReplaceOrder, Price1AsInteger) + sizeof(Price1AsInteger))
			return 0;

		return Price1AsInteger;
	}
	/*==========================================================================*/
	__int32 s_CancelReplaceOrder::GetPrice2AsInteger()
	{
		if (Size < offsetof(s_CancelReplaceOrder, Price2AsInteger) + sizeof(Price2AsInteger))
			return 0;

		return Price2AsInteger;
	}
	/*==========================================================================*/
	float s_CancelReplaceOrder::GetDivisor()
	{
		if (Size < offsetof(s_CancelReplaceOrder, Divisor) + sizeof(Divisor))
			return 0.0;

		return Divisor;
	}




	/****************************************************************************/
	// s_CancelOrder

	/*==========================================================================*/
	unsigned __int16 s_CancelOrder::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_CancelOrder::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_CancelOrder), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	char* s_CancelOrder::GetServerOrderID()
	{
		if (Size < offsetof( s_CancelOrder, ServerOrderID) + sizeof(ServerOrderID))
			return "";

		ServerOrderID[sizeof(ServerOrderID) - 1] = '\0';

		return ServerOrderID;
	}
	/*==========================================================================*/
	void s_CancelOrder::SetServerOrderID(const char* NewValue)
	{
		strncpy(ServerOrderID, NewValue, sizeof(ServerOrderID) - 1);
	}
	/*==========================================================================*/
	char* s_CancelOrder::GetClientOrderID()
	{
		if (Size < offsetof( s_CancelOrder, ClientOrderID) + sizeof(ClientOrderID))
			return "";

		ClientOrderID[sizeof(ClientOrderID) - 1] = '\0';

		return ClientOrderID;
	}
	/*==========================================================================*/
	void s_CancelOrder::SetClientOrderID(const char* NewValue)
	{
		strncpy(ClientOrderID, NewValue, sizeof(ClientOrderID) - 1);
	}
	/*==========================================================================*/
	char* s_CancelOrder::GetTradeAccount()
	{
		if (Size < offsetof( s_CancelOrder, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	void s_CancelOrder::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}

	/****************************************************************************/
	// s_SubmitNewOCOOrder

	/*==========================================================================*/
	unsigned __int16 s_SubmitNewOCOOrder::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SubmitNewOCOOrder::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SubmitNewOCOOrder), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrder::SetClientOrderID_1(const char* NewValue)
	{
		strncpy(ClientOrderID_1, NewValue, sizeof(ClientOrderID_1) - 1);
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrder::SetClientOrderID_2(const char* NewValue)
	{
		strncpy(ClientOrderID_2, NewValue, sizeof(ClientOrderID_2) - 1);
	}

	/*==========================================================================*/
	char* s_SubmitNewOCOOrder::GetFreeFormText()
	{
		if (Size < offsetof( s_SubmitNewOCOOrder, FreeFormText) + sizeof(FreeFormText))
			return "";

		FreeFormText[sizeof(FreeFormText) - 1] = '\0';

		return FreeFormText;
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrder::SetFreeFormText(const char* NewValue)
	{
		strncpy(FreeFormText, NewValue, sizeof(FreeFormText) - 1);
	}
	/*==========================================================================*/
	char* s_SubmitNewOCOOrder::GetClientOrderID_1()
	{
		if (Size < offsetof( s_SubmitNewOCOOrder, ClientOrderID_1) + sizeof(ClientOrderID_1))
			return "";

		ClientOrderID_1[sizeof(ClientOrderID_1) - 1] = '\0';

		return ClientOrderID_1;
	}
	/*==========================================================================*/
	char* s_SubmitNewOCOOrder::GetClientOrderID_2()
	{
		if (Size < offsetof( s_SubmitNewOCOOrder, ClientOrderID_2) + sizeof(ClientOrderID_2))
			return "";

		ClientOrderID_2[sizeof(ClientOrderID_2) - 1] = '\0';

		return ClientOrderID_2;
	}
	/*==========================================================================*/
	char* s_SubmitNewOCOOrder::GetSymbol()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}

	/*==========================================================================*/
	void s_SubmitNewOCOOrder::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	char* s_SubmitNewOCOOrder::GetExchange()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrder::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}
	/*==========================================================================*/
	OrderTypeEnum s_SubmitNewOCOOrder::GetOrderType_1()
	{			
		if (Size < offsetof(s_SubmitNewOCOOrder, OrderType_1) + sizeof(OrderType_1))
			return ORDER_TYPE_UNSET;

		return OrderType_1;	
	}
	/*==========================================================================*/
	OrderTypeEnum s_SubmitNewOCOOrder::GetOrderType_2()
	{			
		if (Size < offsetof(s_SubmitNewOCOOrder, OrderType_2) + sizeof(OrderType_2))
			return ORDER_TYPE_UNSET;

		return OrderType_2;	
	}
	/*==========================================================================*/			 
	BuySellEnum s_SubmitNewOCOOrder::GetBuySell_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, BuySell_1) + sizeof(BuySell_1))
			return (BuySellEnum)0;

		return BuySell_1;
	}
	/*==========================================================================*/
	BuySellEnum s_SubmitNewOCOOrder::GetBuySell_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, BuySell_2) + sizeof(BuySell_2))
			return (BuySellEnum)0;

		return BuySell_2;
	}
	/*==========================================================================*/
	TimeInForceEnum s_SubmitNewOCOOrder::GetTimeInForce()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, TimeInForce) + sizeof(TimeInForce))
			return (TimeInForceEnum)0;

		return TimeInForce;
	}
	/*==========================================================================*/
	t_DateTime s_SubmitNewOCOOrder::GetGoodTillDateTimeUnix() 
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, GoodTillDateTimeUnix) + sizeof(GoodTillDateTimeUnix))
			return 0;

		return GoodTillDateTimeUnix;
	}	
	/*==========================================================================*/
	char* s_SubmitNewOCOOrder::GetParentTriggerClientOrderID()
	{
		if (Size < offsetof( s_SubmitNewOCOOrder, ParentTriggerClientOrderID) + sizeof(ParentTriggerClientOrderID))
			return "";

		ParentTriggerClientOrderID[sizeof(ParentTriggerClientOrderID) - 1] = '\0';

		return ParentTriggerClientOrderID;
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrder::SetParentTriggerClientOrderID(const char* NewValue)
	{
		strncpy(ParentTriggerClientOrderID, NewValue, sizeof(ParentTriggerClientOrderID) - 1);
	}
	/*==========================================================================*/
	byte s_SubmitNewOCOOrder::GetIsAutomatedOrder()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, IsAutomatedOrder) + sizeof(IsAutomatedOrder))
			return 0;

		return IsAutomatedOrder;
	}
	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetPrice1_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Price1_1) + sizeof(Price1_1))
			return 0;

		return Price1_1;
	}
	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetPrice2_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Price2_1) + sizeof(Price2_1))
			return 0;

		return Price2_1;
	}
	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetPrice1_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Price1_2) + sizeof(Price1_2))
			return 0;

		return Price1_2;
	}
	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetPrice2_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Price2_2) + sizeof(Price2_2))
			return 0;

		return Price2_2;
	}

	/*==========================================================================*/
	__int32 s_SubmitNewOCOOrder::GetPrice1_1AsInteger()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Price1_1AsInteger) + sizeof(Price1_1AsInteger))
			return 0;

		return Price1_1AsInteger;
	}
	/*==========================================================================*/
	__int32 s_SubmitNewOCOOrder::GetPrice2_1AsInteger()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Price2_1AsInteger) + sizeof(Price2_1AsInteger))
			return 0;

		return Price2_1AsInteger;
	}
	/*==========================================================================*/
	__int32 s_SubmitNewOCOOrder::GetPrice1_2AsInteger()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Price1_2AsInteger) + sizeof(Price1_2AsInteger))
			return 0;

		return Price1_2AsInteger;
	}
	/*==========================================================================*/
	__int32 s_SubmitNewOCOOrder::GetPrice2_2AsInteger()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Price2_2AsInteger) + sizeof(Price2_2AsInteger))
			return 0;

		return Price2_2AsInteger;
	}
	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetOrderQuantity_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, OrderQuantity_1) + sizeof(OrderQuantity_1))
			return DBL_MAX;

		return OrderQuantity_1;
	}
	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetOrderQuantity_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, OrderQuantity_2) + sizeof(OrderQuantity_2))
			return DBL_MAX;

		return OrderQuantity_2;
	}
	/*==========================================================================*/
	char* s_SubmitNewOCOOrder::GetTradeAccount()
	{
		if (Size < offsetof( s_SubmitNewOCOOrder, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	void s_SubmitNewOCOOrder::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}
	/*==========================================================================*/
	float s_SubmitNewOCOOrder::GetDivisor()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Divisor) + sizeof(Divisor))
			return 0.0;

		return Divisor;
	}
	/****************************************************************************/
	// s_OpenOrdersRequest

	/*==========================================================================*/
	unsigned __int16 s_OpenOrdersRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_OpenOrdersRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_OpenOrdersRequest), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	__int32 s_OpenOrdersRequest::GetRequestID()
	{
		if (Size < offsetof(s_OpenOrdersRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	__int32 s_OpenOrdersRequest::GetRequestAllOpenOrders()
	{
		if (Size < offsetof(s_OpenOrdersRequest, RequestAllOpenOrders) + sizeof(RequestAllOpenOrders))
			return 0;

		return RequestAllOpenOrders;
	}

	/*==========================================================================*/
	char* s_OpenOrdersRequest::GetServerOrderID()
	{
		if (Size < offsetof( s_OpenOrdersRequest, ServerOrderID) + sizeof(ServerOrderID))
			return "";

		ServerOrderID[sizeof(ServerOrderID) - 1] = '\0';

		return ServerOrderID;
	}
	/*==========================================================================*/
	void s_OpenOrdersRequest::SetServerOrderID(const char* NewValue)
	{
		strncpy(ServerOrderID, NewValue, sizeof(ServerOrderID) - 1);
	}

	/****************************************************************************/
	// s_HistoricalOrderFillsRequest

	/*==========================================================================*/
	unsigned __int16 s_HistoricalOrderFillsRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_HistoricalOrderFillsRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalOrderFillsRequest), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	__int32 s_HistoricalOrderFillsRequest::GetRequestID()
	{
		if (Size < offsetof(s_HistoricalOrderFillsRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	__int32 s_HistoricalOrderFillsRequest::GetNumberOfDays()
	{
		if (Size < offsetof(s_HistoricalOrderFillsRequest, NumberOfDays) + sizeof(NumberOfDays))
			return 0;

		return NumberOfDays;
	}

	/*==========================================================================*/
	char* s_HistoricalOrderFillsRequest::GetServerOrderID()
	{
		if (Size < offsetof( s_HistoricalOrderFillsRequest, ServerOrderID) + sizeof(ServerOrderID))
			return "";

		ServerOrderID[sizeof(ServerOrderID) - 1] = '\0';

		return ServerOrderID;
	}
	/*==========================================================================*/
	void s_HistoricalOrderFillsRequest::SetServerOrderID(const char* NewValue)
	{
		strncpy(ServerOrderID, NewValue, sizeof(ServerOrderID) - 1);
	}
	/*==========================================================================*/
	char* s_HistoricalOrderFillsRequest::GetTradeAccount()
	{
		if (Size < offsetof( s_HistoricalOrderFillsRequest, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	void s_HistoricalOrderFillsRequest::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}

	/****************************************************************************/
	// s_CurrentPositionsRequest

	/*==========================================================================*/
	unsigned __int16 s_CurrentPositionsRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_CurrentPositionsRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_CurrentPositionsRequest), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	__int32 s_CurrentPositionsRequest::GetRequestID()
	{
		if (Size < offsetof(s_CurrentPositionsRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	char* s_CurrentPositionsRequest::GetTradeAccount()
	{
		if (Size < offsetof( s_CurrentPositionsRequest, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	void s_CurrentPositionsRequest::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}

	/****************************************************************************/
	// s_CurrentPositionsRequestReject

	/*==========================================================================*/
	unsigned __int16 s_CurrentPositionsRequestReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_CurrentPositionsRequestReject::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_CurrentPositionsRequestReject), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	__int32 s_CurrentPositionsRequestReject::GetRequestID()
	{
		if (Size < offsetof(s_CurrentPositionsRequestReject, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	char* s_CurrentPositionsRequestReject::GetRejectText()
	{
		if (Size < offsetof( s_CurrentPositionsRequestReject, RejectText) + sizeof(RejectText))
			return "";

		RejectText[sizeof(RejectText) - 1] = '\0';

		return RejectText;
	}
	/*==========================================================================*/
	void s_CurrentPositionsRequestReject::SetRejectText(const char* NewValue)
	{
		strncpy(RejectText, NewValue, sizeof(RejectText) - 1);
	}


	/****************************************************************************/
	// s_OrderUpdateReport

	/*==========================================================================*/
	unsigned __int16 s_OrderUpdateReport::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_OrderUpdateReport::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_OrderUpdateReport), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	char* s_OrderUpdateReport::GetSymbol()
	{
		if (Size < offsetof(s_OrderUpdateReport, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}

	/*==========================================================================*/
	void s_OrderUpdateReport::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	char* s_OrderUpdateReport::GetExchange()
	{
		if (Size < offsetof(s_OrderUpdateReport, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_OrderUpdateReport::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}
	/*==========================================================================*/
	char* s_OrderUpdateReport::GetPreviousServerOrderID()
	{
		if (Size < offsetof(s_OrderUpdateReport, PreviousServerOrderID) + sizeof(PreviousServerOrderID))
			return "";

		PreviousServerOrderID[sizeof(PreviousServerOrderID) - 1] = '\0';

		return PreviousServerOrderID;
	}

	/*==========================================================================*/
	void s_OrderUpdateReport::SetPreviousServerOrderID(const char* NewValue)
	{
		strncpy(PreviousServerOrderID, NewValue, sizeof(PreviousServerOrderID) - 1);
	}

	/*==========================================================================*/
	char* s_OrderUpdateReport::GetServerOrderID()
	{
		if (Size < offsetof(s_OrderUpdateReport, ServerOrderID) + sizeof(ServerOrderID))
			return "";

		ServerOrderID[sizeof(ServerOrderID) - 1] = '\0';

		return ServerOrderID;
	}

	/*==========================================================================*/
	void s_OrderUpdateReport::SetServerOrderID(const char* NewValue)
	{
		strncpy(ServerOrderID, NewValue, sizeof(ServerOrderID) - 1);
	}

	/*==========================================================================*/
	char* s_OrderUpdateReport::GetClientOrderID()
	{
		if (Size < offsetof(s_OrderUpdateReport, ClientOrderID) + sizeof(ClientOrderID))
			return "";

		ClientOrderID[sizeof(ClientOrderID) - 1] = '\0';

		return ClientOrderID;
	}

	/*==========================================================================*/
	void s_OrderUpdateReport::SetClientOrderID(const char* NewValue)
	{
		strncpy(ClientOrderID, NewValue, sizeof(ClientOrderID) - 1);
	}

	/*==========================================================================*/
	char* s_OrderUpdateReport::GetExchangeOrderID()
	{
		if (Size < offsetof(s_OrderUpdateReport, ExchangeOrderID) + sizeof(ExchangeOrderID))
			return "";

		ExchangeOrderID[sizeof(ExchangeOrderID) - 1] = '\0';

		return ExchangeOrderID;
	}

	/*==========================================================================*/
	void s_OrderUpdateReport::SetExchangeOrderID(const char* NewValue)
	{
		strncpy(ExchangeOrderID, NewValue, sizeof(ExchangeOrderID) - 1);
	}

	/*==========================================================================*/
	void s_OrderUpdateReport::SetUniqueFillExecutionID(const char* NewValue)
	{
		strncpy(UniqueFillExecutionID, NewValue, sizeof(UniqueFillExecutionID) - 1);
	}

	/*==========================================================================*/
	void s_OrderUpdateReport::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}

	/*==========================================================================*/
	void s_OrderUpdateReport::SetInfoText(const char* NewValue)
	{
		strncpy(InfoText, NewValue, sizeof(InfoText) - 1);
	}

	/*==========================================================================*/
	double s_OrderUpdateReport::GetOrderQuantity()
	{
		if (Size < offsetof(s_OrderUpdateReport, OrderQuantity) + sizeof(OrderQuantity))
			return DBL_MAX;

		return OrderQuantity;
	}

	/*==========================================================================*/
	double s_OrderUpdateReport::GetFilledQuantity()
	{
		if (Size < offsetof(s_OrderUpdateReport, FilledQuantity) + sizeof(FilledQuantity))
			return DBL_MAX;

		return FilledQuantity;
	}

	/*==========================================================================*/
	double s_OrderUpdateReport::GetRemainingQuantity()
	{
		if (Size < offsetof(s_OrderUpdateReport, RemainingQuantity) + sizeof(RemainingQuantity))
			return DBL_MAX;

		return RemainingQuantity;
	}

	/*==========================================================================*/
	double s_OrderUpdateReport::GetLastFillQuantity()
	{
		if (Size < offsetof(s_OrderUpdateReport, LastFillQuantity) + sizeof(LastFillQuantity))
			return DBL_MAX;

		return LastFillQuantity;
	}
	/*==========================================================================*/
	__int32 s_OrderUpdateReport::GetRequestID()
	{
		if (Size < offsetof(s_OrderUpdateReport, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	__int32 s_OrderUpdateReport::GetTotalNumberMessages()
	{
		if (Size < offsetof(s_OrderUpdateReport, TotalNumberMessages) + sizeof(TotalNumberMessages))
			return 0;

		return TotalNumberMessages;
	}

	/*==========================================================================*/
	__int32 s_OrderUpdateReport::GetMessageNumber()
	{
		if (Size < offsetof(s_OrderUpdateReport, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}
	/*==========================================================================*/
	OrderStatusEnum s_OrderUpdateReport::GetOrderStatus()
	{
		if (Size < offsetof(s_OrderUpdateReport, OrderStatus) + sizeof(OrderStatus))
			return (OrderStatusEnum)0;

		return OrderStatus;
	}
	/*==========================================================================*/
	ExecutionTypeEnum s_OrderUpdateReport::GetExecutionType()
	{
		if (Size < offsetof(s_OrderUpdateReport, ExecutionType) + sizeof(ExecutionType))
			return (ExecutionTypeEnum)0;

		return ExecutionType;
	}
	/*==========================================================================*/
	OrderTypeEnum s_OrderUpdateReport::GetOrderType()
	{
		if (Size < offsetof(s_OrderUpdateReport, OrderType) + sizeof(OrderType))
			return (OrderTypeEnum)0;

		return OrderType;
	}
	/*==========================================================================*/
	BuySellEnum s_OrderUpdateReport::GetBuySell()
	{
		if (Size < offsetof(s_OrderUpdateReport, BuySell) + sizeof(BuySell))
			return (BuySellEnum)0;

		return BuySell;
	}
	/*==========================================================================*/
	double s_OrderUpdateReport::GetPrice1()
	{
		if (Size < offsetof(s_OrderUpdateReport, Price1) + sizeof(Price1))
			return DBL_MAX;

		return Price1;
	}
	/*==========================================================================*/
	double s_OrderUpdateReport::GetPrice2()
	{
		if (Size < offsetof(s_OrderUpdateReport, Price2) + sizeof(Price2))
			return DBL_MAX;

		return Price2;
	}

	/*==========================================================================*/
	TimeInForceEnum s_OrderUpdateReport::GetTimeInForce()
	{
		if (Size < offsetof(s_OrderUpdateReport, TimeInForce) + sizeof(TimeInForce))
			return (TimeInForceEnum)0;

		return TimeInForce;
	}
	/*==========================================================================*/
	t_DateTime s_OrderUpdateReport::GetGoodTillDateTimeUnix() 
	{
		if (Size < offsetof(s_OrderUpdateReport, GoodTillDateTimeUnix) + sizeof(GoodTillDateTimeUnix))
			return 0;

		return GoodTillDateTimeUnix;
	}

	/*==========================================================================*/
	double s_OrderUpdateReport::GetAverageFillPrice()
	{
		if (Size < offsetof(s_OrderUpdateReport, AverageFillPrice) + sizeof(AverageFillPrice))
			return DBL_MAX;

		return AverageFillPrice;
	}
	/*==========================================================================*/
	double s_OrderUpdateReport::GetLastFillPrice()
	{
		if (Size < offsetof(s_OrderUpdateReport, LastFillPrice) + sizeof(LastFillPrice))
			return DBL_MAX;

		return LastFillPrice;
	}
	/*==========================================================================*/
	t_DateTime s_OrderUpdateReport::GetLastFillDateTimeUnix() 
	{
		if (Size < offsetof(s_OrderUpdateReport, LastFillDateTimeUnix) + sizeof(LastFillDateTimeUnix))
			return 0;

		return LastFillDateTimeUnix;
	}
	/*==========================================================================*/
	char* s_OrderUpdateReport::GetUniqueFillExecutionID()
	{
		if (Size < offsetof(s_OrderUpdateReport, UniqueFillExecutionID) + sizeof(UniqueFillExecutionID))
			return "";

		UniqueFillExecutionID[sizeof(UniqueFillExecutionID) - 1] = '\0';

		return UniqueFillExecutionID;
	}
	/*==========================================================================*/
	char* s_OrderUpdateReport::GetTradeAccount()
	{
		if (Size < offsetof(s_OrderUpdateReport, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	char* s_OrderUpdateReport::GetInfoText()
	{
		if (Size < offsetof(s_OrderUpdateReport, InfoText) + sizeof(InfoText))
			return "";

		InfoText[sizeof(InfoText) - 1] = '\0';

		return InfoText;
	}
	/*==========================================================================*/	
	byte s_OrderUpdateReport::GetNoneOrders()
	{
		if (Size < offsetof(s_OrderUpdateReport, NoneOrders) + sizeof(NoneOrders))
			return 0;

		return NoneOrders;
	}


	/****************************************************************************/
	// s_OpenOrdersRequestReject

	/*==========================================================================*/
	unsigned __int16 s_OpenOrdersRequestReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_OpenOrdersRequestReject::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_OpenOrdersRequestReject), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	__int32 s_OpenOrdersRequestReject::GetRequestID()
	{
		if (Size < offsetof(s_OpenOrdersRequestReject, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	void s_OpenOrdersRequestReject::SetRejectText(const char* NewValue)
	{
		strncpy(RejectText, NewValue, sizeof(RejectText) - 1);
	}
	/*==========================================================================*/
	char* s_OpenOrdersRequestReject::GetRejectText()
	{
		if (Size < offsetof(s_OpenOrdersRequestReject, RejectText) + sizeof(RejectText))
			return "";

		RejectText[sizeof(RejectText) - 1] = '\0';

		return RejectText;
	}


	/****************************************************************************/
	// s_HistoricalOrderFillReport

	/*==========================================================================*/
	unsigned __int16 s_HistoricalOrderFillReport::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_HistoricalOrderFillReport::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalOrderFillReport), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	__int32 s_HistoricalOrderFillReport::GetRequestID()
	{
		if (Size < offsetof(s_HistoricalOrderFillReport, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	char* s_HistoricalOrderFillReport::GetSymbol()
	{
		if (Size < offsetof(s_HistoricalOrderFillReport, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}

	/*==========================================================================*/
	void s_HistoricalOrderFillReport::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	char* s_HistoricalOrderFillReport::GetExchange()
	{
		if (Size < offsetof(s_HistoricalOrderFillReport, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_HistoricalOrderFillReport::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}
	/*==========================================================================*/
	__int32 s_HistoricalOrderFillReport::GetMessageNumber()
	{
		if (Size < offsetof(s_HistoricalOrderFillReport, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}
	/*==========================================================================*/
	__int32 s_HistoricalOrderFillReport::GetTotalNumberMessages()
	{
		if (Size < offsetof(s_HistoricalOrderFillReport, TotalNumberMessages) + sizeof(TotalNumberMessages))
			return 0;

		return TotalNumberMessages;
	}
	/*==========================================================================*/
	char* s_HistoricalOrderFillReport::GetServerOrderID()
	{
		if (Size < offsetof(s_HistoricalOrderFillReport, ServerOrderID) + sizeof(ServerOrderID))
			return "";

		ServerOrderID[sizeof(ServerOrderID) - 1] = '\0';

		return ServerOrderID;
	}

	/*==========================================================================*/
	void s_HistoricalOrderFillReport::SetServerOrderID(const char* NewValue)
	{
		strncpy(ServerOrderID, NewValue, sizeof(ServerOrderID) - 1);
	}

	/*==========================================================================*/
	char* s_HistoricalOrderFillReport::GetTradeAccount()
	{
		if (Size < offsetof(s_HistoricalOrderFillReport, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	void s_HistoricalOrderFillReport::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}
	/*==========================================================================*/
	char* s_HistoricalOrderFillReport::GetUniqueFillExecutionID()
	{
		if (Size < offsetof(s_HistoricalOrderFillReport, UniqueFillExecutionID) + sizeof(UniqueFillExecutionID))
			return "";

		UniqueFillExecutionID[sizeof(UniqueFillExecutionID) - 1] = '\0';

		return UniqueFillExecutionID;
	}
	/*==========================================================================*/
	void s_HistoricalOrderFillReport::SetUniqueFillExecutionID(const char* NewValue)
	{
		strncpy(UniqueFillExecutionID, NewValue, sizeof(UniqueFillExecutionID) - 1);
	}
	/*==========================================================================*/
	double s_HistoricalOrderFillReport::GetFillPrice()
	{
		if (Size < offsetof(s_HistoricalOrderFillReport, FillPrice) + sizeof(FillPrice))
			return 0;

		return FillPrice;
	}
	/*==========================================================================*/
	double s_HistoricalOrderFillReport::GetFillQuantity()
	{
		if (Size < offsetof(s_HistoricalOrderFillReport, FillQuantity) + sizeof(FillQuantity))
			return 0;

		return FillQuantity;
	}

	/*==========================================================================*/
	t_DateTime s_HistoricalOrderFillReport::GetFillDateTimeUnix() 
	{
		if (Size < offsetof(s_HistoricalOrderFillReport, FillDateTimeUnix) + sizeof(FillDateTimeUnix))
			return 0;

		return FillDateTimeUnix;
	}

	/*==========================================================================*/
	BuySellEnum s_HistoricalOrderFillReport::GetBuySell()
	{
		if (Size < offsetof(s_HistoricalOrderFillReport, BuySell) + sizeof(BuySell))
			return (BuySellEnum)0;

		return BuySell;
	}

	/*==========================================================================*/
	OpenCloseTradeEnum s_HistoricalOrderFillReport::GetOpenClose()
	{
		if (Size < offsetof(s_HistoricalOrderFillReport, OpenClose) + sizeof(OpenClose))
			return (OpenCloseTradeEnum)0;

		return OpenClose;
	}
	/*==========================================================================*/	
	byte s_HistoricalOrderFillReport::GetNoneOrderFills()
	{
		if (Size < offsetof(s_HistoricalOrderFillReport, NoneOrderFills) + sizeof(NoneOrderFills))
			return 0;

		return NoneOrderFills;
	}


	/****************************************************************************/
	// s_PositionReport

	/*==========================================================================*/
	unsigned __int16 s_PositionReport::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_PositionReport::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_PositionReport), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	void s_PositionReport::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	void s_PositionReport::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}
	/*==========================================================================*/
	__int32 s_PositionReport::GetRequestID()
	{
		if (Size < offsetof(s_PositionReport, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	char* s_PositionReport::GetSymbol()
	{
		if (Size < offsetof(s_PositionReport, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}
	/*==========================================================================*/
	char* s_PositionReport::GetExchange()
	{
		if (Size < offsetof(s_PositionReport, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_PositionReport::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}
	/*==========================================================================*/
	__int32 s_PositionReport::GetMessageNumber()
	{
		if (Size < offsetof(s_PositionReport, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}
	/*==========================================================================*/
	__int32 s_PositionReport::GetTotalNumberMessages()
	{
		if (Size < offsetof(s_PositionReport, TotalNumberMessages) + sizeof(TotalNumberMessages))
			return 0;

		return TotalNumberMessages;
	}	
	/*==========================================================================*/
	char* s_PositionReport::GetTradeAccount()
	{
		if (Size < offsetof(s_PositionReport, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}
	/*==========================================================================*/
	void s_PositionReport::SetPositionIdentifier(const char* NewValue)
	{
		strncpy(PositionIdentifier, NewValue, sizeof(PositionIdentifier) - 1);
	}
	/*==========================================================================*/
	char* s_PositionReport::GetPositionIdentifier()
	{
		if (Size < offsetof(s_PositionReport, PositionIdentifier) + sizeof(PositionIdentifier))
			return "";

		PositionIdentifier[sizeof(PositionIdentifier) - 1] = '\0';

		return PositionIdentifier;
	}
	/*==========================================================================*/
	double s_PositionReport::GetPositionQuantity()
	{
		if (Size < offsetof(s_PositionReport, PositionQuantity) + sizeof(PositionQuantity))
			return 0;

		return PositionQuantity;
	}/*==========================================================================*/
	double s_PositionReport::GetAveragePrice()
	{
		if (Size < offsetof(s_PositionReport, AveragePrice) + sizeof(AveragePrice))
			return 0;

		return AveragePrice;
	}
	/*==========================================================================*/	
	byte s_PositionReport::GetNonePositions()
	{
		if (Size < offsetof(s_PositionReport, NonePositions) + sizeof(NonePositions))
			return 0;

		return NonePositions;
	}
	/*==========================================================================*/	
	byte s_PositionReport::GetUnsolicited()
	{
		if (Size < offsetof(s_PositionReport, Unsolicited) + sizeof(Unsolicited))
			return 0;

		return Unsolicited;
	}



	/****************************************************************************/
	// s_AccountsRequest

	/*==========================================================================*/
	unsigned __int16 s_AccountsRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_AccountsRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_AccountsRequest), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/****************************************************************************/
	// s_AccountListResponse

	/*==========================================================================*/
	unsigned __int16 s_AccountListResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_AccountListResponse::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_AccountListResponse), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	__int32 s_AccountListResponse::GetMessageNumber()
	{
		if (Size < offsetof(s_AccountListResponse, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}
	/*==========================================================================*/
	__int32 s_AccountListResponse::GetTotalNumberMessages()
	{
		if (Size < offsetof(s_AccountListResponse, TotalNumberMessages) + sizeof(TotalNumberMessages))
			return 0;

		return TotalNumberMessages;
	}		
	/*==========================================================================*/
	void s_AccountListResponse::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}
	/*==========================================================================*/
	char* s_AccountListResponse::GetTradeAccount()
	{
		if (Size < offsetof(s_AccountListResponse, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';

		return TradeAccount;
	}


	/****************************************************************************/
	// s_ExchangeListRequest

	/*==========================================================================*/
	unsigned __int16 s_ExchangeListRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_ExchangeListRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_ExchangeListRequest), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	__int32 s_ExchangeListRequest::GetRequestID()
	{
		if (Size < offsetof(s_ExchangeListRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}


	/****************************************************************************/
	// s_ExchangeListResponse

	/*==========================================================================*/
	unsigned __int16 s_ExchangeListResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_ExchangeListResponse::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_ExchangeListResponse), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	char* s_ExchangeListResponse::GetExchange()
	{
		if (Size < offsetof(s_ExchangeListResponse, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_ExchangeListResponse::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}

	/*==========================================================================*/
	char* s_ExchangeListResponse::GetExchangeDescription()
	{
		if (Size < offsetof(s_ExchangeListResponse, ExchangeDescription) + sizeof(ExchangeDescription))
			return "";

		ExchangeDescription[sizeof(Exchange) - 1] = '\0';

		return ExchangeDescription;
	}

	/*==========================================================================*/
	void s_ExchangeListResponse::SetExchangeDescription(const char* NewValue)
	{
		strncpy(ExchangeDescription, NewValue, sizeof(ExchangeDescription) - 1);
	}
	/*==========================================================================*/
	__int32 s_ExchangeListResponse::GetRequestID()
	{
		if (Size < offsetof(s_ExchangeListResponse, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	byte s_ExchangeListResponse::GetFinalMessage()
	{
		if (Size < offsetof(s_ExchangeListResponse, FinalMessage) + sizeof(FinalMessage))
			return 0;

		return FinalMessage;
	}


	/****************************************************************************/
	// s_SymbolsForExchangeRequest

	/*==========================================================================*/
	unsigned __int16 s_SymbolsForExchangeRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SymbolsForExchangeRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SymbolsForExchangeRequest), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	__int32 s_SymbolsForExchangeRequest::GetRequestID()
	{
		if (Size < offsetof(s_SymbolsForExchangeRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	char* s_SymbolsForExchangeRequest::GetExchange()
	{
		if (Size < offsetof(s_SymbolsForExchangeRequest, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_SymbolsForExchangeRequest::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}

	/*==========================================================================*/
	SecurityTypeEnum s_SymbolsForExchangeRequest::GetSecurityType()
	{
		if (Size < offsetof(s_SymbolsForExchangeRequest, SecurityType) + sizeof(SecurityType))
			return (SecurityTypeEnum)0;

		return SecurityType;
	}


	/****************************************************************************/
	// s_UnderlyingSymbolsForExchangeRequest

	/*==========================================================================*/
	unsigned __int16 s_UnderlyingSymbolsForExchangeRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_UnderlyingSymbolsForExchangeRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_UnderlyingSymbolsForExchangeRequest), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	__int32 s_UnderlyingSymbolsForExchangeRequest::GetRequestID()
	{
		if (Size < offsetof(s_UnderlyingSymbolsForExchangeRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	char* s_UnderlyingSymbolsForExchangeRequest::GetExchange()
	{
		if (Size < offsetof(s_UnderlyingSymbolsForExchangeRequest, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_UnderlyingSymbolsForExchangeRequest::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}
	/*==========================================================================*/
	SecurityTypeEnum s_UnderlyingSymbolsForExchangeRequest::GetSecurityType()
	{
		if (Size < offsetof(s_UnderlyingSymbolsForExchangeRequest, SecurityType) + sizeof(SecurityType))
			return (SecurityTypeEnum)0;

		return SecurityType;
	}

	/****************************************************************************/
	// s_SymbolsForUnderlyingRequest

	/*==========================================================================*/
	unsigned __int16 s_SymbolsForUnderlyingRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SymbolsForUnderlyingRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SymbolsForUnderlyingRequest), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	__int32 s_SymbolsForUnderlyingRequest::GetRequestID()
	{
		if (Size < offsetof(s_SymbolsForUnderlyingRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	char* s_SymbolsForUnderlyingRequest::GetExchange()
	{
		if (Size < offsetof(s_SymbolsForUnderlyingRequest, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}
	/*==========================================================================*/
	void s_SymbolsForUnderlyingRequest::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}
	/*==========================================================================*/
	void s_SymbolsForUnderlyingRequest::SetUnderlyingSymbol(const char* NewValue)
	{
		strncpy(UnderlyingSymbol, NewValue, sizeof(UnderlyingSymbol) - 1);
	}
	/*==========================================================================*/
	char* s_SymbolsForUnderlyingRequest::GetUnderlyingSymbol()
	{
		if (Size < offsetof(s_SymbolsForUnderlyingRequest, UnderlyingSymbol) + sizeof(UnderlyingSymbol))
			return "";

		UnderlyingSymbol[sizeof(UnderlyingSymbol) - 1] = '\0';

		return UnderlyingSymbol;
	}


	/*==========================================================================*/
	SecurityTypeEnum s_SymbolsForUnderlyingRequest::GetSecurityType()
	{
		if (Size < offsetof(s_SymbolsForUnderlyingRequest, SecurityType) + sizeof(SecurityType))
			return (SecurityTypeEnum)0;

		return SecurityType;
	}


	/****************************************************************************/
	// s_SymbolSearchByDescriptionRequest

	/*==========================================================================*/
	unsigned __int16 s_SymbolSearchByDescriptionRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SymbolSearchByDescriptionRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SymbolSearchByDescriptionRequest), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	char* s_SymbolSearchByDescriptionRequest::GetExchange()
	{
		if (Size < offsetof(s_SymbolSearchByDescriptionRequest, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_SymbolSearchByDescriptionRequest::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}

	/*==========================================================================*/
	char* s_SymbolSearchByDescriptionRequest::GetSymbolDescription()
	{
		if (Size < offsetof(s_SymbolSearchByDescriptionRequest, SymbolDescription) + sizeof(SymbolDescription))
			return "";

		SymbolDescription[sizeof(SymbolDescription) - 1] = '\0';

		return SymbolDescription;
	}

	/*==========================================================================*/
	void s_SymbolSearchByDescriptionRequest::SetSymbolDescription(const char* NewValue)
	{
		strncpy(SymbolDescription, NewValue, sizeof(SymbolDescription) - 1);
	}
	/*==========================================================================*/
	__int32 s_SymbolSearchByDescriptionRequest::GetRequestID()
	{
		if (Size < offsetof(s_SymbolSearchByDescriptionRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	SecurityTypeEnum s_SymbolSearchByDescriptionRequest::GetSecurityType()
	{
		if (Size < offsetof(s_SymbolSearchByDescriptionRequest, SecurityType) + sizeof(SecurityType))
			return (SecurityTypeEnum)0;

		return SecurityType;
	}


	/****************************************************************************/
	// s_SecurityDefinitionForSymbolRequest

	/*==========================================================================*/
	unsigned __int16 s_SecurityDefinitionForSymbolRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SecurityDefinitionForSymbolRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SecurityDefinitionForSymbolRequest), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	char* s_SecurityDefinitionForSymbolRequest::GetSymbol()
	{
		if (Size < offsetof(s_SecurityDefinitionForSymbolRequest, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}

	/*==========================================================================*/
	void s_SecurityDefinitionForSymbolRequest::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	char* s_SecurityDefinitionForSymbolRequest::GetExchange()
	{
		if (Size < offsetof(s_SecurityDefinitionForSymbolRequest, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_SecurityDefinitionForSymbolRequest::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}
	/*==========================================================================*/
	__int32 s_SecurityDefinitionForSymbolRequest::GetRequestID()
	{
		if (Size < offsetof(s_SecurityDefinitionForSymbolRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	/*==========================================================================*/
	SecurityTypeEnum s_SecurityDefinitionForSymbolRequest::GetSecurityType()
	{
		if (Size < offsetof(s_SecurityDefinitionForSymbolRequest, SecurityType) + sizeof(SecurityType))
			return (SecurityTypeEnum)0;

		return SecurityType;
	}


	/****************************************************************************/
	// s_SecurityDefinitionResponse

	/*==========================================================================*/
	unsigned __int16 s_SecurityDefinitionResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_SecurityDefinitionResponse::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_SecurityDefinitionResponse), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	__int32 s_SecurityDefinitionResponse::GetRequestID() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	const char* s_SecurityDefinitionResponse::GetSymbol()
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';  // Ensure that the null terminator exists

		return Symbol;
	}

	/*==========================================================================*/
	void s_SecurityDefinitionResponse::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	const char* s_SecurityDefinitionResponse::GetExchange()
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';  // Ensure that the null terminator exists

		return Exchange;
	}

	/*==========================================================================*/
	void s_SecurityDefinitionResponse::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}

	/*==========================================================================*/
	SecurityTypeEnum s_SecurityDefinitionResponse::GetSecurityType() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, SecurityType) + sizeof(SecurityType))
			return ST_UNSET;

		return SecurityType;
	}

	/*==========================================================================*/
	const char* s_SecurityDefinitionResponse::GetSymbolDescription()
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, SymbolDescription) + sizeof(SymbolDescription))
			return "";

		SymbolDescription[sizeof(SymbolDescription) - 1] = '\0';  // Ensure that the null terminator exists

		return SymbolDescription;
	}

	/*==========================================================================*/
	void s_SecurityDefinitionResponse::SetSymbolDescription(const char* NewValue)
	{
		strncpy(SymbolDescription, NewValue, sizeof(SymbolDescription) - 1);
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetTickSize() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, TickSize) + sizeof(TickSize))
			return 0;

		return TickSize;
	}

	/*==========================================================================*/
	DisplayFormatEnum s_SecurityDefinitionResponse::GetPriceDisplayFormat() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, PriceDisplayFormat) + sizeof(PriceDisplayFormat))
			return DISPLAY_FORMAT_UNSET;

		return PriceDisplayFormat;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetTickCurrencyValue() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, TickCurrencyValue) + sizeof(TickCurrencyValue))
			return 0;

		return TickCurrencyValue;
	}

	/*==========================================================================*/
	byte s_SecurityDefinitionResponse::GetFinalMessage() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, FinalMessage) + sizeof(FinalMessage))
			return 0;

		return FinalMessage;
	}

	/****************************************************************************/
	// s_AccountBalanceUpdate

	/*==========================================================================*/
	unsigned __int16 s_AccountBalanceUpdate::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_AccountBalanceUpdate::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_AccountBalanceUpdate), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	void s_AccountBalanceUpdate::SetAccountCurrency(const char* NewValue)
	{
		strncpy(AccountCurrency, NewValue, sizeof(AccountCurrency) - 1);
	}

	/*==========================================================================*/
	void s_AccountBalanceUpdate::SetTradeAccount(const char* NewValue)
	{
		strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
	}
	/*==========================================================================*/
	char* s_AccountBalanceUpdate::GetAccountCurrency()
	{
		if (Size < offsetof(s_AccountBalanceUpdate, AccountCurrency) + sizeof(AccountCurrency))
			return "";

		AccountCurrency[sizeof(AccountCurrency) - 1] = '\0';  // Ensure that the null terminator exists

		return AccountCurrency;
	}
	/*==========================================================================*/
	char* s_AccountBalanceUpdate::GetTradeAccount()
	{
		if (Size < offsetof(s_AccountBalanceUpdate, TradeAccount) + sizeof(TradeAccount))
			return "";

		TradeAccount[sizeof(TradeAccount) - 1] = '\0';  // Ensure that the null terminator exists

		return TradeAccount;
	}
	/*==========================================================================*/
	double s_AccountBalanceUpdate::GetCurrentCashBalance()
	{
		if (Size < offsetof(s_AccountBalanceUpdate, CurrentCashBalance) + sizeof(CurrentCashBalance))
			return 0;

		return CurrentCashBalance;
	}
	/*==========================================================================*/
	double s_AccountBalanceUpdate::GetCurrentBalanceAvailableForNewPositions()
	{
		if (Size < offsetof(s_AccountBalanceUpdate, CurrentBalanceAvailableForNewPositions) + sizeof(CurrentBalanceAvailableForNewPositions))
			return 0;

		return CurrentBalanceAvailableForNewPositions;
	}


	/****************************************************************************/
	// s_UserMessage

	/*==========================================================================*/
	unsigned __int16 s_UserMessage::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_UserMessage::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_UserMessage), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	void s_UserMessage::SetUserMessage(const char* NewValue)
	{
		strncpy(UserMessage, NewValue, sizeof(UserMessage) - 1);
	}
	/*==========================================================================*/
	char* s_UserMessage::GetUserMessage()
	{
		if (Size < offsetof(s_UserMessage, UserMessage) + sizeof(UserMessage))
			return "";

		UserMessage[sizeof(UserMessage) - 1] = '\0';  // Ensure that the null terminator exists

		return UserMessage;
	}

	/*==========================================================================*/
	byte s_UserMessage::GetPopupMessage()
	{
		if (Size < offsetof(s_UserMessage, PopupMessage) + sizeof(PopupMessage))
			return 0;

		return PopupMessage;
	}


	/****************************************************************************/
	// s_GeneralLogMessage

	/*==========================================================================*/
	unsigned __int16 s_GeneralLogMessage::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_GeneralLogMessage::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_GeneralLogMessage), *static_cast<unsigned __int16*>( p_SourceData) ));
	}


	/*==========================================================================*/
	char* s_GeneralLogMessage::GetMessageText()
	{
		if (Size < offsetof(s_GeneralLogMessage, MessageText) + sizeof(MessageText))
			return "";

		MessageText[sizeof(MessageText) - 1] = '\0';

		return MessageText;
	}

	/*==========================================================================*/
	void s_GeneralLogMessage::SetMessageText(const char* NewValue)
	{
		strncpy(MessageText, NewValue, sizeof(MessageText) - 1);
	}

	/****************************************************************************/
	// s_HistoricalPriceDataRequest

	/*==========================================================================*/
	unsigned __int16 s_HistoricalPriceDataRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataRequest::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataRequest), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	char* s_HistoricalPriceDataRequest::GetSymbol()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, Symbol) + sizeof(Symbol))
			return "";

		Symbol[sizeof(Symbol) - 1] = '\0';

		return Symbol;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataRequest::SetSymbol(const char* NewValue)
	{
		strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
	}

	/*==========================================================================*/
	char* s_HistoricalPriceDataRequest::GetExchange()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataRequest::SetExchange(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}
	/*==========================================================================*/
	__int32 s_HistoricalPriceDataRequest::GetRequestIdentifier()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, RequestIdentifier) + sizeof(RequestIdentifier))
			return 0;

		return RequestIdentifier;
	}
	/*==========================================================================*/
	unsigned __int32 s_HistoricalPriceDataRequest::GetMaximumDaysToReturn()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, MaximumDaysToReturn) + sizeof(MaximumDaysToReturn))
			return 0;

		return MaximumDaysToReturn;
	}
	/*==========================================================================*/
	t_DateTime s_HistoricalPriceDataRequest::GetEndDateTime() 
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, EndDateTime) + sizeof(EndDateTime))
			return 0;

		return EndDateTime;
	}
	/*==========================================================================*/
	t_DateTime s_HistoricalPriceDataRequest::GetStartDateTime() 
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, StartDateTime) + sizeof(StartDateTime))
			return 0;

		return StartDateTime;
	}
	/*==========================================================================*/
	HistoricalDataIntervalEnum s_HistoricalPriceDataRequest::GetDataInterval()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, DataInterval) + sizeof(DataInterval))
			return (HistoricalDataIntervalEnum)0;

		return DataInterval;
	}
	/*==========================================================================*/
	byte s_HistoricalPriceDataRequest::GetUseZLibCompression()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, UseZLibCompression) + sizeof(UseZLibCompression))
			return 0;

		return UseZLibCompression;
	}
	/*==========================================================================*/
	byte s_HistoricalPriceDataRequest::GetDividendAdjustedStockData()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, DividendAdjustedStockData) + sizeof(DividendAdjustedStockData))
			return 0;

		return DividendAdjustedStockData;
	}
	/*==========================================================================*/
	byte s_HistoricalPriceDataRequest::GetDelayedData()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, DelayedData) + sizeof(DelayedData))
			return 0;

		return DelayedData;
	}


	/****************************************************************************/
	// s_HistoricalPriceDataHeaderResponse

	/*==========================================================================*/
	unsigned __int16 s_HistoricalPriceDataHeaderResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataHeaderResponse::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataHeaderResponse), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	__int32 s_HistoricalPriceDataHeaderResponse::GetRequestIdentifier()
	{
		if (Size < offsetof(s_HistoricalPriceDataHeaderResponse, RequestIdentifier) + sizeof(RequestIdentifier))
			return 0;

		return RequestIdentifier;
	}
	/*==========================================================================*/
	HistoricalDataIntervalEnum s_HistoricalPriceDataHeaderResponse::GetDataInterval()
	{
		if (Size < offsetof(s_HistoricalPriceDataHeaderResponse, DataInterval) + sizeof(DataInterval))
			return (HistoricalDataIntervalEnum)0;

		return DataInterval;
	}
	/*==========================================================================*/
	byte s_HistoricalPriceDataHeaderResponse::GetRecordsUseZLibCompression()
	{
		if (Size < offsetof(s_HistoricalPriceDataHeaderResponse, RecordsUseZLibCompression) + sizeof(RecordsUseZLibCompression))
			return 0;

		return RecordsUseZLibCompression;
	}
	/*==========================================================================*/
	byte s_HistoricalPriceDataHeaderResponse::GetNoRecordsToReturn()
	{
		if (Size < offsetof(s_HistoricalPriceDataHeaderResponse, NoRecordsToReturn) + sizeof(NoRecordsToReturn))
			return 0;

		return NoRecordsToReturn;
	}

	/****************************************************************************/
	// s_HistoricalPriceDataReject

	/*==========================================================================*/
	unsigned __int16 s_HistoricalPriceDataReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataReject::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataReject),*static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	char* s_HistoricalPriceDataReject::GetRejectText()
	{
		if (Size < offsetof(s_MarketDataReject, RejectText) + sizeof(RejectText))
			return "";

		RejectText[sizeof(RejectText) - 1] = '\0';

		return RejectText;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataReject::SetRejectText(const char* NewValue)
	{
		strncpy(RejectText, NewValue, sizeof(RejectText) - 1);
	}
	/*==========================================================================*/
	__int32 s_HistoricalPriceDataReject::GetRequestIdentifier()
	{
		if (Size < offsetof(s_HistoricalPriceDataReject, RequestIdentifier) + sizeof(RequestIdentifier))
			return 0;

		return RequestIdentifier;
	}



	/****************************************************************************/
	// s_HistoricalPriceDataRecordResponse

	/*==========================================================================*/
	unsigned __int16 s_HistoricalPriceDataRecordResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataRecordResponse::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataRecordResponse), *static_cast<unsigned __int16*>( p_SourceData) ));
	}
	/*==========================================================================*/
	__int32 s_HistoricalPriceDataRecordResponse::GetRequestIdentifier()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, RequestIdentifier) + sizeof(RequestIdentifier))
			return 0;

		return RequestIdentifier;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataRecordResponse::GetOpen()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, Open) + sizeof(Open))
			return 0;

		return Open;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataRecordResponse::GetHigh()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, High) + sizeof(High))
			return 0;

		return High;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataRecordResponse::GetLow()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, Low) + sizeof(Low))
			return 0;

		return Low;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataRecordResponse::GetLast()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, Last) + sizeof(Last))
			return 0;

		return Last;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataRecordResponse::GetVolume()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, Volume) + sizeof(Volume))
			return 0;

		return Volume;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataRecordResponse::GetBidVolume()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, BidVolume) + sizeof(BidVolume))
			return 0;

		return BidVolume;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataRecordResponse::GetAskVolume()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, AskVolume) + sizeof(AskVolume))
			return 0;

		return AskVolume;
	}
	/*==========================================================================*/
	t_DateTime s_HistoricalPriceDataRecordResponse::GetStartingDateTime() 
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, StartingDateTime) + sizeof(StartingDateTime))
			return 0;

		return StartingDateTime;
	}
	/*==========================================================================*/
	byte s_HistoricalPriceDataRecordResponse::GetFinalRecord()
	{
		if (Size < offsetof(s_HistoricalPriceDataRecordResponse, FinalRecord) + sizeof(FinalRecord))
			return 0;

		return FinalRecord;
	}


	/****************************************************************************/
	// s_HistoricalPriceDataTickRecordResponse

	/*==========================================================================*/
	unsigned __int16 s_HistoricalPriceDataTickRecordResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataTickRecordResponse::CopyFrom(void* p_SourceData)
	{
		memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataTickRecordResponse), *static_cast<unsigned __int16*>( p_SourceData) ));
	}

	/*==========================================================================*/
	void s_HistoricalPriceDataTickRecordResponse::Clear()
	{
		memset(this, 0,sizeof(s_HistoricalPriceDataTickRecordResponse));
		Type=HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE;
		Size=sizeof(s_HistoricalPriceDataTickRecordResponse);
	}
	/*==========================================================================*/
	__int32 s_HistoricalPriceDataTickRecordResponse::GetRequestIdentifier()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse, RequestIdentifier) + sizeof(RequestIdentifier))
			return 0;

		return RequestIdentifier;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataTickRecordResponse::GetTradeDateTimeWithMilliseconds()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse, TradeDateTimeWithMilliseconds) + sizeof(TradeDateTimeWithMilliseconds))
			return 0;

		return TradeDateTimeWithMilliseconds;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataTickRecordResponse::GetTradePrice()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse, TradePrice) + sizeof(TradePrice))
			return 0;

		return TradePrice;
	}
	/*==========================================================================*/
	double s_HistoricalPriceDataTickRecordResponse::GetTradeVolume()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse, TradeVolume) + sizeof(TradeVolume))
			return 0;

		return TradeVolume;
	}
	/*==========================================================================*/
	BidOrAskEnum s_HistoricalPriceDataTickRecordResponse::GetBidOrAsk()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse, BidOrAsk) + sizeof(BidOrAsk))
			return BID_ASK_UNSET;

		return BidOrAsk;
	}
	/*==========================================================================*/
	byte s_HistoricalPriceDataTickRecordResponse::GetFinalRecord()
	{
		if (Size < offsetof(s_HistoricalPriceDataTickRecordResponse, FinalRecord) + sizeof(FinalRecord))
			return 0;

		return FinalRecord;
	}



	/*==========================================================================*/
}
