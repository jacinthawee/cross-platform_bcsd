
int PEM_write_bio_PrivateKey
              (BIO *bp,EVP_PKEY *x,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cb,void *u)

{
  undefined *puVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  int iVar3;
  char *pcVar4;
  BIO *pBVar5;
  undefined4 uVar6;
  BIO *pBVar7;
  EVP_PKEY *pEVar8;
  BIO *pBVar9;
  BIO **x_00;
  BIO **name;
  char *u_00;
  BIO *apBStack_174 [20];
  int iStack_124;
  char *pcStack_11c;
  undefined *puStack_118;
  EVP_CIPHER *pEStack_114;
  EVP_PKEY *pEStack_110;
  code *pcStack_10c;
  BIO_METHOD *pBStack_dc;
  BIO *pBStack_d8;
  BIO *pBStack_d4;
  BIO *pBStack_d0;
  BIO *pBStack_cc;
  undefined *puStack_c4;
  EVP_PKEY *pEStack_c0;
  EVP_CIPHER *pEStack_bc;
  bio_st *pbStack_b8;
  code *pcStack_b4;
  EVP_PKEY aEStack_7c [2];
  BIO *local_2c;
  
  puStack_c4 = PTR___stack_chk_guard_006aabf0;
  pEVar2 = x->ameth;
  local_2c = *(BIO **)PTR___stack_chk_guard_006aabf0;
  if ((pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0) || (*(int *)(pEVar2 + 0x28) != 0)) {
    pEStack_110 = x;
    iVar3 = PEM_write_bio_PKCS8PrivateKey(bp,x,enc,(char *)kstr,klen,cb,u);
  }
  else {
    pEStack_110 = aEStack_7c;
    (*(code *)PTR_BIO_snprintf_006a8060)
              (pEStack_110,0x50,"%s PRIVATE KEY",*(undefined4 *)(pEVar2 + 0xc));
    iVar3 = PEM_ASN1_write_bio(PTR_i2d_PrivateKey_006a9fcc,(char *)pEStack_110,bp,x,enc,kstr,klen,cb
                               ,u);
  }
  if (local_2c == *(BIO **)puStack_c4) {
    return iVar3;
  }
  pcStack_b4 = PEM_read_bio_Parameters;
  pBVar9 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_118 = PTR___stack_chk_guard_006aabf0;
  pBVar7 = (BIO *)&pBStack_dc;
  pcStack_11c = "7 datafinal";
  u_00 = "PARAMETERS";
  x_00 = &pBStack_d0;
  pBStack_dc = (BIO_METHOD *)0x0;
  pBStack_d8 = (BIO *)0x0;
  pBStack_d4 = (BIO *)0x0;
  pBStack_cc = *(BIO **)PTR___stack_chk_guard_006aabf0;
  pEStack_c0 = x;
  pEStack_bc = enc;
  pbStack_b8 = (bio_st *)kstr;
  iVar3 = PEM_bytes_read_bio((uchar **)&pBStack_d4,(long *)x_00,(char **)pBVar7,"PARAMETERS",pBVar9,
                             (undefined1 *)0x0,(void *)0x0);
  if (iVar3 == 0) {
    pcVar4 = (char *)0x0;
    goto LAB_00573c08;
  }
  pBStack_d8 = pBStack_d4;
  enc = (EVP_CIPHER *)pem_check_suffix(pBStack_dc,"PARAMETERS");
  if (((int)enc < 1) ||
     (pcVar4 = (char *)(*(code *)PTR_EVP_PKEY_new_006a8710)(), pcVar4 == (char *)0x0)) {
LAB_00573bb8:
    pBStack_d0 = (BIO *)&DAT_0000000d;
    u_00 = "pem_pkey.c";
    x_00 = (BIO **)&DAT_0000008c;
    pcVar4 = (char *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(9);
  }
  else {
    iVar3 = (*(code *)PTR_EVP_PKEY_set_type_str_006a9fd0)(pcVar4,pBStack_dc,enc);
    if ((iVar3 == 0) || (*(code **)(*(int *)(pcVar4 + 0xc) + 0x38) == (code *)0x0)) {
LAB_00573ba8:
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(pcVar4);
      goto LAB_00573bb8;
    }
    x_00 = &pBStack_d8;
    iVar3 = (**(code **)(*(int *)(pcVar4 + 0xc) + 0x38))(pcVar4);
    if (iVar3 == 0) goto LAB_00573ba8;
    if (pEStack_110 != (EVP_PKEY *)0x0) {
      if (pEStack_110->type != 0) {
        (*(code *)PTR_EVP_PKEY_free_006a7f78)();
      }
      pEStack_110->type = (int)pcVar4;
    }
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)(pBStack_dc);
  (*(code *)PTR_CRYPTO_free_006a7f88)(pBStack_d4);
  pBVar7 = pBStack_d0;
  pcStack_11c = pcVar4;
LAB_00573c08:
  if (pBStack_cc == *(BIO **)puStack_118) {
    return (int)pcVar4;
  }
  pcStack_10c = PEM_write_bio_Parameters;
  pBVar9 = pBStack_cc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pBVar5 = x_00[3];
  iStack_124 = *(int *)PTR___stack_chk_guard_006aabf0;
  pEStack_114 = enc;
  if ((pBVar5 == (BIO *)0x0) || (pBVar7 = (BIO *)0x670000, (&pBVar5->ptr)[7] == (void *)0x0)) {
    pBVar9 = pBVar7;
    iVar3 = 0;
  }
  else {
    name = apBStack_174;
    (*(code *)PTR_BIO_snprintf_006a8060)
              (name,0x50,"%s PARAMETERS",(EVP_PKEY_ASN1_METHOD *)pBVar5->init);
    u_00 = (char *)x_00;
    iVar3 = PEM_ASN1_write_bio((undefined1 *)(&x_00[3]->ptr)[7],(char *)name,pBVar9,x_00,
                               (EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
    x_00 = name;
  }
  if (iStack_124 != *(int *)puVar1) {
    iVar3 = iStack_124;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    uVar6 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    pBVar7 = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar6);
    if (pBVar7 == (BIO *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x7c,7,"pem_pkey.c",0xd8);
      pEVar8 = (EVP_PKEY *)0x0;
    }
    else {
      (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar7,0x6a,0,iVar3);
      pEVar8 = PEM_read_bio_PrivateKey(pBVar7,(EVP_PKEY **)x_00,(undefined1 *)pBVar9,u_00);
      (*(code *)PTR_BIO_free_006a7f70)(pBVar7);
    }
    return (int)pEVar8;
  }
  return iVar3;
}

