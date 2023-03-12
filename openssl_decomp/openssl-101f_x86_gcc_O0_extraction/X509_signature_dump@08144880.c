
int X509_signature_dump(BIO *bp,ASN1_STRING *sig,int indent)

{
  uchar *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = sig->length;
  puVar1 = sig->data;
  iVar4 = 0;
  if (0 < iVar3) {
    while( true ) {
      if (iVar4 == (iVar4 / 0x12) * 0x12) {
        iVar2 = BIO_write(bp,&DAT_081f11d3,1);
        if (iVar2 < 1) {
          return 0;
        }
        iVar2 = BIO_indent(bp,indent,indent);
        if (iVar2 < 1) {
          return 0;
        }
      }
      if (iVar3 == iVar4 + 1) break;
      iVar2 = BIO_printf(bp,"%02x%s",(uint)puVar1[iVar4],":");
      iVar4 = iVar4 + 1;
      if (iVar2 < 1) {
        return 0;
      }
    }
    iVar3 = BIO_printf(bp,"%02x%s",(uint)puVar1[iVar4],&DAT_081ec74a);
    if (iVar3 < 1) {
      return 0;
    }
  }
  iVar3 = BIO_write(bp,&DAT_081f11d3,1);
  return (uint)(iVar3 == 1);
}

