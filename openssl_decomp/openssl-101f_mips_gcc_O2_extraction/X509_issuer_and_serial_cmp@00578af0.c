
int X509_issuer_and_serial_cmp(X509 *a,X509 *b)

{
  int iVar1;
  X509_CINF *pXVar2;
  X509_NAME *pXVar3;
  X509_CINF *pXVar4;
  X509_NAME *pXVar5;
  
  pXVar4 = a->cert_info;
  pXVar2 = b->cert_info;
  iVar1 = ASN1_STRING_cmp(pXVar4->serialNumber,pXVar2->serialNumber);
  if (iVar1 == 0) {
    pXVar5 = pXVar4->issuer;
    pXVar3 = pXVar2->issuer;
    if (((pXVar5->canon_enc == (uchar *)0x0) || (pXVar5->modified != 0)) &&
       (iVar1 = (*(code *)PTR_i2d_X509_NAME_006a87d8)(pXVar5,0), iVar1 < 0)) {
      iVar1 = -2;
    }
    else if (((pXVar3->canon_enc == (uchar *)0x0) || (pXVar3->modified != 0)) &&
            (iVar1 = (*(code *)PTR_i2d_X509_NAME_006a87d8)(pXVar3,0), iVar1 < 0)) {
      iVar1 = -2;
    }
    else {
      iVar1 = pXVar5->canon_enclen - pXVar3->canon_enclen;
      if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00578b9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar1 = (*(code *)PTR_memcmp_006aabd8)(pXVar5->canon_enc,pXVar3->canon_enc);
        return iVar1;
      }
    }
  }
  return iVar1;
}

