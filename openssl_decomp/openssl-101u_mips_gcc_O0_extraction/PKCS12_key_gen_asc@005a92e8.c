
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

int PKCS12_key_gen_asc(char *pass,int passlen,uchar *salt,int saltlen,int id,int iter,int n,
                      uchar *out,EVP_MD *md_type)

{
  undefined *puVar1;
  undefined *puVar2;
  uchar *puVar3;
  int iVar4;
  PKCS12_SAFEBAG *bag;
  ASN1_TYPE *pAVar5;
  int iVar6;
  X509 *pXVar7;
  PKCS8_PRIV_KEY_INFO *pPVar8;
  stack_st_PKCS7 *psVar9;
  PKCS7 *p7;
  stack_st_PKCS12_SAFEBAG *psVar10;
  undefined4 uVar11;
  PKCS12 *p12;
  X509 *pass_00;
  X509 *pass_01;
  int *piVar12;
  int *piVar13;
  int *piVar14;
  undefined4 uVar15;
  char *pcVar16;
  int *piVar17;
  int iVar18;
  ASN1_STRING *pAVar19;
  char *pcVar20;
  X509 *pXStack_88;
  PKCS12 *pPStack_84;
  uchar *puStack_80;
  undefined *puStack_7c;
  uchar *puStack_78;
  int iStack_74;
  EVP_MD *pEStack_70;
  uchar *local_24;
  X509 *local_20;
  int local_1c;
  
  puStack_7c = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (pass == (char *)0x0) {
    local_24 = (uchar *)0x0;
    local_20 = (X509 *)0x0;
LAB_005a9350:
    pass_00 = local_20;
    pcVar16 = (char *)saltlen;
    puStack_80 = (uchar *)PKCS12_key_gen_uni((uchar *)pass,(int)local_20,salt,saltlen,id,iter,n,out,
                                             md_type);
    piVar12 = (int *)salt;
    if ((int)puStack_80 < 1) {
      puVar3 = (uchar *)0x0;
    }
    else {
      puVar3 = puStack_80;
      if (local_24 != (uchar *)0x0) {
        pass_00 = local_20;
        (*(code *)PTR_OPENSSL_cleanse_006a7074)();
        (*(code *)PTR_CRYPTO_free_006a6e88)(local_24);
        piVar12 = (int *)salt;
      }
    }
  }
  else {
    puVar3 = OPENSSL_asc2uni(pass,passlen,&local_24,(int *)&local_20);
    pass = (char *)local_24;
    if (puVar3 != (uchar *)0x0) goto LAB_005a9350;
    piVar12 = (int *)&DAT_00000041;
    pcVar16 = s_p12_key_c_0066fd64;
    pass_00 = (X509 *)&DAT_0000006e;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23);
    puVar3 = (uchar *)0x0;
    puStack_80 = salt;
  }
  if (local_1c == *(int *)puStack_7c) {
    return (int)puVar3;
  }
  iVar6 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puStack_78 = out;
  pEStack_70 = md_type;
  iVar18 = 0;
  pPStack_84 = *(PKCS12 **)PTR___stack_chk_guard_006a9ae8;
  pass_01 = pass_00;
  piVar13 = piVar12;
  piVar17 = (int *)pcVar16;
  iStack_74 = saltlen;
  iVar4 = (*(code *)PTR_sk_num_006a6e2c)(iVar6);
  if (0 < iVar4) {
    do {
      bag = (PKCS12_SAFEBAG *)(*(code *)PTR_sk_value_006a6e24)(iVar6,iVar18);
      pAVar5 = PKCS12_get_attr_gen(bag->attrib,0x9c);
      if (pAVar5 == (ASN1_TYPE *)0x0) {
        pcVar20 = (char *)0x0;
      }
      else {
        pcVar20 = (pAVar5->value).ptr;
      }
      pass_01 = (X509 *)0x9d;
      pAVar5 = PKCS12_get_attr_gen(bag->attrib,0x9d);
      if (pAVar5 == (ASN1_TYPE *)0x0) {
        pAVar19 = (ASN1_STRING *)0x0;
      }
      else {
        pAVar19 = (pAVar5->value).asn1_string;
      }
      iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(bag->type);
      if (iVar4 == 0x97) {
        if ((piVar12 != (int *)0x0) && (*piVar12 == 0)) {
          piVar13 = (int *)0xffffffff;
          pass_01 = pass_00;
          pPVar8 = PKCS12_decrypt_skey(bag,(char *)pass_00,-1);
          if (pPVar8 != (PKCS8_PRIV_KEY_INFO *)0x0) {
            iVar4 = (*(code *)PTR_EVP_PKCS82PKEY_006a7220)(pPVar8);
            puVar1 = PTR_PKCS8_PRIV_KEY_INFO_free_006a722c;
            *piVar12 = iVar4;
            (*(code *)puVar1)(pPVar8);
            if (*piVar12 != 0) goto LAB_005a9560;
          }
LAB_005a95f0:
          iVar6 = 0;
          goto LAB_005a957c;
        }
      }
      else if (iVar4 < 0x98) {
        if (((iVar4 == 0x96) && (piVar12 != (int *)0x0)) && (*piVar12 == 0)) {
          iVar4 = (*(code *)PTR_EVP_PKCS82PKEY_006a7220)((bag->value).bag);
          *piVar12 = iVar4;
joined_r0x005a95e8:
          if (iVar4 == 0) goto LAB_005a95f0;
        }
      }
      else if (iVar4 == 0x98) {
        iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(((bag->value).bag)->type);
        if (iVar4 == 0x9e) {
          pXVar7 = PKCS12_certbag2x509(bag);
          if (pXVar7 == (X509 *)0x0) goto LAB_005a95f0;
          piVar14 = piVar13;
          if (pAVar19 == (ASN1_STRING *)0x0) {
LAB_005a964c:
            if ((pcVar20 != (char *)0x0) &&
               (piVar13 = (int *)(*(code *)PTR_ASN1_STRING_to_UTF8_006a8cf0)(&pXStack_88,pcVar20),
               -1 < (int)piVar13)) {
              pass_01 = pXStack_88;
              iVar4 = (*(code *)PTR_X509_alias_set1_006a7254)(pXVar7);
              (*(code *)PTR_CRYPTO_free_006a6e88)(pXStack_88);
              piVar14 = piVar13;
              if (iVar4 == 0) goto LAB_005a96b0;
            }
            piVar13 = piVar14;
            pass_01 = pXVar7;
            iVar4 = (*(code *)PTR_sk_push_006a6fa8)(pcVar16);
            if (iVar4 != 0) goto LAB_005a9560;
          }
          else {
            piVar13 = (int *)pAVar19->length;
            pass_01 = (X509 *)pAVar19->data;
            iVar4 = (*(code *)PTR_X509_keyid_set1_006a7284)(pXVar7);
            piVar14 = piVar13;
            if (iVar4 != 0) goto LAB_005a964c;
          }
LAB_005a96b0:
          (*(code *)PTR_X509_free_006a6e90)(pXVar7);
          iVar6 = 0;
          goto LAB_005a957c;
        }
      }
      else {
        piVar13 = piVar12;
        if (iVar4 == 0x9b) {
          pass_01 = pass_00;
          piVar17 = (int *)pcVar16;
          iVar4 = parse_bags_constprop_1((bag->value).bag);
          goto joined_r0x005a95e8;
        }
      }
LAB_005a9560:
      iVar18 = iVar18 + 1;
      iVar4 = (*(code *)PTR_sk_num_006a6e2c)(iVar6);
    } while (iVar18 < iVar4);
  }
  iVar6 = 1;
LAB_005a957c:
  if (pPStack_84 == *(PKCS12 **)puVar2) {
    return iVar6;
  }
  p12 = pPStack_84;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (p12 == (PKCS12 *)0x0) {
    uVar15 = 0x69;
    uVar11 = 0x5b;
    goto LAB_005a9b74;
  }
  if (piVar13 != (int *)0x0) {
    *piVar13 = 0;
  }
  if (piVar17 != (int *)0x0) {
    *piVar17 = 0;
  }
  if ((pass_01 == (X509 *)0x0) || (*(uchar *)&pass_01->cert_info == '\0')) {
    iVar6 = PKCS12_verify_mac(p12,(char *)0x0,0);
    if (iVar6 == 0) {
      iVar6 = PKCS12_verify_mac(p12,"",0);
      if (iVar6 == 0) {
        uVar11 = 0x73;
        goto LAB_005a9be0;
      }
      pass_01 = (X509 *)0x638d8c;
    }
    else {
      pass_01 = (X509 *)0x0;
    }
LAB_005a97d8:
    iVar6 = (*(code *)PTR_sk_new_null_006a6fa4)();
    if (iVar6 == 0) {
      uVar15 = 0x41;
      uVar11 = 0x7f;
LAB_005a9b74:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x76,uVar15,"p12_kiss.c",uVar11);
      return 0;
    }
    psVar9 = PKCS12_unpack_authsafes(p12);
    if (psVar9 == (stack_st_PKCS7 *)0x0) {
LAB_005a9918:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x76,0x72,"p12_kiss.c",0x84);
      goto LAB_005a9940;
    }
    iVar4 = 0;
    while (iVar18 = (*(code *)PTR_sk_num_006a6e2c)(psVar9), iVar4 < iVar18) {
      p7 = (PKCS7 *)(*(code *)PTR_sk_value_006a6e24)(psVar9,iVar4);
      iVar18 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
      if (iVar18 == 0x15) {
        psVar10 = PKCS12_unpack_p7data(p7);
joined_r0x005a98fc:
        if (psVar10 == (stack_st_PKCS12_SAFEBAG *)0x0) {
          (*(code *)PTR_sk_pop_free_006a7058)(psVar9,PTR_PKCS7_free_006a723c);
          goto LAB_005a9918;
        }
        iVar18 = parse_bags_constprop_1(psVar10,pass_01,piVar13,iVar6);
        if (iVar18 == 0) {
          (*(code *)PTR_sk_pop_free_006a7058)(psVar10,PTR_PKCS12_SAFEBAG_free_006a7238);
          (*(code *)PTR_sk_pop_free_006a7058)(psVar9,PTR_PKCS7_free_006a723c);
          goto LAB_005a9918;
        }
        iVar4 = iVar4 + 1;
        (*(code *)PTR_sk_pop_free_006a7058)();
      }
      else {
        if (iVar18 == 0x1a) {
          psVar10 = PKCS12_unpack_p7encdata(p7,(char *)pass_01,-1);
          goto joined_r0x005a98fc;
        }
        iVar4 = iVar4 + 1;
      }
    }
    (*(code *)PTR_sk_pop_free_006a7058)(psVar9,PTR_PKCS7_free_006a723c);
    if (piVar17 != (int *)0x0) {
      if (piVar13 != (int *)0x0) {
LAB_005a9a08:
        iVar4 = (*(code *)PTR_sk_pop_006a8da4)(iVar6);
        if (iVar4 != 0) {
          do {
            if ((*piVar13 != 0) && (*piVar17 == 0)) {
              (*(code *)PTR_ERR_set_mark_006a9238)();
              iVar18 = (*(code *)PTR_X509_check_private_key_006a707c)(iVar4,*piVar13);
              puVar2 = PTR_ERR_pop_to_mark_006a923c;
              if (iVar18 != 0) goto code_r0x005a9b50;
              (*(code *)PTR_ERR_pop_to_mark_006a923c)();
            }
            if ((__gp == 0) && (__gp = (*(code *)PTR_sk_new_null_006a6fa4)(), __gp == 0)) {
              iVar18 = *piVar13;
              goto LAB_005a994c;
            }
            iVar18 = (*(code *)PTR_sk_push_006a6fa8)(__gp,iVar4);
            if (iVar18 == 0) goto LAB_005a9948;
            iVar4 = (*(code *)PTR_sk_pop_006a8da4)(iVar6);
            if (iVar4 == 0) break;
          } while( true );
        }
        goto LAB_005a9a74;
      }
      do {
        iVar4 = (*(code *)PTR_sk_pop_006a8da4)(iVar6);
        if (iVar4 == 0) goto LAB_005a9a74;
      } while (((__gp != 0) || (__gp = (*(code *)PTR_sk_new_null_006a6fa4)(), __gp != 0)) &&
              (iVar18 = (*(code *)PTR_sk_push_006a6fa8)(__gp,iVar4), iVar18 != 0));
      if (piVar17 == (int *)0x0) goto LAB_005a9988;
      goto LAB_005a9968;
    }
    if (piVar13 != (int *)0x0) {
      do {
        iVar4 = (*(code *)PTR_sk_pop_006a8da4)(iVar6);
        if (iVar4 == 0) goto LAB_005a9a74;
        if ((__gp == 0) && (__gp = (*(code *)PTR_sk_new_null_006a6fa4)(), __gp == 0)) {
          iVar18 = *piVar13;
          goto LAB_005a994c;
        }
        iVar18 = (*(code *)PTR_sk_push_006a6fa8)(__gp,iVar4);
      } while (iVar18 != 0);
      iVar18 = *piVar13;
      goto LAB_005a994c;
    }
    do {
      iVar4 = (*(code *)PTR_sk_pop_006a8da4)(iVar6);
      if (iVar4 == 0) {
LAB_005a9a74:
        (*(code *)PTR_sk_pop_free_006a7058)(iVar6,PTR_X509_free_006a6e90);
        return 1;
      }
    } while (((__gp != 0) || (__gp = (*(code *)PTR_sk_new_null_006a6fa4)(), __gp != 0)) &&
            (iVar18 = (*(code *)PTR_sk_push_006a6fa8)(__gp,iVar4), iVar18 != 0));
  }
  else {
    iVar6 = PKCS12_verify_mac(p12,(char *)pass_01,-1);
    if (iVar6 != 0) goto LAB_005a97d8;
    uVar11 = 0x77;
LAB_005a9be0:
    iVar6 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x76,0x71,"p12_kiss.c",uVar11);
LAB_005a9940:
    iVar4 = 0;
    if (piVar13 == (int *)0x0) {
      if (piVar17 == (int *)0x0) goto LAB_005a9994;
      iVar18 = *piVar17;
LAB_005a996c:
      if (iVar18 != 0) {
        (*(code *)PTR_X509_free_006a6e90)();
      }
    }
    else {
LAB_005a9948:
      iVar18 = *piVar13;
LAB_005a994c:
      if (iVar18 != 0) {
        (*(code *)PTR_EVP_PKEY_free_006a6e78)();
      }
      if (piVar17 != (int *)0x0) {
LAB_005a9968:
        iVar18 = *piVar17;
        goto LAB_005a996c;
      }
    }
    if (iVar4 == 0) goto LAB_005a9994;
  }
LAB_005a9988:
  (*(code *)PTR_X509_free_006a6e90)(iVar4);
LAB_005a9994:
  if (iVar6 == 0) {
    return 0;
  }
  (*(code *)PTR_sk_pop_free_006a7058)(iVar6,PTR_X509_free_006a6e90);
  return 0;
code_r0x005a9b50:
  *piVar17 = iVar4;
  (*(code *)puVar2)();
  goto LAB_005a9a08;
}

