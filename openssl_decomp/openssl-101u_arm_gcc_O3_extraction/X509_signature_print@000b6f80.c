
int X509_signature_print(BIO *bp,X509_ALGOR *alg,ASN1_STRING *sig)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  EVP_PKEY_ASN1_METHOD *pEVar4;
  uint uVar5;
  int iVar6;
  uchar *puVar7;
  int local_20;
  int iStack_1c;
  
  iVar2 = BIO_puts(bp,"    Signature Algorithm: ");
  if ((0 < iVar2) && (iVar2 = i2a_ASN1_OBJECT(bp,alg->algorithm), 0 < iVar2)) {
    iVar2 = OBJ_obj2nid(alg->algorithm);
    if ((iVar2 != 0) &&
       (((iVar2 = OBJ_find_sigid_algs(iVar2,&iStack_1c,&local_20), iVar2 != 0 &&
         (pEVar4 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_20),
         pEVar4 != (EVP_PKEY_ASN1_METHOD *)0x0)) && (*(code **)(pEVar4 + 0x50) != (code *)0x0)))) {
      iVar2 = (**(code **)(pEVar4 + 0x50))(bp,alg,sig,9,0);
      return iVar2;
    }
    if (sig == (ASN1_STRING *)0x0) {
      iVar2 = BIO_puts(bp,"\n");
      return (uint)(0 < iVar2);
    }
    iVar2 = sig->length;
    puVar7 = sig->data;
    if (iVar2 < 1) {
LAB_000b707a:
      iVar2 = BIO_write(bp,"\n",1);
      uVar5 = count_leading_zeroes(iVar2 + -1);
      return uVar5 >> 5;
    }
    iVar6 = 0;
    do {
      if (iVar6 == (iVar6 / 0x12) * 0x12) {
        iVar3 = BIO_write(bp,"\n",1);
        if (iVar3 < 1) {
          return 0;
        }
        iVar3 = BIO_indent(bp,9,9);
        if (iVar3 < 1) {
          return 0;
        }
      }
      pbVar1 = puVar7 + iVar6;
      iVar6 = iVar6 + 1;
      if (iVar2 == iVar6) {
        iVar2 = BIO_printf(bp,"%02x%s",(uint)*pbVar1,"");
        if (iVar2 < 1) {
          return 0;
        }
        goto LAB_000b707a;
      }
      iVar3 = BIO_printf(bp,"%02x%s",(uint)*pbVar1,":");
    } while (0 < iVar3);
  }
  return 0;
}

