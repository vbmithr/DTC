
#include <float.h>
#include <limits.h>
#include <string.h>
#include <memory.h> 
#include <stddef.h>

#include "GeneralDataTradeServiceProtocol.h"


#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

/****************************************************************************/
// s_LogonRequest

/*============================================================================
	Will get the size of the message received over the network
----------------------------------------------------------------------------*/
unsigned __int16 GSP::s_LogonRequest::GetMessageSize()
{
	return Size;
}

/*============================================================================
	Performs a safe copy of data into this structure instance from the given
	data pointer.
----------------------------------------------------------------------------*/
void GSP::s_LogonRequest::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_LogonRequest), Size));
}

/*==========================================================================*/
__int32 GSP::s_LogonRequest::GetProtocolVersion()
{
	if (Size < offsetof(s_LogonRequest, ProtocolVersion) + sizeof(ProtocolVersion))
		return 0;

	return ProtocolVersion;
}

/*==========================================================================*/
const char* GSP::s_LogonRequest::GetUsername()
{
	if (Size < offsetof(s_LogonRequest, Username) + sizeof(Username))
		return "";

	Username[sizeof(Username) - 1] = '\0';  // Ensure that the null terminator exists

	return Username;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetUsername(const char* NewValue)
{
	strncpy(Username, NewValue, sizeof(Username) - 1);
}

/*==========================================================================*/
char* GSP::s_LogonRequest::GetPassword()
{
	if (Size < offsetof(s_LogonRequest, Password) + sizeof(Password))
		return "";

	Password[sizeof(Password) - 1] = '\0';

	return Password;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetPassword(const char* NewValue)
{
	strncpy(Password, NewValue, sizeof(Password) - 1);
}

/*==========================================================================*/
char* GSP::s_LogonRequest::GetGeneralTextData()
{
	if (Size < offsetof(s_LogonRequest, GeneralTextData) + sizeof(GeneralTextData))
		return "";

	GeneralTextData[sizeof(GeneralTextData) - 1] = '\0';

	return GeneralTextData;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetGeneralTextData(const char* NewValue)
{
	strncpy(GeneralTextData, NewValue, sizeof(GeneralTextData) - 1);
}

/*==========================================================================*/
__int32 GSP::s_LogonRequest::GetInteger_1()
{
	if (Size < offsetof(s_LogonRequest, Integer_1) + sizeof(Integer_1))
		return 0;

	return Integer_1;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetInteger_1(__int32 NewValue)
{
	Integer_1 = NewValue;
}

/*==========================================================================*/
__int32 GSP::s_LogonRequest::GetInteger_2()
{
	if (Size < offsetof(s_LogonRequest, Integer_2) + sizeof(Integer_2))
		return 0;

	return Integer_2;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetInteger_2(__int32 NewValue)
{
	Integer_2 = NewValue;
}

/*==========================================================================*/
__int32 GSP::s_LogonRequest::GetInHeartbeatIntervalInSeconds()
{
	if (Size < offsetof(s_LogonRequest, HeartbeatIntervalInSeconds) + sizeof(HeartbeatIntervalInSeconds))
		return 0;

	return HeartbeatIntervalInSeconds;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetHeartbeatIntervalInSeconds(__int32 NewValue)
{
	HeartbeatIntervalInSeconds = NewValue;
}

/*==========================================================================*/
GSP::TradeModeEnum GSP::s_LogonRequest::GetTradeMode()
{
	if (Size < offsetof(s_LogonRequest, TradeMode) + sizeof(TradeMode))
		return (TradeModeEnum)0;

	return TradeMode;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetTradeMode(GSP::TradeModeEnum NewValue)
{
	TradeMode = NewValue;
}

/*==========================================================================*/
char* GSP::s_LogonRequest::GetTradeAccount()
{
	if (Size < offsetof(s_LogonRequest, TradeAccount) + sizeof(TradeAccount))
		return "";

	TradeAccount[sizeof(TradeAccount) - 1] = '\0';

	return TradeAccount;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetTradeAccount(const char* NewValue)
{
	strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
}

/*==========================================================================*/
char* GSP::s_LogonRequest::GetHardwareIdentifier()
{
	if (Size < offsetof(s_LogonRequest, HardwareIdentifier) + sizeof(HardwareIdentifier))
		return "";

	HardwareIdentifier[sizeof(HardwareIdentifier) - 1] = '\0';

	return HardwareIdentifier;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetHardwareIdentifier(const char* NewValue)
{
	strncpy(HardwareIdentifier, NewValue, sizeof(HardwareIdentifier) - 1);
}

/*==========================================================================*/
char* GSP::s_LogonRequest::GetClientName()
{
	if (Size < offsetof(s_LogonRequest, ClientName) + sizeof(ClientName))
		return "";

	ClientName[sizeof(ClientName) - 1] = '\0';

	return ClientName;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetClientName(const char* NewValue)
{
	strncpy(ClientName, NewValue, sizeof(ClientName) - 1);
}

/****************************************************************************/
// s_LogonResponse

/*==========================================================================*/
unsigned __int16 GSP::s_LogonResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_LogonResponse::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_LogonResponse), Size));
}

/*==========================================================================*/
__int32 GSP::s_LogonResponse::GetProtocolVersion()
{
	if (Size < offsetof(s_LogonResponse, ProtocolVersion) + sizeof(ProtocolVersion))
		return 0;

	return ProtocolVersion;
}

/*==========================================================================*/
GSP::LogonStatusEnum GSP::s_LogonResponse::GetResult()
{
	if (Size < offsetof(s_LogonResponse, Result) + sizeof(Result))
		return (LogonStatusEnum)0;

	return Result;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetResult(LogonStatusEnum NewValue)
{
	Result = NewValue;
}

/*==========================================================================*/
char* GSP::s_LogonResponse::GetResultText()
{
	if (Size < offsetof(s_LogonResponse, ResultText) + sizeof(ResultText))
		return "";

	ResultText[sizeof(ResultText) - 1] = '\0';

	return ResultText;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetResultText(const char* NewValue)
{
	strncpy(ResultText, NewValue, sizeof(ResultText) - 1);
}

/*==========================================================================*/
char* GSP::s_LogonResponse::GetReconnectAddress()
{
	if (Size < offsetof(s_LogonResponse, ReconnectAddress) + sizeof(ReconnectAddress))
		return "";

	ReconnectAddress[sizeof(ReconnectAddress) - 1] = '\0';

	return ReconnectAddress;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetReconnectAddress(const char* NewValue)
{
	strncpy(ReconnectAddress, NewValue, sizeof(ReconnectAddress) - 1);
}

/*==========================================================================*/
__int32 GSP::s_LogonResponse::GetInteger_1()
{
	if (Size < offsetof(s_LogonResponse, Integer_1) + sizeof(Integer_1))
		return 0;

	return Integer_1;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetInteger_1(__int32 NewValue)
{
	Integer_1 = NewValue;
}

/*==========================================================================*/
char* GSP::s_LogonResponse::GetServerVersion()
{
	if (Size < offsetof(s_LogonResponse, ServerVersion) + sizeof(ServerVersion))
		return "";

	ServerVersion[sizeof(ServerVersion) - 1] = '\0';

	return ServerVersion;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetServerVersion(const char* NewValue)
{
	strncpy(ServerVersion, NewValue, sizeof(ServerVersion) - 1);
}

/*==========================================================================*/
char* GSP::s_LogonResponse::GetServerName()
{
	if (Size < offsetof(s_LogonResponse, ServerName) + sizeof(ServerName))
		return "";

	ServerName[sizeof(ServerName) - 1] = '\0';

	return ServerName;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetServerName(const char* NewValue)
{
	strncpy(ServerName, NewValue, sizeof(ServerName) - 1);
}

/*==========================================================================*/
char* GSP::s_LogonResponse::GetServiceProviderName()
{
	if (Size < offsetof(s_LogonResponse, ServiceProviderName) + sizeof(ServiceProviderName))
		return "";

	ServiceProviderName[sizeof(ServiceProviderName) - 1] = '\0';

	return ServiceProviderName;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetServiceProviderName(const char* NewValue)
{
	strncpy(ServiceProviderName, NewValue, sizeof(ServiceProviderName) - 1);
}

/*==========================================================================*/
unsigned char GSP::s_LogonResponse::GetMarketDepthUpdatesBestBidAndAsk()
{
	if (Size < offsetof(s_LogonResponse, MarketDepthUpdatesBestBidAndAsk) + sizeof(MarketDepthUpdatesBestBidAndAsk))
		return 0;

	return MarketDepthUpdatesBestBidAndAsk;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetMarketDepthUpdatesBestBidAndAsk(unsigned char NewValue)
{
	MarketDepthUpdatesBestBidAndAsk = NewValue;
}

/*==========================================================================*/
unsigned char GSP::s_LogonResponse::GetTradingIsSupported()
{
	if (Size < offsetof(s_LogonResponse, TradingIsSupported) + sizeof(TradingIsSupported))
		return 0;

	return TradingIsSupported;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetTradingIsSupported(unsigned char NewValue)
{
	TradingIsSupported = NewValue;
}

/*==========================================================================*/
unsigned char GSP::s_LogonResponse::GetOCOOrdersSupported()
{
	if (Size < offsetof(s_LogonResponse, OCOOrdersSupported) + sizeof(OCOOrdersSupported))
		return 0;

	return OCOOrdersSupported;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetOCOOrdersSupported(unsigned char NewValue)
{
	OCOOrdersSupported = NewValue;
}

/*==========================================================================*/
unsigned char GSP::s_LogonResponse::GetOrderCancelReplaceSupported()
{
	if (Size < offsetof(s_LogonResponse, OrderCancelReplaceSupported) + sizeof(OrderCancelReplaceSupported))
		return 0;

	return OrderCancelReplaceSupported;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetOrderCancelReplaceSupported(unsigned char NewValue)
{
	OrderCancelReplaceSupported = NewValue;
}

/*==========================================================================*/
char* GSP::s_LogonResponse::GetSymbolExchangeDelimiter()
{
	if (Size < offsetof(s_LogonResponse, SymbolExchangeDelimiter) + sizeof(SymbolExchangeDelimiter))
		return "";

	SymbolExchangeDelimiter[sizeof(SymbolExchangeDelimiter) - 1] = '\0';

	return SymbolExchangeDelimiter;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetSymbolExchangeDelimiter(const char* NewValue)
{
	strncpy(SymbolExchangeDelimiter, NewValue, sizeof(SymbolExchangeDelimiter) - 1);
}

/*==========================================================================*/
unsigned char GSP::s_LogonResponse::GetSecurityDefinitionsSupported()
{
	if (Size < offsetof(s_LogonResponse, SecurityDefinitionsSupported) + sizeof(SecurityDefinitionsSupported))
		return 0;

	return SecurityDefinitionsSupported;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetSecurityDefinitionsSupported(unsigned char NewValue)
{
	SecurityDefinitionsSupported = NewValue;
}

/*==========================================================================*/
unsigned char GSP::s_LogonResponse::GetHistoricalPriceDataSupported()
{
	if (Size < offsetof(s_LogonResponse, HistoricalPriceDataSupported) + sizeof(HistoricalPriceDataSupported))
		return 0;

	return HistoricalPriceDataSupported;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetHistoricalPriceDataSupported(unsigned char NewValue)
{
	HistoricalPriceDataSupported  = NewValue;
}

/*==========================================================================*/
unsigned char GSP::s_LogonResponse::GetResubscribeWhenMarketDataFeedRestored()
{
	if (Size < offsetof(s_LogonResponse, ResubscribeWhenMarketDataFeedRestored) + sizeof(ResubscribeWhenMarketDataFeedRestored))
		return 0;

	return ResubscribeWhenMarketDataFeedRestored;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetResubscribeWhenMarketDataFeedRestored(unsigned char NewValue)
{
	ResubscribeWhenMarketDataFeedRestored = NewValue;
}

/****************************************************************************/
// s_Heartbeat

/*==========================================================================*/
unsigned __int16 GSP::s_Heartbeat::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_Heartbeat::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_Heartbeat), Size));
}

/*==========================================================================*/
unsigned __int32 GSP::s_Heartbeat::GetDroppedMessages()
{
	if (Size < offsetof(s_Heartbeat, DroppedMessages) + sizeof(DroppedMessages))
		return 0;

	return DroppedMessages;
}

/*==========================================================================*/
void GSP::s_Heartbeat::SetDroppedMessages(unsigned __int32 NewValue)
{
	DroppedMessages = NewValue;
}

/*==========================================================================*/
unsigned __int16 GSP::s_DisconnectFromServer::GetMessageSize()
{
	return Size;
}

/****************************************************************************/
// s_DisconnectFromServer

/*==========================================================================*/
void GSP::s_DisconnectFromServer::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_DisconnectFromServer), Size));
}

/*==========================================================================*/
char* GSP::s_DisconnectFromServer::GetDisconnectReason()
{
	if (Size < offsetof(s_DisconnectFromServer, DisconnectReason) + sizeof(DisconnectReason))
		return "";

	DisconnectReason[sizeof(DisconnectReason) - 1] = '\0';

	return DisconnectReason;
}

/*==========================================================================*/
void GSP::s_DisconnectFromServer::SetDisconnectReason(const char* NewValue)
{
	strncpy(DisconnectReason, NewValue, sizeof(DisconnectReason) - 1);
}

/****************************************************************************/
// s_MarketDataFeedStatus

/*==========================================================================*/
unsigned __int16 GSP::s_MarketDataFeedStatus::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDataFeedStatus::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_MarketDataFeedStatus), Size));
}

/*==========================================================================*/
GSP::MarketDataFeedStatusEnum GSP::s_MarketDataFeedStatus::GetStatus()
{
	if (Size < offsetof(s_MarketDataFeedStatus, Status) + sizeof(Status))
		return (MarketDataFeedStatusEnum)0;

	return Status;
}

/*==========================================================================*/
void GSP::s_MarketDataFeedStatus::SetStatus(MarketDataFeedStatusEnum NewValue)
{
	Status = NewValue;
}

/****************************************************************************/
// s_MarketDataFeedSymbolStatus

/*==========================================================================*/
unsigned __int16 GSP::s_MarketDataFeedSymbolStatus::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDataFeedSymbolStatus::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_MarketDataFeedSymbolStatus), Size));
}

/*==========================================================================*/
unsigned __int16 GSP::s_MarketDataFeedSymbolStatus::GetMarketDataSymbolID()
{
	if (Size < offsetof(s_MarketDataFeedSymbolStatus, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
		return 0;

	return MarketDataSymbolID;
}

/*==========================================================================*/
void GSP::s_MarketDataFeedSymbolStatus::SetMarketDataSymbolID(unsigned __int16 NewValue)
{
	MarketDataSymbolID = NewValue;
}

/*==========================================================================*/
GSP::MarketDataFeedStatusEnum GSP::s_MarketDataFeedSymbolStatus::GetStatus()
{
	if (Size < offsetof(s_MarketDataFeedSymbolStatus, Status) + sizeof(Status))
		return (MarketDataFeedStatusEnum)0;

	return Status;
}

/*==========================================================================*/
void GSP::s_MarketDataFeedSymbolStatus::SetStatus(MarketDataFeedStatusEnum NewValue)
{
	Status = NewValue;
}

/****************************************************************************/
// s_MarketDataRequest

/*==========================================================================*/
unsigned __int16 GSP::s_MarketDataRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDataRequest::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_MarketDataRequest), Size));
}

/*==========================================================================*/
GSP::RequestActionEnum GSP::s_MarketDataRequest::GetRequestActionValue()
{
	if (Size < offsetof(s_MarketDataRequest, RequestActionValue) + sizeof(RequestActionValue))
		return (RequestActionEnum)0;

	return RequestActionValue;
}

/*==========================================================================*/
void GSP::s_MarketDataRequest::SetRequestActionValue(GSP::RequestActionEnum NewValue)
{
	RequestActionValue = NewValue;
}

/*==========================================================================*/
unsigned __int16 GSP::s_MarketDataRequest::GetMarketDataSymbolID()
{
	if (Size < offsetof(s_MarketDataRequest, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
		return 0;

	return MarketDataSymbolID;
}

/*==========================================================================*/
void GSP::s_MarketDataRequest::SetMarketDataSymbolID(unsigned __int16 NewValue)
{
	MarketDataSymbolID = NewValue;
}

/*==========================================================================*/
char* GSP::s_MarketDataRequest::GetSymbol()
{
	if (Size < offsetof(s_MarketDataRequest, Symbol) + sizeof(Symbol))
		return "";

	Symbol[sizeof(Symbol) - 1] = '\0';

	return Symbol;
}

/*==========================================================================*/
void GSP::s_MarketDataRequest::SetSymbol(const char* NewValue)
{
	strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
}

/*==========================================================================*/
char* GSP::s_MarketDataRequest::GetExchange()
{
	if (Size < offsetof(s_MarketDataRequest, Exchange) + sizeof(Exchange))
		return "";

	Exchange[sizeof(Exchange) - 1] = '\0';

	return Exchange;
}

/*==========================================================================*/
void GSP::s_MarketDataRequest::SetExchange(const char* NewValue)
{
	strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
}

/****************************************************************************/
// s_MarketDepthRequest

/*==========================================================================*/
unsigned __int16 GSP::s_MarketDepthRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDepthRequest::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_MarketDepthRequest), Size));
}

/*==========================================================================*/
GSP::RequestActionEnum GSP::s_MarketDepthRequest::GetRequestActionValue()
{
	if (Size < offsetof(s_MarketDepthRequest, RequestActionValue) + sizeof(RequestActionValue))
		return (RequestActionEnum)0;

	return RequestActionValue;
}

/*==========================================================================*/
void GSP::s_MarketDepthRequest::SetRequestActionValue(GSP::RequestActionEnum NewValue)
{
	RequestActionValue = NewValue;
}

/*==========================================================================*/
unsigned __int16 GSP::s_MarketDepthRequest::GetMarketDataSymbolID()
{
	if (Size < offsetof(s_MarketDepthRequest, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
		return 0;

	return MarketDataSymbolID;
}

/*==========================================================================*/
void GSP::s_MarketDepthRequest::SetMarketDataSymbolID(unsigned __int16 NewValue)
{
	MarketDataSymbolID = NewValue;
}

/*==========================================================================*/
char* GSP::s_MarketDepthRequest::GetSymbol()
{
	if (Size < offsetof(s_MarketDepthRequest, Symbol) + sizeof(Symbol))
		return "";

	Symbol[sizeof(Symbol) - 1] = '\0';

	return Symbol;
}

/*==========================================================================*/
void GSP::s_MarketDepthRequest::SetSymbol(const char* NewValue)
{
	strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
}

/*==========================================================================*/
char* GSP::s_MarketDepthRequest::GetExchange()
{
	if (Size < offsetof(s_MarketDepthRequest, Exchange) + sizeof(Exchange))
		return "";

	Exchange[sizeof(Exchange) - 1] = '\0';

	return Exchange;
}

/*==========================================================================*/
void GSP::s_MarketDepthRequest::SetExchange(const char* NewValue)
{
	strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
}

/*==========================================================================*/
__int32 GSP::s_MarketDepthRequest::GetNumberOfLevels()
{
	if (Size < offsetof(s_MarketDepthRequest, NumberOfLevels) + sizeof(NumberOfLevels))
		return 0;

	return NumberOfLevels;
}

/*==========================================================================*/
void GSP::s_MarketDepthRequest::SetNumberOfLevels(__int32 NewValue)
{
	NumberOfLevels = NewValue;
}

/****************************************************************************/
// s_MarketDataReject

/*==========================================================================*/
unsigned __int16 GSP::s_MarketDataReject::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDataReject::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_MarketDataReject), Size));
}

/*==========================================================================*/
unsigned __int16 GSP::s_MarketDataReject::GetMarketDataSymbolID()
{
	if (Size < offsetof(s_MarketDataReject, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
		return 0;

	return MarketDataSymbolID;
}

/*==========================================================================*/
void GSP::s_MarketDataReject::SetMarketDataSymbolID(unsigned __int16 NewValue)
{
	MarketDataSymbolID = NewValue;
}

/*==========================================================================*/
char* GSP::s_MarketDataReject::GetRejectText()
{
	if (Size < offsetof(s_MarketDataReject, RejectText) + sizeof(RejectText))
		return "";

	RejectText[sizeof(RejectText) - 1] = '\0';

	return RejectText;
}

/*==========================================================================*/
void GSP::s_MarketDataReject::SetRejectText(const char* NewValue)
{
	strncpy(RejectText, NewValue, sizeof(RejectText) - 1);
}

/****************************************************************************/
// s_MarketDataSnapshot

/*==========================================================================*/
unsigned __int16 GSP::s_MarketDataSnapshot::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_MarketDataSnapshot), Size));
}

/*==========================================================================*/
unsigned __int16 GSP::s_MarketDataSnapshot::GetMarketDataSymbolID()
{
	if (Size < offsetof(s_MarketDataSnapshot, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
		return 0;

	return MarketDataSymbolID;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetMarketDataSymbolID(unsigned __int16 NewValue)
{
	MarketDataSymbolID = NewValue;
}

/*==========================================================================*/
double GSP::s_MarketDataSnapshot::GetSettlementPrice()
{
	if (Size < offsetof(s_MarketDataSnapshot, SettlementPrice) + sizeof(SettlementPrice))
		return 0;

	return SettlementPrice;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetSettlementPrice(double NewValue)
{
	SettlementPrice = NewValue;
}

/*==========================================================================*/
double GSP::s_MarketDataSnapshot::GetDailyOpen()
{
	if (Size < offsetof(s_MarketDataSnapshot, DailyOpen) + sizeof(DailyOpen))
		return 0;

	return DailyOpen;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetDailyOpen(double NewValue)
{
	DailyOpen = NewValue;
}

/*==========================================================================*/
double GSP::s_MarketDataSnapshot::GetDailyHigh()
{
	if (Size < offsetof(s_MarketDataSnapshot, DailyHigh) + sizeof(DailyHigh))
		return 0;

	return DailyHigh;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetDailyHigh(double NewValue)
{
	DailyHigh = NewValue;
}

/*==========================================================================*/
double GSP::s_MarketDataSnapshot::GetDailyLow()
{
	if (Size < offsetof(s_MarketDataSnapshot, DailyLow) + sizeof(DailyLow))
		return 0;

	return DailyLow;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetDailyLow(double NewValue)
{
	DailyLow = NewValue;
}

/*==========================================================================*/
double GSP::s_MarketDataSnapshot::GetDailyVolume()
{
	if (Size < offsetof(s_MarketDataSnapshot, DailyVolume) + sizeof(DailyVolume))
		return 0;

	return DailyVolume;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetDailyVolume(double NewValue)
{
	DailyVolume = NewValue;
}

/*==========================================================================*/
unsigned __int32 GSP::s_MarketDataSnapshot::GetDailyNumberOfTrades()
{
	if (Size < offsetof(s_MarketDataSnapshot, DailyNumberOfTrades) + sizeof(DailyNumberOfTrades))
		return 0;

	return DailyNumberOfTrades;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetDailyNumberOfTrades(unsigned __int32 NewValue)
{
	DailyNumberOfTrades = NewValue;
}

/*==========================================================================*/
unsigned __int32 GSP::s_MarketDataSnapshot::GetSharesOutstanding()
{
	if (Size < offsetof(s_MarketDataSnapshot, SharesOutstanding) + sizeof(SharesOutstanding))
		return 0;

	return SharesOutstanding;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetSharesOutstanding(unsigned __int32 NewValue)
{
	SharesOutstanding = NewValue;
}

/*==========================================================================*/
unsigned __int32 GSP::s_MarketDataSnapshot::GetOpenInterest()
{
	if (Size < offsetof(s_MarketDataSnapshot, OpenInterest) + sizeof(OpenInterest))
		return 0;

	return OpenInterest;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetOpenInterest(unsigned __int32 NewValue)
{
	OpenInterest = NewValue;
}

/*==========================================================================*/
unsigned __int32 GSP::s_MarketDataSnapshot::GetUnitsOutstanding()
{
	if (Size < offsetof(s_MarketDataSnapshot, UnitsOutstanding) + sizeof(UnitsOutstanding))
		return 0;

	return UnitsOutstanding;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetUnitsOutstanding(unsigned __int32 NewValue)
{
	UnitsOutstanding = NewValue;
}

/*==========================================================================*/
double GSP::s_MarketDataSnapshot::GetBid()
{
	if (Size < offsetof(s_MarketDataSnapshot, Bid) + sizeof(Bid))
		return 0;

	return Bid;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetBid(double NewValue)
{
	Bid = NewValue;
}

/*==========================================================================*/
double GSP::s_MarketDataSnapshot::GetAsk()
{
	if (Size < offsetof(s_MarketDataSnapshot, Ask) + sizeof(Ask))
		return 0;

	return Ask;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetAsk(double NewValue)
{
	Ask = NewValue;
}

/*==========================================================================*/
unsigned __int32 GSP::s_MarketDataSnapshot::GetAskSize()
{
	if (Size < offsetof(s_MarketDataSnapshot, AskSize) + sizeof(AskSize))
		return 0;

	return AskSize;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetAskSize(unsigned __int32 NewValue)
{
	AskSize = NewValue;
}

/*==========================================================================*/
unsigned __int32 GSP::s_MarketDataSnapshot::GetBidSize()
{
	if (Size < offsetof(s_MarketDataSnapshot, BidSize) + sizeof(BidSize))
		return 0;

	return BidSize;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetBidSize(unsigned __int32 NewValue)
{
	BidSize = NewValue;
}

/*==========================================================================*/
double GSP::s_MarketDataSnapshot::GetLastTradePrice()
{
	if (Size < offsetof(s_MarketDataSnapshot, LastTradePrice) + sizeof(LastTradePrice))
		return 0;

	return LastTradePrice;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetLastTradePrice(double NewValue)
{
	LastTradePrice = NewValue;
}

/*==========================================================================*/
unsigned __int32 GSP::s_MarketDataSnapshot::GetLastTradeSize()
{
	if (Size < offsetof(s_MarketDataSnapshot, LastTradeSize) + sizeof(LastTradeSize))
		return 0;

	return LastTradeSize;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetLastTradeSize(unsigned __int32 NewValue)
{
	LastTradeSize = NewValue;
}

/*==========================================================================*/
GSP::t_DateTime GSP::s_MarketDataSnapshot::GetLastTradeDateTimeUnix()
{
	if (Size < offsetof(s_MarketDataSnapshot, LastTradeDateTimeUnix) + sizeof(LastTradeDateTimeUnix))
		return 0;

	return LastTradeDateTimeUnix;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetLastTradeDateTimeUnix(GSP::t_DateTime NewValue)
{
	LastTradeDateTimeUnix = NewValue;
}

/*==========================================================================*/
__int16 GSP::s_MarketDataSnapshot::GetLastTradeMilliseconds()
{
	if (Size < offsetof(s_MarketDataSnapshot, LastTradeMilliseconds) + sizeof(LastTradeMilliseconds))
		return 0;

	return LastTradeMilliseconds;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetLastTradeMilliseconds(__int16 NewValue)
{
	LastTradeMilliseconds = NewValue;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetToUnsetValues()
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
	AskSize = UINT_MAX;
	BidSize = UINT_MAX;

	LastTradePrice = DBL_MAX;
	LastTradeSize = UINT_MAX;
}

/****************************************************************************/
// s_FundamentalDataResponse

/*==========================================================================*/
unsigned __int16 GSP::s_FundamentalDataResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_FundamentalDataResponse::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_FundamentalDataResponse), Size));
}

/*==========================================================================*/
unsigned __int16 GSP::s_FundamentalDataResponse::GetMarketDataSymbolID()
{
	if (Size < offsetof(s_FundamentalDataResponse, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
		return 0;

	return MarketDataSymbolID;
}

/*==========================================================================*/
void GSP::s_FundamentalDataResponse::SetMarketDataSymbolID(unsigned __int16 NewValue)
{
	MarketDataSymbolID = NewValue;
}

/*==========================================================================*/
char* GSP::s_FundamentalDataResponse::GetSymbolDescription()
{
	if (Size < offsetof(s_FundamentalDataResponse, SymbolDescription) + sizeof(SymbolDescription))
		return "";

	SymbolDescription[sizeof(SymbolDescription) - 1] = '\0';

	return SymbolDescription;
}

/*==========================================================================*/
void GSP::s_FundamentalDataResponse::SetSymbolDescription(const char* NewValue)
{
	strncpy(SymbolDescription, NewValue, sizeof(SymbolDescription) - 1);
}

/*==========================================================================*/
float GSP::s_FundamentalDataResponse::GetTickSize()
{
	if (Size < offsetof(s_FundamentalDataResponse, TickSize) + sizeof(TickSize))
		return 0;

	return TickSize;
}

/*==========================================================================*/
void GSP::s_FundamentalDataResponse::SetTickSize(float NewValue)
{
	TickSize = NewValue;
}

/*==========================================================================*/
float GSP::s_FundamentalDataResponse::GetTickCurrencyValue()
{
	if (Size < offsetof(s_FundamentalDataResponse, TickCurrencyValue) + sizeof(TickCurrencyValue))
		return 0;

	return TickCurrencyValue;
}

/*==========================================================================*/
void GSP::s_FundamentalDataResponse::SetTickCurrencyValue(float NewValue)
{
	TickCurrencyValue = NewValue;
}

/*==========================================================================*/
GSP::DisplayFormatEnum GSP::s_FundamentalDataResponse::GetDisplayFormat()
{
	if (Size < offsetof(s_FundamentalDataResponse, DisplayFormat) + sizeof(DisplayFormat))
		return (DisplayFormatEnum)0;

	return DisplayFormat;
}

/*==========================================================================*/
void GSP::s_FundamentalDataResponse::SetDisplayFormat(GSP::DisplayFormatEnum NewValue)
{
	DisplayFormat = NewValue;
}

/*==========================================================================*/
float GSP::s_FundamentalDataResponse::GetBuyRolloverInterest()
{
	if (Size < offsetof(s_FundamentalDataResponse, BuyRolloverInterest) + sizeof(BuyRolloverInterest))
		return 0;

	return BuyRolloverInterest;
}

/*==========================================================================*/
void GSP::s_FundamentalDataResponse::SetBuyRolloverInterest(float NewValue)
{
	BuyRolloverInterest = NewValue;
}

/*==========================================================================*/
float GSP::s_FundamentalDataResponse::GetSellRolloverInterest()
{
	if (Size < offsetof(s_FundamentalDataResponse, SellRolloverInterest) + sizeof(SellRolloverInterest))
		return 0;

	return SellRolloverInterest;
}

/*==========================================================================*/
void GSP::s_FundamentalDataResponse::SetSellRolloverInterest(float NewValue)
{
	SellRolloverInterest = NewValue;
}

/*==========================================================================*/
float GSP::s_FundamentalDataResponse::GetOrderPriceMultiplier()
{
	if (Size < offsetof(s_FundamentalDataResponse, OrderPriceMultiplier) + sizeof(OrderPriceMultiplier))
		return 0;

	return OrderPriceMultiplier;
}

/*==========================================================================*/
void GSP::s_FundamentalDataResponse::SetOrderPriceMultiplier(float NewValue)
{
	OrderPriceMultiplier = NewValue;
}

/*==========================================================================*/
void GSP::s_FundamentalDataResponse::SetDisplayFormatFromTickSize()
{
	if (TickSize == 0.0f && DisplayFormat == GSP:: DISPLAY_FORMAT_UNSET)
	{
		DisplayFormat = GSP::DISPLAY_FORMAT_DECIMAL_3;
		return;
	}

	if (TickSize < 0.00000995f)
		DisplayFormat = GSP::DISPLAY_FORMAT_DECIMAL_6;
	else if (TickSize < 0.0000995f)
		DisplayFormat = GSP::DISPLAY_FORMAT_DECIMAL_5;
	else if (TickSize < 0.000995f)
		DisplayFormat = GSP::DISPLAY_FORMAT_DECIMAL_4;
	else if (TickSize > 0.00249f && TickSize < 0.00251f)
		DisplayFormat  = GSP::DISPLAY_FORMAT_DECIMAL_4;
	else if (TickSize < 0.00995f)
	{
		if (TickSize > 0.00390620f && TickSize < 0.00390630f)  //== 0.00390625)
			DisplayFormat = GSP::DISPLAY_FORMAT_DENOMINATOR_256;
		else if (TickSize > 0.0078120f && TickSize < 0.0078130f)  // .25/32 = 0.0078125
			DisplayFormat = GSP::DISPLAY_FORMAT_DENOMINATOR_32_QUARTERS;
		else
			DisplayFormat = GSP::DISPLAY_FORMAT_DECIMAL_3;
	}
	else if (TickSize < 0.0995f)
	{
		if (TickSize > 0.0249f &&  TickSize < 0.0251f)
			DisplayFormat = GSP::DISPLAY_FORMAT_DECIMAL_3;
		else if (TickSize > 0.015620f && TickSize < 0.015630f)  // .5/32 = 0.015625
			DisplayFormat = GSP::DISPLAY_FORMAT_DENOMINATOR_32_HALVES;
		else if (TickSize > 0.03120f && TickSize < 0.03130f)  // 1/32 = 0.03125 
			DisplayFormat = GSP::DISPLAY_FORMAT_DENOMINATOR_32;
		else if (TickSize > 0.0620f && TickSize < 0.0630f)  //== 0.0625)
			DisplayFormat = GSP::DISPLAY_FORMAT_DENOMINATOR_16;
		else
			DisplayFormat  = GSP::DISPLAY_FORMAT_DECIMAL_2;
	}
	else if (TickSize < 0.995f)
	{
		if (TickSize > 0.120 && TickSize < 0.130)  //== 0.125)
			DisplayFormat = GSP::DISPLAY_FORMAT_DENOMINATOR_8;
		else
			DisplayFormat = GSP::DISPLAY_FORMAT_DECIMAL_1;
	}
	else
		DisplayFormat = GSP::DISPLAY_FORMAT_DECIMAL_0;
}

/****************************************************************************/
// s_TradeIncrementalUpdateWithFullDepth

/*==========================================================================*/
unsigned __int16 GSP::s_TradeIncrementalUpdateWithFullDepth::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_TradeIncrementalUpdateWithFullDepth::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_TradeIncrementalUpdateWithFullDepth), Size));
}

/****************************************************************************/
// s_MarketDepthFullUpdate

/*==========================================================================*/
unsigned __int16 GSP::s_MarketDepthFullUpdate::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDepthFullUpdate::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_MarketDepthFullUpdate), Size));
}

/*==========================================================================*/
unsigned __int16 GSP::s_MarketDepthFullUpdate::GetMarketDataSymbolID()
{
	if (Size < offsetof(s_MarketDepthFullUpdate, MarketDataSymbolID) + sizeof(MarketDataSymbolID))
		return 0;

	return MarketDataSymbolID;
}

/*==========================================================================*/
void GSP::s_MarketDepthFullUpdate::SetMarketDataSymbolID(unsigned __int16 NewValue)
{
	MarketDataSymbolID = NewValue;
}

/****************************************************************************/
// s_MarketDepthFullUpdateLarge

/*==========================================================================*/
unsigned __int16 GSP::s_MarketDepthFullUpdateLarge::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDepthFullUpdateLarge::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_MarketDepthFullUpdateLarge), Size));
}

/****************************************************************************/
// s_MarketDepthIncrementalUpdate

/*==========================================================================*/
unsigned __int16 GSP::s_MarketDepthIncrementalUpdate::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDepthIncrementalUpdate::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_MarketDepthIncrementalUpdate), Size));
}

/****************************************************************************/
// s_TradeIncrementalUpdate

/*==========================================================================*/
unsigned __int16 GSP::s_TradeIncrementalUpdate::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_TradeIncrementalUpdate::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_TradeIncrementalUpdate), Size));
}

/****************************************************************************/
// s_QuoteIncrementalUpdate

/*==========================================================================*/
unsigned __int16 GSP::s_QuoteIncrementalUpdate::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_QuoteIncrementalUpdate::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_QuoteIncrementalUpdate), Size));
}

/****************************************************************************/
// s_TradeIncrementalUpdateCompact

/*==========================================================================*/
unsigned __int16 GSP::s_TradeIncrementalUpdateCompact::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_TradeIncrementalUpdateCompact::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_TradeIncrementalUpdateCompact), Size));
}

/****************************************************************************/
// s_DailyVolumeIncrementalUpdate

/*==========================================================================*/
unsigned __int16 GSP::s_DailyVolumeIncrementalUpdate::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_DailyVolumeIncrementalUpdate::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_DailyVolumeIncrementalUpdate), Size));
}

/****************************************************************************/
// s_DailyHighIncrementalUpdate

/*==========================================================================*/
unsigned __int16 GSP::s_DailyHighIncrementalUpdate::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_DailyHighIncrementalUpdate::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_DailyHighIncrementalUpdate), Size));
}

/****************************************************************************/
// s_DailyLowIncrementalUpdate

/*==========================================================================*/
unsigned __int16 GSP::s_DailyLowIncrementalUpdate::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_DailyLowIncrementalUpdate::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_DailyLowIncrementalUpdate), Size));
}

/*==========================================================================*/
char* GSP::s_OrderUpdateReport::GetSymbol()
{
	if (Size < offsetof(s_OrderUpdateReport, Symbol) + sizeof(Symbol))
		return "";

	Symbol[sizeof(Symbol) - 1] = '\0';

	return Symbol;
}

/****************************************************************************/
// s_SubmitNewSingleOrder

/*==========================================================================*/
unsigned __int16 GSP::s_SubmitNewSingleOrder::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_SubmitNewSingleOrder::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_SubmitNewSingleOrder), Size));
}

/****************************************************************************/
// s_CancelReplaceOrder

/*==========================================================================*/
unsigned __int16 GSP::s_CancelReplaceOrder::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_CancelReplaceOrder::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_CancelReplaceOrder), Size));
}

/****************************************************************************/
// s_CancelReplaceOrder2

/*==========================================================================*/
unsigned __int16 GSP::s_CancelReplaceOrder2::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_CancelReplaceOrder2::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_CancelReplaceOrder2), Size));
}

/****************************************************************************/
// s_CancelOrder

/*==========================================================================*/
unsigned __int16 GSP::s_CancelOrder::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_CancelOrder::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_CancelOrder), Size));
}

/****************************************************************************/
// s_SubmitNewOCOOrder

/*==========================================================================*/
unsigned __int16 GSP::s_SubmitNewOCOOrder::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_SubmitNewOCOOrder::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_SubmitNewOCOOrder), Size));
}

/****************************************************************************/
// s_OpenOrdersRequest

/*==========================================================================*/
unsigned __int16 GSP::s_OpenOrdersRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_OpenOrdersRequest::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_OpenOrdersRequest), Size));
}

/****************************************************************************/
// s_RequestHistoricalOrderFills

/*==========================================================================*/
unsigned __int16 GSP::s_RequestHistoricalOrderFills::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_RequestHistoricalOrderFills::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_RequestHistoricalOrderFills), Size));
}

/****************************************************************************/
// s_CurrentPositionsRequest

/*==========================================================================*/
unsigned __int16 GSP::s_CurrentPositionsRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_CurrentPositionsRequest::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_CurrentPositionsRequest), Size));
}

/****************************************************************************/
// s_CurrentPositionsRequestReject

/*==========================================================================*/
unsigned __int16 GSP::s_CurrentPositionsRequestReject::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_CurrentPositionsRequestReject::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_CurrentPositionsRequestReject), Size));
}

/****************************************************************************/
// s_OrderUpdateReport

/*==========================================================================*/
unsigned __int16 GSP::s_OrderUpdateReport::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_OrderUpdateReport), Size));
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetSymbol(const char* NewValue)
{
	strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
}

/*==========================================================================*/
char* GSP::s_OrderUpdateReport::GetExchange()
{
	if (Size < offsetof(s_OrderUpdateReport, Exchange) + sizeof(Exchange))
		return "";

	Exchange[sizeof(Exchange) - 1] = '\0';

	return Exchange;
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetExchange(const char* NewValue)
{
	strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
}
/*==========================================================================*/
char* GSP::s_OrderUpdateReport::GetPreviousServerOrderID()
{
	if (Size < offsetof(s_OrderUpdateReport, PreviousServerOrderID) + sizeof(PreviousServerOrderID))
		return "";

	PreviousServerOrderID[sizeof(PreviousServerOrderID) - 1] = '\0';

	return PreviousServerOrderID;
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetPreviousServerOrderID(const char* NewValue)
{
	strncpy(PreviousServerOrderID, NewValue, sizeof(PreviousServerOrderID) - 1);
}

/*==========================================================================*/
char* GSP::s_OrderUpdateReport::GetServerOrderID()
{
	if (Size < offsetof(s_OrderUpdateReport, ServerOrderID) + sizeof(ServerOrderID))
		return "";

	ServerOrderID[sizeof(ServerOrderID) - 1] = '\0';

	return ServerOrderID;
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetServerOrderID(const char* NewValue)
{
	strncpy(ServerOrderID, NewValue, sizeof(ServerOrderID) - 1);
}

/*==========================================================================*/
char* GSP::s_OrderUpdateReport::GetClientOrderID()
{
	if (Size < offsetof(s_OrderUpdateReport, ClientOrderID) + sizeof(ClientOrderID))
		return "";

	ClientOrderID[sizeof(ClientOrderID) - 1] = '\0';

	return ClientOrderID;
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetClientOrderID(const char* NewValue)
{
	strncpy(ClientOrderID, NewValue, sizeof(ClientOrderID) - 1);
}

/*==========================================================================*/
char* GSP::s_OrderUpdateReport::GetExchangeOrderID()
{
	if (Size < offsetof(s_OrderUpdateReport, ExchangeOrderID) + sizeof(ExchangeOrderID))
		return "";

	ExchangeOrderID[sizeof(ExchangeOrderID) - 1] = '\0';

	return ExchangeOrderID;
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetExchangeOrderID(const char* NewValue)
{
	strncpy(ExchangeOrderID, NewValue, sizeof(ExchangeOrderID) - 1);
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetUniqueFillExecutionID(const char* NewValue)
{
	strncpy(UniqueFillExecutionID, NewValue, sizeof(UniqueFillExecutionID) - 1);
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetTradeAccount(const char* NewValue)
{
	strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetInfoText(const char* NewValue)
{
	strncpy(InfoText, NewValue, sizeof(InfoText) - 1);
}

/****************************************************************************/
// s_OpenOrdersRequestReject

/*==========================================================================*/
unsigned __int16 GSP::s_OpenOrdersRequestReject::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_OpenOrdersRequestReject::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_OpenOrdersRequestReject), Size));
}

/****************************************************************************/
// s_HistoricalOrderFillReport

/*==========================================================================*/
unsigned __int16 GSP::s_HistoricalOrderFillReport::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_HistoricalOrderFillReport::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_HistoricalOrderFillReport), Size));
}

/****************************************************************************/
// s_PositionReport

/*==========================================================================*/
unsigned __int16 GSP::s_PositionReport::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_PositionReport::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_PositionReport), Size));
}

/*==========================================================================*/
void GSP::s_PositionReport::SetSymbol(const char* NewValue)
{
	strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
}

/*==========================================================================*/
void GSP::s_PositionReport::SetTradeAccount(const char* NewValue)
{
	strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
}

/****************************************************************************/
// s_RequestAccounts

/*==========================================================================*/
unsigned __int16 GSP::s_RequestAccounts::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_RequestAccounts::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_RequestAccounts), Size));
}

/****************************************************************************/
// s_AccountsListResponse

/*==========================================================================*/
unsigned __int16 GSP::s_AccountsListResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_AccountsListResponse::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_AccountsListResponse), Size));
}

/****************************************************************************/
// s_ExchangeListRequest

/*==========================================================================*/
unsigned __int16 GSP::s_ExchangeListRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_ExchangeListRequest::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_ExchangeListRequest), Size));
}

/****************************************************************************/
// s_ExchangeListResponse

/*==========================================================================*/
unsigned __int16 GSP::s_ExchangeListResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_ExchangeListResponse::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_ExchangeListResponse), Size));
}

/****************************************************************************/
// s_SymbolsForExchangeRequest

/*==========================================================================*/
unsigned __int16 GSP::s_SymbolsForExchangeRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_SymbolsForExchangeRequest::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_SymbolsForExchangeRequest), Size));
}

/****************************************************************************/
// s_UnderlyingSymbolsForExchangeRequest

/*==========================================================================*/
unsigned __int16 GSP::s_UnderlyingSymbolsForExchangeRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_UnderlyingSymbolsForExchangeRequest::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_UnderlyingSymbolsForExchangeRequest), Size));
}

/****************************************************************************/
// s_SymbolsForUnderlyingRequest

/*==========================================================================*/
unsigned __int16 GSP::s_SymbolsForUnderlyingRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_SymbolsForUnderlyingRequest::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_SymbolsForUnderlyingRequest), Size));
}

/****************************************************************************/
// s_SecurityDefinitionForSymbolRequest

/*==========================================================================*/
unsigned __int16 GSP::s_SecurityDefinitionForSymbolRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_SecurityDefinitionForSymbolRequest::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_SecurityDefinitionForSymbolRequest), Size));
}

/****************************************************************************/
// s_SymbolResponse

#if 0
/*==========================================================================*/
unsigned __int16 GSP::s_SymbolResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_SymbolResponse::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_SymbolResponse), Size));
}
#endif

/****************************************************************************/
// s_SecurityDefinitionResponse

/*==========================================================================*/
unsigned __int16 GSP::s_SecurityDefinitionResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_SecurityDefinitionResponse::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_SecurityDefinitionResponse), Size));
}

/****************************************************************************/
// s_AccountBalanceUpdate

/*==========================================================================*/
unsigned __int16 GSP::s_AccountBalanceUpdate::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_AccountBalanceUpdate::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_AccountBalanceUpdate), Size));
}

/*==========================================================================*/
void GSP::s_AccountBalanceUpdate::SetAccountCurrency(const char* NewValue)
{
	strncpy(AccountCurrency, NewValue, sizeof(AccountCurrency) - 1);
}

/*==========================================================================*/
void GSP::s_AccountBalanceUpdate::SetTradeAccount(const char* NewValue)
{
	strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
}

/****************************************************************************/
// s_UserMessage

/*==========================================================================*/
unsigned __int16 GSP::s_UserMessage::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_UserMessage::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_UserMessage), Size));
}

/****************************************************************************/
// s_GeneralLogMessage

/*==========================================================================*/
unsigned __int16 GSP::s_GeneralLogMessage::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_GeneralLogMessage::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_GeneralLogMessage), Size));
}

/****************************************************************************/
// s_HistoricalPriceDataRequest

/*==========================================================================*/
unsigned __int16 GSP::s_HistoricalPriceDataRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_HistoricalPriceDataRequest::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataRequest), Size));
}

/*==========================================================================*/
char* GSP::s_HistoricalPriceDataRequest::GetSymbol()
{
	if (Size < offsetof(s_HistoricalPriceDataRequest, Symbol) + sizeof(Symbol))
		return "";

	Symbol[sizeof(Symbol) - 1] = '\0';

	return Symbol;
}

/*==========================================================================*/
void GSP::s_HistoricalPriceDataRequest::SetSymbol(const char* NewValue)
{
	strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
}

/*==========================================================================*/
char* GSP::s_HistoricalPriceDataRequest::GetExchange()
{
	if (Size < offsetof(s_HistoricalPriceDataRequest, Exchange) + sizeof(Exchange))
		return "";

	Exchange[sizeof(Exchange) - 1] = '\0';

	return Exchange;
}

/*==========================================================================*/
void GSP::s_HistoricalPriceDataRequest::SetExchange(const char* NewValue)
{
	strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
}

/****************************************************************************/
// s_HistoricalPriceDataHeaderResponse

/*==========================================================================*/
unsigned __int16 GSP::s_HistoricalPriceDataHeaderResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_HistoricalPriceDataHeaderResponse::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataHeaderResponse), Size));
}

/****************************************************************************/
// s_HistoricalPriceDataReject

/*==========================================================================*/
unsigned __int16 GSP::s_HistoricalPriceDataReject::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_HistoricalPriceDataReject::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataReject), Size));
}

/****************************************************************************/
// s_HistoricalPriceDataRecordResponse

/*==========================================================================*/
unsigned __int16 GSP::s_HistoricalPriceDataRecordResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_HistoricalPriceDataRecordResponse::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataRecordResponse), Size));
}

/****************************************************************************/
// s_HistoricalPriceDataTickRecordResponse

/*==========================================================================*/
unsigned __int16 GSP::s_HistoricalPriceDataTickRecordResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_HistoricalPriceDataTickRecordResponse::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_HistoricalPriceDataTickRecordResponse), Size));
}

/****************************************************************************/
// s_ConfigurationRequestFromClient

/*==========================================================================*/
unsigned __int16 GSP::s_ConfigurationRequestFromClient::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_ConfigurationRequestFromClient::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_ConfigurationRequestFromClient), Size));
}

/****************************************************************************/
// s_ServerReadyToReceive

/*==========================================================================*/
__int32 GSP::s_ServerReadyToReceive::GetProtocolVersion()
{
	if (Size < offsetof(s_ServerReadyToReceive, ProtocolVersion) + sizeof(ProtocolVersion))
		return 0;

	return ProtocolVersion;
}

/*==========================================================================*/
unsigned __int16 GSP::s_ServerReadyToReceive::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_ServerReadyToReceive::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_ServerReadyToReceive), Size));
}

/*==========================================================================*/
char* GSP::s_ServerReadyToReceive::GetServerName()
{
	if (Size < offsetof(s_ServerReadyToReceive, ServerName) + sizeof(ServerName))
		return "";

	ServerName[sizeof(ServerName) - 1] = '\0';

	return ServerName;
}

/*==========================================================================*/
void GSP::s_ServerReadyToReceive::SetServerName(const char* NewValue)
{
	strncpy(ServerName, NewValue, sizeof(ServerName) - 1);
}

/*==========================================================================*/
char* GSP::s_ServerReadyToReceive::GetServerVersion()
{
	if (Size < offsetof(s_ServerReadyToReceive, ServerVersion) + sizeof(ServerVersion))
		return "";

	ServerVersion[sizeof(ServerVersion) - 1] = '\0';

	return ServerVersion;
}

/*==========================================================================*/
void GSP::s_ServerReadyToReceive::SetServerVersion(const char* NewValue)
{
	strncpy(ServerVersion, NewValue, sizeof(ServerVersion) - 1);
}

/*==========================================================================*/
char* GSP::s_ServerReadyToReceive::GetServiceProviderName()
{
	if (Size < offsetof(s_ServerReadyToReceive, ServiceProviderName) + sizeof(ServiceProviderName))
		return "";

	ServiceProviderName[sizeof(ServiceProviderName) - 1] = '\0';

	return ServiceProviderName;
}

/*==========================================================================*/
void GSP::s_ServerReadyToReceive::SetServiceProviderName(const char* NewValue)
{
	strncpy(ServiceProviderName, NewValue, sizeof(ServiceProviderName) - 1);
}

/*==========================================================================*/