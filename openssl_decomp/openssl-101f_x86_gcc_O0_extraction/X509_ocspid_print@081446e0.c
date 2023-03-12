
int X509_ocspid_print(BIO *bp,X509 *x)

{
  ASN1_BIT_STRING *pAVar1;
  int iVar2;
  size_t count;
  uchar *data;
  EVP_MD *pEVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int in_GS_OFFSET;
  uchar *local_38;
  int local_34 [5];
  int local_20 [4];
  
  local_20[0] = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = BIO_printf(bp,"        Subject OCSP hash: ");
  if (0 < iVar2) {
    count = i2d_X509_NAME(x->cert_info->subject,(uchar **)0x0);
    data = (uchar *)CRYPTO_malloc(count,"t_x509.c",0x103);
    local_38 = data;
    if (data != (uchar *)0x0) {
      i2d_X509_NAME(x->cert_info->subject,&local_38);
      pEVar3 = EVP_sha1();
      iVar2 = EVP_Digest(data,count,(uchar *)local_34,(uint *)0x0,pEVar3,(ENGINE *)0x0);
      if (iVar2 == 0) {
LAB_08144820:
        CRYPTO_free(data);
        iVar2 = 0;
        goto LAB_08144802;
      }
      piVar5 = local_34;
      piVar6 = piVar5;
      do {
        uVar4 = (uint)*(byte *)piVar6;
        iVar2 = BIO_printf(bp,"%02X",uVar4);
        if (iVar2 < 1) goto LAB_08144820;
        piVar6 = (int *)((int)piVar6 + 1);
      } while (local_20 != piVar6);
      CRYPTO_free(data);
      iVar2 = BIO_printf(bp,"\n        Public key OCSP hash: ",uVar4);
      if (0 < iVar2) {
        pEVar3 = EVP_sha1();
        pAVar1 = x->cert_info->key->public_key;
        iVar2 = EVP_Digest(pAVar1->data,pAVar1->length,(uchar *)local_34,(uint *)0x0,pEVar3,
                           (ENGINE *)0x0);
        if (iVar2 != 0) {
          do {
            uVar4 = (uint)*(byte *)piVar5;
            iVar2 = BIO_printf(bp,"%02X",uVar4);
            if (iVar2 < 1) goto LAB_08144800;
            piVar5 = (int *)((int)piVar5 + 1);
          } while (local_20 != piVar5);
          BIO_printf(bp,"\n",uVar4);
          iVar2 = 1;
          goto LAB_08144802;
        }
      }
    }
  }
LAB_08144800:
  iVar2 = 0;
LAB_08144802:
  if (local_20[0] != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

