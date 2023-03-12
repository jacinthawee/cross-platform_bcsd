
stack_st_X509_INFO * PEM_X509_INFO_read_bio(BIO *bp,stack_st_X509_INFO *sk,undefined1 *cb,void *u)

{
  uchar *puVar1;
  X509_INFO *pXVar2;
  int iVar3;
  EVP_PKEY *pEVar4;
  char *pcVar5;
  X509_PKEY *pXVar6;
  size_t sVar7;
  int iVar8;
  ulong uVar9;
  _STACK *p_Var10;
  _STACK *st;
  code *pcVar11;
  X509_INFO *local_60;
  int local_5c;
  char *local_54;
  char *local_50;
  uchar *local_4c;
  uchar *local_48;
  int local_44;
  EVP_CIPHER_INFO EStack_40;
  int local_2c;
  
  local_54 = (char *)0x0;
  local_2c = __TMC_END__;
  local_50 = (char *)0x0;
  local_4c = (uchar *)0x0;
  st = &sk->stack;
  if ((sk == (stack_st_X509_INFO *)0x0) && (st = sk_new_null(), st == (_STACK *)0x0)) {
    ERR_put_error(9,0x74,0x41,"pem_info.c",0x6c);
    p_Var10 = st;
  }
  else {
    pXVar2 = X509_INFO_new();
    p_Var10 = st;
    if (pXVar2 != (X509_INFO *)0x0) {
LAB_000c33f4:
      iVar3 = PEM_read_bio(bp,&local_54,&local_50,&local_4c,&local_44);
      if (iVar3 != 0) {
        do {
          pcVar5 = local_54;
          iVar3 = strcmp(local_54,"CERTIFICATE");
          local_60 = pXVar2;
          if ((iVar3 == 0) || (iVar3 = strcmp(pcVar5,"X509 CERTIFICATE"), iVar3 == 0)) {
            if (pXVar2->x509 == (X509 *)0x0) goto code_r0x000c3466;
LAB_000c3432:
            iVar3 = sk_push(st,pXVar2);
            if (iVar3 == 0) goto LAB_000c3678;
          }
          else {
            iVar3 = strcmp(pcVar5,"TRUSTED CERTIFICATE");
            if (iVar3 == 0) {
              if (pXVar2->x509 != (X509 *)0x0) goto LAB_000c3432;
              pcVar11 = d2i_X509_AUX + 1;
              goto LAB_000c3470;
            }
            iVar3 = strcmp(pcVar5,"X509 CRL");
            if (iVar3 == 0) {
              if (pXVar2->crl != (X509_CRL *)0x0) goto LAB_000c3432;
              local_60 = (X509_INFO *)&pXVar2->crl;
              pcVar11 = d2i_X509_CRL + 1;
              goto LAB_000c3470;
            }
            iVar3 = strcmp(pcVar5,"RSA PRIVATE KEY");
            if (iVar3 == 0) {
              if (pXVar2->x_pkey == (X509_PKEY *)0x0) {
                pXVar2->enc_data = (char *)0x0;
                pXVar2->enc_len = 0;
                pcVar11 = d2i_RSAPrivateKey + 1;
                pXVar6 = X509_PKEY_new();
                iVar3 = 6;
                local_5c = 6;
                local_60 = (X509_INFO *)&pXVar6->dec_pkey;
                pXVar2->x_pkey = pXVar6;
                goto LAB_000c353c;
              }
              goto LAB_000c3432;
            }
            iVar3 = strcmp(pcVar5,"DSA PRIVATE KEY");
            if (iVar3 == 0) {
              if (pXVar2->x_pkey == (X509_PKEY *)0x0) {
                pXVar2->enc_data = (char *)0x0;
                pXVar2->enc_len = 0;
                iVar3 = 0x74;
                pXVar6 = X509_PKEY_new();
                pcVar11 = d2i_DSAPrivateKey + 1;
                local_5c = 0x74;
                local_60 = (X509_INFO *)&pXVar6->dec_pkey;
                pXVar2->x_pkey = pXVar6;
LAB_000c353c:
                pcVar5 = local_50;
                sVar7 = strlen(local_50);
                if ((int)sVar7 < 0xb) goto LAB_000c347a;
                iVar3 = PEM_get_EVP_CIPHER_INFO(pcVar5,&pXVar2->enc_cipher);
                puVar1 = local_4c;
                if (iVar3 == 0) goto LAB_000c3678;
                local_4c = (uchar *)0x0;
                pXVar2->enc_data = (char *)puVar1;
                pXVar2->enc_len = local_44;
                pcVar5 = local_54;
                goto LAB_000c34be;
              }
            }
            else {
              iVar3 = strcmp(pcVar5,"EC PRIVATE KEY");
              if (iVar3 != 0) goto LAB_000c34be;
              if (pXVar2->x_pkey == (X509_PKEY *)0x0) {
                pXVar2->enc_data = (char *)0x0;
                pXVar2->enc_len = 0;
                iVar3 = 0x198;
                pXVar6 = X509_PKEY_new();
                pcVar11 = d2i_ECPrivateKey + 1;
                local_5c = 0x198;
                local_60 = (X509_INFO *)&pXVar6->dec_pkey;
                pXVar2->x_pkey = pXVar6;
                goto LAB_000c353c;
              }
            }
            iVar3 = sk_push(st,pXVar2);
            if (iVar3 == 0) goto LAB_000c367c;
          }
          pXVar2 = X509_INFO_new();
          if (pXVar2 == (X509_INFO *)0x0) goto LAB_000c35d2;
        } while( true );
      }
      uVar9 = ERR_peek_last_error();
      if ((uVar9 & 0xfff) == 0x6c) {
        ERR_clear_error();
        if ((((pXVar2->x509 == (X509 *)0x0) && (pXVar2->crl == (X509_CRL *)0x0)) &&
            (pXVar2->x_pkey == (X509_PKEY *)0x0)) && (pXVar2->enc_data == (char *)0x0)) {
          iVar3 = 1;
        }
        else {
          iVar3 = sk_push(st,pXVar2);
          if (iVar3 != 0) goto LAB_000c3600;
        }
        goto LAB_000c367c;
      }
      goto LAB_000c3678;
    }
  }
LAB_000c35d2:
  for (iVar3 = 0; iVar8 = sk_num(p_Var10), iVar3 < iVar8; iVar3 = iVar3 + 1) {
    pXVar2 = (X509_INFO *)sk_value(p_Var10,iVar3);
    X509_INFO_free(pXVar2);
  }
  if (p_Var10 == &sk->stack) {
    st = (_STACK *)0x0;
  }
  else {
    st = (_STACK *)0x0;
    sk_free(p_Var10);
  }
LAB_000c3600:
  if (local_54 != (char *)0x0) {
    CRYPTO_free(local_54);
  }
  if (local_50 != (char *)0x0) {
    CRYPTO_free(local_50);
  }
  if (local_4c != (uchar *)0x0) {
    CRYPTO_free(local_4c);
  }
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (stack_st_X509_INFO *)st;
code_r0x000c3466:
  pcVar11 = d2i_X509 + 1;
LAB_000c3470:
  iVar3 = 0;
  local_5c = 0;
  pcVar5 = local_50;
LAB_000c347a:
  iVar8 = PEM_get_EVP_CIPHER_INFO(pcVar5,&EStack_40);
  if ((iVar8 == 0) || (iVar8 = PEM_do_header(&EStack_40,local_4c,&local_44,cb,u), iVar8 == 0))
  goto LAB_000c3678;
  local_48 = local_4c;
  if (local_5c == 0) {
    iVar3 = (*pcVar11)(local_60,&local_48,local_44);
    pcVar5 = local_54;
    if (iVar3 != 0) goto LAB_000c34be;
    iVar3 = 0x103;
  }
  else {
    pEVar4 = d2i_PrivateKey(iVar3,(EVP_PKEY **)local_60,&local_48,local_44);
    pcVar5 = local_54;
    if (pEVar4 != (EVP_PKEY *)0x0) {
LAB_000c34be:
      if (pcVar5 != (char *)0x0) {
        CRYPTO_free(pcVar5);
      }
      if (local_50 != (char *)0x0) {
        CRYPTO_free(local_50);
      }
      if (local_4c != (uchar *)0x0) {
        CRYPTO_free(local_4c);
      }
      local_54 = (char *)0x0;
      local_50 = (char *)0x0;
      local_4c = (uchar *)0x0;
      goto LAB_000c33f4;
    }
    iVar3 = 0xfd;
  }
  ERR_put_error(9,0x74,0xd,"pem_info.c",iVar3);
LAB_000c3678:
  iVar3 = 0;
LAB_000c367c:
  X509_INFO_free(pXVar2);
  if (iVar3 != 0) goto LAB_000c3600;
  goto LAB_000c35d2;
}

