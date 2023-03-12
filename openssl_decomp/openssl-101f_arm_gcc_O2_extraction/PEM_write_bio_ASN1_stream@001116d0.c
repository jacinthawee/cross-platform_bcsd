
int PEM_write_bio_ASN1_stream(BIO *out,ASN1_VALUE *val,BIO *in,int flags,char *hdr,ASN1_ITEM *it)

{
  BIO_METHOD *type;
  BIO *b;
  BIO *out_00;
  BIO *out_01;
  BIO *pBVar1;
  
  BIO_printf(out,"-----BEGIN %s-----\n",hdr);
  type = BIO_f_base64();
  b = BIO_new(type);
  if (b == (BIO *)0x0) {
    ERR_put_error(0xd,0xd2,0x41,"asn_mime.c",0x9c);
  }
  else {
    out_00 = BIO_push(b,out);
    if (flags << 0x13 < 0) {
      out_01 = BIO_new_NDEF(out_00,val,it);
      if (out_01 == (BIO *)0x0) {
        ERR_put_error(0xd,0xd3,0x41,"asn_mime.c",0x7d);
      }
      else {
        SMIME_crlf_copy(in,out_01,flags);
        BIO_ctrl(out_01,0xb,0,(void *)0x0);
        do {
          pBVar1 = BIO_pop(out_01);
          BIO_free(out_01);
          out_01 = pBVar1;
        } while (out_00 != pBVar1);
        out_01 = (BIO *)0x1;
      }
    }
    else {
      out_01 = (BIO *)0x1;
      ASN1_item_i2d_bio(it,out_00,val);
    }
    BIO_ctrl(out_00,0xb,0,(void *)0x0);
    BIO_pop(out_00);
    BIO_free(b);
    b = out_01;
  }
  BIO_printf(out,"-----END %s-----\n",hdr);
  return (int)b;
}

