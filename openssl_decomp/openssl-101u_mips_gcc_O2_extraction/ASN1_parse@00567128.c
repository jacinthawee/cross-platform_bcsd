
int ASN1_parse(BIO *bp,uchar *pp,long len,int indent)

{
  int iVar1;
  uchar *local_res4 [3];
  
  local_res4[0] = pp;
  iVar1 = asn1_parse2(bp,local_res4,len,0,0,indent,0);
  return iVar1;
}
