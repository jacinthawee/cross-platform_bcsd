
int PEM_write_bio_ASN1_stream(BIO *out,ASN1_VALUE *val,BIO *in,int flags,char *hdr,ASN1_ITEM *it)

{
  int iVar1;
  
  (*(code *)PTR_BIO_printf_006a6e38)(out,"-----BEGIN %s-----\n",hdr);
  iVar1 = B64_write_ASN1(out,val,in,flags,it);
  (*(code *)PTR_BIO_printf_006a6e38)(out,"-----END %s-----\n",hdr);
  return iVar1;
}

