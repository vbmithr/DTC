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
	uint16_t s_LogonRequest::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_LogonRequest::GetProtocolVersion()
	{
		if (BaseSize < offsetof(s_LogonRequest, ProtocolVersion) + sizeof(ProtocolVersion))
			return 0;

		return ProtocolVersion;
	}

	/*==========================================================================*/
	int32_t s_LogonRequest::GetInteger_1()
	{
		if (BaseSize < offsetof(s_LogonRequest, Integer_1) + sizeof(Integer_1))
			return 0;

		return Integer_1;
	}
	
	/*==========================================================================*/
	int32_t s_LogonRequest::GetInteger_2()
	{
		if (BaseSize < offsetof(s_LogonRequest, Integer_2) + sizeof(Integer_2))
			return 0;

		return Integer_2;
	}

	/*==========================================================================*/
	int32_t s_LogonRequest::GetHeartbeatIntervalInSeconds()
	{
		if (BaseSize < offsetof(s_LogonRequest, HeartbeatIntervalInSeconds) + sizeof(HeartbeatIntervalInSeconds))
			return 0;

		return HeartbeatIntervalInSeconds;
	}

	/*==========================================================================*/
	DTC::TradeModeEnum s_LogonRequest::GetTradeMode()
	{
		if (BaseSize < offsetof(s_LogonRequest, TradeMode) + sizeof(TradeMode))
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
	uint16_t s_LogonResponse::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_LogonResponse::GetProtocolVersion() const
	{
		if (BaseSize < offsetof(s_LogonResponse, ProtocolVersion) + sizeof(ProtocolVersion))
			return 0;

		return ProtocolVersion;
	}

	/*==========================================================================*/
	DTC::LogonStatusEnum s_LogonResponse::GetResult() const
	{
		if (BaseSize < offsetof(s_LogonResponse, Result) + sizeof(Result))
			return (DTC::LogonStatusEnum)0;

		return Result;
	}
	
	/*==========================================================================*/
	int32_t s_LogonResponse::GetInteger_1() const
	{
		if (BaseSize < offsetof(s_LogonResponse, Integer_1) + sizeof(Integer_1))
			return 0;

		return Integer_1;
	}

	/*==========================================================================*/
	uint8_t s_LogonResponse::GetMarketDepthUpdatesBestBidAndAsk() const
	{
		if (BaseSize < offsetof(s_LogonResponse, MarketDepthUpdatesBestBidAndAsk) + sizeof(MarketDepthUpdatesBestBidAndAsk))
			return 0;

		return MarketDepthUpdatesBestBidAndAsk;
	}

	/*==========================================================================*/
	uint8_t s_LogonResponse::GetTradingIsSupported() const
	{
		if (BaseSize < offsetof(s_LogonResponse, TradingIsSupported) + sizeof(TradingIsSupported))
			return 0;

		return TradingIsSupported;
	}


	/*==========================================================================*/
	uint8_t s_LogonResponse::GetOCOOrdersSupported() const
	{
		if (BaseSize < offsetof(s_LogonResponse, OCOOrdersSupported) + sizeof(OCOOrdersSupported))
			return 0;

		return OCOOrdersSupported;
	}

	/*==========================================================================*/
	uint8_t s_LogonResponse::GetOrderCancelReplaceSupported() const
	{
		if (BaseSize < offsetof(s_LogonResponse, OrderCancelReplaceSupported) + sizeof(OrderCancelReplaceSupported))
			return 0;

		return OrderCancelReplaceSupported;
	}


	/*==========================================================================*/
	uint8_t s_LogonResponse::GetSecurityDefinitionsSupported() const
	{
		if (BaseSize < offsetof(s_LogonResponse, SecurityDefinitionsSupported) + sizeof(SecurityDefinitionsSupported))
			return 0;

		return SecurityDefinitionsSupported;
	}


	/*==========================================================================*/
	uint8_t s_LogonResponse::GetHistoricalPriceDataSupported() const
	{
		if (BaseSize < offsetof(s_LogonResponse, HistoricalPriceDataSupported) + sizeof(HistoricalPriceDataSupported))
			return 0;

		return HistoricalPriceDataSupported;
	}


	/*==========================================================================*/
	uint8_t s_LogonResponse::GetResubscribeWhenMarketDataFeedAvailable() const
	{
		if (BaseSize < offsetof(s_LogonResponse, ResubscribeWhenMarketDataFeedAvailable) + sizeof(ResubscribeWhenMarketDataFeedAvailable))
			return 0;

		return ResubscribeWhenMarketDataFeedAvailable;
	}

	/*==========================================================================*/
	uint8_t s_LogonResponse::GetMarketDepthIsSupported() const
	{
		if (BaseSize < offsetof(s_LogonResponse, MarketDepthIsSupported) + sizeof(MarketDepthIsSupported))
			return 0;

		return MarketDepthIsSupported;
	}
	/*==========================================================================*/
	uint8_t s_LogonResponse::GetOneHistoricalPriceDataRequestPerConnection() const
	{
		if (BaseSize < offsetof(s_LogonResponse, OneHistoricalPriceDataRequestPerConnection) + sizeof(OneHistoricalPriceDataRequestPerConnection))
			return 0;

		return OneHistoricalPriceDataRequestPerConnection;
	}
	/*==========================================================================*/
	uint8_t s_LogonResponse::GetUseIntegerPriceOrderMessages() const
	{
		if (BaseSize < offsetof(s_LogonResponse, UseIntegerPriceOrderMessages) + sizeof(UseIntegerPriceOrderMessages))
			return 0;

		return UseIntegerPriceOrderMessages;
	}

	/*==========================================================================*/
	uint8_t s_LogonResponse::GetBracketOrdersSupported() const
	{
		if (BaseSize < offsetof(s_LogonResponse, BracketOrdersSupported) + sizeof(BracketOrdersSupported))
			return 0;

		return BracketOrdersSupported;
	}
	
	/*==========================================================================*/
	uint8_t s_LogonResponse::GetUsesMultiplePositionsPerSymbolAndTradeAccount() const
	{
		if (BaseSize < offsetof(s_LogonResponse, UsesMultiplePositionsPerSymbolAndTradeAccount) + sizeof(UsesMultiplePositionsPerSymbolAndTradeAccount))
			return 0;

		return UsesMultiplePositionsPerSymbolAndTradeAccount;
	}

	/*==========================================================================*/
	uint8_t s_LogonResponse::GetMarketDataSupported() const
	{
		if (BaseSize < offsetof(s_LogonResponse, MarketDataSupported) + sizeof(MarketDataSupported))
			return 0;

		return MarketDataSupported;
	}

	/****************************************************************************/
	// s_LogoffRequest

	/*==========================================================================*/
	uint16_t s_Logoff::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_Logoff::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	uint8_t s_Logoff::GetDoNotReconnect()
	{
		if (BaseSize < offsetof(s_Logoff, DoNotReconnect) + sizeof(DoNotReconnect))
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
	uint16_t s_MarketDataRequest::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	DTC::RequestActionEnum s_MarketDataRequest::GetRequestAction()
	{
		if (BaseSize < offsetof(s_MarketDataRequest, RequestAction) + sizeof(RequestAction))
			return (DTC::RequestActionEnum)0;

		return RequestAction;
	}

	/*==========================================================================*/
	uint16_t s_MarketDataRequest::GetSymbolID()
	{
		if (BaseSize < offsetof(s_MarketDataRequest, SymbolID) + sizeof(SymbolID))
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
	uint16_t s_MarketDepthRequest::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	DTC::RequestActionEnum s_MarketDepthRequest::GetRequestAction()
	{
		if (BaseSize < offsetof(s_MarketDepthRequest, RequestAction) + sizeof(RequestAction))
			return (DTC::RequestActionEnum)0;

		return RequestAction;
	}

	/*==========================================================================*/
	uint16_t s_MarketDepthRequest::GetSymbolID()
	{
		if (BaseSize < offsetof(s_MarketDepthRequest, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}

	/*==========================================================================*/
	int32_t s_MarketDepthRequest::GetNumLevels()
	{
		if (BaseSize < offsetof(s_MarketDepthRequest, NumLevels) + sizeof(NumLevels))
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
	uint16_t s_MarketDataReject::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	uint16_t s_MarketDataReject::GetSymbolID()
	{
		if (BaseSize < offsetof(s_MarketDataReject, SymbolID) + sizeof(SymbolID))
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
	uint16_t s_MarketDepthReject::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	uint16_t s_MarketDepthReject::GetSymbolID()
	{
		if (BaseSize < offsetof(s_MarketDepthReject, SymbolID) + sizeof(SymbolID))
			return 0;

		return SymbolID;
	}
	

	/****************************************************************************/
	// s_SubmitNewSingleOrder

	/*==========================================================================*/
	uint16_t s_SubmitNewSingleOrder::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_SubmitNewSingleOrder::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	DTC::OrderTypeEnum s_SubmitNewSingleOrder::GetOrderType()
	{			
		if (BaseSize < offsetof(s_SubmitNewSingleOrder, OrderType) + sizeof(OrderType))
			return DTC::ORDER_TYPE_UNSET;

		return OrderType;	
	}

	/*==========================================================================*/
	DTC::BuySellEnum s_SubmitNewSingleOrder::GetBuySell()
	{			
		if (BaseSize < offsetof(s_SubmitNewSingleOrder, BuySell) + sizeof(BuySell))
			return DTC::BUY_SELL_UNSET;

		return BuySell;	
	}

	/*==========================================================================*/
	double s_SubmitNewSingleOrder::GetPrice1()
	{
		if (BaseSize < offsetof(s_SubmitNewSingleOrder, Price1) + sizeof(Price1))
			return 0.0;

		return Price1;
	}

	/*==========================================================================*/
	double s_SubmitNewSingleOrder::GetPrice2()
	{
		if (BaseSize < offsetof(s_SubmitNewSingleOrder, Price2) + sizeof(Price2))
			return 0.0;

		return Price2;
	}

	/*==========================================================================*/
	double s_SubmitNewSingleOrder::GetQuantity()
	{
		if (BaseSize < offsetof(s_SubmitNewSingleOrder, Quantity) + sizeof(Quantity))
			return 0.0;

		return Quantity;
	}

	/*==========================================================================*/
	DTC::TimeInForceEnum s_SubmitNewSingleOrder::GetTimeInForce()
	{			
		if (BaseSize < offsetof(s_SubmitNewSingleOrder, TimeInForce) + sizeof(TimeInForce))
			return DTC::TIF_UNSET;

		return TimeInForce;	
	}

	/*==========================================================================*/	 
	DTC::t_DateTime s_SubmitNewSingleOrder::GetGoodTillDateTime() 
	{
		if (BaseSize < offsetof(s_SubmitNewSingleOrder, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
	}

	/*==========================================================================*/
	uint8_t s_SubmitNewSingleOrder::GetIsAutomatedOrder()
	{
		if (BaseSize < offsetof(s_SubmitNewSingleOrder, IsAutomatedOrder) + sizeof(IsAutomatedOrder))
			return 0;

		return IsAutomatedOrder;
	}

	/*==========================================================================*/
	uint8_t s_SubmitNewSingleOrder::GetIsParentOrder()
	{
		if (BaseSize < offsetof(s_SubmitNewSingleOrder, IsParentOrder) + sizeof(IsParentOrder))
			return 0;

		return IsParentOrder;
	}

	/*==========================================================================*/
	DTC::OpenCloseTradeEnum s_SubmitNewSingleOrder::GetOpenOrClose()
	{
		if (BaseSize < offsetof(s_SubmitNewSingleOrder, OpenOrClose) + sizeof(OpenOrClose))
			return DTC::TRADE_UNSET;

		return OpenOrClose;
	}

	/****************************************************************************/
	// s_SubmitNewSingleOrderInt

	/*==========================================================================*/
	uint16_t s_SubmitNewSingleOrderInt::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_SubmitNewSingleOrderInt::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	DTC::OrderTypeEnum s_SubmitNewSingleOrderInt::GetOrderType()
	{			
		if (BaseSize < offsetof(s_SubmitNewSingleOrderInt, OrderType) + sizeof(OrderType))
			return DTC::ORDER_TYPE_UNSET;

		return OrderType;	
	}

	/*==========================================================================*/
	DTC::BuySellEnum s_SubmitNewSingleOrderInt::GetBuySell()
	{			
		if (BaseSize < offsetof(s_SubmitNewSingleOrderInt, BuySell) + sizeof(BuySell))
			return DTC::BUY_SELL_UNSET;

		return BuySell;	
	}
	
	/*==========================================================================*/
	int64_t s_SubmitNewSingleOrderInt::GetPrice1()
	{
		if (BaseSize < offsetof(s_SubmitNewSingleOrderInt, Price1) + sizeof(Price1))
			return 0;

		return Price1;
	}

	/*==========================================================================*/
	int64_t s_SubmitNewSingleOrderInt::GetPrice2()
	{
		if (BaseSize < offsetof(s_SubmitNewSingleOrderInt, Price2) + sizeof(Price2))
			return 0;

		return Price2;
	}

	/*==========================================================================*/
	float s_SubmitNewSingleOrderInt::GetDivisor()
	{
		if (BaseSize < offsetof(s_SubmitNewSingleOrderInt, Divisor) + sizeof(Divisor))
			return 0.0;

		return Divisor;
	}

	/*==========================================================================*/
	int64_t s_SubmitNewSingleOrderInt::GetQuantity()
	{
		if (BaseSize < offsetof(s_SubmitNewSingleOrderInt, Quantity) + sizeof(Quantity))
			return 0;

		return Quantity;
	}

	/*==========================================================================*/
	DTC::TimeInForceEnum s_SubmitNewSingleOrderInt::GetTimeInForce()
	{			
		if (BaseSize < offsetof(s_SubmitNewSingleOrderInt, TimeInForce) + sizeof(TimeInForce))
			return DTC::TIF_UNSET;

		return TimeInForce;	
	}

	/*==========================================================================*/	 
	DTC::t_DateTime s_SubmitNewSingleOrderInt::GetGoodTillDateTime() 
	{
		if (BaseSize < offsetof(s_SubmitNewSingleOrderInt, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
	}

	/*==========================================================================*/
	uint8_t s_SubmitNewSingleOrderInt::GetIsAutomatedOrder()
	{
		if (BaseSize < offsetof(s_SubmitNewSingleOrderInt, IsAutomatedOrder) + sizeof(IsAutomatedOrder))
			return 0;

		return IsAutomatedOrder;
	}

	/*==========================================================================*/
	uint8_t s_SubmitNewSingleOrderInt::GetIsParentOrder()
	{
		if (BaseSize < offsetof(s_SubmitNewSingleOrderInt, IsParentOrder) + sizeof(IsParentOrder))
			return 0;

		return IsParentOrder;
	}

	/*==========================================================================*/
	DTC::OpenCloseTradeEnum s_SubmitNewSingleOrderInt::GetOpenOrClose()
	{
		if (BaseSize < offsetof(s_SubmitNewSingleOrderInt, OpenOrClose) + sizeof(OpenOrClose))
			return DTC::TRADE_UNSET;

		return OpenOrClose;
	}

	/****************************************************************************/
	// s_CancelReplaceOrder

	/*==========================================================================*/
	uint16_t s_CancelReplaceOrder::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_CancelReplaceOrder::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	double s_CancelReplaceOrder::GetPrice1()
	{
		if (BaseSize < offsetof(s_CancelReplaceOrder, Price1) + sizeof(Price1))
			return 0.0;

		return Price1;
	}

	/*==========================================================================*/
	double s_CancelReplaceOrder::GetPrice2()
	{
		if (BaseSize < offsetof(s_CancelReplaceOrder, Price2) + sizeof(Price2))
			return 0.0;

		return Price2;
	}

	/*==========================================================================*/
	double s_CancelReplaceOrder::GetQuantity()
	{
		if (BaseSize < offsetof(s_CancelReplaceOrder, Quantity) + sizeof(Quantity))
			return 0.0;

		return Quantity;
	}

	/*==========================================================================*/
	int8_t s_CancelReplaceOrder::GetPrice1IsSet()
	{
		if (BaseSize < offsetof(s_CancelReplaceOrder, Price1IsSet) + sizeof(Price1IsSet))
			return 1;

		return Price1IsSet;
	}

	/*==========================================================================*/
	int8_t s_CancelReplaceOrder::GetPrice2IsSet()
	{
		if (BaseSize < offsetof(s_CancelReplaceOrder, Price2IsSet) + sizeof(Price2IsSet))
			return 1;

		return Price2IsSet;
	}

	/*==========================================================================*/
	DTC::OrderTypeEnum s_CancelReplaceOrder::GetOrderType()
	{
		if (BaseSize < offsetof(s_CancelReplaceOrder, OrderType) + sizeof(OrderType))
			return DTC::ORDER_TYPE_UNSET;

		return OrderType;
	}

	/*==========================================================================*/
	DTC::TimeInForceEnum s_CancelReplaceOrder::GetTimeInForce()
	{
		if (BaseSize < offsetof(s_CancelReplaceOrder, TimeInForce) + sizeof(TimeInForce))
			return DTC::TIF_UNSET;

		return TimeInForce;
	}

	/*==========================================================================*/
	DTC::t_DateTime s_CancelReplaceOrder::GetGoodTillDateTime()
	{
		if (BaseSize < offsetof(s_CancelReplaceOrder, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
	}

	/****************************************************************************/
	// s_CancelReplaceOrderInt

	/*==========================================================================*/
	uint16_t s_CancelReplaceOrderInt::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_CancelReplaceOrderInt::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int64_t s_CancelReplaceOrderInt::GetPrice1()
	{
		if (BaseSize < offsetof(s_CancelReplaceOrderInt, Price1) + sizeof(Price1))
			return 0;

		return Price1;
	}

	/*==========================================================================*/
	int64_t s_CancelReplaceOrderInt::GetPrice2()
	{
		if (BaseSize < offsetof(s_CancelReplaceOrderInt, Price2) + sizeof(Price2))
			return 0;

		return Price2;
	}

	/*==========================================================================*/
	float s_CancelReplaceOrderInt::GetDivisor()
	{
		if (BaseSize < offsetof(s_CancelReplaceOrderInt, Divisor) + sizeof(Divisor))
			return 1.0f;

		return Divisor;
	}

	/*==========================================================================*/
	int64_t s_CancelReplaceOrderInt::GetQuantity()
	{
		if (BaseSize < offsetof(s_CancelReplaceOrderInt, Quantity) + sizeof(Quantity))
			return 0;

		return Quantity;
	}

	/*==========================================================================*/
	int8_t s_CancelReplaceOrderInt::GetPrice1IsSet()
	{
		if (BaseSize < offsetof(s_CancelReplaceOrderInt, Price1IsSet) + sizeof(Price1IsSet))
			return 1;

		return Price1IsSet;
	}

	/*==========================================================================*/
	int8_t s_CancelReplaceOrderInt::GetPrice2IsSet()
	{
		if (BaseSize < offsetof(s_CancelReplaceOrderInt, Price2IsSet) + sizeof(Price2IsSet))
			return 1;

		return Price2IsSet;
	}

	/*==========================================================================*/
	DTC::OrderTypeEnum s_CancelReplaceOrderInt::GetOrderType()
	{
		if (BaseSize < offsetof(s_CancelReplaceOrderInt, OrderType) + sizeof(OrderType))
			return DTC::ORDER_TYPE_UNSET;

		return OrderType;
	}

	/*==========================================================================*/
	DTC::TimeInForceEnum s_CancelReplaceOrderInt::GetTimeInForce()
	{
		if (BaseSize < offsetof(s_CancelReplaceOrderInt, TimeInForce) + sizeof(TimeInForce))
			return DTC::TIF_UNSET;

		return TimeInForce;
	}

	/*==========================================================================*/
	DTC::t_DateTime s_CancelReplaceOrderInt::GetGoodTillDateTime()
	{
		if (BaseSize < offsetof(s_CancelReplaceOrderInt, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
	}


	/****************************************************************************/
	// s_CancelOrder

	/*==========================================================================*/
	uint16_t s_CancelOrder::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_CancelOrder::GetBaseSize()
	{
		return BaseSize;
	}

	/****************************************************************************/
	// s_SubmitNewOCOOrder

	/*==========================================================================*/
	uint16_t s_SubmitNewOCOOrder::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_SubmitNewOCOOrder::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	DTC::OrderTypeEnum s_SubmitNewOCOOrder::GetOrderType_1()
	{			
		if (BaseSize < offsetof(s_SubmitNewOCOOrder, OrderType_1) + sizeof(OrderType_1))
			return DTC::ORDER_TYPE_UNSET;

		return OrderType_1;	
	}

	/*==========================================================================*/
	DTC::OrderTypeEnum s_SubmitNewOCOOrder::GetOrderType_2()
	{			
		if (BaseSize < offsetof(s_SubmitNewOCOOrder, OrderType_2) + sizeof(OrderType_2))
			return DTC::ORDER_TYPE_UNSET;

		return OrderType_2;	
	}

	/*==========================================================================*/			 
	DTC::BuySellEnum s_SubmitNewOCOOrder::GetBuySell_1()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrder, BuySell_1) + sizeof(BuySell_1))
			return (DTC::BuySellEnum)0;

		return BuySell_1;
	}

	/*==========================================================================*/
	DTC::BuySellEnum s_SubmitNewOCOOrder::GetBuySell_2()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrder, BuySell_2) + sizeof(BuySell_2))
			return (DTC::BuySellEnum)0;

		return BuySell_2;
	}

	/*==========================================================================*/
	DTC::TimeInForceEnum s_SubmitNewOCOOrder::GetTimeInForce()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrder, TimeInForce) + sizeof(TimeInForce))
			return (DTC::TimeInForceEnum)0;

		return TimeInForce;
	}

	/*==========================================================================*/
	DTC::t_DateTime s_SubmitNewOCOOrder::GetGoodTillDateTime() 
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrder, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
	}	

	/*==========================================================================*/
	uint8_t s_SubmitNewOCOOrder::GetIsAutomatedOrder()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrder, IsAutomatedOrder) + sizeof(IsAutomatedOrder))
			return 0;

		return IsAutomatedOrder;
	}

	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetPrice1_1()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrder, Price1_1) + sizeof(Price1_1))
			return 0.0;

		return Price1_1;
	}

	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetPrice2_1()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrder, Price2_1) + sizeof(Price2_1))
			return 0.0;

		return Price2_1;
	}

	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetPrice1_2()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrder, Price1_2) + sizeof(Price1_2))
			return 0.0;

		return Price1_2;
	}

	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetPrice2_2()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrder, Price2_2) + sizeof(Price2_2))
			return 0.0;

		return Price2_2;
	}

	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetQuantity_1()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrder, Quantity_1) + sizeof(Quantity_1))
			return 0.0;

		return Quantity_1;
	}

	/*==========================================================================*/
	double s_SubmitNewOCOOrder::GetQuantity_2()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrder, Quantity_2) + sizeof(Quantity_2))
			return 0.0;

		return Quantity_2;
	}

	/*==========================================================================*/
	DTC::OpenCloseTradeEnum s_SubmitNewOCOOrder::GetOpenOrClose()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrder, OpenOrClose) + sizeof(OpenOrClose))
			return DTC::TRADE_UNSET;

		return OpenOrClose;
	}

	/*==========================================================================*/
	DTC::PartialFillHandlingEnum s_SubmitNewOCOOrder::GetPartialFillHandling()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrder, PartialFillHandling) + sizeof(PartialFillHandling))
			return DTC::PARTIAL_FILL_UNSET;

		return PartialFillHandling;
	}

	/****************************************************************************/
	// s_SubmitNewOCOOrderInt

	/*==========================================================================*/
	uint16_t s_SubmitNewOCOOrderInt::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_SubmitNewOCOOrderInt::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	DTC::OrderTypeEnum s_SubmitNewOCOOrderInt::GetOrderType_1()
	{			
		if (BaseSize < offsetof(s_SubmitNewOCOOrderInt, OrderType_1) + sizeof(OrderType_1))
			return DTC::ORDER_TYPE_UNSET;

		return OrderType_1;	
	}

	/*==========================================================================*/
	DTC::OrderTypeEnum s_SubmitNewOCOOrderInt::GetOrderType_2()
	{			
		if (BaseSize < offsetof(s_SubmitNewOCOOrderInt, OrderType_2) + sizeof(OrderType_2))
			return DTC::ORDER_TYPE_UNSET;

		return OrderType_2;	
	}

	/*==========================================================================*/			 
	DTC::BuySellEnum s_SubmitNewOCOOrderInt::GetBuySell_1()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrderInt, BuySell_1) + sizeof(BuySell_1))
			return (DTC::BuySellEnum)0;

		return BuySell_1;
	}

	/*==========================================================================*/
	DTC::BuySellEnum s_SubmitNewOCOOrderInt::GetBuySell_2()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrderInt, BuySell_2) + sizeof(BuySell_2))
			return (DTC::BuySellEnum)0;

		return BuySell_2;
	}

	/*==========================================================================*/
	DTC::TimeInForceEnum s_SubmitNewOCOOrderInt::GetTimeInForce()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrderInt, TimeInForce) + sizeof(TimeInForce))
			return (DTC::TimeInForceEnum)0;

		return TimeInForce;
	}

	/*==========================================================================*/
	DTC::t_DateTime s_SubmitNewOCOOrderInt::GetGoodTillDateTime() 
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrderInt, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
	}	

	/*==========================================================================*/
	uint8_t s_SubmitNewOCOOrderInt::GetIsAutomatedOrder()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrderInt, IsAutomatedOrder) + sizeof(IsAutomatedOrder))
			return 0;

		return IsAutomatedOrder;
	}

	/*==========================================================================*/
	int64_t s_SubmitNewOCOOrderInt::GetPrice1_1()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrderInt, Price1_1) + sizeof(Price1_1))
			return 0;

		return Price1_1;
	}
	
	/*==========================================================================*/
	int64_t s_SubmitNewOCOOrderInt::GetPrice2_1()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrderInt, Price2_1) + sizeof(Price2_1))
			return 0;

		return Price2_1;
	}
	
	/*==========================================================================*/
	int64_t s_SubmitNewOCOOrderInt::GetPrice1_2()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrderInt, Price1_2) + sizeof(Price1_2))
			return 0;

		return Price1_2;
	}
	
	/*==========================================================================*/
	int64_t s_SubmitNewOCOOrderInt::GetPrice2_2()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrderInt, Price2_2) + sizeof(Price2_2))
			return 0;

		return Price2_2;
	}

	/*==========================================================================*/
	int64_t s_SubmitNewOCOOrderInt::GetQuantity_1()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrderInt, Quantity_1) + sizeof(Quantity_1))
			return 0;

		return Quantity_1;
	}

	/*==========================================================================*/
	int64_t s_SubmitNewOCOOrderInt::GetQuantity_2()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrderInt, Quantity_2) + sizeof(Quantity_2))
			return 0;

		return Quantity_2;
	}

	/*==========================================================================*/
	float s_SubmitNewOCOOrderInt::GetDivisor()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrderInt, Divisor) + sizeof(Divisor))
			return 0.0;

		return Divisor;
	}

	/*==========================================================================*/
	DTC::OpenCloseTradeEnum s_SubmitNewOCOOrderInt::GetOpenOrClose()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrderInt, OpenOrClose) + sizeof(OpenOrClose))
			return DTC::TRADE_UNSET;

		return OpenOrClose;
	}

	/*==========================================================================*/
	DTC::PartialFillHandlingEnum s_SubmitNewOCOOrderInt::GetPartialFillHandling()
	{
		if (BaseSize < offsetof(s_SubmitNewOCOOrderInt, PartialFillHandling) + sizeof(PartialFillHandling))
			return DTC::PARTIAL_FILL_UNSET;

		return PartialFillHandling;
	}

	/****************************************************************************/
	// s_OpenOrdersRequest

	/*==========================================================================*/
	uint16_t s_OpenOrdersRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_OpenOrdersRequest::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_OpenOrdersRequest::GetRequestID()
	{
		if (BaseSize < offsetof(s_OpenOrdersRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	int32_t s_OpenOrdersRequest::GetRequestAllOrders()
	{
		if (BaseSize < offsetof(s_OpenOrdersRequest, RequestAllOrders) + sizeof(RequestAllOrders))
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
	uint16_t s_HistoricalOrderFillsRequest::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_HistoricalOrderFillsRequest::GetRequestID()
	{
		if (BaseSize < offsetof(s_HistoricalOrderFillsRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	int32_t s_HistoricalOrderFillsRequest::GetNumberOfDays()
	{
		if (BaseSize < offsetof(s_HistoricalOrderFillsRequest, NumberOfDays) + sizeof(NumberOfDays))
			return 0;

		return NumberOfDays;
	}

	/****************************************************************************/
	// s_HistoricalOrderFillsReject

	/*==========================================================================*/
	uint16_t s_HistoricalOrderFillsReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_HistoricalOrderFillsReject::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_HistoricalOrderFillsReject::GetRequestID()
	{
		if (BaseSize < offsetof(s_HistoricalOrderFillsReject, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/****************************************************************************/
	// s_CurrentPositionsRequest

	/*==========================================================================*/
	uint16_t s_CurrentPositionsRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_CurrentPositionsRequest::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_CurrentPositionsRequest::GetRequestID()
	{
		if (BaseSize < offsetof(s_CurrentPositionsRequest, RequestID) + sizeof(RequestID))
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
	uint16_t s_CurrentPositionsReject::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_CurrentPositionsReject::GetRequestID()
	{
		if (BaseSize < offsetof(s_CurrentPositionsReject, RequestID) + sizeof(RequestID))
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
	uint16_t s_OrderUpdate::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	double s_OrderUpdate::GetOrderQuantity()
	{
		if (BaseSize < offsetof(s_OrderUpdate, OrderQuantity) + sizeof(OrderQuantity))
			return DBL_MAX;

		return OrderQuantity;
	}

	/*==========================================================================*/
	double s_OrderUpdate::GetFilledQuantity()
	{
		if (BaseSize < offsetof(s_OrderUpdate, FilledQuantity) + sizeof(FilledQuantity))
			return DBL_MAX;

		return FilledQuantity;
	}

	/*==========================================================================*/
	double s_OrderUpdate::GetRemainingQuantity()
	{
		if (BaseSize < offsetof(s_OrderUpdate, RemainingQuantity) + sizeof(RemainingQuantity))
			return DBL_MAX;

		return RemainingQuantity;
	}

	/*==========================================================================*/
	double s_OrderUpdate::GetLastFillQuantity()
	{
		if (BaseSize < offsetof(s_OrderUpdate, LastFillQuantity) + sizeof(LastFillQuantity))
			return DBL_MAX;

		return LastFillQuantity;
	}
	
	/*==========================================================================*/
	int32_t s_OrderUpdate::GetRequestID()
	{
		if (BaseSize < offsetof(s_OrderUpdate, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}
	
	/*==========================================================================*/
	int32_t s_OrderUpdate::GetTotalNumMessages()
	{
		if (BaseSize < offsetof(s_OrderUpdate, TotalNumMessages) + sizeof(TotalNumMessages))
			return 0;

		return TotalNumMessages;
	}

	/*==========================================================================*/
	int32_t s_OrderUpdate::GetMessageNumber()
	{
		if (BaseSize < offsetof(s_OrderUpdate, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}
	
	/*==========================================================================*/
	DTC::OrderStatusEnum s_OrderUpdate::GetOrderStatus()
	{
		if (BaseSize < offsetof(s_OrderUpdate, OrderStatus) + sizeof(OrderStatus))
			return (DTC::OrderStatusEnum)0;

		return OrderStatus;
	}
	
	/*==========================================================================*/
	DTC::OrderUpdateReasonEnum s_OrderUpdate::GetOrderUpdateReason()
	{
		if (BaseSize < offsetof(s_OrderUpdate, OrderUpdateReason) + sizeof(OrderUpdateReason))
			return (DTC::OrderUpdateReasonEnum)0;

		return OrderUpdateReason;
	}
	
	/*==========================================================================*/
	DTC::OrderTypeEnum s_OrderUpdate::GetOrderType()
	{
		if (BaseSize < offsetof(s_OrderUpdate, OrderType) + sizeof(OrderType))
			return (DTC::OrderTypeEnum)0;

		return OrderType;
	}
	
	/*==========================================================================*/
	DTC::BuySellEnum s_OrderUpdate::GetBuySell()
	{
		if (BaseSize < offsetof(s_OrderUpdate, BuySell) + sizeof(BuySell))
			return (DTC::BuySellEnum)0;

		return BuySell;
	}
	
	/*==========================================================================*/
	double s_OrderUpdate::GetPrice1()
	{
		if (BaseSize < offsetof(s_OrderUpdate, Price1) + sizeof(Price1))
			return DBL_MAX;

		return Price1;
	}
	
	/*==========================================================================*/
	double s_OrderUpdate::GetPrice2()
	{
		if (BaseSize < offsetof(s_OrderUpdate, Price2) + sizeof(Price2))
			return DBL_MAX;

		return Price2;
	}

	/*==========================================================================*/
	DTC::TimeInForceEnum s_OrderUpdate::GetTimeInForce()
	{
		if (BaseSize < offsetof(s_OrderUpdate, TimeInForce) + sizeof(TimeInForce))
			return (DTC::TimeInForceEnum)0;

		return TimeInForce;
	}

	/*==========================================================================*/
	DTC::t_DateTime s_OrderUpdate::GetGoodTillDateTime() 
	{
		if (BaseSize < offsetof(s_OrderUpdate, GoodTillDateTime) + sizeof(GoodTillDateTime))
			return 0;

		return GoodTillDateTime;
	}

	/*==========================================================================*/
	double s_OrderUpdate::GetAverageFillPrice()
	{
		if (BaseSize < offsetof(s_OrderUpdate, AverageFillPrice) + sizeof(AverageFillPrice))
			return DBL_MAX;

		return AverageFillPrice;
	}
	
	/*==========================================================================*/
	double s_OrderUpdate::GetLastFillPrice()
	{
		if (BaseSize < offsetof(s_OrderUpdate, LastFillPrice) + sizeof(LastFillPrice))
			return DBL_MAX;

		return LastFillPrice;
	}
	
	/*==========================================================================*/
	DTC::t_DateTime s_OrderUpdate::GetLastFillDateTime() 
	{
		if (BaseSize < offsetof(s_OrderUpdate, LastFillDateTime) + sizeof(LastFillDateTime))
			return 0;

		return LastFillDateTime;
	}

	/*==========================================================================*/
	uint8_t s_OrderUpdate::GetNoOrders()
	{
		if (BaseSize < offsetof(s_OrderUpdate, NoOrders) + sizeof(NoOrders))
			return 0;

		return NoOrders;
	}

	/*==========================================================================*/
	DTC::OpenCloseTradeEnum s_OrderUpdate::GetOpenOrClose()
	{
		if (BaseSize < offsetof(s_OrderUpdate, OpenOrClose) + sizeof(OpenOrClose))
			return DTC::TRADE_UNSET;

		return OpenOrClose;
	}

	/****************************************************************************/
	// s_OpenOrdersRequestReject

	/*==========================================================================*/
	uint16_t s_OpenOrdersReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_OpenOrdersReject::GetBaseSize()
	{
		return BaseSize;
	}
	/*==========================================================================*/
	int32_t s_OpenOrdersReject::GetRequestID()
	{
		if (BaseSize < offsetof(s_OpenOrdersReject, RequestID) + sizeof(RequestID))
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
	uint16_t s_HistoricalOrderFillResponse::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_HistoricalOrderFillResponse::GetRequestID()
	{
		if (BaseSize < offsetof(s_HistoricalOrderFillResponse, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	int32_t s_HistoricalOrderFillResponse::GetMessageNumber()
	{
		if (BaseSize < offsetof(s_HistoricalOrderFillResponse, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}

	/*==========================================================================*/
	int32_t s_HistoricalOrderFillResponse::GetTotalNumberMessages()
	{
		if (BaseSize < offsetof(s_HistoricalOrderFillResponse, TotalNumberMessages) + sizeof(TotalNumberMessages))
			return 0;

		return TotalNumberMessages;
	}

	/*==========================================================================*/
	double s_HistoricalOrderFillResponse::GetPrice()
	{
		if (BaseSize < offsetof(s_HistoricalOrderFillResponse, Price) + sizeof(Price))
			return 0;

		return Price;
	}

	/*==========================================================================*/
	double s_HistoricalOrderFillResponse::GetQuantity()
	{
		if (BaseSize < offsetof(s_HistoricalOrderFillResponse, Quantity) + sizeof(Quantity))
			return 0;

		return Quantity;
	}

	/*==========================================================================*/
	DTC::t_DateTime s_HistoricalOrderFillResponse::GetDateTime() 
	{
		if (BaseSize < offsetof(s_HistoricalOrderFillResponse, DateTime) + sizeof(DateTime))
			return 0;

		return DateTime;
	}

	/*==========================================================================*/
	DTC::BuySellEnum s_HistoricalOrderFillResponse::GetBuySell()
	{
		if (BaseSize < offsetof(s_HistoricalOrderFillResponse, BuySell) + sizeof(BuySell))
			return (DTC::BuySellEnum)0;

		return BuySell;
	}

	/*==========================================================================*/
	DTC::OpenCloseTradeEnum s_HistoricalOrderFillResponse::GetOpenClose()
	{
		if (BaseSize < offsetof(s_HistoricalOrderFillResponse, OpenClose) + sizeof(OpenClose))
			return (DTC::OpenCloseTradeEnum)0;

		return OpenClose;
	}

	/*==========================================================================*/
	uint8_t s_HistoricalOrderFillResponse::GetNoOrderFills()
	{
		if (BaseSize < offsetof(s_HistoricalOrderFillResponse, NoOrderFills) + sizeof(NoOrderFills))
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
	uint16_t s_PositionUpdate::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_PositionUpdate::GetRequestID()
	{
		if (BaseSize < offsetof(s_PositionUpdate, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	int32_t s_PositionUpdate::GetMessageNumber()
	{
		if (BaseSize < offsetof(s_PositionUpdate, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}

	/*==========================================================================*/
	int32_t s_PositionUpdate::GetTotalNumberMessages()
	{
		if (BaseSize < offsetof(s_PositionUpdate, TotalNumberMessages) + sizeof(TotalNumberMessages))
			return 0;

		return TotalNumberMessages;
	}	

	/*==========================================================================*/
	double s_PositionUpdate::GetQuantity()
	{
		if (BaseSize < offsetof(s_PositionUpdate, Quantity) + sizeof(Quantity))
			return 0;

		return Quantity;
	}
	
	/*==========================================================================*/
	double s_PositionUpdate::GetAveragePrice()
	{
		if (BaseSize < offsetof(s_PositionUpdate, AveragePrice) + sizeof(AveragePrice))
			return 0;

		return AveragePrice;
	}
	
	/*==========================================================================*/	
	uint8_t s_PositionUpdate::GetNoPositions()
	{
		if (BaseSize < offsetof(s_PositionUpdate, NoPositions) + sizeof(NoPositions))
			return 0;

		return NoPositions;
	}
	
	/*==========================================================================*/	
	uint8_t s_PositionUpdate::GetUnsolicited()
	{
		if (BaseSize < offsetof(s_PositionUpdate, Unsolicited) + sizeof(Unsolicited))
			return 0;

		return Unsolicited;
	}


	/****************************************************************************/
	// s_TradeAccountResponse

	/*==========================================================================*/
	uint16_t s_TradeAccountResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_TradeAccountResponse::GetBaseSize()
	{
		return BaseSize;
	}
	
	/*==========================================================================*/
	int32_t s_TradeAccountResponse::GetTotalNumberMessages()
	{
		if (BaseSize < offsetof(s_TradeAccountResponse, TotalNumberMessages) + sizeof(TotalNumberMessages))
			return 0;

		return TotalNumberMessages;
	}	

	/*==========================================================================*/
	int32_t s_TradeAccountResponse::GetMessageNumber()
	{
		if (BaseSize < offsetof(s_TradeAccountResponse, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}

	/*==========================================================================*/
	int32_t s_TradeAccountResponse::GetRequestID()
	{
		if (BaseSize < offsetof(s_TradeAccountResponse, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}


	/****************************************************************************/
	// s_ExchangeListResponse

	/*==========================================================================*/
	uint16_t s_ExchangeListResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_ExchangeListResponse::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_ExchangeListResponse::GetRequestID()
	{
		if (BaseSize < offsetof(s_ExchangeListResponse, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	uint8_t s_ExchangeListResponse::GetIsFinalMessage()
	{
		if (BaseSize < offsetof(s_ExchangeListResponse, IsFinalMessage) + sizeof(IsFinalMessage))
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

	uint16_t s_SymbolsForExchangeRequest::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_SymbolsForExchangeRequest::GetRequestID()
	{
		if (BaseSize < offsetof(s_SymbolsForExchangeRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	DTC::SecurityTypeEnum s_SymbolsForExchangeRequest::GetSecurityType()
	{
		if (BaseSize < offsetof(s_SymbolsForExchangeRequest, SecurityType) + sizeof(SecurityType))
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
	uint16_t s_UnderlyingSymbolsForExchangeRequest::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_UnderlyingSymbolsForExchangeRequest::GetRequestID()
	{
		if (BaseSize < offsetof(s_UnderlyingSymbolsForExchangeRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	DTC::SecurityTypeEnum s_UnderlyingSymbolsForExchangeRequest::GetSecurityType()
	{
		if (BaseSize < offsetof(s_UnderlyingSymbolsForExchangeRequest, SecurityType) + sizeof(SecurityType))
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
	uint16_t s_SymbolsForUnderlyingRequest::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_SymbolsForUnderlyingRequest::GetRequestID()
	{
		if (BaseSize < offsetof(s_SymbolsForUnderlyingRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	DTC::SecurityTypeEnum s_SymbolsForUnderlyingRequest::GetSecurityType()
	{
		if (BaseSize < offsetof(s_SymbolsForUnderlyingRequest, SecurityType) + sizeof(SecurityType))
			return (DTC::SecurityTypeEnum)0;

		return SecurityType;
	}


	/****************************************************************************/
	// s_SymbolSearchRequest

	/*==========================================================================*/
	uint16_t s_SymbolSearchRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_SymbolSearchRequest::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_SymbolSearchRequest::GetRequestID()
	{
		if (BaseSize < offsetof(s_SymbolSearchRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	DTC::SecurityTypeEnum s_SymbolSearchRequest::GetSecurityType()
	{
		if (BaseSize < offsetof(s_SymbolSearchRequest, SecurityType) + sizeof(SecurityType))
			return (DTC::SecurityTypeEnum)0;

		return SecurityType;
	}

	/*==========================================================================*/
	DTC::SearchTypeEnum s_SymbolSearchRequest::GetSearchType()
	{
		if (BaseSize < offsetof(s_SymbolSearchRequest, SearchType) + sizeof(SearchType))
			return (DTC::SearchTypeEnum)0;

		return SearchType;
	}

	/****************************************************************************/
	// s_SecurityDefinitionForSymbolRequest

	/*==========================================================================*/
	uint16_t s_SecurityDefinitionForSymbolRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_SecurityDefinitionForSymbolRequest::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_SecurityDefinitionForSymbolRequest::GetRequestID()
	{
		if (BaseSize < offsetof(s_SecurityDefinitionForSymbolRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}


	/****************************************************************************/
	// s_SecurityDefinitionResponse

	/*==========================================================================*/
	uint16_t s_SecurityDefinitionResponse::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_SecurityDefinitionResponse::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_SecurityDefinitionResponse::GetRequestID() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	DTC::SecurityTypeEnum s_SecurityDefinitionResponse::GetSecurityType() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, SecurityType) + sizeof(SecurityType))
			return DTC::SECURITY_TYPE_UNSET;

		return SecurityType;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetMinPriceIncrement() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, MinPriceIncrement) + sizeof(MinPriceIncrement))
			return 0.0;

		return MinPriceIncrement;
	}

	/*==========================================================================*/
	DTC::PriceDisplayFormatEnum s_SecurityDefinitionResponse::GetPriceDisplayFormat() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, PriceDisplayFormat) + sizeof(PriceDisplayFormat))
			return DTC::PRICE_DISPLAY_FORMAT_UNSET;

		return PriceDisplayFormat;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetCurrencyValuePerIncrement() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, CurrencyValuePerIncrement) + sizeof(CurrencyValuePerIncrement))
			return 0.0;

		return CurrencyValuePerIncrement;
	}

	/*==========================================================================*/
	uint8_t s_SecurityDefinitionResponse::GetIsFinalMessage() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, IsFinalMessage) + sizeof(IsFinalMessage))
			return 0;

		return IsFinalMessage;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetFloatToIntPriceMultiplier()
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, FloatToIntPriceMultiplier) + sizeof(FloatToIntPriceMultiplier))
			return 1.0f;

		return FloatToIntPriceMultiplier;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetIntToFloatPriceDivisor()
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, IntToFloatPriceDivisor) + sizeof(IntToFloatPriceDivisor))
			return 1.0f;

		return IntToFloatPriceDivisor;
	}

	/*==========================================================================*/
	uint8_t s_SecurityDefinitionResponse::GetUpdatesBidAskOnly() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, UpdatesBidAskOnly) + sizeof(UpdatesBidAskOnly))
			return 0;

		return UpdatesBidAskOnly;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetStrikePrice() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, StrikePrice) + sizeof(StrikePrice))
			return 0.0;

		return StrikePrice;
	}

	/*==========================================================================*/
	DTC::PutCallEnum s_SecurityDefinitionResponse::GetPutOrCall() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, PutOrCall) + sizeof(PutOrCall))
			return DTC::PC_UNSET;

		return PutOrCall;
	}

	/*==========================================================================*/
	uint32_t s_SecurityDefinitionResponse::GetShortInterest() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, ShortInterest) + sizeof(ShortInterest))
			return 0;

		return ShortInterest;
	}

	/*==========================================================================*/
	DTC::t_DateTime4Byte s_SecurityDefinitionResponse::GetSecurityExpirationDate() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, SecurityExpirationDate) + sizeof(SecurityExpirationDate))
			return 0;

		return SecurityExpirationDate;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetBuyRolloverInterest() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, BuyRolloverInterest) + sizeof(BuyRolloverInterest))
			return 0.0;

		return BuyRolloverInterest;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetSellRolloverInterest() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, SellRolloverInterest) + sizeof(SellRolloverInterest))
			return 0.0;

		return SellRolloverInterest;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetEarningsPerShare() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, EarningsPerShare) + sizeof(EarningsPerShare))
			return 0.0;

		return EarningsPerShare;
	}

	/*==========================================================================*/
	uint32_t s_SecurityDefinitionResponse::GetSharesOutstanding() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, SharesOutstanding) + sizeof(SharesOutstanding))
			return 0;

		return SharesOutstanding;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetIntToFloatQuantityDivisor() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, IntToFloatQuantityDivisor) + sizeof(IntToFloatQuantityDivisor))
			return 0.0;

		return IntToFloatQuantityDivisor;
	}

	/*==========================================================================*/
	uint8_t s_SecurityDefinitionResponse::GetHasMarketDepthData() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, HasMarketDepthData) + sizeof(HasMarketDepthData))
			return 1;

		return HasMarketDepthData;
	}

	/*==========================================================================*/
	float s_SecurityDefinitionResponse::GetDisplayPriceMultiplier() const
	{
		if (BaseSize < offsetof(s_SecurityDefinitionResponse, DisplayPriceMultiplier) + sizeof(DisplayPriceMultiplier))
			return 1.0;

		return DisplayPriceMultiplier;
	}

	/****************************************************************************/
	// s_SecurityDefinitionReject

	/*==========================================================================*/
	uint16_t s_SecurityDefinitionReject::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_SecurityDefinitionReject::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_SecurityDefinitionReject::GetRequestID()
	{

		if (BaseSize < offsetof(s_SecurityDefinitionReject, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/****************************************************************************/
	// s_AccountBalanceRequest

	/*==========================================================================*/
	uint16_t s_AccountBalanceRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_AccountBalanceRequest::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_AccountBalanceRequest::GetRequestID()
	{

		if (BaseSize < offsetof(s_AccountBalanceRequest, RequestID) + sizeof(RequestID))
			return 0;

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
	uint16_t s_AccountBalanceReject::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_AccountBalanceReject::GetRequestID()
	{

		if (BaseSize < offsetof(s_AccountBalanceReject, RequestID) + sizeof(RequestID))
			return 0;

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
	uint16_t s_AccountBalanceUpdate::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_AccountBalanceUpdate::GetRequestID()
	{
		if (BaseSize < offsetof(s_AccountBalanceUpdate, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	double s_AccountBalanceUpdate::GetCashBalance() const
	{
		if (BaseSize < offsetof(s_AccountBalanceUpdate, CashBalance) + sizeof(CashBalance))
			return 0;

		return CashBalance;
	}

	/*==========================================================================*/
	double s_AccountBalanceUpdate::GetBalanceAvailableForNewPositions() const
	{
		if (BaseSize < offsetof(s_AccountBalanceUpdate, BalanceAvailableForNewPositions) + sizeof(BalanceAvailableForNewPositions))
			return 0;

		return BalanceAvailableForNewPositions;
	}

	/*==========================================================================*/
	double s_AccountBalanceUpdate::GetSecuritiesValue() const
	{
		if (BaseSize < offsetof(s_AccountBalanceUpdate, SecuritiesValue) + sizeof(SecuritiesValue))
			return 0;

		return SecuritiesValue;
	}

	/*==========================================================================*/
	double s_AccountBalanceUpdate::GetMarginRequirement() const
	{
		if (BaseSize < offsetof(s_AccountBalanceUpdate, MarginRequirement) + sizeof(MarginRequirement))
			return 0;

		return MarginRequirement;
	}

	
	/*==========================================================================*/
	int32_t s_AccountBalanceUpdate::GetTotalNumberMessages() const
	{
		if (BaseSize < offsetof(s_AccountBalanceUpdate, TotalNumberMessages) + sizeof(TotalNumberMessages))
			return 0;

		return TotalNumberMessages;
	}

	/*==========================================================================*/
	int32_t s_AccountBalanceUpdate::GetMessageNumber() const
	{
		if (BaseSize < offsetof(s_AccountBalanceUpdate, MessageNumber) + sizeof(MessageNumber))
			return 0;

		return MessageNumber;
	}

	/*==========================================================================*/
	uint8_t s_AccountBalanceUpdate::GetNoAccountBalances() const
	{
		if (BaseSize < offsetof(s_AccountBalanceUpdate, NoAccountBalances) + sizeof(NoAccountBalances))
			return 0;

		return NoAccountBalances;
	}

	/*==========================================================================*/
	uint8_t s_AccountBalanceUpdate::GetUnsolicited() const
	{
		if (BaseSize < offsetof(s_AccountBalanceUpdate, Unsolicited) + sizeof(Unsolicited))
			return 0;

		return Unsolicited;
	}

	/****************************************************************************/
	// s_UserMessage

	/*==========================================================================*/
	uint16_t s_UserMessage::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_UserMessage::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	uint8_t s_UserMessage::GetIsPopupMessage()
	{
		if (BaseSize < offsetof(s_UserMessage, IsPopupMessage) + sizeof(IsPopupMessage))
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

	/*==========================================================================*/
	uint16_t s_GeneralLogMessage::GetBaseSize()
	{
		return BaseSize;
	}

	/****************************************************************************/
	// s_HistoricalPriceDataRequest

	/*==========================================================================*/
	uint16_t s_HistoricalPriceDataRequest::GetMessageSize()
	{
		return Size;
	}

	/*==========================================================================*/
	uint16_t s_HistoricalPriceDataRequest::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_HistoricalPriceDataRequest::GetRequestID()
	{
		if (BaseSize < offsetof(s_HistoricalPriceDataRequest, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	uint32_t s_HistoricalPriceDataRequest::GetMaxDaysToReturn()
	{
		if (BaseSize < offsetof(s_HistoricalPriceDataRequest, MaxDaysToReturn) + sizeof(MaxDaysToReturn))
			return 0;

		return MaxDaysToReturn;
	}

	/*==========================================================================*/
	DTC::t_DateTime s_HistoricalPriceDataRequest::GetEndDateTime() 
	{
		if (BaseSize < offsetof(s_HistoricalPriceDataRequest, EndDateTime) + sizeof(EndDateTime))
			return 0;

		return EndDateTime;
	}

	/*==========================================================================*/
	DTC::t_DateTime s_HistoricalPriceDataRequest::GetStartDateTime() 
	{
		if (BaseSize < offsetof(s_HistoricalPriceDataRequest, StartDateTime) + sizeof(StartDateTime))
			return 0;

		return StartDateTime;
	}

	/*==========================================================================*/
	DTC::HistoricalDataIntervalEnum s_HistoricalPriceDataRequest::GetRecordInterval()
	{
		if (BaseSize < offsetof(s_HistoricalPriceDataRequest, RecordInterval) + sizeof(RecordInterval))
			return (DTC::HistoricalDataIntervalEnum)0;

		return RecordInterval;
	}

	/*==========================================================================*/
	uint8_t s_HistoricalPriceDataRequest::GetUseZLibCompression()
	{
		if (BaseSize < offsetof(s_HistoricalPriceDataRequest, UseZLibCompression) + sizeof(UseZLibCompression))
			return 0;

		return UseZLibCompression;
	}
	
	/*==========================================================================*/
	uint8_t s_HistoricalPriceDataRequest::GetRequestDividendAdjustedStockData()
	{
		if (BaseSize < offsetof(s_HistoricalPriceDataRequest, RequestDividendAdjustedStockData) + sizeof(RequestDividendAdjustedStockData))
			return 0;

		return RequestDividendAdjustedStockData;
	}
	
	/*==========================================================================*/
	uint8_t s_HistoricalPriceDataRequest::GetFlag_1()
	{
		if (BaseSize < offsetof(s_HistoricalPriceDataRequest, Flag_1) + sizeof(Flag_1))
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
	uint16_t s_HistoricalPriceDataReject::GetBaseSize()
	{
		return BaseSize;
	}

	/*==========================================================================*/
	int32_t s_HistoricalPriceDataReject::GetRequestID()
	{
		if (BaseSize < offsetof(s_HistoricalPriceDataReject, RequestID) + sizeof(RequestID))
			return 0;

		return RequestID;
	}

	/*==========================================================================*/
	DTC::HistoricalPriceDataRejectReasonCodeEnum s_HistoricalPriceDataReject::GetRejectReasonCode()
	{
		if (BaseSize < offsetof(s_HistoricalPriceDataReject, RejectReasonCode) + sizeof(RejectReasonCode))
			return DTC::HPDR_UNSET;

		return RejectReasonCode;
	}

	/*==========================================================================*/
	uint16_t s_HistoricalPriceDataReject::GetRetryTimeInSeconds()
	{
		if (BaseSize < offsetof(s_HistoricalPriceDataReject, RetryTimeInSeconds) + sizeof(RetryTimeInSeconds))
			return 0;

		return RetryTimeInSeconds;
	}

	/*==========================================================================*/
}
