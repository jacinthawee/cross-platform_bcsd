
int PKCS12_parse(PKCS12 *p12,char *pass,EVP_PKEY **pkey,X509 **cert,stack_st_X509 **ca)

{
  undefined *puVar1;
  int iVar2;
  stack_st_PKCS7 *psVar3;
  int iVar4;
  PKCS7 *p7;
  stack_st_PKCS12_SAFEBAG *psVar5;
  undefined4 uVar6;
  EVP_PKEY *pEVar7;
  X509 *pXVar8;
  stack_st_X509 *psVar9;
  undefined4 uVar10;
  int iVar11;
  X509 *pXVar12;
  
  if (p12 == (PKCS12 *)0x0) {
    uVar10 = 0x69;
    uVar6 = 0x5b;
    goto LAB_005a9b74;
  }
  if (pkey != (EVP_PKEY **)0x0) {
    *pkey = (EVP_PKEY *)0x0;
  }
  if (cert != (X509 **)0x0) {
    *cert = (X509 *)0x0;
  }
  if ((pass == (char *)0x0) || (*pass == '\0')) {
    iVar2 = PKCS12_verify_mac(p12,(char *)0x0,0);
    if (iVar2 == 0) {
      iVar2 = PKCS12_verify_mac(p12,"",0);
      if (iVar2 == 0) {
        uVar6 = 0x73;
        goto LAB_005a9be0;
      }
      pass = "";
    }
    else {
      pass = (char *)0x0;
    }
LAB_005a97d8:
    iVar2 = (*(code *)PTR_sk_new_null_006a6fa4)();
    if (iVar2 == 0) {
      uVar10 = 0x41;
      uVar6 = 0x7f;
LAB_005a9b74:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x76,uVar10,"p12_kiss.c",uVar6);
      return 0;
    }
    psVar3 = PKCS12_unpack_authsafes(p12);
    if (psVar3 == (stack_st_PKCS7 *)0x0) {
LAB_005a9918:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x76,0x72,"p12_kiss.c",0x84);
      goto LAB_005a9940;
    }
    iVar11 = 0;
    while (iVar4 = (*(code *)PTR_sk_num_006a6e2c)(psVar3), iVar11 < iVar4) {
      p7 = (PKCS7 *)(*(code *)PTR_sk_value_006a6e24)(psVar3,iVar11);
      iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
      if (iVar4 == 0x15) {
        psVar5 = PKCS12_unpack_p7data(p7);
joined_r0x005a98fc:
        if (psVar5 == (stack_st_PKCS12_SAFEBAG *)0x0) {
          (*(code *)PTR_sk_pop_free_006a7058)(psVar3,PTR_PKCS7_free_006a723c);
          goto LAB_005a9918;
        }
        iVar4 = parse_bags_constprop_1(psVar5,pass,pkey,iVar2);
        if (iVar4 == 0) {
          (*(code *)PTR_sk_pop_free_006a7058)(psVar5,PTR_PKCS12_SAFEBAG_free_006a7238);
          (*(code *)PTR_sk_pop_free_006a7058)(psVar3,PTR_PKCS7_free_006a723c);
          goto LAB_005a9918;
        }
        iVar11 = iVar11 + 1;
        (*(code *)PTR_sk_pop_free_006a7058)();
      }
      else {
        if (iVar4 == 0x1a) {
          psVar5 = PKCS12_unpack_p7encdata(p7,pass,-1);
          goto joined_r0x005a98fc;
        }
        iVar11 = iVar11 + 1;
      }
    }
    (*(code *)PTR_sk_pop_free_006a7058)(psVar3,PTR_PKCS7_free_006a723c);
    if (ca == (stack_st_X509 **)0x0) {
      do {
        if ((cert == (X509 **)0x0) || (pkey == (EVP_PKEY **)0x0)) {
          pXVar12 = (X509 *)(*(code *)PTR_sk_pop_006a8da4)(iVar2);
          if (pXVar12 == (X509 *)0x0) goto LAB_005a9a78;
        }
        else {
          while( true ) {
            pXVar12 = (X509 *)(*(code *)PTR_sk_pop_006a8da4)(iVar2);
            if (pXVar12 == (X509 *)0x0) goto LAB_005a9a78;
            if ((*pkey == (EVP_PKEY *)0x0) || (*cert != (X509 *)0x0)) goto LAB_005a9d74;
            (*(code *)PTR_ERR_set_mark_006a9238)();
            iVar11 = (*(code *)PTR_X509_check_private_key_006a707c)(pXVar12,*pkey);
            puVar1 = PTR_ERR_pop_to_mark_006a923c;
            if (iVar11 == 0) break;
            *cert = pXVar12;
            (*(code *)puVar1)();
          }
          (*(code *)PTR_ERR_pop_to_mark_006a923c)();
        }
LAB_005a9d74:
        (*(code *)PTR_X509_free_006a6e90)(pXVar12);
      } while( true );
    }
    if (cert == (X509 **)0x0) {
      if (pkey == (EVP_PKEY **)0x0) {
        do {
          pXVar12 = (X509 *)(*(code *)PTR_sk_pop_006a8da4)(iVar2);
          if (pXVar12 == (X509 *)0x0) goto LAB_005a9a78;
          psVar9 = *ca;
          if (psVar9 == (stack_st_X509 *)0x0) {
            psVar9 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a6fa4)();
            *ca = psVar9;
            if (psVar9 == (stack_st_X509 *)0x0) break;
          }
          iVar11 = (*(code *)PTR_sk_push_006a6fa8)(psVar9,pXVar12);
        } while (iVar11 != 0);
        goto LAB_005a9988;
      }
      do {
        pXVar12 = (X509 *)(*(code *)PTR_sk_pop_006a8da4)(iVar2);
        if (pXVar12 == (X509 *)0x0) goto LAB_005a9a78;
        psVar9 = *ca;
        if (psVar9 == (stack_st_X509 *)0x0) {
          psVar9 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a6fa4)();
          *ca = psVar9;
          if (psVar9 == (stack_st_X509 *)0x0) {
            pEVar7 = *pkey;
            goto LAB_005a994c;
          }
        }
        iVar11 = (*(code *)PTR_sk_push_006a6fa8)(psVar9,pXVar12);
      } while (iVar11 != 0);
      pEVar7 = *pkey;
      goto LAB_005a994c;
    }
    if (pkey != (EVP_PKEY **)0x0) {
LAB_005a9a08:
      pXVar12 = (X509 *)(*(code *)PTR_sk_pop_006a8da4)(iVar2);
      if (pXVar12 != (X509 *)0x0) {
        do {
          if ((*pkey != (EVP_PKEY *)0x0) && (*cert == (X509 *)0x0)) {
            (*(code *)PTR_ERR_set_mark_006a9238)();
            iVar11 = (*(code *)PTR_X509_check_private_key_006a707c)(pXVar12,*pkey);
            puVar1 = PTR_ERR_pop_to_mark_006a923c;
            if (iVar11 != 0) goto code_r0x005a9b50;
            (*(code *)PTR_ERR_pop_to_mark_006a923c)();
          }
          psVar9 = *ca;
          if (psVar9 == (stack_st_X509 *)0x0) {
            psVar9 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a6fa4)();
            *ca = psVar9;
            if (psVar9 == (stack_st_X509 *)0x0) {
              pEVar7 = *pkey;
              goto LAB_005a994c;
            }
          }
          iVar11 = (*(code *)PTR_sk_push_006a6fa8)(psVar9,pXVar12);
          if (iVar11 == 0) goto LAB_005a9948;
          pXVar12 = (X509 *)(*(code *)PTR_sk_pop_006a8da4)(iVar2);
          if (pXVar12 == (X509 *)0x0) break;
        } while( true );
      }
      goto LAB_005a9a78;
    }
    do {
      pXVar12 = (X509 *)(*(code *)PTR_sk_pop_006a8da4)(iVar2);
      if (pXVar12 == (X509 *)0x0) {
LAB_005a9a78:
        (*(code *)PTR_sk_pop_free_006a7058)(iVar2,PTR_X509_free_006a6e90);
        return 1;
      }
      psVar9 = *ca;
      if (psVar9 == (stack_st_X509 *)0x0) {
        psVar9 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a6fa4)();
        *ca = psVar9;
        if (psVar9 == (stack_st_X509 *)0x0) break;
      }
      iVar11 = (*(code *)PTR_sk_push_006a6fa8)(psVar9,pXVar12);
    } while (iVar11 != 0);
    if (cert != (X509 **)0x0) goto LAB_005a9968;
  }
  else {
    iVar2 = PKCS12_verify_mac(p12,pass,-1);
    if (iVar2 != 0) goto LAB_005a97d8;
    uVar6 = 0x77;
LAB_005a9be0:
    iVar2 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x76,0x71,"p12_kiss.c",uVar6);
LAB_005a9940:
    pXVar12 = (X509 *)0x0;
    if (pkey == (EVP_PKEY **)0x0) {
      if (cert == (X509 **)0x0) goto LAB_005a9994;
      pXVar8 = *cert;
LAB_005a996c:
      if (pXVar8 != (X509 *)0x0) {
        (*(code *)PTR_X509_free_006a6e90)();
      }
    }
    else {
LAB_005a9948:
      pEVar7 = *pkey;
LAB_005a994c:
      if (pEVar7 != (EVP_PKEY *)0x0) {
        (*(code *)PTR_EVP_PKEY_free_006a6e78)();
      }
      if (cert != (X509 **)0x0) {
LAB_005a9968:
        pXVar8 = *cert;
        goto LAB_005a996c;
      }
    }
    if (pXVar12 == (X509 *)0x0) goto LAB_005a9994;
  }
LAB_005a9988:
  (*(code *)PTR_X509_free_006a6e90)(pXVar12);
LAB_005a9994:
  if (iVar2 == 0) {
    return 0;
  }
  (*(code *)PTR_sk_pop_free_006a7058)(iVar2,PTR_X509_free_006a6e90);
  return 0;
code_r0x005a9b50:
  *cert = pXVar12;
  (*(code *)puVar1)();
  goto LAB_005a9a08;
}

