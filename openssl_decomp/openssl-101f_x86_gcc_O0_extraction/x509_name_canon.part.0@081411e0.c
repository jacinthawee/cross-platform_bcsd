
undefined4 __regparm3 x509_name_canon_part_0(_STACK **param_1)

{
  byte bVar1;
  ASN1_OBJECT *in;
  byte *pbVar2;
  _STACK *st;
  int iVar3;
  ASN1_OBJECT **ppAVar4;
  ASN1_OBJECT **val;
  ASN1_OBJECT *pAVar5;
  ulong uVar6;
  char *pcVar7;
  ushort **ppuVar8;
  __int32_t **pp_Var9;
  _STACK *num;
  int iVar10;
  byte *pbVar11;
  undefined4 uVar12;
  _STACK *p_Var13;
  char *pcVar14;
  byte *pbVar15;
  byte *pbVar16;
  int in_GS_OFFSET;
  int local_48;
  ASN1_OBJECT *local_38;
  _STACK *local_34;
  _STACK *local_28;
  ASN1_VALUE *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    uVar12 = 0;
  }
  else {
    local_38 = (ASN1_OBJECT *)0xffffffff;
    local_34 = (_STACK *)0x0;
    for (local_48 = 0; iVar3 = sk_num(*param_1), local_48 < iVar3; local_48 = local_48 + 1) {
      ppAVar4 = (ASN1_OBJECT **)sk_value(*param_1,local_48);
      if (ppAVar4[2] != local_38) {
        local_34 = sk_new_null();
        if ((local_34 == (_STACK *)0x0) || (iVar3 = sk_push(st,local_34), iVar3 == 0))
        goto LAB_081412ec;
        local_38 = ppAVar4[2];
      }
      val = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)X509_NAME_ENTRY_it);
      pAVar5 = OBJ_dup(*ppAVar4);
      *val = pAVar5;
      pAVar5 = val[1];
      in = ppAVar4[1];
      uVar6 = ASN1_tag2bit((int)in->ln);
      if ((uVar6 & 0x2956) != 0) {
        pAVar5->ln = (char **)&DAT_0000000c;
        pcVar7 = (char *)ASN1_STRING_to_UTF8((uchar **)&pAVar5->nid,(ASN1_STRING *)in);
        pAVar5->sn = pcVar7;
        if (pcVar7 != (char *)0xffffffff) {
          pbVar2 = (byte *)pAVar5->nid;
          if ((int)pcVar7 < 1) {
LAB_08141320:
            pAVar5->sn = (char *)0x0;
          }
          else {
            bVar1 = *pbVar2;
            pbVar11 = pbVar2;
            if (-1 < (char)bVar1) {
              ppuVar8 = __ctype_b_loc();
              do {
                if ((*(byte *)((int)*ppuVar8 + (uint)bVar1 * 2 + 1) & 0x20) == 0) break;
                pbVar11 = pbVar11 + 1;
                pcVar7 = pcVar7 + -1;
                if (pcVar7 == (char *)0x0) goto LAB_08141320;
                bVar1 = *pbVar11;
              } while (-1 < (char)bVar1);
            }
            bVar1 = pbVar11[(int)(pcVar7 + -1)];
            pcVar14 = pcVar7;
            if (-1 < (char)bVar1) {
              ppuVar8 = __ctype_b_loc();
              do {
                if ((*(byte *)((int)*ppuVar8 + (uint)bVar1 * 2 + 1) & 0x20) == 0) break;
                pcVar14 = pcVar14 + -1;
                if (pcVar14 == (char *)0x0) goto LAB_08141320;
                bVar1 = (pbVar11 + (int)(pcVar7 + -1))[(int)pcVar14 - (int)pcVar7];
              } while (-1 < (char)bVar1);
            }
            pbVar16 = (byte *)0x0;
            do {
              pbVar15 = pbVar2 + 1;
              bVar1 = *pbVar11;
              if ((char)bVar1 < '\0') {
                pbVar11 = pbVar11 + 1;
                *pbVar2 = bVar1;
                pbVar16 = pbVar16 + 1;
              }
              else {
                ppuVar8 = __ctype_b_loc();
                if ((*(byte *)((int)*ppuVar8 + (uint)bVar1 * 2 + 1) & 0x20) == 0) {
                  pp_Var9 = __ctype_tolower_loc();
                  pbVar11 = pbVar11 + 1;
                  pbVar16 = pbVar16 + 1;
                  *pbVar2 = (byte)(*pp_Var9)[bVar1];
                }
                else {
                  *pbVar2 = 0x20;
                  iVar3 = (int)pbVar16 - (int)pbVar11;
                  do {
                    pbVar11 = pbVar11 + 1;
                    pbVar16 = pbVar11 + iVar3;
                    if ((char)*pbVar11 < '\0') break;
                  } while ((*(byte *)((int)*ppuVar8 + (uint)*pbVar11 * 2 + 1) & 0x20) != 0);
                }
              }
              pbVar2 = pbVar15;
            } while ((int)pbVar16 < (int)pcVar14);
            pAVar5->sn = (char *)(pbVar15 + -(int)pAVar5->nid);
          }
          goto LAB_08141328;
        }
LAB_081412d8:
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_NAME_ENTRY_it);
        goto LAB_081412ec;
      }
      iVar3 = ASN1_STRING_copy((ASN1_STRING *)pAVar5,(ASN1_STRING *)in);
      if (iVar3 == 0) goto LAB_081412d8;
LAB_08141328:
      iVar3 = sk_push(local_34,val);
      if (iVar3 == 0) goto LAB_081412d8;
    }
    p_Var13 = (_STACK *)0x0;
    for (iVar3 = 0; iVar10 = sk_num(st), num = p_Var13, iVar3 < iVar10; iVar3 = iVar3 + 1) {
      local_24 = (ASN1_VALUE *)sk_value(st,iVar3);
      num = (_STACK *)
            ASN1_item_ex_i2d(&local_24,(uchar **)0x0,(ASN1_ITEM *)X509_NAME_ENTRIES_it,-1,-1);
      if ((int)num < 0) break;
      p_Var13 = (_STACK *)((int)&num->num + (int)&p_Var13->num);
    }
    param_1[4] = num;
    local_28 = (_STACK *)CRYPTO_malloc((int)num,"x_name.c",0x16d);
    if (local_28 == (_STACK *)0x0) {
LAB_081412ec:
      uVar12 = 0;
    }
    else {
      param_1[3] = local_28;
      for (iVar3 = 0; iVar10 = sk_num(st), iVar3 < iVar10; iVar3 = iVar3 + 1) {
        local_24 = (ASN1_VALUE *)sk_value(st,iVar3);
        iVar10 = ASN1_item_ex_i2d(&local_24,(uchar **)&local_28,(ASN1_ITEM *)X509_NAME_ENTRIES_it,-1
                                  ,-1);
        if (iVar10 < 0) break;
      }
      uVar12 = 1;
    }
    sk_pop_free(st,local_sk_X509_NAME_ENTRY_pop_free);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12;
}

