
ASN1_VALUE * ASN1_item_d2i(ASN1_VALUE **val,uchar **in,long len,ASN1_ITEM *it)

{
  uchar *puVar1;
  uchar uVar2;
  uchar *puVar3;
  int iVar4;
  ASN1_TEMPLATE *pAVar5;
  ASN1_VALUE **ppAVar6;
  int iVar7;
  uint uVar8;
  code *pcVar9;
  ASN1_TEMPLATE *tt;
  code *pcVar10;
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
  pcVar9 = (code *)it->funcs;
  local_40[0] = 0;
  local_50[0] = (uchar *)0x0;
  pcVar10 = pcVar9;
  if (pcVar9 != (code *)0x0) {
    pcVar10 = *(code **)(pcVar9 + 0x10);
  }
  local_58[0] = (uchar *)len;
  switch(it->itype) {
  case '\0':
    if (it->templates == (ASN1_TEMPLATE *)0x0) {
      iVar4 = asn1_d2i_ex_primitive(val,in,len,it,0xffffffff,0,0,local_40);
    }
    else {
      iVar4 = asn1_template_ex_d2i(val,in,len,it->templates,0,local_40);
    }
    goto LAB_000bc4e0;
  case '\x01':
  case '\x06':
    local_50[0] = *in;
    iVar4 = asn1_check_tlen(local_58,0,0,local_68,local_60,local_50,len,0x10,0,0,local_40);
    iVar7 = 0x176;
    if (iVar4 == 0) goto LAB_000bc5c0;
    if (iVar4 == -1) {
      return (ASN1_VALUE *)0x0;
    }
    uVar2 = local_68[0];
    if ((pcVar9 != (code *)0x0) && (*(int *)(pcVar9 + 4) << 0x1d < 0)) {
      local_58[0] = *in + (len - (int)local_50[0]);
      uVar2 = '\x01';
    }
    if (local_60[0] == '\0') {
      ERR_put_error(0xd,0x78,0x95,"tasn_dec.c",0x182);
    }
    else {
      if ((*val == (ASN1_VALUE *)0x0) && (iVar4 = ASN1_item_ex_new(val,it), iVar4 == 0)) {
        iVar7 = 0x187;
        goto LAB_000bc5c0;
      }
      if ((pcVar10 != (code *)0x0) && (iVar4 = (*pcVar10)(4,val,it,0), iVar4 == 0))
      goto LAB_000bc422;
      iVar4 = it->tcount;
      tt = it->templates;
      if (iVar4 < 1) {
        iVar7 = 0;
      }
      else {
        iVar7 = 0;
        do {
          iVar7 = iVar7 + 1;
          if ((tt->flags & 0x300) != 0) {
            pAVar5 = asn1_do_adb(val,tt,1);
            ppAVar6 = asn1_get_field_ptr(val,pAVar5);
            ASN1_template_free(ppAVar6,pAVar5);
            iVar4 = it->tcount;
          }
          tt = tt + 1;
        } while (iVar7 < iVar4);
        tt = it->templates;
        iVar7 = 0;
        if (0 < iVar4) {
          do {
            pAVar5 = asn1_do_adb(val,tt,1);
            if (pAVar5 == (ASN1_TEMPLATE *)0x0) goto LAB_000bc43a;
            ppAVar6 = asn1_get_field_ptr(val,pAVar5);
            puVar3 = local_50[0];
            if (local_58[0] == (uchar *)0x0) break;
            if (((1 < (int)local_58[0]) && (*local_50[0] == '\0')) &&
               (puVar1 = local_50[0] + 1, *puVar1 == '\0')) {
              local_50[0] = local_50[0] + 2;
              if (local_68[0] == '\0') {
                ERR_put_error(0xd,0x78,0x9f,"tasn_dec.c",0x1a7);
                goto LAB_000bc43a;
              }
              local_58[0] = local_58[0] + -2;
              local_68[0] = *puVar1;
              goto LAB_000bc7ce;
            }
            if (it->tcount + -1 == iVar7) {
              uVar8 = 0;
            }
            else {
              uVar8 = pAVar5->flags & 1;
            }
            iVar4 = asn1_template_ex_d2i(ppAVar6,local_50,local_58[0],pAVar5,uVar8,local_40);
            if (iVar4 == 0) goto LAB_000bc8fe;
            if (iVar4 == -1) {
              ASN1_template_free(ppAVar6,pAVar5);
            }
            else {
              local_58[0] = puVar3 + ((int)local_58[0] - (int)local_50[0]);
            }
            iVar7 = iVar7 + 1;
            tt = tt + 1;
          } while (iVar7 < it->tcount);
        }
      }
      if (local_68[0] != '\0') {
        if ((((int)local_58[0] < 2) || (*local_50[0] != '\0')) || (local_50[0][1] != '\0')) {
          ERR_put_error(0xd,0x78,0x89,"tasn_dec.c",0x1ce);
          break;
        }
        local_50[0] = local_50[0] + 2;
      }
LAB_000bc7ce:
      if ((uVar2 != '\0') || (local_58[0] == (uchar *)0x0)) {
        while (iVar7 < it->tcount) {
          iVar7 = iVar7 + 1;
          pAVar5 = asn1_do_adb(val,tt,1);
          tt = tt + 1;
          if (pAVar5 == (ASN1_TEMPLATE *)0x0) goto LAB_000bc43a;
          if (-1 < (int)(pAVar5->flags << 0x1f)) {
            ERR_put_error(0xd,0x78,0x79,"tasn_dec.c",0x1e7);
LAB_000bc8fe:
            ASN1_item_ex_free(val,it);
LAB_000bc8a8:
            ERR_add_error_data(4,"Field=",pAVar5->field_name,", Type=",it->sname);
            return (ASN1_VALUE *)0x0;
          }
          ppAVar6 = asn1_get_field_ptr(val,pAVar5);
          ASN1_template_free(ppAVar6,pAVar5);
        }
        iVar4 = asn1_enc_save(val,*in,(int)local_50[0] - (int)*in,it);
        if (iVar4 == 0) goto LAB_000bc422;
        goto joined_r0x000bc65e;
      }
      ERR_put_error(0xd,0x78,0x94,"tasn_dec.c",0x1d3);
    }
    break;
  case '\x02':
    if ((pcVar10 == (code *)0x0) || (iVar4 = (*pcVar10)(4,val,it,0), iVar4 != 0)) {
      if (*val == (ASN1_VALUE *)0x0) {
        iVar4 = ASN1_item_ex_new(val,it);
        if (iVar4 == 0) {
          iVar7 = 0x13f;
          goto LAB_000bc5c0;
        }
        iVar4 = it->tcount;
      }
      else {
        iVar7 = asn1_get_choice_selector(val,it);
        iVar4 = it->tcount;
        if ((-1 < iVar7) && (iVar7 < iVar4)) {
          pAVar5 = it->templates;
          ppAVar6 = asn1_get_field_ptr(val,pAVar5 + iVar7);
          ASN1_template_free(ppAVar6,pAVar5 + iVar7);
          asn1_set_choice_selector(val,-1,it);
          iVar4 = it->tcount;
        }
      }
      local_50[0] = *in;
      pAVar5 = it->templates;
      if (iVar4 < 1) {
        iVar7 = 0;
      }
      else {
        iVar7 = 0;
        do {
          ppAVar6 = asn1_get_field_ptr(val,pAVar5);
          iVar4 = asn1_template_ex_d2i(ppAVar6,local_50,local_58[0],pAVar5,1,local_40);
          if (iVar4 != -1) {
            if (iVar4 < 1) {
              ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",0x152);
              ASN1_item_ex_free(val,it);
              if (pAVar5 == (ASN1_TEMPLATE *)0x0) goto LAB_000bc442;
              goto LAB_000bc8a8;
            }
            iVar4 = it->tcount;
            break;
          }
          iVar4 = it->tcount;
          iVar7 = iVar7 + 1;
          pAVar5 = pAVar5 + 1;
        } while (iVar7 < iVar4);
      }
      if (iVar7 == iVar4) {
        ERR_put_error(0xd,0x78,0x8f,"tasn_dec.c",0x15e);
        break;
      }
      asn1_set_choice_selector(val,iVar7,it);
joined_r0x000bc65e:
      if ((pcVar10 == (code *)0x0) || (iVar4 = (*pcVar10)(5,val,it,0), iVar4 != 0)) {
        *in = local_50[0];
        goto LAB_000bc4e4;
      }
    }
LAB_000bc422:
    ERR_put_error(0xd,0x78,100,"tasn_dec.c",0x1f7);
    break;
  case '\x03':
    iVar4 = (**(code **)(pcVar9 + 8))(val,in,len);
    iVar7 = 0x12f;
    if (iVar4 != 0) goto LAB_000bc4e4;
LAB_000bc5c0:
    ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",iVar7);
    break;
  case '\x04':
    iVar4 = (**(code **)(pcVar9 + 0x10))(val,in,len,it,0xffffffff,0,0,local_40);
LAB_000bc4e0:
    if (iVar4 < 1) {
      return (ASN1_VALUE *)0x0;
    }
LAB_000bc4e4:
    return *val;
  case '\x05':
    local_50[0] = *in;
    iVar4 = asn1_check_tlen_constprop_1(0,&local_44,local_70,0,0,local_50,len,1,local_40);
    iVar7 = 0xdb;
    if (iVar4 == 0) goto LAB_000bc5c0;
    if (local_70[0] == '\0') {
      if ((local_44 < 0x1f) && ((it->utype & *(uint *)(&tag2bit + local_44 * 4)) != 0)) {
        iVar4 = asn1_d2i_ex_primitive(val,in,local_58[0],it,local_44,0,0,local_40);
        goto LAB_000bc4e0;
      }
      ERR_put_error(0xd,0x78,0x8c,"tasn_dec.c",0xec);
    }
    else {
      ERR_put_error(0xd,0x78,0x8b,"tasn_dec.c",0xe4);
    }
    break;
  default:
    goto switchD_000bc3f8_caseD_7;
  }
LAB_000bc43a:
  ASN1_item_ex_free(val,it);
LAB_000bc442:
  ERR_add_error_data(2,"Type=",it->sname);
switchD_000bc3f8_caseD_7:
  return (ASN1_VALUE *)0x0;
}

