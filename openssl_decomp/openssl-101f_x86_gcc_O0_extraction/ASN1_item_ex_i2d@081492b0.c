
int ASN1_item_ex_i2d(ASN1_VALUE **pval,uchar **out,ASN1_ITEM *it,int tag,int aclass)

{
  byte bVar1;
  void *pvVar2;
  code *pcVar3;
  byte *pbVar4;
  _STACK *p_Var5;
  int iVar6;
  int iVar7;
  ASN1_TEMPLATE *pAVar8;
  _STACK **pval_00;
  int iVar9;
  ASN1_TEMPLATE *tt;
  uint uVar10;
  uint aclass_00;
  uint length;
  int length_00;
  int in_GS_OFFSET;
  int local_54;
  long local_50;
  int local_4c;
  ASN1_TEMPLATE *local_48;
  uint local_40;
  int local_3c;
  int local_34;
  int local_28;
  ASN1_VALUE *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pvVar2 = it->funcs;
  bVar1 = it->itype;
  if (bVar1 == 0) {
    if ((pvVar2 != (void *)0x0) && (*(int *)((int)pvVar2 + 0x10) == 0)) {
LAB_08149323:
                    /* WARNING: Could not recover jumptable at 0x08149323. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar6 = (*(code *)(&PTR_LAB_0822803c)[bVar1])();
      return iVar6;
    }
    if (it->templates != (ASN1_TEMPLATE *)0x0) {
      iVar6 = asn1_template_ex_i2d(tag,aclass);
      goto LAB_08149362;
    }
LAB_0814946c:
    iVar6 = asn1_i2d_ex_primitive(tag,aclass);
    goto LAB_08149362;
  }
  if (*pval == (ASN1_VALUE *)0x0) goto switchD_08149305_caseD_0;
  if ((pvVar2 == (void *)0x0) || (pcVar3 = *(code **)((int)pvVar2 + 0x10), pcVar3 == (code *)0x0)) {
    if (bVar1 < 7) goto LAB_08149323;
    goto switchD_08149305_caseD_0;
  }
  switch((uint)bVar1) {
  case 1:
    local_34 = 1;
    goto LAB_08149400;
  case 2:
    iVar6 = (*pcVar3)(6,pval,it,0);
    if (iVar6 != 0) {
      iVar6 = asn1_get_choice_selector(pval,it);
      if ((iVar6 < 0) || (it->tcount == iVar6 || it->tcount < iVar6)) {
        (*pcVar3)(7,pval,it,0);
        iVar6 = 0;
      }
      else {
        asn1_get_field_ptr(pval,it->templates + iVar6);
        iVar6 = asn1_template_ex_i2d(0xffffffff,aclass);
      }
      goto LAB_08149362;
    }
    break;
  case 3:
    if (out == (uchar **)0x0) {
      iVar6 = (**(code **)((int)pvVar2 + 0xc))(*pval,0);
    }
    else {
      pbVar4 = *out;
      iVar6 = (**(code **)((int)pvVar2 + 0xc))(*pval,out);
      if (tag != -1) {
        *pbVar4 = (byte)aclass | (byte)tag | *pbVar4 & 0x20;
      }
    }
    goto LAB_08149362;
  case 4:
    iVar6 = (**(code **)((int)pvVar2 + 0x14))(pval,out,it,tag,aclass);
    goto LAB_08149362;
  case 5:
    tag = -1;
    goto LAB_0814946c;
  case 6:
    local_34 = 2 - (uint)((aclass & 0x800U) == 0);
LAB_08149400:
    iVar7 = asn1_enc_restore(&local_28,out,pval,it);
    if (-1 < iVar7) {
      iVar6 = local_28;
      if (iVar7 != 0) goto LAB_08149362;
      local_28 = 0;
      if (tag == -1) {
        aclass = aclass & 0xffffff3f;
        tag = 0x10;
      }
      if ((pcVar3 == (code *)0x0) || (iVar6 = (*pcVar3)(6,pval,it,0), iVar6 != 0)) {
        local_54 = 0;
        local_48 = it->templates;
        aclass_00 = aclass & 0xffffff3f;
        if (0 < it->tcount) {
          do {
            pAVar8 = asn1_do_adb(pval,local_48,1);
            if (pAVar8 == (ASN1_TEMPLATE *)0x0) goto switchD_08149305_caseD_0;
            pval_00 = (_STACK **)asn1_get_field_ptr(pval,pAVar8);
            local_40 = pAVar8->flags;
            if ((local_40 & 0x18) == 0) {
              uVar10 = 0;
              local_50 = -1;
            }
            else {
              local_50 = pAVar8->tag;
              uVar10 = local_40 & 0xc0;
            }
            local_4c = 1;
            if ((local_40 & 0x800) != 0) {
              local_4c = 2 - (uint)((aclass & 0x800U) == 0);
            }
            length = local_40 & 6;
            if (length == 0) {
              if ((local_40 & 0x10) == 0) {
                length = ASN1_item_ex_i2d((ASN1_VALUE **)pval_00,(uchar **)0x0,pAVar8->item,local_50
                                          ,uVar10 | aclass_00);
              }
              else {
                iVar6 = ASN1_item_ex_i2d((ASN1_VALUE **)pval_00,(uchar **)0x0,pAVar8->item,-1,
                                         aclass_00);
                if (iVar6 != 0) {
                  length = ASN1_object_size(local_4c,iVar6,local_50);
                }
              }
            }
            else {
              p_Var5 = *pval_00;
              if (p_Var5 == (_STACK *)0x0) {
                length = 0;
              }
              else {
                if ((local_40 & 2) == 0) {
                  if (local_50 == -1) {
                    local_3c = 0x10;
                  }
                  else {
                    local_3c = 0x10;
                    if ((local_40 & 0x10) == 0) {
                      local_3c = local_50;
                    }
                  }
                }
                else if (local_50 == -1) {
                  local_3c = 0x11;
                }
                else {
                  local_3c = 0x11;
                  if ((local_40 & 0x10) == 0) {
                    local_3c = local_50;
                  }
                }
                local_40 = local_40 & 0x10;
                length_00 = 0;
                for (iVar6 = 0; iVar9 = sk_num(p_Var5), iVar6 < iVar9; iVar6 = iVar6 + 1) {
                  local_24 = (ASN1_VALUE *)sk_value(p_Var5,iVar6);
                  iVar9 = ASN1_item_ex_i2d(&local_24,(uchar **)0x0,pAVar8->item,-1,aclass_00);
                  length_00 = length_00 + iVar9;
                }
                length = ASN1_object_size(local_4c,length_00,local_3c);
                if (local_40 != 0) {
                  length = ASN1_object_size(local_4c,length,local_50);
                }
              }
            }
            local_54 = local_54 + 1;
            local_28 = length + local_28;
            local_48 = local_48 + 1;
          } while (it->tcount != local_54 && local_54 <= it->tcount);
        }
        iVar6 = ASN1_object_size(local_34,local_28,tag);
        if (out == (uchar **)0x0) goto LAB_08149362;
        ASN1_put_object(out,local_34,local_28,tag,aclass);
        pAVar8 = it->templates;
        if (0 < it->tcount) {
          do {
            tt = asn1_do_adb(pval,pAVar8,1);
            if (tt == (ASN1_TEMPLATE *)0x0) goto switchD_08149305_caseD_0;
            pAVar8 = pAVar8 + 1;
            iVar7 = iVar7 + 1;
            asn1_get_field_ptr(pval,tt);
            asn1_template_ex_i2d(0xffffffff,aclass);
          } while (it->tcount != iVar7 && iVar7 <= it->tcount);
        }
        if (local_34 == 2) {
          ASN1_put_eoc(out);
        }
        if ((pcVar3 == (code *)0x0) || (iVar7 = (*pcVar3)(7,pval,it,0), iVar7 != 0))
        goto LAB_08149362;
      }
    }
  }
switchD_08149305_caseD_0:
  iVar6 = 0;
LAB_08149362:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

