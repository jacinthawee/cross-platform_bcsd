
undefined4 oid_module_init(CONF_IMODULE *param_1,CONF *param_2)

{
  byte bVar1;
  ushort *puVar2;
  char *pcVar3;
  _STACK *p_Var4;
  int iVar5;
  void *pvVar6;
  byte *pbVar7;
  ushort **ppuVar8;
  char **__dest;
  ASN1_OBJECT *pAVar9;
  byte *pbVar10;
  byte *__s;
  int iVar11;
  
  pcVar3 = CONF_imodule_get_value(param_1);
  p_Var4 = (_STACK *)NCONF_get_section(param_2,pcVar3);
  if (p_Var4 == (_STACK *)0x0) {
    iVar5 = 0x50;
    iVar11 = 0xac;
  }
  else {
    iVar11 = 0;
    while( true ) {
      iVar5 = sk_num(p_Var4);
      if (iVar5 <= iVar11) {
        return 1;
      }
      pvVar6 = sk_value(p_Var4,iVar11);
      pcVar3 = *(char **)((int)pvVar6 + 4);
      __s = *(byte **)((int)pvVar6 + 8);
      pbVar7 = (byte *)strrchr((char *)__s,0x2c);
      if (pbVar7 != (byte *)0x0) break;
      iVar5 = OBJ_create((char *)__s,pcVar3,pcVar3);
      if (iVar5 == 0) goto LAB_081d1131;
LAB_081d11aa:
      iVar11 = iVar11 + 1;
    }
    if (pbVar7[1] != 0) {
      ppuVar8 = __ctype_b_loc();
      pbVar10 = pbVar7;
      do {
        pbVar10 = pbVar10 + 1;
      } while ((*(byte *)((int)*ppuVar8 + (uint)*pbVar10 * 2 + 1) & 0x20) != 0);
      iVar5 = OBJ_create((char *)pbVar10,pcVar3,(char *)0x0);
      if (iVar5 != 0) {
        puVar2 = *ppuVar8;
        while ((*(byte *)((int)puVar2 + (uint)*__s * 2 + 1) & 0x20) != 0) {
          __s = __s + 1;
        }
        pbVar10 = pbVar7 + -1;
        bVar1 = *(byte *)((int)puVar2 + (uint)pbVar7[-1] * 2 + 1);
        while ((bVar1 & 0x20) != 0) {
          if (__s == pbVar10) goto LAB_081d1131;
          pbVar10 = pbVar10 + -1;
          bVar1 = *(byte *)((int)puVar2 + (uint)*pbVar10 * 2 + 1);
        }
        pbVar10 = pbVar10 + (1 - (int)__s);
        __dest = (char **)CRYPTO_malloc((int)(pbVar10 + 1),"asn_moid.c",0x8f);
        if (__dest != (char **)0x0) {
          memcpy(__dest,__s,(size_t)pbVar10);
          *(byte *)((int)__dest + (int)pbVar10) = 0;
          pAVar9 = OBJ_nid2obj(iVar5);
          pAVar9->ln = __dest;
          goto LAB_081d11aa;
        }
      }
    }
LAB_081d1131:
    iVar5 = 0x56;
    iVar11 = 0xab;
  }
  ERR_put_error(0xd,0xae,iVar11,"asn_moid.c",iVar5);
  return 0;
}

