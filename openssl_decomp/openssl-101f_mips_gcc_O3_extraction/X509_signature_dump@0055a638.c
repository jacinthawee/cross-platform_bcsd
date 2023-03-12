
int X509_signature_dump(BIO *bp,ASN1_STRING *sig,int indent)

{
  uchar uVar1;
  int iVar2;
  uchar *puVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = sig->length;
  puVar3 = sig->data;
  if (0 < iVar4) {
    iVar5 = 0;
    while( true ) {
      if (iVar5 == (iVar5 / 0x12) * 0x12) {
        iVar2 = (*(code *)PTR_BIO_write_006a7f14)(bp,"\n",1);
        if (iVar2 < 1) {
          return 0;
        }
        iVar2 = (*(code *)PTR_BIO_indent_006a97d0)(bp,indent,indent);
        if (iVar2 < 1) {
          return 0;
        }
      }
      iVar5 = iVar5 + 1;
      uVar1 = *puVar3;
      if (iVar4 == iVar5) break;
      puVar3 = puVar3 + 1;
      iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(bp,"%02x%s",uVar1,":");
      if (iVar2 < 1) {
        return 0;
      }
    }
    iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(bp,"%02x%s",uVar1,"");
    if (iVar4 < 1) {
      return 0;
    }
  }
  iVar4 = (*(code *)PTR_BIO_write_006a7f14)(bp,"\n",1);
  return (uint)(iVar4 == 1);
}

