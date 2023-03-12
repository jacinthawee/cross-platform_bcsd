
undefined4 __regparm3 set_multi_opts(uint *param_1,char *param_2,char **param_3)

{
  char cVar1;
  char *__s2;
  _STACK *st;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  char *pcVar5;
  char **ppcVar6;
  int iVar7;
  undefined4 local_20;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar7 = 0;
  st = (_STACK *)X509V3_parse_list(param_2);
  local_20 = 1;
  iVar2 = sk_num(st);
  if (0 < iVar2) {
    do {
      pvVar3 = sk_value(st,iVar7);
      pcVar5 = *(char **)((int)pvVar3 + 4);
      cVar1 = *pcVar5;
      if (cVar1 == '-') {
        pcVar5 = pcVar5 + 1;
      }
      else {
        pcVar5 = pcVar5 + (cVar1 == '+');
      }
      __s2 = *param_3;
      ppcVar6 = param_3;
      while (__s2 != (char *)0x0) {
        iVar2 = strcasecmp(pcVar5,__s2);
        if (iVar2 == 0) {
          uVar4 = ~(uint)ppcVar6[2] & *param_1;
          *param_1 = uVar4;
          if (cVar1 == '-') {
            uVar4 = uVar4 & ~(uint)ppcVar6[1];
          }
          else {
            uVar4 = uVar4 | (uint)ppcVar6[1];
          }
          *param_1 = uVar4;
          goto LAB_08079786;
        }
        ppcVar6 = ppcVar6 + 3;
        __s2 = *ppcVar6;
      }
      local_20 = 0;
LAB_08079786:
      iVar7 = iVar7 + 1;
      iVar2 = sk_num(st);
    } while (iVar7 < iVar2);
  }
  sk_pop_free(st,X509V3_conf_free);
  return local_20;
}

