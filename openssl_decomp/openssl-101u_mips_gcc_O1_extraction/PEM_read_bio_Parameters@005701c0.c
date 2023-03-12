
EVP_PKEY * PEM_read_bio_Parameters(BIO *bp,EVP_PKEY **x)

{
  undefined *puVar1;
  int iVar2;
  EVP_PKEY *pEVar3;
  BIO *pBVar4;
  undefined4 uVar5;
  BIO *pBVar6;
  BIO *bp_00;
  BIO **x_00;
  BIO **name;
  char *u;
  int unaff_s2;
  BIO *apBStack_c4 [20];
  int iStack_74;
  EVP_PKEY *pEStack_6c;
  undefined *puStack_68;
  int iStack_64;
  EVP_PKEY **ppEStack_60;
  code *pcStack_5c;
  BIO_METHOD *local_2c;
  BIO *local_28;
  BIO *local_24;
  BIO *local_20;
  BIO *local_1c;
  
  puStack_68 = PTR___stack_chk_guard_006a9ae8;
  pBVar6 = (BIO *)&local_2c;
  pEStack_6c = (EVP_PKEY *)0x670000;
  u = "PARAMETERS";
  x_00 = &local_20;
  local_2c = (BIO_METHOD *)0x0;
  local_28 = (BIO *)0x0;
  local_24 = (BIO *)0x0;
  local_1c = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  iVar2 = PEM_bytes_read_bio((uchar **)&local_24,(long *)x_00,(char **)pBVar6,"PARAMETERS",bp,
                             (undefined1 *)0x0,(void *)0x0);
  if (iVar2 == 0) {
    pEVar3 = (EVP_PKEY *)0x0;
    goto LAB_00570338;
  }
  local_28 = local_24;
  unaff_s2 = pem_check_suffix(local_2c,"PARAMETERS");
  if ((unaff_s2 < 1) ||
     (pEVar3 = (EVP_PKEY *)(*(code *)PTR_EVP_PKEY_new_006a7620)(), pEVar3 == (EVP_PKEY *)0x0)) {
LAB_005702e8:
    local_20 = (BIO *)&DAT_0000000d;
    u = "pem_pkey.c";
    x_00 = (BIO **)&DAT_0000008c;
    pEVar3 = (EVP_PKEY *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(9);
  }
  else {
    iVar2 = (*(code *)PTR_EVP_PKEY_set_type_str_006a8eb4)(pEVar3,local_2c,unaff_s2);
    if ((iVar2 == 0) || (*(code **)(pEVar3->ameth + 0x38) == (code *)0x0)) {
LAB_005702d8:
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(pEVar3);
      goto LAB_005702e8;
    }
    x_00 = &local_28;
    iVar2 = (**(code **)(pEVar3->ameth + 0x38))(pEVar3);
    if (iVar2 == 0) goto LAB_005702d8;
    if (x != (EVP_PKEY **)0x0) {
      if (*x != (EVP_PKEY *)0x0) {
        (*(code *)PTR_EVP_PKEY_free_006a6e78)();
      }
      *x = pEVar3;
    }
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(local_2c);
  (*(code *)PTR_CRYPTO_free_006a6e88)(local_24);
  pBVar6 = local_20;
  pEStack_6c = pEVar3;
LAB_00570338:
  if (local_1c == *(BIO **)puStack_68) {
    return pEVar3;
  }
  pcStack_5c = PEM_write_bio_Parameters;
  bp_00 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pBVar4 = x_00[3];
  iStack_74 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_64 = unaff_s2;
  ppEStack_60 = x;
  if ((pBVar4 == (BIO *)0x0) || (pBVar6 = (BIO *)0x670000, (&pBVar4->ptr)[7] == (void *)0x0)) {
    bp_00 = pBVar6;
    pEVar3 = (EVP_PKEY *)0x0;
  }
  else {
    name = apBStack_c4;
    (*(code *)PTR_BIO_snprintf_006a6f60)
              (name,0x50,"%s PARAMETERS",(EVP_PKEY_ASN1_METHOD *)pBVar4->init);
    u = (char *)x_00;
    pEVar3 = (EVP_PKEY *)
             PEM_ASN1_write_bio((undefined1 *)(&x_00[3]->ptr)[7],(char *)name,bp_00,x_00,
                                (EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
    x_00 = name;
  }
  if (iStack_74 != *(int *)puVar1) {
    iVar2 = iStack_74;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    uVar5 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    pBVar6 = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar5);
    if (pBVar6 == (BIO *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x7c,7,"pem_pkey.c",0xda);
      pEVar3 = (EVP_PKEY *)0x0;
    }
    else {
      (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar6,0x6a,0,iVar2);
      pEVar3 = PEM_read_bio_PrivateKey(pBVar6,(EVP_PKEY **)x_00,(undefined1 *)bp_00,u);
      (*(code *)PTR_BIO_free_006a6e70)(pBVar6);
    }
    return pEVar3;
  }
  return pEVar3;
}

