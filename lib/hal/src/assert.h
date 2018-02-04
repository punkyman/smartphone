#pragma once

#define CONCAT_TOKENS( TokenA, TokenB )       TokenA ## TokenB
#define EXPAND_THEN_CONCAT( TokenA, TokenB )  CONCAT_TOKENS( TokenA, TokenB )
#define STATIC_ASSERT( Expression )                  enum{ EXPAND_THEN_CONCAT( ASSERT_line_, __LINE__ ) = 1 / !!( Expression ) }
#define STATIC_ASSERT_MESSAGE( Expression, Message )        enum{ EXPAND_THEN_CONCAT( Message ## _ASSERT_line_, __LINE__ ) = 1 / !!( Expression ) }  
