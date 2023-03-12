
_STACK * TS_CONF_set_certs(CONF *param_1,char *param_2,_STACK *param_3,undefined4 param_4)

{
  _STACK *p_Var1;
  
  if ((param_3 == (_STACK *)0x0) &&
     (param_3 = (_STACK *)NCONF_get_string(param_1,param_2,"certs"), param_3 == (_STACK *)0x0)) {
    p_Var1 = (_STACK *)0x1;
  }
  else {
    param_3 = (_STACK *)TS_CONF_load_certs(param_3);
    p_Var1 = param_3;
    if ((param_3 != (_STACK *)0x0) &&
       (p_Var1 = (_STACK *)TS_RESP_CTX_set_certs(param_4,param_3), p_Var1 != (_STACK *)0x0)) {
      p_Var1 = (_STACK *)0x1;
    }
  }
  sk_pop_free(param_3,X509_free + 1);
  return p_Var1;
}

