
// Data and Trading Communications Protocol Variable Length String Encoding (DTC Protocol VLS)

// This protocol is in the public domain and freely usable by anyone.

// Documentation: http://DTCprotocol.org/index.php?page=doc_DTCMessageDocumentation.php

// The uint8_t ordering is little endian.

#pragma once

#include "DTCProtocol.h"

namespace DTC_VLS
{
#pragma pack(8)

	// see DTCProtocol.h for constants and enum values

	/*==========================================================================*/
	enum TradeModeEnum : int8_t
	{ TRADE_MODE_UNSET = 0
	, TRADE_MODE_DEMO = 1
	, TRADE_MODE_SIMULATED = 2
	, TRADE_MODE_LIVE = 3
	};

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
	inline const char* GetVariableLengthStringField
		( const uint16_t& MessageSizeField
		, uint16_t BaseStructureSizeField
		, const vls_t& VariableLengthStringField
		, const uint16_t VariableLengthStringFieldOffset
	)
	{
		if (BaseStructureSizeField < VariableLengthStringFieldOffset + sizeof(vls_t))
			return "";
		else if (VariableLengthStringField.Offset == 0 || VariableLengthStringField.Length <= 1)
			return "";
		else if ((VariableLengthStringField.Offset + VariableLengthStringField.Length) > MessageSizeField)
			return "";
		else
			return (const char*)&MessageSizeField + VariableLengthStringField.Offset;
	}

	/*==========================================================================*/
	struct s_LogonRequest
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;
		int32_t ProtocolVersion;
		vls_t Username;
		vls_t Password;
		vls_t GeneralTextData;
		int32_t Integer_1;
		int32_t Integer_2;
		int32_t HeartbeatIntervalInSeconds; 
		DTC::TradeModeEnum TradeMode;
		//TradeModeEnum TradeMode;
		vls_t TradeAccount; 
		vls_t HardwareIdentifier;
		vls_t ClientName;

		s_LogonRequest()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_LogonRequest));
			Size = sizeof(s_LogonRequest);
			Type = DTC::LOGON_REQUEST;
			BaseSize = Size;

			ProtocolVersion = DTC::CURRENT_VERSION;
		}

		int32_t GetProtocolVersion();

		const char* GetUsername() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_LogonRequest, Username));
		}

		void AddUsername(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Username, StringLength);
		}

		const char* GetPassword() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Password, offsetof(s_LogonRequest, Password));
		}

		void AddPassword(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Password, StringLength);
		}

		const char* GetGeneralTextData() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GeneralTextData, offsetof(s_LogonRequest, GeneralTextData));
		}

		void AddGeneralTextData(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, GeneralTextData, StringLength);
		}

		int32_t GetInteger_1();
		int32_t GetInteger_2();
		int32_t GetHeartbeatIntervalInSeconds();
		DTC::TradeModeEnum GetTradeMode();
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_LogonRequest, TradeAccount));
		}

		void AddTradeAccount(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetHardwareIdentifier() const
		{
			return GetVariableLengthStringField(Size, BaseSize, HardwareIdentifier, offsetof(s_LogonRequest, HardwareIdentifier));
		}

		void AddHardwareIdentifier(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, HardwareIdentifier, StringLength);
		}

		const char* GetClientName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientName, offsetof(s_LogonRequest, ClientName));
		}

		void AddClientName(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ClientName, StringLength);
		}

	};

	/*==========================================================================*/
	struct s_LogonResponse
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;
		int32_t ProtocolVersion;
		DTC::LogonStatusEnum Result;
		vls_t ResultText;
		vls_t ReconnectAddress;
		int32_t Integer_1;
		vls_t ServerName;
		uint8_t MarketDepthUpdatesBestBidAndAsk;
		uint8_t TradingIsSupported;
		uint8_t OCOOrdersSupported;
		uint8_t OrderCancelReplaceSupported;
		vls_t SymbolExchangeDelimiter;
		uint8_t SecurityDefinitionsSupported;
		uint8_t HistoricalPriceDataSupported;
		uint8_t ResubscribeWhenMarketDataFeedAvailable;
		uint8_t MarketDepthIsSupported;
		uint8_t OneHistoricalPriceDataRequestPerConnection;
		uint8_t BracketOrdersSupported;
		uint8_t UseIntegerPriceOrderMessages;
		uint8_t UsesMultiplePositionsPerSymbolAndTradeAccount;
		uint8_t MarketDataSupported;

		s_LogonResponse()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_LogonResponse));
			Size = sizeof(s_LogonResponse);
			Type = DTC::LOGON_RESPONSE;
			BaseSize = Size;

			ProtocolVersion = DTC::CURRENT_VERSION;
			OrderCancelReplaceSupported = 1;
			MarketDepthIsSupported = 1;
		}

		int32_t GetProtocolVersion() const;
		DTC::LogonStatusEnum GetResult() const;
		int32_t GetInteger_1() const;
		uint8_t GetMarketDepthUpdatesBestBidAndAsk() const;
		uint8_t GetTradingIsSupported() const;
		uint8_t GetOCOOrdersSupported() const;
		uint8_t GetOrderCancelReplaceSupported() const;
		uint8_t GetSecurityDefinitionsSupported() const;
		uint8_t GetHistoricalPriceDataSupported() const;
		uint8_t GetResubscribeWhenMarketDataFeedAvailable() const;
		uint8_t GetMarketDepthIsSupported() const;
		uint8_t GetOneHistoricalPriceDataRequestPerConnection() const;
		uint8_t GetUseIntegerPriceOrderMessages() const;
		uint8_t GetBracketOrdersSupported() const;
		uint8_t GetUsesMultiplePositionsPerSymbolAndTradeAccount() const;
		uint8_t GetMarketDataSupported() const;

		const char* GetResultText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ResultText, offsetof(s_LogonResponse, ResultText));
		}

		void AddResultText(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ResultText, StringLength);
		}

		const char* GetReconnectAddress() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ReconnectAddress, offsetof(s_LogonResponse, ReconnectAddress));
		}

		void AddReconnectAddress(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ReconnectAddress, StringLength);
		}

		const char* GetServerName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ServerName, offsetof(s_LogonResponse, ServerName));
		}

		void AddServerName(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ServerName, StringLength);
		}

		const char* GetSymbolExchangeDelimiter() const
		{
			return GetVariableLengthStringField(Size, BaseSize, SymbolExchangeDelimiter, offsetof(s_LogonResponse, SymbolExchangeDelimiter));
		}

		void AddSymbolExchangeDelimiter(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, SymbolExchangeDelimiter, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_Logoff
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;
		vls_t Reason;
		uint8_t DoNotReconnect;

		s_Logoff()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_Logoff));
			Size = sizeof(s_Logoff);
			Type = DTC::LOGOFF;
			BaseSize = Size;
		}

		const char* GetReason() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Reason, offsetof(s_Logoff, Reason));
		}

		void AddReason(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Reason, StringLength);
		}

		uint8_t GetDoNotReconnect();
	};


	/*==========================================================================*/
	struct s_MarketDataRequest
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;
		DTC::RequestActionEnum RequestAction;
		uint16_t SymbolID;
		vls_t Symbol;
		vls_t Exchange;

		s_MarketDataRequest()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_MarketDataRequest));
			Size = sizeof(s_MarketDataRequest);
			Type = DTC::MARKET_DATA_REQUEST;
			BaseSize = Size;

			RequestAction = DTC::SUBSCRIBE;
		}

		DTC::RequestActionEnum GetRequestAction();
		uint16_t GetSymbolID();

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_MarketDataRequest, Symbol));
		}

		void AddSymbol(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_MarketDataRequest, Symbol));
		}

		void AddExchange(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_MarketDepthRequest
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;
		DTC::RequestActionEnum RequestAction;
		uint16_t SymbolID;
		vls_t Symbol;
		vls_t Exchange;
		int32_t NumLevels;

		s_MarketDepthRequest()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_MarketDepthRequest));
			Size = sizeof(s_MarketDepthRequest);
			Type = DTC::MARKET_DEPTH_REQUEST;
			BaseSize = Size;

			RequestAction = DTC::SUBSCRIBE;
			NumLevels = 10;
		}

		DTC::RequestActionEnum GetRequestAction();
		uint16_t GetSymbolID();

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_MarketDepthRequest, Symbol));
		}

		void AddSymbol(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_MarketDepthRequest, Exchange));
		}

		void AddExchange(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		int32_t GetNumLevels();
	};

	/*==========================================================================*/
	struct s_MarketDataReject
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;
		uint16_t SymbolID;
		vls_t RejectText;

		s_MarketDataReject()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_MarketDataReject));
			Size = sizeof(s_MarketDataReject);
			Type = DTC::MARKET_DATA_REJECT;
			BaseSize = Size;
		}

		uint16_t GetSymbolID();

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_MarketDataReject, RejectText));
		}

		void AddRejectText(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}
	};


	/*==========================================================================*/
	struct s_MarketDepthReject
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;
		uint16_t SymbolID;
		vls_t RejectText;

		s_MarketDepthReject()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_MarketDepthReject));
			Size = sizeof(s_MarketDepthReject);
			Type = DTC::MARKET_DEPTH_REJECT;
			BaseSize = Size;
		}

		uint16_t GetSymbolID();

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_MarketDepthReject, RejectText));
		}

		void AddRejectText(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}
	};


	/*==========================================================================*/
	struct s_SubmitNewSingleOrder
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

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
		
		uint8_t IsAutomatedOrder;

		uint8_t IsParentOrder;

		vls_t FreeFormText;

		DTC::OpenCloseTradeEnum OpenOrClose;

		s_SubmitNewSingleOrder()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_SubmitNewSingleOrder));
			Size = sizeof(s_SubmitNewSingleOrder);
			Type = DTC::SUBMIT_NEW_SINGLE_ORDER;
			BaseSize = Size;
		}

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_SubmitNewSingleOrder, Symbol));
		}

		void AddSymbol(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_SubmitNewSingleOrder, Exchange));
		}

		void AddExchange(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_SubmitNewSingleOrder, TradeAccount));
		}

		void AddTradeAccount(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID, offsetof(s_SubmitNewSingleOrder, ClientOrderID));
		}

		void AddClientOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID, StringLength);
		}

		DTC::OrderTypeEnum GetOrderType();	
		DTC::BuySellEnum GetBuySell();	
		double GetPrice1();
		double GetPrice2();
		double GetQuantity();	
		DTC::TimeInForceEnum GetTimeInForce();	
		DTC::t_DateTime GetGoodTillDateTime();
		void SetTradeAccount(const char* NewValue);
		uint8_t GetIsAutomatedOrder();	
		uint8_t GetIsParentOrder();

		const char* GetFreeFormText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FreeFormText, offsetof(s_SubmitNewSingleOrder, FreeFormText));
		}

		void AddFreeFormText(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, FreeFormText, StringLength);
		}

		DTC::OpenCloseTradeEnum GetOpenOrClose();
	};

	/*==========================================================================*/
	struct s_SubmitNewSingleOrderInt
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		vls_t Symbol;
		vls_t Exchange;

		vls_t TradeAccount;
		vls_t ClientOrderID;

		DTC::OrderTypeEnum OrderType;
		DTC::BuySellEnum BuySell;

		int64_t Price1;
		int64_t Price2;
		float Divisor;
		int64_t Quantity;

		DTC::TimeInForceEnum TimeInForce;
		DTC::t_DateTime GoodTillDateTime;
		
		uint8_t IsAutomatedOrder;
		uint8_t IsParentOrder;

		vls_t FreeFormText;

		DTC::OpenCloseTradeEnum OpenOrClose;

		s_SubmitNewSingleOrderInt()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_SubmitNewSingleOrderInt));
			Size = sizeof(s_SubmitNewSingleOrderInt);
			Type = DTC::SUBMIT_NEW_SINGLE_ORDER_INT;
			BaseSize = Size;
		}

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_SubmitNewSingleOrderInt, Symbol));
		}

		void AddSymbol(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_SubmitNewSingleOrderInt, Exchange));
		}

		void AddExchange(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_SubmitNewSingleOrderInt, TradeAccount));
		}

		void AddTradeAccount(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID, offsetof(s_SubmitNewSingleOrderInt, ClientOrderID));
		}

		void AddClientOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID, StringLength);
		}

		DTC::OrderTypeEnum GetOrderType();	
		DTC::BuySellEnum GetBuySell();	
		int64_t GetPrice1();
		int64_t GetPrice2();
		float GetDivisor();
		int64_t GetQuantity();	
		DTC::TimeInForceEnum GetTimeInForce();	
		DTC::t_DateTime GetGoodTillDateTime();
		uint8_t GetIsAutomatedOrder();	
		uint8_t GetIsParentOrder();

		const char* GetFreeFormText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FreeFormText, offsetof(s_SubmitNewSingleOrderInt, FreeFormText));
		}

		void AddFreeFormText(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, FreeFormText, StringLength);
		}

		DTC::OpenCloseTradeEnum GetOpenOrClose();
	};

	/*==========================================================================*/
	struct s_CancelReplaceOrder
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		vls_t ServerOrderID;
		vls_t ClientOrderID;

		double Price1;
		double Price2;

		double Quantity;

		int8_t Price1IsSet;
		int8_t Price2IsSet;

		DTC::OrderTypeEnum OrderType;
		DTC::TimeInForceEnum TimeInForce;
		DTC::t_DateTime GoodTillDateTime;

		s_CancelReplaceOrder()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_CancelReplaceOrder));
			Size = sizeof(s_CancelReplaceOrder);
			Type = DTC::CANCEL_REPLACE_ORDER;
			BaseSize = Size;

			Price1IsSet = 1;
			Price2IsSet = 1;
		}

		const char* GetServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ServerOrderID, offsetof(s_CancelReplaceOrder, ServerOrderID));
		}

		void AddServerOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ServerOrderID, StringLength);
		}

		const char* GetClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID, offsetof(s_CancelReplaceOrder, ClientOrderID));
		}

		void AddClientOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID, StringLength);
		}

		double GetPrice1();
		double GetPrice2();
		double GetQuantity();
		int8_t GetPrice1IsSet();
		int8_t GetPrice2IsSet();
		DTC::OrderTypeEnum GetOrderType();
		DTC::TimeInForceEnum GetTimeInForce();
		DTC::t_DateTime GetGoodTillDateTime();
	};

	/*==========================================================================*/
	struct s_CancelReplaceOrderInt
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		vls_t ServerOrderID;
		vls_t ClientOrderID;

		int64_t Price1;
		int64_t Price2;
		float Divisor;
		int64_t Quantity;
		int8_t Price1IsSet;
		int8_t Price2IsSet;

		DTC::OrderTypeEnum OrderType;
		DTC::TimeInForceEnum TimeInForce;
		DTC::t_DateTime GoodTillDateTime;

		s_CancelReplaceOrderInt()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_CancelReplaceOrderInt));
			Size = sizeof(s_CancelReplaceOrderInt);
			Type = DTC::CANCEL_REPLACE_ORDER_INT;
			BaseSize = Size;

			Divisor = 1.0f;
			Price1IsSet = 1;
			Price2IsSet = 1;
		}

		const char* GetServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ServerOrderID, offsetof(s_CancelReplaceOrderInt, ServerOrderID));
		}

		void AddServerOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ServerOrderID, StringLength);
		}

		const char* GetClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID, offsetof(s_CancelReplaceOrderInt, ClientOrderID));
		}

		void AddClientOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID, StringLength);
		}

		int64_t GetPrice1();
		int64_t GetPrice2();
		float GetDivisor();
		int64_t GetQuantity();
		int8_t GetPrice1IsSet();
		int8_t GetPrice2IsSet();
		DTC::OrderTypeEnum GetOrderType();
		DTC::TimeInForceEnum GetTimeInForce();
		DTC::t_DateTime GetGoodTillDateTime();
	};

	/*==========================================================================*/
	struct s_CancelOrder
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;
		
		vls_t ServerOrderID;
		vls_t ClientOrderID;

		s_CancelOrder()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_CancelOrder));
			Size = sizeof(s_CancelOrder);
			Type = DTC::CANCEL_ORDER;
			BaseSize = Size;
		}

		const char* GetServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ServerOrderID, offsetof(s_CancelOrder, ServerOrderID));
		}

		void AddServerOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ServerOrderID, StringLength);
		}

		const char* GetClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID, offsetof(s_CancelOrder, ClientOrderID));
		}

		void AddClientOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_SubmitNewOCOOrder
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

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

		uint8_t IsAutomatedOrder;

		vls_t ParentTriggerClientOrderID;

		vls_t FreeFormText;

		DTC::OpenCloseTradeEnum OpenOrClose;

		DTC::PartialFillHandlingEnum PartialFillHandling;

		s_SubmitNewOCOOrder()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_SubmitNewOCOOrder));
			Size = sizeof(s_SubmitNewOCOOrder);
			Type = DTC::SUBMIT_NEW_OCO_ORDER;
			BaseSize = Size;
		}

		const char* GetClientOrderID_1() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID_1, offsetof(s_SubmitNewOCOOrder, ClientOrderID_1));
		}

		void AddClientOrderID_1(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID_1, StringLength);
		}

		const char* GetClientOrderID_2() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID_2, offsetof(s_SubmitNewOCOOrder, ClientOrderID_2));
		}

		void AddClientOrderID_2(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID_2, StringLength);
		}

		const char* GetFreeFormText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FreeFormText, offsetof(s_SubmitNewOCOOrder, FreeFormText));
		}

		void AddFreeFormText(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, FreeFormText, StringLength);
		}

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_SubmitNewOCOOrder, Symbol));
		}

		void AddSymbol(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_SubmitNewOCOOrder, Exchange));
		}

		void AddExchange(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		void AddParentTriggerClientOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ParentTriggerClientOrderID, StringLength);
		}

		const char* GetParentTriggerClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ParentTriggerClientOrderID, offsetof(s_SubmitNewOCOOrder, ParentTriggerClientOrderID));
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_SubmitNewOCOOrder, TradeAccount));
		}

		void AddTradeAccount(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		DTC::OrderTypeEnum GetOrderType_1();
		DTC::OrderTypeEnum GetOrderType_2();
		DTC::BuySellEnum GetBuySell_1();
		DTC::BuySellEnum GetBuySell_2();	
		DTC::TimeInForceEnum GetTimeInForce();
		DTC::t_DateTime GetGoodTillDateTime();
		uint8_t GetIsAutomatedOrder();
		double GetPrice1_1();
		double GetPrice2_1();
		double GetPrice1_2();
		double GetPrice2_2();
		double GetQuantity_1();
		double GetQuantity_2();
		DTC::OpenCloseTradeEnum GetOpenOrClose();
		DTC::PartialFillHandlingEnum GetPartialFillHandling();
	};

	/*==========================================================================*/
	struct s_SubmitNewOCOOrderInt
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		vls_t Symbol;
		vls_t Exchange;

		vls_t ClientOrderID_1;
		DTC::OrderTypeEnum OrderType_1;
		DTC::BuySellEnum BuySell_1;
		int64_t Price1_1;
		int64_t Price2_1;
		int64_t Quantity_1;

		vls_t ClientOrderID_2;
		DTC::OrderTypeEnum OrderType_2;
		DTC::BuySellEnum BuySell_2;
		int64_t Price1_2;
		int64_t Price2_2;
		int64_t Quantity_2;

		DTC::TimeInForceEnum TimeInForce;
		DTC::t_DateTime GoodTillDateTime;

		vls_t TradeAccount;

		uint8_t IsAutomatedOrder;

		vls_t ParentTriggerClientOrderID;

		vls_t FreeFormText;

		float Divisor;

		DTC::OpenCloseTradeEnum OpenOrClose;

		DTC::PartialFillHandlingEnum PartialFillHandling;

		s_SubmitNewOCOOrderInt()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_SubmitNewOCOOrderInt));
			Size = sizeof(s_SubmitNewOCOOrderInt);
			Type = DTC::SUBMIT_NEW_OCO_ORDER_INT;
			BaseSize = Size;
		}

		void AddClientOrderID_1(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID_1, StringLength);
		}

		void AddClientOrderID_2(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID_2, StringLength);
		}

		const char* GetFreeFormText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FreeFormText, offsetof(s_SubmitNewOCOOrderInt, FreeFormText));
		}

		void AddFreeFormText(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, FreeFormText, StringLength);
		}

		const char* GetClientOrderID_1() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID_1, offsetof(s_SubmitNewOCOOrderInt, ClientOrderID_1));
		}

		const char* GetClientOrderID_2() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID_2, offsetof(s_SubmitNewOCOOrderInt, ClientOrderID_2));
		}

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_SubmitNewOCOOrderInt, Symbol));
		}

		void AddSymbol(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_SubmitNewOCOOrderInt, Exchange));
		}

		void AddExchange(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		void AddParentTriggerClientOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ParentTriggerClientOrderID, StringLength);
		}

		const char* GetParentTriggerClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ParentTriggerClientOrderID, offsetof(s_SubmitNewOCOOrderInt, ParentTriggerClientOrderID));
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_SubmitNewOCOOrderInt, TradeAccount));
		}

		void AddTradeAccount(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		DTC::OrderTypeEnum GetOrderType_1();
		DTC::OrderTypeEnum GetOrderType_2();
		DTC::BuySellEnum GetBuySell_1();
		DTC::BuySellEnum GetBuySell_2();	
		DTC::TimeInForceEnum GetTimeInForce();
		DTC::t_DateTime GetGoodTillDateTime();
		uint8_t GetIsAutomatedOrder();
		int64_t GetPrice1_1();
		int64_t GetPrice2_1();
		int64_t GetPrice1_2();
		int64_t GetPrice2_2();
		int64_t GetQuantity_1();
		int64_t GetQuantity_2();
		float GetDivisor();
		DTC::OpenCloseTradeEnum GetOpenOrClose();
		DTC::PartialFillHandlingEnum GetPartialFillHandling();
	};

	/*==========================================================================*/
	struct s_OpenOrdersRequest
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;

		int32_t RequestAllOrders;

		vls_t ServerOrderID;
		vls_t TradeAccount;

		s_OpenOrdersRequest()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_OpenOrdersRequest));
			Size = sizeof(s_OpenOrdersRequest);
			Type = DTC::OPEN_ORDERS_REQUEST;
			BaseSize = Size;

			RequestAllOrders = 1;
		}

		int32_t GetRequestID();
		int32_t GetRequestAllOrders();

		void AddServerOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ServerOrderID, StringLength);
		}

		const char* GetServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ServerOrderID, offsetof(s_OpenOrdersRequest, ServerOrderID));
		}

		void AddTradeAccount(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_OpenOrdersRequest, TradeAccount));
		}
	};

	/*==========================================================================*/
	struct s_HistoricalOrderFillsRequest
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;

		vls_t ServerOrderID;

		int32_t NumberOfDays;

		vls_t TradeAccount;

		s_HistoricalOrderFillsRequest()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_HistoricalOrderFillsRequest));
			Size = sizeof(s_HistoricalOrderFillsRequest);
			Type = DTC::HISTORICAL_ORDER_FILLS_REQUEST;
			BaseSize = Size;
		}

		int32_t GetRequestID();
		int32_t GetNumberOfDays();

		void AddServerOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ServerOrderID, StringLength);
		}

		const char* GetServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ServerOrderID, offsetof(s_HistoricalOrderFillsRequest, ServerOrderID));
		}

		void AddTradeAccount(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_HistoricalOrderFillsRequest, TradeAccount));
		}
	};

	/*==========================================================================*/
	struct s_HistoricalOrderFillsReject
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;
		vls_t RejectText;

		s_HistoricalOrderFillsReject()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_HistoricalOrderFillsReject));
			Size = sizeof(s_HistoricalOrderFillsReject);
			Type = DTC::HISTORICAL_ORDER_FILLS_REJECT;
			BaseSize = Size;
		}

		int32_t GetRequestID();

		void AddRejectText(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_HistoricalOrderFillsReject, RejectText));
		}
	};

	/*==========================================================================*/
	struct s_CurrentPositionsRequest
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;
		vls_t  TradeAccount;

		s_CurrentPositionsRequest()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_CurrentPositionsRequest));
			Size = sizeof(s_CurrentPositionsRequest);
			Type = DTC::CURRENT_POSITIONS_REQUEST;
			BaseSize = Size;
		}

		int32_t GetRequestID();

		void AddTradeAccount(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_CurrentPositionsRequest, TradeAccount));
		}
	};

	/*==========================================================================*/
	struct s_CurrentPositionsReject
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;
		vls_t RejectText;

		s_CurrentPositionsReject()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_CurrentPositionsReject));
			Size = sizeof(s_CurrentPositionsReject);
			Type = DTC::CURRENT_POSITIONS_REJECT;
			BaseSize = Size;
		}

		int32_t GetRequestID();

		void AddRejectText(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_CurrentPositionsReject, RejectText));
		}
	};

	/*==========================================================================*/
	struct s_OrderUpdate
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

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
		vls_t LastFillExecutionID;

		vls_t TradeAccount;
		vls_t InfoText;

		uint8_t NoOrders;
		vls_t ParentServerOrderID;
		vls_t OCOLinkedOrderServerOrderID;

		DTC::OpenCloseTradeEnum OpenOrClose;

		vls_t PreviousClientOrderID;
		vls_t FreeFormText;

		DTC::t_DateTime OrderReceivedDateTime;

		s_OrderUpdate()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_OrderUpdate));
			Size = sizeof(s_OrderUpdate);
			Type = DTC::ORDER_UPDATE;
			BaseSize = Size;

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

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_OrderUpdate, Symbol));
		}

		void AddSymbol(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_OrderUpdate, Exchange));
		}

		void AddExchange(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetPreviousServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, PreviousServerOrderID, offsetof(s_OrderUpdate, PreviousServerOrderID));
		}

		void AddPreviousServerOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, PreviousServerOrderID, StringLength);
		}

		const char* GetServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ServerOrderID, offsetof(s_OrderUpdate, ServerOrderID));
		}

		void AddServerOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ServerOrderID, StringLength);
		}

		const char* GetClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID, offsetof(s_OrderUpdate, ClientOrderID));
		}

		void AddClientOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID, StringLength);
		}

		const char* GetExchangeOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ExchangeOrderID, offsetof(s_OrderUpdate, ExchangeOrderID));
		}

		void AddExchangeOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ExchangeOrderID, StringLength);
		}

		void AddLastFillExecutionID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, LastFillExecutionID, StringLength);
		}

		const char* GetLastFillExecutionID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, LastFillExecutionID, offsetof(s_OrderUpdate, LastFillExecutionID));
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_OrderUpdate, TradeAccount));
		}

		void AddTradeAccount(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetInfoText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, InfoText, offsetof(s_OrderUpdate, InfoText));
		}

		void AddInfoText(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, InfoText, StringLength);
		}

		const char* GetParentServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ParentServerOrderID, offsetof(s_OrderUpdate, ParentServerOrderID));
		}

		void AddParentServerOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ParentServerOrderID, StringLength);
		}

		const char* GetOCOLinkedOrderServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, OCOLinkedOrderServerOrderID, offsetof(s_OrderUpdate, OCOLinkedOrderServerOrderID));
		}

		void AddOCOLinkedOrderServerOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, OCOLinkedOrderServerOrderID, StringLength);
		}

		const char* GetPreviousClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, PreviousClientOrderID, offsetof(s_OrderUpdate, PreviousClientOrderID));
		}

		void AddPreviousClientOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, PreviousClientOrderID, StringLength);
		}

		const char* GetFreeFormText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FreeFormText, offsetof(s_OrderUpdate, FreeFormText));
		}

		void AddFreeFormText(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, FreeFormText, StringLength);
		}

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
		uint8_t GetNoOrders();
		DTC::OpenCloseTradeEnum GetOpenOrClose();
		DTC::t_DateTime GetOrderReceivedDateTime();
	};
	
	/*==========================================================================*/
	struct s_OpenOrdersReject
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;
		vls_t RejectText;

		s_OpenOrdersReject()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_OpenOrdersReject));
			Size = sizeof(s_OpenOrdersReject);
			Type = DTC::OPEN_ORDERS_REJECT;
			BaseSize = Size;
		}

		int32_t GetRequestID();

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_OpenOrdersReject, RejectText));
		}

		void AddRejectText(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_HistoricalOrderFillResponse
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

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

		uint8_t NoOrderFills;

		s_HistoricalOrderFillResponse()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_HistoricalOrderFillResponse));
			Size = sizeof(s_HistoricalOrderFillResponse);
			Type = DTC::HISTORICAL_ORDER_FILL_RESPONSE;
			BaseSize = Size;
		}

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_HistoricalOrderFillResponse, Symbol));
		}

		void AddSymbol(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_HistoricalOrderFillResponse, Exchange));
		}

		void AddExchange(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ServerOrderID, offsetof(s_HistoricalOrderFillResponse, ServerOrderID));
		}

		void AddServerOrderID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ServerOrderID, StringLength);
		}

		void AddTradeAccount(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_HistoricalOrderFillResponse, TradeAccount));
		}

		void AddUniqueExecutionID(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, UniqueExecutionID, StringLength);
		}

		const char* GetUniqueExecutionID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, UniqueExecutionID, offsetof(s_HistoricalOrderFillResponse, UniqueExecutionID));
		}

		int32_t GetRequestID();
		int32_t GetMessageNumber();
		int32_t GetTotalNumberMessages();		
		DTC::BuySellEnum GetBuySell();
		double GetPrice();
		DTC::t_DateTime GetDateTime();
		double GetQuantity();
		DTC::OpenCloseTradeEnum GetOpenClose();
		uint8_t GetNoOrderFills();
	};

	/*==========================================================================*/
	struct s_PositionUpdate
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;

		int32_t TotalNumberMessages;

		int32_t MessageNumber;

		vls_t Symbol;
		vls_t Exchange;

		double Quantity;
		double AveragePrice;

		vls_t PositionIdentifier;

		vls_t TradeAccount;
		uint8_t NoPositions;

		uint8_t Unsolicited;

		s_PositionUpdate()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_PositionUpdate));
			Size = sizeof(s_PositionUpdate);
			Type = DTC::POSITION_UPDATE;
			BaseSize = Size;
		}

		void AddSymbol(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_PositionUpdate, Symbol));
		}

		void AddExchange(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_PositionUpdate, Exchange));
		}

		void AddPositionIdentifier(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, PositionIdentifier, StringLength);
		}

		const char* GetPositionIdentifier() const
		{
			return GetVariableLengthStringField(Size, BaseSize, PositionIdentifier, offsetof(s_PositionUpdate, PositionIdentifier));
		}

		void AddTradeAccount(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_PositionUpdate, TradeAccount));
		}

		int32_t GetRequestID();
		int32_t GetTotalNumberMessages();
		int32_t GetMessageNumber();
		double GetQuantity();
		double GetAveragePrice();
		uint8_t GetNoPositions();
		uint8_t GetUnsolicited();
	};


	/*==========================================================================*/
	struct s_TradeAccountResponse
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t TotalNumberMessages;

		int32_t MessageNumber;

		vls_t TradeAccount;

		int32_t RequestID;

		s_TradeAccountResponse()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_TradeAccountResponse));
			Size = sizeof(s_TradeAccountResponse);
			Type = DTC::TRADE_ACCOUNT_RESPONSE;
			BaseSize = Size;
		}

		int32_t GetTotalNumberMessages();
		int32_t GetMessageNumber();

		void AddTradeAccount(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountResponse, TradeAccount));
		}

		int32_t GetRequestID();
	};

	/*==========================================================================*/
	struct s_ExchangeListResponse
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;
		vls_t Exchange;
		uint8_t IsFinalMessage;
		vls_t Description;

		s_ExchangeListResponse()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_ExchangeListResponse));
			Size = sizeof(s_ExchangeListResponse);
			Type = DTC::EXCHANGE_LIST_RESPONSE;
			BaseSize = Size;
		}

		int32_t GetRequestID();
		uint8_t GetIsFinalMessage();

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_ExchangeListResponse, Exchange));
		}

		void AddExchange(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetDescription() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Description, offsetof(s_ExchangeListResponse, Description));
		}

		void AddDescription(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Description, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_SymbolsForExchangeRequest
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;
		vls_t Exchange;

		DTC::SecurityTypeEnum SecurityType;

		s_SymbolsForExchangeRequest()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_SymbolsForExchangeRequest));
			Size = sizeof(s_SymbolsForExchangeRequest);
			Type = DTC::SYMBOLS_FOR_EXCHANGE_REQUEST;
			BaseSize = Size;
		}

		int32_t GetRequestID();
		DTC::SecurityTypeEnum GetSecurityType();

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_SymbolsForExchangeRequest, Exchange));
		}

		void AddExchange(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_UnderlyingSymbolsForExchangeRequest
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;

		vls_t Exchange;

		DTC::SecurityTypeEnum SecurityType;

		s_UnderlyingSymbolsForExchangeRequest()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_UnderlyingSymbolsForExchangeRequest));
			Size = sizeof(s_UnderlyingSymbolsForExchangeRequest);
			Type = DTC::UNDERLYING_SYMBOLS_FOR_EXCHANGE_REQUEST;
			BaseSize = Size;
		}

		int32_t GetRequestID();
		DTC::SecurityTypeEnum GetSecurityType();

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_UnderlyingSymbolsForExchangeRequest, Exchange));
		}

		void AddExchange(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_SymbolsForUnderlyingRequest
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;

		vls_t UnderlyingSymbol;
		vls_t Exchange;

		DTC::SecurityTypeEnum SecurityType;

		s_SymbolsForUnderlyingRequest()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_SymbolsForUnderlyingRequest));
			Size = sizeof(s_SymbolsForUnderlyingRequest);
			Type = DTC::SYMBOLS_FOR_UNDERLYING_REQUEST;
			BaseSize = Size;
		}

		int32_t GetRequestID();
		DTC::SecurityTypeEnum GetSecurityType();

		const char* GetUnderlyingSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, UnderlyingSymbol, offsetof(s_SymbolsForUnderlyingRequest, UnderlyingSymbol));
		}

		void AddUnderlyingSymbol(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, UnderlyingSymbol, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_SymbolsForUnderlyingRequest, Exchange));
		}

		void AddExchange(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_SymbolSearchRequest
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;
		vls_t SearchText;
		vls_t Exchange;

		DTC::SecurityTypeEnum SecurityType;
		DTC::SearchTypeEnum SearchType;

		s_SymbolSearchRequest()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_SymbolSearchRequest));
			Size = sizeof(s_SymbolSearchRequest);
			Type = DTC::SYMBOL_SEARCH_REQUEST;
			BaseSize = Size;
		}

		int32_t GetRequestID();
		DTC::SecurityTypeEnum GetSecurityType();
		DTC::SearchTypeEnum GetSearchType();

		const char* GetSearchText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, SearchText, offsetof(s_SymbolSearchRequest, SearchText));
		}

		void AddSearchText(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, SearchText, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_SymbolSearchRequest, Exchange));
		}

		void AddExchange(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_SecurityDefinitionForSymbolRequest
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;

		vls_t Symbol;
		vls_t Exchange;


		s_SecurityDefinitionForSymbolRequest()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_SecurityDefinitionForSymbolRequest));
			Size = sizeof(s_SecurityDefinitionForSymbolRequest);
			Type = DTC::SECURITY_DEFINITION_FOR_SYMBOL_REQUEST;
			BaseSize = Size;
		}

		int32_t GetRequestID();

		void AddSymbol(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetSymbol() const 
		{ 
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_SecurityDefinitionForSymbolRequest, Symbol)); 
		}

		void AddExchange(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_SecurityDefinitionForSymbolRequest, Exchange));
		}
	};

	/*==========================================================================*/
	struct s_SecurityDefinitionResponse
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;

		vls_t Symbol;
		vls_t Exchange;

		DTC::SecurityTypeEnum SecurityType;
		
		vls_t Description;
		float MinPriceIncrement;
		DTC::PriceDisplayFormatEnum PriceDisplayFormat;
		float CurrencyValuePerIncrement;

		uint8_t IsFinalMessage;

		float FloatToIntPriceMultiplier;
		float IntToFloatPriceDivisor;
		vls_t UnderlyingSymbol;

		uint8_t UpdatesBidAskOnly;

		float StrikePrice;

		DTC::PutCallEnum PutOrCall;

		uint32_t ShortInterest;

		DTC::t_DateTime4Byte SecurityExpirationDate;

		float BuyRolloverInterest;
		float SellRolloverInterest;

		float EarningsPerShare;
		uint32_t SharesOutstanding;

		float IntToFloatQuantityDivisor;

		uint8_t HasMarketDepthData;

		float DisplayPriceMultiplier;

		vls_t ExchangeSymbol;

		s_SecurityDefinitionResponse()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_SecurityDefinitionResponse));
			Size = sizeof(s_SecurityDefinitionResponse);
			Type = DTC::SECURITY_DEFINITION_RESPONSE;
			BaseSize = Size;

			FloatToIntPriceMultiplier = 1.0;
			IntToFloatPriceDivisor = 1.0;
			HasMarketDepthData = 1;
			DisplayPriceMultiplier = 1.0;
		}

		void AddSymbol(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_SecurityDefinitionResponse, Symbol));
		}

		void AddExchange(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_SecurityDefinitionResponse, Exchange));
		}

		void AddDescription(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Description, StringLength);
		}

		const char* GetDescription() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Description, offsetof(s_SecurityDefinitionResponse, Description));
		}

		int32_t GetRequestID() const;
		DTC::SecurityTypeEnum GetSecurityType() const;
		float GetMinPriceIncrement() const;
		DTC::PriceDisplayFormatEnum GetPriceDisplayFormat() const;
		float GetCurrencyValuePerIncrement() const;
		uint8_t GetIsFinalMessage() const;
		float GetFloatToIntPriceMultiplier();
		float GetIntToFloatPriceDivisor();

		void AddUnderlyingSymbol(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, UnderlyingSymbol, StringLength);
		}

		const char* GetUnderlyingSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, UnderlyingSymbol, offsetof(s_SecurityDefinitionResponse, UnderlyingSymbol));
		}

		uint8_t GetUpdatesBidAskOnly() const;
		float GetStrikePrice() const;
		DTC::PutCallEnum GetPutOrCall() const;
		uint32_t GetShortInterest() const;
		DTC::t_DateTime4Byte GetSecurityExpirationDate() const;
		float GetBuyRolloverInterest() const;
		float GetSellRolloverInterest() const;
		float GetEarningsPerShare() const;
		uint32_t GetSharesOutstanding() const;
		float GetIntToFloatQuantityDivisor() const;
		uint8_t GetHasMarketDepthData() const;
		float GetDisplayPriceMultiplier() const;

		void AddExchangeSymbol(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, ExchangeSymbol, StringLength);
		}

		const char* GetExchangeSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ExchangeSymbol, offsetof(s_SecurityDefinitionResponse, ExchangeSymbol));
		}
	};


	/*==========================================================================*/
	struct s_SecurityDefinitionReject
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;
		vls_t RejectText;

		s_SecurityDefinitionReject()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_SecurityDefinitionReject));
			Size = sizeof(s_SecurityDefinitionReject);
			Type = DTC::SECURITY_DEFINITION_REJECT;
			BaseSize = Size;
		}

		int32_t GetRequestID();

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_SecurityDefinitionReject, RejectText));
		}

		void AddRejectText(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_AccountBalanceRequest
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;
		vls_t TradeAccount;

		s_AccountBalanceRequest()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_AccountBalanceRequest));
			Size = sizeof(s_AccountBalanceRequest);
			Type = DTC::ACCOUNT_BALANCE_REQUEST;
			BaseSize = Size;
		}

		int32_t GetRequestID();

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_AccountBalanceRequest, TradeAccount));
		}

		void AddTradeAccount(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_AccountBalanceReject
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;
		vls_t RejectText;

		s_AccountBalanceReject()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_AccountBalanceReject));
			Size = sizeof(s_AccountBalanceReject);
			Type = DTC::ACCOUNT_BALANCE_REJECT;
			BaseSize = Size;
		}

		int32_t GetRequestID();

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_AccountBalanceReject, RejectText));
		}

		void AddRejectText(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_AccountBalanceUpdate
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;

		double CashBalance;

		double BalanceAvailableForNewPositions;

		vls_t AccountCurrency;

		vls_t TradeAccount;
		double SecuritiesValue;  // Not including cash
		double MarginRequirement;

		int32_t TotalNumberMessages;
		int32_t MessageNumber;
		uint8_t NoAccountBalances;
		uint8_t Unsolicited;

		s_AccountBalanceUpdate()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_AccountBalanceUpdate));
			Size = sizeof(s_AccountBalanceUpdate);
			Type = DTC::ACCOUNT_BALANCE_UPDATE;
			BaseSize = Size;
		}

		int32_t GetRequestID();

		void AddAccountCurrency(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, AccountCurrency, StringLength);
		}

		const char* GetAccountCurrency() const
		{
			return GetVariableLengthStringField(Size, BaseSize, AccountCurrency, offsetof(s_AccountBalanceUpdate, AccountCurrency));
		}

		void AddTradeAccount(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_AccountBalanceUpdate, TradeAccount));
		}

		double GetCashBalance() const;
		double GetBalanceAvailableForNewPositions() const;
		double GetSecuritiesValue() const;
		double GetMarginRequirement() const;

		int32_t GetTotalNumberMessages() const;
		int32_t GetMessageNumber() const;
		uint8_t GetNoAccountBalances() const;
		uint8_t GetUnsolicited() const;
	};

	/*==========================================================================*/
	struct s_UserMessage
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		vls_t UserMessage;

		uint8_t IsPopupMessage;

		s_UserMessage()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_UserMessage));
			Size = sizeof(s_UserMessage);
			Type = DTC::USER_MESSAGE;
			BaseSize = Size;

			IsPopupMessage = 1;
		}

		uint8_t GetIsPopupMessage();

		void AddUserMessage(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, UserMessage, StringLength);
		}

		const char* GetUserMessage() const
		{
			return GetVariableLengthStringField(Size, BaseSize, UserMessage, offsetof(s_UserMessage, UserMessage));
		}
	};

	/*==========================================================================*/
	struct s_GeneralLogMessage
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		vls_t MessageText;

		s_GeneralLogMessage()
		{
			Clear();
		}
		
		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_GeneralLogMessage));
			Size = sizeof(s_GeneralLogMessage);
			Type = DTC::GENERAL_LOG_MESSAGE;
			BaseSize = Size;
		}

		void AddMessageText(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, MessageText, StringLength);
		}

		const char* GetMessageText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, MessageText, offsetof(s_GeneralLogMessage, MessageText));
		}
	};

	/*==========================================================================*/
	struct s_HistoricalPriceDataRequest
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;
		vls_t Symbol;
		vls_t Exchange;
		DTC::HistoricalDataIntervalEnum RecordInterval;
		DTC::t_DateTime StartDateTime;
		DTC::t_DateTime EndDateTime;
		uint32_t MaxDaysToReturn;
		uint8_t  UseZLibCompression;
		uint8_t RequestDividendAdjustedStockData;
		uint8_t Flag_1;

		s_HistoricalPriceDataRequest()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_HistoricalPriceDataRequest));
			Size = sizeof(s_HistoricalPriceDataRequest);
			Type = DTC::HISTORICAL_PRICE_DATA_REQUEST;
			BaseSize = Size;
		}

		int32_t GetRequestID();

		void AddSymbol(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_HistoricalPriceDataRequest, Symbol));
		}

		void AddExchange(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_HistoricalPriceDataRequest, Exchange));
		}

		DTC::HistoricalDataIntervalEnum GetRecordInterval();
		DTC::t_DateTime GetStartDateTime();
		DTC::t_DateTime GetEndDateTime();
		uint32_t GetMaxDaysToReturn();
		uint8_t GetUseZLibCompression();
		uint8_t GetRequestDividendAdjustedStockData();
		uint8_t GetFlag_1();
	};

	/*==========================================================================*/
	struct s_HistoricalPriceDataReject
	{
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;

		vls_t RejectText;

		DTC::HistoricalPriceDataRejectReasonCodeEnum RejectReasonCode;
		uint16_t RetryTimeInSeconds;

		s_HistoricalPriceDataReject()
		{
			Clear();
		}

		uint16_t GetMessageSize();
		uint16_t GetBaseSize();
		void Clear()
		{
			memset(this, 0, sizeof(s_HistoricalPriceDataReject));
			Size = sizeof(s_HistoricalPriceDataReject);
			Type = DTC::HISTORICAL_PRICE_DATA_REJECT;
			BaseSize = Size;
		}

		int32_t GetRequestID();
		DTC::HistoricalPriceDataRejectReasonCodeEnum GetRejectReasonCode();
		uint16_t GetRetryTimeInSeconds();

		void AddRejectText(unsigned int StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_HistoricalPriceDataReject, RejectText));
		}
	};

#pragma pack()
}
