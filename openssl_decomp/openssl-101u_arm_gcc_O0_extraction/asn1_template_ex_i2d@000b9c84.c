
/* WARNING: Type propagation algorithm not settling */

_STACK * asn1_template_ex_i2d
                   (_STACK **param_1,uchar **param_2,uint *param_3,uint param_4,uint param_5)

{
  uchar **ppuVar1;
  int iVar2;
  uchar *puVar3;
  _STACK *length;
  uchar *puVar4;
  ASN1_VALUE **ppAVar5;
  ASN1_TEMPLATE *tt;
  _STACK *p_Var6;
  uchar **ptr;
  size_t __nmemb;
  uint aclass;
  code *pcVar7;
  int iVar8;
  int iVar9;
  uchar **ppuVar10;
  uchar *puVar11;
  _STACK *p_Var12;
  code *pcVar13;
  ASN1_TEMPLATE *pAVar14;
  uint uVar15;
  ASN1_ITEM *pAVar16;
  uint local_68;
  int local_5c;
  uint local_58;
  int local_54;
  uint local_4c;
  uint local_48;
  uint local_40;
  ASN1_VALUE *local_34;
  ASN1_VALUE *local_30;
  uchar *local_2c [2];
  
  uVar15 = *param_3;
  local_58 = uVar15 & 0x18;
  if (local_58 == 0) {
    local_68 = param_4;
    if (param_4 != 0xffffffff) {
      local_58 = param_5 & 0xc0;
    }
  }
  else {
    if (param_4 != 0xffffffff) {
      return (_STACK *)0xffffffff;
    }
    local_68 = param_3[1];
    local_58 = uVar15 & 0xc0;
  }
  aclass = param_5 & 0xffffff3f;
  if ((uVar15 & 0x800) == 0) {
    local_5c = 1;
  }
  else if ((param_5 & 0x800) == 0) {
    local_5c = 1;
  }
  else {
    local_5c = 2;
  }
  if ((_STACK *)(uVar15 & 6) == (_STACK *)0x0) {
    if ((uVar15 & 0x10) == 0) {
      p_Var6 = (_STACK *)
               ASN1_item_ex_i2d((ASN1_VALUE **)param_1,param_2,(ASN1_ITEM *)param_3[4],local_68,
                                local_58 | aclass);
      return p_Var6;
    }
    iVar2 = ASN1_item_ex_i2d((ASN1_VALUE **)param_1,(uchar **)0x0,(ASN1_ITEM *)param_3[4],-1,aclass)
    ;
    if (iVar2 == 0) {
      return (_STACK *)0;
    }
    p_Var6 = (_STACK *)ASN1_object_size(local_5c,iVar2,local_68);
    if (p_Var6 == (_STACK *)0xffffffff || param_2 == (uchar **)0x0) {
      return p_Var6;
    }
    ASN1_put_object(param_2,local_5c,iVar2,local_68,local_58);
    ASN1_item_ex_i2d((ASN1_VALUE **)param_1,param_2,(ASN1_ITEM *)param_3[4],-1,aclass);
    if (local_5c != 2) {
      return p_Var6;
    }
  }
  else {
    p_Var12 = *param_1;
    if (p_Var12 == (_STACK *)0x0) {
      return (_STACK *)0;
    }
    local_4c = uVar15 & 2;
    if (local_4c != 0) {
      if ((uVar15 & 4) == 0) {
        local_4c = 1;
      }
      else {
        local_4c = 2;
      }
    }
    if ((local_68 == 0xffffffff) || ((uVar15 & 0x10) != 0)) {
      local_40 = 0;
      if (local_4c == 0) {
        local_48 = 0x10;
      }
      else {
        local_48 = 0x11;
      }
    }
    else {
      local_40 = local_58;
      local_48 = local_68;
    }
    puVar11 = (uchar *)0x0;
    iVar2 = sk_num(p_Var12);
    iVar9 = 0;
    if (0 < iVar2) {
      do {
        local_34 = (ASN1_VALUE *)sk_value(p_Var12,iVar9);
        pAVar16 = (ASN1_ITEM *)param_3[4];
        pcVar7 = (code *)pAVar16->funcs;
        if ((pAVar16->itype != 0) && (local_34 == (ASN1_VALUE *)0x0)) goto switchD_000b9d64_caseD_7;
        pcVar13 = pcVar7;
        if (pcVar7 != (code *)0x0) {
          pcVar13 = *(code **)(pcVar7 + 0x10);
        }
        switch(pAVar16->itype) {
        case '\0':
          if (pAVar16->templates == (ASN1_TEMPLATE *)0x0) {
            puVar4 = (uchar *)asn1_i2d_ex_primitive(&local_34,0,pAVar16,0xffffffff,aclass);
          }
          else {
            puVar4 = (uchar *)asn1_template_ex_i2d(&local_34,0,pAVar16->templates,0xffffffff,aclass)
            ;
          }
          break;
        case '\x01':
          local_54 = 1;
          goto LAB_000b9da0;
        case '\x02':
          if ((pcVar13 == (code *)0x0) || (iVar2 = (*pcVar13)(6,&local_34,pAVar16,0), iVar2 != 0)) {
            iVar2 = asn1_get_choice_selector(&local_34,pAVar16);
            if ((-1 < iVar2) && (iVar2 < pAVar16->tcount)) {
              pAVar14 = pAVar16->templates;
              ppAVar5 = asn1_get_field_ptr(&local_34,pAVar14 + iVar2);
              puVar4 = (uchar *)asn1_template_ex_i2d(ppAVar5,0,pAVar14 + iVar2,0xffffffff,aclass);
              break;
            }
            if (pcVar13 != (code *)0x0) {
              (*pcVar13)(7,&local_34,pAVar16,0);
            }
          }
        default:
switchD_000b9d64_caseD_7:
          puVar4 = (uchar *)0x0;
          goto LAB_000b9dce;
        case '\x03':
          puVar4 = (uchar *)(**(code **)(pcVar7 + 0xc))(local_34,0);
          break;
        case '\x04':
          puVar4 = (uchar *)(**(code **)(pcVar7 + 0x14))(&local_34,0,pAVar16,0xffffffff,aclass);
          break;
        case '\x05':
          puVar4 = (uchar *)asn1_i2d_ex_primitive(&local_34,0,pAVar16,0xffffffff,aclass);
          break;
        case '\x06':
          if ((param_5 & 0x800) == 0) {
            local_54 = 1;
          }
          else {
            local_54 = 2;
          }
LAB_000b9da0:
          puVar3 = (uchar *)asn1_enc_restore((int *)local_2c,(uchar **)0x0,&local_34,pAVar16);
          if ((int)puVar3 < 0) goto switchD_000b9d64_caseD_7;
          puVar4 = local_2c[0];
          if (puVar3 == (uchar *)0x0) {
            local_2c[0] = puVar3;
            if ((pcVar13 != (code *)0x0) && (iVar2 = (*pcVar13)(6,&local_34,pAVar16,0), iVar2 == 0))
            goto switchD_000b9d64_caseD_7;
            pAVar14 = pAVar16->templates;
            if (0 < pAVar16->tcount) {
              do {
                puVar3 = puVar3 + 1;
                tt = asn1_do_adb(&local_34,pAVar14,1);
                pAVar14 = pAVar14 + 1;
                if (tt == (ASN1_TEMPLATE *)0x0) goto switchD_000b9d64_caseD_7;
                ppAVar5 = asn1_get_field_ptr(&local_34,tt);
                iVar2 = asn1_template_ex_i2d(ppAVar5,0,tt,0xffffffff,aclass);
                if (iVar2 == -1) {
                  return (_STACK *)0xffffffff;
                }
                iVar8 = 0x7fffffff - (int)local_2c[0];
                local_2c[0] = local_2c[0] + iVar2;
                if (iVar8 < iVar2) {
                  return (_STACK *)0xffffffff;
                }
              } while ((int)puVar3 < pAVar16->tcount);
            }
            puVar4 = (uchar *)ASN1_object_size(local_54,(int)local_2c[0],0x10);
          }
        }
        if (puVar4 == (uchar *)0xffffffff) {
          return (_STACK *)0xffffffff;
        }
        if (0x7fffffff - (int)puVar4 < (int)puVar11) {
          return (_STACK *)0xffffffff;
        }
LAB_000b9dce:
        puVar11 = puVar11 + (int)puVar4;
        iVar2 = sk_num(p_Var12);
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar2);
    }
    length = (_STACK *)ASN1_object_size(local_5c,(int)puVar11,local_48);
    if (length == (_STACK *)0xffffffff) {
      return (_STACK *)0xffffffff;
    }
    if ((uVar15 & 0x10) == 0) {
      p_Var6 = length;
      if (param_2 == (uchar **)0x0) {
        return length;
      }
    }
    else {
      p_Var6 = (_STACK *)ASN1_object_size(local_5c,(int)length,local_68);
      if (param_2 == (uchar **)0x0 || p_Var6 == (_STACK *)0xffffffff) {
        return p_Var6;
      }
      ASN1_put_object(param_2,local_5c,(int)length,local_68,local_58);
    }
    iVar2 = 0;
    ASN1_put_object(param_2,local_5c,(int)puVar11,local_48,local_40);
    pAVar16 = (ASN1_ITEM *)param_3[4];
    local_2c[0] = (uchar *)0x0;
    if ((local_4c == 0) || (iVar9 = sk_num(p_Var12), iVar9 < 2)) {
      iVar2 = 0;
      while( true ) {
        iVar9 = sk_num(p_Var12);
        if (iVar9 <= iVar2) break;
        local_30 = (ASN1_VALUE *)sk_value(p_Var12,iVar2);
        ASN1_item_ex_i2d(&local_30,param_2,pAVar16,-1,aclass);
        iVar2 = iVar2 + 1;
      }
    }
    else {
      iVar9 = sk_num(p_Var12);
      ptr = (uchar **)CRYPTO_malloc(iVar9 * 0xc,"tasn_enc.c",0x1ba);
      if (ptr != (uchar **)0x0) {
        puVar4 = (uchar *)CRYPTO_malloc((int)puVar11,"tasn_enc.c",0x1bd);
        ppuVar10 = ptr;
        puVar11 = puVar4;
        if (puVar4 == (uchar *)0x0) {
          CRYPTO_free(ptr);
        }
        else {
          while( true ) {
            local_2c[0] = puVar11;
            iVar9 = sk_num(p_Var12);
            if (iVar9 <= iVar2) break;
            local_30 = (ASN1_VALUE *)sk_value(p_Var12,iVar2);
            *ppuVar10 = local_2c[0];
            puVar11 = (uchar *)ASN1_item_ex_i2d(&local_30,local_2c,pAVar16,-1,aclass);
            ppuVar10[2] = (uchar *)local_30;
            ppuVar10[1] = puVar11;
            ppuVar10 = ppuVar10 + 3;
            iVar2 = iVar2 + 1;
            puVar11 = local_2c[0];
          }
          __nmemb = sk_num(p_Var12);
          qsort(ptr,__nmemb,0xc,der_cmp + 1);
          local_2c[0] = *param_2;
          iVar2 = 0;
          ppuVar10 = ptr;
          while( true ) {
            iVar9 = sk_num(p_Var12);
            if (iVar9 <= iVar2) break;
            memcpy(local_2c[0],*ppuVar10,(size_t)ppuVar10[1]);
            local_2c[0] = ppuVar10[1] + (int)local_2c[0];
            iVar2 = iVar2 + 1;
            ppuVar10 = ppuVar10 + 3;
          }
          *param_2 = local_2c[0];
          if (local_4c == 2) {
            ppuVar10 = ptr;
            iVar2 = 0;
            while( true ) {
              iVar9 = sk_num(p_Var12);
              if (iVar9 <= iVar2) break;
              ppuVar1 = ppuVar10 + 2;
              ppuVar10 = ppuVar10 + 3;
              sk_set(p_Var12,iVar2,*ppuVar1);
              iVar2 = iVar2 + 1;
            }
          }
          CRYPTO_free(ptr);
          CRYPTO_free(puVar4);
        }
      }
    }
    if (local_5c != 2) {
      return p_Var6;
    }
    ASN1_put_eoc(param_2);
    if ((uVar15 & 0x10) == 0) {
      return p_Var6;
    }
  }
  ASN1_put_eoc(param_2);
  return p_Var6;
}

