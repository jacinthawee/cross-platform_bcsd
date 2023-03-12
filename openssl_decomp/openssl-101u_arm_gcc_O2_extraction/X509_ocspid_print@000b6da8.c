
int X509_ocspid_print(BIO *bp,X509 *x)

{
  int iVar1;
  size_t sVar2;
  uchar *puVar3;
  EVP_MD *pEVar4;
  ASN1_BIT_STRING *pAVar5;
  byte *pbVar6;
  undefined4 local_3c;
  byte local_38 [20];
  int local_24;
  
  local_24 = __stack_chk_guard;
  iVar1 = BIO_printf(bp,"        Subject OCSP hash: ");
  if (0 < iVar1) {
    sVar2 = i2d_X509_NAME(x->cert_info->subject,(uchar **)0x0);
    puVar3 = (uchar *)CRYPTO_malloc(sVar2,"t_x509.c",0x109);
    local_3c = puVar3;
    if (puVar3 != (uchar *)0x0) {
      i2d_X509_NAME(x->cert_info->subject,(uchar **)&local_3c);
      pEVar4 = EVP_sha1();
      iVar1 = EVP_Digest(puVar3,sVar2,local_38,(uint *)0x0,pEVar4,(ENGINE *)0x0);
      if (iVar1 == 0) {
LAB_000b6e82:
        CRYPTO_free(puVar3);
        iVar1 = 0;
        goto LAB_000b6e74;
      }
      pbVar6 = (byte *)((int)&local_3c + 3);
      do {
        pbVar6 = pbVar6 + 1;
        iVar1 = BIO_printf(bp,"%02X",(uint)*pbVar6);
        if (iVar1 < 1) goto LAB_000b6e82;
      } while (pbVar6 != local_38 + 0x13);
      CRYPTO_free(puVar3);
      iVar1 = BIO_printf(bp,"\n        Public key OCSP hash: ");
      if (0 < iVar1) {
        pAVar5 = x->cert_info->key->public_key;
        puVar3 = pAVar5->data;
        sVar2 = pAVar5->length;
        pEVar4 = EVP_sha1();
        iVar1 = EVP_Digest(puVar3,sVar2,local_38,(uint *)0x0,pEVar4,(ENGINE *)0x0);
        if (iVar1 != 0) {
          pbVar6 = (byte *)((int)&local_3c + 3);
          do {
            pbVar6 = pbVar6 + 1;
            iVar1 = BIO_printf(bp,"%02X",(uint)*pbVar6);
            if (iVar1 < 1) goto LAB_000b6e72;
          } while (local_38 + 0x13 != pbVar6);
          BIO_printf(bp,"\n");
          iVar1 = 1;
          goto LAB_000b6e74;
        }
      }
    }
  }
LAB_000b6e72:
  iVar1 = 0;
LAB_000b6e74:
  if (local_24 == __stack_chk_guard) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

