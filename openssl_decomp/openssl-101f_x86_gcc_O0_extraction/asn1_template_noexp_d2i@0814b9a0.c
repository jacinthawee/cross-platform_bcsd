
undefined4 __regparm3
asn1_template_noexp_d2i
          (_STACK **param_1_00,uchar **param_2_00,uchar *param_3_00,ASN1_TEMPLATE *param_1,
          char param_2,ASN1_TLC *param_3)

{
  ASN1_ITEM *it;
  void *pvVar1;
  uchar *puVar2;
  uchar *puVar3;
  int iVar4;
  ASN1_TEMPLATE *tt;
  ASN1_VALUE **ppAVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  _STACK *p_Var9;
  uint aclass;
  int in_GS_OFFSET;
  code *local_58;
  ASN1_TEMPLATE *local_54;
  char local_41;
  uchar *local_40;
  char local_38;
  char local_37;
  char local_36;
  char local_35;
  uchar *local_34;
  ASN1_VALUE *local_30;
  uchar *local_2c;
  uchar *local_28;
  ASN1_VALUE *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1_00 == (_STACK **)0x0) {
    uVar8 = 0;
    goto LAB_0814bb50;
  }
  uVar6 = param_1->flags;
  local_34 = *param_2_00;
  aclass = uVar6 & 0xc0;
  if ((uVar6 & 6) != 0) {
    if ((uVar6 & 8) == 0) {
      aclass = 0;
      iVar4 = 0x11 - (uint)((uVar6 & 2) == 0);
    }
    else {
      iVar4 = param_1->tag;
    }
    iVar4 = asn1_check_tlen(&local_38,0,&local_34,param_3_00,iVar4,aclass,(int)param_2,param_3);
    if (iVar4 == 0) {
      ERR_put_error(0xd,0x83,0x3a,"tasn_dec.c",0x293);
      uVar8 = 0;
      goto LAB_0814bb50;
    }
    if (iVar4 != -1) {
      p_Var9 = *param_1_00;
      if (p_Var9 == (_STACK *)0x0) {
        p_Var9 = sk_new_null();
        *param_1_00 = p_Var9;
      }
      else {
        while (iVar4 = sk_num(p_Var9), 0 < iVar4) {
          local_24 = (ASN1_VALUE *)sk_pop(p_Var9);
          ASN1_item_ex_free(&local_24,param_1->item);
        }
        p_Var9 = *param_1_00;
      }
      local_40 = param_3_00;
      if (p_Var9 != (_STACK *)0x0) {
LAB_0814ba98:
        puVar2 = local_34;
        if ((int)local_40 < 1) {
          if (local_38 == '\0') goto LAB_0814bb45;
          ERR_put_error(0xd,0x83,0x89,"tasn_dec.c",0x2d5);
          goto LAB_0814c05e;
        }
        if (((local_40 != (uchar *)0x1) && (*local_34 == '\0')) && (local_34[1] == '\0')) {
          local_34 = local_34 + 2;
          if (local_38 != '\0') goto LAB_0814bb45;
          ERR_put_error(0xd,0x83,0x9f,"tasn_dec.c",0x2ba);
          goto LAB_0814c05e;
        }
        local_30 = (ASN1_VALUE *)0x0;
        local_2c = local_40;
        local_28 = (uchar *)0x0;
        it = param_1->item;
        pvVar1 = it->funcs;
        if (pvVar1 == (void *)0x0) {
          if ((byte)it->itype < 7) {
            switch(it->itype) {
            case '\0':
              goto switchD_0814bf8a_caseD_0;
            default:
              local_58 = (code *)0x0;
              goto switchD_0814baf5_caseD_1;
            case '\x02':
              local_58 = (code *)0x0;
              goto LAB_0814c08c;
            case '\x03':
              goto switchD_0814bf8a_caseD_3;
            case '\x04':
              goto switchD_0814bf8a_caseD_4;
            case '\x05':
              goto switchD_0814bf8a_caseD_5;
            }
          }
        }
        else {
          local_58 = *(code **)((int)pvVar1 + 0x10);
          if (6 < (byte)it->itype) goto LAB_0814bf70;
          switch(it->itype) {
          case '\0':
            goto switchD_0814bf8a_caseD_0;
          default:
switchD_0814baf5_caseD_1:
            local_28 = local_34;
            iVar4 = asn1_check_tlen(&local_36,&local_35,&local_28,local_40,0x10,0,0,param_3);
            if (iVar4 == 0) {
              iVar7 = 0x17d;
              iVar4 = 0x3a;
              goto LAB_0814be22;
            }
            if (iVar4 == -1) goto LAB_0814bb98;
            if ((pvVar1 == (void *)0x0) || ((*(byte *)((int)pvVar1 + 4) & 4) == 0)) {
              local_41 = local_36;
            }
            else {
              local_41 = '\x01';
              local_2c = local_40 + -((int)local_28 - (int)local_34);
            }
            if (local_35 == '\0') {
              iVar7 = 0x18c;
              iVar4 = 0x95;
              goto LAB_0814be22;
            }
            if ((local_30 == (ASN1_VALUE *)0x0) &&
               (iVar4 = ASN1_item_ex_new(&local_30,it), iVar4 == 0)) {
              iVar4 = 0x193;
              goto LAB_0814bc00;
            }
            if ((local_58 != (code *)0x0) && (iVar4 = (*local_58)(4,&local_30,it,0), iVar4 == 0))
            goto LAB_0814bf30;
            local_54 = it->templates;
            if (it->tcount < 1) {
              iVar4 = 0;
            }
            else {
              iVar4 = 0;
              do {
                tt = asn1_do_adb(&local_30,local_54,1);
                if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_0814bf4b;
                ppAVar5 = asn1_get_field_ptr(&local_30,tt);
                puVar3 = local_28;
                if (local_2c == (uchar *)0x0) {
                  if (local_36 != '\0') goto LAB_0814c363;
                  goto LAB_0814c251;
                }
                if (((1 < (int)local_2c) && (*local_28 == '\0')) && (local_28[1] == '\0')) {
                  local_28 = local_28 + 2;
                  if (local_36 != '\0') {
                    local_2c = local_2c + -2;
                    local_36 = '\0';
                    goto LAB_0814c23e;
                  }
                  ERR_put_error(0xd,0x78,0x9f,"tasn_dec.c",0x1ac);
                  goto LAB_0814bf4b;
                }
                uVar6 = 0;
                if (it->tcount + -1 != iVar4) {
                  uVar6 = tt->flags & 1;
                }
                iVar7 = asn1_template_ex_d2i(tt,uVar6,param_3);
                if (iVar7 == 0) goto LAB_0814c38a;
                if (iVar7 == -1) {
                  ASN1_template_free(ppAVar5,tt);
                }
                else {
                  local_2c = puVar3 + ((int)local_2c - (int)local_28);
                }
                iVar4 = iVar4 + 1;
                local_54 = local_54 + 1;
              } while (iVar4 < it->tcount);
            }
            if (local_36 != '\0') {
              if ((((int)local_2c < 2) || (*local_28 != '\0')) || (local_28[1] != '\0')) {
LAB_0814c363:
                ERR_put_error(0xd,0x78,0x89,"tasn_dec.c",0x1d6);
                break;
              }
              local_28 = local_28 + 2;
            }
LAB_0814c23e:
            if ((local_41 == '\0') && (local_2c != (uchar *)0x0)) {
              ERR_put_error(0xd,0x78,0x94,"tasn_dec.c",0x1dd);
              break;
            }
LAB_0814c251:
            if (it->tcount != iVar4 && iVar4 <= it->tcount) {
LAB_0814c2a2:
              tt = asn1_do_adb(&local_30,local_54,1);
              if (tt != (ASN1_TEMPLATE *)0x0) {
                if ((*(byte *)&tt->flags & 1) != 0) goto code_r0x0814c279;
                ERR_put_error(0xd,0x78,0x79,"tasn_dec.c",0x1f5);
LAB_0814c38a:
                ASN1_item_ex_free(&local_30,it);
LAB_0814c0dd:
                ERR_add_error_data(4,"Field=",tt->field_name,", Type=",it->sname);
                goto LAB_0814bf70;
              }
              break;
            }
LAB_0814bee9:
            iVar4 = asn1_enc_save(&local_30,local_34,(int)local_28 - (int)local_34,it);
            if (iVar4 != 0) {
              local_34 = local_28;
              if (local_58 != (code *)0x0) {
                iVar4 = (*local_58)(5,&local_30,it,0);
                goto joined_r0x0814c1cf;
              }
              goto LAB_0814bb98;
            }
LAB_0814bf30:
            ERR_put_error(0xd,0x78,100,"tasn_dec.c",0x205);
            break;
          case '\x02':
            if (local_58 != (code *)0x0) {
              iVar4 = (*local_58)(4,&local_30,it,0);
              if (iVar4 != 0) {
                if (local_30 == (ASN1_VALUE *)0x0) goto LAB_0814c08c;
                goto LAB_0814be73;
              }
              goto LAB_0814bf30;
            }
LAB_0814c08c:
            iVar4 = ASN1_item_ex_new(&local_30,it);
            if (iVar4 == 0) {
              iVar4 = 0x13e;
              goto LAB_0814bc00;
            }
LAB_0814be73:
            iVar7 = 0;
            tt = it->templates;
            local_28 = local_34;
            iVar4 = it->tcount;
            if (0 < iVar4) {
              do {
                asn1_get_field_ptr(&local_30,tt);
                iVar4 = asn1_template_ex_d2i(tt,1,param_3);
                if (iVar4 != -1) {
                  if (iVar4 < 1) {
                    ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",0x153);
                    ASN1_item_ex_free(&local_30,it);
                    if (tt != (ASN1_TEMPLATE *)0x0) goto LAB_0814c0dd;
                    goto LAB_0814bf58;
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
              break;
            }
            asn1_set_choice_selector(&local_30,iVar7,it);
            local_34 = local_28;
            if (local_58 != (code *)0x0) {
              iVar4 = (*local_58)(5,&local_30,it,0);
joined_r0x0814c1cf:
              if (iVar4 == 0) goto LAB_0814bf30;
            }
LAB_0814bb98:
            local_40 = local_40 + -((int)local_34 - (int)puVar2);
            iVar4 = sk_push(*param_1_00,local_30);
            if (iVar4 == 0) goto code_r0x0814bbbd;
            goto LAB_0814ba98;
          case '\x03':
switchD_0814bf8a_caseD_3:
            iVar4 = (**(code **)((int)pvVar1 + 8))(&local_30,&local_34,local_40);
            if (iVar4 != 0) goto LAB_0814bb98;
            iVar4 = 0x132;
LAB_0814bc00:
            ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",iVar4);
            break;
          case '\x04':
switchD_0814bf8a_caseD_4:
            iVar4 = (**(code **)((int)pvVar1 + 0x10))
                              (&local_30,&local_34,local_40,it,0xffffffff,0,0,param_3);
            goto LAB_0814bb8c;
          case '\x05':
switchD_0814bf8a_caseD_5:
            local_28 = local_34;
            iVar4 = asn1_check_tlen_constprop_1(0,0,&local_28,local_40,1,param_3);
            if (iVar4 == 0) {
              iVar7 = 0xd2;
              iVar4 = 0x3a;
            }
            else if (local_37 == '\0') {
              if ((local_24 < (ASN1_VALUE *)0x1f) &&
                 ((it->utype & *(uint *)(tag2bit + (int)local_24 * 4)) != 0)) {
                iVar4 = asn1_d2i_ex_primitive(it,local_24,0,0,param_3);
                goto LAB_0814bb8c;
              }
              iVar7 = 0xe6;
              iVar4 = 0x8c;
            }
            else {
              iVar7 = 0xdc;
              iVar4 = 0x8b;
            }
LAB_0814be22:
            ERR_put_error(0xd,0x78,iVar4,"tasn_dec.c",iVar7);
          }
LAB_0814bf4b:
          ASN1_item_ex_free(&local_30,it);
LAB_0814bf58:
          ERR_add_error_data(2,"Type=",it->sname);
        }
        goto LAB_0814bf70;
      }
      iVar4 = 0x2ab;
      goto LAB_0814bbc5;
    }
LAB_0814c2e0:
    uVar8 = 0xffffffff;
    goto LAB_0814bb50;
  }
  if ((uVar6 & 8) == 0) {
    iVar4 = ASN1_item_ex_d2i((ASN1_VALUE **)param_1_00,&local_34,(long)param_3_00,param_1->item,-1,0
                             ,param_2,param_3);
    if (iVar4 != 0) goto LAB_0814bb38;
    iVar4 = 0x2ef;
  }
  else {
    iVar4 = ASN1_item_ex_d2i((ASN1_VALUE **)param_1_00,&local_34,(long)param_3_00,param_1->item,
                             param_1->tag,aclass,param_2,param_3);
    if (iVar4 != 0) {
LAB_0814bb38:
      if (iVar4 != -1) {
LAB_0814bb45:
        *param_2_00 = local_34;
        uVar8 = 1;
        goto LAB_0814bb50;
      }
      goto LAB_0814c2e0;
    }
    iVar4 = 0x2e1;
  }
LAB_0814c048:
  ERR_put_error(0xd,0x83,0x3a,"tasn_dec.c",iVar4);
  goto LAB_0814c05e;
code_r0x0814c279:
  local_54 = local_54 + 1;
  iVar4 = iVar4 + 1;
  ppAVar5 = asn1_get_field_ptr(&local_30,tt);
  ASN1_template_free(ppAVar5,tt);
  if (it->tcount <= iVar4) goto LAB_0814bee9;
  goto LAB_0814c2a2;
switchD_0814bf8a_caseD_0:
  if (it->templates == (ASN1_TEMPLATE *)0x0) {
    iVar4 = asn1_d2i_ex_primitive(it,0xffffffff,0,0,param_3);
  }
  else {
    iVar4 = asn1_template_ex_d2i(it->templates,0,param_3);
  }
LAB_0814bb8c:
  if (iVar4 != 0) goto LAB_0814bb98;
LAB_0814bf70:
  iVar4 = 0x2c7;
  goto LAB_0814c048;
code_r0x0814bbbd:
  iVar4 = 0x2cf;
LAB_0814bbc5:
  ERR_put_error(0xd,0x83,0x41,"tasn_dec.c",iVar4);
LAB_0814c05e:
  ASN1_template_free((ASN1_VALUE **)param_1_00,param_1);
  uVar8 = 0;
LAB_0814bb50:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

