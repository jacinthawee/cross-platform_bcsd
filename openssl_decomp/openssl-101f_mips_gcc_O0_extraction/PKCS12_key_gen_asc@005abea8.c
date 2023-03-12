
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
  int *piVar12;
  int *piVar13;
  int *piVar14;
  undefined4 uVar15;
  char *pcVar16;
  int *piVar17;
  int iVar18;
  ASN1_STRING *pAVar19;
  char *pcVar20;
  X509 *pXStack_ac;
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
  
  puStack_7c = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (pass == (char *)0x0) {
    local_24 = (uchar *)0x0;
    local_20 = (X509 *)0x0;
LAB_005abf10:
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
        (*(code *)PTR_OPENSSL_cleanse_006a8174)();
        (*(code *)PTR_CRYPTO_free_006a7f88)(local_24);
        piVar12 = (int *)salt;
      }
    }
  }
  else {
    puVar3 = OPENSSL_asc2uni(pass,passlen,&local_24,(int *)&local_20);
    pass = (char *)local_24;
    if (puVar3 != (uchar *)0x0) goto LAB_005abf10;
    piVar12 = (int *)&DAT_00000041;
    pcVar16 = s_p12_key_c_00670654;
    pass_00 = (X509 *)&DAT_0000006e;
    (*(code *)PTR_ERR_put_error_006a9030)(0x23);
    puVar3 = (uchar *)0x0;
    puStack_80 = salt;
  }
  if (local_1c == *(int *)puStack_7c) {
    return (int)puVar3;
  }
  iVar6 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puStack_78 = out;
  pEStack_70 = md_type;
  iVar18 = 0;
  pPStack_84 = *(PKCS12 **)PTR___stack_chk_guard_006aabf0;
  pXStack_ac = pass_00;
  piVar13 = piVar12;
  piVar17 = (int *)pcVar16;
  iStack_74 = saltlen;
  iVar4 = (*(code *)PTR_sk_num_006a7f2c)(iVar6);
  if (0 < iVar4) {
    do {
      bag = (PKCS12_SAFEBAG *)(*(code *)PTR_sk_value_006a7f24)(iVar6,iVar18);
      pAVar5 = PKCS12_get_attr_gen(bag->attrib,0x9c);
      if (pAVar5 == (ASN1_TYPE *)0x0) {
        pcVar20 = (char *)0x0;
      }
      else {
        pcVar20 = (pAVar5->value).ptr;
      }
      pXStack_ac = (X509 *)&DAT_0000009d;
      pAVar5 = PKCS12_get_attr_gen(bag->attrib,0x9d);
      if (pAVar5 == (ASN1_TYPE *)0x0) {
        pAVar19 = (ASN1_STRING *)0x0;
      }
      else {
        pAVar19 = (pAVar5->value).asn1_string;
      }
      iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(bag->type);
      if (iVar4 == 0x97) {
        if ((piVar12 != (int *)0x0) && (*piVar12 == 0)) {
          piVar13 = (int *)0xffffffff;
          pXStack_ac = pass_00;
          pPVar8 = PKCS12_decrypt_skey(bag,(char *)pass_00,-1);
          if (pPVar8 != (PKCS8_PRIV_KEY_INFO *)0x0) {
            iVar4 = (*(code *)PTR_EVP_PKCS82PKEY_006a8334)(pPVar8);
            puVar1 = PTR_PKCS8_PRIV_KEY_INFO_free_006a8340;
            *piVar12 = iVar4;
            (*(code *)puVar1)(pPVar8);
            if (*piVar12 != 0) goto LAB_005ac120;
          }
LAB_005ac1b0:
          iVar6 = 0;
          goto LAB_005ac13c;
        }
      }
      else if (iVar4 < 0x98) {
        if (((iVar4 == 0x96) && (piVar12 != (int *)0x0)) && (*piVar12 == 0)) {
          iVar4 = (*(code *)PTR_EVP_PKCS82PKEY_006a8334)((bag->value).bag);
          *piVar12 = iVar4;
joined_r0x005ac1a8:
          if (iVar4 == 0) goto LAB_005ac1b0;
        }
      }
      else if (iVar4 == 0x98) {
        iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(((bag->value).bag)->type);
        if (iVar4 == 0x9e) {
          pXVar7 = PKCS12_certbag2x509(bag);
          if (pXVar7 == (X509 *)0x0) goto LAB_005ac1b0;
          piVar14 = piVar13;
          if (pAVar19 == (ASN1_STRING *)0x0) {
LAB_005ac20c:
            if ((pcVar20 != (char *)0x0) &&
               (piVar13 = (int *)(*(code *)PTR_ASN1_STRING_to_UTF8_006a9e10)(&pXStack_88,pcVar20),
               0 < (int)piVar13)) {
              pXStack_ac = pXStack_88;
              iVar4 = (*(code *)PTR_X509_alias_set1_006a8368)(pXVar7);
              (*(code *)PTR_CRYPTO_free_006a7f88)(pXStack_88);
              piVar14 = piVar13;
              if (iVar4 == 0) goto LAB_005ac270;
            }
            piVar13 = piVar14;
            pXStack_ac = pXVar7;
            iVar4 = (*(code *)PTR_sk_push_006a80a8)(pcVar16);
            if (iVar4 != 0) goto LAB_005ac120;
          }
          else {
            piVar13 = (int *)pAVar19->length;
            pXStack_ac = (X509 *)pAVar19->data;
            iVar4 = (*(code *)PTR_X509_keyid_set1_006a8394)(pXVar7);
            piVar14 = piVar13;
            if (iVar4 != 0) goto LAB_005ac20c;
          }
LAB_005ac270:
          (*(code *)PTR_X509_free_006a7f90)(pXVar7);
          iVar6 = 0;
          goto LAB_005ac13c;
        }
      }
      else {
        piVar13 = piVar12;
        if (iVar4 == 0x9b) {
          pXStack_ac = pass_00;
          piVar17 = (int *)pcVar16;
          iVar4 = parse_bags_constprop_1((bag->value).bag);
          goto joined_r0x005ac1a8;
        }
      }
LAB_005ac120:
      iVar18 = iVar18 + 1;
      iVar4 = (*(code *)PTR_sk_num_006a7f2c)(iVar6);
    } while (iVar18 < iVar4);
  }
  iVar6 = 1;
LAB_005ac13c:
  if (pPStack_84 == *(PKCS12 **)puVar2) {
    return iVar6;
  }
  p12 = pPStack_84;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (p12 == (PKCS12 *)0x0) {
    uVar15 = 0x69;
    uVar11 = 0x59;
    goto LAB_005ac758;
  }
  if (piVar13 != (int *)0x0) {
    *piVar13 = 0;
  }
  if (piVar17 != (int *)0x0) {
    *piVar17 = 0;
  }
  if ((pXStack_ac == (X509 *)0x0) || (*(uchar *)&pXStack_ac->cert_info == '\0')) {
    iVar6 = PKCS12_verify_mac(p12,(char *)0x0,0);
    if (iVar6 == 0) {
      iVar6 = PKCS12_verify_mac(p12,"",0);
      if (iVar6 == 0) {
        uVar11 = 0x6e;
        goto LAB_005ac7c4;
      }
      pXStack_ac = (X509 *)0x6395d0;
    }
    else {
      pXStack_ac = (X509 *)0x0;
    }
LAB_005ac3a0:
    iVar6 = (*(code *)PTR_sk_new_null_006a80a4)();
    if (iVar6 == 0) {
      uVar15 = 0x41;
      uVar11 = 0x7b;
LAB_005ac758:
      (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x76,uVar15,"p12_kiss.c",uVar11);
      return 0;
    }
    psVar9 = PKCS12_unpack_authsafes(p12);
    if (psVar9 == (stack_st_PKCS7 *)0x0) {
LAB_005ac4ec:
      (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x76,0x72,"p12_kiss.c",0x81);
      goto LAB_005ac514;
    }
    iVar4 = 0;
    while (iVar18 = (*(code *)PTR_sk_num_006a7f2c)(psVar9), iVar4 < iVar18) {
      p7 = (PKCS7 *)(*(code *)PTR_sk_value_006a7f24)(psVar9,iVar4);
      iVar18 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
      if (iVar18 == 0x15) {
        psVar10 = PKCS12_unpack_p7data(p7);
joined_r0x005ac4d0:
        if (psVar10 == (stack_st_PKCS12_SAFEBAG *)0x0) {
          (*(code *)PTR_sk_pop_free_006a8158)(psVar9,PTR_PKCS7_free_006a8350);
          goto LAB_005ac4ec;
        }
        iVar18 = parse_bags_constprop_1(psVar10,pXStack_ac,piVar13,iVar6);
        if (iVar18 == 0) {
          (*(code *)PTR_sk_pop_free_006a8158)(psVar10,PTR_PKCS12_SAFEBAG_free_006a834c);
          (*(code *)PTR_sk_pop_free_006a8158)(psVar9,PTR_PKCS7_free_006a8350);
          goto LAB_005ac4ec;
        }
        iVar4 = iVar4 + 1;
        (*(code *)PTR_sk_pop_free_006a8158)();
      }
      else {
        if (iVar18 == 0x1a) {
          psVar10 = PKCS12_unpack_p7encdata(p7,(char *)pXStack_ac,-1);
          goto joined_r0x005ac4d0;
        }
        iVar4 = iVar4 + 1;
      }
    }
    (*(code *)PTR_sk_pop_free_006a8158)(psVar9,PTR_PKCS7_free_006a8350);
    if (piVar13 != (int *)0x0) {
      if (piVar17 != (int *)0x0) {
        while (iVar4 = (*(code *)PTR_sk_pop_006a9ec4)(iVar6), iVar4 != 0) {
          while (((*piVar13 == 0 || (*piVar17 != 0)) ||
                 (iVar18 = (*(code *)PTR_X509_check_private_key_006a817c)(iVar4), iVar18 == 0))) {
            if ((__gp == 0) && (__gp = (*(code *)PTR_sk_new_null_006a80a4)(), __gp == 0)) {
              iVar18 = *piVar13;
              goto LAB_005ac520;
            }
            iVar18 = (*(code *)PTR_sk_push_006a80a8)(__gp,iVar4);
            if (iVar18 == 0) goto LAB_005ac51c;
            iVar4 = (*(code *)PTR_sk_pop_006a9ec4)(iVar6);
            if (iVar4 == 0) goto LAB_005ac640;
          }
          *piVar17 = iVar4;
        }
LAB_005ac640:
        (*(code *)PTR_sk_pop_free_006a8158)(iVar6,PTR_X509_free_006a7f90);
        return 1;
      }
      do {
        iVar4 = (*(code *)PTR_sk_pop_006a9ec4)(iVar6);
        if (iVar4 == 0) goto LAB_005ac640;
        if ((__gp == 0) && (__gp = (*(code *)PTR_sk_new_null_006a80a4)(), __gp == 0)) {
          iVar18 = *piVar13;
          goto LAB_005ac520;
        }
        iVar18 = (*(code *)PTR_sk_push_006a80a8)(__gp,iVar4);
      } while (iVar18 != 0);
      iVar18 = *piVar13;
      goto LAB_005ac520;
    }
    do {
      iVar4 = (*(code *)PTR_sk_pop_006a9ec4)(iVar6);
      if (iVar4 == 0) goto LAB_005ac640;
    } while (((__gp != 0) || (__gp = (*(code *)PTR_sk_new_null_006a80a4)(), __gp != 0)) &&
            (iVar18 = (*(code *)PTR_sk_push_006a80a8)(__gp,iVar4), iVar18 != 0));
    if (piVar17 != (int *)0x0) goto LAB_005ac53c;
  }
  else {
    iVar6 = PKCS12_verify_mac(p12,(char *)pXStack_ac,-1);
    if (iVar6 != 0) goto LAB_005ac3a0;
    uVar11 = 0x72;
LAB_005ac7c4:
    iVar6 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x76,0x71,"p12_kiss.c",uVar11);
LAB_005ac514:
    iVar4 = 0;
    if (piVar13 == (int *)0x0) {
      if (piVar17 == (int *)0x0) goto LAB_005ac568;
      iVar18 = *piVar17;
LAB_005ac540:
      if (iVar18 != 0) {
        (*(code *)PTR_X509_free_006a7f90)();
      }
    }
    else {
LAB_005ac51c:
      iVar18 = *piVar13;
LAB_005ac520:
      if (iVar18 != 0) {
        (*(code *)PTR_EVP_PKEY_free_006a7f78)();
      }
      if (piVar17 != (int *)0x0) {
LAB_005ac53c:
        iVar18 = *piVar17;
        goto LAB_005ac540;
      }
    }
    if (iVar4 == 0) goto LAB_005ac568;
  }
  (*(code *)PTR_X509_free_006a7f90)(iVar4);
LAB_005ac568:
  if (iVar6 == 0) {
    return 0;
  }
  (*(code *)PTR_sk_pop_free_006a8158)(iVar6,PTR_X509_free_006a7f90);
  return 0;
}

