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

/*==========================================================================*/
//Will get the size of the message received over the network
unsigned short GSP::s_LogonRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
//Performs a safe copy of data into this structure instance from the given data pointer
void GSP::s_LogonRequest::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_LogonRequest), Size) );
}

/*==========================================================================*/
int GSP::s_LogonRequest::GetProtocolVersion()
{
	return ProtocolVersion;
}

/*==========================================================================*/
const char * GSP::s_LogonRequest::GetUsername()
{
	// Example to check if member actually exists. This is not needed in this case because this member exists in the first version of this structure.
	if (offsetof(s_LogonRequest,Username ) > Size)
		return "";

	Username[sizeof(Username) - 1 ] = '\0';//Ensure that the null terminator exists

	return Username;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetUsername(const char * NewValue)
{
	strncpy(Username, NewValue, sizeof(Username) - 1);
}

/*==========================================================================*/
char * GSP::s_LogonRequest::GetPassword()
{
	Password[sizeof(Password) - 1 ] = '\0';
	return Password;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetPassword(const char * NewValue)
{
	strncpy(Password, NewValue, sizeof(Password) - 1);
}

/*==========================================================================*/
char * GSP::s_LogonRequest::GetGeneralTextData()
{
	GeneralTextData[sizeof(GeneralTextData) - 1 ] = '\0';
	return GeneralTextData;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetGeneralTextData(const char * NewValue)
{
	strncpy(GeneralTextData, NewValue, sizeof(GeneralTextData) - 1);
}

/*==========================================================================*/
int GSP::s_LogonRequest::GetInteger_1()
{
	return Integer_1;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetInteger_1(int NewValue)
{
	Integer_1 = NewValue;
}

/*==========================================================================*/
int GSP::s_LogonRequest::GetInteger_2()
{
	return Integer_2;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetInteger_2(int NewValue)
{
	Integer_2 = NewValue;
}

/*==========================================================================*/
int GSP::s_LogonRequest::GetInHeartbeatIntervalInSeconds()
{
	return HeartbeatIntervalInSeconds;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetHeartbeatIntervalInSeconds(int NewValue)
{
	HeartbeatIntervalInSeconds = NewValue;
}

/*==========================================================================*/
GSP::TradeModeEnum GSP::s_LogonRequest::GetTradeMode()
{
	return TradeMode;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetTradeMode(GSP::TradeModeEnum NewValue)
{
	TradeMode = NewValue;
}

/*==========================================================================*/
char * GSP::s_LogonRequest::GetTradeAccount()
{
	TradeAccount[sizeof(TradeAccount) - 1 ] = '\0';
	return TradeAccount;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetTradeAccount(const char * NewValue)
{
	strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
}

/*==========================================================================*/
char * GSP::s_LogonRequest::GetHardwareIdentifier()
{
	HardwareIdentifier[sizeof(HardwareIdentifier) - 1 ] = '\0';
	return HardwareIdentifier;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetHardwareIdentifier(const char * NewValue)
{
	strncpy(HardwareIdentifier, NewValue, sizeof(HardwareIdentifier) - 1);
}

/*==========================================================================*/
char * GSP::s_LogonRequest::GetClientName()
{
	ClientName[sizeof(ClientName) - 1 ] = '\0';
	return ClientName;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetClientName(const char * NewValue)
{
	strncpy(ClientName, NewValue, sizeof(ClientName) - 1);
}

/*==========================================================================*/
unsigned short GSP::s_LogonResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_LogonResponse::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_LogonResponse), Size) );
}

/*==========================================================================*/
int GSP::s_LogonResponse::GetProtocolVersion()
{
	return ProtocolVersion;
}

/*==========================================================================*/
GSP::LogonStatusEnum GSP::s_LogonResponse::GetResult()
{
	return Result;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetResult(LogonStatusEnum NewValue)
{
	Result = NewValue;
}

/*==========================================================================*/
char * GSP::s_LogonResponse::GetResultText()
{
	ResultText[sizeof(ResultText) - 1 ] = '\0';
	return ResultText;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetResultText(const char * NewValue)
{
	strncpy(ResultText, NewValue, sizeof(ResultText) - 1);
}

/*==========================================================================*/
char * GSP::s_LogonResponse::GetReconnectAddress()
{
	ReconnectAddress[sizeof(ReconnectAddress) - 1 ] = '\0';
	return ReconnectAddress;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetReconnectAddress(const char * NewValue)
{
	strncpy(ReconnectAddress, NewValue, sizeof(ReconnectAddress) - 1);
}

/*==========================================================================*/
int GSP::s_LogonResponse::GetInteger_1()
{
	return Integer_1;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetInteger_1(int NewValue)
{
	Integer_1 = NewValue;
}

/*==========================================================================*/
char * GSP::s_LogonResponse::GetServerVersion()
{
	ServerVersion[sizeof(ServerVersion) - 1 ] = '\0';
	return ServerVersion;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetServerVersion(const char * NewValue)
{
	strncpy(ServerVersion, NewValue, sizeof(ServerVersion) - 1);
}

/*==========================================================================*/
char * GSP::s_LogonResponse::GetServerName()
{
	ServerName[sizeof(ServerName) - 1 ] = '\0';
	return ServerName;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetServerName(const char * NewValue)
{
	strncpy(ServerName, NewValue, sizeof(ServerName) - 1);
}

/*==========================================================================*/
char * GSP::s_LogonResponse::GetServiceProviderName()
{
	ServiceProviderName[sizeof(ServiceProviderName) - 1 ] = '\0';
	return ServiceProviderName;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetServiceProviderName(const char * NewValue)
{
	strncpy(ServiceProviderName, NewValue, sizeof(ServiceProviderName) - 1);
}

/*==========================================================================*/
unsigned char GSP::s_LogonResponse::GetMarketDepthUpdatesBestBidAndAsk()
{
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
	return OrderCancelReplaceSupported;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetOrderCancelReplaceSupported(unsigned char NewValue)
{
	OrderCancelReplaceSupported = NewValue;
}

/*==========================================================================*/
char * GSP::s_LogonResponse::GetSymbolExchangeDelimiter()
{
	SymbolExchangeDelimiter[sizeof(SymbolExchangeDelimiter) - 1 ] = '\0';
	return SymbolExchangeDelimiter;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetSymbolExchangeDelimiter(const char * NewValue)
{
	strncpy(SymbolExchangeDelimiter, NewValue, sizeof(SymbolExchangeDelimiter) - 1);
}

/*==========================================================================*/
unsigned char GSP::s_LogonResponse::GetSecurityDefinitionsSupported()
{
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
	return ResubscribeWhenMarketDataFeedRestored;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetResubscribeWhenMarketDataFeedRestored(unsigned char NewValue)
{
	ResubscribeWhenMarketDataFeedRestored  = NewValue;
}

/*==========================================================================*/
unsigned short GSP::s_Heartbeat::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_Heartbeat::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_Heartbeat), Size) );
}

/*==========================================================================*/
unsigned int GSP::s_Heartbeat::GetDroppedMessages()
{
	return DroppedMessages;
}

/*==========================================================================*/
void GSP::s_Heartbeat::SetDroppedMessages(unsigned int NewValue)
{
	DroppedMessages = NewValue;
}

/*==========================================================================*/
unsigned short GSP::s_DisconnectFromServer::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_DisconnectFromServer::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_DisconnectFromServer), Size) );
}

/*==========================================================================*/
char * GSP::s_DisconnectFromServer::GetDisconnectReason()
{
	if (offsetof(s_DisconnectFromServer,DisconnectReason ) > Size)
		return "";

	DisconnectReason[sizeof(DisconnectReason) - 1 ] = '\0';
	return DisconnectReason;
}

/*==========================================================================*/
void GSP::s_DisconnectFromServer::SetDisconnectReason(const char * NewValue)
{
	strncpy(DisconnectReason, NewValue, sizeof(DisconnectReason) - 1);
}

/*==========================================================================*/
unsigned short GSP::s_MarketDataFeedStatus::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDataFeedStatus::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_MarketDataFeedStatus), Size) );
}

/*==========================================================================*/
GSP::MarketDataFeedStatusEnum GSP::s_MarketDataFeedStatus::GetStatus()
{
	return Status;
}

/*==========================================================================*/
void GSP::s_MarketDataFeedStatus::SetStatus(MarketDataFeedStatusEnum NewValue)
{
	Status = NewValue;
}

/*==========================================================================*/
unsigned short GSP::s_MarketDataFeedSymbolStatus::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDataFeedSymbolStatus::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_MarketDataFeedSymbolStatus), Size) );	
}

/*==========================================================================*/
unsigned short GSP::s_MarketDataFeedSymbolStatus::GetMarketDataSymbolID()
{
	return MarketDataSymbolID;
}

/*==========================================================================*/
void GSP::s_MarketDataFeedSymbolStatus::SetMarketDataSymbolID(unsigned short NewValue)
{
	MarketDataSymbolID = NewValue;
}

/*==========================================================================*/
GSP::MarketDataFeedStatusEnum GSP::s_MarketDataFeedSymbolStatus::GetStatus()
{
	return Status;
}

/*==========================================================================*/
void GSP::s_MarketDataFeedSymbolStatus::SetStatus(MarketDataFeedStatusEnum NewValue)
{
	Status = NewValue;
}

/*==========================================================================*/
unsigned short GSP::s_MarketDataRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDataRequest::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_MarketDataRequest), Size) );
}

/*==========================================================================*/
GSP::RequestActionEnum GSP::s_MarketDataRequest::GetRequestActionValue()
{
	return RequestActionValue;
}

/*==========================================================================*/
void GSP::s_MarketDataRequest::SetRequestActionValue(GSP::RequestActionEnum NewValue)
{
	RequestActionValue = NewValue;
}

/*==========================================================================*/
unsigned short GSP::s_MarketDataRequest::GetMarketDataSymbolID()
{
	return MarketDataSymbolID;
}

/*==========================================================================*/
void GSP::s_MarketDataRequest::SetMarketDataSymbolID(unsigned short NewValue)
{
	MarketDataSymbolID = NewValue;
}

/*==========================================================================*/
char * GSP::s_MarketDataRequest::GetSymbol()
{
	Symbol[sizeof(Symbol) - 1 ] = '\0';
	return Symbol;
}

/*==========================================================================*/
void GSP::s_MarketDataRequest::SetSymbol(const char * NewValue)
{
	strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
}

/*==========================================================================*/
char * GSP::s_MarketDataRequest::GetExchange()
{
	Exchange[sizeof(Exchange) - 1 ] = '\0';
	return Exchange;
}

/*==========================================================================*/
void GSP::s_MarketDataRequest::SetExchange(const char * NewValue)
{
	strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
}

/*==========================================================================*/
unsigned short GSP::s_MarketDepthRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDepthRequest::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_MarketDepthRequest), Size) );
}

/*==========================================================================*/
GSP::RequestActionEnum GSP::s_MarketDepthRequest::GetRequestActionValue()
{
	return RequestActionValue;
}

/*==========================================================================*/
void GSP::s_MarketDepthRequest::SetRequestActionValue(GSP::RequestActionEnum NewValue)
{
	RequestActionValue = NewValue;
}

/*==========================================================================*/
unsigned short GSP::s_MarketDepthRequest::GetMarketDataSymbolID()
{
	return MarketDataSymbolID;
}

/*==========================================================================*/
void GSP::s_MarketDepthRequest::SetMarketDataSymbolID(unsigned short NewValue)
{
	MarketDataSymbolID = NewValue;
}

/*==========================================================================*/
char * GSP::s_MarketDepthRequest::GetSymbol()
{
	Symbol[sizeof(Symbol) - 1 ] = '\0';
	return Symbol;
}

/*==========================================================================*/
void GSP::s_MarketDepthRequest::SetSymbol(const char * NewValue)
{
	strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
}

/*==========================================================================*/
char * GSP::s_MarketDepthRequest::GetExchange()
{
	Exchange[sizeof(Exchange) - 1 ] = '\0';
	return Exchange;
}

/*==========================================================================*/
void GSP::s_MarketDepthRequest::SetExchange(const char * NewValue)
{
	strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
}

/*==========================================================================*/
int GSP::s_MarketDepthRequest::GetNumberOfLevels()
{
	return NumberOfLevels;
}

/*==========================================================================*/
void GSP::s_MarketDepthRequest::SetNumberOfLevels(int NewValue)
{
	NumberOfLevels = NewValue;
}

/*==========================================================================*/
unsigned short GSP::s_MarketDataReject::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDataReject::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_MarketDataReject), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_MarketDataReject::GetMarketDataSymbolID()
{
	return MarketDataSymbolID;
}

/*==========================================================================*/
void GSP::s_MarketDataReject::SetMarketDataSymbolID(unsigned short NewValue)
{
	MarketDataSymbolID = NewValue;
}

/*==========================================================================*/
char * GSP::s_MarketDataReject::GetRejectText()
{
	RejectText[sizeof(RejectText) - 1 ] = '\0';
	return RejectText;
}

/*==========================================================================*/
void GSP::s_MarketDataReject::SetRejectText(const char * NewValue)
{
	strncpy(RejectText, NewValue, sizeof(RejectText) - 1);
}

/*==========================================================================*/
unsigned short GSP::s_MarketDataSnapshot::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_MarketDataSnapshot), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_MarketDataSnapshot::GetMarketDataSymbolID()
{
	return MarketDataSymbolID;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetMarketDataSymbolID(unsigned short NewValue)
{
	MarketDataSymbolID = NewValue;
}

/*==========================================================================*/
double GSP::s_MarketDataSnapshot::GetSettlementPrice()
{
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
	return DailyVolume;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetDailyVolume(double NewValue)
{
	DailyVolume = NewValue;
}

/*==========================================================================*/
unsigned int GSP::s_MarketDataSnapshot::GetDailyNumberOfTrades()
{
	return DailyNumberOfTrades;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetDailyNumberOfTrades(unsigned int NewValue)
{
	DailyNumberOfTrades = NewValue;
}

/*==========================================================================*/
unsigned int GSP::s_MarketDataSnapshot::GetSharesOutstanding()
{
	return SharesOutstanding;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetSharesOutstanding(unsigned int NewValue)
{
	SharesOutstanding = NewValue;
}

/*==========================================================================*/
unsigned int GSP::s_MarketDataSnapshot::GetOpenInterest()
{
	return OpenInterest;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetOpenInterest(unsigned int NewValue)
{
	OpenInterest = NewValue;
}

/*==========================================================================*/
unsigned int GSP::s_MarketDataSnapshot::GetUnitsOutstanding()
{
	return UnitsOutstanding;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetUnitsOutstanding(unsigned int NewValue)
{
	UnitsOutstanding = NewValue;
}

/*==========================================================================*/
double GSP::s_MarketDataSnapshot::GetBid()
{
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
	return Ask;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetAsk(double NewValue)
{
	Ask = NewValue;
}

/*==========================================================================*/
unsigned int GSP::s_MarketDataSnapshot::GetAskSize()
{
	return AskSize;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetAskSize(unsigned int NewValue)
{
	AskSize = NewValue;
}

/*==========================================================================*/
unsigned int GSP::s_MarketDataSnapshot::GetBidSize()
{
	return BidSize;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetBidSize(unsigned int NewValue)
{
	BidSize = NewValue;
}

/*==========================================================================*/
double GSP::s_MarketDataSnapshot::GetLastTradePrice()
{
	return LastTradePrice;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetLastTradePrice(double NewValue)
{
	LastTradePrice = NewValue;
}

/*==========================================================================*/
unsigned int GSP::s_MarketDataSnapshot::GetLastTradeSize()
{
	return LastTradeSize;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetLastTradeSize(unsigned int NewValue)
{
	LastTradeSize = NewValue;
}

/*==========================================================================*/
GSP::t_DateTime GSP::s_MarketDataSnapshot::GetLastTradeDateTimeUnix()
{
	return LastTradeDateTimeUnix;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetLastTradeDateTimeUnix(GSP::t_DateTime NewValue)
{
	LastTradeDateTimeUnix = NewValue;
}

/*==========================================================================*/
short GSP::s_MarketDataSnapshot::GetLastTradeMilliseconds()
{
	return LastTradeMilliseconds;
}

/*==========================================================================*/
void GSP::s_MarketDataSnapshot::SetLastTradeMilliseconds(short NewValue)
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

/*==========================================================================*/
unsigned short GSP::s_FundamentalDataResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_FundamentalDataResponse::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_FundamentalDataResponse), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_FundamentalDataResponse::GetMarketDataSymbolID()
{
	return MarketDataSymbolID;
}

/*==========================================================================*/
void GSP::s_FundamentalDataResponse::SetMarketDataSymbolID(unsigned short NewValue)
{
	MarketDataSymbolID = NewValue;
}

/*==========================================================================*/
char * GSP::s_FundamentalDataResponse::GetSymbolDescription()
{
	SymbolDescription[sizeof(SymbolDescription) - 1 ] = '\0';
	return SymbolDescription;
}

/*==========================================================================*/
void GSP::s_FundamentalDataResponse::SetSymbolDescription(const char * NewValue)
{
	strncpy(SymbolDescription, NewValue, sizeof(SymbolDescription) - 1);
}

/*==========================================================================*/
float GSP::s_FundamentalDataResponse::GetTickSize()
{
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
	if (TickSize== 0.0 && DisplayFormat == GSP:: DISPLAY_FORMAT_UNSET)
	{
		DisplayFormat  = GSP::DISPLAY_FORMAT_DECIMAL_3;
		return;
	}


	if (TickSize < 0.00000995)
		DisplayFormat  = GSP::DISPLAY_FORMAT_DECIMAL_6;
	else if (TickSize < 0.0000995)
		DisplayFormat  = GSP::DISPLAY_FORMAT_DECIMAL_5;
	else if (TickSize < 0.000995)
		DisplayFormat  = GSP::DISPLAY_FORMAT_DECIMAL_4;
	else if (TickSize > 0.00249  && TickSize < 0.00251)
	{
		DisplayFormat  = GSP::DISPLAY_FORMAT_DECIMAL_4;
	}
	else if (TickSize < 0.00995)
	{
		if (TickSize > 0.00390620  && TickSize < 0.00390630)  //== 0.00390625)
			DisplayFormat  = GSP::DISPLAY_FORMAT_DENOMINATOR_256;
		else if (TickSize > 0.0078120 && TickSize < 0.0078130)  //.25/32 =0.0078125
			DisplayFormat  = GSP::DISPLAY_FORMAT_DENOMINATOR_32_QUARTERS;
		else
			DisplayFormat  = GSP::DISPLAY_FORMAT_DECIMAL_3;
	}
	else if (TickSize < 0.0995)
	{
		if (TickSize > .0249 &&  TickSize < .0251)
			DisplayFormat  = GSP::DISPLAY_FORMAT_DECIMAL_3;
		else if (TickSize > 0.015620 && TickSize < 0.015630)  // .5/32 =0.015625
			DisplayFormat  = GSP::DISPLAY_FORMAT_DENOMINATOR_32_HALVES;
		else if (TickSize > 0.03120 && TickSize < 0.03130)  //1/32 = 0.03125 
			DisplayFormat  = GSP::DISPLAY_FORMAT_DENOMINATOR_32;
		else if (TickSize > 0.0620 && TickSize < 0.0630)  //== 0.0625)
			DisplayFormat  = GSP::DISPLAY_FORMAT_DENOMINATOR_16;
		else
			DisplayFormat  = GSP::DISPLAY_FORMAT_DECIMAL_2;
	}
	else if (TickSize < .995)
	{
		if (TickSize > 0.120 && TickSize < 0.130)  //== 0.125)
			DisplayFormat  = GSP::DISPLAY_FORMAT_DENOMINATOR_8;
		else
			DisplayFormat  = GSP::DISPLAY_FORMAT_DECIMAL_1;
	}
	else
		DisplayFormat  = GSP::DISPLAY_FORMAT_DECIMAL_0;
}


/*==========================================================================*/
unsigned short GSP::s_TradeIncrementalUpdateWithFullDepth::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_TradeIncrementalUpdateWithFullDepth::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_TradeIncrementalUpdateWithFullDepth), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_MarketDepthFullUpdate::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDepthFullUpdate::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_MarketDepthFullUpdate), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_MarketDepthFullUpdate::GetMarketDataSymbolID()
{
	return MarketDataSymbolID;
}

/*==========================================================================*/
void GSP::s_MarketDepthFullUpdate::SetMarketDataSymbolID(unsigned short NewValue)
{
	MarketDataSymbolID = NewValue;
}

/*==========================================================================*/
unsigned short GSP::s_MarketDepthFullUpdateLarge::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDepthFullUpdateLarge::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_MarketDepthFullUpdateLarge), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_MarketDepthIncrementalUpdate::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_MarketDepthIncrementalUpdate::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_MarketDepthIncrementalUpdate), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_TradeIncrementalUpdate::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_TradeIncrementalUpdate::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_TradeIncrementalUpdate), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_QuoteIncrementalUpdate::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_QuoteIncrementalUpdate::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_QuoteIncrementalUpdate), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_TradeIncrementalUpdateCompact::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_TradeIncrementalUpdateCompact::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_TradeIncrementalUpdateCompact), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_DailyVolumeIncrementalUpdate::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_DailyVolumeIncrementalUpdate::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_DailyVolumeIncrementalUpdate), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_DailyHighIncrementalUpdate::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_DailyHighIncrementalUpdate::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_DailyHighIncrementalUpdate), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_DailyLowIncrementalUpdate::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_DailyLowIncrementalUpdate::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_DailyLowIncrementalUpdate), Size) );
}

/*==========================================================================*/
char * GSP::s_OrderUpdateReport::GetSymbol()
{
	Symbol[sizeof(Symbol) - 1 ] = '\0';
	return Symbol;
}

/*==========================================================================*/
unsigned short GSP::s_SubmitNewSingleOrder::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_SubmitNewSingleOrder::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_SubmitNewSingleOrder), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_CancelReplaceOrder::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_CancelReplaceOrder::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_CancelReplaceOrder), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_CancelReplaceOrder2::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_CancelReplaceOrder2::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_CancelReplaceOrder2), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_CancelOrder::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_CancelOrder::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_CancelOrder), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_SubmitNewOCOOrder::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_SubmitNewOCOOrder::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_SubmitNewOCOOrder), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_OpenOrdersRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_OpenOrdersRequest::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_OpenOrdersRequest), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_RequestHistoricalOrderFills::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_RequestHistoricalOrderFills::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_RequestHistoricalOrderFills), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_CurrentPositionsRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_CurrentPositionsRequest::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_CurrentPositionsRequest), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_CurrentPositionsRequestReject::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_CurrentPositionsRequestReject::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_CurrentPositionsRequestReject), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_OrderUpdateReport::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_OrderUpdateReport), Size) );
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetSymbol(const char * NewValue)
{
	strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
}

/*==========================================================================*/
char * GSP::s_OrderUpdateReport::GetExchange()
{
	Exchange[sizeof(Exchange) - 1 ] = '\0';
	return Exchange;
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetExchange(const char * NewValue)
{
	strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
}
/*==========================================================================*/
char * GSP::s_OrderUpdateReport::GetPreviousServerOrderID()
{
	PreviousServerOrderID[sizeof(PreviousServerOrderID) - 1 ] = '\0';
	return PreviousServerOrderID;
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetPreviousServerOrderID(const char * NewValue)
{
	strncpy(PreviousServerOrderID, NewValue, sizeof(PreviousServerOrderID) - 1);
}

/*==========================================================================*/
char * GSP::s_OrderUpdateReport::GetServerOrderID()
{
	ServerOrderID[sizeof(ServerOrderID) - 1 ] = '\0';
	return ServerOrderID;
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetServerOrderID(const char * NewValue)
{
	strncpy(ServerOrderID, NewValue, sizeof(ServerOrderID) - 1);
}

/*==========================================================================*/
char * GSP::s_OrderUpdateReport::GetClientOrderID()
{
	ClientOrderID[sizeof(ClientOrderID) - 1 ] = '\0';
	return ClientOrderID;
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetClientOrderID(const char * NewValue)
{
	strncpy(ClientOrderID, NewValue, sizeof(ClientOrderID) - 1);
}

/*==========================================================================*/
char * GSP::s_OrderUpdateReport::GetExchangeOrderID()
{
	ExchangeOrderID[sizeof(ExchangeOrderID) - 1 ] = '\0';
	return ExchangeOrderID;
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetExchangeOrderID(const char * NewValue)
{
	strncpy(ExchangeOrderID, NewValue, sizeof(ExchangeOrderID) - 1);
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetUniqueFillExecutionID(const char * NewValue)
{
	strncpy(UniqueFillExecutionID, NewValue, sizeof(UniqueFillExecutionID) - 1);
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetTradeAccount(const char * NewValue)
{
	strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
}

/*==========================================================================*/
void GSP::s_OrderUpdateReport::SetInfoText(const char * NewValue)
{
	strncpy(InfoText, NewValue, sizeof(InfoText) - 1);
}

/*==========================================================================*/
unsigned short GSP::s_OpenOrdersRequestReject::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_OpenOrdersRequestReject::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_OpenOrdersRequestReject), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_HistoricalOrderFillReport::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_HistoricalOrderFillReport::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_HistoricalOrderFillReport), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_PositionReport::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_PositionReport::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_PositionReport), Size) );
}

/*==========================================================================*/
void GSP::s_PositionReport::SetSymbol(const char * NewValue)
{
	strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
}

/*==========================================================================*/
void GSP::s_PositionReport::SetTradeAccount(const char * NewValue)
{
	strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
}

/*==========================================================================*/
unsigned short GSP::s_RequestAccounts::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_RequestAccounts::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_RequestAccounts), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_AccountsListResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_AccountsListResponse::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_AccountsListResponse), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_ExchangeListRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_ExchangeListRequest::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_ExchangeListRequest), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_ExchangeListResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_ExchangeListResponse::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_ExchangeListResponse), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_SymbolsForExchangeRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_SymbolsForExchangeRequest::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_SymbolsForExchangeRequest), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_UnderlyingSymbolsForExchangeRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_UnderlyingSymbolsForExchangeRequest::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_UnderlyingSymbolsForExchangeRequest), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_SymbolsForUnderlyingRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_SymbolsForUnderlyingRequest::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_SymbolsForUnderlyingRequest), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_SecurityDefinitionForSymbolRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_SecurityDefinitionForSymbolRequest::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_SecurityDefinitionForSymbolRequest), Size) );
}

/*==========================================================================
unsigned short GSP::s_SymbolResponse::GetMessageSize()
{
	return Size;
}

void GSP::s_SymbolResponse::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_SymbolResponse), Size) );
}

==========================================================================*/
unsigned short GSP::s_SecurityDefinitionResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_SecurityDefinitionResponse::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_SecurityDefinitionResponse), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_AccountBalanceUpdate::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_AccountBalanceUpdate::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_AccountBalanceUpdate), Size) );
}

/*==========================================================================*/
void GSP::s_AccountBalanceUpdate::SetAccountCurrency(const char * NewValue)
{
	strncpy(AccountCurrency, NewValue, sizeof(AccountCurrency) - 1);
}

/*==========================================================================*/
void GSP::s_AccountBalanceUpdate::SetTradeAccount(const char * NewValue)
{
	strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
}

/*==========================================================================*/
unsigned short GSP::s_UserMessage::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_UserMessage::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_UserMessage), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_GeneralLogMessage::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_GeneralLogMessage::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_GeneralLogMessage), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_HistoricalPriceDataRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_HistoricalPriceDataRequest::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_HistoricalPriceDataRequest), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_HistoricalPriceDataHeaderResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_HistoricalPriceDataHeaderResponse::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_HistoricalPriceDataHeaderResponse), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_HistoricalPriceDataReject::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_HistoricalPriceDataReject::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_HistoricalPriceDataReject), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_HistoricalPriceDataRecordResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_HistoricalPriceDataRecordResponse::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_HistoricalPriceDataRecordResponse), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_HistoricalPriceDataTickRecordResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_HistoricalPriceDataTickRecordResponse::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_HistoricalPriceDataTickRecordResponse), Size) );
}

/*==========================================================================*/
unsigned short GSP::s_ConfigurationRequestFromClient::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_ConfigurationRequestFromClient::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_ConfigurationRequestFromClient), Size) );
}

/*==========================================================================*/
int GSP::s_ServerReadyToReceive::GetProtocolVersion()
{
	return ProtocolVersion;
}

/*==========================================================================*/
unsigned short GSP::s_ServerReadyToReceive::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
void GSP::s_ServerReadyToReceive::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_ServerReadyToReceive), Size) );
}

/*==========================================================================*/
char * GSP::s_ServerReadyToReceive::GetServerName()
{
	ServerName[sizeof(ServerName) - 1 ] = '\0';
	return ServerName;
}

/*==========================================================================*/
void GSP::s_ServerReadyToReceive::SetServerName(const char * NewValue)
{
	strncpy(ServerName, NewValue, sizeof(ServerName) - 1);
}

/*==========================================================================*/
char * GSP::s_ServerReadyToReceive::GetServerVersion()
{
	ServerVersion[sizeof(ServerVersion) - 1 ] = '\0';
	return ServerVersion;
}

/*==========================================================================*/
void GSP::s_ServerReadyToReceive::SetServerVersion(const char * NewValue)
{
	strncpy(ServerVersion, NewValue, sizeof(ServerVersion) - 1);
}

/*==========================================================================*/
char * GSP::s_ServerReadyToReceive::GetServiceProviderName()
{
	ServiceProviderName[sizeof(ServiceProviderName) - 1 ] = '\0';
	return ServiceProviderName;
}

/*==========================================================================*/
void GSP::s_ServerReadyToReceive::SetServiceProviderName(const char * NewValue)
{
	strncpy(ServiceProviderName, NewValue, sizeof(ServiceProviderName) - 1);
}

/*==========================================================================*/
