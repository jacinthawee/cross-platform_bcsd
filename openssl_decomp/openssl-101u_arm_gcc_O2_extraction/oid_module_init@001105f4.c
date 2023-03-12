
_STACK * oid_module_init(CONF_IMODULE *param_1,CONF *param_2)

{
  ushort uVar1;
  char *pcVar2;
  _STACK *p_Var3;
  int iVar4;
  void *pvVar5;
  byte *pbVar6;
  ushort **ppuVar7;
  char **__dest;
  ASN1_OBJECT *pAVar8;
  byte *pbVar9;
  ushort *puVar10;
  byte *pbVar11;
  int iVar12;
  
  pcVar2 = CONF_imodule_get_value(param_1);
  iVar12 = 0;
  p_Var3 = (_STACK *)NCONF_get_section(param_2,pcVar2);
  if (p_Var3 == (_STACK *)0x0) {
    ERR_put_error(0xd,0xae,0xac,"asn_moid.c",0x50);
  }
  else {
    while( true ) {
      iVar4 = sk_num(p_Var3);
      if (iVar4 <= iVar12) {
        return (_STACK *)0x1;
      }
      pvVar5 = sk_value(p_Var3,iVar12);
      pbVar11 = *(byte **)((int)pvVar5 + 8);
      pcVar2 = *(char **)((int)pvVar5 + 4);
      pbVar6 = (byte *)strrchr((char *)pbVar11,0x2c);
      if (pbVar6 != (byte *)0x0) break;
      iVar4 = OBJ_create((char *)pbVar11,pcVar2,pcVar2);
      if (iVar4 == 0) goto LAB_0011069c;
LAB_00110712:
      iVar12 = iVar12 + 1;
    }
    if (pbVar6[1] != 0) {
      ppuVar7 = __ctype_b_loc();
      pbVar9 = pbVar6;
      do {
        pbVar9 = pbVar9 + 1;
      } while (((*ppuVar7)[*pbVar9] & 0x2000) != 0);
      iVar4 = OBJ_create((char *)pbVar9,pcVar2,(char *)0x0);
      if (iVar4 != 0) {
        puVar10 = *ppuVar7;
        do {
          pbVar9 = pbVar11;
          pbVar11 = pbVar9 + 1;
        } while ((int)((uint)puVar10[*pbVar9] << 0x12) < 0);
        pbVar11 = pbVar6 + -1;
        uVar1 = puVar10[pbVar6[-1]];
        while ((int)((uint)uVar1 << 0x12) < 0) {
          if (pbVar9 == pbVar11) goto LAB_0011069c;
          pbVar11 = pbVar11 + -1;
          uVar1 = puVar10[*pbVar11];
        }
        pbVar11 = pbVar11 + (1 - (int)pbVar9);
        __dest = (char **)CRYPTO_malloc((int)(pbVar11 + 1),"asn_moid.c",0x8f);
        if (__dest != (char **)0x0) {
          memcpy(__dest,pbVar9,(size_t)pbVar11);
          *(byte *)((int)__dest + (int)pbVar11) = 0;
          pAVar8 = OBJ_nid2obj(iVar4);
          pAVar8->ln = __dest;
          goto LAB_00110712;
        }
      }
    }
LAB_0011069c:
    ERR_put_error(0xd,0xae,0xab,"asn_moid.c",0x56);
    p_Var3 = (_STACK *)0x0;
  }
  return p_Var3;
}

