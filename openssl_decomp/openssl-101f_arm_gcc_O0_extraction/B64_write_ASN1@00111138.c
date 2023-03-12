
BIO * B64_write_ASN1(BIO *param_1,ASN1_VALUE *param_2,BIO *param_3,int param_4,ASN1_ITEM *param_5)

{
  BIO_METHOD *type;
  BIO *b;
  BIO *out;
  BIO *out_00;
  BIO *pBVar1;
  
  type = BIO_f_base64();
  b = BIO_new(type);
  if (b != (BIO *)0x0) {
    out = BIO_push(b,param_1);
    if (param_4 << 0x13 < 0) {
      out_00 = BIO_new_NDEF(out,param_2,param_5);
      if (out_00 == (BIO *)0x0) {
        ERR_put_error(0xd,0xd3,0x41,"asn_mime.c",0x7d);
      }
      else {
        SMIME_crlf_copy(param_3,out_00,param_4);
        BIO_ctrl(out_00,0xb,0,(void *)0x0);
        do {
          pBVar1 = BIO_pop(out_00);
          BIO_free(out_00);
          out_00 = pBVar1;
        } while (out != pBVar1);
        out_00 = (BIO *)0x1;
      }
    }
    else {
      out_00 = (BIO *)0x1;
      ASN1_item_i2d_bio(param_5,out,param_2);
    }
    BIO_ctrl(out,0xb,0,(void *)0x0);
    BIO_pop(out);
    BIO_free(b);
    return out_00;
  }
  ERR_put_error(0xd,0xd2,0x41,"asn_mime.c",0x9c);
  return (BIO *)0x0;
}

