#pragma unmanaged

#include <float.h>
#include <limits.h>
#include <string.h>
#include <memory.h> 
#include <stddef.h>

#include "DTCProtocolVLS.h"


#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif


namespace DTC_VLS
{

	/****************************************************************************/
	// s_LogonRequest

	/*============================================================================
	Will get the size of the message received over the network
	----------------------------------------------------------------------------*/
	uint16_t s_LogonRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_LogonRequest::GetProtocolVersion()
	{
		if (Size < offsetof(s_LogonRequest, ProtocolVersion) + sizeof(ProtocolVersion))
			return 0;

		return ProtocolVersion;
	}

	/*==========================================================================*/
	int32_t s_LogonRequest::GetInteger_1()
	{
		if (Size < offsetof(s_LogonRequest, Integer_1) + sizeof(Integer_1))
			return 0;

		return Integer_1;
	}
	
	/*==========================================================================*/
	int32_t s_LogonRequest::GetInteger_2()
	{
		if (Size < offsetof(s_LogonRequest, Integer_2) + sizeof(Integer_2))
			return 0;

		return Integer_2;
	}

	/*==========================================================================*/
	int32_t s_LogonRequest::GetHeartbeatIntervalInSeconds()
	{
		if (Size < offsetof(s_LogonRequest, HeartbeatIntervalInSeconds) + sizeof(HeartbeatIntervalInSeconds))
			return 0;

		return HeartbeatIntervalInSeconds;
	}

	/*==========================================================================*/
	DTC::TradeModeEnum s_LogonRequest::GetTradeMode()
	{
		if (Size < offsetof(s_LogonRequest, TradeMode) + sizeof(TradeMode))
			return (DTC::TradeModeEnum)0;

		return TradeMode;
	}

	/****************************************************************************/
	// s_LogonResponse

	/*==========================================================================*/
	uint16_t s_LogonResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_LogonResponse::GetProtocolVersion()
	{
		if (Size < offsetof(s_LogonResponse, ProtocolVersion) + sizeof(ProtocolVersion))
			return 0;

		return ProtocolVersion;
	}

	/*==========================================================================*/
	DTC::LogonStatusEnum s_LogonResponse::GetResult()
	{
		if (Size < offsetof(s_LogonResponse, Result) + sizeof(Result))
			return (DTC::LogonStatusEnum)0;

		return Result;
	}
	
	/*==========================================================================*/
	int32_t s_LogonResponse::GetInteger_1()
	{
		if (Size < offsetof(s_LogonResponse, Integer_1) + sizeof(Integer_1))
			return 0;

		return Integer_1;
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
	byte s_LogonResponse::GetOrderCancelReplaceSupported()
	{
		if (Size < offsetof(s_LogonResponse, OrderCancelReplaceSupported) + sizeof(OrderCancelReplaceSupported))
			return 0;

		return OrderCancelReplaceSupported;
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
	byte s_LogonResponse::GetResubscribeWhenMarketDataFeedAvailable()
	{
		if (Size < offsetof(s_LogonResponse, ResubscribeWhenMarketDataFeedAvailable) + sizeof(ResubscribeWhenMarketDataFeedAvailable))
			return 0;

		return ResubscribeWhenMarketDataFeedAvailable;
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

	/*==========================================================================*/
	byte s_LogonResponse::GetBracketOrdersSupported()
	{
		if (Size < offsetof(s_LogonResponse, BracketOrdersSupported) + sizeof(BracketOrdersSupported))
			return 0;

		return BracketOrdersSupported;
	}
	
	/****************************************************************************/
	// s_LogoffRequest

	/*==========================================================================*/
	uint16_t s_Logoff::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	byte s_Logoff::GetDoNotReconnect()
	{
		if (Size < offsetof(s_Logoff, DoNotReconnect) + sizeof(DoNotReconnect))
			return false;

		return DoNotReconnect;
	}


	/****************************************************************************/
	// s_MarketDataRequest

	/*==========================================================================*/
	uint16_t s_MarketDataRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	DTC::RequestActionEnum s_MarketDataRequest::GetRequestAction()
	{
		if (Size < offsetof(s_MarketDataRequest, RequestAction) + sizeof(RequestAction))
			return (DTC::RequestActionEnum)0;

		return RequestAction;
	}

	/*==========================================================================*/
	uint16_t s_MarketDataRequest::GetSymbolID()
	{
		if (Size < offsetof(s_MarketDataRequest, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/****************************************************************************/
	// s_MarketDepthRequest

	/*==========================================================================*/
	uint16_t s_MarketDepthRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	DTC::RequestActionEnum s_MarketDepthRequest::GetRequestAction()
	{
		if (Size < offsetof(s_MarketDepthRequest, RequestAction) + sizeof(RequestAction))
			return (DTC::RequestActionEnum)0;

		return RequestAction;
	}

	/*==========================================================================*/
	uint16_t s_MarketDepthRequest::GetSymbolID()
	{
		if (Size < offsetof(s_MarketDepthRequest, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	int32_t s_MarketDepthRequest::GetNumLevels()
	{
		if (Size < offsetof(s_MarketDepthRequest, NumLevels) + sizeof(NumLevels))
			return 0;

		return NumLevels;
	}


	/****************************************************************************/
	// s_MarketDataReject

	/*==========================================================================*/
	uint16_t s_MarketDataReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_MarketDataReject::GetSymbolID()
	{
		if (Size < offsetof(s_MarketDataReject, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/****************************************************************************/
	// s_MarketDepthReject

	/*==========================================================================*/
	uint16_t s_MarketDepthReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_MarketDepthReject::GetSymbolID()
	{
		if (Size < offsetof(s_MarketDepthReject, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}


	/****************************************************************************/
	// s_FundamentalDataRequest

	/*==========================================================================*/
	uint16_t s_FundamentalDataRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_FundamentalDataRequest::GetSymbolID()
	{
		if (Size < offsetof(s_FundamentalDataRequest, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}


	/****************************************************************************/
	// s_FundamentalDataResponse

	/*==========================================================================*/
	uint16_t s_FundamentalDataResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_FundamentalDataResponse::GetSymbolID()
	{
		if (Size < offsetof(s_FundamentalDataResponse, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	float s_FundamentalDataResponse::GetMinPriceIncrement()
	{
		if (Size < offsetof(s_FundamentalDataResponse, MinPriceIncrement) + sizeof(MinPriceIncrement))
			return 0;

		return MinPriceIncrement;
	}


	/*==========================================================================*/
	float s_FundamentalDataResponse::GetCurrencyValuePerIncrement()
	{
		if (Size < offsetof(s_FundamentalDataResponse, CurrencyValuePerIncrement) + sizeof(CurrencyValuePerIncrement))
			return 0;

		return CurrencyValuePerIncrement;
	}


	/*==========================================================================*/
	DTC::PriceDisplayFormatEnum s_FundamentalDataResponse::GetPriceDisplayFormat()
	{
		if (Size < offsetof(s_FundamentalDataResponse, PriceDisplayFormat) + sizeof(PriceDisplayFormat))
			return (DTC::PriceDisplayFormatEnum)0;

		return PriceDisplayFormat;
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
	float s_FundamentalDataResponse::GetOrderIntPriceMultiplier(){
		if (Size < offsetof(s_FundamentalDataResponse, OrderIntPriceMultiplier) + sizeof(OrderIntPriceMultiplier))
			return 0;

		return OrderIntPriceMultiplier;
	}

	/*==========================================================================*/
	float s_FundamentalDataResponse::GetMarketDataIntPriceDivisor()
	{
		if (Size < offsetof(s_FundamentalDataResponse, MarketDataIntPriceDivisor) + sizeof(MarketDataIntPriceDivisor))
			return 0;

		return MarketDataIntPriceDivisor;
	}

	/*==========================================================================*/
	DTC::SecurityTypeEnum s_FundamentalDataResponse::GetSecurityType()
	{
		if (Size < offsetof(s_FundamentalDataResponse, SecurityType) + sizeof(SecurityType))
			return DTC::SECURITY_TYPE_UNSET;

		return static_cast<DTC::SecurityTypeEnum>(SecurityType);
	}

	/*==========================================================================*/
	DTC::t_DateTime4Byte s_FundamentalDataResponse::GetSecurityExpirationDate()
	{
		if (Size < offsetof(s_FundamentalDataResponse, SecurityExpirationDate) + sizeof(SecurityExpirationDate))
			return 0;

		return SecurityExpirationDate;
	}

	/*==========================================================================*/
	uint16_t s_FundamentalDataResponse::GetShortInterest()
	{
		if (Size < offsetof(s_FundamentalDataResponse, ShortInterest) + sizeof(ShortInterest))
			return 0;

		return ShortInterest;
	}

	/*==========================================================================*/
	float s_FundamentalDataResponse::GetEarningsPerShare()
	{
		if (Size < offsetof(s_FundamentalDataResponse, EarningsPerShare) + sizeof(EarningsPerShare))
			return 0;

		return EarningsPerShare;
	}

	/*==========================================================================*/
	float s_FundamentalDataResponse::GetDividendYield()
	{
		if (Size < offsetof(s_FundamentalDataResponse, DividendYield) + sizeof(DividendYield))
			return 0;

		return DividendYield;
	}

	/*==========================================================================*/
	float s_FundamentalDataResponse::GetDividendAmount()
	{
		if (Size < offsetof(s_FundamentalDataResponse, DividendAmount) + sizeof(DividendAmount))
			return 0;

		return DividendAmount;
	}

	/*==========================================================================*/
	DTC::t_DateTime4Byte s_FundamentalDataResponse::GetExDividendDate()
	{
		if (Size < offsetof(s_FundamentalDataResponse, ExDividendDate) + sizeof(ExDividendDate))
			return 0;

		return ExDividendDate;
	}

	/*==========================================================================*/
	float s_FundamentalDataResponse::GetStrikePrice()
	{
		if (Size < offsetof(s_FundamentalDataResponse, StrikePrice) + sizeof(StrikePrice))
			return 0;

		return StrikePrice;
	}


	/****************************************************************************/
	// s_SubmitNewSingleOrder

	/*==========================================================================*/
	uint16_t s_SubmitNewSingleOrder::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	DTC::OrderTypeEnum s_SubmitNewSingleOrder::GetOrderType()
	{			
		if (Size < offsetof(s_SubmitNewSingleOrder, OrderType) + sizeof(OrderType))
			return DTC::ORDER_TYPE_UNSET;

		return OrderType;	
	}

	/*==========================================================================*/
	DTC::BuySellEnum s_SubmitNewSingleOrder::GetBuySell()
	{			
		if (Size < offsetof(s_SubmitNewSingleOrder, BuySell) + sizeof(BuySell))
			return DTC::BUY_SELL_UNSET;

		return BuySell;	
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
	double s_SubmitNewSingleOrder::GetQuantity()
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, Quantity) + sizeof(Quantity))
			return DBL_MAX;

		return Quantity;
	}

	/*==========================================================================*/
	DTC::TimeInForceEnum s_SubmitNewSingleOrder::GetTimeInForce()
	{			
		if (Size < offsetof(s_SubmitNewSingleOrder, TimeInForce) + sizeof(TimeInForce))
			return DTC::TIF_UNSET;

		return TimeInForce;	
	}

	/*==========================================================================*/	 
	DTC::t_DateTime s_SubmitNewSingleOrder::GetGoodTillDateTime() 
	{
		if (Size < offsetof(s_SubmitNewSingleOrder, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
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


	/****************************************************************************/
	// s_SubmitNewSingleOrderInt

	/*==========================================================================*/
	uint16_t s_SubmitNewSingleOrderInt::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	DTC::OrderTypeEnum s_SubmitNewSingleOrderInt::GetOrderType()
	{			
		if (Size < offsetof(s_SubmitNewSingleOrderInt, OrderType) + sizeof(OrderType))
			return DTC::ORDER_TYPE_UNSET;

		return OrderType;	
	}

	/*==========================================================================*/
	DTC::BuySellEnum s_SubmitNewSingleOrderInt::GetBuySell()
	{			
		if (Size < offsetof(s_SubmitNewSingleOrderInt, BuySell) + sizeof(BuySell))
			return DTC::BUY_SELL_UNSET;

		return BuySell;	
	}
	
	/*==========================================================================*/
	int32_t s_SubmitNewSingleOrderInt::GetPrice1()
	{
		if (Size < offsetof(s_SubmitNewSingleOrderInt, Price1) + sizeof(Price1))
			return 0;

		return Price1;
	}

	/*==========================================================================*/
	int32_t s_SubmitNewSingleOrderInt::GetPrice2()
	{
		if (Size < offsetof(s_SubmitNewSingleOrderInt, Price2) + sizeof(Price2))
			return 0;

		return Price2;
	}

	/*==========================================================================*/
	float s_SubmitNewSingleOrderInt::GetDivisor()
	{
		if (Size < offsetof(s_SubmitNewSingleOrderInt, Divisor) + sizeof(Divisor))
			return 0.0;

		return Divisor;
	}

	/*==========================================================================*/
	double s_SubmitNewSingleOrderInt::GetQuantity()
	{
		if (Size < offsetof(s_SubmitNewSingleOrderInt, Quantity) + sizeof(Quantity))
			return DBL_MAX;

		return Quantity;
	}

	/*==========================================================================*/
	DTC::TimeInForceEnum s_SubmitNewSingleOrderInt::GetTimeInForce()
	{			
		if (Size < offsetof(s_SubmitNewSingleOrderInt, TimeInForce) + sizeof(TimeInForce))
			return DTC::TIF_UNSET;

		return TimeInForce;	
	}

	/*==========================================================================*/	 
	DTC::t_DateTime s_SubmitNewSingleOrderInt::GetGoodTillDateTime() 
	{
		if (Size < offsetof(s_SubmitNewSingleOrderInt, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
	}

	/*==========================================================================*/
	byte s_SubmitNewSingleOrderInt::GetIsAutomatedOrder()
	{
		if (Size < offsetof(s_SubmitNewSingleOrderInt, IsAutomatedOrder) + sizeof(IsAutomatedOrder))
			return 0;

		return IsAutomatedOrder;
	}

	/*==========================================================================*/
	byte s_SubmitNewSingleOrderInt::GetIsParentOrder()
	{
		if (Size < offsetof(s_SubmitNewSingleOrderInt, IsParentOrder) + sizeof(IsParentOrder))
			return 0;

		return IsParentOrder;
	}


	/****************************************************************************/
	// s_CancelReplaceOrder

	/*==========================================================================*/
	uint16_t s_CancelReplaceOrder::GetMessageSize()
	{
		return Size;
	}

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
	double s_CancelReplaceOrder::GetQuantity()
	{
		if (Size < offsetof(s_CancelReplaceOrder, Quantity) + sizeof(Quantity))
			return DBL_MAX;

		return Quantity;
	}

	/****************************************************************************/
	// s_CancelReplaceOrderInt

	/*==========================================================================*/
	uint16_t s_CancelReplaceOrderInt::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_CancelReplaceOrderInt::GetPrice1()
	{
		if (Size < offsetof(s_CancelReplaceOrderInt, Price1) + sizeof(Price1))
			return 0;

		return Price1;
	}

	/*==========================================================================*/
	int32_t s_CancelReplaceOrderInt::GetPrice2()
	{
		if (Size < offsetof(s_CancelReplaceOrderInt, Price2) + sizeof(Price2))
			return 0;

		return Price2;
	}

	/*==========================================================================*/
	float s_CancelReplaceOrderInt::GetDivisor()
	{
		if (Size < offsetof(s_CancelReplaceOrderInt, Divisor) + sizeof(Divisor))
			return 0.0;

		return Divisor;
	}

	/*==========================================================================*/
	double s_CancelReplaceOrderInt::GetQuantity()
	{
		if (Size < offsetof(s_CancelReplaceOrderInt, Quantity) + sizeof(Quantity))
			return DBL_MAX;

		return Quantity;
	}



	/****************************************************************************/
	// s_CancelOrder

	/*==========================================================================*/
	uint16_t s_CancelOrder::GetMessageSize()
	{
		return Size;
	}

	/****************************************************************************/
	// s_SubmitNewOCOOrder

	/*==========================================================================*/
	uint16_t s_SubmitNewOCOOrder::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	DTC::OrderTypeEnum s_SubmitNewOCOOrder::GetOrderType_1()
	{			
		if (Size < offsetof(s_SubmitNewOCOOrder, OrderType_1) + sizeof(OrderType_1))
			return DTC::ORDER_TYPE_UNSET;

		return OrderType_1;	
	}

	/*==========================================================================*/
	DTC::OrderTypeEnum s_SubmitNewOCOOrder::GetOrderType_2()
	{			
		if (Size < offsetof(s_SubmitNewOCOOrder, OrderType_2) + sizeof(OrderType_2))
			return DTC::ORDER_TYPE_UNSET;

		return OrderType_2;	
	}

	/*==========================================================================*/			 
	DTC::BuySellEnum s_SubmitNewOCOOrder::GetBuySell_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, BuySell_1) + sizeof(BuySell_1))
			return (DTC::BuySellEnum)0;

		return BuySell_1;
	}

	/*==========================================================================*/
	DTC::BuySellEnum s_SubmitNewOCOOrder::GetBuySell_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, BuySell_2) + sizeof(BuySell_2))
			return (DTC::BuySellEnum)0;

		return BuySell_2;
	}

	/*==========================================================================*/
	DTC::TimeInForceEnum s_SubmitNewOCOOrder::GetTimeInForce()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, TimeInForce) + sizeof(TimeInForce))
			return (DTC::TimeInForceEnum)0;

		return TimeInForce;
	}

	/*==========================================================================*/
	DTC::t_DateTime s_SubmitNewOCOOrder::GetGoodTillDateTime() 
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
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
	double s_SubmitNewOCOOrder::GetQuantity_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Quantity_1) + sizeof(Quantity_1))
			return DBL_MAX;

		return Quantity_1;
	}

	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetQuantity_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrder, Quantity_2) + sizeof(Quantity_2))
			return DBL_MAX;

		return Quantity_2;
	}


	/****************************************************************************/
	// s_SubmitNewOCOOrderInt

	/*==========================================================================*/
	uint16_t s_SubmitNewOCOOrderInt::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	DTC::OrderTypeEnum s_SubmitNewOCOOrderInt::GetOrderType_1()
	{			
		if (Size < offsetof(s_SubmitNewOCOOrderInt, OrderType_1) + sizeof(OrderType_1))
			return DTC::ORDER_TYPE_UNSET;

		return OrderType_1;	
	}

	/*==========================================================================*/
	DTC::OrderTypeEnum s_SubmitNewOCOOrderInt::GetOrderType_2()
	{			
		if (Size < offsetof(s_SubmitNewOCOOrderInt, OrderType_2) + sizeof(OrderType_2))
			return DTC::ORDER_TYPE_UNSET;

		return OrderType_2;	
	}

	/*==========================================================================*/			 
	DTC::BuySellEnum s_SubmitNewOCOOrderInt::GetBuySell_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, BuySell_1) + sizeof(BuySell_1))
			return (DTC::BuySellEnum)0;

		return BuySell_1;
	}

	/*==========================================================================*/
	DTC::BuySellEnum s_SubmitNewOCOOrderInt::GetBuySell_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, BuySell_2) + sizeof(BuySell_2))
			return (DTC::BuySellEnum)0;

		return BuySell_2;
	}

	/*==========================================================================*/
	DTC::TimeInForceEnum s_SubmitNewOCOOrderInt::GetTimeInForce()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, TimeInForce) + sizeof(TimeInForce))
			return (DTC::TimeInForceEnum)0;

		return TimeInForce;
	}

	/*==========================================================================*/
	DTC::t_DateTime s_SubmitNewOCOOrderInt::GetGoodTillDateTime() 
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
	}	

	/*==========================================================================*/
	byte s_SubmitNewOCOOrderInt::GetIsAutomatedOrder()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, IsAutomatedOrder) + sizeof(IsAutomatedOrder))
			return 0;

		return IsAutomatedOrder;
	}

	/*==========================================================================*/
	int32_t s_SubmitNewOCOOrderInt::GetPrice1_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, Price1_1) + sizeof(Price1_1))
			return 0;

		return Price1_1;
	}
	
	/*==========================================================================*/
	int32_t s_SubmitNewOCOOrderInt::GetPrice2_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, Price2_1) + sizeof(Price2_1))
			return 0;

		return Price2_1;
	}
	
	/*==========================================================================*/
	int32_t s_SubmitNewOCOOrderInt::GetPrice1_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, Price1_2) + sizeof(Price1_2))
			return 0;

		return Price1_2;
	}
	
	/*==========================================================================*/
	int32_t s_SubmitNewOCOOrderInt::GetPrice2_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, Price2_2) + sizeof(Price2_2))
			return 0;

		return Price2_2;
	}

	/*==========================================================================*/
	double s_SubmitNewOCOOrderInt::GetQuantity_1()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, Quantity_1) + sizeof(Quantity_1))
			return DBL_MAX;

		return Quantity_1;
	}

	/*==========================================================================*/
	double s_SubmitNewOCOOrderInt::GetQuantity_2()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, Quantity_2) + sizeof(Quantity_2))
			return DBL_MAX;

		return Quantity_2;
	}

	/*==========================================================================*/
	float s_SubmitNewOCOOrderInt::GetDivisor()
	{
		if (Size < offsetof(s_SubmitNewOCOOrderInt, Divisor) + sizeof(Divisor))
			return 0.0;

		return Divisor;
	}


	/****************************************************************************/
	// s_OpenOrdersRequest

	/*==========================================================================*/
	uint16_t s_OpenOrdersRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_OpenOrdersRequest::GetRequestID()
	{
		if (Size < offsetof(s_OpenOrdersRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	int32_t s_OpenOrdersRequest::GetRequestAllOrders()
	{
		if (Size < offsetof(s_OpenOrdersRequest, RequestAllOrders) + sizeof(RequestAllOrders))
			return 0;

		return RequestAllOrders;
	}



	/****************************************************************************/
	// s_HistoricalOrderFillsRequest

	/*==========================================================================*/
	uint16_t s_HistoricalOrderFillsRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_HistoricalOrderFillsRequest::GetRequestID()
	{
		if (Size < offsetof(s_HistoricalOrderFillsRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	int32_t s_HistoricalOrderFillsRequest::GetNumberOfDays()
	{
		if (Size < offsetof(s_HistoricalOrderFillsRequest, NumberOfDays) + sizeof(NumberOfDays))
			return 0;

		return NumberOfDays;
	}


	/****************************************************************************/
	// s_CurrentPositionsRequest

	/*==========================================================================*/
	uint16_t s_CurrentPositionsRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_CurrentPositionsRequest::GetRequestID()
	{
		if (Size < offsetof(s_CurrentPositionsRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}


	/****************************************************************************/
	// s_CurrentPositionsRequestReject

	/*==========================================================================*/
	uint16_t s_CurrentPositionsReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_CurrentPositionsReject::GetRequestID()
	{
		if (Size < offsetof(s_CurrentPositionsReject, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}


	/****************************************************************************/
	// s_OrderUpdateReport

	/*==========================================================================*/
	uint16_t s_OrderUpdate::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	double s_OrderUpdate::GetOrderQuantity()
	{
		if (Size < offsetof(s_OrderUpdate, OrderQuantity) + sizeof(OrderQuantity))
			return DBL_MAX;

		return OrderQuantity;
	}

	/*==========================================================================*/
	double s_OrderUpdate::GetFilledQuantity()
	{
		if (Size < offsetof(s_OrderUpdate, FilledQuantity) + sizeof(FilledQuantity))
			return DBL_MAX;

		return FilledQuantity;
	}

	/*==========================================================================*/
	double s_OrderUpdate::GetRemainingQuantity()
	{
		if (Size < offsetof(s_OrderUpdate, RemainingQuantity) + sizeof(RemainingQuantity))
			return DBL_MAX;

		return RemainingQuantity;
	}

	/*==========================================================================*/
	double s_OrderUpdate::GetLastFillQuantity()
	{
		if (Size < offsetof(s_OrderUpdate, LastFillQuantity) + sizeof(LastFillQuantity))
			return DBL_MAX;

		return LastFillQuantity;
	}
	
	/*==========================================================================*/
	int32_t s_OrderUpdate::GetRequestID()
	{
		if (Size < offsetof(s_OrderUpdate, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	
	/*==========================================================================*/
	int32_t s_OrderUpdate::GetTotalNumMessages()
	{
		if (Size < offsetof(s_OrderUpdate, TotalNumMessages) + sizeof(TotalNumMessages))
			return 0;

		return TotalNumMessages;
	}

	/*==========================================================================*/
	int32_t s_OrderUpdate::GetMessageNumber()
	{
		if (Size < offsetof(s_OrderUpdate, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}
	
	/*==========================================================================*/
	DTC::OrderStatusEnum s_OrderUpdate::GetOrderStatus()
	{
		if (Size < offsetof(s_OrderUpdate, OrderStatus) + sizeof(OrderStatus))
			return (DTC::OrderStatusEnum)0;

		return OrderStatus;
	}
	
	/*==========================================================================*/
	DTC::OrderUpdateReasonEnum s_OrderUpdate::GetOrderUpdateReason()
	{
		if (Size < offsetof(s_OrderUpdate, OrderUpdateReason) + sizeof(OrderUpdateReason))
			return (DTC::OrderUpdateReasonEnum)0;

		return OrderUpdateReason;
	}
	
	/*==========================================================================*/
	DTC::OrderTypeEnum s_OrderUpdate::GetOrderType()
	{
		if (Size < offsetof(s_OrderUpdate, OrderType) + sizeof(OrderType))
			return (DTC::OrderTypeEnum)0;

		return OrderType;
	}
	
	/*==========================================================================*/
	DTC::BuySellEnum s_OrderUpdate::GetBuySell()
	{
		if (Size < offsetof(s_OrderUpdate, BuySell) + sizeof(BuySell))
			return (DTC::BuySellEnum)0;

		return BuySell;
	}
	
	/*==========================================================================*/
	double s_OrderUpdate::GetPrice1()
	{
		if (Size < offsetof(s_OrderUpdate, Price1) + sizeof(Price1))
			return DBL_MAX;

		return Price1;
	}
	
	/*==========================================================================*/
	double s_OrderUpdate::GetPrice2()
	{
		if (Size < offsetof(s_OrderUpdate, Price2) + sizeof(Price2))
			return DBL_MAX;

		return Price2;
	}

	/*==========================================================================*/
	DTC::TimeInForceEnum s_OrderUpdate::GetTimeInForce()
	{
		if (Size < offsetof(s_OrderUpdate, TimeInForce) + sizeof(TimeInForce))
			return (DTC::TimeInForceEnum)0;

		return TimeInForce;
	}

	/*==========================================================================*/
	DTC::t_DateTime s_OrderUpdate::GetGoodTillDateTime() 
	{
		if (Size < offsetof(s_OrderUpdate, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
	}

	/*==========================================================================*/
	double s_OrderUpdate::GetAverageFillPrice()
	{
		if (Size < offsetof(s_OrderUpdate, AverageFillPrice) + sizeof(AverageFillPrice))
			return DBL_MAX;

		return AverageFillPrice;
	}
	
	/*==========================================================================*/
	double s_OrderUpdate::GetLastFillPrice()
	{
		if (Size < offsetof(s_OrderUpdate, LastFillPrice) + sizeof(LastFillPrice))
			return DBL_MAX;

		return LastFillPrice;
	}
	
	/*==========================================================================*/
	DTC::t_DateTime s_OrderUpdate::GetLastFillDateTime() 
	{
		if (Size < offsetof(s_OrderUpdate, LastFillDateTime) + sizeof(LastFillDateTime))
			return 0;

		return LastFillDateTime;
	}

	/*==========================================================================*/	
	byte s_OrderUpdate::GetNoOrders()
	{
		if (Size < offsetof(s_OrderUpdate, NoOrders) + sizeof(NoOrders))
			return 0;

		return NoOrders;
	}


	/****************************************************************************/
	// s_OpenOrdersRequestReject

	/*==========================================================================*/
	uint16_t s_OpenOrdersReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_OpenOrdersReject::GetRequestID()
	{
		if (Size < offsetof(s_OpenOrdersReject, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/****************************************************************************/
	// s_HistoricalOrderFillResponse

	/*==========================================================================*/
	uint16_t s_HistoricalOrderFillResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_HistoricalOrderFillResponse::GetRequestID()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	int32_t s_HistoricalOrderFillResponse::GetMessageNumber()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}

	/*==========================================================================*/
	int32_t s_HistoricalOrderFillResponse::GetTotalNumberMessages()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, TotalNumberMessages) + sizeof(TotalNumberMessages))
			return 0;

		return TotalNumberMessages;
	}

	/*==========================================================================*/
	double s_HistoricalOrderFillResponse::GetPrice()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, Price) + sizeof(Price))
			return 0;

		return Price;
	}

	/*==========================================================================*/
	double s_HistoricalOrderFillResponse::GetQuantity()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, Quantity) + sizeof(Quantity))
			return 0;

		return Quantity;
	}

	/*==========================================================================*/
	DTC::t_DateTime s_HistoricalOrderFillResponse::GetDateTime() 
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, DateTime) + sizeof(DateTime))
			return 0;

		return DateTime;
	}

	/*==========================================================================*/
	DTC::BuySellEnum s_HistoricalOrderFillResponse::GetBuySell()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, BuySell) + sizeof(BuySell))
			return (DTC::BuySellEnum)0;

		return BuySell;
	}

	/*==========================================================================*/
	DTC::OpenCloseTradeEnum s_HistoricalOrderFillResponse::GetOpenClose()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, OpenClose) + sizeof(OpenClose))
			return (DTC::OpenCloseTradeEnum)0;

		return OpenClose;
	}

	/*==========================================================================*/	
	byte s_HistoricalOrderFillResponse::GetNoOrderFills()
	{
		if (Size < offsetof(s_HistoricalOrderFillResponse, NoOrderFills) + sizeof(NoOrderFills))
			return 0;

		return NoOrderFills;
	}


	/****************************************************************************/
	// s_PositionReport

	/*==========================================================================*/
	uint16_t s_PositionUpdate::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_PositionUpdate::GetRequestID()
	{
		if (Size < offsetof(s_PositionUpdate, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	int32_t s_PositionUpdate::GetMessageNumber()
	{
		if (Size < offsetof(s_PositionUpdate, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}

	/*==========================================================================*/
	int32_t s_PositionUpdate::GetTotalNumberMessages()
	{
		if (Size < offsetof(s_PositionUpdate, TotalNumberMessages) + sizeof(TotalNumberMessages))
			return 0;

		return TotalNumberMessages;
	}	

	/*==========================================================================*/
	double s_PositionUpdate::GetQuantity()
	{
		if (Size < offsetof(s_PositionUpdate, Quantity) + sizeof(Quantity))
			return 0;

		return Quantity;
	}
	
	/*==========================================================================*/
	double s_PositionUpdate::GetAveragePrice()
	{
		if (Size < offsetof(s_PositionUpdate, AveragePrice) + sizeof(AveragePrice))
			return 0;

		return AveragePrice;
	}
	
	/*==========================================================================*/	
	byte s_PositionUpdate::GetNoPositions()
	{
		if (Size < offsetof(s_PositionUpdate, NoPositions) + sizeof(NoPositions))
			return 0;

		return NoPositions;
	}
	
	/*==========================================================================*/	
	byte s_PositionUpdate::GetUnsolicited()
	{
		if (Size < offsetof(s_PositionUpdate, Unsolicited) + sizeof(Unsolicited))
			return 0;

		return Unsolicited;
	}



	/****************************************************************************/
	// s_AccountListResponse

	/*==========================================================================*/
	uint16_t s_TradeAccountResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_TradeAccountResponse::GetMessageNumber()
	{
		if (Size < offsetof(s_TradeAccountResponse, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}

	/*==========================================================================*/
	int32_t s_TradeAccountResponse::GetTotalNumberMessages()
	{
		if (Size < offsetof(s_TradeAccountResponse, TotalNumberMessages) + sizeof(TotalNumberMessages))
			return 0;

		return TotalNumberMessages;
	}		


	/****************************************************************************/
	// s_ExchangeListResponse

	/*==========================================================================*/
	uint16_t s_ExchangeListResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_ExchangeListResponse::GetRequestID()
	{
		if (Size < offsetof(s_ExchangeListResponse, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	byte s_ExchangeListResponse::GetIsFinalMessage()
	{
		if (Size < offsetof(s_ExchangeListResponse, IsFinalMessage) + sizeof(IsFinalMessage))
			return 0;

		return IsFinalMessage;
	}


	/****************************************************************************/
	// s_SymbolsForExchangeRequest

	/*==========================================================================*/
	uint16_t s_SymbolsForExchangeRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_SymbolsForExchangeRequest::GetRequestID()
	{
		if (Size < offsetof(s_SymbolsForExchangeRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	DTC::SecurityTypeEnum s_SymbolsForExchangeRequest::GetSecurityType()
	{
		if (Size < offsetof(s_SymbolsForExchangeRequest, SecurityType) + sizeof(SecurityType))
			return (DTC::SecurityTypeEnum)0;

		return SecurityType;
	}


	/****************************************************************************/
	// s_UnderlyingSymbolsForExchangeRequest

	/*==========================================================================*/
	uint16_t s_UnderlyingSymbolsForExchangeRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_UnderlyingSymbolsForExchangeRequest::GetRequestID()
	{
		if (Size < offsetof(s_UnderlyingSymbolsForExchangeRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	DTC::SecurityTypeEnum s_UnderlyingSymbolsForExchangeRequest::GetSecurityType()
	{
		if (Size < offsetof(s_UnderlyingSymbolsForExchangeRequest, SecurityType) + sizeof(SecurityType))
			return (DTC::SecurityTypeEnum)0;

		return SecurityType;
	}

	/****************************************************************************/
	// s_SymbolsForUnderlyingRequest

	/*==========================================================================*/
	uint16_t s_SymbolsForUnderlyingRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_SymbolsForUnderlyingRequest::GetRequestID()
	{
		if (Size < offsetof(s_SymbolsForUnderlyingRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	DTC::SecurityTypeEnum s_SymbolsForUnderlyingRequest::GetSecurityType()
	{
		if (Size < offsetof(s_SymbolsForUnderlyingRequest, SecurityType) + sizeof(SecurityType))
			return (DTC::SecurityTypeEnum)0;

		return SecurityType;
	}


	/****************************************************************************/
	// s_SymbolSearchByDescriptionRequest

	/*==========================================================================*/
	uint16_t s_SymbolSearchByDescription::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_SymbolSearchByDescription::GetRequestID()
	{
		if (Size < offsetof(s_SymbolSearchByDescription, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	DTC::SecurityTypeEnum s_SymbolSearchByDescription::GetSecurityType()
	{
		if (Size < offsetof(s_SymbolSearchByDescription, SecurityType) + sizeof(SecurityType))
			return (DTC::SecurityTypeEnum)0;

		return SecurityType;
	}


	/****************************************************************************/
	// s_SecurityDefinitionForSymbolRequest

	/*==========================================================================*/
	uint16_t s_SecurityDefinitionForSymbolRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_SecurityDefinitionForSymbolRequest::GetRequestID()
	{
		if (Size < offsetof(s_SecurityDefinitionForSymbolRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	DTC::SecurityTypeEnum s_SecurityDefinitionForSymbolRequest::GetSecurityType()
	{
		if (Size < offsetof(s_SecurityDefinitionForSymbolRequest, SecurityType) + sizeof(SecurityType))
			return (DTC::SecurityTypeEnum)0;

		return SecurityType;
	}


	/****************************************************************************/
	// s_SecurityDefinitionResponse

	/*==========================================================================*/
	uint16_t s_SecurityDefinitionResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_SecurityDefinitionResponse::GetRequestID() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	DTC::SecurityTypeEnum s_SecurityDefinitionResponse::GetSecurityType() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, SecurityType) + sizeof(SecurityType))
			return DTC::SECURITY_TYPE_UNSET;

		return SecurityType;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetMinPriceIncrement() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, MinPriceIncrement) + sizeof(MinPriceIncrement))
			return 0;

		return MinPriceIncrement;
	}

	/*==========================================================================*/
	DTC::PriceDisplayFormatEnum s_SecurityDefinitionResponse::GetPriceDisplayFormat() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, PriceDisplayFormat) + sizeof(PriceDisplayFormat))
			return DTC::PRICE_DISPLAY_FORMAT_UNSET;

		return PriceDisplayFormat;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetCurrencyValuePerIncrement() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, CurrencyValuePerIncrement) + sizeof(CurrencyValuePerIncrement))
			return 0;

		return CurrencyValuePerIncrement;
	}

	/*==========================================================================*/
	byte s_SecurityDefinitionResponse::GetIsFinalMessage() const
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, IsFinalMessage) + sizeof(IsFinalMessage))
			return 0;

		return IsFinalMessage;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetOrderIntPriceMultiplier()
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, OrderIntPriceMultiplier) + sizeof(OrderIntPriceMultiplier))
			return 0;

		return OrderIntPriceMultiplier;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetMarketDataIntPriceDivisor()
	{
		if (Size < offsetof(s_SecurityDefinitionResponse, MarketDataIntPriceDivisor) + sizeof(MarketDataIntPriceDivisor))
			return 0;

		return MarketDataIntPriceDivisor;
	}


	/****************************************************************************/
	// s_AccountBalanceRequest

	/*==========================================================================*/
	uint16_t s_AccountBalanceRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_AccountBalanceRequest::GetRequestID()
	{
		return RequestID;
	}

	/****************************************************************************/
	// s_AccountBalanceReject

	/*==========================================================================*/
	uint16_t s_AccountBalanceReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint32_t s_AccountBalanceReject::GetRequestID()
	{
		return RequestID;
	}


	/****************************************************************************/
	// s_AccountBalanceUpdate

	/*==========================================================================*/
	uint16_t s_AccountBalanceUpdate::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_AccountBalanceUpdate::GetRequestID()
	{
		return RequestID;
	}

	/*==========================================================================*/
	double s_AccountBalanceUpdate::GetCashBalance()
	{
		if (Size < offsetof(s_AccountBalanceUpdate, CashBalance) + sizeof(CashBalance))
			return 0;

		return CashBalance;
	}

	/*==========================================================================*/
	double s_AccountBalanceUpdate::GetBalanceAvailableForNewPositions()
	{
		if (Size < offsetof(s_AccountBalanceUpdate, BalanceAvailableForNewPositions) + sizeof(BalanceAvailableForNewPositions))
			return 0;

		return BalanceAvailableForNewPositions;
	}

	/*==========================================================================*/
	double s_AccountBalanceUpdate::GetSecuritiesValue()
	{
		if (Size < offsetof(s_AccountBalanceUpdate, SecuritiesValue) + sizeof(SecuritiesValue))
			return 0;

		return SecuritiesValue;
	}

	/*==========================================================================*/
	double s_AccountBalanceUpdate::GetMarginRequirement()
	{
		if (Size < offsetof(s_AccountBalanceUpdate, MarginRequirement) + sizeof(MarginRequirement))
			return 0;

		return MarginRequirement;
	}

	/****************************************************************************/
	// s_UserMessage

	/*==========================================================================*/
	uint16_t s_UserMessage::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	byte s_UserMessage::GetIsPopupMessage()
	{
		if (Size < offsetof(s_UserMessage, IsPopupMessage) + sizeof(IsPopupMessage))
			return 0;

		return IsPopupMessage;
	}


	/****************************************************************************/
	// s_GeneralLogMessage

	/*==========================================================================*/
	uint16_t s_GeneralLogMessage::GetMessageSize()
	{
		return Size;
	}

	/****************************************************************************/
	// s_HistoricalPriceDataRequest

	/*==========================================================================*/
	uint16_t s_HistoricalPriceDataRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_HistoricalPriceDataRequest::GetRequestID()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	uint32_t s_HistoricalPriceDataRequest::GetMaxDaysToReturn()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, MaxDaysToReturn) + sizeof(MaxDaysToReturn))
			return 0;

		return MaxDaysToReturn;
	}

	/*==========================================================================*/
	DTC::t_DateTime s_HistoricalPriceDataRequest::GetEndDateTime() 
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, EndDateTime) + sizeof(EndDateTime))
			return 0;

		return EndDateTime;
	}

	/*==========================================================================*/
	DTC::t_DateTime s_HistoricalPriceDataRequest::GetStartDateTime() 
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, StartDateTime) + sizeof(StartDateTime))
			return 0;

		return StartDateTime;
	}

	/*==========================================================================*/
	DTC::HistoricalDataIntervalEnum s_HistoricalPriceDataRequest::GetRecordInterval()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, RecordInterval) + sizeof(RecordInterval))
			return (DTC::HistoricalDataIntervalEnum)0;

		return RecordInterval;
	}

	/*==========================================================================*/
	byte s_HistoricalPriceDataRequest::GetUseZLibCompression()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, UseZLibCompression) + sizeof(UseZLibCompression))
			return 0;

		return UseZLibCompression;
	}
	
	/*==========================================================================*/
	byte s_HistoricalPriceDataRequest::GetRequestDividendAdjustedStockData()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, RequestDividendAdjustedStockData) + sizeof(RequestDividendAdjustedStockData))
			return 0;

		return RequestDividendAdjustedStockData;
	}
	
	/*==========================================================================*/
	byte s_HistoricalPriceDataRequest::GetFlag_1()
	{
		if (Size < offsetof(s_HistoricalPriceDataRequest, Flag_1) + sizeof(Flag_1))
			return 0;

		return Flag_1;
	}


	/****************************************************************************/
	// s_HistoricalPriceDataReject

	/*==========================================================================*/
	uint16_t s_HistoricalPriceDataReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	int32_t s_HistoricalPriceDataReject::GetRequestID()
	{
		if (Size < offsetof(s_HistoricalPriceDataReject, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
}
