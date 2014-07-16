

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
	char* s_LogonResponse::GetServerVersion()
	{
		if (Size < offsetof(s_LogonResponse, ServerVersion) + sizeof(ServerVersion))
			return "";

		ServerVersion[sizeof(ServerVersion) - 1] = '\0';

		return ServerVersion;
	}
	/*==========================================================================*/
	void s_LogonResponse::SetServerVersion(const char * NewValue)
	{
		strncpy(ServerVersion, NewValue, sizeof(ServerVersion) - 1);
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
	char* s_LogonResponse::GetServiceProviderName()
	{
		if (Size < offsetof(s_LogonResponse, ServiceProviderName) + sizeof(ServiceProviderName))
			return "";

		ServiceProviderName[sizeof(ServiceProviderName) - 1] = '\0';

		return ServiceProviderName;
	}

	/*==========================================================================*/
	void s_LogonResponse::SetServiceProviderName(const char* NewValue)
	{
		strncpy(ServiceProviderName, NewValue, sizeof(ServiceProviderName) - 1);
	}

	/*==========================================================================*/
	unsigned char s_LogonResponse::GetMarketDepthUpdatesBestBidAndAsk()
	{
		if (Size < offsetof(s_LogonResponse, MarketDepthUpdatesBestBidAndAsk) + sizeof(MarketDepthUpdatesBestBidAndAsk))
			return 0;

		return MarketDepthUpdatesBestBidAndAsk;
	}

	/*==========================================================================*/
	unsigned char s_LogonResponse::GetTradingIsSupported()
	{
		if (Size < offsetof(s_LogonResponse, TradingIsSupported) + sizeof(TradingIsSupported))
			return 0;

		return TradingIsSupported;
	}


	/*==========================================================================*/
	unsigned char s_LogonResponse::GetOCOOrdersSupported()
	{
		if (Size < offsetof(s_LogonResponse, OCOOrdersSupported) + sizeof(OCOOrdersSupported))
			return 0;

		return OCOOrdersSupported;
	}

	/*==========================================================================*/
	unsigned char s_LogonResponse::GetOrderCancelReplaceSupported()
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
	unsigned char s_LogonResponse::GetSecurityDefinitionsSupported()
	{
		if (Size < offsetof(s_LogonResponse, SecurityDefinitionsSupported) + sizeof(SecurityDefinitionsSupported))
			return 0;

		return SecurityDefinitionsSupported;
	}


	/*==========================================================================*/
	unsigned char s_LogonResponse::GetHistoricalPriceDataSupported()
	{
		if (Size < offsetof(s_LogonResponse, HistoricalPriceDataSupported) + sizeof(HistoricalPriceDataSupported))
			return 0;

		return HistoricalPriceDataSupported;
	}


	/*==========================================================================*/
	unsigned char s_LogonResponse::GetResubscribeWhenMarketDataFeedRestored()
	{
		if (Size < offsetof(s_LogonResponse, ResubscribeWhenMarketDataFeedRestored) + sizeof(ResubscribeWhenMarketDataFeedRestored))
			return 0;

		return ResubscribeWhenMarketDataFeedRestored;
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
	unsigned __int16 s_DisconnectFromServer::GetMessageSize()
	{
		return Size;
	}

	/****************************************************************************/
	// s_DisconnectFromServer

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
	unsigned char s_MarketDepthSnapshotLevel::GetFirstMessageInBatch()
	{
		if (Size < offsetof(s_MarketDepthSnapshotLevel, FirstMessageInBatch) + sizeof(FirstMessageInBatch))
			return 0;

		return FirstMessageInBatch;
	}

	/*==========================================================================*/
	unsigned char s_MarketDepthSnapshotLevel::GetLastMessageInBatch()
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
	void s_SubmitNewSingleOrder::SetClientOrderID(const char* NewValue)
	{
		strncpy(ClientOrderID, NewValue, sizeof(ClientOrderID) - 1);
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
	char* s_ExchangeListResponse::GetExchangeText()
	{
		if (Size < offsetof(s_ExchangeListResponse, Exchange) + sizeof(Exchange))
			return "";

		Exchange[sizeof(Exchange) - 1] = '\0';

		return Exchange;
	}

	/*==========================================================================*/
	void s_ExchangeListResponse::SetExchangeText(const char* NewValue)
	{
		strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
	}

	/*==========================================================================*/
	char* s_ExchangeListResponse::GetExchangeDescriptionText()
	{
		if (Size < offsetof(s_ExchangeListResponse, ExchangeDescription) + sizeof(ExchangeDescription))
			return "";

		ExchangeDescription[sizeof(Exchange) - 1] = '\0';

		return ExchangeDescription;
	}

	/*==========================================================================*/
	void s_ExchangeListResponse::SetExchangeDescriptionText(const char* NewValue)
	{
		strncpy(ExchangeDescription, NewValue, sizeof(ExchangeDescription) - 1);
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
	char* s_SymbolSearchByDescriptionRequest::GetDescription()
	{
		if (Size < offsetof(s_SymbolSearchByDescriptionRequest, SymbolDescription) + sizeof(SymbolDescription))
			return "";

		SymbolDescription[sizeof(SymbolDescription) - 1] = '\0';

		return SymbolDescription;
	}

	/*==========================================================================*/
	void s_SymbolSearchByDescriptionRequest::SetDescription(const char* NewValue)
	{
		strncpy(SymbolDescription, NewValue, sizeof(SymbolDescription) - 1);
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
	char s_SecurityDefinitionResponse::GetFinalMessage() const
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
}
