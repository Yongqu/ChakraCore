//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------

#pragma once

namespace Js
{
    class JavascriptSIMDUint8x16 sealed : public RecyclableObject
    {
    private:
        SIMDValue value;
        DEFINE_VTABLE_CTOR(JavascriptSIMDUint8x16, RecyclableObject);
    public:
        class EntryInfo
        {
        public:
            static FunctionInfo ToString;
        };

        JavascriptSIMDUint8x16(SIMDValue *val, StaticType *type);
        static JavascriptSIMDUint8x16* New(SIMDValue *val, ScriptContext* requestContext);
        static bool Is(Var instance);
        static JavascriptSIMDUint8x16* FromVar(Var aValue);

        __inline SIMDValue GetValue() { return value; }

        virtual BOOL GetPropertyReference(Var originalInstance, PropertyId propertyId, Var* value, PropertyValueInfo* info, ScriptContext* requestContext) override;
        virtual BOOL GetProperty(Var originalInstance, PropertyId propertyId, Var* value, PropertyValueInfo* info, ScriptContext* requestContext) override;
        virtual BOOL GetProperty(Var originalInstance, JavascriptString* propertyNameString, Var* value, PropertyValueInfo* info, ScriptContext* requestContext) override;
        virtual RecyclableObject * CloneToScriptContext(ScriptContext* requestContext) override;

        // Entry Points
        /*
        There is one toString per SIMD type. The code is entrant from value objects explicitly (e.g. a.toString()) or on overloaded operations.
        It will also be a property of SIMD.int32x4.prototype for SIMD dynamic objects.
        */
        static Var EntryToString(RecyclableObject* function, CallInfo callInfo, ...);
        // End Entry Points

        Var  Copy(ScriptContext* requestContext);

    private:
        bool GetPropertyBuiltIns(PropertyId propertyId, Var* value, ScriptContext* requestContext);
    };
}
