
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
  ASN1_TEMPLATE *pAVar5;
  ASN1_VALUE **ppAVar6;
  uint uVar7;
  undefined4 uVar8;
  _STACK *p_Var9;
  uint aclass;
  long lVar10;
  int iVar11;
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
    goto LAB_08149190;
  }
  uVar7 = param_1->flags;
  local_34 = *param_2_00;
  aclass = uVar7 & 0xc0;
  if ((uVar7 & 6) != 0) {
    if ((uVar7 & 8) == 0) {
      aclass = 0;
      iVar4 = 0x11 - (uint)((uVar7 & 2) == 0);
    }
    else {
      iVar4 = param_1->tag;
    }
    iVar4 = asn1_check_tlen(&local_38,0,&local_34,param_3_00,iVar4,aclass,(int)param_2,param_3);
    if (iVar4 == 0) {
      ERR_put_error(0xd,0x83,0x3a,"tasn_dec.c",0x273);
      uVar8 = 0;
      goto LAB_08149190;
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
LAB_081490d8:
        puVar2 = local_34;
        if ((int)local_40 < 1) {
          if (local_38 == '\0') goto LAB_08149185;
          ERR_put_error(0xd,0x83,0x89,"tasn_dec.c",0x2a7);
          goto LAB_0814970e;
        }
        if (((local_40 != (uchar *)0x1) && (*local_34 == '\0')) && (local_34[1] == '\0')) {
          local_34 = local_34 + 2;
          if (local_38 != '\0') goto LAB_08149185;
          ERR_put_error(0xd,0x83,0x9f,"tasn_dec.c",0x292);
          goto LAB_0814970e;
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
              goto switchD_0814962a_caseD_0;
            default:
              local_58 = (code *)0x0;
              goto switchD_08149135_caseD_1;
            case '\x02':
              local_58 = (code *)0x0;
              goto LAB_0814973c;
            case '\x03':
              goto switchD_0814962a_caseD_3;
            case '\x04':
              goto switchD_0814962a_caseD_4;
            case '\x05':
              goto switchD_0814962a_caseD_5;
            }
          }
        }
        else {
          local_58 = *(code **)((int)pvVar1 + 0x10);
          if (6 < (byte)it->itype) goto LAB_08149610;
          switch(it->itype) {
          case '\0':
            goto switchD_0814962a_caseD_0;
          default:
switchD_08149135_caseD_1:
            local_28 = local_34;
            iVar4 = asn1_check_tlen(&local_36,&local_35,&local_28,local_40,0x10,0,0,param_3);
            if (iVar4 == 0) {
              iVar11 = 0x176;
              iVar4 = 0x3a;
              goto LAB_081494c2;
            }
            if (iVar4 == -1) goto LAB_081491d8;
            if ((pvVar1 == (void *)0x0) || ((*(byte *)((int)pvVar1 + 4) & 4) == 0)) {
              local_41 = local_36;
            }
            else {
              local_41 = '\x01';
              local_2c = local_40 + -((int)local_28 - (int)local_34);
            }
            if (local_35 == '\0') {
              iVar11 = 0x182;
              iVar4 = 0x95;
              goto LAB_081494c2;
            }
            if ((local_30 == (ASN1_VALUE *)0x0) &&
               (iVar4 = ASN1_item_ex_new(&local_30,it), iVar4 == 0)) {
              iVar4 = 0x187;
              goto LAB_08149240;
            }
            if ((local_58 != (code *)0x0) && (iVar4 = (*local_58)(4,&local_30,it,0), iVar4 == 0))
            goto LAB_081495d1;
            iVar4 = it->tcount;
            iVar11 = 0;
            local_54 = it->templates;
            if (iVar4 < 1) {
LAB_08149b5d:
              iVar4 = 0;
            }
            else {
              do {
                while ((local_54->flags & 0x300) == 0) {
                  iVar11 = iVar11 + 1;
                  local_54 = local_54 + 1;
                  if (iVar4 <= iVar11) goto LAB_08149366;
                }
                iVar11 = iVar11 + 1;
                pAVar5 = asn1_do_adb(&local_30,local_54,1);
                ppAVar6 = asn1_get_field_ptr(&local_30,pAVar5);
                ASN1_template_free(ppAVar6,pAVar5);
                iVar4 = it->tcount;
                local_54 = local_54 + 1;
              } while (iVar11 < iVar4);
LAB_08149366:
              local_54 = it->templates;
              if (iVar4 < 1) goto LAB_08149b5d;
              iVar4 = 0;
              do {
                pAVar5 = asn1_do_adb(&local_30,local_54,1);
                if (pAVar5 == (ASN1_TEMPLATE *)0x0) goto LAB_081495ec;
                ppAVar6 = asn1_get_field_ptr(&local_30,pAVar5);
                puVar3 = local_28;
                if (local_2c == (uchar *)0x0) {
                  if (local_36 == '\0') goto LAB_08149907;
                  goto LAB_08149a51;
                }
                if (((1 < (int)local_2c) && (*local_28 == '\0')) && (local_28[1] == '\0')) {
                  local_28 = local_28 + 2;
                  if (local_36 == '\0') {
                    ERR_put_error(0xd,0x78,0x9f,"tasn_dec.c",0x1a7);
                    goto LAB_081495ec;
                  }
                  local_2c = local_2c + -2;
                  local_36 = '\0';
                  goto LAB_081498f4;
                }
                uVar7 = 0;
                if (iVar4 != it->tcount + -1) {
                  uVar7 = pAVar5->flags & 1;
                }
                iVar11 = asn1_template_ex_d2i(pAVar5,uVar7,param_3);
                if (iVar11 == 0) goto LAB_08149a78;
                if (iVar11 == -1) {
                  ASN1_template_free(ppAVar6,pAVar5);
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
LAB_08149a51:
                ERR_put_error(0xd,0x78,0x89,"tasn_dec.c",0x1ce);
                break;
              }
              local_28 = local_28 + 2;
            }
LAB_081498f4:
            if ((local_41 != '\0') || (local_2c == (uchar *)0x0)) {
LAB_08149907:
              if (it->tcount != iVar4 && iVar4 <= it->tcount) {
LAB_08149952:
                pAVar5 = asn1_do_adb(&local_30,local_54,1);
                if (pAVar5 != (ASN1_TEMPLATE *)0x0) {
                  if ((*(byte *)&pAVar5->flags & 1) != 0) goto code_r0x08149929;
                  ERR_put_error(0xd,0x78,0x79,"tasn_dec.c",0x1e7);
LAB_08149a78:
                  ASN1_item_ex_free(&local_30,it);
LAB_0814978d:
                  ERR_add_error_data(4,"Field=",pAVar5->field_name,", Type=",it->sname);
                  goto LAB_08149610;
                }
                break;
              }
LAB_0814984e:
              iVar4 = asn1_enc_save(&local_30,local_34,(int)local_28 - (int)local_34,it);
              if (iVar4 != 0) goto joined_r0x081495b4;
              goto LAB_081495d1;
            }
            ERR_put_error(0xd,0x78,0x94,"tasn_dec.c",0x1d3);
            break;
          case '\x02':
            if (local_58 == (code *)0x0) {
LAB_0814973c:
              iVar4 = ASN1_item_ex_new(&local_30,it);
              if (iVar4 == 0) {
                iVar4 = 0x13f;
                goto LAB_08149240;
              }
              lVar10 = it->tcount;
LAB_0814952f:
              iVar4 = 0;
              pAVar5 = it->templates;
              local_28 = local_34;
              if (0 < lVar10) {
                do {
                  asn1_get_field_ptr(&local_30,pAVar5);
                  iVar11 = asn1_template_ex_d2i(pAVar5,1,param_3);
                  if (iVar11 != -1) {
                    if (iVar11 < 1) {
                      ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",0x152);
                      ASN1_item_ex_free(&local_30,it);
                      if (pAVar5 == (ASN1_TEMPLATE *)0x0) goto LAB_081495f9;
                      goto LAB_0814978d;
                    }
                    lVar10 = it->tcount;
                    break;
                  }
                  lVar10 = it->tcount;
                  iVar4 = iVar4 + 1;
                  pAVar5 = pAVar5 + 1;
                } while (iVar4 < lVar10);
              }
              if (iVar4 == lVar10) {
                ERR_put_error(0xd,0x78,0x8f,"tasn_dec.c",0x15e);
                break;
              }
              asn1_set_choice_selector(&local_30,iVar4,it);
joined_r0x081495b4:
              if ((local_58 == (code *)0x0) || (iVar4 = (*local_58)(5,&local_30,it,0), iVar4 != 0))
              {
                local_34 = local_28;
                goto LAB_081491d8;
              }
            }
            else {
              iVar4 = (*local_58)(4,&local_30,it,0);
              if (iVar4 != 0) {
                if (local_30 == (ASN1_VALUE *)0x0) goto LAB_0814973c;
                iVar4 = asn1_get_choice_selector(&local_30,it);
                lVar10 = it->tcount;
                if ((-1 < iVar4) && (iVar4 < lVar10)) {
                  pAVar5 = it->templates;
                  ppAVar6 = asn1_get_field_ptr(&local_30,pAVar5 + iVar4);
                  ASN1_template_free(ppAVar6,pAVar5 + iVar4);
                  asn1_set_choice_selector(&local_30,-1,it);
                  lVar10 = it->tcount;
                }
                goto LAB_0814952f;
              }
            }
LAB_081495d1:
            ERR_put_error(0xd,0x78,100,"tasn_dec.c",0x1f7);
            break;
          case '\x03':
switchD_0814962a_caseD_3:
            iVar4 = (**(code **)((int)pvVar1 + 8))(&local_30,&local_34,local_40);
            if (iVar4 != 0) goto LAB_081491d8;
            iVar4 = 0x12f;
LAB_08149240:
            ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",iVar4);
            break;
          case '\x04':
switchD_0814962a_caseD_4:
            iVar4 = (**(code **)((int)pvVar1 + 0x10))
                              (&local_30,&local_34,local_40,it,0xffffffff,0,0,param_3);
            goto LAB_081491cc;
          case '\x05':
switchD_0814962a_caseD_5:
            local_28 = local_34;
            iVar4 = asn1_check_tlen_constprop_1(0,0,&local_28,local_40,1,param_3);
            if (iVar4 == 0) {
              iVar11 = 0xdb;
              iVar4 = 0x3a;
            }
            else if (local_37 == '\0') {
              if ((local_24 < (ASN1_VALUE *)0x1f) &&
                 ((it->utype & *(uint *)(tag2bit + (int)local_24 * 4)) != 0)) {
                iVar4 = asn1_d2i_ex_primitive(it,local_24,0,0,param_3);
                goto LAB_081491cc;
              }
              iVar11 = 0xec;
              iVar4 = 0x8c;
            }
            else {
              iVar11 = 0xe4;
              iVar4 = 0x8b;
            }
LAB_081494c2:
            ERR_put_error(0xd,0x78,iVar4,"tasn_dec.c",iVar11);
          }
LAB_081495ec:
          ASN1_item_ex_free(&local_30,it);
LAB_081495f9:
          ERR_add_error_data(2,"Type=",it->sname);
        }
LAB_08149610:
        iVar4 = 0x29d;
        goto LAB_081496f8;
      }
      iVar4 = 0x286;
      goto LAB_08149205;
    }
LAB_08149990:
    uVar8 = 0xffffffff;
    goto LAB_08149190;
  }
  if ((uVar7 & 8) == 0) {
    iVar4 = ASN1_item_ex_d2i((ASN1_VALUE **)param_1_00,&local_34,(long)param_3_00,param_1->item,-1,
                             uVar7 & 0x400,param_2,param_3);
    if (iVar4 != 0) goto LAB_08149178;
    iVar4 = 0x2b9;
  }
  else {
    iVar4 = ASN1_item_ex_d2i((ASN1_VALUE **)param_1_00,&local_34,(long)param_3_00,param_1->item,
                             param_1->tag,aclass,param_2,param_3);
    if (iVar4 != 0) {
LAB_08149178:
      if (iVar4 != -1) {
LAB_08149185:
        *param_2_00 = local_34;
        uVar8 = 1;
        goto LAB_08149190;
      }
      goto LAB_08149990;
    }
    iVar4 = 0x2b0;
  }
LAB_081496f8:
  ERR_put_error(0xd,0x83,0x3a,"tasn_dec.c",iVar4);
  goto LAB_0814970e;
code_r0x08149929:
  local_54 = local_54 + 1;
  iVar4 = iVar4 + 1;
  ppAVar6 = asn1_get_field_ptr(&local_30,pAVar5);
  ASN1_template_free(ppAVar6,pAVar5);
  if (it->tcount <= iVar4) goto LAB_0814984e;
  goto LAB_08149952;
switchD_0814962a_caseD_0:
  if (it->templates == (ASN1_TEMPLATE *)0x0) {
    iVar4 = asn1_d2i_ex_primitive(it,0xffffffff,0,0,param_3);
  }
  else {
    iVar4 = asn1_template_ex_d2i(it->templates,0,param_3);
  }
LAB_081491cc:
  if (iVar4 == 0) goto LAB_08149610;
LAB_081491d8:
  local_40 = local_40 + -((int)local_34 - (int)puVar2);
  iVar4 = sk_push(*param_1_00,local_30);
  if (iVar4 == 0) goto code_r0x081491fd;
  goto LAB_081490d8;
code_r0x081491fd:
  iVar4 = 0x2a2;
LAB_08149205:
  ERR_put_error(0xd,0x83,0x41,"tasn_dec.c",iVar4);
LAB_0814970e:
  ASN1_template_free((ASN1_VALUE **)param_1_00,param_1);
  uVar8 = 0;
LAB_08149190:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}

