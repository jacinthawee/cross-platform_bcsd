
BIO * B64_write_ASN1(undefined4 param_1,ASN1_VALUE *param_2,BIO *param_3,uint param_4,
                    ASN1_ITEM *param_5)

{
  undefined4 uVar1;
  int iVar2;
  BIO *out;
  BIO *out_00;
  BIO *pBVar3;
  
  uVar1 = (*(code *)PTR_BIO_f_base64_006a85b8)();
  iVar2 = (*(code *)PTR_BIO_new_006a7fa4)(uVar1);
  if (iVar2 != 0) {
    out = (BIO *)(*(code *)PTR_BIO_push_006a85c0)(iVar2,param_1);
    if ((param_4 & 0x1000) == 0) {
      out_00 = (BIO *)0x1;
      (*(code *)PTR_ASN1_item_i2d_bio_006a8810)(param_5,out,param_2);
    }
    else {
      out_00 = BIO_new_NDEF(out,param_2,param_5);
      if (out_00 == (BIO *)0x0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xd3,0x41,"asn_mime.c",0x7d);
      }
      else {
        SMIME_crlf_copy(param_3,out_00,param_4);
        (*(code *)PTR_BIO_ctrl_006a7f18)(out_00,0xb,0,0);
        do {
          pBVar3 = (BIO *)(*(code *)PTR_BIO_pop_006a8ab4)(out_00);
          (*(code *)PTR_BIO_free_006a7f70)(out_00);
          out_00 = pBVar3;
        } while (out != pBVar3);
        out_00 = (BIO *)0x1;
      }
    }
    (*(code *)PTR_BIO_ctrl_006a7f18)(out,0xb,0,0);
    (*(code *)PTR_BIO_pop_006a8ab4)(out);
    (*(code *)PTR_BIO_free_006a7f70)(iVar2);
    return out_00;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xd2,0x41,"asn_mime.c",0x9c);
  return (BIO *)0x0;
}

