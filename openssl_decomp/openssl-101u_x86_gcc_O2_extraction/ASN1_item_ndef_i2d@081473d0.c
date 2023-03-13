
int ASN1_item_ndef_i2d(ASN1_VALUE *val,uchar **out,ASN1_ITEM *it)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ASN1_TEMPLATE *pAVar6;
  uchar *num;
  uchar *puVar7;
  uchar *puVar8;
  ASN1_TEMPLATE *pAVar9;
  code *pcVar10;
  int in_GS_OFFSET;
  int local_38;
  ASN1_VALUE *local_28;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = val;
  if ((out != (uchar **)0x0) && (*out == (uchar *)0x0)) {
    num = (uchar *)ASN1_item_ex_i2d(&local_28,(uchar **)0x0,it,-1,0x800);
    puVar8 = num;
    if (0 < (int)num) {
      puVar7 = (uchar *)CRYPTO_malloc((int)num,"tasn_enc.c",0x6e);
      puVar8 = (uchar *)0xffffffff;
      if (puVar7 != (uchar *)0x0) {
        local_24 = puVar7;
        ASN1_item_ex_i2d(&local_28,&local_24,it,-1,0x800);
        *out = puVar7;
        puVar8 = num;
      }
    }
    goto LAB_08147462;
  }
  pvVar2 = it->funcs;
  cVar1 = it->itype;
  if ((val == (ASN1_VALUE *)0x0) && (cVar1 != '\0')) goto switchD_08147484_caseD_7;
  if ((pvVar2 == (void *)0x0) || (pcVar10 = *(code **)((int)pvVar2 + 0x10), pcVar10 == (code *)0x0))
  {
    switch(cVar1) {
    case '\0':
      goto switchD_08147484_caseD_0;
    case '\x01':
      pcVar10 = (code *)0x0;
      goto switchD_0814741e_caseD_1;
    case '\x02':
      iVar3 = asn1_get_choice_selector(&local_28,it);
      if ((-1 < iVar3) && (iVar3 < it->tcount)) goto LAB_08147720;
      break;
    case '\x03':
      goto switchD_08147484_caseD_3;
    case '\x04':
      goto switchD_08147484_caseD_4;
    case '\x05':
      goto switchD_08147484_caseD_5;
    case '\x06':
      pcVar10 = (code *)0x0;
      goto switchD_0814741e_caseD_6;
    }
    goto switchD_08147484_caseD_7;
  }
  switch(cVar1) {
  case '\0':
switchD_08147484_caseD_0:
    if (it->templates != (ASN1_TEMPLATE *)0x0) {
      puVar8 = (uchar *)asn1_template_ex_i2d(0xffffffff,0x800);
      goto LAB_08147462;
    }
  case '\x05':
switchD_08147484_caseD_5:
    puVar8 = (uchar *)asn1_i2d_ex_primitive(0xffffffff,0x800);
    goto LAB_08147462;
  case '\x01':
switchD_0814741e_caseD_1:
    local_38 = 1;
    goto LAB_08147502;
  case '\x02':
    iVar3 = (*pcVar10)(6,&local_28,it,0);
    if (iVar3 != 0) {
      iVar3 = asn1_get_choice_selector(&local_28,it);
      if ((iVar3 < 0) || (it->tcount == iVar3 || it->tcount < iVar3)) {
        (*pcVar10)(7,&local_28,it,0);
        puVar8 = (uchar *)0x0;
        goto LAB_08147462;
      }
LAB_08147720:
      asn1_get_field_ptr(&local_28,it->templates + iVar3);
      puVar8 = (uchar *)asn1_template_ex_i2d(0xffffffff,0x800);
      goto LAB_08147462;
    }
    break;
  case '\x03':
switchD_08147484_caseD_3:
    puVar8 = (uchar *)(**(code **)((int)pvVar2 + 0xc))(val,out);
    goto LAB_08147462;
  case '\x04':
switchD_08147484_caseD_4:
    puVar8 = (uchar *)(**(code **)((int)pvVar2 + 0x14))(&local_28,out,it,0xffffffff,0x800);
    goto LAB_08147462;
  case '\x06':
switchD_0814741e_caseD_6:
    local_38 = 2;
LAB_08147502:
    iVar3 = asn1_enc_restore((int *)&local_24,out,&local_28,it);
    if (-1 < iVar3) {
      puVar8 = local_24;
      if (iVar3 != 0) goto LAB_08147462;
      local_24 = (uchar *)0x0;
      if ((pcVar10 == (code *)0x0) || (iVar4 = (*pcVar10)(6,&local_28,it,0), iVar4 != 0)) {
        pAVar9 = it->templates;
        if (0 < it->tcount) {
          iVar4 = 0;
          do {
            pAVar6 = asn1_do_adb(&local_28,pAVar9,1);
            if (pAVar6 == (ASN1_TEMPLATE *)0x0) goto switchD_08147484_caseD_7;
            asn1_get_field_ptr(&local_28,pAVar6);
            iVar5 = asn1_template_ex_i2d(0xffffffff,0x800);
            if ((iVar5 == -1) || (0x7fffffff - (int)local_24 < iVar5)) {
              puVar8 = (uchar *)0xffffffff;
              goto LAB_08147462;
            }
            local_24 = local_24 + iVar5;
            pAVar9 = pAVar9 + 1;
            iVar4 = iVar4 + 1;
          } while (iVar4 < it->tcount);
        }
        puVar8 = (uchar *)ASN1_object_size(local_38,(int)local_24,0x10);
        if ((out == (uchar **)0x0) || (puVar8 == (uchar *)0xffffffff)) goto LAB_08147462;
        ASN1_put_object(out,local_38,(int)local_24,0x10,0x800);
        pAVar9 = it->templates;
        if (0 < it->tcount) {
          do {
            pAVar6 = asn1_do_adb(&local_28,pAVar9,1);
            if (pAVar6 == (ASN1_TEMPLATE *)0x0) goto switchD_08147484_caseD_7;
            pAVar9 = pAVar9 + 1;
            iVar3 = iVar3 + 1;
            asn1_get_field_ptr(&local_28,pAVar6);
            asn1_template_ex_i2d(0xffffffff,0x800);
          } while (iVar3 < it->tcount);
        }
        if (local_38 == 2) {
          ASN1_put_eoc(out);
        }
        if ((pcVar10 == (code *)0x0) || (iVar3 = (*pcVar10)(7,&local_28,it,0), iVar3 != 0))
        goto LAB_08147462;
      }
    }
  }
switchD_08147484_caseD_7:
  puVar8 = (uchar *)0x0;
LAB_08147462:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (int)puVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

