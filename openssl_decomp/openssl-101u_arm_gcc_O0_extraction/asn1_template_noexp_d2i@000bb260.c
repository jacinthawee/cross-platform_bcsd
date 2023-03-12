
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
  ASN1_TEMPLATE *pAVar6;
  ASN1_VALUE **ppAVar7;
  uint uVar8;
  long lVar9;
  int iVar10;
  uint uVar11;
  _STACK *p_Var12;
  ASN1_ITEM *it;
  ASN1_TEMPLATE *tt;
  code *pcVar13;
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
  local_3c = *param_2;
  uVar8 = param_4->flags;
  local_5c = param_3;
  if ((uVar8 & 6) != 0) {
    uVar11 = uVar8 & 8;
    if (uVar11 == 0) {
      if ((uVar8 & 2) == 0) {
        lVar9 = 0x10;
      }
      else {
        lVar9 = 0x11;
      }
    }
    else {
      lVar9 = param_4->tag;
      uVar11 = uVar8 & 0xc0;
    }
    iVar5 = asn1_check_tlen(&local_5c,0,0,local_58,0,&local_3c,param_3,lVar9,uVar11,param_5,param_6)
    ;
    if (iVar5 == 0) {
      ERR_put_error(0xd,0x83,0x3a,"tasn_dec.c",0x273);
      return 0;
    }
    if (iVar5 == -1) {
      return 0xffffffff;
    }
    p_Var12 = *param_1;
    if (p_Var12 == (_STACK *)0x0) {
      p_Var12 = sk_new_null();
      *param_1 = p_Var12;
    }
    else {
      while (iVar5 = sk_num(p_Var12), 0 < iVar5) {
        local_2c[0] = (ASN1_VALUE *)sk_pop(p_Var12);
        ASN1_item_ex_free(local_2c,param_4->item);
      }
      p_Var12 = *param_1;
    }
    if (p_Var12 != (_STACK *)0x0) {
      if (0 < (int)local_5c) {
LAB_000bb312:
        puVar4 = local_3c;
        puVar3 = local_5c;
        if (((local_5c != (uchar *)0x1) && (*local_3c == '\0')) && (local_3c[1] == '\0')) {
          local_3c = local_3c + 2;
          if (local_58[0] != '\0') goto LAB_000bb474;
          ERR_put_error(0xd,0x83,0x9f,"tasn_dec.c",0x292);
          goto LAB_000bb430;
        }
        it = param_4->item;
        local_38 = (ASN1_VALUE *)0x0;
        local_34 = local_5c;
        pcVar13 = (code *)it->funcs;
        local_30 = (uchar *)0x0;
        local_74 = pcVar13;
        if (pcVar13 != (code *)0x0) {
          local_74 = *(code **)(pcVar13 + 0x10);
        }
        switch(it->itype) {
        case '\0':
          if (it->templates == (ASN1_TEMPLATE *)0x0) {
            iVar5 = asn1_d2i_ex_primitive(&local_38,&local_3c,local_5c,it,0xffffffff,0,0,param_6);
          }
          else {
            iVar5 = asn1_template_ex_d2i(&local_38,&local_3c,local_5c,it->templates,0,param_6);
          }
          if (iVar5 == 0) goto switchD_000bb346_caseD_7;
LAB_000bb51c:
          local_5c = puVar4 + ((int)local_5c - (int)local_3c);
          iVar5 = sk_push(*param_1,local_38);
          if (iVar5 != 0) goto code_r0x000bb534;
          iVar5 = 0x2a2;
          goto LAB_000bb898;
        case '\x01':
        case '\x06':
          local_30 = local_3c;
          iVar5 = asn1_check_tlen(&local_34,0,0,local_48,local_40,&local_30,local_5c,0x10,0,0,
                                  param_6);
          if (iVar5 != 0) {
            if (iVar5 == -1) goto LAB_000bb51c;
            uVar2 = local_48[0];
            if ((pcVar13 != (code *)0x0) && (*(int *)(pcVar13 + 4) << 0x1d < 0)) {
              local_34 = local_3c + ((int)puVar3 - (int)local_30);
              uVar2 = '\x01';
            }
            if (local_40[0] == '\0') {
              ERR_put_error(0xd,0x78,0x95,"tasn_dec.c",0x182);
              break;
            }
            if ((local_38 == (ASN1_VALUE *)0x0) &&
               (iVar5 = ASN1_item_ex_new(&local_38,it), iVar5 == 0)) {
              iVar5 = 0x187;
              goto LAB_000bb924;
            }
            if ((local_74 != (code *)0x0) && (iVar5 = (*local_74)(4,&local_38,it,0), iVar5 == 0))
            goto LAB_000bb3e6;
            iVar5 = it->tcount;
            tt = it->templates;
            if (iVar5 < 1) {
              iVar10 = 0;
            }
            else {
              iVar10 = 0;
              do {
                while (iVar10 = iVar10 + 1, (tt->flags & 0x300) == 0) {
                  tt = tt + 1;
                  if (iVar5 <= iVar10) goto LAB_000bb61c;
                }
                pAVar6 = asn1_do_adb(&local_38,tt,1);
                ppAVar7 = asn1_get_field_ptr(&local_38,pAVar6);
                ASN1_template_free(ppAVar7,pAVar6);
                iVar5 = it->tcount;
                tt = tt + 1;
              } while (iVar10 < iVar5);
LAB_000bb61c:
              tt = it->templates;
              iVar10 = 0;
              if (0 < iVar5) {
                do {
                  pAVar6 = asn1_do_adb(&local_38,tt,1);
                  if (pAVar6 == (ASN1_TEMPLATE *)0x0) goto LAB_000bb400;
                  ppAVar7 = asn1_get_field_ptr(&local_38,pAVar6);
                  puVar3 = local_30;
                  if (local_34 == (uchar *)0x0) break;
                  if (((1 < (int)local_34) && (*local_30 == '\0')) &&
                     (puVar1 = local_30 + 1, *puVar1 == '\0')) {
                    local_30 = local_30 + 2;
                    if (local_48[0] == '\0') {
                      ERR_put_error(0xd,0x78,0x9f,"tasn_dec.c",0x1a7);
                      goto LAB_000bb400;
                    }
                    local_34 = local_34 + -2;
                    local_48[0] = *puVar1;
                    goto LAB_000bb380;
                  }
                  if (it->tcount + -1 == iVar10) {
                    uVar8 = 0;
                  }
                  else {
                    uVar8 = pAVar6->flags & 1;
                  }
                  iVar5 = asn1_template_ex_d2i(ppAVar7,&local_30,local_34,pAVar6,uVar8,param_6);
                  if (iVar5 == 0) goto LAB_000bb9b4;
                  if (iVar5 == -1) {
                    ASN1_template_free(ppAVar7,pAVar6);
                  }
                  else {
                    local_34 = puVar3 + ((int)local_34 - (int)local_30);
                  }
                  iVar10 = iVar10 + 1;
                  tt = tt + 1;
                } while (iVar10 < it->tcount);
              }
            }
            if (local_48[0] != '\0') {
              if ((((int)local_34 < 2) || (*local_30 != '\0')) || (local_30[1] != '\0')) {
                ERR_put_error(0xd,0x78,0x89,"tasn_dec.c",0x1ce);
                break;
              }
              local_30 = local_30 + 2;
            }
LAB_000bb380:
            if ((uVar2 == '\0') && (local_34 != (uchar *)0x0)) {
              ERR_put_error(0xd,0x78,0x94,"tasn_dec.c",0x1d3);
              break;
            }
LAB_000bb3b8:
            if (iVar10 < it->tcount) {
              iVar10 = iVar10 + 1;
              pAVar6 = asn1_do_adb(&local_38,tt,1);
              tt = tt + 1;
              if (pAVar6 != (ASN1_TEMPLATE *)0x0) {
                if ((int)(pAVar6->flags << 0x1f) < 0) goto code_r0x000bb3ae;
                ERR_put_error(0xd,0x78,0x79,"tasn_dec.c",0x1e7);
LAB_000bb9b4:
                ASN1_item_ex_free(&local_38,it);
LAB_000bb96c:
                ERR_add_error_data(4,"Field=",pAVar6->field_name,", Type=",it->sname);
                goto switchD_000bb346_caseD_7;
              }
              break;
            }
            iVar5 = asn1_enc_save(&local_38,local_3c,(int)local_30 - (int)local_3c,it);
            if ((iVar5 == 0) ||
               ((local_74 != (code *)0x0 && (iVar5 = (*local_74)(5,&local_38,it,0), iVar5 == 0))))
            goto LAB_000bb3e6;
LAB_000bb85e:
            local_3c = local_30;
            goto LAB_000bb51c;
          }
          iVar5 = 0x176;
          goto LAB_000bb818;
        case '\x02':
          if (local_74 == (code *)0x0) {
LAB_000bb936:
            iVar5 = ASN1_item_ex_new(&local_38,it);
            if (iVar5 == 0) {
              iVar5 = 0x13f;
              goto LAB_000bb924;
            }
            iVar5 = it->tcount;
LAB_000bb706:
            pAVar6 = it->templates;
            iVar10 = 0;
            local_30 = local_3c;
            if (0 < iVar5) {
              do {
                ppAVar7 = asn1_get_field_ptr(&local_38,pAVar6);
                iVar5 = asn1_template_ex_d2i(ppAVar7,&local_30,local_34,pAVar6,1,param_6);
                if (iVar5 != -1) {
                  if (iVar5 < 1) {
                    ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",0x152);
                    ASN1_item_ex_free(&local_38,it);
                    if (pAVar6 == (ASN1_TEMPLATE *)0x0) goto LAB_000bb408;
                    goto LAB_000bb96c;
                  }
                  iVar5 = it->tcount;
                  break;
                }
                iVar5 = it->tcount;
                iVar10 = iVar10 + 1;
                pAVar6 = pAVar6 + 1;
              } while (iVar10 < iVar5);
            }
            if (iVar10 == iVar5) {
              ERR_put_error(0xd,0x78,0x8f,"tasn_dec.c",0x15e);
              break;
            }
            asn1_set_choice_selector(&local_38,iVar10,it);
            if ((local_74 == (code *)0x0) || (iVar5 = (*local_74)(5,&local_38,it,0), iVar5 != 0))
            goto LAB_000bb85e;
          }
          else {
            iVar5 = (*local_74)(4,&local_38,it,0);
            if (iVar5 != 0) {
              if (local_38 == (ASN1_VALUE *)0x0) goto LAB_000bb936;
              iVar10 = asn1_get_choice_selector(&local_38,it);
              iVar5 = it->tcount;
              if ((-1 < iVar10) && (iVar10 < iVar5)) {
                pAVar6 = it->templates;
                ppAVar7 = asn1_get_field_ptr(&local_38,pAVar6 + iVar10);
                ASN1_template_free(ppAVar7,pAVar6 + iVar10);
                asn1_set_choice_selector(&local_38,-1,it);
                iVar5 = it->tcount;
              }
              goto LAB_000bb706;
            }
          }
LAB_000bb3e6:
          ERR_put_error(0xd,0x78,100,"tasn_dec.c",0x1f7);
          break;
        case '\x03':
          iVar5 = (**(code **)(pcVar13 + 8))(&local_38,&local_3c,local_5c);
          if (iVar5 != 0) goto LAB_000bb51c;
          iVar5 = 0x12f;
LAB_000bb924:
          ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",iVar5);
          break;
        case '\x04':
          iVar5 = (**(code **)(pcVar13 + 0x10))
                            (&local_38,&local_3c,local_5c,it,0xffffffff,0,0,param_6);
joined_r0x000bb8c2:
          if (iVar5 != 0) goto LAB_000bb51c;
          goto switchD_000bb346_caseD_7;
        case '\x05':
          local_30 = local_3c;
          iVar5 = asn1_check_tlen_constprop_1(0,local_2c,local_50,0,0,&local_30,local_5c,1,param_6);
          if (iVar5 != 0) {
            if (local_50[0] == '\0') {
              if ((local_2c[0] < (ASN1_VALUE *)0x1f) &&
                 ((it->utype & *(uint *)(&tag2bit + (int)local_2c[0] * 4)) != 0)) {
                iVar5 = asn1_d2i_ex_primitive
                                  (&local_38,&local_3c,local_34,it,local_2c[0],0,0,param_6);
                goto joined_r0x000bb8c2;
              }
              ERR_put_error(0xd,0x78,0x8c,"tasn_dec.c",0xec);
            }
            else {
              ERR_put_error(0xd,0x78,0x8b,"tasn_dec.c",0xe4);
            }
            break;
          }
          iVar5 = 0xdb;
LAB_000bb818:
          ERR_put_error(0xd,0x78,0x3a,"tasn_dec.c",iVar5);
          break;
        default:
          goto switchD_000bb346_caseD_7;
        }
LAB_000bb400:
        ASN1_item_ex_free(&local_38,it);
LAB_000bb408:
        ERR_add_error_data(2,"Type=",it->sname);
switchD_000bb346_caseD_7:
        iVar10 = 0x29d;
        goto LAB_000bb420;
      }
LAB_000bb53c:
      if (local_58[0] != '\0') {
        ERR_put_error(0xd,0x83,0x89,"tasn_dec.c",0x2a7);
        goto LAB_000bb430;
      }
      goto LAB_000bb474;
    }
    iVar5 = 0x286;
LAB_000bb898:
    ERR_put_error(0xd,0x83,0x41,"tasn_dec.c",iVar5);
    goto LAB_000bb430;
  }
  if ((int)(uVar8 << 0x1c) < 0) {
    iVar5 = ASN1_item_ex_d2i((ASN1_VALUE **)param_1,&local_3c,(long)param_3,param_4->item,
                             param_4->tag,uVar8 & 0xc0,param_5,param_6);
    iVar10 = 0x2b0;
    if (iVar5 != 0) {
LAB_000bb46a:
      if (iVar5 == -1) {
        return 0xffffffff;
      }
LAB_000bb474:
      *param_2 = local_3c;
      return 1;
    }
  }
  else {
    iVar5 = ASN1_item_ex_d2i((ASN1_VALUE **)param_1,&local_3c,(long)param_3,param_4->item,-1,
                             uVar8 & 0x400,param_5,param_6);
    if (iVar5 != 0) goto LAB_000bb46a;
    iVar10 = 0x2b9;
  }
LAB_000bb420:
  ERR_put_error(0xd,0x83,0x3a,"tasn_dec.c",iVar10);
LAB_000bb430:
  ASN1_template_free((ASN1_VALUE **)param_1,param_4);
  return 0;
code_r0x000bb3ae:
  ppAVar7 = asn1_get_field_ptr(&local_38,pAVar6);
  ASN1_template_free(ppAVar7,pAVar6);
  goto LAB_000bb3b8;
code_r0x000bb534:
  if ((int)local_5c < 1) goto LAB_000bb53c;
  goto LAB_000bb312;
}

