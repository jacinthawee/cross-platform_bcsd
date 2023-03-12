
int ASN1_item_ex_d2i(ASN1_VALUE **pval,uchar **in,long len,ASN1_ITEM *it,int tag,int aclass,char opt
                    ,ASN1_TLC *ctx)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  ASN1_TEMPLATE *tt;
  ASN1_VALUE **ppAVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  byte *pbVar8;
  code *pcVar9;
  ASN1_TEMPLATE *tt_00;
  code *pcVar10;
  byte *local_4c;
  char local_48 [8];
  byte local_40 [8];
  char local_38 [8];
  byte *local_30;
  uint local_2c [2];
  
  pcVar9 = (code *)it->funcs;
  local_30 = (byte *)0x0;
  if (pval == (ASN1_VALUE **)0x0) {
    return 0;
  }
  pcVar10 = pcVar9;
  if (pcVar9 != (code *)0x0) {
    pcVar10 = *(code **)(pcVar9 + 0x10);
  }
  local_4c = (byte *)len;
  switch(it->itype) {
  case '\0':
    if (it->templates == (ASN1_TEMPLATE *)0x0) {
      iVar5 = asn1_d2i_ex_primitive(pval,in,len,it,tag,aclass,opt,ctx);
      return iVar5;
    }
    if (opt == '\0' && tag == -1) {
      iVar5 = asn1_template_ex_d2i(pval,in,len,it->templates,0,ctx);
      return iVar5;
    }
    ERR_put_error(0xd,0x78,0xaa,"tasn_dec.c",0xc0);
    goto LAB_000be5a2;
  case '\x01':
  case '\x06':
    local_30 = *in;
    if (tag == -1) {
      aclass = 0;
      tag = 0x10;
    }
    iVar3 = asn1_check_tlen(&local_4c,0,0,local_40,local_38,&local_30,len,tag,aclass,opt,ctx);
    iVar5 = 0x17d;
    if (iVar3 != 0) {
      if (iVar3 == -1) {
        return -1;
      }
      bVar2 = local_40[0];
      if ((pcVar9 != (code *)0x0) && (*(int *)(pcVar9 + 4) << 0x1d < 0)) {
        local_4c = *in + (len - (int)local_30);
        bVar2 = 1;
      }
      if (local_38[0] == '\0') {
        ERR_put_error(0xd,0x78,0x95,"tasn_dec.c",0x18c);
        goto LAB_000be5a2;
      }
      if ((*pval != (ASN1_VALUE *)0x0) || (iVar5 = ASN1_item_ex_new(pval,it), iVar5 != 0)) {
        if ((pcVar10 == (code *)0x0) || (iVar5 = (*pcVar10)(4,pval,it,0), iVar5 != 0)) {
          iVar5 = 0;
          tt_00 = it->templates;
          if (0 < it->tcount) {
            do {
              tt = asn1_do_adb(pval,tt_00,1);
              if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_000be5a2;
              ppAVar4 = asn1_get_field_ptr(pval,tt);
              pbVar8 = local_30;
              if (local_4c == (byte *)0x0) break;
              if (((1 < (int)local_4c) && (*local_30 == 0)) && (pbVar1 = local_30 + 1, *pbVar1 == 0)
                 ) {
                local_30 = local_30 + 2;
                if (local_40[0] == 0) {
                  ERR_put_error(0xd,0x78,0x9f,"tasn_dec.c",0x1ac);
                  goto LAB_000be5a2;
                }
                local_4c = local_4c + -2;
                local_40[0] = *pbVar1;
                goto LAB_000be94a;
              }
              if (it->tcount + -1 == iVar5) {
                uVar7 = 0;
              }
              else {
                uVar7 = tt->flags & 1;
              }
              iVar3 = asn1_template_ex_d2i(ppAVar4,&local_30,local_4c,tt,uVar7,ctx);
              if (iVar3 == 0) goto LAB_000be9aa;
              if (iVar3 == -1) {
                ASN1_template_free(ppAVar4,tt);
              }
              else {
                local_4c = pbVar8 + ((int)local_4c - (int)local_30);
              }
              iVar5 = iVar5 + 1;
              tt_00 = tt_00 + 1;
            } while (iVar5 < it->tcount);
          }
          if (local_40[0] != 0) {
            if ((((int)local_4c < 2) || (*local_30 != 0)) || (local_30[1] != 0)) {
              ERR_put_error(0xd,0x78,0x89,"tasn_dec.c",0x1d6);
              goto LAB_000be5a2;
            }
            local_30 = local_30 + 2;
          }
LAB_000be94a:
          if ((bVar2 == 0) && (local_4c != (byte *)0x0)) {
            ERR_put_error(0xd,0x78,0x94,"tasn_dec.c",0x1dd);
            goto LAB_000be5a2;
          }
          if (iVar5 < it->tcount) {
            do {
              iVar5 = iVar5 + 1;
              tt = asn1_do_adb(pval,tt_00,1);
              tt_00 = tt_00 + 1;
              if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_000be5a2;
              if (-1 < (int)(tt->flags << 0x1f)) {
                ERR_put_error(0xd,0x78,0x79,"tasn_dec.c",0x1f5);
LAB_000be9aa:
                ASN1_item_ex_free(pval,it);
LAB_000be9b2:
                ERR_add_error_data(4,"Field=",tt->field_name,", Type=",it->sname);
                return 0;
              }
              ppAVar4 = asn1_get_field_ptr(pval,tt);
              ASN1_template_free(ppAVar4,tt);
            } while (iVar5 < it->tcount);
          }
          iVar5 = asn1_enc_save(pval,*in,(int)local_30 - (int)*in,it);
          if (iVar5 != 0) {
            *in = local_30;
            goto joined_r0x000be76e;
          }
        }
        goto LAB_000be77e;
      }
      iVar5 = 0x193;
    }
    break;
  case '\x02':
    if ((pcVar10 != (code *)0x0) && (iVar5 = (*pcVar10)(4,pval,it,0), iVar5 == 0))
    goto LAB_000be77e;
    if (*pval == (ASN1_VALUE *)0x0) {
      iVar3 = ASN1_item_ex_new(pval,it);
      iVar5 = 0x13e;
      if (iVar3 == 0) break;
    }
    iVar5 = it->tcount;
    local_30 = *in;
    tt = it->templates;
    if (iVar5 < 1) {
      iVar3 = 0;
    }
    else {
      iVar3 = 0;
      do {
        ppAVar4 = asn1_get_field_ptr(pval,tt);
        iVar5 = asn1_template_ex_d2i(ppAVar4,&local_30,local_4c,tt,1,ctx);
        if (iVar5 != -1) {
          if (iVar5 < 1) {
            ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",0x153);
            ASN1_item_ex_free(pval,it);
            if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_000be5aa;
            goto LAB_000be9b2;
          }
          iVar5 = it->tcount;
          break;
        }
        iVar5 = it->tcount;
        iVar3 = iVar3 + 1;
        tt = tt + 1;
      } while (iVar3 < iVar5);
    }
    if (iVar3 == iVar5) {
      if (opt != '\0') {
        ASN1_item_ex_free(pval,it);
        return -1;
      }
      ERR_put_error(0xd,0x78,0x8f,"tasn_dec.c",0x162);
      goto LAB_000be5a2;
    }
    asn1_set_choice_selector(pval,iVar3,it);
    *in = local_30;
joined_r0x000be76e:
    if (pcVar10 == (code *)0x0) {
      return 1;
    }
    iVar5 = (*pcVar10)(5,pval,it,0);
    if (iVar5 != 0) {
      return 1;
    }
LAB_000be77e:
    ERR_put_error(0xd,0x78,100,"tasn_dec.c",0x205);
    goto LAB_000be5a2;
  case '\x03':
    if (opt != '\0') {
      local_30 = *in;
      lVar6 = tag;
      if (tag == -1) {
        lVar6 = it->utype;
      }
      iVar3 = asn1_check_tlen(0,0,0,0,0,&local_30,len,lVar6,aclass,1,ctx);
      iVar5 = 0x106;
      if (iVar3 == 0) break;
      if (iVar3 == -1) {
        return -1;
      }
    }
    if (tag == -1) {
      iVar5 = (**(code **)(pcVar9 + 8))(pval,in,local_4c);
    }
    else {
      pbVar8 = *in;
      bVar2 = *pbVar8;
      if (local_30 == (byte *)0x0) {
        iVar5 = 0x123;
        break;
      }
      *pbVar8 = (byte)it->utype | *local_30 & 0x20;
      iVar5 = (**(code **)(pcVar9 + 8))(pval,in,local_4c);
      *pbVar8 = bVar2;
    }
    if (iVar5 != 0) {
      return 1;
    }
    iVar5 = 0x132;
    break;
  case '\x04':
    iVar5 = (**(code **)(pcVar9 + 0x10))(pval,in,len,it,tag,aclass,opt,ctx);
    return iVar5;
  case '\x05':
    local_30 = *in;
    iVar3 = asn1_check_tlen_constprop_1(0,local_2c,local_48,0,0,&local_30,len,1,ctx);
    iVar5 = 0xd2;
    if (iVar3 != 0) {
      if (local_48[0] == '\0') {
        if ((local_2c[0] < 0x1f) && ((*(uint *)(&tag2bit + local_2c[0] * 4) & it->utype) != 0)) {
          iVar5 = asn1_d2i_ex_primitive(pval,in,local_4c,it,local_2c[0],0,0,ctx);
          return iVar5;
        }
        if (opt != '\0') {
          return -1;
        }
        ERR_put_error(0xd,0x78,0x8c,"tasn_dec.c",0xe6);
      }
      else {
        if (opt != '\0') {
          return -1;
        }
        ERR_put_error(0xd,0x78,0x8b,"tasn_dec.c",0xdc);
      }
      goto LAB_000be5a2;
    }
    break;
  default:
    return 0;
  }
  ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",iVar5);
LAB_000be5a2:
  ASN1_item_ex_free(pval,it);
LAB_000be5aa:
  ERR_add_error_data(2,"Type=",it->sname);
  return 0;
}

