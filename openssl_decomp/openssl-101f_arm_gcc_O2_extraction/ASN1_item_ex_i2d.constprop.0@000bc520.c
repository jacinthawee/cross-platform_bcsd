
/* WARNING: Type propagation algorithm not settling */

uint ASN1_item_ex_i2d_constprop_0(_STACK **param_1,ASN1_ITEM *param_2,uint param_3)

{
  bool bVar1;
  _STACK *length;
  int iVar2;
  _STACK *p_Var3;
  int iVar4;
  ASN1_TEMPLATE *tt;
  _STACK **pval;
  int iVar5;
  ASN1_VALUE **ppAVar6;
  code *pcVar7;
  uint uVar8;
  undefined *tag;
  undefined *puVar9;
  uint uVar10;
  _STACK *p_Var11;
  code *pcVar12;
  int length_00;
  ASN1_TEMPLATE *pAVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  bool bVar17;
  bool bVar18;
  uint local_4c;
  int local_48;
  _STACK *local_40;
  int local_3c;
  int local_34;
  _STACK *local_30;
  undefined *local_2c [2];
  
  pcVar7 = (code *)param_2->funcs;
  if ((param_2->itype != '\0') && (*param_1 == (_STACK *)0x0)) {
    return 0;
  }
  pcVar12 = pcVar7;
  if (pcVar7 != (code *)0x0) {
    pcVar12 = *(code **)(pcVar7 + 0x10);
  }
  switch(param_2->itype) {
  case '\0':
    pAVar13 = param_2->templates;
    if (pAVar13 == (ASN1_TEMPLATE *)0x0) {
      uVar16 = asn1_i2d_ex_primitive(param_1,0,param_2,0xffffffff,param_3);
      return uVar16;
    }
    local_4c = pAVar13->flags;
    uVar8 = param_3 & 0xffffff3f;
    uVar16 = local_4c & 0x18;
    if (uVar16 == 0) {
      iVar2 = -1;
    }
    else {
      uVar16 = local_4c & 0xc0;
      iVar2 = pAVar13->tag;
    }
    if ((int)(local_4c << 0x14) < 0) {
      if ((param_3 & 0x800) == 0) {
        iVar14 = 1;
      }
      else {
        iVar14 = 2;
      }
    }
    else {
      iVar14 = 1;
    }
    uVar10 = local_4c & 6;
    if (uVar10 == 0) {
      if (-1 < (int)(local_4c << 0x1b)) {
        uVar16 = ASN1_item_ex_i2d((ASN1_VALUE **)param_1,(uchar **)0x0,pAVar13->item,iVar2,
                                  uVar16 | uVar8);
        return uVar16;
      }
      local_4c = ASN1_item_ex_i2d_constprop_0(param_1,pAVar13->item,uVar8);
      uVar16 = local_4c;
    }
    else {
      p_Var3 = *param_1;
      if (p_Var3 == (_STACK *)0x0) {
        return 0;
      }
      uVar16 = local_4c & 2;
      if (uVar16 != 0) {
        if ((local_4c & 4) == 0) {
          uVar16 = 1;
        }
        else {
          uVar16 = 2;
        }
      }
      if ((iVar2 == -1) || (iVar5 = iVar2, (local_4c & 0x10) != 0)) {
        if (uVar16 == 0) {
          iVar5 = 0x10;
        }
        else {
          iVar5 = 0x11;
        }
      }
      local_4c = local_4c & 0x10;
      length_00 = 0;
      iVar15 = 0;
      while( true ) {
        iVar4 = sk_num(p_Var3);
        if (iVar4 <= iVar15) break;
        local_2c[0] = (undefined *)sk_value(p_Var3,iVar15);
        iVar4 = ASN1_item_ex_i2d_constprop_0(local_2c,pAVar13->item,uVar8);
        length_00 = length_00 + iVar4;
        iVar15 = iVar15 + 1;
      }
      uVar10 = ASN1_object_size(iVar14,length_00,iVar5);
      uVar16 = uVar10;
    }
    if (local_4c != 0) {
      uVar16 = ASN1_object_size(iVar14,uVar16,iVar2);
      return uVar16;
    }
    return uVar10;
  case '\x01':
    local_34 = 1;
    break;
  case '\x02':
    if ((pcVar12 != (code *)0x0) && (iVar2 = (*pcVar12)(6,param_1,param_2,0), iVar2 == 0)) {
      return 0;
    }
    iVar2 = asn1_get_choice_selector((ASN1_VALUE **)param_1,param_2);
    if ((-1 < iVar2) && (iVar2 < param_2->tcount)) {
      pAVar13 = param_2->templates;
      ppAVar6 = asn1_get_field_ptr((ASN1_VALUE **)param_1,pAVar13 + iVar2);
      uVar16 = asn1_template_ex_i2d(ppAVar6,0,pAVar13 + iVar2,0xffffffff,param_3);
      return uVar16;
    }
    if (pcVar12 == (code *)0x0) {
      return 0;
    }
    (*pcVar12)(7,param_1,param_2,0);
    return 0;
  case '\x03':
    uVar16 = (**(code **)(pcVar7 + 0xc))(*param_1,0);
    return uVar16;
  case '\x04':
    uVar16 = (**(code **)(pcVar7 + 0x14))(param_1,0,param_2,0xffffffff,param_3);
    return uVar16;
  case '\x05':
    local_2c[0] = (undefined *)param_2->utype;
    p_Var3 = (_STACK *)asn1_ex_i2c((ASN1_VALUE **)param_1,(uchar *)0x0,(int *)local_2c,param_2);
    puVar9 = local_2c[0] + -0x10;
    bVar18 = (undefined *)0xfffffffc < local_2c[0];
    bVar17 = local_2c[0] == (undefined *)0xfffffffd;
    if (!bVar17) {
      bVar18 = puVar9 != (undefined *)0x0;
    }
    bVar1 = puVar9 == (undefined *)0x1;
    if (!bVar18 || (bVar17 || bVar1)) {
      puVar9 = (undefined *)0x1;
    }
    if (bVar18 && (!bVar17 && !bVar1)) {
      puVar9 = (undefined *)0x0;
    }
    if (p_Var3 == (_STACK *)0xffffffff) {
      return 0;
    }
    if (p_Var3 == (_STACK *)0xfffffffe) {
      local_34 = 2;
      p_Var3 = (_STACK *)0x0;
    }
    else {
      local_34 = 0;
    }
    tag = local_2c[0];
    if (puVar9 != (undefined *)0x0) {
      return (uint)p_Var3;
    }
    goto LAB_000bc802;
  case '\x06':
    if ((param_3 & 0x800) == 0) {
      local_34 = 1;
    }
    else {
      local_34 = 2;
    }
    break;
  default:
    goto LAB_000bc568;
  }
  p_Var3 = (_STACK *)asn1_enc_restore((int *)&local_30,(uchar **)0x0,(ASN1_VALUE **)param_1,param_2)
  ;
  if (-1 < (int)p_Var3) {
    if (p_Var3 != (_STACK *)0x0) {
      return (uint)local_30;
    }
    local_30 = p_Var3;
    if ((pcVar12 == (code *)0x0) || (iVar2 = (*pcVar12)(6,param_1,param_2,0), iVar2 != 0)) {
      pAVar13 = param_2->templates;
      if (0 < param_2->tcount) {
        uVar16 = param_3 & 0xffffff3f;
        do {
          tt = asn1_do_adb((ASN1_VALUE **)param_1,pAVar13,1);
          if (tt == (ASN1_TEMPLATE *)0x0) {
            return 0;
          }
          pval = (_STACK **)asn1_get_field_ptr((ASN1_VALUE **)param_1,tt);
          uVar10 = tt->flags;
          uVar8 = uVar10 & 0x18;
          if (uVar8 == 0) {
            local_4c = -1;
          }
          else {
            uVar8 = uVar10 & 0xc0;
            local_4c = tt->tag;
          }
          if ((int)(uVar10 << 0x14) < 0) {
            if ((param_3 & 0x800) == 0) {
              local_48 = 1;
            }
            else {
              local_48 = 2;
            }
          }
          else {
            local_48 = 1;
          }
          p_Var11 = (_STACK *)(uVar10 & 6);
          if (p_Var11 == (_STACK *)0x0) {
            if ((int)(uVar10 << 0x1b) < 0) {
              local_40 = (_STACK *)ASN1_item_ex_i2d_constprop_0(pval,tt->item,uVar16);
              length = local_40;
              goto joined_r0x000bc870;
            }
            p_Var11 = (_STACK *)
                      ASN1_item_ex_i2d((ASN1_VALUE **)pval,(uchar **)0x0,tt->item,local_4c,
                                       uVar8 | uVar16);
          }
          else {
            p_Var11 = *pval;
            if (p_Var11 != (_STACK *)0x0) {
              uVar8 = uVar10 & 2;
              if (uVar8 != 0) {
                if ((uVar10 & 4) == 0) {
                  uVar8 = 1;
                }
                else {
                  uVar8 = 2;
                }
              }
              if ((local_4c == -1) || ((uVar10 & 0x10) != 0)) {
                if (uVar8 == 0) {
                  local_3c = 0x10;
                }
                else {
                  local_3c = 0x11;
                }
              }
              else {
                local_3c = local_4c;
              }
              local_40 = (_STACK *)(uVar10 & 0x10);
              iVar14 = 0;
              iVar2 = 0;
              while( true ) {
                iVar5 = sk_num(p_Var11);
                if (iVar5 <= iVar2) break;
                local_2c[0] = (undefined *)sk_value(p_Var11,iVar2);
                iVar5 = ASN1_item_ex_i2d_constprop_0(local_2c,tt->item,uVar16);
                iVar14 = iVar14 + iVar5;
                iVar2 = iVar2 + 1;
              }
              p_Var11 = (_STACK *)ASN1_object_size(local_48,iVar14,local_3c);
              length = p_Var11;
joined_r0x000bc870:
              if (local_40 != (_STACK *)0x0) {
                p_Var11 = (_STACK *)ASN1_object_size(local_48,(int)length,local_4c);
              }
            }
          }
          p_Var3 = (_STACK *)((int)&p_Var3->num + 1);
          pAVar13 = pAVar13 + 1;
          local_30 = (_STACK *)((int)&local_30->num + (int)&p_Var11->num);
        } while ((int)p_Var3 < param_2->tcount);
      }
      p_Var3 = local_30;
      tag = &DAT_00000010;
LAB_000bc802:
      uVar16 = ASN1_object_size(local_34,(int)p_Var3,(int)tag);
      return uVar16;
    }
  }
LAB_000bc568:
  return 0;
}

