
char * set_multi_opts(uint *param_1,char *param_2,char **param_3)

{
  char **ppcVar1;
  bool bVar2;
  _STACK *st;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  char *__s1;
  int iVar6;
  char *__s2;
  char *pcVar7;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  st = (_STACK *)X509V3_parse_list(param_2);
  iVar6 = 0;
  __s2 = (char *)0x1;
  iVar3 = sk_num(st);
  pcVar7 = __s2;
  if (0 < iVar3) {
    do {
      pvVar4 = sk_value(st,iVar6);
      __s1 = *(char **)((int)pvVar4 + 4);
      if (*__s1 == '-') {
        __s1 = __s1 + 1;
        bVar2 = false;
      }
      else {
        bVar2 = true;
        if (*__s1 == '+') {
          __s1 = __s1 + 1;
        }
      }
      __s2 = *param_3;
      ppcVar1 = param_3;
      while (__s2 != (char *)0x0) {
        iVar3 = strcasecmp(__s1,__s2);
        if (iVar3 == 0) {
          uVar5 = *param_1 & ~(uint)ppcVar1[2];
          *param_1 = uVar5;
          if (bVar2) {
            uVar5 = uVar5 | (uint)ppcVar1[1];
          }
          else {
            uVar5 = uVar5 & ~(uint)ppcVar1[1];
          }
          *param_1 = uVar5;
          __s2 = pcVar7;
          break;
        }
        ppcVar1 = ppcVar1 + 3;
        __s2 = *ppcVar1;
      }
      iVar6 = iVar6 + 1;
      iVar3 = sk_num(st);
      pcVar7 = __s2;
    } while (iVar6 < iVar3);
  }
  sk_pop_free(st,X509V3_conf_free + 1);
  return __s2;
}

