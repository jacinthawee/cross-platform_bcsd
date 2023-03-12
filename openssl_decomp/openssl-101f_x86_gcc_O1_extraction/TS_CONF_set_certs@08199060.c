
bool TS_CONF_set_certs(CONF *param_1,char *param_2,char *param_3,undefined4 param_4)

{
  _STACK *st;
  int iVar1;
  bool bVar2;
  
  if (param_3 == (char *)0x0) {
    param_3 = NCONF_get_string(param_1,param_2,"certs");
    if (param_3 == (char *)0x0) {
      st = (_STACK *)0x0;
      bVar2 = true;
      goto LAB_0819909b;
    }
  }
  bVar2 = false;
  st = (_STACK *)TS_CONF_load_certs(param_3);
  if (st != (_STACK *)0x0) {
    iVar1 = TS_RESP_CTX_set_certs(param_4,st);
    bVar2 = iVar1 != 0;
  }
LAB_0819909b:
  sk_pop_free(st,X509_free);
  return bVar2;
}

