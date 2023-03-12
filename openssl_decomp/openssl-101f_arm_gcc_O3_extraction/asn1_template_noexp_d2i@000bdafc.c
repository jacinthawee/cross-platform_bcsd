
undefined4
asn1_template_noexp_d2i
          (_STACK **param_1,uchar **param_2,uchar *param_3,ASN1_TEMPLATE *param_4,char param_5,
          ASN1_TLC *param_6)

{
  uchar *puVar1;
  uchar uVar2;
  uchar *puVar3;
  uchar *puVar4;
  int iVar5;
  ASN1_TEMPLATE *tt;
  ASN1_VALUE **ppAVar6;
  uint uVar7;
  long lVar8;
  int iVar9;
  uint uVar10;
  _STACK *p_Var11;
  ASN1_ITEM *it;
  code *pcVar12;
  ASN1_TEMPLATE *tt_00;
  code *local_74;
  uchar *local_5c;
  char local_58 [8];
  char local_50 [8];
  uchar local_48 [8];
  char local_40 [4];
  uchar *local_3c;
  ASN1_VALUE *local_38;
  uchar *local_34;
  uchar *local_30;
  ASN1_VALUE *local_2c [2];
  
  if (param_1 == (_STACK **)0x0) {
    return 0;
  }
  uVar10 = param_4->flags;
  local_3c = *param_2;
  local_5c = param_3;
  if ((uVar10 & 6) != 0) {
    uVar7 = uVar10 & 8;
    if (uVar7 == 0) {
      if ((uVar10 & 2) == 0) {
        lVar8 = 0x10;
      }
      else {
        lVar8 = 0x11;
      }
    }
    else {
      lVar8 = param_4->tag;
      uVar7 = uVar10 & 0xc0;
    }
    iVar5 = asn1_check_tlen(&local_5c,0,0,local_58,0,&local_3c,param_3,lVar8,uVar7,param_5,param_6);
    if (iVar5 == 0) {
      ERR_put_error(0xd,0x83,0x3a,"tasn_dec.c",0x293);
      return 0;
    }
    if (iVar5 == -1) {
      return 0xffffffff;
    }
    p_Var11 = *param_1;
    if (p_Var11 == (_STACK *)0x0) {
      p_Var11 = sk_new_null();
      *param_1 = p_Var11;
    }
    else {
      while (iVar5 = sk_num(p_Var11), 0 < iVar5) {
        local_2c[0] = (ASN1_VALUE *)sk_pop(p_Var11);
        ASN1_item_ex_free(local_2c,param_4->item);
      }
      p_Var11 = *param_1;
    }
    if (p_Var11 != (_STACK *)0x0) {
      if (0 < (int)local_5c) {
LAB_000bdbac:
        puVar4 = local_3c;
        puVar3 = local_5c;
        if (((local_5c != (uchar *)0x1) && (*local_3c == '\0')) && (local_3c[1] == '\0')) {
          local_3c = local_3c + 2;
          if (local_58[0] != '\0') goto LAB_000bdca6;
          ERR_put_error(0xd,0x83,0x9f,"tasn_dec.c",0x2ba);
          goto LAB_000bdc60;
        }
        it = param_4->item;
        local_38 = (ASN1_VALUE *)0x0;
        local_34 = local_5c;
        pcVar12 = (code *)it->funcs;
        local_30 = (uchar *)0x0;
        local_74 = pcVar12;
        if (pcVar12 != (code *)0x0) {
          local_74 = *(code **)(pcVar12 + 0x10);
        }
        switch(it->itype) {
        case '\0':
          if (it->templates == (ASN1_TEMPLATE *)0x0) {
            iVar5 = asn1_d2i_ex_primitive(&local_38,&local_3c,local_5c,it,0xffffffff,0,0,param_6);
          }
          else {
            iVar5 = asn1_template_ex_d2i(&local_38,&local_3c,local_5c,it->templates,0,param_6);
          }
          if (iVar5 == 0) goto switchD_000bdbe0_caseD_7;
LAB_000bdd4c:
          local_5c = puVar4 + ((int)local_5c - (int)local_3c);
          iVar5 = sk_push(*param_1,local_38);
          if (iVar5 != 0) goto code_r0x000bdd64;
          iVar5 = 0x2cf;
          goto LAB_000be0fe;
        case '\x01':
        case '\x06':
          local_30 = local_3c;
          iVar5 = asn1_check_tlen(&local_34,0,0,local_48,local_40,&local_30,local_5c,0x10,0,0,
                                  param_6);
          if (iVar5 != 0) {
            if (iVar5 == -1) goto LAB_000bdd4c;
            uVar2 = local_48[0];
            if ((pcVar12 != (code *)0x0) && (*(int *)(pcVar12 + 4) << 0x1d < 0)) {
              local_34 = local_3c + ((int)puVar3 - (int)local_30);
              uVar2 = '\x01';
            }
            if (local_40[0] == '\0') {
              ERR_put_error(0xd,0x78,0x95,"tasn_dec.c",0x18c);
              break;
            }
            if ((local_38 == (ASN1_VALUE *)0x0) &&
               (iVar5 = ASN1_item_ex_new(&local_38,it), iVar5 == 0)) {
              iVar5 = 0x193;
              goto LAB_000be00a;
            }
            if ((local_74 != (code *)0x0) && (iVar5 = (*local_74)(4,&local_38,it,0), iVar5 == 0))
            goto LAB_000bdc18;
            iVar5 = 0;
            tt_00 = it->templates;
            if (0 < it->tcount) {
              do {
                tt = asn1_do_adb(&local_38,tt_00,1);
                if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_000bdc30;
                ppAVar6 = asn1_get_field_ptr(&local_38,tt);
                puVar3 = local_30;
                if (local_34 == (uchar *)0x0) break;
                if (((1 < (int)local_34) && (*local_30 == '\0')) &&
                   (puVar1 = local_30 + 1, *puVar1 == '\0')) {
                  local_30 = local_30 + 2;
                  if (local_48[0] == '\0') {
                    ERR_put_error(0xd,0x78,0x9f,"tasn_dec.c",0x1ac);
                    goto LAB_000bdc30;
                  }
                  local_34 = local_34 + -2;
                  local_48[0] = *puVar1;
                  goto LAB_000be078;
                }
                if (it->tcount + -1 == iVar5) {
                  uVar10 = 0;
                }
                else {
                  uVar10 = tt->flags & 1;
                }
                iVar9 = asn1_template_ex_d2i(ppAVar6,&local_30,local_34,tt,uVar10,param_6);
                if (iVar9 == 0) goto LAB_000be1c4;
                if (iVar9 == -1) {
                  ASN1_template_free(ppAVar6,tt);
                }
                else {
                  local_34 = puVar3 + ((int)local_34 - (int)local_30);
                }
                iVar5 = iVar5 + 1;
                tt_00 = tt_00 + 1;
              } while (iVar5 < it->tcount);
            }
            if (local_48[0] != '\0') {
              if ((((int)local_34 < 2) || (*local_30 != '\0')) || (local_30[1] != '\0')) {
                ERR_put_error(0xd,0x78,0x89,"tasn_dec.c",0x1d6);
                break;
              }
              local_30 = local_30 + 2;
            }
LAB_000be078:
            if ((uVar2 == '\0') && (local_34 != (uchar *)0x0)) {
              ERR_put_error(0xd,0x78,0x94,"tasn_dec.c",0x1dd);
              break;
            }
LAB_000be0b2:
            if (iVar5 < it->tcount) {
              iVar5 = iVar5 + 1;
              tt = asn1_do_adb(&local_38,tt_00,1);
              tt_00 = tt_00 + 1;
              if (tt != (ASN1_TEMPLATE *)0x0) {
                if ((int)(tt->flags << 0x1f) < 0) goto code_r0x000be0a8;
                ERR_put_error(0xd,0x78,0x79,"tasn_dec.c",0x1f5);
LAB_000be1c4:
                ASN1_item_ex_free(&local_38,it);
LAB_000be182:
                ERR_add_error_data(4,"Field=",tt->field_name,", Type=",it->sname);
                goto switchD_000bdbe0_caseD_7;
              }
              break;
            }
            iVar5 = asn1_enc_save(&local_38,local_3c,(int)local_30 - (int)local_3c,it);
            if (iVar5 == 0) goto LAB_000bdc18;
            local_3c = local_30;
            if (local_74 == (code *)0x0) goto LAB_000bdd4c;
LAB_000bdc08:
            local_3c = local_30;
            iVar5 = (*local_74)(5,&local_38,it,0);
            if (iVar5 == 0) goto LAB_000bdc18;
            goto LAB_000bdd4c;
          }
          iVar5 = 0x17d;
          goto LAB_000be022;
        case '\x02':
          if (local_74 == (code *)0x0) {
LAB_000bdff4:
            iVar5 = ASN1_item_ex_new(&local_38,it);
            if (iVar5 == 0) {
              iVar5 = 0x13e;
              goto LAB_000be00a;
            }
LAB_000bdeda:
            iVar5 = it->tcount;
            iVar9 = 0;
            tt = it->templates;
            local_30 = local_3c;
            if (0 < iVar5) {
              do {
                ppAVar6 = asn1_get_field_ptr(&local_38,tt);
                iVar5 = asn1_template_ex_d2i(ppAVar6,&local_30,local_34,tt,1,param_6);
                if (iVar5 != -1) {
                  if (iVar5 < 1) {
                    ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",0x153);
                    ASN1_item_ex_free(&local_38,it);
                    if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_000bdc38;
                    goto LAB_000be182;
                  }
                  iVar5 = it->tcount;
                  break;
                }
                iVar5 = it->tcount;
                iVar9 = iVar9 + 1;
                tt = tt + 1;
              } while (iVar9 < iVar5);
            }
            if (iVar9 != iVar5) {
              asn1_set_choice_selector(&local_38,iVar9,it);
              local_3c = local_30;
              if (local_74 != (code *)0x0) goto LAB_000bdc08;
              goto LAB_000bdd4c;
            }
            ERR_put_error(0xd,0x78,0x8f,"tasn_dec.c",0x162);
          }
          else {
            iVar5 = (*local_74)(4,&local_38,it,0);
            if (iVar5 != 0) {
              if (local_38 == (ASN1_VALUE *)0x0) goto LAB_000bdff4;
              goto LAB_000bdeda;
            }
LAB_000bdc18:
            ERR_put_error(0xd,0x78,100,"tasn_dec.c",0x205);
          }
          break;
        case '\x03':
          iVar5 = (**(code **)(pcVar12 + 8))(&local_38,&local_3c,local_5c);
          if (iVar5 != 0) goto LAB_000bdd4c;
          iVar5 = 0x132;
LAB_000be00a:
          ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",iVar5);
          break;
        case '\x04':
          iVar5 = (**(code **)(pcVar12 + 0x10))
                            (&local_38,&local_3c,local_5c,it,0xffffffff,0,0,param_6);
joined_r0x000be128:
          if (iVar5 != 0) goto LAB_000bdd4c;
          goto switchD_000bdbe0_caseD_7;
        case '\x05':
          local_30 = local_3c;
          iVar5 = asn1_check_tlen_constprop_1(0,local_2c,local_50,0,0,&local_30,local_5c,1,param_6);
          if (iVar5 != 0) {
            if (local_50[0] == '\0') {
              if ((local_2c[0] < (ASN1_VALUE *)0x1f) &&
                 ((it->utype & *(uint *)(&tag2bit + (int)local_2c[0] * 4)) != 0)) {
                iVar5 = asn1_d2i_ex_primitive
                                  (&local_38,&local_3c,local_34,it,local_2c[0],0,0,param_6);
                goto joined_r0x000be128;
              }
              ERR_put_error(0xd,0x78,0x8c,"tasn_dec.c",0xe6);
            }
            else {
              ERR_put_error(0xd,0x78,0x8b,"tasn_dec.c",0xdc);
            }
            break;
          }
          iVar5 = 0xd2;
LAB_000be022:
          ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",iVar5);
          break;
        default:
          goto switchD_000bdbe0_caseD_7;
        }
LAB_000bdc30:
        ASN1_item_ex_free(&local_38,it);
LAB_000bdc38:
        ERR_add_error_data(2,"Type=",it->sname);
switchD_000bdbe0_caseD_7:
        iVar9 = 0x2c7;
        goto LAB_000bdc50;
      }
LAB_000bdd6c:
      if (local_58[0] != '\0') {
        ERR_put_error(0xd,0x83,0x89,"tasn_dec.c",0x2d5);
        goto LAB_000bdc60;
      }
      goto LAB_000bdca6;
    }
    iVar5 = 0x2ab;
LAB_000be0fe:
    ERR_put_error(0xd,0x83,0x41,"tasn_dec.c",iVar5);
    goto LAB_000bdc60;
  }
  if ((uVar10 & 8) == 0) {
    iVar5 = ASN1_item_ex_d2i((ASN1_VALUE **)param_1,&local_3c,(long)param_3,param_4->item,-1,0,
                             param_5,param_6);
    if (iVar5 != 0) goto LAB_000bdc9c;
    iVar9 = 0x2ef;
  }
  else {
    iVar5 = ASN1_item_ex_d2i((ASN1_VALUE **)param_1,&local_3c,(long)param_3,param_4->item,
                             param_4->tag,uVar10 & 0xc0,param_5,param_6);
    iVar9 = 0x2e1;
    if (iVar5 != 0) {
LAB_000bdc9c:
      if (iVar5 == -1) {
        return 0xffffffff;
      }
LAB_000bdca6:
      *param_2 = local_3c;
      return 1;
    }
  }
LAB_000bdc50:
  ERR_put_error(0xd,0x83,0x3a,"tasn_dec.c",iVar9);
LAB_000bdc60:
  ASN1_template_free((ASN1_VALUE **)param_1,param_4);
  return 0;
code_r0x000be0a8:
  ppAVar6 = asn1_get_field_ptr(&local_38,tt);
  ASN1_template_free(ppAVar6,tt);
  goto LAB_000be0b2;
code_r0x000bdd64:
  if ((int)local_5c < 1) goto LAB_000bdd6c;
  goto LAB_000bdbac;
}

