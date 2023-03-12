
undefined4 TS_CONF_set_policies(CONF *param_1,char *param_2,undefined4 param_3)

{
  char *pcVar1;
  _STACK *st;
  ASN1_OBJECT *a;
  int iVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  
  pcVar1 = NCONF_get_string(param_1,param_2,"other_policies");
  if (pcVar1 == (char *)0x0) {
    st = (_STACK *)0x0;
  }
  else {
    st = (_STACK *)X509V3_parse_list(pcVar1);
    if (st == (_STACK *)0x0) {
LAB_08199348:
      uVar5 = 0;
      __fprintf_chk(stderr,1,"invalid variable value for %s::%s\n",param_2,"other_policies");
      goto LAB_0819936b;
    }
  }
  iVar4 = 0;
  while( true ) {
    iVar2 = sk_num(st);
    if (iVar2 <= iVar4) break;
    pvVar3 = sk_value(st,iVar4);
    pcVar1 = *(char **)((int)pvVar3 + 8);
    if (pcVar1 == (char *)0x0) {
      pcVar1 = *(char **)((int)pvVar3 + 4);
    }
    a = OBJ_txt2obj(pcVar1,0);
    if (a == (ASN1_OBJECT *)0x0) goto LAB_08199348;
    iVar2 = TS_RESP_CTX_add_policy(param_3,a);
    if (iVar2 == 0) {
      uVar5 = 0;
      goto LAB_0819936b;
    }
    iVar4 = iVar4 + 1;
    ASN1_OBJECT_free(a);
  }
  uVar5 = 1;
LAB_0819936b:
  sk_pop_free(st,X509V3_conf_free);
  return uVar5;
}

