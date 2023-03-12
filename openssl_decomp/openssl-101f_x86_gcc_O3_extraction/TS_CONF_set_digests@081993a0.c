
undefined4 TS_CONF_set_digests(CONF *param_1,char *param_2,undefined4 param_3)

{
  char *line;
  _STACK *st;
  int iVar1;
  int iVar2;
  void *pvVar3;
  EVP_MD *pEVar4;
  undefined4 uVar5;
  
  line = NCONF_get_string(param_1,param_2,"digests");
  if (line == (char *)0x0) {
    st = (_STACK *)0x0;
    uVar5 = 0;
    __fprintf_chk(stderr,1,"variable lookup failed for %s::%s\n",param_2,"digests");
  }
  else {
    st = (_STACK *)X509V3_parse_list(line);
    if ((st == (_STACK *)0x0) || (iVar1 = sk_num(st), iVar1 == 0)) {
LAB_08199450:
      uVar5 = 0;
      __fprintf_chk(stderr,1,"invalid variable value for %s::%s\n",param_2,"digests");
    }
    else {
      for (iVar1 = 0; iVar2 = sk_num(st), iVar1 < iVar2; iVar1 = iVar1 + 1) {
        pvVar3 = sk_value(st,iVar1);
        if (*(char **)((int)pvVar3 + 8) == (char *)0x0) {
          pEVar4 = EVP_get_digestbyname(*(char **)((int)pvVar3 + 4));
        }
        else {
          pEVar4 = EVP_get_digestbyname(*(char **)((int)pvVar3 + 8));
        }
        if (pEVar4 == (EVP_MD *)0x0) goto LAB_08199450;
        iVar2 = TS_RESP_CTX_add_md(param_3,pEVar4);
        if (iVar2 == 0) {
          uVar5 = 0;
          goto LAB_08199470;
        }
      }
      uVar5 = 1;
    }
  }
LAB_08199470:
  sk_pop_free(st,X509V3_conf_free);
  return uVar5;
}

