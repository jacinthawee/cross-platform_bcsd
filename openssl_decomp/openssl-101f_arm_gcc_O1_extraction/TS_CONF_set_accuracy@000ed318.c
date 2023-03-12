
int TS_CONF_set_accuracy(CONF *param_1,char *param_2,undefined4 param_3)

{
  _STACK *st;
  int iVar1;
  void *pvVar2;
  int iVar3;
  char *__s1;
  long lVar4;
  long lVar5;
  long lVar6;
  
  st = (_STACK *)NCONF_get_string(param_1,param_2,"accuracy");
  if ((st == (_STACK *)0x0) || (st = (_STACK *)X509V3_parse_list((char *)st), st != (_STACK *)0x0))
  {
    lVar5 = 0;
    lVar6 = 0;
    lVar4 = 0;
    for (iVar3 = 0; iVar1 = sk_num(st), iVar3 < iVar1; iVar3 = iVar3 + 1) {
      pvVar2 = sk_value(st,iVar3);
      __s1 = *(char **)((int)pvVar2 + 4);
      iVar1 = strcmp(__s1,"secs");
      if (iVar1 == 0) {
        if (*(char **)((int)pvVar2 + 8) != (char *)0x0) {
          lVar4 = strtol(*(char **)((int)pvVar2 + 8),(char **)0x0,10);
        }
      }
      else {
        iVar1 = strcmp(__s1,"millisecs");
        if (iVar1 == 0) {
          if (*(char **)((int)pvVar2 + 8) != (char *)0x0) {
            lVar6 = strtol(*(char **)((int)pvVar2 + 8),(char **)0x0,10);
          }
        }
        else {
          iVar1 = strcmp(__s1,"microsecs");
          if (iVar1 != 0) goto LAB_000ed3ee;
          if (*(char **)((int)pvVar2 + 8) != (char *)0x0) {
            lVar5 = strtol(*(char **)((int)pvVar2 + 8),(char **)0x0,10);
          }
        }
      }
    }
    iVar3 = TS_RESP_CTX_set_accuracy(param_3,lVar4,lVar6,lVar5);
    if (iVar3 != 0) {
      iVar3 = 1;
    }
  }
  else {
LAB_000ed3ee:
    iVar3 = 0;
    __fprintf_chk(stderr,1,"invalid variable value for %s::%s\n",param_2,"accuracy");
  }
  sk_pop_free(st,X509V3_conf_free + 1);
  return iVar3;
}

