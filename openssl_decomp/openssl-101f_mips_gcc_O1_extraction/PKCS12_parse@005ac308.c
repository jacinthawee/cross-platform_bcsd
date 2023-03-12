
int PKCS12_parse(PKCS12 *p12,char *pass,EVP_PKEY **pkey,X509 **cert,stack_st_X509 **ca)

{
  int iVar1;
  stack_st_PKCS7 *psVar2;
  int iVar3;
  PKCS7 *p7;
  stack_st_PKCS12_SAFEBAG *psVar4;
  undefined4 uVar5;
  EVP_PKEY *pEVar6;
  X509 *pXVar7;
  stack_st_X509 *psVar8;
  undefined4 uVar9;
  int iVar10;
  X509 *pXVar11;
  char *local_res4;
  
  if (p12 == (PKCS12 *)0x0) {
    uVar9 = 0x69;
    uVar5 = 0x59;
    goto LAB_005ac758;
  }
  if (pkey != (EVP_PKEY **)0x0) {
    *pkey = (EVP_PKEY *)0x0;
  }
  if (cert != (X509 **)0x0) {
    *cert = (X509 *)0x0;
  }
  if ((pass == (char *)0x0) || (*pass == '\0')) {
    iVar1 = PKCS12_verify_mac(p12,(char *)0x0,0);
    if (iVar1 == 0) {
      iVar1 = PKCS12_verify_mac(p12,"",0);
      if (iVar1 == 0) {
        uVar5 = 0x6e;
        goto LAB_005ac7c4;
      }
      local_res4 = "";
    }
    else {
      local_res4 = (char *)0x0;
    }
LAB_005ac3a0:
    iVar1 = (*(code *)PTR_sk_new_null_006a80a4)();
    if (iVar1 == 0) {
      uVar9 = 0x41;
      uVar5 = 0x7b;
LAB_005ac758:
      (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x76,uVar9,"p12_kiss.c",uVar5);
      return 0;
    }
    psVar2 = PKCS12_unpack_authsafes(p12);
    if (psVar2 == (stack_st_PKCS7 *)0x0) {
LAB_005ac4ec:
      (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x76,0x72,"p12_kiss.c",0x81);
      goto LAB_005ac514;
    }
    iVar10 = 0;
    while (iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar2), iVar10 < iVar3) {
      p7 = (PKCS7 *)(*(code *)PTR_sk_value_006a7f24)(psVar2,iVar10);
      iVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
      if (iVar3 == 0x15) {
        psVar4 = PKCS12_unpack_p7data(p7);
joined_r0x005ac4d0:
        if (psVar4 == (stack_st_PKCS12_SAFEBAG *)0x0) {
          (*(code *)PTR_sk_pop_free_006a8158)(psVar2,PTR_PKCS7_free_006a8350);
          goto LAB_005ac4ec;
        }
        iVar3 = parse_bags_constprop_1(psVar4,local_res4,pkey,iVar1);
        if (iVar3 == 0) {
          (*(code *)PTR_sk_pop_free_006a8158)(psVar4,PTR_PKCS12_SAFEBAG_free_006a834c);
          (*(code *)PTR_sk_pop_free_006a8158)(psVar2,PTR_PKCS7_free_006a8350);
          goto LAB_005ac4ec;
        }
        iVar10 = iVar10 + 1;
        (*(code *)PTR_sk_pop_free_006a8158)();
      }
      else {
        if (iVar3 == 0x1a) {
          psVar4 = PKCS12_unpack_p7encdata(p7,local_res4,-1);
          goto joined_r0x005ac4d0;
        }
        iVar10 = iVar10 + 1;
      }
    }
    (*(code *)PTR_sk_pop_free_006a8158)(psVar2,PTR_PKCS7_free_006a8350);
    if (ca == (stack_st_X509 **)0x0) {
      do {
        if ((cert == (X509 **)0x0) || (pkey == (EVP_PKEY **)0x0)) {
          pXVar11 = (X509 *)(*(code *)PTR_sk_pop_006a9ec4)(iVar1);
          if (pXVar11 == (X509 *)0x0) goto LAB_005ac644;
        }
        else {
          while( true ) {
            pXVar11 = (X509 *)(*(code *)PTR_sk_pop_006a9ec4)(iVar1);
            if (pXVar11 == (X509 *)0x0) goto LAB_005ac644;
            if (((*pkey == (EVP_PKEY *)0x0) || (*cert != (X509 *)0x0)) ||
               (iVar10 = (*(code *)PTR_X509_check_private_key_006a817c)(pXVar11), iVar10 == 0))
            break;
            *cert = pXVar11;
          }
        }
        (*(code *)PTR_X509_free_006a7f90)(pXVar11);
      } while( true );
    }
    if (pkey != (EVP_PKEY **)0x0) {
      if (cert != (X509 **)0x0) {
        while (pXVar11 = (X509 *)(*(code *)PTR_sk_pop_006a9ec4)(iVar1), pXVar11 != (X509 *)0x0) {
          while (((*pkey == (EVP_PKEY *)0x0 || (*cert != (X509 *)0x0)) ||
                 (iVar10 = (*(code *)PTR_X509_check_private_key_006a817c)(pXVar11), iVar10 == 0))) {
            psVar8 = *ca;
            if (psVar8 == (stack_st_X509 *)0x0) {
              psVar8 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a80a4)();
              *ca = psVar8;
              if (psVar8 == (stack_st_X509 *)0x0) {
                pEVar6 = *pkey;
                goto LAB_005ac520;
              }
            }
            iVar10 = (*(code *)PTR_sk_push_006a80a8)(psVar8,pXVar11);
            if (iVar10 == 0) goto LAB_005ac51c;
            pXVar11 = (X509 *)(*(code *)PTR_sk_pop_006a9ec4)(iVar1);
            if (pXVar11 == (X509 *)0x0) goto LAB_005ac644;
          }
          *cert = pXVar11;
        }
LAB_005ac644:
        (*(code *)PTR_sk_pop_free_006a8158)(iVar1,PTR_X509_free_006a7f90);
        return 1;
      }
      do {
        pXVar11 = (X509 *)(*(code *)PTR_sk_pop_006a9ec4)(iVar1);
        if (pXVar11 == (X509 *)0x0) goto LAB_005ac644;
        psVar8 = *ca;
        if (psVar8 == (stack_st_X509 *)0x0) {
          psVar8 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a80a4)();
          *ca = psVar8;
          if (psVar8 == (stack_st_X509 *)0x0) {
            pEVar6 = *pkey;
            goto LAB_005ac520;
          }
        }
        iVar10 = (*(code *)PTR_sk_push_006a80a8)(psVar8,pXVar11);
      } while (iVar10 != 0);
      pEVar6 = *pkey;
      goto LAB_005ac520;
    }
    do {
      pXVar11 = (X509 *)(*(code *)PTR_sk_pop_006a9ec4)(iVar1);
      if (pXVar11 == (X509 *)0x0) goto LAB_005ac644;
      psVar8 = *ca;
      if (psVar8 == (stack_st_X509 *)0x0) {
        psVar8 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a80a4)();
        *ca = psVar8;
        if (psVar8 == (stack_st_X509 *)0x0) break;
      }
      iVar10 = (*(code *)PTR_sk_push_006a80a8)(psVar8,pXVar11);
    } while (iVar10 != 0);
    if (cert != (X509 **)0x0) goto LAB_005ac53c;
  }
  else {
    iVar1 = PKCS12_verify_mac(p12,pass,-1);
    local_res4 = pass;
    if (iVar1 != 0) goto LAB_005ac3a0;
    uVar5 = 0x72;
LAB_005ac7c4:
    iVar1 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x76,0x71,"p12_kiss.c",uVar5);
LAB_005ac514:
    pXVar11 = (X509 *)0x0;
    if (pkey == (EVP_PKEY **)0x0) {
      if (cert == (X509 **)0x0) goto LAB_005ac568;
      pXVar7 = *cert;
LAB_005ac540:
      if (pXVar7 != (X509 *)0x0) {
        (*(code *)PTR_X509_free_006a7f90)();
      }
    }
    else {
LAB_005ac51c:
      pEVar6 = *pkey;
LAB_005ac520:
      if (pEVar6 != (EVP_PKEY *)0x0) {
        (*(code *)PTR_EVP_PKEY_free_006a7f78)();
      }
      if (cert != (X509 **)0x0) {
LAB_005ac53c:
        pXVar7 = *cert;
        goto LAB_005ac540;
      }
    }
    if (pXVar11 == (X509 *)0x0) goto LAB_005ac568;
  }
  (*(code *)PTR_X509_free_006a7f90)(pXVar11);
LAB_005ac568:
  if (iVar1 == 0) {
    return 0;
  }
  (*(code *)PTR_sk_pop_free_006a8158)(iVar1,PTR_X509_free_006a7f90);
  return 0;
}

