
int ASN1_item_ex_i2d(ASN1_VALUE **pval,uchar **out,ASN1_ITEM *it,int tag,int aclass)

{
  byte bVar1;
  void *pvVar2;
  code *pcVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ASN1_TEMPLATE *pAVar8;
  ASN1_TEMPLATE *pAVar9;
  int in_GS_OFFSET;
  int local_38;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar1 = it->itype;
  pvVar2 = it->funcs;
  if (bVar1 == 0) {
    if ((pvVar2 != (void *)0x0) && (*(int *)((int)pvVar2 + 0x10) == 0)) {
LAB_08146703:
                    /* WARNING: Could not recover jumptable at 0x08146703. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar5 = (*(code *)(&PTR_LAB_08228310)[bVar1])();
      return iVar5;
    }
    if (it->templates != (ASN1_TEMPLATE *)0x0) {
      iVar5 = asn1_template_ex_i2d(tag,aclass);
      goto LAB_08146742;
    }
LAB_08146819:
    iVar5 = asn1_i2d_ex_primitive(tag,aclass);
    goto LAB_08146742;
  }
  if (*pval == (ASN1_VALUE *)0x0) goto switchD_081466e6_caseD_0;
  if ((pvVar2 == (void *)0x0) || (pcVar3 = *(code **)((int)pvVar2 + 0x10), pcVar3 == (code *)0x0)) {
    if (bVar1 < 7) goto LAB_08146703;
    goto switchD_081466e6_caseD_0;
  }
  switch((uint)bVar1) {
  case 1:
    local_38 = 1;
    goto LAB_081467c0;
  case 2:
    iVar5 = (*pcVar3)(6,pval,it,0);
    if (iVar5 != 0) {
      iVar5 = asn1_get_choice_selector(pval,it);
      if ((iVar5 < 0) || (it->tcount == iVar5 || it->tcount < iVar5)) {
        (*pcVar3)(7,pval,it,0);
        iVar5 = 0;
      }
      else {
        asn1_get_field_ptr(pval,it->templates + iVar5);
        iVar5 = asn1_template_ex_i2d(0xffffffff,aclass);
      }
      goto LAB_08146742;
    }
    break;
  case 3:
    if (out == (uchar **)0x0) {
      iVar5 = (**(code **)((int)pvVar2 + 0xc))(*pval,0);
    }
    else {
      pbVar4 = *out;
      iVar5 = (**(code **)((int)pvVar2 + 0xc))(*pval,out);
      if (tag != -1) {
        *pbVar4 = (byte)aclass | (byte)tag | *pbVar4 & 0x20;
      }
    }
    goto LAB_08146742;
  case 4:
    iVar5 = (**(code **)((int)pvVar2 + 0x14))(pval,out,it,tag,aclass);
    goto LAB_08146742;
  case 5:
    tag = -1;
    goto LAB_08146819;
  case 6:
    local_38 = 2 - (uint)((aclass & 0x800U) == 0);
LAB_081467c0:
    iVar6 = asn1_enc_restore(&local_24,out,pval,it);
    if (-1 < iVar6) {
      iVar5 = local_24;
      if (iVar6 != 0) goto LAB_08146742;
      local_24 = 0;
      if (tag == -1) {
        aclass = aclass & 0xffffff3f;
        tag = 0x10;
      }
      if ((pcVar3 == (code *)0x0) || (iVar5 = (*pcVar3)(6,pval,it,0), iVar5 != 0)) {
        pAVar9 = it->templates;
        if (0 < it->tcount) {
          iVar5 = 0;
          do {
            pAVar8 = asn1_do_adb(pval,pAVar9,1);
            if (pAVar8 == (ASN1_TEMPLATE *)0x0) goto switchD_081466e6_caseD_0;
            asn1_get_field_ptr(pval,pAVar8);
            iVar7 = asn1_template_ex_i2d(0xffffffff,aclass);
            if ((iVar7 == -1) || (0x7fffffff - local_24 < iVar7)) {
              iVar5 = -1;
              goto LAB_08146742;
            }
            local_24 = local_24 + iVar7;
            pAVar9 = pAVar9 + 1;
            iVar5 = iVar5 + 1;
          } while (it->tcount != iVar5 && iVar5 <= it->tcount);
        }
        iVar5 = ASN1_object_size(local_38,local_24,tag);
        if ((out == (uchar **)0x0) || (iVar5 == -1)) goto LAB_08146742;
        ASN1_put_object(out,local_38,local_24,tag,aclass);
        pAVar9 = it->templates;
        if (0 < it->tcount) {
          do {
            pAVar8 = asn1_do_adb(pval,pAVar9,1);
            if (pAVar8 == (ASN1_TEMPLATE *)0x0) goto switchD_081466e6_caseD_0;
            pAVar9 = pAVar9 + 1;
            iVar6 = iVar6 + 1;
            asn1_get_field_ptr(pval,pAVar8);
            asn1_template_ex_i2d(0xffffffff,aclass);
          } while (it->tcount != iVar6 && iVar6 <= it->tcount);
        }
        if (local_38 == 2) {
          ASN1_put_eoc(out);
        }
        if ((pcVar3 == (code *)0x0) || (iVar6 = (*pcVar3)(7,pval,it,0), iVar6 != 0))
        goto LAB_08146742;
      }
    }
  }
switchD_081466e6_caseD_0:
  iVar5 = 0;
LAB_08146742:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

