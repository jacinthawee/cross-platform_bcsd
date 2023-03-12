
ASN1_OBJECT * TS_CONF_set_policies(CONF *param_1,char *param_2,undefined4 param_3)

{
  ASN1_OBJECT *st;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  void *pvVar3;
  ASN1_OBJECT *a;
  int iVar4;
  
  st = (ASN1_OBJECT *)NCONF_get_string(param_1,param_2,"other_policies");
  if ((st == (ASN1_OBJECT *)0x0) ||
     (pAVar1 = (ASN1_OBJECT *)X509V3_parse_list((char *)st), st = pAVar1,
     pAVar1 != (ASN1_OBJECT *)0x0)) {
    iVar4 = 0;
    while( true ) {
      iVar2 = sk_num((_STACK *)st);
      if (iVar2 <= iVar4) break;
      pvVar3 = sk_value((_STACK *)st,iVar4);
      if (*(char **)((int)pvVar3 + 8) == (char *)0x0) {
        a = OBJ_txt2obj(*(char **)((int)pvVar3 + 4),0);
      }
      else {
        a = OBJ_txt2obj(*(char **)((int)pvVar3 + 8),0);
      }
      if (a == (ASN1_OBJECT *)0x0) {
        __fprintf_chk(stderr,1,"invalid variable value for %s::%s\n",param_2,"other_policies");
        pAVar1 = a;
        goto LAB_000eb25c;
      }
      pAVar1 = (ASN1_OBJECT *)TS_RESP_CTX_add_policy(param_3,a);
      if (pAVar1 == (ASN1_OBJECT *)0x0) goto LAB_000eb25c;
      ASN1_OBJECT_free(a);
      iVar4 = iVar4 + 1;
    }
    pAVar1 = (ASN1_OBJECT *)0x1;
  }
  else {
    __fprintf_chk(stderr,1,"invalid variable value for %s::%s\n",param_2,"other_policies");
  }
LAB_000eb25c:
  sk_pop_free((_STACK *)st,X509V3_conf_free + 1);
  return pAVar1;
}

