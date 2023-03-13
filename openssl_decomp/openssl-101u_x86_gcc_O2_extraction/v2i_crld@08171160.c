
_STACK * v2i_crld(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  char *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  CONF_VALUE *cnf;
  int iVar4;
  void *pvVar5;
  _STACK *p_Var6;
  _STACK *st;
  X509_NAME *nm;
  stack_st_CONF_VALUE *dn_sk;
  undefined4 *puVar7;
  GENERAL_NAMES *pGVar8;
  byte *pbVar9;
  byte *pbVar10;
  GENERAL_NAME *a;
  byte *pbVar11;
  undefined uVar12;
  undefined uVar13;
  bool bVar14;
  byte bVar15;
  undefined auStack_3c [8];
  _STACK *local_34;
  int local_30;
  int local_2c;
  int *local_28;
  _STACK *local_24;
  int *local_20;
  
  bVar15 = 0;
  local_24 = sk_new_null();
  if (local_24 == (_STACK *)0x0) {
    a = (GENERAL_NAME *)0x0;
    p_Var6 = (_STACK *)0x0;
  }
  else {
    local_30 = 0;
    while( true ) {
      iVar3 = sk_num(param_3);
      if (iVar3 <= local_30) {
        return local_24;
      }
      cnf = (CONF_VALUE *)sk_value(param_3,local_30);
      if (cnf->value != (char *)0x0) break;
      local_34 = (_STACK *)X509V3_get_section(param_2,cnf->name);
      if (local_34 == (_STACK *)0x0) goto LAB_081713fd;
      local_28 = (int *)ASN1_item_new((ASN1_ITEM *)DIST_POINT_it);
      if (local_28 == (int *)0x0) {
LAB_081713ea:
        X509V3_section_free(param_2,(stack_st_CONF_VALUE *)local_34);
        goto LAB_081713fd;
      }
      local_20 = local_28 + 1;
      for (iVar3 = 0; iVar4 = sk_num(local_34), iVar3 < iVar4; iVar3 = iVar3 + 1) {
        uVar12 = auStack_3c < &DAT_00000008;
        uVar13 = &stack0x00000000 == (undefined *)0x44;
        pvVar5 = sk_value(local_34,iVar3);
        pbVar10 = *(byte **)((int)pvVar5 + 4);
        iVar4 = 9;
        pbVar9 = pbVar10;
        pbVar11 = (byte *)0x822d7f3;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          uVar12 = *pbVar9 < *pbVar11;
          uVar13 = *pbVar9 == *pbVar11;
          pbVar9 = pbVar9 + (uint)bVar15 * -2 + 1;
          pbVar11 = pbVar11 + (uint)bVar15 * -2 + 1;
        } while ((bool)uVar13);
        bVar14 = (!(bool)uVar12 && !(bool)uVar13) == (bool)uVar12;
        if (bVar14) {
          pcVar1 = *(char **)((int)pvVar5 + 8);
          if (*pcVar1 == '@') {
            p_Var6 = (_STACK *)X509V3_get_section(param_2,pcVar1 + 1);
          }
          else {
            p_Var6 = (_STACK *)X509V3_parse_list(pcVar1);
          }
          if (p_Var6 == (_STACK *)0x0) {
            ERR_put_error(0x22,0x9c,0x96,"v3_crld.c",0x66);
          }
          else {
            st = (_STACK *)
                 v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,param_2,(stack_st_CONF_VALUE *)p_Var6);
            if (*pcVar1 == '@') {
              X509V3_section_free(param_2,(stack_st_CONF_VALUE *)p_Var6);
            }
            else {
              sk_pop_free(p_Var6,X509V3_conf_free);
            }
            if (st != (_STACK *)0x0) {
              p_Var6 = (_STACK *)0x0;
              if (*local_28 == 0) {
LAB_081714c0:
                puVar7 = (undefined4 *)ASN1_item_new((ASN1_ITEM *)DIST_POINT_NAME_it);
                *local_28 = (int)puVar7;
                if (puVar7 != (undefined4 *)0x0) {
                  if (st == (_STACK *)0x0) {
                    puVar7[1] = p_Var6;
                    *puVar7 = 1;
                  }
                  else {
                    puVar7[1] = st;
                    *puVar7 = 0;
                  }
                  goto LAB_081712dc;
                }
              }
              else {
LAB_0817138b:
                ERR_put_error(0x22,0x9e,0xa0,"v3_crld.c",0x9c);
              }
              if (st != (_STACK *)0x0) {
                sk_pop_free(st,GENERAL_NAME_free);
              }
LAB_081713c1:
              if (p_Var6 != (_STACK *)0x0) {
                sk_pop_free(p_Var6,X509_NAME_ENTRY_free);
              }
            }
          }
LAB_081713d6:
          ASN1_item_free((ASN1_VALUE *)local_28,(ASN1_ITEM *)DIST_POINT_it);
          goto LAB_081713ea;
        }
        iVar4 = 0xd;
        pbVar9 = pbVar10;
        pbVar11 = (byte *)0x822d801;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar14 = *pbVar9 == *pbVar11;
          pbVar9 = pbVar9 + (uint)bVar15 * -2 + 1;
          pbVar11 = pbVar11 + (uint)bVar15 * -2 + 1;
        } while (bVar14);
        if (bVar14) {
          nm = X509_NAME_new();
          if (nm != (X509_NAME *)0x0) {
            dn_sk = X509V3_get_section(param_2,*(char **)((int)pvVar5 + 8));
            if (dn_sk != (stack_st_CONF_VALUE *)0x0) {
              local_2c = X509V3_NAME_from_section(nm,dn_sk,0x1001);
              X509V3_section_free(param_2,dn_sk);
              p_Var6 = (_STACK *)nm->entries;
              nm->entries = (stack_st_X509_NAME_ENTRY *)0x0;
              X509_NAME_free(nm);
              if ((local_2c != 0) && (iVar4 = sk_num(p_Var6), 0 < iVar4)) {
                iVar4 = sk_num(p_Var6);
                pvVar5 = sk_value(p_Var6,iVar4 + -1);
                if (*(int *)((int)pvVar5 + 8) == 0) {
                  st = (_STACK *)0x0;
                  if (*local_28 == 0) {
                    st = (_STACK *)0x0;
                    goto LAB_081714c0;
                  }
                  goto LAB_0817138b;
                }
                ERR_put_error(0x22,0x9e,0xa1,"v3_crld.c",0x94);
              }
              goto LAB_081713c1;
            }
            ERR_put_error(0x22,0x9e,0x96,"v3_crld.c",0x84);
          }
          goto LAB_081713d6;
        }
        iVar4 = 8;
        pbVar9 = pbVar10;
        pbVar11 = (byte *)0x822d777;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar14 = *pbVar9 == *pbVar11;
          pbVar9 = pbVar9 + (uint)bVar15 * -2 + 1;
          pbVar11 = pbVar11 + (uint)bVar15 * -2 + 1;
        } while (bVar14);
        if (bVar14) {
          iVar4 = set_reasons();
          if (iVar4 == 0) goto LAB_081713d6;
        }
        else {
          iVar4 = 10;
          pbVar9 = (byte *)"CRLissuer";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar14 = *pbVar10 == *pbVar9;
            pbVar10 = pbVar10 + (uint)bVar15 * -2 + 1;
            pbVar9 = pbVar9 + (uint)bVar15 * -2 + 1;
          } while (bVar14);
          if (bVar14) {
            pcVar1 = *(char **)((int)pvVar5 + 8);
            if (*pcVar1 == '@') {
              p_Var6 = (_STACK *)X509V3_get_section(param_2,pcVar1 + 1);
            }
            else {
              p_Var6 = (_STACK *)X509V3_parse_list(pcVar1);
            }
            if (p_Var6 == (_STACK *)0x0) {
              ERR_put_error(0x22,0x9c,0x96,"v3_crld.c",0x66);
              local_28[2] = 0;
            }
            else {
              pGVar8 = v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,param_2,
                                         (stack_st_CONF_VALUE *)p_Var6);
              if (*pcVar1 == '@') {
                X509V3_section_free(param_2,(stack_st_CONF_VALUE *)p_Var6);
              }
              else {
                sk_pop_free(p_Var6,X509V3_conf_free);
              }
              local_28[2] = (int)pGVar8;
              if (pGVar8 != (GENERAL_NAMES *)0x0) goto LAB_081712dc;
            }
            goto LAB_081713d6;
          }
        }
LAB_081712dc:
      }
      X509V3_section_free(param_2,(stack_st_CONF_VALUE *)local_34);
      iVar3 = sk_push(local_24,local_28);
      if (iVar3 == 0) {
        p_Var6 = (_STACK *)0x0;
        ASN1_item_free((ASN1_VALUE *)local_28,(ASN1_ITEM *)DIST_POINT_it);
        a = (GENERAL_NAME *)0x0;
        goto LAB_08171628;
      }
LAB_0817121f:
      local_30 = local_30 + 1;
    }
    a = v2i_GENERAL_NAME(param_1,param_2,cnf);
    if (a == (GENERAL_NAME *)0x0) {
LAB_081713fd:
      a = (GENERAL_NAME *)0x0;
      p_Var6 = (_STACK *)0x0;
      goto LAB_08171646;
    }
    p_Var6 = (_STACK *)GENERAL_NAMES_new();
    if ((p_Var6 == (_STACK *)0x0) || (iVar3 = sk_push(p_Var6,a), iVar3 == 0)) goto LAB_08171628;
    puVar7 = (undefined4 *)ASN1_item_new((ASN1_ITEM *)DIST_POINT_it);
    if (puVar7 != (undefined4 *)0x0) {
      iVar3 = sk_push(local_24,puVar7);
      if (iVar3 == 0) {
        a = (GENERAL_NAME *)0x0;
        ASN1_item_free((ASN1_VALUE *)puVar7,(ASN1_ITEM *)DIST_POINT_it);
        goto LAB_08171628;
      }
      puVar2 = (undefined4 *)ASN1_item_new((ASN1_ITEM *)DIST_POINT_NAME_it);
      *puVar7 = puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[1] = p_Var6;
        *puVar2 = 0;
        goto LAB_0817121f;
      }
    }
    a = (GENERAL_NAME *)0x0;
  }
LAB_08171628:
  ERR_put_error(0x22,0x86,0x41,"v3_crld.c",0x150);
LAB_08171646:
  GENERAL_NAME_free(a);
  GENERAL_NAMES_free((GENERAL_NAMES *)p_Var6);
  sk_pop_free(local_24,DIST_POINT_free);
  return (_STACK *)0x0;
}

