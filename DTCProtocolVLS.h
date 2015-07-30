
// Data and Trading Communications Protocol Variable Length String Encoding (DTC Protocol VLS)

// This protocol is in the public domain and freely usable by anyone.

// Documentation: http://DTCprotocol.org/index.php?page=doc_DTCMessageDocumentation.php

// The byte ordering is little endian.

#pragma once

#include "DTCProtocol.h"

namespace DTC_VLS
{
#pragma pack(8)

	// see DTCProtocol.h for constants and enum values

	/*==========================================================================*/
	struct s_VariableLengthStringField
	{
		uint16_t Offset;
		uint16_t Length;
	};

	typedef s_VariableLengthStringField vls_t;

	/*==========================================================================*/
	inline void AddVariableLengthStringField(uint16_t& BaseStructureSizeField, vls_t& VariableLengthStringField, uint16_t SizeToAdd)
	{
		if (SizeToAdd == 0)
		{
			VariableLengthStringField.Offset = 0;
			VariableLengthStringField.Length = 0;
		}
		else
		{
			VariableLengthStringField.Offset = BaseStructureSizeField;
			VariableLengthStringField.Length = SizeToAdd + 1;
			BaseStructureSizeField += VariableLengthStringField.Length;
		}
	}

	/*==========================================================================*/
	inline const char* GetVariableLengthStringField(const uint16_t& BaseStructureSizeField, const vls_t& VariableLengthStringField, const uint16_t VariableLengthStringFieldOffset)
	{
		if (BaseStructureSizeField < VariableLengthStringFieldOffset + sizeof(vls_t))
			return "";
		else if (VariableLengthStringField.Offset == 0 || VariableLengthStringField.Length <= 1)
			return "";
		else if ((VariableLengthStringField.Offset + VariableLengthStringField.Length) > BaseStructureSizeField)
			return "";
		else
			return (const char*)&BaseStructureSizeField + VariableLengthStringField.Offset;
	}

	/*==========================================================================*/
	struct s_LogonRequest
	{
		uint16_t Size;
		uint16_t Type;
		int32_t ProtocolVersion;
		vls_t Username;
		vls_t Password;
		vls_t GeneralTextData;
		int32_t Integer_1;
		int32_t Integer_2;
		int32_t HeartbeatIntervalInSeconds; 
		DTC::TradeModeEnum TradeMode;
		vls_t TradeAccount; 
		vls_t HardwareIdentifier;
		vls_t ClientName;

		s_LogonRequest()
		{
			memset(this, 0,sizeof(s_LogonRequest));
			Type=DTC::LOGON_REQUEST;
			Size=sizeof(s_LogonRequest);
			ProtocolVersion = DTC::CURRENT_VERSION;
		}

		uint16_t GetMessageSize();
		int32_t GetProtocolVersion();
		const char* GetUsername() const { return GetVariableLengthStringField(Size, Username, offsetof(s_LogonRequest, Username)); }
		void AddUsername(unsigned int StringLength) { AddVariableLengthStringField(Size, Username, StringLength); }
		const char* GetPassword() const { return GetVariableLengthStringField(Size, Password, offsetof(s_LogonRequest, Password)); }
		void AddPassword(unsigned int StringLength) { AddVariableLengthStringField(Size, Password, StringLength); }
		const char* GetGeneralTextData() const { return GetVariableLengthStringField(Size, GeneralTextData, offsetof(s_LogonRequest, GeneralTextData)); }
		void AddGeneralTextData(unsigned int StringLength) { AddVariableLengthStringField(Size, GeneralTextData, StringLength); }
		int32_t GetInteger_1();
		int32_t GetInteger_2();
		int32_t GetHeartbeatIntervalInSeconds();
		DTC::TradeModeEnum GetTradeMode();
		const char* GetTradeAccount() const { return GetVariableLengthStringField(Size, TradeAccount, offsetof(s_LogonRequest, TradeAccount)); }
		void AddTradeAccount(unsigned int StringLength) { AddVariableLengthStringField(Size, TradeAccount, StringLength); }
		const char* GetHardwareIdentifier() const { return GetVariableLengthStringField(Size, HardwareIdentifier, offsetof(s_LogonRequest, HardwareIdentifier)); }
		void AddHardwareIdentifier(unsigned int StringLength) { AddVariableLengthStringField(Size, HardwareIdentifier, StringLength); }
		const char* GetClientName() const { return GetVariableLengthStringField(Size, ClientName, offsetof(s_LogonRequest, ClientName)); }
		void AddClientName(unsigned int StringLength) { AddVariableLengthStringField(Size, ClientName, StringLength); }
	};

	/*==========================================================================*/
	struct s_LogonResponse
	{
		uint16_t Size;
		uint16_t Type;
		int32_t ProtocolVersion;
		DTC::LogonStatusEnum Result;
		vls_t ResultText;
		vls_t ReconnectAddress;
		int32_t Integer_1;
		vls_t ServerName;
		byte MarketDepthUpdatesBestBidAndAsk;
		byte TradingIsSupported;
		byte OCOOrdersSupported;
		byte OrderCancelReplaceSupported;
		vls_t SymbolExchangeDelimiter;
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
			Type=DTC::LOGON_RESPONSE;
			Size=sizeof(s_LogonResponse);
			ProtocolVersion = DTC::CURRENT_VERSION;
			OrderCancelReplaceSupported = 1;
			MarketDepthIsSupported = 1;
		}

		uint16_t GetMessageSize();
		int32_t GetProtocolVersion();
		DTC::LogonStatusEnum GetResult();
		int32_t GetInteger_1();
		byte GetMarketDepthUpdatesBestBidAndAsk();
		byte GetTradingIsSupported();
		byte GetOCOOrdersSupported();
		byte GetOrderCancelReplaceSupported();
		byte GetSecurityDefinitionsSupported();
		byte GetHistoricalPriceDataSupported();
		byte GetResubscribeWhenMarketDataFeedAvailable();
		byte GetMarketDepthIsSupported();
		byte GetOneHistoricalPriceDataRequestPerConnection();
		byte GetUseIntegerPriceOrderMessages();
		byte GetBracketOrdersSupported();
		const char* GetResultText() const { return GetVariableLengthStringField(Size, ResultText, offsetof(s_LogonResponse, ResultText)); }
		void AddResultText(unsigned int StringLength) { AddVariableLengthStringField(Size, ResultText, StringLength); }
		const char* GetReconnectAddress() const { return GetVariableLengthStringField(Size, ReconnectAddress, offsetof(s_LogonResponse, ReconnectAddress)); }
		void AddReconnectAddress(unsigned int StringLength) { AddVariableLengthStringField(Size, ReconnectAddress, StringLength); }
		const char* GetServerName() const { return GetVariableLengthStringField(Size, ServerName, offsetof(s_LogonResponse, ServerName)); }
		void AddServerName(unsigned int StringLength) { AddVariableLengthStringField(Size, ServerName, StringLength); }
		const char* GetSymbolExchangeDelimiter() const { return GetVariableLengthStringField(Size, SymbolExchangeDelimiter, offsetof(s_LogonResponse, SymbolExchangeDelimiter)); }
		void AddSymbolExchangeDelimiter(unsigned int StringLength) { AddVariableLengthStringField(Size, SymbolExchangeDelimiter, StringLength); }
	};

	/*==========================================================================*/
	struct s_Logoff
	{
		uint16_t Size;
		uint16_t Type;
		vls_t Reason;
		byte DoNotReconnect;

		s_Logoff()
		{
			memset(this, 0, sizeof(s_Logoff));
			Type = DTC::LOGOFF;
			Size=sizeof(s_Logoff);
		}

		uint16_t GetMessageSize();
		const char* GetReason() const { return GetVariableLengthStringField(Size, Reason, offsetof(s_Logoff, Reason)); }
		void AddReason(unsigned int StringLength) { AddVariableLengthStringField(Size, Reason, StringLength); }
		byte GetDoNotReconnect();
	};


	/*==========================================================================*/
	struct s_MarketDataRequest
	{
		uint16_t Size;
		uint16_t Type;
		DTC::RequestActionEnum RequestAction;
		uint16_t SymbolID;
		vls_t Symbol;
		vls_t Exchange;

		s_MarketDataRequest()
		{
			memset(this, 0,sizeof(s_MarketDataRequest));
			Type=DTC::MARKET_DATA_REQUEST;
			Size=sizeof(s_MarketDataRequest);
			RequestAction=DTC::SUBSCRIBE;
		}
		
		uint16_t GetMessageSize();
		DTC::RequestActionEnum GetRequestAction();
		uint16_t GetSymbolID();
		const char* GetSymbol() const { return GetVariableLengthStringField(Size, Symbol, offsetof(s_MarketDataRequest, Symbol)); }
		void AddSymbol(unsigned int StringLength) { AddVariableLengthStringField(Size, Symbol, StringLength); }
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_MarketDataRequest, Symbol)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
	};

	/*==========================================================================*/
	struct s_MarketDepthRequest
	{
		uint16_t Size;
		uint16_t Type;
		DTC::RequestActionEnum RequestAction;
		uint16_t SymbolID;
		vls_t Symbol;
		vls_t Exchange;
		int32_t NumLevels;

		s_MarketDepthRequest()
		{
			memset(this, 0,sizeof(s_MarketDepthRequest));
			Type=DTC::MARKET_DEPTH_REQUEST;
			Size=sizeof(s_MarketDepthRequest);

			RequestAction=DTC::SUBSCRIBE;
			NumLevels= 10;
		}
		
		uint16_t GetMessageSize();
		DTC::RequestActionEnum GetRequestAction();
		uint16_t GetSymbolID();
		const char* GetSymbol() const { return GetVariableLengthStringField(Size, Symbol, offsetof(s_MarketDepthRequest, Symbol)); }
		void AddSymbol(unsigned int StringLength) { AddVariableLengthStringField(Size, Symbol, StringLength); }
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_MarketDepthRequest, Exchange)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
		int32_t GetNumLevels();
	};

	/*==========================================================================*/
	struct s_MarketDataReject
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t SymbolID;
		vls_t RejectText;

		s_MarketDataReject()
		{
			memset(this, 0,sizeof(s_MarketDataReject));
			Type=DTC::MARKET_DATA_REJECT;
			Size=sizeof(s_MarketDataReject);
		}
		
		uint16_t GetMessageSize();
		uint16_t GetSymbolID();
		const char* GetRejectText() const { return GetVariableLengthStringField(Size, RejectText, offsetof(s_MarketDataReject, RejectText)); }
		void AddRejectText(unsigned int StringLength) { AddVariableLengthStringField(Size, RejectText, StringLength); }
	};


	/*==========================================================================*/
	struct s_MarketDepthReject
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t SymbolID;
		vls_t RejectText;

		s_MarketDepthReject()
		{
			memset(this, 0, sizeof(s_MarketDepthReject));
			Type = DTC::MARKET_DEPTH_REJECT;
			Size = sizeof(s_MarketDepthReject);
		}

		uint16_t GetMessageSize();
		uint16_t GetSymbolID();
		const char* GetRejectText() const { return GetVariableLengthStringField(Size, RejectText, offsetof(s_MarketDepthReject, RejectText)); }
		void AddRejectText(unsigned int StringLength) { AddVariableLengthStringField(Size, RejectText, StringLength); }
	};


	/*==========================================================================*/
	struct s_FundamentalDataRequest
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t SymbolID;

		vls_t Symbol;
		vls_t Exchange;

		s_FundamentalDataRequest()
		{
			memset(this, 0,sizeof(s_FundamentalDataRequest));
			Type=DTC::FUNDAMENTAL_DATA_REQUEST;
			Size=sizeof(s_FundamentalDataRequest);
		}

		uint16_t GetMessageSize();
		uint16_t GetSymbolID();
		const char* GetSymbol() const { return GetVariableLengthStringField(Size, Symbol, offsetof(s_FundamentalDataRequest, Symbol)); }
		void AddSymbol(unsigned int StringLength) { AddVariableLengthStringField(Size, Symbol, StringLength); }
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_FundamentalDataRequest, Exchange)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
	};

	/*==========================================================================*/
	struct s_FundamentalDataResponse
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t SymbolID;
		vls_t SymbolDescription;
		float MinPriceIncrement;
		float CurrencyValuePerIncrement;
		DTC::PriceDisplayFormatEnum PriceDisplayFormat;
		float BuyRolloverInterest;
		float SellRolloverInterest;
		float OrderIntPriceMultiplier;
		float MarketDataIntPriceDivisor;
		DTC::SecurityTypeEnum SecurityType;

		DTC::t_DateTime4Byte SecurityExpirationDate;

		uint16_t ShortInterest;

		float EarningsPerShare;

		float DividendYield;
		float DividendAmount;
		DTC::t_DateTime4Byte ExDividendDate;

		float StrikePrice;//For options

		s_FundamentalDataResponse()
		{
			memset(this, 0,sizeof(s_FundamentalDataResponse));
			Type=DTC::FUNDAMENTAL_DATA_RESPONSE;
			Size=sizeof(s_FundamentalDataResponse);
			PriceDisplayFormat = DTC::PRICE_DISPLAY_FORMAT_UNSET;
			OrderIntPriceMultiplier = 1.0;
			MarketDataIntPriceDivisor = 1.0;
		}

		uint16_t GetMessageSize();
		uint16_t GetSymbolID();
		float GetMinPriceIncrement();
		float GetCurrencyValuePerIncrement();
		DTC::PriceDisplayFormatEnum GetPriceDisplayFormat();
		float GetBuyRolloverInterest();
		float GetSellRolloverInterest();
		float GetOrderIntPriceMultiplier();
		float GetMarketDataIntPriceDivisor();
		DTC::SecurityTypeEnum GetSecurityType();
		DTC::t_DateTime4Byte GetSecurityExpirationDate();
		uint16_t GetShortInterest();
		float GetEarningsPerShare();
		float GetDividendYield();
		float GetDividendAmount();
		DTC::t_DateTime4Byte GetExDividendDate();
		float GetStrikePrice();

		const char* GetSymbolDescription() const { return GetVariableLengthStringField(Size, SymbolDescription, offsetof(s_FundamentalDataResponse, SymbolDescription)); }
		void AddSymbolDescription(unsigned int StringLength) { AddVariableLengthStringField(Size, SymbolDescription, StringLength); }
	};

	/*==========================================================================*/
	struct s_SubmitNewSingleOrder
	{
		uint16_t Size;
		uint16_t Type;

		vls_t Symbol;
		vls_t Exchange;

		vls_t TradeAccount;
		vls_t ClientOrderID;

		DTC::OrderTypeEnum OrderType;

		DTC::BuySellEnum BuySell;

		double Price1;
		double Price2;

		double Quantity;

		DTC::TimeInForceEnum TimeInForce;

		DTC::t_DateTime GoodTillDateTime;
		
		byte IsAutomatedOrder;

		byte IsParentOrder;

		vls_t FreeFormText;

		s_SubmitNewSingleOrder()
		{
			memset(this, 0,sizeof(s_SubmitNewSingleOrder));
			Type=DTC::SUBMIT_NEW_SINGLE_ORDER;
			Size=sizeof(s_SubmitNewSingleOrder);
		}

		uint16_t GetMessageSize();
		const char* GetSymbol() const { return GetVariableLengthStringField(Size, Symbol, offsetof(s_SubmitNewSingleOrder, Symbol)); }
		void AddSymbol(unsigned int StringLength) { AddVariableLengthStringField(Size, Symbol, StringLength); }
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_SubmitNewSingleOrder, Exchange)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
		const char* GetTradeAccount() const { return GetVariableLengthStringField(Size, TradeAccount, offsetof(s_SubmitNewSingleOrder, TradeAccount)); }
		void AddTradeAccount(unsigned int StringLength) { AddVariableLengthStringField(Size, TradeAccount, StringLength); }
		const char* GetClientOrderID() const { return GetVariableLengthStringField(Size, ClientOrderID, offsetof(s_SubmitNewSingleOrder, ClientOrderID)); }
		void AddClientOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, ClientOrderID, StringLength); }
		DTC::OrderTypeEnum GetOrderType();	
		DTC::BuySellEnum GetBuySell();	
		double GetPrice1();
		double GetPrice2();
		double GetQuantity();	
		DTC::TimeInForceEnum GetTimeInForce();	
		DTC::t_DateTime GetGoodTillDateTime();
		void SetTradeAccount(const char* NewValue);
		byte GetIsAutomatedOrder();	
		byte GetIsParentOrder();	
		const char* GetFreeFormText() const { return GetVariableLengthStringField(Size, FreeFormText, offsetof(s_SubmitNewSingleOrder, FreeFormText)); }
		void AddFreeFormText(unsigned int StringLength) { AddVariableLengthStringField(Size, FreeFormText, StringLength); }
	};

	/*==========================================================================*/
	struct s_SubmitNewSingleOrderInt
	{
		uint16_t Size;
		uint16_t Type;

		vls_t Symbol;
		vls_t Exchange;

		vls_t TradeAccount;
		vls_t ClientOrderID;

		DTC::OrderTypeEnum OrderType;
		DTC::BuySellEnum BuySell;

		int32_t Price1;
		int32_t Price2;
		float Divisor;
		double Quantity;

		DTC::TimeInForceEnum TimeInForce;
		DTC::t_DateTime GoodTillDateTime;
		
		byte IsAutomatedOrder;
		byte IsParentOrder;

		vls_t FreeFormText;

		s_SubmitNewSingleOrderInt()
		{
			memset(this, 0,sizeof(s_SubmitNewSingleOrderInt));
			Type=DTC::SUBMIT_NEW_SINGLE_ORDER_INT;
			Size=sizeof(s_SubmitNewSingleOrderInt);
		}
		
		uint16_t GetMessageSize();
		const char* GetSymbol() const { return GetVariableLengthStringField(Size, Symbol, offsetof(s_SubmitNewSingleOrderInt, Symbol)); }
		void AddSymbol(unsigned int StringLength) { AddVariableLengthStringField(Size, Symbol, StringLength); }
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_SubmitNewSingleOrderInt, Exchange)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
		const char* GetTradeAccount() const { return GetVariableLengthStringField(Size, TradeAccount, offsetof(s_SubmitNewSingleOrderInt, TradeAccount)); }
		void AddTradeAccount(unsigned int StringLength) { AddVariableLengthStringField(Size, TradeAccount, StringLength); }
		const char* GetClientOrderID() const { return GetVariableLengthStringField(Size, ClientOrderID, offsetof(s_SubmitNewSingleOrderInt, ClientOrderID)); }
		void AddClientOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, ClientOrderID, StringLength); }
		DTC::OrderTypeEnum GetOrderType();	
		DTC::BuySellEnum GetBuySell();	
		int32_t GetPrice1();
		int32_t GetPrice2();
		float GetDivisor();
		double GetQuantity();	
		DTC::TimeInForceEnum GetTimeInForce();	
		DTC::t_DateTime GetGoodTillDateTime();
		byte GetIsAutomatedOrder();	
		byte GetIsParentOrder();	
		const char* GetFreeFormText() const { return GetVariableLengthStringField(Size, FreeFormText, offsetof(s_SubmitNewSingleOrderInt, FreeFormText)); }
		void AddFreeFormText(unsigned int StringLength) { AddVariableLengthStringField(Size, FreeFormText, StringLength); }
	};

	/*==========================================================================*/
	struct s_CancelReplaceOrder
	{
		uint16_t Size;
		uint16_t Type;

		vls_t ServerOrderID;
		vls_t ClientOrderID;

		double Price1;
		double Price2;

		double Quantity;
		int8_t Price1IsSet;
		int8_t Price2IsSet;

		s_CancelReplaceOrder()
		{
			memset(this, 0,sizeof(s_CancelReplaceOrder));
			Type=DTC::CANCEL_REPLACE_ORDER;
			Size=sizeof(s_CancelReplaceOrder);
			Price1IsSet = 1;
			Price2IsSet = 1;
		}
		
		uint16_t GetMessageSize();
		const char* GetServerOrderID() const { return GetVariableLengthStringField(Size, ServerOrderID, offsetof(s_CancelReplaceOrder, ServerOrderID)); }
		void AddServerOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, ServerOrderID, StringLength); }
		const char* GetClientOrderID() const { return GetVariableLengthStringField(Size, ClientOrderID, offsetof(s_CancelReplaceOrder, ClientOrderID)); }
		void AddClientOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, ClientOrderID, StringLength); }
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

		vls_t ServerOrderID;
		vls_t ClientOrderID;

		int32_t Price1;
		int32_t Price2;
		float Divisor;
		double Quantity;
		int8_t Price1IsSet;
		int8_t Price2IsSet;

		s_CancelReplaceOrderInt()
		{
			memset(this, 0,sizeof(s_CancelReplaceOrderInt));
			Type=DTC::CANCEL_REPLACE_ORDER_INT;
			Size=sizeof(s_CancelReplaceOrderInt);
			Divisor = 1.0f;
			Price1IsSet = 1;
			Price2IsSet = 1;
		}
		
		uint16_t GetMessageSize();
		const char* GetServerOrderID() const { return GetVariableLengthStringField(Size, ServerOrderID, offsetof(s_CancelReplaceOrderInt, ServerOrderID)); }
		void AddServerOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, ServerOrderID, StringLength); }
		const char* GetClientOrderID() const { return GetVariableLengthStringField(Size, ClientOrderID, offsetof(s_CancelReplaceOrderInt, ClientOrderID)); }
		void AddClientOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, ClientOrderID, StringLength); }
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
		
		vls_t ServerOrderID;
		vls_t ClientOrderID;

		s_CancelOrder()
		{
			memset(this, 0,sizeof(s_CancelOrder));
			Type=DTC::CANCEL_ORDER;
			Size=sizeof(s_CancelOrder);
		}
		
		uint16_t GetMessageSize();
		const char* GetServerOrderID() const { return GetVariableLengthStringField(Size, ServerOrderID, offsetof(s_CancelOrder, ServerOrderID)); }
		void AddServerOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, ServerOrderID, StringLength); }
		const char* GetClientOrderID() const { return GetVariableLengthStringField(Size, ClientOrderID, offsetof(s_CancelOrder, ClientOrderID)); }
		void AddClientOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, ClientOrderID, StringLength); }
	};

	/*==========================================================================*/
	struct s_SubmitNewOCOOrder
	{
		uint16_t Size;
		uint16_t Type;

		vls_t Symbol;
		vls_t Exchange;

		vls_t ClientOrderID_1;
		DTC::OrderTypeEnum OrderType_1;
		DTC::BuySellEnum BuySell_1;
		double Price1_1;
		double Price2_1;
		double Quantity_1;

		vls_t ClientOrderID_2;
		DTC::OrderTypeEnum OrderType_2;
		DTC::BuySellEnum BuySell_2;
		double Price1_2;
		double Price2_2;
		double Quantity_2;

		DTC::TimeInForceEnum TimeInForce;
		DTC::t_DateTime GoodTillDateTime;

		vls_t TradeAccount;

		byte IsAutomatedOrder;

		vls_t ParentTriggerClientOrderID;

		vls_t FreeFormText;

		s_SubmitNewOCOOrder()
		{
			memset(this, 0,sizeof(s_SubmitNewOCOOrder));
			Type=DTC::SUBMIT_NEW_OCO_ORDER;
			Size=sizeof(s_SubmitNewOCOOrder);
		}
		
		uint16_t GetMessageSize();
		const char* GetClientOrderID_1() const { return GetVariableLengthStringField(Size, ClientOrderID_1, offsetof(s_SubmitNewOCOOrder, ClientOrderID_1)); }
		void AddClientOrderID_1(unsigned int StringLength) { AddVariableLengthStringField(Size, ClientOrderID_1, StringLength); }
		const char* GetClientOrderID_2() const { return GetVariableLengthStringField(Size, ClientOrderID_2, offsetof(s_SubmitNewOCOOrder, ClientOrderID_2)); }
		void AddClientOrderID_2(unsigned int StringLength) { AddVariableLengthStringField(Size, ClientOrderID_2, StringLength); }
		const char* GetFreeFormText() const { return GetVariableLengthStringField(Size, FreeFormText, offsetof(s_SubmitNewOCOOrder, FreeFormText)); }
		void AddFreeFormText(unsigned int StringLength) { AddVariableLengthStringField(Size, FreeFormText, StringLength); }
		const char* GetSymbol() const { return GetVariableLengthStringField(Size, Symbol, offsetof(s_SubmitNewOCOOrder, Symbol)); }
		void AddSymbol(unsigned int StringLength) { AddVariableLengthStringField(Size, Symbol, StringLength); }
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_SubmitNewOCOOrder, Exchange)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
		void AddParentTriggerClientOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, ParentTriggerClientOrderID, StringLength); }
		const char* GetParentTriggerClientOrderID() const { return GetVariableLengthStringField(Size, ParentTriggerClientOrderID, offsetof(s_SubmitNewOCOOrder, ParentTriggerClientOrderID)); }
		const char* GetTradeAccount() const { return GetVariableLengthStringField(Size, TradeAccount, offsetof(s_SubmitNewOCOOrder, TradeAccount)); }
		void AddTradeAccount(unsigned int StringLength) { AddVariableLengthStringField(Size, TradeAccount, StringLength); }
		DTC::OrderTypeEnum GetOrderType_1();
		DTC::OrderTypeEnum GetOrderType_2();
		DTC::BuySellEnum GetBuySell_1();
		DTC::BuySellEnum GetBuySell_2();	
		DTC::TimeInForceEnum GetTimeInForce();
		DTC::t_DateTime GetGoodTillDateTime();
		byte GetIsAutomatedOrder();
		double GetPrice1_1();
		double GetPrice2_1();
		double GetPrice1_2();
		double GetPrice2_2();
		double GetQuantity_1();
		double GetQuantity_2();
	};

	/*==========================================================================*/
	struct s_SubmitNewOCOOrderInt
	{
		uint16_t Size;
		uint16_t Type;

		vls_t Symbol;
		vls_t Exchange;

		vls_t ClientOrderID_1;
		DTC::OrderTypeEnum OrderType_1;
		DTC::BuySellEnum BuySell_1;
		int32_t Price1_1;
		int32_t Price2_1;
		double Quantity_1;

		vls_t ClientOrderID_2;
		DTC::OrderTypeEnum OrderType_2;
		DTC::BuySellEnum BuySell_2;
		int32_t Price1_2;
		int32_t Price2_2;
		double Quantity_2;

		DTC::TimeInForceEnum TimeInForce;
		DTC::t_DateTime GoodTillDateTime;

		vls_t TradeAccount;

		byte IsAutomatedOrder;

		vls_t ParentTriggerClientOrderID;

		vls_t FreeFormText;

		float Divisor;

		s_SubmitNewOCOOrderInt()
		{
			memset(this, 0,sizeof(s_SubmitNewOCOOrderInt));
			Type=DTC::SUBMIT_NEW_OCO_ORDER_INT;
			Size=sizeof(s_SubmitNewOCOOrderInt);
		}
		
		uint16_t GetMessageSize();
		void AddClientOrderID_1(unsigned int StringLength) { AddVariableLengthStringField(Size, ClientOrderID_1, StringLength); }
		void AddClientOrderID_2(unsigned int StringLength) { AddVariableLengthStringField(Size, ClientOrderID_2, StringLength); }
		const char* GetFreeFormText() const { return GetVariableLengthStringField(Size, FreeFormText, offsetof(s_SubmitNewOCOOrderInt, FreeFormText)); }
		void AddFreeFormText(unsigned int StringLength) { AddVariableLengthStringField(Size, FreeFormText, StringLength); }
		const char* GetClientOrderID_1() const { return GetVariableLengthStringField(Size, ClientOrderID_1, offsetof(s_SubmitNewOCOOrderInt, ClientOrderID_1)); }
		const char* GetClientOrderID_2() const { return GetVariableLengthStringField(Size, ClientOrderID_2, offsetof(s_SubmitNewOCOOrderInt, ClientOrderID_2)); }
		const char* GetSymbol() const { return GetVariableLengthStringField(Size, Symbol, offsetof(s_SubmitNewOCOOrderInt, Symbol)); }
		void AddSymbol(unsigned int StringLength) { AddVariableLengthStringField(Size, Symbol, StringLength); }
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_SubmitNewOCOOrderInt, Exchange)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
		void AddParentTriggerClientOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, ParentTriggerClientOrderID, StringLength); }
		const char* GetParentTriggerClientOrderID() const { return GetVariableLengthStringField(Size, ParentTriggerClientOrderID, offsetof(s_SubmitNewOCOOrderInt, ParentTriggerClientOrderID)); }
		const char* GetTradeAccount() const { return GetVariableLengthStringField(Size, TradeAccount, offsetof(s_SubmitNewOCOOrderInt, TradeAccount)); }
		void AddTradeAccount(unsigned int StringLength) { AddVariableLengthStringField(Size, TradeAccount, StringLength); }
		DTC::OrderTypeEnum GetOrderType_1();
		DTC::OrderTypeEnum GetOrderType_2();
		DTC::BuySellEnum GetBuySell_1();
		DTC::BuySellEnum GetBuySell_2();	
		DTC::TimeInForceEnum GetTimeInForce();
		DTC::t_DateTime GetGoodTillDateTime();
		byte GetIsAutomatedOrder();
		int32_t GetPrice1_1();
		int32_t GetPrice2_1();
		int32_t GetPrice1_2();
		int32_t GetPrice2_2();
		float GetDivisor();
		double GetQuantity_1();
		double GetQuantity_2();
	};

	/*==========================================================================*/
	struct s_OpenOrdersRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		int32_t RequestAllOrders;

		vls_t ServerOrderID;

		s_OpenOrdersRequest()
		{

			memset(this, 0,sizeof(s_OpenOrdersRequest));
			Type=DTC::OPEN_ORDERS_REQUEST;
			Size=sizeof(s_OpenOrdersRequest);
			RequestAllOrders = 1;
		}
		
		uint16_t GetMessageSize();
		int32_t GetRequestID();
		int32_t GetRequestAllOrders();
		void AddServerOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, ServerOrderID, StringLength); }
		const char* GetServerOrderID() const { return GetVariableLengthStringField(Size, ServerOrderID, offsetof(s_OpenOrdersRequest, ServerOrderID)); }
	};

	/*==========================================================================*/
	struct s_HistoricalOrderFillsRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		vls_t ServerOrderID;

		int32_t NumberOfDays;

		vls_t TradeAccount;

		s_HistoricalOrderFillsRequest()
		{
			memset(this, 0,sizeof(s_HistoricalOrderFillsRequest));
			Type=DTC::HISTORICAL_ORDER_FILLS_REQUEST;
			Size=sizeof(s_HistoricalOrderFillsRequest);
		}
		
		uint16_t GetMessageSize();
		int32_t GetRequestID();
		int32_t GetNumberOfDays();
		void AddServerOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, ServerOrderID, StringLength); }
		const char* GetServerOrderID() const { return GetVariableLengthStringField(Size, ServerOrderID, offsetof(s_HistoricalOrderFillsRequest, ServerOrderID)); }
		void AddTradeAccount(unsigned int StringLength) { AddVariableLengthStringField(Size, TradeAccount, StringLength); }
		const char* GetTradeAccount() const { return GetVariableLengthStringField(Size, TradeAccount, offsetof(s_HistoricalOrderFillsRequest, TradeAccount)); }
	};

	/*==========================================================================*/
	struct s_CurrentPositionsRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		vls_t  TradeAccount;

		s_CurrentPositionsRequest()
		{
			memset(this, 0,sizeof(s_CurrentPositionsRequest));
			Type=DTC::CURRENT_POSITIONS_REQUEST;
			Size=sizeof(s_CurrentPositionsRequest);
		}
		
		uint16_t GetMessageSize();
		int32_t GetRequestID();
		void AddTradeAccount(unsigned int StringLength) { AddVariableLengthStringField(Size, TradeAccount, StringLength); }
		const char* GetTradeAccount() const { return GetVariableLengthStringField(Size, TradeAccount, offsetof(s_CurrentPositionsRequest, TradeAccount)); }
	};

	/*==========================================================================*/
	struct s_CurrentPositionsReject
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		vls_t RejectText;

		s_CurrentPositionsReject()
		{
			memset(this, 0,sizeof(s_CurrentPositionsReject));
			Type=DTC::CURRENT_POSITIONS_REJECT;
			Size=sizeof(s_CurrentPositionsReject);
		}

		uint16_t GetMessageSize();
		int32_t GetRequestID();
		void AddRejectText(unsigned int StringLength) { AddVariableLengthStringField(Size, RejectText, StringLength); }
		const char* GetRejectText() const { return GetVariableLengthStringField(Size, RejectText, offsetof(s_CurrentPositionsReject, RejectText)); }
	};

	/*==========================================================================*/
	struct s_OrderUpdate
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		int32_t TotalNumMessages;
		int32_t MessageNumber;

		vls_t Symbol;
		vls_t Exchange;

		vls_t PreviousServerOrderID;

		vls_t ServerOrderID;

		vls_t ClientOrderID;

		vls_t ExchangeOrderID;

		DTC::OrderStatusEnum OrderStatus;

		DTC::OrderUpdateReasonEnum OrderUpdateReason;

		DTC::OrderTypeEnum OrderType;

		DTC::BuySellEnum BuySell;

		double Price1;

		double Price2;

		DTC::TimeInForceEnum TimeInForce;
		DTC::t_DateTime GoodTillDateTime;
		double OrderQuantity;
		double FilledQuantity;
		double RemainingQuantity;
		double AverageFillPrice;

		double LastFillPrice;
		DTC::t_DateTime LastFillDateTime;
		double LastFillQuantity;
		vls_t UniqueFillExecutionID;

		vls_t TradeAccount;
		vls_t InfoText;

		byte NoOrders;
		vls_t ParentServerOrderID;
		vls_t OCOLinkedOrderServerOrderID;

		s_OrderUpdate()
		{
			memset(this, 0,sizeof(s_OrderUpdate));
			Type=DTC::ORDER_UPDATE;
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
		const char* GetSymbol() const { return GetVariableLengthStringField(Size, Symbol, offsetof(s_OrderUpdate, Symbol)); }
		void AddSymbol(unsigned int StringLength) { AddVariableLengthStringField(Size, Symbol, StringLength); }
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_OrderUpdate, Exchange)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
		const char* GetPreviousServerOrderID() const { return GetVariableLengthStringField(Size, PreviousServerOrderID, offsetof(s_OrderUpdate, PreviousServerOrderID)); }
		void AddPreviousServerOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, PreviousServerOrderID, StringLength); }
		const char* GetServerOrderID() const { return GetVariableLengthStringField(Size, ServerOrderID, offsetof(s_OrderUpdate, ServerOrderID)); }
		void AddServerOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, ServerOrderID, StringLength); }
		const char* GetClientOrderID() const { return GetVariableLengthStringField(Size, ClientOrderID, offsetof(s_OrderUpdate, ClientOrderID)); }
		void AddClientOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, ClientOrderID, StringLength); }
		const char* GetExchangeOrderID() const { return GetVariableLengthStringField(Size, ExchangeOrderID, offsetof(s_OrderUpdate, ExchangeOrderID)); }
		void AddExchangeOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, ExchangeOrderID, StringLength); }
		void AddUniqueFillExecutionID(unsigned int StringLength) { AddVariableLengthStringField(Size, UniqueFillExecutionID, StringLength); }
		const char* GetUniqueFillExecutionID() const { return GetVariableLengthStringField(Size, UniqueFillExecutionID, offsetof(s_OrderUpdate, UniqueFillExecutionID)); }
		const char* GetTradeAccount() const { return GetVariableLengthStringField(Size, TradeAccount, offsetof(s_OrderUpdate, TradeAccount)); }
		void AddTradeAccount(unsigned int StringLength) { AddVariableLengthStringField(Size, TradeAccount, StringLength); }
		const char* GetInfoText() const { return GetVariableLengthStringField(Size, InfoText, offsetof(s_OrderUpdate, InfoText)); }
		void AddInfoText(unsigned int StringLength) { AddVariableLengthStringField(Size, InfoText, StringLength); }
		const char* GetParentServerOrderID() const { return GetVariableLengthStringField(Size, ParentServerOrderID, offsetof(s_OrderUpdate, ParentServerOrderID)); }
		void AddParentServerOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, ParentServerOrderID, StringLength); }
		const char* GetOCOLinkedOrderServerOrderID() const { return GetVariableLengthStringField(Size, OCOLinkedOrderServerOrderID, offsetof(s_OrderUpdate, OCOLinkedOrderServerOrderID)); }
		void AddOCOLinkedOrderServerOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, OCOLinkedOrderServerOrderID, StringLength); }
		double GetOrderQuantity();
		double GetFilledQuantity();
		double GetRemainingQuantity();
		double GetLastFillQuantity();
		int32_t GetRequestID();
		int32_t GetMessageNumber();
		int32_t GetTotalNumMessages();
		DTC::OrderStatusEnum GetOrderStatus();	
		DTC::OrderUpdateReasonEnum GetOrderUpdateReason();	
		DTC::OrderTypeEnum GetOrderType();	
		DTC::BuySellEnum GetBuySell();	
		double GetPrice1();
		double GetPrice2();		
		DTC::TimeInForceEnum GetTimeInForce();	
		DTC::t_DateTime GetGoodTillDateTime();	
		double GetAverageFillPrice();
		double GetLastFillPrice();	
		DTC::t_DateTime GetLastFillDateTime();	
		byte GetNoOrders();
	};
	
	/*==========================================================================*/
	struct s_OpenOrdersReject
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		vls_t RejectText;

		s_OpenOrdersReject()
		{
			memset(this, 0,sizeof(s_OpenOrdersReject));
			Type = DTC::OPEN_ORDERS_REJECT;
			Size=sizeof(s_OpenOrdersReject);
		}
		
		uint16_t GetMessageSize();
		int32_t GetRequestID();
		const char* GetRejectText() const { return GetVariableLengthStringField(Size, RejectText, offsetof(s_OpenOrdersReject, RejectText)); }
		void AddRejectText(unsigned int StringLength) { AddVariableLengthStringField(Size, RejectText, StringLength); }
	};

	/*==========================================================================*/
	struct s_HistoricalOrderFillResponse
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID; 

		int32_t TotalNumberMessages;

		int32_t MessageNumber;

		vls_t Symbol;
		vls_t Exchange;
		vls_t ServerOrderID;
		DTC::BuySellEnum BuySell;
		double Price;
		DTC::t_DateTime DateTime;
		double Quantity;
		vls_t UniqueExecutionID;
		vls_t TradeAccount;

		DTC::OpenCloseTradeEnum OpenClose; 

		byte NoOrderFills;

		s_HistoricalOrderFillResponse()
		{
			memset(this, 0,sizeof(s_HistoricalOrderFillResponse));
			Type=DTC::HISTORICAL_ORDER_FILL_RESPONSE;
			Size=sizeof(s_HistoricalOrderFillResponse);
		}
		
		uint16_t GetMessageSize();
		const char* GetSymbol() const { return GetVariableLengthStringField(Size, Symbol, offsetof(s_HistoricalOrderFillResponse, Symbol)); }
		void AddSymbol(unsigned int StringLength) { AddVariableLengthStringField(Size, Symbol, StringLength); }
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_HistoricalOrderFillResponse, Exchange)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
		const char* GetServerOrderID() const { return GetVariableLengthStringField(Size, ServerOrderID, offsetof(s_HistoricalOrderFillResponse, ServerOrderID)); }
		void AddServerOrderID(unsigned int StringLength) { AddVariableLengthStringField(Size, ServerOrderID, StringLength); }
		void AddTradeAccount(unsigned int StringLength) { AddVariableLengthStringField(Size, TradeAccount, StringLength); }
		const char* GetTradeAccount() const { return GetVariableLengthStringField(Size, TradeAccount, offsetof(s_HistoricalOrderFillResponse, TradeAccount)); }
		void AddUniqueExecutionID(unsigned int StringLength) { AddVariableLengthStringField(Size, UniqueExecutionID, StringLength); }
		const char* GetUniqueExecutionID() const { return GetVariableLengthStringField(Size, UniqueExecutionID, offsetof(s_HistoricalOrderFillResponse, UniqueExecutionID)); }
		int32_t GetRequestID();
		int32_t GetMessageNumber();
		int32_t GetTotalNumberMessages();		
		DTC::BuySellEnum GetBuySell();
		double GetPrice();
		DTC::t_DateTime GetDateTime();
		double GetQuantity();
		DTC::OpenCloseTradeEnum GetOpenClose();	
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

		vls_t Symbol;
		vls_t Exchange;

		double Quantity;
		double AveragePrice;

		vls_t PositionIdentifier;

		vls_t TradeAccount;
		byte NoPositions;

		byte Unsolicited;

		s_PositionUpdate()
		{
			memset(this, 0,sizeof(s_PositionUpdate));
			Type=DTC::POSITION_UPDATE;
			Size=sizeof(s_PositionUpdate);
		}

		uint16_t GetMessageSize();
		void AddSymbol(unsigned int StringLength) { AddVariableLengthStringField(Size, Symbol, StringLength); }
		const char* GetSymbol() const { return GetVariableLengthStringField(Size, Symbol, offsetof(s_PositionUpdate, Symbol)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_PositionUpdate, Exchange)); }
		void AddPositionIdentifier(unsigned int StringLength) { AddVariableLengthStringField(Size, PositionIdentifier, StringLength); }
		const char* GetPositionIdentifier() const { return GetVariableLengthStringField(Size, PositionIdentifier, offsetof(s_PositionUpdate, PositionIdentifier)); }
		void AddTradeAccount(unsigned int StringLength) { AddVariableLengthStringField(Size, TradeAccount, StringLength); }
		const char* GetTradeAccount() const { return GetVariableLengthStringField(Size, TradeAccount, offsetof(s_PositionUpdate, TradeAccount)); }
		int32_t GetRequestID();
		int32_t GetTotalNumberMessages();
		int32_t GetMessageNumber();
		double GetQuantity();
		double GetAveragePrice();
		byte GetNoPositions();
		byte GetUnsolicited();
	};

	/*==========================================================================*/
	struct s_TradeAccountResponse
	{
		uint16_t Size;
		uint16_t Type;

		int32_t TotalNumberMessages;

		int32_t MessageNumber;

		vls_t TradeAccount;

		s_TradeAccountResponse()
		{
			memset(this, 0,sizeof(s_TradeAccountResponse));
			Type=DTC::TRADE_ACCOUNT_RESPONSE;
			Size=sizeof(s_TradeAccountResponse);
		}

		uint16_t GetMessageSize();
		int32_t GetTotalNumberMessages();
		int32_t GetMessageNumber();
		void AddTradeAccount(unsigned int StringLength) { AddVariableLengthStringField(Size, TradeAccount, StringLength); }
		const char* GetTradeAccount() const { return GetVariableLengthStringField(Size, TradeAccount, offsetof(s_TradeAccountResponse, TradeAccount)); }
	};

	/*==========================================================================*/
	struct s_ExchangeListResponse
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		vls_t Exchange;
		byte IsFinalMessage;
		vls_t Description;

		s_ExchangeListResponse()
		{
			memset(this, 0,sizeof(s_ExchangeListResponse));
			Type=DTC::EXCHANGE_LIST_RESPONSE;
			Size=sizeof(s_ExchangeListResponse);
		}

		uint16_t GetMessageSize();
		int32_t GetRequestID();
		byte GetIsFinalMessage();
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_ExchangeListResponse, Exchange)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
		const char* GetDescription() const { return GetVariableLengthStringField(Size, Description, offsetof(s_ExchangeListResponse, Description)); }
		void AddDescription(unsigned int StringLength) { AddVariableLengthStringField(Size, Description, StringLength); }
	};

	/*==========================================================================*/
	struct s_SymbolsForExchangeRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		vls_t Exchange;

		DTC::SecurityTypeEnum SecurityType;

		s_SymbolsForExchangeRequest()
		{
			memset(this, 0,sizeof(s_SymbolsForExchangeRequest));
			Type=DTC::SYMBOLS_FOR_EXCHANGE_REQUEST;
			Size=sizeof(s_SymbolsForExchangeRequest);
		}

		uint16_t GetMessageSize();
		int32_t GetRequestID();
		DTC::SecurityTypeEnum GetSecurityType();
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_SymbolsForExchangeRequest, Exchange)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
	};

	/*==========================================================================*/
	struct s_UnderlyingSymbolsForExchangeRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		vls_t Exchange;

		DTC::SecurityTypeEnum SecurityType;

		s_UnderlyingSymbolsForExchangeRequest()
		{
			memset(this, 0,sizeof(s_UnderlyingSymbolsForExchangeRequest));
			Type=DTC::UNDERLYING_SYMBOLS_FOR_EXCHANGE_REQUEST;
			Size=sizeof(s_UnderlyingSymbolsForExchangeRequest);
		}
		
		uint16_t GetMessageSize();
		int32_t GetRequestID();
		DTC::SecurityTypeEnum GetSecurityType();
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_UnderlyingSymbolsForExchangeRequest, Exchange)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
	};

	/*==========================================================================*/
	struct s_SymbolsForUnderlyingRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		vls_t UnderlyingSymbol;
		vls_t Exchange;

		DTC::SecurityTypeEnum SecurityType;

		s_SymbolsForUnderlyingRequest()
		{
			memset(this, 0,sizeof(s_SymbolsForUnderlyingRequest));
			Type=DTC::SYMBOLS_FOR_UNDERLYING_REQUEST;
			Size=sizeof(s_SymbolsForUnderlyingRequest);
		}

		uint16_t GetMessageSize();
		int32_t GetRequestID();
		DTC::SecurityTypeEnum GetSecurityType();
		const char* GetUnderlyingSymbol() const { return GetVariableLengthStringField(Size, UnderlyingSymbol, offsetof(s_SymbolsForUnderlyingRequest, UnderlyingSymbol)); }
		void AddUnderlyingSymbol(unsigned int StringLength) { AddVariableLengthStringField(Size, UnderlyingSymbol, StringLength); }
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_SymbolsForUnderlyingRequest, Exchange)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
	};

	/*==========================================================================*/
	struct s_SymbolSearchByDescription
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		vls_t Exchange;
		vls_t SymbolDescription;

		DTC::SecurityTypeEnum SecurityType;

		s_SymbolSearchByDescription()
		{
			memset(this, 0, sizeof(s_SymbolSearchByDescription));
			Type = DTC::SYMBOL_SEARCH_BY_DESCRIPTION;
			Size=sizeof(s_SymbolSearchByDescription);
		}

		uint16_t GetMessageSize();
		int32_t GetRequestID();
		DTC::SecurityTypeEnum GetSecurityType();
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_SymbolSearchByDescription, Exchange)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
		const char* GetSymbolDescription() const { return GetVariableLengthStringField(Size, SymbolDescription, offsetof(s_SymbolSearchByDescription, SymbolDescription)); }
		void AddSymbolDescription(unsigned int StringLength) { AddVariableLengthStringField(Size, SymbolDescription, StringLength); }
	};

	/*==========================================================================*/
	struct s_SecurityDefinitionForSymbolRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		vls_t Symbol;
		vls_t Exchange;

		DTC::SecurityTypeEnum SecurityType;

		s_SecurityDefinitionForSymbolRequest()
		{
			memset(this, 0,sizeof(s_SecurityDefinitionForSymbolRequest));
			Type=DTC::SECURITY_DEFINITION_FOR_SYMBOL_REQUEST;
			Size=sizeof(s_SecurityDefinitionForSymbolRequest);
		}

		uint16_t GetMessageSize();
		int32_t GetRequestID();
		DTC::SecurityTypeEnum GetSecurityType();
		void AddSymbol(unsigned int StringLength) { AddVariableLengthStringField(Size, Symbol, StringLength); }
		const char* GetSymbol() const { return GetVariableLengthStringField(Size, Symbol, offsetof(s_SecurityDefinitionForSymbolRequest, Symbol)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_SecurityDefinitionForSymbolRequest, Exchange)); }
	};

	/*==========================================================================*/
	struct s_SecurityDefinitionResponse
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		vls_t Symbol;
		vls_t Exchange;

		DTC::SecurityTypeEnum SecurityType;
		
		vls_t Description;
		float MinPriceIncrement;
		DTC::PriceDisplayFormatEnum PriceDisplayFormat;
		float CurrencyValuePerIncrement;

		byte IsFinalMessage;

		float OrderIntPriceMultiplier;
		float MarketDataIntPriceDivisor;
		vls_t UnderlyingSymbol;

		s_SecurityDefinitionResponse()
		{
			memset(this, 0,sizeof(s_SecurityDefinitionResponse));
			Type=DTC::SECURITY_DEFINITION_RESPONSE;
			Size=sizeof(s_SecurityDefinitionResponse);
		}
		
		uint16_t GetMessageSize();
		void AddSymbol(unsigned int StringLength) { AddVariableLengthStringField(Size, Symbol, StringLength); }
		const char* GetSymbol() const { return GetVariableLengthStringField(Size, Symbol, offsetof(s_SecurityDefinitionResponse, Symbol)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_SecurityDefinitionResponse, Exchange)); }
		void AddDescription(unsigned int StringLength) { AddVariableLengthStringField(Size, Description, StringLength); }
		const char* GetDescription() const { return GetVariableLengthStringField(Size, Description, offsetof(s_SecurityDefinitionResponse, Description)); }
		int32_t GetRequestID() const;
		DTC::SecurityTypeEnum GetSecurityType() const;
		float GetMinPriceIncrement() const;
		DTC::PriceDisplayFormatEnum GetPriceDisplayFormat() const;
		float GetCurrencyValuePerIncrement() const;
		byte GetIsFinalMessage() const;
		float GetOrderIntPriceMultiplier();
		float GetMarketDataIntPriceDivisor();
		void AddUnderlyingSymbol(unsigned int StringLength) { AddVariableLengthStringField(Size, UnderlyingSymbol, StringLength); }
		const char* GetUnderlyingSymbol() const { return GetVariableLengthStringField(Size, UnderlyingSymbol, offsetof(s_SecurityDefinitionResponse, UnderlyingSymbol)); }
	};

	/*==========================================================================*/
	struct s_AccountBalanceRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		vls_t TradeAccount;

		s_AccountBalanceRequest()
		{
			memset(this, 0,sizeof(s_AccountBalanceRequest));
			Type=DTC::ACCOUNT_BALANCE_REQUEST;
			Size=sizeof(s_AccountBalanceRequest);
		}

		uint16_t GetMessageSize();
		int32_t GetRequestID();
		const char* GetTradeAccount() const { return GetVariableLengthStringField(Size, TradeAccount, offsetof(s_AccountBalanceRequest, TradeAccount)); }
		void AddTradeAccount(unsigned int StringLength) { AddVariableLengthStringField(Size, TradeAccount, StringLength); }
	};

	/*==========================================================================*/
	struct s_AccountBalanceReject
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		vls_t RejectText;

		s_AccountBalanceReject()
		{
			memset(this, 0,sizeof(s_AccountBalanceReject));
			Type=DTC::ACCOUNT_BALANCE_REJECT;
			Size=sizeof(s_AccountBalanceReject);
		}

		uint16_t GetMessageSize();
		uint32_t GetRequestID();
		const char* GetRejectText() const { return GetVariableLengthStringField(Size, RejectText, offsetof(s_AccountBalanceReject, RejectText)); }
		void AddRejectText(unsigned int StringLength) { AddVariableLengthStringField(Size, RejectText, StringLength); }
	};

	/*==========================================================================*/
	struct s_AccountBalanceUpdate
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		double CashBalance;

		double BalanceAvailableForNewPositions;

		vls_t AccountCurrency;

		vls_t TradeAccount;
		double SecuritiesValue;  // Not including cash
		double MarginRequirement;

		s_AccountBalanceUpdate()
		{
			memset(this, 0,sizeof(s_AccountBalanceUpdate));
			Type=DTC::ACCOUNT_BALANCE_UPDATE;
			Size=sizeof(s_AccountBalanceUpdate);
		}
		
		uint16_t GetMessageSize();
		int32_t GetRequestID();
		void AddAccountCurrency(unsigned int StringLength) { AddVariableLengthStringField(Size, AccountCurrency, StringLength); }
		const char* GetAccountCurrency() const { return GetVariableLengthStringField(Size, AccountCurrency, offsetof(s_AccountBalanceUpdate, AccountCurrency)); }
		void AddTradeAccount(unsigned int StringLength) { AddVariableLengthStringField(Size, TradeAccount, StringLength); }
		const char* GetTradeAccount() const { return GetVariableLengthStringField(Size, TradeAccount, offsetof(s_AccountBalanceUpdate, TradeAccount)); }
		double GetCashBalance();
		double GetBalanceAvailableForNewPositions();
		double GetSecuritiesValue();
		double GetMarginRequirement();
	};

	/*==========================================================================*/
	struct s_UserMessage
	{
		uint16_t Size;
		uint16_t Type;

		vls_t UserMessage;

		byte IsPopupMessage;

		s_UserMessage()
		{
			memset(this, 0,sizeof(s_UserMessage));
			Type=DTC::USER_MESSAGE;
			Size=sizeof(s_UserMessage);
			IsPopupMessage = 1;
		}

		uint16_t GetMessageSize();
		byte GetIsPopupMessage();
		void AddUserMessage(unsigned int StringLength) { AddVariableLengthStringField(Size, UserMessage, StringLength); }
		const char* GetUserMessage() const { return GetVariableLengthStringField(Size, UserMessage, offsetof(s_UserMessage, UserMessage)); }
	};

	/*==========================================================================*/
	struct s_GeneralLogMessage
	{
		uint16_t Size;
		uint16_t Type;

		vls_t MessageText;

		s_GeneralLogMessage()
		{
			memset(this, 0,sizeof(s_GeneralLogMessage));
			Type=DTC::GENERAL_LOG_MESSAGE;
			Size=sizeof(s_GeneralLogMessage);
		}
		
		uint16_t GetMessageSize();
		void AddMessageText(unsigned int StringLength) { AddVariableLengthStringField(Size, MessageText, StringLength); }
		const char* GetMessageText() const { return GetVariableLengthStringField(Size, MessageText, offsetof(s_GeneralLogMessage, MessageText)); }
	};

	/*==========================================================================*/
	struct s_HistoricalPriceDataRequest
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		vls_t Symbol;
		vls_t Exchange;
		DTC::HistoricalDataIntervalEnum RecordInterval;
		DTC::t_DateTime StartDateTime;
		DTC::t_DateTime EndDateTime;
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
			Type=DTC::HISTORICAL_PRICE_DATA_REQUEST;
			Size=sizeof(s_HistoricalPriceDataRequest);
		}
		
		uint16_t GetMessageSize();
		int32_t GetRequestID();
		void AddSymbol(unsigned int StringLength) { AddVariableLengthStringField(Size, Symbol, StringLength); }
		const char* GetSymbol() const { return GetVariableLengthStringField(Size, Symbol, offsetof(s_HistoricalPriceDataRequest, Symbol)); }
		void AddExchange(unsigned int StringLength) { AddVariableLengthStringField(Size, Exchange, StringLength); }
		const char* GetExchange() const { return GetVariableLengthStringField(Size, Exchange, offsetof(s_HistoricalPriceDataRequest, Exchange)); }
		DTC::HistoricalDataIntervalEnum GetRecordInterval();
		DTC::t_DateTime GetStartDateTime();
		DTC::t_DateTime GetEndDateTime();
		uint32_t GetMaxDaysToReturn();
		byte GetUseZLibCompression();
		byte GetRequestDividendAdjustedStockData();
		byte GetFlag_1();
	};

	/*==========================================================================*/
	struct s_HistoricalPriceDataReject
	{
		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;

		vls_t RejectText;

		s_HistoricalPriceDataReject()
		{
			memset(this, 0,sizeof(s_HistoricalPriceDataReject));
			Type=DTC::HISTORICAL_PRICE_DATA_REJECT;
			Size=sizeof(s_HistoricalPriceDataReject);
		}

		uint16_t GetMessageSize();
		int32_t GetRequestID();
		void AddRejectText(unsigned int StringLength) { AddVariableLengthStringField(Size, RejectText, StringLength); }
		const char* GetRejectText() const { return GetVariableLengthStringField(Size, RejectText, offsetof(s_HistoricalPriceDataReject, RejectText)); }
	};

#pragma pack()
}
