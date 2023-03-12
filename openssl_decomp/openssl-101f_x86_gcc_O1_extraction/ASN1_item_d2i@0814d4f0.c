
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ASN1_VALUE * ASN1_item_d2i(ASN1_VALUE **val,uchar **in,long len,ASN1_ITEM *it)

{
  void *pvVar1;
  uchar *puVar2;
  ASN1_VALUE *pAVar3;
  int iVar4;
  ASN1_TEMPLATE *tt;
  ASN1_VALUE **ppAVar5;
  uint uVar6;
  int iVar7;
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
    if ((byte)it->itype < 7) {
      switch(it->itype) {
      case '\0':
        goto switchD_0814d924_caseD_0;
      default:
        local_68 = (code *)0x0;
        goto switchD_0814d556_caseD_1;
      case '\x02':
        local_68 = (code *)0x0;
LAB_0814d568:
        if ((*val == (ASN1_VALUE *)0x0) && (iVar4 = ASN1_item_ex_new(val,it), iVar4 == 0)) {
          iVar4 = 0x13e;
          goto LAB_0814da10;
        }
        iVar7 = 0;
        tt = it->templates;
        local_40 = *in;
        iVar4 = it->tcount;
        if (0 < iVar4) {
          do {
            asn1_get_field_ptr(val,tt);
            iVar4 = asn1_template_ex_d2i(tt,1,local_38);
            if (iVar4 != -1) {
              if (iVar4 < 1) {
                ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",0x153);
                ASN1_item_ex_free(val,it);
                if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_0814d632;
                goto LAB_0814d95d;
              }
              iVar4 = it->tcount;
              break;
            }
            iVar4 = it->tcount;
            iVar7 = iVar7 + 1;
            tt = tt + 1;
          } while (iVar7 < iVar4);
        }
        if (iVar7 == iVar4) {
          ERR_put_error(0xd,0x78,0x8f,"tasn_dec.c",0x162);
          goto LAB_0814d625;
        }
        asn1_set_choice_selector(val,iVar7,it);
        *in = local_40;
        if (local_68 == (code *)0x0) goto LAB_0814d687;
LAB_0814d5fb:
        iVar4 = (*local_68)(5,val,it,0);
        if (iVar4 != 0) goto LAB_0814d687;
        goto LAB_0814d60a;
      case '\x03':
        goto switchD_0814d924_caseD_3;
      case '\x04':
        local_68 = _DAT_00000010;
        goto LAB_0814d8c4;
      case '\x05':
        goto switchD_0814d924_caseD_5;
      }
    }
  }
  else {
    local_68 = *(code **)((int)pvVar1 + 0x10);
    if ((byte)it->itype < 7) {
      switch(it->itype) {
      case '\0':
        goto switchD_0814d924_caseD_0;
      default:
switchD_0814d556_caseD_1:
        local_40 = *in;
        iVar4 = asn1_check_tlen(&local_4a,&local_49,&local_40,len,0x10,0,0,local_38);
        if (iVar4 == 0) {
          iVar4 = 0x17d;
LAB_0814da10:
          ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",iVar4);
        }
        else {
          if (iVar4 == -1) goto LAB_0814d650;
          if ((pvVar1 == (void *)0x0) || ((*(byte *)((int)pvVar1 + 4) & 4) == 0)) {
            local_4d = local_4a;
          }
          else {
            local_4d = '\x01';
            local_44 = (uchar *)(len - ((int)local_40 - (int)*in));
          }
          if (local_49 == '\0') {
            ERR_put_error(0xd,0x78,0x95,"tasn_dec.c",0x18c);
          }
          else {
            if ((*val == (ASN1_VALUE *)0x0) && (iVar4 = ASN1_item_ex_new(val,it), iVar4 == 0)) {
              iVar4 = 0x193;
              goto LAB_0814da10;
            }
            local_58 = local_38;
            if ((local_68 != (code *)0x0) && (iVar4 = (*local_68)(4,val,it,0), iVar4 == 0))
            goto LAB_0814d60a;
            local_64 = it->templates;
            iVar4 = 0;
            if (0 < it->tcount) {
              do {
                tt = asn1_do_adb(val,local_64,1);
                if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_0814d625;
                ppAVar5 = asn1_get_field_ptr(val,tt);
                puVar2 = local_40;
                if (local_44 == (uchar *)0x0) {
                  if (local_4a == '\0') goto LAB_0814dab1;
                  goto LAB_0814dba4;
                }
                if (((1 < (int)local_44) && (*local_40 == '\0')) && (local_40[1] == '\0')) {
                  local_40 = local_40 + 2;
                  if (local_4a == '\0') {
                    ERR_put_error(0xd,0x78,0x9f,"tasn_dec.c",0x1ac);
                    goto LAB_0814d625;
                  }
                  local_44 = local_44 + -2;
                  local_4a = '\0';
                  goto LAB_0814da9e;
                }
                uVar6 = 0;
                if (iVar4 != it->tcount + -1) {
                  uVar6 = tt->flags & 1;
                }
                iVar7 = asn1_template_ex_d2i(tt,uVar6,local_58);
                if (iVar7 == 0) goto LAB_0814dbd4;
                if (iVar7 == -1) {
                  ASN1_template_free(ppAVar5,tt);
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
LAB_0814dba4:
                ERR_put_error(0xd,0x78,0x89,"tasn_dec.c",0x1d6);
                break;
              }
              local_40 = local_40 + 2;
            }
LAB_0814da9e:
            if ((local_4d != '\0') || (local_44 == (uchar *)0x0)) {
LAB_0814dab1:
              if (iVar4 < it->tcount) {
LAB_0814dafa:
                tt = asn1_do_adb(val,local_64,1);
                if (tt != (ASN1_TEMPLATE *)0x0) {
                  if ((*(byte *)&tt->flags & 1) != 0) goto code_r0x0814dad1;
                  ERR_put_error(0xd,0x78,0x79,"tasn_dec.c",0x1f5);
LAB_0814dbd4:
                  ASN1_item_ex_free(val,it);
LAB_0814d95d:
                  ERR_add_error_data(4,"Field=",tt->field_name,", Type=",it->sname);
                  goto LAB_0814d650;
                }
                break;
              }
LAB_0814dc2e:
              iVar4 = asn1_enc_save(val,*in,(int)local_40 - (int)*in,it);
              if (iVar4 != 0) {
                *in = local_40;
                if (local_68 == (code *)0x0) {
                  pAVar3 = *val;
                  goto LAB_0814d652;
                }
                goto LAB_0814d5fb;
              }
              goto LAB_0814d60a;
            }
            ERR_put_error(0xd,0x78,0x94,"tasn_dec.c",0x1dd);
          }
        }
        break;
      case '\x02':
        if ((local_68 == (code *)0x0) || (iVar4 = (*local_68)(4,val,it,0), iVar4 != 0))
        goto LAB_0814d568;
LAB_0814d60a:
        ERR_put_error(0xd,0x78,100,"tasn_dec.c",0x205);
        break;
      case '\x03':
switchD_0814d924_caseD_3:
        iVar4 = (**(code **)((int)pvVar1 + 8))(val,in,len);
        if (iVar4 == 0) {
          iVar4 = 0x132;
          goto LAB_0814da10;
        }
LAB_0814d687:
        pAVar3 = *val;
        goto LAB_0814d652;
      case '\x04':
LAB_0814d8c4:
        iVar4 = (*local_68)(val,in,len,it,0xffffffff,0,0,local_38);
        goto LAB_0814d8db;
      case '\x05':
switchD_0814d924_caseD_5:
        local_40 = *in;
        iVar4 = asn1_check_tlen_constprop_1(0,0,&local_40,len,1,local_38);
        if (iVar4 == 0) {
          iVar4 = 0xd2;
          goto LAB_0814da10;
        }
        if (local_4b == '\0') {
          if ((local_3c < 0x1f) && ((it->utype & *(uint *)(tag2bit + local_3c * 4)) != 0)) {
            iVar4 = asn1_d2i_ex_primitive(it,local_3c,0,0,local_38);
            goto LAB_0814d8db;
          }
          ERR_put_error(0xd,0x78,0x8c,"tasn_dec.c",0xe6);
        }
        else {
          ERR_put_error(0xd,0x78,0x8b,"tasn_dec.c",0xdc);
        }
      }
LAB_0814d625:
      ASN1_item_ex_free(val,it);
LAB_0814d632:
      ERR_add_error_data(2,"Type=",it->sname);
    }
  }
  goto LAB_0814d650;
code_r0x0814dad1:
  local_64 = local_64 + 1;
  iVar4 = iVar4 + 1;
  ppAVar5 = asn1_get_field_ptr(val,tt);
  ASN1_template_free(ppAVar5,tt);
  if (it->tcount <= iVar4) goto LAB_0814dc2e;
  goto LAB_0814dafa;
switchD_0814d924_caseD_0:
  if (it->templates == (ASN1_TEMPLATE *)0x0) {
    iVar4 = asn1_d2i_ex_primitive(it,0xffffffff,0,0,local_38);
  }
  else {
    iVar4 = asn1_template_ex_d2i(it->templates,0,local_38);
  }
LAB_0814d8db:
  if (0 < iVar4) {
    pAVar3 = *val;
    goto LAB_0814d652;
  }
LAB_0814d650:
  pAVar3 = (ASN1_VALUE *)0x0;
LAB_0814d652:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pAVar3;
}

