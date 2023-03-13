
int ASN1_parse_dump(BIO *bp,uchar *pp,long len,int indent,int dump)

{
  int iVar1;
  
  iVar1 = asn1_parse2(0,0,indent,dump);
  return iVar1;
}

