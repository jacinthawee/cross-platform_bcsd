
ASN1_OCTET_STRING *
s2i_skey_id(undefined4 param_1,ASN1_OCTET_STRING *param_2,ASN1_OCTET_STRING *param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  ASN1_OCTET_STRING *pAVar4;
  uchar *puVar5;
  int iVar6;
  int iVar7;
  ASN1_OCTET_STRING *pAVar8;
  X509_EXTENSION *ext;
  X509_NAME *pXVar9;
  GENERAL_NAME *pGVar10;
  int *len;
  X509 *x;
  GENERAL_NAMES *pGVar11;
  undefined4 uVar12;
  ASN1_OCTET_STRING *pAVar13;
  undefined4 uVar14;
  int iVar15;
  ASN1_INTEGER *pAVar16;
  int iVar17;
  char *pcVar18;
  code *pcVar19;
  int iStack_98;
  int iStack_94;
  undefined *puStack_90;
  ASN1_OCTET_STRING *pAStack_8c;
  ASN1_OCTET_STRING *pAStack_88;
  code *pcStack_84;
  undefined4 local_70;
  undefined4 local_6c;
  undefined *local_68;
  ASN1_OCTET_STRING *local_60;
  ASN1_OCTET_STRING aAStack_5c [4];
  int local_1c;
  
  puStack_90 = PTR___stack_chk_guard_006aabf0;
  local_68 = &_gp;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar13 = param_3;
  iVar2 = (*(code *)PTR_strcmp_006aac20)(param_3,"hash");
  if (iVar2 == 0) {
    param_3 = (ASN1_OCTET_STRING *)(**(code **)(local_68 + -0x673c))();
    if (param_3 == (ASN1_OCTET_STRING *)0x0) {
      pAVar13 = (ASN1_OCTET_STRING *)&DAT_00000041;
      local_70 = 0x70;
      (**(code **)(local_68 + -0x6eb0))(0x22,0x73,0x41,"v3_skey.c");
      pAVar8 = (ASN1_OCTET_STRING *)0x0;
    }
    else {
      if (param_2 == (ASN1_OCTET_STRING *)0x0) {
LAB_00592974:
        pcVar19 = *(code **)(local_68 + -0x6eb0);
        pAVar13 = (ASN1_OCTET_STRING *)0x72;
        local_70 = 0x77;
        goto LAB_005928e4;
      }
      pAVar8 = param_3;
      if (param_2->length == 1) goto LAB_00592858;
      if ((int *)param_2->flags == (int *)0x0) {
        if ((int *)param_2->data == (int *)0x0) goto LAB_00592974;
        puVar3 = *(undefined4 **)(*(int *)(*(int *)param_2->data + 0x18) + 4);
      }
      else {
        puVar3 = *(undefined4 **)(*(int *)(*(int *)param_2->flags + 0x14) + 4);
      }
      param_2 = aAStack_5c;
      if (puVar3 == (undefined4 *)0x0) {
        pcVar19 = *(code **)(local_68 + -0x6eb0);
        pAVar13 = (ASN1_OCTET_STRING *)0x72;
        local_70 = 0x80;
LAB_005928e4:
        (*pcVar19)(0x22,0x73,pAVar13,"v3_skey.c");
      }
      else {
        uVar12 = puVar3[2];
        uVar14 = *puVar3;
        local_70 = (**(code **)(local_68 + -0x781c))();
        local_6c = 0;
        pAVar13 = param_2;
        iVar2 = (**(code **)(local_68 + -0x73dc))(uVar12,uVar14,param_2,&local_60);
        if (iVar2 != 0) {
          iVar2 = (**(code **)(local_68 + -0x70d4))(param_3,param_2);
          pAVar13 = local_60;
          if (iVar2 != 0) goto LAB_00592858;
          pcVar19 = *(code **)(local_68 + -0x6eb0);
          pAVar13 = (ASN1_OCTET_STRING *)&DAT_00000041;
          local_70 = 0x88;
          goto LAB_005928e4;
        }
      }
      (**(code **)(local_68 + -0x6624))(param_3);
      pAVar8 = (ASN1_OCTET_STRING *)0x0;
    }
  }
  else {
    param_2 = (ASN1_OCTET_STRING *)(**(code **)(local_68 + -0x673c))(4);
    if (param_2 == (ASN1_OCTET_STRING *)0x0) {
      pAVar13 = (ASN1_OCTET_STRING *)&DAT_00000041;
      local_70 = 0x56;
      (**(code **)(local_68 + -0x6eb0))(0x22,0x70,0x41,"v3_skey.c");
      pAVar8 = (ASN1_OCTET_STRING *)0x0;
    }
    else {
      puVar5 = string_to_hex((char *)param_3,(long *)&local_60);
      param_2->data = puVar5;
      if (puVar5 == (uchar *)0x0) {
        (**(code **)(local_68 + -0x6624))(param_2);
        pAVar8 = (ASN1_OCTET_STRING *)0x0;
      }
      else {
        param_2->length = (int)local_60;
        pAVar8 = param_2;
      }
    }
  }
LAB_00592858:
  if (local_1c == *(int *)puStack_90) {
    return pAVar8;
  }
  pcStack_84 = s2i_ASN1_OCTET_STRING;
  (**(code **)(local_68 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_94 = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar8 = pAVar13;
  pAStack_8c = param_2;
  pAStack_88 = param_3;
  pAVar4 = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(4);
  if (pAVar4 == (ASN1_OCTET_STRING *)0x0) {
    pAVar8 = (ASN1_OCTET_STRING *)&DAT_00000041;
    len = (int *)&DAT_00000070;
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x70,0x41,"v3_skey.c",0x56);
    pAVar4 = (ASN1_OCTET_STRING *)0x0;
  }
  else {
    len = &iStack_98;
    puVar5 = string_to_hex((char *)pAVar13,len);
    pAVar4->data = puVar5;
    if (puVar5 == (uchar *)0x0) {
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(pAVar4);
      pAVar4 = (ASN1_OCTET_STRING *)0x0;
    }
    else {
      pAVar4->length = iStack_98;
    }
  }
  if (iStack_94 == *(int *)puVar1) {
    return pAVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar17 = 0;
  iVar15 = 0;
  iVar2 = 0;
  while (iVar6 = (*(code *)PTR_sk_num_006a7f2c)(pAVar8), iVar2 < iVar6) {
    iVar6 = (*(code *)PTR_sk_value_006a7f24)(pAVar8,iVar2);
    uVar12 = *(undefined4 *)(iVar6 + 4);
    iVar7 = (*(code *)PTR_strcmp_006aac20)(uVar12,"keyid");
    if (iVar7 == 0) {
      if (*(int *)(iVar6 + 8) == 0) {
        iVar15 = 1;
        iVar2 = iVar2 + 1;
      }
      else {
        iVar15 = 1;
        iVar6 = (*(code *)PTR_strcmp_006aac20)(*(int *)(iVar6 + 8),"always");
        iVar2 = iVar2 + 1;
        if (iVar6 == 0) {
          iVar15 = 2;
        }
      }
    }
    else {
      iVar17 = (*(code *)PTR_strcmp_006aac20)(uVar12,"issuer");
      if (iVar17 != 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x77,0x78,"v3_akey.c",0x8f);
        (*(code *)PTR_ERR_add_error_data_006a9264)(2,"name=",*(undefined4 *)(iVar6 + 4));
        return (ASN1_OCTET_STRING *)0x0;
      }
      if (*(int *)(iVar6 + 8) == 0) {
        iVar17 = 1;
        iVar2 = iVar2 + 1;
      }
      else {
        iVar17 = 1;
        iVar6 = (*(code *)PTR_strcmp_006aac20)(*(int *)(iVar6 + 8),"always");
        iVar2 = iVar2 + 1;
        if (iVar6 == 0) {
          iVar17 = 2;
        }
      }
    }
  }
  if (len != (int *)0x0) {
    x = (X509 *)len[1];
    if (x != (X509 *)0x0) {
      if (iVar15 == 0) {
LAB_00592c2c:
        pAVar13 = (ASN1_OCTET_STRING *)0x0;
        if (iVar17 == 0) {
LAB_00592c38:
          pAVar16 = (ASN1_INTEGER *)0x0;
          pAVar8 = (ASN1_OCTET_STRING *)AUTHORITY_KEYID_new();
          if (pAVar8 != (ASN1_OCTET_STRING *)0x0) {
            pGVar11 = (GENERAL_NAMES *)0x0;
            goto LAB_00592c50;
          }
          pcVar18 = (char *)0x0;
          goto LAB_00592efc;
        }
LAB_00592ecc:
        pAVar13 = (ASN1_OCTET_STRING *)0x0;
      }
      else {
        iVar2 = X509_get_ext_by_NID(x,0x52,-1);
        if ((iVar2 < 0) || (ext = X509_get_ext(x,iVar2), ext == (X509_EXTENSION *)0x0)) {
          if (iVar15 == 2) {
LAB_00592e7c:
            uVar14 = 0x7b;
            uVar12 = 0xa6;
            goto LAB_00592ea4;
          }
          goto LAB_00592c2c;
        }
        pAVar13 = (ASN1_OCTET_STRING *)X509V3_EXT_d2i(ext);
        if (iVar15 != 2) {
          if (iVar17 == 0) goto LAB_00592c38;
          if (pAVar13 != (ASN1_OCTET_STRING *)0x0) goto LAB_00592da4;
          goto LAB_00592ecc;
        }
        if (pAVar13 == (ASN1_OCTET_STRING *)0x0) goto LAB_00592e7c;
        if (iVar17 == 0) goto LAB_00592c38;
LAB_00592da4:
        if (iVar17 != 2) goto LAB_00592c38;
      }
      pXVar9 = X509_get_issuer_name(x);
      pcVar18 = (char *)(*(code *)PTR_X509_NAME_dup_006a823c)(pXVar9);
      pAVar16 = X509_get_serialNumber(x);
      pAVar16 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_STRING_dup_006a9ddc)(pAVar16);
      if ((pcVar18 == (char *)0x0) || (pAVar16 == (ASN1_INTEGER *)0x0)) {
        uVar14 = 0x7a;
        uVar12 = 0xb1;
      }
      else {
        pAVar8 = (ASN1_OCTET_STRING *)AUTHORITY_KEYID_new();
        if (pAVar8 == (ASN1_OCTET_STRING *)0x0) goto LAB_00592efc;
        pGVar11 = (GENERAL_NAMES *)(*(code *)PTR_sk_new_null_006a80a4)();
        if (((pGVar11 != (GENERAL_NAMES *)0x0) &&
            (pGVar10 = GENERAL_NAME_new(), pGVar10 != (GENERAL_NAME *)0x0)) &&
           (iVar2 = (*(code *)PTR_sk_push_006a80a8)(pGVar11,pGVar10), iVar2 != 0)) {
          (pGVar10->d).ptr = pcVar18;
          pGVar10->type = 4;
LAB_00592c50:
          pAVar8->type = (int)pGVar11;
          pAVar8->data = (uchar *)pAVar16;
          pAVar8->length = (int)pAVar13;
          return pAVar8;
        }
        uVar14 = 0x41;
        uVar12 = 0xbe;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x77,uVar14,"v3_akey.c",uVar12);
LAB_00592efc:
      (*(code *)PTR_X509_NAME_free_006a80f8)(pcVar18);
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(pAVar16);
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(pAVar13);
      return (ASN1_OCTET_STRING *)0x0;
    }
    if (*len == 1) {
      pAVar13 = (ASN1_OCTET_STRING *)AUTHORITY_KEYID_new();
      return pAVar13;
    }
  }
  uVar14 = 0x79;
  uVar12 = 0x99;
LAB_00592ea4:
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x77,uVar14,"v3_akey.c",uVar12);
  return (ASN1_OCTET_STRING *)0x0;
}

