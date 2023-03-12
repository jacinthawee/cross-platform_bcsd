
int i2d_ASN1_bio_stream(BIO *out,ASN1_VALUE *val,BIO *in,int flags,ASN1_ITEM *it)

{
  BIO *out_00;
  BIO *pBVar1;
  int iVar2;
  
  if ((flags & 0x1000U) == 0) {
    (*(code *)PTR_ASN1_item_i2d_bio_006a8810)(it,out,val);
    iVar2 = 1;
  }
  else {
    out_00 = BIO_new_NDEF(out,val,it);
    if (out_00 != (BIO *)0x0) {
      SMIME_crlf_copy(in,out_00,flags);
      (*(code *)PTR_BIO_ctrl_006a7f18)(out_00,0xb,0,0);
      do {
        pBVar1 = (BIO *)(*(code *)PTR_BIO_pop_006a8ab4)(out_00);
        (*(code *)PTR_BIO_free_006a7f70)(out_00);
        out_00 = pBVar1;
      } while (out != pBVar1);
      return 1;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xd3,0x41,"asn_mime.c",0x7d);
    iVar2 = 0;
  }
  return iVar2;
}

