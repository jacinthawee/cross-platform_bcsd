
EVP_PKEY * PEM_read_bio_PrivateKey(BIO *bp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  undefined *puVar1;
  int iVar2;
  X509_SIG *a;
  EVP_PKEY *pEVar3;
  int *piVar4;
  EVP_PKEY_ASN1_METHOD *pEVar5;
  BIO_METHOD *pBVar6;
  BIO *pBVar7;
  undefined4 uVar8;
  BIO *pBVar9;
  BIO *pBVar10;
  BIO **x_00;
  BIO **name;
  char *u_00;
  EVP_PKEY *unaff_s0;
  char *unaff_s4;
  BIO *apBStack_5d4 [20];
  int iStack_584;
  BIO_METHOD *pBStack_57c;
  undefined *puStack_578;
  bio_st *pbStack_574;
  bio_st *pbStack_570;
  code *pcStack_56c;
  BIO_METHOD *pBStack_53c;
  BIO *pBStack_538;
  BIO *pBStack_534;
  BIO *pBStack_530;
  BIO *pBStack_52c;
  undefined *puStack_524;
  bio_st *pbStack_520;
  bio_st *pbStack_51c;
  char *pcStack_518;
  code *pcStack_514;
  bio_st bStack_4dc;
  BIO *pBStack_48c;
  EVP_PKEY *pEStack_484;
  undefined *puStack_480;
  PKCS8_PRIV_KEY_INFO *pPStack_47c;
  void *pvStack_478;
  char *pcStack_474;
  EVP_PKEY **ppEStack_470;
  undefined1 *cb_00;
  void *u_01;
  undefined local_434 [8];
  BIO_METHOD *local_42c;
  undefined local_428 [1028];
  BIO *local_24;
  
  puStack_480 = PTR___stack_chk_guard_006aabf0;
  pcStack_518 = "ANY PRIVATE KEY";
  pbStack_574 = (bio_st *)local_434;
  pbStack_520 = (bio_st *)local_428;
  local_434._0_4_ = (BIO_METHOD *)0x0;
  local_434._4_4_ = (BIO_METHOD *)0x0;
  local_42c = (BIO_METHOD *)0x0;
  local_24 = *(BIO **)PTR___stack_chk_guard_006aabf0;
  cb_00 = cb;
  u_01 = u;
  iVar2 = PEM_bytes_read_bio((uchar **)&local_42c,(long *)pbStack_520,(char **)pbStack_574,
                             "ANY PRIVATE KEY",bp,cb,u);
  pBVar6 = local_434._0_4_;
  if (iVar2 == 0) {
    pEVar3 = (EVP_PKEY *)0x0;
  }
  else {
    unaff_s4 = "7 datafinal";
    local_434._4_4_ = local_42c;
    iVar2 = (*(code *)PTR_strcmp_006aac20)(local_434._0_4_,"PRIVATE KEY");
    if (iVar2 == 0) {
      pbStack_574 = local_428._0_4_;
      cb = (undefined1 *)
           d2i_PKCS8_PRIV_KEY_INFO
                     ((PKCS8_PRIV_KEY_INFO **)0x0,(uchar **)(local_434 + 4),(long)local_428._0_4_);
joined_r0x005738cc:
      if ((PKCS8_PRIV_KEY_INFO *)cb == (PKCS8_PRIV_KEY_INFO *)0x0) goto LAB_005737bc;
      pEVar3 = (EVP_PKEY *)(*(code *)PTR_EVP_PKCS82PKEY_006a8334)(cb);
      if (x != (EVP_PKEY **)0x0) {
        if (*x != (EVP_PKEY *)0x0) {
          (*(code *)PTR_EVP_PKEY_free_006a7f78)();
        }
        *x = pEVar3;
      }
      PKCS8_PRIV_KEY_INFO_free((PKCS8_PRIV_KEY_INFO *)cb);
joined_r0x005738a4:
      if (pEVar3 == (EVP_PKEY *)0x0) goto LAB_005737bc;
    }
    else {
      iVar2 = (*(code *)PTR_strcmp_006aac20)(pBVar6,"ENCRYPTED PRIVATE KEY");
      if (iVar2 == 0) {
        a = d2i_X509_SIG((X509_SIG **)0x0,(uchar **)(local_434 + 4),(long)local_428._0_4_);
        if (a != (X509_SIG *)0x0) {
          unaff_s4 = local_428 + 4;
          pcStack_518 = (char *)u;
          if (cb == (undefined1 *)0x0) {
            pbStack_574 = (bio_st *)PEM_def_callback(unaff_s4,0x400,0,u);
          }
          else {
            pbStack_574 = (bio_st *)(*(code *)cb)(unaff_s4,0x400,0);
          }
          if (0 < (int)pbStack_574) {
            cb = (undefined1 *)(*(code *)PTR_PKCS8_decrypt_006a8da4)(a,unaff_s4);
            X509_SIG_free(a);
            goto joined_r0x005738cc;
          }
          pbStack_574 = (bio_st *)&DAT_00000068;
          pcStack_518 = "pem_pkey.c";
          bp = (BIO *)&DAT_0000006d;
          (*(code *)PTR_ERR_put_error_006a9030)(9,0x7b);
          pEVar3 = (EVP_PKEY *)0x0;
          X509_SIG_free(a);
          goto LAB_005737e4;
        }
      }
      else {
        iVar2 = pem_check_suffix(pBVar6,"PRIVATE KEY");
        if (((0 < iVar2) &&
            (piVar4 = (int *)EVP_PKEY_asn1_find_str((ENGINE **)0x0,(char *)local_434._0_4_,iVar2),
            piVar4 != (int *)0x0)) && (piVar4[0x17] != 0)) {
          pbStack_574 = (bio_st *)(local_434 + 4);
          pcStack_518 = (char *)local_428._0_4_;
          pEVar3 = d2i_PrivateKey(*piVar4,x,(uchar **)pbStack_574,(long)local_428._0_4_);
          goto joined_r0x005738a4;
        }
      }
LAB_005737bc:
      pbStack_574 = (bio_st *)&DAT_0000000d;
      pcStack_518 = "pem_pkey.c";
      bp = (BIO *)&DAT_00000084;
      pEVar3 = (EVP_PKEY *)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x7b);
    }
LAB_005737e4:
    (*(code *)PTR_CRYPTO_free_006a7f88)(local_434._0_4_);
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_42c);
    (*(code *)PTR_CRYPTO_free_006a7f88)(local_42c);
    pbStack_520 = local_428._0_4_;
    unaff_s0 = pEVar3;
  }
  if (local_24 == *(BIO **)puStack_480) {
    return pEVar3;
  }
  pBVar10 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_524 = PTR___stack_chk_guard_006aabf0;
  pEVar5 = (EVP_PKEY_ASN1_METHOD *)pbStack_520->init;
  pBStack_48c = *(BIO **)PTR___stack_chk_guard_006aabf0;
  pEStack_484 = unaff_s0;
  pPStack_47c = (PKCS8_PRIV_KEY_INFO *)cb;
  pvStack_478 = u;
  pcStack_474 = unaff_s4;
  ppEStack_470 = x;
  if ((pEVar5 == (EVP_PKEY_ASN1_METHOD *)0x0) || (*(int *)(pEVar5 + 0x28) != 0)) {
    pbStack_570 = pbStack_520;
    pEVar3 = (EVP_PKEY *)
             PEM_write_bio_PKCS8PrivateKey
                       (pBVar10,(EVP_PKEY *)pbStack_520,(EVP_CIPHER *)pbStack_574,pcStack_518,
                        (int)bp,cb_00,u_01);
  }
  else {
    pbStack_570 = &bStack_4dc;
    (*(code *)PTR_BIO_snprintf_006a8060)
              (pbStack_570,0x50,"%s PRIVATE KEY",*(undefined4 *)(pEVar5 + 0xc));
    pEVar3 = (EVP_PKEY *)
             PEM_ASN1_write_bio(PTR_i2d_PrivateKey_006a9fcc,(char *)pbStack_570,pBVar10,pbStack_520,
                                (EVP_CIPHER *)pbStack_574,(uchar *)pcStack_518,(int)bp,cb_00,u_01);
  }
  if (pBStack_48c == *(BIO **)puStack_524) {
    return pEVar3;
  }
  pcStack_514 = PEM_read_bio_Parameters;
  pBVar10 = pBStack_48c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_578 = PTR___stack_chk_guard_006aabf0;
  pBVar9 = (BIO *)&pBStack_53c;
  pBStack_57c = (BIO_METHOD *)0x670000;
  u_00 = "PARAMETERS";
  x_00 = &pBStack_530;
  pBStack_53c = (BIO_METHOD *)0x0;
  pBStack_538 = (BIO *)0x0;
  pBStack_534 = (BIO *)0x0;
  pBStack_52c = *(BIO **)PTR___stack_chk_guard_006aabf0;
  pbStack_51c = pbStack_574;
  iVar2 = PEM_bytes_read_bio((uchar **)&pBStack_534,(long *)x_00,(char **)pBVar9,"PARAMETERS",
                             pBVar10,(undefined1 *)0x0,(void *)0x0);
  if (iVar2 == 0) {
    pBVar6 = (BIO_METHOD *)0x0;
    goto LAB_00573c08;
  }
  pBStack_538 = pBStack_534;
  pbStack_574 = (bio_st *)pem_check_suffix(pBStack_53c,"PARAMETERS");
  if (((int)pbStack_574 < 1) ||
     (pBVar6 = (BIO_METHOD *)(*(code *)PTR_EVP_PKEY_new_006a8710)(), pBVar6 == (BIO_METHOD *)0x0)) {
LAB_00573bb8:
    pBStack_530 = (BIO *)&DAT_0000000d;
    u_00 = "pem_pkey.c";
    x_00 = (BIO **)&DAT_0000008c;
    pBVar6 = (BIO_METHOD *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(9);
  }
  else {
    iVar2 = (*(code *)PTR_EVP_PKEY_set_type_str_006a9fd0)(pBVar6,pBStack_53c,pbStack_574);
    if ((iVar2 == 0) || (*(code **)((EVP_PKEY_ASN1_METHOD *)pBVar6->bread + 0x38) == (code *)0x0)) {
LAB_00573ba8:
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(pBVar6);
      goto LAB_00573bb8;
    }
    x_00 = &pBStack_538;
    iVar2 = (**(code **)((EVP_PKEY_ASN1_METHOD *)pBVar6->bread + 0x38))(pBVar6);
    if (iVar2 == 0) goto LAB_00573ba8;
    if (pbStack_570 != (bio_st *)0x0) {
      if (pbStack_570->method != (BIO_METHOD *)0x0) {
        (*(code *)PTR_EVP_PKEY_free_006a7f78)();
      }
      pbStack_570->method = pBVar6;
    }
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)(pBStack_53c);
  (*(code *)PTR_CRYPTO_free_006a7f88)(pBStack_534);
  pBVar9 = pBStack_530;
  pBStack_57c = pBVar6;
LAB_00573c08:
  if (pBStack_52c == *(BIO **)puStack_578) {
    return (EVP_PKEY *)pBVar6;
  }
  pcStack_56c = PEM_write_bio_Parameters;
  pBVar10 = pBStack_52c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pBVar7 = x_00[3];
  iStack_584 = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((pBVar7 == (BIO *)0x0) || (pBVar9 = (BIO *)0x670000, (&pBVar7->ptr)[7] == (void *)0x0)) {
    pBVar10 = pBVar9;
    pEVar3 = (EVP_PKEY *)0x0;
  }
  else {
    name = apBStack_5d4;
    (*(code *)PTR_BIO_snprintf_006a8060)
              (name,0x50,"%s PARAMETERS",(EVP_PKEY_ASN1_METHOD *)pBVar7->init);
    u_00 = (char *)x_00;
    pEVar3 = (EVP_PKEY *)
             PEM_ASN1_write_bio((undefined1 *)(&x_00[3]->ptr)[7],(char *)name,pBVar10,x_00,
                                (EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
    x_00 = name;
  }
  if (iStack_584 != *(int *)puVar1) {
    iVar2 = iStack_584;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    uVar8 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    pBVar9 = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar8);
    if (pBVar9 == (BIO *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x7c,7,"pem_pkey.c",0xd8);
      pEVar3 = (EVP_PKEY *)0x0;
    }
    else {
      (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar9,0x6a,0,iVar2);
      pEVar3 = PEM_read_bio_PrivateKey(pBVar9,(EVP_PKEY **)x_00,(undefined1 *)pBVar10,u_00);
      (*(code *)PTR_BIO_free_006a7f70)(pBVar9);
    }
    return pEVar3;
  }
  return pEVar3;
}

