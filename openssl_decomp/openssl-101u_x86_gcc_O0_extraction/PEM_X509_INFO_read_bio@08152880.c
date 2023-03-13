
stack_st_X509_INFO * PEM_X509_INFO_read_bio(BIO *bp,stack_st_X509_INFO *sk,undefined1 *cb,void *u)

{
  uchar *puVar1;
  X509_INFO *pXVar2;
  int iVar3;
  EVP_PKEY *pEVar4;
  X509_PKEY *pXVar5;
  size_t sVar6;
  int iVar7;
  ulong uVar8;
  _STACK *p_Var9;
  _STACK *st;
  char *pcVar10;
  X509_INFO *pXVar11;
  char *pcVar12;
  int in_GS_OFFSET;
  bool bVar13;
  byte bVar14;
  code *local_54;
  int local_50;
  char *local_48;
  char *local_44;
  uchar *local_40;
  uchar *local_3c;
  int local_38;
  EVP_CIPHER_INFO local_34;
  int local_20;
  
  bVar14 = 0;
  local_48 = (char *)0x0;
  local_44 = (char *)0x0;
  local_40 = (uchar *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  st = &sk->stack;
  if ((sk == (stack_st_X509_INFO *)0x0) && (st = sk_new_null(), st == (_STACK *)0x0)) {
    ERR_put_error(9,0x74,0x41,"pem_info.c",0x6b);
    p_Var9 = st;
  }
  else {
    pXVar2 = X509_INFO_new();
    p_Var9 = st;
    if (pXVar2 != (X509_INFO *)0x0) {
LAB_081528e5:
      iVar3 = PEM_read_bio(bp,&local_48,&local_44,&local_40,&local_38);
      bVar13 = iVar3 == 0;
      if (!bVar13) {
        do {
          iVar3 = 0xc;
          pcVar10 = local_48;
          pcVar12 = "CERTIFICATE";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar13 = *pcVar10 == *pcVar12;
            pcVar10 = pcVar10 + (uint)bVar14 * -2 + 1;
            pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
          } while (bVar13);
          pXVar11 = pXVar2;
          if (bVar13) {
LAB_08152988:
            if (pXVar2->x509 == (X509 *)0x0) goto code_r0x0815298f;
          }
          else {
            iVar3 = 0x11;
            pcVar10 = local_48;
            pcVar12 = "X509 CERTIFICATE";
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar13 = *pcVar10 == *pcVar12;
              pcVar10 = pcVar10 + (uint)bVar14 * -2 + 1;
              pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
            } while (bVar13);
            if (bVar13) goto LAB_08152988;
            iVar3 = 0x14;
            pcVar10 = local_48;
            pcVar12 = "TRUSTED CERTIFICATE";
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar13 = *pcVar10 == *pcVar12;
              pcVar10 = pcVar10 + (uint)bVar14 * -2 + 1;
              pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
            } while (bVar13);
            if (bVar13) {
              if (pXVar2->x509 == (X509 *)0x0) {
                local_54 = d2i_X509_AUX;
                goto LAB_08152999;
              }
            }
            else {
              iVar3 = 9;
              pcVar10 = local_48;
              pcVar12 = "X509 CRL";
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar13 = *pcVar10 == *pcVar12;
                pcVar10 = pcVar10 + (uint)bVar14 * -2 + 1;
                pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
              } while (bVar13);
              if (bVar13) {
                if (pXVar2->crl == (X509_CRL *)0x0) {
                  pXVar11 = (X509_INFO *)&pXVar2->crl;
                  local_54 = d2i_X509_CRL;
                  goto LAB_08152999;
                }
              }
              else {
                iVar3 = 0x10;
                pcVar10 = local_48;
                pcVar12 = "RSA PRIVATE KEY";
                do {
                  if (iVar3 == 0) break;
                  iVar3 = iVar3 + -1;
                  bVar13 = *pcVar10 == *pcVar12;
                  pcVar10 = pcVar10 + (uint)bVar14 * -2 + 1;
                  pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
                } while (bVar13);
                if (bVar13) {
                  if (pXVar2->x_pkey == (X509_PKEY *)0x0) {
                    pXVar2->enc_data = (char *)0x0;
                    pXVar2->enc_len = 0;
                    pXVar5 = X509_PKEY_new();
                    pXVar2->x_pkey = pXVar5;
                    if (pXVar5 != (X509_PKEY *)0x0) {
                      pXVar11 = (X509_INFO *)&pXVar5->dec_pkey;
                      iVar3 = 6;
                      sVar6 = strlen(local_44);
                      local_50 = 6;
                      bVar13 = 10 < (int)sVar6;
                      local_54 = d2i_RSAPrivateKey;
                      goto LAB_08152b0d;
                    }
                    goto LAB_08152d50;
                  }
                }
                else {
                  iVar3 = 0x10;
                  pcVar10 = local_48;
                  pcVar12 = "DSA PRIVATE KEY";
                  do {
                    if (iVar3 == 0) break;
                    iVar3 = iVar3 + -1;
                    bVar13 = *pcVar10 == *pcVar12;
                    pcVar10 = pcVar10 + (uint)bVar14 * -2 + 1;
                    pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
                  } while (bVar13);
                  if (bVar13) {
                    if (pXVar2->x_pkey == (X509_PKEY *)0x0) {
                      pXVar2->enc_data = (char *)0x0;
                      pXVar2->enc_len = 0;
                      pXVar5 = X509_PKEY_new();
                      pXVar2->x_pkey = pXVar5;
                      if (pXVar5 != (X509_PKEY *)0x0) {
                        pXVar11 = (X509_INFO *)&pXVar5->dec_pkey;
                        iVar3 = 0x74;
                        sVar6 = strlen(local_44);
                        local_50 = 0x74;
                        bVar13 = 10 < (int)sVar6;
                        local_54 = d2i_DSAPrivateKey;
                        goto LAB_08152b0d;
                      }
                      goto LAB_08152d50;
                    }
                  }
                  else {
                    iVar3 = 0xf;
                    pcVar10 = local_48;
                    pcVar12 = "EC PRIVATE KEY";
                    do {
                      if (iVar3 == 0) break;
                      iVar3 = iVar3 + -1;
                      bVar13 = *pcVar10 == *pcVar12;
                      pcVar10 = pcVar10 + (uint)bVar14 * -2 + 1;
                      pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
                    } while (bVar13);
                    if (!bVar13) goto LAB_08152a1e;
                    if (pXVar2->x_pkey == (X509_PKEY *)0x0) {
                      pXVar2->enc_data = (char *)0x0;
                      pXVar2->enc_len = 0;
                      pXVar5 = X509_PKEY_new();
                      pXVar2->x_pkey = pXVar5;
                      if (pXVar5 == (X509_PKEY *)0x0) goto LAB_08152d50;
                      pXVar11 = (X509_INFO *)&pXVar5->dec_pkey;
                      iVar3 = 0x198;
                      sVar6 = strlen(local_44);
                      local_50 = 0x198;
                      bVar13 = 10 < (int)sVar6;
                      local_54 = d2i_ECPrivateKey;
LAB_08152b0d:
                      if (!bVar13) goto LAB_081529a3;
                      iVar3 = PEM_get_EVP_CIPHER_INFO(local_44,&pXVar2->enc_cipher);
                      puVar1 = local_40;
                      if (iVar3 == 0) goto LAB_08152d50;
                      local_40 = (uchar *)0x0;
                      pXVar2->enc_data = (char *)puVar1;
                      pXVar2->enc_len = local_38;
                      goto LAB_08152a16;
                    }
                  }
                }
              }
            }
          }
          iVar3 = sk_push(st,pXVar2);
          if (iVar3 == 0) goto LAB_08152d50;
          pXVar2 = X509_INFO_new();
          bVar13 = pXVar2 == (X509_INFO *)0x0;
          if (bVar13) goto LAB_08152c10;
        } while( true );
      }
      uVar8 = ERR_peek_last_error();
      if ((uVar8 & 0xfff) == 0x6c) {
        ERR_clear_error();
        if ((((pXVar2->x509 == (X509 *)0x0) && (pXVar2->crl == (X509_CRL *)0x0)) &&
            (pXVar2->x_pkey == (X509_PKEY *)0x0)) && (pXVar2->enc_data == (char *)0x0)) {
          X509_INFO_free(pXVar2);
          goto LAB_08152c58;
        }
        iVar3 = sk_push(st,pXVar2);
        if (iVar3 != 0) goto LAB_08152c58;
      }
      goto LAB_08152d50;
    }
  }
LAB_08152c10:
  for (iVar3 = 0; iVar7 = sk_num(p_Var9), iVar3 < iVar7; iVar3 = iVar3 + 1) {
    pXVar2 = (X509_INFO *)sk_value(p_Var9,iVar3);
    X509_INFO_free(pXVar2);
  }
  if (p_Var9 == &sk->stack) {
    st = (_STACK *)0x0;
  }
  else {
    st = (_STACK *)0x0;
    sk_free(p_Var9);
  }
LAB_08152c58:
  if (local_48 != (char *)0x0) {
    CRYPTO_free(local_48);
  }
  if (local_44 != (char *)0x0) {
    CRYPTO_free(local_44);
  }
  if (local_40 != (uchar *)0x0) {
    CRYPTO_free(local_40);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (stack_st_X509_INFO *)st;
code_r0x0815298f:
  local_54 = d2i_X509;
LAB_08152999:
  local_50 = 0;
  iVar3 = 0;
LAB_081529a3:
  iVar7 = PEM_get_EVP_CIPHER_INFO(local_44,&local_34);
  if ((iVar7 == 0) || (iVar7 = PEM_do_header(&local_34,local_40,&local_38,cb,u), iVar7 == 0))
  goto LAB_08152d50;
  local_3c = local_40;
  if (iVar3 == 0) {
    iVar3 = (*local_54)(pXVar11,&local_3c,local_38);
    if (iVar3 == 0) {
      iVar3 = 0xf9;
      goto LAB_08152d36;
    }
  }
  else {
    pEVar4 = d2i_PrivateKey(local_50,(EVP_PKEY **)pXVar11,&local_3c,local_38);
    if (pEVar4 == (EVP_PKEY *)0x0) {
      iVar3 = 0xf5;
LAB_08152d36:
      ERR_put_error(9,0x74,0xd,"pem_info.c",iVar3);
LAB_08152d50:
      X509_INFO_free(pXVar2);
      goto LAB_08152c10;
    }
  }
LAB_08152a16:
  if (local_48 != (char *)0x0) {
LAB_08152a1e:
    CRYPTO_free(local_48);
  }
  if (local_44 != (char *)0x0) {
    CRYPTO_free(local_44);
  }
  if (local_40 != (uchar *)0x0) {
    CRYPTO_free(local_40);
  }
  local_48 = (char *)0x0;
  local_44 = (char *)0x0;
  local_40 = (uchar *)0x0;
  goto LAB_081528e5;
}

