
ASN1_VALUE * ASN1_item_d2i(ASN1_VALUE **val,uchar **in,long len,ASN1_ITEM *it)

{
  uchar *puVar1;
  uchar uVar2;
  uchar *puVar3;
  int iVar4;
  ASN1_TEMPLATE *tt;
  ASN1_VALUE **ppAVar5;
  int iVar6;
  uint uVar7;
  code *pcVar8;
  ASN1_TEMPLATE *tt_00;
  code *pcVar9;
  char local_70 [8];
  uchar local_68 [8];
  char local_60 [8];
  uchar *local_58 [2];
  uchar *local_50 [2];
  ASN1_VALUE *local_48;
  uint local_44;
  undefined local_40 [28];
  
  local_48 = (ASN1_VALUE *)0x0;
  if (val == (ASN1_VALUE **)0x0) {
    val = &local_48;
  }
  pcVar8 = (code *)it->funcs;
  local_40[0] = 0;
  local_50[0] = (uchar *)0x0;
  pcVar9 = pcVar8;
  if (pcVar8 != (code *)0x0) {
    pcVar9 = *(code **)(pcVar8 + 0x10);
  }
  local_58[0] = (uchar *)len;
  switch(it->itype) {
  case '\0':
    if (it->templates == (ASN1_TEMPLATE *)0x0) {
      iVar6 = asn1_d2i_ex_primitive(val,in,len,it,0xffffffff,0,0,local_40);
    }
    else {
      iVar6 = asn1_template_ex_d2i(val,in,len,it->templates,0,local_40);
    }
    goto LAB_000becba;
  case '\x01':
  case '\x06':
    local_50[0] = *in;
    iVar4 = asn1_check_tlen(local_58,0,0,local_68,local_60,local_50,len,0x10,0,0,local_40);
    iVar6 = 0x17d;
    if (iVar4 == 0) goto LAB_000bedec;
    if (iVar4 == -1) {
      return (ASN1_VALUE *)0x0;
    }
    uVar2 = local_68[0];
    if ((pcVar8 != (code *)0x0) && (*(int *)(pcVar8 + 4) << 0x1d < 0)) {
      local_58[0] = *in + (len - (int)local_50[0]);
      uVar2 = '\x01';
    }
    if (local_60[0] == '\0') {
      ERR_put_error(0xd,0x78,0x95,"tasn_dec.c",0x18c);
    }
    else {
      if ((*val == (ASN1_VALUE *)0x0) && (iVar6 = ASN1_item_ex_new(val,it), iVar6 == 0)) {
        iVar6 = 0x193;
        goto LAB_000bedec;
      }
      if ((pcVar9 != (code *)0x0) && (iVar6 = (*pcVar9)(4,val,it,0), iVar6 == 0)) goto LAB_000bebfc;
      iVar6 = 0;
      tt_00 = it->templates;
      if (0 < it->tcount) {
        do {
          tt = asn1_do_adb(val,tt_00,1);
          if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_000bec14;
          ppAVar5 = asn1_get_field_ptr(val,tt);
          puVar3 = local_50[0];
          if (local_58[0] == (uchar *)0x0) break;
          if (((1 < (int)local_58[0]) && (*local_50[0] == '\0')) &&
             (puVar1 = local_50[0] + 1, *puVar1 == '\0')) {
            local_50[0] = local_50[0] + 2;
            if (local_68[0] == '\0') {
              ERR_put_error(0xd,0x78,0x9f,"tasn_dec.c",0x1ac);
              goto LAB_000bec14;
            }
            local_58[0] = local_58[0] + -2;
            local_68[0] = *puVar1;
            goto LAB_000beec2;
          }
          if (it->tcount + -1 == iVar6) {
            uVar7 = 0;
          }
          else {
            uVar7 = tt->flags & 1;
          }
          iVar4 = asn1_template_ex_d2i(ppAVar5,local_50,local_58[0],tt,uVar7,local_40);
          if (iVar4 == 0) goto LAB_000befe4;
          if (iVar4 == -1) {
            ASN1_template_free(ppAVar5,tt);
          }
          else {
            local_58[0] = puVar3 + ((int)local_58[0] - (int)local_50[0]);
          }
          iVar6 = iVar6 + 1;
          tt_00 = tt_00 + 1;
        } while (iVar6 < it->tcount);
      }
      if (local_68[0] != '\0') {
        if ((((int)local_58[0] < 2) || (*local_50[0] != '\0')) || (local_50[0][1] != '\0')) {
          ERR_put_error(0xd,0x78,0x89,"tasn_dec.c",0x1d6);
          break;
        }
        local_50[0] = local_50[0] + 2;
      }
LAB_000beec2:
      if ((uVar2 != '\0') || (local_58[0] == (uchar *)0x0)) {
        while (iVar6 < it->tcount) {
          iVar6 = iVar6 + 1;
          tt = asn1_do_adb(val,tt_00,1);
          tt_00 = tt_00 + 1;
          if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_000bec14;
          if (-1 < (int)(tt->flags << 0x1f)) {
            ERR_put_error(0xd,0x78,0x79,"tasn_dec.c",0x1f5);
LAB_000befe4:
            ASN1_item_ex_free(val,it);
LAB_000bef8e:
            ERR_add_error_data(4,"Field=",tt->field_name,", Type=",it->sname);
            return (ASN1_VALUE *)0x0;
          }
          ppAVar5 = asn1_get_field_ptr(val,tt);
          ASN1_template_free(ppAVar5,tt);
        }
        iVar6 = asn1_enc_save(val,*in,(int)local_50[0] - (int)*in,it);
        if (iVar6 == 0) goto LAB_000bebfc;
        *in = local_50[0];
        goto joined_r0x000bebec;
      }
      ERR_put_error(0xd,0x78,0x94,"tasn_dec.c",0x1dd);
    }
    break;
  case '\x02':
    if ((pcVar9 == (code *)0x0) || (iVar6 = (*pcVar9)(4,val,it,0), iVar6 != 0)) {
      if (*val == (ASN1_VALUE *)0x0) {
        iVar4 = ASN1_item_ex_new(val,it);
        iVar6 = 0x13e;
        if (iVar4 == 0) goto LAB_000bedec;
      }
      iVar6 = it->tcount;
      local_50[0] = *in;
      tt = it->templates;
      if (iVar6 < 1) {
        iVar4 = 0;
      }
      else {
        iVar4 = 0;
        do {
          ppAVar5 = asn1_get_field_ptr(val,tt);
          iVar6 = asn1_template_ex_d2i(ppAVar5,local_50,local_58[0],tt,1,local_40);
          if (iVar6 != -1) {
            if (iVar6 < 1) {
              ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",0x153);
              ASN1_item_ex_free(val,it);
              if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_000bec1c;
              goto LAB_000bef8e;
            }
            iVar6 = it->tcount;
            break;
          }
          iVar6 = it->tcount;
          iVar4 = iVar4 + 1;
          tt = tt + 1;
        } while (iVar4 < iVar6);
      }
      if (iVar4 == iVar6) {
        ERR_put_error(0xd,0x78,0x8f,"tasn_dec.c",0x162);
        break;
      }
      asn1_set_choice_selector(val,iVar4,it);
      *in = local_50[0];
joined_r0x000bebec:
      if ((pcVar9 == (code *)0x0) || (iVar6 = (*pcVar9)(5,val,it,0), iVar6 != 0)) goto LAB_000becbe;
    }
LAB_000bebfc:
    ERR_put_error(0xd,0x78,100,"tasn_dec.c",0x205);
    break;
  case '\x03':
    iVar4 = (**(code **)(pcVar8 + 8))(val,in,len);
    iVar6 = 0x132;
    if (iVar4 != 0) goto LAB_000becbe;
LAB_000bedec:
    ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",iVar6);
    break;
  case '\x04':
    iVar6 = (**(code **)(pcVar8 + 0x10))(val,in,len,it,0xffffffff,0,0,local_40);
LAB_000becba:
    if (iVar6 < 1) {
      return (ASN1_VALUE *)0x0;
    }
LAB_000becbe:
    return *val;
  case '\x05':
    local_50[0] = *in;
    iVar4 = asn1_check_tlen_constprop_1(0,&local_44,local_70,0,0,local_50,len,1,local_40);
    iVar6 = 0xd2;
    if (iVar4 == 0) goto LAB_000bedec;
    if (local_70[0] == '\0') {
      if ((local_44 < 0x1f) && ((it->utype & *(uint *)(&tag2bit + local_44 * 4)) != 0)) {
        iVar6 = asn1_d2i_ex_primitive(val,in,local_58[0],it,local_44,0,0,local_40);
        goto LAB_000becba;
      }
      ERR_put_error(0xd,0x78,0x8c,"tasn_dec.c",0xe6);
    }
    else {
      ERR_put_error(0xd,0x78,0x8b,"tasn_dec.c",0xdc);
    }
    break;
  default:
    goto switchD_000beb60_caseD_7;
  }
LAB_000bec14:
  ASN1_item_ex_free(val,it);
LAB_000bec1c:
  ERR_add_error_data(2,"Type=",it->sname);
switchD_000beb60_caseD_7:
  return (ASN1_VALUE *)0x0;
}

