
int PEM_X509_INFO_write_bio
              (BIO *bp,X509_INFO *xi,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cd,void *u)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  char *type;
  int iVar4;
  int iVar5;
  int iVar6;
  X509 *x;
  EVP_CIPHER *pEVar7;
  uint uVar8;
  char *pcVar9;
  undefined auStack_4b8 [140];
  undefined local_42c;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pEVar7 = enc;
  pcVar9 = (char *)kstr;
  if (enc != (EVP_CIPHER *)0x0) {
    uVar2 = (*(code *)PTR_EVP_CIPHER_nid_006a73d0)(enc);
    iVar3 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar2);
    if (iVar3 != 0) goto LAB_0056ab94;
    pEVar7 = (EVP_CIPHER *)0x71;
    uVar2 = 0x141;
    goto LAB_0056ad54;
  }
LAB_0056ab94:
  if (xi->x_pkey == (X509_PKEY *)0x0) {
LAB_0056ad2c:
    enc = pEVar7;
    x = xi->x509;
    if (x == (X509 *)0x0) {
      uVar8 = 1;
      goto LAB_0056ac90;
    }
  }
  else {
    pcVar9 = xi->enc_data;
    if (((uchar *)pcVar9 == (uchar *)0x0) || (iVar3 = xi->enc_len, iVar3 < 1)) {
      iVar3 = PEM_write_bio_RSAPrivateKey(bp,(xi->x_pkey->dec_pkey->pkey).rsa,enc,kstr,klen,cd,u);
      pEVar7 = enc;
      pcVar9 = (char *)kstr;
      if (iVar3 < 1) {
        uVar8 = 0;
        goto LAB_0056ac90;
      }
      goto LAB_0056ad2c;
    }
    if (enc == (EVP_CIPHER *)0x0) {
      pEVar7 = (EVP_CIPHER *)0x7f;
      uVar2 = 0x14e;
LAB_0056ad54:
      pcVar9 = "pem_info.c";
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x75,pEVar7,"pem_info.c",uVar2);
LAB_0056ad6c:
      uVar8 = 0;
      enc = pEVar7;
      goto LAB_0056ac90;
    }
    uVar2 = (*(code *)PTR_EVP_CIPHER_nid_006a73d0)((xi->enc_cipher).cipher);
    type = (char *)(*(code *)PTR_OBJ_nid2sn_006a709c)(uVar2);
    if (type == (char *)0x0) {
      pEVar7 = (EVP_CIPHER *)0x71;
      uVar2 = 0x15f;
      goto LAB_0056ad54;
    }
    iVar4 = (*(code *)PTR_strlen_006a9a24)(type);
    if (0x400 < (uint)(enc->iv_len * 2 + 0x24 + iVar4)) {
      (*(code *)PTR_OpenSSLDie_006a7c5c)
                ("pem_info.c",0x165,"strlen(objstr) + 23 + 2 * enc->iv_len + 13 <= sizeof buf");
    }
    pEVar7 = (EVP_CIPHER *)&local_42c;
    local_42c = 0;
    PEM_proc_type((char *)pEVar7,10);
    PEM_dek_info((char *)pEVar7,type,enc->iv_len,(char *)(xi->enc_cipher).iv);
    iVar3 = PEM_write_bio(bp,"RSA PRIVATE KEY",(char *)pEVar7,(uchar *)pcVar9,iVar3);
    if (iVar3 < 1) goto LAB_0056ad6c;
    x = xi->x509;
    uVar8 = 1;
    enc = pEVar7;
    if (x == (X509 *)0x0) goto LAB_0056ac90;
  }
  iVar3 = PEM_write_bio_X509(bp,x);
  uVar8 = (uint)(0 < iVar3);
LAB_0056ac90:
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_4b8,0x8c);
  iVar3 = 0x400;
  (*(code *)PTR_OPENSSL_cleanse_006a7074)((EVP_CIPHER *)&local_42c);
  if (local_2c == *(int *)puVar1) {
    return uVar8;
  }
  iVar4 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((uchar *)pcVar9 == (uchar *)0x0) {
    pcVar9 = (char *)(*(code *)PTR_EVP_get_pw_prompt_006a8e30)();
    puVar1 = PTR_stderr_006a9af8;
    if (pcVar9 == (char *)0x0) {
      pcVar9 = "Enter PEM pass phrase:";
    }
    while( true ) {
      iVar6 = (*(code *)PTR_EVP_read_pw_string_min_006a8e34)(iVar4,4,iVar3,pcVar9,enc);
      if (iVar6 != 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(9,100,0x6d,"pem_lib.c",0x6e);
        (*(code *)PTR_memset_006a99f4)(iVar4,0,iVar3);
        return -1;
      }
      iVar6 = (*(code *)PTR_strlen_006a9a24)(iVar4);
      if (3 < iVar6) break;
      (*(code *)PTR___fprintf_chk_006a9980)
                (*(undefined4 *)puVar1,1,"phrase is too short, needs to be at least %d chars\n",4);
    }
  }
  else {
    iVar5 = (*(code *)PTR_strlen_006a9a24)(pcVar9);
    iVar6 = iVar3;
    if (iVar5 <= iVar3) {
      iVar6 = iVar5;
    }
    (*(code *)PTR_memcpy_006a9aec)(iVar4,pcVar9,iVar6);
  }
  return iVar6;
}

