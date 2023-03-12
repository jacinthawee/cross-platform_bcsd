
int X509_issuer_and_serial_cmp(X509 *a,X509 *b)

{
  X509_CINF *pXVar1;
  X509_CINF *pXVar2;
  X509_NAME *a_00;
  X509_NAME *a_01;
  int iVar3;
  
  pXVar1 = a->cert_info;
  pXVar2 = b->cert_info;
  iVar3 = ASN1_STRING_cmp(pXVar1->serialNumber,pXVar2->serialNumber);
  if (iVar3 == 0) {
    a_00 = pXVar1->issuer;
    a_01 = pXVar2->issuer;
    if ((((a_00->canon_enc == (uchar *)0x0) || (a_00->modified != 0)) &&
        (iVar3 = i2d_X509_NAME(a_00,(uchar **)0x0), iVar3 < 0)) ||
       (((a_01->canon_enc == (uchar *)0x0 || (a_01->modified != 0)) &&
        (iVar3 = i2d_X509_NAME(a_01,(uchar **)0x0), iVar3 < 0)))) {
      iVar3 = -2;
    }
    else {
      iVar3 = a_00->canon_enclen - a_01->canon_enclen;
      if (iVar3 == 0) {
        iVar3 = memcmp(a_00->canon_enc,a_01->canon_enc,a_00->canon_enclen);
        return iVar3;
      }
    }
  }
  return iVar3;
}

