#include "scripting/lua-bindings/auto/lua_cocos2dx_tmx_auto.hpp"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "cocos2d.h"

int lua_cocos2dx_TMXObjectGroup_setPositionOffset(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXObjectGroup* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXObjectGroup",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXObjectGroup*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXObjectGroup_setPositionOffset'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::Vec2 arg0;
        
        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "cc.TMXObjectGroup:setPositionOffset");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXObjectGroup_setPositionOffset'", nullptr);
            return 0;
        }
        cobj->setPositionOffset(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXObjectGroup:setPositionOffset",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXObjectGroup_setPositionOffset'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXObjectGroup_getProperty(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXObjectGroup* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXObjectGroup",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXObjectGroup*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXObjectGroup_getProperty'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::string arg0;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.TMXObjectGroup:getProperty");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXObjectGroup_getProperty'", nullptr);
            return 0;
        }
        cocos2d::Value ret = cobj->getProperty(arg0);
        if (ret.getType() != cocos2d::Value::Type::NONE) {
            ccvalue_to_luaval(tolua_S, ret);
            return 1;
        }
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXObjectGroup:getProperty",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXObjectGroup_getProperty'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXObjectGroup_getPositionOffset(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXObjectGroup* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXObjectGroup",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXObjectGroup*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXObjectGroup_getPositionOffset'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        const cocos2d::Vec2& ret = cobj->getPositionOffset();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXObjectGroup:getPositionOffset",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXObjectGroup_getPositionOffset'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXObjectGroup_getObject(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXObjectGroup* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXObjectGroup",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXObjectGroup*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXObjectGroup_getObject'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::string arg0;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.TMXObjectGroup:getObject");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXObjectGroup_getObject'", nullptr);
            return 0;
        }
        cocos2d::ValueMap ret = cobj->getObject(arg0);
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXObjectGroup:getObject",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXObjectGroup_getObject'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXObjectGroup_getObjects(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXObjectGroup* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXObjectGroup",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::TMXObjectGroup*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXObjectGroup_getObjects'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        const cocos2d::ValueVector& ret = cobj->getObjects();
        ccvaluevector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.TMXObjectGroup:getObjects",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXObjectGroup_getObjects'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXObjectGroup_setGroupName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXObjectGroup* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXObjectGroup",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXObjectGroup*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXObjectGroup_setGroupName'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::string arg0;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.TMXObjectGroup:setGroupName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXObjectGroup_setGroupName'", nullptr);
            return 0;
        }
        cobj->setGroupName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXObjectGroup:setGroupName",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXObjectGroup_setGroupName'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXObjectGroup_getProperties(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXObjectGroup* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXObjectGroup",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::TMXObjectGroup*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXObjectGroup_getProperties'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        cocos2d::ValueMap& ret = cobj->getProperties();
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.TMXObjectGroup:getProperties",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXObjectGroup_getProperties'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXObjectGroup_getGroupName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXObjectGroup* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXObjectGroup",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXObjectGroup*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXObjectGroup_getGroupName'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        const std::string& ret = cobj->getGroupName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXObjectGroup:getGroupName",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXObjectGroup_getGroupName'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXObjectGroup_setProperties(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXObjectGroup* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXObjectGroup",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXObjectGroup*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXObjectGroup_setProperties'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::ValueMap arg0;
        
        ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0, "cc.TMXObjectGroup:setProperties");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXObjectGroup_setProperties'", nullptr);
            return 0;
        }
        cobj->setProperties(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXObjectGroup:setProperties",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXObjectGroup_setProperties'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXObjectGroup_setObjects(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXObjectGroup* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXObjectGroup",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXObjectGroup*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXObjectGroup_setObjects'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::ValueVector arg0;
        
        ok &= luaval_to_ccvaluevector(tolua_S, 2, &arg0, "cc.TMXObjectGroup:setObjects");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXObjectGroup_setObjects'", nullptr);
            return 0;
        }
        cobj->setObjects(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXObjectGroup:setObjects",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXObjectGroup_setObjects'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXObjectGroup_getOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXObjectGroup* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXObjectGroup",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXObjectGroup*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXObjectGroup_getOpacity'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        lua_pushinteger(tolua_S, cobj->getOpacity());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting 0 \n", "cc.TMXObjectGroup:getOpacity",argc);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXObjectGroup_getOpacity'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXObjectGroup_setOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXObjectGroup* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXObjectGroup",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXObjectGroup*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXObjectGroup_setOpacity'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        unsigned int opacity;
        luaval_to_uint32(tolua_S, 2, &opacity, "cc.TMXObjectGroup:setOpacity");
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXObjectGroup_setOpacity'", nullptr);
            return 0;
        }
        cobj->setOpacity(opacity);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting 1 \n", "cc.TMXObjectGroup:setOpacity",argc);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXObjectGroup_setOpacity'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXObjectGroup_isVisible(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXObjectGroup* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXObjectGroup",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXObjectGroup*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXObjectGroup_isVisible'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        lua_pushboolean(tolua_S, cobj->isVisible());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting 0 \n", "cc.TMXObjectGroup:isVisible",argc);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXObjectGroup_isVisible'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXObjectGroup_setVisible(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXObjectGroup* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXObjectGroup",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXObjectGroup*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXObjectGroup_setVisible'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        bool visible;
        luaval_to_boolean(tolua_S, 2, &visible, "cc.TMXObjectGroup:setVisible");
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXObjectGroup_setVisible'", nullptr);
            return 0;
        }
        cobj->setVisible(visible);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting 1 \n", "cc.TMXObjectGroup:setVisible",argc);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXObjectGroup_setVisible'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXObjectGroup_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXObjectGroup* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        cobj = new cocos2d::TMXObjectGroup();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.TMXObjectGroup");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXObjectGroup:TMXObjectGroup",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXObjectGroup_constructor'.",&tolua_err);
#endif
    
    return 0;
}

int lua_register_cocos2dx_TMXObjectGroup(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.TMXObjectGroup");
    tolua_cclass(tolua_S,"TMXObjectGroup","cc.TMXObjectGroup","cc.Ref",nullptr);
    
    tolua_beginmodule(tolua_S,"TMXObjectGroup");
        tolua_function(tolua_S,"new",lua_cocos2dx_TMXObjectGroup_constructor);
        tolua_function(tolua_S,"setPositionOffset",lua_cocos2dx_TMXObjectGroup_setPositionOffset);
        tolua_function(tolua_S,"getProperty",lua_cocos2dx_TMXObjectGroup_getProperty);
        tolua_function(tolua_S,"getPositionOffset",lua_cocos2dx_TMXObjectGroup_getPositionOffset);
        tolua_function(tolua_S,"getObject",lua_cocos2dx_TMXObjectGroup_getObject);
        tolua_function(tolua_S,"getObjects",lua_cocos2dx_TMXObjectGroup_getObjects);
        tolua_function(tolua_S,"setGroupName",lua_cocos2dx_TMXObjectGroup_setGroupName);
        tolua_function(tolua_S,"getProperties",lua_cocos2dx_TMXObjectGroup_getProperties);
        tolua_function(tolua_S,"getGroupName",lua_cocos2dx_TMXObjectGroup_getGroupName);
        tolua_function(tolua_S,"setProperties",lua_cocos2dx_TMXObjectGroup_setProperties);
        tolua_function(tolua_S,"setObjects",lua_cocos2dx_TMXObjectGroup_setObjects);
        tolua_function(tolua_S,"getOpacity",lua_cocos2dx_TMXObjectGroup_getOpacity);
        tolua_function(tolua_S,"setOpacity",lua_cocos2dx_TMXObjectGroup_setOpacity);
        tolua_function(tolua_S,"isVisible",lua_cocos2dx_TMXObjectGroup_isVisible);
        tolua_function(tolua_S,"setVisible",lua_cocos2dx_TMXObjectGroup_setVisible);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::TMXObjectGroup).name();
    g_luaType[typeName] = "cc.TMXObjectGroup";
    g_typeCast["TMXObjectGroup"] = "cc.TMXObjectGroup";
    return 1;
}

int lua_cocos2dx_TMXLayerInfo_setProperties(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayerInfo* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayerInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayerInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayerInfo_setProperties'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::ValueMap arg0;
        
        ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0, "cc.TMXLayerInfo:setProperties");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXLayerInfo_setProperties'", nullptr);
            return 0;
        }
        cobj->setProperties(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayerInfo:setProperties",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayerInfo_setProperties'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayerInfo_getProperties(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayerInfo* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayerInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayerInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayerInfo_getProperties'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        cocos2d::ValueMap& ret = cobj->getProperties();
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayerInfo:getProperties",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayerInfo_getProperties'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayerInfo_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayerInfo* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        cobj = new cocos2d::TMXLayerInfo();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.TMXLayerInfo");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayerInfo:TMXLayerInfo",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayerInfo_constructor'.",&tolua_err);
#endif
    
    return 0;
}

int lua_register_cocos2dx_TMXLayerInfo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.TMXLayerInfo");
    tolua_cclass(tolua_S,"TMXLayerInfo","cc.TMXLayerInfo","cc.Ref",nullptr);
    
    tolua_beginmodule(tolua_S,"TMXLayerInfo");
    tolua_function(tolua_S,"new",lua_cocos2dx_TMXLayerInfo_constructor);
    tolua_function(tolua_S,"setProperties",lua_cocos2dx_TMXLayerInfo_setProperties);
    tolua_function(tolua_S,"getProperties",lua_cocos2dx_TMXLayerInfo_getProperties);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::TMXLayerInfo).name();
    g_luaType[typeName] = "cc.TMXLayerInfo";
    g_typeCast["TMXLayerInfo"] = "cc.TMXLayerInfo";
    return 1;
}

int lua_cocos2dx_TMXTilesetInfo_getRectForGID(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXTilesetInfo* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXTilesetInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXTilesetInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXTilesetInfo_getRectForGID'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        unsigned int arg0;
        
        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "cc.TMXTilesetInfo:getRectForGID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXTilesetInfo_getRectForGID'", nullptr);
            return 0;
        }
        cocos2d::Rect ret = cobj->getRectForGID(arg0);
        rect_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXTilesetInfo:getRectForGID",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTilesetInfo_getRectForGID'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_TMXTilesetInfo_getProperties(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXTilesetInfo* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXTilesetInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXTilesetInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXTilesetInfo_getProperties'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        lua_newtable(tolua_S);
        
        lua_pushstring(tolua_S, "offset");
        vec2_to_luaval(tolua_S, cobj->_tileOffset);
        lua_rawset(tolua_S, -3);    /* property.offset */
        
        lua_pushstring(tolua_S, "name");
        lua_pushstring(tolua_S, cobj->_name.c_str());
        lua_rawset(tolua_S, -3);    /* property.name */

        lua_pushstring(tolua_S, "firstGid");
        lua_pushinteger(tolua_S, cobj->_firstGid);
        lua_rawset(tolua_S, -3);    /* property.firstGid */
        
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXTilesetInfo:getProperties",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTilesetInfo_getProperties'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_TMXTilesetInfo_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXTilesetInfo* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        cobj = new cocos2d::TMXTilesetInfo();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.TMXTilesetInfo");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXTilesetInfo:TMXTilesetInfo",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTilesetInfo_constructor'.",&tolua_err);
#endif
    
    return 0;
}

int lua_register_cocos2dx_TMXTilesetInfo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.TMXTilesetInfo");
    tolua_cclass(tolua_S,"TMXTilesetInfo","cc.TMXTilesetInfo","cc.Ref",nullptr);
    
    tolua_beginmodule(tolua_S,"TMXTilesetInfo");
    tolua_function(tolua_S,"new",lua_cocos2dx_TMXTilesetInfo_constructor);
    tolua_function(tolua_S,"getRectForGID",lua_cocos2dx_TMXTilesetInfo_getRectForGID);
    tolua_function(tolua_S,"getProperties",lua_cocos2dx_TMXTilesetInfo_getProperties);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::TMXTilesetInfo).name();
    g_luaType[typeName] = "cc.TMXTilesetInfo";
    g_typeCast["TMXTilesetInfo"] = "cc.TMXTilesetInfo";
    return 1;
}
int lua_cocos2dx_TMXMapInfo_getHexSideLength(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_getHexSideLength'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        int ret = cobj->getHexSideLength();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXMapInfo:getHexSideLength",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_getHexSideLength'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_getOrientation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_getOrientation'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        int ret = cobj->getOrientation();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXMapInfo:getOrientation",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_getOrientation'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_parseXMLFile(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_parseXMLFile'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::string arg0;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.TMXMapInfo:parseXMLFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXMapInfo_parseXMLFile'", nullptr);
            return 0;
        }
        bool ret = cobj->parseXMLFile(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXMapInfo:parseXMLFile",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_parseXMLFile'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_setTMXFileName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_setTMXFileName'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::string arg0;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.TMXMapInfo:setTMXFileName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXMapInfo_setTMXFileName'", nullptr);
            return 0;
        }
        cobj->setTMXFileName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXMapInfo:setTMXFileName",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_setTMXFileName'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_parseXMLString(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_parseXMLString'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::string arg0;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.TMXMapInfo:parseXMLString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXMapInfo_parseXMLString'", nullptr);
            return 0;
        }
        bool ret = cobj->parseXMLString(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXMapInfo:parseXMLString",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_parseXMLString'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_getLayers(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_getLayers'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        cocos2d::Vector<cocos2d::TMXLayerInfo *>& ret = cobj->getLayers();
        ccvector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.TMXMapInfo:getLayers",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_getLayers'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_getStaggerAxis(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_getStaggerAxis'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXMapInfo_getStaggerAxis'", nullptr);
            return 0;
        }
        int ret = cobj->getStaggerAxis();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXMapInfo:getStaggerAxis",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_getStaggerAxis'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_getTilesets(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_getTilesets'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        cocos2d::Vector<cocos2d::TMXTilesetInfo *>& ret = cobj->getTilesets();
        ccvector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.TMXMapInfo:getTilesets",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_getTilesets'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_getLayerAttribs(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_getLayerAttribs'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        int ret = cobj->getLayerAttribs();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXMapInfo:getLayerAttribs",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_getLayerAttribs'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_getTileSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_getTileSize'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        const cocos2d::Size& ret = cobj->getTileSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXMapInfo:getTileSize",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_getTileSize'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_getTileProperties(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_getTileProperties'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        cocos2d::ValueMapIntKey& ret = cobj->getTileProperties();
        ccvaluemapintkey_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXMapInfo:getTileProperties",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_getTileProperties'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_isStoringCharacters(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_isStoringCharacters'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        bool ret = cobj->isStoringCharacters();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXMapInfo:isStoringCharacters",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_isStoringCharacters'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_getObjectGroups(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_getObjectGroups'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        cocos2d::Vector<cocos2d::TMXObjectGroup *>& ret = cobj->getObjectGroups();
        ccvector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.TMXMapInfo:getObjectGroups",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_getObjectGroups'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_getTMXFileName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_getTMXFileName'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        const std::string& ret = cobj->getTMXFileName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXMapInfo:getTMXFileName",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_getTMXFileName'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_setTileProperties(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_setTileProperties'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::ValueMapIntKey arg0;
        
        ok &= luaval_to_ccvaluemapintkey(tolua_S, 2, &arg0, "cc.TMXMapInfo:setTileProperties");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXMapInfo_setTileProperties'", nullptr);
            return 0;
        }
        cobj->setTileProperties(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXMapInfo:setTileProperties",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_setTileProperties'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_getCurrentString(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_getCurrentString'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        const std::string& ret = cobj->getCurrentString();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXMapInfo:getCurrentString",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_getCurrentString'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_getMapSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_getMapSize'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        const cocos2d::Size& ret = cobj->getMapSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXMapInfo:getMapSize",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_getMapSize'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_getProperties(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_getProperties'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        cocos2d::ValueMap& ret = cobj->getProperties();
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.TMXMapInfo:getProperties",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_getProperties'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_getStaggerIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXMapInfo* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXMapInfo*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXMapInfo_getStaggerIndex'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        int ret = cobj->getStaggerIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXMapInfo:getStaggerIndex",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_getStaggerIndex'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXMapInfo_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    
    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.TMXMapInfo:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXMapInfo_create'", nullptr);
            return 0;
        }
        cocos2d::TMXMapInfo* ret = cocos2d::TMXMapInfo::create(arg0);
        object_to_luaval<cocos2d::TMXMapInfo>(tolua_S, "cc.TMXMapInfo",(cocos2d::TMXMapInfo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.TMXMapInfo:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TMXMapInfo_createWithXML(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.TMXMapInfo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    
    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.TMXMapInfo:createWithXML");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "cc.TMXMapInfo:createWithXML");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXMapInfo_createWithXML'", nullptr);
            return 0;
        }
        cocos2d::TMXMapInfo* ret = cocos2d::TMXMapInfo::createWithXML(arg0, arg1);
        object_to_luaval<cocos2d::TMXMapInfo>(tolua_S, "cc.TMXMapInfo",(cocos2d::TMXMapInfo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.TMXMapInfo:createWithXML",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXMapInfo_createWithXML'.",&tolua_err);
#endif
    return 0;
}

int lua_register_cocos2dx_TMXMapInfo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.TMXMapInfo");
    tolua_cclass(tolua_S,"TMXMapInfo","cc.TMXMapInfo","",nullptr);
    
    tolua_beginmodule(tolua_S,"TMXMapInfo");
    tolua_function(tolua_S,"getHexSideLength",lua_cocos2dx_TMXMapInfo_getHexSideLength);
    tolua_function(tolua_S,"getOrientation",lua_cocos2dx_TMXMapInfo_getOrientation);
    tolua_function(tolua_S,"parseXMLFile",lua_cocos2dx_TMXMapInfo_parseXMLFile);
    tolua_function(tolua_S,"setTMXFileName",lua_cocos2dx_TMXMapInfo_setTMXFileName);
    tolua_function(tolua_S,"parseXMLString",lua_cocos2dx_TMXMapInfo_parseXMLString);
    tolua_function(tolua_S,"getLayers",lua_cocos2dx_TMXMapInfo_getLayers);
    tolua_function(tolua_S,"getStaggerAxis",lua_cocos2dx_TMXMapInfo_getStaggerAxis);
    tolua_function(tolua_S,"getTilesets",lua_cocos2dx_TMXMapInfo_getTilesets);
    tolua_function(tolua_S,"getLayerAttribs",lua_cocos2dx_TMXMapInfo_getLayerAttribs);
    tolua_function(tolua_S,"getTileSize",lua_cocos2dx_TMXMapInfo_getTileSize);
    tolua_function(tolua_S,"getTileProperties",lua_cocos2dx_TMXMapInfo_getTileProperties);
    tolua_function(tolua_S,"isStoringCharacters",lua_cocos2dx_TMXMapInfo_isStoringCharacters);
    tolua_function(tolua_S,"getObjectGroups",lua_cocos2dx_TMXMapInfo_getObjectGroups);
    tolua_function(tolua_S,"getTMXFileName",lua_cocos2dx_TMXMapInfo_getTMXFileName);
    tolua_function(tolua_S,"getCurrentString",lua_cocos2dx_TMXMapInfo_getCurrentString);
    tolua_function(tolua_S,"getMapSize",lua_cocos2dx_TMXMapInfo_getMapSize);
    tolua_function(tolua_S,"getProperties",lua_cocos2dx_TMXMapInfo_getProperties);
    tolua_function(tolua_S,"getStaggerIndex",lua_cocos2dx_TMXMapInfo_getStaggerIndex);
    tolua_function(tolua_S,"create", lua_cocos2dx_TMXMapInfo_create);
    tolua_function(tolua_S,"createWithXML", lua_cocos2dx_TMXMapInfo_createWithXML);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::TMXMapInfo).name();
    g_luaType[typeName] = "cc.TMXMapInfo";
    g_typeCast["TMXMapInfo"] = "cc.TMXMapInfo";
    return 1;
}

int lua_cocos2dx_TMXLayer_getPositionAt(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_getPositionAt'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::Vec2 arg0;
        
        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "cc.TMXLayer:getPositionAt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXLayer_getPositionAt'", nullptr);
            return 0;
        }
        cocos2d::Vec2 ret = cobj->getPositionAt(arg0);
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayer:getPositionAt",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_getPositionAt'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayer_setLayerOrientation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_setLayerOrientation'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        int arg0;
        
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.TMXLayer:setLayerOrientation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXLayer_setLayerOrientation'", nullptr);
            return 0;
        }
        cobj->setLayerOrientation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayer:setLayerOrientation",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_setLayerOrientation'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayer_getLayerSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_getLayerSize'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        const cocos2d::Size& ret = cobj->getLayerSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayer:getLayerSize",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_getLayerSize'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayer_setMapTileSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_setMapTileSize'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::Size arg0;
        
        ok &= luaval_to_size(tolua_S, 2, &arg0, "cc.TMXLayer:setMapTileSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXLayer_setMapTileSize'", nullptr);
            return 0;
        }
        cobj->setMapTileSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayer:setMapTileSize",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_setMapTileSize'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayer_getLayerOrientation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_getLayerOrientation'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        int ret = cobj->getLayerOrientation();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayer:getLayerOrientation",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_getLayerOrientation'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayer_setProperties(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_setProperties'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::ValueMap arg0;
        
        ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0, "cc.TMXLayer:setProperties");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXLayer_setProperties'", nullptr);
            return 0;
        }
        cobj->setProperties(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayer:setProperties",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_setProperties'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayer_setLayerName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_setLayerName'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::string arg0;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.TMXLayer:setLayerName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXLayer_setLayerName'", nullptr);
            return 0;
        }
        cobj->setLayerName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayer:setLayerName",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_setLayerName'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayer_removeTileAt(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_removeTileAt'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc > 0) {
        cocos2d::Vec2 arg0;
        bool arg1 = true;
        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "cc.TMXLayer:removeTileAt");
        if (argc > 1) {
            ok &= luaval_to_boolean(tolua_S, 3, &arg1, "cc.TMXLayer:removeTileAt");
        }
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXLayer_removeTileAt'", nullptr);
            return 0;
        }
        cobj->removeTileAt(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayer:removeTileAt",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_removeTileAt'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayer_setTileGID(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_setTileGID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc > 1) {
        unsigned int arg0;
        cocos2d::Vec2 arg1;
        cocos2d::TMXTileFlags arg2 = (cocos2d::TMXTileFlags)0;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "cc.TMXLayer:setTileGID");
        ok &= luaval_to_vec2(tolua_S, 3, &arg1, "cc.TMXLayer:setTileGID");
        if (argc > 2) {
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "cc.TMXLayer:setTileGID");
        }
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXLayer_setTileGID'", nullptr);
            return 0;
        }

        cobj->setTileGID(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting 2~3 \n",  "cc.TMXLayer:setTileGID",argc);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_setTileGID'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayer_getMapTileSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_getMapTileSize'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        const cocos2d::Size& ret = cobj->getMapTileSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayer:getMapTileSize",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_getMapTileSize'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayer_getProperty(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_getProperty'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::string arg0;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.TMXLayer:getProperty");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXLayer_getProperty'", nullptr);
            return 0;
        }
        cocos2d::Value ret = cobj->getProperty(arg0);
        if (ret.getType() != cocos2d::Value::Type::NONE) {
            ccvalue_to_luaval(tolua_S, ret);
            return 1;
        }
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayer:getProperty",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_getProperty'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayer_setLayerSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_setLayerSize'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::Size arg0;
        
        ok &= luaval_to_size(tolua_S, 2, &arg0, "cc.TMXLayer:setLayerSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXLayer_setLayerSize'", nullptr);
            return 0;
        }
        cobj->setLayerSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayer:setLayerSize",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_setLayerSize'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayer_getLayerName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_getLayerName'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        const std::string& ret = cobj->getLayerName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayer:getLayerName",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_getLayerName'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayer_getLocalZForPos(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_getLocalZForPos'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        cocos2d::Vec2 arg0;
        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "cc.TMXLayer:getLocalZForPos");
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXLayer_getLocalZForPos'", nullptr);
            return 0;
        }
        int ret = cobj->getLocalZForPos(arg0);
        lua_pushinteger(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayer:getLocalZForPos",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_getLocalZForPos'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TMXLayer_getLayerType(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_getLayerType'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        int ret = cobj->getLayerType();
        lua_pushinteger(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting 0 \n", "cc.TMXLayer:getLayerType",argc);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_getLayerType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TMXLayer_getProperties(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_getProperties'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        cocos2d::ValueMap& ret = cobj->getProperties();
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.TMXLayer:getProperties",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_getProperties'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayer_getTileAt(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_getTileAt'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::Vec2 arg0;
        
        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "cc.TMXLayer:getTileAt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXLayer_getTileAt'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->getTileAt(arg0);
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayer:getTileAt",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_getTileAt'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayer_setupTiles(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXLayer* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXLayer*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXLayer_setupTiles'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        cobj->setupTiles();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXLayer:setupTiles",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_setupTiles'.",&tolua_err);
#endif
    
    return 0;
}
int lua_cocos2dx_TMXLayer_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.TMXLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    
    if (argc == 2)
    {
        cocos2d::TMXLayerInfo* arg0_1 = nullptr;
        cocos2d::TMXImageLayerInfo* arg0_2 = nullptr;
        cocos2d::TMXGroupInfo* arg0_3 = nullptr;
        cocos2d::TMXObjectGroup* arg0_4 = nullptr;
        cocos2d::TMXTiledMap* arg1 = nullptr;
        
        ok = luaval_to_object<cocos2d::TMXLayerInfo>(tolua_S, 2, "cc.TMXLayerInfo",&arg0_1, "cc.TMXLayer:create");
        if(!ok) {
            ok = luaval_to_object<cocos2d::TMXImageLayerInfo>(tolua_S, 2, "cc.TMXLayerInfo",&arg0_2, "cc.TMXLayer:create");
        }
        if(!ok) {
            ok = luaval_to_object<cocos2d::TMXGroupInfo>(tolua_S, 2, "cc.TMXLayerInfo",&arg0_3, "cc.TMXLayer:create");
        }
        if(!ok) {
            ok = luaval_to_object<cocos2d::TMXObjectGroup>(tolua_S, 2, "cc.TMXLayerInfo",&arg0_4, "cc.TMXLayer:create");
        }
        ok &= luaval_to_object<cocos2d::TMXTiledMap>(tolua_S, 3, "cc.TMXTiledMap",&arg1, "cc.TMXLayer:create");
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXLayer_create'", nullptr);
            return 0;
        }
        cocos2d::TMXLayer* ret = nullptr;
        if (arg0_1) {
            ret = cocos2d::TMXLayer::create(arg0_1, arg1);
        } else if(arg0_2) {
            ret = cocos2d::TMXLayer::create(arg0_2, arg1);
        } else if(arg0_3) {
            ret = cocos2d::TMXLayer::create(arg0_3, arg1);
        } else {
            ret = cocos2d::TMXLayer::create(arg0_4, arg1);
        }
        object_to_luaval<cocos2d::TMXLayer>(tolua_S, "cc.TMXLayer", ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.TMXLayer:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXLayer_create'.",&tolua_err);
#endif
    return 0;
}

int lua_register_cocos2dx_TMXLayer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.TMXLayer");
    tolua_cclass(tolua_S,"TMXLayer","cc.TMXLayer","cc.Node",nullptr);
    
    tolua_beginmodule(tolua_S,"TMXLayer");
    tolua_function(tolua_S,"getPositionAt",lua_cocos2dx_TMXLayer_getPositionAt);
    tolua_function(tolua_S,"setLayerOrientation",lua_cocos2dx_TMXLayer_setLayerOrientation);
    tolua_function(tolua_S,"getLayerSize",lua_cocos2dx_TMXLayer_getLayerSize);
    tolua_function(tolua_S,"setMapTileSize",lua_cocos2dx_TMXLayer_setMapTileSize);
    tolua_function(tolua_S,"getLayerOrientation",lua_cocos2dx_TMXLayer_getLayerOrientation);
    tolua_function(tolua_S,"setProperties",lua_cocos2dx_TMXLayer_setProperties);
    tolua_function(tolua_S,"setLayerName",lua_cocos2dx_TMXLayer_setLayerName);
    tolua_function(tolua_S,"removeTileAt",lua_cocos2dx_TMXLayer_removeTileAt);
    tolua_function(tolua_S,"setTileGID",lua_cocos2dx_TMXLayer_setTileGID);
    tolua_function(tolua_S,"getMapTileSize",lua_cocos2dx_TMXLayer_getMapTileSize);
    tolua_function(tolua_S,"getProperty",lua_cocos2dx_TMXLayer_getProperty);
    tolua_function(tolua_S,"setLayerSize",lua_cocos2dx_TMXLayer_setLayerSize);
    tolua_function(tolua_S,"getLayerName",lua_cocos2dx_TMXLayer_getLayerName);
    tolua_function(tolua_S,"getLocalZForPos",lua_cocos2dx_TMXLayer_getLocalZForPos);
    tolua_function(tolua_S,"getLayerType",lua_cocos2dx_TMXLayer_getLayerType);
    tolua_function(tolua_S,"getProperties",lua_cocos2dx_TMXLayer_getProperties);
    tolua_function(tolua_S,"getTileAt",lua_cocos2dx_TMXLayer_getTileAt);
    tolua_function(tolua_S,"setupTiles",lua_cocos2dx_TMXLayer_setupTiles);
    tolua_function(tolua_S,"create", lua_cocos2dx_TMXLayer_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::TMXLayer).name();
    g_luaType[typeName] = "cc.TMXLayer";
    g_typeCast["TMXLayer"] = "cc.TMXLayer";
    return 1;
}

int lua_cocos2dx_TMXTiledMap_setObjectGroups(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXTiledMap* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXTiledMap",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXTiledMap*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXTiledMap_setObjectGroups'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::Vector<cocos2d::TMXObjectGroup *> arg0;
        
        ok &= luaval_to_ccvector(tolua_S, 2, &arg0, "cc.TMXTiledMap:setObjectGroups");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXTiledMap_setObjectGroups'", nullptr);
            return 0;
        }
        cobj->setObjectGroups(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXTiledMap:setObjectGroups",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTiledMap_setObjectGroups'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_TMXTiledMap_getProperty(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXTiledMap* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXTiledMap",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXTiledMap*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXTiledMap_getProperty'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::string arg0;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.TMXTiledMap:getProperty");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXTiledMap_getProperty'", nullptr);
            return 0;
        }
        cocos2d::Value ret = cobj->getProperty(arg0);
        ccvalue_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXTiledMap:getProperty",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTiledMap_getProperty'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_TMXTiledMap_setMapSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXTiledMap* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXTiledMap",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXTiledMap*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXTiledMap_setMapSize'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::Size arg0;
        
        ok &= luaval_to_size(tolua_S, 2, &arg0, "cc.TMXTiledMap:setMapSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXTiledMap_setMapSize'", nullptr);
            return 0;
        }
        cobj->setMapSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXTiledMap:setMapSize",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTiledMap_setMapSize'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_TMXTiledMap_getObjectGroup(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXTiledMap* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXTiledMap",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXTiledMap*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXTiledMap_getObjectGroup'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::string arg0;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.TMXTiledMap:getObjectGroup");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXTiledMap_getObjectGroup'", nullptr);
            return 0;
        }
        cocos2d::TMXObjectGroup* ret = cobj->getObjectGroup(arg0);
        object_to_luaval<cocos2d::TMXObjectGroup>(tolua_S, "cc.TMXObjectGroup",(cocos2d::TMXObjectGroup*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXTiledMap:getObjectGroup",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTiledMap_getObjectGroup'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_TMXTiledMap_getObjectGroups(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXTiledMap* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXTiledMap",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::TMXTiledMap*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXTiledMap_getObjectGroups'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        cocos2d::Vector<cocos2d::TMXObjectGroup *>& ret = cobj->getObjectGroups();
        ccvector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.TMXTiledMap:getObjectGroups",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTiledMap_getObjectGroups'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_TMXTiledMap_getResourceFile(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXTiledMap* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXTiledMap",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXTiledMap*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXTiledMap_getResourceFile'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        const std::string& ret = cobj->getResourceFile();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXTiledMap:getResourceFile",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTiledMap_getResourceFile'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_TMXTiledMap_getTileSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXTiledMap* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXTiledMap",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXTiledMap*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXTiledMap_getTileSize'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        const cocos2d::Size& ret = cobj->getTileSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXTiledMap:getTileSize",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTiledMap_getTileSize'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_TMXTiledMap_getMapSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXTiledMap* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXTiledMap",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXTiledMap*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXTiledMap_getMapSize'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        const cocos2d::Size& ret = cobj->getMapSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXTiledMap:getMapSize",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTiledMap_getMapSize'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_TMXTiledMap_getProperties(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXTiledMap* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXTiledMap",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXTiledMap*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXTiledMap_getProperties'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        cocos2d::ValueMap& ret = cobj->getProperties();
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXTiledMap:getProperties",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTiledMap_getProperties'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_TMXTiledMap_setTileSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXTiledMap* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXTiledMap",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXTiledMap*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXTiledMap_setTileSize'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::Size arg0;
        
        ok &= luaval_to_size(tolua_S, 2, &arg0, "cc.TMXTiledMap:setTileSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXTiledMap_setTileSize'", nullptr);
            return 0;
        }
        cobj->setTileSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXTiledMap:setTileSize",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTiledMap_setTileSize'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_TMXTiledMap_setProperties(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXTiledMap* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXTiledMap",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXTiledMap*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXTiledMap_setProperties'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::ValueMap arg0;
        
        ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0, "cc.TMXTiledMap:setProperties");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXTiledMap_setProperties'", nullptr);
            return 0;
        }
        cobj->setProperties(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXTiledMap:setProperties",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTiledMap_setProperties'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_TMXTiledMap_getLayer(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXTiledMap* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXTiledMap",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXTiledMap*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXTiledMap_getLayer'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::string arg0;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.TMXTiledMap:getLayer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXTiledMap_getLayer'", nullptr);
            return 0;
        }
        cocos2d::TMXLayer* ret = cobj->getLayer(arg0);
        object_to_luaval<cocos2d::TMXLayer>(tolua_S, "cc.TMXLayer",(cocos2d::TMXLayer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXTiledMap:getLayer",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTiledMap_getLayer'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_TMXTiledMap_getMapOrientation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXTiledMap* cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXTiledMap",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXTiledMap*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXTiledMap_getMapOrientation'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        int ret = cobj->getMapOrientation();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXTiledMap:getMapOrientation",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTiledMap_getMapOrientation'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_TMXTiledMap_setMapOrientation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TMXTiledMap* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TMXTiledMap",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::TMXTiledMap*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_TMXTiledMap_setMapOrientation'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        int arg0;
        
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.TMXTiledMap:setMapOrientation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXTiledMap_setMapOrientation'", nullptr);
            return 0;
        }
        cobj->setMapOrientation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TMXTiledMap:setMapOrientation",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTiledMap_setMapOrientation'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_TMXTiledMap_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.TMXTiledMap",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    if (argc > 0) {
        std::string arg0;
        bool arg1 = true;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.TMXTiledMap:create");
        if (argc > 1) { // option arg
            ok &= luaval_to_boolean(tolua_S, 3,&arg1, "cc.TMXTiledMap:create");
        }
        if (!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXTiledMap_create'", nullptr);
            return 0;
        }
        cocos2d::TMXTiledMap* ret = cocos2d::TMXTiledMap::create(arg0, arg1);
        object_to_luaval<cocos2d::TMXTiledMap>(tolua_S, "cc.TMXTiledMap",(cocos2d::TMXTiledMap*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting 1~2\n ", "cc.TMXTiledMap:create",argc);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTiledMap_create'.",&tolua_err);
#endif
    return 0;
}

int lua_cocos2dx_TMXTiledMap_createWithXML(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.TMXTiledMap",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    if (argc > 1) {
        std::string arg0;
        std::string arg1;
        bool arg2 = true;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.TMXTiledMap:createWithXML");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "cc.TMXTiledMap:createWithXML");
        if (argc > 2) { // option arg
            ok &= luaval_to_boolean(tolua_S, 4,&arg2, "cc.TMXTiledMap:createWithXML");
        }
        if (!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_TMXTiledMap_createWithXML'", nullptr);
            return 0;
        }
        cocos2d::TMXTiledMap* ret = cocos2d::TMXTiledMap::createWithXML(arg0, arg1, arg2);
        object_to_luaval<cocos2d::TMXTiledMap>(tolua_S, "cc.TMXTiledMap",(cocos2d::TMXTiledMap*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting 2~3\n ", "cc.TMXTiledMap:createWithXML",argc);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TMXTiledMap_createWithXML'.",&tolua_err);
#endif
    return 0;
}

int lua_register_cocos2dx_TMXTiledMap(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.TMXTiledMap");
    tolua_cclass(tolua_S,"TMXTiledMap","cc.TMXTiledMap","cc.Node",nullptr);
    
    tolua_beginmodule(tolua_S,"TMXTiledMap");
    tolua_function(tolua_S,"setObjectGroups",lua_cocos2dx_TMXTiledMap_setObjectGroups);
    tolua_function(tolua_S,"getProperty",lua_cocos2dx_TMXTiledMap_getProperty);
    tolua_function(tolua_S,"setMapSize",lua_cocos2dx_TMXTiledMap_setMapSize);
    tolua_function(tolua_S,"getObjectGroup",lua_cocos2dx_TMXTiledMap_getObjectGroup);
    tolua_function(tolua_S,"getObjectGroups",lua_cocos2dx_TMXTiledMap_getObjectGroups);
    tolua_function(tolua_S,"getResourceFile",lua_cocos2dx_TMXTiledMap_getResourceFile);
    tolua_function(tolua_S,"getTileSize",lua_cocos2dx_TMXTiledMap_getTileSize);
    tolua_function(tolua_S,"getMapSize",lua_cocos2dx_TMXTiledMap_getMapSize);
    tolua_function(tolua_S,"getProperties",lua_cocos2dx_TMXTiledMap_getProperties);
    tolua_function(tolua_S,"setTileSize",lua_cocos2dx_TMXTiledMap_setTileSize);
    tolua_function(tolua_S,"setProperties",lua_cocos2dx_TMXTiledMap_setProperties);
    tolua_function(tolua_S,"getLayer",lua_cocos2dx_TMXTiledMap_getLayer);
    tolua_function(tolua_S,"getMapOrientation",lua_cocos2dx_TMXTiledMap_getMapOrientation);
    tolua_function(tolua_S,"setMapOrientation",lua_cocos2dx_TMXTiledMap_setMapOrientation);
    tolua_function(tolua_S,"create", lua_cocos2dx_TMXTiledMap_create);
    tolua_function(tolua_S,"createWithXML", lua_cocos2dx_TMXTiledMap_createWithXML);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::TMXTiledMap).name();
    g_luaType[typeName] = "cc.TMXTiledMap";
    g_typeCast["TMXTiledMap"] = "cc.TMXTiledMap";
    return 1;
}
