
int PEM_write_bio_ASN1_stream(BIO *out,ASN1_VALUE *val,BIO *in,int flags,char *hdr,ASN1_ITEM *it)

{
  int iVar1;
  
  BIO_printf(out,"-----BEGIN %s-----\n",hdr);
  iVar1 = B64_write_ASN1(flags,it);
  BIO_printf(out,"-----END %s-----\n",hdr);
  return iVar1;
}

