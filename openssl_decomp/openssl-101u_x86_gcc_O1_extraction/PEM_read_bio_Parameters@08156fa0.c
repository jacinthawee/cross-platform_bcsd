
EVP_PKEY * PEM_read_bio_Parameters(BIO *bp,EVP_PKEY **x)

{
  int iVar1;
  EVP_PKEY *pkey;
  int in_GS_OFFSET;
  char *local_20;
  uchar *local_1c;
  uchar *local_18;
  long local_14;
  int local_10;
  
  pkey = (EVP_PKEY *)0x0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_20 = (char *)0x0;
  local_1c = (uchar *)0x0;
  local_18 = (uchar *)0x0;
  iVar1 = PEM_bytes_read_bio(&local_18,&local_14,&local_20,"PARAMETERS",bp,(undefined1 *)0x0,
                             (void *)0x0);
  if (iVar1 == 0) goto LAB_081570c5;
  local_1c = local_18;
  iVar1 = pem_check_suffix(local_20,"PARAMETERS");
  if (iVar1 < 1) {
LAB_0815708c:
    pkey = (EVP_PKEY *)0x0;
    ERR_put_error(9,0x8c,0xd,"pem_pkey.c",0xc1);
  }
  else {
    pkey = EVP_PKEY_new();
    if (pkey == (EVP_PKEY *)0x0) goto LAB_0815708c;
    iVar1 = EVP_PKEY_set_type_str(pkey,local_20,iVar1);
    if ((iVar1 == 0) || (*(code **)(pkey->ameth + 0x38) == (code *)0x0)) {
LAB_08157080:
      EVP_PKEY_free(pkey);
      goto LAB_0815708c;
    }
    iVar1 = (**(code **)(pkey->ameth + 0x38))(pkey,&local_1c,local_14);
    if (iVar1 == 0) goto LAB_08157080;
    if (x != (EVP_PKEY **)0x0) {
      if (*x != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(*x);
      }
      *x = pkey;
    }
  }
  CRYPTO_free(local_20);
  CRYPTO_free(local_18);
LAB_081570c5:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pkey;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

