
undefined4 x509_name_canon(_STACK **param_1)

{
  byte bVar1;
  int *piVar2;
  _STACK *p_Var3;
  int iVar4;
  _STACK *st;
  int iVar5;
  ASN1_OBJECT **ppAVar6;
  ASN1_OBJECT **val;
  ASN1_OBJECT *pAVar7;
  ulong uVar8;
  byte *pbVar9;
  ushort **ppuVar10;
  __int32_t **pp_Var11;
  _STACK *p_Var12;
  _STACK *num;
  byte *pbVar13;
  byte *pbVar14;
  ASN1_OBJECT *in;
  undefined4 uVar15;
  uint uVar16;
  ASN1_OBJECT *dst;
  byte *pbVar17;
  _STACK *local_3c;
  ASN1_OBJECT *local_38;
  _STACK *local_30;
  ASN1_VALUE *local_2c [2];
  
  if (param_1[3] != (_STACK *)0x0) {
    CRYPTO_free(param_1[3]);
    param_1[3] = (_STACK *)0x0;
  }
  iVar4 = sk_num(*param_1);
  if (iVar4 == 0) {
    param_1[4] = (_STACK *)0x0;
    return 1;
  }
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
LAB_000b4fb0:
    uVar15 = 0;
  }
  else {
    local_38 = (ASN1_OBJECT *)0xffffffff;
    local_3c = (_STACK *)0x0;
    for (iVar4 = 0; iVar5 = sk_num(*param_1), iVar4 < iVar5; iVar4 = iVar4 + 1) {
      ppAVar6 = (ASN1_OBJECT **)sk_value(*param_1,iVar4);
      if (ppAVar6[2] != local_38) {
        local_3c = sk_new_null();
        if ((local_3c == (_STACK *)0x0) || (iVar5 = sk_push(st,local_3c), iVar5 == 0))
        goto LAB_000b4fac;
        local_38 = ppAVar6[2];
      }
      val = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)&X509_NAME_ENTRY_it);
      if (val == (ASN1_OBJECT **)0x0) goto LAB_000b4fac;
      pAVar7 = OBJ_dup(*ppAVar6);
      in = ppAVar6[1];
      dst = val[1];
      *val = pAVar7;
      uVar8 = ASN1_tag2bit((int)in->ln);
      if ((uVar8 & 0x2956) != 0) {
        dst->ln = (char **)&DAT_0000000c;
        pbVar9 = (byte *)ASN1_STRING_to_UTF8((uchar **)&dst->nid,(ASN1_STRING *)in);
        dst->sn = (char *)pbVar9;
        if (pbVar9 != (byte *)0xffffffff) {
          pbVar17 = (byte *)dst->nid;
          if ((int)pbVar9 < 1) {
            pbVar9 = (byte *)0x0;
          }
          else {
            uVar16 = (uint)*pbVar17;
            pbVar14 = pbVar17;
            if (-1 < (int)(uVar16 << 0x18)) {
              ppuVar10 = __ctype_b_loc();
              do {
                pbVar13 = pbVar14 + 1;
                if (((*ppuVar10)[uVar16] & 0x2000) == 0) {
                  pbVar13 = pbVar14 + (int)(pbVar9 + -1);
                  goto LAB_000b4eb2;
                }
                pbVar9 = pbVar9 + -1;
                if (pbVar9 == (byte *)0x0) goto LAB_000b4e46;
                uVar16 = (uint)pbVar14[1];
                pbVar14 = pbVar13;
              } while (-1 < (int)(uVar16 << 0x18));
            }
            pbVar13 = pbVar14 + (int)(pbVar9 + -1);
LAB_000b4eb2:
            uVar16 = (uint)*pbVar13;
            if (-1 < (int)(uVar16 << 0x18)) {
              ppuVar10 = __ctype_b_loc();
              do {
                if (-1 < (int)((uint)(*ppuVar10)[uVar16] << 0x12)) break;
                pbVar9 = pbVar9 + -1;
                if (pbVar9 == (byte *)0x0) goto LAB_000b4e46;
                pbVar13 = pbVar13 + -1;
                uVar16 = (uint)*pbVar13;
              } while (-1 < (int)(uVar16 << 0x18));
            }
            iVar5 = 0;
            pbVar17 = pbVar17 + 1;
            do {
              while (pbVar13 = pbVar17, bVar1 = *pbVar14, (bVar1 & 0x80) != 0) {
                pbVar14 = pbVar14 + 1;
                iVar5 = iVar5 + 1;
                pbVar13[-1] = bVar1;
joined_r0x000b4f26:
                pbVar17 = pbVar13 + 1;
                if ((int)pbVar9 <= iVar5) goto LAB_000b4e40;
              }
              ppuVar10 = __ctype_b_loc();
              if ((int)((uint)(*ppuVar10)[(short)(ushort)bVar1] << 0x12) < 0) {
                pbVar13[-1] = 0x20;
                do {
                  pbVar14 = pbVar14 + 1;
                  iVar5 = iVar5 + 1;
                  if ((int)((uint)*pbVar14 << 0x18) < 0) break;
                } while ((int)((uint)(*ppuVar10)[*pbVar14] << 0x12) < 0);
                goto joined_r0x000b4f26;
              }
              pp_Var11 = __ctype_tolower_loc();
              iVar5 = iVar5 + 1;
              pbVar14 = pbVar14 + 1;
              pbVar13[-1] = (byte)(*pp_Var11)[(short)(ushort)bVar1];
              pbVar17 = pbVar13 + 1;
            } while (iVar5 < (int)pbVar9);
LAB_000b4e40:
            pbVar9 = pbVar13 + -dst->nid;
          }
LAB_000b4e46:
          dst->sn = (char *)pbVar9;
          goto LAB_000b4e48;
        }
LAB_000b4e08:
        uVar15 = 0;
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&X509_NAME_ENTRY_it);
        goto LAB_000b4e18;
      }
      iVar5 = ASN1_STRING_copy((ASN1_STRING *)dst,(ASN1_STRING *)in);
      if (iVar5 == 0) goto LAB_000b4e08;
LAB_000b4e48:
      iVar5 = sk_push(local_3c,val);
      if (iVar5 == 0) goto LAB_000b4e08;
    }
    iVar4 = 0;
    p_Var3 = (_STACK *)0x0;
    do {
      num = p_Var3;
      iVar5 = sk_num(st);
      if (iVar5 <= iVar4) break;
      local_2c[0] = (ASN1_VALUE *)sk_value(st,iVar4);
      p_Var12 = (_STACK *)
                ASN1_item_ex_i2d(local_2c,(uchar **)0x0,
                                 (ASN1_ITEM *)PTR_X509_NAME_ENTRIES_it_000b4ffc,-1,-1);
      piVar2 = &num->num;
      num = p_Var12;
      iVar4 = iVar4 + 1;
      p_Var3 = (_STACK *)((int)&p_Var12->num + (int)piVar2);
    } while (-1 < (int)p_Var12);
    param_1[4] = num;
    local_30 = (_STACK *)CRYPTO_malloc((int)num,"x_name.c",0x188);
    if (local_30 == (_STACK *)0x0) {
LAB_000b4fac:
      if (st == (_STACK *)0x0) goto LAB_000b4fb0;
      uVar15 = 0;
    }
    else {
      param_1[3] = local_30;
      iVar4 = 0;
      do {
        iVar5 = sk_num(st);
        if (iVar5 <= iVar4) break;
        local_2c[0] = (ASN1_VALUE *)sk_value(st,iVar4);
        iVar5 = ASN1_item_ex_i2d(local_2c,(uchar **)&local_30,
                                 (ASN1_ITEM *)PTR_X509_NAME_ENTRIES_it_000b4ffc,-1,-1);
        iVar4 = iVar4 + 1;
      } while (-1 < iVar5);
      uVar15 = 1;
    }
LAB_000b4e18:
    sk_pop_free(st,local_sk_X509_NAME_ENTRY_pop_free + 1);
  }
  return uVar15;
}

