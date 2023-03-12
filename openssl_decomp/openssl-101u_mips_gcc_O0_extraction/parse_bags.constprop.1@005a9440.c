
/* WARNING: Removing unreachable block (ram,0x005a9d80) */
/* WARNING: Removing unreachable block (ram,0x005a9d38) */
/* WARNING: Removing unreachable block (ram,0x005a9d88) */
/* WARNING: Removing unreachable block (ram,0x005a9d9c) */
/* WARNING: Removing unreachable block (ram,0x005a9d40) */
/* WARNING: Removing unreachable block (ram,0x005a9d58) */
/* WARNING: Removing unreachable block (ram,0x005a9d64) */
/* WARNING: Removing unreachable block (ram,0x005a9de0) */
/* WARNING: Removing unreachable block (ram,0x005a9e08) */
/* WARNING: Removing unreachable block (ram,0x005a9d70) */
/* WARNING: Removing unreachable block (ram,0x005a9d74) */
/* WARNING: Removing unreachable block (ram,0x005a9e18) */
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
  X509 *pass;
  int *piVar11;
  int *piVar12;
  undefined4 uVar13;
  int *piVar14;
  int iVar15;
  ASN1_STRING *pAVar16;
  char *pcVar17;
  X509 *local_30;
  PKCS12 *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iVar15 = 0;
  local_2c = *(PKCS12 **)PTR___stack_chk_guard_006a9ae8;
  pass = param_2;
  piVar11 = param_3;
  piVar14 = param_4;
  iVar3 = (*(code *)PTR_sk_num_006a6e2c)(param_1);
  if (0 < iVar3) {
    do {
      bag = (PKCS12_SAFEBAG *)(*(code *)PTR_sk_value_006a6e24)(param_1,iVar15);
      pAVar4 = PKCS12_get_attr_gen(bag->attrib,0x9c);
      if (pAVar4 == (ASN1_TYPE *)0x0) {
        pcVar17 = (char *)0x0;
      }
      else {
        pcVar17 = (pAVar4->value).ptr;
      }
      pass = (X509 *)0x9d;
      pAVar4 = PKCS12_get_attr_gen(bag->attrib,0x9d);
      if (pAVar4 == (ASN1_TYPE *)0x0) {
        pAVar16 = (ASN1_STRING *)0x0;
      }
      else {
        pAVar16 = (pAVar4->value).asn1_string;
      }
      iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(bag->type);
      if (iVar3 == 0x97) {
        if ((param_3 != (int *)0x0) && (*param_3 == 0)) {
          piVar11 = (int *)0xffffffff;
          pass = param_2;
          pPVar7 = PKCS12_decrypt_skey(bag,(char *)param_2,-1);
          if (pPVar7 != (PKCS8_PRIV_KEY_INFO *)0x0) {
            iVar3 = (*(code *)PTR_EVP_PKCS82PKEY_006a7220)(pPVar7);
            puVar1 = PTR_PKCS8_PRIV_KEY_INFO_free_006a722c;
            *param_3 = iVar3;
            (*(code *)puVar1)(pPVar7);
            if (*param_3 != 0) goto LAB_005a9560;
          }
LAB_005a95f0:
          uVar5 = 0;
          goto LAB_005a957c;
        }
      }
      else if (iVar3 < 0x98) {
        if (((iVar3 == 0x96) && (param_3 != (int *)0x0)) && (*param_3 == 0)) {
          iVar3 = (*(code *)PTR_EVP_PKCS82PKEY_006a7220)((bag->value).bag);
          *param_3 = iVar3;
joined_r0x005a95e8:
          if (iVar3 == 0) goto LAB_005a95f0;
        }
      }
      else if (iVar3 == 0x98) {
        iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(((bag->value).bag)->type);
        if (iVar3 == 0x9e) {
          pXVar6 = PKCS12_certbag2x509(bag);
          if (pXVar6 == (X509 *)0x0) goto LAB_005a95f0;
          piVar12 = piVar11;
          if (pAVar16 == (ASN1_STRING *)0x0) {
LAB_005a964c:
            if ((pcVar17 != (char *)0x0) &&
               (piVar11 = (int *)(*(code *)PTR_ASN1_STRING_to_UTF8_006a8cf0)(&local_30,pcVar17),
               -1 < (int)piVar11)) {
              pass = local_30;
              iVar3 = (*(code *)PTR_X509_alias_set1_006a7254)(pXVar6);
              (*(code *)PTR_CRYPTO_free_006a6e88)(local_30);
              piVar12 = piVar11;
              if (iVar3 == 0) goto LAB_005a96b0;
            }
            piVar11 = piVar12;
            pass = pXVar6;
            iVar3 = (*(code *)PTR_sk_push_006a6fa8)(param_4);
            if (iVar3 != 0) goto LAB_005a9560;
          }
          else {
            piVar11 = (int *)pAVar16->length;
            pass = (X509 *)pAVar16->data;
            iVar3 = (*(code *)PTR_X509_keyid_set1_006a7284)(pXVar6);
            piVar12 = piVar11;
            if (iVar3 != 0) goto LAB_005a964c;
          }
LAB_005a96b0:
          (*(code *)PTR_X509_free_006a6e90)(pXVar6);
          uVar5 = 0;
          goto LAB_005a957c;
        }
      }
      else {
        piVar11 = param_3;
        if (iVar3 == 0x9b) {
          pass = param_2;
          piVar14 = param_4;
          iVar3 = parse_bags_constprop_1((bag->value).bag);
          goto joined_r0x005a95e8;
        }
      }
LAB_005a9560:
      iVar15 = iVar15 + 1;
      iVar3 = (*(code *)PTR_sk_num_006a6e2c)(param_1);
    } while (iVar15 < iVar3);
  }
  uVar5 = 1;
LAB_005a957c:
  if (local_2c == *(PKCS12 **)puVar2) {
    return uVar5;
  }
  p12 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (p12 == (PKCS12 *)0x0) {
    uVar13 = 0x69;
    uVar5 = 0x5b;
    goto LAB_005a9b74;
  }
  if (piVar11 != (int *)0x0) {
    *piVar11 = 0;
  }
  if (piVar14 != (int *)0x0) {
    *piVar14 = 0;
  }
  if ((pass == (X509 *)0x0) || (*(uchar *)&pass->cert_info == '\0')) {
    iVar3 = PKCS12_verify_mac(p12,(char *)0x0,0);
    if (iVar3 == 0) {
      iVar3 = PKCS12_verify_mac(p12,"",0);
      if (iVar3 == 0) {
        uVar5 = 0x73;
        goto LAB_005a9be0;
      }
      pass = (X509 *)0x638d8c;
    }
    else {
      pass = (X509 *)0x0;
    }
LAB_005a97d8:
    iVar3 = (*(code *)PTR_sk_new_null_006a6fa4)();
    if (iVar3 == 0) {
      uVar13 = 0x41;
      uVar5 = 0x7f;
LAB_005a9b74:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x76,uVar13,"p12_kiss.c",uVar5);
      return 0;
    }
    psVar8 = PKCS12_unpack_authsafes(p12);
    if (psVar8 == (stack_st_PKCS7 *)0x0) {
LAB_005a9918:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x76,0x72,"p12_kiss.c",0x84);
      goto LAB_005a9940;
    }
    iVar15 = 0;
    while (iVar9 = (*(code *)PTR_sk_num_006a6e2c)(psVar8), iVar15 < iVar9) {
      p7 = (PKCS7 *)(*(code *)PTR_sk_value_006a6e24)(psVar8,iVar15);
      iVar9 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
      if (iVar9 == 0x15) {
        psVar10 = PKCS12_unpack_p7data(p7);
joined_r0x005a98fc:
        if (psVar10 == (stack_st_PKCS12_SAFEBAG *)0x0) {
          (*(code *)PTR_sk_pop_free_006a7058)(psVar8,PTR_PKCS7_free_006a723c);
          goto LAB_005a9918;
        }
        iVar9 = parse_bags_constprop_1(psVar10,pass,piVar11,iVar3);
        if (iVar9 == 0) {
          (*(code *)PTR_sk_pop_free_006a7058)(psVar10,PTR_PKCS12_SAFEBAG_free_006a7238);
          (*(code *)PTR_sk_pop_free_006a7058)(psVar8,PTR_PKCS7_free_006a723c);
          goto LAB_005a9918;
        }
        iVar15 = iVar15 + 1;
        (*(code *)PTR_sk_pop_free_006a7058)();
      }
      else {
        if (iVar9 == 0x1a) {
          psVar10 = PKCS12_unpack_p7encdata(p7,(char *)pass,-1);
          goto joined_r0x005a98fc;
        }
        iVar15 = iVar15 + 1;
      }
    }
    (*(code *)PTR_sk_pop_free_006a7058)(psVar8,PTR_PKCS7_free_006a723c);
    if (piVar14 != (int *)0x0) {
      if (piVar11 != (int *)0x0) {
LAB_005a9a08:
        iVar15 = (*(code *)PTR_sk_pop_006a8da4)(iVar3);
        if (iVar15 != 0) {
          do {
            if ((*piVar11 != 0) && (*piVar14 == 0)) {
              (*(code *)PTR_ERR_set_mark_006a9238)();
              iVar9 = (*(code *)PTR_X509_check_private_key_006a707c)(iVar15,*piVar11);
              puVar2 = PTR_ERR_pop_to_mark_006a923c;
              if (iVar9 != 0) goto code_r0x005a9b50;
              (*(code *)PTR_ERR_pop_to_mark_006a923c)();
            }
            if ((__gp == 0) && (__gp = (*(code *)PTR_sk_new_null_006a6fa4)(), __gp == 0)) {
              iVar9 = *piVar11;
              goto LAB_005a994c;
            }
            iVar9 = (*(code *)PTR_sk_push_006a6fa8)(__gp,iVar15);
            if (iVar9 == 0) goto LAB_005a9948;
            iVar15 = (*(code *)PTR_sk_pop_006a8da4)(iVar3);
            if (iVar15 == 0) break;
          } while( true );
        }
        goto LAB_005a9a74;
      }
      do {
        iVar15 = (*(code *)PTR_sk_pop_006a8da4)(iVar3);
        if (iVar15 == 0) goto LAB_005a9a74;
      } while (((__gp != 0) || (__gp = (*(code *)PTR_sk_new_null_006a6fa4)(), __gp != 0)) &&
              (iVar9 = (*(code *)PTR_sk_push_006a6fa8)(__gp,iVar15), iVar9 != 0));
      if (piVar14 == (int *)0x0) goto LAB_005a9988;
      goto LAB_005a9968;
    }
    if (piVar11 != (int *)0x0) {
      do {
        iVar15 = (*(code *)PTR_sk_pop_006a8da4)(iVar3);
        if (iVar15 == 0) goto LAB_005a9a74;
        if ((__gp == 0) && (__gp = (*(code *)PTR_sk_new_null_006a6fa4)(), __gp == 0)) {
          iVar9 = *piVar11;
          goto LAB_005a994c;
        }
        iVar9 = (*(code *)PTR_sk_push_006a6fa8)(__gp,iVar15);
      } while (iVar9 != 0);
      iVar9 = *piVar11;
      goto LAB_005a994c;
    }
    do {
      iVar15 = (*(code *)PTR_sk_pop_006a8da4)(iVar3);
      if (iVar15 == 0) {
LAB_005a9a74:
        (*(code *)PTR_sk_pop_free_006a7058)(iVar3,PTR_X509_free_006a6e90);
        return 1;
      }
    } while (((__gp != 0) || (__gp = (*(code *)PTR_sk_new_null_006a6fa4)(), __gp != 0)) &&
            (iVar9 = (*(code *)PTR_sk_push_006a6fa8)(__gp,iVar15), iVar9 != 0));
  }
  else {
    iVar3 = PKCS12_verify_mac(p12,(char *)pass,-1);
    if (iVar3 != 0) goto LAB_005a97d8;
    uVar5 = 0x77;
LAB_005a9be0:
    iVar3 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x76,0x71,"p12_kiss.c",uVar5);
LAB_005a9940:
    iVar15 = 0;
    if (piVar11 == (int *)0x0) {
      if (piVar14 == (int *)0x0) goto LAB_005a9994;
      iVar9 = *piVar14;
LAB_005a996c:
      if (iVar9 != 0) {
        (*(code *)PTR_X509_free_006a6e90)();
      }
    }
    else {
LAB_005a9948:
      iVar9 = *piVar11;
LAB_005a994c:
      if (iVar9 != 0) {
        (*(code *)PTR_EVP_PKEY_free_006a6e78)();
      }
      if (piVar14 != (int *)0x0) {
LAB_005a9968:
        iVar9 = *piVar14;
        goto LAB_005a996c;
      }
    }
    if (iVar15 == 0) goto LAB_005a9994;
  }
LAB_005a9988:
  (*(code *)PTR_X509_free_006a6e90)(iVar15);
LAB_005a9994:
  if (iVar3 == 0) {
    return 0;
  }
  (*(code *)PTR_sk_pop_free_006a7058)(iVar3,PTR_X509_free_006a6e90);
  return 0;
code_r0x005a9b50:
  *piVar14 = iVar15;
  (*(code *)puVar2)();
  goto LAB_005a9a08;
}

