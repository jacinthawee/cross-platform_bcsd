
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ASN1_VALUE * ASN1_item_d2i(ASN1_VALUE **val,uchar **in,long len,ASN1_ITEM *it)

{
  void *pvVar1;
  uchar *puVar2;
  ASN1_VALUE *pAVar3;
  int iVar4;
  ASN1_TEMPLATE *pAVar5;
  ASN1_VALUE **ppAVar6;
  uint uVar7;
  int iVar8;
  int in_GS_OFFSET;
  code *local_68;
  ASN1_TEMPLATE *local_64;
  undefined *local_58;
  char local_4d;
  char local_4b;
  char local_4a;
  char local_49;
  ASN1_VALUE *local_48;
  uchar *local_44;
  uchar *local_40;
  uint local_3c;
  undefined local_38 [24];
  int local_20;
  
  local_48 = (ASN1_VALUE *)0x0;
  local_38[0] = 0;
  pvVar1 = it->funcs;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_44 = (uchar *)len;
  local_40 = (uchar *)0x0;
  if (val == (ASN1_VALUE **)0x0) {
    val = &local_48;
  }
  if (pvVar1 == (void *)0x0) {
    if (6 < (byte)it->itype) goto LAB_0814add0;
    switch(it->itype) {
    case '\0':
      goto switchD_0814b0d4_caseD_0;
    default:
      local_68 = (code *)0x0;
      goto switchD_0814ad62_caseD_1;
    case '\x02':
      local_68 = (code *)0x0;
LAB_0814b000:
      if (*val == (ASN1_VALUE *)0x0) {
        iVar4 = ASN1_item_ex_new(val,it);
        if (iVar4 == 0) {
          iVar4 = 0x13f;
          goto LAB_0814b1f0;
        }
        iVar4 = it->tcount;
      }
      else {
        iVar8 = asn1_get_choice_selector(val,it);
        iVar4 = it->tcount;
        if ((-1 < iVar8) && (iVar8 < iVar4)) {
          pAVar5 = it->templates;
          ppAVar6 = asn1_get_field_ptr(val,pAVar5 + iVar8);
          ASN1_template_free(ppAVar6,pAVar5 + iVar8);
          asn1_set_choice_selector(val,-1,it);
          iVar4 = it->tcount;
        }
      }
      iVar8 = 0;
      pAVar5 = it->templates;
      local_40 = *in;
      if (0 < iVar4) {
        do {
          asn1_get_field_ptr(val,pAVar5);
          iVar4 = asn1_template_ex_d2i(pAVar5,1,local_38);
          if (iVar4 != -1) {
            if (iVar4 < 1) {
              ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",0x152);
              ASN1_item_ex_free(val,it);
              if (pAVar5 == (ASN1_TEMPLATE *)0x0) goto LAB_0814adb7;
              goto LAB_0814b108;
            }
            iVar4 = it->tcount;
            break;
          }
          iVar4 = it->tcount;
          iVar8 = iVar8 + 1;
          pAVar5 = pAVar5 + 1;
        } while (iVar8 < iVar4);
      }
      if (iVar8 == iVar4) {
        ERR_put_error(0xd,0x78,0x8f,"tasn_dec.c",0x15e);
        goto LAB_0814adaa;
      }
      asn1_set_choice_selector(val,iVar8,it);
      break;
    case '\x03':
      goto switchD_0814b0d4_caseD_3;
    case '\x04':
      local_68 = _DAT_00000010;
      goto LAB_0814afcc;
    case '\x05':
      goto switchD_0814b0d4_caseD_5;
    }
joined_r0x0814b098:
    if ((local_68 == (code *)0x0) || (iVar4 = (*local_68)(5,val,it,0), iVar4 != 0)) {
      *in = local_40;
      pAVar3 = *val;
      goto LAB_0814add2;
    }
    goto LAB_0814ad8f;
  }
  local_68 = *(code **)((int)pvVar1 + 0x10);
  if (6 < (byte)it->itype) goto LAB_0814add0;
  switch(it->itype) {
  case '\0':
switchD_0814b0d4_caseD_0:
    if (it->templates == (ASN1_TEMPLATE *)0x0) {
      iVar4 = asn1_d2i_ex_primitive(it,0xffffffff,0,0,local_38);
    }
    else {
      iVar4 = asn1_template_ex_d2i(it->templates,0,local_38);
    }
    goto LAB_0814afe3;
  default:
switchD_0814ad62_caseD_1:
    local_40 = *in;
    iVar4 = asn1_check_tlen(&local_4a,&local_49,&local_40,len,0x10,0,0,local_38);
    if (iVar4 == 0) {
      iVar4 = 0x176;
      goto LAB_0814b1f0;
    }
    if (iVar4 == -1) goto LAB_0814add0;
    if ((pvVar1 == (void *)0x0) || ((*(byte *)((int)pvVar1 + 4) & 4) == 0)) {
      local_4d = local_4a;
    }
    else {
      local_4d = '\x01';
      local_44 = (uchar *)(len - ((int)local_40 - (int)*in));
    }
    if (local_49 == '\0') {
      ERR_put_error(0xd,0x78,0x95,"tasn_dec.c",0x182);
      break;
    }
    if ((*val == (ASN1_VALUE *)0x0) && (iVar4 = ASN1_item_ex_new(val,it), iVar4 == 0)) {
      iVar4 = 0x187;
      goto LAB_0814b1f0;
    }
    if ((local_68 != (code *)0x0) && (iVar4 = (*local_68)(4,val,it,0), iVar4 == 0))
    goto LAB_0814ad8f;
    iVar4 = it->tcount;
    iVar8 = 0;
    local_64 = it->templates;
    if (iVar4 < 1) {
LAB_0814b562:
      iVar4 = 0;
    }
    else {
      do {
        if ((local_64->flags & 0x300) != 0) {
          pAVar5 = asn1_do_adb(val,local_64,1);
          ppAVar6 = asn1_get_field_ptr(val,pAVar5);
          ASN1_template_free(ppAVar6,pAVar5);
          iVar4 = it->tcount;
        }
        iVar8 = iVar8 + 1;
        local_64 = local_64 + 1;
      } while (iVar8 < iVar4);
      local_64 = it->templates;
      if (iVar4 < 1) goto LAB_0814b562;
      iVar4 = 0;
      do {
        local_58 = local_38;
        pAVar5 = asn1_do_adb(val,local_64,1);
        if (pAVar5 == (ASN1_TEMPLATE *)0x0) goto LAB_0814adaa;
        ppAVar6 = asn1_get_field_ptr(val,pAVar5);
        puVar2 = local_40;
        if (local_44 == (uchar *)0x0) {
          if (local_4a == '\0') goto LAB_0814b363;
          goto LAB_0814b454;
        }
        if (((1 < (int)local_44) && (*local_40 == '\0')) && (local_40[1] == '\0')) {
          local_40 = local_40 + 2;
          if (local_4a == '\0') {
            ERR_put_error(0xd,0x78,0x9f,"tasn_dec.c",0x1a7);
            goto LAB_0814adaa;
          }
          local_44 = local_44 + -2;
          local_4a = '\0';
          goto LAB_0814b350;
        }
        uVar7 = 0;
        if (it->tcount + -1 != iVar4) {
          uVar7 = pAVar5->flags & 1;
        }
        iVar8 = asn1_template_ex_d2i(pAVar5,uVar7,local_58);
        if (iVar8 == 0) goto LAB_0814b47b;
        if (iVar8 == -1) {
          ASN1_template_free(ppAVar6,pAVar5);
        }
        else {
          local_44 = puVar2 + ((int)local_44 - (int)local_40);
        }
        iVar4 = iVar4 + 1;
        local_64 = local_64 + 1;
      } while (iVar4 < it->tcount);
    }
    if (local_4a != '\0') {
      if ((((int)local_44 < 2) || (*local_40 != '\0')) || (local_40[1] != '\0')) {
LAB_0814b454:
        ERR_put_error(0xd,0x78,0x89,"tasn_dec.c",0x1ce);
        break;
      }
      local_40 = local_40 + 2;
    }
LAB_0814b350:
    if ((local_4d == '\0') && (local_44 != (uchar *)0x0)) {
      ERR_put_error(0xd,0x78,0x94,"tasn_dec.c",0x1d3);
      break;
    }
LAB_0814b363:
    if (it->tcount != iVar4 && iVar4 <= it->tcount) {
LAB_0814b3aa:
      pAVar5 = asn1_do_adb(val,local_64,1);
      if (pAVar5 != (ASN1_TEMPLATE *)0x0) {
        if ((*(byte *)&pAVar5->flags & 1) != 0) goto code_r0x0814b381;
        ERR_put_error(0xd,0x78,0x79,"tasn_dec.c",0x1e7);
LAB_0814b47b:
        ASN1_item_ex_free(val,it);
LAB_0814b108:
        ERR_add_error_data(4,"Field=",pAVar5->field_name,", Type=",it->sname);
        goto LAB_0814add0;
      }
      break;
    }
LAB_0814b4ea:
    iVar4 = asn1_enc_save(val,*in,(int)local_40 - (int)*in,it);
    if (iVar4 != 0) goto joined_r0x0814b098;
    goto LAB_0814ad8f;
  case '\x02':
    if ((local_68 == (code *)0x0) || (iVar4 = (*local_68)(4,val,it,0), iVar4 != 0))
    goto LAB_0814b000;
LAB_0814ad8f:
    ERR_put_error(0xd,0x78,100,"tasn_dec.c",0x1f7);
    break;
  case '\x03':
switchD_0814b0d4_caseD_3:
    iVar4 = (**(code **)((int)pvVar1 + 8))(val,in,len);
    if (iVar4 != 0) {
      pAVar3 = *val;
      goto LAB_0814add2;
    }
    iVar4 = 0x12f;
LAB_0814b1f0:
    ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",iVar4);
    break;
  case '\x04':
LAB_0814afcc:
    iVar4 = (*local_68)(val,in,len,it,0xffffffff,0,0,local_38);
LAB_0814afe3:
    if (0 < iVar4) {
      pAVar3 = *val;
      goto LAB_0814add2;
    }
    goto LAB_0814add0;
  case '\x05':
switchD_0814b0d4_caseD_5:
    local_40 = *in;
    iVar4 = asn1_check_tlen_constprop_1(0,0,&local_40,len,1,local_38);
    if (iVar4 == 0) {
      iVar4 = 0xdb;
      goto LAB_0814b1f0;
    }
    if (local_4b == '\0') {
      if ((local_3c < 0x1f) && ((it->utype & *(uint *)(tag2bit + local_3c * 4)) != 0)) {
        iVar4 = asn1_d2i_ex_primitive(it,local_3c,0,0,local_38);
        goto LAB_0814afe3;
      }
      ERR_put_error(0xd,0x78,0x8c,"tasn_dec.c",0xec);
    }
    else {
      ERR_put_error(0xd,0x78,0x8b,"tasn_dec.c",0xe4);
    }
  }
LAB_0814adaa:
  ASN1_item_ex_free(val,it);
LAB_0814adb7:
  ERR_add_error_data(2,"Type=",it->sname);
LAB_0814add0:
  pAVar3 = (ASN1_VALUE *)0x0;
LAB_0814add2:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pAVar3;
code_r0x0814b381:
  local_64 = local_64 + 1;
  iVar4 = iVar4 + 1;
  ppAVar6 = asn1_get_field_ptr(val,pAVar5);
  ASN1_template_free(ppAVar6,pAVar5);
  if (it->tcount <= iVar4) goto LAB_0814b4ea;
  goto LAB_0814b3aa;
}

