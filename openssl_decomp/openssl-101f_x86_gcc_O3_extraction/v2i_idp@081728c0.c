
int * v2i_idp(undefined4 param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  char *line;
  int iVar1;
  CONF_VALUE *value;
  _STACK *p_Var2;
  _STACK *st;
  X509_NAME *nm;
  stack_st_CONF_VALUE *dn_sk;
  void *pvVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined uVar8;
  undefined uVar9;
  bool bVar10;
  byte bVar11;
  int *asn1_bool;
  int local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  
  bVar11 = 0;
  local_28 = (int *)ASN1_item_new((ASN1_ITEM *)ISSUING_DIST_POINT_it);
  if (local_28 == (int *)0x0) {
    ERR_put_error(0x22,0x9d,0x41,"v3_crld.c",0x1f5);
LAB_08172a8a:
    ASN1_item_free((ASN1_VALUE *)local_28,(ASN1_ITEM *)ISSUING_DIST_POINT_it);
    return (int *)0x0;
  }
  local_24 = local_28 + 3;
  local_20 = local_28 + 4;
  local_2c = 0;
  do {
    iVar1 = sk_num(param_3);
    if (iVar1 <= local_2c) {
      return local_28;
    }
    uVar8 = &local_2c < &DAT_00000008;
    uVar9 = &stack0x00000000 == (undefined *)0x34;
    value = (CONF_VALUE *)sk_value(param_3,local_2c);
    pbVar6 = (byte *)value->name;
    iVar1 = 9;
    line = value->value;
    pbVar5 = pbVar6;
    pbVar7 = (byte *)0x822d353;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      uVar8 = *pbVar5 < *pbVar7;
      uVar9 = *pbVar5 == *pbVar7;
      pbVar5 = pbVar5 + (uint)bVar11 * -2 + 1;
      pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
    } while ((bool)uVar9);
    bVar10 = (!(bool)uVar8 && !(bool)uVar9) == (bool)uVar8;
    if (bVar10) {
      if (*line == '@') {
        p_Var2 = (_STACK *)X509V3_get_section(param_2,line + 1);
      }
      else {
        p_Var2 = (_STACK *)X509V3_parse_list(line);
      }
      if (p_Var2 == (_STACK *)0x0) {
        ERR_put_error(0x22,0x9c,0x96,"v3_crld.c",0x68);
      }
      else {
        st = (_STACK *)
             v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,param_2,(stack_st_CONF_VALUE *)p_Var2);
        if (*line == '@') {
          X509V3_section_free(param_2,(stack_st_CONF_VALUE *)p_Var2);
        }
        else {
          sk_pop_free(p_Var2,X509V3_conf_free);
        }
        if (st != (_STACK *)0x0) {
          p_Var2 = (_STACK *)0x0;
          if (*local_28 == 0) {
LAB_08172b60:
            puVar4 = (undefined4 *)ASN1_item_new((ASN1_ITEM *)DIST_POINT_NAME_it);
            *local_28 = (int)puVar4;
            if (puVar4 != (undefined4 *)0x0) {
              if (st == (_STACK *)0x0) {
                puVar4[1] = p_Var2;
                *puVar4 = 1;
              }
              else {
                puVar4[1] = st;
                *puVar4 = 0;
              }
              goto LAB_0817298b;
            }
          }
          else {
LAB_08172a3f:
            ERR_put_error(0x22,0x9e,0xa0,"v3_crld.c",0xa5);
          }
          if (st != (_STACK *)0x0) {
            sk_pop_free(st,GENERAL_NAME_free);
          }
LAB_08172a75:
          if (p_Var2 != (_STACK *)0x0) {
            sk_pop_free(p_Var2,X509_NAME_ENTRY_free);
          }
        }
      }
      goto LAB_08172a8a;
    }
    iVar1 = 0xd;
    pbVar5 = pbVar6;
    pbVar7 = (byte *)0x822d361;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar10 = *pbVar5 == *pbVar7;
      pbVar5 = pbVar5 + (uint)bVar11 * -2 + 1;
      pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
    } while (bVar10);
    if (bVar10) {
      nm = X509_NAME_new();
      if (nm != (X509_NAME *)0x0) {
        dn_sk = X509V3_get_section(param_2,value->value);
        if (dn_sk != (stack_st_CONF_VALUE *)0x0) {
          iVar1 = X509V3_NAME_from_section(nm,dn_sk,0x1001);
          X509V3_section_free(param_2,dn_sk);
          p_Var2 = (_STACK *)nm->entries;
          nm->entries = (stack_st_X509_NAME_ENTRY *)0x0;
          X509_NAME_free(nm);
          if ((iVar1 != 0) && (iVar1 = sk_num(p_Var2), 0 < iVar1)) {
            iVar1 = sk_num(p_Var2);
            pvVar3 = sk_value(p_Var2,iVar1 + -1);
            if (*(int *)((int)pvVar3 + 8) == 0) {
              st = (_STACK *)0x0;
              if (*local_28 == 0) {
                st = (_STACK *)0x0;
                goto LAB_08172b60;
              }
              goto LAB_08172a3f;
            }
            ERR_put_error(0x22,0x9e,0xa1,"v3_crld.c",0x9b);
          }
          goto LAB_08172a75;
        }
        ERR_put_error(0x22,0x9e,0x96,"v3_crld.c",0x8a);
      }
      goto LAB_08172a8a;
    }
    iVar1 = 9;
    pbVar5 = pbVar6;
    pbVar7 = (byte *)"onlyuser";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar10 = *pbVar5 == *pbVar7;
      pbVar5 = pbVar5 + (uint)bVar11 * -2 + 1;
      pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
    } while (bVar10);
    if (bVar10) {
      asn1_bool = local_28 + 1;
    }
    else {
      iVar1 = 7;
      pbVar5 = pbVar6;
      pbVar7 = (byte *)"onlyCA";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar10 = *pbVar5 == *pbVar7;
        pbVar5 = pbVar5 + (uint)bVar11 * -2 + 1;
        pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
      } while (bVar10);
      if (bVar10) {
        asn1_bool = local_28 + 2;
      }
      else {
        iVar1 = 7;
        pbVar5 = pbVar6;
        pbVar7 = (byte *)"onlyAA";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar10 = *pbVar5 == *pbVar7;
          pbVar5 = pbVar5 + (uint)bVar11 * -2 + 1;
          pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
        } while (bVar10);
        if (bVar10) {
          asn1_bool = local_28 + 5;
        }
        else {
          iVar1 = 0xc;
          pbVar5 = pbVar6;
          pbVar7 = (byte *)"indirectCRL";
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar10 = *pbVar5 == *pbVar7;
            pbVar5 = pbVar5 + (uint)bVar11 * -2 + 1;
            pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
          } while (bVar10);
          asn1_bool = local_20;
          if (!bVar10) {
            iVar1 = 0x10;
            pbVar5 = (byte *)"onlysomereasons";
            do {
              if (iVar1 == 0) break;
              iVar1 = iVar1 + -1;
              bVar10 = *pbVar6 == *pbVar5;
              pbVar6 = pbVar6 + (uint)bVar11 * -2 + 1;
              pbVar5 = pbVar5 + (uint)bVar11 * -2 + 1;
            } while (bVar10);
            if (bVar10) {
              iVar1 = set_reasons();
              if (iVar1 != 0) goto LAB_0817298b;
            }
            else {
              ERR_put_error(0x22,0x9d,0x6a,"v3_crld.c",0x1ed);
              ERR_add_error_data(6,"section:",value->section,",name:",value->name,",value:",
                                 value->value);
            }
            goto LAB_08172a8a;
          }
        }
      }
    }
    iVar1 = X509V3_get_value_bool(value,asn1_bool);
    if (iVar1 == 0) goto LAB_08172a8a;
LAB_0817298b:
    local_2c = local_2c + 1;
  } while( true );
}

