
ASN1_INTEGER * serial_cb(undefined4 param_1,char *param_2)

{
  ASN1_INTEGER *a;
  BIO *bp;
  int iVar1;
  
  a = (ASN1_INTEGER *)next_serial();
  if (a != (ASN1_INTEGER *)0x0) {
    bp = BIO_new_file(param_2,"w");
    if (((bp == (BIO *)0x0) || (iVar1 = i2a_ASN1_INTEGER(bp,a), iVar1 < 1)) ||
       (iVar1 = BIO_puts(bp,"\n"), iVar1 < 1)) {
      BIO_printf(bio_err,"could not save serial number to %s\n",param_2);
    }
    BIO_free_all(bp);
    return a;
  }
  TS_RESP_CTX_set_status_info(param_1,2,"Error during serial number generation.");
  TS_RESP_CTX_add_failure_info(param_1,0x11);
  return (ASN1_INTEGER *)0x0;
}

