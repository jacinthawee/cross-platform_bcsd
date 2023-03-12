
int X509_signature_dump(BIO *bp,ASN1_STRING *sig,int indent)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uchar *puVar6;
  
  iVar5 = sig->length;
  puVar6 = sig->data;
  if (0 < iVar5) {
    iVar4 = 0;
    while( true ) {
      if (iVar4 == (iVar4 / 0x12) * 0x12) {
        iVar2 = BIO_write(bp,"\n",1);
        if (iVar2 < 1) {
          return 0;
        }
        iVar2 = BIO_indent(bp,indent,indent);
        if (iVar2 < 1) {
          return 0;
        }
      }
      pbVar1 = puVar6 + iVar4;
      iVar4 = iVar4 + 1;
      if (iVar4 == iVar5) break;
      iVar2 = BIO_printf(bp,"%02x%s",(uint)*pbVar1,":");
      if (iVar2 < 1) {
        return 0;
      }
    }
    iVar5 = BIO_printf(bp,"%02x%s",(uint)*pbVar1,"");
    if (iVar5 < 1) {
      return 0;
    }
  }
  iVar5 = BIO_write(bp,"\n",1);
  uVar3 = count_leading_zeroes(iVar5 + -1);
  return uVar3 >> 5;
}

