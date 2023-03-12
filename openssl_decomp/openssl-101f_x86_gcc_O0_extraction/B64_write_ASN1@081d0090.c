
BIO * __regparm3
B64_write_ASN1(BIO *param_1_00,ASN1_VALUE *param_2_00,BIO *param_3,uint param_1,ASN1_ITEM *param_2)

{
  BIO_METHOD *type;
  BIO *b;
  BIO *out;
  BIO *pBVar1;
  BIO *out_00;
  
  type = BIO_f_base64();
  b = BIO_new(type);
  if (b == (BIO *)0x0) {
    ERR_put_error(0xd,0xd2,0x41,"asn_mime.c",0x9c);
    return (BIO *)0x0;
  }
  out = BIO_push(b,param_1_00);
  if ((param_1 & 0x1000) == 0) {
    ASN1_item_i2d_bio(param_2,out,param_2_00);
  }
  else {
    out_00 = BIO_new_NDEF(out,param_2_00,param_2);
    if (out_00 == (BIO *)0x0) {
      ERR_put_error(0xd,0xd3,0x41,"asn_mime.c",0x7d);
      goto LAB_081d00e7;
    }
    SMIME_crlf_copy(param_3,out_00,param_1);
    BIO_ctrl(out_00,0xb,0,(void *)0x0);
    do {
      pBVar1 = BIO_pop(out_00);
      BIO_free(out_00);
      out_00 = pBVar1;
    } while (out != pBVar1);
  }
  out_00 = (BIO *)0x1;
LAB_081d00e7:
  BIO_ctrl(out,0xb,0,(void *)0x0);
  BIO_pop(out);
  BIO_free(b);
  return out_00;
}

