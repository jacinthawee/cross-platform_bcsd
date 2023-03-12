
/* WARNING: Removing unreachable block (ram,0x005ac8bc) */
/* WARNING: Removing unreachable block (ram,0x005ac874) */
/* WARNING: Removing unreachable block (ram,0x005ac8c4) */
/* WARNING: Removing unreachable block (ram,0x005ac8d8) */
/* WARNING: Removing unreachable block (ram,0x005ac87c) */
/* WARNING: Removing unreachable block (ram,0x005ac894) */
/* WARNING: Removing unreachable block (ram,0x005ac8a0) */
/* WARNING: Removing unreachable block (ram,0x005ac8f8) */
/* WARNING: Removing unreachable block (ram,0x005ac8ac) */
/* WARNING: Removing unreachable block (ram,0x005ac8b0) */
/* WARNING: Removing unreachable block (ram,0x005ac908) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 parse_bags_constprop_1(undefined4 param_1,X509 *param_2,int *param_3,int *param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  PKCS12_SAFEBAG *bag;
  ASN1_TYPE *pAVar4;
  undefined4 uVar5;
  X509 *pXVar6;
  PKCS8_PRIV_KEY_INFO *pPVar7;
  stack_st_PKCS7 *psVar8;
  int iVar9;
  PKCS7 *p7;
  stack_st_PKCS12_SAFEBAG *psVar10;
  PKCS12 *p12;
  int *piVar11;
  int *piVar12;
  undefined4 uVar13;
  int *piVar14;
  int iVar15;
  ASN1_STRING *pAVar16;
  char *pcVar17;
  X509 *pXStack_54;
  X509 *local_30;
  PKCS12 *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iVar15 = 0;
  local_2c = *(PKCS12 **)PTR___stack_chk_guard_006aabf0;
  pXStack_54 = param_2;
  piVar11 = param_3;
  piVar14 = param_4;
  iVar3 = (*(code *)PTR_sk_num_006a7f2c)(param_1);
  if (0 < iVar3) {
    do {
      bag = (PKCS12_SAFEBAG *)(*(code *)PTR_sk_value_006a7f24)(param_1,iVar15);
      pAVar4 = PKCS12_get_attr_gen(bag->attrib,0x9c);
      if (pAVar4 == (ASN1_TYPE *)0x0) {
        pcVar17 = (char *)0x0;
      }
      else {
        pcVar17 = (pAVar4->value).ptr;
      }
      pXStack_54 = (X509 *)&DAT_0000009d;
      pAVar4 = PKCS12_get_attr_gen(bag->attrib,0x9d);
      if (pAVar4 == (ASN1_TYPE *)0x0) {
        pAVar16 = (ASN1_STRING *)0x0;
      }
      else {
        pAVar16 = (pAVar4->value).asn1_string;
      }
      iVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(bag->type);
      if (iVar3 == 0x97) {
        if ((param_3 != (int *)0x0) && (*param_3 == 0)) {
          piVar11 = (int *)0xffffffff;
          pXStack_54 = param_2;
          pPVar7 = PKCS12_decrypt_skey(bag,(char *)param_2,-1);
          if (pPVar7 != (PKCS8_PRIV_KEY_INFO *)0x0) {
            iVar3 = (*(code *)PTR_EVP_PKCS82PKEY_006a8334)(pPVar7);
            puVar1 = PTR_PKCS8_PRIV_KEY_INFO_free_006a8340;
            *param_3 = iVar3;
            (*(code *)puVar1)(pPVar7);
            if (*param_3 != 0) goto LAB_005ac120;
          }
LAB_005ac1b0:
          uVar5 = 0;
          goto LAB_005ac13c;
        }
      }
      else if (iVar3 < 0x98) {
        if (((iVar3 == 0x96) && (param_3 != (int *)0x0)) && (*param_3 == 0)) {
          iVar3 = (*(code *)PTR_EVP_PKCS82PKEY_006a8334)((bag->value).bag);
          *param_3 = iVar3;
joined_r0x005ac1a8:
          if (iVar3 == 0) goto LAB_005ac1b0;
        }
      }
      else if (iVar3 == 0x98) {
        iVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(((bag->value).bag)->type);
        if (iVar3 == 0x9e) {
          pXVar6 = PKCS12_certbag2x509(bag);
          if (pXVar6 == (X509 *)0x0) goto LAB_005ac1b0;
          piVar12 = piVar11;
          if (pAVar16 == (ASN1_STRING *)0x0) {
LAB_005ac20c:
            if ((pcVar17 != (char *)0x0) &&
               (piVar11 = (int *)(*(code *)PTR_ASN1_STRING_to_UTF8_006a9e10)(&local_30,pcVar17),
               0 < (int)piVar11)) {
              pXStack_54 = local_30;
              iVar3 = (*(code *)PTR_X509_alias_set1_006a8368)(pXVar6);
              (*(code *)PTR_CRYPTO_free_006a7f88)(local_30);
              piVar12 = piVar11;
              if (iVar3 == 0) goto LAB_005ac270;
            }
            piVar11 = piVar12;
            pXStack_54 = pXVar6;
            iVar3 = (*(code *)PTR_sk_push_006a80a8)(param_4);
            if (iVar3 != 0) goto LAB_005ac120;
          }
          else {
            piVar11 = (int *)pAVar16->length;
            pXStack_54 = (X509 *)pAVar16->data;
            iVar3 = (*(code *)PTR_X509_keyid_set1_006a8394)(pXVar6);
            piVar12 = piVar11;
            if (iVar3 != 0) goto LAB_005ac20c;
          }
LAB_005ac270:
          (*(code *)PTR_X509_free_006a7f90)(pXVar6);
          uVar5 = 0;
          goto LAB_005ac13c;
        }
      }
      else {
        piVar11 = param_3;
        if (iVar3 == 0x9b) {
          pXStack_54 = param_2;
          piVar14 = param_4;
          iVar3 = parse_bags_constprop_1((bag->value).bag);
          goto joined_r0x005ac1a8;
        }
      }
LAB_005ac120:
      iVar15 = iVar15 + 1;
      iVar3 = (*(code *)PTR_sk_num_006a7f2c)(param_1);
    } while (iVar15 < iVar3);
  }
  uVar5 = 1;
LAB_005ac13c:
  if (local_2c == *(PKCS12 **)puVar2) {
    return uVar5;
  }
  p12 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (p12 == (PKCS12 *)0x0) {
    uVar13 = 0x69;
    uVar5 = 0x59;
    goto LAB_005ac758;
  }
  if (piVar11 != (int *)0x0) {
    *piVar11 = 0;
  }
  if (piVar14 != (int *)0x0) {
    *piVar14 = 0;
  }
  if ((pXStack_54 == (X509 *)0x0) || (*(uchar *)&pXStack_54->cert_info == '\0')) {
    iVar3 = PKCS12_verify_mac(p12,(char *)0x0,0);
    if (iVar3 == 0) {
      iVar3 = PKCS12_verify_mac(p12,"",0);
      if (iVar3 == 0) {
        uVar5 = 0x6e;
        goto LAB_005ac7c4;
      }
      pXStack_54 = (X509 *)0x6395d0;
    }
    else {
      pXStack_54 = (X509 *)0x0;
    }
LAB_005ac3a0:
    iVar3 = (*(code *)PTR_sk_new_null_006a80a4)();
    if (iVar3 == 0) {
      uVar13 = 0x41;
      uVar5 = 0x7b;
LAB_005ac758:
      (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x76,uVar13,"p12_kiss.c",uVar5);
      return 0;
    }
    psVar8 = PKCS12_unpack_authsafes(p12);
    if (psVar8 == (stack_st_PKCS7 *)0x0) {
LAB_005ac4ec:
      (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x76,0x72,"p12_kiss.c",0x81);
      goto LAB_005ac514;
    }
    iVar15 = 0;
    while (iVar9 = (*(code *)PTR_sk_num_006a7f2c)(psVar8), iVar15 < iVar9) {
      p7 = (PKCS7 *)(*(code *)PTR_sk_value_006a7f24)(psVar8,iVar15);
      iVar9 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
      if (iVar9 == 0x15) {
        psVar10 = PKCS12_unpack_p7data(p7);
joined_r0x005ac4d0:
        if (psVar10 == (stack_st_PKCS12_SAFEBAG *)0x0) {
          (*(code *)PTR_sk_pop_free_006a8158)(psVar8,PTR_PKCS7_free_006a8350);
          goto LAB_005ac4ec;
        }
        iVar9 = parse_bags_constprop_1(psVar10,pXStack_54,piVar11,iVar3);
        if (iVar9 == 0) {
          (*(code *)PTR_sk_pop_free_006a8158)(psVar10,PTR_PKCS12_SAFEBAG_free_006a834c);
          (*(code *)PTR_sk_pop_free_006a8158)(psVar8,PTR_PKCS7_free_006a8350);
          goto LAB_005ac4ec;
        }
        iVar15 = iVar15 + 1;
        (*(code *)PTR_sk_pop_free_006a8158)();
      }
      else {
        if (iVar9 == 0x1a) {
          psVar10 = PKCS12_unpack_p7encdata(p7,(char *)pXStack_54,-1);
          goto joined_r0x005ac4d0;
        }
        iVar15 = iVar15 + 1;
      }
    }
    (*(code *)PTR_sk_pop_free_006a8158)(psVar8,PTR_PKCS7_free_006a8350);
    if (piVar11 != (int *)0x0) {
      if (piVar14 != (int *)0x0) {
        while (iVar15 = (*(code *)PTR_sk_pop_006a9ec4)(iVar3), iVar15 != 0) {
          while (((*piVar11 == 0 || (*piVar14 != 0)) ||
                 (iVar9 = (*(code *)PTR_X509_check_private_key_006a817c)(iVar15), iVar9 == 0))) {
            if ((__gp == 0) && (__gp = (*(code *)PTR_sk_new_null_006a80a4)(), __gp == 0)) {
              iVar9 = *piVar11;
              goto LAB_005ac520;
            }
            iVar9 = (*(code *)PTR_sk_push_006a80a8)(__gp,iVar15);
            if (iVar9 == 0) goto LAB_005ac51c;
            iVar15 = (*(code *)PTR_sk_pop_006a9ec4)(iVar3);
            if (iVar15 == 0) goto LAB_005ac640;
          }
          *piVar14 = iVar15;
        }
LAB_005ac640:
        (*(code *)PTR_sk_pop_free_006a8158)(iVar3,PTR_X509_free_006a7f90);
        return 1;
      }
      do {
        iVar15 = (*(code *)PTR_sk_pop_006a9ec4)(iVar3);
        if (iVar15 == 0) goto LAB_005ac640;
        if ((__gp == 0) && (__gp = (*(code *)PTR_sk_new_null_006a80a4)(), __gp == 0)) {
          iVar9 = *piVar11;
          goto LAB_005ac520;
        }
        iVar9 = (*(code *)PTR_sk_push_006a80a8)(__gp,iVar15);
      } while (iVar9 != 0);
      iVar9 = *piVar11;
      goto LAB_005ac520;
    }
    do {
      iVar15 = (*(code *)PTR_sk_pop_006a9ec4)(iVar3);
      if (iVar15 == 0) goto LAB_005ac640;
    } while (((__gp != 0) || (__gp = (*(code *)PTR_sk_new_null_006a80a4)(), __gp != 0)) &&
            (iVar9 = (*(code *)PTR_sk_push_006a80a8)(__gp,iVar15), iVar9 != 0));
    if (piVar14 != (int *)0x0) goto LAB_005ac53c;
  }
  else {
    iVar3 = PKCS12_verify_mac(p12,(char *)pXStack_54,-1);
    if (iVar3 != 0) goto LAB_005ac3a0;
    uVar5 = 0x72;
LAB_005ac7c4:
    iVar3 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x76,0x71,"p12_kiss.c",uVar5);
LAB_005ac514:
    iVar15 = 0;
    if (piVar11 == (int *)0x0) {
      if (piVar14 == (int *)0x0) goto LAB_005ac568;
      iVar9 = *piVar14;
LAB_005ac540:
      if (iVar9 != 0) {
        (*(code *)PTR_X509_free_006a7f90)();
      }
    }
    else {
LAB_005ac51c:
      iVar9 = *piVar11;
LAB_005ac520:
      if (iVar9 != 0) {
        (*(code *)PTR_EVP_PKEY_free_006a7f78)();
      }
      if (piVar14 != (int *)0x0) {
LAB_005ac53c:
        iVar9 = *piVar14;
        goto LAB_005ac540;
      }
    }
    if (iVar15 == 0) goto LAB_005ac568;
  }
  (*(code *)PTR_X509_free_006a7f90)(iVar15);
LAB_005ac568:
  if (iVar3 == 0) {
    return 0;
  }
  (*(code *)PTR_sk_pop_free_006a8158)(iVar3,PTR_X509_free_006a7f90);
  return 0;
}

