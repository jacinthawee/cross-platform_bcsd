
int ASN1_item_ex_d2i(ASN1_VALUE **pval,uchar **in,long len,ASN1_ITEM *it,int tag,int aclass,char opt
                    ,ASN1_TLC *ctx)

{
  byte bVar1;
  ASN1_TEMPLATE *pAVar2;
  int iVar3;
  ASN1_VALUE **ppAVar4;
  long lVar5;
  ASN1_TEMPLATE *pAVar6;
  ASN1_TEMPLATE *pAVar7;
  byte *pbVar8;
  code *pcVar9;
  int iVar10;
  code *pcVar11;
  uint uVar12;
  ASN1_TEMPLATE *local_58;
  uchar *local_4c;
  char local_48 [8];
  byte local_40 [8];
  byte local_38 [8];
  ASN1_TEMPLATE *local_30;
  uint local_2c [2];
  
  uVar12 = aclass & 0xfffffbff;
  pcVar9 = (code *)it->funcs;
  local_30 = (ASN1_TEMPLATE *)0x0;
  pAVar6 = (ASN1_TEMPLATE *)(uint)(byte)opt;
  if (pval == (ASN1_VALUE **)0x0) {
    return 0;
  }
  pcVar11 = pcVar9;
  if (pcVar9 != (code *)0x0) {
    pcVar11 = *(code **)(pcVar9 + 0x10);
  }
  local_4c = (uchar *)len;
  switch(it->itype) {
  case '\0':
    if (it->templates == (ASN1_TEMPLATE *)0x0) {
      iVar3 = asn1_d2i_ex_primitive(pval,in,len,it,tag,uVar12,pAVar6,ctx);
      return iVar3;
    }
    if (pAVar6 == (ASN1_TEMPLATE *)0x0 && tag == -1) {
      iVar3 = asn1_template_ex_d2i(pval,in,len,it->templates,0,ctx);
      return iVar3;
    }
    pAVar6 = (ASN1_TEMPLATE *)0x0;
    ERR_put_error(0xd,0x78,0xaa,"tasn_dec.c",0xcb);
    goto LAB_000bbdb6;
  case '\x01':
  case '\x06':
    local_30 = (ASN1_TEMPLATE *)*in;
    if (tag == -1) {
      tag = 0x10;
      uVar12 = 0;
    }
    pAVar6 = (ASN1_TEMPLATE *)
             asn1_check_tlen(&local_4c,0,0,local_40,local_38,&local_30,len,tag,uVar12,pAVar6,ctx);
    if (pAVar6 == (ASN1_TEMPLATE *)0x0) {
      ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",0x176);
      goto LAB_000bbdb6;
    }
    if (pAVar6 == (ASN1_TEMPLATE *)0xffffffff) {
      return -1;
    }
    if ((pcVar9 == (code *)0x0) || (-1 < *(int *)(pcVar9 + 4) << 0x1d)) {
      local_58 = (ASN1_TEMPLATE *)(uint)local_40[0];
    }
    else {
      local_58 = (ASN1_TEMPLATE *)0x1;
      local_4c = *in + (len - (int)local_30);
    }
    pAVar6 = (ASN1_TEMPLATE *)(uint)local_38[0];
    if (pAVar6 == (ASN1_TEMPLATE *)0x0) {
      ERR_put_error(0xd,0x78,0x95,"tasn_dec.c",0x182);
      goto LAB_000bbdb6;
    }
    if (*pval == (ASN1_VALUE *)0x0) {
      pAVar7 = (ASN1_TEMPLATE *)ASN1_item_ex_new(pval,it);
      iVar3 = 0x187;
      if (pAVar7 == (ASN1_TEMPLATE *)0x0) goto LAB_000bc054;
    }
    if ((pcVar11 == (code *)0x0) || (iVar3 = (*pcVar11)(4,pval,it,0), iVar3 != 0)) {
      iVar3 = it->tcount;
      pAVar7 = it->templates;
      if (iVar3 < 1) {
        iVar10 = 0;
      }
      else {
        iVar10 = 0;
        do {
          iVar10 = iVar10 + 1;
          if ((pAVar7->flags & 0x300) != 0) {
            pAVar6 = asn1_do_adb(pval,pAVar7,1);
            ppAVar4 = asn1_get_field_ptr(pval,pAVar6);
            ASN1_template_free(ppAVar4,pAVar6);
            iVar3 = it->tcount;
          }
          pAVar7 = pAVar7 + 1;
        } while (iVar10 < iVar3);
        pAVar7 = it->templates;
        iVar10 = 0;
        if (0 < iVar3) {
          do {
            pAVar6 = asn1_do_adb(pval,pAVar7,1);
            if (pAVar6 == (ASN1_TEMPLATE *)0x0) goto LAB_000bc27c;
            ppAVar4 = asn1_get_field_ptr(pval,pAVar6);
            pAVar2 = local_30;
            if (local_4c == (uchar *)0x0) break;
            if (((1 < (int)local_4c) && (*(char *)&local_30->flags == '\0')) &&
               (bVar1 = *(byte *)((int)&local_30->flags + 1), bVar1 == 0)) {
              pAVar6 = (ASN1_TEMPLATE *)(uint)local_40[0];
              local_30 = (ASN1_TEMPLATE *)((int)&local_30->flags + 2);
              if (pAVar6 == (ASN1_TEMPLATE *)0x0) {
                ERR_put_error(0xd,0x78,0x9f,"tasn_dec.c",0x1a7);
                goto LAB_000bbdb6;
              }
              local_4c = local_4c + -2;
              local_40[0] = bVar1;
              goto LAB_000bc236;
            }
            if (it->tcount + -1 == iVar10) {
              uVar12 = 0;
            }
            else {
              uVar12 = pAVar6->flags & 1;
            }
            iVar3 = asn1_template_ex_d2i(ppAVar4,&local_30,local_4c,pAVar6,uVar12,ctx);
            if (iVar3 == 0) goto LAB_000bbdb6;
            if (iVar3 == -1) {
              ASN1_template_free(ppAVar4,pAVar6);
            }
            else {
              local_4c = (uchar *)((int)pAVar2 + ((int)local_4c - (int)local_30));
            }
            iVar10 = iVar10 + 1;
            pAVar7 = pAVar7 + 1;
          } while (iVar10 < it->tcount);
        }
      }
      if (local_40[0] != 0) {
        if ((((int)local_4c < 2) || (*(char *)&local_30->flags != '\0')) ||
           (*(char *)((int)&local_30->flags + 1) != '\0')) {
          pAVar6 = (ASN1_TEMPLATE *)0x0;
          ERR_put_error(0xd,0x78,0x89,"tasn_dec.c",0x1ce);
          goto LAB_000bbdb6;
        }
        local_30 = (ASN1_TEMPLATE *)((int)&local_30->flags + 2);
      }
LAB_000bc236:
      if ((local_58 == (ASN1_TEMPLATE *)0x0) && (local_4c != (uchar *)0x0)) {
        ERR_put_error(0xd,0x78,0x94,"tasn_dec.c",0x1d3);
        pAVar6 = local_58;
        goto LAB_000bbdb6;
      }
      if (iVar10 < it->tcount) {
        do {
          iVar10 = iVar10 + 1;
          pAVar6 = asn1_do_adb(pval,pAVar7,1);
          pAVar7 = pAVar7 + 1;
          if (pAVar6 == (ASN1_TEMPLATE *)0x0) goto LAB_000bc27c;
          if (-1 < (int)(pAVar6->flags << 0x1f)) {
            ERR_put_error(0xd,0x78,0x79,"tasn_dec.c",0x1e7);
            goto LAB_000bbdb6;
          }
          ppAVar4 = asn1_get_field_ptr(pval,pAVar6);
          ASN1_template_free(ppAVar4,pAVar6);
        } while (iVar10 < it->tcount);
      }
      iVar3 = asn1_enc_save(pval,*in,(int)local_30 - (int)*in,it);
      if (iVar3 != 0) goto joined_r0x000bbf8a;
    }
    break;
  case '\x02':
    if ((pcVar11 == (code *)0x0) || (iVar3 = (*pcVar11)(4,pval,it,0), iVar3 != 0)) {
      if (*pval == (ASN1_VALUE *)0x0) {
        pAVar7 = (ASN1_TEMPLATE *)ASN1_item_ex_new(pval,it);
        if (pAVar7 == (ASN1_TEMPLATE *)0x0) {
          iVar3 = 0x13f;
          goto LAB_000bc054;
        }
        iVar3 = it->tcount;
      }
      else {
        iVar10 = asn1_get_choice_selector(pval,it);
        iVar3 = it->tcount;
        if ((-1 < iVar10) && (iVar10 < iVar3)) {
          pAVar7 = it->templates;
          ppAVar4 = asn1_get_field_ptr(pval,pAVar7 + iVar10);
          ASN1_template_free(ppAVar4,pAVar7 + iVar10);
          asn1_set_choice_selector(pval,-1,it);
          iVar3 = it->tcount;
        }
      }
      local_30 = (ASN1_TEMPLATE *)*in;
      pAVar7 = it->templates;
      if (iVar3 < 1) {
        iVar10 = 0;
      }
      else {
        iVar10 = 0;
        do {
          ppAVar4 = asn1_get_field_ptr(pval,pAVar7);
          iVar3 = asn1_template_ex_d2i(ppAVar4,&local_30,local_4c,pAVar7,1,ctx);
          if (iVar3 != -1) {
            if (iVar3 < 1) {
              iVar3 = 0x152;
              goto LAB_000bc054;
            }
            iVar3 = it->tcount;
            break;
          }
          iVar3 = it->tcount;
          iVar10 = iVar10 + 1;
          pAVar7 = pAVar7 + 1;
        } while (iVar10 < iVar3);
      }
      if (iVar10 == iVar3) {
        if (pAVar6 != (ASN1_TEMPLATE *)0x0) {
          ASN1_item_ex_free(pval,it);
          return -1;
        }
        ERR_put_error(0xd,0x78,0x8f,"tasn_dec.c",0x15e);
        goto LAB_000bbdb6;
      }
      asn1_set_choice_selector(pval,iVar10,it);
joined_r0x000bbf8a:
      if ((pcVar11 == (code *)0x0) || (iVar3 = (*pcVar11)(5,pval,it,0), iVar3 != 0)) {
        *in = (uchar *)local_30;
        return 1;
      }
    }
    break;
  case '\x03':
    if (pAVar6 != (ASN1_TEMPLATE *)0x0) {
      local_30 = (ASN1_TEMPLATE *)*in;
      lVar5 = tag;
      if (tag == -1) {
        lVar5 = it->utype;
      }
      pAVar7 = (ASN1_TEMPLATE *)asn1_check_tlen(0,0,0,0,0,&local_30,len,lVar5,uVar12,1,ctx);
      if (pAVar7 == (ASN1_TEMPLATE *)0x0) {
        iVar3 = 0x109;
        goto LAB_000bc054;
      }
      if (pAVar7 == (ASN1_TEMPLATE *)0xffffffff) {
        return -1;
      }
    }
    if (tag == -1) {
      pAVar7 = (ASN1_TEMPLATE *)(**(code **)(pcVar9 + 8))(pval,in,local_4c);
    }
    else {
      pbVar8 = *in;
      iVar3 = 0x120;
      bVar1 = *pbVar8;
      pAVar7 = local_30;
      if (local_30 == (ASN1_TEMPLATE *)0x0) goto LAB_000bc054;
      *pbVar8 = (byte)it->utype | *(byte *)&local_30->flags & 0x20;
      pAVar7 = (ASN1_TEMPLATE *)(**(code **)(pcVar9 + 8))(pval,in,local_4c);
      *pbVar8 = bVar1;
    }
    iVar3 = 0x12f;
    if (pAVar7 != (ASN1_TEMPLATE *)0x0) {
      return 1;
    }
    goto LAB_000bc054;
  case '\x04':
    iVar3 = (**(code **)(pcVar9 + 0x10))(pval,in,len,it,tag,uVar12,pAVar6,ctx);
    return iVar3;
  case '\x05':
    local_30 = (ASN1_TEMPLATE *)*in;
    pAVar7 = (ASN1_TEMPLATE *)
             asn1_check_tlen_constprop_1(0,local_2c,local_48,0,0,&local_30,len,1,ctx);
    iVar3 = 0xdb;
    if (pAVar7 != (ASN1_TEMPLATE *)0x0) {
      if (local_48[0] == '\0') {
        if ((local_2c[0] < 0x1f) && ((*(uint *)(&tag2bit + local_2c[0] * 4) & it->utype) != 0)) {
          iVar3 = asn1_d2i_ex_primitive(pval,in,local_4c,it,local_2c[0],0,0,ctx);
          return iVar3;
        }
        if (pAVar6 != (ASN1_TEMPLATE *)0x0) {
          return -1;
        }
        ERR_put_error(0xd,0x78,0x8c,"tasn_dec.c",0xec);
      }
      else {
        if (pAVar6 != (ASN1_TEMPLATE *)0x0) {
          return -1;
        }
        ERR_put_error(0xd,0x78,0x8b,"tasn_dec.c",0xe4);
      }
      goto LAB_000bbdb6;
    }
LAB_000bc054:
    pAVar6 = pAVar7;
    ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",iVar3);
    goto LAB_000bbdb6;
  default:
    return 0;
  }
  ERR_put_error(0xd,0x78,100,"tasn_dec.c",0x1f7);
  pAVar6 = (ASN1_TEMPLATE *)0x0;
LAB_000bbdb6:
  if (-1 < aclass << 0x15) {
    ASN1_item_ex_free(pval,it);
  }
  if (pAVar6 == (ASN1_TEMPLATE *)0x0) {
    ERR_add_error_data(2,"Type=",it->sname);
  }
  else {
    ERR_add_error_data(4,"Field=",pAVar6->field_name,", Type=",it->sname);
    pAVar6 = (ASN1_TEMPLATE *)0x0;
  }
  return (int)pAVar6;
LAB_000bc27c:
  pAVar6 = (ASN1_TEMPLATE *)0x0;
  goto LAB_000bbdb6;
}

