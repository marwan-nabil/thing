#pragma once

#define Assert(Expression) {if(!(Expression)){ *(int *)0 = 0; }}
#define AbsoluteValue(X) ((u32)(((X) < 0)?-(X):(X)))
#define Assert(Expression) {if(!(Expression)){ *(int *)0 = 0; }}
#define AssertBit(Value) Assert(!((Value) & (~1ull)))
#define AssertFits(Value, FittingMask) Assert(!((Value) & (~(FittingMask))))
