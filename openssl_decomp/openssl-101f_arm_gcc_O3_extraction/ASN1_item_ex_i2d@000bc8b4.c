
int ASN1_item_ex_i2d(ASN1_VALUE **pval,uchar **out,ASN1_ITEM *it,int tag,int aclass)

{
  _STACK *length;
  int iVar1;
  int iVar2;
  ASN1_TEMPLATE *pAVar3;
  _STACK **pval_00;
  int iVar4;
  ASN1_VALUE **ppAVar5;
  uint uVar6;
  code *pcVar7;
  uint uVar8;
  byte *pbVar9;
  ASN1_TEMPLATE *pAVar10;
  _STACK *p_Var11;
  int length_00;
  uint uVar12;
  int iVar13;
  int local_5c;
  code *local_58;
  long local_54;
  int local_50;
  int local_48;
  _STACK *local_44;
  int local_38;
  int local_30;
  void *local_2c [2];
  
  pcVar7 = (code *)it->funcs;
  if ((it->itype != '\0') && (*pval == (ASN1_VALUE *)0x0)) {
    return 0;
  }
  local_58 = pcVar7;
  if (pcVar7 != (code *)0x0) {
    local_58 = *(code **)(pcVar7 + 0x10);
  }
  switch(it->itype) {
  case '\0':
    if (it->templates != (ASN1_TEMPLATE *)0x0) {
      iVar1 = asn1_template_ex_i2d(pval,out,it->templates,tag,aclass);
      return iVar1;
    }
    iVar1 = asn1_i2d_ex_primitive(pval,out,it,tag,aclass);
    return iVar1;
  case '\x01':
    local_38 = 1;
    break;
  case '\x02':
    if ((local_58 != (code *)0x0) && (iVar1 = (*local_58)(6,pval,it,0), iVar1 == 0)) {
      return 0;
    }
    iVar1 = asn1_get_choice_selector(pval,it);
    if ((-1 < iVar1) && (iVar1 < it->tcount)) {
      pAVar10 = it->templates;
      ppAVar5 = asn1_get_field_ptr(pval,pAVar10 + iVar1);
      iVar1 = asn1_template_ex_i2d(ppAVar5,out,pAVar10 + iVar1,0xffffffff,aclass);
      return iVar1;
    }
    if (local_58 == (code *)0x0) {
      return 0;
    }
    (*local_58)(7,pval,it,0);
    return 0;
  case '\x03':
    if (out == (uchar **)0x0) {
      iVar1 = (**(code **)(pcVar7 + 0xc))(*pval,0);
      return iVar1;
    }
    pbVar9 = *out;
    iVar1 = (**(code **)(pcVar7 + 0xc))();
    if (tag != -1) {
      *pbVar9 = *pbVar9 & 0x20 | (byte)tag | (byte)aclass;
      return iVar1;
    }
    return iVar1;
  case '\x04':
    iVar1 = (**(code **)(pcVar7 + 0x14))(pval,out,it,tag,aclass);
    return iVar1;
  case '\x05':
    iVar1 = asn1_i2d_ex_primitive(pval,out,it,0xffffffff,aclass);
    return iVar1;
  case '\x06':
    if ((aclass & 0x800U) == 0) {
      local_38 = 1;
    }
    else {
      local_38 = 2;
    }
    break;
  default:
    goto LAB_000bc918;
  }
  iVar1 = asn1_enc_restore(&local_30,out,pval,it);
  if (-1 < iVar1) {
    if (iVar1 != 0) {
      return local_30;
    }
    local_5c = tag;
    if (tag == -1) {
      aclass = aclass & 0xffffff3f;
      local_5c = 0x10;
    }
    local_30 = iVar1;
    if ((local_58 == (code *)0x0) || (iVar2 = (*local_58)(6,pval,it,0), iVar2 != 0)) {
      pAVar10 = it->templates;
      if (0 < it->tcount) {
        uVar12 = aclass & 0xffffff3f;
        iVar2 = iVar1;
        do {
          pAVar3 = asn1_do_adb(pval,pAVar10,1);
          if (pAVar3 == (ASN1_TEMPLATE *)0x0) {
            return 0;
          }
          pval_00 = (_STACK **)asn1_get_field_ptr(pval,pAVar3);
          uVar8 = pAVar3->flags;
          uVar6 = uVar8 & 0x18;
          if (uVar6 == 0) {
            local_54 = -1;
          }
          else {
            uVar6 = uVar8 & 0xc0;
            local_54 = pAVar3->tag;
          }
          if ((int)(uVar8 << 0x14) < 0) {
            if ((aclass & 0x800U) == 0) {
              local_50 = 1;
            }
            else {
              local_50 = 2;
            }
          }
          else {
            local_50 = 1;
          }
          p_Var11 = (_STACK *)(uVar8 & 6);
          if (p_Var11 == (_STACK *)0x0) {
            if ((int)(uVar8 << 0x1b) < 0) {
              local_44 = (_STACK *)ASN1_item_ex_i2d_constprop_0(pval_00,pAVar3->item,uVar12);
              length = local_44;
              goto joined_r0x000bcb98;
            }
            p_Var11 = (_STACK *)
                      ASN1_item_ex_i2d((ASN1_VALUE **)pval_00,(uchar **)0x0,pAVar3->item,local_54,
                                       uVar6 | uVar12);
          }
          else {
            p_Var11 = *pval_00;
            if (p_Var11 != (_STACK *)0x0) {
              uVar6 = uVar8 & 2;
              if (uVar6 != 0) {
                if ((uVar8 & 4) == 0) {
                  uVar6 = 1;
                }
                else {
                  uVar6 = 2;
                }
              }
              if ((local_54 == -1) || ((uVar8 & 0x10) != 0)) {
                if (uVar6 == 0) {
                  local_48 = 0x10;
                }
                else {
                  local_48 = 0x11;
                }
              }
              else {
                local_48 = local_54;
              }
              local_44 = (_STACK *)(uVar8 & 0x10);
              length_00 = 0;
              iVar13 = 0;
              while( true ) {
                iVar4 = sk_num(p_Var11);
                if (iVar4 <= iVar13) break;
                local_2c[0] = sk_value(p_Var11,iVar13);
                iVar4 = ASN1_item_ex_i2d_constprop_0(local_2c,pAVar3->item,uVar12);
                length_00 = length_00 + iVar4;
                iVar13 = iVar13 + 1;
              }
              p_Var11 = (_STACK *)ASN1_object_size(local_50,length_00,local_48);
              length = p_Var11;
joined_r0x000bcb98:
              if (local_44 != (_STACK *)0x0) {
                p_Var11 = (_STACK *)ASN1_object_size(local_50,(int)length,local_54);
              }
            }
          }
          iVar2 = iVar2 + 1;
          pAVar10 = pAVar10 + 1;
          local_30 = (int)&p_Var11->num + local_30;
        } while (iVar2 < it->tcount);
      }
      iVar2 = ASN1_object_size(local_38,local_30,local_5c);
      if (out == (uchar **)0x0) {
        return iVar2;
      }
      ASN1_put_object(out,local_38,local_30,local_5c,aclass);
      pAVar10 = it->templates;
      if (0 < it->tcount) {
        do {
          iVar1 = iVar1 + 1;
          pAVar3 = asn1_do_adb(pval,pAVar10,1);
          pAVar10 = pAVar10 + 1;
          if (pAVar3 == (ASN1_TEMPLATE *)0x0) {
            return 0;
          }
          ppAVar5 = asn1_get_field_ptr(pval,pAVar3);
          asn1_template_ex_i2d(ppAVar5,out,pAVar3,0xffffffff,aclass);
        } while (iVar1 < it->tcount);
      }
      if (local_38 == 2) {
        ASN1_put_eoc(out);
      }
      if (local_58 == (code *)0x0) {
        return iVar2;
      }
      iVar1 = (*local_58)(7,pval,it,0);
      if (iVar1 != 0) {
        return iVar2;
      }
    }
  }
LAB_000bc918:
  return 0;
}

