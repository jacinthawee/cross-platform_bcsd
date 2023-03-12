
/* WARNING: Type propagation algorithm not settling */

uint __regparm3
asn1_template_ex_i2d
          (_STACK **param_1_00,ASN1_VALUE **param_2_00,uint *param_3,uint param_1,uint param_2)

{
  ASN1_VALUE **ppAVar1;
  byte bVar2;
  _STACK *p_Var3;
  ASN1_ITEM *pAVar4;
  void *pvVar5;
  _STACK *p_Var6;
  int iVar7;
  uint uVar8;
  int iVar9;
  ASN1_TEMPLATE *tt;
  _STACK **pval;
  int iVar10;
  ASN1_VALUE **__base;
  ASN1_VALUE *pAVar11;
  ASN1_VALUE *pAVar12;
  size_t __nmemb;
  code *pcVar13;
  uint length;
  ASN1_VALUE **ppAVar14;
  uint aclass;
  int in_GS_OFFSET;
  bool bVar15;
  int local_7c;
  uint local_74;
  ASN1_VALUE *local_6c;
  long local_68;
  int local_64;
  ASN1_TEMPLATE *local_60;
  int local_58;
  int local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  ASN1_VALUE *local_2c;
  ASN1_VALUE *local_28;
  ASN1_VALUE *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_34 = *param_3;
  if ((local_34 & 0x18) == 0) {
    local_44 = local_34 & 0x18;
    if (param_1 != 0xffffffff) {
      local_44 = param_2 & 0xc0;
    }
  }
  else {
    if (param_1 != 0xffffffff) {
      local_74 = 0xffffffff;
      goto LAB_08149c60;
    }
    param_1 = param_3[1];
    local_44 = local_34 & 0xc0;
  }
  local_58 = 1;
  aclass = param_2 & 0xffffff3f;
  if ((local_34 & 0x800) != 0) {
    local_58 = 2 - (uint)((param_2 & 0x800) == 0);
  }
  if ((local_34 & 6) == 0) {
    if ((local_34 & 0x10) == 0) {
      local_74 = ASN1_item_ex_i2d((ASN1_VALUE **)param_1_00,(uchar **)param_2_00,
                                  (ASN1_ITEM *)param_3[4],param_1,local_44 | aclass);
      goto LAB_08149c60;
    }
    iVar7 = ASN1_item_ex_i2d((ASN1_VALUE **)param_1_00,(uchar **)0x0,(ASN1_ITEM *)param_3[4],-1,
                             aclass);
    local_74 = local_34 & 6;
    if ((iVar7 == 0) ||
       (local_74 = ASN1_object_size(local_58,iVar7,param_1), param_2_00 == (ASN1_VALUE **)0x0))
    goto LAB_08149c60;
    ASN1_put_object((uchar **)param_2_00,local_58,iVar7,param_1,local_44);
    ASN1_item_ex_i2d((ASN1_VALUE **)param_1_00,(uchar **)param_2_00,(ASN1_ITEM *)param_3[4],-1,
                     aclass);
    if (local_58 != 2) goto LAB_08149c60;
  }
  else {
    p_Var3 = *param_1_00;
    if (p_Var3 == (_STACK *)0x0) {
      local_74 = 0;
      goto LAB_08149c60;
    }
    if ((local_34 & 2) == 0) {
      if (param_1 == 0xffffffff) {
        local_38 = 0;
        local_30 = 0;
        local_40 = 0x10;
      }
      else {
        local_30 = 0;
        local_38 = 0;
        local_40 = 0x10;
        if ((local_34 & 0x10) == 0) {
          local_40 = param_1;
          local_30 = local_44;
        }
      }
    }
    else {
      local_38 = 2 - (uint)((local_34 & 4) == 0);
      if (param_1 == 0xffffffff) {
        local_30 = 0;
        local_40 = 0x11;
      }
      else {
        bVar15 = (local_34 & 0x10) == 0;
        local_30 = 0;
        if (bVar15) {
          local_30 = local_44;
        }
        local_40 = 0x11;
        if (bVar15) {
          local_40 = param_1;
        }
      }
    }
    local_34 = local_34 & 0x10;
    local_6c = (ASN1_VALUE *)0x0;
    for (local_7c = 0; iVar7 = sk_num(p_Var3), local_7c < iVar7; local_7c = local_7c + 1) {
      local_2c = (ASN1_VALUE *)sk_value(p_Var3,local_7c);
      pAVar4 = (ASN1_ITEM *)param_3[4];
      pvVar5 = pAVar4->funcs;
      bVar2 = pAVar4->itype;
      if ((local_2c == (ASN1_VALUE *)0x0) && (bVar2 != 0)) goto switchD_08149ef5_caseD_7;
      if ((pvVar5 == (void *)0x0) ||
         (pcVar13 = *(code **)((int)pvVar5 + 0x10), pcVar13 == (code *)0x0)) {
        switch(bVar2) {
        case 0:
          goto switchD_08149ef5_caseD_0;
        case 1:
          pcVar13 = (code *)0x0;
          goto switchD_08149d65_caseD_1;
        case 2:
          iVar7 = asn1_get_choice_selector(&local_2c,pAVar4);
          if ((-1 < iVar7) && (iVar7 < pAVar4->tcount)) {
LAB_08149da9:
            asn1_get_field_ptr(&local_2c,pAVar4->templates + iVar7);
            pAVar11 = (ASN1_VALUE *)asn1_template_ex_i2d(0xffffffff,aclass);
            goto LAB_08149e00;
          }
          break;
        case 3:
          goto switchD_08149ef5_caseD_3;
        case 4:
          goto switchD_08149ef5_caseD_4;
        case 5:
          goto switchD_08149ef5_caseD_5;
        case 6:
          pcVar13 = (code *)0x0;
          goto switchD_08149d65_caseD_6;
        }
        goto switchD_08149ef5_caseD_7;
      }
      switch(bVar2) {
      case 0:
switchD_08149ef5_caseD_0:
        if (pAVar4->templates == (ASN1_TEMPLATE *)0x0) goto switchD_08149ef5_caseD_5;
        pAVar11 = (ASN1_VALUE *)asn1_template_ex_i2d(0xffffffff,aclass);
        break;
      case 1:
switchD_08149d65_caseD_1:
        local_3c = 1;
        goto LAB_08149e1a;
      case 2:
        iVar7 = (*pcVar13)(6,&local_2c,pAVar4,0);
        if (iVar7 == 0) goto switchD_08149ef5_caseD_7;
        iVar7 = asn1_get_choice_selector(&local_2c,pAVar4);
        if ((-1 < iVar7) && (iVar7 < pAVar4->tcount)) goto LAB_08149da9;
        (*pcVar13)(7,&local_2c,pAVar4,0);
        pAVar11 = (ASN1_VALUE *)0x0;
        break;
      case 3:
switchD_08149ef5_caseD_3:
        pAVar11 = (ASN1_VALUE *)(**(code **)((int)pvVar5 + 0xc))(local_2c,0);
        break;
      case 4:
switchD_08149ef5_caseD_4:
        pAVar11 = (ASN1_VALUE *)
                  (**(code **)((int)pvVar5 + 0x14))(&local_2c,0,pAVar4,0xffffffff,aclass);
        break;
      case 5:
switchD_08149ef5_caseD_5:
        pAVar11 = (ASN1_VALUE *)asn1_i2d_ex_primitive(0xffffffff,aclass);
        break;
      case 6:
switchD_08149d65_caseD_6:
        local_3c = 2 - (uint)((param_2 & 0x800) == 0);
LAB_08149e1a:
        local_74 = asn1_enc_restore((int *)&local_28,(uchar **)0x0,&local_2c,pAVar4);
        if ((int)local_74 < 0) {
switchD_08149ef5_caseD_7:
          pAVar11 = (ASN1_VALUE *)0x0;
        }
        else {
          pAVar11 = local_28;
          if (local_74 == 0) {
            local_28 = (ASN1_VALUE *)0x0;
            if ((pcVar13 != (code *)0x0) && (iVar7 = (*pcVar13)(6,&local_2c,pAVar4,0), iVar7 == 0))
            goto switchD_08149ef5_caseD_7;
            local_60 = pAVar4->templates;
            if (0 < pAVar4->tcount) {
              do {
                tt = asn1_do_adb(&local_2c,local_60,1);
                if (tt == (ASN1_TEMPLATE *)0x0) goto switchD_08149ef5_caseD_7;
                pval = (_STACK **)asn1_get_field_ptr(&local_2c,tt);
                local_48 = tt->flags;
                if ((local_48 & 0x18) == 0) {
                  uVar8 = 0;
                  local_68 = -1;
                }
                else {
                  local_68 = tt->tag;
                  uVar8 = local_48 & 0xc0;
                }
                local_64 = 1;
                if ((local_48 & 0x800) != 0) {
                  local_64 = 2 - (uint)((param_2 & 0x800) == 0);
                }
                length = local_48 & 6;
                if (length == 0) {
                  if ((local_48 & 0x10) == 0) {
                    length = ASN1_item_ex_i2d((ASN1_VALUE **)pval,(uchar **)0x0,tt->item,local_68,
                                              uVar8 | aclass);
                  }
                  else {
                    iVar7 = ASN1_item_ex_i2d((ASN1_VALUE **)pval,(uchar **)0x0,tt->item,-1,aclass);
                    if (iVar7 != 0) {
                      length = ASN1_object_size(local_64,iVar7,local_68);
                    }
                  }
                }
                else {
                  p_Var6 = *pval;
                  if (p_Var6 == (_STACK *)0x0) {
                    length = 0;
                  }
                  else {
                    if ((local_48 & 2) == 0) {
                      if (local_68 == -1) {
                        local_4c = 0x10;
                      }
                      else {
                        local_4c = 0x10;
                        if ((local_48 & 0x10) == 0) {
                          local_4c = local_68;
                        }
                      }
                    }
                    else if (local_68 == -1) {
                      local_4c = 0x11;
                    }
                    else {
                      local_4c = 0x11;
                      if ((local_48 & 0x10) == 0) {
                        local_4c = local_68;
                      }
                    }
                    local_48 = local_48 & 0x10;
                    iVar9 = 0;
                    for (iVar7 = 0; iVar10 = sk_num(p_Var6), iVar7 < iVar10; iVar7 = iVar7 + 1) {
                      local_24 = (ASN1_VALUE *)sk_value(p_Var6,iVar7);
                      iVar10 = ASN1_item_ex_i2d(&local_24,(uchar **)0x0,tt->item,-1,aclass);
                      iVar9 = iVar9 + iVar10;
                    }
                    length = ASN1_object_size(local_64,iVar9,local_4c);
                    if (local_48 != 0) {
                      length = ASN1_object_size(local_64,length,local_68);
                    }
                  }
                }
                local_74 = local_74 + 1;
                local_28 = local_28 + length;
                local_60 = local_60 + 1;
              } while ((int)local_74 < pAVar4->tcount);
            }
            pAVar11 = (ASN1_VALUE *)ASN1_object_size(local_3c,(int)local_28,0x10);
          }
        }
        break;
      default:
        goto switchD_08149ef5_caseD_7;
      }
LAB_08149e00:
      local_6c = local_6c + (int)pAVar11;
    }
    uVar8 = ASN1_object_size(local_58,(int)local_6c,local_40);
    if (local_34 == 0) {
      local_74 = uVar8;
      if (param_2_00 == (ASN1_VALUE **)0x0) goto LAB_08149c60;
    }
    else {
      local_74 = ASN1_object_size(local_58,uVar8,param_1);
      if (param_2_00 == (ASN1_VALUE **)0x0) goto LAB_08149c60;
      ASN1_put_object((uchar **)param_2_00,local_58,uVar8,param_1,local_44);
    }
    ASN1_put_object((uchar **)param_2_00,local_58,(int)local_6c,local_40,local_30);
    local_24 = (ASN1_VALUE *)0x0;
    pAVar4 = (ASN1_ITEM *)param_3[4];
    if ((local_38 == 0) || (iVar7 = sk_num(p_Var3), iVar7 < 2)) {
      for (iVar7 = 0; iVar9 = sk_num(p_Var3), iVar7 < iVar9; iVar7 = iVar7 + 1) {
        local_28 = (ASN1_VALUE *)sk_value(p_Var3,iVar7);
        ASN1_item_ex_i2d(&local_28,(uchar **)param_2_00,pAVar4,-1,aclass);
      }
    }
    else {
      iVar7 = sk_num(p_Var3);
      __base = (ASN1_VALUE **)CRYPTO_malloc(iVar7 * 0xc,"tasn_enc.c",0x1c7);
      pAVar11 = (ASN1_VALUE *)CRYPTO_malloc((int)local_6c,"tasn_enc.c",0x1c8);
      if ((__base != (ASN1_VALUE **)0x0) && (pAVar11 != (ASN1_VALUE *)0x0)) {
        ppAVar14 = __base;
        local_24 = pAVar11;
        for (iVar7 = 0; iVar9 = sk_num(p_Var3), iVar7 < iVar9; iVar7 = iVar7 + 1) {
          local_28 = (ASN1_VALUE *)sk_value(p_Var3,iVar7);
          *ppAVar14 = local_24;
          pAVar12 = (ASN1_VALUE *)ASN1_item_ex_i2d(&local_28,(uchar **)&local_24,pAVar4,-1,aclass);
          ppAVar14[1] = pAVar12;
          ppAVar14[2] = local_28;
          ppAVar14 = ppAVar14 + 3;
        }
        __nmemb = sk_num(p_Var3);
        qsort(__base,__nmemb,0xc,der_cmp);
        local_24 = *param_2_00;
        ppAVar14 = __base;
        for (iVar7 = 0; iVar9 = sk_num(p_Var3), iVar7 < iVar9; iVar7 = iVar7 + 1) {
          memcpy(local_24,*ppAVar14,(size_t)ppAVar14[1]);
          local_24 = local_24 + (int)ppAVar14[1];
          ppAVar14 = ppAVar14 + 3;
        }
        *param_2_00 = local_24;
        if (local_38 == 2) {
          ppAVar14 = __base;
          for (iVar7 = 0; iVar9 = sk_num(p_Var3), iVar7 < iVar9; iVar7 = iVar7 + 1) {
            ppAVar1 = ppAVar14 + 2;
            ppAVar14 = ppAVar14 + 3;
            sk_set(p_Var3,iVar7,*ppAVar1);
          }
        }
        CRYPTO_free(__base);
        CRYPTO_free(pAVar11);
      }
    }
    if ((local_58 != 2) || (ASN1_put_eoc((uchar **)param_2_00), local_34 == 0)) goto LAB_08149c60;
  }
  ASN1_put_eoc((uchar **)param_2_00);
LAB_08149c60:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_74;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

